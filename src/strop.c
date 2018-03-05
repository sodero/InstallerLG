//----------------------------------------------------------------------------
// strop.c: 
//
// String operations
//
//----------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "strop.h"
#include "util.h"

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef AMIGA
#include <dos/dos.h>
#endif

//----------------------------------------------------------------------------
// (cat <string1> <string2>...)
//     returns concatenation of strings
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_cat(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        size_t n = 64; 
        char *buf = calloc(n + 1, 1);  
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
                    REST; 
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
                        tmp = calloc(n + 1, 1);
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

            // Unless we're out of memory, buf will
            // will contain the concatenation of all
            // the children.
            RSTR(buf); 
        }
    }
    // The parser isn't necessarily broken 
    // if we end up here. We could alse be
    // out of memory.
    error(PANIC);
    RCUR;
}
//----------------------------------------------------------------------------
// !!!MOVE THIS TO FILE.C!!!
//
// (expandpath <path>)
//     Expands a short path to its full path equivalent
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_expandpath(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        #ifdef AMIGA
        BPTR lock = (BPTR) Lock(str(CARG(1)), ACCESS_READ);
        if(lock)
        {
            char *buf = calloc(PATH_MAX, 1);
            if(buf)
            {
                NameFromLock(lock, buf, PATH_MAX); 
                UnLock(lock); 
                RSTR(buf);
            }

            UnLock(lock); 
        }
        #endif
    }
    else
    {
        // Broken parser
        error(PANIC); 
    }

    // Return empty string.
    REST;
}

//----------------------------------------------------------------------------
// ("<fmt>" <expr1> <expr2>)
//     returns a formatted string
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
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
                        sct[k] = calloc(i - j + 2, 1); 
                        if(sct[k])
                        {
                            memcpy(sct[k], fmt + j, i - j + 1);
                            j = i + 1;  
                            k++; 
                        }
                        else
                        {
                            // Out of memory
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
                        char *new = calloc(nln + 1, 1); 
                        if(new)
                        {
                            int n = snprintf(new, nln, sct[k], cur->name); 
                            l += n > 0 ? (size_t) n : 0; 
                            free(sct[k]); 
                            sct[k] = new; 
                        }
                        else
                        {
                            // Out of memory
                            error(PANIC);
                        }
                    }
                    else
                    if(sct[k][oln - 1] == 'd' &&
                       cur->type == NUMBER)
                    {
                        size_t nln = oln + NUMLEN;  
                        char *new = calloc(nln + 1, 1); 
                        if(new)
                        {
                            int n = snprintf(new, nln, sct[k], cur->id);  
                            l += n > 0 ? (size_t) n : 0; 
                            free(sct[k]); 
                            sct[k] = new; 
                        }
                        else
                        {
                            // Out of memory
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
            ret = calloc(l + 1, 1); 
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
                // Out of memory
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
        // Either something is terribly
        // broken or we're out of memory
        error(PANIC);
        free(sct);
    }
    free(ret);
    REST; 
}

//----------------------------------------------------------------------------
// (pathonly <path>)
//     return dir part of path (see fileonly)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_pathonly(entry_p contxt)
{
    // We need one argument, a full path. 
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
                r = calloc(i + 2, 1); 
                if(r)
                {
                    memcpy(r, s, i + 1); 
                    RSTR(r); 
                }
                error(PANIC); 
            }
        }
        REST; 
    }
    else
    {
        // The parser is broken
        error(PANIC);
        RCUR; 
    }
}

