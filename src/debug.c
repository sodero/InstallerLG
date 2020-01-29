//------------------------------------------------------------------------------
// debug.c:
//
// Low level grammar debugging utility functions.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "debug.h"
#include "util.h"

//------------------------------------------------------------------------------
// (___astraw)
//     Dump the complete AST to the debug console. Depending on where in the
//     script this statement is located, parts of the AST might already have
//     been resolved before the dump.
//
// Please note the ___ prefix. This is not meant to be used by end users.
//------------------------------------------------------------------------------
entry_p m_astraw(entry_p contxt)
{
    // No arguments.
    C_SANE(0, NULL);

    // Dump without resolving.
    dump(global(contxt));

    // Dummy value.
    R_NUM(LG_TRUE);
}

//------------------------------------------------------------------------------
// (___asbraw <statement>)
//     Dump the raw non-evaluated <statement> AST branch to the debug console.
//
// Please note the ___ prefix. This is not meant to be used by end users.
//------------------------------------------------------------------------------
entry_p m_asbraw(entry_p contxt)
{
    // One argument.
    C_SANE(1, NULL);

    // Dump argument without resolving.
    dump(C_ARG(1));

    // Dummy value.
    R_NUM(LG_TRUE);
}

//------------------------------------------------------------------------------
// (___asbeval <statement>)
//     Dump the evaluated <statement> AST branch to the debug console. By doing
//     so all side effects of <statement> will take effect before the dump.
//
// Please note the ___ prefix. This is not meant to be used by end users.
//------------------------------------------------------------------------------
entry_p m_asbeval(entry_p contxt)
{
    // One argument.
    C_SANE(1, NULL);

    // Resolve argument and ignore the result.
    resolve(C_ARG(1));

    // Dump resolved argument.
    dump(C_ARG(1));

    // Dummy value.
    R_NUM(LG_TRUE);
}
