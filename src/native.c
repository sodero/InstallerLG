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
        entry_p val = NULL; 
        entry_p *cur = contxt->symbols; 
        while(*cur && *cur != SENTINEL)
        {
            kill((*cur)->resolved);
            val = (*cur)->expression;
            (*cur)->resolved = resolve(val); 
            (*cur)->resolved->parent = *cur; 
            val = (*cur)->resolved;
            push(dst, *cur); 
            cur++; 
        }
        return resolve(val);
    }
    error(PANIC);
    return new_failure(); 
}

/*
*/
entry_p m_if(entry_p contxt)
{
    TRIPLES(c, p1, p2); 
    entry_p p = num(c) ? p1 : p2; 
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
    entry_p r = new_number(0); 
    TWINS(c, b); 
    while(num(c) && 
          !runtime_error())
    {
        if(b->type == CONTXT)
        {
            kill(r); 
            r = invoke(b);
        }
        else if(b->type == NATIVE ||
                b->type == CUSREF)
        {
            if(b->call)
            {
                kill(r); 
                r = b->call(b); 
            }
            else
            {
                error(PANIC);
            }
        }
    }
    return r; 
}

/*
`(+ <expr1> <expr2> ...)'
     returns sum of expressions
*/
entry_p m_add (entry_p contxt)
{
    if(contxt && 
       contxt->children)
    {
        int s = 0; 
        entry_p *cur = contxt->children; 
        while(*cur && *cur != SENTINEL)
        {
            s += num(*cur);
            cur++; 
        }
        return new_number(s); 
    }
    else
    {
        error(PANIC);
        pretty_print(contxt);
        return new_failure();
    }
}

/*
`(< <expr1> <expr2>)'
     less than test (returns 0 or 1)
*/
entry_p m_lt(entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
        ((a->type == STRING && b->type == STRING && strcmp(a->name, b->name) < 0) ||
         (!(a->type == STRING && b->type == STRING) && num(a) < num(b))) ? 1 : 0
    );
}

/*
`(<= <expr1> <expr2>)'
     less than or equal test (returns 0 or 1)
*/
entry_p m_lte(entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
        ((a->type == STRING && b->type == STRING && strcmp(a->name, b->name) <= 0) ||
         (!(a->type == STRING && b->type == STRING) && num(a) <= num(b))) ? 1 : 0
    );
}

/*
`(< <expr1> <expr2>)'
     greater than test (returns 0 or 1)
*/
entry_p m_gt(entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
        ((a->type == STRING && b->type == STRING && strcmp(a->name, b->name) > 0) ||
         (!(a->type == STRING && b->type == STRING) && num(a) > num(b))) ? 1 : 0
    );
}

/*
`(<= <expr1> <expr2>)'
     greater than or equal test (returns 0 or 1)
*/
entry_p m_gte(entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
        ((a->type == STRING && b->type == STRING && strcmp(a->name, b->name) >= 0) ||
         (!(a->type == STRING && b->type == STRING) && num(a) >= num(b))) ? 1 : 0
    );
}

/*
`(= <expr1> <expr2>)'
     equality test (returns 0 or 1)
*/
entry_p m_eq(entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
        ((a->type == STRING && b->type == STRING && !strcmp(a->name, b->name)) ||
         (!(a->type == STRING && b->type == STRING) && num(a) == num(b))) ? 1 : 0
    );
}

/* 
`(- <expr1> <expr2>)'
     returns `<expr1>' minus `<expr2>'
*/
entry_p m_sub(entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
         num(a) - num(b)
    );
}

/*
`(* <expr1> <expr2> ...)'
     returns product of expressions
*/
entry_p m_mul(entry_p contxt)
{
    if(contxt && 
       contxt->children)
    {
        int s = 1; 
        entry_p *cur = contxt->children; 
        while(*cur && *cur != SENTINEL)
        {
            s *= num(*cur);
            cur++; 
        }
        return new_number(s); 
    }
    else
    {
        error(PANIC);
        pretty_print(contxt);
        return new_failure();
    }
}

/* 
`(/ <expr1> <expr2>)'
     returns `<expr1>' divided by `<expr2>'
*/
entry_p m_div(entry_p contxt)
{
    TWINS(a, b); 
    if(num(b))
    {
        return new_number
        (
            num(a) / num(b)
        );
    }
    else
    {
        error(contxt->id, "Division by zero", 
              contxt->name); 
        return new_failure(); 
    }
}

