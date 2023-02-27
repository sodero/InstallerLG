//------------------------------------------------------------------------------
// prompt.c:
//
// User prompting
//------------------------------------------------------------------------------
// Copyright (C) 2018-2023, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "debug.h"
#include "error.h"
#include "eval.h"
#include "gui.h"
#include "prompt.h"
#include "resource.h"
#include "util.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>

#ifdef AMIGA
#include <dos/dos.h>
#include <dos/dosextens.h>
#include <proto/dos.h>
#include <proto/exec.h>
#endif

//------------------------------------------------------------------------------
// (askbool (prompt..) (help..) (default..) (choices..))
//     0=no, 1=yes
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_askbool(entry_p contxt)
{
    // Arguments are optional.
    C_SANE(0, contxt);

    entry_p prompt   = opt(contxt, OPT_PROMPT),
            help     = opt(contxt, OPT_HELP),
            back     = opt(contxt, OPT_BACK),
            deflt    = opt(contxt, OPT_DEFAULT),
            choices  = opt(contxt, OPT_CHOICES);

    // Do we have both prompt and help text?
    if(!prompt || !help)
    {
        // Missing one or more.
        ERR(ERR_MISSING_OPTION, prompt ? "help" : "prompt");
        R_NUM(LG_FALSE);
    }

    // Default choices are 'yes' and 'no' (or translations thereof).
    const char *yes = tr(S_AYES), *nay = tr(S_NONO);

    // Do we have a choice option?
    if(choices)
    {
        entry_p *ans = choices->children;

        // The CBM installer needs two choices.
        if(ans && exists(ans[0]) && exists(ans[1]))
        {
            yes = str(ans[0]);
            nay = str(ans[1]);
        }
    }

    // Default = 'no'.
    int32_t ans = LG_FALSE;

    // Do we have a user specified default?
    if(deflt)
    {
        ans = num(deflt) ? LG_TRUE : LG_FALSE;
    }

    // Don't show requester in 'novice' mode.
    if(get_num(contxt, "@user-level") == LG_NOVICE)
    {
        // Return default or false.
        R_NUM(ans);
    }

    const char *prt = str(prompt), *hlp = str(help);

    // Only show requester if we could resolve all options.
    if(DID_ERR)
    {
        R_NUM(LG_FALSE);
    }

    // Prompt user.
    inp_t grc = gui_bool(prt, hlp, yes, nay, back != false);

    // Is the back option available?
    if(back)
    {
        // Fake input?
        if(get_num(contxt, "@back"))
        {
            grc = G_ABORT;
        }

        // On abort execute.
        if(grc == G_ABORT)
        {
            return resolve(back);
        }
    }

    // FIXME
    if(grc == G_ABORT || grc == G_EXIT)
    {
        HALT;
    }

    // Translate return code.
    R_NUM((grc == G_TRUE) ? LG_TRUE : LG_FALSE);
}

