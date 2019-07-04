//----------------------------------------------------------------------------
// comparison.c:
//
// Comparison operators
//----------------------------------------------------------------------------
// Copyright (C) 2018, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//----------------------------------------------------------------------------

#include "alloc.h"
#include "comparison.h"
#include "error.h"
#include "eval.h"
#include "util.h"
#include <string.h>

//----------------------------------------------------------------------------
// < <= == >= >
//     helper function for m_eq, m_gt, m_gte, m_lt, m_lte, m_ne.
//----------------------------------------------------------------------------
static int h_cmp(entry_p lhs, entry_p rhs)
{
    // Resolve both arguments. We don't need
    // to check for failures; we will always
    // get something to compare.
    entry_p alfa = resolve(lhs);
    entry_p beta = resolve(rhs);

    // If both arguments are strings then use
    // string comparison. Don't trust strings
    // since we might be out of memory.
    if(alfa->type == STRING &&
       beta->type == STRING &&
       alfa->name && beta->name)
    {
        return strcmp(alfa->name, beta->name);
    }

    // Quirky treatment of comparisons between
    // the constant 0 and strings. The original
    // implementation is not very stringent when
    // evaluating strings. Let's create the same
    // mess here to be fully compatible.
    if((alfa == lhs && !alfa->id &&
        alfa->type == NUMBER &&
        beta->type == STRING &&
        beta->name) ||
       (beta == rhs && !beta->id &&
        beta->type == NUMBER &&
        alfa->type == STRING &&
        alfa->name))
    {
        char *val = alfa->type == STRING ?
                    alfa->name : beta->name;

        // Strings not equal to "0" are != 0.
        if(!val[0] || val[0] != '0')
        {
            // Not 0.
            return 1;
        }
    }

    // Otherwise convert whatever we have to
    // numerical values and subtract.
    return num(alfa) - num(beta);
}

//----------------------------------------------------------------------------
// (= <expr1> <expr2>)
//     equality test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_eq(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Turn the result of h_cmp into 1 or 0.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) ? 0 : 1);
}

//----------------------------------------------------------------------------
// (< <expr1> <expr2>)
//     greater than test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_gt(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Turn the result of h_cmp into 0 or 1.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) > 0 ? 1 : 0);
}

//----------------------------------------------------------------------------
// (>= <expr1> <expr2>)
//     greater than or equal test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_gte(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Turn the result of h_cmp into 0 or 1.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) >= 0 ? 1 : 0);
}

//----------------------------------------------------------------------------
// (< <expr1> <expr2>)
//     less than test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_lt(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Turn the result of h_cmp into 0 or 1.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) < 0 ? 1 : 0);
}

//----------------------------------------------------------------------------
// (<= <expr1> <expr2>)
//     less than or equal test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_lte(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Turn the result of h_cmp into 0 or 1.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) <= 0 ? 1 : 0);
}

//----------------------------------------------------------------------------
// (<> <expr1> <expr2>)
//     inequality test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_neq(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Turn the result of h_cmp into 0 or 1.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) ? 1 : 0);
}
