//----------------------------------------------------------------------------
// external.c:
//
// Execution of external scripts / binaries
//----------------------------------------------------------------------------
// Copyright (C) 2018, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//----------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "external.h"
#include "file.h"
#include "gui.h"
#include "resource.h"
#include "util.h"
#include <stdio.h>
#include <unistd.h>

#ifdef AMIGA
#include <dos/dos.h>
#include <dos/dostags.h>
#include <proto/dos.h>
#endif

#include <string.h>

//----------------------------------------------------------------------------
// h_run - m_run / m_execute / m_rexx helper
//----------------------------------------------------------------------------
static entry_p h_run(entry_p contxt, const char *pre, const char *dir)
{
    // One or more arguments.
    C_SANE(1, CARG(2));

    entry_p prompt   = get_opt(CARG(2), OPT_PROMPT),
            help     = get_opt(CARG(2), OPT_HELP),
            confirm  = get_opt(CARG(2), OPT_CONFIRM),
            safe     = get_opt(CARG(2), OPT_SAFE),
            back     = get_opt(CARG(2), OPT_BACK);

    DNUM = 0;

    // Do we need confirmation?
    if(confirm)
    {
        inp_t grc = gui_confirm(str(prompt), str(help), back != false);

        // Is the back option available?
        if(back)
        {
            // Fake input?
            if(get_numvar(contxt, "@back"))
            {
                grc = G_ABORT;
            }

            // On abort execute.
            if(grc == G_ABORT)
            {
                return resolve(back);
            }
        }

        // FIXME
        if(grc == G_ABORT || grc == G_EXIT)
        {
            HALT;
        }

        // FIXME
        if(grc != G_TRUE)
        {
            RCUR;
        }
    }

    // Is this call safe to run or are we not
    // in pretend mode?
    if(safe || !get_numvar(contxt, "@pretend"))
    {
        // Command / script. Merge all and insert
        // space between arguments.
        char *cmd = get_chlstr(contxt, true);

        if(!cmd)
        {
            // Out of memory.
            PANIC(contxt);
            RCUR;
        }

        // Working dir.
        char *cwd = NULL;

        // DOS / Arexx script?
        if(pre)
        {
            size_t len = strlen(cmd) + strlen(pre) + 2;
            char *tmp = DBG_ALLOC(malloc(len));

            if(tmp)
            {
                // Prepend prefix to command string.
                snprintf(tmp, len, "%s %s", pre, cmd);
                free(cmd);
                cmd = tmp;
            }
            else
            {
                // Out of memory
                PANIC(contxt);
                free(cmd);

                // Failure.
                RCUR;
            }
        }

        // If we have a valid destination dir,
        // change to that directory. We're not
        // treating errors as such.
        if(dir && *dir && h_exists(dir))
        {
            // Use the global buffer.
            char *buf = get_buf();

            // Try to get current working dir
            // before changing to the new dir
            // Save the old one so that we can
            // go back afterwards.
            if(getcwd(buf, buf_size()) == buf
               && !chdir(dir))
            {
                cwd = buf;
            }
        }

        #if defined(AMIGA) && !defined(LG_TEST)
        // No input needed.
        BPTR inp = (BPTR) Open("NIL:", MODE_OLDFILE);

        // Can this fail?
        if(inp)
        {
            // No output needed.
            BPTR out = (BPTR) Open("NIL:", MODE_OLDFILE);

            // Can this fail?
            if(out)
            {

                // Execute whatever we have in cmd.
                DNUM = SystemTags
                (
                    cmd,
                    SYS_Input, inp,
                    SYS_Output, out,
                    TAG_END
                );

                // On error, get secondary status.
                if(DNUM)
                {
                    LONG ioe = IoErr();

                    // Expose IoErr to script.
                    set_numvar(contxt, "@ioerr", ioe);
                }

                // Not sure if we need to close NIL:
                // but it doesn't hurt.
                Close(out);
            }
            else
            {
                // Unknown error.
                DNUM = -1;
            }

            // Not sure if we need to close NIL:
            // but it doesn't hurt.
            Close(inp);
        }
        else
        {
            // Unknown error.
            DNUM = -1;
        }
        #else
        // For testing purposes only.
        printf("%s%s", cmd, dir ? dir : "");
        #endif

        // Go back to where we started if we've
        // changed directory.
        if(cwd && chdir(cwd))
        {
            // The rug was swept away from us.
            ERR(ERR_NO_SUCH_FILE_OR_DIR, cwd);
        }

        // OK == 0. Only fail in 'strict' mode.
        if(DNUM && get_numvar(contxt, "@strict"))
        {
            ERR(ERR_EXEC, cmd);
        }

        // Free concatenation.
        free(cmd);
    }

    // Write an explanation of what we just did /
    // tried to do to the log file.
    h_log(contxt, tr(S_XCTD), str(CARG(1)));

    // Success or failure.
    RCUR;
}

//----------------------------------------------------------------------------
// (execute <arg> (help..) (prompt..) (confirm) (safe))
//     execute script file
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_execute(entry_p contxt)
{
    return h_run(contxt, "execute", get_strvar(contxt, "@execute-dir"));
}

//----------------------------------------------------------------------------
// (rexx <arg> (help..) (prompt..) (confirm..) (safe))
//     execute ARexx script
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_rexx(entry_p contxt)
{
    return h_run(contxt, "rx", NULL);
}

//----------------------------------------------------------------------------
// (run <arg> (help..) (prompt..) (confirm..) (safe))
//     execute program
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_run(entry_p contxt)
{
    return h_run(contxt, NULL, get_strvar(contxt, "@execute-dir"));
}
