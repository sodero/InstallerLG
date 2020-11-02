//------------------------------------------------------------------------------
// alloc.c:
//
// Functions for allocation and management of entry_t data objects.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "control.h"
#include "procedure.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------------------------------
// Name:        new_contxt
// Description: Allocate CONTXT.
// Input:       -
// Return:      entry_p:    A CONTXT on success, NULL otherwise.
//------------------------------------------------------------------------------
entry_p new_contxt(void)
{
    // Memory for LG_VECLEN children and symbols, it will be grown if necessary.
    entry_p *children = DBG_ALLOC(calloc(LG_VECLEN + 1, sizeof(entry_p))),
            *symbols = DBG_ALLOC(calloc(LG_VECLEN + 1, sizeof(entry_p)));

    // We rely on everything being set to '0'
    entry_p entry = DBG_ALLOC(calloc(1, sizeof(entry_t)));

    if(entry && symbols && children)
    {
        entry->children = children;
        entry->symbols = symbols;
        entry->type = CONTXT;

        // Set sentinel values.
        entry->children[LG_VECLEN] = end();
        entry->symbols[LG_VECLEN] = end();
        return entry;
    }

    free(entry);
    free(symbols);
    free(children);

    (void) PANIC(NULL);
    return NULL;
}

//------------------------------------------------------------------------------
// Name:        new_number
// Description: Allocate NUMBER.
// Input:       int32_t num:    The initial value.
// Return:      entry_p:        A NUMBER on success, NULL otherwise.
//------------------------------------------------------------------------------
entry_p new_number(int32_t num)
{
    // We rely on everything being set to '0'
    entry_p entry = DBG_ALLOC(calloc(1, sizeof(entry_t)));

    if(entry)
    {
        // The value of a NUMBER equals its ID.
        entry->type = NUMBER;
        entry->id = num;
        return entry;
    }

    (void) PANIC(NULL);
    return NULL;
}

//------------------------------------------------------------------------------
// Name:        new_string
// Description: Allocate STRING.
// Input:       char *name:    A pointer to a null terminated string. The string
//                             won't be copied and it will be free:d by kill()
//                             so it must be allocated by the calling function.
// Return:      entry_p:       A STRING on success, NULL otherwise.
//------------------------------------------------------------------------------
entry_p new_string(char *name)
{
    // We rely on everything being set to '0'
    entry_p entry = DBG_ALLOC(calloc(1, sizeof (entry_t)));

    if(DBG_ADDR(name) && entry)
    {
        // The value of a string equals its name.
        entry->type = STRING;
        entry->name = name;
        return entry;
    }

    // We need to free 'name' also, since we own it.
    free(name);
    free(entry);

    (void) PANIC(NULL);
    return NULL;
}

//------------------------------------------------------------------------------
// Name:        new_symbol
// Description: Allocate SYMBOL.
// Input:       char *name: The name of the symbol. The string won't be copied
//                          and it will be free:d by kill() so it must be
//                          allocated by the calling function.
// Return:      entry_p:    A SYMBOL on success, NULL otherwise.
//------------------------------------------------------------------------------
entry_p new_symbol(char *name)
{
    // We rely on everything being set to '0'
    entry_p entry = DBG_ALLOC(calloc(1, sizeof(entry_t)));

    if(DBG_ADDR(name) && entry)
    {
        // The value of the symbol will dangle until the first (set).
        entry->resolved = end();
        entry->type = SYMBOL;
        entry->name = name;
        return entry;
    }

    // We need to free 'name' also, since we own it.
    free(name);
    free(entry);

    (void) PANIC(NULL);
    return NULL;
}

//------------------------------------------------------------------------------
// Name:        reparent_and_set
// Description: Reparent entries and set resolved value.
// Input:       entry_p *chl:   A vector with entries to reparent.
//              entry_p par:    Parent entry.
//              entry_p res:    Resolved value. If NULL no value will be set.
// Return:      -
//------------------------------------------------------------------------------
static void reparent_and_set(entry_p *chl, entry_p par, entry_p res)
{
    if(!chl || !par)
    {
        // Nothing to do.
        return;
    }

    // Reparent all given entries.
    for(entry_p *cur = chl; exists(*cur); cur++)
    {
        if(res)
        {
            // Set resolved value.
            (*cur)->resolved = res;
        }

        // Reparent current entry.
        (*cur)->parent = par;
    }
}

