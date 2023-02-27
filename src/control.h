//------------------------------------------------------------------------------
// control.h:
//
// Control structures
//------------------------------------------------------------------------------
// Copyright (C) 2018-2023, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef CONTROL_H_
#define CONTROL_H_

#include "types.h"

entry_p n_if(entry_p contxt);
entry_p n_select(entry_p contxt);
entry_p n_until(entry_p contxt);
entry_p n_while(entry_p contxt);
entry_p n_trace(entry_p contxt);
entry_p n_retrace(entry_p contxt);

#endif
