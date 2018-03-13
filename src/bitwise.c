//----------------------------------------------------------------------------
// bitwise.c: 
//
// Bitwise operations 
//
//----------------------------------------------------------------------------

#include "alloc.h"
#include "bitwise.h"
#include "error.h"
#include "eval.h"
#include "util.h"

//----------------------------------------------------------------------------
// (AND <expr1> <expr2>)
//     returns logical `AND' of `<expr1>' and `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_and(entry_p contxt)
{
    // We need two arguments. 
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            num(CARG(1)) && 
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

//----------------------------------------------------------------------------
// (BITAND <expr1> <expr2>)
//     returns bitwise `AND' of `<expr1>' and `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_bitand(entry_p contxt)
{
    // We need two arguments. 
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            num(CARG(1)) & 
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

//----------------------------------------------------------------------------
// (BITNOT <expr>)
//     returns bitwise `NOT' of `<expr>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_bitnot(entry_p contxt)
{
    // We need a single argument. 
    if(c_sane(contxt, 1))
    {
        RNUM
        (
            ~num(CARG(1))
        );
    }
    else
    {
        // The parser is broken
        error(PANIC);
        RCUR; 
    }
}

//----------------------------------------------------------------------------
// (BITOR <expr1> <expr2>)
//     returns bitwise `OR' of `<expr1>' and `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_bitor(entry_p contxt)
{
    // We need two arguments. 
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            num(CARG(1)) | 
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

//----------------------------------------------------------------------------
// (BITXOR <expr1> <expr2>)
//     returns bitwise `XOR' of `<expr1>' and `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_bitxor(entry_p contxt)
{
    // We need two arguments. 
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            num(CARG(1)) ^
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

//----------------------------------------------------------------------------
// (NOT <expr>)
//     returns logical `NOT' of `<expr>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_not(entry_p contxt)
{
    // We need a single argument. 
    if(c_sane(contxt, 1))
    {
        RNUM
        (
            !num(CARG(1))
        );
    }
    else
    {
        // The parser is broken
        error(PANIC);
        RCUR; 
    }
}

//----------------------------------------------------------------------------
// (IN <expr> <bit-number> <bitnumber>...)
//     returns `<expr>' `AND' bits
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_in(entry_p contxt)
{
    // We need atleast two arguments. 
    if(c_sane(contxt, 2))
    {
        DNUM = 0;  

        // For all the children in the context
        // of the second argument, create the
        // corresponding bitmask. 
        entry_p *cur = CARG(2)->children; 
        while(*cur && *cur != end())
        {
            DNUM += 1 << num(*cur);
            cur++; 
        }

        // Apply the bitmask to the first 
        // argument and return the result. 
        RNUM
        (
            num(CARG(1)) & 
            DNUM 
        );
    }
    else
    {
        // The parser is broken
        error(PANIC);
        RCUR; 
    }
}

//----------------------------------------------------------------------------
// (OR <expr1> <expr2>)
//     returns logical `OR' of `<expr1>' and `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_or(entry_p contxt)
{
    // We need two arguments. 
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            num(CARG(1)) ||  
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

//----------------------------------------------------------------------------
// (shiftleft <number> <amount to shift>)
//     logical shift left
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_shiftleft(entry_p contxt)
{
    // We need two arguments. 
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            num(CARG(1)) << 
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

//----------------------------------------------------------------------------
// (shiftright <number> <amount to shift>)
//     logical shift right
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_shiftright(entry_p contxt)
{
    // We need two arguments. 
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            num(CARG(1)) >> 
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

//----------------------------------------------------------------------------
// (XOR <expr1> <expr2>)
//     returns logical `XOR' of `<expr1>' and `<expr2>'
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_xor(entry_p contxt)
{
    // We need two arguments. 
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            (
                num(CARG(1)) && !num(CARG(2))
            ) 
            || 
            (
                num(CARG(2)) && !num(CARG(1))
            ) 
        );
    }
    else
    {
        // The parser is broken
        error(PANIC);
        RCUR; 
    }
}