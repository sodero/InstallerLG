//------------------------------------------------------------------------------
// optional.c:
//
// Fake option handling
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "optional.h"
#include "util.h"
#include <string.h>

//------------------------------------------------------------------------------
// FIXME
//------------------------------------------------------------------------------
typedef enum { FAIL, FORCE, NOFAIL, ASKUSER, OKNODELETE, DELFAIL, DELFORCE,
               DELNOFAIL, DELASKUSER, DELOKNODELETE, INVALID, NOPTS } stropt_t;

//------------------------------------------------------------------------------
// FIXME
//------------------------------------------------------------------------------
static char *h_optional_t2v(stropt_t type)
{
    char *var[NOPTS] = { "@fail", "@force", "@nofail", "@askuser",
                         "@oknodelete", "@delfail", "@delforce", "@delnofail",
                         "@delaskuser", "@deloknodelete", "@invalid" };

    return var[type < INVALID ? type : INVALID];
}

//------------------------------------------------------------------------------
// FIXME
//------------------------------------------------------------------------------
static void h_optional_reset(entry_p contxt)
{
    for(stropt_t type = DELFAIL; type < INVALID; type++)
    {
        int32_t cur = get_num(contxt, h_optional_t2v(type - 5)),
                new = get_num(contxt, h_optional_t2v(type)) ? LG_TRUE : cur;

        set_num(contxt, h_optional_t2v(type - 5), new);
    }
}

//------------------------------------------------------------------------------
// FIXME
//------------------------------------------------------------------------------
entry_p h_optional_get(entry_p contxt, opt_t type)
{
    int32_t val;

    switch(type)
    {
        case OPT_FAIL:
            val = get_num(contxt, h_optional_t2v(FAIL));
            break;

        case OPT_FORCE:
            val = get_num(contxt, h_optional_t2v(FORCE));
            break;

        case OPT_NOFAIL:
            val = get_num(contxt, h_optional_t2v(NOFAIL));
            break;

        case OPT_ASKUSER:
            val = get_num(contxt, h_optional_t2v(ASKUSER));
            break;

        case OPT_OKNODELETE:
            val = get_num(contxt, h_optional_t2v(OKNODELETE));
            break;

        default:
            val = LG_FALSE;
    }

    return val == LG_TRUE ? end() : NULL;
}

//------------------------------------------------------------------------------
// FIXME
//------------------------------------------------------------------------------
static void h_optional_modify(entry_p contxt, bool delete)
{
    // Set variable prefix length and option range depending on the operation.
    stropt_t start = delete ? DELFAIL : FAIL, stop = delete ? INVALID : DELFAIL;
    size_t off = delete ? 4 : 1;

    for(size_t cur = 1; exists(C_ARG(cur)); cur++)
    {
        // Resolve current argument.
        char *arg = str(C_ARG(cur));

        // Iterate over all option set / delete types.
        for(stropt_t type = start; type < stop; type++)
        {
            // Get name of option variable.
            char *var = h_optional_t2v(type);

            // Compare argument with suffix.
            if(!strcasecmp(arg, var + off))
            {
                set_num(contxt, var, LG_TRUE);
            }
        }
    }
}

//------------------------------------------------------------------------------
// (optional <option name> [<option name> ...])
//      FIXME
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_optional(entry_p contxt)
{
    // Atleast one option needed.
    C_SANE(1, NULL);

    // Reset options taking delopts into account.
    h_optional_reset(contxt);

    // Set new options.
    h_optional_modify(contxt, false);

    // Always dangle.
    return end();
}

//------------------------------------------------------------------------------
// (delopts <option name> [<option name> ...])
//      FIXME
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_delopts(entry_p contxt)
{
    // Atleast one option needed.
    C_SANE(1, NULL);

    // Set new options to delete.
    h_optional_modify(contxt, true);

    // Reset options taking delopts into account.
    h_optional_reset(contxt);

    // Always dangle.
    return end();
}
