//------------------------------------------------------------------------------
// wb.c:
//
// Workbench interaction
//------------------------------------------------------------------------------
// Copyright (C) 2018-2022, Ola S�der. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "file.h"
#include "util.h"
#include "wb.h"

#ifdef AMIGA
#include <proto/wb.h>
#endif

//------------------------------------------------------------------------------
// (openwbobject <argument> ...)                                           (V44)
//      open a workbench object which can be a disk, a drawer, a trashcan, a
//      tool or a project.
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//------------------------------------------------------------------------------
entry_p n_openwbobject(entry_p contxt)
{
    // We need a single argument.
    C_SANE(1, contxt);

    // A non safe operation in pretend mode always succeeds.
    if(get_num(contxt, "@pretend") && !opt(contxt, OPT_SAFE))
    {
        R_NUM(LG_TRUE);
    }

    // Get confirmation if necessary.
    if(!opt(contxt, OPT_CONFIRM) || h_confirm(contxt,
        str(opt(contxt, OPT_HELP)), str(opt(contxt, OPT_PROMPT))))
    {
        #if defined(AMIGA) && !defined(LG_TEST)
        R_NUM(OpenWorkbenchObjectA(str(C_ARG(1)), NULL) ? LG_TRUE : LG_FALSE);
        #else
        // If not supported by workbench.library -1 is to be returned.
        R_NUM(-1);
        #endif
    }

    // User abort.
    R_NUM(LG_FALSE);
}

//------------------------------------------------------------------------------
// (showwbobject <argument>)                                             (V44)
//      scroll the view of an workbench drawer until the named icon is visible.
//      The drawer has to be opened before.
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//
// KNOWN BUG: This doesn't seem to work on AROS and MorphOS.
//------------------------------------------------------------------------------
entry_p n_showwbobject(entry_p contxt)
{
    // We need a single argument.
    C_SANE(1, NULL);

    #if defined(AMIGA) && !defined(LG_TEST)
    R_NUM(MakeWorkbenchObjectVisibleA(str(C_ARG(1)), NULL)? LG_TRUE : LG_FALSE);
    #else
    // If not supported by workbench.library -1 is to be returned.
    R_NUM(-1);
    #endif
}

//------------------------------------------------------------------------------
// (closewbobject <argument>)                                              (V44)
//      close named workbench object. Only disks, trashcans and drawers can be
//      closed.
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//
// KNOWN BUG: This doesn't seem to work on AROS and MorphOS.
//------------------------------------------------------------------------------
entry_p n_closewbobject(entry_p contxt)
{
    // We need a single argument.
    C_SANE(1, NULL);

    #if defined(AMIGA) && !defined(LG_TEST)
    R_NUM(CloseWorkbenchObjectA(str(C_ARG(1)), NULL) ? LG_TRUE : LG_FALSE);
    #else
    // If not supported by workbench.library -1 is to be returned.
    R_NUM(-1);
    #endif
}