//------------------------------------------------------------------------------
// (askchoice (prompt..) (choices..) (default..))
//     choose 1 option
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// The installer in OS 3.9 doesn't seem to return a bitmap, which is how it is
// supposed to work according to the Installer.guide, instead it returns a zero
// index. We ignore the guide and mimic the behaviour of the CBM implementation.
//------------------------------------------------------------------------------
entry_p n_askchoice(entry_p contxt)
{
    C_SANE(0, contxt);

    entry_p prompt   = opt(contxt, OPT_PROMPT),
            help     = opt(contxt, OPT_HELP),
            back     = opt(contxt, OPT_BACK),
            choices  = opt(contxt, OPT_CHOICES),
            deflt    = opt(contxt, OPT_DEFAULT);

    // We need something to choose from, a help text and a prompt text.
    if(!prompt || !help || !choices)
    {
        // Missing one or more.
        ERR(ERR_MISSING_OPTION, prompt ? help ? "choices" : "help" : "prompt");
        R_NUM(LG_FALSE);
    }

    // The choice is a 32 bit bitmask, refer to Installer.guide.
    const char *prt = str(prompt), *hlp = str(help), *chs[33] = { NULL };
    int add[32], ndx = 0, off = 0;

    // Pick up a string representation of all the options.
    for(entry_p *entry = choices->children; exists(*entry) && off < 32; entry++)
    {
        // Resolve once.
        char *opn = str(*entry);

        // Save skip deltas. See (1).
        add[ndx] = off - ndx;

        // From the Installer.guide:
        //
        // 1. If you use an empty string as choice descriptor, the choice will
        //    be invisible to the user, i.e. it will not be displayed on screen.
        //    By using variables you can easily set up a programable number of
        //    choices then while retaining the bit numbering.
        if(*opn)
        {
            // 2. Previous versions of Installer did not support proportional
            //    fonts well and some people depended on the non proportional
            //    layout of the display for table like choices. So Installer
            //    will continue to render choices non proportional unless you
            //    start one of the choices with a special escape sequence
            //    `"<ESC>[2p"'. This escape sequence allows proportional
            //    rendering. It is wise to specify this only in the first
            //    choice of the list. Note this well.  (V42)
            if(strlen(opn) > 3 && !memcmp("\x1B[2p", opn, 4))
            {
                // We rely on Zune / MUI for #2. Hide this control sequence if
                // it exists.
                opn += 4;
            }

            // Make sure that the removal of the control sequence hasn't cleared
            // the string.
            if(*opn)
            {
                // Something to show.
                chs[ndx++] = opn;
            }
        }

        // Invisible items are valid as default values, so we need to count
        // these as well.
        off++;
    }

    // Exit if there's nothing to show.
    if(!ndx)
    {
        // Use the default value if such exists.
        R_NUM(deflt ? num(deflt) : 0);
    }

    // Do we have default option?
    if(deflt)
    {
        int32_t def = num(deflt);

        if((def < 0 || def >= off) && get_num(contxt, "@strict"))
        {
            // Out of range.
            ERR(ERR_NO_ITEM, str(deflt));
            R_NUM(LG_FALSE);
        }

        // Use default value.
        ndx = def;
    }
    else
    {
        // No default = 0
        ndx = 0;
    }

    // Don't show requester if we're executing in 'novice' mode.
    if(get_num(contxt, "@user-level") == LG_NOVICE)
    {
        R_NUM(ndx);
    }

    // Only show requester if we could resolve all options.
    if(DID_ERR)
    {
        R_NUM(LG_FALSE);
    }

    // Skipper and result.
    int del = 0, res = 0;

    // Cap / compute skipper.
    if(ndx > 0 && ndx < 31 && ndx - add[ndx - 1] > 0 && ndx + add[ndx - 1] < 31)
    {
        del = add[ndx - 1];
    }

    // Prompt user. Subtract skipper from default.
    inp_t grc = gui_choice(prt, hlp, chs, ndx - del, back != false, &res);

    // Add skipper. Don't trust the GUI.
    res += ((res < 32 && res >= 0) ? add[res] : 0);

    // Is the back option available?
    if(back)
    {
        // Fake input?
        if(get_num(contxt, "@back"))
        {
            grc = G_ABORT;
        }

        // On abort execute.
        if(grc == G_ABORT)
        {
            return resolve(back);
        }
    }

    // FIXME
    if(grc == G_ABORT || grc == G_EXIT)
    {
        HALT;
    }

    R_NUM(res);
}

