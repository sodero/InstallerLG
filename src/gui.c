//----------------------------------------------------------------------------
// gui.c: 
//
// MUI based GUI. On non Amiga systems this is, except for some stdout prints
// to aid testing, a stub.
//----------------------------------------------------------------------------
// Copyright (C) 2018, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//----------------------------------------------------------------------------

#include "gui.h"
#include "resource.h"

#ifdef AMIGA
#include <libraries/asl.h>
#include <libraries/mui.h> 
#include <proto/alib.h>
#include <proto/debug.h>
#include <proto/exec.h>
#include <proto/graphics.h>
#include <proto/intuition.h>
#include <proto/muimaster.h>
#endif /* AMIGA */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h> 
#include <sys/time.h>

#ifdef AMIGA
//----------------------------------------------------------------------------
// MUI helper macros 
//----------------------------------------------------------------------------
#ifdef __MORPHOS__     
# define DISPATCH_GATE(C) &C ## Gate
# define DISPATCH_ARGS void
# define DISPATCH_HEAD \
  Class *cls = (Class *) REG_A0; \
  Object *obj = (Object *) REG_A2; \
  Msg msg = (Msg) REG_A1
# define CLASS_DEF(C) \
  static IPTR C ## Dispatch (void); \
  struct MUI_CustomClass * C ## Class; \
  const struct EmulLibEntry C ## Gate = \
  { TRAP_LIB, 0, (void (*) (void)) C ## Dispatch }; \
  struct C ## Data
#else
# define DoSuperNew(C,O,...) DoSuperNewTags(C,O,NULL,__VA_ARGS__)
# define DISPATCH_HEAD                              
# define DISPATCH_ARGS Class *cls, Object *obj, Msg msg
# define DISPATCH_GATE(C) C ## Dispatch
# define CLASS_DEF(C) \
  struct MUI_CustomClass * C ## Class; \
  struct C ## Data
#endif    
#define DISPATCH(C) static IPTR C ## Dispatch (DISPATCH_ARGS)    
#define CLASS_DATA(C) C ## Data
#define TAGBASE_sTx (TAG_USER | 27<<16)
#define MUIDSP static inline __attribute__((always_inline)) 

//----------------------------------------------------------------------------
// Debug and logging macros
//----------------------------------------------------------------------------
#define GPUT(E,S) KPrintF((CONST_STRPTR)"%s:\t%s\t(%s)\n",E,S,__func__)
#define GERR(S) GPUT("ERR",S)
#define WARN(S) if(LLVL>0) GPUT("WARN",S)
#define INFO(S) if(LLVL>1) GPUT("INFO",S)

//----------------------------------------------------------------------------
// The installer window 
//----------------------------------------------------------------------------
Object *Win; 

//----------------------------------------------------------------------------
// InstallerGui - Class members
//----------------------------------------------------------------------------
CLASS_DEF(InstallerGui) 
{
    struct MUI_InputHandlerNode Ticker;
    Object *ExpertLevel,
           *UserLevel,
           *Pretend,
           *Log;
};

//----------------------------------------------------------------------------
// InstallerGui - Public methods
//----------------------------------------------------------------------------
#define MUIM_InstallerGui_Init             (TAGBASE_sTx + 101)
#define MUIM_InstallerGui_Welcome          (TAGBASE_sTx + 102)
#define MUIM_InstallerGui_CopyFilesStart   (TAGBASE_sTx + 104)
#define MUIM_InstallerGui_CopyFilesSetCur  (TAGBASE_sTx + 105)
#define MUIM_InstallerGui_CopyFilesEnd     (TAGBASE_sTx + 106)
#define MUIM_InstallerGui_Exit             (TAGBASE_sTx + 107)
#define MUIM_InstallerGui_Complete         (TAGBASE_sTx + 108)
#define MUIM_InstallerGui_Ticker           (TAGBASE_sTx + 109)
#define MUIM_InstallerGui_CopyFilesAdd     (TAGBASE_sTx + 110)
#define MUIM_InstallerGui_Confirm          (TAGBASE_sTx + 111)
#define MUIM_InstallerGui_Message          (TAGBASE_sTx + 112)
#define MUIM_InstallerGui_Radio            (TAGBASE_sTx + 114)
#define MUIM_InstallerGui_Bool             (TAGBASE_sTx + 115)
#define MUIM_InstallerGui_String           (TAGBASE_sTx + 116)
#define MUIM_InstallerGui_Number           (TAGBASE_sTx + 117)
#define MUIM_InstallerGui_CheckBoxes       (TAGBASE_sTx + 118)
#define MUIM_InstallerGui_AskFile          (TAGBASE_sTx + 119)

//----------------------------------------------------------------------------
// InstallerGui - Init parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_Init
{
    ULONG MethodID;
};

//----------------------------------------------------------------------------
// InstallerGui - Welcome parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_Welcome
{
    ULONG MethodID;
    ULONG Message;
    ULONG Level;
    ULONG Log;
    ULONG Pretend;
    ULONG MinLevel;
    ULONG NoPretend;
    ULONG NoLog;
};

//----------------------------------------------------------------------------
// InstallerGui - CopyFilesStart parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_CopyFilesStart
{
    ULONG MethodID;
    ULONG Message;
    ULONG NumberOfFiles;
};

//----------------------------------------------------------------------------
// InstallerGui - CopyFilesSetCur parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_CopyFilesSetCur
{
    ULONG MethodID;
    ULONG File;
    ULONG NoGauge;
};

//----------------------------------------------------------------------------
// InstallerGui - Exit parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_Exit
{
    ULONG MethodID;
    ULONG Message;
};

//----------------------------------------------------------------------------
// InstallerGui - Complete parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_Complete
{
    ULONG MethodID;
    ULONG Progress;
};

//----------------------------------------------------------------------------
// InstallerGui - CopyFilesAdd parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_CopyFilesAdd
{
    ULONG MethodID;
    ULONG File;
};

//----------------------------------------------------------------------------
// InstallerGui - Run parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_Confirm
{
    ULONG MethodID;
    ULONG Message;
    ULONG Help;
};

//----------------------------------------------------------------------------
// InstallerGui - Message parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_Message
{
    ULONG MethodID;
    ULONG Message;
    ULONG Immediate;
};

//----------------------------------------------------------------------------
// InstallerGui - Radio parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_Radio
{
    ULONG MethodID;
    ULONG Message;
    ULONG Help;
    ULONG Names;
    ULONG Default; 
    ULONG Halt; 
};

//----------------------------------------------------------------------------
// InstallerGui - Bool parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_Bool
{
    ULONG MethodID;
    ULONG Message;
    ULONG Help;
    ULONG Yes;
    ULONG No;
};

//----------------------------------------------------------------------------
// InstallerGui - String parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_String
{
    ULONG MethodID;
    ULONG Message;
    ULONG Help;
    ULONG Default; 
    ULONG Halt; 
};

//----------------------------------------------------------------------------
// InstallerGui - Number parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_Number
{
    ULONG MethodID;
    ULONG Message;
    ULONG Help;
    ULONG Min;
    ULONG Max;
    ULONG Default; 
    ULONG Halt; 
};

//----------------------------------------------------------------------------
// InstallerGui - CheckBoxes parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_CheckBoxes
{
    ULONG MethodID;
    ULONG Message;
    ULONG Help;
    ULONG Names;
    ULONG Default; 
    ULONG Halt; 
};

//----------------------------------------------------------------------------
// InstallerGui - AskFile parameters
//----------------------------------------------------------------------------
struct MUIP_InstallerGui_AskFile
{
    ULONG MethodID;
    ULONG Message;
    ULONG Help;
    ULONG NewPath;
    ULONG Disk;
    ULONG Assign; 
    ULONG Default;
    ULONG Dir;
};

//----------------------------------------------------------------------------
// InstallerGui - private values 
//----------------------------------------------------------------------------
#define MUIV_InstallerGui_FirstButton      (TAGBASE_sTx + 200)
#define MUIV_InstallerGui_Proceed          (TAGBASE_sTx + 200)
#define MUIV_InstallerGui_Abort            (TAGBASE_sTx + 201)
#define MUIV_InstallerGui_Yes              (TAGBASE_sTx + 203)
#define MUIV_InstallerGui_No               (TAGBASE_sTx + 204)
#define MUIV_InstallerGui_Tick             (TAGBASE_sTx + 207)
#define MUIV_InstallerGui_AbortOnly        (TAGBASE_sTx + 208)
#define MUIV_InstallerGui_ProceedRun       (TAGBASE_sTx + 209)
#define MUIV_InstallerGui_SkipRun          (TAGBASE_sTx + 210)
#define MUIV_InstallerGui_AbortRun         (TAGBASE_sTx + 211)
#define MUIV_InstallerGui_ProceedOnly      (TAGBASE_sTx + 212)
#define MUIV_InstallerGui_LastButton       (TAGBASE_sTx + 212)
#define MUIV_InstallerGui_TopPager         (TAGBASE_sTx + 218)
#define MUIV_InstallerGui_BottomPager      (TAGBASE_sTx + 219)
#define MUIV_InstallerGui_UserLevel        (TAGBASE_sTx + 220)
#define MUIV_InstallerGui_Progress         (TAGBASE_sTx + 221)
#define MUIV_InstallerGui_Text             (TAGBASE_sTx + 224)
#define MUIV_InstallerGui_FileProgress     (TAGBASE_sTx + 226)
#define MUIV_InstallerGui_FileList         (TAGBASE_sTx + 227)
#define MUIV_InstallerGui_Pretend          (TAGBASE_sTx + 228)
#define MUIV_InstallerGui_Logging          (TAGBASE_sTx + 229)
#define MUIV_InstallerGui_EmptyGroup       (TAGBASE_sTx + 230)
#define MUIV_InstallerGui_String           (TAGBASE_sTx + 231)
#define MUIV_InstallerGui_Number           (TAGBASE_sTx + 232)
#define MUIV_InstallerGui_AskFile          (TAGBASE_sTx + 233)
#define MUIV_InstallerGui_TopGroup         (TAGBASE_sTx + 234)

// Pages
#define P_WELCOME                          0
#define P_COPYFILES                        1
#define P_FILEDEST                         2
#define P_PRETEND_LOG                      3
#define P_MESSAGE                          4
#define P_STRING                           5
#define P_NUMBER                           6
#define P_ASKFILE                          7

// Buttons
#define B_PROCEED_ABORT                    0
#define B_YES_NO                           1
#define B_ABORT                            2
#define B_PROCEED_SKIP_ABORT               3
#define B_PROCEED                          4
#define B_NONE                             5

//----------------------------------------------------------------------------
// InstallerGuiWait - [PRIVATE] Wait for notification(s)
// Input:             ULONG notif:  Start notification value 
//                    ULONG range:  Number of values to check for
// Return:            Notifcation val. / zero on return id quit 
//----------------------------------------------------------------------------
MUIDSP ULONG InstallerGuiWait(Object *obj, ULONG notif, ULONG range)
{
    ULONG sig = 0, 
          ret = 0, n; 

    // Set cycle chain for all buttons
    // within the notification range.
    for(n = 0; n < range; n++)
    {
        // Filter out ticks.
        if(notif + n != MUIV_InstallerGui_Tick) 
        {
            // Find current button. 
            Object *but = (Object *) DoMethod
            (
                obj, MUIM_FindUData, 
                notif + n
            );

            // Don't trust the caller.
            if(but)
            {
                // Add button to cycle chain.
                set(but, MUIA_CycleChain, TRUE);
            }
            else
            {
                // Button doesn't exist. 
                GERR(tr(S_UNER)); 
            }
        }
    }

    // Get MUI input. 
    ret = DoMethod(_app(obj), MUIM_Application_NewInput, &sig);

    // Enter the message loop. 
    while(ret != MUIV_Application_ReturnID_Quit)
    {
        // Iterate over all signals that we're 
        // waiting for.
        for(n = 0; n < range; n++)
        {
            // Did we get what we're waiting for?
            if(ret == notif + n)
            {
                // Remove buttons within the range
                // from the cycle chain. 
                for(n = 0; n < range; n++)
                {
                    // Filter out ticks.
                    if(notif + n != MUIV_InstallerGui_Tick) 
                    {
                        // Find current button. 
                        Object *but = (Object *) DoMethod
                        (
                            obj, MUIM_FindUData, 
                            notif + n
                        );

                        // Don't trust the caller.
                        if(but)
                        {
                            set(but, MUIA_CycleChain, FALSE);
                        }
                    }
                }

                // Return notifier value.
                return ret; 
            }
        }

        // It wasn't for us. Go to sleep again. 
        if(sig)
        {
            sig = Wait(sig | SIGBREAKF_CTRL_C);

            // Are we getting killed? 
            if(sig & SIGBREAKF_CTRL_C) 
            {
                break; 
            }
        }

        // Get new input. 
        ret = DoMethod(_app(obj), MUIM_Application_NewInput, &sig);
    }

    // Quit application. 
    return 0; 
}

//----------------------------------------------------------------------------
// InstallerGuiInit - Initialize all the things 
// Input:             -
// Return:            On success TRUE, FALSE otherwise.
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiInit(Class *cls,
                             Object *obj)
{
    static unsigned int init; 

    // Make sure that we execute this once only.
    if(!init && obj && _app(obj))
    {
        // Exit upon close request
        DoMethod
        (
            obj, MUIM_Notify, 
            MUIA_Window_CloseRequest, TRUE,
            _app(obj), 2, 
            MUIM_Application_ReturnID, 
            MUIV_Application_ReturnID_Quit
        );

        // Set up notifications for all buttons.
        for(init = MUIV_InstallerGui_FirstButton; 
            init <= MUIV_InstallerGui_LastButton; 
            init++)
        {
            // Locate button.
            Object *cur = (Object *) DoMethod
            (
                obj, MUIM_FindUData,
                init
            );

            // Don't assume that the button exists.
            if(cur)
            {
                DoMethod
                (
                    cur, MUIM_Notify, 
                    MUIA_Pressed, FALSE, 
                    _app(obj), 2, 
                    MUIM_Application_ReturnID, init
                ); 
            }
        }

        // All done.
        return TRUE; 
    }
    else
    {
        // Unknown error.
        GERR(tr(S_UNER)); 
        return FALSE; 
    }
}

//----------------------------------------------------------------------------
// InstallerGuiPageSet - [PRIVATE] Set page / buttons and display text
// Input:                int top:   Top page 
//                       int btm:   Button page 
//                       ULONG msg: Top text message
// Return:               TRUE on success, FALSE otherwise
//----------------------------------------------------------------------------
static ULONG InstallerGuiPageSet(Object *obj, 
                                 int top, 
                                 int btm, 
                                 ULONG msg)
{
    static Object *txt, *con, *but; 

    // Initial lookup. 
    if(!txt)
    {
        txt = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_Text
        );

        con = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_TopPager
        );

        but = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_BottomPager
        );
    }

    // Sanity check.
    if(txt && con && but)
    {
        // Select top and buttons.
        set(con, MUIA_Group_ActivePage, top);
        set(but, MUIA_Group_ActivePage, btm);

        // Show the message if we have one.
        if(msg)
        {
            // Wrap at 50 for now, even though
            // we make room for more below.
            char *src = (char *) msg;
            size_t cnt = strlen(src), len = 50;

            // Allow no more than 80 columns
            // and 10 lines of text, newline
            // characters are included. More
            // than this would be to much in
            // a single page.
            static char dst[80 * 10];

            // Do we have a non empty message?
            if(cnt)
            {
                // Cap the size of the message.
                cnt = cnt < (sizeof(dst) - 1) ?
                      cnt : (sizeof(dst) - 1);

                // Copy for wrapping.
                memcpy(dst, src, cnt);

                // Do we need to word wrap?
                if(cnt > len)
                {
                    // Start from the first point
                    // where we need to wrap.
                    size_t cur = len;

                    // As long we have characters.
                    while(cur < cnt)
                    {
                        // Last wrapping point.
                        size_t ref = cur - len;

                        // Go backwards from where we are
                        // to a point where we can wrap.
                        while(cur > ref && dst[cur] > 33)
                        {
                            cur--;
                        }

                        // If we ended up where we started
                        // we failed. Wrap in the middle of
                        // the word in that case. This will
                        // only happen with words >= len.
                        if(cur == ref)
                        {
                            // Restore the previous point.
                            cur += len;
                        }
                        else
                        {
                            // If we found a wrapping point
                            // we must make sure that no NL
                            // exists before this point but
                            // after the previous point.
                            while(++ref < cur)
                            {
                                if(dst[ref] == '\n')
                                {
                                    // Skip wrap.
                                    cur = ref;
                                    break; 
                                }
                            }
                        }

                        // Wrap and continue.
                        dst[cur] = '\n';
                        cur += len;
                    }
                }

                // Terminate string.
                dst[cnt] = '\0';

                // Show the message.
                set(txt, MUIA_ShowMe, FALSE);
                set(txt, MUIA_Text_Contents, dst);
                set(txt, MUIA_ShowMe, TRUE);
            }
        }

        // Always.
        return TRUE; 
    }
    else
    {
        // Unknown error.
        GERR(tr(S_UNER)); 
        return FALSE; 
    }
}

