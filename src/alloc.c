#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "debug.h"
#include "util.h"
#include "alloc.h"
#include "error.h"
#include "native.h"

entry_p new_contxt()
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
        error(__LINE__, "Internal error", 
              __func__); 
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
        error(__LINE__, "Internal error", 
              __func__); 
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
            error(__LINE__, "Internal error", 
                  __func__); 
        }
    }
    return NULL; 
}

entry_p new_success () 
{
    char *name = strdup("Success");
    entry_p status = calloc (1, sizeof (entry_t)); 
    if (status && name)
    {
        status->type = STATUS;
        status->id = 1;
        status->name = name;
        return status;
    }
    else
    {
        error(__LINE__, "Internal error", 
              __func__); 
    }
    free(name); 
    free(status); 
    return NULL;
}

entry_p new_failure (char *s) 
{
    char *name = strdup(s ? s : "Failure");
    entry_p status = calloc (1, sizeof (entry_t)); 
    if (status && name)
    {
        status->type = STATUS;
        status->id = 0;
        status->name = name;
        return status;
    }
    else
    {
        error(__LINE__, "Internal error", 
              __func__); 
    }
    free(name); 
    free(status); 
    return NULL;
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
            error(__LINE__, "Internal error", 
                  __func__); 
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
            error(__LINE__, "Internal error", 
                  __func__); 
        }
        free (entry);  
    }
    return NULL; 
}


entry_p new_native (call_t call, int nargs)
{
    if (call)
    {
        entry_p entry = calloc (1, sizeof (entry_t)); 
        if (entry)
        {
            entry->children = calloc (nargs + 1, sizeof (entry_p));
            if (entry->children)
            {
                entry->type = NATIVE;
                entry->call = call;
                entry->children[nargs] = SENTINEL; 
                return entry;
            }
            else
            {
                error(__LINE__, "Internal error", 
                      __func__); 
            }
            free (entry);
        }
        else
        {
            error(__LINE__, "Internal error", 
                  __func__); 
        }
    }
    return NULL;
}

entry_p new_cusref (char *s, entry_p e)
{
    fprintf(stderr, "%s\n", s);
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
                error(__LINE__, "Internal error", 
                      __func__); 
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
        free (entry->symbols);
        free (entry); 
    }
}

