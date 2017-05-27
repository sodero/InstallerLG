#include <stdio.h>
#include "util.h"
#include "debug.h"
#include "alloc.h"

void eval_print (entry_p entry)
{
    if(!entry)
    {
        printf ("NULL\n");
        return; 
    }
    switch (entry->type)
    {
        case NUMBER:
            printf ("%d\n", entry->id);
            break;

        case STRING:
            printf ("%s\n", entry->name);
            break;

        case SYMBOL:
        case SYMREF:
        case NATIVE:
        case CUSTOM:
        case CUSREF:
        case CONTXT:
        case STATUS:
        case DANGLE:
            break;
    }
}

void pretty_print (entry_p entry)
{
    static int ind = 0; 
    char *tbs[] = { "", "\t", "\t\t", "\t\t\t", 
                    "\t\t\t\t", "\t\t\t\t\t" }; 
    if(!entry)
    {
        printf ("\tNULL\n\n");
        return; 
    }
    switch (entry->type)
    {
        case NUMBER:
            printf ("%sNUMBER\n", tbs[ind]);
            printf ("%sId:\t%d\n", tbs[ind], entry->id);
            break;

        case STRING:
            printf ("%sSTRING\n", tbs[ind]);
            printf ("%sName:\t%s\n", tbs[ind], entry->name);
            break;

        case SYMBOL:
            printf ("%sSYMBOL\n", tbs[ind]);
            printf ("%sName:\t%s", tbs[ind], entry->name);
            pretty_print (entry->reference);
            break;

        case SYMREF:
            printf ("%sSYMREF\n", tbs[ind]);
            printf ("%sName:\t%s\n", tbs[ind], entry->name);
            break;

        case NATIVE:
            printf ("%sNATIVE\n", tbs[ind]);
            printf ("%sCall:\t%p\n", tbs[ind], entry->call);
            break;

        case CUSTOM:
            printf ("%sCUSTOM\n", tbs[ind]);
            printf ("%sName:\t%s\n", tbs[ind], entry->name);
            printf ("%sCall:\t%p\n", tbs[ind], entry->call);
            if(entry->children || 
               entry->symbols)
            {
                entry_p *e = entry->children;
                if(e && *e)
                {
                    printf ("%sChld:", tbs[ind]); 
                    ind++; 
                    while(*e && *e != SENTINEL)
                    {
                        pretty_print(*e); 
                        e++; 
                    }
                    ind--; 
                }
                e = entry->symbols;
                if(e && *e)
                {
                    printf ("%sSyms:", tbs[ind]); 
                    ind++; 
                    while(*e && *e != SENTINEL)
                    {
                        pretty_print(*e); 
                        e++; 
                    }
                    ind--; 
                }
            }

            break;

        case CUSREF:
            printf ("%sCUSREF\n", tbs[ind]);
            printf ("%sName:\t%s\n", tbs[ind], entry->name);
            break;

        case CONTXT:
            printf ("%sCONTXT\n", tbs[ind]); 
            if(entry->children || 
               entry->symbols)
            {
                entry_p *e = entry->children;
                if(e && *e)
                {
                    printf ("%sChld:", tbs[ind]); 
                    ind++; 
                    while(*e && *e != SENTINEL)
                    {
                        pretty_print(*e); 
                        e++; 
                    }
                    ind--; 
                }
                e = entry->symbols;
                if(e && *e)
                {
                    printf ("%sSyms:", tbs[ind]); 
                    ind++; 
                    while(*e && *e != SENTINEL)
                    {
                        pretty_print(*e); 
                        e++; 
                    }
                    ind--; 
                }
            }
            break;

        case STATUS:
            printf ("%sSTATUS\n", tbs[ind]);
            printf ("%sName:\t%s\n", tbs[ind], entry->name);
            printf ("%sId:\t%d\n", tbs[ind], entry->id);
            break;

        case DANGLE:
            printf ("%sDANGLE\n", tbs[ind]);
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

