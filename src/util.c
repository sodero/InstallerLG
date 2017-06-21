#include <stdio.h>
#include "util.h"
#include "debug.h"
#include "alloc.h"

void eval_print (entry_p entry)
{
    if(entry)
    {
        if(entry->type == NUMBER)
        {
            printf ("%d\n", entry->id);
        }
        else if(entry->type == STRING)
        {
            printf ("%s\n", entry->name);
        }
    }
    else
    {
        printf ("NULL\n");
    }
    return;     
}

char *tabs(int n)
{
    static char t[16]; 
    n = n < sizeof(t) ? n : sizeof(t); 
    for(t[n] = '\0'; n--; t[n] = '\t'); 
    return t; 
}

void pretty_print (entry_p entry)
{
    static int ind = 0; 
    static char *tps[] = 
    {
        "NUMBER",
        "STRING", 
        "SYMBOL",
        "SYMREF",
        "NATIVE", 
        "CUSTOM", 
        "CUSREF", 
        "CONTXT",
        "STATUS",
        "DANGLE"
    };

    if(entry)
    {
        printf("%s\n", tps[entry->type]);
        printf("%sThis:%p\n", tabs(ind), entry);
        printf("%sParent:%p\n", tabs(ind), entry->parent);
        if(entry->id || 
           entry->type == STATUS ||
           entry->type == NUMBER) 
        {
            printf("%sId:\t%d\n", tabs(ind), entry->id);
        }
        if(entry->name) 
        {
            printf("%sName:\t%s\n", tabs(ind), entry->name);
        }
        if(entry->expression) 
        {
            printf ("%sExp:\t", tabs(ind));
            ind++; 
            pretty_print (entry->expression);
            ind--; 
        }
        if(entry->resolved) 
        {
            printf ("%sRes:\t", tabs(ind));
            ind++; 
            pretty_print (entry->resolved);
            ind--; 
        }
        if(entry->children) 
        {
            entry_p *e = entry->children;
            if(e && *e)
            {
                while(*e && *e != SENTINEL)
                {
                    printf ("%sChl:\t", tabs(ind)); 
                    ind++; 
                    pretty_print(*e); 
                    ind--; 
                    e++; 
                }
            }
        }
        if(entry->symbols) 
        {
            entry_p *e = entry->symbols;
            if(e && *e)
            {
                while(*e && *e != SENTINEL)
                {
                    printf ("%sSym:\t", tabs(ind)); 
                    ind++; 
                    pretty_print(*e); 
                    ind--; 
                    e++; 
                }
            }
        }
    }
    else
    {
        printf ("NULL\n\n");
        return; 
    }
}

void ror(entry_p *e)
{
    if(e && *e)
    {
        int i = 0; 
        while(e[i] && e[i] != SENTINEL)
        {
            i++; 
        }
        i--; 
        if(i)
        {
            entry_p f = e[i]; 
            while(i)
            {
                e[i] = e[i - 1]; 
                i--; 
            }
            e[0] = f; 
        }
    }
}

entry_p local(entry_p e)
{
    int i = 0; 
    for(; e && 
        e->type != CONTXT && 
        e->type != CUSTOM 
        ; e = e->parent);
    return e; 
}

entry_p global(entry_p e)
{
    for(e = local(e); 
        local(e->parent); 
        e = local(e->parent)); 
    return e; 
}

