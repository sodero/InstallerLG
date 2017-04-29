#include <stdio.h>
#include "util.h"

void eval_print (entry_p entry)
{
    switch (entry->type)
    {
        case NUMBER:
            printf ("%d\n", entry->value.number);
            break;

        case STRING:
            printf ("%s\n", entry->value.string);
            break;

        case SYMBOL:
            eval_print (entry->value.symbol.data);
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
            printf ("Value:\t%d\n", entry->value.number);
            break;

        case STRING:
            printf ("\tSTRING\n");
            printf ("Value:\t%s\n", entry->value.string);
            break;

        case SYMBOL:
            printf ("\tSYMBOL\n");
            printf ("Name:\t%s", entry->value.symbol.name);
            pretty_print (entry->value.symbol.data);
            break;

        case SYMREF:
            printf ("\tSYMREF\n");
            printf ("Name:\t%s\n", entry->value.symbol.name);
            break;

        case NATIVE:
            printf ("\tNATIVE\n");
            printf ("Call:\t%p\n", entry->value.native.call);
            break;

        case CUSTOM:
            printf ("\tCUSTOM\n");
            printf ("Name:\t%s\n", entry->value.custom.name);
            printf ("Call:\t%p\n", entry->value.custom.call);
            break;

        case CONTXT:
            printf ("\tCONTXT\n"); 
            break;

        case STATUS:
            printf ("\tSTATUS\n");
            printf ("Name:\t%s\n", entry->value.status.name);
            printf ("Value:\t%d\n", entry->value.status.value);
            break;
    }
}

