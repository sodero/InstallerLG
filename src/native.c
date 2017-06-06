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
                    while(*arg && 
                         (*arg)->expression &&
                          *ina)
                    {
                        if((*ina)->type == CUSREF &&
                           !strcmp((*ina)->name, contxt->name))          
                        {
                            error(contxt->id, "Infinite recursion", 
                                  contxt->name); 
                            return new_failure(); 
                        }
                        (*arg)->expression = *ina; 
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
    entry_p dst; 
    CHECK_SYMS(1);
    dst = global(contxt);
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
    CHECK_CHLD(3);
    entry_p cond = contxt->children[0];
    entry_p path = eval_as_number(cond)->id ? 
                   contxt->children[1] :
                   contxt->children[2];
    if(path->type == CONTXT)
    {
        return invoke(path);
    }
    else if(path->type == NATIVE ||
            path->type == CUSREF)
    {
        if(path->call)
        {
            return path->call(path); 
        }
    }
    error(PANIC);
    return new_failure(); 
}

/*
*/
entry_p m_while(entry_p contxt)
{
    CHECK_CHLD(2);
    entry_p ret = new_failure(); 
    entry_p cnd = contxt->children[0];
    entry_p bdy = contxt->children[1]; 

    while(eval_as_number(cnd)->id)
    {
printf("%d\n", eval_as_number(cnd)->id); 
        if(bdy->type == CONTXT)
        {
            kill(ret); 
            ret = invoke(bdy);
        }
        else if(bdy->type == NATIVE ||
                bdy->type == CUSREF)
        {
//pretty_print(bdy);
            if(bdy->call)
            {
//    HERE; 
                kill(ret); 
                ret = bdy->call(bdy); 
            }
            else
            {
//    HERE; 
                error(PANIC);
            }
        }
//    HERE; 
    }
//    HERE; 
    return ret; 
}

/*
`(+ <expr1> <expr2> ...)'
     returns sum of expressions
*/
entry_p m_add (entry_p contxt)
{
    CHECK_CHLD(2);
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
