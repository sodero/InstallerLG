//------------------------------------------------------------------------------
// symbol.c:
//
// Symbol manipulation
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
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
// Name:        h_copydeep
// Description: Do a deep copy of an entry.
// Input:       entry_p entry:      The entry to be copied.
// Return:      entry_p:               If confirmed 'true' else 'false'. Both
//                                  skip and abort will return 'false'.
//------------------------------------------------------------------------------
static entry_p h_copydeep(entry_p entry)
{
    entry_p copy = DBG_ALLOC(malloc(sizeof(entry_t)));

    if(!copy && PANIC(entry))
    {
        // Out of memory.
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
            // Out of memory.
            free(copy);
        }
    }

    return copy;
}

//------------------------------------------------------------------------------
// (set <varname> <value> [<varname2> <value2> ...])
//      sets the variable `<varname>' to the indicated value.
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_set(entry_p contxt)
{
    // We need atleast one symbol value tuple.
    C_SANE(1, NULL); S_SANE(1);

    // Function argument tuples.
    entry_p *sym = contxt->symbols, *val = contxt->children;

    // The custom procedure contxt if we're in one. If so we need to handle
    // local variables (args).
    entry_p cus = custom(contxt);

    // Iterate over all symbol -> value tuples
    while(exists(*sym) && exists(*val))
    {
        // Resolve the right hand side before setting the symbol value.
        entry_p rhs = resolve(*val);
        entry_p dst = global(contxt);

        if(DID_ERR)
        {
            // Ignore the rest of the tuples if resolve failed.
            break;
        }

        if(cus)
        {
            // If we are within the contxt of a custom procedure? determine if
            // this particular symbol is one of the local ones (arguments), if
            // it is, the local context should be the target.
            for(entry_p *cur = cus->symbols; cur && exists(*cur); cur++)
            {
                // As always with symbols, ignore the case.
                if(!strcasecmp((*cur)->name, (*sym)->name))
                {
                    // Set destination to the local context if we have a match.
                    dst = cus;
                }
            }
        }

        // Create a copy of the contents of the rhs.
        entry_p res = h_copydeep(rhs);

        if(!res)
        {
            // PANIC in h_copydeep() if we're  out of memory.
            break;
        }

        // In non strict mode we might have a DANGLE on the right hand side if a
        // bogus resolve was done. To prevent leaks we need to typecast the rhs.
        if(res->type == DANGLE)
        {
            // Typecast to string. The string will be empty. If evaluated as a
            // number, it will be zero.
            res->type = STRING;
        }

        // Reparent the value and free the old resolved value if any, and create
        // a reference from the global context to the symbol.
        res->parent = *sym;
        kill((*sym)->resolved);
        (*sym)->resolved = res;
        push(dst, *sym);
        (*sym)->parent = contxt;

        if(*(++sym) == *(++val))
        {
            // We're at the end of the list.
            return res;
        }
    }

    // Unresolvable right hand side or broken parser.
    return end();
}

//------------------------------------------------------------------------------
// (symbolset <symbolname> <expression>)
//     assign a value to a variable named by the string result of
//     `<symbolname>' (V42.9)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_symbolset(entry_p contxt)
{
    // Symbol destination.
    entry_p dst = global(contxt);

    // We need one or more tuples of symbol name and value.
    if(c_sane(contxt, 2) && dst)
    {
        entry_p ret = D_CUR;
        entry_p *cur = contxt->children;

        // Iterate over all tuples.
        while(exists(*cur))
        {
            // Resolve symbol name and value.
            const char *lhs = str(*cur++);
            entry_p rhs = resolve(*cur++);

            if(DID_ERR)
            {
                // Error set by resolve() if rhs is unresolvable.
                R_CUR;
            }

            // Create a copy of the evaluated rhs.
            entry_p res = h_copydeep(rhs);

            if(!res)
            {
                // PANIC in h_copydeep() if we're  out of memory.
                R_CUR;
            }

            // In non strict mode we might have a DANGLE on the right hand side
            // if a bogus resolve was done. Typecast rhs to prevent leaks.
            if(res->type == DANGLE)
            {
                // Typecast to string. The string will be empty. If evaluated as
                // a number, it will be zero.
                res->type = STRING;
            }

            // Do we already have a symbol with this name?
            for(entry_p *sym = contxt->symbols; exists(*sym); sym++)
            {
                // If true, replace its resolved value with the copy of the rhs.
                if(!strcasecmp((*sym)->name, lhs))
                {
                    kill((*sym)->resolved);
                    (*sym)->resolved = res;
                    push(dst, *sym);
                    res->parent = *sym;
                    ret = res;
                    break;
                }

                // Iterate over all symbols in this context.
                sym++;
            }

            if(ret == res)
            {
                // Pick the next tuple this symbol already exists.
                continue;
            }

            // This is a new symbol.
            entry_p nsm = new_symbol(DBG_ALLOC(strdup(lhs)));

            if(!nsm && PANIC(contxt))
            {
                // Out of memory.
                kill(res);
                break;
            }

            res->parent = nsm;
            nsm->resolved = res;

            // Append the symbol to the current context and create a global ref.
            if(append(&contxt->symbols, nsm))
            {
                push(dst, nsm);
                nsm->parent = contxt;
                ret = res;
                continue;
            }

            // Out of memory.
            kill(nsm);
            kill(res);
        }

        // Return the last rhs.
        return ret;
    }

    // Broken parser
    R_CUR;
}

//------------------------------------------------------------------------------
// (symbolval <symbolname>)
//     returns the value of the symbol named by the string expression
//     `<symbolname>' (V42.9)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_symbolval(entry_p contxt)
{
    // We need one argument, the name of the symbol.
    if(c_sane(contxt, 1))
    {
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

    // The parser is broken
    PANIC(contxt);
    R_CUR;
}
