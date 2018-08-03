//----------------------------------------------------------------------------
// prompt.c: 
//
// User prompting
//----------------------------------------------------------------------------
// Copyright (C) 2018, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//----------------------------------------------------------------------------

#include "alloc.h"
#include "gui.h"
#include "error.h"
#include "eval.h"
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

//----------------------------------------------------------------------------
// (askbool (prompt..) (help..) (default..) (choices..))
//     0=no, 1=yes
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_askbool(entry_p contxt)
{
    if(contxt)
    {
        const char *yes = tr(S_AYES), *no = tr(S_NONO); 
        entry_p prompt   = get_opt_va(OPT_PROMPT, contxt, NULL),
                help     = get_opt_va(OPT_HELP, contxt, NULL),
                deflt    = get_opt_va(OPT_DEFAULT, contxt, NULL),
                choices  = get_opt_va(OPT_CHOICES, contxt, NULL);

        // Default = 'no'.
        DNUM = 0; 

        if(prompt && help)
        {
            // Do we have a choice option?
            if(choices)
            {
                // Unless the parser is broken, 
                // we will have >= one child. 
                entry_p *e = choices->children;

                // Pick up whatever we can, use the default
                // value if we only have a single choice.
                yes = *e && *e != end() ? str(*e) : yes; 
                no = *(++e) && *e != end() ? str(*e) : no; 
            }

            // Do we have a user specified default?
            if(deflt)
            {
                DNUM = num(deflt); 
            }

            // Show requester unless we're executing in
            // 'novice' mode.
            if(get_numvar(contxt, "@user-level") > 0)
            {
                const char *p = str(prompt),
                           *h = str(help);

                // Only show requester if we could
                // resolve all options.
                if(!DID_ERR())
                {
                    // Prompt user.
                    DNUM = gui_bool(p, h, yes, no);
                }
            }
        }
        else
        {
            char *m = !prompt ? "prompt" : "help";
            ERR(ERR_MISSING_OPTION, m);
        }
    }
    else
    {
        // The parser is broken
        PANIC(contxt); 
    }

    // Success, failure or
    // broken parser. 
    RCUR; 
}

//----------------------------------------------------------------------------
// (askchoice (prompt..) (choices..) (default..))
//     choose 1 options
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// The installer in OS 3.9 doesn't seem to return a bitmap, which 
// is how it is supposed to work according to the Installer.guide, 
// instead it returns a zero index. We choose to ignore the guide
// and mimic the behaviour of the implementation in 3.9.
//----------------------------------------------------------------------------
entry_p m_askchoice(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt_va(OPT_PROMPT, contxt, NULL),
                help     = get_opt_va(OPT_HELP, contxt, NULL),
                choices  = get_opt_va(OPT_CHOICES, contxt, NULL),
                deflt    = get_opt_va(OPT_DEFAULT, contxt, NULL);

        DNUM = 0; 

        // Are all mandatory options (!?) present?
        if(prompt && help && choices)
        {
            // Unless the parser is broken, 
            // we will have >= one child. 
            entry_p *e = choices->children;

            // The choice is represented by a bitmask of
            // 32 bits, refer to Install.guide. Thus, we
            // need room for 32 pointers + NULL.
            static const char *chs[33]; 

            // Index
            int i = 0; 

            // Pick up a string representation of all
            // the options.
            while(*e && *e != end())
            {
                char *cur = str(*e);

                // Filter out any empty strings. 
                // Refer to Install.guide. 
                if(strlen(cur))
                {
                    chs[i++] = cur; 
                }

                // Next option.
                e++; 
            }

            // Terminate array. 
            chs[i] = NULL; 

            // Do we have default option?
            if(deflt)
            {
                // Is there such a choice? 
                int d = num(deflt);

                // Check for negative values
                // as well.
                if(d < 0 || d >= i)
                {
                    // Nope, out of range.
                    ERR(ERR_NO_ITEM, str(deflt)); 
                    RNUM(0); 
                }

                // Yes, use the default
                // value given.
                i = d; 
            }
            else
            {
                // No default = 0 
                i = 0; 
            }

            // Show requester unless we're executing in
            // 'novice' mode.
            if(get_numvar(contxt, "@user-level") > 0)
            {
                const char *p = str(prompt),
                           *h = str(help);

                // Only show requester if we could
                // resolve all options.
                if(!DID_ERR())
                {
                    int hlt = 0; 

                    // Prompt user.
                    DNUM = gui_choice(p, h, chs, i, &hlt); 

                    // Halt if abort.
                    if(hlt)
                    {
                        HALT(); 
                    }
                }
            }
            else
            {
                DNUM = i;
            }
        }
        else
        {
            char *m = !prompt ? "prompt" : !help ? "help" : "choices";
            ERR(ERR_MISSING_OPTION, m);
        }
    }
    else
    {
        // The parser is broken
        PANIC(contxt); 
    }

    // Success, failure or
    // broken parser. 
    RCUR; 
}

