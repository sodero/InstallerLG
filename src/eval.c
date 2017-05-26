#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eval.h"
#include "alloc.h"
#include "util.h"
#include "debug.h"
#include "error.h"

static entry_p resolve_symref(entry_p entry)
{
    entry_p par; 
    for(par = entry->parent; 
        par && par->type != CONTXT; 
        par = par->parent);
    if(par)
    {
        entry_p *s; 
        for(s = par->symbols;
            *s && *s != SENTINEL; s++)
        {
            if(!strcmp((*s)->name, entry->name)) 
            {
                entry_p r = (*s)->reference;
                return r; 
            }
        }
        error(entry->id, "Undefined variable", 
              entry->name); 
    }
    else
    {
        error(PANIC);
    }
    return new_failure();
}

static entry_p resolve_native(entry_p entry)
{
    if(entry->call)
    {
        entry_p result = entry->call(entry);
        return result; 
    }
    error(PANIC);
    return new_failure();
}
 
entry_p eval_as_number(entry_p entry)
{
    static entry_t num;
    num.id = 0;
    num.type = NUMBER;
    if(entry && 
       entry != SENTINEL)
    {
        entry_p r; 
        switch(entry->type)
        {
            case NUMBER:
            case STATUS:
            case DANGLE:
            case CUSTOM:
                num.id = entry->id;
                break;

            case STRING:
                num.id = atoi(entry->name);
                break;

            case SYMBOL:
                r = entry->reference;
                num.id = eval_as_number(r)->id;
                break;

            case SYMREF:
                r = resolve_symref(entry); 
                num.id = eval_as_number(r)->id;
                break;

            case CUSREF:
            case NATIVE:
                r = resolve_native(entry);
                num.id = eval_as_number(r)->id;
                kill(r);
                break;

            default:
                error(PANIC);
        }
    }
    else
    {
        error(PANIC);
    }
    return &num;
}

entry_p eval_as_string(entry_p entry)
{
    static entry_t str;
    static char buf[BUFSIZE];

    str.type = STRING;
    str.name = buf;
    memset (str.name, 0, BUFSIZE);

    return &str;
}

entry_p invoke(entry_p entry)
{
    entry_p ret = new_failure(); 
    if(entry)
    {
        entry_p *vec = entry->children;
        while (*vec && 
               *vec != SENTINEL &&
               !runtime_error())
        {
            entry_p cur = *vec; 
            if(cur && ( 
               cur->type == NATIVE ||
               cur->type == CUSREF))
            {
                kill(ret);
                ret = resolve_native(cur);
            }
            vec++; 
        }
    }
    else
    {
        error(PANIC);
    }
    return ret;
}

void run(entry_p entry)
{
    entry_p status = invoke(entry);
    eval_print(status);
    kill(status);
    kill(entry);
}

