#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include "eval.h"
#include "native.h"
#include "util.h"
#include "error.h"
#include "debug.h"

/*
*/
entry_p m_procedure(entry_p contxt)
{
    entry_p dst = global(contxt);
    if(dst && s_sane(contxt, 1))
    {
        push(dst, contxt->symbols[0]); 
        contxt->symbols[0]->parent = contxt; 
        return contxt->symbols[0];
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
*/
entry_p m_if(entry_p contxt)
{
    if(c_sane(contxt, 3))
    {
        entry_p p = num(CARG(1)) ? CARG(2) : CARG(3); 
        if(p->type == CONTXT)
        {
            return invoke(p);
        }
        else 
        if((p->type == NATIVE ||
            p->type == CUSREF) &&
            p->call)
        {
            return p->call(p); 
        }
    }
    error(PANIC);
    RCUR; 
}

/*
*/
static entry_p h_whunt(entry_p contxt, int m)
{
    if(c_sane(contxt, 2) &&
       CARG(2)->type == CONTXT)
    {
        DNUM = 0; 
        entry_p r = DCUR; 
        while((m ^ num(CARG(1))) && 
              !did_error())
        {
            r = invoke(CARG(2));
        }
        return r; 
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
*/
entry_p m_while(entry_p contxt)
{
    return h_whunt(contxt, 0); 
}

/*
*/
entry_p m_until(entry_p contxt)
{
    return h_whunt(contxt, 1); 
}

/*
*/
entry_p m_gosub(entry_p contxt)
{
    static int dep = 0; 
    entry_p con = global(contxt);  
    if(s_sane(con, 0)) 
    {
        entry_p *cus = con->symbols; 
        while(*cus && 
              *cus != end())
        {
            if((*cus)->type == CUSTOM &&
               !strcmp((*cus)->name, contxt->name))
            {
                entry_p ret; 
                entry_p *arg = (*cus)->symbols, 
                        *ina = contxt->children;
                if(arg && ina)
                {
                    while(*arg && *arg != end() &&
                          *ina && *ina != end())
                    {
                        entry_p res = malloc(sizeof(entry_t)); 
                        if(res)
                        {
                            memmove(res, resolve(*ina), sizeof(entry_t)); 
                            res->name = res->name ? strdup(res->name) : NULL; 
                            res->parent = *arg; 
                            kill((*arg)->resolved); 
                            (*arg)->resolved = res; 
                        }
                        else
                        {
                            error(PANIC);
                            return new_failure(); 
                        }
                        arg++; 
                        ina++;
                    }
                }
                if(dep++ < MAXDEP)
                {
                    ret = invoke(*cus); 
                    dep--; 
                    return ret; 
                }
                else
                {
                    error(contxt->id, ERR_MAX_DEPTH, contxt->name); 
                    return new_failure(); 
                }
            }
            cus++; 
        }
        error(contxt->id, ERR_UNDEF_FNC, contxt->name); 
    }
    else
    {
        error(PANIC);
    }
    return new_failure(); 
}

/*
*/
entry_p m_set(entry_p contxt)
{
    entry_p dst = global(contxt);
    if (dst)
    {
        entry_p *sym = contxt->symbols, 
                *val = contxt->children; 
        while(*sym && *sym != end() &&
              *val && *val != end())
        {
            entry_p res = malloc(sizeof(entry_t)); 
            if(res)
            {
                memmove(res, resolve(*val), sizeof(entry_t)); 
                res->name = res->name ? strdup(res->name) : NULL; 
                res->parent = *sym; 
                kill((*sym)->resolved); 
                (*sym)->resolved = res; 
                push(dst, *sym); 
                (*sym)->parent = contxt;  
            }
            else
            {
                break; 
            }
            if(*(++sym) == *(++val))
            {
                return res; 
            }
        }
    }
    error(PANIC);
    return new_failure(); 
}

/*
`(+ <expr1> <expr2> ...)'
     returns sum of expressions
*/
entry_p m_add (entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        DNUM = 0; 
        entry_p *cur = contxt->children; 
        while(*cur && *cur != end())
        {
            DNUM += num(*cur);
            cur++; 
        }
        RCUR; 
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
 * < <= == >= > 
*/
static int h_cmp(entry_p a, entry_p b)
{
    if(a->type == STRING &&
       b->type == STRING)
    {
        return strcmp(a->name, b->name);
    }
    else
    {
        return num(a) - num(b); 
    }
}

/*
`(< <expr1> <expr2>)'
     less than test (returns 0 or 1)
*/
entry_p m_lt(entry_p contxt)
{
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            h_cmp(CARG(1), CARG(2)) < 0 ? 1 : 0
        );
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
`(<= <expr1> <expr2>)'
     less than or equal test (returns 0 or 1)
*/
entry_p m_lte(entry_p contxt)
{
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            h_cmp(CARG(1), CARG(2)) <= 0 ? 1 : 0
        );
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
`(< <expr1> <expr2>)'
     greater than test (returns 0 or 1)
*/
entry_p m_gt(entry_p contxt)
{
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            h_cmp(CARG(1), CARG(2)) > 0 ? 1 : 0
        );
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
`(<= <expr1> <expr2>)'
     greater than or equal test (returns 0 or 1)
*/
entry_p m_gte(entry_p contxt)
{
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            h_cmp(CARG(1), CARG(2)) >= 0 ? 1 : 0
        );
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
`(= <expr1> <expr2>)'
     equality test (returns 0 or 1)
*/
entry_p m_eq(entry_p contxt)
{
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            !h_cmp(CARG(1), CARG(2)) ? 1 : 0
        );
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/* 
`(- <expr1> <expr2>)'
     returns `<expr1>' minus `<expr2>'
*/
entry_p m_sub(entry_p contxt)
{
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
        error(PANIC);
        RCUR; 
    }
}

/*
`(* <expr1> <expr2> ...)'
     returns product of expressions
*/
entry_p m_mul(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        DNUM = 1; 
        entry_p *cur = contxt->children; 
        while(*cur && *cur != end())
        {
            DNUM *= num(*cur);
            cur++; 
        }
        RCUR; 
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/* 
`(/ <expr1> <expr2>)'
     returns `<expr1>' divided by `<expr2>'
*/
entry_p m_div(entry_p contxt)
{
    if(c_sane(contxt, 2))
    {
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
            error(contxt->id, ERR_DIV_BY_ZERO, contxt->name); 
            RCUR; 
        }
    }
    else
    {
        error(PANIC);
        RCUR; 
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
        size_t i = 0, j = 0, k = 0, l = 0; 
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
                            memcpy(sct[k], fmt + j, i - j + 1);
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
                        error(contxt->id, ERR_FMT_INVALID, contxt->name); 
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
                   *arg != end())
                {
                    size_t oln = strlen(sct[k]);  
                    entry_p cur = resolve(*arg); 
                    if(sct[k][oln - 1] == 's' &&
                       cur->type == STRING)
                    {
                        size_t nln = oln + strlen(cur->name);  
                        char *new = calloc(nln + 1, sizeof(char)); 
                        if(new)
                        {
                            int n = snprintf(new, nln, sct[k], cur->name); 
                            l += n > 0 ? (size_t) n : 0; 
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
                        size_t nln = oln + NUMLEN;  
                        char *new = calloc(nln + 1, sizeof(char)); 
                        if(new)
                        {
                            int n = snprintf(new, nln, sct[k], cur->id);  
                            l += n > 0 ? (size_t) n : 0; 
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
                        error(contxt->id, ERR_FMT_MISMATCH, contxt->name); 
                    }
                    if(did_error())
                    {
                        arg = NULL; 
                        break;
                    }
                    else
                    {
                        arg++; 
                    }
                }
                else 
                {
                    error(contxt->id, ERR_FMT_MISSING, contxt->name); 
                    break; 
                }
            }
        }
        if(k)
        {
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
        }
        for(k = 0; sct[k]; k++)
        {
            free(sct[k]);
        }
        free(sct);
        if(arg && *arg && 
           *arg != end())
        {
            error(contxt->id, ERR_FMT_UNUSED, contxt->name); 
        }
        else if(ret)
        {
            RSTR(ret); 
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
        error(PANIC);
        RCUR; 
    }
}

/* 
`(OR <expr1> <expr2>)'
     returns logical `OR' of `<expr1>' and `<expr2>'
*/
entry_p m_or(entry_p contxt)
{
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
        error(PANIC);
        RCUR; 
    }
}

/* 
`(XOR <expr1> <expr2>)'
     returns logical `XOR' of `<expr1>' and `<expr2>'
*/
entry_p m_xor(entry_p contxt)
{
    if(c_sane(contxt, 2))
    {
        RNUM
        (
            (num(CARG(1)) && !num(CARG(2))) || 
            (num(CARG(2)) && !num(CARG(1))) 
        );
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/* 
`(NOT <expr>)'
     returns logical `NOT' of `<expr>'
*/
entry_p m_not(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        RNUM(!num(CARG(1)));
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/* 
`(BITAND <expr1> <expr2>)'
     returns bitwise `AND' of `<expr1>' and `<expr2>'
*/
entry_p m_bitand(entry_p contxt)
{
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
        error(PANIC);
        RCUR; 
    }
}

/* 
`(BITOR <expr1> <expr2>)'
     returns bitwise `OR' of `<expr1>' and `<expr2>'
*/
entry_p m_bitor(entry_p contxt)
{
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
        error(PANIC);
        RCUR; 
    }
}

/* 
`(BITXOR <expr1> <expr2>)'
     returns bitwise `XOR' of `<expr1>' and `<expr2>'
*/
entry_p m_bitxor(entry_p contxt)
{
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
        error(PANIC);
        RCUR; 
    }
}

/* 
`(BITNOT <expr>)'
     returns bitwise `NOT' of `<expr>'
*/
entry_p m_bitnot(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        RNUM
        (
            ~num(CARG(1))
        );
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/* 
`(shiftleft <number> <amount to shift>)'
     logical shift left
*/
entry_p m_shiftleft(entry_p contxt)
{
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
        error(PANIC);
        RCUR; 
    }
}

/* 
`(shiftright <number> <amount to shift>)'
     logical shift right
*/
entry_p m_shiftright(entry_p contxt)
{
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
        error(PANIC);
        RCUR; 
    }
}

/*
`(IN <expr> <bit-number> <bitnumber>...)'
     returns `<expr>' `AND' bits
*/
entry_p m_in(entry_p contxt)
{
    if(c_sane(contxt, 2))
    {
        DNUM = 0;  
        entry_p *cur = CARG(2)->children; 
        while(*cur && *cur != end())
        {
            DNUM += 1 << num(*cur);
            cur++; 
        }
        RNUM
        (
            num(CARG(1)) & 
            DNUM 
        );
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
`(askdir (prompt..) (help..) (default..) (newpath) (disk))'
      ask for directory name
*/
entry_p m_askdir(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                deflt    = get_opt(contxt, OPT_DEFAULT),
                newpath  = get_opt(contxt, OPT_NEWNAME),
                disk     = get_opt(contxt, OPT_NOGAUGE);

        prompt = help = deflt = newpath = disk;

        RCUR; 
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(askfile (prompt..) (help..) (default..) (newpath) (disk))'
     ask for file name
*/
entry_p m_askfile(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                deflt    = get_opt(contxt, OPT_DEFAULT),
                newpath  = get_opt(contxt, OPT_NEWNAME),
                disk     = get_opt(contxt, OPT_NOGAUGE);

        prompt = help = deflt = newpath = disk;

        RCUR; 
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(askstring (prompt..) (help..) (default..))'
     ask for a string
*/
entry_p m_askstring(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                deflt    = get_opt(contxt, OPT_DEFAULT);

        prompt = help = deflt; 

        RCUR; 
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(asknumber (prompt..) (help..) (range..) (default..))'
     ask for a number
*/
entry_p m_asknumber(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                range    = get_opt(contxt, OPT_RANGE),
                deflt    = get_opt(contxt, OPT_DEFAULT);

        prompt = help = range = deflt;

        RNUM(1); 
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(askchoice (prompt..) (choices..) (default..))'
     choose 1 options
*/
entry_p m_askchoice(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                choices  = get_opt(contxt, OPT_CHOICES),
                deflt    = get_opt(contxt, OPT_DEFAULT);

        prompt = choices = deflt; 

        RNUM(1); 
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(askoptions (prompt (help..) (choices..) default..))'
     choose n options
*/
entry_p m_askoptions(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                choices  = get_opt(contxt, OPT_CHOICES),
                deflt    = get_opt(contxt, OPT_DEFAULT);

        prompt = help = choices = deflt; 

        RNUM(1); 
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(askbool (prompt..) (help..) (default..) (choices..))'
     0=no, 1=yes
*/
entry_p m_askbool(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                deflt    = get_opt(contxt, OPT_DEFAULT),
                choices  = get_opt(contxt, OPT_CHOICES);

        prompt = help = choices = deflt; 

        RNUM(1); 
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(askdisk (prompt..) (help..) (dest..) (newname..) (assigns))'
*/
entry_p m_askdisk(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                dest     = get_opt(contxt, OPT_DEST),
                newname  = get_opt(contxt, OPT_NEWNAME),
                assigns  = get_opt(contxt, OPT_ASSIGNS);

        prompt = help = dest = newname = assigns; 

        RNUM(1); 
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(cat <string1> <string2>...)'
     returns concatenation of strings
*/
entry_p m_cat(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        size_t n = 64; 
        char *buf = calloc(n + 1, sizeof(char));  
        if(buf)
        {
            size_t l = 0, i = 0; 
            while(contxt->children[i] && 
                  contxt->children[i] != end()) 
            {
                size_t ln; 
                const char *s = str(contxt->children[i++]); 
                if(did_error())
                {
                    free(buf); 
                    return new_failure();
                }
                ln = strlen(s); 
                if(ln)
                {
                    l += strlen(s); 
                    if(l > n) 
                    {
                        char *tmp; 
                        while(n && n < l)
                        {
                            n = n << 1;  
                        }
                        tmp = calloc(n + 1, sizeof(char));  
                        if(tmp && n) 
                        {
                            memcpy(tmp, buf, l - ln + 1); 
                            free(buf); 
                            buf = tmp; 
                        }
                        else
                        {
                            free(tmp); 
                            free(buf); 
                            buf = NULL; 
                            break; 
                        }
                    }
                    strncat(buf, s, n); 
                }
            } 
            if(buf)
            {
                RSTR(buf); 
            }
        }
    }
    error(PANIC);
    RCUR; 
}

static int h_exists(const char *n)
{
    if(n)
    {
        struct stat fs; 
        if(!stat(n, &fs))
        {
            if(S_ISREG(fs.st_mode))
            {
                return 1; 
            }
            if(S_ISDIR(fs.st_mode))
            {
                return 2; 
            }
        }
    }
    return 0; 
}

/*
`(exists <filename> (noreq))'
     0 if no, 1 if file, 2 if dir
*/
entry_p m_exists(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        if(get_opt(contxt, OPT_NOREQ))
        {
            /* show mount req */
        }
        RNUM
        (
            h_exists(str(CARG(1))); 
        ); 
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
`(expandpath <path>)'
     Expands a short path to its full path equivalent
*/
entry_p m_expandpath(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

/*
`(earlier <file1> <file2>)'
     true if file1 earlier than file2
*/
entry_p m_earlier(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

static char *h_fileonly(int id, 
                        const char *s)
{
    if(s)
    {
        size_t l = strlen(s), 
               i = l - 1;
        if(l && 
           s[i] != '/' &&
           s[i] != ':' )
        {
            char *r; 
            while(i &&
                  s[i - 1] != '/' && 
                  s[i - 1] != ':' ) i--;
            r = calloc(l - i + 1, sizeof(char)); 
            if(r)
            {
                memcpy(r, s + i, l - i); 
                return r; 
            }
            error(PANIC); 
        }
        else
        {
            error(id, ERR_NOT_A_FILE, s); 
        }   
    }
    return NULL; 
}

/*
`(fileonly <path>)'
     return file part of path (see pathonly)
*/
entry_p m_fileonly(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        const char *f = str(CARG(1));
        char *r = h_fileonly(contxt->id, f); 
        RSTR(r ? r : strdup("")); 
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(getassign <name> <opts>)'
     return value of logical name (no `:') `<opts>': 'v'-volumes,
     'a'-assigns, 'd'-devices
*/
entry_p m_getassign(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

/*
`(getdevice <path>)'
     returns name of device upon which <path> resides
*/
entry_p m_getdevice(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

/*
`(getdiskspace <path>)'
     return available space
*/
entry_p m_getdiskspace(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

/*
`(getenv <name>)'
     return value of environment variable
*/
entry_p m_getenv(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        char *e = getenv(str(CARG(1))); 
        RSTR(strdup(e ? e : "")); 
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
`(getsize <file>)'
     return size
*/
entry_p m_getsize(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        FILE *f = fopen(str(CARG(1)), "r"); 
        if(f)
        {
            fseek(f, 0L, SEEK_END);
            DNUM = (int) ftell(f); 
            fclose(f); 
            RCUR; 
        }
        else
        {
            error(contxt->id, ERR_READ_FILE, str(CARG(1))); 
            RNUM(0); 
        }
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
`(getsum <file>)'
     return checksum of file for comparison purposes
*/
entry_p m_getsum(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        DNUM = 0; 
        FILE *f = fopen(str(CARG(1)), "r"); 
        if(f)
        {
            int c = getc(f), n = 1; 
            while(c != EOF)
            {
                DNUM -= (c + n);
                c = getc(f); 
                n = ~DNUM; 
            }
            fclose(f); 
            RCUR; 
        }
        else
        {
            error(contxt->id, ERR_READ_FILE, str(CARG(1))); 
            RCUR; 
        }
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
`(getversion <file> (resident))'
     return version/revision of file, library, etc. as 32 bit num
*/
entry_p m_getversion(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        if(get_opt(contxt, OPT_RESIDENT))
        {
            /* do something */
        }
        /* do some more */
        RNUM(0); 
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
`(iconinfo <parameters>)'
      return information about an icon (V42.12)
*/
entry_p m_iconinfo(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        entry_p dst = get_opt(contxt, OPT_DEST);
        if(c_sane(dst, 1))
        {
            /* do something */
            RNUM(1); 
        }
        else
        {
            error(contxt->id, ERR_MISSING_OPTION, "dest"); 
            RNUM(0); 
        }
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
 `(pathonly <path>)'
      return dir part of path (see fileonly)
*/
entry_p m_pathonly(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        const char *s = str(CARG(1)); 
        size_t i = strlen(s); 
        while(i--) 
        {
            if(s[i] == '/' ||
               s[i] == ':' )
            {
                char *r; 
                r = calloc(i + 2, sizeof(char)); 
                if(r)
                {
                    memcpy(r, s, i + 1); 
                    RSTR(r); 
                }
                error(PANIC); 
                RCUR; 
            }
        }
        RSTR(strdup("")); 
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
`(patmatch <pattern> <string>)'
      Does <pattern> match <string> ? TRUE : FALSE
*/
entry_p m_patmatch(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

/*
`(select <n> <item1> <item2> ...)'
    return n'th item
*/
entry_p m_select(entry_p contxt)
{
    if(c_sane(contxt, 2))
    {
        int i = 0, j = num(CARG(1)) - 1; 
        while(CARG(2)->children[i] && 
              CARG(2)->children[i] != end())
        {
            if(i == j)
            {
                return resolve(CARG(2)->children[i]); 
            }
            i++; 
        }
        error(contxt->id, ERR_NO_ITEM, str(CARG(1))); 
        RNUM(0); 
    }
    else
    {
        error(PANIC); 
        RCUR;
    }
}

/*
`(strlen <string>)'
    returns string length
*/
entry_p m_strlen(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        RNUM
        (
            (int) strlen(str(CARG(1)))
        ); 
    } 
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
`(substr <string> <start> [<count>])'
    returns a substring of <string>
*/
entry_p m_substr(entry_p contxt)
{
    if(c_sane(contxt, 2) &&
       c_sane(CARG(2), 1))
    {
        char *r; 
        const char *s = str(CARG(1));
        entry_p se = CARG(2)->children[0], 
                ne = CARG(2)->children[1];
        size_t n, l = strlen(s),
               i = num(se) > 0 ? 
               (size_t) num(se) : 0;
        i = i >= l ? 0 : i; 
        n = l - i; 
        if(ne && ne != end())
        {
            size_t j = num(ne) > 0 ? 
                   (size_t) num(ne) : n; 
            n = j < n ? j : n; 
        }
        r = calloc(n + 1, sizeof(char)); 
        if(r)
        {
            memcpy(r, s + i, n); 
            RSTR(r); 
        }
    }
    error(PANIC);
    RCUR; 
}

/*
`(symbolset <symbolname> <expression>)'
    assign a value to a variable named by the string result of
    `<symbolname>' (V42.9)
*/
entry_p m_symbolset(entry_p contxt)
{
    entry_p res = malloc(sizeof(entry_t)); 
    if(res && c_sane(contxt, 2))
    {
        size_t i = 0; 
        const char *n = str(CARG(1)); 
        memmove(res, resolve(CARG(2)), sizeof(entry_t)); 
        res->name = res->name ? strdup(res->name) : NULL; 
        while(contxt->symbols[i] &&
              contxt->symbols[i] != end())
        {
            if(!strcmp(contxt->symbols[i]->name, n))
            {
                kill(contxt->symbols[i]->resolved); 
                contxt->symbols[i]->resolved = res;
                push(global(contxt), contxt->symbols[i]); 
                res->parent = contxt->symbols[i]; 
                return res; 
            }
            i++; 
        }
        entry_p sym = new_symbol(strdup(n)); 
        if(sym)
        {
            res->parent = sym; 
            sym->resolved = res; 
            if(append(&contxt->symbols, sym))
            {
                push(global(contxt), sym); 
                sym->parent = contxt;  
                return res; 
            }
        }
        kill(sym); 
        kill(res); 
    }
    else
    {
        free(res); 
    }
    error(PANIC); 
    RCUR; 
}

/*
`(symbolval <symbolname>)'
    returns the value of the symbol named by the string expression
    `<smbolval>' (V42.9)
*/
entry_p m_symbolval(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        entry_p r; 
        entry_t e; 
        e.type = SYMREF; 
        e.parent = contxt; 
        e.id = contxt->id; 
        e.name = str(CARG(1)); 
        r = resolve(&e); 
        if(!did_error())
        {
            return r; 
        }
        RNUM(0);
    }
    else
    {
        error(PANIC);
        RCUR;
    }
}

static char *h_tackon(int id, 
                      const char *p, 
                      const char *f)
{
    if(p && f)
    {
        size_t lp = strlen(p), 
               lf = strlen(f); 
        if(lp || lf)
        {
            char *r; 
            if(!lp) 
            {
                return strdup(f); 
            }
            if(!lf) 
            {
                return strdup(p); 
            }
            if(f[lf - 1] == '/' ||
               f[lf - 1] == ':') 
            {
                error(id, ERR_NOT_A_FILE, f); 
                return NULL; 
            }
            r = calloc(lp + lf + 2, sizeof(char)); 
            if(r)
            {
                memcpy(r, p, lp); 
                if(p[lp - 1] == '/' ||
                   p[lp - 1] == ':') 
                {
                    if(f[0] == '/' ||
                       f[0] == ':') 
                    {
                        f++; 
                    }
                }
                else
                {
                    if(f[0] != '/' && 
                       f[0] != ':') 
                    {
                        strcat(r, "/"); 
                    }
                }
                strcat(r, f); 
                return r; 
            }
            error(PANIC); 
        }
    }
    return NULL; 
}

/*
`(tackon <path> <file>)'
     return properly concatenated file to path
*/
entry_p m_tackon(entry_p contxt)
{
    if(c_sane(contxt, 2))
    {
        const char *d = str(CARG(1)), *f = str(CARG(2));
        char *r = h_tackon(contxt->id, d, f); 
        RSTR(r ? r : strdup("")); 
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(transcript <string1> <string2>)'
     puts concatenated strings in log file
*/
entry_p m_transcript(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        size_t len = 0; 
        entry_p override = get_opt(contxt, OPT_OVERRIDE); 
        const char *log = override ? str(override) : "default.log"; 
        for(entry_p *e = contxt->children; 
            *e && *e != end(); e++)
        {
            if((*e)->type != OPTION)
            {
                len += strlen(str(*e)); 
            }
        }
        char *buf = calloc(len + 2, sizeof(char));
        if(buf)
        {
            for(entry_p *e = contxt->children; 
                *e && *e != end(); e++)
            {
                if((*e)->type != OPTION)
                {
                    strcat(buf, str(*e)); 
                }
            }
            FILE *fp = fopen(log, "a"); 
            if(fp)
            {
                buf[len] = '\n'; 
                if(fwrite(buf, sizeof(char), 
                   len + 1, fp) == len + 1)
                {
                    fclose(fp); 
                    free(buf); 
                    RNUM(1);
                }
                fclose(fp); 
            }
            else
            {
                error(contxt->id, ERR_WRITE_FILE, log); 
            }
            free(buf); 
            RNUM(0); 
        }
    }
    error(PANIC); 
    RCUR; 
}

static int h_makedir(int id, const char *dst)
{
    if(dst)
    {
        char *dir; 
        if(h_exists(dst) == 2)
        {
            return 1; 
        }
        dir = strdup(dst); 
        if(dir)
        {
            int d = 1, 
                l = (int) strlen(dir);
            for(int i = 0; i < l; i++)
            {
                if(dir[i] == '/')
                {
                    d++;  
                }
            }
            while(d--)
            {
                for(int i = l; i >= 0; i--)
                {
                    if(dir[i] == '/' ||
                       dir[i] == '\0')
                    {
                        char c = dir[i]; 
                        dir[i] = '\0'; 
                        if(mkdir(dir, 0777) == 0)
                        {
                            if(i == l)
                            {
                                free(dir);
                                return 1; 
                            }
                            dir[i] = c; 
                            break; 
                        }
                        else
                        {
                            dir[i] = c; 
                        }
                    }
                }
            }
            free(dir);
            error(id, ERR_WRITE_DIR, dst); 
        }
        else
        {
            error(PANIC); 
        }
    }
    return 0; 
}

/*
`(makedir <name> (prompt..) (help..) (infos) (confirm..) (safe))'
     make a directory
*/
entry_p m_makedir(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        entry_p opt = contxt->children[1]; 
        if(opt)
        {
            // handle options
        }
        RNUM
        (
            h_makedir(contxt->id, str(CARG(1))); 
        ); 
    }
    else
    {
        error(PANIC); 
        RNUM(0);
    }
}

/*
  copyfiles / copylib helper function
*/
static int h_copyfile(int id, 
                      const char *src, 
                      const char *dst)
{
    if(src && dst)
    { 
        static char buf[BUFSIZ]; 
        FILE *fs = fopen(src, "r"); 
        if(fs)
        {
            FILE *fd = fopen(dst, "w"); 
            if(fd)
            {
                size_t n = fread(buf, sizeof(char), BUFSIZ, fs);
                while(n)
                {
                    if(fwrite(buf, sizeof(char), n, fd) != n)
                    {
                        error(id, ERR_WRITE_FILE, dst); 
                        break; 
                    }
                    n = fread(buf, sizeof(char), BUFSIZ, fs);
                }
                fclose(fs); 
                fclose(fd); 
                return n ? 0 : 1; 
            }
            else
            {
                fclose(fs); 
                error(id, ERR_WRITE_FILE, dst); 
            }
        }
        else
        {
            error(id, ERR_READ_FILE, src); 
        }
    }
    return 0; 
}

/*
  copyfiles helper function
*/
static int h_copydir(int id, 
                     const char *src, 
                     const char *dst, 
                     int nodir)
{
    int r = 0; 
    if(src && dst)
    { 
        DIR *dp = opendir(src);
        if(dp) 
        {
            for(struct dirent *de = readdir(dp); 
                de && !did_error(); 
                de = readdir(dp))
            {
                char *fn = h_tackon(id, src, de->d_name);
                if(fn)
                {
                    int t = h_exists(fn);
                    r = 0; 
                    if(t == 2)
                    {
                        /* A directory */
                        if(!nodir &&
                           strcmp(de->d_name, ".") &&
                           strcmp(de->d_name, ".."))
                        {
                            char *nd = h_tackon(id, dst, de->d_name);
                            if(nd)
                            {
                                if(h_makedir(id, nd))
                                {
                                    /* Error is set by h_makedir*/
                                    r = h_copydir(id, fn, nd, 0);
                                }
                                free(nd); 
                            }
                            else
                            {
                                error(PANIC); 
                            }
                        }
                        else
                        {
                            r = 1; 
                        }
                    } 
                    else
                    {
                        /* A file */
                        char *nf = h_tackon(id, dst, de->d_name);
                        if(nf)
                        {
                            if(h_copyfile(id, fn, nf))
                            {
                                /* Error is set by h_makedir*/
                                r = 1; 
                            }
                            free(nf); 
                        }
                        else
                        {
                            error(PANIC); 
                        }
                    } 
                    free(fn); 
                }
                else
                {
                    error(PANIC); 
                }
            }
            closedir(dp);
        }
        else
        {
            error(id, ERR_READ_DIR, src); 
        }
    }
    return r; 
}

/*
`(copyfiles (prompt..) (help..) (source..) (dest..) (newname..) (choices..)'
     `(all) (pattern..) (files) (infos) (confirm..) (safe) (optional
     <option> <option> ...) (delopts <option> <option> ...) (nogauge))'

     copy files (and subdir's by default).  files option say NO
     subdirectories
*/
entry_p m_copyfiles(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                source   = get_opt(contxt, OPT_SOURCE),
                dest     = get_opt(contxt, OPT_DEST),
                newname  = get_opt(contxt, OPT_NEWNAME),
                choices  = get_opt(contxt, OPT_CHOICES),
                all      = get_opt(contxt, OPT_ALL),
                pattern  = get_opt(contxt, OPT_PATTERN),
                files    = get_opt(contxt, OPT_FILES),
                infos    = get_opt(contxt, OPT_INFOS),
                confirm  = get_opt(contxt, OPT_CONFIRM),
                safe     = get_opt(contxt, OPT_SAFE),
                optional = get_opt(contxt, OPT_OPTIONAL),
                delopts  = get_opt(contxt, OPT_DELOPTS),
                nogauge  = get_opt(contxt, OPT_NOGAUGE);

        prompt = help = choices = all = pattern; 
        infos = confirm = safe = optional; 
        delopts = nogauge; 

        if(source && dest) 
        {
            const char *src = str(source), 
                       *dst = str(dest);
            int st = h_exists(src), 
                dt = h_exists(dst); 
            if(!st)
            {
                error(contxt->id, ERR_NO_SUCH_FILE_OR_DIR, src); 
                RNUM(0); 
            }
            if(!dt)
            {
                /* We need to create the destination dir */
                if(!h_makedir(contxt->id, dst))
                {
                    /* Error is set by h_makedir*/
                    RNUM(0); 
                }
            }
            else
            if(dt == 1)
            {
                /* Destination is a file, not a dir */                
                error(contxt->id, ERR_NOT_A_DIR, dst); 
                RNUM(0); 
            }
            /* We have a destination directory */                
            if(st == 1)
            {
                char *f = newname ? 
                     strdup(str(newname)) :
                     h_fileonly(contxt->id, src), 
                     *p = h_tackon(contxt->id, dst, f);
                if(f && p)
                {
                    DNUM = h_copyfile(contxt->id, src, p); 
                }
                else
                {
                    error(PANIC); 
                }
                free(f); 
                free(p); 
                RCUR; 
            }
            else
            {
                RNUM
                (
                    h_copydir(contxt->id, 
                              src, dst, 
                              files ? 1 : 0)
                );
            }
            RNUM(0); 
        }
        else
        {
            char *opt = !source ? "source" : "dest"; 
            error(contxt->id, ERR_MISSING_OPTION, opt); 
            RNUM(0); 
        }
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
`(copylib (prompt..) (help..) (source..) (dest..) (newname..) (infos) (confirm)'
     `(safe) (optional <option> <option> ...) (delopts <option>
     <option> ...) (nogauge))'

     install a library if newer version
*/
entry_p m_copylib(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {   
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                source   = get_opt(contxt, OPT_SOURCE),
                dest     = get_opt(contxt, OPT_DEST),
                newname  = get_opt(contxt, OPT_NEWNAME),
                infos    = get_opt(contxt, OPT_INFOS),
                confirm  = get_opt(contxt, OPT_CONFIRM),
                safe     = get_opt(contxt, OPT_SAFE),
                optional = get_opt(contxt, OPT_OPTIONAL),
                delopts  = get_opt(contxt, OPT_DELOPTS),
                nogauge  = get_opt(contxt, OPT_NOGAUGE);

        infos = confirm = safe; 
        prompt = help = newname;
        optional = delopts = nogauge; 

        if(source && dest) 
        {
            /*
            const char *d = str(dest);
            if(h_makedir(contxt->id, d))
            {
                // Check if newer!
                const char *s = str(source);
                int r = h_copyfile(contxt->id, s, d);
                RNUM(r); 
            }
            */
        }
        else
        {
            char *opt = !source ? "source" : "dest"; 
            error(contxt->id, ERR_MISSING_OPTION, opt); 
        }
        RNUM(0); 
    }
    else
    {
        error(PANIC);
        RCUR; 
    }
}

/*
`(startup (prompt..) (command..))'
     add a command to the boot scripts (startup-sequence, user-startup)
*/
entry_p m_startup(entry_p contxt)
{
    if(c_sane(contxt, 2))
    {
        entry_p command  = get_opt(contxt, OPT_COMMAND),
                help     = get_opt(CARG(3), OPT_HELP),
                prompt   = get_opt(CARG(3), OPT_PROMPT), 
                confirm  = get_opt(CARG(3), OPT_CONFIRM), 
                override = get_opt(CARG(3), OPT_OVERRIDE);

        help = prompt = confirm; 

        if(!command) 
        {
            error(contxt->id, ERR_MISSING_OPTION, "command"); 
            RNUM(0); 
        }
        if(c_sane(command, 1))
        {
            const char *app = str(CARG(1)), 
                       *cmd = str(command->children[0]),
                       *fln = override ? 
                              str(override->children[0]) : 
                              "s:user-startup";
            FILE *fp = fopen(fln, "r"); 
            if(fp)
            {
                size_t al = strlen(app) + 2; 
                if(al < 3)
                {
                    fclose(fp); 
                    error(contxt->id, ERR_INVALID_APP, "NULL"); 
                    RNUM(0);
                }
                else
                {
                    char *fnd, *buf;
                    size_t fl, cl = strlen(cmd); 
                    fseek(fp, 0L, SEEK_END);
                    fl = (size_t) ftell(fp);
                    fnd = calloc(al + 1, sizeof(char)); 
                    buf = calloc(fl + 2 * (al + 1) + cl + 2, sizeof(char)); 
                    if(buf && fnd)
                    {
                        fseek(fp, 0L, SEEK_SET);
                        sprintf(fnd, ";%s\n", app); 
                        if(fread(buf, sizeof(char), fl, fp) == fl)
                        {
                            char *b = strstr(buf, fnd),
                                 *e = b ? strstr(b + al, fnd) : NULL; 
                            b += al; 
                            fclose(fp); 
                            if(e && b)
                            {
                                fp = fopen(fln, "w"); 
                                if(fp)
                                {
                                    memmove(b + cl + 1, e, buf + fl - e); 
                                    fl -= (size_t) e - (size_t) b - cl - 1;
                                    memcpy(b, cmd, cl); 
                                    b[cl] = '\n';
                                    if(fwrite(buf, sizeof(char), fl, fp) == fl)
                                    {
                                        fclose(fp); 
                                        free(fnd); 
                                        free(buf); 
                                        RNUM(1);
                                    }
                                }
                            }
                            else
                            {
                                fp = fopen(fln, "a"); 
                                if(fp)
                                {
                                    if(fprintf(fp, "%s%s\n%s", 
                                       fnd, cmd, fnd) > 0)
                                    {
                                        fclose(fp); 
                                        free(fnd); 
                                        free(buf); 
                                        RNUM(1);
                                    }
                                }
                            }
                            error(contxt->id, ERR_WRITE_FILE, fln); 
                        }
                    }
                    if(fp)
                    {
                        fclose(fp); 
                    }
                    free(buf);
                    free(fnd);
                }
            }
            else
            {
                error(contxt->id, ERR_READ_FILE, fln); 
            }
            RNUM(0);
        }
    }
    error(PANIC); 
    RCUR; 
}

/*
`(tooltype (prompt..) (help..) (dest..) (settooltype..) (setstack..)'
     `(setdefaulttool..) (noposition) (confirm..) (safe))'

     modify an icon
*/
entry_p m_tooltype(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

/*
`(textfile (prompt..) (help..) (dest..) (append) (include..) (confirm..) (safe))'
     create text file from other text files and strings
*/
entry_p m_textfile(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                dest     = get_opt(contxt, OPT_DEST),
                append   = get_opt(contxt, OPT_APPEND),
                include  = get_opt(contxt, OPT_INCLUDE),
                confirm  = get_opt(contxt, OPT_CONFIRM),
                safe     = get_opt(contxt, OPT_SAFE); 

        prompt = help = confirm = safe; 

        if(dest)
        {
            const char *fn = str(dest); 
            FILE *fp = fopen(fn, "a"); 
            if(fp)
            {
                DNUM = 1; 
                if(include)
                {
                    static char buf[BUFSIZ]; 
                    FILE *fs = fopen(str(include), "r"); 
                    if(fs)
                    {
                        size_t n = fread(buf, sizeof(char), BUFSIZ, fs);
                        while(n)
                        {
                            if(fwrite(buf, sizeof(char), n, fp) != n)
                            {
                                error(contxt->id, ERR_WRITE_FILE, fn); 
                                DNUM = 0; 
                                break; 
                            }
                            n = fread(buf, sizeof(char), BUFSIZ, fs);
                        }
                        fclose(fs); 
                    }
                    else
                    {
                        error(contxt->id, ERR_READ_FILE, str(include)); 
                        DNUM = 0;  
                    }
                }
                if(append && DNUM)
                {
                    if(fputs(str(append), fp) == EOF)
                    {
                        error(contxt->id, ERR_WRITE_FILE, fn); 
                        DNUM = 0; 
                    }
                }
                fclose(fp); 
                if(append || include)
                {
                    RCUR; 
                }
                error(contxt->id, ERR_NOTHING_TO_DO, contxt->name); 
                RNUM(0); 
            }
            error(contxt->id, ERR_WRITE_FILE, fn); 
        }
        else
        {
            error(contxt->id, ERR_MISSING_OPTION, "dest"); 
            RCUR; 
        }
        RNUM(0); 
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(execute <arg> (help..) (prompt..) (confirm) (safe))'
     execute script file
*/
entry_p m_execute(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

/*
`(run <arg> (help..) (prompt..) (confirm..) (safe))'
     execute program
*/
entry_p m_run(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

/*
`(rexx <arg> (help..) (prompt..) (confirm..) (safe))'
     execute ARexx script
*/
entry_p m_rexx(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

/*
`(makeassign <assign> <path> (safe)) ; note: <assign> doesn't need `:''
     create an assignment
*/
entry_p m_makeassign(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

/*
`(rename <old> <new> (help..) (prompt..) (confirm..) (safe))'
     rename files
*/
entry_p m_rename(entry_p contxt)
{
    if(c_sane(contxt, 2))
    {
        entry_p help     = get_opt(CARG(3), OPT_HELP),
                prompt   = get_opt(CARG(3), OPT_PROMPT), 
                confirm  = get_opt(CARG(3), OPT_CONFIRM), 
                safe     = get_opt(CARG(3), OPT_COMMAND);

        help = prompt = confirm = safe; 

        if(rename(str(CARG(1)), str(CARG(2))) == 0)
        {
            RNUM(1); 
        }
        else
        {
            error(contxt->id, ERR_RENAME_FILE, str(CARG(1))); 
            RNUM(0); 
        }
    }  
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(delete file (help..) (prompt..) (confirm..) (infos) (optional <option> <option> ...) (all)'
     `(delopts <option> <option> ...) (safe))'

     delete file
*/
entry_p m_delete(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        entry_p help     = get_opt(CARG(2), OPT_HELP),
                prompt   = get_opt(CARG(2), OPT_PROMPT), 
                confirm  = get_opt(CARG(2), OPT_CONFIRM), 
                infos    = get_opt(CARG(2), OPT_INFOS), 
                optional = get_opt(CARG(2), OPT_OPTIONAL), 
                all      = get_opt(CARG(2), OPT_ALL), 
                delopts  = get_opt(CARG(2), OPT_DELOPTS), 
                safe     = get_opt(CARG(2), OPT_SAFE); 

        help = prompt = confirm = infos; 
        optional = all = delopts = safe; 

        if(remove(str(CARG(1))) == 0)
        {
            RNUM(1); 
        }
        else
        {
            error(contxt->id, ERR_DELETE_FILE, str(CARG(1))); 
            RNUM(0); 
        }
    }  
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(protect <file> [<string of flags to change>] [<decimal mask>] <parameters>)'
     get/set file protection flags

 8 7 6 5 4 3 2 1  <- Bit number
 h s p a r w e d  <- corresponding protection flag
 ^ ^ ^ ^ ^ ^ ^ ^
 | | | | | | | |
 | | | | | | | +- \
 | | | | | | +--- | 0 = flag set
 | | | | | +----- | 1 = flag clear
 | | | | +------- /
 | | | |
 | | | |
 | | | +--------- \
 | | +----------- | 0 = flag clear
 | +------------- | 1 = flag set
 +--------------- /
*/
entry_p m_protect(entry_p contxt)
{
    if(c_sane(contxt, 2))
    {
        int mask = num(CARG(2)), r = 0; 
        const char *file = str(CARG(1)); 
        entry_p override = get_opt(CARG(3), OPT_OVERRIDE),
                    safe = get_opt(CARG(3), OPT_SAFE); 

        safe = NULL; 
        file = NULL; 

        if(mask)
        {
            r = mask; 
        }
        else
        {
            int m = 0; 
            const char *flags = str(CARG(2)); 
            size_t n = strlen(flags); 
            if(override)
            {
                r = num(override); 
            }
            else
            {
                /* current state -> r */
            }
            r ^= 0x0f; /* invert 1-4 */
            for(size_t i = 0; i < n; i++)
            {
                int b = 0; 
                switch(flags[i])
                {
                    case '+': m = 1; break; 
                    case '-': m = 2; break; 
                    case 'h': b = 1 << 7; break; 
                    case 's': b = 1 << 6; break; 
                    case 'p': b = 1 << 5; break; 
                    case 'a': b = 1 << 4; break; 
                    case 'r': b = 1 << 3; break; 
                    case 'w': b = 1 << 2; break; 
                    case 'e': b = 1 << 1; break; 
                    case 'd': b = 1 << 0; break; 
                }
                switch(m)
                {
                    case 0: r = b; m = 1; break; 
                    case 1: r |= b; break; 
                    case 2: r &= ~b; break; 
                }
            }
            r ^= 0x0f; /* invert 1-4 */
        }
        if(!override)
        {
            /* r = r -> current state */
        }
        else
        {
            r = mask ? mask : r; 
        }
        RNUM(r); 
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(complete <num>)'
     display percentage through install in titlebar
*/
entry_p m_complete(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        RNUM(num(CARG(1))); 
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(message <string1> <string2>... (all))'
     display message with Proceed, Abort buttons
*/
entry_p m_message(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        entry_p all = get_opt(contxt, OPT_ALL);
        if(all)
        {
            /* do something */
        }
        RNUM(1); 
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(working)'
     indicate to user that Installer is busy doing things
*/
entry_p m_working(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

/*
`(welcome <string> <string> ...)'
     allow Installation to commence.
*/
entry_p m_welcome(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

/*
`(foreach <dir> <pattern> <statements>)'
     do for entries in directory
*/
entry_p m_foreach(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

/*
`(abort <string1> <string2> ...)'
     abandon installation
*/
entry_p m_abort(entry_p contxt)
{
    if(c_sane(contxt, 0))
    {
        entry_p *cur = contxt->children; 
        while(*cur && *cur != end())
        {
            /* show message */
            cur++; 
        }
        error(-3, ERR_ABORT, __func__); 
        RNUM(0);
    }
    else
    {
        error(PANIC); 
        RCUR; 
    }
}

/*
`(exit <string> <string> ... (quiet))'
     end installation after displaying strings (if provided)
*/
entry_p m_exit(entry_p contxt)
{
    if(contxt)
    {
        if(contxt->children &&
           !get_opt(contxt, OPT_QUIET))
        {
            entry_p *cur = contxt->children; 
            while(*cur && *cur != end())
            {
                /*
                printf("%s\n", str(contxt->children[i])); 

                This causes normal termination of a script.  If strings are
                provided, they are displayed.  The "done with installation" message is
                then displayed.  The "onerror" statements are not executed.  If (quiet)
                is specified, the final report display is skipped.

                MISSING
                */
                cur++; 
            }
        }
        error(HALT); 
        RNUM(0); 
    }
    else
    {
        error(PANIC);
        RCUR;
    }
}

/*
`(trap <flags> <statements>)'
     trap errors.  flags: 1-abort, 2-nomem, 3-error, 4-dos, 5-badargs
*/
entry_p m_trap(entry_p contxt)
{
    (void) contxt; 
    error(MISS); 
    return new_failure(); 
}

/*
`(onerror (<statements>))'
     general error trap

 ------------------------------------------------------
 In part implemented using m_procedure. This function
 just invokes the @onerror custom procedure inserted
 using (onerror) which is a special case of (procedure)
 ------------------------------------------------------
*/
entry_p m_onerror(entry_p contxt)
{
    if(c_sane(contxt, 0))
    {
        entry_p handler = new_cusref(strdup("@onerror"), __LINE__, NULL);
        push(contxt, handler);
        return m_gosub(handler); 
    }
    else
    {
        error(PANIC);  
        RCUR;
    }
}

/*
`(user <user-level>)'
   change the user level (debugging purposes only)

   -----------------------
   Implemented using m_set
   -----------------------
*/

/*
`(debug <anything> <anything> ...)'
    print to stdout when running from a shell
*/
entry_p m_debug(entry_p contxt)
{
    if(c_sane(contxt, 0))
    {
        entry_p *cur = contxt->children; 
        while(*cur && *cur != end())
        {
            printf("%s ", str(*cur)); 
            cur++; 
        }
        printf("\n"); 
        RNUM(1); 
    }
    else
    {
        error(PANIC); 
        RCUR;
    }
}

/*
`(database <feature> [<checkvalue>])'
    return information about the Amiga that the Installer 
    is running on.  
*/
entry_p m_database(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        entry_p n = NULL; 
        const char *fin = str(CARG(1)); 
        const char *fdb[] = 
        {   
            "vblank", "50",
            "cpu", "68000",
            "fpu", "NOFPU", 
            "graphics-mem", "524288",
            "total-mem", "524288",
            "chiprev", "AGNUS", NULL
        };
        for(size_t i = 0; fdb[i]; i+= 2)
        {
            if(!strcmp(fdb[i], fin))
            {
                if(CARG(2) && 
                   CARG(2) != end())
                {
                    fin = str(CARG(2)); 
                    n = new_number(!strcmp(fdb[i + 1], fin) ? 1 : 0); 
                    
                }
                else
                {
                    n = new_string(strdup(fdb[i + 1])); 
                }
            }
        } 
        n = n ? n : new_number(0); 
        n->parent = contxt; 
        kill(contxt->resolved); 
        contxt->resolved = n; 
        RCUR; 
    }
    else
    {
        error(PANIC); 
        RCUR;
    }
}
