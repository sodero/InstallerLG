/*
 */

#include "gui.h"
#include "resource.h"

#ifdef AMIGA
#include <libraries/asl.h>
#include <libraries/gadtools.h>
#include <mui/TheBar_mcc.h> 
#include <graphics/rpattr.h>
#include <proto/icon.h>
#include <proto/iffparse.h>
#include <proto/graphics.h>
#include <proto/cybergraphics.h>
#include <proto/keymap.h>
#include <proto/muimaster.h>
#include <cybergraphx/cybergraphics.h>
#include <devices/rawkeycodes.h>
#include <clib/debug_protos.h>
#include <clib/alib_protos.h>
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
    struct MUI_InputHandlerNode ticker;
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
#define MUIM_InstallerGui_Run              (TAGBASE_sTx + 111)
#define MUIM_InstallerGui_Message          (TAGBASE_sTx + 112)
#define MUIM_InstallerGui_Confirm          (TAGBASE_sTx + 113)
#define MUIM_InstallerGui_Radio            (TAGBASE_sTx + 114)
#define MUIM_InstallerGui_Bool             (TAGBASE_sTx + 115)
#define MUIM_InstallerGui_String           (TAGBASE_sTx + 116)
#define MUIM_InstallerGui_Number           (TAGBASE_sTx + 117)
#define MUIM_InstallerGui_CheckBoxes       (TAGBASE_sTx + 118)
#define MUIM_InstallerGui_AskFile          (TAGBASE_sTx + 119)

struct MUIP_InstallerGui_Init
{
    ULONG MethodID;
};

struct MUIP_InstallerGui_Welcome
{
    ULONG MethodID;
    ULONG Message;
};

struct MUIP_InstallerGui_CopyFilesStart
{
    ULONG MethodID;
    ULONG Message;
    ULONG NumberOfFiles;
};

struct MUIP_InstallerGui_CopyFilesSetCur
{
    ULONG MethodID;
    ULONG File;
    ULONG NoGauge;
};

struct MUIP_InstallerGui_Exit
{
    ULONG MethodID;
    ULONG Message;
};

struct MUIP_InstallerGui_Complete
{
    ULONG MethodID;
    ULONG Progress;
};

struct MUIP_InstallerGui_CopyFilesAdd
{
    ULONG MethodID;
    ULONG File;
    ULONG ID;
};

struct MUIP_InstallerGui_Run
{
    ULONG MethodID;
    ULONG Message;
    ULONG Help;
};

struct MUIP_InstallerGui_Message
{
    ULONG MethodID;
    ULONG Message;
    ULONG Immediate;
};

struct MUIP_InstallerGui_Confirm
{
    ULONG MethodID;
    ULONG Message;
};

struct MUIP_InstallerGui_Radio
{
    ULONG MethodID;
    ULONG Message;
    ULONG Help;
    ULONG Names;
    ULONG Default; 
};

struct MUIP_InstallerGui_Bool
{
    ULONG MethodID;
    ULONG Message;
    ULONG Help;
    ULONG Yes;
    ULONG No;
};

struct MUIP_InstallerGui_String
{
    ULONG MethodID;
    ULONG Message;
    ULONG Help;
    ULONG Default; 
    ULONG Halt; 
};

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

struct MUIP_InstallerGui_CheckBoxes
{
    ULONG MethodID;
    ULONG Message;
    ULONG Help;
    ULONG Names;
    ULONG Default; 
};

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
#define B_PROCEED_ABORT                    0
#define B_YES_NO                           1
#define B_ABORT                            2
#define B_PROCEED_SKIP_ABORT               3
#define B_PROCEED                          4
#define B_NONE                             5
#define P_WELCOME                          0
#define P_COPYFILES                        1
#define P_FILEDEST                         2
#define P_PRETEND_LOG                      3
#define P_MESSAGE                          4
#define P_STRING                           5
#define P_NUMBER                           6
#define P_ASKFILE                          7

//----------------------------------------------------------------------------
// InstallerGuiWait - PRIVATE: Wait for notification(s)
// Input:             notif - Start notification value 
//                    range - Number of values to check for
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
        for(n = 0; n < range; n++)
        {
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
// Return:            TRUE 
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
            MUIA_Window_CloseRequest, TRUE, _app(obj), 2, 
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

        // Done.
        return TRUE; 
    }
    else
    {
        GERR(tr(S_UNER)); 
        return FALSE; 
    }
}

