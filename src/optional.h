//------------------------------------------------------------------------------
// optional.h:
//
// Fake option handling
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef OPTIONAL_H_
#define OPTIONAL_H_

#include "types.h"

entry_p n_optional(entry_p contxt);
entry_p n_delopts(entry_p contxt);

entry_p h_optional_get(entry_p contxt, opt_t type);

#endif
