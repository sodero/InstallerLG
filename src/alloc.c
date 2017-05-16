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
    const int size = 8; 
    entry_p entry = calloc (1, sizeof (entry_t)); 
    if (entry)
    {
        entry_p *symbols, *children; 
        symbols = calloc (size + 1, sizeof (entry_p)); 
        children = calloc (size + 1, sizeof (entry_p)); 
        if (symbols && children)
        {
            entry->type = CONTXT;
            entry->symbols = symbols; 
            entry->children = children; 
            entry->symbols[size] = SENTINEL; 
            entry->children[size] = SENTINEL; 
            return entry; 
        }
        free (symbols); 
        free (children); 
    }
    else
    {
        error(PANIC);
    }
    free (entry);
    return 0;
}

entry_p new_number (int n)
{
    entry_p entry = calloc (1, sizeof (entry_t)); 
    if (entry)
    {
        entry->type = NUMBER;
        entry->id = n;
    }
    else
    {
        error(PANIC);
    }
    return entry;
}

entry_p new_string (char *s) 
{
    if(s)
    {
        entry_p entry = calloc (1, sizeof (entry_t)); 
        if (entry)
        {
            entry->type = STRING;
            entry->name = s;
            return entry;
        }
        else
        {
            error(PANIC);
        }
    }
    return NULL; 
}

static entry_p new_status(int s)
{
    entry_p status = calloc (1, sizeof (entry_t)); 
    if (status)
    {
        status->type = STATUS;
        status->id = s;
        return status;
    }
    error(PANIC);
    return NULL;
}

entry_p new_success(void) 
{
    return new_status(1); 
}

entry_p new_failure(void) 
{
    return new_status(0); 
}

entry_p new_symbol (char *s, entry_p e) 
{
    if (s && e)
    {
        entry_p entry = calloc (1, sizeof (entry_t)); 
        if (entry)
        {
            entry->type = SYMBOL; 
            entry->name = s;
            entry->reference = e;
            return entry; 
        }
        else
        {
            error(PANIC);
        }
        free (entry);  
    }
    return NULL; 
}

entry_p new_symref (char *s, int l)
{
    if(s && (l > 0))
    {
        entry_p entry = calloc (1, sizeof (entry_t)); 
        if (entry)
        {
            entry->type = SYMREF; 
            entry->name = s;
            entry->id = l;
            return entry; 
        }
        else
        {
            error(PANIC);
        }
        free (entry);  
    }
    return NULL; 
}

static void move_contxt(entry_p dst, entry_p src)
{
    entry_p *c = dst->children = src->children; 
    entry_p *s = dst->symbols = src->symbols; 
    while(*c && *c != SENTINEL)
    {
        (*c)->parent = dst; 
        c++; 
    }
    while(*s && *s != SENTINEL)
    {
        (*s)->parent = dst; 
        s++; 
    }
    src->children = NULL; 
    src->symbols = NULL; 
    kill(src); 
}

entry_p new_native (call_t call, entry_p e)
{
    if(call)
    {
        entry_p entry = calloc (1, sizeof (entry_t)); 
        if (entry)
        {
            entry->call = call;
            entry->type = NATIVE;
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

entry_p new_cusref (char *s, int l, entry_p e)
{
    if(s && (l > 0))
    {
        entry_p entry = calloc (1, sizeof (entry_t)); 
        if (entry)
        {
            entry->id = l; 
            entry->name = s; 
            entry->call = m_cus;
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

void push (entry_p dst, entry_p src)
{
    if (dst && src)
    {
        int u = 0; 
        entry_p **dst_p = &dst->children;
        if (dst->type == CONTXT && 
            src->type == SYMBOL)
        {
            while (dst->symbols[u] &&
                   dst->symbols[u] != SENTINEL)
            {
                entry_p cur = dst->symbols[u]; 
                char *old = cur->name, 
                     *new = src->name; 
                if (strcmp (old, new) == 0)
                {
                    dst->symbols[u] = src;
                    return; 
                }
                u++;
            }
            dst_p = &dst->symbols; 
        }
        if(*dst_p)
        {
            entry_p *new; 
            int new_size; 
            // Free space? 
            while ((*dst_p)[u] != SENTINEL)
            {
                if (!(*dst_p)[u])
                {
                    // If true, push and return
                    (*dst_p)[u] = src; 
                    src->parent = dst; 
                    return; 
                }
                u++;
            }
            // Make the new array twice as big (+sentinel)
            new_size = u ? u << 1 : 1;  
            new = calloc (1 + new_size, sizeof (entry_p));
            if (new)
            {
                // Insert sentinel
                new[new_size] = SENTINEL; 
                // Make the swap and free the old array
                memmove (new, *dst_p, u * sizeof (entry_p)); 
                free (*dst_p); 
                *dst_p = new; 
                // Do the push
                (*dst_p)[u] = src; 
                src->parent = dst; 
            }
            else
            {
                error(PANIC);
            }
        }
    }
}

void kill (entry_p entry)
{
    if (entry)
    {
        free (entry->name); 
        kill (entry->reference);
        if(entry->children)
        {
            entry_p *e = entry->children; 
            while (*e && *e != SENTINEL)
            {
                kill (*e);
                e++; 
            }
            free (entry->children);
        }
        if(entry->type == NATIVE &&
           entry->symbols)
        {
            entry_p *e = entry->symbols; 
            while (*e && *e != SENTINEL)
            {
                kill (*e);
                e++; 
            }
        }
        free (entry->symbols);
        free (entry); 
    }
}

