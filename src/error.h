//------------------------------------------------------------------------------
// error.h:
//
// Functions for setting, getting and communicating errors.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef ERROR_H_
#define ERROR_H_

#include "types.h"

//------------------------------------------------------------------------------
// Macros
//------------------------------------------------------------------------------
#define HALT error(NULL, 0, ERR_HALT, __func__)
#define RESET error(NULL, 0, ERR_RESET, __func__)
#define PANIC(C) error((C), __LINE__, ERR_PANIC, __func__)
#define ERR_C(C,T,I) error((C), (C)->id, T, I)
#define ERR(T,I) ERR_C(contxt,T,I)
#define DID_ERR error(NULL, 0, ERR_NONE, NULL)
#define DID_HALT (error(NULL, 0, ERR_NONE, NULL) == ERR_HALT)

//------------------------------------------------------------------------------
// Error types
//------------------------------------------------------------------------------
typedef enum
{
    ERR_NONE = 0,               // 0
    ERR_HALT,                   // 1
    ERR_ABORT,                  // 2
    ERR_RESET,                  // 3
    ERR_PARSE,                  // 4
    ERR_PANIC,                  // 5
    ERR_OVERFLOW,               // 6
    ERR_READ,                   // 7
    ERR_READ_FILE,              // 8
    ERR_READ_DIR,               // 9
    ERR_WRITE_FILE,             // 10
    ERR_WRITE_DIR,              // 11
    ERR_RENAME_FILE,            // 12
    ERR_DELETE_FILE,            // 13
    ERR_NO_VERSION,             // 14
    ERR_NOT_A_FILE,             // 15
    ERR_NOT_A_DIR,              // 16
    ERR_NO_SUCH_FILE_OR_DIR,    // 17
    ERR_GET_PERM,               // 18
    ERR_SET_PERM,               // 19
    ERR_EXEC,                   // 20
    ERR_ASSIGN,                 // 21
    ERR_UNDEF_FNC,              // 22
    ERR_UNDEF_VAR,              // 23
    ERR_MAX_DEPTH,              // 24
    ERR_MISSING_OPTION,         // 25
    ERR_NOTHING_TO_DO,          // 26
    ERR_DIV_BY_ZERO,            // 27
    ERR_FMT_INVALID,            // 28
    ERR_FMT_MISMATCH,           // 29
    ERR_FMT_MISSING,            // 30
    ERR_FMT_UNUSED,             // 31
    ERR_NO_ITEM,                // 32
    ERR_INVALID_APP,            // 33
    ERR_INVALID_VOLUME,         // 34
    ERR_INVALID_ASSIGN,         // 35
    ERR_OPTION_MUTEX,           // 36
    ERR_VAL_INVALID             // 37
} err_t;

//------------------------------------------------------------------------------
// Don't use this function directly, use the macros above instead.
//------------------------------------------------------------------------------
int error(entry_p contxt, int line, err_t type, const char *info);

#endif