//------------------------------------------------------------------------------
// (askdir (prompt..) (help..) (default..) (newpath) (disk))
//      ask for directory name
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// We don't support (assigns) and (newpath), or rather, we act as if they are
// always present.
//------------------------------------------------------------------------------
entry_p n_askdir(entry_p contxt)
{
    // Zero or more arguments.
    C_SANE(0, contxt);

    entry_p prompt   = opt(contxt, OPT_PROMPT),
            help     = opt(contxt, OPT_HELP),
            back     = opt(contxt, OPT_BACK),
            deflt    = opt(contxt, OPT_DEFAULT),
            newpath  = opt(contxt, OPT_NEWPATH),
            disk     = opt(contxt, OPT_DISK),
            assigns  = opt(contxt, OPT_ASSIGNS);

    // Are all mandatory options (?) present?
    if(!prompt || !help || !deflt)
    {
        ERR(ERR_MISSING_OPTION, prompt ? help ? "default" : "help" : "prompt");
        return end();
    }

    // Return default value if we're executing in 'novice' mode.
    if(get_num(contxt, "@user-level") == LG_NOVICE)
    {
        R_STR(DBG_ALLOC(strdup(str(deflt))));
    }

    const char *prt = str(prompt), *hlp = str(help), *def = str(deflt), *ret;

    // Could we resolve all options?
    if(DID_ERR)
    {
        return end();
    }

    // Prompt user.
    inp_t grc = gui_askdir(prt, hlp, newpath != false, disk != false,
                           assigns != false, def, back != false, &ret);

    // Is the back option available?
    if(back)
    {
        // Fake input?
        if(get_num(contxt, "@back"))
        {
            grc = G_ABORT;
        }

        // On abort execute.
        if(grc == G_ABORT)
        {
            return resolve(back);
        }
    }

    // FIXME
    if(grc == G_ABORT || grc == G_EXIT)
    {
        HALT;
        R_EST;
    }

    // We have a directory.
    R_STR(DBG_ALLOC(strdup(ret)));
}

//------------------------------------------------------------------------------
// (askdisk (prompt..) (help..) (dest..) (newname..) (assigns))
//     ask user to insert disk
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// Limitations: (disk) and (assigns) aren't supported. Assigns always satisfy
// the request and (disk) is simply ignored.
//------------------------------------------------------------------------------
entry_p n_askdisk(entry_p contxt)
{
    // One or more arguments / options.
    C_SANE(1, contxt);

    entry_p prompt   = opt(contxt, OPT_PROMPT),
            help     = opt(contxt, OPT_HELP),
            back     = opt(contxt, OPT_BACK),
            dest     = opt(contxt, OPT_DEST),
            newname  = opt(contxt, OPT_NEWNAME);

    // Are all mandatory options (?) present?
    if(!prompt || !help || !dest)
    {
        ERR(ERR_MISSING_OPTION, prompt ? help ? "dest" : "help" : "prompt");
        R_NUM(LG_FALSE);
    }

    // Append ':' to turn 'dest' into something we can lock.
    snprintf(buf_get(B_KEY), buf_len(), "%s:", str(dest));

    // Volume names must be > 0 (+ :) characters long.
    if(strlen(buf_get(B_KEY)) < 2)
    {
        ERR(ERR_INVALID_VOLUME, buf_put(B_KEY));
        R_NUM(LG_FALSE);
    }

    // Return code.
    int32_t ret = LG_FALSE;

    #if defined(AMIGA) && !defined(LG_TEST)
    struct Process *p = (struct Process *) FindTask(NULL);

    // Save the current window ptr.
    APTR w = p->pr_WindowPtr;

    // Disable auto request.
    p->pr_WindowPtr = (APTR) -1L;

    // Is this volume present already?
    BPTR vol = (BPTR) Lock(buf_get(B_KEY), ACCESS_READ);

    if(!vol)
    {
        const char *msg = str(prompt), *hlp = str(help),
                   *bt1 = tr(S_RTRY), *bt2 = tr(S_SKIP);

        // Only show requester if we could resolve all options.
        if(NOT_ERR)
        {
            // Retry until we can get a lock or the user aborts.
            while(!vol)
            {
                // Prompt user.
                inp_t grc = gui_bool(msg, hlp, bt1, bt2, back != false);

                if(grc == G_TRUE)
                {
                    vol = (BPTR) Lock(buf_get(B_KEY), ACCESS_READ);
                }
                else
                {
                    // Is the back option available?
                    if(back)
                    {
                        // Fake input?
                        if(get_num(contxt, "@back"))
                        {
                            grc = G_ABORT;
                        }

                        // On abort execute.
                        if(grc == G_ABORT)
                        {
                            // Restore auto request before and unlock buffer
                            // before resolving (back).
                            p->pr_WindowPtr = w;
                            buf_put(B_KEY);
                            return resolve(back);
                        }
                    }
                    // FIXME
                    if(grc == G_ABORT || grc == G_EXIT)
                    {
                        HALT;
                    }

                    // User abort or err.
                    break;
                }
            }
        }
    }

    // Volume not needed anymore.
    buf_put(B_KEY);

    // Did the user abort?
    if(vol)
    {
        // Are we going to create an assign aliasing 'dest'?
        if(newname)
        {
            const char *nn = str(newname);

            // Assigns must be > 0 characters long.
            if(*nn)
            {
                // On success, the lock belongs to
                // the system. Do not UnLock().
                ret = AssignLock(nn, vol) ? LG_TRUE : LG_FALSE;

                // On failure, we need to UnLock() it ourselves.
                if(ret == LG_FALSE)
                {
                    // Could not create 'newname' assign.
                    ERR(ERR_ASSIGN, str(C_ARG(1)));
                    UnLock(vol);
                }
            }
            else
            {
                // An assign must contain at least one character.
                ERR(ERR_INVALID_ASSIGN, nn);
                UnLock(vol);
            }
        }
        else
        {
            // Sucess.
            ret = LG_TRUE;
            UnLock(vol);
        }
    }

    // Restore auto request.
    p->pr_WindowPtr = w;
    #else
    // On non-Amiga systems, or in test mode, we always succeed.
    ret = LG_TRUE;
    OUT("%s%d", buf_put(B_KEY), (newname || back) ? LG_TRUE : LG_FALSE);
    #endif

    // Success or failure.
    R_NUM(ret);
}

