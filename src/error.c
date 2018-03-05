//----------------------------------------------------------------------------
// error.c: 
//
// Functions for setting, getting and communicating errors.
//----------------------------------------------------------------------------

#include "error.h"
#include "gui.h"

#include <stdio.h>

//----------------------------------------------------------------------------
// Name:        did_error(void)
// Description: Function used to determine whether or not we have erred.
// Input:       -
// Return:      int:    '1' if we have erred, '0' otherwise.
//----------------------------------------------------------------------------
int did_error(void)
{
    int err = error(0, ERR_NONE, NULL) != 0 ? 1 : 0; 
    return err; 
}

//----------------------------------------------------------------------------
// Name:        did_halt(void)
// Description: Function used to determine whether or not we should halt.
// Input:       -
// Return:      int:    '1' if we should halt execution, '0' otherwise.
//----------------------------------------------------------------------------
int did_halt(void)
{
    int err = error(0, ERR_NONE, NULL) == -1 ? 1 : 0; 
    return err; 
}

//----------------------------------------------------------------------------
// Name:        error(int id, error_t type, const char *info)
// Description: Function used to set / get / communicate errors.
// Input:       int id:             A numerical identifier aiding debugging. 
//                                  In most cases this will be a line number. 
//              error_t:            Type of error to set, or ERR_NONE to get 
//                                  status.  
//              const char *info:   A message describing the problem in a way
//                                  that makes sense to the user.
// Return:      int:                The current state. 
//----------------------------------------------------------------------------
int error(int id, error_t type, const char *info)
{
    static int err;
    static const char *des[] =
    {
        NULL, 
        "Internal error",
        "Implementation missing",
        "Halt",
        "Reset",
        "Buffer overflow",
        "Abort",
        "Read error", 
        "Could not read from file", 
        "Could not read directory",
        "Could not write to file",
        "Could not create directory", 
        "Could not rename file",
        "Could not delete file",
        "Version string not found",
        "Not a file",
        "Not a directory",
        "No such file or directory",
        "Could not get file / dir permissions",
        "Could not set file / dir permissions",
        "Could not execute command",
        "Could not create / remove assign",
        "Undefined function", 
        "Undefined variable", 
        "Max recursion depth exceeded", 
        "Missing option",
        "Nothing to do",
        "Division by zero", 
        "Invalid format string", 
        "Format string type mismatch", 
        "Missing format string arguments", 
        "Unused format string arguments", 
        "No such item", 
        "Invalid application name",
        "Invalid name of volume",
        "Invalid name of assign"
    };

    // Unless ERR_NONE...
    if(id && type && info)
    {
        // Save the ID for future use by
        // did_error and did_halt..
        err = id; 

        // Real errors have ID:s >= 1 
        if(id > 0)
        {
            // Try to show the error dialog window
            if(!gui_error(id, des[type], info))
            {
                // Fallback to stderr if necessary
                fprintf(stderr, "Line %d: %s '%s'\n", 
                        id, des[type], info);
            }
        }
        // ERR_RESET
        else if(id == -2)
        {
            err = 0; 
        }
    }

    // Used by did_error and did_halt
    return err; 
}