//----------------------------------------------------------------------------
// InstallerGuiPageSet - PRIVATE: Set page / buttons and display text
// Input:                Top page 
//                       Button page 
//                       Top text message
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

    if(txt && con && but)
    {
        set(con, MUIA_Group_ActivePage, top);
        set(but, MUIA_Group_ActivePage, btm);

        if(msg)
        {
            set(txt, MUIA_ShowMe, FALSE);
            set(txt, MUIA_Text_Contents, msg);
            set(txt, MUIA_ShowMe, TRUE);
        }

        return TRUE; 
    }

    GERR(tr(S_UNER)); 
    return FALSE; 
}

//----------------------------------------------------------------------------
// InstallerGuiWelcome - Show welcome message 
// Input:                Message - the welcome message text
// Return:               4 3 2 1  <- Bit number
//                       ^ ^ ^ ^
//                       | | | |
//                       | | | +- User level LSB
//                       | | +--- User level MSB
//                       | +----- Log to file 
//                       +------- Pretend
//
//                       User level 0 = abort
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiWelcome(Class *cls,
                                Object *obj,
                                struct MUIP_InstallerGui_Welcome *msg)
{
    if(InstallerGuiPageSet(obj, P_WELCOME, B_PROCEED_ABORT, 
                           msg->Message))
    {
        ULONG b = InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2); 

        if(b == MUIV_InstallerGui_Proceed)
        {
            ULONG pat; 

            Object *user = (Object *) DoMethod
            (
                obj, MUIM_FindUData, 
                MUIV_InstallerGui_UserLevel
            );

            if(user)
            {
                // Novice, Intermediate, Expert. 
                get(user, MUIA_Radio_Active, &pat); 

                // MUI is one step behind, fix that
                pat++; 
                
                // Don't show logging and pretend mode
                // settings to 'Novice' users.
                if(pat > 1)
                {
                    if(InstallerGuiPageSet(obj, P_PRETEND_LOG, B_PROCEED_ABORT, 
                                          (ULONG) ""))
                    {
                        b = InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2); 

                        if(b == MUIV_InstallerGui_Proceed)
                        {
                            Object *prt = (Object *) DoMethod
                            (
                                obj, MUIM_FindUData, 
                                MUIV_InstallerGui_Pretend
                            );

                            Object *lgf = (Object *) DoMethod
                            (
                                obj, MUIM_FindUData, 
                                MUIV_InstallerGui_Logging
                            );
                            
                            if(prt && lgf)
                            {
                                ULONG prp, lgp; 

                                get(prt, MUIA_Radio_Active, &prp); 
                                get(lgf, MUIA_Radio_Active, &lgp); 

                                pat |= ((lgp << 2) | (prp << 3));

                                return pat; 
                            }
                        }
                        else
                        {
                            return 0; 
                        }
                    }
                }
                else
                {
                    return pat; 
                }
            }
        }
        else
        {
            return 0; 
        }
    }

    // We have a MUI problem
    GERR(tr(S_UNER)); 
    return 0; 
}

//----------------------------------------------------------------------------
// InstallerGuiAskFile - Show file / directory requester 
// Input:                Message - Top text 
//                       Default - Default file / directory
// Return:               File / directory name or NULL
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiAskFile(Class *cls,
                                Object *obj,
                                struct MUIP_InstallerGui_AskFile *msg)
{
    if(InstallerGuiPageSet(obj, P_ASKFILE, B_PROCEED_ABORT, 
                           msg->Message))
    {
        static Object *ask, *top; 

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

        if(ask && top)
        { 
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

            if(pop)
            {
                static char buf[PATH_MAX]; 

                set(top, MUIA_ShortHelp, msg->Help); 
                set(str, MUIA_String_Contents, msg->Default); 

                if(DoMethod(ask, MUIM_Group_InitChange))
                {
                    DoMethod(ask, OM_ADDMEMBER, pop); 
                    DoMethod(ask, MUIM_Group_ExitChange);

                    if(InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2) 
                       == MUIV_InstallerGui_Proceed)
                    {
                        char *f = NULL; 
                        get(str, MUIA_String_Contents, &f); 
                        snprintf(buf, sizeof(buf), "%s", f ? f : "NULL"); 
                    }

                    if(DoMethod(ask, MUIM_Group_InitChange))
                    {
                        DoMethod(ask, OM_REMMEMBER, pop); 
                        DoMethod(ask, MUIM_Group_ExitChange);
                        MUI_DisposeObject(pop);
                        return (IPTR) buf; 
                    }
                }

                MUI_DisposeObject(pop);
            }
        }
    }

    GERR(tr(S_UNER)); 
    return (IPTR) NULL; 
}

