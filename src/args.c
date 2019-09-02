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

// Argument / tooltype support.
#ifdef AMIGA
static struct RDArgs *rda;
static struct DiskObject *dob;
#endif

#ifdef __VBCC__
typedef LONG IPTR;
#endif

static char *args[ARG_NUMBER_OF];

static bool arg_post(void)
{
    if(!args[ARG_SCRIPT])
    {
        // Bad input.
        return false;
    }

    #if defined(AMIGA) && !defined(LG_TEST)
    BPTR lock = (BPTR) Lock(args[ARG_SCRIPT], ACCESS_READ);

    if(!lock || !NameFromLock(lock, get_buf(), buf_size()))
    {
        // Read error or buffer to small.
        UnLock(lock);
        return false;
    }

    UnLock(lock);
    #else
    snprintf(get_buf(), buf_size(), "./%s", args[ARG_SCRIPT]);
    #endif

    args[ARG_SCRIPT] = DBG_ALLOC(strdup(get_buf()));

    for(size_t arg = ARG_APPNAME; arg < ARG_NUMBER_OF; arg++)
    {
        if(!args[arg])
        {
            continue;
        }

        args[arg] =  DBG_ALLOC(strdup(args[arg]));
    }

    return true;
}

static bool arg_cli(int argc, char **argv)
{
    #if defined(AMIGA) && !defined(LG_TEST)
    // Use the builtin commandline parser.
    struct RDArgs *rda = (struct RDArgs *) ReadArgs("SCRIPT/A,APPNAME/K,"
                                                    "MINUSER/K,DEFUSER/K,"
                                                    "LANGUAGE/K,LOGFILE/K,"
                                                    "NOLOG/S,NOPRETEND/S",
                                                    (IPTR *) args, NULL);
    // Post process parser output.
    bool ret = arg_post();

    // We no longer need this struct, a deep copy is done in arg_post().
    FreeArgs(rda)
    return ret;
    #else
    // On non-AMIGA systems, or in test mode, only the script name is supported.
    if(argc < 2)
    {
        // Missing argument(s)
        fputs(tr(S_RQMS), stderr);
        return false;
    }

    // On non Amigas this is the only argument we can handle.
    args[ARG_SCRIPT] = argv[1];
    return arg_post();
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

    if(argc)
    {
        return arg_cli(argc, argv);
    }

    #if defined(AMIGA) && !defined(LG_TEST)
    // Invoked from the command line.
    if(argc)
    {
        // Use the builtin parser.
        rda = (struct RDArgs *)

        ReadArgs
        (
            "SCRIPT/A,"
            "APPNAME/K,"
            "MINUSER/K,"
            "DEFUSER/K,"
            "LANGUAGE/K,"
            "LOGFILE/K,"
            "NOLOG/S,"
            "NOPRETEND/S",
            (IPTR *) args,
            NULL
        );
    }
    else
    // Invoked from Workbench. Examine 'tooltypes'.
    {
        struct WBArg *arg = NULL;
        struct WBStartup *wb = (struct WBStartup *) argv;

        // Invoked using a 'tool'?
        if(wb->sm_NumArgs == 1)
        {
            arg = wb->sm_ArgList;
        }
        // Invoked using a 'project'?
        else if(wb->sm_NumArgs == 2)
        {
            // We're after the 'next' argument, where the information about the
            // script is to be found.
            arg = wb->sm_ArgList + 1;

            // Sanity check.
            if(arg->wa_Name && arg->wa_Lock)
            {
                // Change directory to that of the script.
                static char wd[PATH_MAX];
                BPTR owd = (BPTR) CurrentDir(arg->wa_Lock);

                // Get the name of the script and the directory.
                if(NameFromLock(arg->wa_Lock, wd, sizeof(wd)))
                {
                    args[ARG_SCRIPT] = arg->wa_Name;
                    args[ARG_WORKDIR] = wd;
                }

                // Go back.
                CurrentDir(owd);
            }
        }

        // Do we have something we can handle?
        if(arg)
        {
            BPTR owd = (BPTR) -1;

            // Change current directory if necessary.
            if(arg->wa_Lock)
            {
                // Save the old directory.
                owd = (BPTR) CurrentDir(arg->wa_Lock);
            }

            // Read information from icon.
            dob = (struct DiskObject *) GetDiskObject(arg->wa_Name);

            if(dob)
            {
                char **tt = (char **) dob->do_ToolTypes;

                if(tt)
                {
                    // We already have the name of the script if the invocation
                    // was done using a 'project'
                    if(!args[ARG_SCRIPT])
                    {
                        args[ARG_SCRIPT] = (char *)
                            FindToolType ((STRPTR *) tt, "SCRIPT");
                    }

                    // The rest of the 'tooltypes' are handled the same way for
                    // 'projects' and 'tools'.
                    args[ARG_APPNAME] = (char *)
                        FindToolType((STRPTR *) tt, "APPNAME");
                    args[ARG_MINUSER] = (char *)
                        FindToolType((STRPTR *) tt, "MINUSER");
                    args[ARG_DEFUSER] = (char *)
                        FindToolType((STRPTR *) tt, "DEFUSER");
                    args[ARG_LANGUAGE] = (char *)
                        FindToolType((STRPTR *) tt, "LANGUAGE");
                    args[ARG_LOGFILE] = (char *)
                        FindToolType((STRPTR *) tt, "LOGFILE");
                    args[ARG_NOLOG] = (char *)
                        FindToolType((STRPTR *) tt, "NOLOG");
                    args[ARG_NOPRETEND] = (char *)
                        FindToolType((STRPTR *) tt, "NOPRETEND");
                }
                else
                {
                    // Unknown problem, free disk object and bail out.
                    FreeDiskObject(dob);
                    dob = NULL;
                }
            }

            // If we did change directory before, change back to the old one.
            if(owd != (BPTR) -1)
            {
                CurrentDir(owd);
            }
        }
    }

    // Change working dir if started from a 'project'.
    if(args[ARG_WORKDIR] && chdir(args[ARG_WORKDIR]))
    {
        // Could not change directory.
        return false;
    }

    // By now we should have either a disk object, or an rda, otherwise we have
    // failed.
    return rda || dob;
    #else
    // On non-AMIGA systems, or in test mode, only the script name is supported.
    if(argc >= 2)
    {
        args[ARG_SCRIPT] = argv[1];
    }
    else
    {
        // Missing argument(s)
        fputs(tr(S_RQMS), stderr);
    }

    // Something is really wrong if we don't have the executable name.
    return *args;
    #endif
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
    // Free what we have allocated. Make sure that we don't do this twice by
    // setting all pointers to NULL.

    #if defined(AMIGA) && !defined(LG_TEST)
    // From Workbench.
    if(dob)
    {
        FreeDiskObject(dob);
        dob = NULL;
    }

    // From Shell.
    if(rda)
    {
        FreeArgs(rda);
        rda = NULL;
    }
    #endif

    for(size_t arg = ARG_SCRIPT; arg < ARG_NUMBER_OF; arg++)
    {
//      if(args[arg]) printf("freeing:%p\n", args[arg]);
        free(args[arg]);
    }
}
