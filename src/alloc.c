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
    // Panic
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
    return 0; 
}

entry_p new_symbol (char *s) 
{
    return 0; 
}

entry_p new_native (call_t call, int nargs)
{
    entry_p entry = malloc (sizeof (entry_t)); 
    if (entry)
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
    entry_p **args_p; 

    if (dst->type == NATIVE)
    {
        args_p = &dst->value.native.args; 
printf("native %p == %p\n", *args_p, dst->value.native.args);
    }
    else if (dst->type == CONTXT)
    {
        args_p = &dst->value.contxt.args; 
printf("contxt %p == %p\n", *args_p, dst->value.contxt.args);
    }
    else 
    {
        // Invalid push!
printf("sumfnels\n");
        return; 
    }

    // du kan inte bara hantera native har!
    // du borde kanske ersatta args med barn?
    // Free space? 
    //while (dst->value.native.args[u] != dst)
    while ((*args_p)[u] != dst)
    {
        //if (!dst->value.native.args[u])
        if (!(*args_p)[u])
        {
            // If true, push and return
            //dst->value.native.args[u] = src; 
            (*args_p)[u] = src; 
            src->parent = dst; 
            return; 
        }
        u++;
printf("3b u:%d\n", u);
    }

printf("4 u:%d\n", u);

    // Make the new array twice as big (+sentinel)
    new = calloc (1 + (u << 1), sizeof (entry_p));
printf("5 new size:%d\n", 1 + (u << 1));
    if (new)
    {
        // Put the sentinel in place
        new[u << 1] = dst; 

        // Make the swap and release the old array
printf("6\n");
        //memmove (new, dst->value.native.args, u * sizeof (entry_p)); 
        memmove (new, *args_p, u * sizeof (entry_p)); 
printf("7\n");
      //  free (dst->value.native.args); 
        free (*args_p); 
printf("8\n");
        //dst->value.native.args = new; 
        *args_p = new; 

        // Finally, do the push
        //dst->value.native.args[u] = src; 
        (*args_p)[u] = src; 
        src->parent = dst; 
    }
    else
    {
        // Panic!
    }
}
/*
void push (entry_p dst, entry_p src)
{
    int u = 0; 
    entry_p *new; 

    // du kan inte bara hantera native har!
    // du borde kanske ersatta args med barn?

    // Free space? 
    while (dst->value.native.args[u] != dst)
    {
        if (!dst->value.native.args[u])
        {
            // If true, push and return
            dst->value.native.args[u] = src; 
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
        memmove (new, dst->value.native.args, u * sizeof (entry_p)); 
        free (dst->value.native.args); 
        dst->value.native.args = new; 

        // Finally, do the push
        dst->value.native.args[u] = src; 
        src->parent = dst; 
    }
    else
    {
        // Panic!
    }
}
*/

void kill (entry_p entry)
{
    if (entry)
    {
    }
}