//----------------------------------------------------------------------------
// InstallerGuiCopyFilesStart - Show file copy requester
// Input:                       Message - Top text 
//                              NumberOfFiles - Num. of files / dirs to copy
// Return:                      TRUE to start copy, FALSE to cancel
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiCopyFilesStart(Class *cls,
                                       Object *obj,
                                       struct MUIP_InstallerGui_CopyFilesStart *msg)
{
    struct InstallerGuiData *my = INST_DATA(cls,obj);

    if(InstallerGuiPageSet(obj, P_COPYFILES, B_ABORT, 
                           msg->Message))
    {
        static Object *prg; 

        if(!prg)
        { 
            prg = (Object *) DoMethod
            (
                obj, MUIM_FindUData, 
                MUIV_InstallerGui_FileProgress
            );
        } 

        if(prg) 
        {
            DoMethod(_app(obj), MUIM_Application_AddInputHandler, &my->ticker);
            SetAttrs(prg, MUIA_Gauge_Max, msg->NumberOfFiles,
                     MUIA_Gauge_Current, 0, TAG_END);

            return (IPTR) TRUE; 
        }

        GERR(tr(S_UNER)); 
    }

    return FALSE; 
}

//----------------------------------------------------------------------------
// InstallerGuiCopyFilesSetCur - Show current file
// Input:                        File - filename
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

    // Something's really wrong if !prg. 
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
            ULONG cur, len = strlen(txt), 
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
                    cut[max] = '\0';
                    txt = cut; 
                }
            }

            // Update progress bar. Text and number. 
            if(!msg->NoGauge)
            {
                get(prg, MUIA_Gauge_Current, &cur); 
                SetAttrs(prg, MUIA_Gauge_InfoText, txt,
                         MUIA_Gauge_Current, ++cur, TAG_END);
            }
            else
            {
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
        // Go on. Next file.  
        return (IPTR) TRUE; 
    }
    else
    {
        GERR(tr(S_UNER)); 
        return (IPTR) FALSE; 
    }
}

//----------------------------------------------------------------------------
// InstallerGuiCopyFilesEnd - All files copied
// Input:                     -   
// Return:                    TRUE 
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiCopyFilesEnd(Class *cls,
                                     Object *obj) 
{
    struct InstallerGuiData *my = INST_DATA (cls,obj);

    DoMethod (_app (obj), MUIM_Application_RemInputHandler, &my->ticker);

    return (IPTR) TRUE; 
}

//----------------------------------------------------------------------------
// InstallerGuiCopyFilesAdd - Add files to (expert) file (de)selector
// Input:                     File - Name of file (or dir)
//                            ID - File / dir ID                               // REMOVE, NOT USED
// Return:                    TRUE on success, FALSE otherwise
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiCopyFilesAdd(Class *cls,
                                     Object *obj,
                                     struct MUIP_InstallerGui_CopyFilesAdd *msg)
{
    static Object *lst; 
    if(!lst)
    { 
        lst = (Object *) DoMethod
        (
            obj, MUIM_FindUData, 
            MUIV_InstallerGui_FileList
        );
    } 
    if(lst) 
    {
        DoMethod(lst, MUIM_List_Insert, &(msg->File), 1, MUIV_List_Insert_Bottom); 
        set(lst, MUIA_ShowMe, TRUE);
    }
    else
    {
        GERR(tr(S_UNER)); 
    }
    return (IPTR) FALSE; 
}


//----------------------------------------------------------------------------
// InstallerGuiExit - Say goodbye, we're done
// Input:             Message 
// Return:            TRUE
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiExit(Class *cls,
                             Object *obj,
                             struct MUIP_InstallerGui_Exit *msg)
{
    // Do nothing
    return TRUE;
}

