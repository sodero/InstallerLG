//------------------------------------------------------------------------------
// probe.h:
//
// Environment information retrieval
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef PROBE_H_
#define PROBE_H_

#include "types.h"

entry_p n_database(entry_p contxt);
entry_p n_earlier(entry_p contxt);
entry_p n_getassign(entry_p contxt);
entry_p n_getdevice(entry_p contxt);
entry_p n_getdiskspace(entry_p contxt);
entry_p n_getenv(entry_p contxt);
entry_p n_getsize(entry_p contxt);
entry_p n_getsum(entry_p contxt);
entry_p n_getversion(entry_p contxt);
entry_p n_iconinfo(entry_p contxt);
entry_p n_querydisplay(entry_p contxt);

int32_t h_getversion_file(const char *name);

#endif
