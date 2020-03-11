//------------------------------------------------------------------------------
// error.c:
//
// Functions for setting, getting and communicating errors.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "error.h"
#include "gui.h"
#include "util.h"

//------------------------------------------------------------------------------
// Name:        h_error_str
// Description: Translate error code to a human readable description.
// Input:       err_t type:         Type of error.
// Return:      const char *:       Error description.
//------------------------------------------------------------------------------
static const char *h_error_str(err_t err)
{
    const char *des[] =
    {
        "No error",                              // ERR_NONE
        "Halt",                                  // ERR_HALT
        "Abort",                                 // ERR_ABORT
        "Reset",                                 // ERR_RESET
        "Parse error",                           // ERR_PARSE
        "Internal error",                        // ERR_PANIC
        "Buffer overflow",                       // ERR_OVERFLOW
        "Read error",                            // ERR_READ
        "Could not read from file",              // ERR_READ_FILE
        "Could not read directory",              // ERR_READ_DIR
        "Could not write to file",               // ERR_WRITE_FILE
        "Could not create directory",            // ERR_WRITE_DIR
        "Could not rename file",                 // ERR_RENAME_FILE
        "Could not delete file",                 // ERR_DELETE_FILE
        "Version not found",                     // ERR_NO_VERSION
        "Not a file",                            // ERR_NOT_A_FILE
        "Not a directory",                       // ERR_NOT_A_DIR
        "No such file or directory",             // ERR_NO_SUCH_FILE_OR_DIR
        "Could not get file / dir permissions",  // ERR_GET_PERM
        "Could not set file / dir permissions",  // ERR_SET_PERM
        "Could not execute command",             // ERR_EXEC
        "Could not create / remove assign",      // ERR_ASSIGN
        "Undefined function",                    // ERR_UNDEF_FNC
        "Undefined variable",                    // ERR_UNDEF_VAR
        "Max recursion depth exceeded",          // ERR_MAX_DEPTH
        "Missing option",                        // ERR_MISSING_OPTION
        "Nothing to do",                         // ERR_NOTHING_TO_DO
        "Division by zero",                      // ERR_DIV_BY_ZERO
        "Invalid format string",                 // ERR_FMT_INVALID
        "Format string type mismatch",           // ERR_FMT_MISMATCH
        "Missing format string arguments",       // ERR_FMT_MISSING
        "Unused format string arguments",        // ERR_FMT_UNUSED
        "No such item",                          // ERR_NO_ITEM
        "Invalid application name",              // ERR_INVALID_APP
        "Invalid name of volume",                // ERR_INVALID_VOLUME
        "Invalid assign",                        // ERR_INVALID_ASSIGN
        "Options are mutually exclusive",        // ERR_OPTION_MUTEX
        "Invalid value"                          // ERR_VAL_INVALID
    };

    return des[err < ERR_VAL_INVALID ? err : ERR_VAL_INVALID];
}

//------------------------------------------------------------------------------
// Name:        error
// Description: Function used to set / get / communicate errors.
// Input:       int32_t line:       Line number.
//              err_t type:         Type of error to set, or ERR_NONE to get
//                                  status.
//              const char *info:   A message describing the problem in a way
//                                  that makes sense to the user.
// Return:      err_t:              The current state.
//------------------------------------------------------------------------------
err_t error(entry_p contxt, int32_t line, err_t type, const char *info)
{
    // Last error.
    static err_t last;

    if(type == ERR_NONE)
    {
        // Return current state.
        return last;
    }

    // Clear state or proper error?
    last = (type == ERR_RESET) ? ERR_NONE : type;

    // RESET, ABORT or HALT.
    if(type <= ERR_RESET)
    {
        return last;
    }

    // Dump context if in PANIC.
    if(type == ERR_PANIC)
    {
        dump(contxt);
        return type;
    }

    // Show error in window / console unless trap mode is active.
    if(get_num(contxt, "@trap") == LG_FALSE)
    {
        gui_error(line, h_error_str(type), info);
    }

    return last;
}