//------------------------------------------------------------------------------
// Name:        new_custom
// Description: Allocate CUSTOM, a user defined procedure / function.
// Input:       char *name:   The name of the function. This string won't be
//                            copied and it will be free:d by kill(...) so it
//                            must be allocated by the calling function.
//              int32_t line: The source code line number.
//              entry_p sym:  A CONTXT with symbols or NULL.
//              entry_p chl:  A CONTXT with children, functions.
// Return:      entry_p:      A CUSTOM on success, NULL otherwise.
//------------------------------------------------------------------------------
entry_p new_custom(char *name, int32_t line, entry_p sym, entry_p chl)
{
    // We rely on everything being set to '0'
    entry_p entry = DBG_ALLOC(calloc(1, sizeof(entry_t)));

    if(DBG_ADDR(name) && entry)
    {
        entry->type = CUSTOM;
        entry->name = name;
        entry->id = line;

        // Move symbols if we have any, adopt and clear the 'resolved' status.
        if(sym && sym->symbols)
        {
            // Transfer and kill the input.
            entry->symbols = sym->symbols;
            sym->symbols = NULL;
            kill(sym);

            // Reparent all symbols. Let the return value dangle.
            reparent_and_set(entry->symbols, entry, end());
        }

        // We're finished if we dont't have any children to adopt.
        if(!chl || !chl->children)
        {
            return entry;
        }

        // Transfer children and free the input.
        entry->children = chl->children;
        chl->children = NULL;
        kill(chl);

        // Reparent all children. Don't touch the resolved value.
        reparent_and_set(entry->children, entry, NULL);

        return entry;
    }

    // All or nothing, we own 'name', 'chl' and 'sym'.
    kill(chl);
    kill(sym);
    free(name);
    free(entry);

    (void) PANIC(NULL);
    return NULL;
}

//------------------------------------------------------------------------------
// Name:        new_symref
// Description: Allocate SYMREF, a reference to a symbol / variable.
// Input:       char *name:     The name of the referenced symbol. This string
//                              won't be copied and it will be free:d by kill()
//                              so it must be allocated by the calling function.
//              int32_t line:   The source code line number.
// Return:      entry_p:        A SYMREF on success, NULL otherwise.
//------------------------------------------------------------------------------
entry_p new_symref(char *name, int32_t line)
{
    // We rely on everything being set to '0'
    entry_p entry = DBG_ALLOC(calloc(1, sizeof(entry_t)));

    // All references must have a name and a line number. Line numbers are used
    // in error messages when refering to non existing symbols in strict mode.
    if(DBG_ADDR(name) && entry && (line > 0))
    {
        entry->type = SYMREF;
        entry->name = name;
        entry->id = line;
        return entry;
    }

    // We need to free 'name', since we own it.
    free(name);
    free(entry);

    (void) PANIC(NULL);
    return NULL;
}

//------------------------------------------------------------------------------
// Name:        move_contxt
// Description: Move children and symbols from one context to another. The empty
//              source context will be freed afterwards.
// Input:       entry_p dst:    The destination context.
//              entry_p src:    The source context.
// Return:      -
//------------------------------------------------------------------------------
static void move_contxt(entry_p dst, entry_p src)
{
    // Validate input.
    LG_ASSERT(src && dst, LG_VOID);

    entry_p *sym = dst->symbols = src->symbols,
            *chl = dst->children = src->children;

    // Reparent children.
    while(exists(*chl))
    {
        (*chl)->parent = dst;
        chl++;
    }

    // Reparent symbols.
    while(exists(*sym))
    {
        (*sym)->parent = dst;
        sym++;
    }

    // Free the source.
    src->children = NULL;
    src->symbols = NULL;
    kill(src);
}