//----------------------------------------------------------------------------
// InstallerGuiWelcome - Show welcome message. The Level, Log, and Pretend
//                       parameters are int pointers that act as both input
//                       and output.
// Input:                Message - the welcome message text
//                       Level - User level
//                       Log - Log to file
//                       Pretend - Pretend mode
//                       MinLevel - Minimum user level
//                       NoPretend - Disable pretend mode
//                       NoLog - Disable logging
// Return:               1 on success, 0 on abort
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiWelcome(Class *cls,
                                Object *obj,
                                struct MUIP_InstallerGui_Welcome *msg)
{
    // Show welcome page.
    if(InstallerGuiPageSet(obj, P_WELCOME, B_PROCEED_ABORT, msg->Message))
    {
        struct InstallerGuiData *my = INST_DATA(cls, obj);

        // If the minimum user level is set to 'expert',
        // disable radio buttons to indicate that there
        // is no choice to be made.
        if(msg->MinLevel == 2)
        {
            set(my->UserLevel, MUIA_Disabled, TRUE);
        }
        // If the minimum user level is set to 'average',
        // show 'average' and 'expert' only.
        else if(msg->MinLevel == 1)
        {
            set(my->UserLevel, MUIA_ShowMe, FALSE);
            set(my->ExpertLevel, MUIA_ShowMe, TRUE);
        }

        // Set the current user level, reflecting the minimum user
        // level unless there are overrides in the script.
        set(my->UserLevel, MUIA_Radio_Active, *((int *) msg->Level));

        // Wait for proceed or abort.
        if(InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2)
           == MUIV_InstallerGui_Proceed)
        {
            // Get the selected user level value. If we have
            // a minimum user level of 'average' we're using
            // a different set of radio buttons. Fetch from
            // the right object and adjust the return value.
            if(msg->MinLevel == 1)
            {
                // Minimum user level 'average'.
                get(my->ExpertLevel, MUIA_Radio_Active, (int *) msg->Level);
                (*((int *) msg->Level))++;
            }
            else
            {
                // Minimum user level 'novice' or 'expert'.
                get(my->UserLevel, MUIA_Radio_Active, (int *) msg->Level);
            }

            // Disable the pretend choice if the NOPRETEND
            // tooltype is used. The default behaviour is
            // to install for real, not to pretend.
            SetAttrs
            (
                my->Pretend,
                MUIA_Radio_Active,
                msg->NoPretend ? 0 : *((int *) msg->Pretend),
                MUIA_Disabled, msg->NoPretend ? TRUE : FALSE,
                TAG_END
            );

            // Disable the 'log to file' choice if the NOLOG
            // tooltype is used. The default behaviour is to
            // not write to a log file.
            SetAttrs
            (
                my->Log,
                MUIA_Radio_Active,
                msg->NoLog ? 0 : *((int *) msg->Log),
                MUIA_Disabled, msg->NoLog ? TRUE : FALSE,
                TAG_END
            );

            // Don't show logging and pretend mode settings
            // to 'Novice' users.
            if(*((int *) msg->Level))
            {
                // Show pretend / log page.
                if(InstallerGuiPageSet(obj, P_PRETEND_LOG, B_PROCEED_ABORT,
                                      (ULONG) ""))
                {
                    // Wait for proceed or abort.
                    if(InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2)
                       == MUIV_InstallerGui_Proceed)
                    {
                        // Get pretend and log settings.
                        get(my->Pretend, MUIA_Radio_Active, (int *) msg->Pretend);
                        get(my->Log, MUIA_Radio_Active, (int *) msg->Log);
                    }
                    else
                    {
                        // Abort.
                        return 0;
                    }
                }
                else
                {
                    // Unknown error.
                    GERR(tr(S_UNER));
                    return 0;
                }
            }

