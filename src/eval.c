//----------------------------------------------------------------------------
// eval.c: 
//
// Functions for evaluation of entry_t objects. 
//----------------------------------------------------------------------------

#include "alloc.h"
#include "args.h"
#include "error.h"
#include "eval.h"
#include "exit.h"
#include "gui.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------------------------------------------------------------------------
// Name:        find_symbol(entry_p entry)
// Description: Find the referent of a symbolic reference. 
// Input:       entry_p entry:  A symbolic reference, SYMREF.
// Return:      entry_p:        A symbol, SYMBOL, matching the symbolic
//                              reference. NULL if no match is found.
//----------------------------------------------------------------------------
entry_p find_symbol(entry_p entry)
{
    // Local variables have priority. This
    // currently implies function arguments 
    // only. We could enable local (set), 
    // but this might break old scripts, so
    // let's not do it. 
    entry_p con = local(entry); 

    if(con)
    {
        do
        {
            entry_p *tmp; 

            // Iterate over all symbols in the current
            // context. 
            for(tmp = con->symbols;
                tmp && *tmp && *tmp != end(); 
                tmp++)
            {
                // The current item might be a CUSTOM
                // Only match SYMBOL:s, return if we
                // find a match. 
                if((*tmp)->type == SYMBOL &&
                   !strcmp((*tmp)->name, entry->name)) 
                {
                    return *tmp; 
                }
            }

            // Nothing found in the current context. 
            // Climb one scope higher and try again. 
            con = local(con->parent);
        }
        while(con);

        // We found nothing. 
        error(entry->id, ERR_UNDEF_VAR, 
              entry->name); 
    }
    else
    {
        // Bad input. 
        error(PANIC);
    }

    return new_failure();
}

//----------------------------------------------------------------------------
// Name:        resolve(entry_p entry)
// Description: Derive primitive from a complex type, something that can be
//              directly evaluated as a string or numerical value. 
// Input:       entry_p entry:  An entry_t pointer to an object of any type.
// Return:      entry_p:        Pointer to an entry_t primitive.  
//----------------------------------------------------------------------------
entry_p resolve(entry_p entry)
{
    // Is there anything to resolve?
    if(entry && 
       entry != end())
    {
        switch(entry->type)
        {
            // Symbols are resolved from birth. 
            case SYMBOL: 
                return entry->resolved ? entry->resolved : new_failure(); 

            // A symbolic reference is resolved by resolving
            // the symbol it refers to.
            case SYMREF: 
                return resolve(find_symbol(entry)); 

            // A context is resolved by executing all functions in it.
            case CONTXT: 
                return invoke(entry);

            // Functions are resolved by executing them. 
            case CUSREF:
            case NATIVE:
                return entry->call ? entry->call(entry) : new_failure(); 

            // If we end up here, we already have a primitive. 
            default:
                return entry; 
        }
    }

    // Bad input. 
    error(PANIC);
    return new_failure();
}

//----------------------------------------------------------------------------
// Name:        num(entry_p entry)
// Description: Get integer representation of an entry. This implies resolving 
//              it, and, if necessary, converting it. 
// Input:       entry_p entry:  An entry_t pointer to an object of any type.
// Return:      int:            An integer representation of the input. 
//----------------------------------------------------------------------------
int num(entry_p entry)
{
    // Is there anything to resolve?
    if(entry && 
       entry != end())
    {
        switch(entry->type)
        {
            // Options might contain numbers. If not, a '0'
            // will be returned. 
            case OPTION:
                return atoi(str(entry)); 

            // These are all numeric values: 
            case STATUS:
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
                return num(entry->call ? entry->call(entry) : NULL); 

            // Attempt to convert string.
            case STRING:
                return atoi(entry->name);

            default:
                break; 
        }
    }

    // Bad input. 
    error(PANIC);
    return 0; 
}

//----------------------------------------------------------------------------
// Name:        str(entry_p entry)
// Description: Get string representation of an entry. This implies resolving 
//              it, and, if necessary, converting it. 
// Input:       entry_p entry:  An entry_t pointer to an object of any type.
// Return:      int:            String representation of the input. 
//----------------------------------------------------------------------------
char *str(entry_p entry)
{
    // Is there anything to resolve?
    if(entry && 
       entry != end())
    {
        switch(entry->type)
        {
            // Special treatment of options
            // with a single string argument. 
            // Let other options fall through. 
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
                        return str
                        (
                            entry->children ? 
                            entry->children[0] : NULL
                        );
                    case OPT_HELP: 
                    case OPT_PROMPT: 
                        // FIXME
                        /* Wrong! All children shall be merged */
                        return str
                        (
                            entry->children ? 
                            entry->children[0] : NULL
                        );
                }

            // This doesn't make sense. We need
            // a proper string though. 
            case STATUS:
            case DANGLE:
                return ""; 

            // Strings and function names can
            // be returned directly. 
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
                return str(entry->call ? entry->call(entry) : NULL); 

            // Conversion. Please note the use 
            // of NUMLEN. 
            case NUMBER:
                if(!entry->name)
                {
                    entry->name = malloc(NUMLEN); 
                }

                if(entry->name)
                {
                    snprintf(entry->name, NUMLEN, "%d", entry->id); 
                    return entry->name;
                }

            default:
                break;
        }
    }

    error(PANIC);
    return ""; 
}

//----------------------------------------------------------------------------
// Name:        invoke(entry_p entry)
// Description: Execute all (executable) children of a CONTXT and return the 
//              the return value of the last executed function. If any of the
//              functions in the CONTXT fails, the execution will be aborted.
// Input:       entry_p entry:  An entry_t pointer to a CONTXT object. 
// Return:      entry_p:        The return value of the last function in 
//                              entry. 
//----------------------------------------------------------------------------
entry_p invoke(entry_p entry)
{
    // Be prepared to fail. 
    entry_p ret = new_failure(); 

    if(entry)
    {
        // Iter. 
        entry_p *vec = entry->children;

        // As long as we have something and
        // no one fails, execute and save the 
        // return value. 
        while (*vec && 
               *vec != end() &&
               !did_error())
        {
            if((*vec)->type == NATIVE ||
               (*vec)->type == CUSREF)
            {
                if((*vec)->call)
                {
                    // The function call. 
                    ret = (*vec)->call(*vec); 
                }
                else
                {
                    // Either the parser is broken
                    // or (procedure) is not doing
                    // its job. 
                    error(PANIC);
                    break; 
                }
            }

            // Next one / skip anything
            // that we can't execute. 
            vec++; 
        }

        // Return the last value. 
        return ret;
    }

    // Bad input. 
    error(PANIC);
    return ret;
}

//----------------------------------------------------------------------------
// Name:        run(entry_p entry)
// Description: Run script. Setup and teardown of everything, GUI included.
// Input:       entry_p entry:  The start symbol, refer to the parser. 
// Return:      - 
//----------------------------------------------------------------------------
void run(entry_p entry)
{
    // Initialize GUI before starting
    // the execution.
    if(gui_init())
    {
        // Execute the script. 
        entry_p status = invoke(entry);

        // Execute the (onerror) function
        // on failure. 
        if(did_error() && !did_halt())
        {
            status = m_onerror(entry); 
        }

        // Output what we have unless we're
        // running from WB.
        if(arg_argc(-1))
        {
            printf("%s\n", str(status)); 
        }

        // GUI teardown.
        gui_exit(); 
    }

    // Free AST
    kill(entry);
}
