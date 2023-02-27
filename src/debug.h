//------------------------------------------------------------------------------
// debug.h:
//
// TODO
//------------------------------------------------------------------------------
// Copyright (C) 2018-2023, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef DEBUG_H_
#define DEBUG_H_

#include "types.h"

#if defined(AMIGA) && !defined(LG_TEST)
#include <clib/debug_protos.h>
#define DBG(...) KPrintF("%s:%s:%d>", __FILE__, __func__, __LINE__);\
                 KPrintF((CONST_STRPTR)__VA_ARGS__)
#define OUT(...) KPrintF((CONST_STRPTR)__VA_ARGS__)
#else
#define DBG(...) printf("%s:%s:%d>",__FILE__,__func__,__LINE__);\
                 printf(__VA_ARGS__); fflush(stdout)
#define OUT(...) printf(__VA_ARGS__); fflush(stdout)
#endif

entry_p n_astraw(entry_p contxt);
entry_p n_asbraw(entry_p contxt);
entry_p n_asbeval(entry_p contxt);
entry_p n_eval(entry_p contxt);
entry_p n_options(entry_p contxt);

#endif
