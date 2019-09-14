//------------------------------------------------------------------------------
// args.c:
//
// Functions for handling command line arguments and workbench tooltypes.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "args.h"
#include "resource.h"
#include "util.h"

#ifdef AMIGA
#include <proto/dos.h>
#include <proto/icon.h>
#include <workbench/startup.h>
#include <workbench/workbench.h>
#endif

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifdef __VBCC__
typedef LONG IPTR;
#endif

static char *args[ARG_NUMBER_OF];

//------------------------------------------------------------------------------
// Name:        arg_post
// Description: Postprocess arguments from WB and CLI.
// Input:       -
// Return:      'true' on success, 'false' otherwise.
//------------------------------------------------------------------------------
static bool arg_post(void)
{
    // We need a script name.
    if(!args[ARG_SCRIPT])
    {
        return false;
    }

    #if defined(AMIGA) && !defined(LG_TEST)
    BPTR lock = (BPTR) Lock(args[ARG_SCRIPT], ACCESS_READ);

    // Use script name if we fail to get the absolute path.
    if(!lock || !NameFromLock(lock, get_buf(), buf_size()))
    {
        strncpy(get_buf(), args[ARG_SCRIPT], buf_size());
    }

    // Lock might be invalid. The script might not exist.
    UnLock(lock);
    #else
    // Prepend redundant path in test mode.
    snprintf(get_buf(), buf_size(), "./%s", args[ARG_SCRIPT]);
    #endif

    // Create a copy of the (hopefully) absolute path.
    args[ARG_SCRIPT] = DBG_ALLOC(strdup(get_buf()));

    // Copy string arguments. Stop at OLDDIR since that's already a copied and
    // the items after that are (interpreted as) booleans.
    for(size_t arg = ARG_APPNAME; arg < ARG_OLDDIR; arg++)
    {
        args[arg] = args[arg] ? DBG_ALLOC(strdup(args[arg])) : NULL;
    }

    // Script isn't optional.
    return args[ARG_SCRIPT];
}

//------------------------------------------------------------------------------
// Name:        arg_cli
// Description: Get CLI arguments.
// Input:       int argc:       From main(), the number of arguments.
//              char **argv:    From main(), the array of arguments.
// Return:      'true' on success, 'false' otherwise.
//------------------------------------------------------------------------------
static bool arg_cli(int argc, char **argv)
{
    #if defined(AMIGA) && !defined(LG_TEST)
    // Not used on Amiga.
    (void) argc;
    (void) argv;

    // Use the builtin commandline parser.
    struct RDArgs *rda = (struct RDArgs *) ReadArgs(tr(S_ARGS), (IPTR *) args,
                                                    NULL);
    if(!rda)
    {
        // Invalid or missing arguments.
        fputs(tr(S_ARGS), stderr);
        return false;
    };

    // Postprocess parser output.
    bool ret = arg_post();

    // ReadArgs struct not needed, a deep copy is done in arg_post().
    FreeArgs(rda);

    // Return the result of arg_post().
    return ret;
    #else
    // On non-AMIGA systems, or in test mode, only the script name is supported.
    if(argc < 2)
    {
        // Missing argument(s)
        fputs(tr(S_RQMS), stderr);
        return false;
    }

    // This is the only argument we can handle on non-Amigas.
    args[ARG_SCRIPT] = argv[1];

    // Copy and return.
    return arg_post();
    #endif
}

