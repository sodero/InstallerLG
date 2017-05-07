#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eval.h"
#include "alloc.h"
#include "util.h"
#include "debug.h"

static int error(int id, char *type, char *info)
{
    static int err = 0;
    if (id && type && info)
    {
        err++; 
        fprintf(stderr, "Line %d: ", id); 
        fprintf(stderr, "%s ", type); 
        fprintf(stderr, "'%s'\n", info);
    }
    return err; 
}

static int runtime_error()
{
    return error(0, NULL, NULL);
}

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
                if (strcmp (entry->name, (*s)->name) == 0)
                {
                    entry_p r = (*s)->reference;
                    return r; 
                }
                s++;
            }
        }
    }
    // Symbol not found
    error(entry->id, "Undefined variable", entry->name); 
    return NULL;
}

entry_p eval_as_number(entry_p entry)
{
    static entry_t num;
    num.type = NUMBER;
    num.id = 0;

    if(entry)
    {
        if (entry->type == NUMBER || 
            entry->type == STATUS )
        {
            num.id = entry->id;
        }
        else if (entry->type == STRING)
        {
            num.id = atoi (entry->name);
        }
        else if (entry->type == SYMBOL)
        {
            entry_p r = entry->reference;
            num.id = eval_as_number(r)->id;
        }
        else if (entry->type == SYMREF)
        {
            entry_p r = resolve_symref(entry); 
            num.id = eval_as_number(r)->id;
        }
        else if (entry->type == NATIVE)
        {
            call_t call = entry->call;
            entry_p *args = entry->children;
            if (call && args)
            {
                entry_p result = call (args);
                num.id =  eval_as_number(result)->id;
                kill (result);
            }
        }
        else if (entry->type == CUSTOM)
        {
            // Todo
            TRACE ("Custom\n");
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
}

