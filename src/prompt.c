//----------------------------------------------------------------------------
// prompt.c: 
//
// User prompting
//
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
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                deflt    = get_opt(contxt, OPT_DEFAULT),
                choices  = get_opt(contxt, OPT_CHOICES);

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
                DNUM = gui_bool
                (
                    str(prompt), 
                    str(help), 
                    yes, 
                    no
                );
            }
        }
        else
        {
            error
            (
                contxt->id, ERR_MISSING_OPTION, 
                !prompt ? "prompt" : "help"
            ); 
        }
    }
    else
    {
        // The parser is broken
        error(PANIC); 
    }

    // 
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
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                choices  = get_opt(contxt, OPT_CHOICES),
                deflt    = get_opt(contxt, OPT_DEFAULT);

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
                    error(contxt->id, ERR_NO_ITEM, 
                          str(deflt)); 

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
                // The GUI part will do the rest. 
                DNUM = gui_choice
                (
                    str(prompt), 
                    str(help),
                    (const char **) chs, 
                    i
                ); 
            }
            else
            {
                DNUM = i;
            }
        }
        else
        {
            error
            (
                contxt->id, ERR_MISSING_OPTION, 
                !prompt ? "prompt" : !help ? "help" : "choices"
            ); 
        }
    }
    else
    {
        // The parser is broken
        error(PANIC); 
    }

    // We could be in any
    // state here.
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
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                deflt    = get_opt(contxt, OPT_DEFAULT),
                newpath  = get_opt(contxt, OPT_NEWPATH),
                disk     = get_opt(contxt, OPT_DISK),
                assigns  = get_opt(contxt, OPT_ASSIGNS);

        // Are all mandatory options (!?) present?
        if(prompt && help && deflt)
        {
            const char *ret;
            int level = get_numvar(contxt, "@user-level");

            // Show requeter unless we're executing in
            // 'novice' mode.
            if(level > 0)
            {
                ret = gui_askdir
                (
                    str(prompt),
                    str(help),
                    newpath ? 1 : 0, 
                    disk ? 1 : 0, 
                    assigns ? 1 : 0, 
                    str(deflt)
                ); 

                // Return empty string and
                // halt if user aborted.
                if(!ret)
                {
                    error(HALT); 
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
            error
            (
                contxt->id, ERR_MISSING_OPTION, 
                !prompt ? "prompt" : 
                !help ? "help" : "default"
            ); 
        }
    }
    else
    {
        // Broken parser.
        error(PANIC); 
    }

    // Broken parser / broken
    // code / user abort. 
    REST; 
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
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                dest     = get_opt(contxt, OPT_DEST),
                newname  = get_opt(contxt, OPT_NEWNAME); 

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
                                error(contxt->id, ERR_ASSIGN, str(CARG(1))); 
                                UnLock(l); 
                            }
                        }
                        else
                        {
                            // An assign must contain at least one character. 
                            error(contxt->id, ERR_INVALID_ASSIGN, nn); 
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
                DNUM = 1; 
                newname = NULL; 
                #endif
            }
            else
            {
                // A volume name must contain at
                // least one character. 
                error(contxt->id, ERR_INVALID_VOLUME, n); 
            }
        }
        else
        {
            error
            (
                contxt->id, ERR_MISSING_OPTION, 
                !prompt ? "prompt" : 
                !help ? "help" : "dest"
            ); 
        }
    }
    else
    {
        // The parser is broken
        error(PANIC); 
    }

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
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                newpath  = get_opt(contxt, OPT_NEWPATH),
                disk     = get_opt(contxt, OPT_DISK),
                deflt    = get_opt(contxt, OPT_DEFAULT);

        // Are all mandatory options (!?) present?
        if(prompt && help && deflt)
        {
            const char *ret;
            int level = get_numvar(contxt, "@user-level");

            // Show file dialog unless we're executing
            // in 'novice' mode.
            if(level > 0)
            {
                ret = gui_askfile
                (
                    str(prompt),
                    str(help),
                    newpath ? 1 : 0, 
                    disk ? 1 : 0, 
                    str(deflt)
                ); 

                // Return empty string and
                // halt if user aborted.
                if(!ret)
                {
                    error(HALT); 
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
            error
            (
                contxt->id, ERR_MISSING_OPTION, 
                !prompt ? "prompt" : !help ? "help" : "default"
            ); 
        }
    }
    else
    {
        // Broken parser.
        error(PANIC); 
    }

    // Broken parser / broken
    // code / user abort. 
    REST; 
}

//----------------------------------------------------------------------------
// (asknumber (prompt..) (help..) (range..) (default..))
//     ask for a number
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_asknumber(entry_p contxt)
{
    if(contxt)
    {
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                range    = get_opt(contxt, OPT_RANGE),
                deflt    = get_opt(contxt, OPT_DEFAULT);

        if(prompt && help && deflt)
        {
            // This is not right, you need
            // some other widget if no range
            // is given (or a huge one). 
            int min = 0, max = 10; 

            if(range)
            {
                if(c_sane(range, 2))
                {
                    min = num(range->children[0]);
                    max = num(range->children[1]);
                }
                else
                {
                    // The parser is broken
                    error(PANIC); 
                    RCUR; 
                }
            }

            RNUM
            (
                gui_number
                (
                    str(prompt),
                    str(help),
                    min, 
                    max, 
                    num(deflt)
                )
            );
        }
        else
        {
            error
            (
                contxt->id, ERR_MISSING_OPTION, 
                !prompt ? "prompt" : !help ? "help" : "default"
            ); 
        }
    }
    else
    {
        // The parser is broken
        error(PANIC); 
    }

    RNUM(0); 
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
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                choices  = get_opt(contxt, OPT_CHOICES),
                deflt    = get_opt(contxt, OPT_DEFAULT);

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
                    error(contxt->id, ERR_NO_ITEM, 
                          str(deflt)); 
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
                // The GUI part will do the rest. 
                DNUM = gui_options
                (
                    str(prompt), 
                    str(help), 
                    (const char **) chs, 
                    i
                ); 
            }
            else
            {
                DNUM = i;
            }
        }
        else
        {
            error
            (
                contxt->id, ERR_MISSING_OPTION, 
                !prompt ? "prompt" : !help ? "help" : "choices"
            );
        }
    }
    else
    {
        // The parser is broken
        error(PANIC); 
    }

    // We could be in any
    // state here.
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
        entry_p prompt   = get_opt(contxt, OPT_PROMPT),
                help     = get_opt(contxt, OPT_HELP),
                deflt    = get_opt(contxt, OPT_DEFAULT);

        if(prompt && help && deflt)
        {
            const char *res = gui_string
            (
                str(prompt), 
                str(help), 
                str(deflt)
            );

            RSTR(strdup(res)); 
        }
        else
        {
            error
            (
                contxt->id, ERR_MISSING_OPTION, 
                !prompt ? "prompt" : !help ? "help" : "default"
            ); 
        }
    }
    else
    {
        // The parser is broken
        error(PANIC); 
    }

    REST; 
}
