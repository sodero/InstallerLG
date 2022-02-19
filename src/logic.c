//------------------------------------------------------------------------------
// logic.c:
//
// Logic operations
//------------------------------------------------------------------------------
// Copyright (C) 2018-2022, Ola Söder. All rights reserved.
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
// Contrary to what the documentation says, the 3.9 implementation supports any
// number of arguments greater than 0, including 1 (which doesn't make sense).
//------------------------------------------------------------------------------
entry_p n_and(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, NULL);

    // Start with the truth value of the first argument.
    uint32_t res = num(C_ARG(1)) ? LG_TRUE : LG_FALSE;

    // Repeat until there are no more arguments or one them is false.
    for(size_t arg = 2; res == LG_TRUE && exists(C_ARG(arg)); arg++)
    {
        res = num(C_ARG(arg)) ? LG_TRUE : LG_FALSE;
    }

    // Set and return.
    R_NUM(res);
}

//------------------------------------------------------------------------------
// (BITAND <expr1> <expr2>)
//     returns bitwise `AND' of `<expr1>' and `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// Contrary to what the documentation says, the 3.9 implementation supports any
// number of arguments greater than 0, including 1 (which doesn't make sense).
//------------------------------------------------------------------------------
entry_p n_bitand(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, NULL);

    // Set initial value to that of the first argument.
    uint32_t res = num(C_ARG(1));

    // Apply mask to the rest of the arguments, if any.
    for(size_t arg = 2; exists(C_ARG(arg)); arg++)
    {
        res &= num(C_ARG(arg));
    }

    // Set and return.
    R_NUM(res);
}

//------------------------------------------------------------------------------
// (BITNOT <expr>)
//     returns bitwise `NOT' of `<expr>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_bitnot(entry_p contxt)
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
//
// Contrary to what the documentation says, the 3.9 implementation supports any
// number of arguments greater than 0, including 1 (which doesn't make sense).
//------------------------------------------------------------------------------
entry_p n_bitor(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, NULL);

    // Set initial value to that of the first argument.
    uint32_t res = num(C_ARG(1));

    // Apply mask to the rest of the arguments, if any.
    for(size_t arg = 2; exists(C_ARG(arg)); arg++)
    {
        res |= num(C_ARG(arg));
    }

    // Set and return.
    R_NUM(res);
}

//------------------------------------------------------------------------------
// (BITXOR <expr1> <expr2>)
//     returns bitwise `XOR' of `<expr1>' and `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// Contrary to what the documentation says, the 3.9 implementation supports any
// number of arguments greater than 0, including 1 (which doesn't make sense).
//------------------------------------------------------------------------------
entry_p n_bitxor(entry_p contxt)
{
     // One or more arguments.
    C_SANE(1, NULL);

    // Set initial value to that of the first argument.
    uint32_t res = num(C_ARG(1));

    // XOR the rest of the arguments, if any.
    for(size_t arg = 2; exists(C_ARG(arg)); arg++)
    {
        res ^= num(C_ARG(arg));
    }

    // Set and return.
    R_NUM(res);
}

//------------------------------------------------------------------------------
// (NOT <expr>)
//     returns logical `NOT' of `<expr>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_not(entry_p contxt)
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
entry_p n_in(entry_p contxt)
{
    // Two or more arguments.
    C_SANE(2, NULL);

    // Bitmask.
    int32_t mask = 0;

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
// Contrary to what the documentation says, the 3.9 implementation supports any
// number of arguments greater than 0, including 1 (which doesn't make sense).
//------------------------------------------------------------------------------
entry_p n_or(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, NULL);

    // Start with the truth value of the first argument.
    uint32_t res = num(C_ARG(1)) ? LG_TRUE : LG_FALSE;

    // Repeat until there are no more arguments or one them is true.
    for(size_t arg = 2; res == LG_FALSE && exists(C_ARG(arg)); arg++)
    {
        res = num(C_ARG(arg)) ? LG_TRUE : LG_FALSE;
    }

    // Set and return.
    R_NUM(res);
}

//------------------------------------------------------------------------------
// (shiftleft <number> <amount to shift>)
//     logical shift left
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_shiftleft(entry_p contxt)
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
entry_p n_shiftright(entry_p contxt)
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
// Contrary to what the documentation says, the 3.9 implementation supports any
// number of arguments greater than 0, including 1 (which doesn't make sense).
//------------------------------------------------------------------------------
entry_p n_xor(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, NULL);

    // Start with the truth value of the first argument.
    uint32_t res = num(C_ARG(1)) ? LG_TRUE : LG_FALSE;

    // Repeat until there are no more arguments.
    for(size_t arg = 2; exists(C_ARG(arg)); arg++)
    {
        // Translate the current value to a truth value.
        uint32_t cur = num(C_ARG(arg)) ? LG_TRUE : LG_FALSE;

        // Return false if the current value equals the last one.
        if(cur == res)
        {
            R_NUM(LG_FALSE);
        }

        // Update the last value.
        res = cur;
    }

    // No equals or fall through.
    R_NUM(res);
}
