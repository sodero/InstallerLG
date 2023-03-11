//------------------------------------------------------------------------------
// gui.c:
//
// MUI based GUI. On non Amiga systems this is, except for some stdout prints
// to aid testing, a stub.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2023, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "args.h"
#include "debug.h"
#include "gui.h"
#include "resource.h"
#include "version.h"

#if defined(AMIGA) && !defined(LG_TEST)
# include <graphics/rpattr.h>
# include <libraries/asl.h>
# include <libraries/mui.h>
# if !defined(__VBCC__) && !defined(__amigaos4__)
#  include <proto/alib.h>
# endif
# ifndef __MORPHOS__
#  if !defined(__VBCC__) && !defined(__amigaos4__)
#   include <proto/debug.h>
#  else
#   include <datatypes/datatypesclass.h>
#  endif
# else
#  include <clib/debug_protos.h>
# endif
# include <proto/exec.h>
# include <proto/datatypes.h>
# include <proto/dos.h>
# include <proto/graphics.h>
# include <proto/intuition.h>
# include <proto/muimaster.h>
# include <proto/utility.h>
# ifdef __amigaos4__
#  include <dos/obsolete.h>
   typedef unsigned long IPTR;
   struct Library *MUIMasterBase;
   struct MUIMasterIFace *IMUIMaster;
# endif
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/time.h>
#ifndef __GNUC__
# define __attribute__(a)
#endif

#if defined(AMIGA) && !defined(LG_TEST)
//------------------------------------------------------------------------------
// MUI
//------------------------------------------------------------------------------
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
# if !defined(__VBCC__) && !defined(__amigaos4__)
#  define DoSuperNew(C,O,...) DoSuperNewTags(C,O,NULL,__VA_ARGS__)
# else
Object *STDARGS VARARGS68K DoSuperNew(struct IClass *cl, Object *obj, ...)
{
    Object *rc;
    va_list args;
    struct opSet msg;

    va_start(args, obj);
    msg.MethodID = OM_NEW;
    msg.ops_AttrList = va_getlinearva(args, struct TagItem *);
    msg.ops_GInfo = NULL;
    rc = (Object *) DoSuperMethodA(cl, obj, (Msg)&msg);
    va_end(args);

    return rc;
}
# endif
# define DISPATCH_HEAD
# define DISPATCH_ARGS Class *cls, Object *obj, Msg msg
# define DISPATCH_GATE(C) C ## Dispatch
# define CLASS_DEF(C) \
  struct MUI_CustomClass * C ## Class; \
  struct C ## Data
#endif
#define DISPATCH(C) static IPTR C ## Dispatch (DISPATCH_ARGS)
#define CLASS_DATA(C) C ## Data
#define TAGBASE_LG (TAG_USER | 27<<16)
#define MUIDSP static IPTR

//------------------------------------------------------------------------------
// Debug and logging macros
//------------------------------------------------------------------------------
#ifdef __amigaos4__
# define KPrintF DebugPrintF
#endif
#define GPUT(E,S) KPrintF((CONST_STRPTR)"%s:\t%s\t(%s:%d)\n",E,S,__func__,\
    __LINE__)
#define GERR(S) GPUT("ERR",S)

//------------------------------------------------------------------------------
// IG - Installer window
//------------------------------------------------------------------------------
Object *Win;

//------------------------------------------------------------------------------
// IG - Class members
//------------------------------------------------------------------------------
CLASS_DEF(IG)
{
    // Timer.
    struct MUI_InputHandlerNode Ticker;

    // Backdrop screen / window.
    struct Screen *Scr;
    struct Window *Win;

    // Widgets.
    Object *ExpertLevel, *UserLevel, *Progress, *Pretend, *Bottom, *String,
        *Number, *Empty, *Text, *List, *Log, *Top, *Ask, *Yes, *No, *AbortYes,
        *Abort, *AbortOnly, *AbortRun;

    // String buffer.
    char Buf[1 << 10];
};

//------------------------------------------------------------------------------
// IG - Public methods
//------------------------------------------------------------------------------
#define MUIM_IG_Init                (TAGBASE_LG + 101)
#define MUIM_IG_Welcome             (TAGBASE_LG + 102)
#define MUIM_IG_CopyFilesStart      (TAGBASE_LG + 104)
#define MUIM_IG_CopyFilesSetCur     (TAGBASE_LG + 105)
#define MUIM_IG_CopyFilesEnd        (TAGBASE_LG + 106)
#define MUIM_IG_Exit                (TAGBASE_LG + 107)
#define MUIM_IG_Complete            (TAGBASE_LG + 108)
#define MUIM_IG_Ticker              (TAGBASE_LG + 109)
#define MUIM_IG_CopyFilesAdd        (TAGBASE_LG + 110)
#define MUIM_IG_Confirm             (TAGBASE_LG + 111)
#define MUIM_IG_Message             (TAGBASE_LG + 112)
#define MUIM_IG_Abort               (TAGBASE_LG + 113)
#define MUIM_IG_Radio               (TAGBASE_LG + 114)
#define MUIM_IG_Bool                (TAGBASE_LG + 115)
#define MUIM_IG_String              (TAGBASE_LG + 116)
#define MUIM_IG_Number              (TAGBASE_LG + 117)
#define MUIM_IG_CheckBoxes          (TAGBASE_LG + 118)
#define MUIM_IG_AskFile             (TAGBASE_LG + 119)
#define MUIM_IG_PageSet             (TAGBASE_LG + 120)
#define MUIM_IG_Finish              (TAGBASE_LG + 121)
#define MUIM_IG_Working             (TAGBASE_LG + 122)
#define MUIM_IG_Effect              (TAGBASE_LG + 123)
#define MUIM_IG_CloseMedia          (TAGBASE_LG + 124)
#define MUIM_IG_SetMedia            (TAGBASE_LG + 125)
#define MUIM_IG_ShowMedia           (TAGBASE_LG + 126)
#define MUIM_IG_ShowPicture         (TAGBASE_LG + 127)
#define MUIM_IG_GetCustomScreen     (TAGBASE_LG + 128)
#define MUIM_IG_GetScreenProp       (TAGBASE_LG + 129)
#define MUIM_IG_GetWindowProp       (TAGBASE_LG + 130)

//------------------------------------------------------------------------------
// IG - Attributes
//------------------------------------------------------------------------------
#define MUIA_IG_UseCustomScreen     (TAGBASE_LG + 201)

//------------------------------------------------------------------------------
// IG - Media ID
//------------------------------------------------------------------------------
#define MUIA_IG_MediaBase           (TAGBASE_LG + 301)
#define MUIA_IG_MediaMax            (TAGBASE_LG + 399)

//------------------------------------------------------------------------------
// IG - Init parameters
//------------------------------------------------------------------------------
struct MUIP_IG_Init
{
    IPTR MethodID;
};

//------------------------------------------------------------------------------
// IG - Welcome parameters
//------------------------------------------------------------------------------
struct MUIP_IG_Welcome
{
    IPTR MethodID;
    IPTR Message;
    IPTR Level;
    IPTR Log;
    IPTR Pretend;
    IPTR MinLevel;
    IPTR NoPretend;
    IPTR NoLog;
};

//------------------------------------------------------------------------------
// IG - CopyFilesStart parameters
//------------------------------------------------------------------------------
struct MUIP_IG_CopyFilesStart
{
    IPTR MethodID;
    IPTR Message;
    IPTR Help;
    IPTR List;
    IPTR Confirm;
    IPTR Back;
};

//------------------------------------------------------------------------------
// IG - CopyFilesSetCur parameters
//------------------------------------------------------------------------------
struct MUIP_IG_CopyFilesSetCur
{
    IPTR MethodID;
    IPTR File;
    IPTR NoGauge;
    IPTR Back;
};

//------------------------------------------------------------------------------
// IG - Exit parameters
//------------------------------------------------------------------------------
struct MUIP_IG_Exit
{
    IPTR MethodID;
    IPTR Message;
};

//------------------------------------------------------------------------------
// IG - Complete parameters
//------------------------------------------------------------------------------
struct MUIP_IG_Complete
{
    IPTR MethodID;
    IPTR Progress;
};

//------------------------------------------------------------------------------
// IG - CopyFilesAdd parameters
//------------------------------------------------------------------------------
struct MUIP_IG_CopyFilesAdd
{
    IPTR MethodID;
    IPTR File;
};

//------------------------------------------------------------------------------
// IG - Run parameters
//------------------------------------------------------------------------------
struct MUIP_IG_Confirm
{
    IPTR MethodID;
    IPTR Message;
    IPTR Help;
    IPTR Back;
};

//------------------------------------------------------------------------------
// IG - Message parameters
//------------------------------------------------------------------------------
struct MUIP_IG_Message
{
    IPTR MethodID;
    IPTR Message;
    IPTR Back;
};

//------------------------------------------------------------------------------
// IG - Finish parameters
//------------------------------------------------------------------------------
struct MUIP_IG_Finish
{
    IPTR MethodID;
    IPTR Message;
};

//------------------------------------------------------------------------------
// IG - Working parameters
//------------------------------------------------------------------------------
struct MUIP_IG_Working
{
    IPTR MethodID;
    IPTR Message;
};

//------------------------------------------------------------------------------
// IG - Effect parameters
//------------------------------------------------------------------------------
struct MUIP_IG_Effect
{
    IPTR MethodID;
    IPTR Effect;
    IPTR ColorStart;
    IPTR ColorEnd;
};

//------------------------------------------------------------------------------
// IG - CloseMedia parameters
//------------------------------------------------------------------------------
struct MUIP_IG_CloseMedia
{
    IPTR MethodID;
    IPTR MediaID;
};

//------------------------------------------------------------------------------
// IG - SetMedia parameters
//------------------------------------------------------------------------------
struct MUIP_IG_SetMedia
{
    IPTR MethodID;
    IPTR MediaID;
    IPTR Action;
    IPTR Parameter;
};

//------------------------------------------------------------------------------
// IG - ShowMedia parameters
//------------------------------------------------------------------------------
struct MUIP_IG_ShowMedia
{
    IPTR MethodID;
    IPTR MediaID;
    IPTR Media;
    IPTR Action;
};

//------------------------------------------------------------------------------
// IG - ShowPicture parameters
//------------------------------------------------------------------------------
struct MUIP_IG_ShowPicture
{
    IPTR MethodID;
    IPTR MediaID;
    IPTR Picture;
    IPTR Action;
};

//------------------------------------------------------------------------------
// IG - Abort parameters
//------------------------------------------------------------------------------
struct MUIP_IG_Abort
{
    IPTR MethodID;
    IPTR Message;
};

//------------------------------------------------------------------------------
// IG - Radio parameters
//------------------------------------------------------------------------------
struct MUIP_IG_Radio
{
    IPTR MethodID;
    IPTR Message;
    IPTR Help;
    IPTR Names;
    IPTR Default;
    IPTR Back;
    IPTR Select;
};

//------------------------------------------------------------------------------
// IG - Bool parameters
//------------------------------------------------------------------------------
struct MUIP_IG_Bool
{
    IPTR MethodID;
    IPTR Message;
    IPTR Help;
    IPTR Yes;
    IPTR No;
    IPTR Back;
};

//------------------------------------------------------------------------------
// IG - String parameters
//------------------------------------------------------------------------------
struct MUIP_IG_String
{
    IPTR MethodID;
    IPTR Message;
    IPTR Help;
    IPTR Default;
    IPTR Back;
    IPTR String;
};

//------------------------------------------------------------------------------
// IG - Number parameters
//------------------------------------------------------------------------------
struct MUIP_IG_Number
{
    IPTR MethodID;
    IPTR Message;
    IPTR Help;
    IPTR Min;
    IPTR Max;
    IPTR Default;
    IPTR Back;
    IPTR Number;
};

//------------------------------------------------------------------------------
// IG - CheckBoxes parameters
//------------------------------------------------------------------------------
struct MUIP_IG_CheckBoxes
{
    IPTR MethodID;
    IPTR Message;
    IPTR Help;
    IPTR Names;
    IPTR Default;
    IPTR Back;
    IPTR Bitmap;
};

//------------------------------------------------------------------------------
// IG - AskFile parameters
//------------------------------------------------------------------------------
struct MUIP_IG_AskFile
{
    IPTR MethodID;
    IPTR Message;
    IPTR Help;
    IPTR NewPath;
    IPTR Disk;
    IPTR Assign;
    IPTR Default;
    IPTR Dir;
    IPTR Back;
    IPTR File;
};

//------------------------------------------------------------------------------
// IG - PageSet parameters
//------------------------------------------------------------------------------
struct MUIP_IG_PageSet
{
    IPTR MethodID;
    IPTR Message;
    IPTR Help;
    IPTR Top;
    IPTR Bottom;
};

//------------------------------------------------------------------------------
// IG - GetCustomScreen parameters
//------------------------------------------------------------------------------
struct MUIP_IG_GetCustomScreen
{
    IPTR MethodID;
};

//------------------------------------------------------------------------------
// IG - GetScreenProp
//------------------------------------------------------------------------------
struct MUIP_IG_GetScreenProp
{
    IPTR MethodID;
    IPTR Width;
    IPTR Height;
    IPTR Depth;
    IPTR Colors;
};

//------------------------------------------------------------------------------
// IG - GetWindowProp
//------------------------------------------------------------------------------
struct MUIP_IG_GetWindowProp
{
    IPTR MethodID;
    IPTR Width;
    IPTR Height;
    IPTR Upper;
    IPTR Lower;
    IPTR Left;
    IPTR Right;
};