//------------------------------------------------------------------------------
// (askfile (prompt..) (help..) (default..) (newpath) (disk))
//     ask for file name
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// The installer in OS 3.9 doesn't seem to recognise (disk) and (newpath). We
// support (disk) but not (newpath), or rather we act as if (newpath) is always
// present.
//------------------------------------------------------------------------------
entry_p n_askfile(entry_p contxt)
{
    // Zero or more arguments.
    C_SANE(0, contxt);

    entry_p prompt   = opt(contxt, OPT_PROMPT),
            help     = opt(contxt, OPT_HELP),
            back     = opt(contxt, OPT_BACK),
            newpath  = opt(contxt, OPT_NEWPATH),
            disk     = opt(contxt, OPT_DISK),
            deflt    = opt(contxt, OPT_DEFAULT);

    // Are all mandatory options (?) present?
    if(!prompt || !help || !deflt)
    {
        ERR(ERR_MISSING_OPTION, prompt ? help ? "default" : "help" : "prompt");
        return end();
    }

    // Return default value if we're executing in 'novice' mode.
    if(get_num(contxt, "@user-level") == LG_NOVICE)
    {
        R_STR(DBG_ALLOC(strdup(str(deflt))));
    }

    const char *prt = str(prompt), *hlp = str(help), *def = str(deflt), *ret;

    // Could we resolve all options?
    if(DID_ERR)
    {
        return end();
    }

    // Prompt user.
    inp_t grc = gui_askfile(prt, hlp, newpath != false, disk != false,
                            def, back != false, &ret);

    // Is the back option available?
    if(back)
    {
        // Fake input?
        if(get_num(contxt, "@back"))
        {
            grc = G_ABORT;
        }

        // On abort execute.
        if(grc == G_ABORT)
        {
            return resolve(back);
        }
    }

    // FIXME
    if(grc == G_ABORT || grc == G_EXIT)
    {
        HALT;
        R_EST;
    }

    // We have a file.
    R_STR(DBG_ALLOC(strdup(ret)));
}