//----------------------------------------------------------------------------
// (askdir (prompt..) (help..) (default..) (newpath) (disk))
//      ask for directory name
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// We don't support (assigns) and (newpath), or rather, we act 
// as if they are always present. 
//----------------------------------------------------------------------------
entry_p m_askdir(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt_va(OPT_PROMPT, contxt, NULL),
                help     = get_opt_va(OPT_HELP, contxt, NULL),
                deflt    = get_opt_va(OPT_DEFAULT, contxt, NULL),
                newpath  = get_opt_va(OPT_NEWPATH, contxt, NULL),
                disk     = get_opt_va(OPT_DISK, contxt, NULL),
                assigns  = get_opt_va(OPT_ASSIGNS, contxt, NULL);

        // Are all mandatory options (!?) present?
        if(prompt && help && deflt)
        {
            const char *ret;

            // Show requeter unless we're executing in
            // 'novice' mode.
            if(get_numvar(contxt, "@user-level") > 0)
            {
                const char *p = str(prompt),
                           *h = str(help),
                           *d = str(deflt);

                // Only show requester if we could
                // resolve all options.
                if(!DID_ERR())
                {
                    int np = newpath ? 1 : 0,
                        dk = disk ? 1 : 0,
                        as = assigns ? 1 : 0;

                    // Prompt user.
                    ret = gui_askdir(p, h, np, dk, as, d); 

                    // Return empty string and
                    // halt if user aborted.
                    if(!ret)
                    {
                        HALT(); 
                        REST; 
                    }
                }
                else
                {
                    // Could not resolve one
                    // or more options.
                    REST;
                }
            }
            else
            {
                // We're executing in 'novice' mode, 
                // use the default value. 
                ret = str(deflt); 
            }

            // We have a file.
            RSTR(strdup(ret)); 
        }
        else
        {
            char *m = !prompt ? "prompt" : !help ? "help" : "default";
            ERR(ERR_MISSING_OPTION, m);
        }

        // Return empty string
        // on failure.
        REST;
    }
    else
    {
        // Broken parser.
        PANIC(contxt); 
        RCUR;
    }
}

//----------------------------------------------------------------------------
// (askdisk (prompt..) (help..) (dest..) (newname..) (assigns))
//     ask user to insert disk
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// Limitations: (disk) and (assigns) aren't supported. Assigns 
// always satisfy the request and (disk) is simply ignored. 
//
//----------------------------------------------------------------------------
entry_p m_askdisk(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt_va(OPT_PROMPT, contxt, NULL),
                help     = get_opt_va(OPT_HELP, contxt, NULL),
                dest     = get_opt_va(OPT_DEST, contxt, NULL),
                newname  = get_opt_va(OPT_NEWNAME, contxt, NULL); 

        DNUM = 0; 

        // Are all mandatory options (!?) present?
        if(prompt && help && dest)
        {
            char n[PATH_MAX]; 

            // Append ':' to turn 'dest' into something
            // we can 'Lock'.
            snprintf(n, PATH_MAX, "%s:", str(dest)); 

            // Volume names must be > 0 characters long.
            if(strlen(n) > 1)
            {
                #ifdef AMIGA
                struct Process *p = (struct Process *) 
                    FindTask(NULL);

                // Save the current window ptr. 
                APTR w = p->pr_WindowPtr;

                // Disable auto request. 
                p->pr_WindowPtr = (APTR) -1L; 

                // Is this volume present already? 
                BPTR l = (BPTR) Lock(n, ACCESS_READ);
                if(!l)
                {
                    const char *msg = str(prompt), 
                               *hlp = str(help),
                               *bt1 = tr(S_RTRY),
                               *bt2 = tr(S_ABRT); 

                    // Only show requester if we could
                    // resolve all options.
                    if(!DID_ERR())
                    {
                        // Retry until we can get a lock or the
                        // user aborts. 
                        while(!l)
                        {
                            // Probe user, retry or abort?  
                            if(gui_bool(msg, hlp, bt1, bt2))
                            {
                                l = (BPTR) Lock(n, ACCESS_READ);
                            }
                            else
                            {
                                // User abort. 
                                break; 
                            }
                        }
                    }
                }

                // Did the user abort? 
                if(l)
                {
                    // Are we going to create an assign
                    // aliasing 'dest'? 
                    if(newname)
                    {
                        const char *nn = str(newname); 

                        // Assigns must be > 0 characters long.
                        if(strlen(nn))
                        {
                            // On success, the lock belongs to 
                            // the system. Do not UnLock().
                            DNUM = AssignLock(nn, l) ? 1 : 0; 

                            // On failure, we need to UnLock()
                            // it ourselves. 
                            if(!DNUM)
                            {
                                // Could not create 'newname' assign. 
                                ERR(ERR_ASSIGN, str(CARG(1))); 
                                UnLock(l); 
                            }
                        }
                        else
                        {
                            // An assign must contain at least one character. 
                            ERR(ERR_INVALID_ASSIGN, nn); 
                            UnLock(l); 
                        }
                    }
                    else
                    {
                        // Sucess. 
                        DNUM = 1; 
                        UnLock(l); 
                    }
                }

                // Restore auto request. 
                p->pr_WindowPtr = w; 
                #else
                // On non-Amiga systems we always succeed.
                DNUM = 1; 

                // For testing purposes only.
                printf("%d", newname ? 1 : 0);
                #endif
            }
            else
            {
                // A volume name must contain at
                // least one character. 
                ERR(ERR_INVALID_VOLUME, n); 
            }
        }
        else
        {
            char *m = !prompt ? "prompt" : !help ? "help" : "dest";
            ERR(ERR_MISSING_OPTION, m);
        }
    }
    else
    {
        // The parser is broken
        PANIC(contxt); 
    }

    // Success, failure or
    // broken parser. 
    RCUR; 
}