//------------------------------------------------------------------------------
// IG - private values
//------------------------------------------------------------------------------
#define MUIV_IG_FirstButton      (TAGBASE_LG + 200)
#define MUIV_IG_Proceed          (TAGBASE_LG + 200)
#define MUIV_IG_Abort            (TAGBASE_LG + 201)
#define MUIV_IG_Yes              (TAGBASE_LG + 202)
#define MUIV_IG_No               (TAGBASE_LG + 203)
#define MUIV_IG_AbortYes         (TAGBASE_LG + 204)
#define MUIV_IG_Tick             (TAGBASE_LG + 205)
#define MUIV_IG_AbortOnly        (TAGBASE_LG + 206)
#define MUIV_IG_ProceedRun       (TAGBASE_LG + 207)
#define MUIV_IG_SkipRun          (TAGBASE_LG + 208)
#define MUIV_IG_AbortRun         (TAGBASE_LG + 209)
#define MUIV_IG_Ok               (TAGBASE_LG + 210)
#define MUIV_IG_LastButton       (TAGBASE_LG + 211)

// Pages
#define P_WELCOME                0
#define P_COPYFILES              1
#define P_FILEDEST               2
#define P_PRETEND_LOG            3
#define P_MESSAGE                4
#define P_STRING                 5
#define P_NUMBER                 6
#define P_ASKFILE                7

// Buttons
#define B_PROCEED_ABORT          0
#define B_YES_NO_ABORT           1
#define B_ABORT                  2
#define B_PROCEED_SKIP_ABORT     3
#define B_OK                     4
#define B_NONE                   5

//------------------------------------------------------------------------------
// IGTrans - [PRIVATE] Translate button input to GUI response value
// Input:    IPTR signal: -
// Return:   GUI response value
//------------------------------------------------------------------------------
static IPTR IGTrans(IPTR signal)
{
    switch(signal)
    {
        case MUIV_IG_Ok:
        case MUIV_IG_Yes:
        case MUIV_IG_Proceed:
        case MUIV_IG_ProceedRun:
            return G_TRUE;

        case MUIV_IG_No:
        case MUIV_IG_SkipRun:
            return G_FALSE;

        case MUIV_IG_Abort:
        case MUIV_IG_AbortRun:
        case MUIV_IG_AbortYes:
        case MUIV_IG_AbortOnly:
            return G_ABORT;

        case 0:
            return G_EXIT;

        default:
            return G_ERR;
    }
}