            // Done.
            return 1;
        }
        else
        {
            // Abort.
            return 0;
        }
    }

    // Unknown error.
    GERR(tr(S_UNER)); 
    return 0; 
}

//----------------------------------------------------------------------------
// InstallerGuiAskFile - Show file / directory requester 
// Input:                Message - The prompt
//                       Help - Help text
//                       NewPath - Allow non-existent defaults
//                       Disk - Show drive list first
//                       Assign - Logical assign OK as dir
//                       Default - Default file / directory
//                       Dir - Ask for directory
// Return:               File / directory name or NULL
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiAskFile(Class *cls,
                                Object *obj,
                                struct MUIP_InstallerGui_AskFile *msg)
{
    // Show file requester page.
    if(InstallerGuiPageSet(obj, P_ASKFILE, B_PROCEED_ABORT, 
                           msg->Message))
    {
        static Object *ask, *top; 

        // Initial lookup. 
        if(!ask)
        {
            ask = (Object *) DoMethod
            (
                obj, MUIM_FindUData, 
                MUIV_InstallerGui_AskFile
            );

            top = (Object *) DoMethod
            (
                obj, MUIM_FindUData, 
                MUIV_InstallerGui_TopGroup
            );
        }

        // Sanity check.
        if(ask && top)
        { 
            // Create ASL file requester
            Object *str, *pop = (Object *) MUI_NewObject
            (
                MUIC_Popasl, 
                MUIA_Popasl_Type, ASL_FileRequest, 
                ASLFR_DrawersOnly, msg->Dir, 
                ASLFR_InitialShowVolumes, msg->Disk, 
                ASLFR_TitleText, msg->Dir ? tr(S_SDIR) : tr(S_SFLE), 
                MUIA_Popstring_String, str = (Object *) MUI_MakeObject(MUIO_String, NULL, PATH_MAX),
                MUIA_Popstring_Button, (Object *) MUI_MakeObject(MUIO_PopButton, MUII_PopDrawer), 
                TAG_END
            );

            // Open the requester after adding it
            // to the current group.
            if(pop)
            {
                // Set help bubble.
                set(top, MUIA_ShortHelp, msg->Help); 

                // Set default file / dir.
                set(str, MUIA_String_Contents, msg->Default); 

                // Prepare before adding requester.
                if(DoMethod(ask, MUIM_Group_InitChange))
                {
                    char *ret = NULL;
                    static char buf[PATH_MAX];

                    // Add pop up requester.
                    DoMethod(ask, OM_ADDMEMBER, pop); 

                    // We're done adding things.
                    DoMethod(ask, MUIM_Group_ExitChange);

                    // Wait for proceed or abort.
                    if(InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2) 
                       == MUIV_InstallerGui_Proceed)
                    {
                        // Get filename from requester.
                        get(str, MUIA_String_Contents, &ret); 

                        if(ret)
                        {
                            // We need to create a copy of the filename
                            // string since we're about to free the pop
                            // up requester.
                            int n = snprintf(buf, sizeof(buf), "%s", ret); 

                            // Make sure that we succeded in creating a
                            // copy of the filename.
                            if(n >= 0 && n < sizeof(buf))
                            {
                                ret = buf;
                            }
                        }

                        if(!ret)
                        {
                            // Unknown error.
                            GERR(tr(S_UNER)); 
                        }
                    }

                    // Prepare before removing requester.
                    if(DoMethod(ask, MUIM_Group_InitChange))
                    {
                        // Remove pop up requester.
                        DoMethod(ask, OM_REMMEMBER, pop); 

                        // We're done removing things.
                        DoMethod(ask, MUIM_Group_ExitChange);

                        // Free ASL requester.
                        MUI_DisposeObject(pop);

                        // Return filename.
                        return (IPTR) ret;
                    }
                }

                // Free ASL requester.
                MUI_DisposeObject(pop);
            }
        }
    }

    // Unknown error.
    GERR(tr(S_UNER)); 
    return (IPTR) NULL; 
}

//----------------------------------------------------------------------------
// InstallerGuiCopyFilesStart - Show file copy requester
// Input:                       Message - The prompt
//                              NumberOfFiles - Number of files to copy
// Return:                      TRUE to start copy, FALSE to cancel
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiCopyFilesStart(Class *cls,
                                       Object *obj,
                                       struct MUIP_InstallerGui_CopyFilesStart *msg)
{
    // Show file copy page.
    if(InstallerGuiPageSet(obj, P_COPYFILES, B_ABORT, 
                           msg->Message))
    {
        static Object *prg; 

        // Initial lookup. 
        if(!prg)
        { 
            prg = (Object *) DoMethod
            (
                obj, MUIM_FindUData, 
                MUIV_InstallerGui_FileProgress
            );
        } 

        // Sanity check.
        if(prg) 
        {
            struct InstallerGuiData *my = INST_DATA(cls, obj);

            // Install a timer to create a time slice
            // where the user has a chance to abort.
            DoMethod(_app(obj), MUIM_Application_AddInputHandler, &my->Ticker);

            // Configure gauge so that one tick == one file.
            SetAttrs(prg, MUIA_Gauge_Max, msg->NumberOfFiles,
                     MUIA_Gauge_Current, 0, TAG_END);

            // Always true. 
            return (IPTR) TRUE; 
        }
    }

    // Unknown error.
    GERR(tr(S_UNER)); 
    return FALSE; 
}

//----------------------------------------------------------------------------
// InstallerGuiCopyFilesSetCur - Show current file
// Input:                        File - filename
//                               NoGauge - Hide file gauge
// Return:                       TRUE to continue, FALSE to abort 
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiCopyFilesSetCur(Class *cls,
                                        Object *obj,
                                        struct MUIP_InstallerGui_CopyFilesSetCur *msg)
{
    static Object *prg; 

    // Initial lookup. 
    if(!prg)
    { 
        prg = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_FileProgress
        );
    } 

    // Sanity check.
    if(prg) 
    {
        struct timeval tv; 
        static unsigned long last; 
        char *txt = (char *) msg->File; 

        // We need to keep track of the
        // last time we've been here.
        gettimeofday(&tv, NULL); 

        // If we have a file name, update
        // the progress bar. 
        if(txt)
        {
            char *cut = NULL; 
            struct TextExtent e; 

            // Get rendered size of file string.
            ULONG cur = 0, len = strlen(txt), 
                  w = _width(prg), h = _height(prg),
                  max = TextFit(_rp(prg), txt, len, 
                                &e, NULL, 1, w, h); 

            // If the string length of the file
            // name is longer than we can fit in
            // the progress bar, truncate string. 
            if(max < len)
            {
                // Modify a copy ot the string. 
                cut = strdup(txt);  

                if(cut)
                {
                    // Truncate copy and let the copy
                    // replace the current string
                    cut[max] = '\0';
                    txt = cut; 
                }
                else
                {
                    // Out of memory.
                    GERR(tr(S_UNER)); 
                    return (IPTR) FALSE; 
                }
            }

            // Update progress bar. Text and number. 
            if(!msg->NoGauge)
            {
                // Get current progress.
                get(prg, MUIA_Gauge_Current, &cur); 

                // Add another file on top of the current
                // progress (one file = one tick).
                SetAttrs(prg, MUIA_Gauge_InfoText, txt,
                         MUIA_Gauge_Current, ++cur, TAG_END);
            }
            else
            {
                // Update text only, ignore the gauge.
                set(prg, MUIA_Gauge_InfoText, txt);
            }

            // Dispose the copy, if any. 
            free(cut); 
        }

        // Has enough time passsed for us to let the user get 
        // a chance to abort?
        if(((tv.tv_sec << 20L) + tv.tv_usec) - last > 40000)
        {
            // Wait for the next tick before returning. 
            if(InstallerGuiWait(obj, MUIV_InstallerGui_Tick, 2) ==
               MUIV_InstallerGui_Tick)
            {
                // Save the current time. 
                gettimeofday(&tv, NULL); 
                last = (tv.tv_sec << 20L) + tv.tv_usec; 
            }
            else
            {
                // User abort. 
                return (IPTR) FALSE; 
            }
        }

        // Next file (if any).  
        return (IPTR) TRUE; 
    }
    else
    {
        // Unknown error.
        GERR(tr(S_UNER)); 
        return (IPTR) FALSE; 
    }
}

//----------------------------------------------------------------------------
// InstallerGuiCopyFilesEnd - End of file copy
// Input:                     -   
// Return:                    TRUE 
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiCopyFilesEnd(Class *cls,
                                     Object *obj) 
{
    static Object *lst;
    struct InstallerGuiData *my = INST_DATA(cls, obj);

    // Initial lookup.
    if(!lst)
    {
        lst = (Object *) DoMethod
        (
            obj, MUIM_FindUData,
            MUIV_InstallerGui_FileList
        );
    }

    // Uninstall timer created to establish a time
    // slice where the user has a chance to abort
    // file copy operations. Things will continue
    // to work even if we don't, but by doing it 
    // this way we make less noise.
    DoMethod
    (
        _app (obj), 
        MUIM_Application_RemInputHandler, &my->Ticker
    );


    // Sanity check.
    if(lst)
    {
        // Leave the file list the way we
        // found it (empty).
        DoMethod(lst, MUIM_List_Clear);

        // Always true.
        return (IPTR) TRUE;
    }
    else
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return (IPTR) FALSE;
    }
}

