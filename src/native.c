#include <stdio.h>
#include "eval.h"
#include "native.h"
#include "util.h"
#include "error.h"
#include "debug.h"


entry_p m_set (entry_p contxt)
{
    entry_p dst; 
    S_CHECK(1);
    for(dst = contxt->parent; 
        dst && dst->type != CONTXT; 
        dst = dst->parent);
    if (dst)
    {
        entry_p *cur = contxt->symbols; 
        while(*cur && *cur != SENTINEL)
        {
            push(dst, *cur); 
            cur++; 
        }
        return new_success(); 
    }
    PANIC;
    return new_failure("No context"); 
}

/*
`(+ <expr1> <expr2> ...)'
     returns sum of expressions
*/
entry_p m_add (entry_p contxt)
{
    C_CHECK(2);
    return new_number
    (
        eval_as_number(contxt->children[0])->id +
        eval_as_number(contxt->children[1])->id
    ); 
}

/* 
`(- <expr1> <expr2>)'
     returns `<expr1>' minus `<expr2>'
*/
int m_sub(int a, int b)
{
    return a - b; 
}

/*
`(* <expr1> <expr2> ...)'
     returns product of expressions
*/
int m_mul(int a, int b)
{
    return a * b; 
}

/* 
`(/ <expr1> <expr2>)'
     returns `<expr1>' divided by `<expr2>'
*/
int m_div(int a, int b)
{
    return a / (b ? b : 1); 
}

/* 
`(AND <expr1> <expr2>)'
     returns logical `AND' of `<expr1>' and `<expr2>'
*/
int m_and(int a, int b)
{
    return a && b; 
}

/* 
`(OR <expr1> <expr2>)'
     returns logical `OR' of `<expr1>' and `<expr2>'
*/
int m_or(int a, int b)
{
    return a || b; 
}

/* 
`(XOR <expr1> <expr2>)'
     returns logical `XOR' of `<expr1>' and `<expr2>'
*/
int m_xor(int a, int b)
{
    return (a && !b) || (!a && b); 
}

/* 
`(NOT <expr>)'
     returns logical `NOT' of `<expr>'
*/
int m_not(int a)
{
    return !a; 
}

/* 
`(BITAND <expr1> <expr2>)'
     returns bitwise `AND' of `<expr1>' and `<expr2>'
*/
int m_bitand(int a, int b)
{
    return a & b; 
}

/* 
`(BITOR <expr1> <expr2>)'
     returns bitwise `OR' of `<expr1>' and `<expr2>'
*/
int m_bitor(int a, int b)
{
    return a | b; 
}

/* 
`(BITXOR <expr1> <expr2>)'
     returns bitwise `XOR' of `<expr1>' and `<expr2>'
*/
int m_bitxor(int a, int b)
{
    return a ^ b; 
}

/* 
`(BITNOT <expr>)'
     returns bitwise `NOT' of `<expr>'
*/
int m_bitnot(int a)
{
    return ~a; 
}

/* 
`(shiftleft <number> <amount to shift>)'
     logical shift left
*/
int m_shiftleft(int a, int n)
{
    return a << n; 
}

/* 
`(shiftright <number> <amount to shift>)'
     logical shift right
*/
int m_shiftright(int a, int n)
{
    return a >> n; 
}


/*
message
=  
>  
>= 
<  
<= 
<> 
set
symbolset
cat
substr
strlen
exists
makedir
copyfiles
textfile
rename
delete
procedure
welcome
copylib
startup
tooltype
execute
run
rexx
makeassign
protect
complete
working
user
debug
transcript
tackon
fileonly
pathonly
expandpath
askdir
askfile
askstring
asknumber
askchoice
askoptions
askbool
askdisk
earlier
getsize
getdevice
getdiskspace
getsum
getversion
getenv
getassign
iconinfo
database
select
patmatch
symbolval
*/