//------------------------------------------------------------------------------
// IGWait - [PRIVATE] Wait for notification(s)
// Input:   IPTR notif:  Start notification value
//          IPTR range:  Number of values to check for
// Return:  Notifcation val. / zero on return id quit
//------------------------------------------------------------------------------
static IPTR IGWait(Object *obj, IPTR notif, IPTR range)
{
    IPTR sig = 0, ret = 0, n;

    // Set cycle chain for buttons within range.
    if(notif != MUIV_IG_Tick)
    {
        for(n = 0; n < range; n++)
        {
            // Find button.
            Object *but = (Object *) DoMethod
            (
                obj, MUIM_FindUData,
                notif + n
            );

            if(!but)
            {
                continue;
            }

            // Add button to cycle chain.
            set(but, MUIA_CycleChain, TRUE);

            // Activate first button.
            if(n == 0)
            {
                set(Win, MUIA_Window_ActiveObject, but);
            }
        }
    }

    ret = DoMethod(_app(obj), MUIM_Application_NewInput, &sig);

    // Enter message loop.
    while(ret != (IPTR) MUIV_Application_ReturnID_Quit)
    {
        // Iterate over signals we're waiting for.
        for(n = 0; n < range; n++)
        {
            // Did we get what we're waiting for?
            if(ret != notif + n)
            {
                continue;
            }

            if(ret == MUIV_IG_Tick)
            {
                return ret;
            }

            // Remove range from cycle chain.
            for(n = 0; n < range; n++)
            {
                // Find button.
                Object *but = (Object *) DoMethod
                (
                    obj, MUIM_FindUData,
                    notif + n
                );

                if(!but)
                {
                    continue;
                }

                set(but, MUIA_CycleChain, FALSE);
            }

            set(Win, MUIA_Window_ActiveObject,
                MUIV_Window_ActiveObject_None);

            return ret;
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

//------------------------------------------------------------------------------
// IGInit - Initialize all the things
// Input:   -
// Return:  On success TRUE, FALSE otherwise.
//------------------------------------------------------------------------------
MUIDSP IGInit(Class *cls, Object *obj)
{
    static IPTR i = MUIV_IG_FirstButton;

    // Have we already done this?
    if(i == MUIV_IG_LastButton)
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return FALSE;
    }

    struct IGData *my = INST_DATA(cls, obj);

    // Set notifications on all buttons.
    while(i <= MUIV_IG_LastButton)
    {
        // Find current button.
        Object *but = (Object *) DoMethod(obj, MUIM_FindUData, i);

        // Set notification if it exists.
        if(but)
        {
            DoMethod
            (
                but, MUIM_Notify,
                MUIA_Pressed, FALSE, _app(obj), 2,
                MUIM_Application_ReturnID, i
            );
        }

        // Next button.
        i++;
    }

    // Enter in string gadget = proceed.
    DoMethod
    (
        my->String, MUIM_Notify,
        MUIA_String_Acknowledge,
        MUIV_EveryTime, _app(obj), 2,
        MUIM_Application_ReturnID,
        MUIV_IG_Proceed
    );

    // Exit upon close request.
    DoMethod
    (
        obj, MUIM_Notify, MUIA_Window_CloseRequest,
        TRUE, _app(obj), 2, MUIM_Application_ReturnID,
        MUIV_Application_ReturnID_Quit
    );

    // All done.
    return TRUE;
}

//------------------------------------------------------------------------------
// IGWrapString - Wrap and chomp strings. Please note this function uses its
//                own static buffer. Care (and possibly copies) needs to be
//                taken when used by multiple callers.
// Input:         const char * src:     String to be wrapped.
//                size_t len:           Line length.
//                bool chomp:           Chomp trailing whitespace when true.
// Return:        A wrapped and chomped copy of src.
//------------------------------------------------------------------------------
MUIDSP IGWrapString(const char *src, size_t len, bool chomp)
{
    // Create capped copy.
    static char buf[1 << 12];
    size_t cnt = strlen(src);
    cnt = cnt < (sizeof(buf) - 1) ? cnt : (sizeof(buf) - 1);
    memcpy(buf, src, cnt);
    buf[cnt] = '\0';

    if(chomp)
    {
        while(cnt && buf[--cnt] < '!')
        {
            buf[cnt] = '\0';
        }
    }

    // Do we need to word wrap?
    if(cnt > len)
    {
        // Start from the first point where we need to wrap.
        size_t cur = len;

        // As long we have characters.
        while(cur < cnt)
        {
            // Last wrapping point.
            size_t ref = cur - len;

            // Go backwards from where we are to a point where we can wrap.
            while(cur > ref && buf[cur] > '!')
            {
                cur--;
            }

            // If we ended up where we started we failed. Wrap in the middle of
            // the word in that case. This will only happen with words >= len.
            if(cur == ref)
            {
                // Restore the previous point.
                cur += len;
            }
            else
            {
                // If we found a wrapping point we must make sure that no NL
                // exists before this point but after the previous point.
                while(++ref < cur)
                {
                    if(buf[ref] == '\n')
                    {
                        // Skip wrap.
                        cur = ref;
                        break;
                    }
                }
            }

            // Wrap and continue.
            buf[cur] = '\n';
            cur += len;
        }
    }

    // Always.
    return (IPTR) buf;
}

//------------------------------------------------------------------------------
// IGPageSet - [PRIVATE] Set page / buttons and display text
// Input:                Message - Top message
//                       Help - Help message
//                       Top - Top page
//                       Bottom - Bottom page
// Return:               TRUE on success, FALSE otherwise
//------------------------------------------------------------------------------
MUIDSP IGPageSet(Class *cls, Object *obj, struct MUIP_IG_PageSet *msg)
{
    struct IGData *my = INST_DATA(cls, obj);

    // Select top and buttons.
    set(my->Top, MUIA_Group_ActivePage, msg->Top);
    set(my->Bottom, MUIA_Group_ActivePage, msg->Bottom);

    // Show message. Wrap at 53 characters like the CBM installer.
    set(my->Text, MUIA_ShowMe, FALSE);
    set(my->Text, MUIA_Text_Contents, IGWrapString(msg->Message ? (const char *)
        msg->Message : "", 53, false));
    set(my->Text, MUIA_ShowMe, TRUE);

    // On AROS/Zune no line wrapping is done in help bubbles. We need to take
    // care of that ourselves. Use 53 characters as limit.
#ifdef __AROS__
    set(my->Text, MUIA_ShortHelp, msg->Help ? IGWrapString((const char *)
        msg->Help, 53, true) : msg->Help);
#else
    // On MorphOS line wrapping is done in help bubbles, but it doesn't work if
    // the string ends with newlines, so chomping is needed.
    set(my->Text, MUIA_ShortHelp, msg->Help ? IGWrapString((const char *)
        msg->Help, INT_MAX, true) : msg->Help);
#endif /* __AROS__ */

    // Always.
    return TRUE;
}

//------------------------------------------------------------------------------
// IGWelcome - Show welcome message. The Level, Log, and Pretend parameters are
//             int32_t pointers that act as both input and output.
// Input:      Message - the welcome message text
//             Level - User level
//             Log - Log to file
//             Pretend - Pretend mode
//             MinLevel - Minimum user level
//             NoPretend - Disable pretend mode
//             NoLog - Disable logging
// Return:     G_TRUE / G_ABORT / G_EXIT / G_ERR.
//------------------------------------------------------------------------------
MUIDSP IGWelcome(Class *cls, Object *obj, struct MUIP_IG_Welcome *msg)
{
    struct IGData *my = INST_DATA(cls, obj);

    // If the minimum user level is set to 'expert', disable radio buttons
    // to indicate that there is no choice to be made.
    if(msg->MinLevel == 2)
    {
        set(my->UserLevel, MUIA_Disabled, TRUE);
    }
    // If the minimum user level is set to 'average', show 'average' and
    // 'expert' only.
    else if(msg->MinLevel == 1)
    {
        // Hide the full one.
        set(my->UserLevel, MUIA_ShowMe, FALSE);
        set(my->ExpertLevel, MUIA_ShowMe, TRUE);

        // Take minimum user level into account.
        set(my->ExpertLevel, MUIA_Radio_Active,
           *((int32_t *) msg->Level) - 1);
    }

    // Set the current user level.
    set(my->UserLevel, MUIA_Radio_Active, *((int32_t *) msg->Level));


    // Show welcome page.
    if(!DoMethod(obj, MUIM_IG_PageSet, msg->Message, NULL, P_WELCOME,
       B_PROCEED_ABORT))
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    // Wait for proceed or abort.
    inp_t rc = IGTrans(IGWait(obj, MUIV_IG_Proceed, 2));

    if(rc != G_TRUE)
    {
        return rc;
    }

    // Get the selected user level value. If we have a minimum user
    // level of 'average' we're using a different set of radio buttons.
    // Fetch from the right object and adjust the return value.
    if(msg->MinLevel == 1)
    {
        // Minimum user level 'average'.
        get(my->ExpertLevel, MUIA_Radio_Active, (int32_t *) msg->Level);
        (*((int32_t *) msg->Level))++;
    }
    else
    {
        // Minimum user level 'novice' or 'expert'.
        get(my->UserLevel, MUIA_Radio_Active, (int32_t *) msg->Level);
    }

    // Disable the pretend choice if the NOPRETEND tooltype is used. The
    // default behaviour is to install for real, not to pretend.
    SetAttrs
    (
        my->Pretend,
        MUIA_Radio_Active,
        msg->NoPretend ? 0 : *((int32_t *) msg->Pretend),
        MUIA_Disabled, msg->NoPretend ? TRUE : FALSE,
        TAG_END
    );

    // Disable the 'log to file' choice if the NOLOG tooltype is used.
    // The default behaviour is to not write to a log file.
    SetAttrs
    (
        my->Log,
        MUIA_Radio_Active,
        msg->NoLog ? 0 : *((int32_t *) msg->Log),
        MUIA_Disabled, msg->NoLog ? TRUE : FALSE,
        TAG_END
    );

    // Don't show logging and pretend mode settings to 'Novice' users.
    if(*((int32_t *) msg->Level))
    {
        // Show pretend / log page.
        if(!DoMethod(obj, MUIM_IG_PageSet, NULL, NULL, P_PRETEND_LOG,
           B_PROCEED_ABORT))
        {
            // Unknown error.
            GERR(tr(S_UNER));
            return G_ERR;
        }

        // Wait for proceed or abort.
        rc = IGTrans(IGWait(obj, MUIV_IG_Proceed, 2));

        if(rc == G_TRUE)
        {
            // Get pretend and log settings.
            get(my->Log, MUIA_Radio_Active, (int32_t *) msg->Log);
            get(my->Pretend, MUIA_Radio_Active, (int32_t *)
                msg->Pretend);
        }
    }

    // 'Proceed', 'Abort' or 'Exit'.
    return rc;
}

//------------------------------------------------------------------------------
// IGDirPart - [PRIVATE] - Return existing dir from random path
// Input:      IPTR Path: Random path.
// Return:     IPTR:      Existing dir from path.
//------------------------------------------------------------------------------
static IPTR IGDirPart(Class *cls, Object *obj, IPTR Path)
{
    struct FileInfoBlock *fib = (struct FileInfoBlock *)
        AllocDosObject(DOS_FIB, NULL);

    if(!fib)
    {
        GERR(tr(S_UNER));
        return Path;
    }

    struct IGData *my = INST_DATA(cls, obj);

    // Copy path string.
    strncpy(my->Buf, (const char *) Path, sizeof(my->Buf));

    struct Process *p = (struct Process *) FindTask(NULL);

    // Save current window ptr.
    APTR w = p->pr_WindowPtr;

    // Disable auto request.
    p->pr_WindowPtr = (APTR) -1L;

    // Attempt to lock file or directory.
    BPTR lock = (BPTR) Lock(my->Buf, ACCESS_READ);

    while(*(my->Buf) && (!lock || (Examine(lock, fib) &&
          fib->fib_DirEntryType <= 0)))
    {
        // Release lock to file or directory.
        UnLock(lock);

        // Find path tail.
        char *tail = PathPart(my->Buf);

        if(*tail == '\0')
        {
            // We've reached the end of the road.
            *(my->Buf) = '\0';
        }
        else
        {
            // Cut of the tail and repeat.
            *tail = '\0';
            lock = (BPTR) Lock(my->Buf, ACCESS_READ);
        }
    }

    // Release lock to file or directory.
    FreeDosObject(DOS_FIB, fib);
    UnLock(lock);

    // Restore auto request.
    p->pr_WindowPtr = w;
    return (IPTR) my->Buf;
}

//------------------------------------------------------------------------------
// IGAskFile - Show file / directory requester
// Input:      Message - The prompt
//             Help - Help text
//             NewPath - Allow non-existent defaults
//             Disk - Show drive list first
//             Assign - Logical assign OK as dir
//             Default - Default file / directory
//             Dir - Ask for directory
//             Back - Use 'Back' instead of 'Abort'.
//             File - File / dir return value.
// Return:     G_TRUE / G_ABORT / G_EXIT / G_ERR.
//------------------------------------------------------------------------------
MUIDSP IGAskFile(Class *cls, Object *obj, struct MUIP_IG_AskFile *msg)
{
    // Show file requester page.
    if(!DoMethod(obj, MUIM_IG_PageSet, msg->Message, msg->Help, P_ASKFILE,
       B_PROCEED_ABORT))
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    if(!msg->NewPath)
    {
        // Make sure that the default dir exists.
        msg->Default = IGDirPart(cls, obj, msg->Default);
    }

    // Create ASL file requester
    Object *str, *pop = (Object *) MUI_NewObject
    (
        MUIC_Popasl,
        MUIA_Popasl_Type, ASL_FileRequest,
        ASLFR_DrawersOnly, msg->Dir,
        ASLFR_InitialShowVolumes, msg->Disk,
        ASLFR_TitleText, msg->Dir ? tr(S_SDIR) : tr(S_SFLE),
        MUIA_Popstring_String, str = (Object *)
            MUI_MakeObject(MUIO_String, NULL, PATH_MAX),
        MUIA_Popstring_Button, (Object *)
            MUI_MakeObject(MUIO_PopButton, MUII_PopDrawer),
        TAG_END
    );

    // Open the requester after adding it to the current group.
    if(pop)
    {
        struct IGData *my = INST_DATA(cls, obj);

        // Set default file / dir.
        set(str, MUIA_String_Contents, msg->Default);

        // Prepare before adding requester.
        if(DoMethod(my->Ask, MUIM_Group_InitChange))
        {
            // Add pop up requester.
            DoMethod(my->Ask, OM_ADDMEMBER, pop);

            // Use 'Abort' or 'Back'?
            if(msg->Back)
            {
                // Set 'Back' button.
                set(my->Abort, MUIA_Text_Contents, tr(S_BACK));
            }

            // We're done adding things.
            DoMethod(my->Ask, MUIM_Group_ExitChange);

            // Wait for proceed or abort.
            inp_t rc = IGTrans(IGWait(obj, MUIV_IG_Proceed, 2));

            if(rc == G_TRUE)
            {
                // Get filename from requester.
                get(str, MUIA_String_Contents, (char **) msg->File);

                if(*((char **) msg->File))
                {
                    // We need to create a copy of the filename string since
                    // we're about to free the pop up requester.
                    int n = snprintf(my->Buf, sizeof(my->Buf), "%s",
                                     *((char **) msg->File));

                    // Make sure that we succeded in creating a copy of the
                    // filename.
                    if(n >= 0 && ((size_t) n < sizeof(my->Buf)))
                    {
                        size_t len = strlen(my->Buf);

                        // The ASL appends '/' to dirs. This is not how the
                        // CBM installer works, no trailing '/' allowed.
                        if(msg->Dir && len > 1 && my->Buf[len - 1] == '/')
                        {
                            my->Buf[len - 1] = '\0';
                        }

                        *((char **) msg->File) = my->Buf;
                    }
                }

                if(!*((char **) msg->File))
                {
                    // Unknown error.
                    GERR(tr(S_UNER));
                    rc = G_ERR;
                }
            }

            // Prepare before removing requester.
            if(DoMethod(my->Ask, MUIM_Group_InitChange))
            {
                // Remove pop up requester.
                DoMethod(my->Ask, OM_REMMEMBER, pop);

                if(msg->Back)
                {
                    // Restore 'Abort' if needed.
                    set(my->Abort, MUIA_Text_Contents, tr(S_ABRT));
                }

                // We're done removing things.
                DoMethod(my->Ask, MUIM_Group_ExitChange);

                // Free ASL requester.
                MUI_DisposeObject(pop);

                // Return filename.
                return rc;
            }
        }

        // Free ASL requester.
        MUI_DisposeObject(pop);
    }

    // Unknown error.
    GERR(tr(S_UNER));
    return G_ERR;
}

//------------------------------------------------------------------------------
// IGCopyFilesStart - Show file copy requester
// Input:             Message - The prompt
//                    List - File / dir list
//                    Confirm - User confirmation
// Return:            G_TRUE / G_ABORT / G_EXIT / G_ERR.
//------------------------------------------------------------------------------
MUIDSP IGCopyFilesStart(Class *cls, Object *obj,
                        struct MUIP_IG_CopyFilesStart *msg)
{
    struct IGData *my = INST_DATA(cls, obj);
    pnode_p cur = (pnode_p) msg->List, lst = cur;
    int n = 0;

    // For all files and directories to be copied; count the files, and if
    // confirmation is needed, add them to the selection / deselection list.
    while(cur)
    {
        // Is this a file?
        if(cur->type == 1)
        {
            // Do we need confirmation?
            if(msg->Confirm)
            {
                // Add file to the selection / deselection list.
                DoMethod(Win, MUIM_IG_CopyFilesAdd, cur->name);
            }

            // Increase the total file count.
            n++;
        }

        // Next file / directory.
        cur = cur->next;
    }

    // Install timer to give the user a chance to abort.
    DoMethod(_app(obj), MUIM_Application_AddInputHandler, &my->Ticker);

    if(msg->Confirm && n)
    {
        // Show the file selection page.
        if(DoMethod(Win, MUIM_IG_PageSet, msg->Message,
                    msg->Help, P_FILEDEST, B_PROCEED_SKIP_ABORT))
        {
            inp_t rc;

            // Use 'Abort' or 'Back'?
            if(msg->Back)
            {
                // Set 'Back' button.
                set(my->AbortRun, MUIA_Text_Contents, tr(S_BACK));

                // Wait for 'Proceed', 'Skip' or 'Back'.
                rc = IGTrans(IGWait(obj, MUIV_IG_ProceedRun, 3));

                // Restore 'Abort' button.
                set(my->AbortRun, MUIA_Text_Contents, tr(S_ABRT));
            }
            else
            {
                // Wait for 'Proceed', 'Skip' or 'Abort'.
                rc = IGTrans(IGWait(obj, MUIV_IG_ProceedRun, 3));
            }

            // Did the user confirm?
            if(rc == G_TRUE)
            {
                LONG id = MUIV_List_NextSelected_Start;

                // For all files in the selection / deselection list, tag the
                // ones that we're going to copy.
                for(;;)
                {
                    // Get the first element in the list.
                    DoMethod(my->List, MUIM_List_NextSelected, &id);

                    // Are we done with all of the files?
                    if(id != MUIV_List_NextSelected_End)
                    {
                        // Get name of current file?
                        char *ent = NULL;
                        DoMethod(my->List, MUIM_List_GetEntry, id, &ent);

                        if(ent)
                        {
                            // Find the corresponding file node in 'our' list.
                            for(cur = lst; cur; cur = cur->next)
                            {
                                // If we find it, and it's a file, give it a
                                // 'copy' tag.
                                if(cur->type == 1 && !strcmp(ent, cur->name))
                                {
                                    cur->type = -1;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        // We're done with all files in the selection /
                        // deselection list.
                        break;
                    }
                }

                // Iterate over nodes in 'our' list and tag everything that
                // we're NOT going to copy.
                for(cur = lst; cur; cur = cur->next)
                {
                    // Is this a file that's not going to be copied?
                    if(cur->type == 1)
                    {
                        // Give it an 'ignore' tag and decrease the number of
                        // files to be copied.
                        cur->type = 0;
                        n--;
                    }
                    // Is this a file that's going to be copied?
                    else if(cur->type == -1)
                    {
                        // Restore the file type so that the rest of the world
                        // understands that this is a file.
                        cur->type = 1;
                    }
                }
            }
            else
            {
                // Skip or abort.
                return rc;
            }
        }
    }


    // Show file copy page.
    if(!DoMethod(obj, MUIM_IG_PageSet, msg->Message, NULL, P_COPYFILES,
       B_ABORT))
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return (IPTR) G_ERR;
    }

    // Configure gauge so that one tick == one file.
    SetAttrs(my->Progress, MUIA_Gauge_Max, n, MUIA_Gauge_Current, 0, TAG_END);

    // Always true.
    return (IPTR) G_TRUE;
}

//------------------------------------------------------------------------------
// IGCopyFilesSetCur - Show current file
// Input:              File - filename
//                     NoGauge - Hide file gauge
//                     Back - Use 'Back' instead of 'Abort'.
// Return:             G_TRUE / G_ABORT / G_EXIT / G_ERR.
//------------------------------------------------------------------------------
MUIDSP IGCopyFilesSetCur(Class *cls, Object *obj,
                         struct MUIP_IG_CopyFilesSetCur *msg)
{
    if(msg->File)
    {
        struct IGData *my = INST_DATA(cls, obj);
        char *file = (char *) msg->File;
        size_t len = strlen(file);
        struct TextExtent ext;
        static IPTR back;

        // Toggle 'Abort' and 'Back'?
        if(msg->Back != back)
        {
            // Save value.
            back = msg->Back;

            // Set new button text.
            set(my->AbortOnly, MUIA_Text_Contents,
                back ? tr(S_BACK) : tr(S_ABRT));
        }

        // Get the number of characters that can be shown given the width of
        // the gauge and the contents of the string.
        IPTR max = TextFit(_rp(my->Progress), file, len, &ext, NULL, 1,
                            _mwidth(my->Progress), _mheight(my->Progress));

        // Do we need to truncate the file string to not wreck the gauge?
        if(len > max)
        {
            // The gauge might have room for more than the temporary my->Buffer.
            len = max < sizeof(my->Buf) ? max : sizeof(my->Buf);

            // Truncate and switch.
            snprintf(my->Buf, len, "%s", file);
            file = my->Buf;
        }

        // Update progress bar. Text and number.
        if(!msg->NoGauge)
        {
            IPTR cur = 0;

            // Get current progress.
            get(my->Progress, MUIA_Gauge_Current, &cur);

            // Add another file on top (one file = one tick).
            SetAttrs(my->Progress, MUIA_Gauge_InfoText, file,
                     MUIA_Gauge_Current, ++cur, TAG_END);
        }
        else
        {
            // Update text only, ignore the gauge.
            set(my->Progress, MUIA_Gauge_InfoText, file);
        }
    }
    else
    {
        // Inv. count.
        static int n;

        // Give the user a chance to abort every 64:th block.
        if(++n >> 6)
        {
            // Wait for tick / abort / exit.
            IPTR rs = IGWait(obj, MUIV_IG_Tick, 2);

            // Start over or return.
            if(rs != MUIV_IG_Tick)
            {
                // Abort or exit.
                return IGTrans(rs);
            }
            else
            {
                // Repeat.
                n = 0;
            }
        }
    }

    // Next block.
    return (IPTR) G_TRUE;
}

//------------------------------------------------------------------------------
// IGCopyFilesEnd - End of file copy
// Input:           -
// Return:          G_TRUE
//------------------------------------------------------------------------------
MUIDSP IGCopyFilesEnd(Class *cls, Object *obj)
{
    struct IGData *my = INST_DATA(cls, obj);

    // Uninstall timer created to establish a time slice where the user has a
    // chance to abort file copy operations.
    DoMethod(_app (obj), MUIM_Application_RemInputHandler, &my->Ticker);

    // Leave the file list the way we found it (empty).
    DoMethod(my->List, MUIM_List_Clear);

    // Always true.
    return (IPTR) G_TRUE;
}

//------------------------------------------------------------------------------
// IGCopyFilesAdd - Add files to (expert) file (de)selector
// Input:           File - Name of file (or dir)
// Return:          TRUE
//------------------------------------------------------------------------------
MUIDSP IGCopyFilesAdd(Class *cls, Object *obj,
                      struct MUIP_IG_CopyFilesAdd *msg)
{
    struct IGData *my = INST_DATA(cls, obj);

    // Insert filename.
    DoMethod(my->List, MUIM_List_Insert, &(msg->File), 1,
        MUIV_List_Insert_Bottom);

    // All files are selected by default.
    DoMethod(my->List, MUIM_List_Select, MUIV_List_Select_All,
        MUIV_List_Select_On, NULL);

    // The lister must be visible.
    set(my->List, MUIA_ShowMe, TRUE);

    // Always true.
    return (IPTR) TRUE;
}


//------------------------------------------------------------------------------
// IGExit - Say goodbye and close GUI
// Input    Message - The prompt
// Return:  TRUE
//------------------------------------------------------------------------------
MUIDSP IGExit(Class *cls, Object *obj, struct MUIP_IG_Exit *msg)
{
    // Silence.
    (void) cls;
    (void) obj;
    (void) msg;

    // Do nothing.
    return G_TRUE;
}

//------------------------------------------------------------------------------
// IGWorking - Show busy message
// Input:      Message - The message
// Return:     G_TRUE / G_ERR.
//------------------------------------------------------------------------------
MUIDSP IGWorking(Class *cls, Object *obj, struct MUIP_IG_Working *msg)
{
    // Silence.
    (void) cls;

    // Set correct page and button combination.
    if(!DoMethod(obj, MUIM_IG_PageSet, msg->Message, NULL, P_MESSAGE, B_NONE))
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    // The message is already shown.
    return G_TRUE;
}

//------------------------------------------------------------------------------
// IGEffect -  Show gradient backdrop.
// Input:      Effect - Type and position
//             ColorStart - First color in gradient.
//             ColorEnd - Last color in gradient.
// Return:     G_TRUE / G_FALSE / G_ERR.
//------------------------------------------------------------------------------
MUIDSP IGEffect(Class *cls, Object *obj, struct MUIP_IG_Effect *msg)
{
    struct IGData *my = INST_DATA(cls, obj);

    // Do we have anything to do?
    if(!(msg->Effect & G_EFFECT))
    {
        // No effect.
        return G_FALSE;
    }

    // Don't trust Init().
    if(my->Scr && my->Win)
    {
        // Allocate pen for the gradient.
        LONG pn = ObtainPen(my->Scr->ViewPort.ColorMap, -1, 0, 0, 0,
                            PEN_EXCLUSIVE | PEN_NO_SETCOLOR);

        // Valid pen?
        if(pn != -1)
        {
            // Get 8-bit RGB start and stop values.
            int r1 = msg->ColorStart >> 16,
                g1 = (msg->ColorStart >> 8) & 0xff,
                b1 = msg->ColorStart & 0xff, r2 = msg->ColorEnd >> 16,
                g2 = (msg->ColorEnd >> 8) & 0xff, b2 = msg->ColorEnd & 0xff,

                // Minimum chunk = 1 << ct pixels, to save time when drawing.
                ct = 2, s = my->Win->Height >> ct;

            // RGB deltas per chunk.
            float rd = (r2 - r1) / ((float) s - 1),
                  gd = (g2 - g1) / ((float) s - 1),
                  bd = (b2 - b1) / ((float) s - 1);

            // Backdrop big enough?
            if(s)
            {
                // Allocate color vector.
                ULONG *cv = calloc(s * 3, sizeof(ULONG));

                // Release pen and bail on OOM.
                if(!cv)
                {
                    ReleasePen(my->Scr->ViewPort.ColorMap, pn);
                    return G_ERR;
                }

                // Color index.
                int i = 0;

                // Initial RGB values.
                float r = r1, g = g1, b = b1;

                // Compute gradient.
                while(i < s * 3)
                {
                    cv[i++] = ((ULONG) r) << 24;
                    cv[i++] = ((ULONG) g) << 24;
                    cv[i++] = ((ULONG) b) << 24;
                    r += rd;
                    g += gd;
                    b += bd;
                }

                // Set backdrop pen.
                SetRPAttrs(my->Win->RPort, RPTAG_APen, pn, RPTAG_BPen, pn,
                           TAG_END);

                // Draw effect if it's enabled.
                if(msg->Effect & G_EFFECT)
                {
                    // Start from the bottom, one delta at a time.
                    int d = 1 << ct, v = my->Win->Height;

                    // For all colors in gradient, draw rectangle with delta
                    // height.
                    while(i >= 0)
                    {
                        // Go backwards in vector.
                        i -= 3;

                        // Use the same pen again and again.
                        SetRGB32(&my->Scr->ViewPort, pn, cv[i], cv[i + 1],
                                 cv[i + 2]);

                        // From bottom to top.
                        v -= d;

                        // Draw rectangle.
                        RectFill(my->Win->RPort, 0, v, my->Win->Width, v + d);
                    }
                }

                // Free color vector.
                free(cv);
            }

            // We're done with the pen.
            ReleasePen(my->Scr->ViewPort.ColorMap, pn);

            // True even if Window is too small.
            return G_TRUE;
        }
    }

    // Unknown error.
    GERR(tr(S_UNER));
    return G_ERR;
}

//------------------------------------------------------------------------------
// IGCloseMedia -  FIXME
// Input:          FIXME
// Return:         G_TRUE / G_FALSE
//------------------------------------------------------------------------------
MUIDSP IGCloseMedia(Class *cls, Object *obj, struct MUIP_IG_CloseMedia *msg)
{
    // Silence.
    (void) cls;

    // Compute user data value.
    IPTR mid = msg->MediaID + MUIA_IG_MediaBase;


    // Is the media ID valid?
    if(mid > MUIA_IG_MediaMax)
    {
        // Invalid / non existing ID.
        return G_FALSE;
    }

    // Is the ID in use?
    Object *win = (Object *) DoMethod(_app(obj), MUIM_FindUData, mid);

    if(!win)
    {
        // Invalid / non existing ID.
        return G_FALSE;
    }

    set(win, MUIA_Window_Open, FALSE);
    return G_TRUE;
}

//------------------------------------------------------------------------------
// IGSetMedia -  FIXME
// Input:        FIXME
// Return:       G_TRUE / G_FALSE / G_ERR.
//------------------------------------------------------------------------------
MUIDSP IGSetMedia(Class *cls, Object *obj, struct MUIP_IG_SetMedia *msg)
{
    // Silence.
    (void) cls;
    (void) obj;

    // Do we have anything to do?
    if(!msg->MediaID)
    {
        // Invalid ID.
        return G_FALSE;
    }

    // Dummy.
    return G_TRUE;
}

//------------------------------------------------------------------------------
// IGGetCustomScreen - Get custom screen.
// Input:            -
// Return:           struct Screen * if open, NULL otherwise.
//------------------------------------------------------------------------------
MUIDSP IGGetCustomScreen(Class *cls, Object *obj)
{
    struct IGData *my = INST_DATA(cls, obj);
    return (IPTR) my->Scr;
}

//------------------------------------------------------------------------------
// IGGetScreenProp   FIXME
// Input:            FIXME
// Return:           FIXME
//------------------------------------------------------------------------------
MUIDSP IGGetScreenProp(Class *cls, Object *obj,
                       struct MUIP_IG_GetScreenProp *msg)
{
    (void) cls;

    struct Screen *scr = NULL;
    get(obj, MUIA_Window_Screen, &scr);

    if(!scr)
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    int32_t *width = (int32_t *) msg->Width, *height = (int32_t *) msg->Height,
            *depth = (int32_t *) msg->Depth, *colors = (int32_t *) msg->Colors;

    *width = scr->Width;
    *height = scr->Height;
    *depth = GetBitMapAttr(scr->RastPort.BitMap, BMA_DEPTH);
    *colors = 1 << (*depth > 24 ? 24 : *depth);

    return G_TRUE;
}

//------------------------------------------------------------------------------
// IGGetWindowProp   FIXME
// Input:            FIXME
// Return:           FIXME
//------------------------------------------------------------------------------
MUIDSP IGGetWindowProp(Class *cls, Object *obj,
                       struct MUIP_IG_GetWindowProp *msg)
{
    (void) cls;

    struct Window *win = NULL;
    struct Screen *scr = NULL;

    get(obj, MUIA_Window_Window, &win);
    get(obj, MUIA_Window_Screen, &scr);

    if(!win || !scr)
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    int32_t *width = (int32_t *) msg->Width, *height = (int32_t *) msg->Height,
        *upper = (int32_t *) msg->Upper, *lower  = (int32_t *) msg->Lower,
        *left  = (int32_t *) msg->Left, *right   = (int32_t *) msg->Right;

    *width = win->Width;
    *height = win->Height;
    *left = win->LeftEdge;
    *right = scr->Width - *width - *left;
    *upper = win->TopEdge;
    *lower = scr->Height - *height - *upper;

    return G_TRUE;
}

//------------------------------------------------------------------------------
// IGShowPicture -  FIXME
// Input:           Picture - Image file.
//                  Action - FIXME
// Return:          FIXME
//------------------------------------------------------------------------------
MUIDSP IGShowPicture(Class *cls, Object *obj, struct MUIP_IG_ShowPicture *msg)
{
    struct IGData *my = INST_DATA(cls, obj);
    Object *win = NULL;

    // We need something to show.
    if(msg->Picture)
    {
        // Default behaviour is to put the window in the center and leave the
        // size as is.
        IPTR xs = 0, ys = 0, yp = MUIV_Window_TopEdge_Centered,
              xp = MUIV_Window_LeftEdge_Centered;

        // Set size explicitly?
        if(msg->Action & G_SIZE)
        {
            // Get screen dimensions.
            struct Screen *scr = NULL;
            get(obj, MUIA_Window_Screen, &scr);

            // Can we not have a screen?
            if(scr)
            {
                // Screen / 2 (large) 4 (medium) 8 (small).
                xs = scr->Width >> ((msg->Action & G_SMALL) ? 3 :
                                    (msg->Action & G_LARGE) ? 1 : 2);

                // Height of the window depends on the width.
                ys = (msg->Action & G_MORE) ? scr->Height >>
                     ((msg->Action & G_LARGE) ? 2 : 1) :
                     (msg->Action & G_LESS) ? scr->Height >>
                     ((msg->Action & G_SMALL) ? 2 : 3) :
                     scr->Height >> ((msg->Action & G_SMALL) ? 3 :
                                     (msg->Action & G_LARGE) ? 1 : 2);
            }
        }

        // Explicit horizontal placement?
        if(msg->Action & G_HORIZ)
        {
            xp = (msg->Action & G_LEFT) ? 0 :
#if !defined(__AROS__) && !defined(__VBCC__)
                // This doesn't work on AROS.
                MUIV_Window_LeftEdge_Right(0);
#else
                MUIV_Window_LeftEdge_Centered;
#endif /* !defined(__AROS__) && !defined(__VBCC__) */
        }

        // Explicit vertical placement?
        if(msg->Action & G_VERT)
        {
            yp = (msg->Action & G_UPPER) ? 0 :
#if !defined(__AROS__) && !defined(__VBCC__)
                // This doesn't work on AROS.
                MUIV_Window_TopEdge_Bottom(0);
#else
                MUIV_Window_TopEdge_Centered;
#endif /* !defined(__AROS__) && !defined(__VBCC__) */
        }

        // Proper window unless borderless is set.
        if(msg->Action & G_BORDER)
        {
            // Take size and placement into account. Make sure that this
            // window is not activated and that it's not possible to close it.
            win = (Object *) MUI_NewObject
            (
                MUIC_Window,
                my->Scr ? MUIA_Window_Screen : TAG_IGNORE, my->Scr,
                MUIA_Window_TopEdge, yp,
                MUIA_Window_LeftEdge, xp,
                MUIA_UserData, msg->MediaID,
                xs ? MUIA_Window_Width : TAG_IGNORE, xs,
                ys ? MUIA_Window_Height : TAG_IGNORE, ys,
                MUIA_Window_Activate, FALSE,
                MUIA_Window_CloseGadget, FALSE,
                MUIA_Window_RootObject, (Object *) MUI_NewObject(
                    MUIC_Scrollgroup,
                    MUIA_Scrollgroup_Contents, (Object *) MUI_NewObject(
                        MUIC_Virtgroup,
                        MUIA_Group_Child, (Object *) MUI_NewObject(
                            MUIC_Dtpic,
                            MUIA_Dtpic_Name, msg->Picture,
                            TAG_END),
                        TAG_END),
                    TAG_END),
                TAG_END
            );
        }
        else
        {
            // Take placement into account, ignore size. Create no gadgets
            // whatsoever, and it should be inactive.
            win = (Object *) MUI_NewObject
            (
                MUIC_Window,
                my->Scr ? MUIA_Window_Screen : TAG_IGNORE, my->Scr,
                MUIA_Window_TopEdge, yp,
                MUIA_Window_LeftEdge, xp,
                MUIA_Window_DragBar, FALSE,
                MUIA_UserData, msg->MediaID,
                MUIA_Window_Activate, FALSE,
                MUIA_Window_Borderless, TRUE,
                MUIA_Window_SizeGadget, FALSE,
                MUIA_Window_CloseGadget, FALSE,
                MUIA_Window_DepthGadget, FALSE,
                MUIA_Window_RootObject, (Object *) MUI_NewObject(
                    MUIC_Dtpic,
                    MUIA_Dtpic_Name, msg->Picture,
                    TAG_END),
                TAG_END
            );
        }
    }

    // On success, let the application manage the new window. Make sure that
    // the installer window is in front of it.
    if(win)
    {
        DoMethod(_app(obj), OM_ADDMEMBER, win);
        set(win, MUIA_Window_Open, TRUE);
        DoMethod(win, MUIM_Show);
        DoMethod(obj, MUIM_Window_ToFront);
    }

    // FIXME
    return (IPTR) win;
}

//------------------------------------------------------------------------------
// IGShowMedia -  FIXME
// Input:         MediaID - Output FIXME
//                Media - Media file.
//                Action - FIXME
// Return:        G_TRUE / G_FALSE / G_ERR.
//------------------------------------------------------------------------------
MUIDSP IGShowMedia(Class *cls, Object *obj, struct MUIP_IG_ShowMedia *msg)
{
    // Silence.
    (void) cls;

    // ID counter.
    static int32_t mid;

    // Test name and cap the number of open files.
    if(mid + MUIA_IG_MediaBase <= MUIA_IG_MediaMax && msg->Media)
    {
        // And we need permission to read from the file.
        BPTR flk = Lock((STRPTR) msg->Media, ACCESS_READ);

        if(flk)
        {
            // Check datatype before opening the file for real.
            struct DataType *dtp = ObtainDataTypeA(DTST_FILE, (APTR) flk, NULL);

            if(dtp)
            {
                // Get group ID of datatype.
                struct DataTypeHeader *dth = dtp->dtn_Header;
                ULONG gid = dth->dth_GroupID;

                // Free datatype resources and release lock.
                ReleaseDataType(dtp);
                UnLock(flk);

                // We only support pictures at the moment.
                if(gid == GID_PICTURE)
                {
                    DoMethod(obj, MUIM_IG_ShowPicture,
                             mid + MUIA_IG_MediaBase,
                             msg->Media, msg->Action);

                    // Return current media ID.
                    *((int32_t *) msg->MediaID) = mid;

                    // Next ID.
                    mid++;

                    // FIXME.
                    return G_TRUE;
                }
                else
                {
                    /*
                    case GID_SYSTEM:
                    case GID_TEXT:
                    case GID_DOCUMENT:
                    case GID_SOUND:
                    case GID_INSTRUMENT:
                    case GID_MUSIC:
                    case GID_ANIMATION:
                    case GID_MOVIE:
                    */
                    // FIXME - ID?.
                    return G_FALSE;
                }

            }
            else
            {
                // Unknown data.
                UnLock(flk);
            }
        }
    }

    // Invalid input.
    return G_ERR;
}

//------------------------------------------------------------------------------
// IGMessage - Show message
// Input:      Message - The prompt
//             Back - Use 'Back' instead of 'Abort'.
// Return:     G_TRUE / G_ABORT / G_EXIT / G_ERR.
//------------------------------------------------------------------------------
MUIDSP IGMessage(Class *cls, Object *obj, struct MUIP_IG_Message *msg)
{
    // Set correct page and button combination.
    if(!DoMethod(obj, MUIM_IG_PageSet, msg->Message, NULL, P_MESSAGE,
       B_PROCEED_ABORT))
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    struct IGData *my = INST_DATA(cls, obj);

    // Return code.
    inp_t rc;

    // Use 'Abort' or 'Back'?
    if(msg->Back)
    {
        // Set 'Back' button.
        set(my->Abort, MUIA_Text_Contents, tr(S_BACK));

        // Wait for 'Proceed' or 'Back'.
        rc = IGTrans(IGWait(obj, MUIV_IG_Proceed, 2));

        // Restore 'Abort' button.
        set(my->Abort, MUIA_Text_Contents, tr(S_ABRT));
    }
    else
    {
        // Wait for 'Proceed' or 'Abort'.
        rc = IGTrans(IGWait(obj, MUIV_IG_Proceed, 2));
    }

    // G_TRUE / G_ABORT / G_EXIT
    return rc;
}

//------------------------------------------------------------------------------
// IGFinish - Show final message
// Input:     Message - The message
// Return:    G_TRUE / G_ABORT / G_EXIT / G_ERR.
//------------------------------------------------------------------------------
MUIDSP IGFinish(Class *cls, Object *obj, struct MUIP_IG_Finish *msg)
{
    // Silence.
    (void) cls;

    // Set correct page and button combination.
    if(!DoMethod(obj, MUIM_IG_PageSet, msg->Message, NULL, P_MESSAGE, B_OK))
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    // No need to wait for anything specific.
    return IGTrans(IGWait(obj, MUIV_IG_Ok, 1));
}

//------------------------------------------------------------------------------
// IGAbort - Show message and abort
// Input:    Message - The message to be shown
// Return:   G_ABORT / G_ERR.
//------------------------------------------------------------------------------
MUIDSP IGAbort(Class *cls, Object *obj, struct MUIP_IG_Abort *msg)
{
    // Silence.
    (void) cls;

    // Set correct page and button combination.
    if(!DoMethod(obj, MUIM_IG_PageSet, msg->Message, NULL, P_MESSAGE, B_ABORT))
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    // Wait for abort.
    return IGTrans(IGWait(obj, MUIV_IG_AbortOnly, 1));
}

//------------------------------------------------------------------------------
// IGRadio - Show radio buttons
// Input:    Message - The prompt
//           Help - Help text
//           Names - Array of choices (strings)
//           Default - Default selection
//           Back - Use 'Back' instead of 'Abort'.
//           Select - Zero index representing the selected button
// Return:   G_TRUE / G_ABORT / G_EXIT / G_ERR.
//------------------------------------------------------------------------------
MUIDSP IGRadio(Class *cls, Object *obj, struct MUIP_IG_Radio *msg)
{

    if(!DoMethod(obj, MUIM_IG_PageSet, msg->Message, msg->Help, P_MESSAGE,
       B_PROCEED_ABORT))
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    char **nms = (char **) msg->Names;

    if(nms && *nms)
    {
        struct IGData *my = INST_DATA(cls, obj);
        int32_t def = msg->Default;

        // Make sure that the default value is a valid choice.
        while(def && *nms)
        {
            def--;
            nms++;
        }

        // Don't fail if it isn't, use a fallback of 0 instead.
        def = !def ? msg->Default : 0;

        // Unlike most other pages, this one is partly generated on the fly,
        // we have no choice.
        Object *r = (Object *) MUI_NewObject
        (
            MUIC_Radio,
            MUIA_Radio_Active, def,
            MUIA_Radio_Entries, msg->Names,
            TAG_END
        );

        if(r)
        {
            // Prepare before adding radio buttons.
            if(DoMethod(my->Empty, MUIM_Group_InitChange))
            {
                // Return code.
                inp_t rc;

                // Use 'Abort' or 'Back'?
                if(msg->Back)
                {
                    // Set 'Back' button.
                    set(my->Abort, MUIA_Text_Contents, tr(S_BACK));
                }

                // Add radio buttons.
                DoMethod(my->Empty, OM_ADDMEMBER, r);

                // We're done adding things.
                DoMethod(my->Empty, MUIM_Group_ExitChange);

                // Wait for 'Proceed' or 'Back'.
                rc = IGTrans(IGWait(obj, MUIV_IG_Proceed, 2));

                if(msg->Back)
                {
                    // Restore 'Abort' if needed.
                    set(my->Abort, MUIA_Text_Contents, tr(S_ABRT));
                }

                // Prepare before removing radio buttons.
                if(DoMethod(my->Empty, MUIM_Group_InitChange))
                {
                    // Remove radio buttons.
                    DoMethod(my->Empty, OM_REMMEMBER, r);

                    // We're done removing things.
                    DoMethod(my->Empty, MUIM_Group_ExitChange);

                    // Get value from buttons and then kill them. A halt
                    // above will not make any difference.
                    get(r, MUIA_Radio_Active, (int32_t *) msg->Select);
                    MUI_DisposeObject(r);

                    // Unknown status.
                    return rc;
                }
            }

            // The GUI is broken.
            MUI_DisposeObject(r);
        }
    }

    // Unknown error.
    GERR(tr(S_UNER));
    return G_ERR;
}

//------------------------------------------------------------------------------
// IGBool - Get boolean value from user
// Input:   Message - The prompt
//          Help - Help text
//          Yes - True string value
//          No - False string value
//          Back - Use 'Back' instead of 'Abort'.
// Return:  G_TRUE / G_FALSE / G_ABORT / G_ERR
//------------------------------------------------------------------------------
MUIDSP IGBool(Class *cls, Object *obj, struct MUIP_IG_Bool *msg)
{
    if(!DoMethod(obj, MUIM_IG_PageSet, msg->Message, msg->Help, P_MESSAGE,
       B_YES_NO_ABORT))
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    struct IGData *my = INST_DATA(cls, obj);

    // Return code.
    inp_t rc;

    // Set values of true and false.
    set(my->No, MUIA_Text_Contents, msg->No);
    set(my->Yes, MUIA_Text_Contents, msg->Yes);

    if(msg->Back)
    {
        // Set back.
        set(my->AbortYes, MUIA_Text_Contents, tr(S_BACK));

        // Wait for yes, no or back.
        rc = IGTrans(IGWait(obj, MUIV_IG_Yes, 3));

        // Restore abort.
        set(my->AbortYes, MUIA_Text_Contents, tr(S_ABRT));
    }
    else
    {
        // Wait for yes, no or abort.
        rc = IGTrans(IGWait(obj, MUIV_IG_Yes, 3));
    }

    return rc;
}

//------------------------------------------------------------------------------
// IGString - Get string value from user.
// Input:     Message - The prompt
//            Help - Help text
//            Default - Default string value
//            Back - Use 'Back' instead of 'Abort'.
//            String - String return value
// Return:    G_TRUE / G_FALSE / G_ABORT / G_ERR
//------------------------------------------------------------------------------
MUIDSP IGString(Class *cls, Object *obj, struct MUIP_IG_String *msg)
{
    // Show string widget page.
    if(!DoMethod(obj, MUIM_IG_PageSet, msg->Message, msg->Help, P_STRING,
       B_PROCEED_ABORT))
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    struct IGData *my = INST_DATA(cls, obj);

    // Return code.
    inp_t rc;

    // Set initial value of string.
    set(my->String, MUIA_String_Contents, msg->Default);

    // Use 'Abort' or 'Back'?
    if(msg->Back)
    {
        // Set 'Back' button.
        set(my->Abort, MUIA_Text_Contents, tr(S_BACK));

        // Wait for 'Proceed' or 'Back'.
        rc = IGTrans(IGWait(obj, MUIV_IG_Proceed, 2));

        // Restore 'Abort' button.
        set(my->Abort, MUIA_Text_Contents, tr(S_ABRT));
    }
    else
    {
        // Wait for 'Proceed' or 'Abort'.
        rc = IGTrans(IGWait(obj, MUIV_IG_Proceed, 2));
    }

    // No matter what, get string.
    get(my->String, MUIA_String_Contents, (char **) msg->String);

    // Return status.
    return rc;
}

//------------------------------------------------------------------------------
// IGNumber - Get numerical value from user
// Input:     Message - The prompt
//            Help - Help text
//            Min - Minimum allowed value
//            Max - Maximum allowed value
//            Default - Default value
//            Back - Use 'Back' instead of 'Abort'
//            Number - Return value
// Return:    G_TRUE / G_ABORT / G_EXIT / G_ERR
//------------------------------------------------------------------------------
MUIDSP IGNumber(Class *cls, Object *obj, struct MUIP_IG_Number *msg)
{
    // Show slider.
    if(!DoMethod(obj, MUIM_IG_PageSet, msg->Message, msg->Help, P_NUMBER,
       B_PROCEED_ABORT))
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    struct IGData *my = INST_DATA(cls, obj);

    // Return code.
    inp_t rc;

    // Set min, max and default value.
    set(my->Number, MUIA_Numeric_Min, msg->Min);
    set(my->Number, MUIA_Numeric_Max, msg->Max);
    set(my->Number, MUIA_Numeric_Value, msg->Default);

    // Use 'Abort' or 'Back'?
    if(msg->Back)
    {
        // Set 'Back' button.
        set(my->Abort, MUIA_Text_Contents, tr(S_BACK));

        // Wait for 'Proceed' or 'Back'.
        rc = IGTrans(IGWait(obj, MUIV_IG_Proceed, 2));

        // Restore 'Abort' button.
        set(my->Abort, MUIA_Text_Contents, tr(S_ABRT));
    }
    else
    {
        // Wait for 'Proceed' or 'Abort'.
        rc = IGTrans(IGWait(obj, MUIV_IG_Proceed, 2));
    }

    // No matter what, get numerical value.
    get(my->Number, MUIA_Numeric_Value, (int32_t *) msg->Number);

    // Success or halt.
    return rc;
}

//------------------------------------------------------------------------------
// IGCheckBoxes - Show list of radiobuttons
// Input:         Message - The prompt
//                Help - Help text
//                Names - Array of choices (strings)
//                Default - Default bitmask
//                Back - Use 'Back' instead of 'Abort'
//                Bitmap - A bitmask representing the selected button(s)
// Return:        G_TRUE / G_ABORT / G_EXIT / G_ERR
//------------------------------------------------------------------------------
MUIDSP IGCheckBoxes(Class *cls, Object *obj, struct MUIP_IG_CheckBoxes *msg)
{
    if(!DoMethod(obj, MUIM_IG_PageSet, msg->Message, msg->Help, P_MESSAGE,
       B_PROCEED_ABORT))
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    struct IGData *my = INST_DATA(cls, obj);

    // We have no choice but to generate this page on the fly,
    if(DoMethod(my->Empty, MUIM_Group_InitChange))
    {
        size_t i = 0;
        static Object *cb[33];
        char **cs = (char **) msg->Names;

        // Use 'Abort' or 'Back'?
        if(msg->Back)
        {
            // Set 'Back' button.
            set(my->Abort, MUIA_Text_Contents, tr(S_BACK));
        }

        // The maximum number of choices is 32.
        while(*cs && i < 32)
        {
            // Default selection.
            LONG sel = (msg->Default & (1u << i)) ? TRUE : FALSE;

            // New checkbox with default selection.
            Object *c = (Object *) MUI_NewObject
            (
                MUIC_Group,
                MUIA_Group_Horiz, TRUE,
                MUIA_ShowMe, *(*cs) ? TRUE : FALSE,
                MUIA_InputMode, MUIV_InputMode_Toggle,
                MUIA_Selected, *(*cs) ? sel : FALSE,
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

            // On success, add it to the group and save the adress.
            if(c)
            {
                DoMethod(my->Empty, OM_ADDMEMBER, c);
                cb[i++] = c;
                cs++;
            }
            else
            {
                // On error, free all the previous ones and bail out.
                GERR(tr(S_UNER));

                while(i--)
                {
                    DoMethod(my->Empty, OM_REMMEMBER, cb[i]);
                    MUI_DisposeObject(cb[i]);
                }

                // We're done modifying the group.
                DoMethod(my->Empty, MUIM_Group_ExitChange);
                return G_ERR;
            }
        }

        // We're done modifying the group.
        DoMethod(my->Empty, MUIM_Group_ExitChange);

        // Wait for 'Proceed' or 'Back'.
        inp_t rc = IGTrans(IGWait(obj, MUIV_IG_Proceed, 2));

        if(msg->Back)
        {
            // Restore 'Abort' if needed.
            set(my->Abort, MUIA_Text_Contents, tr(S_ABRT));
        }

        // Remove all dynamic objects in group.
        if(DoMethod(my->Empty, MUIM_Group_InitChange))
        {
            // The return value.
            *((int32_t *) msg->Bitmap) = 0;

            while(i--)
            {
                ULONG sel = 0;

                get(cb[i], MUIA_Selected, &sel);
                *((int32_t *) msg->Bitmap) |= (sel ? (1 << i) : 0);
                DoMethod(my->Empty, OM_REMMEMBER, cb[i]);
                MUI_DisposeObject(cb[i]);
            }

            // All cleared.
            DoMethod(my->Empty, MUIM_Group_ExitChange);

            // Unknown status.
            return rc;
        }
    }

    // Unknown error.
    GERR(tr(S_UNER));
    return G_ERR;
}

//------------------------------------------------------------------------------
// IGComplete - Show progress
// Input:       Progress - Installer progress in %
// Return:      G_TRUE / G_FALSE.
//------------------------------------------------------------------------------
MUIDSP IGComplete(Class *cls, Object *obj, struct MUIP_IG_Complete *msg)
{
    struct IGData *my = INST_DATA(cls, obj);

    snprintf(my->Buf, sizeof(my->Buf), "%s (%lu%%)", arg_get(ARG_APPNAME),
        msg->Progress);

    set(Win, MUIA_Window_Title, my->Buf);
    return LG_TRUE;
}

//------------------------------------------------------------------------------
// IGConfirm - Get user confirmation.
// Input:      Message - The prompt
//             Help - Help text
//             Back - Use 'Back' instead of 'Abort'.
// Return:     '1' = proceed, '0' = skip, '-1' = abort
//------------------------------------------------------------------------------
MUIDSP IGConfirm(Class *cls, Object *obj, struct MUIP_IG_Confirm *msg)
{
    struct IGData *my = INST_DATA(cls, obj);
    ULONG top = 0, btm = 0, str = 0;


    // Save the current state of whatever we're showing before we ask for
    // confirmation.
    if(!get(my->Top, MUIA_Group_ActivePage, &top) ||
       !get(my->Bottom, MUIA_Group_ActivePage, &btm) ||
       !get(my->Text, MUIA_Text_Contents, &str))
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    // Allocate memory to hold a copy of the current message.
    size_t osz = strlen((char *) str) + 1;
    char *ost = calloc(osz, 1);

    if(!ost)
    {
        // Unknown error.
        GERR(tr(S_UNER));
        return G_ERR;
    }

    // Copy the current message.
    memcpy(ost, (char *) str, osz);

    // Prompt for confirmation.
    if(DoMethod(obj, MUIM_IG_PageSet, msg->Message, msg->Help,
                P_MESSAGE, B_PROCEED_SKIP_ABORT))
    {
        // Return code.
        inp_t rc;

        // Use 'Abort' or 'Back'?
        if(msg->Back)
        {
            // Set 'Back' button.
            set(my->AbortRun, MUIA_Text_Contents, tr(S_BACK));

            // Wait for 'Proceed', 'Skip' or 'Back'.
            rc = IGTrans(IGWait(obj, MUIV_IG_ProceedRun, 3));

            // Restore 'Abort' button.
            set(my->AbortRun, MUIA_Text_Contents, tr(S_ABRT));
        }
        else
        {
            // Wait for 'Proceed', 'Skip' or 'Abort'.
            rc = IGTrans(IGWait(obj, MUIV_IG_ProceedRun, 3));
        }

        // Restore everything so that things look the way they did
        // before the confirmation dialog was shown.
        set(my->Top, MUIA_Group_ActivePage, top);
        set(my->Bottom, MUIA_Group_ActivePage, btm);
        set(my->Text, MUIA_Text_Contents, ost);

        // We no longer need the old message.
        free(ost);

        // Take care of the user input.
        return rc;
    }

    // We never did show the new message so we can get rid of the old
    // (current).
    free(ost);

    // Unknown error.
    GERR(tr(S_UNER));
    return G_ERR;
}

//------------------------------------------------------------------------------
// IGNew - Overloading OM_NEW
// Input:  See BOOPSI docs
// Return: See BOOPSI docs
//------------------------------------------------------------------------------
MUIDSP IGNew(Class *cls, Object *obj, struct opSet *msg)
{
    // Temp widgets.
    Object *el, *ul, *fp, *pr, *st, *nm, *bp, *em, *tx, *ls, *lg, *tp, *af,
        *ys, *no, *ya, *ab, *ao, *ar;

    // Radio button strings.
    static const char *lev[4], *pre[3], *log[3];

    // Clear to enable check.
    el = ul = fp = pr = st = nm = bp = em = tx = ls = lg = tp = af = ys =
    no = ya = ab = ao = ar = NULL;

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

    // Screen / window backdrop.
    struct Screen *scr = NULL;
    struct Window *win = NULL;

    // Application banner.
    char *img = arg_get(ARG_APPBANNER);

    // Open backdrop screen / window on demand.
    if(GetTagData(MUIA_IG_UseCustomScreen, FALSE, msg->ops_AttrList))
    {
        scr = OpenScreenTags(NULL, SA_PubName, "Installer", SA_LikeWorkbench,
            TRUE, SA_ShowTitle, FALSE, TAG_END);

        if(scr)
        {
            win = OpenWindowTags(NULL, WA_CustomScreen, scr, WA_Borderless,
                TRUE, WA_Backdrop, TRUE, TAG_END);
        }

        if(!scr || !win)
        {
            // Unknown error.
            GERR(tr(S_UNER));
        }
    }

    // The GUI is, as far as possible, a static construct. We're not
    // constructing things on the fly, instead we use paging to let
    // widgets become visible / disappear.
    obj = (Object *) DoSuperNew
    (
        cls, obj,
        MUIA_Window_Title, arg_get(ARG_APPNAME),
        MUIA_Window_AppWindow, TRUE,
        MUIA_Window_ID, MAKE_ID('W','D','L','A'),
        scr ? MUIA_Window_Screen : TAG_IGNORE, scr,
#ifndef __VBCC__
        MUIA_Window_RootObject, MUI_NewObject(
            MUIC_Group,
            /* Application banner */
            MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
            MUIA_Group_Child, MUI_NewObject(
                MUIC_Group,
                MUIA_ShowMe, (img && *img) ? TRUE : FALSE,
                MUIA_Group_Horiz, TRUE,
                MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Dtpic,
                    MUIA_Dtpic_Name, (img && *img) ? img : "",
                    TAG_END),
                MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                TAG_END),
            MUIA_Group_Child, (Object *) MUI_NewObject(
                MUIC_Rectangle,
                MUIA_Rectangle_HBar, TRUE,
                MUIA_ShowMe, (img && *img) ? TRUE : FALSE,
                TAG_END),
            /* Top text */
            MUIA_Group_Child, tx = (Object *) MUI_NewObject(
                MUIC_Text,
                MUIA_Text_Contents, "\n\n\n\n\n\n\n\n\n\n",
                MUIA_Text_SetMax, FALSE,
                MUIA_Text_PreParse, "\33c",
                TAG_END),
            /* Top pager */
            MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
            MUIA_Group_Child, tp = MUI_NewObject(
                MUIC_Group,
                MUIA_Group_PageMode, TRUE,
                /* Page 0 - P_WELCOME */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Group,
                        MUIA_Group_Horiz, TRUE,
                        MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                        MUIA_Group_Child, ul = (Object *) MUI_NewObject(
                            MUIC_Radio,
                            MUIA_Radio_Entries, lev,
                            TAG_END),
                        MUIA_Group_Child, el = (Object *) MUI_NewObject(
                            MUIC_Radio,
                            MUIA_ShowMe, FALSE,
                            MUIA_Radio_Entries, lev + 1,
                            TAG_END),
                        MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                        TAG_END),
                    TAG_END),
                /* Page 1 - P_COPYFILES */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Child, fp = MUI_NewObject(
                        MUIC_Gauge,
                        MUIA_Frame, MUIV_Frame_Gauge,
                        MUIA_ShowMe, TRUE,
                        MUIA_Gauge_Horiz, TRUE,
                        MUIA_Gauge_InfoText, "-",
                        TAG_END),
                    TAG_END),
                /* Page 2 - P_FILEDEST */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Listview,
                        MUIA_Listview_List, ls = MUI_NewObject(
                            MUIC_List,
                            MUIA_ShowMe, FALSE,
                            TAG_END),
                        MUIA_Listview_MultiSelect, MUIV_Listview_MultiSelect_Always,
                        TAG_END),
                    TAG_END),
                /* Page 3 - P_PRETEND_LOG */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Group,
                        MUIA_Group_Horiz, TRUE,
                        MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                        MUIA_Group_Child, pr = (Object *) MUI_NewObject(
                            MUIC_Radio,
                            MUIA_Radio_Entries, pre,
                            TAG_END),
                        MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                        MUIA_Group_Child, lg = (Object *) MUI_NewObject(
                            MUIC_Radio,
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
                    MUIA_Group_Child, em = (Object *) MUI_NewObject(
                        MUIC_Group,
                        MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
                        TAG_END),
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                    TAG_END),
                /* Page 5 - P_STRING */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
                    MUIA_Group_Child, st = (Object *) MUI_NewObject(
                        MUIC_String,
                        MUIA_Frame, MUIV_Frame_String,
                        MUIA_String_MaxLen, BUFSIZ,
                        TAG_END),
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
                    TAG_END),
                /* Page 6 - P_NUMBER */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
                    MUIA_Group_Child, nm = (Object *) MUI_NewObject(
                        MUIC_Slider,
                        MUIA_Slider_Horiz, TRUE,
                        TAG_END),
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
                    TAG_END),
                /* Page 7 - P_ASKFILE */
                MUIA_Group_Child, af = MUI_NewObject(
                    MUIC_Group,
                    TAG_END),
                TAG_END),
            /* Bottom pager */
            MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_VSpace, 0),
            MUIA_Group_Child, bp = MUI_NewObject(
                MUIC_Group,
                MUIA_Group_PageMode, TRUE,
                /* Page 0 - B_PROCEED_ABORT */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Horiz, TRUE,
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_IG_Proceed,
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_PRCD),
                        MUIA_Text_PreParse, "\33c",
                        MUIA_InputMode, MUIV_InputMode_RelVerify,
                        MUIA_Background, MUII_ButtonBack,
                        TAG_END),
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                    MUIA_Group_Child, ab = MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_IG_Abort,
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_ABRT),
                        MUIA_Text_PreParse, "\33c",
                        MUIA_InputMode, MUIV_InputMode_RelVerify,
                        MUIA_Background, MUII_ButtonBack,
                        TAG_END),
                    TAG_END),
                /* Page 1 - B_YES_NO_ABORT */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Horiz, TRUE,
                    MUIA_Group_Child, ys = (Object *) MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_IG_Yes,
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_AYES),
                        MUIA_Text_PreParse, "\33c",
                        MUIA_InputMode, MUIV_InputMode_RelVerify,
                        MUIA_Background, MUII_ButtonBack,
                        TAG_END),
                    MUIA_Group_Child, no = (Object *) MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_IG_No,
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_NONO),
                        MUIA_Text_PreParse, "\33c",
                        MUIA_InputMode, MUIV_InputMode_RelVerify,
                        MUIA_Background, MUII_ButtonBack,
                        TAG_END),
                    MUIA_Group_Child, ya = (Object *) MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_IG_AbortYes,
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_ABRT),
                        MUIA_Text_PreParse, "\33c",
                        MUIA_InputMode, MUIV_InputMode_RelVerify,
                        MUIA_Background, MUII_ButtonBack,
                        TAG_END),
                    TAG_END),
                /* Page 2 - B_ABORT */
                MUIA_Group_Child, (Object *) MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Horiz, TRUE,
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                    MUIA_Group_Child, ao = MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_IG_AbortOnly,
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_ABRT),
                        MUIA_Text_PreParse, "\33c",
                        MUIA_InputMode, MUIV_InputMode_RelVerify,
                        MUIA_Background, MUII_ButtonBack,
                        TAG_END),
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                    TAG_END),
                /* Page 3 - B_PROCEED_SKIP_ABORT */
                MUIA_Group_Child, (Object *) MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Horiz, TRUE,
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_IG_ProceedRun,
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_PRCD),
                        MUIA_Text_PreParse, "\33c",
                        MUIA_InputMode, MUIV_InputMode_RelVerify,
                        MUIA_Background, MUII_ButtonBack,
                        TAG_END),
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_IG_SkipRun,
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_SKIP),
                        MUIA_Text_PreParse, "\33c",
                        MUIA_InputMode, MUIV_InputMode_RelVerify,
                        MUIA_Background, MUII_ButtonBack,
                        TAG_END),
                    MUIA_Group_Child, ar = MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_IG_AbortRun,
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_ABRT),
                        MUIA_Text_PreParse, "\33c",
                        MUIA_InputMode, MUIV_InputMode_RelVerify,
                        MUIA_Background, MUII_ButtonBack,
                        TAG_END),
                    TAG_END),
                /* Page 4 - B_OK */
                MUIA_Group_Child, MUI_NewObject(
                    MUIC_Group,
                    MUIA_Group_Horiz, TRUE,
                    MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Text,
                        MUIA_UserData, MUIV_IG_Ok,
                        MUIA_Frame, MUIV_Frame_Button,
                        MUIA_Text_Contents, tr(S_OKEY),
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
#endif /* !__VBCC__ */
        TAG_END
    );

    // Initialize the rest if the parent is OK.
    if(obj)
    {
        struct IGData *my = INST_DATA(cls, obj);

        // Initialize timer struct.
        my->Ticker.ihn_Object = obj;
        my->Ticker.ihn_Flags = MUIIHNF_TIMER;
        my->Ticker.ihn_Method = MUIM_IG_Ticker;
        my->Ticker.ihn_Millis = 10;

        // Backdrop.
        my->Scr = scr;
        my->Win = win;

        // Save widgets.
        if(el && ul && fp && pr && st && nm && bp && em && tx &&
           ls && lg && tp && af && ys && no && ab && ao && ar)
        {
            my->ExpertLevel = el;
            my->AbortOnly = ao;
            my->UserLevel = ul;
            my->Progress = fp;
            my->AbortRun = ar;
            my->AbortYes = ya;
            my->Pretend = pr;
            my->String = st;
            my->Number = nm;
            my->Bottom = bp;
            my->Empty = em;
            my->Abort = ab;
            my->Text = tx;
            my->List = ls;
            my->Log = lg;
            my->Top = tp;
            my->Ask = af;
            my->Yes = ys;
            my->No = no;
        }
        else
        {
            // Forgot something.
            MUI_DisposeObject(obj);
            GERR(tr(S_UNER));
            obj = NULL;
        }
    }

    // Done.
    return (IPTR) obj;
}