//------------------------------------------------------------------------------
// (asknumber (prompt..) (help..) (range..) (default..))
//     ask for a number
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// NOTE: We do not follow the Installer.guide when it comes to the default
// range. Instead of all positive values, we use 0 - 100 in order to be able to
// use a slider instead of a string gadget. This might be a problem. Scrap it?
//------------------------------------------------------------------------------
entry_p n_asknumber(entry_p contxt)
{
    // Zero or more arguments.
    C_SANE(0, contxt);

    entry_p prompt   = opt(contxt, OPT_PROMPT),
            help     = opt(contxt, OPT_HELP),
            back     = opt(contxt, OPT_BACK),
            range    = opt(contxt, OPT_RANGE),
            deflt    = opt(contxt, OPT_DEFAULT);

    D_NUM = 0;

    // Accept missing default in sloppy mode.
    if(!deflt && get_num(contxt, "@strict") == LG_FALSE)
    {
        deflt = end();
    }

    if(!prompt || !help || !deflt)
    {
        ERR(ERR_MISSING_OPTION, prompt ? help ? "default" : "help" : "prompt");
        R_NUM(LG_FALSE);
    }

    int32_t min = 0, max = 100;

    if(range)
    {
        // Assert a non-broken parser.
        LG_ASSERT(c_sane(range, 2), end());

        min = num(range->children[0]);
        max = num(range->children[1]);

        // Use default range when range is invalid.
        if(min >= max)
        {
            max = 100;
            min = 0;
        }
    }

    int32_t def = num(deflt);

    // Use default value in 'novice' mode.
    if(get_num(contxt, "@user-level") == LG_NOVICE)
    {
        R_NUM(def);
    }

    const char *prt = str(prompt), *hlp = str(help);

    // Bail out on error.
    if(DID_ERR)
    {
        R_NUM(LG_FALSE);
    }

    // Extend range if necessary.
    min = min < def ? min : def;
    max = max > def ? max : def;

    // Prompt user.
    inp_t grc = gui_number(prt, hlp, min, max, def, back != false, &D_NUM);

    // Is the back option available?
    if(back)
    {
        // Fake input?
        if(get_num(contxt, "@back"))
        {
            grc = G_ABORT;
        }

        // On abort execute.
        if(grc == G_ABORT)
        {
            return resolve(back);
        }
    }

    // FIXME
    if(grc == G_ABORT || grc == G_EXIT)
    {
        HALT;
    }

    // Success or failure.
    R_CUR;
}

