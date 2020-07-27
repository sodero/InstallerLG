//------------------------------------------------------------------------------
// eval.c:
//
// Functions for evaluation of entry_t objects.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "args.h"
#include "error.h"
#include "eval.h"
#include "exit.h"
#include "gui.h"
#include "media.h"
#include "resource.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------------------------------
// Name:        swap
// Description: Swap symbols to accelerate lookups. The type of 'src' is checked,
//              so that only those entries that can be moved, are moved.
// Input:       entry_p *dst:  Pointer to where 'src' is going.
//              entry_p *src:  Pointer to where 'dst' is goind.
// Return:      entry_p:       The entry referred to by 'src'.
//------------------------------------------------------------------------------
static entry_p swap(entry_p *dst, entry_p *src)
{
    // Only symbols at the root that don't belong to a CUSTOM can be moved.
    if(dst != src && !(*src)->parent->parent && (*src)->parent->type != CUSTOM)
    {
        entry_p tmp = *dst;
        *dst = *src;
        *src = tmp;

        // New position of *src is *dst.
        return *dst;
    }

    // No swap.
    return *src;
}

//------------------------------------------------------------------------------
// Name:        find_symbol
// Description: Find the referent of a symbolic reference.
// Input:       entry_p entry:  A symbolic reference, SYMREF.
// Return:      entry_p:        A symbol, SYMBOL, matching the symbolic
//                              reference. NULL if no match is found.
//------------------------------------------------------------------------------
entry_p find_symbol(entry_p entry)
{
    // All symbols are global.
    entry_p contxt = global(entry);

    // No panic if symbols don't exist.
    S_SANE(0);

    // Iterate over all symbols in the global context.
    for(entry_p *tmp = contxt->symbols; exists(*tmp); tmp++)
    {
        // Entry might be a CUSTOM. Ignore everything but SYMBOLS.
        if((*tmp)->type == SYMBOL && !strcasecmp((*tmp)->name, entry->name))
        {
            // If possible swap symbol order to speed up future lookups before
            // returning. This is only done in the root and not inside CUSTOM,
            // since those symbols determine the order of function arguments.
            return swap(contxt->symbols, tmp);
        }
    }

    // Fail if in strict mode. Never recur, we might be out of memory.
    if(strcasecmp(entry->name, "@strict") && get_num(contxt, "@strict"))
    {
        ERR_C(entry, ERR_UNDEF_VAR, entry->name);
    }

    // Dangle: Zero / empty string.
    return end();
}

//------------------------------------------------------------------------------
// Name:        h_resolve_option
// Description: Resolve all option types.
// Input:       entry_p option:  An OPTION.
// Return:      entry_p:         Pointer to an entry_t primitive.
//------------------------------------------------------------------------------
static entry_p h_resolve_option(entry_p option)
{
    // Dynamic options are native function calls.
    if(option->id == OPT_DYNOPT)
    {
        return option->call(option);
    }

    // Back options are treated like contexts.
    if(option->id == OPT_BACK)
    {
        return invoke(option);
    }

    // Special handling of (delopts).
    if(option->id == OPT_DELOPTS)
    {
        // Initialize cache to delete options.
        opt(option ,OPT_INIT);
    }

    // A normal option.
    return option;
}

//------------------------------------------------------------------------------
// Name:        resolve
// Description: Derive primitive from a complex type, something that can be
//              directly evaluated as a string or numerical value.
// Input:       entry_p entry:  An entry_t pointer to an object of any type.
// Return:      entry_p:        Pointer to an entry_t primitive.
//------------------------------------------------------------------------------
entry_p resolve(entry_p entry)
{
    // Validate input.
    LG_ASSERT(entry, end());

    switch(entry->type)
    {
        // Symbols are resolved from birth.
        case SYMBOL:
            return entry->resolved;

        // References are resolved by resolving the symbol it refers to.
        case SYMREF:
            return resolve(find_symbol(entry));

        // A context is resolved by executing all functions in it.
        case CONTXT:
            return invoke(entry);

        // Functions are resolved by executing them.
        case CUSREF:
        case NATIVE:
            return entry->call(entry);

        // Special options.
        case OPTION:
            return h_resolve_option(entry);

        // We already have a primitive.
        case NUMBER:
        case STRING:
        case DANGLE:
            return entry;

        case CUSTOM:
            return end();
    }

    // We should never end up here.
    PANIC(entry);
    return entry;
}

