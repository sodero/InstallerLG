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

    // Exit on OOM.
    LG_ASSERT(copy, NULL);

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
    // We need atleast one symbol. The CBM installer tolerates constructs such
    // as (set a). In that case 'a' will simply be ignored.
    C_SANE(0, NULL); S_SANE(1);
//dump(contxt);
    // Function argument symbol value tuples.
    entry_p *sym = contxt->symbols, *val = contxt->children;

    while(exists(*sym) && exists(*val))
    {
        // Resolve the RHS value.
        entry_p rhs = resolve(*val);

        if(DID_ERR)
        {
            // Unresolvable.
            return end();
        }

        // Sloppy mode dangle.
        entry_p res = end();

        if(rhs != end())
        {
            // Do a deep copy the resolved RHS.
            res = h_copy_deep(rhs);

            // Exit on OOM.
            LG_ASSERT(res, end());

            // Reparent and create global reference.
            res->parent = *sym;
            kill((*sym)->resolved);
            (*sym)->resolved = res;

            // Push cannot fail in this context.
            push(global(contxt), *sym);
            (*sym)->parent = contxt;
        }

        // We're at the end of the list when both are NULL or end().
        if(*(++sym) == *(++val))
        {
            return res;
        }
    }

    // Broken list of tuples.
    return end();
}

//------------------------------------------------------------------------------
// Name:        h_symbolset_exists
// Description: Update symbol in current context.
// Input:       entry_p contxt:     Execution context.
//              entry_p esm:        Existing symbol.
//              entry_p res:        New resolved value.
// Return:      entry_p:            The existing symbol.
//------------------------------------------------------------------------------
static entry_p n_symbolset_exists(entry_p contxt, entry_p esm, entry_p res)
{
    // Replace resolved value of existing symbol.
    kill(esm->resolved);
    esm->resolved = res;

    // Push cannot fail in this context.
    push(global(contxt), esm);
    res->parent = esm;

    // Pass the result.
    return res;
}

//------------------------------------------------------------------------------
// Name:        h_symbolset_new
// Description: Create new named symbol in current context.
// Input:       entry_p contxt:     Execution context.
//              const char *:       Symbol name.
//              entry_p res:        Initial resolved value.
// Return:      entry_p:            The newly created symbol.
//------------------------------------------------------------------------------
static entry_p n_symbolset_new(entry_p contxt, const char *lhs, entry_p res)
{
    // Append new symbol to current context.
    entry_p nsm = new_symbol(DBG_ALLOC(strdup(lhs)));

    if(!nsm || !append(&contxt->symbols, nsm))
    {
        kill(nsm);
        kill(res);

        // Fallback.
        return end();
    }

    // Reparent and create global reference.
    nsm->resolved = res;
    res->parent = nsm;

    // Push cannot fail in this context.
    push(global(contxt), nsm);
    nsm->parent = contxt;

    // Pass the result.
    return res;
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
    // We need atleast one symbol. The CBM installer tolerates constructs such
    // as (symbolset "a"). In that case 'a' will simply be ignored.
    C_SANE(1, NULL); S_SANE(0);

    entry_p ret = end();

    // Iterate over all name value tuples
    for(size_t cur = 1; exists(C_ARG(cur)) && exists(C_ARG(cur + 1)); cur += 2)
    {
        // Resolve LHS and RHS.
        const char *lhs = str(C_ARG(cur));
        entry_p rhs = resolve(C_ARG(cur + 1));

        if(DID_ERR)
        {
            // Unresolvable.
            return end();
        }

        if(rhs == end())
        {
            // Sloppy mode dangle.
            continue;
        }

        // Do a deep copy the resolved RHS.
        entry_p res = h_copy_deep(rhs);

        // Exit on OOM.
        LG_ASSERT(res, end());

        // Does this symbol already exist?
        entry_p esm = h_set_find(contxt, lhs);

        // Create new or update existing symbol.
        ret = esm ? n_symbolset_exists(contxt, esm, res) :
                    n_symbolset_new(contxt, lhs, res);
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
    if(NOT_ERR)
    {
        return ret;
    }

    // Symbol not found.
    R_NUM(LG_FALSE);
}
