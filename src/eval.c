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
        // Todo
    }
    else if (entry->type == STRING)
    {
        // Todo
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

    i = 0; 
    while (entry->value.contxt.syms[i] && 
           entry->value.contxt.syms[i] != entry)
    {
        entry_p curr = entry->value.contxt.syms[i]; 
        plain_print (curr);
        i++; 
    }

    return entry;
}

