//------------------------------------------------------------------------------
// init.c:
//
// Initilization by means of prepending and appending code.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "args.h"
#include "control.h"
#include "exit.h"
#include "gui.h"
#include "information.h"
#include "init.h"
#include "media.h"
#include "procedure.h"
#include "symbol.h"
#include "util.h"
#include "version.h"
#include <string.h>

#ifdef AMIGA
#include <proto/locale.h>
#ifdef __MORPHOS__
char *strcasestr(const char *, const char *);
#endif

#if defined(__amigaos4__)
static const char* __attribute__((used)) stackcookie = "$STACK: 131072";
#elif defined(__AROS__) || defined(__MORPHOS__)
unsigned long __stack = 131072;
#endif
#endif

//------------------------------------------------------------------------------
// Name:        init_num
// Description: Init helper; insert numeric variable in CONTXT. This is only
//              for use in init(), nothing is resolved and duplicates aren't
//              accounted for.
// Input:       entry_p contxt: CONTXT.
//              char *sym:      Name.
//              int32_t num:    Value.
// Return:      -
//------------------------------------------------------------------------------
static void init_num(entry_p contxt, char *sym, int32_t num)
{
    // Create SYMBOL -> VALUE tuple.
    entry_p var = new_symbol(DBG_ALLOC(strdup(sym))), val = new_number(num);

    if(!var || !val)
    {
        kill(var);
        kill(val);
        return;
    }

    // Initialize tuple.
    var->parent = contxt;
    var->resolved = val;
    val->parent = var;

    // Insert result in CONTXT.
    (void) append(&contxt->symbols, var);
}

//------------------------------------------------------------------------------
// Name:        init_str
// Description: Init helper; insert string variable in CONTXT. This is only
//              for use in init(), nothing is resolved and duplicates aren't
//              accounted for.
// Input:       entry_p contxt: CONTXT.
//              char *sym:      Name.
//              char *str:      Value.
// Return:      -
//------------------------------------------------------------------------------
static void init_str(entry_p contxt, char *sym, char *str)
{
    // Create SYMBOL -> VALUE tuple.
    entry_p var = new_symbol(DBG_ALLOC(strdup(sym))),
            val = new_string(DBG_ALLOC(strdup(str)));

    if(!var || !val)
    {
        kill(var);
        kill(val);
        return;
    }

    // Initialize tuple.
    var->parent = contxt;
    var->resolved = val;
    val->parent = var;

    // Insert result in CONTXT.
    (void) append(&contxt->symbols, var);
}

//------------------------------------------------------------------------------
// Name:        init_tooltypes
// Description: Init helper; Promote tooltypes to variables in CONTXT.
// Input:       entry_p contxt: CONTXT.
// Return:      -
//------------------------------------------------------------------------------
static void init_tooltypes(entry_p contxt)
{
    // Get tooltypes / CLI arguments.
    char *a_app = arg_get(ARG_APPNAME), *a_scr = arg_get(ARG_SCRIPT),
         *a_ico = arg_get(ARG_ICON), *a_log = arg_get(ARG_LOGFILE),
         *a_lng = arg_get(ARG_LANGUAGE);

    // User levels: minimum 'NOVICE' and default 'AVERAGE'.
    int32_t l_def = str_to_userlevel(arg_get(ARG_DEFUSER), LG_AVERAGE),
            l_min = str_to_userlevel(arg_get(ARG_MINUSER), LG_NOVICE);

    // Cap userlevel values, default must be >= minimum.
    init_num(contxt, "@user-level", l_def < l_min ? l_min : l_def);
    init_num(contxt, "@user-min", l_min);

    // Modus.
    init_num(contxt, "@no-log", arg_get(ARG_NOLOG) ? LG_TRUE : LG_FALSE);
    init_num(contxt, "@no-pretend", arg_get(ARG_NOPRETEND) ?
             LG_TRUE : LG_FALSE);

    // File names.
    init_str(contxt, "@icon", a_ico ? a_ico : (a_scr ? a_scr : ""));
    init_str(contxt, "@app-name", a_app ? a_app : "Test App");
    init_str(contxt, "@log-file", a_log ? a_log : "install_log_file");

    if(a_lng)
    {
        init_str(contxt, "@language", arg_get(ARG_LANGUAGE));
    }
    else
    {
        // Don't use locale if in test mode, doing so would break tests.
        #if defined(AMIGA) && !defined(LG_TEST)
        // Open the current default locale.
        struct Locale *loc = OpenLocale(NULL);

        // Set the preferred installer language.
        if(loc && loc->loc_PrefLanguages[0])
        {
            init_str(contxt, "@language", loc->loc_PrefLanguages[0]);
            CloseLocale(loc);
        }
        #else
        init_str(contxt, "@language", "english");
        #endif
    }
}

