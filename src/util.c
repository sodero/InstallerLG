#include <stdio.h>
#include "util.h"
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
            break;
    }
}

void pretty_print (entry_p entry)
{
    printf("\nType:"); 
    if(!entry)
    {
        printf ("\tNULL\n");
        return; 
    }
    switch (entry->type)
    {
        case NUMBER:
            printf ("\tNUMBER\n");
            printf ("Id:\t%d\n", entry->id);
            break;

        case STRING:
            printf ("\tSTRING\n");
            printf ("Name:\t%s\n", entry->name);
            break;

        case SYMBOL:
            printf ("\tSYMBOL\n");
            printf ("Name:\t%s", entry->name);
            pretty_print (entry->reference);
            break;

        case SYMREF:
            printf ("\tSYMREF\n");
            printf ("Name:\t%s\n", entry->name);
            break;

        case NATIVE:
            printf ("\tNATIVE\n");
            printf ("Call:\t%p\n", entry->call);
            break;

        case CUSTOM:
            printf ("\tCUSTOM\n");
            printf ("Name:\t%s\n", entry->name);
            printf ("Call:\t%p\n", entry->call);
            break;

        case CUSREF:
            printf ("\tCUSREF\n");
            break;

        case CONTXT:
            printf ("\tCONTXT\n"); 
            if(entry->children)
            {
                entry_p *e = entry->children;
                while(*e && *e != SENTINEL)
                {
                    pretty_print(*e); 
                    e++; 
                }
            }
            break;

        case STATUS:
            printf ("\tSTATUS\n");
            printf ("Name:\t%s\n", entry->name);
            printf ("Id:\t%d\n", entry->id);
            break;
    }
}