//----------------------------------------------------------------------------
// InstallerGuiCopyFilesAdd - Add files to (expert) file (de)selector
// Input:                     File - Name of file (or dir)
// Return:                    TRUE on success, FALSE otherwise
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiCopyFilesAdd(Class *cls,
                                     Object *obj,
                                     struct MUIP_InstallerGui_CopyFilesAdd *msg)
{
    static Object *lst; 

    // Initial lookup. 
    if(!lst)
    { 
        lst = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_FileList
        );
    } 

    // Sanity check.
    if(lst) 
    {
        // Insert filename.
        DoMethod
        (
            lst, MUIM_List_Insert,
            &(msg->File), 1, 
            MUIV_List_Insert_Bottom
        ); 

        // The lister must be visible. 
        set(lst, MUIA_ShowMe, TRUE);

        // Always true. 
        return (IPTR) TRUE; 
    }
    else
    {
        // Unknown error.
        GERR(tr(S_UNER)); 
        return (IPTR) FALSE; 
    }
}


//----------------------------------------------------------------------------
// InstallerGuiExit - Say goodbye and close GUI
// Input:             Message - The prompt
// Return:            TRUE
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiExit(Class *cls,
                             Object *obj,
                             struct MUIP_InstallerGui_Exit *msg)
{
    // Do nothing.
    return TRUE;
}

//----------------------------------------------------------------------------
// InstallerGuiMessage - Show message
// Input:                Message - The prompt
//                       Immediate - No button
// Return:               TRUE on success, FALSE otherwise
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiMessage(Class *cls,
                                Object *obj,
                                struct MUIP_InstallerGui_Message *msg)
{
    // Setup the correct page and button combination.
    if(InstallerGuiPageSet(obj, P_MESSAGE, msg->Immediate ? B_NONE : B_PROCEED,
                           msg->Message))
    {
        // Wait for user input unless we're in immediate mode.
        if(!msg->Immediate)
        {
            // Wait for proceed and proceed only.
            InstallerGuiWait(obj, MUIV_InstallerGui_ProceedOnly, 1); 
        }

        // Always. 
        return TRUE;
    }
    else
    {
        // Unknown error.
        GERR(tr(S_UNER)); 
        return FALSE;
    }
}

//----------------------------------------------------------------------------
// InstallerGuiRadio - Show radio buttons
// Input:              Message - The prompt 
//                     Help - Help text
//                     Names - Array of choices (strings)
//                     Default - Default selection
//                     Halt - Halt return value
// Return:             Zero index representing the selected button
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiRadio(Class *cls,
                              Object *obj,
                              struct MUIP_InstallerGui_Radio *msg)
{
    const char **cs = (const char **) msg->Names; 
    IPTR err = TRUE, ret = 0; 
    static Object *grp, *top; 

    // Initial lookup. 
    if(!grp)
    { 
        grp = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_EmptyGroup
        );

        top = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_TopGroup
        );
    } 

    // Sanity check and set the correct page.
    if(top && grp && cs &&
       InstallerGuiPageSet(obj, P_MESSAGE, B_PROCEED_ABORT, 
                           msg->Message))
    {
        // 32 bits + NULL. 
        static const char *c[33];
        unsigned int i = 0;
        Object *r;

        // Make sure that the default value is a 
        // valid choice. Don't fail if it isn't,
        // use a fallback of 0 instead.
        while(*cs && i < 32)
        {
            c[i++] = *cs;
            cs++;
        }

        i = msg->Default < i ? 
            msg->Default : 0; 

        // Unlike most other pages, this one is
        // partly generated on the fly, we have
        // no choice.
        r = (Object *) MUI_NewObject
        (
            MUIC_Radio,
            MUIA_Radio_Active, i,
            MUIA_Radio_Entries, c,
            TAG_END
        );

        if(r)
        {
            // Set bubble help. 
            set(top, MUIA_ShortHelp, msg->Help); 

            // Prepare before adding radio buttons.
            if(DoMethod(grp, MUIM_Group_InitChange))
            {
                // Add radio buttons.
                DoMethod(grp, OM_ADDMEMBER, r); 

                // We're done adding things.
                DoMethod(grp, MUIM_Group_ExitChange);

                // Wait for proceed or abort.
                if(InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2) !=
                   MUIV_InstallerGui_Proceed)
                {
                    // On abort return HALT.
                    *((int *) msg->Halt) = 1; 
                }

                // Prepare before removing radio buttons.
                if(DoMethod(grp, MUIM_Group_InitChange))
                {
                    // Remove radio buttons.
                    DoMethod(grp, OM_REMMEMBER, r); 

                    // We're done removing things.
                    DoMethod(grp, MUIM_Group_ExitChange);
                    err = FALSE; 
                }
            }

            // Get value from buttons and then kill them.
            // A halt above will not make any difference.
            GetAttr(MUIA_Radio_Active, r, (IPTR *) &ret); 
            MUI_DisposeObject(r);
        }
    }

    if(err)
    {
        // Unknown error.
        GERR(tr(S_UNER)); 
    }

    return ret;
}

//----------------------------------------------------------------------------
// InstallerGuiBool - Get boolean value from user 
// Input:             Message - The prompt 
//                    Help - Help text
//                    Yes - True string value
//                    No - False string value
// Return:            0 = no, 1 = yes
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiBool(Class *cls,
                             Object *obj,
                             struct MUIP_InstallerGui_Bool *msg)
{
    static Object *yes, *no, *top; 

    // Initial lookup. 
    if(!yes)
    { 
        yes = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_Yes
        );

        no = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_No
        );
        
        top = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_TopGroup
        );
    } 

    // Sanity check.
    if(yes && no && top)
    {
        // Set values of true and false.
        set(yes, MUIA_Text_Contents, msg->Yes);
        set(no, MUIA_Text_Contents, msg->No);

        // Set help bubble.
        set(top, MUIA_ShortHelp, msg->Help); 

        if(InstallerGuiPageSet(obj, P_MESSAGE, B_YES_NO, 
                               msg->Message))
        {
            // Wait for yes or no.
            ULONG b = InstallerGuiWait(obj, MUIV_InstallerGui_Yes, 2); 

            switch(b)
            {
                case MUIV_InstallerGui_Yes:
                    return 1; 

                case MUIV_InstallerGui_No:
                    return 0; 

                default:
                    return -1; 
            }
        }
    }

    // Unknown error.
    GERR(tr(S_UNER)); 
    return -1;
}

//----------------------------------------------------------------------------
// InstallerGuiString - Get string value from user.
// Input:               Message - The prompt 
//                      Help - Help text
//                      Default - Default string value
//                      Halt - Halt return value
// Return:              A string value
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiString(Class *cls,
                               Object *obj,
                               struct MUIP_InstallerGui_String *msg)
{
    static Object *str, *top; 
    char *ret = NULL; 

    // Initial lookup. 
    if(!str)
    { 
        str = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_String
        );

        top = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_TopGroup
        );

        // Enter in string gadget = proceed.
        DoMethod(str, MUIM_Notify, MUIA_String_Acknowledge, 
                 MUIV_EveryTime, _app(obj), 2, 
                 MUIM_Application_ReturnID, MUIV_InstallerGui_Proceed); 
    } 

    // Sanity check.
    if(str && top)
    {
        // Set help bubble.
        set(top, MUIA_ShortHelp, msg->Help); 

        // Set initial value of string.
        set(str, MUIA_String_Contents, msg->Default);

        // Show string widget page.
        if(InstallerGuiPageSet(obj, P_STRING, B_PROCEED_ABORT, 
                               msg->Message))
        {
            // Wait for proceed or abort.
            if(InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2) ==
               MUIV_InstallerGui_Proceed)
            {
                // On proceed get string value.
                get(str, MUIA_String_Contents, &ret); 
            }
            else
            {
                // On abort return HALT.
                *((int *) msg->Halt) = 1; 
            }
        }
    }
    else
    {
        // Unknown error.
        GERR(tr(S_UNER)); 
    }

    // Always return a valid string.
    return (ULONG) (ret ? ret : ""); 
}

//----------------------------------------------------------------------------
// InstallerGuiNumber - Get numerical value from user
// Input:               Message - The prompt 
//                      Help - Help text
//                      Min - Minimum allowed value
//                      Max - Maximum allowed value
//                      Default - Default value
//                      Halt - Halt return value
// Return:              Numerical value
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiNumber(Class *cls,
                               Object *obj,
                               struct MUIP_InstallerGui_Number *msg)
{
    static Object *num, *top; 

    // Initial lookup. 
    if(!num)
    { 
        num = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_Number
        );

        top = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_TopGroup
        );
    } 

    // Sanity check.
    if(num)
    {
        // Set help bubble.
        set(top, MUIA_ShortHelp, msg->Help); 

        // Set min, max and default value.
        set(num, MUIA_Numeric_Min, msg->Min);
        set(num, MUIA_Numeric_Max, msg->Max);
        set(num, MUIA_Numeric_Value, msg->Default);

        // Show slider.
        if(InstallerGuiPageSet(obj, P_NUMBER, B_PROCEED_ABORT, 
                               msg->Message))
        {
            // Wait for proceed or abort.
            if(InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2) ==
               MUIV_InstallerGui_Proceed)
            {
                ULONG res = 0; 

                // On proceed get and return
                // numerical value.
                get(num, MUIA_Numeric_Value, &res); 
                return res;
            }
            else
            {
                // On abort return HALT.
                *((int *) msg->Halt) = 1; 
                return 0; 
            }
        }
    }

    // Unknown error.
    GERR(tr(S_UNER)); 
    return 0; 
}

//----------------------------------------------------------------------------
// InstallerGuiCheckBoxes - Show list of radiobuttons
// Input:                   Message - The prompt 
//                          Help - Help text
//                          Names - Array of choices (strings)
//                          Default - Default bitmask
//                          Halt - Halt return value
// Return:                  A bitmask representing the selected button(s)
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiCheckBoxes(Class *cls,
                                   Object *obj,
                                   struct MUIP_InstallerGui_CheckBoxes *msg)
{
    static Object *grp, *top; 

    // Initial lookup. 
    if(!grp)
    { 
        grp = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_EmptyGroup
        );

