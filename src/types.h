//------------------------------------------------------------------------------
// types.h:
//
// Datatypes and constants used everywhere.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2023, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef TYPES_H_
#define TYPES_H_

#include <stdint.h>

//------------------------------------------------------------------------------
// File / dir type values according to the CBM installer documentation.
//------------------------------------------------------------------------------
#define LG_NONE     0
#define LG_FILE     1
#define LG_DIR      2

//------------------------------------------------------------------------------
// User levels according to the CBM installer documentation.
//------------------------------------------------------------------------------
#define LG_NOVICE   0
#define LG_AVERAGE  1
#define LG_EXPERT   2

//------------------------------------------------------------------------------
// Version return value according to the CBM installer documentation.
//------------------------------------------------------------------------------
#define LG_NOVER    -1

//------------------------------------------------------------------------------
// Default return values.
//------------------------------------------------------------------------------
#define LG_TRUE     1
#define LG_FALSE    0

//------------------------------------------------------------------------------
// Misc constants.
//------------------------------------------------------------------------------
#define LG_VECLEN   4        // Default array size
#define LG_NUMLEN   16       // Max string length of numerical values
#define LG_MAXDEP   32       // Max recursion depth
#define LG_STRLEN   64       // Default string length.

//------------------------------------------------------------------------------
// Data types.
//------------------------------------------------------------------------------
typedef enum
{
    NUMBER,
    STRING,
    SYMBOL,
    SYMREF,
    NATIVE,
    OPTION,
    CUSTOM,
    CUSREF,
    CONTXT,
    DANGLE
} type_t;

//------------------------------------------------------------------------------
// Option types, refer to new_option() and parser/opt.
//------------------------------------------------------------------------------
typedef enum
{
    OPT_ALL,                // 0
    OPT_APPEND,             // 1
    OPT_ASSIGNS,            // 2
    OPT_BACK,               // 3
    OPT_CHOICES,            // 4
    OPT_COMMAND,            // 5
    OPT_COMPRESSION,        // 6
    OPT_CONFIRM,            // 7
    OPT_DEFAULT,            // 8
    OPT_DELOPTS,            // 9
    OPT_DEST,               // 10
    OPT_DISK,               // 11
    OPT_FILES,              // 12
    OPT_FONTS,              // 13
    OPT_GETDEFAULTTOOL,     // 14
    OPT_GETPOSITION,        // 15
    OPT_GETSTACK,           // 16
    OPT_GETTOOLTYPE,        // 17
    OPT_HELP,               // 18
    OPT_INFOS,              // 19
    OPT_INCLUDE,            // 20
    OPT_NEWNAME,            // 21
    OPT_NEWPATH,            // 22
    OPT_NOGAUGE,            // 23
    OPT_NOPOSITION,         // 24
    OPT_NOREQ,              // 25
    OPT_PATTERN,            // 26
    OPT_PROMPT,             // 27
    OPT_QUIET,              // 28
    OPT_RANGE,              // 29
    OPT_SAFE,               // 30
    OPT_SETDEFAULTTOOL,     // 31
    OPT_SETPOSITION,        // 32
    OPT_SETSTACK,           // 33
    OPT_SETTOOLTYPE,        // 34
    OPT_SOURCE,             // 35
    OPT_SWAPCOLORS,         // 36
    OPT_OPTIONAL,           // 37
    OPT_RESIDENT,           // 38
    OPT_OVERRIDE,           // 39
    OPT_IFOPT,              // 40
    OPT_SELOPT,             // 41
    OPT_ASKUSER,            // 42
    OPT_FAIL,               // 43
    OPT_FORCE,              // 44
    OPT_NOFAIL,             // 45
    OPT_OKNODELETE,         // 46
    OPT_UNIX,               // 47
    OPT_INIT,               // 48
    OPT_LAST,               // 49
} opt_t;

//------------------------------------------------------------------------------
// Types used by the parser and all native functions.
//------------------------------------------------------------------------------
typedef struct entry_s * entry_p;
typedef entry_p (*call_t) (entry_p);

struct entry_s
{
    type_t type;            // One of type_t above.
    int32_t id;             // Numerical ID. Refer to new_*.
    char *name;             // String repr. Refer to new_*().
    call_t call;            // NATIVE function.
    entry_p resolved;       // Resolved value. Refer to eval().
    entry_p *children;      // Subordinate native functions.
    entry_p *symbols;       // Variables / user defined functions.
    entry_p parent;         // Self descriptive.
};

typedef struct entry_s entry_t;

#endif