/* 
`("<fmt>" <expr1> <expr2>)'
     returns a formatted string
*/
entry_p m_fmt(entry_p contxt)
{
    char *ret = NULL, *fmt = contxt->name; 
    char **sct = calloc((strlen(fmt) >> 1) + 1, sizeof(char *));
    if(contxt && fmt && sct)
    {
        int i = 0, j = 0, k = 0, l = 0; 
        entry_p *arg = contxt->children; 
        for(; fmt[i]; i++)
        {
            if(fmt[i] == '%')
            {
                if(!i || (i && fmt[i - 1] != '\\'))
                {
                    i++; 
                    if(fmt[i] == 's' || (
                       fmt[i++] == 'l' &&
                       fmt[i] && fmt[i] == 'd'))
                    {
                        sct[k] = calloc(i - j + 2, sizeof(char)); 
                        if(sct[k])
                        {
                            memmove(sct[k], fmt + j, i - j + 1);
                            j = i + 1;  
                            k++; 
                        }
                        else
                        {
                            error(PANIC);
                        }
                    }
                    else 
                    {
                        error(contxt->id, "Invalid format string", 
                        contxt->name); 
                        break; 
                    }
                }
            }
        }
        if(k)
        {
            for(k = 0; sct[k]; k++)
            {
                if(arg && *arg && 
                   *arg != SENTINEL)
                {
                    int oln = strlen(sct[k]);  
                    entry_p cur = resolve(*arg); 
                    if(sct[k][oln - 1] == 's' &&
                       cur->type == STRING)
                    {
                        int nln = oln + strlen(cur->name);  
                        char *new = calloc(nln + 1, sizeof(char)); 
                        if(new)
                        {
                            l += snprintf(new, nln, sct[k], cur->name);  
                            free(sct[k]); 
                            sct[k] = new; 
                        }
                        else
                        {
                            error(PANIC);
                        }
                    }
                    else
                    if(sct[k][oln - 1] == 'd' &&
                       cur->type == NUMBER)
                    {
                        int nln = oln + 16;  
                        char *new = calloc(nln + 1, sizeof(char)); 
                        if(new)
                        {
                            l += snprintf(new, nln, sct[k], cur->id);  
                            free(sct[k]); 
                            sct[k] = new; 
                        }
                        else
                        {
                            error(PANIC);
                        }
                    }
                    else
                    {
                        error(contxt->id, "Format string type mismatch", 
                        contxt->name); 
                    }
                    kill(cur); 
                    arg++; 
                }
                else 
                {
                    error(contxt->id, "Missing format string arguments", 
                    contxt->name); 
                    break; 
                }
            }
        }
        l += strlen(fmt + j); 
        ret = calloc(l + 1, sizeof(char)); 
        if(ret)
        {
            for(k = 0; sct[k]; k++)
            {
                strcat(ret, sct[k]); 
            }
            strcat(ret, fmt + j); 
        }
        else
        {
            error(PANIC);
        }
        for(k = 0; sct[k]; k++)
        {
            free(sct[k]);
        }
        free(sct);
        if(arg && *arg && 
           *arg != SENTINEL)
        {
            error(contxt->id, "Superfluous format string arguments", 
                  contxt->name); 
        }
        else
        if(ret)
        {
            return new_string(ret); 
        }
    }
    else
    {
        error(PANIC);
    }
    free(ret);
    return new_failure(); 
}

/* 
`(AND <expr1> <expr2>)'
     returns logical `AND' of `<expr1>' and `<expr2>'
*/
entry_p m_and(entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
        num(a) && num(b)
    );
}

/* 
`(OR <expr1> <expr2>)'
     returns logical `OR' of `<expr1>' and `<expr2>'
*/
entry_p m_or(entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
        num(a) || num(b)
    );
}

/* 
`(XOR <expr1> <expr2>)'
     returns logical `XOR' of `<expr1>' and `<expr2>'
*/
entry_p m_xor(entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
        (num(a) && !num(b)) || 
        (num(b) && !num(a)) 
    );
}

/* 
`(NOT <expr>)'
     returns logical `NOT' of `<expr>'
*/
entry_p m_not(entry_p contxt)
{
    ONLY(a); 
    return new_number
    (
         !num(a)
    );
}

/* 
`(BITAND <expr1> <expr2>)'
     returns bitwise `AND' of `<expr1>' and `<expr2>'
*/
entry_p m_bitand(entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
         num(a) & num(b)
    );
}

/* 
`(BITOR <expr1> <expr2>)'
     returns bitwise `OR' of `<expr1>' and `<expr2>'
*/
entry_p m_bitor(entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
         num(a) | num(b)
    );
}

/* 
`(BITXOR <expr1> <expr2>)'
     returns bitwise `XOR' of `<expr1>' and `<expr2>'
*/
entry_p m_bitxor(entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
         num(a) ^ num(b)
    );
}

/* 
`(BITNOT <expr>)'
     returns bitwise `NOT' of `<expr>'
*/
entry_p m_bitnot(entry_p contxt)
{
    ONLY(a); 
    return new_number
    (
         ~num(a)
    );
}

/* 
`(shiftleft <number> <amount to shift>)'
     logical shift left
*/
entry_p m_shiftleft(entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
         num(a) << num(b)
    );
}

/* 
`(shiftright <number> <amount to shift>)'
     logical shift right
*/
entry_p m_shiftright(entry_p contxt)
{
    TWINS(a, b); 
    return new_number
    (
         num(a) >> num(b)
    );
}

/*
message
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