        top = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_TopGroup
        );
    } 

    // Sanity check and set the correct page.
    if(grp && top &&
       InstallerGuiPageSet(obj, P_MESSAGE, B_PROCEED_ABORT, 
                           msg->Message))
    {
        // Unlike most other pages, this one is
        // partly generated on the fly, we have
        // no choice.
        if(DoMethod(grp, MUIM_Group_InitChange))
        {
            ULONG id; 
            size_t i = 0; 
            static Object * cb[33]; 
            const char **cs = (const char **) msg->Names; 

            // The maximum number of choices is 32.
            while(*cs && i < 32)
            {
                // Default selection.
                LONG sel = (msg->Default & (1 << i)) ? TRUE : FALSE;

                // New checkbox with default selection.
                Object *c = (Object *) MUI_NewObject
                (
                    MUIC_Group,
                    MUIA_Group_Horiz, TRUE,
                    MUIA_InputMode, MUIV_InputMode_Toggle,
                    MUIA_Selected, sel, 
                    MUIA_Group_Child, (Object *) MUI_NewObject(
                        MUIC_Image,
                        MUIA_Frame, MUIV_Frame_ImageButton,
                        MUIA_Image_Spec, MUII_CheckMark,
                        MUIA_Background, MUII_ButtonBack,
                        MUIA_Image_FreeVert, TRUE,
                        MUIA_ShowSelState, FALSE,
                        MUIA_Selected, sel, 
                        TAG_END),
                    MUIA_Group_Child, (Object *) MUI_NewObject(
                        MUIC_Text, 
                        MUIA_Text_Contents, *cs, 
                        TAG_END),
                    TAG_END
                );

                // On success, add it to the group and
                // save the adress.
                if(c)
                {
                    DoMethod(grp, OM_ADDMEMBER, c); 
                    cb[i++] = c; 
                    cs++; 
                } 
                else
                {
                    // On error, free all the previous ones
                    // and bail out.
                    GERR(tr(S_UNER)); 

                    while(i--)
                    {
                        DoMethod(grp, OM_REMMEMBER, cb[i]); 
                        MUI_DisposeObject(cb[i]);
                    }

                    // We're done modifying the group.
                    DoMethod(grp, MUIM_Group_ExitChange);
                    return 0; 
                }
            }

            // We're done modifying the group.
            DoMethod(grp, MUIM_Group_ExitChange);

            // Set help bubble.
            set(top, MUIA_ShortHelp, msg->Help); 

            // Wait for proceed or abort.
            id = InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2);

            // Remove all dynamic objects in group.
            if(DoMethod(grp, MUIM_Group_InitChange))
            {
                // Bitmask.
                IPTR ret = 0; 

                while(i--)
                {
                    ULONG sel = 0; 

                    get(cb[i], MUIA_Selected, &sel); 
                    ret |= (sel ? (1 << i) : 0);

                    DoMethod(grp, OM_REMMEMBER, cb[i]); 
                    MUI_DisposeObject(cb[i]);
                }

                DoMethod(grp, MUIM_Group_ExitChange);
    
                if(id != MUIV_InstallerGui_Proceed)
                {
                    // On abort return HALT.
                    *((int *) msg->Halt) = 1; 
                    ret = 0;
                }

                // Bitmap or zero on abort.
                return ret;
            }
        }
    }

    // Unknown error.
    GERR(tr(S_UNER)); 
    return 0;
}

//----------------------------------------------------------------------------
// InstallerGuiComplete - Show progress
// Input:                 Progress - Installer progress in %
// Return:                On success TRUE, FALSE otherwise.
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiComplete(Class *cls,
                                 Object *obj,
                                 struct MUIP_InstallerGui_Complete *msg)
{
    static Object *prg; 

    // Initial lookup. 
    if(!prg)
    {
        prg = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_Progress
        );
    }

    // Sanity check.
    if(prg)
    {
        // Cap value at 100%.
        int p = msg->Progress > 100 ? 
                100 : msg->Progress;

        // Set value and make sure that 
        // the gauge is shown.
        set(prg, MUIA_Gauge_Current, p);
        set(prg, MUIA_ShowMe, TRUE);

        return TRUE; 
    }
    else
    {
        // Unknown error.
        GERR(tr(S_UNER)); 
        return FALSE; 
    }
}

//----------------------------------------------------------------------------
// InstallerGuiConfirm - Get user confirmation before running shell command
// Input:                Message - The prompt 
//                       Help - Help text
// Return:               '1' = proceed, '0' = skip, '-1' = abort
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiConfirm(Class *cls,
                                Object *obj,
                                struct MUIP_InstallerGui_Confirm *msg)
{
    static Object *con, *but, *txt, *grp; 

    // Initial lookup. 
    if(!con)
    {
        con = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_TopPager
        );

        but = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_BottomPager
        );
        
        txt = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_Text
        );

        grp = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_TopGroup
        );
    }

    // Sanity check.
    if(con && but && txt && grp)
    {
        ULONG top = 0,
              btm = 0,
              str = 0; 

        // Set help bubble.
        set(grp, MUIA_ShortHelp, msg->Help); 

        // Save the current state of whatever we're
        // showing before we ask for confirmation.
        if(get(con, MUIA_Group_ActivePage, &top) &&
           get(but, MUIA_Group_ActivePage, &btm) &&
           get(txt, MUIA_Text_Contents, &str))
        {
            // Allocate memory to hold a copy of the
            // current message.
            size_t osz = strlen((char *) str) + 1;
            char *ost = calloc(osz, 1); 

            if(ost)
            {
                // Copy the current message. 
                memcpy(ost, (void *) str, osz);

                // Prompt for confirmation. 
                if(InstallerGuiPageSet(obj, P_MESSAGE, B_PROCEED_SKIP_ABORT, 
                                       msg->Message))
                {
                    // Sleep until we get valid input.
                    ULONG b = InstallerGuiWait(obj, MUIV_InstallerGui_ProceedRun, 3); 

                    // Restore everything so that things 
                    // look the way they did before the
                    // confirmation dialog was shown.
                    set(con, MUIA_Group_ActivePage, top);
                    set(but, MUIA_Group_ActivePage, btm);
                    set(txt, MUIA_Text_Contents, ost);

                    // We no longer need the old message.
                    free(ost);

                    // Take care of the user input.
                    switch(b)
                    {
                        case MUIV_InstallerGui_ProceedRun:
                            return 1; 

                        case MUIV_InstallerGui_SkipRun:
                            return 0; 

                        case MUIV_InstallerGui_AbortRun:
                            return -1; 
                    }
                }

                // We never did show the new message so
                // we can get rid of the old (current).
                free(ost);
            }
        }
    }

    // Unknown error.
    GERR(tr(S_UNER)); 
    return -1; 
}

//----------------------------------------------------------------------------
// InstallerGuiNew - Overloading OM_NEW
// Input:            See BOOPSI docs
// Return:           See BOOPSI docs
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiNew(Class *cls,
			                Object *obj,
			                struct opSet *msg)
{
    // Misc widgets.
    Object *el = NULL,
           *ul = NULL,
           *pr = NULL,
           *lg = NULL;

    // Radio buttons.
    static const char *lev[4],
                      *pre[3],
                      *log[3];

    // User level.
    lev[0] = tr(S_ULNV); // Novice
    lev[1] = tr(S_ULIN); // Intermediate
    lev[2] = tr(S_ULEX); // Expert

    // Pretend mode.
    pre[0] = tr(S_INRL); // For real
    pre[1] = tr(S_INDR); // Dry run

    // Logging mode.
    log[0] = tr(S_NOLG); // No logging
    log[1] = tr(S_SILG); // Log to file

