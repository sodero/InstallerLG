//------------------------------------------------------------------------------
// logic.h:
//
// Logic operations
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef BITWISE_H_
#define BITWISE_H_

#include "types.h"

entry_p n_and(entry_p contxt);
entry_p n_bitand(entry_p contxt);
entry_p n_bitnot(entry_p contxt);
entry_p n_bitor(entry_p contxt);
entry_p n_bitxor(entry_p contxt);
entry_p n_not(entry_p contxt);
entry_p n_in(entry_p contxt);
entry_p n_or(entry_p contxt);
entry_p n_shiftleft(entry_p contxt);
entry_p n_shiftright(entry_p contxt);
entry_p n_xor(entry_p contxt);

#endif