//----------------------------------------------------------------------------
// (patmatch <pattern> <string>)
//     Does <pattern> match <string> ? TRUE : FALSE
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_patmatch(entry_p contxt)
{
    // We need two arguments
    if(c_sane(contxt, 2))
    {
        #ifdef AMIGA
        // Use a static buffer, Installer.guide
        // restricts pattern length to 64. It 
        // seems like MatchPattern can use a lot
        // of stack if we use long patterns, so 
        // let's not get rid of this limitation. 
        static char buf[BUFSIZ]; 

        // Create pattern. 
        const char *p = str(CARG(1)), *m = str(CARG(2));
        LONG w = ParsePattern(p, buf, sizeof(buf)); 

        // Can we parse the pattern?
        if(w >= 0)
        {
            // Use pattern matching if we have one or more
            // wildcards, otherwise use plain strcmp().
            int r = w ? MatchPattern(buf, m) : !strcmp(p, m);
            RNUM(r ? 1 : 0);
        }
        else
        {
            // We probably had a buffer overflow. 
            error(contxt->id, ERR_OVERFLOW, p); 
            RNUM(0); 
        }
        #else
        RNUM(0); 
        #endif
    }
    else
    {
        // The parser is broken.
        error(PANIC); 
        RCUR; 
    }
}

//----------------------------------------------------------------------------
// (strlen <string>)
//     returns string length
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_strlen(entry_p contxt)
{
    // We need one argument, the string.
    if(c_sane(contxt, 1))
    {
        RNUM
        (
            (int) strlen(str(CARG(1)))
        ); 
    } 
    else
    {
        // The parser is broken.
        error(PANIC);
        RCUR; 
    }
}

//----------------------------------------------------------------------------
// (substr <string> <start> [<count>])
//     returns a substring of <string>
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_substr(entry_p contxt)
{
    if(c_sane(contxt, 2))
    {
        char *s = str(CARG(1));
        int i = num(CARG(2)),
            l = (int) strlen(s); 

        // Is the number characters limited?
        if(CARG(3) && CARG(3) != end())
        {
            // Get the number of characters 
            // to copy. 
            int j = num(CARG(3)); 

            // Use the limitations used by the
            // CBM installer. 
            if(i < l && j > 0 && i >= 0)
            {
                char *r = calloc((size_t) l + 1, 1); 
                if(r)
                {
                    // Cap all values and do the
                    // actual copy. 
                    l -= i; 
                    l = l < j ? l : j; 
                    memcpy(r, s + i, l); 
                    RSTR(r); 
                }
            }
        }
        // No, copy until the end of the string. 
        else
        {
            // Max cap
            if(i < l)
            {
                // Min cap
                if(i > 0)
                {
                    char *r = calloc((size_t) l + 1, 1); 
                    if(r)
                    {
                        // All values are already
                        // capped, just copy. 
                        memcpy(r, s + i, l - i); 
                        RSTR(r); 
                    }
                }

                // Return full string. 
                return CARG(1); 
            }
        }

        // Fall through. Return
        // empty string. 
        REST;
    }

    // The parser isn't necessarily broken 
    // if we end up here. We could alse be
    // out of memory.
    error(PANIC);
    RCUR; 
}

//----------------------------------------------------------------------------
// (tackon <path> <file>)
//     return properly concatenated file to path
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_tackon(entry_p contxt)
{
    // We need atleast two arguments, a path 
    // and a file.
    if(c_sane(contxt, 2))
    {
        const char *d = str(CARG(1)), *f = str(CARG(2));
        char *r = h_tackon(contxt->id, d, f); 
        if(r)
        {
            RSTR(r); 
        }
    }
    else
    {
        // The parser is broken
        error(PANIC); 
    }

    REST; 
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
char *h_tackon(int id, 
               const char *p, 
               const char *f)
{
    if(p && f)
    {
        size_t lp = strlen(p), 
               lf = strlen(f); 
        if(lp || lf)
        {
            char *r = NULL; 

            if(!lp) 
            {
                r = strdup(f); 

                if(!r)
                {
                    error(PANIC); 
                }

                return r;
            }

            if(!lf) 
            {
                r = strdup(p); 

                if(!r)
                {
                    error(PANIC); 
                }

                return r;
            }

            if(f[lf - 1] == '/' ||
               f[lf - 1] == ':') 
            {
                error(id, ERR_NOT_A_FILE, f); 
                return NULL; 
            }

            r = calloc(lp + lf + 2, 1); 

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
            else
            {
                error(PANIC); 
            }
        }
    }

    return NULL; 
}