//------------------------------------------------------------------------------
// IGSetup - Overloading MUIM_Setup
// Input:    See MUI docs
// Return:   See MUI docs
//------------------------------------------------------------------------------
MUIDSP IGSetup(Class *cls, Object *obj, struct MUI_RenderInfo *msg)
{
    // Let our parent set itself up first
    if(!DoSuperMethodA (cls, obj, (Msg) msg))
    {
        GERR(tr(S_STFL));
        return FALSE;
    }

    // Nothing to do.
    return TRUE;
}

//------------------------------------------------------------------------------
// IGDispose - Overloading OM_DISPOSE
// Input:      See BOOPSI docs
// Return:     See BOOPSI docs
//------------------------------------------------------------------------------
MUIDSP IGDispose (Class *cls, Object *obj, Msg msg)
{
    struct IGData *my = INST_DATA(cls, obj);

    // Close backdrop window.
    if(my->Win)
    {
        CloseWindow(my->Win);
    }

    return DoSuperMethodA(cls, obj, msg);
}

//------------------------------------------------------------------------------
// IGCleanup - Overloading MUIM_Cleanup
// Input:      See MUI docs
// Return:     See MUI docs
//------------------------------------------------------------------------------
MUIDSP IGCleanup (Class *cls, Object *obj, Msg msg)
{
    return (IPTR) DoSuperMethodA(cls, obj, (Msg) msg);
}

