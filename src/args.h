//------------------------------------------------------------------------------
// args.h:
//
// Functions and data types for handling command line arguments and workbench
// tooltypes.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef ARGS_H_
#define ARGS_H_

#ifdef AMIGA
#include <dos/dos.h>
#endif

#include <stdbool.h>

enum
{
    ARG_SCRIPT = 0,
    ARG_APPNAME,
    ARG_MINUSER,
    ARG_DEFUSER,
    ARG_LANGUAGE,
    ARG_LOGFILE,
    ARG_OLDDIR,
    ARG_SCRIPTDIR,
    ARG_NOLOG,
    ARG_NOPRETEND,
    ARG_NUMBER_OF
};

bool arg_init(int argc, char **argv);
char *arg_get(int ndx);
int arg_argc(int argc);
void arg_done(void);

#endif
