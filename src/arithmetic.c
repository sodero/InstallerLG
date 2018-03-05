//----------------------------------------------------------------------------
// arithmetic.c: 
//
// Arithmetic operations 
//
//----------------------------------------------------------------------------

#include "alloc.h"
#include "arithmetic.h"
#include "error.h"
#include "eval.h"
#include "util.h"

//----------------------------------------------------------------------------
// (+ <expr1> <expr2> ...)
//     returns sum of expressions
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_add (entry_p contxt)
{
    // We should have one or more arguments.
    if(c_sane(contxt, 1))
    {
        // Work directly with our resolved
        // value.
        DNUM = 0; 
        entry_p *cur = contxt->children; 

        // For each child, add the numeric
        // value to our resolved value. 
        while(*cur && *cur != end())
        {
            DNUM += num(*cur);
            cur++; 
        }

        // Return the resolved value of this
        // function / context.
        RCUR; 
    }
    else
    {
        // The parser is broken.
        error(PANIC);
        RCUR; 
    }
}

//----------------------------------------------------------------------------
// (/ <expr1> <expr2>)
//     returns `<expr1>' divided by `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_div(entry_p contxt)
{
    // We should have exactly two arguments. 
    if(c_sane(contxt, 2))
    {
        // Let's not divide by zero.
        DNUM = num(CARG(2)); 
        if(DNUM)
        {
            RNUM
            (
                num(CARG(1)) / 
                DNUM 
            ); 
        }
        else
        {
            // Fail and return undefined value. 
            error(contxt->id, ERR_DIV_BY_ZERO, contxt->name); 
            RCUR; 
        }
    }
    else
    {
        // The parser is broken
        error(PANIC);
        RCUR; 
    }
}

//----------------------------------------------------------------------------
// (* <expr1> <expr2> ...)
//     returns product of expressions
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_mul(entry_p contxt)
{
    // We should have one or more arguments.
    if(c_sane(contxt, 1))
    {
        DNUM = 1; 

        // Multiply all children. The first
        // is multiplied by 1.
        entry_p *cur = contxt->children; 
        while(*cur && *cur != end())
        {
            DNUM *= num(*cur);
            cur++; 
        }

        // Return whatever we have in DNUM
        // at this point. 
        RCUR; 
    }
    else
    {
        // The parser is broken
        error(PANIC);
        RCUR; 
    }
}

//----------------------------------------------------------------------------
// (- <expr1> <expr2>)
//     returns `<expr1>' minus `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_sub(entry_p contxt)
{
    // We should have two arguments
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            num(CARG(1)) - 
            num(CARG(2))
        ); 
    }
    else
    {
        // The parser is broken
        error(PANIC);
        RCUR; 
    }
}
