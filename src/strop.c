//------------------------------------------------------------------------------
// strop.c:
//
// String operations
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
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
entry_p m_cat(entry_p contxt)
{
    // We need atleast one string.
    C_SANE(1, NULL);

    // Start with a string length of LG_STRLEN.
    size_t cnt = LG_STRLEN, len = 0, cur = 0;
    char *buf = DBG_ALLOC(calloc(cnt + 1, 1));

    if(!buf && PANIC(contxt))
    {
        // Out of memory.
        R_CUR;
    }

    // Iterate over all arguments.
    while(exists(contxt->children[cur]))
    {
        // Resolve the current argument.
        const char *arg = str(contxt->children[cur++]);
        size_t alen = strlen(arg);

        // Return an empty string if argument couldn't be resolved.
        if(DID_ERR)
        {
            free(buf);
            R_EST;
        }

        // Next argument if the current is empty.
        if(!alen)
        {
            continue;
        }

        // Increase the total string length.
        len += strlen(arg);

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
                // Out of memory.
                free(tmp);
                free(buf);
                R_EST;
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
// ("<fmt>" <expr1> <expr2>)
//     returns a formatted string
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_fmt(entry_p contxt)
{
    // No arguments needed.
    C_SANE(0, NULL);

    // The format string is in the name with a maximum length of specifiers / 2.
    char *ret = NULL, *fmt = contxt->name;
    char **sct = DBG_ALLOC(calloc((strlen(fmt) >> 1) + 1, sizeof(char *)));

    if(!sct && PANIC(contxt))
    {
        // Out of memory.
        R_EST;
    }

    size_t ndx = 0, off = 0, cnt = 0, len = 0;
    entry_p *arg = contxt->children;

    // Scan the format string.
    for(; fmt[ndx]; ndx++)
    {
        // Skip non format specifiers.
        if(fmt[ndx] != '%')
        {
            continue;
        }

        // If escape translate into fprintf escape and skip.
        if(ndx && fmt[ndx - 1] == '\\')
        {
            fmt[ndx - 1] = '%';
            continue;
        }

        // If this is a specifier, allocate a string with just this specifier.
        if(fmt[++ndx] == 's' || (fmt[ndx++] == 'l' && fmt[ndx] == 'd'))
        {
            sct[cnt] = DBG_ALLOC(calloc(ndx - off + 2, 1));

            if(sct[cnt])
            {
                memcpy(sct[cnt], fmt + off, ndx - off + 1);
                off = ndx + 1;
                cnt++;
                continue;
            }

            // Out of memory
            PANIC(contxt);
        }
        else
        {
            ERR(ERR_FMT_INVALID, contxt->name);
            break;
        }
    }

    // Convert and format format specifiers and arguments.
    if(cnt)
    {
        for(cnt = 0; sct[cnt]; cnt++)
        {
            if(arg && exists(*arg))
            {
                // Original string length.
                size_t oln = strlen(sct[cnt]);

                // Format string.
                if(sct[cnt][oln - 1] == 's')
                {
                    char *val = str(*arg);
                    size_t nln = oln + strlen(val);
                    char *new = DBG_ALLOC(calloc(nln + 1, 1));

                    if(!new && PANIC(contxt))
                    {
                        // Out of memory
                        len = 0;
                        break;
                    }

                    // Replace format string with the formated string.
                    int sln = snprintf(new, nln, sct[cnt], val);
                    len += sln > 0 ? (size_t) sln : 0;
                    free(sct[cnt]);
                    sct[cnt] = new;
                }
                else
                // Format numeric value.
                if(sct[cnt][oln - 1] == 'd')
                {
                    int val = num(*arg);
                    size_t nln = oln + LG_NUMLEN;
                    char *new = DBG_ALLOC(calloc(nln + 1, 1));

                    if(!new && PANIC(contxt))
                    {
                        // Out of memory
                        len = 0;
                        break;
                    }

                    // Replace format string with the formated string.
                    int sln = snprintf(new, nln, sct[cnt], val);
                    len += sln > 0 ? (size_t) sln : 0;
                    free(sct[cnt]);
                    sct[cnt] = new;
                }
                else
                {
                    // Argument <-> specifier mismatch.
                    ERR(ERR_FMT_MISMATCH, contxt->name);
                }

                // Next specifier -> argument.
                arg++;
            }
            else
            {
                // Argument count and specifier count mismatch.
                ERR(ERR_FMT_MISSING, contxt->name);
                len = 0;
                break;
            }
        }
    }

    // Concatenate all formated strings.
    if(cnt && len)
    {
        // Allocate memory to hold all of them.
        len += strlen(fmt + off) + 1;
        ret = DBG_ALLOC(calloc(len, 1));

        if(ret)
        {
            // All format strings.
            for(cnt = 0; sct[cnt]; cnt++)
            {
                strncat(ret, sct[cnt], len - strlen(ret));
            }

            // Suffix.
            strncat(ret, fmt + off, len - strlen(ret));
        }
        else
        {
            // Out of memory
            PANIC(contxt);
        }
    }

    // Free all temporary format strings.
    for(cnt = 0; sct[cnt]; cnt++)
    {
        free(sct[cnt]);
    }

    // Free scatter list.
    free(sct);

    // No format specifiers, the format string is the result.
    if(!cnt)
    {
        ret = DBG_ALLOC(strdup(fmt));
    }

    // If in strict mode, fail on argument <-> specifier count mismatch.
    if(arg && exists(*arg) && get_num(contxt, "@strict"))
    {
        ERR(ERR_FMT_UNUSED, contxt->name);
    }
    else if(ret)
    {
        R_STR(ret);
    }

    // Return empty string on failure.
    free(ret);
    R_EST;
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
                // Out of memory.
                return NULL;
            }

            // Copy full path.
            memcpy(path, full, len + 1);

            // Cut trailing '/' if preceeded by something absolute, dir or vol.
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
entry_p m_pathonly(entry_p contxt)
{
    // One argument.
    C_SANE(1, NULL);

    char *path = h_pathonly(str(C_ARG(1)));

    if(!path && PANIC(contxt))
    {
        // Out of memory.
        R_EST;
    }

    R_STR(path);
}

//------------------------------------------------------------------------------
// (patmatch <pattern> <string>)
//     Does <pattern> match <string> ? TRUE : FALSE
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_patmatch(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    #if defined(AMIGA) && !defined(LG_TEST)
    // Pattern and string to match.
    char *pat = str(C_ARG(1)), *mat = str(C_ARG(2));

    // Try to tokenize pattern.
    LONG w = ParsePatternNoCase(pat, get_buf(), buf_size());

    // Can we parse the pattern?
    if(w >= 0)
    {
        // Use pattern matching or case insensitive string comparison.
        int r = w ? MatchPatternNoCase(get_buf(), mat) : !strcasecmp(pat, mat);
        R_NUM(r ? LG_TRUE : LG_FALSE);
    }

    // Buffer overflow.
    ERR(ERR_OVERFLOW, pat);
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
entry_p m_strlen(entry_p contxt)
{
    // One argument.
    C_SANE(1, NULL);

    // Set and return.
    R_NUM((int) strlen(str(C_ARG(1))));
}

//------------------------------------------------------------------------------
// (substr <string> <start> [<count>])
//     returns a substring of <string>
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_substr(entry_p contxt)
{
    // We need at least two arguments.
    C_SANE(2, NULL);

    char *arg = str(C_ARG(1));
    int off = num(C_ARG(2)), len = (int) strlen(arg);

    // Is there a limitation on the number of characters?
    if(exists(C_ARG(3)))
    {
        // Get the number of characters to copy.
        int chr = num(C_ARG(3));

        // Use the limitations used by the CBM installer.
        if(off >= len || chr <= 0 || off < 0)
        {
            // Empty string fallback.
            R_EST;
        }

        char *ret = DBG_ALLOC(calloc((size_t) len + 1, 1));

        if(!ret && PANIC(contxt))
        {
            // Out of memory.
            R_EST;
        }

        // Cap values, set and return.
        len -= off;
        len = len < chr ? len : chr;
        memcpy(ret, arg + off, len);
        R_STR(ret);
    }

    // Copy until the end of the string. Max cap.
    if(off >= len)
    {
        // Empty string fallback.
        R_EST;
    }

    // Min cap.
    if(off > 0)
    {
        char *ret = DBG_ALLOC(calloc((size_t) len + 1, 1));

        if(!ret && PANIC(contxt))
        {
            // Out of memory.
            R_EST;
        }

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
entry_p m_tackon(entry_p contxt)
{
    // Two arguments.
    C_SANE(2, NULL);

    // All work is done by the helper.
    char *ret = h_tackon(contxt, str(C_ARG(1)), str(C_ARG(2)));

    if(!ret)
    {
        // Empty string. Error codes are set by h_tackon().
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

    // If the path is empty, the result equals the filename. If the filename is
    // empty, the result equals the path.
    if(!lep || !les)
    {
        char *ret = DBG_ALLOC(strdup(lep ? pre : suf));

        if(!ret)
        {
            // Out of memory.
            PANIC(contxt);
        }

        return ret;
    }

    // Allocate memory to hold path, filename, delimiter and termination.
    size_t let = lep + les + 2;
    char *ret = DBG_ALLOC(calloc(let, 1));

    if(!ret && PANIC(contxt))
    {
        // Out of memory.
        return NULL;
    }

    // Copy the path and insert delimiter if it doesn't exist.
    memcpy(ret, pre, lep);

    if(pre[lep - 1] != '/' && pre[lep - 1] != ':')
    {
       strncat(ret, "/", let - strlen(ret));
    }

    // Concatenate the result.
    strncat(ret, suf, let - strlen(ret));
    return ret;
}