//----------------------------------------------------------------------------
// (askfile (prompt..) (help..) (default..) (newpath) (disk))
//     ask for file name
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// The installer in OS 3.9 doesn't seem to recognise (disk) and 
// (newpath). We support (disk) but not (newpath), or rather we 
// act as if (newpath) is always present. 
//----------------------------------------------------------------------------
entry_p m_askfile(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt_va(OPT_PROMPT, contxt, NULL),
                help     = get_opt_va(OPT_HELP, contxt, NULL),
                newpath  = get_opt_va(OPT_NEWPATH, contxt, NULL),
                disk     = get_opt_va(OPT_DISK, contxt, NULL),
                deflt    = get_opt_va(OPT_DEFAULT, contxt, NULL);

        // Are all mandatory options (!?) present?
        if(prompt && help && deflt)
        {
            const char *ret;

            // Show file dialog unless we're executing
            // in 'novice' mode.
            if(get_numvar(contxt, "@user-level") > 0)
            {
                const char *p = str(prompt),
                           *h = str(help),
                           *d = str(deflt);

                // Only show requester if we could
                // resolve all options.
                if(!DID_ERR())
                {
                    int np = newpath ? 1 : 0,
                        dk = disk ? 1 : 0;

                    // Prompt user.
                    ret = gui_askfile(p, h, np, dk, d); 

                    // Return empty string and
                    // halt if user aborted.
                    if(!ret)
                    {
                        HALT(); 
                        REST; 
                    }
                }
                else
                {
                    // Could not resolve one
                    // or more options.
                    REST;
                }
            }
            else
            {
                // We're executing in 'novice' mode, 
                // use the default value. 
                ret = str(deflt); 
            }

            // We have a file.
            RSTR(strdup(ret)); 
        }
        else
        {
            char *m = !prompt ? "prompt" : !help ? "help" : "default";
            ERR(ERR_MISSING_OPTION, m);
        }

        // Return empty string
        // on failure.
        REST;
    }
    else
    {
        // Broken parser.
        PANIC(contxt); 
        RCUR;
    }
}

//----------------------------------------------------------------------------
// (asknumber (prompt..) (help..) (range..) (default..))
//     ask for a number
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
// NOTE: We do not follow the Installer.guide when it comes to the default
// range. Instead of all positive values, we use 0 - 100 in order to be
// able to use a slider instead of a string gadget. This might be a problem.
// Scrap it?
//----------------------------------------------------------------------------
entry_p m_asknumber(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt_va(OPT_PROMPT, contxt, NULL),
                help     = get_opt_va(OPT_HELP, contxt, NULL),
                range    = get_opt_va(OPT_RANGE, contxt, NULL),
                deflt    = get_opt_va(OPT_DEFAULT, contxt, NULL);

        DNUM = 0;

        if(prompt && help && deflt)
        {
            // Default range. 
            int min = 0, max = 100; 

            if(range)
            {
                if(c_sane(range, 2))
                {
                    min = num(range->children[0]);
                    max = num(range->children[1]);

                    // Use default range when the
                    // user given range is invalid. 
                    if(min >= max)
                    {
                        max = 100; 
                        min = 0; 
                    }
                }
                else
                {
                    // The parser is broken
                    PANIC(contxt); 
                    RCUR; 
                }
            }

            // Show requester unless we're executing in
            // 'novice' mode.
            if(get_numvar(contxt, "@user-level") > 0)
            {
                int d = num(deflt);
                const char *p = str(prompt),
                           *h = str(help);

                // Only show requester if we could
                // resolve all options.
                if(!DID_ERR())
                {
                    int hlt = 0; 

                    // Prompt user.
                    DNUM = gui_number(p, h, min, max, d, &hlt);

                    // Halt if abort.
                    if(hlt)
                    {
                        HALT(); 
                    }
                }
            }
            else
            {
                // Use the default value. 
                DNUM = num(deflt);
            }
        }
        else
        {
            char *m = !prompt ? "prompt" : !help ? "help" : "default";
            ERR(ERR_MISSING_OPTION, m);
        }
    }
    else
    {
        // The parser is broken
        PANIC(contxt); 
    }

    // Success, failure or
    // broken parser. 
    RCUR; 
}

