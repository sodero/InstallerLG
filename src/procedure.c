//------------------------------------------------------------------------------
// procedure.c:
//
// Management of user defined procedures
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "procedure.h"
#include "strop.h"
#include "util.h"
#include <string.h>

//------------------------------------------------------------------------------
// (<procedure-name>)
//
// ********************************
// Trampoline function for invoking
// user defined procedures.
// ********************************
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_gosub(entry_p contxt)
{
    // Global context where the user defined procedures are found.
    entry_p con = global(contxt);

    // Is the global context in order?
    if(!s_sane(con, 0))
    {
        // The parser is broken
        PANIC(contxt);
        return end();
    }

    // Search through all symbols and see if there's a used defined
    // procedure that matches the reference name.
    for(entry_p *cus = con->symbols; *cus && *cus != end(); cus++)
    {
        // Skip symbol if we don't have a match.
        if((*cus)->type != CUSTOM || strcasecmp((*cus)->name, contxt->name))
        {
            continue;
        }

        // Copy parameter values to procedure context.
        entry_p *arg = (*cus)->symbols, *ina = contxt->children;

        if(arg && ina)
        {
            // From the Installer.guide:
            //
            // If you leave out any arguments at the end, the
            // corresponding variables will retain their previous value.
            //
            // An example:
            //
            // (procedure P_ADDMUL arg1 arg2 arg3
            //     (* (+ arg1 arg2) arg3)
            // )
            //
            // (message (P_ADDMUL 1 2 3)) ; shows 9
            // (message (P_ADDMUL 4 5))   ; shows 27
            while(*arg && *arg != end() && *ina && *ina != end())
            {
                entry_p res = DBG_ALLOC(malloc(sizeof(entry_t)));

                if(!res && PANIC(contxt))
                {
                    // Out of memory
                    return end();
                }

                // Copy and free the resources from the last invocation, if any.
                memmove(res, resolve(*ina), sizeof(entry_t));
                res->name = res->name ? DBG_ALLOC(strdup(res->name)) : NULL;
                res->parent = *arg;
                kill((*arg)->resolved);
                (*arg)->resolved = res;

                // Continue until we have no more arguments from the caller or
                // that the procedure doesn't take any more arguments.
                arg++;
                ina++;
            }
        }

        // Recursion depth.
        static int dep;

        // Keep track of the recursion depth. Do not invoke if we're
        // beyond LG_MAXDEP.
        if(dep++ < LG_MAXDEP)
        {
            // Return value.
            entry_p ret = invoke(*cus);
            dep--;
            return ret;
        }

        // We risk running out of stack if we don't abort.
        ERR(ERR_MAX_DEPTH, contxt->name);
        return end();
    }

    // In non strict mode, transform the syntax of a function call such as
    // (f1 arg1 arg2 ...) into a format string expression ("%s%ld.." ...) if
    // the function is not defined and a symbol that can be resolved into a
    // format string exists.
    if(!get_num(contxt, "@strict"))
    {
        // First invocation?
        if(!contxt->resolved)
        {
            // We need a resolved dummy. See new_*. In this case we're
            // mimicing a NATIVE returning a STRING.
            contxt->resolved = new_string(DBG_ALLOC(strdup("")));

            if(!contxt->resolved)
            {
                // Panic already set.
                return end();
            }

            // Reparent the dummy.
            contxt->resolved->parent = contxt;
        }

        // Save the old name. We need to do this in order to resolve the
        // format string multiple times when needed.
        char *old = contxt->name;

        // Set format string, type and callback to mimic a real ("%ld" ..)
        // function.
        contxt->call = m_fmt;
        contxt->type = NATIVE;
        contxt->name = get_str(contxt, contxt->name);

        // Get the resolved value of the things we've stitched together.
        entry_p res = resolve(contxt);

        // Restore everything so that we can do this again, once again
        // resolving the format string.
        contxt->name = old;
        contxt->call = m_gosub;
        contxt->type = CUSREF;

        // Success.
        return res;
    }

    // Undefined user procedure.
    ERR(ERR_UNDEF_FNC, contxt->name);
    return end();
}

//------------------------------------------------------------------------------
// (procedure <procedure-name> [<args>] <statements>)
//    user defined procedure
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_procedure(entry_p contxt)
{
    // The global context is where we want the user procedure to end up.
    entry_p dst = global(contxt);

    // We have a single argument, the function to add to the global context.
    if(dst && s_sane(contxt, 1))
    {
        // Push the function and let the global context be its parent.
        push(dst, contxt->symbols[0]);
        contxt->symbols[0]->parent = contxt;

        // Return the function itself.
        return contxt->symbols[0];
    }

    // Everything is broken.
    PANIC(contxt);
    R_CUR;
}