//------------------------------------------------------------------------------
// Name:        opt_to_int
// Description: Convert option to numerical value. This will translate string
//              representations of user levels to the corresponding numerical
//              value.
// Input:       entry_p entry:  An entry_t pointer to an OPTION object.
// Return:      int32_t:        An integer representation of the input.
//------------------------------------------------------------------------------
static int32_t opt_to_int(entry_p entry)
{
    // Resolve once.
    char *option = str(entry);

    // Is this an ordinary option?
    if(entry->id != OPT_CONFIRM)
    {
        // No translation needed.
        return atoi(option);
    }

    // Translate (confirm) to userlevel.
    return str_to_userlevel(option, atoi(option));
}

//------------------------------------------------------------------------------
// Name:        num
// Description: Get integer representation of an entry. This implies resolving
//              it, and, if necessary, converting it.
// Input:       entry_p entry:  An entry_t pointer to an object of any type.
// Return:      int32_t:        An integer representation of the input.
//------------------------------------------------------------------------------
int32_t num(entry_p entry)
{
    // Validate input.
    LG_ASSERT(entry, 0);

    switch(entry->type)
    {
        // Translate options.
        case OPTION:
            return opt_to_int(entry);

        // These are numeric values:
        case DANGLE:
        case NUMBER:
            return entry->id;

        // Recur.
        case SYMBOL:
            return num(entry->resolved);

        // Recur.
        case SYMREF:
            return num(find_symbol(entry));

        // Recur.
        case CUSREF:
        case NATIVE:
            return num(entry->call(entry));

        // Attempt to convert string.
        case STRING:
            return entry->name ? atoi(entry->name) : 0;

        // Recur.
        case CONTXT:
            return num(resolve(entry));

        // Procedure line number.
        case CUSTOM:
            return entry->id;
    }

    PANIC(entry);
    return 0;
}

//------------------------------------------------------------------------------
// Name:        tru
// Description: Get truth value of an entry. This implies resolving it, and, if
//              necessary, converting it. Non empty strings and non zero
//              numerical values are considered true, everythings else false.
// Input:       entry_p entry:  An entry_t pointer to an object of any type.
// Return:      bool:           The truth value of the input.
//------------------------------------------------------------------------------
bool tru(entry_p entry)
{
    // Validate input.
    LG_ASSERT(entry, false);

    // Attempt to resolve it.
    entry_p val = resolve(entry);

    // Only numerals and strings can be true.
    return (((val->type == STRING && *(val->name)) ||
             (val->type == NUMBER && val->id)) && NOT_ERR);
}

//------------------------------------------------------------------------------
// Name:        h_str_opt
// Description: Convert OPTION to string.
// Input:       entry_p entry:  An entry_t pointer to a OPTION.
// Return:      char *:         String representation of the input.
//------------------------------------------------------------------------------
static char *h_str_opt(entry_p opt)
{
    switch(opt->id)
    {
        case OPT_APPEND:
        case OPT_CONFIRM:
        case OPT_DEFAULT:
        case OPT_DEST:
        case OPT_DISK:
        case OPT_INCLUDE:
        case OPT_NEWNAME:
        case OPT_PATTERN:
        case OPT_SETDEFAULTTOOL:
        case OPT_SETSTACK:
        case OPT_SOURCE:
        case OPT_OVERRIDE:
        case OPT_GETDEFAULTTOOL:
        case OPT_GETSTACK:
        case OPT_GETTOOLTYPE:
            return str(opt->children ? opt->children[0] : NULL);

       case OPT_HELP:
       case OPT_PROMPT:
           // Concatenate children of (help) and (prompt).
           free(opt->name);
           opt->name = get_chlstr(opt, false);

           if(!opt->name && PANIC(opt))
           {
               break;
           }

           // Return concatenated value.
           return opt->name;

       default:
           // Fall through for all other option types.
           break;
    }

    // Always return a valid string.
    return "";
}

