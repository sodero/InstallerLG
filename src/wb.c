//----------------------------------------------------------------------------
// wb.c:
//
// Workbench interaction
//----------------------------------------------------------------------------
// Copyright (C) 2018, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//----------------------------------------------------------------------------

#include "error.h"
#include "util.h"
#include "wb.h"

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
entry_p m_openwbobject(entry_p contxt)
{
    // We need a sane context. Arguments
    // are optional though.
    if(c_sane(contxt, 1))
    {
        RNUM(1);
    }

    // Broken parser / OOM
    PANIC(contxt);

    // Failure.
    RCUR;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
entry_p m_showwbobject(entry_p contxt)
{
    // We need a sane context. Arguments
    // are optional though.
    if(c_sane(contxt, 1))
    {
        RNUM(1);
    }

    // Broken parser / OOM
    PANIC(contxt);

    // Failure.
    RCUR;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
entry_p m_closewbobject(entry_p contxt)
{
    // We need a sane context. Arguments
    // are optional though.
    if(c_sane(contxt, 1))
    {
        RNUM(1);
    }

    // Broken parser / OOM
    PANIC(contxt);

    // Failure.
    RCUR;
}
