//------------------------------------------------------------------------------
// external.c:
//
// Execution of external scripts / binaries
//------------------------------------------------------------------------------
// Copyright (C) 2018-2022, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------
// h_run - n_run / n_execute / n_rexx helper
//------------------------------------------------------------------------------
static entry_p h_run(entry_p contxt, const char *pre, const char *dir)
{
    // One or more arguments.
    C_SANE(1, con(contxt));

    entry_p otx      = con(contxt),
            prompt   = opt(otx, OPT_PROMPT),
            help     = opt(otx, OPT_HELP),
            confirm  = opt(otx, OPT_CONFIRM),
            safe     = opt(otx, OPT_SAFE),
            back     = opt(otx, OPT_BACK);

    // Error status.
    int32_t err = LG_FALSE;

    // Do we need confirmation?
    if(confirm)
    {
        inp_t grc = gui_confirm(str(prompt), str(help), back != false);

        // Is the back option available?
        if(back)
        {
            // Fake input?
            if(get_num(contxt, "@back"))
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
            R_NUM(err);
        }
    }

    // Is this call safe to run or are we not in pretend mode?
    if(safe || !get_num(contxt, "@pretend"))
    {
        // Command / script. Merge all and insert space between arguments.
        char *cmd = get_chlstr(contxt, true);

        // Exit on OOM.
        LG_ASSERT(cmd, end());

        // DOS / Arexx script?
        if(pre)
        {
            size_t len = strlen(cmd) + strlen(pre) + 2;
            char *tmp = DBG_ALLOC(malloc(len));

            if(!tmp && PANIC(contxt))
            {
                free(cmd);
                return end();
            }

            // Prepend prefix to command string.
            snprintf(tmp, len, "%s %s", pre, cmd);
            free(cmd);
            cmd = tmp;
        }

        // Working dir.
        char *cwd = NULL;

        // If we have a valid destination dir, change to that directory. We're
        // not treating errors as such.
        if(dir && *dir && h_exists(dir))
        {
            // Try to get current working dir before changing to the new dir
            // Save the old one so that we can go back afterwards.
            if(getcwd(buf_raw(), buf_len()) == buf_raw() && !chdir(dir))
            {
                cwd = buf_raw();
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
                err = SystemTags
                (
                    cmd,
                    SYS_Input, inp,
                    SYS_Output, out,
                    TAG_END
                );

                // On error, get secondary status.
                if(err)
                {
                    LONG ioe = IoErr();

                    // Expose IoErr to script.
                    set_num(contxt, "@ioerr", ioe);
                }

                // We probably don't need to close NIL: but it doesn't hurt.
                Close(out);
            }
            else
            {
                // Unknown error.
                err = -1;
            }

            // We probably don't need to close NIL: but it doesn't hurt.
            Close(inp);
        }
        else
        {
            // Unknown error.
            err = -1;
        }
        #else
        // For testing purposes only.
        printf("%s%s", cmd, dir ? dir : "");
        #endif

        // Go back to where we started if we've changed directory.
        if(cwd && chdir(cwd))
        {
            // The rug was swept away from us.
            ERR(ERR_NO_SUCH_FILE_OR_DIR, cwd);
        }

        // OK == 0. Only fail in 'strict' mode.
        if(err && get_num(contxt, "@strict"))
        {
            ERR(ERR_EXEC, cmd);
        }

        // Free concatenation.
        free(cmd);
    }

    // Write an explanation of what we just did / tried to do to the log file.
    h_log(contxt, tr(S_XCTD), str(C_ARG(1)));

    // Success or failure.
    R_NUM(err);
}

//------------------------------------------------------------------------------
// (execute <arg> (help..) (prompt..) (confirm) (safe))
//     execute script file
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_execute(entry_p contxt)
{
    return h_run(contxt, "execute", get_str(contxt, "@execute-dir"));
}

//------------------------------------------------------------------------------
// (rexx <arg> (help..) (prompt..) (confirm..) (safe))
//     execute ARexx script
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_rexx(entry_p contxt)
{
    return h_run(contxt, "rx", NULL);
}

//------------------------------------------------------------------------------
// (run <arg> (help..) (prompt..) (confirm..) (safe))
//     execute program
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_run(entry_p contxt)
{
    return h_run(contxt, NULL, get_str(contxt, "@execute-dir"));
}
