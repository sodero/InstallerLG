//------------------------------------------------------------------------------
// strop.h:
//
// String operations
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef STROP_H_
#define STROP_H_

#include "types.h"

entry_p n_cat(entry_p contxt);
entry_p n_fmt(entry_p contxt);
entry_p n_pathonly(entry_p contxt);
entry_p n_patmatch(entry_p contxt);
entry_p n_strlen(entry_p contxt);
entry_p n_substr(entry_p contxt);
entry_p n_tackon(entry_p contxt);

//------------------------------------------------------------------------------
// Helper functions
//------------------------------------------------------------------------------
char *h_tackon(entry_p contxt, const char *pre, const char *suf);
char *h_pathonly(const char *full);

#endif
