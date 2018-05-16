//----------------------------------------------------------------------------
// init.c: 
//
// Initilization by means of prepending and appending code.
//----------------------------------------------------------------------------

#include "alloc.h"
#include "args.h"
#include "control.h"
#include "exit.h"
#include "information.h"
#include "init.h"
#include "procedure.h"
#include "symbol.h"
#include "util.h"

#include <string.h>

static char version[] __attribute__((used)) = "\0$VER: InstallerLG 43.3 [ALPHA1]";

//----------------------------------------------------------------------------
// Name:        init(entry_p contxt)
// Description: Prepend / append startup and shutdown code.
// Input:       entry_p contxt:  The start symbol, refer to the parser. 
// Return:      entry_p:         Start + startup / shutdown additions.
//----------------------------------------------------------------------------
entry_p init(entry_p contxt)
{
    // If we don't have a context with 
    // children the parser is broken.
    if(contxt &&
       contxt->children)
    {
        // Iterator. 
        entry_p e = NULL; 

        // Only on Amiga, otherwise tests will break, they don't
        // expect any default (welcome) or (exit):s.
        #ifdef AMIGA 
        // Search for a 'welcome' in the root, if there is one
        // (or two) in one of the children then so be it, then 
        // they are probably there for a reason. 
        entry_p *c = contxt->children; 

        while(*c && *c != end())
        {
            // Match function pointer rather than function name
            // since the latter can lie to us (and is slower). 
            if((*c)->type == NATIVE &&
               (*c)->call == m_welcome)
            {
                e = *c; 
                break; 
            }

            c++; 
        }

        // If no (welcome) is found insert a default one on top
        if(!e)
        {
            // The line numbers and naming are for debugging 
            // purposes only. 
            e = new_native
            (
                STRDUP("welcome"), __LINE__, m_welcome, 
                push
                (
                    new_contxt(), 
                    new_string(STRDUP("Welcome"))
                ),
                NUMBER
            );

            // Add to the root and reparent. 
            if(e)
            {
                append(&contxt->children, e); 
                e->parent = contxt; 
            }

            // Rotate right to make it end up on top. 
            ror(contxt->children);
        }
        #endif
        // Create default error handler, it simply returns '0'
        // without doing anything.
        e = new_native
        (
            STRDUP("onerror"), __LINE__, m_procedure, 
            push
            (
                new_contxt(), 
                new_custom
                (
                    STRDUP("@onerror"), __LINE__, NULL, 
                    push
                    (
                        new_contxt(),
                        new_native
                        (
                            STRDUP("select"), __LINE__, m_select,
                            push(push
                            (
                                new_contxt(),
                                new_number(1)
                            ),
                                push
                                (
                                    new_contxt(), 
                                    new_number(0)
                                )
                            ), 
                            NUMBER
                        ) 
                    )
                )
            ),
            DANGLE
        );

        // Add to the root and reparent. 
        if(e)
        {
            append(&contxt->children, e); 
            e->parent = contxt; 
        }

        // Rotate right to make it end up on top. 
        ror(contxt->children);
        
        // Set default variables using (set) instead
        // of creating them directly. Hides all the
        // magic involved in symbol handling.
        e = new_native
        (
            // All the numerical values.
            STRDUP("set"), __LINE__, m_set, 
            push(push(push(push(push(push(
            push(push(push(push(push(push(
            push(push(push(push
            (
                new_contxt(), 
                new_symbol(STRDUP("@user-level"))),
                new_number(2)
            ),
                new_symbol(STRDUP("@pretend"))),
                new_number(0)
            ),
                new_symbol(STRDUP("@ioerr"))),
                new_number(0)
            ),
                new_symbol(STRDUP("@log"))),
                new_number(0)
            ),
                new_symbol(STRDUP("@yes"))),
                new_number(0)
            ),
                new_symbol(STRDUP("@skip"))),
                new_number(0)
            ),
                new_symbol(STRDUP("@abort"))),
                new_number(0)
            ),
                new_symbol(STRDUP("@each-type"))),
                new_number(0)
            ),
            NUMBER
        );

        // Add to the root and reparent. 
        if(e)
        {
            append(&contxt->children, e); 
            e->parent = contxt; 
        }

        // Rotate right to make it end up on top. 
        // We need these to be set before any user
        // code is executed.
        ror(contxt->children);

        e = new_native
        (
            // All the string values.
            STRDUP("set"), __LINE__, m_set,
            push(push(push(push(push(push(push(push(
            push(push(push(push(push(push(push(push(
            push(push(push(push(push(push(push(push(
            push(push(push(push(push(push(push(push(
            push(push(push(push(push(push(push(push(
            push(push(push(push(push(push
            (
                new_contxt(), 
                new_symbol(STRDUP("@abort-button"))),
                new_string(STRDUP("Abort"))
            ),
                new_symbol(STRDUP("@app-name"))),
                new_string(STRDUP(arg_get(ARG_APPNAME)))
            ),
                new_symbol(STRDUP("@askoptions-help"))),
                new_string(STRDUP("Help (askoptions)"))
            ),
                new_symbol(STRDUP("@askchoice-help"))),
                new_string(STRDUP("Help (askchoice)"))
            ),
                new_symbol(STRDUP("@asknumber-help"))),
                new_string(STRDUP("Help (asknumber)"))
            ),
                new_symbol(STRDUP("@askstring-help"))),
                new_string(STRDUP("Help (askstring)"))
            ),
                new_symbol(STRDUP("@askdisk-help"))),
                new_string(STRDUP("Help (askdisk)"))
            ),
                new_symbol(STRDUP("@askfile-help"))),
                new_string(STRDUP("Help (askfile)"))
            ),
                new_symbol(STRDUP("@askdir-help"))),
                new_string(STRDUP("Help (askdir)"))
            ),
                new_symbol(STRDUP("@copylib-help"))),
                new_string(STRDUP("Help (copylib)"))
            ),
                new_symbol(STRDUP("@copyfiles-help"))),
                new_string(STRDUP("Help (copyfiles)"))
            ),
                new_symbol(STRDUP("@makedir-help"))),
                new_string(STRDUP("Help (makedir)"))
            ),
                new_symbol(STRDUP("@startup-help"))),
                new_string(STRDUP("Help (startup)"))
            ),
                new_symbol(STRDUP("@default-dest"))),
                new_string(STRDUP("Work:"))
            ),
                new_symbol(STRDUP("@error-msg"))),
                new_string(STRDUP("Help (error-msg)"))
            ),
                new_symbol(STRDUP("@execute-dir"))),
                new_string(STRDUP("Help (execute-dir)"))
            ),
                new_symbol(STRDUP("@icon"))),
                new_string(STRDUP("Help (icon)"))
            ),
                new_symbol(STRDUP("@installer-version"))),
                new_string(STRDUP("Help (installer-version)"))
            ),
                new_symbol(STRDUP("@language"))),
                new_string(STRDUP("english"))
            ),
                new_symbol(STRDUP("@special-msg"))),
                new_string(STRDUP("Help (special-msg)"))
            ),
                new_symbol(STRDUP("@log-file"))),
                new_string(STRDUP("install_log_file"))
            ),
                new_symbol(STRDUP("@each-name"))),
                new_string(STRDUP(""))
            ),
                new_symbol(STRDUP("@user-startup"))),
                new_string(STRDUP("s:user-startup"))
            ),
            STRING
        );

        // Add to the root and reparent. 
        if(e)
        {
            append(&contxt->children, e); 
            e->parent = contxt; 
        }

        // Rotate right to make it end up on top. 
        // We need these to be set before any user
        // code is executed.
        ror(contxt->children);
       
        // Only on Amiga, otherwise tests will break, they don't
        // expect any default (welcome) or (exist):s.
        #ifdef AMIGA 
        e = NULL; 
        c = contxt->children; 

        // Search for an (exit) in the root.
        while(*c && *c != end())
        {
            // Match function pointer rather than function name
            // since the latter can lie to us (and is slower). 
            if((*c)->type == NATIVE &&
               (*c)->call == m_exit)
            {
                e = *c; 
                break; 
            }

            c++; 
        }

        // If no (exit) is found insert a default one at the bottom. 
        if(!e)
        {
            // The line numbers and naming are for debugging 
            // purposes only. 
            e = new_native
            (
                STRDUP("exit"), __LINE__, 
                m_exit, NULL, NUMBER
            );

            // Add to the root and reparent. 
            if(e)
            {
                append(&contxt->children, e); 
                e->parent = contxt; 
            }

            // No rotation. 
        }
        #endif
    }

    return contxt; 
}

