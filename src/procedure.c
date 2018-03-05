//----------------------------------------------------------------------------
// procedure.c: 
//
// Management of user defined procedures
//
//----------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "procedure.h"
#include "util.h"

#include <string.h>

//----------------------------------------------------------------------------
// (<procedure-name>)
//
// ********************************
// Trampoline function for invoking 
// user defined procedures.
// ********************************
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_gosub(entry_p contxt)
{
    // Recursion depth. 
    static int dep = 0; 

    // Global context where the user
    // defined procedures are found.
    entry_p con = global(contxt);  

    // Is the global context in order?
    if(s_sane(con, 0)) 
    {
        // Look through all symbols and see
        // there's a used defined procedure
        // that matches the reference name. 
        entry_p *cus = con->symbols; 
        while(*cus && 
              *cus != end())
        {
            if((*cus)->type == CUSTOM &&
               !strcmp((*cus)->name, contxt->name))
            {
                entry_p ret; 
                entry_p *arg = (*cus)->symbols, 
                        *ina = contxt->children;
                if(arg && ina)
                {
                    while(*arg && *arg != end() &&
                          *ina && *ina != end())
                    {
                        entry_p res = malloc(sizeof(entry_t)); 
                        if(res)
                        {
                            memmove(res, resolve(*ina), sizeof(entry_t)); 
                            res->name = res->name ? strdup(res->name) : NULL; 
                            res->parent = *arg; 
                            kill((*arg)->resolved); 
                            (*arg)->resolved = res; 
                        }
                        else
                        {
                            // Out of memory
                            error(PANIC);
                            return new_failure(); 
                        }
                        arg++; 
                        ina++;
                    }
                }
                if(dep++ < MAXDEP)
                {
                    ret = invoke(*cus); 
                    dep--; 
                    return ret; 
                }
                else
                {
                    error(contxt->id, ERR_MAX_DEPTH, contxt->name); 
                    return new_failure(); 
                }
            }
            cus++; 
        }
        error(contxt->id, ERR_UNDEF_FNC, contxt->name); 
    }
    else
    {
        // The parser is broken
        error(PANIC);
    }
    return new_failure(); 
}

//----------------------------------------------------------------------------
// (procedure <procedure-name> [<args>] <statements>)
//    user defined procedure
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_procedure(entry_p contxt)
{
    // The global context is where we want the
    // user procedure to end up.
    entry_p dst = global(contxt);

    // We have a single argument, the function 
    // to add to the global context.
    if(dst && s_sane(contxt, 1))
    {
        // Push the function and let the global 
        // context be its parent.
        push(dst, contxt->symbols[0]); 
        contxt->symbols[0]->parent = contxt; 

        // Return the function itself. 
        return contxt->symbols[0];
    }
    else
    {
        // Everything is broken.
        error(PANIC);
        RCUR; 
    }
}