//----------------------------------------------------------------------------
// InstallerGuiMessage - Show message
// Input:                Message 
// Return:               TRUE
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
            // Proceed and proceed only. 
            InstallerGuiWait(obj, MUIV_InstallerGui_ProceedOnly, 1); 
        }
    }
    else
    {
        // GUI's broken. 
        GERR(tr(S_UNER)); 
    }

    // Always. 
    return TRUE;
}

//----------------------------------------------------------------------------
// InstallerGuiConfirm - XXXXXXX
// Input:                Message
// Return:               TRUE
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiConfirm(Class *cls,
                                Object *obj,
                                struct MUIP_InstallerGui_Confirm *msg)
{
    if(InstallerGuiPageSet(obj, P_MESSAGE, B_PROCEED_ABORT, 
                           msg->Message))
    {
        if(InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2) ==
           MUIV_InstallerGui_Proceed)
        {
            return TRUE;
        }
    }
    else
    {
        GERR(tr(S_UNER)); 
    }

    return FALSE;
}

//----------------------------------------------------------------------------
// InstallerGuiRadio - XXXXXXX 
// Input:              Message 
//                     Help
//                     Names
//                     Default
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

    if(top && grp && cs &&
       InstallerGuiPageSet(obj, P_MESSAGE, B_PROCEED_ABORT, 
                           msg->Message))
    {
        // 32 bits + NULL. 
        static const char *c[33];
        unsigned int i = 0;
        Object *r;

        while(*cs && i < 32)
        {
            c[i++] = *cs;
            cs++;
        }

        i = msg->Default < i ? 
            msg->Default : 0; 

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

            if(DoMethod(grp, MUIM_Group_InitChange))
            {
                DoMethod(grp, OM_ADDMEMBER, r); 
                DoMethod(grp, MUIM_Group_ExitChange);

                if(InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2) ==
                   MUIV_InstallerGui_Proceed)
                {
                    ret = TRUE;
                }

                if(DoMethod(grp, MUIM_Group_InitChange))
                {
                    DoMethod(grp, OM_REMMEMBER, r); 
                    DoMethod(grp, MUIM_Group_ExitChange);
                    err = FALSE; 
                }
            }

            GetAttr(MUIA_Radio_Active, r, (IPTR *) &ret); 
            MUI_DisposeObject(r);
        }
    }

    if(err)
    {
        GERR(tr(S_UNER)); 
    }

    return ret;
}

//----------------------------------------------------------------------------
// InstallerGuiBool - XXXXXXX 
// Input:              Yes
//                     No
// Return:             0 = no, 1 = yes
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

    if(yes && no && top)
    {
        set(yes, MUIA_Text_Contents, msg->Yes);
        set(no, MUIA_Text_Contents, msg->No);
        set(top, MUIA_ShortHelp, msg->Help); 

        if(InstallerGuiPageSet(obj, P_MESSAGE, B_YES_NO, 
                               msg->Message))
        {
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

    GERR(tr(S_UNER)); 
    return -1;
}

//----------------------------------------------------------------------------
// InstallerGuiString - XXXXXXX 
// Input:               Message
//                      Default
// Return:              A bitmask representing the selected button(s)
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

        DoMethod(str, MUIM_Notify, MUIA_String_Acknowledge, 
                 MUIV_EveryTime, _app(obj), 2, 
                 MUIM_Application_ReturnID, MUIV_InstallerGui_Proceed); 
    } 

    if(str && top)
    {
        set(top, MUIA_ShortHelp, msg->Help); 
        set(str, MUIA_String_Contents, msg->Default);

        if(InstallerGuiPageSet(obj, P_STRING, B_PROCEED_ABORT, 
                               msg->Message))
        {
            if(InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2) ==
               MUIV_InstallerGui_Proceed)
            {
                get(str, MUIA_String_Contents, &ret); 
            }
            else
            {
                *((int *) msg->Halt) = 1; 
            }
        }
    }
    else
    {
        GERR(tr(S_UNER)); 
    }

    return (ULONG) (ret ? ret : ""); 
}

