//------------------------------------------------------------------------------
// prompt.h:
//
// User prompting
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef PROMPT_H_
#define PROMPT_H_

#include "types.h"

entry_p n_askbool(entry_p contxt);
entry_p n_askchoice(entry_p contxt);
entry_p n_askdir(entry_p contxt);
entry_p n_askdisk(entry_p contxt);
entry_p n_askfile(entry_p contxt);
entry_p n_asknumber(entry_p contxt);
entry_p n_askoptions(entry_p contxt);
entry_p n_askstring(entry_p contxt);

#endif