//------------------------------------------------------------------------------
// Name:        new_native
// Description: Allocate NATIVE, a native, non-user-defined function.
// Input:       char *name:     The name of the function. This string won't be
//                              copied and it will be free:d by kill() so it
//                              must be allocated by the calling function. It's
//                              used for decoration purposes only, it doesn't
//                              affect the execution.
//              int32_t line:   The source code line number.
//              call_t call:    A function pointer, the code to be executed.
//              entry_p chl:    The context of the function, if any.
//              type_t type:    Default return value data type.
// Return:      entry_p:        A NATIVE on success, NULL otherwise.
//------------------------------------------------------------------------------
entry_p new_native(char *name, int32_t line, call_t call, entry_p chl, type_t type)
{
    // We rely on everything being set to '0'
    entry_p entry = DBG_ALLOC(calloc(1, sizeof (entry_t)));

    // We require a name and a line number.
    if(DBG_ADDR(name) && DBG_ADDR(call) && entry && (line > 0))
    {
        // Allocate default return value.
        entry->resolved = type == NUMBER ? new_number(0) : type == STRING ?
                          new_string(DBG_ALLOC(strdup(""))) : end();

        // Make sure that we have a valid default return value.
        if(entry->resolved)
        {
            // ID and name are for debug only.
            entry->type = NATIVE;
            entry->name = name;
            entry->call = call;
            entry->id = line;

            // Adopt children and symbols if any.
            if(chl && chl->type == CONTXT)
            {
                move_contxt(entry, chl);
            }

            // Set parent of return value.
            entry->resolved->parent = entry;
            return entry;
        }
    }

    // We need to free 'name' and 'chl' also, since we own them.
    free(entry);
    free(name);
    kill(chl);

    (void) PANIC(NULL);
    return NULL;
}

//------------------------------------------------------------------------------
// Name:        new_option
// Description: Allocate OPTION
// Input:       char *name:     The name of the option. This string won't be
//                              copied and it will be free:d by kill() so it
//                              must be allocated by the calling function. It's
//                              used for decoration purposes only, it doesn't
//                              affect the execution.
//              opt_t type:     The option type.
//              entry_p chl:    An optional context containing children.
// Return:      entry_p:        An OPTION on success, NULL otherwise.
//------------------------------------------------------------------------------
entry_p new_option(char *name, opt_t type, entry_p chl)
{
    // We rely on everything being set to '0'
    entry_p entry = DBG_ALLOC(calloc(1, sizeof (entry_t)));

    // We required a name of the option for debugging purposes.
    if(DBG_ADDR(name) && entry)
    {
        // Dynamic options need a return value.
        entry->resolved = new_number(LG_FALSE);

        if(entry->resolved)
        {
            // Set parent of return value.
            entry->resolved->parent = entry;

            // Let the type be our ID.
            entry->id = (int32_t) type;
            entry->type = OPTION;
            entry->name = name;

            // Adopt contents of CONTXT, if there is any.
            if(chl && chl->type == CONTXT)
            {
                // This is for options that contain more info than just 1 / 0,
                // e.g (delopts) and (command).
                move_contxt(entry, chl);
            }

            // Dynamic options need a callback.
            if(type == OPT_IFOPT)
            {
                entry->call = n_if;
            }
            else if(type == OPT_SELOPT)
            {
                entry->call = n_select;
            }

            return entry;
        }
    }

    // We need to free 'name' and 'chl' also, since we own them.
    kill(chl);
    free(name);
    free(entry);

    (void) PANIC(NULL);
    return NULL;
}

