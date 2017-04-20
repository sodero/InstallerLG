#include <stdio.h>
#include "util.h"

void plain_print (entry_p entry)
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
            printf ("%s\n\t", entry->value.symbol.name);
            plain_print (entry->value.symbol.data);
            break;

        case NATIVE:
            printf ("NATIVE\n"); 
            break;

        case CUSTOM:
            printf ("%s\n", entry->value.custom.name);
            break;

        case CONTXT:
            printf ("CONTXT\n"); 
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
    }
}

