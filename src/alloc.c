#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "alloc.h"
#include "native.h"

entry_p new_contxt ()
{
    entry_p entry = malloc (sizeof (entry_t)); 
    if (entry)
    {
        entry_p *syms, *args; 
        syms = calloc (ENTRIES + 1, sizeof (entry_p)); 
        args = calloc (ENTRIES + 1, sizeof (entry_p)); 
        if (syms && args)
        {
            entry->type = CONTXT;
            entry->value.contxt.syms = syms; 
            entry->value.contxt.args = args; 
            entry->value.contxt.syms[ENTRIES] = entry; 
            entry->value.contxt.args[ENTRIES] = entry; 
            return entry; 
        }
        free (syms); 
        free (args); 
    }
    // OOM panic
    free (entry);
    return 0;
}

entry_p new_number (int n)
{
    entry_p entry = malloc (sizeof (entry_t)); 
    if (entry)
    {
        entry->type = NUMBER;
        entry->value.number = n;
    }
    else
    {
        // Panic
    }
    return entry;
}

entry_p new_string (char *s) 
{
    entry_p entry = malloc (sizeof (entry_t)); 
    if (entry)
    {
        entry->type = STRING;
        entry->value.string = s;
    }
    else
    {
        // Panic
    }
    return entry;
}

entry_p new_symbol (char *s, entry_p e) 
{
    entry_p entry = malloc (sizeof (entry_t)); 
    if (entry && s && e)
    {
        entry->type = SYMBOL; 
        entry->value.symbol.name = s;
        entry->value.symbol.data = e;
        return entry; 
    }
    // Panic
    free (entry);  
    return 0; 
}

entry_p new_symref (char *s) 
{
    entry_p entry = malloc (sizeof (entry_t)); 
    if (entry && s)
    {
        entry->type = SYMREF; 
        entry->value.symref.name = s;
        return entry; 
    }
    // Panic
    free (entry);  
    return 0; 
}


entry_p new_native (call_t call, int nargs)
{
    entry_p entry = malloc (sizeof (entry_t)); 
    if (entry && call)
    {
        entry->value.native.args = calloc (nargs + 1, sizeof (entry_p));
        if (entry->value.native.args)
        {
            entry->type = NATIVE;
            entry->value.native.call = call;
            entry->value.native.args[nargs] = entry; 
            return entry;
        }
    }
    // Panic
    free (entry);
    return 0;
}

void push (entry_p dst, entry_p src)
{
    int u = 0; 
    entry_p *new; 
    entry_p **dst_p; 

    if (!dst || !src)
    {
        // Panic
        return;
    }

    switch (dst->type)
    {
        case CONTXT:
            switch (src->type)
            {
                case SYMBOL:
                    dst_p = &dst->value.contxt.syms; 
                    break; 
                
                default: 
                    dst_p = &dst->value.contxt.args; 
            }
            break; 

        case NATIVE:
            dst_p = &dst->value.native.args; 
            break; 

        case CUSTOM:
            dst_p = &dst->value.custom.args; 
            break; 

        default: 
            return; 
    }

    // Free space? 
    while ((*dst_p)[u] != dst)
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
    new = calloc (1 + (u << 1), sizeof (entry_p));
    if (new)
    {
        // Put the sentinel in place
        new[u << 1] = dst; 
        // Make the swap and release the old array
        memmove (new, *dst_p, u * sizeof (entry_p)); 
        free (*dst_p); 
        *dst_p = new; 
        // Finally, do the push
        (*dst_p)[u] = src; 
        src->parent = dst; 
    }
    else
    {
        // Panic!
    }
}

void kill (entry_p entry)
{
    if (!entry)
    {
        return; 
    }
    else if (entry->type == NUMBER)
    {
        printf("Freeing NUMBER (%d)\n", entry->value.number);
    }
    else if (entry->type == STRING)
    {
        printf("Freeing STRING (%s)\n", entry->value.string);
        free (entry->value.string); 
    }
    else if (entry->type == SYMBOL)
    {
        kill (entry->value.symbol.data);
        free (entry->value.symbol.name); 
        printf("Freeing SYMBOL\n");
    }
    else if (entry->type == SYMREF)
    {
        free (entry->value.symref.name); 
        printf("Freeing SYMREF\n");
    }
    else if (entry->type == NATIVE)
    {
        entry_p *e = entry->value.native.args; 
        while (*e && *e != entry)
        {
            kill (*e);
            e++; 
        }
        free (entry->value.native.args);
        printf("Freeing NATIVE\n");
    }
    else if (entry->type == CUSTOM)
    {
        // Todo
    }
    else if (entry->type == CONTXT)
    {
        entry_p *e = entry->value.contxt.args; 
        while (*e && *e != entry)
        {
            kill (*e);
            e++; 
        }
        e = entry->value.contxt.syms; 
        while (*e && *e != entry)
        {
            kill (*e);
            e++; 
        }
        free (entry->value.contxt.args);
        free (entry->value.contxt.syms);
        printf("Freeing CONTXT\n");
    }
    free (entry); 
}

