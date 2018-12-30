//----------------------------------------------------------------------------
// media.c:
//
// Multimedia features
//----------------------------------------------------------------------------
// Copyright (C) 2018, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//----------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "file.h"
#include "media.h"
#include "util.h"

//----------------------------------------------------------------------------
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//----------------------------------------------------------------------------
entry_p m_closemedia(entry_p contxt)
{
    // We need 1 argument.
    if(c_sane(contxt, 1))
    {
		// Dummy.
		pretty_print(contxt);
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
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//----------------------------------------------------------------------------
entry_p m_effect(entry_p contxt)
{
    // We need 4 arguments.
    if(c_sane(contxt, 4))
    {
		// Dummy.
		pretty_print(contxt);
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
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//----------------------------------------------------------------------------
entry_p m_setmedia(entry_p contxt)
{
    // We need atleast 2 arguments.
    if(c_sane(contxt, 2))
    {
		// Dummy.
		pretty_print(contxt);
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
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//----------------------------------------------------------------------------
entry_p m_showmedia(entry_p contxt)
{
    // We need atleast 5 arguments.
    if(c_sane(contxt, 5))
    {
		// Dummy.
		pretty_print(contxt);
    }
    else
    {
        // Broken parser.
        PANIC(contxt);
    }

    // Success, failure or panic.
    RCUR;
}
