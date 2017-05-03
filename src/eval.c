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
    num.value.number = 0;

    if (entry->type == NUMBER)
    {
        num.value.number = entry->value.number;
    }
    else if (entry->type == SYMBOL)
    {
        entry_p r = entry->value.symbol.data;
        num.value.number = eval_as_number(r)->value.number;
    }
    else if (entry->type == SYMREF)
    {
        entry_p e = entry->parent;
        while (e && e->type != CONTXT)
        {
            e = e->parent;
        }
        if (e->type == CONTXT)
        {
            char *ref_name = entry->value.symref.name;
            entry_p *s = e->value.contxt.syms;
            while (*s && *s != e)
            {
                char *sym_name = (*s)->value.symbol.name;
                if (strcmp (sym_name, ref_name) == 0)
                {
                    entry_p r = (*s)->value.symbol.data;
                    num.value.number = eval_as_number(r)->value.number;
                    break;
                }
                s++;
            }

            if (*s == 0 || *s == e)
            {
                // Symbol not found
                fprintf(stderr, "Line %d: Undefined variable '%s'\n",
                        entry->value.symref.line, ref_name);
                runtime_error = 1;
            }
        }
        else
        {
            // Panic
            TRACE ("No context\n");
        }
    }
    else if (entry->type == STRING)
    {
        num.value.number = atoi (entry->value.string);
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
            TRACE ("Panic\n");
        }
    }
    else if (entry->type == STATUS)
    {
        num.value.number = entry->value.status.value;
    }
    else if (entry->type == CUSTOM)
    {
        // Todo
        TRACE ("Custom\n");
    }
    else
    {
        // Panic
        TRACE ("Panic\n");
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

void run(entry_p entry)
{
    int i = 0;
    runtime_error = 0;

    while (entry->value.contxt.args[i] &&
           entry->value.contxt.args[i] != entry &&
           !runtime_error)
    {
        entry_p curr = entry->value.contxt.args[i];
        if (curr->type == NATIVE)
        {
            call_t call = curr->value.native.call;
            entry_p *args = curr->value.native.args;
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

