//------------------------------------------------------------------------------
// version.h:
//
// InstallerLG version information
//------------------------------------------------------------------------------
// Copyright (C) 2018-2022, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#ifndef VERSION_H_
#define VERSION_H_

#define MAJOR 44
#define MINOR 10
#define BUILD 1
#define PHASE "FINAL"

#define STY(X) #X
#define VER(X) STY(X)
#if 1
#define VERSION_STRING "\0$VER: InstallerLG " VER(MAJOR) "." VER(MINOR) " " __AMIGADATE__
#else
#define VERSION_STRING "\0$VER: InstallerLG " VER(MAJOR) "." VER(MINOR) " " __AMIGADATE__ " [" PHASE VER(BUILD) "]"
#endif

#endif
