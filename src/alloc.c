#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "debug.h"
#include "util.h"
#include "alloc.h"
#include "error.h"
#include "native.h"

entry_p new_contxt(void)
{
    entry_p entry = calloc (1, sizeof(entry_t)); 
    if(entry)
    {
        entry_p *symbols, *children; 
        symbols = calloc(VECLEN + 1, sizeof(entry_p)); 
        children = calloc(VECLEN + 1, sizeof(entry_p)); 
        if(symbols && children)
        {
            entry->type = CONTXT;
            entry->symbols = symbols; 
            entry->children = children; 
            entry->symbols[VECLEN] = end(); 
            entry->children[VECLEN] = end(); 
            return entry; 
        }
        free(symbols); 
        free(children); 
    }
    error(PANIC);
    free(entry);
    return 0;
}

entry_p new_number(int n)
{
    entry_p entry = calloc(1, sizeof(entry_t)); 
    if(entry)
    {
        entry->type = NUMBER;
        entry->id = n;
        return entry;
    }
    error(PANIC);
    return NULL;
}

entry_p new_string(char *n) 
{
    if(n)
    {
        entry_p entry = calloc(1, sizeof (entry_t)); 
        if (entry)
        {
            entry->type = STRING;
            entry->name = n;
            return entry;
        }
    }
    error(PANIC);
    return NULL; 
}

static entry_p new_status(int s)
{
    static entry_t status; 
    status.type = STATUS; 
    status.id = s; 
    return &status; 
}

entry_p new_success(void) 
{
    return new_status(1); 
}

entry_p new_failure(void) 
{
    return new_status(0); 
}

entry_p new_symbol(char *n, entry_p e) 
{
    if(n && e)
    {
        entry_p entry = calloc(1, sizeof(entry_t)); 
        if(entry)
        {
            entry->type = SYMBOL; 
            entry->name = n;
            entry->expression = e;
            entry->resolved = new_dangle();
            entry->resolved->parent = entry; 
            e->parent = entry; 
            return entry; 
        }
    }
    error(PANIC);
    return NULL; 
}

entry_p new_custom(char *n, int l, entry_p s, entry_p c) 
{
    if(n && c)
    {
        entry_p entry = calloc(1, sizeof(entry_t)); 
        if(entry)
        {
            entry_p *e; 
            entry->id = l;
            entry->name = n;
            entry->type = CUSTOM; 
            if(s && s->symbols)
            {
                entry->symbols = s->symbols; 
                s->symbols = NULL; 
                kill(s); 
                e = entry->symbols; 
                while(*e && *e != end())
                {
                    (*e)->parent = entry;
                    e++; 
                }
            }
            entry->children = c->children;
            c->children = NULL; 
            kill(c); 
            e = entry->children; 
            while(*e && *e != end())
            {
                (*e)->parent = entry;
                e++; 
            }
            return entry; 
        }
    }
    error(PANIC);
    return NULL; 
}

entry_p new_symref(char *n, int l)
{
    if(n && (l > 0))
    {
        entry_p entry = calloc(1, sizeof(entry_t)); 
        if(entry)
        {
            entry->type = SYMREF; 
            entry->name = n;
            entry->id = l;
            return entry; 
        }
    }
    error(PANIC);
    return NULL; 
}

static void move_contxt(entry_p dst, entry_p src)
{
    if(dst && src)
    {
        entry_p *c = dst->children = src->children; 
        entry_p *s = dst->symbols = src->symbols; 
        while(*c && *c != end())
        {
            (*c)->parent = dst; 
            c++; 
        }
        while(*s && *s != end())
        {
            (*s)->parent = dst; 
            s++; 
        }
        src->children = NULL; 
        src->symbols = NULL; 
        kill(src); 
        return; 
    }
    error(PANIC);
}

