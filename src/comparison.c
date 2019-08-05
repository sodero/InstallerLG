//------------------------------------------------------------------------------
// comparison.c:
//
// Comparison operators
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "comparison.h"
#include "error.h"
#include "eval.h"
#include "util.h"
#include <string.h>

//------------------------------------------------------------------------------
// < <= == >= >
//     helper function for m_eq, m_gt, m_gte, m_lt, m_lte, m_ne.
//------------------------------------------------------------------------------
static int h_cmp(entry_p lhs, entry_p rhs)
{
    // Resolve both arguments. We don't need to check for failures; we will
    // always get something to compare.
    entry_p alfa = resolve(lhs), beta = resolve(rhs);

    // Numbers and dangles can be treated as equals.
    if((alfa->type == NUMBER || alfa->type == DANGLE) &&
       (beta->type == NUMBER || beta->type == DANGLE))
    {
        return alfa->id - beta->id;
    }

    // Use normal string comparison if both arguments are strings.
    if(alfa->type == STRING && alfa->name && beta->type == STRING && beta->name)
    {
        return strcmp(alfa->name, beta->name);
    }

    // We have a string and a number / dangle. Is the first argument a string?
    if(alfa->type == STRING && alfa->name)
    {
        // Empty strings are less than all numbers.
        if(!(*alfa->name))
        {
            // Alfa < Beta.
            return -1;
        }

        // Do we have a number != 0 or a '0' string?
        if(num(alfa) || (alfa->name[0] == '0' && !alfa->name[1]))
        {
            return num(alfa) - beta->id;
        }
    }

    // Beta is a string. A nonzero number or a '0' string?
    if(num(beta) || (beta->name && beta->name[0] == '0' && !beta->name[1]))
    {
        return alfa->id - num(beta);
    }

    // Alfa > Beta.
    return 1;
}

//------------------------------------------------------------------------------
// (= <expr1> <expr2>)
//     equality test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_eq(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Turn the result of h_cmp into 1 or 0.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) ? 0 : 1);
}

//------------------------------------------------------------------------------
// (< <expr1> <expr2>)
//     greater than test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_gt(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Turn the result of h_cmp into 0 or 1.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) > 0 ? 1 : 0);
}

//------------------------------------------------------------------------------
// (>= <expr1> <expr2>)
//     greater than or equal test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_gte(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Turn the result of h_cmp into 0 or 1.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) >= 0 ? 1 : 0);
}

//------------------------------------------------------------------------------
// (< <expr1> <expr2>)
//     less than test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_lt(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Turn the result of h_cmp into 0 or 1.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) < 0 ? 1 : 0);
}

//------------------------------------------------------------------------------
// (<= <expr1> <expr2>)
//     less than or equal test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_lte(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Turn the result of h_cmp into 0 or 1.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) <= 0 ? 1 : 0);
}

//------------------------------------------------------------------------------
// (<> <expr1> <expr2>)
//     inequality test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_neq(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // Turn the result of h_cmp into 0 or 1.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) ? 1 : 0);
}
