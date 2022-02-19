//------------------------------------------------------------------------------
// external.h:
//
// Execution of external scripts / binaries
//------------------------------------------------------------------------------
// Copyright (C) 2018-2022, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef EXTERNAL_H_
#define EXTERNAL_H_

#include "types.h"

entry_p n_execute(entry_p contxt);
entry_p n_rexx(entry_p contxt);
entry_p n_run(entry_p contxt);

#endif
