//------------------------------------------------------------------------------
// file.h:
//
// File operations
//------------------------------------------------------------------------------
// Copyright (C) 2018-2022, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef FILE_H_
#define FILE_H_

#include "types.h"
#include <stdbool.h>
#include <stdio.h>

entry_p n_copyfiles(entry_p contxt);
entry_p n_copylib(entry_p contxt);
entry_p n_delete(entry_p contxt);
entry_p n_exists(entry_p contxt);
entry_p n_expandpath(entry_p contxt);
entry_p n_fileonly(entry_p contxt);
entry_p n_foreach(entry_p contxt);
entry_p n_makeassign(entry_p contxt);
entry_p n_makedir(entry_p contxt);
entry_p n_protect(entry_p contxt);
entry_p n_startup(entry_p contxt);
entry_p n_textfile(entry_p contxt);
entry_p n_tooltype(entry_p contxt);
entry_p n_transcript(entry_p contxt);
entry_p n_rename(entry_p contxt);

int32_t h_exists(const char *name);
FILE *h_fopen(entry_p contxt, const char *name, const char *mode, bool force);
void h_fclose(FILE **file);
void h_log(entry_p contxt, const char *fmt, ...);
bool h_confirm(entry_p contxt, const char *hlp, const char *msg, ...);

//------------------------------------------------------------------------------
// Exchange (GUI) datatypes
//------------------------------------------------------------------------------
struct pnode_t
{
    struct pnode_t *next;
    char *name;
    char *copy;
    int32_t type;
};

typedef struct pnode_t * pnode_p;

#endif
