//------------------------------------------------------------------------------
// resource.c:
//
// Encapsulation of resources that we might want to localize later on.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "error.h"
#include "resource.h"
#ifdef AMIGA
# include <proto/exec.h>
# include <proto/locale.h>
#endif

struct LocaleInfo
{
    APTR li_LocaleBase;
    APTR li_Catalog;
};

static struct LocaleInfo loc;

//------------------------------------------------------------------------------
// Name:        tr
// Description: Get string from string ID.
// Input:       A res_t string ID.
// Return:      The string corresponding to the string ID.
//------------------------------------------------------------------------------
const char *tr(res_t res)
{
    // Fail nicely if we're out of range.
    res_t cur = res > S_GONE ? S_GONE : res;

    // res_t -> string mappings.
    static const char *str[] =
    {
        "NONE",
        /*1*/ "Copying file(s)", /*2*/ "Overwrite existing directory '%s'?",
        /*3*/ "Abort copy '%s' to '%s'.\n", /*4*/ "Could not copy '%s' to '%s'.\n",
        /*5*/ "Delete write protected file '%s'?", /*6*/ "Delete write protected directory '%s'?",
        /*7*/ "Overwrite write protected file '%s'?", /*8*/ "Delete file '%s'?",
        /*9*/ "Deleted '%s'.\n", /*10*/ "No such file '%s'.\n", /*11*/ "Renamed '%s' to '%s'.\n",
        /*12*/ "Copied '%s' to '%s'.\n", /*13*/ "Directory '%s' exists already.\n",
        /*14*/ "Created '%s'.\n", /*15*/ "Get mask '%s' %d\n", /*16*/ "Protect '%s' %d\n",
        /*17*/ "Installer", /*18*/ "Set Installation Mode", /*19*/ "Destination drawer",
        /*20*/ "Copying file", /*21*/ "Files to install", /*22*/ "Installation mode and logging",
        /*23*/ "Progress", /*25*/ "Proceed", /*26*/ "Retry", /*27*/ "Abort", /*27*/ "Yes",
        /*29*/ "No", /*30*/ "Ok", /*31*/ "Next", /*32*/ "Skip", /*32*/ "Back",
        /*34*/ "Unknown error", /*35*/ "Setup failed", /*35*/ "Failed creating MUI custom class",
        /*36*/ "Failed creating MUI application", /*37*/ "Initialization failed", /*39*/ "Error",
        /*40*/ "Success", /*40*/ "Line %d: %s '%s'\n", /*41*/ "Novice User - All Actions Automatic",
        /*42*/ "Intermediate User - Limited Manual Control",
        /*43*/ "Expert User - Must Confirm all actions", /*44*/ "Install for real",
        /*46*/ "Dry run only", /*47*/ "No logging", /*47*/ "Log to file", /*49*/ "Log to printer",
        /*49*/ "installer: required argument missing\n", /*50*/ "%s\n\n%s can be found in %s",
        /*52*/ "Installation complete", /*52*/ "Executed '%s'.\n",
        /*54*/ "Error: Could not open file '%s'\n", /*54*/ "Line %d: %s '%s'\n",
        /*56*/ "Working on installation...\n\n", /*56*/ "Select directory", /*58*/ "Select file",
        /*58*/ "Assign '%s' to '%s'\n", /*60*/ "Remove assign '%s'\n",
        /*60*/ "Could not assign '%s' to '%s'\n", /*61*/ "Could not remove assign '%s'\n",
        /*62*/ "Append '%s' to '%s'\n", /*64*/ "Include '%s' in '%s'\n",
        /*64*/ "Version to install", /*66*/ "Version currently installed", /*66*/ "Unknown version",
        /*68*/ "Destination drawer", /*68*/ "There is no currently installed version",
        /*S_GONE*/ "OUT OF RANGE"
    };

    #if defined(AMIGA) && !defined(LG_TEST)
    if(loc.li_LocaleBase && loc.li_Catalog && cur > S_NONE)
    {
        return GetCatalogStr(loc.li_Catalog, cur - 1, str[cur]);
    }
    #endif

    // Always a valid string.
    return str[cur];
}

//------------------------------------------------------------------------------
// Name:        locale_init
// Description: Initialize and open the catalog.
// Input:       -
// Return:      -
//------------------------------------------------------------------------------
void locale_init(void)
{
    if(!loc.li_LocaleBase)
    {
        #if defined(AMIGA) && !defined(LG_TEST)
        loc.li_LocaleBase = OpenLibrary("locale.library", 37);
        loc.li_Catalog = OpenCatalog(NULL, "Installer.catalog", TAG_DONE);
        #else
        loc.li_LocaleBase = loc.li_Catalog = (APTR) 0;
        #endif
    }
}

//------------------------------------------------------------------------------
// Name:        locale_exit
// Description: Close catalog and free locale resources.
// Input:       -
// Return:      -
//------------------------------------------------------------------------------
void locale_exit(void)
{
    if(loc.li_LocaleBase)
    {
        #if defined(AMIGA) && !defined(LG_TEST)
        CloseCatalog(loc.li_Catalog);
        CloseLibrary(loc.li_LocaleBase);
        #else
        loc.li_LocaleBase = loc.li_Catalog = (APTR) 0;
        #endif
    }
}
