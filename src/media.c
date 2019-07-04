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
#if defined(__MORPHOS__) || defined(__VBCC__)
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

//----------------------------------------------------------------------------
// (closemedia <media>)
//      close media file and remove it from memory.
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//----------------------------------------------------------------------------
entry_p m_closemedia(entry_p contxt)
{
    // We need 1 argument.
    C_SANE(1, NULL);

    // Media identifier.
    int mid = num(C_ARG(1));

    // Invoke GUI to close media.
    R_NUM(gui_closemedia(mid) == G_TRUE ? 1 : 0);
}

//----------------------------------------------------------------------------
// Name:        h_pos
// Description: Get (effect) and (showmedia) position as bitmask.
// Input:       const char *atr:    Attribute name.
// Return:      int:                G_* bitmask.
//----------------------------------------------------------------------------
static int h_pos(const char *atr)
{
    return (strcasestr(atr, "left") ? G_LEFT : 0) |
           (strcasestr(atr, "right") ? G_RIGHT : 0) |
           (strcasestr(atr, "upper") ? G_UPPER : 0) |
           (strcasestr(atr, "lower") ? G_LOWER : 0);
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
    C_SANE(4, NULL);

    // Position and effect.
    char *est = str(C_ARG(2)), *eps = str(C_ARG(1));

    // Colors, type and position.
    int ic1 = num(C_ARG(3)), ic2 = num(C_ARG(4)),
        ief = h_pos(eps) | (strcasecmp(est, "radial") == 0 ? G_RADIAL :
        strcasecmp(est, "horizontal") == 0 ? G_HORIZONTAL : 0);

    // Effect type.
    bool effect = ief & G_EFFECT;

    // Known effect type?
    if(effect)
    {
        // Invalid initial values.
        static int oc1, oc2, oef = G_RADIAL | G_HORIZONTAL;

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
        R_NUM(1);
    }

    // Missing effect type.
    ERR(ERR_VAL_INVALID, est);
    R_NUM(0);
}

//----------------------------------------------------------------------------
// (setmedia <media> <action> [parameter])
//      perform action on datatype
//
// Refer to Installer.guide 1.20 (25.10.1999) 1995-99 by Amiga Inc.
//----------------------------------------------------------------------------
entry_p m_setmedia(entry_p contxt)
{
    // We need atleast 2 arguments.
    C_SANE(2, NULL);

    // Action to perform.
    char *act = str(C_ARG(2));

    // Translate action to command.
    int cmd = strcasecmp(act, "pause") == 0 ? STM_PAUSE :
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

    // Valid action?
    if(cmd)
    {
        // Extra flags.
        char *par = NULL;

        // If the command requires an extra parameter,
        // resolved the next argument, if it exists.
        if((cmd == STM_COMMAND || cmd == STM_LOCATE) &&
            C_ARG(3) && C_ARG(3) != end())
        {
            // Resolve next.
            par = str(C_ARG(3));
        }

        // Media identifier.
        int mid = num(C_ARG(1));

        // Invoke GUI to perform action.
        R_NUM(gui_setmedia(mid, cmd, par) == G_TRUE ? 1 : 0);
    }

    // Invalid action.
    ERR(ERR_VAL_INVALID, act);
    R_NUM(0);
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
    C_SANE(5, NULL);

    // Get size.
    char *att = str(C_ARG(4));

    // Set size bitmask.
    int msk = h_pos(str(C_ARG(3))) | (num(C_ARG(5)) ? G_BORDER : 0) | (
              strcasecmp(att, "small") == 0 ? G_SMALL :
              strcasecmp(att, "small_medium") == 0 ? G_SMALL | G_LESS :
              strcasecmp(att, "small_large") == 0 ? G_SMALL | G_MORE :
              strcasecmp(att, "medium") == 0 ? G_MEDIUM :
              strcasecmp(att, "medium_small") == 0 ? G_MEDIUM | G_LESS :
              strcasecmp(att, "medium_large") == 0 ? G_MEDIUM | G_MORE :
              strcasecmp(att, "large") == 0 ? G_LARGE :
              strcasecmp(att, "large_small") == 0 ? G_LARGE | G_LESS :
              strcasecmp(att, "large_medium") == 0 ? G_LARGE | G_MORE : 0);

    // Get the rest of the flags.
    for(size_t i = 6; C_ARG(i) && C_ARG(i) != end(); i++)
    {
        // Get current flag.
        att = str(C_ARG(i));

        // Translate into bitmask.
        msk |= (strcasecmp(att, "wordwrap") == 0 ? G_WORDWRAP :
                strcasecmp(att, "panel") == 0 ? G_PANEL :
                strcasecmp(att, "play") == 0 ? G_PLAY :
                strcasecmp(att, "repeat") == 0 ? G_REPEAT : 0);
    }

    // Invalid media ID.
    int mid = -1;

    if(gui_showmedia(&mid, str(C_ARG(2)), msk) != G_TRUE)
    {
        // Could not open file.
        R_NUM(0);
    }

    // Symbol destination.
    entry_p dst = global(contxt);

    if(dst)
    {
        char *var = str(C_ARG(1));
        entry_p *sym = contxt->symbols;

        // Symbol exists already?
        while(*sym && *sym != end())
        {
            // If true, update current symbol.
            if(!strcasecmp((*sym)->name, var) &&
               (*sym)->resolved)
            {
                (*sym)->resolved->id = mid;

                // Success.
                R_NUM(1);
            }

            // Next symbol.
            sym++;
        }

        // Create the new media ID.
        entry_p nid = new_number(mid);

        if(nid)
        {
            // Create new symbol with user defined name.
            entry_p nsm = new_symbol(DBG_ALLOC(strdup(var)));

            if(nsm)
            {
                // Reparent value.
                nid->parent = nsm;
                nsm->resolved = nid;

                // Append the symbol to the current
                // context and create a global ref.
                if(append(&contxt->symbols, nsm))
                {
                    // Reparent symbol.
                    push(dst, nsm);
                    nsm->parent = contxt;

                    // Success.
                    R_NUM(1);
                }

                // Out of memory.
                kill(nsm);
            }
            else
            {
                // Out of memory.
                kill(nid);
            }
        }
    }

    // Broken parser / OOM.
    PANIC(contxt);
    R_CUR;
}
