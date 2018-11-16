//----------------------------------------------------------------------------
// wb.c:
//
// Workbench interaction
//----------------------------------------------------------------------------
// Copyright (C) 2018, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//----------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "file.h"
#include "util.h"
#include "wb.h"

//----------------------------------------------------------------------------
// (openwbobject <argument> ...)                                         (V44)
//      open a workbench object which can be a disk, a drawer, a trashcan, a
//      tool or a project.
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//----------------------------------------------------------------------------
entry_p m_openwbobject(entry_p contxt)
{
    // We need a single argument.
    if(c_sane(contxt, 1))
    {
        entry_p prompt     = get_opt(contxt, OPT_PROMPT),
                help       = get_opt(contxt, OPT_HELP),
                confirm    = get_opt(contxt, OPT_CONFIRM),
                safe       = get_opt(contxt, OPT_SAFE);

        // A non safe operation in pretend mode
        // always succeeds.
        if(get_numvar(contxt, "@pretend") && !safe)
        {
            RNUM(1);
        }

        // Do we need confirmation?
        if(confirm)
        {
            // The default threshold is expert.
            int level = get_numvar(contxt, "@user-level"),
                th = 2;

            // If the (confirm ...) option contains
            // something that can be translated into
            // a new threshold value...
            if(confirm->children &&
               confirm->children[0] &&
               confirm->children[0] != end())
            {
                // ...then do so.
                th = num(confirm);
            }

            // If we are below the threshold value, or
            // user input has been short-circuited by
            // @yes, skip confirmation.
            if(level < th ||
               get_numvar(contxt, "@yes"))
            {
                confirm = NULL;
            }

            // Make sure that we have the prompt and
            // help texts that we need if 'confirm'
            // is set.
            if(!prompt || !help)
            {
                char * m = prompt ? "help" : "prompt";
                ERR(ERR_MISSING_OPTION, m);
                RNUM(0);
            }
        }

        if(!confirm || h_confirm(contxt, "", "", ""))
        {
            /*
            1531      This statement returs 1 if the object was successfully opened, 0
            1532      if it was not opened and -1 if it was not opened because the
            1533      workbench.library does not support this command (workbench.library
            1534      supports this since V 44).
            */
            #ifdef AMIGA
            DNUM = 1; // FIXME
            #else
            DNUM = 1;
            #endif
        }
        else
        {
            DNUM = 0;
        }
    }
    else
    {
        // Broken parser.
        PANIC(contxt);
    }

    // Success, failure or panic.
    RCUR;
}

//----------------------------------------------------------------------------
// (showwbobject <argument>)                                             (V44)
//      scroll the view of an workbench drawer until the named icon is
//      visible. The drawer has to be opened before.
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//----------------------------------------------------------------------------
entry_p m_showwbobject(entry_p contxt)
{
    // We need a sane context. Arguments
    // are optional though.
    if(c_sane(contxt, 1))
    {
        /*
        1554    This statement returs 1 if the object was successfully shown, 0 if
        1555 it was not shown and -1 if it was not shown because the
        1556 workbench.library does not support this command (workbench.library
        1557 supports this since V 44).
        */
        #ifdef AMIGA
        DNUM = 1; // FIXME
        #else
        DNUM = 1;
        #endif
    }
    else
    {
        // Broken parser.
        PANIC(contxt);
    }

    // Success, failure or panic.
    RCUR;
}

//----------------------------------------------------------------------------
// (closewbobject <argument>)                                            (V44)
//      close named workbench object. Only disks, trashcans and drawers can
//      be closed.
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//----------------------------------------------------------------------------
entry_p m_closewbobject(entry_p contxt)
{
    // We need a sane context. Arguments
    // are optional though.
    if(c_sane(contxt, 1))
    {
        /*
        1576
        1577    This statement returs 1 if the object was successfully closed, 0 if
        1578 it was not closed and -1 if it was not closed because the
        1579 workbench.library does not support this command (workbench.library
        1580 supports this since V 44).
        */
        #ifdef AMIGA
        DNUM = 1; // FIXME
        #else
        DNUM = 1;
        #endif
    }
    else
    {
        // Broken parser.
        PANIC(contxt);
    }

    // Success, failure or panic.
    RCUR;
}
