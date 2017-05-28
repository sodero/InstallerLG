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
    char *tbs[] = 
    { 
        "\t", 
        "\t\t", 
        "\t\t\t", 
        "\t\t\t\t", 
        "\t\t\t\t\t" 
    }; 

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


    if(!entry)
    {
        printf ("NULL\n\n");
        return; 
    }
    switch (entry->type)
    {
        case NUMBER:
            printf ("NUMBER\n");
            printf ("%sId:\t%d\n", tabs(ind), entry->id);
            break;

        case STRING:
            printf ("STRING\n");
            printf ("%sName:\t%s\n", tabs(ind), entry->name);
            break;

        case SYMBOL:
            printf ("SYMBOL\n");
            printf ("%sName:\t%s\n", tabs(ind), entry->name);
            printf ("%sRef:", tabs(ind));
            pretty_print (entry->reference);
            break;

        case SYMREF:
            printf ("SYMREF\n");
            printf ("%sName:\t%s\n", tabs(ind), entry->name);
            break;

        case NATIVE:
            printf ("NATIVE\n");
            printf ("%sName:\t%s\n", tabs(ind), entry->name);
            printf ("%sCall:\t%p\n", tabs(ind), entry->call);
            break;

        case CUSTOM:
            printf ("CUSTOM\n");
            printf ("%sName:\t%s\n", tabs(ind), entry->name);
            printf ("%sCall:\t%p\n", tabs(ind), entry->call);
            if(entry->children || 
               entry->symbols)
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
                e = entry->symbols;
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
            break;

        case CUSREF:
            printf ("CUSREF\n");
            printf ("%sName:\t%s\n", tabs(ind), entry->name);
            break;

        case CONTXT:
            printf ("CONTXT\n"); 
            if(entry->children || 
               entry->symbols)
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
                e = entry->symbols;
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
            break;

        case STATUS:
            printf ("STATUS\n");
            printf ("%sName:\t%s\n", tabs(ind), entry->name);
            printf ("%sId:\t%d\n", tabs(ind), entry->id);
            break;

        case DANGLE:
            printf ("DANGLE\n");
            break;
    }
}

entry_p local(entry_p e)
{
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

