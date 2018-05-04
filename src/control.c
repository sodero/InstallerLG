//----------------------------------------------------------------------------
// control.c: 
//
// Control structures
//
//----------------------------------------------------------------------------

#include "alloc.h"
#include "control.h"
#include "error.h"
#include "eval.h"
#include "util.h"

//----------------------------------------------------------------------------
// (if <condition> <then-statement> [<else-statements>])
//     conditional
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_if(entry_p contxt)
{
    // We always have atleast two arguments, the expression, 
    // the TRUE branch and optionally the FALSE branch.
    if(c_sane(contxt, 2))
    {
        // Let p be the branch that will be executed.
        entry_p p = num(CARG(1)) ? CARG(2) : CARG(3); 

        // If the expression is FALSE and we don't have
        // any FALSE branch, p will be either NULL if 
        // there is room left in the array, or end() if
        // it's full. 
        if(!p || p == end())
        {
            // We have nothing to execute.
            RNUM(0); 
        }

        // Branches could be either compound statements,
        // CONTXT or ...
        if(p->type == CONTXT)
        {
            // The return value is the return value of the 
            // last function in the compound statement. 
            return invoke(p);
        }
        // a single function, NATIVE, or a user procedure, 
        // CUSREF.
        else 
        if((p->type == NATIVE ||
            p->type == CUSREF) &&
            p->call)
        {
            // The return value is the return value of the 
            // function / user procedure. 
            return p->call(p); 
        }
    }

    // The parser is broken, either the context
    // is broken or we have invalid types in the
    // branch nodes. 
    error(PANIC);
    RCUR; 
}

//----------------------------------------------------------------------------
// (select <n> <item1> <item2> ...)
//     return n'th item
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_select(entry_p contxt)
{
    // We need atleast two arguments, the index
    // and the non-empty list of items.
    if(c_sane(contxt, 2))
    {
        int i = 0, j = num(CARG(1)) - 1; 

        // Find the n:th item, go one step at a time
        // in case no such item exist.
        while(CARG(2)->children[i] && 
              CARG(2)->children[i] != end())
        {
            // Return the resolved value of the found
            // item. 
            if(i == j)
            {
                return resolve(CARG(2)->children[i]); 
            }
            i++; 
        }

        // No such item, n > the number of items. 
        error(contxt->id, ERR_NO_ITEM, str(CARG(1))); 
        RNUM(0); 
    }
    else
    {
        // The parser is broken
        error(PANIC); 
        RCUR;
    }
}

//----------------------------------------------------------------------------
// (while ...) (m = 0) and (until ...) (m = 1)
//     helper / implementation
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
static entry_p h_whunt(entry_p contxt, int m)
{
    // We always have two arguments, the expression
    // and the 'contents' of the loop, a CONTXT.
    if(c_sane(contxt, 2) &&
       CARG(2)->type == CONTXT)
    {
        // Set the return value of this function to zero.
        DNUM = 0; 

        // Prepare to return the resolved value of this 
        // function if the expression is false from the start. 
        entry_p r = contxt->resolved; 

        // Use XOR to support both 'while' and 'until'. Break 
        // the loop if something goes wrong inside.
        while((m ^ num(CARG(1))) && 
              !did_error())
        {
            // Save the return value of the last function
            // in the CONTXT
            r = invoke(CARG(2));
        }

        // Return either zero, the value of the resolved 
        // value of this function, or the return value of 
        // the last function in the last iteration.
        return r; 
    }
    else
    {
        // The parser is broken
        error(PANIC);
        RCUR; 
    }
}

//----------------------------------------------------------------------------
// (until <expr> <statements>)
//     do-until conditional structure (test end of loop)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_until(entry_p contxt)
{
    // Implemented in h_whunt.
    return h_whunt(contxt, 1); 
}

//----------------------------------------------------------------------------
// (while <expr> <statements>)
//     do-while conditional structure (test top of loop)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_while(entry_p contxt)
{
    // Implemented in h_whunt.
    return h_whunt(contxt, 0); 
}
