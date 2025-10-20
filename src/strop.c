//------------------------------------------------------------------------------
// strop.c:
//
// String operations
//------------------------------------------------------------------------------
// Copyright (C) 2018-2023, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "strop.h"
#include "util.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef AMIGA
#include <dos/dos.h>
#include <proto/dos.h>
#endif

//------------------------------------------------------------------------------
// (cat <string1> <string2>...)
//     returns concatenation of strings
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_cat(entry_p contxt)
{
    // We need at least one string.
    C_SANE(1, NULL);

    // Start with a string length of LG_STRLEN.
    char *buf = DBG_ALLOC(calloc(LG_STRLEN + 1, 1));

    // Exit on OOM.
    LG_ASSERT(buf, end());

    // Iterate over all arguments.
    for(size_t cur = 0, len = 0, cnt = LG_STRLEN; exists(contxt->children[cur]);
        cur++)
    {
        // Resolve the current argument.
        const char *arg = str(contxt->children[cur]);

        // Return an empty string if argument couldn't be resolved.
        if(DID_ERR)
        {
            free(buf);
            return end();
        }

        // Next argument if the current is empty.
        size_t alen = strlen(arg);

        if(!alen)
        {
            continue;
        }

        // Increase the total string length.
        len += alen;

        // Allocate a bigger buffer if necessary.
        if(len > cnt)
        {
            char *tmp;

            // Double up until we have enough.
            while(cnt && cnt < len)
            {
                cnt = cnt << 1;
            }

            tmp = DBG_ALLOC(calloc(cnt + 1, 1));

            if((!tmp || !cnt) && PANIC(contxt))
            {
                free(tmp);
                free(buf);
                return end();
            }

            // Copy contents to the new buffer and free the old one.
            memcpy(tmp, buf, len - alen + 1);
            free(buf);
            buf = tmp;
        }

        // By now we're ready to append.
        strncat(buf, arg, cnt - strlen(buf));
    }

    // Return the concatenation of all children.
    R_STR(buf);
}

//------------------------------------------------------------------------------
// Name:        h_fmt_escape
// Description: Determine if a string begins with an escape sequence.
//              specifier.
// Input:       const char *fmt:    Suspected format string.
// Return:      bool *:             'true' if 'fmt' is the beginning of an
//                                  escape seq.
//------------------------------------------------------------------------------
static inline bool h_fmt_escape(const char *fmt)
{
    return fmt && fmt[0] == '%' && (fmt[1] == '%' || fmt[1] == '\0');
}

//------------------------------------------------------------------------------
// Name:        h_fmt_number
// Description: Determine whether of not a string begins with an integer format
//              specifier.
// Input:       const char *fmt Suspected format string.
// Return:      bool *:         'true' if 'fmt' is an integer spec., else
//                              'false'.
//------------------------------------------------------------------------------
static inline bool h_fmt_number(const char *fmt)
{
    return fmt && fmt[0] == '%' && fmt[1] == 'l' && ( fmt[2] == 'd' ||
           fmt[2] == 'u' );
}

//------------------------------------------------------------------------------
// Name:        h_fmt_string
// Description: Determine whether of not a string begins with a string format
//              specifier.
// Input:       const char *fmt:    Suspected format string.
// Return:      bool *:             'true' if 'fmt' is a string spec., else
//                                  'false'.
//------------------------------------------------------------------------------
static inline bool h_fmt_string(const char *fmt)
{
    return fmt && fmt[0] == '%' && fmt[1] == 's';
}

//------------------------------------------------------------------------------
// Name:        h_fmt_scan
// Description: Scan format string and create formatted result.
// Input:       entry_p *args:  Values to format and insert.
//              char *res:      Target buffer.
//              size_t len:     Target buffer size.
//              char *fmt:      String with format specifiers.
// Return:      bool *:         -
//------------------------------------------------------------------------------
static void h_fmt_scan(entry_p *args, char *res, size_t len, char *fmt)
{
    for(size_t cur = 0, pos = 0, ndx = 0; fmt[ndx]; )
    {
        // Escape sequence.
        if(h_fmt_escape(fmt + ndx))
        {
            // Skip two characters unless we're at EOS.
            res[pos] = fmt[ndx + 1];
            ndx += res[pos++] ? 2 : 1;
        }
        // Integer specifier.
        else if(h_fmt_number(fmt + ndx))
        {
            // Skip three characters.
            ndx += 3;

            // Insert formatted segment if argument exists.
            if(exists(args[cur]))
            {
                // Convert strings to numbers if needed.
                const char *val = num(args[cur]) ? str(args[cur]) : "0";
                cur++;
                strncat(res, val, len - pos);
                pos += strlen(val);
            }
        }
        // String specifier.
        else if(h_fmt_string(fmt + ndx))
        {
            // Skip two characters.
            ndx += 2;

            // Insert formatted segment if argument exists.
            if(exists(args[cur]))
            {
                const char *val = str(args[cur++]);
                strncat(res, val, len - pos);
                pos += strlen(val);
            }
        }
        else
        {
            // No format specifier.
            res[pos++] = fmt[ndx++];
        }
    }
}