    // The GUI is, as far as possible, a static 
    // construct. We're not constructing things
    // on the fly, instead we use paging to let
    // widgets become visible / disappear.
    obj = (Object *) DoSuperNew
    (
        cls, obj, 
        MUIA_Window_Title, tr(S_INST),
        MUIA_Window_AppWindow, TRUE,
        MUIA_Window_RootObject, MUI_NewObject(
            MUIC_Group,
            MUIA_UserData, MUIV_InstallerGui_TopGroup, 
            MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
            /* Top text */
            MUIA_Group_Child, (Object *) MUI_NewObject(
                MUIC_Text, 
                MUIA_UserData, MUIV_InstallerGui_Text, 
                MUIA_Text_Contents, "\n\n\n\n\n\n\n\n\n\n",
                MUIA_Text_SetMax, FALSE, 
                MUIA_Text_PreParse, "\33c", 
                TAG_END),
            /* Top pager */
            MUIA_Group_Child, MUI_NewObject(
                MUIC_Group,
                MUIA_Group_PageMode, TRUE,
                MUIA_UserData, MUIV_InstallerGui_TopPager, 
                /* Page 0 - P_WELCOME */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
                    MUIA_Group_Child, (Object *) MUI_NewObject(
                        MUIC_Rectangle, 
                        MUIA_Rectangle_HBar, TRUE, 
                        MUIA_Rectangle_BarTitle, tr(S_INMD),
                        TAG_END),
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Group,
                        MUIA_Group_Horiz, TRUE,
                        MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 32),
                        MUIA_Group_Child, ul = (Object *) MUI_NewObject(
                            MUIC_Radio,
                            MUIA_UserData, MUIV_InstallerGui_UserLevel,
                            MUIA_Radio_Entries, lev,
                            TAG_END),
                        MUIA_Group_Child, el = (Object *) MUI_NewObject(
                            MUIC_Radio,
                            MUIA_ShowMe, FALSE,
                            MUIA_UserData, MUIV_InstallerGui_UserLevel,
                            MUIA_Radio_Entries, lev + 1,
                            TAG_END),
                        MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 32),
                        TAG_END),
                    TAG_END),
                /* Page 1 - P_COPYFILES */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Child, (Object *) MUI_NewObject(
                        MUIC_Rectangle, 
                        MUIA_Rectangle_HBar, TRUE, 
                        MUIA_Rectangle_BarTitle, tr(S_CPYF),
                        TAG_END),
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Gauge, 
                        MUIA_ShowMe, TRUE,
                        MUIA_UserData, MUIV_InstallerGui_FileProgress, 
                        MUIA_Gauge_Horiz, TRUE,
                        MUIA_Gauge_InfoText, "-",
                        TAG_END),
                    TAG_END),
                /* Page 2 - P_FILEDEST */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Child, (Object *) MUI_NewObject(
                        MUIC_Rectangle, 
                        MUIA_Rectangle_HBar, TRUE, 
                        MUIA_Rectangle_BarTitle, tr(S_F2IN),
                        TAG_END),
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Listview,
                        MUIA_Listview_List, MUI_NewObject(
                            MUIC_List, 
                            MUIA_ShowMe, FALSE,
                            MUIA_UserData, MUIV_InstallerGui_FileList, 
                            TAG_END),
                        MUIA_Listview_MultiSelect, MUIV_Listview_MultiSelect_Always,
                        TAG_END),
                    TAG_END),
                /* Page 3 - P_PRETEND_LOG */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Child, (Object *) MUI_NewObject(
                        MUIC_Rectangle, 
                        MUIA_Rectangle_HBar, TRUE, 
                        MUIA_Rectangle_BarTitle, tr(S_IMAL),
                        TAG_END),
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Group,
                        MUIA_Group_Horiz, TRUE,
                        MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                        MUIA_Group_Child, pr = (Object *) MUI_NewObject(
                            MUIC_Radio, 
                            MUIA_UserData, MUIV_InstallerGui_Pretend,
                            MUIA_Radio_Entries, pre, 
                            TAG_END),
                        MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                        MUIA_Group_Child, lg = (Object *) MUI_NewObject(
                            MUIC_Radio, 
                            MUIA_UserData, MUIV_InstallerGui_Logging,
                            MUIA_Radio_Entries, log, 
                            TAG_END),
                        MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                        TAG_END),
                    TAG_END),
                /* Page 4 - P_MESSAGE */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Horiz, TRUE,
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                    MUIA_Group_Child, (Object *) MUI_NewObject(
                        MUIC_Group,
                        MUIA_UserData, MUIV_InstallerGui_EmptyGroup, 
                        MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
                        TAG_END),
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                    TAG_END),
                /* Page 5 - P_STRING */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
                    MUIA_Group_Child, (Object *) MUI_NewObject(
                        MUIC_String, 
                        MUIA_UserData, MUIV_InstallerGui_String,
                        MUIA_Frame, MUIV_Frame_String, 
                        MUIA_String_MaxLen, BUFSIZ, 
                        TAG_END),
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
                    TAG_END),
                /* Page 6 - P_NUMBER */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
                    MUIA_Group_Child, (Object *) MUI_NewObject(
                        MUIC_Slider, 
                        MUIA_Slider_Horiz, TRUE, 
                        MUIA_UserData, MUIV_InstallerGui_Number,
                        TAG_END),
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
                    TAG_END),
                /* Page 7 - P_ASKFILE */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_UserData, MUIV_InstallerGui_AskFile, 
                    TAG_END),
                TAG_END),
            /* Progress bar */
            MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
            MUIA_Group_Child, MUI_NewObject(
                MUIC_Gauge, 
                MUIA_ShowMe, FALSE,
                MUIA_UserData, MUIV_InstallerGui_Progress, 
                MUIA_Gauge_Horiz, TRUE,
                MUIA_Gauge_InfoText, tr(S_PGRS),
                TAG_END),
            /* Bottom pager */
            MUIA_Group_Child, MUI_NewObject(
                MUIC_Group,
                MUIA_Group_PageMode, TRUE,
                MUIA_UserData, MUIV_InstallerGui_BottomPager, 
                /* Page 0 - B_PROCEED_ABORT */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Horiz, TRUE,
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_InstallerGui_Proceed, 
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_PRCD),
                        MUIA_Text_PreParse, "\33c", 
                        MUIA_InputMode, MUIV_InputMode_RelVerify, 
                        MUIA_Background, MUII_ButtonBack, 
                        TAG_END),
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_InstallerGui_Abort, 
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_ABRT),
                        MUIA_Text_PreParse, "\33c", 
                        MUIA_InputMode, MUIV_InputMode_RelVerify, 
                        MUIA_Background, MUII_ButtonBack, 
                        TAG_END),
                    TAG_END),
                /* Page 1 - B_YES_NO */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Horiz, TRUE,
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_InstallerGui_Yes, 
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_AYES),
                        MUIA_Text_PreParse, "\33c", 
                        MUIA_InputMode, MUIV_InputMode_RelVerify, 
                        MUIA_Background, MUII_ButtonBack, 
                        TAG_END),
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_InstallerGui_No, 
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_NONO),
                        MUIA_Text_PreParse, "\33c", 
                        MUIA_InputMode, MUIV_InputMode_RelVerify, 
                        MUIA_Background, MUII_ButtonBack, 
                        TAG_END),
                    TAG_END),
                /* Page 2 - B_ABORT */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Horiz, TRUE,
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_InstallerGui_AbortOnly, 
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_ABRT),
                        MUIA_Text_PreParse, "\33c", 
                        MUIA_InputMode, MUIV_InputMode_RelVerify, 
                        MUIA_Background, MUII_ButtonBack, 
                        TAG_END),
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                    TAG_END),
                /* Page 3 - B_PROCEED_SKIP_ABORT */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Horiz, TRUE,
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_InstallerGui_ProceedRun, 
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_PRCD),
                        MUIA_Text_PreParse, "\33c", 
                        MUIA_InputMode, MUIV_InputMode_RelVerify, 
                        MUIA_Background, MUII_ButtonBack, 
                        TAG_END),
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_InstallerGui_SkipRun, 
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_SKIP),
                        MUIA_Text_PreParse, "\33c", 
                        MUIA_InputMode, MUIV_InputMode_RelVerify, 
                        MUIA_Background, MUII_ButtonBack, 
                        TAG_END),
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_InstallerGui_AbortRun, 
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_ABRT),
                        MUIA_Text_PreParse, "\33c", 
                        MUIA_InputMode, MUIV_InputMode_RelVerify, 
                        MUIA_Background, MUII_ButtonBack, 
                        TAG_END),
                    TAG_END),
                /* Page 4 - B_PROCEED */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Horiz, TRUE,
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_InstallerGui_ProceedOnly, 
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_PRCD),
                        MUIA_Text_PreParse, "\33c", 
                        MUIA_InputMode, MUIV_InputMode_RelVerify, 
                        MUIA_Background, MUII_ButtonBack, 
                        TAG_END),
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                    TAG_END),
                /* Page 5 - B_NONE */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Horiz, TRUE,
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                    TAG_END),
                TAG_END),
            TAG_END),
        TAG_END
    );
    
    // Initialize the rest if the superclass is OK.
    if(obj)
    {
        struct InstallerGuiData *my = INST_DATA(cls, obj);

        // Initialize timer struct.
        my->Ticker.ihn_Object = obj;
        my->Ticker.ihn_Flags = MUIIHNF_TIMER;
        my->Ticker.ihn_Method = MUIM_InstallerGui_Ticker;
        my->Ticker.ihn_Millis = 50;

        // Save values for later access to some
        // of the widgets above.
        if(el && el && pr && lg)
        {
            my->ExpertLevel = el;
            my->UserLevel = ul;
            my->Pretend = pr;
            my->Log = lg;
        }
        else
        {
            // Forgot something.
            MUI_DisposeObject(obj);
            obj = NULL;
        }
    }

    // Done.
    return (IPTR) obj;
}

//----------------------------------------------------------------------------
// InstallerGuiSetup - Overloading MUIM_Setup
// Input:              See MUI docs
// Return:             See MUI docs
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiSetup(Class *cls,
                              Object *obj,
                              struct MUI_RenderInfo *msg)
{
    // Let our parent set itself up first  
    if(!DoSuperMethodA (cls, obj, (Msg) msg))
    {
        GERR(tr(S_STFL)); 
        return FALSE;
    }

    return TRUE;
}

//----------------------------------------------------------------------------
// InstallerGuiDispose - Overloading OM_DISPOSE
// Input:                See BOOPSI docs
// Return:               See BOOPSI docs
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiDispose (Class *cls,
                                 Object *obj,
                                 Msg msg)
{
    return (IPTR) DoSuperMethodA(cls, obj, msg);
}

//----------------------------------------------------------------------------
// InstallerGuiCleanup - Overloading MUIM_Cleanup
// Input:                See MUI docs
// Return:               See MUI docs
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiCleanup (Class *cls,
                                 Object *obj,
                                 Msg msg)
{
    return (IPTR) DoSuperMethodA(cls, obj, (Msg) msg);
}

