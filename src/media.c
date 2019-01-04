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
		// Dummy.
		pretty_print(contxt);
    }
    else
    {
        // Broken parser.
        PANIC(contxt);
    }

    // Success, failure or panic.
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
        /*
        From the Installer.guide:

           The effect statement is special because it is interpreted before all
        other commands in the script - independently of its position in the
        script. Its arguments must be literals (string and integer constants)
        and cannot be evaluated.

           If an effect is used Installer opens a new screen that is a clone of
        the default public screen (Workbench screen).

           position sets the position of the installer window and must be one
        of the following strings:

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

           effect sets the graphical effect that is used for the background. It
        is one of the following strings:

        `horizontal'
             A fade from color 1 to color 2 with horizontal lines is drawn

        `radial'
             A fade from color 1 to color 2 with circles around a point in the
             upper right corner of the screen is drawn.

           If the effect cannot be drawn due to the number of colors in the
        screen the effect is replaced with an effect thats uses less colors. The
        radial effect (only possible at true color screens) is replaced with
        the horizontal fade. If the horizontal effect is not displayable it is
        replaced with an animated fade.

           color 1 is an integer and sets the 24 bit RGB value that is used as
        the first color. Typically a hexadecimal number is used.

           color 2 is an integer and sets the 24 bit RGB value that is used as
        the second color. All effects fades from color 1 to color 2.
        */

        char *est = str(CARG(2)),
             *eps = str(CARG(1));

        int ic1 = num(CARG(3)),
            ic2 = num(CARG(4)),

            cef = get_numvar(contxt, "@effect"),
            cc1 = get_numvar(contxt, "@color_1"),
            cc2 = get_numvar(contxt, "@color_2"),

            ief = (strcasestr(eps, "upper") ? 1 << 0 : 0) |
                  (strcasestr(eps, "lower") ? 1 << 1 : 0) |
                  (strcasestr(eps, "left") ? 1 << 2 : 0) |
                  (strcasestr(eps, "right") ? 1 << 3 : 0) |
                  (strcasecmp(est, "radial") ? 0 : 1 << 4) |
                  (strcasecmp(est, "horizontal") ? 0 : 1 << 5);

        if(ief != cef || ic1 != cc1 || ic2 != cc2)
        {
            gui_effect(ief, ic1, ic2);

            set_numvar(contxt, "@effect", ief);
            set_numvar(contxt, "@color_1", ic1);
            set_numvar(contxt, "@color_2", ic2);

            RNUM(1);
        }
    }
    else
    {
        // Broken parser.
        PANIC(contxt);
    }

    // Success, failure or panic.
    RCUR;
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
    if(c_sane(contxt, 2))
    {
        /*
        From the Installer.guide:

           Using the setmedia statement some action can be performed on the
        datatype.

           media is the variable which is set with the showmedia statement.
        action is one of the following strings:

        `pause'
             Pause playing

        `play'
             Start playing

        `contents'
             Show contents

        `index'
             Show index

        `retrace'
             Goto previous visited node.

        `browser_prev'
             Goto previous node.

        `broser_next'
             Goto next node.

        `command'
             Send a command to the datatype. The parameter is the string
             command.

        `rewind'
             Goto beginning

        `fastforward'
             Run forward

        `stop'
             Stop playing

        `locate'
             Locate a position. The parameter is an integer (frame number for
             example).
        */

		// Dummy.
		pretty_print(contxt);
    }
    else
    {
        // Broken parser.
        PANIC(contxt);
    }

    // Success, failure or panic.
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

		// Dummy.
		pretty_print(contxt);
    }
    else
    {
        // Broken parser.
        PANIC(contxt);
    }

    // Success, failure or panic.
    RCUR;
}
