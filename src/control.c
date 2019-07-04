//------------------------------------------------------------------------------
// control.c:
//
// Control structures
//------------------------------------------------------------------------------
// Copyright (C) 2018, Ola Söder. All rights reserved.
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
    for(int cont = mode ^ tru(C_ARG(1));
            cont && !DID_ERR;
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
// (retrace)
//     backtrace to the next to last backtrace position
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//------------------------------------------------------------------------------
entry_p m_retrace(entry_p contxt)
{
    // No arguments.
    C_SANE(0, NULL);

    // Starting point.
    entry_p con = contxt;

    // Find context or user procedure.
    while(con->parent && con->parent->type != CONTXT &&
          con->parent->type != CUSTOM)
    {
        // Climb one generation.
        con = con->parent;
    }

    // We should always have a CONTXT or CUSTOM parent.
    if(!con->parent || !con->parent->children)
    {
        // Nowhere to go.
        PANIC(con);
        R_CUR;
    }

    // Iterator and sentinel.
    entry_p *chl = con->parent->children;
    entry_p top = *chl;

    // Locate ourselves.
    while(*chl != con)
    {
        chl++;
    }

    // Locate the first trace point, unless we're first in line.
    if(*chl != top)
    {
        // Find first trace point.
        while(*(--chl) != top)
        {
            if((*chl)->call == m_trace)
            {
                // Found it.
                break;
            }
        }

        // Look for the second trace point, unless we're at the top by now.
        if(*chl != top)
        {
            // Find the second point.
            while(*(--chl) != top)
            {
                if((*chl)->call == m_trace)
                {
                    // Found it.
                    break;
                }
            }
        }
    }

    // Backtrack if we found two trace points.
    if((*chl)->call == m_trace)
    {
        // Expect failure.
        entry_p ret = end();
        entry_p *org = chl;

        // Stack frame counter.
        static int dep = 0;

        // Keep track of the recursion depth.
        if(++dep > MAXDEP)
        {
            // We risk running out of stack.
            ERR(ERR_MAX_DEPTH, con->name);
            R_CUR;
        }

        // As long as no one fails, resolve all children and save the return
        // value of the last one.
        for(; !DID_ERR; chl = org)
        {
            while(*chl && *chl != end() && !DID_ERR)
            {
                // Resolve and proceed.
                ret = resolve(*chl);
                chl++;
            }
        }

        // Leaving stack frame.
        dep--;

        // Return the last value.
        return ret;
    }

    // Nowhere to go.
    R_CUR;
}
