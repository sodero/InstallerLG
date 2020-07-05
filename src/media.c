//------------------------------------------------------------------------------
// media.c:
//
// Multimedia features
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "file.h"
#include "gui.h"
#include "media.h"
#include "util.h"
#include <string.h>
#if defined(__MORPHOS__) || defined(__VBCC__) || defined(__MINGW32__)
char *strcasestr(const char *, const char *);
#endif

#ifdef AMIGA
#include <datatypes/datatypesclass.h>
#else
// From datatypesclass.h 44.1 (17.4.1999)
#define STM_PAUSE          1
#define STM_PLAY           2
#define STM_CONTENTS       3
#define STM_INDEX          4
#define STM_RETRACE        5
#define STM_BROWSE_PREV    6
#define STM_BROWSE_NEXT    7
// Skip unused defines to avoid warnings.
#define STM_COMMAND        11
#define STM_REWIND         12
#define STM_FASTFORWARD    13
#define STM_STOP           14
// Skip unused defines to avoid warnings.
#define STM_LOCATE         16
#endif

//------------------------------------------------------------------------------
// (closemedia <media>)
//      close media file and remove it from memory.
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//------------------------------------------------------------------------------
entry_p n_closemedia(entry_p contxt)
{
    // We need 1 argument.
    C_SANE(1, NULL);

    // Media identifier.
    int32_t mid = num(C_ARG(1));

    // Invoke GUI to close media.
    R_NUM(gui_closemedia(mid) == G_TRUE ? LG_TRUE : LG_FALSE);
}

//------------------------------------------------------------------------------
// Name:        h_pos
// Description: Get (effect) and (showmedia) position as bitmask.
// Input:       const char *atr:    Attribute name.
// Return:      int32_t:            G_* bitmask.
//------------------------------------------------------------------------------
static int32_t h_pos(const char *atr)
{
    return (strcasestr(atr, "left") ? G_LEFT : 0) |
           (strcasestr(atr, "right") ? G_RIGHT : 0) |
           (strcasestr(atr, "upper") ? G_UPPER : 0) |
           (strcasestr(atr, "lower") ? G_LOWER : 0);
}

//------------------------------------------------------------------------------
// (effect <position> <effect> <color 1> <color 2>)
//      open the installer on its own screen
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//------------------------------------------------------------------------------
entry_p n_effect(entry_p contxt)
{
    // We need 4 arguments.
    C_SANE(4, NULL);

    // Position and effect.
    char *est = str(C_ARG(2)), *eps = str(C_ARG(1));

    // Colors, type and position.
    int32_t ic1 = num(C_ARG(4)), ic2 = num(C_ARG(3)),
            ief = h_pos(eps) | (strcasecmp(est, "radial") == 0 ? G_RADIAL :
            strcasecmp(est, "horizontal") == 0 ? G_HORIZONTAL : 0);

    // Effect type.
    bool effect = ief & G_EFFECT;

    if(!effect)
    {
        // Unknown effect type.
        ERR(ERR_VAL_INVALID, est);
        R_NUM(LG_FALSE);
    }

    // Invalid values to enable the first invocation.
    static int32_t oc1, oc2, oef = G_RADIAL | G_HORIZONTAL;

    // Show gradient on the first invocation or if the input has changed.
    if(ief != oef || ic1 != oc1 || ic2 != oc2)
    {
        // Show gradient.
        gui_effect(ief, ic1, ic2);

        // Save current values.
        oef = ief;
        oc1 = ic1;
        oc2 = ic2;
    }

    // Always.
    R_NUM(LG_TRUE);
}

//------------------------------------------------------------------------------
// Name:        h_action
// Description: Get (setmedia) action as bitmask.
// Input:       const char *:   Installer media action string.
// Return:      int32_t:        Datatype action string.
//------------------------------------------------------------------------------
static int32_t h_action(const char *act)
{
    // Translate action to command bitmask.
    return strcasecmp(act, "pause") == 0 ? STM_PAUSE :
           strcasecmp(act, "play") == 0 ? STM_PLAY :
           strcasecmp(act, "contents") == 0 ? STM_CONTENTS :
           strcasecmp(act, "index") == 0 ? STM_INDEX :
           strcasecmp(act, "retrace") == 0 ? STM_RETRACE :
           strcasecmp(act, "browser_prev") == 0 ? STM_BROWSE_PREV :
           strcasecmp(act, "browser_next") == 0 ? STM_BROWSE_NEXT :
           strcasecmp(act, "command") == 0 ? STM_COMMAND :
           strcasecmp(act, "rewind") == 0 ? STM_REWIND :
           strcasecmp(act, "fastforward") == 0 ? STM_FASTFORWARD :
           strcasecmp(act, "stop") == 0 ? STM_STOP :
           strcasecmp(act, "locate") == 0 ? STM_LOCATE : 0;
}

