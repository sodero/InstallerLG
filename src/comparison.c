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
// Name:        h_cmp_numbers
// Description: Verify that both arguments can be interpreted as numbers.
// Input:       entry_p lhs:    Left argument.
//              entry_p rhs:    Right argument.
// Return:      bool:           'true' or 'false'.
//------------------------------------------------------------------------------
static bool h_cmp_numbers(entry_p alfa, entry_p beta)
{
    // Numbers and dangles can be treated as equals.
    return (alfa->type == NUMBER || alfa->type == DANGLE) &&
           (beta->type == NUMBER || beta->type == DANGLE);
}

//------------------------------------------------------------------------------
// Name:        h_cmp_strings
// Description: Verify that both arguments can be treated as strings.
// Input:       entry_p lhs:    Left argument.
//              entry_p rhs:    Right argument.
// Return:      bool:           'true' or 'false'.
//------------------------------------------------------------------------------
static bool h_cmp_strings(entry_p alfa, entry_p beta)
{
    // Do not trust strings, we might be out of memory.
    return alfa->type == STRING && alfa->name && beta->type == STRING &&
           beta->name;
}

//------------------------------------------------------------------------------
// Name:        h_cmp
// Description: Helper function for m_eq, m_gt, m_gte, m_lt, m_lte, m_ne.
// Input:       entry_p lhs:    Left argument.
//              entry_p rhs:    Right argument.
// Return:      int:            Left - right.
//------------------------------------------------------------------------------
static int h_cmp_mixed(entry_p alfa, entry_p beta)
{
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
// Name:        h_cmp
// Description: Helper function for m_eq, m_gt, m_gte, m_lt, m_lte, m_ne.
// Input:       entry_p lhs:    Left argument.
//              entry_p rhs:    Right argument.
// Return:      int:            Left - right.
//------------------------------------------------------------------------------
static int h_cmp(entry_p lhs, entry_p rhs)
{
    // Resolve both arguments. We don't need to check for failures; we will
    // always get something to compare.
    entry_p alfa = resolve(lhs), beta = resolve(rhs);

    // Do we have two numbers (or something that can be treated as such)?
    if(h_cmp_numbers(alfa, beta))
    {
        return alfa->id - beta->id;
    }

    // Use normal string comparison if both arguments are strings.
    if(h_cmp_strings(alfa, beta))
    {
        return strcmp(alfa->name, beta->name);
    }

    // We have a string and a number / dangle.
    return h_cmp_mixed(alfa, beta);
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

    // Translate the result of h_cmp.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) ? LG_FALSE : LG_TRUE);
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

    // Translate the result of h_cmp.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) > 0 ? LG_TRUE : LG_FALSE);
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

    // Translate the result of h_cmp.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) >= 0 ? LG_TRUE : LG_FALSE);
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

    // Translate the result of h_cmp.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) < 0 ? LG_TRUE : LG_FALSE);
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

    // Translate the result of h_cmp.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) <= 0 ? LG_TRUE : LG_FALSE);
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

    // Translate the result of h_cmp.
    R_NUM(h_cmp(C_ARG(1), C_ARG(2)) ? LG_TRUE : LG_FALSE);
}
