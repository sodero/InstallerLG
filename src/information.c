//------------------------------------------------------------------------------
// information.c:
//
// Functions for informing the user
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
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
// Name:        h_debug_all
// Description: m_debug helper printing the value of all children in a contxt.
// Input:       entry_p contxt: Execution context.
// Return:      -
//------------------------------------------------------------------------------
static void h_debug_all(entry_p contxt)
{
    // Print string representation of all children.
    for(entry_p *cur = contxt->children; exists(*cur); cur++)
    {
        char *val = "<NIL>";

        // Test if variable is defined, if not print <NIL>.
        if((*cur)->type == SYMREF)
        {
            // Save level of strictness.
            int mode = get_num(contxt, "@strict");

            // Set non strict mode to supress errors.
            set_num(contxt, "@strict", 0);

            // Save string if the symbol is defined.
            if(find_symbol(*cur)->type != DANGLE)
            {
                // Resolve string.
                val = str(*cur);
            }

            // Restore level of strictness.
            set_num(contxt, "@strict", mode);
        }
        else
        {
            // Resolve string.
            val = str(*cur);
        }

        if(arg_argc(-1))
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
    }
}

//------------------------------------------------------------------------------
// (debug <anything> <anything> ...)
//    print to stdout when running from a shell
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_debug(entry_p contxt)
{
    // No arguments required. Weird, but that's how the CBM Installer works.
    C_SANE(0, NULL);

    // Is there anything to print?
    if(contxt->children)
    {
        h_debug_all(contxt);
    }

    // Append final newline.
    if(arg_argc(-1))
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
    R_NUM(LG_TRUE);
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

    // In novice mode no message is to be shown unless (all) is set.
    if(!opt(contxt, OPT_ALL) && get_num(contxt, "@user-level") == LG_NOVICE)
    {
        R_NUM(LG_FALSE);
    }

    // Concatenate all children.
    char *msg = get_chlstr(contxt, false);

    // Make sure that we're not out of memory and that all children are
    // resolvable.
    if((!msg && PANIC(contxt)) || DID_ERR)
    {
        free(msg);
        R_NUM(LG_FALSE);
    }

    // Is the back option available?
    entry_p back = opt(contxt, OPT_BACK);

    // Show the result of the concatenation.
    inp_t grc = gui_message(msg, back != false);

    // Free the temporary buffer.
    free(msg);

    // If (back) exists, execute body on user / fake abort.
    if(back && (grc == G_ABORT || get_num(contxt, "@back")))
    {
        return resolve(back);
    }

    // Translate response.
    R_NUM(((grc == G_ABORT || grc == G_EXIT) && HALT) ? LG_FALSE :
          ((grc == G_TRUE) ? LG_TRUE : LG_FALSE));
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
    int old = get_num(contxt, "@user-level");

    // Set new value of @user-level.
    set_num(contxt, "@user-level", num(C_ARG(1)));

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

    // Current installer settings.
    int lvl = get_num(contxt, "@user-level"), prt = get_num(contxt, "@pretend"),
        lgf = get_num(contxt, "@log");

    // Concatenate children, if any.
    char *msg = get_chlstr(contxt, false);

    // Make sure that we're not out of memory and that all children are
    // resolvable.
    if((!msg && PANIC(contxt)) || DID_ERR)
    {
        free(msg);
        R_NUM(LG_FALSE);
    }

    // Show welcome dialog.
    inp_t grc = gui_welcome(msg, &lvl, &lgf, &prt, get_num(contxt, "@user-min"),
                            get_num(contxt, "@no-pretend"),
                            get_num(contxt, "@no-log"));

    // Free temporary buffer.
    free(msg);

    // User abort?
    if(grc != G_TRUE)
    {
        HALT;
    }

    // Save new settings.
    set_num(contxt, "@user-level", lvl);
    set_num(contxt, "@pretend", prt);
    set_num(contxt, "@log", lgf);

    // Proceed, halt or error.
    R_NUM((grc == G_TRUE) ? LG_TRUE : LG_FALSE);
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

    if(!msg && PANIC(contxt))
    {
        // Out of memory.
        R_CUR;
    }

    // Did we fail while resolving one or more of our children?
    if(DID_ERR)
    {
        // We own msg.
        free(msg);
        R_NUM(LG_FALSE);
    }

    // Standard prefix.
    size_t len = strlen(tr(S_WRKN)) + strlen(msg) + 1;

    // Memory to hold prefix and children.
    char *con = DBG_ALLOC(calloc(len, 1));

    if(!con && PANIC(contxt))
    {
        free(msg);
        R_CUR;
    }

    // Concatenate and free buffer.
    snprintf(con, len, "%s%s", tr(S_WRKN), msg);
    free(msg);

    // Show the result.
    gui_working(con);

    // Free the final message buffer.
    free(con);

    // Success.
    R_NUM(LG_TRUE);
}