//------------------------------------------------------------------------------
// IGDispatch - MUI custom class dispatcher
// Input:       Pass through
// Return:      Pass through
//------------------------------------------------------------------------------
DISPATCH(IG)
{
    DISPATCH_HEAD;

    // Dispatch according to MethodID
    switch (msg->MethodID)
    {
        case OM_NEW:
            return IGNew (cls, obj, (struct opSet *) msg);

        case MUIM_Setup:
            return IGSetup (cls, obj, (struct MUI_RenderInfo *) msg);

        case OM_DISPOSE:
            return IGDispose (cls, obj, msg);

        case MUIM_Cleanup:
            return IGCleanup (cls, obj, msg);

        case MUIM_IG_Init:
            return IGInit(cls, obj);

        case MUIM_IG_GetCustomScreen:
            return IGGetCustomScreen(cls, obj);

        case MUIM_IG_GetScreenProp:
            return IGGetScreenProp(cls, obj,
                                  (struct MUIP_IG_GetScreenProp *) msg);

        case MUIM_IG_GetWindowProp:
            return IGGetWindowProp(cls, obj,
                                  (struct MUIP_IG_GetWindowProp *) msg);

        case MUIM_IG_Welcome:
            return IGWelcome(cls, obj, (struct MUIP_IG_Welcome *) msg);

        case MUIM_IG_AskFile:
            return IGAskFile(cls, obj, (struct MUIP_IG_AskFile *) msg);

        case MUIM_IG_PageSet:
            return IGPageSet(cls, obj, (struct MUIP_IG_PageSet *) msg);

        case MUIM_IG_CopyFilesStart:
            return IGCopyFilesStart(cls, obj, (struct MUIP_IG_CopyFilesStart *) msg);

        case MUIM_IG_CopyFilesSetCur:
            return IGCopyFilesSetCur(cls, obj, (struct MUIP_IG_CopyFilesSetCur *) msg);

        case MUIM_IG_CopyFilesEnd:
            return IGCopyFilesEnd(cls, obj);

        case MUIM_IG_CopyFilesAdd:
            return IGCopyFilesAdd(cls, obj, (struct MUIP_IG_CopyFilesAdd *) msg);

        case MUIM_IG_Exit:
            return IGExit(cls, obj, (struct MUIP_IG_Exit *) msg);

        case MUIM_IG_Message:
            return IGMessage(cls, obj, (struct MUIP_IG_Message *) msg);

        case MUIM_IG_Finish:
            return IGFinish(cls, obj, (struct MUIP_IG_Finish *) msg);

        case MUIM_IG_Working:
            return IGWorking(cls, obj, (struct MUIP_IG_Working *) msg);

        case MUIM_IG_Effect:
            return IGEffect(cls, obj, (struct MUIP_IG_Effect *) msg);

        case MUIM_IG_CloseMedia:
            return IGCloseMedia(cls, obj, (struct MUIP_IG_CloseMedia *) msg);

        case MUIM_IG_SetMedia:
            return IGSetMedia(cls, obj, (struct MUIP_IG_SetMedia *) msg);

        case MUIM_IG_ShowMedia:
            return IGShowMedia(cls, obj, (struct MUIP_IG_ShowMedia *) msg);

        case MUIM_IG_ShowPicture:
            return IGShowPicture(cls, obj, (struct MUIP_IG_ShowPicture *) msg);

        case MUIM_IG_Abort:
            return IGAbort(cls, obj, (struct MUIP_IG_Abort *) msg);

        case MUIM_IG_Radio:
            return IGRadio(cls, obj, (struct MUIP_IG_Radio *) msg);

        case MUIM_IG_Bool:
            return IGBool(cls, obj, (struct MUIP_IG_Bool *) msg);

        case MUIM_IG_String:
            return IGString(cls, obj, (struct MUIP_IG_String *) msg);

        case MUIM_IG_Number:
            return IGNumber(cls, obj, (struct MUIP_IG_Number *) msg);

        case MUIM_IG_CheckBoxes:
            return IGCheckBoxes(cls, obj, (struct MUIP_IG_CheckBoxes *) msg);

        case MUIM_IG_Complete:
            return IGComplete(cls, obj, (struct MUIP_IG_Complete *) msg);

        case MUIM_IG_Ticker:
            return DoMethod(_app(obj), MUIM_Application_ReturnID, MUIV_IG_Tick);

        case MUIM_IG_Confirm:
            return IGConfirm(cls, obj, (struct MUIP_IG_Confirm *) msg);
    }

    // Unknown method, promote to parent.
    return DoSuperMethodA (cls, obj, msg);
}
#endif /* defined(AMIGA) && !defined(LG_TEST) */


