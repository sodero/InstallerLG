//------------------------------------------------------------------------------
// error.c:
//
// Functions for setting, getting and communicating errors.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "error.h"
#include "gui.h"
#include "util.h"
#include <stdio.h>

//------------------------------------------------------------------------------
// Name:        error
// Description: Function used to set / get / communicate errors.
// Input:       int line:           Line number.
//              err_t type:         Type of error to set, or ERR_NONE to get
//                                  status.
//              const char *info:   A message describing the problem in a way
//                                  that makes sense to the user.
// Return:      int:                The current state.
//------------------------------------------------------------------------------
int error(entry_p contxt, int line, err_t type, const char *info)
{
    // Last error.
    static err_t last;

    // Get current state?
    if(type == ERR_NONE)
    {
        return last;
    }

    // Clear state or proper error?
    last = type == ERR_RESET ? ERR_NONE : type;

    if(type <= ERR_RESET)
    {
        return last;
    }

    // Show 'real' errors to the user.
    static const char *des[] =
    {
        /*0*/ NULL, /*1*/ "Halt", /*2*/ "Abort", /*3*/ "Reset", /*4*/ "Parse error",
        /*5*/ "Internal error", /*6*/ "Buffer overflow", /*7*/ "Read error",
        /*8*/ "Could not read from file", /*9*/ "Could not read directory",
        /*10*/ "Could not write to file", /*11*/ "Could not create directory",
        /*12*/ "Could not rename file", /*13*/ "Could not delete file",
        /*14*/ "Version not found", /*15*/ "Not a file", /*16*/ "Not a directory",
        /*17*/ "No such file or directory", /*18*/ "Could not get file / dir permissions",
        /*19*/ "Could not set file / dir permissions", /*20*/ "Could not execute command",
        /*21*/ "Could not create / remove assign", /*22*/ "Undefined function",
        /*23*/ "Undefined variable", /*24*/ "Max recursion depth exceeded", /*25*/ "Missing option",
        /*26*/ "Nothing to do", /*27*/ "Division by zero", /*28*/ "Invalid format string",
        /*29*/ "Format string type mismatch", /*30*/ "Missing format string arguments",
        /*31*/ "Unused format string arguments", /*32*/ "No such item",
        /*33*/ "Invalid application name", /*34*/ "Invalid name of volume",
        /*35*/ "Invalid assign", /*36*/ "Options are mutually exclusive", /*37*/ "Invalid value"
    };

    // Dump context if in PANIC.
    if(type == ERR_PANIC)
    {
        dump(contxt);
    }
    // Don't show GUI if in PANIC.
    else
    {
        // Error window / console output.
        gui_error(line, des[type], info);
    }

    // Current state.
    return last;
}