//------------------------------------------------------------------------------
// (setmedia <media> <action> [parameter])
//      perform action on datatype
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//------------------------------------------------------------------------------
entry_p n_setmedia(entry_p contxt)
{
    // We need atleast 2 arguments.
    C_SANE(2, NULL);

    // Action to perform.
    char *act = str(C_ARG(2));
    int32_t cmd = h_action(act);

    if(!cmd)
    {
        // Invalid action.
        ERR(ERR_VAL_INVALID, act);
        R_NUM(LG_FALSE);
    }

    // Extra flags.
    char *par = NULL;

    // If an extra parameter is required, resolve it, if it exists.
    if((cmd == STM_COMMAND || cmd == STM_LOCATE) && exists(C_ARG(3)))
    {
        // Resolve next.
        par = str(C_ARG(3));
    }

    // Media identifier.
    int32_t mid = num(C_ARG(1));

    // Invoke GUI to perform action.
    R_NUM(gui_setmedia(mid, cmd, par) == G_TRUE ? 1 : 0);
}

//------------------------------------------------------------------------------
// Name:        h_create_id
// Description: n_showmedia helper creating a user defined media ID variable.
// Input:       entry_p contxt: Execution context.
//              int32_t mid:    Media ID.
// Return:      int32_t:        LG_TRUE / LG_FALSE.
//------------------------------------------------------------------------------
static int32_t h_create_id(entry_p contxt, int32_t mid)
{
    // First argument is the variable name.
    char *var = str(C_ARG(1));

    // If we already have a symbol with this name, update it.
    for(entry_p *sym = contxt->symbols; exists(*sym); sym++)
    {
        if(!strcasecmp((*sym)->name, var) && (*sym)->resolved)
        {
            (*sym)->resolved->id = mid;
            return LG_TRUE;
        }
    }

    // Create media ID and a symbol with the user defined name.
    entry_p nid = new_number(mid), nsm = new_symbol(DBG_ALLOC(strdup(var)));

    if(nid && nsm)
    {
        // Reparent value.
        nid->parent = nsm;
        nsm->resolved = nid;

        // Append symbol to current context.
        if(append(&contxt->symbols, nsm))
        {
            // Set global reference.
            push(global(contxt), nsm);
            nsm->parent = contxt;
            return LG_TRUE;
        }
    }

    kill(nid);
    kill(nsm);
    return LG_FALSE;
}

//------------------------------------------------------------------------------
// Name:        h_size
// Description: Get (showmedia) size as bitmask.
// Input:       const char *atr:    Attribute name.
// Return:      int32_t:            G_* bitmask.
//------------------------------------------------------------------------------
static int32_t h_size(const char *atr)
{
    return strcasecmp(atr, "small") == 0 ? G_SMALL :
           strcasecmp(atr, "small_medium") == 0 ? G_SMALL | G_LESS :
           strcasecmp(atr, "small_large") == 0 ? G_SMALL | G_MORE :
           strcasecmp(atr, "medium") == 0 ? G_MEDIUM :
           strcasecmp(atr, "medium_small") == 0 ? G_MEDIUM | G_LESS :
           strcasecmp(atr, "medium_large") == 0 ? G_MEDIUM | G_MORE :
           strcasecmp(atr, "large") == 0 ? G_LARGE :
           strcasecmp(atr, "large_small") == 0 ? G_LARGE | G_LESS :
           strcasecmp(atr, "large_medium") == 0 ? G_LARGE | G_MORE : 0;
}

//------------------------------------------------------------------------------
// Name:        h_extra
// Description: Get (showmedia) extra flags as bitmask.
// Input:       const char *atr:    Attribute name.
// Return:      int32_t:            G_* bitmask.
//------------------------------------------------------------------------------
static int32_t h_extra(const char *atr)
{
    return strcasecmp(atr, "wordwrap") == 0 ? G_WORDWRAP :
           strcasecmp(atr, "panel") == 0 ? G_PANEL :
           strcasecmp(atr, "play") == 0 ? G_PLAY :
           strcasecmp(atr, "repeat") == 0 ? G_REPEAT : 0;
}

//------------------------------------------------------------------------------
// (showmedia <medianame> <filename> <position> <size> <borderflag> ...)
//      open datatype and present it to the user.
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//------------------------------------------------------------------------------
entry_p n_showmedia(entry_p contxt)
{
    // We need atleast 5 arguments.
    C_SANE(5, NULL); S_SANE(0);

    // Set size bitmask.
    int32_t msk = h_pos(str(C_ARG(3))) | (num(C_ARG(5)) ? G_BORDER : 0) |
                  h_size(str(C_ARG(4)));

    // Get the rest of the flags.
    for(size_t i = 6; exists(C_ARG(i)); i++)
    {
        // Translate flag to bitmask.
        msk |= h_extra(str(C_ARG(i)));
    }

    // Invalid media ID.
    int32_t mid = -1;

    if(gui_showmedia(&mid, str(C_ARG(2)), msk) != G_TRUE)
    {
        // Could not open file.
        R_NUM(LG_FALSE);
    }

    // Create media ID user variable.
    R_NUM(h_create_id(contxt, mid));
}