//----------------------------------------------------------------------------
// InstallerGuiNumber - XXXXXXX 
// Input:               Message
//                      Default
// Return:              A bitmask representing the selected button(s)
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

    if(num)
    {
        set(top, MUIA_ShortHelp, msg->Help); 
        set(num, MUIA_Numeric_Min, msg->Min);
        set(num, MUIA_Numeric_Max, msg->Max);
        set(num, MUIA_Numeric_Value, msg->Default);

        if(InstallerGuiPageSet(obj, P_NUMBER, B_PROCEED_ABORT, 
                               msg->Message))
        {
            if(InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2) ==
               MUIV_InstallerGui_Proceed)
            {
                ULONG res; 
                get(num, MUIA_Numeric_Value, &res); 
                return res;
            }
            else
            {
                *((int *) msg->Halt) = 1; 
                return 0; 
            }
        }
    }

    GERR(tr(S_UNER)); 
    return 0; 
}

//----------------------------------------------------------------------------
// InstallerGuiCheckBoxes - XXXXXXX 
// Input:              Names
//                     Default
// Return:             A bitmask representing the selected button(s)
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

    if(grp && top &&
       InstallerGuiPageSet(obj, P_MESSAGE, B_PROCEED_ABORT, 
                           msg->Message))
    {
        if(DoMethod(grp, MUIM_Group_InitChange))
        {
            IPTR ret; 
            ULONG id; 
            size_t i = 0; 
            static Object * cb[33]; 
            const char **cs = (const char **) msg->Names; 

            while(*cs && i < 32)
            {
                Object *c = (Object *) MUI_NewObject
                (
                    MUIC_Group,
                    MUIA_Group_Horiz, TRUE,
                    MUIA_InputMode, MUIV_InputMode_Toggle,
                    MUIA_Group_Child, (Object *) MUI_NewObject(
                        MUIC_Image,
                        MUIA_Frame, MUIV_Frame_ImageButton,
                        MUIA_Image_Spec, MUII_CheckMark,
                        MUIA_Background, MUII_ButtonBack,
                        MUIA_Image_FreeVert, TRUE,
                        MUIA_ShowSelState, FALSE,
                        MUIA_Selected, (msg->Default & (1 << i)) ? TRUE : FALSE,
                        MUIA_Weight, 0,
                        TAG_END),
                    MUIA_Group_Child, (Object *) MUI_NewObject(
                        MUIC_Text, 
                        MUIA_Text_Contents, *cs, 
                        TAG_END),
                    TAG_END
                );

                if(c)
                {
                    DoMethod(grp, OM_ADDMEMBER, c); 
                    cb[i++] = c; 
                    cs++; 
                } 
                else
                {
                    GERR(tr(S_UNER)); 

                    while(i--)
                    {
                        DoMethod(grp, OM_REMMEMBER, cb[i]); 
                        MUI_DisposeObject(cb[i]);
                    }

                    DoMethod(grp, MUIM_Group_ExitChange);
                    return 0; 
                }
            }

            // Mask out non-existing options from -1. 
            ret = msg->Default & ((1 << i) - 1); 

            DoMethod(grp, MUIM_Group_ExitChange);
            set(top, MUIA_ShortHelp, msg->Help); 

            id = InstallerGuiWait(obj, MUIV_InstallerGui_Proceed, 2);

            if(DoMethod(grp, MUIM_Group_InitChange))
            {
                while(i--)
                {
                    ULONG sel; 
                    get(cb[i], MUIA_Selected, &sel); 
                    ret |= (sel ? (1 << i) : 0);

                    DoMethod(grp, OM_REMMEMBER, cb[i]); 
                    MUI_DisposeObject(cb[i]);
                }

                DoMethod(grp, MUIM_Group_ExitChange);
                return id == MUIV_InstallerGui_Proceed ? ret : 0; 
            }
        }
    }

    GERR(tr(S_UNER)); 
    return 0;
}

//----------------------------------------------------------------------------
// InstallerGuiComplete - Show progress
// Input:                 Progress in %
// Return:                TRUE
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiComplete(Class *cls,
                                 Object *obj,
                                 struct MUIP_InstallerGui_Complete *msg)
{
    Object *prg = (Object *) DoMethod
    (
        obj, MUIM_FindUData, 
        MUIV_InstallerGui_Progress
    );
    if(prg)
    {
        int p = msg->Progress > 100 ? 100 : msg->Progress;
        set(prg, MUIA_Gauge_Current, p);
        set(prg, MUIA_ShowMe, TRUE);
        return TRUE; 
    }
    else
    {
        GERR(tr(S_UNER)); 
        return FALSE; 
    }
}

