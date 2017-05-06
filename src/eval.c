#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eval.h"
#include "alloc.h"
#include "util.h"
#include "debug.h"

int runtime_error;

entry_p eval_as_number(entry_p entry)
{
    static entry_t num;

    num.type = NUMBER;
    num.id = 0;

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
        entry_p e = entry->parent;
        while (e && e->type != CONTXT)
        {
            // We go all the way, we 
            // could change this if 
            // we'd like to support 
            // local variabels...
            e = e->parent;
        }

        ASSERT(e->type == CONTXT);
        if (e->type == CONTXT)
        {
            char *ref_name = entry->name;
            entry_p *s = e->symbols;
            while (*s && *s != e)
            {
                char *sym_name = (*s)->name;
                if (strcmp (sym_name, ref_name) == 0)
                {
                    entry_p r = (*s)->reference;
                    num.id = eval_as_number(r)->id;
                    break;
                }
                s++;
            }

            if (*s == 0 || *s == e)
            {
                // Symbol not found
                fprintf(stderr, "Line %d: Undefined variable '%s'\n",
                        entry->id, ref_name);
                runtime_error = 1;
            }
        }
    }
    else if (entry->type == NATIVE)
    {
        call_t call = entry->call;
        entry_p *args = entry->children;

        ASSERT(call && args);
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
    runtime_error = 0;

    while (entry->children[i] &&
           entry->children[i] != entry &&
           !runtime_error)
    {
        entry_p curr = entry->children[i];
        if (curr->type == NATIVE)
        {
            call_t call = curr->call;
            entry_p *args = curr->children;

            ASSERT(call && args);
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

