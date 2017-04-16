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

entry_p eval_as_stdout(entry_p entry)
{ 
    int i = 0; 
    entry_p stmt = entry; 
    while (entry->value.native.args[i] && 
           entry->value.native.args[i] != entry)
    {
        stmt = entry->value.native.args[i]; 
        if (stmt->type == NATIVE)
        {
            call_t call = stmt->value.native.call;
            entry_p *args = stmt->value.native.args; 
            if (call && args)
            {
                entry_p result = call (args); 
                plain_print (result);
                kill (result); 
            }
        }
        i++; 
    }
    return stmt;
}