//------------------------------------------------------------------------------
// Name:        init_misc_num
// Description: Init helper; Set misc default numerical symbols.
// Input:       entry_p contxt: CONTXT.
// Return:      -
//------------------------------------------------------------------------------
static void init_misc_num(entry_p contxt)
{
    // Set numerical values.
    init_num(contxt, "@pretend", LG_FALSE);
    init_num(contxt, "@installer-version", (int32_t) (MAJOR << 16) | MINOR);
    init_num(contxt, "@ioerr", LG_FALSE);
    init_num(contxt, "@log", LG_FALSE);
    init_num(contxt, "@yes", LG_FALSE);
    init_num(contxt, "@skip", LG_FALSE);
    init_num(contxt, "@abort", LG_FALSE);
    init_num(contxt, "@back", LG_FALSE);
    init_num(contxt, "@each-type", LG_FALSE);
    init_num(contxt, "@debug", LG_FALSE);
    init_num(contxt, "@trap", LG_FALSE);
    init_num(contxt, "@fail", LG_FALSE);
    init_num(contxt, "@delfail", LG_FALSE);
    init_num(contxt, "@force", LG_FALSE);
    init_num(contxt, "@delforce", LG_FALSE);
    init_num(contxt, "@nofail", LG_FALSE);
    init_num(contxt, "@delnofail", LG_FALSE);
    init_num(contxt, "@askuser", LG_FALSE);
    init_num(contxt, "@delaskuser", LG_FALSE);
    init_num(contxt, "@oknodelete", LG_FALSE);
    init_num(contxt, "@deloknodelete", LG_FALSE);
    init_num(contxt, "true", LG_TRUE);
    init_num(contxt, "false", LG_FALSE);
    init_num(contxt, "@alfa", 0);
    init_num(contxt, "@beta", 1);
    init_num(contxt, "@gamma", 2);
    init_num(contxt, "@strict",
    // Sloppy mode is default on Amiga unless we're in test mode. On other
    // systems strict is the default.
    #if defined(AMIGA) && !defined(LG_TEST)
    LG_FALSE
    #else
    LG_TRUE
    #endif
    );
}

//------------------------------------------------------------------------------
// Name:        init_misc_string
// Description: Init helper; Set misc default string symbols.
// Input:       entry_p contxt: CONTXT.
// Return:      -
//------------------------------------------------------------------------------
static void init_misc_string(entry_p contxt)
{
    // Set string values.
    init_str(contxt, "@abort-button", "");
    init_str(contxt, "@askoptions-help", "");
    init_str(contxt, "@askchoice-help", "");
    init_str(contxt, "@asknumber-help", "");
    init_str(contxt, "@askstring-help", "");
    init_str(contxt, "@askdisk-help", "");
    init_str(contxt, "@askfile-help", "");
    init_str(contxt, "@askdir-help", "");
    init_str(contxt, "@copylib-help", "");
    init_str(contxt, "@copyfiles-help", "");
    init_str(contxt, "@makedir-help", "");
    init_str(contxt, "@startup-help", "");
    init_str(contxt, "@default-dest", "T:");
    init_str(contxt, "@error-msg", "");
    init_str(contxt, "@execute-dir", "");
    init_str(contxt, "@special-msg", "");
    init_str(contxt, "@each-name", "");
    init_str(contxt, "@user-startup", "s:user-startup");
    init_str(contxt, "fail", "fail");
    init_str(contxt, "nofail", "nofail");
    init_str(contxt, "oknodelete", "oknodelete");
    init_str(contxt, "force", "force");
    init_str(contxt, "askuser", "askuser");
    init_str(contxt, "<fail>", "fail");
    init_str(contxt, "<nofail>", "nofail");
    init_str(contxt, "<oknodelete>", "oknodelete");
    init_str(contxt, "<force>", "force");
    init_str(contxt, "<askuser>", "askuser");
    init_str(contxt, "@null", "");
}

