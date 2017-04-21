#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eval.h"
#include "alloc.h"
#include "util.h"

entry_p eval_as_number(entry_p entry)
{ 
    static entry_t num; 

    num.type = NUMBER; 
    num.value.number = 0; 

    if (entry->type == NUMBER)
    {
        num.value.number = entry->value.number; 
    }
    else if (entry->type == SYMBOL)
    {
        entry_p r = entry->value.symbol.data; 
        num.value.number = eval_as_number(r)->value.number; 
    }
    else if (entry->type == SYMREF)
    {
        entry_p e = entry->parent; 
        while (e && e->type != CONTXT)
        {
            e = e->parent; 
        }
        if (e->type == CONTXT)
        {
            char *sym_name, *ref_name; 
            entry_p *s = e->value.contxt.syms; 
            while (*s && *s != e)
            {
                sym_name = (*s)->value.symbol.name; 
                ref_name = entry->value.symref.name; 
                if (strcmp (sym_name, ref_name) == 0)
                {
                    entry_p r = (*s)->value.symbol.data; 
                    num.value.number = eval_as_number(r)->value.number; 
                    break;
                }
                s++; 
            }

            if (*s == 0 || *s == e)
            {
                // Symbol not found 
                printf ("Unknown symbol\n");
            }
        }
        else
        {
            // Panic
            printf ("No context\n");
        }
    }
    else if (entry->type == STRING)
    {
        num.value.number = atoi (entry->value.string); 
    }
    else if (entry->type == NATIVE)
    {
        call_t call = entry->value.native.call;
        entry_p *args = entry->value.native.args; 
        if (call && args)
        {
            entry_p result = call (args); 
            num.value.number =  eval_as_number(result)->value.number; 
            kill (result); 
        }
        else
        {
            // Panic
        }
    }
    else if (entry->type == CUSTOM)
    {
        // Todo 
    }
    else
    {
        // Panic
    }

    return &num; 
}

entry_p eval_as_string(entry_p entry)
{ 
    static entry_t num; 
    static char buf[BUFSIZE]; 

    memset (buf, 0, BUFSIZE); 
    num.value.string = buf; 
    num.type = STRING; 

    return &num; 
}

entry_p eval_as_contxt(entry_p entry)
{ 
    int i = 0; 
    while (entry->value.contxt.args[i] && 
           entry->value.contxt.args[i] != entry)
    {
        entry_p curr = entry->value.contxt.args[i]; 
        if (curr->type == NATIVE)
        {
            call_t call = curr->value.native.call;
            entry_p *args = curr->value.native.args; 
            if (call && args)
            {
                entry_p ret = call (args); 
                plain_print (ret);
                kill (ret); 
            }
        }
        i++; 
    }
    return entry;
}