//------------------------------------------------------------------------------
// Name:        h_str_num
// Description: Convert NUMBER to string.
// Input:       entry_p entry:  An entry_t pointer to a NUMBER.
// Return:      char *:         String representation of the input.
//------------------------------------------------------------------------------
static char *h_str_num(entry_p opt)
{
    // We already have a string if we've done this number before.
    if(!opt->name)
    {
        // Numbers can be LG_NUMLEN characters long.
        opt->name = DBG_ALLOC(malloc(LG_NUMLEN));
    }

    // Exit on OOM.
    LG_ASSERT(opt->name, "");

    // Create formated string and return.
    snprintf(opt->name, LG_NUMLEN, "%d", opt->id);
    return opt->name;
}

//------------------------------------------------------------------------------
// Name:        str
// Description: Get string representation of an entry. This implies resolving
//              it, and, if necessary, converting it.
// Input:       entry_p entry:  An entry_t pointer to an object of any type.
// Return:      char *:         String representation of the input.
//------------------------------------------------------------------------------
char *str(entry_p entry)
{
    // Validate input.
    LG_ASSERT(entry, "");

    switch(entry->type)
    {
        // Strings, dangles and function names can be returned directly.
        case DANGLE:
        case CUSTOM:
        case STRING:
            if(entry->name)
            {
                return entry->name;
            }
            break;

        // Options need special treatment.
        case OPTION:
            return h_str_opt(entry);

        // Recur.
        case SYMBOL:
            return str(entry->resolved);

        // Recur.
        case SYMREF:
            return str(find_symbol(entry));

        // Recur.
        case CUSREF:
        case NATIVE:
            return str(entry->call(entry));

        // Convert number to string.
        case NUMBER:
            return h_str_num(entry);

        // Recur.
        case CONTXT:
            return str(resolve(entry));
    }

    PANIC(entry);
    return "";
}

//------------------------------------------------------------------------------
// Name:        invoke
// Description: Evaluate all children of an entry. In most cases this implies
//              executing all executable children and return the return value of
//              the last executed function. If any of the functions fail, the
//              execution will be aborted.
// Input:       entry_p entry:  An entry_t pointer to a parent object.
// Return:      entry_p:        The last resolved value.
//------------------------------------------------------------------------------
entry_p invoke(entry_p entry)
{
    // Validate input.
    LG_ASSERT(entry, end());

    // Expect nothing.
    entry_p ret = end();
    entry_p *cur = entry->children;

    // Empty procedures are allowed, there might be no children at all.
    if(cur)
    {
        // Reesolve children and save the last return value.
        while(exists(*cur) && NOT_ERR)
        {
            ret = resolve(*cur);
            cur++;
        }
    }

    // Return the last value.
    return ret;
}

//------------------------------------------------------------------------------
// Name:        run
// Description: Run script. Setup and teardown of everything, GUI included.
// Input:       entry_p entry:  The start symbol, refer to the parser.
// Return:      -
//------------------------------------------------------------------------------
void run(entry_p entry)
{
    // Is there an 'effect' statement in there?
    entry_p status = native_exists(entry, n_effect);

    // i18n setup.
    locale_init();

    // Initialize GUI. Use a custom screen if (effect) statement exists.
    if(gui_init(status != false))
    {
        // If an 'effect' statement exists, execute this first of all.
        if(status)
        {
            // Resolve 'effect' like a symbol.
            status = resolve(status);
        }

        // Execute the script unless 'effect' failed or halted.
        if(NOT_ERR && NOT_HALT)
        {
            status = invoke(entry);

            // Execute (onerror) on failure.
            if(DID_ERR && NOT_HALT)
            {
                status = n_onerror(entry);
            }
        }

        // Output what we have unless we're running from WB.
        if(arg_argc(-1))
        {
            puts(str(status));
        }

        // GUI teardown.
        gui_exit();
    }

    // i18n and AST teardown.
    locale_exit();
    kill(entry);
}
