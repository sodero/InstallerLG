#include <stdio.h>
#include <string.h>
#include "eval.h"
#include "native.h"
#include "util.h"
#include "error.h"
#include "debug.h"

/*
*/
entry_p m_gosub(entry_p contxt)
{
    entry_p con = global(contxt);  
    if (con && con->children)
    {
        entry_p *cus = con->children; 
        while(*cus && 
              *cus != SENTINEL)
        {
            if((*cus)->type == CUSTOM &&
               !strcmp((*cus)->name, contxt->name))
            {
                entry_p *arg = (*cus)->symbols, 
                        *ina = contxt->children;
                if(arg && ina)
                {
                    while(*arg && *ina)
                    {
                        kill((*arg)->resolved); 
                        (*arg)->resolved = resolve(*ina); 
                        arg++; 
                        ina++;
                    }
                }
                return invoke(*cus); 
            }
            cus++; 
        }
        error(contxt->id, "Undefined function", 
              contxt->name); 
    }
    else
    {
        error(PANIC);
    }
    return new_failure(); 
}

/*
*/
entry_p m_set (entry_p contxt)
{
    entry_p dst = global(contxt);
    if (dst)
    {
        entry_p *cur = contxt->symbols; 
        while(*cur && *cur != SENTINEL)
        {
            kill((*cur)->resolved);
            (*cur)->resolved = resolve((*cur)->expression); 
            (*cur)->resolved->parent = *cur; 
            push(dst, *cur); 
            cur++; 
        }
        return new_success(); 
    }
    error(PANIC);
    return new_failure(); 
}

/*
*/
entry_p m_if(entry_p contxt)
{
    TRIPLES(c, p1, p2); 
    entry_p p = eval_as_number(c)->id ? p1 : p2; 
    if(p->type == CONTXT)
    {
        return invoke(p);
    }
    else if(p->type == NATIVE ||
            p->type == CUSREF)
    {
        if(p->call)
        {
            return p->call(p); 
        }
    }
    error(PANIC);
    return new_failure(); 
}

/*
*/
entry_p m_while(entry_p contxt)
{
    entry_p ret = new_failure(); 
    TWINS(c, b); 
    while(eval_as_number(c)->id)
    {
        if(b->type == CONTXT)
        {
            kill(ret); 
            ret = invoke(b);
        }
        else if(b->type == NATIVE ||
                b->type == CUSREF)
        {
            if(b->call)
            {
                kill(ret); 
                ret = b->call(b); 
            }
            else
            {
                error(PANIC);
            }
        }
    }
    return ret; 
}

/*
`(+ <expr1> <expr2> ...)'
     returns sum of expressions
*/
entry_p m_add (entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
        eval_as_number(a)->id +
        eval_as_number(b)->id
    ); 
}

/*
 Impl. helper; < <= = > >=. 
*/
static entry_p m_cmp(entry_p contxt, char c1, char c2)
{
    int r; 
    TWINS(a, b); 
    if(a->type == STRING &&
       b->type == STRING)
    {
        r = strcmp(a->name, b->name); 
    }
    else
    {
        r = eval_as_number(a)->id - 
            eval_as_number(b)->id;
    }
    r = (c1 == '=' && r == 0) ||
        (c2 == '<' && r < 0) ||
        (c2 == '>' && r > 0) ? 1 : 0; 
    return new_number(r);
}

/*
`(< <expr1> <expr2>)'
     less than test (returns 0 or 1)
*/
entry_p m_lt(entry_p contxt)
{
    return m_cmp(contxt, '\0', '<');
}

/*
`(<= <expr1> <expr2>)'
     less than or equal test (returns 0 or 1)
*/
entry_p m_lte(entry_p contxt)
{
    return m_cmp(contxt, '=', '<');
}

/*
`(< <expr1> <expr2>)'
     greater than test (returns 0 or 1)
*/
entry_p m_gt(entry_p contxt)
{
    return m_cmp(contxt, '\0', '>');
}

/*
`(<= <expr1> <expr2>)'
     greater than or equal test (returns 0 or 1)
*/
entry_p m_gte(entry_p contxt)
{
    return m_cmp(contxt, '=', '>');
}

/*
`(= <expr1> <expr2>)'
     equality test (returns 0 or 1)
*/
entry_p m_eq(entry_p contxt)
{
    return m_cmp(contxt, '=', '\0');
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