//------------------------------------------------------------------------------
// (askoptions (prompt (help..) (choices..) default..))
//     choose n options
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_askoptions(entry_p contxt)
{
    // Zero or more arguments.
    C_SANE(0, contxt);

    entry_p prompt   = opt(contxt, OPT_PROMPT),
            help     = opt(contxt, OPT_HELP),
            back     = opt(contxt, OPT_BACK),
            choices  = opt(contxt, OPT_CHOICES),
            deflt    = opt(contxt, OPT_DEFAULT);

    D_NUM = -1;

    // We need everything but a default value.
    if(!prompt || !help || !choices)
    {
        ERR(ERR_MISSING_OPTION, prompt ? help ? "choices" : "help" : "prompt");
        R_NUM(-1);
    }

    // Unless the parser is broken, we will have >= one child.
    entry_p *chl = choices->children;

    // Options are represented by bitmask of 32
    // bits, refer to Install.guide. Thus, we
    // need room for 32 pointers + NULL.
    static const char *chs[33];

    // Choice index.
    int ndx = 0;

    // Pick up a string representation of all the options.
    while(exists(*chl) && ndx < 32)
    {
        char *cur = str(*chl);

        // From the Installer.guide:
        //
        // Previous versions of Installer did not support proportional fonts
        // well and some people depended on the non proportional layout of
        // the display for table like choices.  So Installer will continue to
        // render choices non proportional unless you start one of the
        // choices with a special escape sequence `"<ESC>[2p"'. This escape
        // sequence allows proportional rendering. It is wise to specify this
        // only in the first choice of the list. Note this well.  (V42)
        if(strlen(cur) > 3 && !memcmp("\x1B[2p", cur, 4))
        {
            // We rely on Zune / MUI for #2. Hide
            // this control sequence if it exists.
            cur += 4;
        }

        // Save choice.
        chs[ndx++] = cur;

        // Next option.
        chl++;
    }

    // Exit if there's nothing to show.
    if(!ndx)
    {
        // Use the default value if such exists.
        R_NUM(deflt ? num(deflt) : -1);
    }

    // Terminate array.
    chs[ndx] = NULL;

    // Is there a default option?
    if(deflt)
    {
        // All bits set if symbol is missing.
        deflt = resolve(deflt->children[0]);
        int32_t def = (deflt != end()) ? num(deflt) : -1;

        if((def >= (1L << ndx)) && get_num(contxt, "@strict"))
        {
            // Out of range.
            ERR(ERR_NO_ITEM, str(deflt));
            R_NUM(LG_FALSE);
        }

        // Use default value.
        ndx = def;
    }
    else
    {
        // No default = -1
        ndx = -1;
    }

    // Return default value if we're executing in 'novice' mode.
    if(get_num(contxt, "@user-level") == LG_NOVICE)
    {
        R_NUM(ndx);
    }

    const char *prt = str(prompt), *hlp = str(help);

    // Only show requester if we could resolve all options.
    if(DID_ERR)
    {
        R_NUM(-1);
    }

    // Prompt user.
    inp_t grc = gui_options(prt, hlp, chs, ndx, back != false, &D_NUM);

    // Is the back option available?
    if(back)
    {
        // Fake input?
        if(get_num(contxt, "@back"))
        {
            grc = G_ABORT;
        }

        // On abort execute.
        if(grc == G_ABORT)
        {
            return resolve(back);
        }
    }

    // FIXME
    if(grc == G_ABORT || grc == G_EXIT)
    {
        HALT;
    }

    // Success or failure.
    R_CUR;
}

//------------------------------------------------------------------------------
// (askstring (prompt..) (help..) (default..))
//     ask for a string
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_askstring(entry_p contxt)
{
    // Zero or more arguments.
    C_SANE(0, contxt);

    entry_p prompt   = opt(contxt, OPT_PROMPT),
            help     = opt(contxt, OPT_HELP),
            back     = opt(contxt, OPT_BACK),
            deflt    = opt(contxt, OPT_DEFAULT);

    // Accept missing default in sloppy mode.
    if(!deflt && get_num(contxt, "@strict") == LG_FALSE)
    {
        deflt = end();
    }

    if(!prompt || !help || !deflt)
    {
        ERR(ERR_MISSING_OPTION, prompt ? help ? "default" : "help" : "prompt");
        return end();
    }

    // Return default value if we're executing in 'novice' mode.
    if(get_num(contxt, "@user-level") == LG_NOVICE)
    {
        R_STR(DBG_ALLOC(strdup(str(deflt))));
    }

    const char *prt = str(prompt), *hlp = str(help), *def = str(deflt), *res;

    // Could we resolve all options?
    if(DID_ERR)
    {
        // Return empty string.
        return end();
    }

    // Prompt user.
    inp_t grc = gui_string(prt, hlp, def, back != false, &res);

    // Is the back option available?
    if(back)
    {
        // Fake input?
        if(get_num(contxt, "@back"))
        {
            grc = G_ABORT;
        }

        // On abort execute.
        if(grc == G_ABORT)
        {
            return resolve(back);
        }
    }

    // FIXME
    if(grc == G_ABORT || grc == G_EXIT)
    {
        HALT;
        R_EST;
    }

    // We have a string.
    R_STR(DBG_ALLOC(strdup(res)));
}
