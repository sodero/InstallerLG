//------------------------------------------------------------------------------
// comparison.c:
//
// Comparison operators
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
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
// Description: Test if both arguments can be interpreted as numbers.
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
// Description: Test if both arguments can be treated as strings.
// Input:       entry_p lhs:    Left argument.
//              entry_p rhs:    Right argument.
// Return:      bool:           'true' or 'false'.
//------------------------------------------------------------------------------
static bool h_cmp_strings(entry_p alfa, entry_p beta)
{
    // Don't trust strings, we might be out of memory.
    return alfa->type == STRING && alfa->name != NULL && beta->type == STRING &&
           beta->name != NULL;
}

//------------------------------------------------------------------------------
// Name:        h_cmp_string_0
// Description: Test if string can be treated as zero.
// Input:       entry_p alfa:   String.
// Return:      bool:           'true' if zero, false 'false'.
//------------------------------------------------------------------------------
static bool h_cmp_string_0(entry_p alfa)
{
    return alfa->name != NULL && alfa->name[0] == '0' && alfa->name[1] == '\0';
}

//------------------------------------------------------------------------------
// Name:        h_cmp_mixed
// Description: Compare arguments of different primitive types.
// Input:       entry_p lhs:    Left argument.
//              entry_p rhs:    Right argument.
// Return:      int32_t:        Left - right.
//------------------------------------------------------------------------------
static int32_t h_cmp_mixed(entry_p alfa, entry_p beta)
{
    if(alfa->type == STRING && alfa->name != NULL)
    {
        // Empty strings are less than all numbers.
        if(*alfa->name == '\0')
        {
            // Alfa < Beta.
            return -1;
        }

        // Do we have a number != 0 or a '0' string?
        if(num(alfa) != 0 || h_cmp_string_0(alfa))
        {
            return num(alfa) - beta->id;
        }
    }

    // Beta is a string. A nonzero number or a '0' string?
    if(num(beta) != 0 || h_cmp_string_0(beta))
    {
        return alfa->id - num(beta);
    }

    // Alfa > Beta.
    return 1;
}

//------------------------------------------------------------------------------
// Name:        h_cmp
// Description: Helper function for n_eq, n_gt, n_gte, n_lt, n_lte, n_ne.
// Input:       entry_p lhs:    Left argument.
//              entry_p rhs:    Right argument.
// Return:      int32_t:        Left - right.
//------------------------------------------------------------------------------
static int32_t h_cmp(entry_p lhs, entry_p rhs)
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
        return (int32_t) strcmp(alfa->name, beta->name);
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
entry_p n_eq(entry_p contxt)
{
    // Contrary to what the documentation says, the CBM implementation accepts
    // a single argument. This is obviously a bug, but let's support it anyway
    // since it can be found in some broken scripts.
    C_SANE(1, NULL);

    // Translate the result of h_cmp or return 'true' dummy value.
    R_NUM(exists(C_ARG(2)) && h_cmp(C_ARG(1), C_ARG(2)) != 0 ? LG_FALSE :
                                                               LG_TRUE);
}

//------------------------------------------------------------------------------
// (< <expr1> <expr2>)
//     greater than test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_gt(entry_p contxt)
{
    // Contrary to what the documentation says, the CBM implementation accepts
    // a single argument. This is obviously a bug, but let's support it anyway
    // since it can be found in some broken scripts.
    C_SANE(1, NULL);

    // Translate the result of h_cmp or return 'true' dummy value.
    R_NUM(exists(C_ARG(2)) && h_cmp(C_ARG(1), C_ARG(2)) <= 0 ? LG_FALSE :
                                                               LG_TRUE);
}

//------------------------------------------------------------------------------
// (>= <expr1> <expr2>)
//     greater than or equal test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_gte(entry_p contxt)
{
    // Contrary to what the documentation says, the CBM implementation accepts
    // a single argument. This is obviously a bug, but let's support it anyway
    // since it can be found in some broken scripts.
    C_SANE(1, NULL);

    // Translate the result of h_cmp or return 'true' dummy value.
    R_NUM(exists(C_ARG(2)) && h_cmp(C_ARG(1), C_ARG(2)) < 0 ? LG_FALSE :
                                                              LG_TRUE);
}

//------------------------------------------------------------------------------
// (< <expr1> <expr2>)
//     less than test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_lt(entry_p contxt)
{
    // Contrary to what the documentation says, the CBM implementation accepts
    // a single argument. This is obviously a bug, but let's support it anyway
    // since it can be found in some broken scripts.
    C_SANE(1, NULL);

    // Translate the result of h_cmp or return 'true' dummy value.
    R_NUM(exists(C_ARG(2)) && h_cmp(C_ARG(1), C_ARG(2)) >= 0 ? LG_FALSE :
                                                               LG_TRUE);
}

//------------------------------------------------------------------------------
// (<= <expr1> <expr2>)
//     less than or equal test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_lte(entry_p contxt)
{
    // Contrary to what the documentation says, the CBM implementation accepts
    // a single argument. This is obviously a bug, but let's support it anyway
    // since it can be found in some broken scripts.
    C_SANE(1, NULL);

    // Translate the result of h_cmp or return 'true' dummy value.
    R_NUM(exists(C_ARG(2)) && h_cmp(C_ARG(1), C_ARG(2)) > 0 ? LG_FALSE :
                                                              LG_TRUE);
}

//------------------------------------------------------------------------------
// (<> <expr1> <expr2>)
//     inequality test (returns 0 or 1)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_neq(entry_p contxt)
{
    // Contrary to what the documentation says, the CBM implementation accepts
    // a single argument. This is obviously a bug, but let's support it anyway
    // since it can be found in some broken scripts.
    C_SANE(1, NULL);

    // Translate the result of h_cmp or return 'false' dummy value.
    R_NUM(exists(C_ARG(2)) && h_cmp(C_ARG(1), C_ARG(2)) != 0 ? LG_TRUE :
                                                               LG_FALSE);
}
