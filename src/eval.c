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
        entry_p e = entry->parent;
        while (e && e->type != CONTXT)
        {
            e = e->parent;
        }
        if (e)
        {
            entry_p *s = e->symbols;
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
        error(__LINE__, "Internal error", 
              __func__); 
    }
    return NULL;
}

static entry_p resolve_native(entry_p entry)
{
    if(entry)
    {
        call_t call = entry->call;
        entry_p *args = entry->children;
        if (call && args)
        {
            entry_p result = call(args);
            return result; 
        }
    }
    else
    {
        error(__LINE__, "Internal error", 
              __func__); 
    }
    return NULL;
}

entry_p eval_as_number(entry_p entry)
{
    static entry_t num;

    num.id = 0;
    num.type = NUMBER;

    if(entry)
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
                error(__LINE__, "Internal error", 
                      __func__); 
        }
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
    int i = 0;
    if(entry)
    {
        while (!runtime_error() && 
               entry->children[i] &&
               entry->children[i] != SENTINEL )
        {
            entry_p curr = entry->children[i];
            if (curr && curr->type == NATIVE)
            {
                call_t call = curr->call;
                entry_p *args = curr->children;
                if (call && args)
                {
                    entry_p ret = call (args);
                    eval_print (ret);
                    kill (ret);
                }
            }
            i++;
        }
        kill (entry);
    }
    else
    {
        error(__LINE__, "Internal error", 
              __func__); 
    }
}