//----------------------------------------------------------------------------
// InstallerGuiRun - Get user confirmation before running shell command
// Input:            Message - The prompt 
// Return:           '2' = proceed, '1' = skip, '0' = abort
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiRun(Class *cls,
                            Object *obj,
                            struct MUIP_InstallerGui_Run *msg)
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

    if(con && but && txt && grp)
    {
        ULONG top, btm, str; 

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

    GERR(tr(S_UNER)); 
    return -1; 
}

//----------------------------------------------------------------------------
// InstallerGuiNew - Overloading OM_NEW
// Input:            See BOOPSI docs
// Return:           See BOOPSI docs
//----------------------------------------------------------------------------
MUIDSP IPTR InstallerGuiNew (Class *cls,
			                 Object *obj,
			                 struct opSet *msg)
{
    struct InstallerGuiData *my;
    static const char *lev[4], *pre[3], *log[3]; 

    lev[0] = tr(S_ULNV); // Novice
    lev[1] = tr(S_ULIN); // Intermediate
    lev[2] = tr(S_ULEX); // Expert
    pre[0] = tr(S_INRL); // For real
    pre[1] = tr(S_INDR); // Dry run
    log[0] = tr(S_NOLG); // No logging
    log[1] = tr(S_SILG); // Log to file

    obj = (Object *) DoSuperNew
    (
        cls, obj, 
        MUIA_Window_Title, tr(S_INST),
        MUIA_Window_AppWindow, TRUE,
        MUIA_Window_RootObject, MUI_NewObject(
            MUIC_Group,
            MUIA_UserData, MUIV_InstallerGui_TopGroup, 
            /* Top text */
            MUIA_Group_Child, (Object *) MUI_NewObject(
                MUIC_Text, 
                MUIA_UserData, MUIV_InstallerGui_Text, 
                MUIA_Text_Contents, "\n\n\n\n\n", 
                MUIA_Text_SetVMax, FALSE, 
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
                    MUIA_Group_Child, (Object *) MUI_NewObject(
                        MUIC_Rectangle, 
                        MUIA_Rectangle_HBar, TRUE, 
                        MUIA_Rectangle_BarTitle, tr(S_INMD),
                        TAG_END),
                    MUIA_Group_Child, MUI_NewObject(
                        MUIC_Group,
                        MUIA_Group_Horiz, TRUE,
                        MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                        MUIA_Group_Child, (Object *) MUI_NewObject(
                            MUIC_Radio, 
                            MUIA_UserData, MUIV_InstallerGui_UserLevel, 
                            MUIA_Radio_Entries, lev,
                            TAG_END),
                        MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
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
                        MUIA_Group_Child, (Object *) MUI_NewObject(
                            MUIC_Radio, 
                            MUIA_UserData, MUIV_InstallerGui_Pretend,
                            MUIA_Radio_Entries, pre, 
                            TAG_END),
                        MUIA_Group_Child, (Object *) MUI_MakeObject(MUIO_HSpace, 0),
                        MUIA_Group_Child, (Object *) MUI_NewObject(
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
    
    my = INST_DATA(cls, obj);
    my->ticker.ihn_Object = obj;
    my->ticker.ihn_Flags = MUIIHNF_TIMER;
    my->ticker.ihn_Method = MUIM_InstallerGui_Ticker;
    my->ticker.ihn_Millis = 50;

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
    if (!DoSuperMethodA (cls, obj, (Msg) msg) )
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
// Input:          See MUI docs
// Return:         See MUI docs
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

        case MUIM_InstallerGui_Confirm:
            return InstallerGuiConfirm(cls, obj, (struct MUIP_InstallerGui_Confirm *) msg);

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

        case MUIM_InstallerGui_Run:
            return InstallerGuiRun(cls, obj, (struct MUIP_InstallerGui_Run *) msg);
    }

    // Unknown method, promote to parent.
    return DoSuperMethodA (cls, obj, msg);
}
#endif /* AMIGA */

//----------------------------------------------------------------------------
// gui_mch_init - Initialise the Gui
//----------------------------------------------------------------------------
int gui_init(void)
{
    #ifdef AMIGA
    Object *App; 

    InstallerGuiClass = (struct MUI_CustomClass *) MUI_CreateCustomClass
    (
	    NULL, MUIC_Window, NULL,
        sizeof (struct CLASS_DATA(InstallerGui)),
        (APTR) DISPATCH_GATE (InstallerGui)
    );

    if (!InstallerGuiClass)
    {
        GERR(tr(S_FMCC)); 
        return FALSE;
    }

    App = (Object *) MUI_NewObject(
        MUIC_Application,
        MUIA_Application_Title, tr(S_INST),
        MUIA_Application_Window, Win = (Object *) NewObject(
            InstallerGuiClass->mcc_Class, NULL, 
            TAG_END),
        TAG_END
    ); 

    if(!App)
    {
        GERR(tr(S_MAPP));
        return FALSE;
    }

    if(!DoMethod(Win, MUIM_InstallerGui_Init))
    {
        GERR(tr(S_FINT));
        gui_exit(); 
        return FALSE;
    }

    // Open the window to finish setup. 
    set(Win, MUIA_Window_Open, TRUE);
    DoMethod(Win, MUIM_Show);

    return TRUE;
    #else
    return 1;
    #endif
}


//----------------------------------------------------------------------------
// gui_mch_exit
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
// gui_message
//----------------------------------------------------------------------------
void gui_message(const char *msg, int imm)
{
    #ifdef AMIGA
    DoMethod(Win, MUIM_InstallerGui_Message, msg, imm);
    #else
    if(imm)
    {
        printf("%d:%s", imm, msg); 
    }
    else
    {
        printf(msg); 
    }
    #endif
}

//----------------------------------------------------------------------------
// gui_confirm
//----------------------------------------------------------------------------
int gui_confirm(const char *msg)
{
    int ret = (int)
    #ifdef AMIGA
    DoMethod(Win, MUIM_InstallerGui_Confirm, msg);
    #else
    0;
    msg = NULL; 
    #endif
    return ret; 
}

//----------------------------------------------------------------------------
// gui_choice
//----------------------------------------------------------------------------
int gui_choice(const char *msg, 
               const char *hlp,
               const char **nms, 
               int def)
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
        def
    );
    #else
    (msg && hlp && nms) ? def : ~def;
    #endif

    return ret; 
}

//----------------------------------------------------------------------------
// gui_options
//----------------------------------------------------------------------------
int gui_options(const char *msg, 
                const char *hlp,
                const char **nms, 
                int def)
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
        def
    );
    #else
    (msg && hlp && nms) ? def : ~def;
    #endif
    return ret;
}

