//----------------------------------------------------------------------------
// symbol.h: 
//
// Symbol manipulation
//
//----------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "symbol.h"
#include "util.h"

#include <stdlib.h>
#include <string.h>

//----------------------------------------------------------------------------
// (set <varname> <value> [<varname2> <value2> ...])
//      sets the variable `<varname>' to the indicated value. 
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_set(entry_p contxt)
{
    // Symbol destination. 
    entry_p dst = global(contxt);

    if(c_sane(contxt, 1) &&
       s_sane(contxt, 1) && dst)
    {
        entry_p *sym = contxt->symbols, 
                *val = contxt->children; 

        while(*sym && *sym != end() &&
              *val && *val != end())
        {
            entry_p rhs = resolve(*val);
            if(!did_error())
            {
                entry_p res = malloc(sizeof(entry_t)); 
                if(res)
                {
                    memmove(res, rhs, sizeof(entry_t)); 
                    res->name = res->name ? strdup(res->name) : NULL; 
                    res->parent = *sym; 
                    kill((*sym)->resolved); 
                    (*sym)->resolved = res; 
                    push(dst, *sym); 
                    (*sym)->parent = contxt;  
                }
                else
                {
                    // Out of memory. 
                    break; 
                }
                if(*(++sym) == *(++val))
                {
                    // We're at the end of the list
                    // of tuples. 
                    return res; 
                }
            }
            else
            {
                // Unresolvable right-hand side.
                break; 
            }
        }
    }
    else
    {
        // Broken parser.  
        error(PANIC);
    }

    return new_failure(); 
}

//----------------------------------------------------------------------------
// (symbolset <symbolname> <expression>)
//     assign a value to a variable named by the string result of
//     `<symbolname>' (V42.9)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_symbolset(entry_p contxt)
{
    // Symbol destination. 
    entry_p dst = global(contxt);

    // We need one or more tuples of symbol
    // name and value. 
    if(c_sane(contxt, 2) && dst)
    {
        entry_p ret = DCUR; 
        entry_p *cur = contxt->children; 

        // Iterate over all tuples. 
        while(*cur && *cur != end())
        {
            // Resolve symbol name and value. 
            const char *lhs = str(*cur++);
            entry_p rhs = resolve(*cur++);

            // Could we resolve both lhs and rhs? 
            if(!did_error())
            {
                // Create a copy of the evaluated rhs. 
                entry_p res = malloc(sizeof(entry_t)); 

                if(res)
                {
                    entry_p *sym = contxt->symbols; 
                    memmove(res, rhs, sizeof(entry_t)); 

                    // Do a deep copy if necessary. 
                    if(res->name)
                    {
                        res->name = strdup(res->name); 
                    }

                    // Do we already have a symbol 
                    // with this name?
                    while(*sym && *sym != end())
                    {
                        // If true, replace its resolved
                        // value with the copy of the rhs
                        if(!strcmp((*sym)->name, lhs))
                        {
                            kill((*sym)->resolved); 
                            (*sym)->resolved = res;
                            push(dst, *sym); 
                            res->parent = *sym; 
                            ret = res; 
                            break; 
                        }

                        // Iterate over all symbols in
                        // this context. 
                        sym++; 
                    }

                    // Is this is a new symbol?
                    if(ret != res)
                    {
                        entry_p nsm = new_symbol(strdup(lhs)); 

                        if(nsm)
                        {
                            res->parent = nsm; 
                            nsm->resolved = res; 

                            // Append the symbol to the current
                            // context and create a global ref.
                            if(append(&contxt->symbols, nsm))
                            {
                                push(dst, nsm); 
                                nsm->parent = contxt;  
                                ret = res; 
                                continue;
                            }

                            // Out of memory. 
                            kill(nsm); 
                        }
                    }
                    else
                    {
                        // Symbol exists. Its new
                        // value has already been
                        // set above. 
                        continue; 
                    }

                    // Out of memory. 
                    kill(res); 
                    break;
                }
                else
                {
                    // Out of memory. 
                    error(PANIC); 
                    RCUR; 
                }
            }
            else
            {
                // Could not resolve either the lhs
                // or the rhs. Error will be set by
                // resolve(). 
                RCUR; 
            }
        }

        // Return the last rhs. 
        return ret; 
    }
    else
    {
        // Broken parser
        RCUR; 
    }
}

//----------------------------------------------------------------------------
// (symbolval <symbolname>)
//     returns the value of the symbol named by the string expression
//     `<smbolval>' (V42.9)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_symbolval(entry_p contxt)
{
    // We need one argument, the name
    // of the symbol.
    if(c_sane(contxt, 1))
    {
        entry_p r; 
        entry_t e; 
        e.type = SYMREF; 
        e.parent = contxt; 
        e.id = contxt->id; 
        e.name = str(CARG(1)); 
        r = resolve(&e); 
        if(!did_error())
        {
            return r; 
        }
        RNUM(0);
    }
    else
    {
        // The parser is broken
        error(PANIC);
        RCUR;
    }
}