//.   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+*****************************************************************************
//##############################################################################
//##############################################################################
//+*****************************************************************************
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//..............................................................................
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//.   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .
//
// The gui_* functions below serve as glue between the platform independent
// parts of InstallerLG and the Amiga specific Zune / MUI parts. On non Amiga
// systems, arguments are written to stdout to facilitate testing.

// Amiga style version string.
static char version[] __attribute__((used)) = VERSION_STRING;

//------------------------------------------------------------------------------
// Name:        gui_init
// Description: Initialize and show GUI.
// Input:       bool scr: Use custom screen.
// Return:      inp_t: G_TRUE / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_init(bool scr)
{
#if defined(AMIGA) && !defined(LG_TEST)
# ifdef __amigaos4__
    struct Library *MUIMasterBase = OpenLibrary("muimaster.library", 19);

    if(!MUIMasterBase)
    {
        GERR(tr(S_FMCC));
        return G_ERR;
    }

    IMUIMaster = (struct MUIMasterIFace *)
        GetInterface(MUIMasterBase, "main", 1, NULL);

    if(!IMUIMaster)
    {
        GERR(tr(S_FMCC));
        return G_ERR;
    }
# endif /* __amigaos4__ */

    Object *App;

    // Create our GUI class.
    IGClass = (struct MUI_CustomClass *) MUI_CreateCustomClass
    (
        NULL, MUIC_Window, NULL,
        sizeof (struct CLASS_DATA(IG)),
        (APTR) DISPATCH_GATE (IG)
    );

    // Bail out on error.
    if(!IGClass)
    {
        GERR(tr(S_FMCC));
        return G_ERR;
    }

    // Create application using our newly created class.
    App = (Object *) MUI_NewObject(
        MUIC_Application,
        MUIA_Application_Title, tr(S_INST),
        MUIA_Application_Version, version + 1,
        MUIA_Application_Description, "App installation utility",
        MUIA_Application_HelpFile, "InstallerLG.guide",
        MUIA_Application_Window, Win = (Object *) NewObject(
            IGClass->mcc_Class, NULL,
            MUIA_IG_UseCustomScreen, scr ? TRUE : FALSE,
            TAG_END),
        TAG_END
    );

    // Bail out on error.
    if(!App)
    {
        GERR(tr(S_MAPP));
        return G_ERR;
    }

    // Internal initialization.
    if(!DoMethod(Win, MUIM_IG_Init))
    {
        // Bail out on error.
        GERR(tr(S_FINT));
        gui_exit();

        return G_ERR;
    }

    // Open the window to finish setup.
    set(Win, MUIA_Window_Open, TRUE);
    DoMethod(Win, MUIM_Show);

    return G_TRUE;
#else
    OUT("%s\n", scr ? "e" : "");
    return strlen(version + 1) ? G_TRUE : G_ERR;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_exit
// Description: Close GUI and free GUI resources.
// Input:       -
// Return:      -
//------------------------------------------------------------------------------
void gui_exit(void)
{
#if defined(AMIGA) && !defined(LG_TEST)
    // Must check for NULL. Class creation might have failed.
    if(IGClass)
    {
        // Save screen if we're using a custom one.
        struct Screen *scr = (struct Screen *)
        DoMethod(Win, MUIM_IG_GetCustomScreen);

        // Close window.
        set(Win, MUIA_Window_Open, FALSE);

        // Destroy application.
        MUI_DisposeObject(_app(Win));

        // Destroy custom class.
        MUI_DeleteCustomClass(IGClass);

        // Have we used a custom screen?
        if(scr)
        {
            // It's no longer needed.
            CloseScreen(scr);
        }
    }
# ifdef __amigaos4__
    if(IMUIMaster)
    {
        DropInterface((struct Interface *) IMUIMaster);
        CloseLibrary((struct Library *) MUIMasterBase);
    }
# endif /* __amigaos4__ */
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_message
// Description: Show message.
// Input:       const char *msg: Message shown to the user.
//              bool bck: Enable back mode.
// Return:      inp_t: G_TRUE / G_ABORT / G_EXIT / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_message(const char *msg, bool bck)
{
#if defined(AMIGA) && !defined(LG_TEST)
    return (inp_t) DoMethod(Win, MUIM_IG_Message, msg, bck);
#else
    OUT("%s%d", msg, !!bck);
    return G_TRUE;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_finish
// Description: Show final message.
// Input:       const char *msg: Message shown to the user.
// Return:      inp_t: G_TRUE / G_ABORT / G_EXIT / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_finish(const char *msg)
{
#if defined(AMIGA) && !defined(LG_TEST)
    return (inp_t) DoMethod(Win, MUIM_IG_Finish, msg);
#else
    OUT("%s", msg);
    return G_TRUE;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_working
// Description: Show busy message.
// Input:       const char *msg:    Message shown to the user.
// Return:      inp_t: G_TRUE / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_working(const char *msg)
{
#if defined(AMIGA) && !defined(LG_TEST)
    return (inp_t) DoMethod(Win, MUIM_IG_Working, msg);
#else
    OUT("%s", msg);
    return G_TRUE;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_abort
// Description: Show message and abort.
// Input:       const char *msg: Message shown to the user.
// Return:      -
//------------------------------------------------------------------------------
void gui_abort(const char *msg)
{
#if defined(AMIGA) && !defined(LG_TEST)
    DoMethod(Win, MUIM_IG_Abort, msg);
#else
    OUT("%s", msg);
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_choice
// Description: Get user selecton of a single string out of a list of strings.
// Input:       const char *msg:    Message shown to the user.
//              const char *hlp:    Help text.
//              const char **nms:   List of strings.
//              int32_t def:        Default choice (0-index)
//              bool bck:           Enable back mode.
//              int32_t *ret:       The choice (0-index).
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_choice(const char *msg, const char *hlp, const char **nms,
                 int32_t def, bool bck, int32_t *ret)
{
#if defined(AMIGA) && !defined(LG_TEST)
    return (inp_t) DoMethod(Win, MUIM_IG_Radio, msg, hlp, nms, def, bck, ret);
#else
    OUT("%s%s%s%d%d\n", msg, hlp, *nms, def, !!bck);
    *ret = def;
    return G_TRUE;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_options
// Description: Get user selection of any number / combination of strings
//              from a list.
// Input:       const char *msg:    Message shown to the user.
//              const char *hlp:    Help text.
//              const char **nms:   List of strings from which to choose.
//              int32_t def:        Default bitmap.
//              bool bck:           Enable back mode.
//              int32_t *ret:       A bitmap representing the selection.
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_options(const char *msg, const char *hlp, const char **nms,
                  int32_t def, bool bck, int32_t *ret)
{
#if defined(AMIGA) && !defined(LG_TEST)
    return (inp_t) DoMethod(Win, MUIM_IG_CheckBoxes, msg, hlp, nms, def, bck,
        ret);
#else
    OUT("%s%s%s%d%d%d\n", msg, hlp, *nms, def, *ret, !!bck);
    *ret = def;
    return G_TRUE;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_bool
// Description: Get boolean value from user, e.g 'Yes' / 'No'.
// Input:       const char *msg: Message shown to the user.
//              const char *hlp: Help text.
//              const char *yes: True string.
//              const char *nay: False string.
//              bool bck: Enable back mode.
// Return:      inp_t: G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_bool(const char *msg, const char *hlp, const char *yes,
               const char *nay, bool bck)
{
#if defined(AMIGA) && !defined(LG_TEST)
    return (inp_t) DoMethod(Win, MUIM_IG_Bool, msg, hlp, yes, nay, bck);
#else
    OUT("%s%s%s%s%d\n", msg, hlp, yes, nay, !!bck);
    return G_TRUE;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_string
// Description: Get string value from user.
// Input:       const char *msg:    Message shown to the user.
//              const char *hlp:    Help text.
//              const char *def:    Default string value.
//              bool  bck:          Enable back mode.
//              const char **ret:   String value from user.
// Return:      inp_t: G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_string(const char *msg, const char *hlp, const char *def,
                 bool bck, const char **ret)
{
#if defined(AMIGA) && !defined(LG_TEST)
    return (inp_t) DoMethod(Win, MUIM_IG_String, msg, hlp, def, bck, ret);
#else
    OUT("%s%s%s%d\n", msg, hlp, def, !!bck);
    *ret = def;
    return G_TRUE;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_number
// Description: Get numerical value from user.
// Input:       const char *msg:    Message shown to the user.
//              const char *hlp:    Help text.
//              int32_t min:        Minimum value.
//              int32_t max:        Maximum value.
//              int32_t def:        Default value.
//              bool bck:           Enable back mode.
//              int32_t *ret:       Return value.
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_number(const char *msg, const char *hlp, int32_t min, int32_t max,
                 int32_t def, bool bck, int32_t *ret)
{
#if defined(AMIGA) && !defined(LG_TEST)
    return (inp_t) DoMethod(Win, MUIM_IG_Number, msg, hlp, min, max, def, bck,
        ret);
#else
    OUT("%s%s%d%d%d\n", msg, hlp, min, max, !!bck);
    *ret = def;
    return G_TRUE;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_welcome
// Description: Show welcome message and prompt for user level / installer
//              mode. Note that the 'lvl', 'lgf', and 'prt' parameters act
//              as both input and output.
// Input:       const char *msg:    Welcome message.
//              int32_t *lvl:       User level return and input value.
//              int32_t *lgf:       Log settings return and input value.
//              int32_t *prt:       Pretend mode return and input value.
//              int32_t min:        Minimum user level.
//              bool npr:           Disable pretend mode.
//              bool nlg:           Disable logging.
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_welcome(const char *msg, int32_t *lvl, int32_t *lgf, int32_t *prt,
                  int32_t min, bool npr, bool nlg)
{
#if defined(AMIGA) && !defined(LG_TEST)
    return (inp_t) DoMethod(Win, MUIM_IG_Welcome, msg, lvl, lgf, prt, min, npr,
        nlg);
#else
    OUT("%s%d%d%d%d%d%d\n", msg, *lvl, *lgf, *prt, min, !!npr, !!nlg);
    return G_TRUE;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_askdir
// Description: Get directory name from user.
// Input:       const char *msg:    Message shown to the user.
//              const char *hlp:    Help text.
//              bool pth:           Allow non-existing default.
//              bool dsk:           Show drive list first.
//              bool asn:           Assigns can satisfy the request as well.
//              const char *def:    Default value.
//              bool  bck:          Enable back mode.
//              const char **ret:   File / dir string value.
// Return:      inp_t: G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_askdir(const char *msg, const char *hlp, bool pth, bool dsk, bool asn,
                 const char *def, bool bck, const char **ret)
{
#if defined(AMIGA) && !defined(LG_TEST)
    return (inp_t) DoMethod(Win, MUIM_IG_AskFile, msg, hlp, pth, dsk, asn, def,
        TRUE, bck, ret);
#else
    if(msg && hlp && def && ret)
    {
        *ret = def;
        OUT("%s%s%d%d%d%s%d\n", msg, hlp, !!pth, !!dsk, !!asn, def, !!bck);
        return G_TRUE;
    }
    return G_FALSE;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_askfile
// Description: Get filename from user.
// Input:       const char *msg:    Message shown to the user.
//              const char *hlp:    Help text.
//              bool pth:           Allow non-existing default.
//              bool dsk:           Show drive list first.
//              const char *def:    Default value.
//              bool  bck:          Enable back mode.
//              const char **ret:   File / dir string value.
// Return:      inp_t: G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_askfile(const char *msg, const char *hlp, bool pth, bool dsk,
                  const char *def, bool bck, const char **ret)
{
#if defined(AMIGA) && !defined(LG_TEST)
    return (inp_t) DoMethod(Win, MUIM_IG_AskFile, msg, hlp, pth, dsk, FALSE,
        def, FALSE, bck, ret);
#else
    if(msg && hlp && def && ret)
    {
        *ret = def;
        OUT("%s%s%s%d%d%d\n", msg, hlp, def, !!pth, !!dsk, !!bck);
        return G_TRUE;
    }
    return G_FALSE;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_copyfiles_start
// Description: Show file copy confirmation requester with a populated file
//              list.
// Input:       const char *msg:    Message to be shown.
//              const char *hlp:    Help text.
//              pnode_p lst:        List of files / directories.
//              bool cnf:           Confirmation.
//              bool bck:           Enable back mode.
// Return:      inp_t: G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_copyfiles_start(const char *msg, const char *hlp, pnode_p lst,
                          bool cnf, bool bck)
{
#if defined(AMIGA) && !defined(LG_TEST)
    return (inp_t) DoMethod(Win, MUIM_IG_CopyFilesStart, msg, hlp, lst, cnf,
        bck);
#else
    if(lst)
    {
        // Start copy.
        OUT("%s\n", "sc");

        if(cnf)
        {
            OUT("%s%s%d\n", msg ? msg : "", hlp ? hlp : "", !!bck);
            return G_FALSE;
        }
        return G_TRUE;
    }
    return G_ERR;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_copyfiles_setcur
// Description: Update progress gauge and show current filename.
// Input:       const char *cur: Filename.
//              bool nga: Hide gauge.
//              bool bck: Enable back mode.
// Return:      inp_t: G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_copyfiles_setcur(const char *cur, bool nga, bool bck)
{
#if defined(AMIGA) && !defined(LG_TEST)
    return (inp_t) DoMethod(Win, MUIM_IG_CopyFilesSetCur, cur, nga, bck);
#else
    (void) cur;
    static bool done;

    // We can't do this more than once. If we do, tests will depend on the
    // order of files and directories on the host system.
    if(!done)
    {
        OUT("N%dB%d\n", !!nga, !!bck);
        done = true;
    }
    return G_TRUE;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_copyfiles_end
// Description: End file copy. Must be invoked after gui_copyfiles_start().
// Input:       -
// Return:      -
//------------------------------------------------------------------------------
void gui_copyfiles_end(void)
{
#if defined(AMIGA) && !defined(LG_TEST)
    DoMethod(Win, MUIM_IG_CopyFilesEnd);
#else
    OUT("%s\n", "ec");
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_complete
// Description: Show progress gauge.
// Input:       int32_t com: Progress in percent.
// Return:      -
//------------------------------------------------------------------------------
void gui_complete(int32_t com)
{
#if defined(AMIGA) && !defined(LG_TEST)
    DoMethod(Win, MUIM_IG_Complete, com);
#else
    OUT("%d\n", com);
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_confirm
// Description: Get user confirmation.
// Input:       const char *msg:    Message shown to the user.
//              const char *hlp:    Help text.
//              bool bck:           Enable back mode.
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
inp_t gui_confirm(const char *msg, const char *hlp, bool bck)
{
#if defined(AMIGA) && !defined(LG_TEST)
    return (inp_t) DoMethod(Win, MUIM_IG_Confirm, msg, hlp, bck);
#else
    OUT("%s%s%d\n", msg, hlp, !!bck);
    return G_TRUE;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_error
// Description: Show error message.
// Input:       int32_t line: Line number.
//              const char *type: Error description.
//              const char *info: Extra info, e.g. filename.
// Return:      -
//------------------------------------------------------------------------------
void gui_error(int32_t line, const char *type, const char *info)
{
#if defined(AMIGA) && !defined(LG_TEST)
    static char err[BUFSIZ];
    static struct EasyStruct es = { .es_TextFormat = (UBYTE *) &err,
                                    .es_StructSize = sizeof(struct EasyStruct)};

    es.es_Title = (UBYTE *) tr(S_ERRS);
    es.es_GadgetFormat = (UBYTE *) tr(S_OKEY);
    snprintf(err, sizeof(err), tr(S_LERR), line, type, info);

    // We don't have any way of knowing whether this really works.
    EasyRequest(NULL, &es, NULL);
#else
    OUT(tr(S_LERR), line, type, info);
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_effect
// Description: Show custom screen gradient.
// Input:       int32_t eff:    Type and position.
//              int32_t cl1:    Color 1.
//              int32_t cl2:    Color 2.
// Return:      -
//------------------------------------------------------------------------------
void gui_effect(int32_t eff, int32_t cl1, int32_t cl2)
{
#if defined(AMIGA) && !defined(LG_TEST)
    DoMethod(Win, MUIM_IG_Effect, eff, cl1, cl2);
#else
    OUT("%d:%d:%d\n", eff, cl1, cl2);
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_closemedia
// Description: FIXME
// Input:       int32_t mid:    Media ID.
// Return:      FIXME
//------------------------------------------------------------------------------
inp_t gui_closemedia(int32_t mid)
{
#if defined(AMIGA) && !defined(LG_TEST)
    DoMethod(Win, MUIM_IG_CloseMedia, mid);
#else
    OUT("%d\n", mid);
#endif /* defined(AMIGA) && !defined(LG_TEST) */
    return G_TRUE;
}

//------------------------------------------------------------------------------
// Name:        gui_setmedia
// Description: FIXME
// Input:       int32_t mid:        Media ID
//              int32_t act:        Action
//              const char* par:    Parameter
// Return:      FIXME
//------------------------------------------------------------------------------
inp_t gui_setmedia(int32_t mid, int32_t act, const char *par)
{
#if defined(AMIGA) && !defined(LG_TEST)
    DoMethod(Win, MUIM_IG_SetMedia, mid, act, par);
#else
    OUT("%d:%d:%s\n", mid, act, par ? par : "_");
#endif /* defined(AMIGA) && !defined(LG_TEST) */
    return G_TRUE;
}

//------------------------------------------------------------------------------
// Name:        gui_showmedia
// Description: FIXME
// Input:       FIXME
// Return:      FIXME
//------------------------------------------------------------------------------
inp_t gui_showmedia(int32_t *mid, const char* mda, int32_t act)
{
#if defined(AMIGA) && !defined(LG_TEST)
    DoMethod(Win, MUIM_IG_ShowMedia, mid, mda, act);
#else
    static int32_t num;
    *mid = num++;
    OUT("%d:%d:%s\n", *mid, act, mda ? mda : "_");
#endif /* defined(AMIGA) && !defined(LG_TEST) */
    return G_TRUE;
}

//------------------------------------------------------------------------------
// Name:        gui_query_screen
// Description: FIXME
// Input:       FIXME
// Return:      FIXME
//------------------------------------------------------------------------------
void gui_query_screen(int32_t *width, int32_t *height, int32_t *depth,
                      int32_t *colors)
{
#if defined(AMIGA) && !defined(LG_TEST)
    DoMethod(Win, MUIM_IG_GetScreenProp, width, height, depth, colors);
#else
    *width = 640;
    *height = 256;
    *colors = 4;
    *depth = 2;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}

//------------------------------------------------------------------------------
// Name:        gui_query_window
// Description: FIXME
// Input:       FIXME
// Return:      FIXME
//------------------------------------------------------------------------------
void gui_query_window(int32_t *width, int32_t *height, int32_t *upper,
                      int32_t *lower, int32_t *left, int32_t *right)
{
#if defined(AMIGA) && !defined(LG_TEST)
    DoMethod(Win, MUIM_IG_GetWindowProp, width, height, upper, lower, left,
             right);
#else
    *width = *right = 320;
    *height = *lower = 128;
    *upper = *left = 0;
#endif /* defined(AMIGA) && !defined(LG_TEST) */
}
