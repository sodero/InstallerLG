//----------------------------------------------------------------------------
// media.c:
//
// Multimedia features
//----------------------------------------------------------------------------
// Copyright (C) 2018, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//----------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "file.h"
#include "gui.h"
#include "media.h"
#include "util.h"

#include <string.h>
#ifdef __MORPHOS__
char *strcasestr(const char *, const char *);
#endif

//----------------------------------------------------------------------------
// (closemedia <media>)
//      close media file and remove it from memory.
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//----------------------------------------------------------------------------
entry_p m_closemedia(entry_p contxt)
{
    // We need 1 argument.
    if(c_sane(contxt, 1))
    {
        char *mda = str(CARG(1));

        RNUM
        (
            gui_closemedia(mda) == G_TRUE ? 1 : 0
        );
    }

    // Broken parser.
    PANIC(contxt);
    RCUR;
}

//----------------------------------------------------------------------------
// Name:        h_msk
// Description: Get (effect) and (showmedia) attributes as bitmask.
// Input:       const char *atr:    Attribute name.
// Return:      int:                G_* bitmask.
//----------------------------------------------------------------------------
static int h_msk(const char *atr)
{
    // Bitmask.
    int msk = 0;

    // (effect) only attributes.
    struct { int val; char *str; } eff[] =
    {
        { G_HORIZONTAL, "horizontal" },
        { G_RADIAL, "radial" },
        { 0, NULL }
    };

    // (effect) and (showmedia) position.
    struct { int val; char *str; } pos[] =
    {
        { G_UPPER, "upper" },
        { G_LOWER, "lower" },
        { G_LEFT, "left" },
        { G_RIGHT, "right" },
        { 0, NULL }
    };

    // (showmedia) size and misc.
    struct { int val; char *str; } sze[] =
    {
        { G_SMALL, "small" },
        { G_SMALL | G_LESS, "small_medium" },
        { G_SMALL | G_MORE, "small_large" },
        { G_MEDIUM, "medium" },
        { G_MEDIUM | G_LESS, "medium_small" },
        { G_MEDIUM | G_MORE, "medium_large" },
        { G_LARGE, "large" },
        { G_LARGE | G_LESS, "large_small" },
        { G_LARGE | G_MORE, "large_medium" },
        { G_BORDER, "border" },
        { G_WORDWRAP, "wordwrap" },
        { G_PANEL, "panel" },
        { G_PLAY, "play" },
        { G_REPEAT, "repeat" },
        { 0, NULL }
    };

    // Find (effect/showmedia) position.
    for(size_t i = 0; pos[i].val; i++)
    {
        // Look for substring, we're
        // being cheap and sloppy here.
        if(strcasestr(atr, pos[i].str))
        {
            // Add bit to mask.
            msk |= pos[i].val;
        }
    }

    // Look for (effect) type.
    for(size_t i = 0; eff[i].val; i++)
    {
        // If we find an (effect)
        // attribute, we're done. 
        if(!strcasecmp(atr, eff[i].str))
        {
            // Add bit to mask and
            // return immidiately.
            msk |= eff[i].val;
            return msk;
        }
    }
    
    // Look for (showmedia) size.
    for(size_t i = 0; sze[i].val; i++)
    {
        // We can't be cheap and sloppy
        // due to the positioning combo.
        if(!strcasecmp(atr, sze[i].str))
        {
            // Add bit to mask.
            msk |= sze[i].val;
            break;
        }
    }

    // Done.
    return msk;
}

