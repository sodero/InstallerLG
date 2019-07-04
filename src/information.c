//------------------------------------------------------------------------------
// information.c:
//
// Functions for informing the user
//------------------------------------------------------------------------------
// Copyright (C) 2018, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "args.h"
#include "error.h"
#include "eval.h"
#include "gui.h"
#include "information.h"
#include "resource.h"
#include "util.h"
#include <stdio.h>
#include <string.h>

#ifdef AMIGA
#include <clib/debug_protos.h>
#endif

//------------------------------------------------------------------------------
// (complete <num>)
//     display percentage through install in titlebar
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_complete(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, NULL);

    // Pass value on.
    int val = num(C_ARG(1));

    // Show and update.
    gui_complete(val);

    // Success.
    R_NUM(val);
}

//------------------------------------------------------------------------------
// (debug <anything> <anything> ...)
//    print to stdout when running from a shell
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_debug(entry_p contxt)
{
    // No arguments required. This doesn't make sense, but that's how the CBM
    // Installer works.
    C_SANE(0, NULL);

    // Invoked from shell or WB?
    int cli = arg_argc(-1);

    // Is there anything to print?
    if(contxt->children)
    {
        entry_p *cur = contxt->children;

        // For all children, print the string representation, to stdout if we're
        // running in a shell or to the log when invoked from WB.
        while(*cur && *cur != end())
        {
            char *val = NULL;

            // Test if variable is defined, if not print <NIL>.
            if((*cur)->type == SYMREF)
            {
                // Save level of strictness.
                entry_p res;
                int mode = get_numvar(contxt, "@strict");

                // Set non strict mode and search for symbol. By doing it this
                // way we supress error messages, if any.
                set_numvar(contxt, "@strict", 0);
                res = find_symbol(*cur);

                // If symbol is missing, we will have a (false) DANGLE.
                if(res->type == DANGLE && !tru(res))
                {
                    // As prescribed.
                    val = "<NIL>";
                }
                else
                {
                    // Symbol found. Resolve it.
                    val = str(*cur);
                }

                // Restore level of strictness.
                set_numvar(contxt, "@strict", mode);
            }
            else
            {
                // Resolve string.
                val = str(*cur);
            }

            if(cli)
            {
                // Invoked from CLI.
                printf("%s ", val);
            }
            #ifdef AMIGA
            else
            {
                // Invoked from WB.
                KPrintF("%s ", val);
            }
            #endif
            cur++;
        }
    }

    // Append final newline.
    if(cli)
    {
        // Invoked from CLI.
        printf("\n");
    }
    #ifdef AMIGA
    else
    {
        // Invoked from WB.
        KPrintF("\n");
    }
    #endif

    // Always.
    R_NUM(1);
}

//------------------------------------------------------------------------------
// (message <string1> <string2>... (all))
//     display message with Proceed and Abort buttons if user
//     level > 0 (novice)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_message(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, contxt);

    // Get information needed to determine whether to show anything or not. And,
    // to determine if there is any (back) code to execute.
    entry_p all = get_opt(contxt, OPT_ALL),
            back = get_opt(contxt, OPT_BACK);

    int level = get_numvar(contxt, "@user-level");

    D_NUM = 0;

    if(!level && !all)
    {
        // Silence.
        R_CUR;
    }

    // Concatenate all children.
    char *msg = get_chlstr(contxt, false);

    // Did we manage to concatenate something?
    if(msg)
    {
        // Did we fail while resolving children?
        if(DID_ERR)
        {
            // Free the temporary buffer.
            free(msg);
        }
        else
        {
            // Show the result of the concatenation.
            inp_t grc = gui_message(msg, back != false);

            // Free the temporary buffer.
            free(msg);

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

            // Translate response.
            D_NUM = (grc == G_TRUE) ? 1 : 0;
        }

        // Success or failure.
        R_CUR;
    }

    // Out of memory.
    PANIC(contxt);
    R_CUR;
}

//------------------------------------------------------------------------------
// (user <user-level>)
//   change the user level (debugging purposes only)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_user(entry_p contxt)
{
    // We need one argument
    C_SANE(1, NULL);

    // Save old value.
    int old = get_numvar(contxt, "@user-level");

    // Set new value of @user-level.
    set_numvar(contxt, "@user-level", num(C_ARG(1)));

    // Return the old.
    R_NUM(old);
}

//------------------------------------------------------------------------------
// (welcome <string> <string> ...)
//     allow Installation to commence [sic!].
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_welcome(entry_p contxt)
{
    // Arguments are optional.
    C_SANE(0, NULL);

    // Installer settings.
    int lvl = get_numvar(contxt, "@user-level"),
        prt = get_numvar(contxt, "@pretend"),
        lgf = get_numvar(contxt, "@log");

    // Concatenate children, if any.
    char *msg = get_chlstr(contxt, false);

    // Make sure that we're not out of memory.
    if(msg)
    {
        // Return value.
        int ret = 0;

        // If we could resolve everything, show the result of the concatenation.
        if(!DID_ERR)
        {
            // Show welcome dialog.
            inp_t grc = gui_welcome(msg, &lvl, &lgf, &prt,
                                    get_numvar(contxt, "@user-min"),
                                    get_numvar(contxt, "@no-pretend"),
                                    get_numvar(contxt, "@no-log"));

            // True or false only.
            ret = (grc == G_TRUE) ? 1 : 0;

            // On 'Proceed', set level and mode.
            if(grc == G_TRUE)
            {
                set_numvar(contxt, "@user-level", lvl);
                set_numvar(contxt, "@pretend", prt);
                set_numvar(contxt, "@log", lgf);
            }
            else
            {
                // Abort.
                HALT;
            }
        }

        // Free temporary buffer.
        free(msg);

        // Done or halt.
        R_NUM(ret);
    }

    // Out of memory.
    PANIC(contxt);
    R_CUR;
}

//------------------------------------------------------------------------------
// (working <string> <string> ...)
//     indicate to user that Installer is busy doing things
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_working(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, NULL);

    // Concatenate all children.
    char *msg = get_chlstr(contxt, false);

    // Did we manage to concatenate something?
    if(msg)
    {
        // Did we fail while resolving one or more of our children?
        if(DID_ERR)
        {
            // We own msg.
            free(msg);
            R_NUM(0);
        }

        // Standard prefix.
        const char *pre = tr(S_WRKN);
        size_t len = strlen(pre) + strlen(msg) + 1;

        // Memory to hold prefix and children.
        char *con = DBG_ALLOC(calloc(len, 1));

        if(con)
        {
            // Concatenate and free buffer.
            snprintf(con, len, "%s%s", pre, msg);
            free(msg);

            // Show the result and eturn immediately.
            gui_working(con);

            // Free the final message buffer.
            free(con);

            // Success.
            R_NUM(1);
        }

        // Free the children buffer.
        free(msg);
    }

    // Out of memory.
    PANIC(contxt);
    R_CUR;
}