//------------------------------------------------------------------------------
// Name:        new_cusref
// Description: Allocate CUSREF
// Input:       char *name:     The name of the user-defined function to be
//                              invoked. This string won't be copied and it will
//                              be free:d by kill() so it must be allocated by
//                              the calling function.
//              int32_t line:   The source code line number.
//              entry_p arg:    An optional context with function arguments.
// Return:      entry_p:        a CUSREF on success, NULL otherwise.
//------------------------------------------------------------------------------
entry_p new_cusref(char *name, int32_t line, entry_p arg)
{
    // We rely on everything being set to '0'
    entry_p entry = DBG_ALLOC(calloc(1, sizeof (entry_t)));

    // A line number is required to produce meaningful error messages.
    if(DBG_ADDR(name) && entry && (line > 0))
    {
        // The n_gosub function is used as trampoline.
        entry->id = line;
        entry->name = name;
        entry->type = CUSREF;
        entry->call = n_gosub;

        // Adopt function arguments if any.
        if(arg && arg->type == CONTXT)
        {
            move_contxt(entry, arg);
        }

        return entry;
    }

    // We need to free 'name' and 'arg' also, since we own them.
    free(entry);
    free(name);
    kill(arg);

    (void) PANIC(NULL);
    return NULL;
}

//------------------------------------------------------------------------------
// Name:        append
// Description: Append entry to array. Grow array if necessary.
// Input:       entry_p **dst:   The array.
//              entry_p entry:   The entry.
// Return:      entry_p:         On success, the entry. On failure, NULL.
//------------------------------------------------------------------------------
entry_p append(entry_p **dst, entry_p ent)
{
    // Validate input.
    LG_ASSERT(ent && dst && *dst, NULL);

    // Start from the beginning.
    size_t num = 0;

    // Find the first free slot if there is one.
    while(exists((*dst)[num]))
    {
        num++;
    }

    // No free slot available. More memory needed.
    if((*dst)[num])
    {
        // Everything must be set to '0'. Make the array twice as big.
        entry_p *new = DBG_ALLOC(calloc((num << 1) + 1, sizeof(entry_p)));

        // Move everything to the new array.
        if(new)
        {
            new[num << 1] = end();
            memcpy(new, *dst, num * sizeof(entry_p));
            free(*dst);
            *dst = new;
        }
        else
        {
            // Out of memory. This is a very rude way of not leaking memory
            // when out of memory. Simply overwrite previous elements after
            // killing them of.
            kill((*dst)[0]);
            (*dst)[0] = ent;

            (void) PANIC(NULL);
            return ent;
        }
    }

    // Let entry be the new tail.
    (*dst)[num] = ent;
    return ent;
}

//------------------------------------------------------------------------------
// Name:        merge
// Description: Move and append all children of a context to another one. The
//              empty context will be killed.
// Input:       entry_p dst:    The destination context.
//              entry_p src:    The source context.
// Return:      entry_p:        The destination context.
//------------------------------------------------------------------------------
entry_p merge(entry_p dst, entry_p src)
{
    // Sanity check.
    if(DBG_ADDR(dst) && DBG_ADDR(dst->children) &&
       DBG_ADDR(src) && DBG_ADDR(src->children))
    {
        // Total number of children.
        size_t num = num_entries(src->children) + num_entries(dst->children);

        // Make the new array big enough to hold both source and destination.
        entry_p *new = DBG_ALLOC(calloc(num + 1, sizeof(entry_p)));

        if(new)
        {
            // Start all over.
            num = 0;

            // Copy current destination children.
            for(size_t i = 0; exists(dst->children[i]); i++)
            {
                new[num] = dst->children[i];
                new[num++]->parent = dst;
            }

            // Append children of the source.
            for(size_t i = 0; exists(src->children[i]); i++)
            {
                new[num] = src->children[i];
                new[num++]->parent = dst;
            }

            // Replace the old with the new and add array sentinel.
            free(dst->children);
            dst->children = new;
            new[num] = end();
        }
        else
        {
            (void) PANIC(NULL);
        }
    }
    else
    {
        (void) PANIC(NULL);
    }

    // We own 'src' and need to free it.
    kill(src);
    return dst;
}