//------------------------------------------------------------------------------
// Name:        h_fmt_new_buffer
// Description: Allocate buffers big enough to hold formatted string and the
//              non evaluated values to insert.
// Input:       entry_p contxt: Execution context.
//              entry_p *args:  Output: values to format and insert.
//              char *res:      Output: target buffer.
// Return:      size_t:         Size of target buffer.
//------------------------------------------------------------------------------
static size_t n_fmt_new_buffer(entry_p contxt, entry_p **args, char **res)
{
    // Start with one empty segment.
    size_t ndx = 1;

    if(contxt->children)
    {
        // Count the number of arguments.
        while(exists(C_ARG(ndx)))
        {
            ndx++;
        }
    }

    // Allocate memory to hold all arguments.
    *args = DBG_ALLOC(calloc(ndx, sizeof(entry_p)));

    if(!(*args))
    {
        return false;
    }

    // Start with room for the specifiers.
    size_t len = strlen(contxt->name);

    while(--ndx)
    {
        // Increment by the length of all strings.
        (*args)[ndx - 1] = resolve(C_ARG(ndx));
        len += strlen(str((*args)[ndx - 1]));
    }

    // Allocate room for the concatenated result.
    *res = DBG_ALLOC(calloc(++len, 1));

    if(!(*res))
    {
        // No target buffer.
        free(*args);
        *res = NULL;
        *args = NULL;

        return 0;
    }

    return len;
}

//------------------------------------------------------------------------------
// ("<fmt>" <expr1> <expr2>)
//     returns a formatted string
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_fmt(entry_p contxt)
{
    // No arguments needed.
    C_SANE(0, NULL);

    char *res = NULL;
    entry_p *args = NULL;
    size_t len = n_fmt_new_buffer(contxt, &args, &res);

    // Exit on OOM.
    LG_ASSERT(len, end());

    // The scan can never fail.
    h_fmt_scan(args, res, len, contxt->name);

    // Owned by us.
    free(args);

    R_STR(res);
}

//------------------------------------------------------------------------------
// Name:        h_pathonly
// Description: Get path part from file path.
// Input:       const char *full:   Path to file.
// Return:      const char *:       Path part of full or NULL on failure.
//------------------------------------------------------------------------------
char *h_pathonly(const char *full)
{
    size_t len = strlen(full);

    // Scan backwards.
    while(len--)
    {
        // If we find a delimiter, then we have the path to the left of it.
        if(full[len] == '/' || full[len] == ':' )
        {
            // Get termination for free.
            char *path = DBG_ALLOC(calloc(len + 2, 1));

            if(!path)
            {
                return NULL;
            }

            // Copy full path.
            memcpy(path, full, len + 1);

            // Cut trailing '/' if preceded by something absolute, dir or vol.
            if(len > 1 && path[len] == '/' && path[len - 1] != '/' &&
               path[len - 1] != ':')
            {
                path[len] = '\0';
            }

            return path;
        }
    }

    // Current dir.
    return DBG_ALLOC(strdup(""));
}

//------------------------------------------------------------------------------
// (pathonly <path>)
//     return dir part of path (see fileonly)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_pathonly(entry_p contxt)
{
    // One argument.
    C_SANE(1, NULL);

    char *path = h_pathonly(str(C_ARG(1)));

    // Exit on OOM.
    LG_ASSERT(path, end());

    R_STR(path);
}

