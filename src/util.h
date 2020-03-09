//------------------------------------------------------------------------------
// util.h:
//
// Misc utility functions.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved
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
void ror(entry_p *entry);
entry_p local(entry_p entry);
entry_p global(entry_p entry);
entry_p custom(entry_p entry);
entry_p native(entry_p entry);
entry_p opt(entry_p contxt, opt_t type);
entry_p con(entry_p contxt);
bool c_sane(entry_p contxt, size_t num);
bool s_sane(entry_p contxt, size_t num);
void dump(entry_p entry);
int32_t get_num(entry_p contxt, char *var);
char *get_str(entry_p contxt, char *var);
char *get_optstr(entry_p contxt, opt_t type);
char *get_chlstr(entry_p contxt, bool pad);
void set_num(entry_p contxt, char *var, int32_t val);
void set_str(entry_p contxt, char *var, char *val);
char *buf_get(const char *usr);
char *buf_put(const char *usr);
size_t buf_len(void);
char *buf_raw(void);
void *dbg_alloc(int32_t line, const char *file, const char *func, void *mem);
entry_p native_exists(entry_p contxt, call_t func);
size_t num_children(entry_p *vec);
bool exists(entry_p entry);
int32_t str_to_userlevel(const char *user, int32_t def);

//------------------------------------------------------------------------------
// Utility macros.
//------------------------------------------------------------------------------
#define D_NUM    contxt->resolved->id
#define R_CUR    return contxt ? contxt->resolved : NULL
#define R_NUM(X) contxt->resolved->id = X; return contxt->resolved
#define R_STR(X) char *r_str = X; if(r_str) {free(contxt->resolved->name);\
                 contxt->resolved->name = r_str;} else { PANIC(contxt);\
                 contxt->resolved->name[0] = '\0'; }; return contxt->resolved
#define C_ARG(X) contxt->children[(X) - 1]
#define C_SYM(X) contxt->symbols[(X) - 1]
#define B_KEY __func__
#define DBG_ALLOC(M) dbg_alloc(__LINE__, __FILE__, __func__, M)
#if defined(AMIGA)
#define DBG_PRINT KPrintF
#else
#define DBG_PRINT printf
#endif
#define HERE DBG_PRINT("%s:%s:%d\n", __FILE__, __func__, __LINE__)
#define THIS(X) DBG_PRINT("%p <- %s:%s:%d\n", X, __FILE__, __func__, __LINE__)
#ifndef __clang_analyzer__
#define C_SANE(N,O) if(!c_sane(contxt, N)) {PANIC(contxt); return end();}\
                    {entry_p op_ = O; if(op_ != NULL && opt(O,OPT_INIT) != NULL && DID_ERR)\
                    {return end();}}
#else
#define C_SANE(N,O)
#endif
#define S_SANE(N) if(!s_sane(contxt, N)) {PANIC(contxt); return end();}
#ifdef __AROS__
#define B2CSTR(S) AROS_BSTR_ADDR(S)
#else
#define B2CSTR(S) (*((char *) BADDR(S)) ? (((char *) BADDR(S)) + 1) : ((char *) BADDR(S)))
#endif
#endif
