//------------------------------------------------------------------------------
// control.c:
//
// Control structures
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "control.h"
#include "error.h"
#include "eval.h"
#include "util.h"

//------------------------------------------------------------------------------
// (if <condition> <then-statement> [<else-statements>])
//     conditional
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_if(entry_p contxt)
{
    // Allow empty bodies. If empty, resolve the conditional so that side
    // effects, if any, will come into being.
    C_SANE(1, NULL);

    // Truth value of the condition.
    int val = tru(C_ARG(1));

    // Does the body contain anything?
    if(C_ARG(2) && C_ARG(2) != end())
    {
        // Select branch to execute.
        entry_p sel = val ? C_ARG(2) : C_ARG(3);

        // Is there a branch corresponding to the resolved truth value?
        if(sel && sel != end())
        {
            // Execute the branch by resolving it.
            return resolve(sel);
        }
    }

    // Nothing to resolve.
    R_NUM(0);
}

//------------------------------------------------------------------------------
// (select <n> <item1> <item2> ...)
//     return n'th item
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_select(entry_p contxt)
{
    // We need atleast two arguments, the index and the list of items.
    C_SANE(2, NULL);

    // Index and selection.
    int ndx = 0, sel = num(C_ARG(1));

    // Find the n:th item, go one step at a time in case no such item exists.
    for(entry_p *items = C_ARG(2)->children;
        items[ndx] && items[ndx] != end(); ndx++)
    {
        // Are we there yet?
        if(ndx == sel)
        {
            // Return resolved value.
            return resolve(items[ndx]);
        }
    }

    // No such item, n + 1 > the number of items.
    ERR(ERR_NO_ITEM, str(C_ARG(1)));
    R_NUM(0);
}

//------------------------------------------------------------------------------
// (while ...) (m = 0) and (until ...) (m = 1)
//     helper / implementation
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
static entry_p h_whunt(entry_p contxt, int mode)
{
    // Two arguments, the condition and the body of the loop.
    C_SANE(2, NULL);

    // Reset return value.
    D_NUM = 0;

    // Prepare to return the resolved value of this function if the condition
    // is false from the start.
    entry_p ret = contxt->resolved;

    // Use XOR to support both 'while' and 'until'. Break if something goes
    // wrong inside.
    for(int cont = mode ^ tru(C_ARG(1)); cont && !DID_ERR;
        cont = mode ^ tru(C_ARG(1)))
    {
        // Save the return value of the last function in the CONTXT
        ret = invoke(C_ARG(2));
    }

    // Return either zero, the value of the resolved value of this function,
    // or the return value of the last function in the last iteration.
    return ret;
}

//------------------------------------------------------------------------------
// (until <expr> <statements>)
//     do-until conditional structure (test end of loop)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_until(entry_p contxt)
{
    // Implemented in h_whunt.
    return h_whunt(contxt, 1);
}

//------------------------------------------------------------------------------
// (while <expr> <statements>)
//     do-while conditional structure (test top of loop)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_while(entry_p contxt)
{
    // Implemented in h_whunt.
    return h_whunt(contxt, 0);
}

//------------------------------------------------------------------------------
// (trace)
//     set a backtrace position
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//------------------------------------------------------------------------------
entry_p m_trace(entry_p contxt)
{
    // No arguments.
    C_SANE(0, NULL);

    // We're not doing anything except occupying space.
    R_NUM(1);
}

//------------------------------------------------------------------------------
// Name:        h_retrace
// Description: Backtrack to the next trace point.
// Input:       entry_p contxt: The start context.
// Return:      entry_p *:      Pointer to a trace point, if it exists, NULL
//                              otherwise.
//------------------------------------------------------------------------------
static entry_p *h_retrace(entry_p contxt)
{
    // Stop at the root. User procedures are considered roots. It's not possible
    // to escape a function scope with (retrace).
    if(!contxt || contxt->type == CUSTOM || !contxt->parent)
    {
        return NULL;
    }

    // We must be a child of our parent.
    entry_p *chl = contxt->parent->children;

    if(!chl)
    {
        PANIC(contxt);
        return NULL;
    }

    size_t pos = 0;

    // Locate ourselves among the children.
    while(chl[pos] != contxt)
    {
        pos++;
    }

    // Find trace point before current contxt.
    while(pos--)
    {
        // Use pointer to identify (trace).
        if(chl[pos]->call == m_trace)
        {
            return(chl + pos);
        }
    }

    // No trace point found. Climb up the tree.
    return h_retrace(contxt->parent);
}

//------------------------------------------------------------------------------
// (retrace)
//     backtrace to the next to last backtrace position
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//------------------------------------------------------------------------------
entry_p m_retrace(entry_p contxt)
{
    // No arguments.
    C_SANE(0, NULL);

    // Backtrack to first trace point.
    entry_p *top = h_retrace(contxt);

    // Backtrack to second trace point.
    top = top ? h_retrace(*top) : NULL;

    // Resolve if we have two trace points.
    if(top)
    {
        // Stack frame counter.
        static int dep = 0;

        // Keep track of the recursion depth.
        if(++dep > MAXDEP)
        {
            ERR(ERR_MAX_DEPTH, contxt->name);
            R_CUR;
        }

        // Expect failure.
        entry_p ret = end();

        // Resolve children and save return values.
        while(*top && *top != end() && !DID_ERR)
        {
            ret = resolve(*top);
            top++;
        }

        // Leaving stack frame.
        dep--;

        // Return the last value.
        return ret;
    }

    // Nowhere to go.
    R_CUR;
}