//------------------------------------------------------------------------------
// Name:        push_symbol
// Description: Test whether a symbol is to be pushed or not.
// Input:       entry_p dst:    The destination.
//              entry_p src:    The source.
// Return:      bool:           If pushable 'true', 'false' otherwise.
//------------------------------------------------------------------------------
static bool push_symbol(entry_p dst, entry_p src)
{
    // Symbols and user-defined procedures are treated as equals.
    return ((src->type == SYMBOL || src->type == CUSTOM) &&
            (dst->type == CONTXT || dst->type == CUSTOM));
}

//------------------------------------------------------------------------------
// Name:        push
// Description: Type aware 'append' working on 'entry_t' level. Takes care of
//              children and symbols, while avoiding duplicates of the latter.
// Input:       entry_p dst:    The destination.
//              entry_p src:    The source.
// Return:      entry_p:        When successful, the source entry. On failure,
//                              NULL.
//------------------------------------------------------------------------------
entry_p push(entry_p dst, entry_p src)
{
    if((!DBG_ADDR(dst) || !DBG_ADDR(src)) && PANIC(NULL))
    {
        // We own 'src'.
        kill(src);
        return dst;
    }

    // Assume we're dealing with a child.
    entry_p **dst_p = &dst->children;

    // Symbols and user-defined procedures are equals.
    if(push_symbol(dst, src))
    {
        // We can't have multiple references.
        for(size_t i = 0; exists(dst->symbols[i]); i++)
        {
            // If duplicate reference, update the existing one.
            if(!strcasecmp(dst->symbols[i]->name, src->name))
            {
                // Variables set without (set) own themselves (refer to init()
                // and init_num()) and must be killed before an update.
                if(dst->symbols[i]->parent == dst)
                {
                    kill(dst->symbols[i]);
                }

                dst->symbols[i] = src;
                return dst;
            }
        }

        // We're dealing with a symbols.
        dst_p = &dst->symbols;
    }

    // Whether symbol or child, append and reparent.
    if(*dst_p && append(dst_p, src))
    {
        src->parent = dst;
        return dst;
    }

    // Out of memory. Since we own 'src', we need to free it.
    kill(src);
    (void) PANIC(NULL);
    return dst;
}

//------------------------------------------------------------------------------
// Name:        kill_all
// Description: Kill all entries owned by a given parent.
// Input:       entry_p *chl:   Vector with entries.
//              entry_p par:    Parent entry.
// Return:      -
//------------------------------------------------------------------------------
static void kill_all(entry_p *chl, entry_p par)
{
    if(!chl)
    {
        return;
    }

    // Free the entries we own. References can be anywhere.
    for(entry_p *cur = chl; exists(*cur); cur++)
    {
        if((*cur)->parent == par)
        {
            kill(*cur);
        }
    }
}

static bool own_res(entry_p entry)
{
    // (if), (while) and (until) never own anything. They just contain
    // references to subordinate branches / nodes.
    return entry && entry->call != n_if && entry->call != n_while &&
           entry->call != n_select && entry->call != n_until &&
           entry->call != n_retrace &&
           entry->resolved && entry->resolved->parent == entry;
}

//------------------------------------------------------------------------------
// Name:        kill
// Description: Free the memory occupied by 'entry' and all its children.
// Input:       entry_p entry:  The entry_p to be free:d.
// Return:      -
//------------------------------------------------------------------------------
void kill(entry_p entry)
{
    // DANGLE entries are static, no need to free them.
    if(entry && entry->type != DANGLE)
    {
        // If we own any resolved entries, free them.
        if(own_res(entry))
        {
            kill(entry->resolved);
        }

        // All entries might have a name.
        free(entry->name);

        // Free symbols, if any.
        kill_all(entry->symbols, entry);
        free(entry->symbols);

        // Free children, if any.
        kill_all(entry->children, entry);
        free(entry->children);

        // Nothing but this entry left.
        free(entry);
    }
}

//------------------------------------------------------------------------------
// Name:        end
// Description: Get entry_p sentinel.
// Input:       -
// Return:      entry_p:    An entry_p which can be used as sentinel.
//------------------------------------------------------------------------------
entry_p end(void)
{
    // Zero / empty string.
    static entry_t entry = { .type = DANGLE, .id = 0, .name = "" };

    return &entry;
}
