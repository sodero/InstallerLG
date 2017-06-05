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
    entry_p con = local(entry); 
    if(con)
    {
        do
        {
            entry_p nxt; 
            entry_p *tmp; 
            for(tmp = con->symbols;
                tmp && *tmp && *tmp != SENTINEL; 
                tmp++)
            {
                if(!strcmp((*tmp)->name, entry->name)) 
                {
                    entry_p ret = (*tmp)->reference;
                    return ret; 
                }
            }
            nxt = global(entry);
            con = con == nxt ? NULL : nxt; 
        }
        while(con);
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
 
entry_p resolve(entry_p entry)
{
    if(entry)
    {
        entry_p ret; 
        switch(entry->type)
        {
            case NUMBER:
            case STRING:
            case CUSTOM:
                ret = malloc(sizeof(entry_t)); 
                if(ret)
                {
                    memmove(ret, entry, sizeof(entry_t)); 
                    ret->name = entry->name ? strdup(entry->name) : NULL; 
                    return ret; 
                }
                break;

            case SYMBOL: 
                return resolve(entry->reference);

            case SYMREF: 
                return resolve(resolve_symref(entry));

            case CONTXT: 
                return invoke(entry);

            case STATUS: 
            case DANGLE:
                return entry; 

            case CUSREF:
            case NATIVE:
                return resolve(entry->call ? entry->call(entry) : NULL);
        }
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
            case STATUS:
            case NUMBER:
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

/*

Nar behover vi eval + deep copy? 
- vid "set" pa global niva.
- vid overgang till funktionskontext, dvs nar vi
  gor "set" pa lokala variabler for att overfora
  info fran anropande kontext.




*/

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

