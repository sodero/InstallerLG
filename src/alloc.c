#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "alloc.h"
#include "native.h"

entry_p new_s ()
{
    int default_size = 64; 
    return new_native (0, default_size); 
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


void push (entry_p dst, entry_p src)
{
    int u = 0; 
    entry_p *new; 

    // Free space? 
    while (dst->value.native.args[u] != dst)
    {
        if (!dst->value.native.args[u])
        {
            // If true, push and return
            dst->value.native.args[u] = src; 
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
    }
    else
    {
        // Panic!
    }
}

void kill (entry_p entry)
{
    if (entry)
    {
    }
}

