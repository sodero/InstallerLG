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

#ifdef AMIGA
#include <proto/wb.h>
#endif

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
    C_SANE(1, CARG(2));

    entry_p prompt     = get_opt(CARG(2), OPT_PROMPT),
            help       = get_opt(CARG(2), OPT_HELP),
            confirm    = get_opt(CARG(2), OPT_CONFIRM),
            safe       = get_opt(CARG(2), OPT_SAFE);

    // A non safe operation in pretend mode
    // always succeeds.
    if(get_numvar(contxt, "@pretend") && !safe)
    {
        RNUM(1);
    }

    if(!confirm || h_confirm(CARG(2), str(help), str(prompt)))
    {
        #if defined(AMIGA) && !defined(LG_TEST)
        RNUM(OpenWorkbenchObjectA(str(CARG(1)), NULL) ? 1 : 0);
        #else
        // If not supported by workbench.library -1 is to be returned.
        RNUM(-1);
        #endif
    }

    // User abort.
    RNUM(0);
}

//----------------------------------------------------------------------------
// (showwbobject <argument>)                                             (V44)
//      scroll the view of an workbench drawer until the named icon is
//      visible. The drawer has to be opened before.
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//
// KNOWN BUG: This doesn't seem to work on AROS and MorphOS.
//----------------------------------------------------------------------------
entry_p m_showwbobject(entry_p contxt)
{
    // We need a single argument.
    C_SANE(1, NULL);

    #if defined(AMIGA) && !defined(LG_TEST)
    RNUM(MakeWorkbenchObjectVisibleA(str(CARG(1)), NULL) ? 1 : 0);
    #else
    // If not supported by workbench.library -1 is to be returned.
    RNUM(-1);
    #endif
}

//----------------------------------------------------------------------------
// (closewbobject <argument>)                                            (V44)
//      close named workbench object. Only disks, trashcans and drawers can
//      be closed.
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//
// KNOWN BUG: This doesn't seem to work on AROS and MorphOS.
//----------------------------------------------------------------------------
entry_p m_closewbobject(entry_p contxt)
{
    // We need a single argument.
    C_SANE(1, NULL);

    #if defined(AMIGA) && !defined(LG_TEST)
    RNUM(CloseWorkbenchObjectA(str(CARG(1)), NULL) ? 1 : 0);
    #else
    // If not supported by workbench.library -1 is to be returned.
    RNUM(-1);
    #endif
}