//------------------------------------------------------------------------------
// Name:        init_misc
// Description: Init helper; Set misc default symbols.
// Input:       entry_p contxt: CONTXT.
// Return:      -
//------------------------------------------------------------------------------
static void init_misc(entry_p contxt)
{
    // Set numerical values.
    init_misc_num(contxt);

    // Set string values.
    init_misc_string(contxt);
}

//------------------------------------------------------------------------------
// Name:        init_error
// Description: Init helper; Create default error handler.
// Input:       entry_p contxt: CONTXT.
// Return:      -
//------------------------------------------------------------------------------
static void init_error(entry_p contxt)
{
    // Default error handler: (procedure @onerror (select 0 0) )
    entry_p entry = new_native
    (
        DBG_ALLOC(strdup("onerror")), __LINE__, n_procedure,
        push
        (
            new_contxt(),
            new_custom
            (
                DBG_ALLOC(strdup("@onerror")), __LINE__, NULL,
                push
                (
                    new_contxt(),
                    new_native
                    (
                        DBG_ALLOC(strdup("select")), __LINE__, n_select,
                        push(push
                        (
                            new_contxt(),
                            new_number(0)
                        ),
                            push
                            (
                                new_contxt(),
                                new_number(0)
                            )
                        ),
                        DANGLE
                    )
                )
            )
        ),
        DANGLE
    );

    if(entry)
    {
        // Add to the root and reparent.
        (void) append(&contxt->children, entry);
        entry->parent = contxt;

        // Rotate to put it on top.
        ror(contxt->children);
    }
}

//------------------------------------------------------------------------------
// Name:        init_exit
// Description: Init helper; Create default exit handler.
// Input:       entry_p contxt: CONTXT.
// Return:      -
//------------------------------------------------------------------------------
static void init_exit(entry_p contxt)
{
    // Line numbers and naming are for debugging purposes only.
    entry_p entry = new_native(DBG_ALLOC(strdup("exit")), __LINE__, n_exit,
                               NULL, NUMBER);

    // Tests don't expect any default (exit).
    #if defined(AMIGA) && !defined(LG_TEST)
    // Add to the root and reparent.
    if(entry)
    {
        (void) append(&contxt->children, entry);
        entry->parent = contxt;
    }

    // No rotation. Default (exit) should be last.
    #else
    // Not used.
    (void) contxt;
    // We're not using this, kill it directly.
    kill(entry);
    #endif
}

//------------------------------------------------------------------------------
// Name:        init_welcome
// Description: Init helper; Create default welcome screen.
// Input:       entry_p contxt: CONTXT.
// Return:      -
//------------------------------------------------------------------------------
static void init_welcome(entry_p contxt)
{
    // Is there a (welcome) already?
    entry_p entry = native_exists(contxt, n_welcome);

    // If not, insert a default (welcome).
    if(!entry)
    {
        // The line numbers and naming are for debugging purposes only.
        entry = new_native
        (
            DBG_ALLOC(strdup("welcome")), __LINE__, n_welcome, NULL, NUMBER
        );

        // Tests don't expect a default (welcome).
        #if defined(AMIGA) && !defined(LG_TEST)
        // Add to the root and reparent.
        if(entry)
        {
            (void) append(&contxt->children, entry);
            entry->parent = contxt;
        }

        // Rotate right to make it end up on top.
        ror(contxt->children);
        #else
        // We're not using this, kill it directly.
        kill(entry);
        #endif
    }
}

//------------------------------------------------------------------------------
// Name:        init
// Description: Prepend / append startup and shutdown code.
// Input:       entry_p contxt:  The start symbol, refer to the parser.
// Return:      entry_p:         Start + startup / shutdown additions.
//------------------------------------------------------------------------------
entry_p init(entry_p contxt)
{
    // We should have atleast one child. If we don't, we're out of memory.
    if(!c_sane(contxt, 1) || !s_sane(contxt, 0))
    {
        return contxt;
    }
#ifndef LG_DEBUG
    // Get tooltype / cli arguments.
    init_tooltypes(contxt);

    // Create default (welcome).
    init_welcome(contxt);

    // Create default (onerror).
    init_error(contxt);

    // Create default (exit).
    init_exit(contxt);

    // Set default symbols.
    init_misc(contxt);
#endif
    return contxt;
}
