#include <stdio.h>
#include "error.h"

int runtime_error()
{
    return error(0, NULL, NULL);
}

int error(int id, 
          const char *type, 
          const char *info)
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