//----------------------------------------------------------------------------
// gui_bool
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
    0; 
    printf("%s%s%s%s\n", msg, hlp, yes, no);
    #endif
    return ret;
}

//----------------------------------------------------------------------------
// gui_string
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
    def;
    *hlt = 0; 
    printf("%s%s%s\n", msg, hlp, def);
    #endif
    return ret;
}

//----------------------------------------------------------------------------
// gui_number
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
    def;
    *hlt = 0; 
    printf("%s%s%d%d\n", msg, hlp, min, max);
    #endif
    return ret;
}

//----------------------------------------------------------------------------
// gui_welcome
//----------------------------------------------------------------------------
void gui_welcome(const char *msg, 
                 int *lvl, 
                 int *lgf, 
                 int *prt)
{
    int pat = (int)
    #ifdef AMIGA
    DoMethod(Win, MUIM_InstallerGui_Welcome, msg);
    #else
    1;
    printf("%s\n", msg);
    #endif
    *lvl = pat & 3; 
    *lgf = pat & 4 ? 1 : 0; 
    *prt = pat >> 3; 
}

//----------------------------------------------------------------------------
// gui_askdir
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
    def;
    printf("%s%s%d%d%d%s\n", msg, hlp, pth, dsk, asn, def);
    #endif
    return ret;
}

const char *gui_askfile(const char *msg, const char *hlp, int pth, int dsk, const char *def);

//----------------------------------------------------------------------------
// gui_askfile
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
    def;
    printf("%s%s%d%d\n", msg, hlp, pth, dsk);
    #endif
    return ret;
}

