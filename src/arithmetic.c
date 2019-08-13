//------------------------------------------------------------------------------
// arithmetic.c:
//
// Arithmetic operations
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
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
entry_p m_add(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, NULL);

    // The sum.
    int sum = 0;

    // Sum up the values of all children.
    for(entry_p *cur = contxt->children; *cur && *cur != end(); cur++)
    {
        sum += num(*cur);
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
entry_p m_div(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Do not divide by zero.
    int div = num(C_ARG(2));

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
entry_p m_mul(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, NULL);

    // The product.
    int pro = 1;

    // Multiply the values of all children.
    for(entry_p *cur = contxt->children; *cur && *cur != end(); cur++)
    {
        pro *= num(*cur);
    }

    // Return product.
    R_NUM(pro);
}

//------------------------------------------------------------------------------
// (- <expr1> <expr2>)
//     returns `<expr1>' minus `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_sub(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Return difference.
    R_NUM(num(C_ARG(1)) - num(C_ARG(2)));
}
