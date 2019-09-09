//------------------------------------------------------------------------------
// util.h:
//
// Misc utility functions primarily used by the 'native' methods.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef UTIL_H_
#define UTIL_H_

#include "types.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef AMIGA
#include <clib/debug_protos.h>
#endif

//------------------------------------------------------------------------------
// Utility functions.
//------------------------------------------------------------------------------
void ror(entry_p *e);
entry_p local(entry_p e);
entry_p global(entry_p e);
entry_p custom(entry_p e);
entry_p native(entry_p e);
entry_p opt(entry_p c, opt_t t);
bool c_sane(entry_p c, size_t n);
bool s_sane(entry_p c, size_t n);
void dump(entry_p entry);
int get_numvar(entry_p c, char *v);
char *get_strvar(entry_p c, char *v);
char *get_optstr(entry_p c, opt_t t);
char *get_chlstr(entry_p c, bool p);
void set_numvar(entry_p c, char *v, int n);
void set_strvar(entry_p c, char *v, char *n);
char *get_buf(void);
size_t buf_size(void);
void *dbg_alloc(int line, const char *file, const char *func, void *mem);
entry_p native_exists(entry_p contxt, call_t f);
size_t num_children(entry_p *vec);

//------------------------------------------------------------------------------
// Utility macros.
//------------------------------------------------------------------------------
#define D_CUR    contxt->resolved
#define D_NUM    contxt->resolved->id
#define R_CUR    if(contxt) return contxt->resolved; return NULL
#define R_NUM(X) contxt->resolved->id = X; return contxt->resolved
#define R_STR(X) char *r_str = X; if(r_str) {free(contxt->resolved->name);\
                 contxt->resolved->name = r_str;} else { PANIC(contxt);\
                 contxt->resolved->name[0] = '\0'; }; return contxt->resolved
#define R_EST    if(contxt->resolved->name) {contxt->resolved->name[0] = '\0';}\
                 return contxt->resolved
#define C_ARG(X) contxt->children[(X) - 1]
#define C_SYM(X) contxt->symbols[(X) - 1]
#define DBG_ALLOC(M) dbg_alloc(__LINE__, __FILE__, __func__, M)
#ifdef AMIGA
#define DBG_PRINT KPrintF
#else
#define DBG_PRINT printf
#endif
#define HERE DBG_PRINT("%s:%s:%d\n", __FILE__, __func__, __LINE__)
#define THIS(X) DBG_PRINT("%p <- %s:%s:%d\n", X, __FILE__, __func__, __LINE__)
#define C_SANE(N,O) if(!c_sane(contxt, N)) {PANIC(contxt); R_CUR;}\
                    {entry_p op_ = O; if(op_ && opt(O,OPT_INIT) && DID_ERR)\
                    {R_CUR;}}
#define S_SANE(N) if(!s_sane(contxt, N)) {PANIC(contxt); R_CUR;}

#ifdef __AROS__
#define B_TO_CSTR(S) AROS_BSTR_ADDR(S)
#else
#define B_TO_CSTR(S) (*((char *) BADDR(S)) ? (((char *) BADDR(S)) + 1) : ((char *) BADDR(S)))
#endif

#endif
