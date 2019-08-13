//------------------------------------------------------------------------------
// eval.c:
//
// Functions for evaluation of entry_t objects.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
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
// Name:        find_symbol
// Description: Find the referent of a symbolic reference.
// Input:       entry_p entry:  A symbolic reference, SYMREF.
// Return:      entry_p:        A symbol, SYMBOL, matching the symbolic
//                              reference. NULL if no match is found.
//------------------------------------------------------------------------------
entry_p find_symbol(entry_p entry)
{
    // Local variables have priority. This currently implies function arguments
    // only. We could enable local (set), but this might break old scripts, so
    // let's not do it.
    entry_p con = local(entry);

    // Something is really broken if we're missing a context.
    if(!con)
    {
        // Bad input.
        PANIC(entry);
        return end();
    }

    // Traverse tree until we reach the top.
    do
    {
        // Current level.
        entry_p *tmp;

        // Iterate over all symbols in the current context.
        for(tmp = con->symbols; tmp && *tmp && *tmp != end(); tmp++)
        {
            // Return value.
            entry_p ret = *tmp;

            // The current entry might be a CUSTOM. Ignore everything but
            // SYMBOLS.
            if(ret->type != SYMBOL || strcasecmp(ret->name, entry->name))
            {
                // Next entry;
                continue;
            }
            else
            {
                // Rearrange symbols to make the next lookup faster. Don't do
                // this unless we're at the root and not in a user defined
                // procedure. This would break all positional symbols
                // (procedure arguments).
                if(!ret->parent->parent && ret->parent->type != CUSTOM)
                {
                    *tmp = *(con->symbols);
                    *(con->symbols) = ret;
                }

                // Symbol found.
                return ret;
            }
        }

        // Nothing found in the current context. Climb one scope higher and try
        // again.
        con = local(con->parent);
    }
    while(con);

    // Only fail if we're in strict mode. Never recur when looking for @strict,
    // it might not be there if we're out of memory. If we do, we will run out
    // of stack as well.
    if(strcasecmp(entry->name, "@strict") &&
       get_numvar(global(entry), "@strict"))
    {
        // We found nothing.
        ERR_C(entry, ERR_UNDEF_VAR, entry->name);
    }

    // A failure will be evaluated as as a zero or an empty string.
    return end();
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
    // Is there anything to resolve?
    if(!entry)
    {
        // Bad input.
        PANIC(entry);
        return end();
    }

    switch(entry->type)
    {
        // Symbols are resolved from birth.
        case SYMBOL:
            return entry->resolved;

        // Symbolic references are resolved by resolving the symbol it refers to.
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
            // Dynamic options are treated like functions.
            if(entry->id == OPT_DYNOPT)
            {
                return entry->call(entry);
            }
            else
            // Back options are treated like contexts.
            if(entry->id == OPT_BACK)
            {
                return invoke(entry);
            }
            // Ordinary options.
            return entry;

        // We already have a primitive.
        case NUMBER:
        case STRING:
        case DANGLE:
            return entry;

        case CUSTOM:
            break;
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
// Return:      int:            An integer representation of the input.
//------------------------------------------------------------------------------
static int opt_to_int(entry_p entry)
{
    // Resolve once.
    char *opt = str(entry);

    // Is this an ordinary option?
    if(entry->id != OPT_CONFIRM)
    {
        // No translation needed.
        return atoi(opt);
    }

    // Special treatment of (confirm).
    if(strcasecmp(opt, "novice") == 0)
    {
        return LG_NOVICE;
    }
    else
    if(strcasecmp(opt, "average") == 0)
    {
        return LG_AVERAGE;
    }
    else
    if(strcasecmp(opt, "expert") == 0)
    {
        return LG_EXPERT;
    }

    // Fall through.
    return atoi(opt);
}

//------------------------------------------------------------------------------
// Name:        num
// Description: Get integer representation of an entry. This implies resolving
//              it, and, if necessary, converting it.
// Input:       entry_p entry:  An entry_t pointer to an object of any type.
// Return:      int:            An integer representation of the input.
//------------------------------------------------------------------------------
int num(entry_p entry)
{
    // Is there anything to resolve?
    if(entry)
    {
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
                // Don't trust strings, we might be out of memory.
                if(entry->name)
                {
                    return atoi(entry->name);
                }
                // Panic.
                break;

            // We should never end up here.
            case CONTXT:
            case CUSTOM:
                break;
        }
    }

    // Bad input.
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
    // Anything to resolve?
    if(!entry)
    {
        PANIC(entry);
        return false;
    }

    // Attempt to resolve it.
    entry_p val = resolve(entry);

    // Only numerals and strings can be true.
    if(((val->type == STRING && *(val->name)) ||
        (val->type == NUMBER && val->id)) && !DID_ERR)
    {
        return true;
    }

    // Something else.
    return false;
}

//------------------------------------------------------------------------------
// Name:        str
// Description: Get string representation of an entry. This implies resolving
//              it, and, if necessary, converting it.
// Input:       entry_p entry:  An entry_t pointer to an object of any type.
// Return:      int:            String representation of the input.
//------------------------------------------------------------------------------
char *str(entry_p entry)
{
    // Is there anything to resolve?
    if(!entry)
    {
        // Bad input.
        PANIC(entry);
        return "";
    }

    switch(entry->type)
    {
        // Special treatment of options with a single string argument. Let
        // other options fall through.
        case OPTION:
            switch(entry->id)
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
                    // All the options above have a single child.
                    return str
                    (
                        entry->children ?
                        entry->children[0] : NULL
                    );

                case OPT_HELP:
                case OPT_PROMPT:
                    // (help) and (prompt) may have multiple children that
                    // must be concatenated.
                    free(entry->name);
                    entry->name = get_chlstr(entry, false);

                    // On OOM, fall through.
                    if(entry->name)
                    {
                        return entry->name;
                    }

                    // OOM.
                    PANIC(entry);
                    break;

                default:
                    break;
            }
            /* FALLTHRU */

        // Dangling entries and options are considered empty strings with
        // the exceptions above.
        case DANGLE:
            return "";

        // Strings and function names can be returned directly.
        case CUSTOM:
        case STRING:
            return entry->name;

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

        // Conversion. Please note the use of LG_NUMLEN.
        case NUMBER:
            // Have we converted this number to a string before?
            if(!entry->name)
            {
                entry->name = DBG_ALLOC(malloc(LG_NUMLEN));
            }

            // On out of memory, fall through and PANIC below.
            if(entry->name)
            {
                snprintf(entry->name, LG_NUMLEN, "%d", entry->id);
                return entry->name;
            }
            break;

        // We should never end up here.
        case CONTXT:
            break;
    }

    // Bad input.
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
    // Expect failure.
    entry_p ret = end();

    if(entry)
    {
        // Iterator.
        entry_p *cur = entry->children;

        // Empty procedures are allowed, there might be no children at all.
        if(cur)
        {
            // As long as no one fails, resolve all children and save the return
            // value of the last one.
            while(*cur && *cur != end() && !DID_ERR)
            {
                // Resolve and proceed.
                ret = resolve(*cur);
                cur++;
            }
        }

        // Return the last value.
        return ret;
    }

    // Bad input.
    PANIC(entry);
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
    entry_p status = native_exists(entry, m_effect);

    // i18n setup.
    locale_init();

    // Initialize GUI before starting the execution. If (effect) type is set,
    // use a custom screen.
    if(gui_init(status != false))
    {
        // If an 'effect' statement exists, execute this first of all.
        if(status)
        {
            // Resolve 'effect' like a symbol.
            status = resolve(status);
        }

        // Execute the script unless 'effect' failed or halted.
        if(!DID_ERR && !DID_HALT)
        {
            status = invoke(entry);

            // Execute (onerror) on failure.
            if(DID_ERR && !DID_HALT)
            {
                status = m_onerror(entry);
            }
        }

        // Output what we have unless we're running from WB.
        if(arg_argc(-1))
        {
            printf("%s\n", str(status));
        }

        // GUI teardown.
        gui_exit();
    }

    // i18n teardown.
    locale_exit();

    // Free AST
    kill(entry);
}
