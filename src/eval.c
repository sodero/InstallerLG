#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eval.h"
#include "alloc.h"
#include "util.h"
#include "debug.h"
#include "error.h"
#include "native.h"

static entry_p find_symbol(entry_p entry)
{
    entry_p con = local(entry); 
    if(con)
    {
        do
        {
            entry_p *tmp; 
            for(tmp = con->symbols;
                tmp && *tmp && *tmp != end(); 
                tmp++)
            {
                if((*tmp)->type == SYMBOL &&
                   !strcmp((*tmp)->name, entry->name)) 
                {
                    return *tmp; 
                }
            }
            con = local(con->parent);
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

entry_p resolve(entry_p entry)
{
    if(entry && 
       entry != end())
    {
        switch(entry->type)
        {
            case SYMBOL: 
                return entry->resolved ? entry->resolved : new_failure(); 
            case SYMREF: 
                return resolve(find_symbol(entry)); 
            case CONTXT: 
                return invoke(entry);
            case CUSREF:
            case NATIVE:
                return entry->call ? entry->call(entry) : new_failure(); 
            default:
                return entry; 
        }
    }
    error(PANIC);
    return new_failure();
}

int num(entry_p entry)
{
    if(entry && 
       entry != end())
    {
        switch(entry->type)
        {
            case OPTION:
                return atoi(str(entry)); 
            case STATUS:
            case DANGLE:
            case NUMBER:
                return entry->id;
            case SYMBOL:
                return num(entry->resolved); 
            case SYMREF:
                return num(find_symbol(entry)); 
            case CUSREF:
            case NATIVE:
                return num(entry->call ? entry->call(entry) : NULL); 
            case STRING:
                return atoi(entry->name);
            default:
                break; 
        }
    }
    error(PANIC);
    return 0; 
}

const char *str(entry_p entry)
{
    if(entry && 
       entry != end())
    {
        switch(entry->type)
        {
            case OPTION:
                switch(entry->id)
                {
                    case OPT_APPEND: 
                    case OPT_CONFIRM: 
                    case OPT_DEFAULT: 
                    case OPT_DEST: 
                    case OPT_DISK: 
                    case OPT_INCLUDE: 
                    case OPT_NEWNAME: 
                    case OPT_PATTERN: 
                    case OPT_SETDEFAULTTOOL: 
                    case OPT_SETSTACK: 
                    case OPT_SOURCE: 
                    case OPT_OVERRIDE: 
                        return str
                        (
                            entry->children ? 
                            entry->children[0] : NULL
                        );
                }
            case STATUS:
            case DANGLE:
                return ""; 
            case STRING:
                return entry->name;
            case SYMBOL:
                return str(entry->resolved); 
            case SYMREF:
                return str(find_symbol(entry)); 
            case CUSREF:
            case NATIVE:
                return str(entry->call ? entry->call(entry) : NULL); 
            case NUMBER:
                if(!entry->name)
                {
                    entry->name = malloc(NUMLEN); 
                }
                if(entry->name)
                {
                    snprintf(entry->name, NUMLEN, "%d", entry->id); 
                    return entry->name;
                }
            default:
                break;
        }
    }
    error(PANIC);
    return ""; 
}

entry_p invoke(entry_p entry)
{
    entry_p ret = new_failure(); 
    if(entry)
    {
        entry_p *vec = entry->children;
        while (*vec && 
               *vec != end() &&
               !did_error())
        {
            if((*vec)->type == NATIVE ||
               (*vec)->type == CUSREF)
            {
                if((*vec)->call)
                {
                    ret = (*vec)->call(*vec); 
                }
                else
                {
                    error(PANIC);
                    break; 
                }
            }
            vec++; 
        }
        return ret;
    }
    error(PANIC);
    return ret;
}

void run(entry_p entry)
{
    entry_p status = invoke(entry);
    if(did_error() && !did_halt())
    {
        error(RESET); 
        m_onerror(entry); 
    }
    eval_print(status);
//    pretty_print(entry); 
    kill(entry);
}

