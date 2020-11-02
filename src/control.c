//------------------------------------------------------------------------------
// control.c:
//
// Control structures
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "control.h"
#include "error.h"
#include "eval.h"
#include "util.h"

// Iteration mode.
#define LG_UNTIL true
#define LG_WHILE false

//------------------------------------------------------------------------------
// (if <condition> <then-statement> [<else-statements>])
//     conditional
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_if(entry_p contxt)
{
    // Allow empty bodies.
    C_SANE(1, NULL);

    // Always resolve the conditional to evoke side effects.
    bool val = tru(C_ARG(1));

    // Prepare to dangle if the condition is false from the start.
    contxt->resolved = end();

    // Does the body contain anything?
    if(exists(C_ARG(2)))
    {
        // Select branch to execute (if any).
        entry_p sel = val ? C_ARG(2) : C_ARG(3);

        if(exists(sel))
        {
            // Execute the branch by resolving it.
            contxt->resolved = resolve(sel);
        }
    }

    // Dangle or resolved branch.
    return contxt->resolved;
}

//------------------------------------------------------------------------------
// (select <n> <item1> <item2> ...)
//     return n'th item
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_select(entry_p contxt)
{
    // We need an index.
    C_SANE(1, NULL);

    // Selected item.
    int32_t sel = num(C_ARG(1));

    // Prepare to dangle if there's no such item.
    contxt->resolved = end();

    // One step at a time in case no item exists.
    for(int32_t cur = 2; exists(C_ARG(cur)); cur++)
    {
        if((cur - 2) == sel)
        {
            // Set and return resolved value.
            contxt->resolved = resolve(C_ARG(cur));
            return contxt->resolved;
        }
    }

    // No such item, n + 1 > number of items.
    ERR(ERR_NO_ITEM, str(C_ARG(1)));
    return end();
}

//------------------------------------------------------------------------------
// (while ...) (until == 'false') and (until ...) (until == 'true')
//     helper / implementation
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
static entry_p h_whunt(entry_p contxt, bool until)
{
    // One or more arguments, the condition and the (optional) body.
    C_SANE(1, NULL);

    // Prepare to dangle if the condition is false from the start.
    contxt->resolved = end();

    // Use XOR to support both 'while' and 'until'. Break on error.
    for(bool cont = until ^ tru(C_ARG(1)); cont && NOT_ERR;
        cont = until ^ tru(C_ARG(1)))
    {
        // Save the return value of the last function in the CONTXT or, if the
        // body is empty, don't do anything at all.
        if(exists(C_ARG(2)))
        {
            contxt->resolved = resolve(C_ARG(2));
        }
    }

    // Return either LG_FALSE, the value of the resolved value of this function,
    // or the return value of the last function in the last iteration.
    return contxt->resolved;
}

//------------------------------------------------------------------------------
// (until <expr> <statements>)
//     do-until conditional structure (test end of loop)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_until(entry_p contxt)
{
    // Implemented in h_whunt.
    return h_whunt(contxt, LG_UNTIL);
}

//------------------------------------------------------------------------------
// (while <expr> <statements>)
//     do-while conditional structure (test top of loop)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_while(entry_p contxt)
{
    // Implemented in h_whunt.
    return h_whunt(contxt, LG_WHILE);
}

//------------------------------------------------------------------------------
// (trace)
//     set a backtrace position
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//------------------------------------------------------------------------------
entry_p n_trace(entry_p contxt)
{
    // No arguments.
    C_SANE(0, NULL);

    // We're not doing anything except occupying space.
    R_NUM(LG_TRUE);
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

    entry_p *chl = contxt->parent->children;

    // Assert a non-broken parser.
    LG_ASSERT(chl, NULL);

    size_t pos = 0;

    // Locate ourselves among the children of our parent.
    while(chl[pos] != contxt)
    {
        pos++;
    }

    // Find trace point before current contxt.
    while(pos--)
    {
        // Use pointer to identify (trace).
        if(chl[pos]->call == n_trace)
        {
            return chl + pos;
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
entry_p n_retrace(entry_p contxt)
{
    // No arguments.
    C_SANE(0, NULL);

    // Backtrack to first trace point.
    entry_p *top = h_retrace(contxt);

    // Backtrack to second trace point.
    top = top ? h_retrace(*top) : NULL;

    if(!top)
    {
        // Exit if there's nowhere to go.
        R_NUM(HALT);
    }

    // Stack frame counter.
    static int dep = 0;

    // Keep track of the recursion depth.
    if(++dep > LG_MAXDEP)
    {
        ERR(ERR_MAX_DEPTH, contxt->name);
        R_NUM(LG_FALSE);
    }

    // Expect failure.
    entry_p ret = end();

    // Resolve children and save return values.
    while(exists(*top) && NOT_ERR)
    {
        ret = resolve(*top);
        top++;
    }

    // Leaving stack frame.
    dep--;

    // Return the last value.
    return ret;
}
