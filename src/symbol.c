//------------------------------------------------------------------------------
// symbol.c:
//
// Symbol manipulation
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "symbol.h"
#include "util.h"
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------------------------------
// Name:        h_copy_deep
// Description: Do a deep copy of an entry.
// Input:       entry_p entry:      The entry to be copied.
// Return:      entry_p:            A copy of 'entry' or NULL on failure.
//------------------------------------------------------------------------------
static entry_p h_copy_deep(entry_p entry)
{
    entry_p copy = DBG_ALLOC(malloc(sizeof(entry_t)));

    if(!copy && PANIC(entry))
    {
        return NULL;
    }

    // Do a straight copy of everything.
    memmove(copy, entry, sizeof(entry_t));

    // Copy string value if there is one.
    if(entry->name)
    {
        copy->name = DBG_ALLOC(strdup(entry->name));

        if(!copy->name && PANIC(entry))
        {
            free(copy);
            return NULL;
        }
    }

    return copy;
}

//------------------------------------------------------------------------------
// Name:        h_set_undangle
// Description: n_set helper. Cast entry to a non-dangling type.
// Input:       entry_p entry:  The entry to be cast.
// Return:      -
//------------------------------------------------------------------------------
static void h_set_undangle(entry_p entry)
{
    // In non strict mode we might have a DANGLE on the right hand side if a
    // bogus resolve was done. To prevent leaks after a deep copy we need to
    // typecast the RHS.
    if(!entry || entry->type != DANGLE)
    {
        return;
    }

    // Typecast to string. The string will be empty. If evaluated as a number,
    // it will be zero.
    entry->type = STRING;
}

//------------------------------------------------------------------------------
// Name:        h_set_find
// Description: n_set helper. Find symbol with a given name in symbol array.
// Input:       entry_p contxt:     Execution context.
//              const char *name:   Symbol name.
// Return:      entry_p:            The symbol if found, NULL otherwise.
//------------------------------------------------------------------------------
static entry_p h_set_find(entry_p contxt, const char *name)
{
    if(!contxt || !contxt->symbols || !name)
    {
        // No search possible.
        return NULL;
    }

    // Iterate over all symbols in the current context.
    for(entry_p *cur = contxt->symbols; exists(*cur); cur++)
    {
        if(!strcasecmp((*cur)->name, name))
        {
            // Found it.
            return *cur;
        }
    }

    // Not found.
    return NULL;
}

//------------------------------------------------------------------------------
// (set <varname> <value> [<varname2> <value2> ...])
//      sets the variable `<varname>' to the indicated value.
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_set(entry_p contxt)
{
    // We need atleast one symbol value tuple.
    C_SANE(1, NULL); S_SANE(1);

    // Function argument tuples.
    entry_p *sym = contxt->symbols, *val = contxt->children;

    // Iterate over all symbol -> value tuples
    while(exists(*sym) && exists(*val))
    {
        // Resolve the RHS and do a deep copy of it.
        entry_p rhs = resolve(*val), dst = global(contxt),
                res = DID_ERR ? NULL : h_copy_deep(rhs);

        if(!res)
        {
            // Error / out of memory.
            return end();
        }

        // Make sure the RHS isn't dangling, we'll leak memory if it does.
        h_set_undangle(res);

        // Reparent and create global reference.
        res->parent = *sym;
        kill((*sym)->resolved);
        (*sym)->resolved = res;

        // Push cannot fail in this context.
        push(dst, *sym);
        (*sym)->parent = contxt;

        // We're at the end of the list when both are NULL or end().
        if(*(++sym) == *(++val))
        {
            return res;
        }
    }

    // Broken parser.
    PANIC(contxt);
    return end();
}

//------------------------------------------------------------------------------
// (symbolset <symbolname> <expression>)
//     assign a value to a variable named by the string result of
//     `<symbolname>' (V42.9)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_symbolset(entry_p contxt)
{
    // We need one or more tuples of symbol name and value.
    C_SANE(2, NULL); S_SANE(0);

    entry_p ret = end();

    // Iterate over all name -> value tuples
    for(entry_p *cur = contxt->children; exists(*cur);)
    {
        // Resolve LHS and RHS and do a deep copy of RHS.
        const char *lhs = str(*cur++);
        entry_p rhs = resolve(*cur++), res = DID_ERR ? NULL : h_copy_deep(rhs);

        if(!res)
        {
            // Error / out of memory.
            return end();
        }

        // Make sure the RHS isn't dangling, we'll leak memory if it does.
        h_set_undangle(res);

        // Do we have an existing symbol with this name?
        entry_p esm = h_set_find(contxt, lhs);

        if(esm)
        {
            // Reparent and continue with the next tuple.
            kill(esm->resolved);
            esm->resolved = res;

            // Push cannot fail in this context.
            push(global(contxt), esm);
            res->parent = esm;
            ret = res;
        }
        else
        {
            // Append new symbol to current context.
            entry_p nsm = new_symbol(DBG_ALLOC(strdup(lhs)));

            if(!nsm || !append(&contxt->symbols, nsm))
            {
                kill(nsm);
                kill(res);
                return end();
            }

            // Reparent and create global reference.
            res->parent = nsm;
            nsm->resolved = res;

            // Push cannot fail in this context.
            push(global(contxt), nsm);
            nsm->parent = contxt;
            ret = res;
        }
    }

    // Return the last RHS.
    return ret;
}

//------------------------------------------------------------------------------
// (symbolval <symbolname>)
//     returns the value of the symbol named by the string expression
//     `<symbolname>' (V42.9)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_symbolval(entry_p contxt)
{
    // We need one argument, the name of the symbol.
    C_SANE(1, NULL);

    static entry_t entry = { .type = SYMREF };
    entry_p ret;

    // Initialize and resolve dummy.
    entry.parent = contxt;
    entry.id = contxt->id;
    entry.name = str(C_ARG(1));

    ret = resolve(&entry);

    // Return the resolved value if the symbol could be found.
    if(!DID_ERR)
    {
        return ret;
    }

    // Symbol not found.
    R_NUM(LG_FALSE);
}