//----------------------------------------------------------------------------
// (effect <position> <effect> <color 1> <color 2>)
//      open the installer on its own screen
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//----------------------------------------------------------------------------
entry_p m_effect(entry_p contxt)
{
    // We need 4 arguments.
    if(c_sane(contxt, 4))
    {
        // Position and type.
        char *est = str(CARG(2)),
             *eps = str(CARG(1));

        // Gradient color values.
        int ic1 = num(CARG(3)),
            ic2 = num(CARG(4)),

        // Translate type and position.
        ief = h_msk(eps) | h_msk(est);

        // Invalid initial values.
        static int oc1, oc2, oef = G_RADIAL|G_HORIZONTAL;

        // Known effect type?
        if(ief & G_EFFECT)
        {
            // Only show something if this is the first
            // invocation or if the input has changed.
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
            RNUM(1);
        }

        // Missing effect type.
        ERR(ERR_VAL_INVALID, est);
        RNUM(0);
    }

    // Broken parser.
    PANIC(contxt);
    RCUR;
}

// From datatypesclass.h 44.1 (17.4.1999)
#ifdef AMIGA
#include <datatypes/datatypesclass.h>
#else
#define STM_PAUSE          1
#define STM_PLAY           2
#define STM_CONTENTS       3
#define STM_INDEX          4
#define STM_RETRACE        5
#define STM_BROWSE_PREV    6
#define STM_BROWSE_NEXT    7
#define STM_NEXT_FIELD     8
#define STM_PREV_FIELD     9
#define STM_ACTIVATE_FIELD 10
#define STM_COMMAND        11
#define STM_REWIND         12
#define STM_FASTFORWARD    13
#define STM_STOP           14
#define STM_RESUME         15
#define STM_LOCATE         16
#endif

//----------------------------------------------------------------------------
// (setmedia <media> <action> [parameter])
//      perform action on datatype
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//----------------------------------------------------------------------------
entry_p m_setmedia(entry_p contxt)
{
    // We need atleast 2 arguments.
    if(c_sane(contxt, 2))
    {
        // All supported commands.
        struct { int val; char *str; } all[] =
        {
            { STM_PAUSE, "pause" },
            { STM_PLAY, "play" },
            { STM_CONTENTS, "contents" },
            { STM_INDEX, "index" },
            { STM_RETRACE, "retrace" },
            { STM_BROWSE_PREV, "browser_prev" },
            { STM_BROWSE_NEXT, "browser_next" },
            { STM_COMMAND, "command" },
            { STM_REWIND, "rewind" },
            { STM_FASTFORWARD, "fastforward" },
            { STM_STOP, "stop" },
            { STM_LOCATE, "locate" },
            { 0, NULL }
        };

        // The action to perform.
        char *act = str(CARG(2));

        // Iterate over suported actions.
        for(size_t i = 0; all[i].val; i++)
        {
            // Is the current supported action
            // equal the input action?
            if(!strcasecmp(act, all[i].str))
            {
                // Extra info.
                char *par = NULL;

                // Media identifier.
                int mid = num(CARG(1));

                // The 'command' and 'locate' actions
                // need an additional parameter.
                if(CARG(3) && CARG(3) != end() &&
                  (all[i].val == STM_COMMAND ||
                   all[i].val == STM_LOCATE))
                {
                    // Resolve extra info.
                    par = str(CARG(3));
                }

                RNUM
                (
                    // Invoke GUI to perform action.
                    gui_setmedia(mid, all[i].val, par)
                    == G_TRUE ? 1 : 0
                );
            }
        }

        // Invalid action.
        ERR(ERR_VAL_INVALID, act);
        RNUM(0);
    }

    // Broken parser.
    PANIC(contxt);
    RCUR;
}

//----------------------------------------------------------------------------
// (showmedia <medianame> <filename> <position> <size> <borderflag> ...)
//      open datatype and present it to the user.
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//----------------------------------------------------------------------------
entry_p m_showmedia(entry_p contxt)
{
    // We need atleast 5 arguments.
    if(c_sane(contxt, 5))
    {
        // Translate type and position.
        int mid = 0;

        gui_showmedia(&mid, "dummy", 0);

        // Always.
        RNUM(1);
    }

    // Broken parser.
    PANIC(contxt);
    RCUR;
}
