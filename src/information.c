//------------------------------------------------------------------------------
// information.c:
//
// Functions for informing the user
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
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
entry_p n_complete(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, NULL);

    // Pass value on.
    int32_t val = num(C_ARG(1));

    // Show and update.
    gui_complete(val);

    // Success.
    R_NUM(val);
}

//------------------------------------------------------------------------------
// Name:        h_debug_all
// Description: n_debug helper printing the value of all children in a contxt.
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
            int32_t mode = get_num(contxt, "@strict");

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
entry_p n_debug(entry_p contxt)
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
entry_p n_message(entry_p contxt)
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
entry_p n_user(entry_p contxt)
{
    // We need one argument
    C_SANE(1, NULL);

    // Save old value.
    int32_t old = get_num(contxt, "@user-level");

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
entry_p n_welcome(entry_p contxt)
{
    // Arguments are optional.
    C_SANE(0, NULL);

    // Current installer settings.
    int32_t lvl = get_num(contxt, "@user-level"),
            prt = get_num(contxt, "@pretend"), lgf = get_num(contxt, "@log");

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
entry_p n_working(entry_p contxt)
{
    // One or more arguments.
    C_SANE(0, NULL);

    // Concatenate all children if we have any.
    char *msg = get_chlstr(contxt, false);

    if(!msg && PANIC(contxt))
    {
        return end();
    }

    // Did we fail while resolving one or more of our children?
    if(DID_ERR)
    {
        free(msg);
        R_NUM(LG_FALSE);
    }

    // Standard prefix + message if it exists.
    size_t len = strlen(tr(S_WRKN)) + strlen(msg) + 1;

    // Memory to hold prefix and children.
    char *all = DBG_ALLOC(calloc(len, 1));

    if(!all && PANIC(contxt))
    {
        free(msg);
        return end();
    }

    // Concatenate and free buffer.
    snprintf(all, len, "%s%s", tr(S_WRKN), msg);
    free(msg);

    // Show the result.
    gui_working(all);

    // Free the final message buffer.
    free(all);

    // Success.
    R_NUM(LG_TRUE);
}
