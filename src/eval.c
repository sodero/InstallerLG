#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eval.h"
#include "alloc.h"
#include "util.h"
#include "debug.h"
#include "error.h"

static entry_p find_symbol(entry_p entry)
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
                    return *tmp; 
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
                return resolve(entry->expression);

            case SYMREF: 
                ret = find_symbol(entry); 
                return ret->resolved ? resolve(ret->resolved) : new_failure(); 

            case CONTXT: 
                return invoke(entry);

            case STATUS: 
            case OPTION: 
            case DANGLE:
                return entry; 

            case CUSREF:
            case NATIVE:
                if(entry->call)
                {
                    return entry->call(entry); 
                }
                break;
        }
    }
    error(PANIC);
    return new_failure();
}

int num(entry_p entry)
{
    if(entry && 
       entry != SENTINEL)
    {
        int n; 
        entry_p r; 
        switch(entry->type)
        {
            case CONTXT:
            case STATUS:
            case NUMBER:
            case DANGLE:
            case OPTION:
            case CUSTOM:
                return entry->id;
            case STRING:
                return atoi(entry->name);
            case SYMBOL:
                return num(entry->resolved); 
            case SYMREF:
                return num(find_symbol(entry)); 
            case CUSREF:
            case NATIVE:
                r = resolve_native(entry);
                n = num(r);
                kill(r);
                return n; 
        }
    }
    error(PANIC);
    return 0; 
}

char *str(entry_p entry)
{
    static char buf[BUFSIZE];
    if(entry && 
       entry != SENTINEL)
    {
        entry_p r; 
        switch(entry->type)
        {
            case CONTXT:
            case STATUS:
            case NUMBER:
            case DANGLE:
            case CUSTOM:
                snprintf(buf, BUFSIZE, "%d", entry->id); 
                return buf;
            case OPTION:
            case STRING:
                return entry->name;
            case SYMBOL:
                return str(entry->resolved); 
            case SYMREF:
                return str(find_symbol(entry)); 
            case CUSREF:
            case NATIVE:
                r = resolve_native(entry);
                strncpy(buf, str(r), BUFSIZE); // Den här kan du göra dig av med
                kill(r);
                return buf; 
        }
    }
    buf[0] = 0;  
    error(PANIC);
    return buf; 
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

