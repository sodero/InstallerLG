//------------------------------------------------------------------------------
// logic.c:
//
// Logic operations
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "logic.h"
#include "error.h"
#include "eval.h"
#include "util.h"

//------------------------------------------------------------------------------
// (AND <expr1> <expr2>)
//     returns logical `AND' of `<expr1>' and `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// The 3.9 implementation supports any number of arguments. Since this seems to
// be used by several installers, we'll support it.
//------------------------------------------------------------------------------
entry_p m_and(entry_p contxt)
{
    // Two or more arguments.
    C_SANE(2, NULL);

    // Return false if any of the children are false.
    for(entry_p *cur = contxt->children; exists(*cur); cur++)
    {
        if(!num(*cur))
        {
            R_NUM(LG_FALSE);
        }
    }

    // All children are true.
    R_NUM(LG_TRUE);
}

//------------------------------------------------------------------------------
// (BITAND <expr1> <expr2>)
//     returns bitwise `AND' of `<expr1>' and `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_bitand(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Set and return.
    R_NUM(num(C_ARG(1)) & num(C_ARG(2)));
}

//------------------------------------------------------------------------------
// (BITNOT <expr>)
//     returns bitwise `NOT' of `<expr>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_bitnot(entry_p contxt)
{
    // One argument.
    C_SANE(1, NULL);

    // Set and return.
    R_NUM(~num(C_ARG(1)));
}

//------------------------------------------------------------------------------
// (BITOR <expr1> <expr2>)
//     returns bitwise `OR' of `<expr1>' and `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_bitor(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Set and return.
    R_NUM(num(C_ARG(1)) | num(C_ARG(2)));
}

//------------------------------------------------------------------------------
// (BITXOR <expr1> <expr2>)
//     returns bitwise `XOR' of `<expr1>' and `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_bitxor(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Set and return.
    R_NUM(num(C_ARG(1)) ^ num(C_ARG(2)));
}

//------------------------------------------------------------------------------
// (NOT <expr>)
//     returns logical `NOT' of `<expr>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_not(entry_p contxt)
{
    // One argument.
    C_SANE(1, NULL);

    // Set and return.
    R_NUM(!num(C_ARG(1)));
}

//------------------------------------------------------------------------------
// (IN <expr> <bit-number> <bitnumber>...)
//     returns `<expr>' `AND' bits
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_in(entry_p contxt)
{
    // Two or more arguments.
    C_SANE(2, NULL);

    // Bitmask.
    int mask = 0;

    // Create the bitmask of all children.
    for(entry_p *cur = C_ARG(2)->children; exists(*cur); cur++)
    {
        // Add current bit to the mask.
        mask += 1 << num(*cur);
    }

    // Apply the bitmask to the first argument and return the result.
    R_NUM(num(C_ARG(1)) & mask);
}

//------------------------------------------------------------------------------
// (OR <expr1> <expr2>)
//     returns logical `OR' of `<expr1>' and `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// The 3.9 implementation supports any number of arguments. Since this seems to
// be used by several installers, we'll support it.
//------------------------------------------------------------------------------
entry_p m_or(entry_p contxt)
{
    // Two or more arguments.
    C_SANE(2, NULL);

    // Return true if any of the children are true.
    for(entry_p *cur = contxt->children; exists(*cur); cur++)
    {
        if(num(*cur))
        {
            R_NUM(LG_TRUE);
        }
    }

    // All children were false.
    R_NUM(LG_FALSE);
}

//------------------------------------------------------------------------------
// (shiftleft <number> <amount to shift>)
//     logical shift left
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_shiftleft(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Set and return.
    R_NUM(num(C_ARG(1)) << num(C_ARG(2)));
}

//------------------------------------------------------------------------------
// (shiftright <number> <amount to shift>)
//     logical shift right
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_shiftright(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Set and return.
    R_NUM(num(C_ARG(1)) >> num(C_ARG(2)));
}

//------------------------------------------------------------------------------
// (XOR <expr1> <expr2>)
//     returns logical `XOR' of `<expr1>' and `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_xor(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Two possible combinations.
    bool alfa = num(C_ARG(1)) && !num(C_ARG(2)),
         beta = num(C_ARG(2)) && !num(C_ARG(1));

    // Set and return.
    R_NUM(alfa || beta);
}
