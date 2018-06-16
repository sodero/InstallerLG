//----------------------------------------------------------------------------
// information.h: 
//
// Functions for informing the user
//
//----------------------------------------------------------------------------

#include "alloc.h"
#include "args.h"
#include "error.h"
#include "eval.h"
#include "gui.h"
#include "information.h"
#include "resource.h"
#include "util.h"

#include <stdio.h>
#include <string.h>

#ifdef AMIGA
#include <clib/debug_protos.h>
#endif

//----------------------------------------------------------------------------
// (complete <num>)
//     display percentage through install in titlebar
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_complete(entry_p contxt)
{
    // We need atleast one argument
    if(c_sane(contxt, 1))
    {
        // Pass on the return value. 
        RNUM
        (
            gui_complete(num(CARG(1)))
        );
    }
    else
    {
        // The parser is broken
        error(PANIC); 
        RCUR; 
    }
}

//----------------------------------------------------------------------------
// (debug <anything> <anything> ...)
//    print to stdout when running from a shell
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_debug(entry_p contxt)
{
    // We need a proper context, no arguments
    // needed though. 
    //
    // REALLY? 
    //
    // FIXME
    //
    // More problems, you should be able to 
    // handle missing symbols, they should 
    // generate <NIL> strings. See doc. 
    //
    if(c_sane(contxt, 0))
    {
        // Are we being invoked from shell or
        // WB?
        int cli = arg_argc(-1);
        entry_p *cur = contxt->children; 

        // For all children, print the string
        // representation, to stdout if we're
        // running in a shell or to the debug 
        // log when invoked from Workbench.
        while(*cur && *cur != end())
        {
            if(cli)
            {
                // From shell.
                printf("%s ", str(*cur)); 
            }
            #ifdef AMIGA
            else
            {
                // From Workbench.
                KPrintF("%s ", str(*cur)); 
            }
            #endif
            cur++; 
        }

        // Append final newline. 
        if(cli)
        {
            // From shell.
            printf("\n"); 
        }
        #ifdef AMIGA
        else
        {
            // From Workbench.
            KPrintF("\n"); 
        }
        #endif
        RNUM(1); 
    }
    else
    {
        // The parser is broken
        error(PANIC); 
        RCUR;
    }
}

//----------------------------------------------------------------------------
// (message <string1> <string2>... (all))
//     display message with Proceed and Abort buttons if user 
//     level > 0 (novice)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_message(entry_p contxt)
{
    // We need atleast one argument.
    if(c_sane(contxt, 1))
    {
        // Get information needed to determine 
        // wheter to show anything or not.
        entry_p all = get_opt(contxt, OPT_ALL);
        int level = get_numvar(contxt, "@user-level");

        // Non novice or override using (all)?
        if(level > 0 || all)
        {
            // Concatenate all children.
            char *msg = get_chlstr(contxt);

            // Did we manage to concatenate something?
            if(msg)
            {
                // If we could resolve all our children,
                // show the result of the concatenation.
                if(!did_error())
                {
                    gui_message(msg, 0);  
                }

                // Free the temporary buffer.
                free(msg);
            }
            else
            {
                // Out of memory.
                error(PANIC);
                RCUR;
            }
        }

        // Done. 
        RNUM(1); 
    }
    else
    {
        // The parser is broken.
        error(PANIC); 
        RCUR; 
    }
}

//----------------------------------------------------------------------------
// (user <user-level>)
//   change the user level (debugging purposes only)
//
// ***********************
// Implemented using m_set
// *********************** 
//
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// (welcome <string> <string> ...)
//     allow Installation to commence [sic!].
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_welcome(entry_p contxt)
{
    if(c_sane(contxt, 1))
    {
        // Installer settings.
        int lvl = 0, 
            lgf = 0, 
            prt = 0; 

        // Concatenate all children.
        char *msg = get_chlstr(contxt);

        // Did we manaage to concatenate something?
        if(msg)
        {
            // If we could resolve all our children,
            // show the result of the concatenation.
            if(!did_error())
            {
                gui_welcome(msg, &lvl, &lgf, &prt); 
            }

            // Free the temporary buffer.
            free(msg);

            // User level 0 = abort
            if(lvl > 0)
            {
                set_numvar(contxt, "@user-level", lvl - 1); 
                set_numvar(contxt, "@pretend", prt); 
                set_numvar(contxt, "@log", lgf); 
                RNUM(1);
            }
            else
            {
                error(HALT); 
                RNUM(0); 
            }
        }
    }
        
    // OOM / broken parser.
    error(PANIC);
    RCUR; 
}

//----------------------------------------------------------------------------
// (working)
//     indicate to user that Installer is busy doing things
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//----------------------------------------------------------------------------
entry_p m_working(entry_p contxt)
{
    if(c_sane(contxt, 1)) 
    {
        // Concatenate all children.
        char *msg = get_chlstr(contxt); 

        // Did we manage to concatenate something?
        if(msg)
        {
            // Only proceed if we could resolve all
            // our children.
            if(!did_error())
            {
                // Standard prefix.
                const char *pre = tr(S_WRKN); 
                size_t len = strlen(pre) + 
                             strlen(msg) + 1;

                // Memory to hold prefix and children.
                char *con = calloc(len, 1);

                if(con)
                {
                    // Concatenate prefix and children.
                    snprintf(con, len, "%s%s", pre, msg); 

                    // Free the children buffer.
                    free(msg);

                    // Show the result. Return immediately.
                    // No waiting for any events.
                    gui_message(con, 1);  

                    // Free the final message buffer.
                    free(con);

                    // Success.
                    RNUM(1); 
                }
                else
                {
                    // Free the children buffer.
                    free(msg);
                }
            }
            else
            {
                // Could not resolve children.
                free(msg);
                RNUM(0); 
            }
        }
    }
        
    // Broken parser /
    // out of memory.
    error(PANIC);
    RCUR; 
}
