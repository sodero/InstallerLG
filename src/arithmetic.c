//------------------------------------------------------------------------------
// arithmetic.c:
//
// Arithmetic operations
//------------------------------------------------------------------------------
// Copyright (C) 2018-2023, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "arithmetic.h"
#include "error.h"
#include "eval.h"
#include "util.h"

//------------------------------------------------------------------------------
// (+ <expr1> <expr2> ...)
//     returns sum of expressions
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_add(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, NULL);

    // There is at least one addend.
    int32_t sum = num(C_ARG(1));

    // Add all remaining addends.
    for(size_t cur = 2; exists(C_ARG(cur)); cur++)
    {
        sum += num(C_ARG(cur));
    }

    // Return sum.
    R_NUM(sum);
}

//------------------------------------------------------------------------------
// (/ <expr1> <expr2>)
//     returns `<expr1>' divided by `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_div(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Do not divide by zero.
    int32_t div = num(C_ARG(2));

    if(!div)
    {
        // Division by zero.
        ERR(ERR_DIV_BY_ZERO, contxt->name);
        R_NUM(LG_FALSE);
    }

    // Return quotient.
    R_NUM(num(C_ARG(1)) / div);
}

//------------------------------------------------------------------------------
// (* <expr1> <expr2> ...)
//     returns product of expressions
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_mul(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, NULL);

    // There is at least one factor.
    int32_t pro = num(C_ARG(1));

    // Multiply all remaining factors.
    for(size_t cur = 2; exists(C_ARG(cur)); cur++)
    {
        pro *= num(C_ARG(cur));
    }

    // Return product.
    R_NUM(pro);
}

//------------------------------------------------------------------------------
// (- <expr1> <expr2>)
//     returns `<expr1>' minus `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// NOTE: Despite what the documentation says, the CBM implementation supports
//       any number of subtrahends. Mimic the implementation and ignore the
//       documentation.
//------------------------------------------------------------------------------
entry_p n_sub(entry_p contxt)
{
    // At least two arguments.
    C_SANE(2, NULL);

    // The minuend.
    int32_t dif = num(C_ARG(1));

    // Subtract all subtrahends.
    for(size_t cur = 2; exists(C_ARG(cur)); cur++)
    {
        dif -= num(C_ARG(cur));
    }

    // Return difference.
    R_NUM(dif);
}
