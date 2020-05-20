//------------------------------------------------------------------------------
// args.c:
//
// Functions for handling command line arguments and workbench tooltypes.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "args.h"
#include "resource.h"
#include "strop.h"
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
    // We might not have a script but we must continue with the rest of the
    // strings in case those are tooltypes. Otherwise we'll free memory in
    // arg_done() that is already freed by FreeDiskObject in arg_wb().
    if(args[ARG_SCRIPT])
    {
        #if defined(AMIGA)
        BPTR lock = (BPTR) Lock(args[ARG_SCRIPT], ACCESS_READ);

        // Use script name if we fail to get the absolute path.
        if(!lock || !NameFromLock(lock, buf_get(B_KEY), buf_len()))
        {
            strncpy(buf_get(B_KEY), args[ARG_SCRIPT], buf_len());
        }

        // Lock might be invalid. The script might not exist.
        UnLock(lock);
        #else
        // Prepend redundant path in test mode.
        (void) snprintf(buf_get(B_KEY), buf_len(), "./%s", args[ARG_SCRIPT]);
        #endif

        // Copy of the (hopefully) absolute script path.
        args[ARG_SCRIPT] = DBG_ALLOC(strdup(buf_put(B_KEY)));

        // The home directory already exists if we're invoked as project.
        if(!args[ARG_HOMEDIR])
        {
            args[ARG_HOMEDIR] = DBG_ALLOC(h_pathonly(buf_get(B_KEY)));
            (void) buf_put(B_KEY);
        }
    }

    // Copy string arguments. Stop at OLDDIR since items after that are either
    // already copied or (interpreted as) booleans.
    for(size_t arg = ARG_APPNAME; arg < ARG_OLDDIR; arg++)
    {
        args[arg] = args[arg] ? DBG_ALLOC(strdup(args[arg])) : NULL;
    }

    // Script and home directory aren't optional.
    return args[ARG_SCRIPT] && args[ARG_HOMEDIR];
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
    // Temp AxRT workaround until argument handling in AxRT is implemented.
    #if defined(AMIGA) && !defined(__AXRT__)
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

#if defined(AMIGA)
//------------------------------------------------------------------------------
// Name:        arg_find_tts
// Description: Find tooltypes in string list.
// Input:       STRPTR *tts:    List of tooltype strings.
// Return:      -
//------------------------------------------------------------------------------
static void arg_find_tts(STRPTR *tts)
{
    // Is there an explicit script path?
    char *script = (char *) FindToolType(tts, (STRPTR) tr(S_SCRI));

    // Override current path if explicit path exists.
    args[ARG_SCRIPT] = script ? script : args[ARG_SCRIPT];

    args[ARG_APPNAME] = (char *) FindToolType((STRPTR *) tts, "APPNAME");
    args[ARG_MINUSER] = (char *) FindToolType((STRPTR *) tts, "MINUSER");
    args[ARG_DEFUSER] = (char *) FindToolType((STRPTR *) tts, "DEFUSER");
    args[ARG_LANGUAGE] = (char *) FindToolType((STRPTR *) tts, "LANGUAGE");
    args[ARG_LOGFILE] = (char *) FindToolType((STRPTR *) tts, "LOGFILE");
    args[ARG_NOLOG] = (char *) FindToolType((STRPTR *) tts, "NOLOG");
    args[ARG_NOPRETEND] = (char *) FindToolType((STRPTR *) tts, "NOPRETEND");
}
#endif

//------------------------------------------------------------------------------
// Name:        arg_wb
// Description: Get WB tooltype information.
// Input:       char **argv:    From main(), the array of arguments.
// Return:      'true' on success, 'false' otherwise.
//------------------------------------------------------------------------------
static bool arg_wb(char **argv)
{
    #if defined(AMIGA)
    struct WBStartup *wb = (struct WBStartup *) argv;

    // We must be invoked using a tool or a project.
    if(!wb || (wb->sm_NumArgs != 1 && wb->sm_NumArgs != 2))
    {
        return false;
    }

    struct WBArg *arg = wb->sm_ArgList + wb->sm_NumArgs - 1;

    if(!arg)
    {
        return false;
    }

    // We have the script name and home directory if this is a 'project'.
    if(wb->sm_NumArgs == 2)
    {
        if(NameFromLock(arg->wa_Lock, buf_get(B_KEY), buf_len()))
        {
            args[ARG_HOMEDIR] = DBG_ALLOC(strdup(buf_get(B_KEY)));
        }

        (void) buf_put(B_KEY);
        args[ARG_SCRIPT] = arg->wa_Name;
    }

    // Change to icon directory and get tool types if we can.
    BPTR old = CurrentDir(arg->wa_Lock);
    struct DiskObject *dob = (struct DiskObject *) GetDiskObject(arg->wa_Name);

    if(dob && dob->do_ToolTypes)
    {
        arg_find_tts(dob->do_ToolTypes);
    }

    // Postprocess WB info and go back. We'll crash if we don't.
    bool ret = arg_post();
    CurrentDir(old);

    if(dob)
    {
        FreeDiskObject(dob);
    }

    return ret;
    #else
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
    if(getcwd(buf_get(B_KEY), buf_len()) == buf_get(B_KEY))
    {
        args[ARG_OLDDIR] = DBG_ALLOC(strdup(buf_put(B_KEY)));
    }

    // Invoked from CLI or WB.
    bool init = argc ? arg_cli(argc, argv) : arg_wb(argv);

    // Go to script working directory and return. Temp AxRT workaround until
    // argument handling in AxRT is implemented.
    return init && args[ARG_HOMEDIR]
    #ifndef __AXRT__
        && !chdir(args[ARG_HOMEDIR])
    #endif
    ;
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
    // of these strings, we might be out of memory. If we don't have a home dir
    // then we've never changed directory in the first place.
    if(args[ARG_HOMEDIR] && args[ARG_OLDDIR])
    {
        chdir(args[ARG_OLDDIR]);
    }

    // Free what we have allocated. Note that we stop at HOMEDIR since that's
    // the last string. NOLOG and NOPRETEND are (interpreted as) booleans.
    for(size_t arg = ARG_SCRIPT; arg <= ARG_HOMEDIR; arg++)
    {
        free(args[arg]);
    }
}