//----------------------------------------------------------------------------
// InstallerGuiDispatch - MUI custom class dispatcher
// Input:                 pass through 
// Return:                pass through
//----------------------------------------------------------------------------
DISPATCH(InstallerGui)
{
    DISPATCH_HEAD; 

    // Dispatch according to MethodID
    switch (msg->MethodID)
    {
        case OM_NEW:
            return InstallerGuiNew (cls, obj, (struct opSet *) msg);

        case MUIM_Setup:
            return InstallerGuiSetup (cls, obj, (struct MUI_RenderInfo *) msg);

        case OM_DISPOSE:
            return InstallerGuiDispose (cls, obj, msg);

        case MUIM_Cleanup:
            return InstallerGuiCleanup (cls, obj, msg);

        case MUIM_InstallerGui_Init:
            return InstallerGuiInit(cls, obj); 

        case MUIM_InstallerGui_Welcome:
            return InstallerGuiWelcome(cls, obj, (struct MUIP_InstallerGui_Welcome *) msg);

        case MUIM_InstallerGui_AskFile:
            return InstallerGuiAskFile(cls, obj, (struct MUIP_InstallerGui_AskFile *) msg);

        case MUIM_InstallerGui_CopyFilesStart:
            return InstallerGuiCopyFilesStart(cls, obj, (struct MUIP_InstallerGui_CopyFilesStart *) msg);

        case MUIM_InstallerGui_CopyFilesSetCur:
            return InstallerGuiCopyFilesSetCur(cls, obj, (struct MUIP_InstallerGui_CopyFilesSetCur *) msg);

        case MUIM_InstallerGui_CopyFilesEnd:
            return InstallerGuiCopyFilesEnd(cls, obj); 

        case MUIM_InstallerGui_CopyFilesAdd:
            return InstallerGuiCopyFilesAdd(cls, obj, (struct MUIP_InstallerGui_CopyFilesAdd *) msg);

        case MUIM_InstallerGui_Exit:
            return InstallerGuiExit(cls, obj, (struct MUIP_InstallerGui_Exit *) msg);

        case MUIM_InstallerGui_Message:
            return InstallerGuiMessage(cls, obj, (struct MUIP_InstallerGui_Message *) msg);

        case MUIM_InstallerGui_Radio:
            return InstallerGuiRadio(cls, obj, (struct MUIP_InstallerGui_Radio *) msg);

        case MUIM_InstallerGui_Bool:
            return InstallerGuiBool(cls, obj, (struct MUIP_InstallerGui_Bool *) msg);

        case MUIM_InstallerGui_String:
            return InstallerGuiString(cls, obj, (struct MUIP_InstallerGui_String *) msg);

        case MUIM_InstallerGui_Number:
            return InstallerGuiNumber(cls, obj, (struct MUIP_InstallerGui_Number *) msg);

        case MUIM_InstallerGui_CheckBoxes:
            return InstallerGuiCheckBoxes(cls, obj, (struct MUIP_InstallerGui_CheckBoxes *) msg);

        case MUIM_InstallerGui_Complete:
            return InstallerGuiComplete(cls, obj, (struct MUIP_InstallerGui_Complete *) msg);

        case MUIM_InstallerGui_Ticker:
            return DoMethod(_app(obj), MUIM_Application_ReturnID, MUIV_InstallerGui_Tick); 

        case MUIM_InstallerGui_Confirm:
            return InstallerGuiConfirm(cls, obj, (struct MUIP_InstallerGui_Confirm *) msg);
    }

    // Unknown method, promote to parent.
    return DoSuperMethodA (cls, obj, msg);
}
#endif /* AMIGA */


//____________________________________________________________________________
//############################################################################
//############################################################################
//############################################################################
//****************************************************************************
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//............................................................................
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//.   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .  .
//
//
// The gui_* functions below serve as glue between the platform independent
// parts of InstallerNG and the Amiga specific Zune / MUI parts. On non Amiga
// systems, arguments are typically written to stdout to facilitate testing.
//
//
//.   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .  .
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//****************************************************************************
//############################################################################
//############################################################################
//############################################################################


//----------------------------------------------------------------------------
// Name:        gui_init
// Description: Initialize and show GUI.
// Input:       -
// Return:      int:    TRUE on success, FALSE otherwise. 
//----------------------------------------------------------------------------
int gui_init(void)
{
    #ifdef AMIGA
    Object *App; 

    // Create our GUI class.
    InstallerGuiClass = (struct MUI_CustomClass *) MUI_CreateCustomClass
    (
	    NULL, MUIC_Window, NULL,
        sizeof (struct CLASS_DATA(InstallerGui)),
        (APTR) DISPATCH_GATE (InstallerGui)
    );

    // Bail out on error.
    if(!InstallerGuiClass)
    {
        GERR(tr(S_FMCC)); 
        return FALSE;
    }

    // Create application using our newly created class.
    App = (Object *) MUI_NewObject(
        MUIC_Application,
        MUIA_Application_Title, tr(S_INST),
        MUIA_Application_Window, Win = (Object *) NewObject(
            InstallerGuiClass->mcc_Class, NULL, 
            TAG_END),
        TAG_END
    ); 

    // Bail out on error.
    if(!App)
    {
        GERR(tr(S_MAPP));
        return FALSE;
    }

    // Internal initialization.
    if(!DoMethod(Win, MUIM_InstallerGui_Init))
    {
        // Bail out on error.
        GERR(tr(S_FINT));
        gui_exit(); 

        return FALSE;
    }

    // Open the window to finish setup. 
    set(Win, MUIA_Window_Open, TRUE);
    DoMethod(Win, MUIM_Show);

    return TRUE;
    #else
    // Testing purposes.
    return 1;
    #endif
}

//----------------------------------------------------------------------------
// Name:        gui_exit
// Description: Close GUI and free GUI resources.
// Input:       -
// Return:      -
//----------------------------------------------------------------------------
void gui_exit(void)
{
    #ifdef AMIGA
    // Close window and destroy app
    set(Win, MUIA_Window_Open, FALSE);
    MUI_DisposeObject(_app(Win));

    // Destroy custom class. Must check for NULL.
    if(InstallerGuiClass)
    {
        MUI_DeleteCustomClass(InstallerGuiClass);
    }
    #endif
}

//----------------------------------------------------------------------------
// Name:        gui_message
// Description: Show message.
// Input:       const char *msg:    Message shown to the user. 
//              int imm:            No proceed button.
// Return:      -
//----------------------------------------------------------------------------
void gui_message(const char *msg, int imm)
{
    #ifdef AMIGA
    DoMethod(Win, MUIM_InstallerGui_Message, msg, imm);
    #else
    // Testing purposes.
    if(imm)
    {
        printf("%d:%s", imm, msg); 
    }
    else
    {
        fputs(msg, stdout); 
    }
    #endif
}

//----------------------------------------------------------------------------
// Name:        gui_choice
// Description: Get user selecton of a single string out of a list of strings.
// Input:       const char *msg:    Message shown to the user. 
//              const char *hlp:    Help text.
//              const char **nms:   List of strings.
//              int def:            Default choice (0-index)
//              int *hlt:           Halt return value.
// Return:      int:                The choice (0-index).
//----------------------------------------------------------------------------
int gui_choice(const char *msg, 
               const char *hlp,
               const char **nms, 
               int def, 
               int *hlt)
{
    int ret = (int)
    #ifdef AMIGA
    DoMethod
    (
        Win, 
        MUIM_InstallerGui_Radio, 
        msg, 
        hlp, 
        nms, 
        def,
        hlt
    );
    #else
    // Testing purposes.
    printf("%s%s%s%d\n", msg, hlp, *nms, def) ? def : 0;
    // Don't halt on non Amiga systems.
    *hlt = 0; 
    #endif

    return ret; 
}

//----------------------------------------------------------------------------
// Name:        gui_options
// Description: Get user selection of any number / combination of strings
//              from a list.
// Input:       const char *msg:    Message shown to the user. 
//              const char *hlp:    Help text.
//              const char **nms:   List of strings from which to choose.
//              int def:            Default bitmap.
//              int *hlt:           Halt return value.
// Return:      int:                A bitmap representing the selection.
//----------------------------------------------------------------------------
int gui_options(const char *msg, 
                const char *hlp,
                const char **nms, 
                int def,
                int *hlt)
{
    int ret = (int)
    #ifdef AMIGA
    DoMethod
    (
        Win, 
        MUIM_InstallerGui_CheckBoxes, 
        msg, 
        hlp, 
        nms, 
        def,
        hlt
    );
    #else
    // Testing purposes.
    printf("%s%s%s%d%d\n", msg, hlp, *nms, def, *hlt) ? def : 0;
    #endif

    return ret;
}

//----------------------------------------------------------------------------
// Name:        gui_bool
// Description: Get boolean value from user, e.g 'Yes' / 'No'.
// Input:       const char *msg:    Message shown to the user. 
//              const char *hlp:    Help text.
//              const char *yes:    True string. 
//              const char *no:     False string.
// Return:      int:                '1' or '0'.
//----------------------------------------------------------------------------
int gui_bool(const char *msg,
             const char *hlp,
             const char *yes,
             const char *no)
{
    int ret = (int)
    #ifdef AMIGA
    DoMethod
    (
        Win, 
        MUIM_InstallerGui_Bool, 
        msg, 
        hlp, 
        yes, 
        no 
    );
    #else
    // Testing purposes.
    printf("%s%s%s%s\n", msg, hlp, yes, no) ? 1 : 0;
    #endif
    return ret;
}

//----------------------------------------------------------------------------
// Name:        gui_string
// Description: Get string value from user.
// Input:       const char *msg:    Message shown to the user. 
//              const char *hlp:    Help text.
//              const char *def:    Default string value.
//              int *hlt:           Halt return value.
// Return:      const char *:       String value from user.
//----------------------------------------------------------------------------
const char * gui_string(const char *msg, 
                        const char *hlp,
                        const char *def,
                        int *hlt)
{
    const char *ret = (const char *)
    #ifdef AMIGA
    DoMethod
    (
        Win, 
        MUIM_InstallerGui_String, 
        msg, 
        hlp, 
        def,
        hlt
    );
    #else
    // Testing purposes.
    (printf("%s%s%s\n", msg, hlp, def) ? def : "");

    // Don't halt on non Amiga systems.
    *hlt = 0; 
    #endif
    return ret;
}

//----------------------------------------------------------------------------
// Name:        gui_number
// Description: Get numerical value from user.
// Input:       const char *msg:    Message shown to the user. 
//              const char *hlp:    Help text.
//              int min:            Minimum value.
//              int max:            Maximum value.
//              int def:            Default value.
//              int *hlt:           Halt return value.
// Return:      int:                Numerical value from user.
//----------------------------------------------------------------------------
int gui_number(const char *msg, 
               const char *hlp,
               int min, 
               int max, 
               int def, 
               int *hlt)
{
    int ret = (int) 
    #ifdef AMIGA
    DoMethod
    (
        Win, 
        MUIM_InstallerGui_Number, 
        msg, 
        hlp, 
        min, 
        max, 
        def,
        hlt
    );
    #else
    // Testing purposes.
    (printf("%s%s%d%d\n", msg, hlp, min, max) ? def : 0);

    // Don't halt on non Amiga systems.
    *hlt = 0; 
    #endif
    return ret;
}