//------------------------------------------------------------------------------
// (patmatch <pattern> <string>)
//     Does <pattern> match <string> ? TRUE : FALSE
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_patmatch(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    #if defined(AMIGA) && !defined(LG_TEST)
    // Pattern and string to match.
    char *pat = str(C_ARG(1)), *mat = str(C_ARG(2));

    // Try to tokenize pattern.
    LONG w = ParsePatternNoCase(pat, buf_raw(), buf_len());

    // Can we parse the pattern?
    if(w >= 0)
    {
        // Use pattern matching or case insensitive string comparison.
        bool r = w ? MatchPatternNoCase(buf_raw(), mat) : !strcasecmp(pat, mat);
        R_NUM(r ? LG_TRUE : LG_FALSE);
    }

    // Could not parse pattern.
    R_NUM(LG_FALSE);
    #else
    // Testing.
    R_NUM(LG_FALSE);
    #endif
}

//------------------------------------------------------------------------------
// (strlen <string>)
//     returns string length
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_strlen(entry_p contxt)
{
    // One argument.
    C_SANE(1, NULL);

    // Set and return.
    R_NUM((int32_t) strlen(str(C_ARG(1))));
}

//------------------------------------------------------------------------------
// (substr <string> <start> [<count>])
//     returns a substring of <string>
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_substr(entry_p contxt)
{
    // We need at least two arguments.
    C_SANE(2, NULL);

    const char *arg = str(C_ARG(1));
    int32_t off = num(C_ARG(2)), len = (int32_t) strlen(arg);

    // Is there a limitation on the number of characters?
    if(exists(C_ARG(3)))
    {
        // Get the number of characters to copy.
        int32_t chr = num(C_ARG(3));

        // Use the limitations used by the CBM installer.
        if(off >= len || chr <= 0 || off < 0)
        {
            // Empty string.
            R_EST;
        }

        char *ret = DBG_ALLOC(calloc((size_t) len + 1, 1));

        // Exit on OOM.
        LG_ASSERT(ret, end());

        // Cap values, set and return.
        len -= off;
        len = len < chr ? len : chr;
        memcpy(ret, arg + off, len);
        R_STR(ret);
    }

    // Copy until the end of the string. Max cap.
    if(off >= len)
    {
        // Empty string.
        R_EST;
    }

    // Min cap.
    if(off > 0)
    {
        char *ret = DBG_ALLOC(calloc((size_t) len + 1, 1));

        // Exit on OOM.
        LG_ASSERT(ret, end());

        // All values are already capped, just copy.
        memcpy(ret, arg + off, len - off);
        R_STR(ret);
    }

    // Return full string.
    return C_ARG(1);
}

//------------------------------------------------------------------------------
// (tackon <path> <file>)
//     return properly concatenated file to path
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_tackon(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // All work is done by the helper.
    char *ret = h_tackon(contxt, str(C_ARG(1)), str(C_ARG(2)));

    if(!ret)
    {
        // Empty string. Error set by h_tackon().
        R_EST;
    }

    // Success.
    R_STR(ret);
}

//------------------------------------------------------------------------------
// Name:        h_tackon
// Description: Concatenate directory and file strings
// Input:       entry_p contxt:     The execution context.
//              const char *pre:    The directory.
//              const char *suf:    The file.
// Return:      const char *:       The dir/file concatenation.
//------------------------------------------------------------------------------
char *h_tackon(entry_p contxt, const char *pre, const char *suf)
{
    if(!pre || !suf)
    {
        // Bad input.
        return NULL;
    }

    size_t lep = strlen(pre), les = strlen(suf);

    // No point doing this if both strings are empty.
    if(!lep && !les)
    {
        return NULL;
    }

    // In strict mode, the filename is not allowed to end with a delimiter.
    if(les && (suf[les - 1] == '/' || suf[les - 1] == ':')
       && get_num(contxt, "@strict"))
    {
        ERR(ERR_NOT_A_FILE, suf);
        return NULL;
    }

    // Ignore the path part if the file part is an absolute Amiga path.
    if(strchr(suf, ':'))
    {
        lep = 0;
    }

    // Allocate memory to hold path, filename, delimiter and termination.
    size_t let = lep + les + 2;
    char *ret = DBG_ALLOC(calloc(let, 1));

    // Exit in OOM.
    LG_ASSERT(ret, NULL);

    // Copy the path and insert delimiter if it doesn't exist.
    memcpy(ret, pre, lep);

    if(lep && pre[lep - 1] != '/' && pre[lep - 1] != ':')
    {
       strncat(ret, "/", let - strlen(ret));
    }

    // Concatenate the result.
    strncat(ret, suf, let - strlen(ret));
    return ret;
}
