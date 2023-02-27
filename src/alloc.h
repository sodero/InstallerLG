//------------------------------------------------------------------------------
// alloc.h:
//
// Functions for allocation and management of entry_t data objects.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2023, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef ALLOC_H_
#define ALLOC_H_

#include "types.h"

//------------------------------------------------------------------------------
// Allocation of entry_t types.
//------------------------------------------------------------------------------
entry_p new_contxt(void);
entry_p new_number(int32_t num);
entry_p new_string(char *name);
entry_p new_symbol(char *name);
entry_p new_symref(char *name, int32_t line);
entry_p new_cusref(char *name, int32_t line, entry_p arg);
entry_p new_option(char *name, opt_t type, entry_p chl);
entry_p new_custom(char *name, int32_t line, entry_p sym, entry_p chl);
entry_p new_native(char *name, int32_t line, call_t call, entry_p chl, type_t type);

//------------------------------------------------------------------------------
// Utility functions.
//------------------------------------------------------------------------------
void kill(entry_p entry);
entry_p append(entry_p **dst, entry_p ent);
entry_p merge(entry_p dst, entry_p src);
entry_p push(entry_p dst, entry_p src);
entry_p end(void);

#endif
