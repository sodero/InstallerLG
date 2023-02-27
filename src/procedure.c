//------------------------------------------------------------------------------
// procedure.c:
//
// Management of user defined procedures
//------------------------------------------------------------------------------
// Copyright (C) 2018-2023, Ola Söder. All rights reserved.
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
// Name:        h_gosub_fmt
// Description: Helper for n_gosub. Handling one of those strange CBM Installer
//              features / bugs. The syntax of user defined procedure calls and
//              string formating is ambiguous, so that a function call such as
//              (f1 a1 a2 ... ) is transformed into a format string expression
//              ("%ld%ld" a1 a2 ...) if the function ('f1') is not defined and
//              a symbol ('f1') that can be resolved as a format string exists.
//              In strict mode this isn't allowed.
// Input:       entry_p contxt: Execution context.
// Return:      entry_p:        Resolved STRING result.
//------------------------------------------------------------------------------
static entry_p h_gosub_fmt(entry_p contxt)
{
    if(!contxt->resolved)
    {
        // Create resolved value on the first invocation.
        contxt->resolved = new_string(DBG_ALLOC(strdup("")));

        if(!contxt->resolved)
        {
            return end();
        }

        // Reparent the resolved value.
        contxt->resolved->parent = contxt;
    }

    // Save name to be able to resolve the format string multiple times.
    char *old = contxt->name;

    // Set format, type and callback to mimic a ("%ld" ..) function call.
    contxt->call = n_fmt;
    contxt->type = NATIVE;
    contxt->name = get_str(contxt, contxt->name);

    // Resolve the things we've stitched together.
    entry_p res = resolve(contxt);

    // Restore name to be able to resolve the format string multiple times.
    contxt->name = old;
    contxt->call = n_gosub;
    contxt->type = CUSREF;

    return res;
}

//------------------------------------------------------------------------------
// (<procedure-name>)
//
// Trampoline function for invoking user defined procedures.
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_gosub(entry_p contxt)
{
    LG_ASSERT(s_sane(global(contxt), 0), end());
    bool strict = get_num(contxt, "@strict") == LG_TRUE;

    // Search for a procedure that matches the reference name.
    for(entry_p *cus = global(contxt)->symbols; exists(*cus); cus++)
    {
        // There should be nothing but variables and user procedures here.
        LG_ASSERT((*cus)->type == CUSTOM || (*cus)->type == SYMBOL, end());

        // Skip symbol if we don't have a match. Note that in sloppy mode the
        // ambiguous (sym) form is allowed where 'sym' can be either a user
        // defined procedure or a variable. This is forbidden in strict mode.
        if((strict && (*cus)->type != CUSTOM) ||
           strcasecmp((*cus)->name, contxt->name))
        {
           continue;
        }

        // See above. Ambiguous form.
        if((*cus)->type == SYMBOL)
        {
            break;
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
            while(exists(*arg) && exists(*ina))
            {
                entry_p res = DBG_ALLOC(malloc(sizeof(entry_t)));

                // Exit on OOM.
                LG_ASSERT(res, end());

                // Copy and free the resources from the last invocation, if any.
                memmove(res, resolve(*ina), sizeof(entry_t));
                res->name = res->name ? DBG_ALLOC(strdup(res->name)) : NULL;
                res->parent = *arg;
                kill((*arg)->resolved);
                (*arg)->resolved = res;

                // Turn function arguments into global variables.
                push(global(contxt), *arg);
                (*arg)->parent = *cus;

                // Continue until we have no more arguments or until the
                // procedure doesn't take any more arguments.
                arg++;
                ina++;
            }
        }

        // Keep track of the recursion depth. Do not go beyond LG_MAXDEP.
        static size_t dep;

        if(dep++ < LG_MAXDEP)
        {
            // Invoke user defined procedure.
            entry_p ret = invoke(*cus);
            dep--;
            return ret;
        }

        // We risk running out of stack if we don't abort.
        ERR(ERR_MAX_DEPTH, contxt->name);
        return end();
    }

    if(strict)
    {
        // There's no such procedure.
        ERR(ERR_UNDEF_FNC, contxt->name);
        return end();
    }

    // Transform into a string format call. See description of h_gosub_fmt().
    return h_gosub_fmt(contxt);
}

//------------------------------------------------------------------------------
// (procedure <procedure-name> [<args>] <statements>)
//    user defined procedure
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_procedure(entry_p contxt)
{
    // One argument.
    S_SANE(1);

    // The function itself and all arguments are global.
    entry_p cus = C_SYM(1), dst = global(contxt);

    // Create reference and reparent.
    push(dst, cus);
    cus->parent = contxt;

    if(!cus->symbols)
    {
        // No arguments.
        return cus;
    }

    // Create global reference to arguments and reparent.
    for(entry_p *arg = cus->symbols; exists(*arg); arg++)
    {
        push(dst, *arg);
        (*arg)->parent = cus;
    }

    // Return the function itself.
    return cus;
}