//----------------------------------------------------------------------------
// Name:        gui_welcome
// Description: Show welcome message and prompt for user level / installer
//              mode. Note that the 'lvl', 'lgf', and 'prt' parameters act
//              as both input and output.
// Input:       const char *msg:    Welcome message.
//              int *lvl:           User level return and input value.
//              int *lgf:           Log settings return and input value.
//              int *prt:           Pretend mode return and input value.
//              int min:            Minimum user level.
//              int npr:            Disable pretend mode.
//              int nlg:            Disable logging.
// Return:      int:                1 on success, 0 on abort.
//----------------------------------------------------------------------------
int gui_welcome(const char *msg,
                int *lvl,
                int *lgf,
                int *prt,
                int min,
                int npr,
                int nlg)
{
    int ret = (int)
    #ifdef AMIGA
    DoMethod
    (
        Win, MUIM_InstallerGui_Welcome,
        msg,
        lvl,
        lgf,
        prt,
        min,
        npr,
        nlg
    );
    #else
    1;
    // Testing purposes.
    printf
    (
        "%s%d%d%d%d%d%d\n",
        msg,
        *lvl,
        *lgf,
        *prt,
        min,
        npr,
        nlg
    );
    #endif

    return ret;
}

//----------------------------------------------------------------------------
// Name:        gui_askdir
// Description: Get directory name from user.
// Input:       const char *msg:    Message shown to the user. 
//              const char *hlp:    Help text.
//              int pth:            Allow non-existing default.
//              int dsk:            Show drive list first.
//              int asn:            Assigns can satisfy the request as well.
//              const char *def:    Default value.
// Return:      const char*:        Dir name on success, NULL otherwise.
//----------------------------------------------------------------------------
const char *gui_askdir(const char *msg, 
                       const char *hlp,
                       int pth,
                       int dsk,
                       int asn, 
                       const char *def)
{
    const char *ret = (const char *)
    #ifdef AMIGA
    DoMethod
    (
        Win, MUIM_InstallerGui_AskFile, 
        msg, hlp, pth, dsk, asn, def, TRUE
    );
    #else
    // Testing purposes.
    (printf("%s%s%d%d%d%s\n", msg, hlp, pth, dsk, asn, def) ? def : "");
    #endif

    return ret;
}

//----------------------------------------------------------------------------
// Name:        gui_askfile
// Description: Get filename from user.
// Input:       const char *msg:    Message shown to the user. 
//              const char *hlp:    Help text.
//              int pth:            Allow non-existing default.
//              int dsk:            Show drive list first.
//              const char *def:    Default value.
// Return:      const char*:        Filename on success, NULL otherwise.
//----------------------------------------------------------------------------
const char *gui_askfile(const char *msg, 
                        const char *hlp,
                        int pth,
                        int dsk,
                        const char *def)
{
    const char *ret = (const char *) 
    #ifdef AMIGA
    DoMethod
    (
        Win, MUIM_InstallerGui_AskFile, 
        msg, hlp, pth, dsk, FALSE, def, FALSE
    );
    #else
    // Testing purposes.
    (printf("%s%s%d%d\n", msg, hlp, pth, dsk) ? def : "");
    #endif

    return ret;
}

//----------------------------------------------------------------------------
// Name:        gui_copyfiles_start
// Description: Show file copy confirmation requester with a populated file
//              list. 
// Input:       const char *msg:    Message to be shown.
//              const char *hlp:    Help text.
//              pnode_p lst:        List of files / directories.
//              int cnf:            Confirmation.
// Return:      int:                '1' - proceed, '0' - skip, '-1' abort.
//----------------------------------------------------------------------------
int gui_copyfiles_start(const char *msg, const char *hlp, pnode_p lst, int cnf)
{
    #ifdef AMIGA
    int n = 0; 
    pnode_p cur = lst; 

    // For all files and directories to be copied; count 
    // the files, and if confirmation is needed, add them
    // to the selection / deselection list.
    while(cur)
    {
        // Is this a file?
        if(cur->type == 1)
        {
            // Do we need confirmation?
            if(cnf)
            {
                // Add file to the selection / deselection list.
                DoMethod(Win, MUIM_InstallerGui_CopyFilesAdd, cur->name);
            }

            // Increase the total file count.
            n++; 
        }

        // Next file / directory.
        cur = cur->next; 
    }

    // Do we need confirmation?
    if(cnf && n)
    {
        static Object *sel, *top;
        
        // Initial lookup.
        if(!sel) 
        {
            sel = (Object *) DoMethod
            (
                Win, MUIM_FindUData, 
                MUIV_InstallerGui_FileList
            );

            top = (Object *) DoMethod
            (
                Win, MUIM_FindUData, 
                MUIV_InstallerGui_TopGroup
            );
        }

        // Show the file selection page.
        if(sel && top && InstallerGuiPageSet
          (Win, P_FILEDEST, B_PROCEED_SKIP_ABORT, (ULONG) msg))
        {
            ULONG b; 
            LONG id = MUIV_List_NextSelected_Start; 

            // Set help text.
            set(top, MUIA_ShortHelp, hlp); 

            // The default is to copy all files.
            DoMethod(sel, MUIM_List_Select, MUIV_List_Select_All,
                          MUIV_List_Select_On, NULL); 

            // Wait for confirmation / skip / abort.
            b = InstallerGuiWait(Win, MUIV_InstallerGui_ProceedRun, 3); 

            // Did the user confirm?
            if(b == MUIV_InstallerGui_ProceedRun)
            {
                // For all files in the selection / deselection
                // list, tag the ones that we're going to copy.
                for(;;) 
                {
                    // Get the first element in the list.
                    DoMethod(sel, MUIM_List_NextSelected, &id); 

                    // Are we done with all of the files?
                    if(id != MUIV_List_NextSelected_End)
                    {
                        // Get name of current file?
                        char *ent = NULL;
                        DoMethod(sel, MUIM_List_GetEntry, id, &ent); 

                        if(ent) 
                        {
                            // Find the corresponding file node
                            // in 'our' list.
                            for(cur = lst; cur; 
                                cur = cur->next)
                            {
                                // If we find it, and it's a file,
                                // give it a 'copy' tag.
                                if(cur->type == 1 &&
                                   !strcmp(ent, cur->name))
                                {
                                    cur->type = -1; 
                                    break; 
                                }
                            }
                        }
                    }
                    else
                    {
                        // We're done with all files in the
                        // selection / deselection list.
                        break; 
                    }
                }

                // Iterate over nodes in 'our' list and tag
                // everything that we're NOT going to copy.
                for(cur = lst; cur; 
                    cur = cur->next)
                {
                    // Is this a file that's not going to be
                    // copied?
                    if(cur->type == 1)
                    {
                        // Give it an 'ignore' tag and decrease
                        // the number of files to be copied.
                        n--;
                        cur->type = 0; 
                    }
                    // Is this a file that's going to be copied?
                    else if(cur->type == -1)
                    {
                        // Restore the file type so that the 
                        // rest of the world understands that
                        // this is a file.
                        cur->type = 1; 
                    }
                }
            }
            else
            {
                // Are we going to skip the file copy or are
                // we going to abort?
                return b == MUIV_InstallerGui_SkipRun ?
                       0 : -1; 
            }
        }
        else
        {
            // Unknown error.
            GERR(tr(S_UNER)); 
            return FALSE; 
        }
    }

    // Set up the file copy progress page.
    return (int) DoMethod(Win, MUIM_InstallerGui_CopyFilesStart, msg, n);
    #else
    // Testing purposes.
    return lst ? (cnf ? ((msg && hlp) ? 0 : -1) : 1) : -1;
    #endif
}

//----------------------------------------------------------------------------
// Name:        gui_copyfiles_setcur
// Description: Update progress gauge and show current filename.
// Input:       const char *cur:    Filename.
//              int nogauge:        Hide gauge.
// Return:      int:                TRUE on success, FALSE otherwise.
//----------------------------------------------------------------------------
int gui_copyfiles_setcur(const char *cur, int nogauge) 
{
    return (int)
    #ifdef AMIGA
    DoMethod(Win, MUIM_InstallerGui_CopyFilesSetCur, cur, nogauge);
    #else
    // Testing purposes.
    (cur ? 1 + nogauge : 0);
    #endif
}

//----------------------------------------------------------------------------
// Name:        gui_copyfiles_end
// Description: End file copy. Must be invoked after gui_copyfiles_start().
// Input:       -
// Return:      -
//----------------------------------------------------------------------------
void gui_copyfiles_end(void) 
{
    #ifdef AMIGA
    DoMethod(Win, MUIM_InstallerGui_CopyFilesEnd); 
    #endif
}

//----------------------------------------------------------------------------
// Name:        gui_complete
// Description: Show progress gauge.
// Input:       int com:            Progress in percent.
// Return:      int:                TRUE on success, FALSE otherwise.
//----------------------------------------------------------------------------
int gui_complete(int com)
{
    return (int)
    #ifdef AMIGA
    DoMethod(Win, MUIM_InstallerGui_Complete, com);
    #else
    // Testing purposes.
    com; 
    #endif
}

//----------------------------------------------------------------------------
// Name:        gui_confirm
// Description: Get user confirmation.
// Input:       const char *msg:    Message shown to the user. 
//              const char *hlp:    Help text.
// Return:      int:                '1' = proceed, '0' = skip, '-1' = abort
//----------------------------------------------------------------------------
int gui_confirm(const char *msg, const char *hlp)
{
    return (int)
    #ifdef AMIGA
    DoMethod(Win, MUIM_InstallerGui_Confirm, msg, hlp);
    #else
    // Testing purposes.
    printf("%s%s\n", msg, hlp) ? 1 : 0;
    #endif
}

//----------------------------------------------------------------------------
// Name:        gui_error
// Description: Show error message.
// Input:       int id:             Line number.
//              const char *type:   Error description.
//              const char *info:   Extra info, e.g. filename.
// Return:      int:                1
//----------------------------------------------------------------------------
int gui_error(int id, 
              const char *type, 
              const char *info)
{
    #ifdef AMIGA
    static char err[BUFSIZ]; 
    static struct EasyStruct es = 
    {
        .es_TextFormat = (UBYTE *) &err,
        .es_StructSize = sizeof(struct EasyStruct), 
    };

    es.es_Title = (UBYTE *) tr(S_ERRS); 
    es.es_GadgetFormat = (UBYTE *) tr(S_OKEY); 
    snprintf(err, sizeof(err), tr(S_LERR), id, type, info);

    // We don't have any way of knowing
    // whether this really works out...
    EasyRequest(NULL, &es, NULL);

    // Ignore the user feedback.
    return 1; 
    #else
    // Testing purposes.
    return (id && type && info) ? 0 : 1;
    #endif
}