//----------------------------------------------------------------------------
// gui_copyfiles_start
//----------------------------------------------------------------------------
//
int gui_copyfiles_start(const char *msg, const char *hlp, pnode_p lst, int cnf)
{
    #ifdef AMIGA
    int n = 0; 
    pnode_p cur = lst; 
    while(cur)
    {
        if(cur->type == 1)
        {
            if(cnf)
            {
                DoMethod(Win, MUIM_InstallerGui_CopyFilesAdd, cur->name, cur);
            }
            n++; 
        }
        cur = cur->next; 
    }

    if(cnf)
    {
        static Object *sel, *top;
        
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

        if(sel && top && InstallerGuiPageSet
          (Win, P_FILEDEST, B_PROCEED_SKIP_ABORT, (ULONG) msg))
        {
            ULONG b; 
            LONG id = MUIV_List_NextSelected_Start; 

            set(top, MUIA_ShortHelp, hlp); 
            DoMethod(sel, MUIM_List_Select, MUIV_List_Select_All,
                          MUIV_List_Select_On, NULL); 

            b = InstallerGuiWait(Win, MUIV_InstallerGui_ProceedRun, 3); 

            if(b == MUIV_InstallerGui_ProceedRun)
            {
                for(;;) 
                {
                    DoMethod(sel, MUIM_List_NextSelected, &id); 
                    if(id != MUIV_List_NextSelected_End)
                    {
                        char *ent = NULL;
                        DoMethod(sel, MUIM_List_GetEntry, id, &ent); 

                        if(ent) 
                        {
                            for(cur = lst; cur; 
                                cur = cur->next)
                            {
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
                        break; 
                    }
                }

                for(cur = lst; cur; 
                    cur = cur->next)
                {
                    if(cur->type == 1)
                    {
                        n--;
                        cur->type = 0; 
                    }
                    else if(cur->type == -1)
                    {
                        cur->type = 1; 
                    }
                }
            }
            else
            {
                return b == MUIV_InstallerGui_SkipRun ?
                       0 : -1; 
            }
        }
        else
        {
            GERR(tr(S_UNER)); 
            return FALSE; 
        }
    }

    return (int) DoMethod(Win, MUIM_InstallerGui_CopyFilesStart, msg, n);
    #else
    return lst ? (cnf ? ((msg && hlp) ? 0 : -1) : 1) : -1;
    #endif
}

//----------------------------------------------------------------------------
// gui_copyfiles_setcur
//----------------------------------------------------------------------------
int gui_copyfiles_setcur(const char *cur, int nogauge) 
{
    return (int)
    #ifdef AMIGA
    DoMethod(Win, MUIM_InstallerGui_CopyFilesSetCur, cur, nogauge);
    #else
    (cur ? 1 + nogauge : 0);
    #endif
}

//----------------------------------------------------------------------------
// gui_copyfiles_end
//----------------------------------------------------------------------------
void gui_copyfiles_end(void) 
{
    #ifdef AMIGA
    DoMethod(Win, MUIM_InstallerGui_CopyFilesEnd); 
    #endif
}

//----------------------------------------------------------------------------
// gui_complete
//----------------------------------------------------------------------------
int gui_complete(int com)
{
    return (int)
    #ifdef AMIGA
    DoMethod(Win, MUIM_InstallerGui_Complete, com);
    #else
    com; 
    #endif
}

//----------------------------------------------------------------------------
// gui_run
//----------------------------------------------------------------------------
int gui_run(const char *msg, const char *hlp)
{
    #ifdef AMIGA
    return (int) DoMethod(Win, MUIM_InstallerGui_Run, msg, hlp);
    #else
    printf("%s%s\n", msg, hlp);
    // Always 'proceed'.
    return 2;
    #endif
}

//----------------------------------------------------------------------------
// gui_error
//----------------------------------------------------------------------------
int gui_error(int id, 
              const char *type, 
              const char *info)
{
    #ifdef AMIGA
    static ULONG flags; 
    static char err[BUFSIZ]; 
    static struct EasyStruct es = 
    {
        .es_StructSize = sizeof(struct EasyStruct), 
    };

    es.es_Title = (UBYTE *) tr(S_ERRS); 
    es.es_TextFormat = (UBYTE *) &err; 
    es.es_GadgetFormat = (UBYTE *) tr(S_OKEY); 
    snprintf(err, sizeof(err), tr(S_LERR), id, type, info);

    // We don't have any way of knowing
    // whether this really works out...
    EasyRequest(NULL, &es, &flags);

    return 1; 
    #else
    return (id && type && info) ? 0 : 1;
    #endif
}

