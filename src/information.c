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
    // We need atleast one argument
    if(c_sane(contxt, 1))
    {
        // Get information needed to determine 
        // wheter to show anything or not.
        entry_p all = get_opt(contxt, OPT_ALL);
        int level = get_numvar(contxt, "@user-level");

        // Non novice or override using (all)?
        if(level > 0 || all)
        {
            size_t mln = 0; 
            entry_p *cur = contxt->children; 

            // Sum up the size of all children
            while(*cur && *cur != end())
            {
                mln += strlen(str(*cur)); 
                cur++; 
            }

            // Do we have anything to show? 
            if(mln)
            {
                char *con = CALLOC(mln + 1, 1);

                if(con)
                {
                    // Concatenate the string representation
                    // of all children.
                    cur = contxt->children; 

                    while(*cur && *cur != end())
                    {
                        strcat(con, str(*cur)); 
                        cur++; 
                    }

                    // Show the result of the concatenation
                    // and free the temporary buffer.
                    gui_message(con, 0);  
                    free(con); 
                }
                else
                {
                    // Out of memory
                    error(PANIC);
                    RCUR;
                }
            }
        }

        // Done. 
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
    if(c_sane(contxt, 1)) /* FIXME? Wrong, merge all children */
    {
        size_t mln = 0; 
        entry_p *cur = contxt->children; 
        int lvl = 0, 
            lgf = 0, 
            prt = 0; 

        // Sum up the size of all children
        while(*cur && *cur != end())
        {
            mln += strlen(str(*cur)); 
            cur++; 
        }

        // Do we have anything to show? 
        if(mln)
        {
            char *con = CALLOC(mln + 1, 1);

            if(con)
            {
                // Concatenate the string representation
                // of all children.
                cur = contxt->children; 

                while(*cur && *cur != end())
                {
                    strcat(con, str(*cur)); 
                    cur++; 
                }

                // Show the result of the concatenation
                // and free the temporary buffer.
                gui_welcome(con, &lvl, &lgf, &prt); 
                free(con); 
            }
            else
            {
                // Out of memory
                error(PANIC);
                RCUR;
            }
        }
        else
        {
            gui_welcome("", &lvl, &lgf, &prt); 
        }

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
    else
    {
        // The parser is broken
        error(PANIC);
        RCUR; 
    }
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
        size_t mln = 0; 
        entry_p *cur = contxt->children; 
        const char *pre = tr(S_WRKN); 
        char *con; 

        // Sum up the size of all children
        while(*cur && *cur != end())
        {
            mln += strlen(str(*cur)); 
            cur++; 
        }

        // Allocate enough to hold the standard
        // header and all children + term zero. 
        con = CALLOC(strlen(pre) + mln + 1, 1);

        if(con)
        {
            // Standard part.
            strcat(con, pre); 

            // Concatenate the string representation
            // of all children.
            cur = contxt->children; 

            while(*cur && *cur != end())
            {
                strcat(con, str(*cur)); 
                cur++; 
            }

            // Show the result of the concatenation
            // and free the temporary buffer. We will
            // return immediately. No waiting for any
            // events will take place. 
            gui_message(con, 1);  
            free(con); 
        }
        else
        {
            // Out of memory
            error(PANIC);
            RCUR;
        }

        RNUM(1); 
    }
    else
    {
        // The parser is broken
        error(PANIC);
        RCUR; 
    }
}
