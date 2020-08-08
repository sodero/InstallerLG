//------------------------------------------------------------------------------
// version.h:
//
// InstallerLG version information
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef VERSION_H_
#define VERSION_H_

#define MAJOR 44
#define MINOR 10
#define BUILD 52
#define PHASE "ALPHA"

#define STY(X) #X
#define VER(X) STY(X)
#define VERSION_STRING "\0$VER: InstallerLG " VER(MAJOR) "." VER(MINOR) " " __AMIGADATE__ " [" PHASE VER(BUILD) "]"

#endif
