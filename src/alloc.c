#include <stdlib.h>
#include "alloc.h"
#include "builtin.h"

entry_p create_s ()
{
    int default_size = 64; 
    return create_b (default_size); 
}

entry_p create_b (int nargs)
{
    entry_p entry = malloc (sizeof (entry_t)); 
    if (entry)
    {
        entry->value.builtin.args = calloc (nargs + 1, sizeof (entry_p));
        if (entry->value.builtin.args)
        {
            entry->type = BUILTIN;
            entry->value.builtin.call = m_s;
            entry->value.builtin.args[nargs] = entry; 
            return entry;
        }
    }
    free (entry);
    return 0;
}

void destroy (entry_p entry)
{
    if (entry)
    {
    }
}

int n_used (entry_p entry)
{
    int n = 0; 
    if (entry->type == BUILTIN)
    {
        while (entry->value.builtin.args[n] != entry)
        {
            n++;
        }
    }
    return n;
}

int n_free (entry_p entry)
{
    int n = 0; 
    if (entry->type == BUILTIN)
    {
    }
    return n;
}