//------------------------------------------------------------------------------
// Name:        arg_wb
// Description: Get WB tooltype information.
// Input:       char **argv:    From main(), the array of arguments.
// Return:      'true' on success, 'false' otherwise.
//------------------------------------------------------------------------------
static bool arg_wb(char **argv)
{
    #if defined(AMIGA) && !defined(LG_TEST)
    struct WBStartup *wb = (struct WBStartup *) argv;

    // We must be invoked using a tool or a project.
    if(!wb || (wb->sm_NumArgs != 1 && wb->sm_NumArgs != 2))
    {
        return false;
    }

    // Are we being invoked using a 'tool' or a 'project'?
    struct WBArg *arg = wb->sm_ArgList + wb->sm_NumArgs - 1;

    if(!arg)
    {
        // Unkown error.
        return false;
    }

    // Change directory if applicable.
    if(arg->wa_Lock)
    {
        CurrentDir(arg->wa_Lock);
    }

    // We have the script name if this is a 'project'.
    args[ARG_SCRIPT] = arg->wa_Name;

    // Read information from icon.
    struct DiskObject *dob = (struct DiskObject *) GetDiskObject(arg->wa_Name);

    // Get info from icon if we can, otherwise continue.
    if(dob && dob->do_ToolTypes)
    {
        char **tts = (char **) dob->do_ToolTypes;

        // We need to find the script path if we're invoked as a tool.
        if(wb->sm_NumArgs == 1)
        {
            args[ARG_SCRIPT] = (char *) FindToolType ((STRPTR *) tts,
                                                      (STRPTR) tr(S_SCRI));
        }

        // The rest of the 'tooltypes' are the same for 'projects' and 'tools'.
        args[ARG_APPNAME] = (char *) FindToolType((STRPTR *) tts, "APPNAME");
        args[ARG_MINUSER] = (char *) FindToolType((STRPTR *) tts, "MINUSER");
        args[ARG_DEFUSER] = (char *) FindToolType((STRPTR *) tts, "DEFUSER");
        args[ARG_LANGUAGE] = (char *) FindToolType((STRPTR *) tts, "LANGUAGE");
        args[ARG_LOGFILE] = (char *) FindToolType((STRPTR *) tts, "LOGFILE");
        args[ARG_NOLOG] = (char *) FindToolType((STRPTR *) tts, "NOLOG");
        args[ARG_NOPRETEND] = (char *) FindToolType((STRPTR *) tts, "NOPRETEND");
    }

    // Postprocess WB info.
    bool ret = arg_post();

    // Disk object not needed, a deep copy is done in arg_post().
    if(dob)
    {
        FreeDiskObject(dob);
    }

    // Return the result of arg_post().
    return ret;
    #else
    // We should never end up here.
    (void) argv;
    return false;
    #endif
}

//------------------------------------------------------------------------------
// Name:        arg_init
// Description: Initialization. Must be invoked before arg_get(). This will
//              allocate resources that must be free:d by calling arg_done().
// Input:       int argc:       From main(), the number of arguments.
//              char **argv:    From main(), the array of arguments.
// Return:      'true' on success, 'false' otherwise.
//------------------------------------------------------------------------------
bool arg_init(int argc, char **argv)
{
    // Save argc, used later to determine whether we are invoked from CLI or WB.
    arg_argc(argc);

    // Save current directory so that we can go back on exit.
    if(getcwd(get_buf(), buf_size()) == get_buf())
    {
        args[ARG_OLDDIR] = DBG_ALLOC(strdup(get_buf()));
    }

    // Invoked from CLI or WB.
    return argc ? arg_cli(argc, argv) : arg_wb(argv);
}

//------------------------------------------------------------------------------
// Name:        arg_get
// Description: Get argument.
// Input:       int ndx:    Argument index. Refer to ARG_* enum in arg.h.
// Return:      char *:     Argument as null terminated string if argument
//                          exists / is set, NULL otherwise.
//------------------------------------------------------------------------------
char *arg_get(int ndx)
{
    // Return what we have within bounds or NULL. The return value can be NULL
    // even though ndx is within bounds if the argument doesn't exist.
    return ndx >= 0 && ndx < ARG_NUMBER_OF ? args[ndx] : NULL;
}

//------------------------------------------------------------------------------
// Name:        arg_argc
// Description: Get / set argument count.
// Input:       int argc:   Positive values to set the number of arguments,
//                          negative values to get the number of arguments.
// Return:      int:        Number of arguments.
//------------------------------------------------------------------------------
int arg_argc(int argc)
{
    // We start of by assuming WB, argc == 0.
    static int narg;

    // Store non-negative values.
    if(argc >= 0)
    {
        narg = argc;
    }

    // Return current value.
    return narg;
}

//------------------------------------------------------------------------------
// Name:        arg_done
// Description: Free resources allocated by arg_init().
// Input:       -
// Return:      -
//------------------------------------------------------------------------------
void arg_done(void)
{
    // Go back to the directory where we started. Don't rely on the existance
    // of this string, we might be out of memory.
    if(args[ARG_OLDDIR])
    {
        chdir(args[ARG_OLDDIR]);
    }

    // Free what we have allocated. Note that we stop at LOGFILE since that is
    // the last string. NOLOG and NOPRETEND are (interpreted as) booleans.
    for(size_t arg = ARG_SCRIPT; arg < ARG_NOLOG; arg++)
    {
        free(args[arg]);
    }
}
