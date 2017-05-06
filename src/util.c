#include <stdio.h>
#include "util.h"

void eval_print (entry_p entry)
{
    switch (entry->type)
    {
        case NUMBER:
            printf ("%d\n", entry->id);
            break;

        case STRING:
            printf ("%s\n", entry->name);
            break;

        case SYMBOL:
            eval_print (entry->reference);
            break;

        case SYMREF:
        case NATIVE:
        case CUSTOM:
        case CONTXT:
        case STATUS:
            break;
    }
}

void pretty_print (entry_p entry)
{
    printf("\nType:"); 
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

        case CONTXT:
            printf ("\tCONTXT\n"); 
            break;

        case STATUS:
            printf ("\tSTATUS\n");
            printf ("Name:\t%s\n", entry->name);
            printf ("Id:\t%d\n", entry->id);
            break;
    }
}