entry_p new_native (char *n, int l, call_t call, entry_p e, type_t r)
{
    if(call && n && (l > 0))
    {
        entry_p entry = calloc(1, sizeof (entry_t)); 
        if (entry)
        {
            entry->id = l;
            entry->call = call;
            entry->type = NATIVE;
            entry->name = n; 
            if(e && e->type == CONTXT)
            {
                move_contxt(entry, e); 
            }
            if(r == NUMBER)
            {
                entry->resolved = new_number(0); 
            }
            else if(r == STRING)
            {
                entry->resolved = new_string(strdup("")); 
            }
            else
            {
                return entry;
            }
            if(entry->resolved)
            {
                return entry;
            }
            free(entry); 
        }
    }
    error(PANIC);
    return NULL;
}

entry_p new_option (char *n, opt_t t, entry_p e)
{
    if(n)
    {
        entry_p entry = calloc(1, sizeof (entry_t)); 
        if (entry)
        {
            entry->id = (int) t;
            entry->type = OPTION;
            entry->name = n; 
            if(e && e->type == CONTXT)
            {
                move_contxt(entry, e); 
            }
            return entry;
        }
    }
    error(PANIC);
    return NULL;
}

entry_p new_cusref (char *n, int l, entry_p e)
{
    if(n && (l > 0))
    {
        entry_p entry = calloc (1, sizeof (entry_t)); 
        if (entry)
        {
            entry->id = l; 
            entry->name = n; 
            entry->call = m_gosub;
            entry->type = CUSREF;
            if(e && e->type == CONTXT)
            {
                move_contxt(entry, e); 
            }
            return entry;
        }
    }
    error(PANIC);
    return NULL; 
}

entry_p new_dangle(void)
{
    static entry_t dangle; 
    dangle.type = DANGLE; 
    dangle.id = 0; 
    return &dangle; 
}

entry_p push(entry_p dst, entry_p src)
{
    if (dst && src)
    {
        size_t u = 0; 
        entry_p **dst_p = &dst->children;
        if (dst->type == CONTXT && 
            src->type == SYMBOL)
        {
            while (dst->symbols[u] &&
                   dst->symbols[u] != end())
            {
                entry_p cur = dst->symbols[u]; 
                char *old = cur->name, 
                     *new = src->name; 
                if (strcmp (old, new) == 0)
                {
                    dst->symbols[u] = src;
                    src->parent = dst; 
                    return dst; 
                }
                u++;
            }
            dst_p = &dst->symbols; 
        }
        if(*dst_p)
        {
            entry_p *new; 
            size_t new_size; 
            // Free space? 
            while ((*dst_p)[u] != end())
            {
                if (!(*dst_p)[u])
                {
                    // If true, push and return
                    (*dst_p)[u] = src; 
                    src->parent = dst; 
                    return dst; 
                }
                else if(src->type == CUSTOM &&
                       (*dst_p)[u]->type == CUSTOM) 
                {
                    if(!strcmp(src->name, (*dst_p)[u]->name))
                    {
                        error(src->id, "Procedure naming collision", 
                              src->name); 
                    }
                }
                u++;
            }
            // Make the new array twice as big (+sentinel)
            new_size = u ? u << 1 : 1;  
            new = calloc (1 + new_size, sizeof (entry_p));
            if (new)
            {
                // Insert sentinel
                new[new_size] = end(); 
                // Make the swap and free the old array
                memmove (new, *dst_p, u * sizeof (entry_p)); 
                free (*dst_p); 
                *dst_p = new; 
                // Do the push
                (*dst_p)[u] = src; 
                src->parent = dst; 
                return dst; 
            }
        }
    }
    error(PANIC);
    return dst; 
}

void kill(entry_p entry)
{
return; 
    if(entry && 
       entry->type != STATUS &&
       entry->type != DANGLE)
    {
     //   kill(entry->resolved);
        kill(entry->expression);
        if(entry->symbols && (
           entry->type == NATIVE || 
           entry->type == CUSTOM ))
        {
            entry_p *e = entry->symbols; 
            while(*e && *e != end())
            {
                kill (*e);
                e++; 
            }
        }
        if(entry->children)
        {
            entry_p *e = entry->children; 
            while(*e && *e != end())
            {
                kill (*e);
                e++; 
            }
        }
        free(entry->name); 
        free(entry->symbols);
        free(entry->children);
        free(entry); 
    }
}

entry_p end(void)
{
    static entry_t snt; 
    return &snt; 
}
