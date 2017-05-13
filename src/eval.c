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
    if(entry)
    {
        entry_p par = entry->parent;
        while (par && par->type != CONTXT)
        {
            par = par->parent;
        }
        if (par)
        {
            entry_p *s = par->symbols;
            while (*s && *s != SENTINEL)
            {
                if (strcmp (entry->name, 
                    (*s)->name) == 0)
                {
                    entry_p r = (*s)->reference;
                    return r; 
                }
                s++;
            }
        }
        error(entry->id, "Undefined variable", 
              entry->name); 
    }
    else
    {
        PANIC; 
    }
    return new_failure(NULL);
}

static entry_p resolve_native(entry_p entry)
{
    if(entry && entry->call)
    {
        entry_p result = entry->call(entry);
        return result; 
    }
    PANIC; 
    return new_failure(NULL);
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

            case NATIVE:
                r = resolve_native(entry);
                num.id =  eval_as_number(r)->id;
                kill(r);
                break;
            
            case CUSTOM:
                break;

            default:
                PANIC;
        }
    }
    else
    {
        PANIC;
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

void run(entry_p entry)
{
    if(entry && entry->children)
    {
        entry_p *vec = entry->children;
        while (*vec && *vec != SENTINEL &&
               !runtime_error())
        {
            entry_p cur = *vec; 
            if(cur)
            {
                entry_p ret = NULL; 
                switch(cur->type) 
                {
                    case NATIVE:
                        ret = resolve_native(cur);
                        break; 

                    default:
                        vec++; 
                        continue; 
                }
                eval_print(ret);
                kill(ret);
                vec++; 
            }
        }
        kill (entry);
    }
    else
    {
        PANIC; 
    }
}

