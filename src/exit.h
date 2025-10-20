//------------------------------------------------------------------------------
// exit.h:
//
// Interruption of program execution
//------------------------------------------------------------------------------
// Copyright (C) 2018-2023, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef EXIT_H_
#define EXIT_H_

#include "types.h"

entry_p n_abort(entry_p contxt);
entry_p n_exit(entry_p contxt);
entry_p n_onerror(entry_p contxt);
entry_p n_trap(entry_p contxt);
entry_p n_reboot(entry_p contxt);

#endif
