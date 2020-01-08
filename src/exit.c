//------------------------------------------------------------------------------
// exit.c:
//
// Interuption of program execution
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "exit.h"
#include "gui.h"
#include "procedure.h"
#include "resource.h"
#include "util.h"
#include <stdio.h>
#include <string.h>

#ifdef AMIGA
#include <proto/exec.h>
#endif

//------------------------------------------------------------------------------
// (abort <string1> <string2> ...)
//     abandon installation
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_abort(entry_p contxt)
{
    // Arguments are optional.
    C_SANE(0, NULL);

    // Concatenate all children.
    char *msg = get_chlstr(contxt, false);

    // Bail out on out of memory or if we have unresolvable children.
    if((!msg && PANIC(contxt)) || DID_ERR)
    {
        free(msg);
        R_NUM(LG_FALSE);
    }

    // Show the result of the concatenation unless it's empty.
    if(*msg)
    {
        gui_abort(msg);
    }

    // Free temporary buffer.
    free(msg);

    // Set ABORT and return. This will make invoke() halt.
    error(contxt, -3, ERR_ABORT, __func__);
    R_NUM(LG_TRUE);
}

//------------------------------------------------------------------------------
// Name:        h_exit
// Description: Show final exit message unless quiet mode is set.
// Input:       entry_p contxt:     The execution context.
// Return:      -
//------------------------------------------------------------------------------
static void h_exit(entry_p contxt)
{
    // Nothing to do if 'quiet' is set.
    if(opt(contxt, OPT_QUIET))
    {
        return;
    }

    // Get name and location of application.
    const char *app = get_str(contxt, "@app-name"),
               *dst = get_str(contxt, "@default-dest");

    // Display the 'the app can be found here' message if we know the name and
    // location of the application.
    if(*app && *dst)
    {
        // Display the full message.
        snprintf(buf_get(B_KEY), buf_len(), tr(S_CBFI), tr(S_ICPL), app, dst);
        gui_finish(buf_put(B_KEY));
    }
    else
    {
        // Display the bare minimum.
        gui_finish(tr(S_ICPL));
    }
}

//------------------------------------------------------------------------------
// (exit <string> <string> ... (quiet))
//     end installation after displaying strings (if provided)
//
// This causes normal termination of a script.  If strings are provided, they
// are displayed.  The 'done with installation' message is then displayed.  The
// 'onerror' statements are not executed. If (quiet) is specified, the final
// report display is skipped.
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_exit(entry_p contxt)
{
    // All we need is a context.
    C_SANE(0, NULL);

    // If we have any children, display them.
    if(contxt->children)
    {
        // Concatenate all children.
        char *msg = get_chlstr(contxt, false);

        if((!msg && PANIC(contxt)) || DID_ERR)
        {
            // Non resolvable children or out of memory.
            free(msg);
            R_NUM(LG_FALSE);
        }

        // Show the result of the concatenation unless it's empty.
        if(*msg)
        {
            gui_finish(msg);
        }

        // Free temporary buffer.
        free(msg);
    }

    // Show final message unless 'quiet' is set.
    h_exit(contxt);

    // Make invoke() halt.
    R_NUM(HALT);
}

//------------------------------------------------------------------------------
// (onerror (<statements>))
//     general error trap
//
// In part implemented using m_procedure. This function invokes the @onerror
// procedure inserted using (onerror), which is a special case of (procedure)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_onerror(entry_p contxt)
{
    // A static reference. We might be out of heap when this is invoked.
    static entry_t ref = { .type = CUSREF, .name = "@onerror" };

    // Zero or more arguments. No options.
    C_SANE(0, NULL);

    // Global context where the user defined procedures are found.
    entry_p con = global(contxt);

    // Make sure that '@onerror' exists. On out of memory it might be missing.
    entry_p *err = con->symbols;

    while(exists(*err))
    {
        if((*err)->type == CUSTOM && !strcasecmp((*err)->name, ref.name))
        {
            // Clear errors otherwise m_gosub / invoke will halt.
            RESET;

            // Connect reference to the current context.
            ref.parent = contxt;

            // Invoke @onerror by calling m_gosub
            return m_gosub(&ref);
        }

        // Next function.
        err++;
    }

    // @onerror not found. Init is broken.
    PANIC(contxt);
    R_CUR;
}

//------------------------------------------------------------------------------
// (trap <flags> <statements>)
//     trap errors.  flags: 1-abort, 2-nomem, 3-error, 4-dos, 5-badargs
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// TODO: Currently all errors are trapped. Implement error categories.
//------------------------------------------------------------------------------
entry_p m_trap(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Enter trap mode.
    set_num(contxt, "@trap", num(C_ARG(1)));

    // Resolve statements.
    entry_p ret = resolve(C_ARG(2));

    // Leave trap mode and clear errors.
    set_num(contxt, "@trap", 0);
    RESET;

    // Return resolved value.
    return ret;
}

//------------------------------------------------------------------------------
// (reboot)                                                              (V44)
//     reboot the Amiga
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//------------------------------------------------------------------------------
entry_p m_reboot(entry_p contxt)
{
    // All we need is a context.
    C_SANE(0, NULL);

    // Don't reboot in pretend mode.
    if(get_num(contxt, "@pretend"))
    {
        R_NUM(LG_FALSE);
    }

    // Don't reboot in test mode.
    #if defined(AMIGA) && !defined(LG_TEST)
    // Hard reset.
    ColdReboot();
    #endif

    // Always succeed in test mode.
    R_NUM(LG_TRUE);
}