//----------------------------------------------------------------------------
// (askoptions (prompt (help..) (choices..) default..))
//     choose n options
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_askoptions(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt_va(OPT_PROMPT, contxt, NULL),
                help     = get_opt_va(OPT_HELP, contxt, NULL),
                choices  = get_opt_va(OPT_CHOICES, contxt, NULL),
                deflt    = get_opt_va(OPT_DEFAULT, contxt, NULL);

        DNUM = -1; 

        // We need everything but a defaut value.
        if(prompt && help && choices)
        {
            // Unless the parser is broken, 
            // we will have >= one child. 
            entry_p *e = choices->children;

            // Options are represented by bitmask of 32
            // bits, refer to Install.guide. Thus, we 
            // need room for 32 pointers + NULL.
            static const char *chs[33]; 

            // Index
            int i = 0; 

            // Pick up a string representation of all
            // the options.
            while(*e && *e != end())
            {
                char *cur = str(*e);

                // Filter out any empty strings. 
                // Refer to Install.guide. 
                if(strlen(cur))
                {
                    chs[i++] = cur; 
                }

                // Next option.
                e++; 
            }

            // Terminate array. 
            chs[i] = NULL; 

            // Do we have default option?
            if(deflt)
            {
                // Is there such a choice? 
                int d = num(deflt);

                if(d >= (1 << i))
                {
                    // Nope, out of range.
                    ERR(ERR_NO_ITEM, str(deflt)); 
                    RNUM(0); 
                }

                // Yes, use the default
                // value given.
                i = d; 
            }
            else
            {
                // No default = -1 
                i = -1; 
            }

            // Show requester unless we're executing in
            // 'novice' mode.
            if(get_numvar(contxt, "@user-level") > 0)
            {
                const char *p = str(prompt),
                           *h = str(help);

                // Only show requester if we could
                // resolve all options.
                if(!DID_ERR())
                {
                    // Prompt user.
                    DNUM = gui_options(p, h, chs, i); 
                }
            }
            else
            {
                DNUM = i;
            }
        }
        else
        {
            char *m = !prompt ? "prompt" : !help ? "help" : "choices";
            ERR(ERR_MISSING_OPTION, m);
        }
    }
    else
    {
        // The parser is broken
        PANIC(contxt); 
    }

    // Success, failure or
    // broken parser. 
    RCUR; 
}

//----------------------------------------------------------------------------
// (askstring (prompt..) (help..) (default..))
//     ask for a string
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_askstring(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt_va(OPT_PROMPT, contxt, NULL),
                help     = get_opt_va(OPT_HELP, contxt, NULL),
                deflt    = get_opt_va(OPT_DEFAULT, contxt, NULL);

        if(prompt && help && deflt)
        {
            const char *res = NULL;

            // Show requester unless we're executing in
            // 'novice' mode.
            if(get_numvar(contxt, "@user-level") > 0)
            {
                const char *p = str(prompt),
                           *h = str(help),
                           *d = str(deflt);  
                
                // Only show requester if we could
                // resolve all options.
                if(!DID_ERR())
                {
                    int hlt = 0; 

                    // Prompt user.
                    res = gui_string(p, h, d, &hlt);

                    // Halt if abort.
                    if(hlt)
                    {
                        HALT(); 
                        REST;
                    }
                }
                else
                {
                    // Could not resolve all
                    // options. Error set by
                    // str().
                    REST;
                }
            }
            else
            {
                // Use the default value.
                res = str(deflt); 
            }
            
            RSTR(strdup(res)); 
        }
        else
        {
            char *m = !prompt ? "prompt" : !help ? "help" : "default";
            ERR(ERR_MISSING_OPTION, m);
        }

        // Return empty string
        // on failure.
        REST;
    }
    else
    {
        // The parser is broken
        PANIC(contxt); 
        RCUR;
    }
}
