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

int error_ng(int id, 
             error_t type, 
             const char *info)
{
    static int err = 0;
    static const char *des[] =
    {
        "Internal error",
        "Implementation missing",
        "Halt",
        "Reset",
        "Could not read from file", 
        "Could not read directory",
        "Could not write to file",
        "Could not create directory", 
        "Could not rename file",
        "Could not delete file"
        "Not a file",
        "Not a directory",
        "No such file or directory",
        "Division by zero", 
        "Undefined function", 
        "Undefined variable", 
        "Max recursion depth exceeded", 
        "Invalid format string", 
        "Format string type mismatch", 
        "Missing format string arguments", 
        "Unused format string arguments", 
        "No such item", 
        "Missing option",
        "Invalid application name",
    };
    if(id && info)
    {
        err = id; 
        if(id > 0)
        {
            fprintf(stderr, "Line %d: %s '%s'\n", 
                    id, des[type], info);
        }
        else if(id == -2)
        {
            err = 0; 
        }
    }
    return err; 
}
