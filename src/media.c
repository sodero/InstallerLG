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
        ief = (strcasestr(eps, "upper") ? G_UPPER : 0) |
              (strcasestr(eps, "lower") ? G_LOWER : 0) |
              (strcasestr(eps, "left") ? G_LEFT : 0) |
              (strcasestr(eps, "right") ? G_RIGHT : 0) |
              (strcasecmp(est, "radial") ? 0 : G_RADIAL) |
              (strcasecmp(est, "horizontal") ? 0 : G_HORIZONTAL);

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
        /*
        From the Installer.guide:

           showmedia opens a datatype (AmigaOS 3.0 is needed) and presents it
        to the user. With the exception of sound and music datatypes a window
        is opened with a given position and size to display the datatype. If
        the datatype cannot be opened 0 is returned, if the datatype is opened
        1 is returned.

           medianame is a string value. The value is used as a name of a
        variable that gets a handle to the datatype. This variable has to be
        used in the other media statements.

           filename is the name of the file to show.

           position is one of the following strings:

        `upper_left'
             The window is placed in the upper left corner of the screen.

        `upper_center'
             The window is horizontally centered in the upper part of the
             screen.

        `upper_right'
             The window is placed in the upper right corner of the screen.

        `center_left'
             The window is  vertically centered on the left side of the screen.

        `center'
             The window is centered on the screen.

        `center_right'
             The window is vertically centered on the right side of the screen.

        `lower_left'
             The window is placed in the lower left corner of the screen.

        `lower_center'
             The window is horizontally centered in the lower part of the
             screen.

        `lower_right'
             The window is placed in the lower right corner of the screen.

           size is on of the following strings:

        `none'
             The window gets its size from the datatype (for example the size
             of the picture).

        `small'
             The window is small.

        `small_medium'
             The window has a small width and a medium height.

        `small_large'
             The window has a small width and a large height.

        `medium_small'
             The window has a medium width and a small height.

        `medium'
             The window is medium sized.

        `medium_large'
             The window has a medium width and a large height.

        `large_small'
             The window has a large width and a small height.

        `large_medium'
             The window has a large width and a medium height.

        `large'
             The window is large.

           If the borderflag is 1 the window gets a border with proprtional
        sliders and arrows and a size gadget (prefered for Amiga guide files
        and text files). If the borderflag is 0 the window gets no border at
        all (prefered for pictures and animations).

           After the bordeflag more strings can follow which sets some
        attributes of the datatype:

        `wordwrap'
             A text is displaed using wordwrapping.

        `panel'
             If the datatype has a control panel it is used (amigaguide and
             animation)

        `play'
             The datatype shall start playing immediatly (animation)

        `repeat'
             The datatype shall repeat playing (seems not to be supported by
             any datatype)
        */

        // Always fail.
        RNUM(0);
    }

    // Broken parser.
    PANIC(contxt);
    RCUR;
}
