#include <stdio.h>
#include "error.h"
#include "debug.h"

int did_error(void)
{
    return error(0, NULL, NULL) != 0;
}

int did_halt(void)
{
    return error(0, NULL, NULL) == -1;
}

int error(int id, 
          const char *type, 
          const char *info)
{
    static int err = 0;
    if(id && type && info)
    {
        err = id; 
        if(id > 0)
        {
            fprintf(stderr, "Line %d: %s '%s'\n", 
                    id, type, info);
        }
        else if(id == -2)
        {
            err = 0; 
        }
    }
    return err; 
}

