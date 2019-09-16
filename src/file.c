//------------------------------------------------------------------------------
// file.c:
//
// File operations
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "file.h"
#include "gui.h"
#include "probe.h"
#include "resource.h"
#include "strop.h"
#include "util.h"
#include <dirent.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#ifdef AMIGA
#include <dos/dos.h>
#include <dos/dosasl.h>
#include <dos/dosextens.h>
#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/icon.h>
#include <workbench/workbench.h>
#endif

//------------------------------------------------------------------------------
// (expandpath <path>)
//     Expands a short path to its full path equivalent
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_expandpath(entry_p contxt)
{
    // One argument and no options.
    C_SANE(1, NULL);

    // Short path.
    char *pth = str(C_ARG(1));

    // Make sure that the argument is resolvable.
    if(DID_ERR)
    {
        R_EST;
    }

    #if defined(AMIGA) && !defined(LG_TEST)
    // Lock whatever resource the argument corresponds to.
    BPTR lock = (BPTR) Lock(pth, ACCESS_READ);

    if(lock)
    {
        // Get full name from lock.
        if(NameFromLock(lock, get_buf(), buf_size()))
        {
            UnLock(lock);
            R_STR(strdup(get_buf()));
        }

        // Buffer overflow.
        ERR(ERR_OVERFLOW, pth);
        UnLock(lock);
    }

    // Empty string fallback.
    R_EST;
    #else
    // Testing only.
    R_STR(strdup(pth));
    #endif
}

//------------------------------------------------------------------------------
// Name:        h_confirm
// Description: Ask user for confirmation (proceed / skip / abort).
// Input:       entry_p contxt:     The execution context.
//              const char *hlp:    Help text.
//              const char *msg:    Message format string.
//              ...:                Format string varargs.
// Return:      bool:               If confirmed 'true' else 'false'. Both
//                                  skip and abort will return 'false'.
//------------------------------------------------------------------------------
bool h_confirm(entry_p contxt, const char *hlp, const char *msg, ...)
{
    if(!contxt && PANIC(NULL))
    {
        // Bad input.
        return false;
    }

    // By setting @yes, @skip or @abort user behaviour can be simulated.
    inp_t grc = get_num(contxt, "@abort") ? G_ABORT :
                get_num(contxt, "@skip") ? G_FALSE :
                get_num(contxt, "@yes") ? G_TRUE : G_EXIT;

    va_list ap;

    // Format messsage string.
    va_start(ap, msg);
    vsnprintf(get_buf(), buf_size(), msg, ap);
    va_end(ap);

    // Get confirmation unless @yes, @skip or @abort are set.
    if(grc == G_EXIT)
    {
        entry_p back = opt(contxt, OPT_BACK);
        grc = gui_confirm(get_buf(), hlp, back != false);

        // If (back) exists, execute body on user / fake abort.
        if(back && (grc == G_ABORT || get_num(contxt, "@back")))
        {
            grc = resolve(back) ? G_TRUE : G_ERR;
        }
    }

    // Translate response.
    return (grc == G_TRUE) || ((grc == G_ABORT || grc == G_EXIT) && HALT);
}

#if defined(AMIGA) && !defined(LG_TEST)
//------------------------------------------------------------------------------
// Name:        h_exists_amiga_type
// Description: h_exists amiga implementation.
// Input:       const char *name:   Path to file / dir.
// Return:      int:                LG_NONE/LG_FILE/LG_DIR
//------------------------------------------------------------------------------
static int h_exists_amiga_type(const char *name)
{
    struct FileInfoBlock *fib = (struct FileInfoBlock *)
           AllocDosObject(DOS_FIB, NULL);

    if(!fib && PANIC(NULL))
    {
        // Out of memory.
        return LG_NONE;
    }

    // Attempt to lock file or directory.
    BPTR lock = (BPTR) Lock(name, ACCESS_READ);
    int type = LG_NONE;

    if(lock)
    {
        // Get information from lock.
        if(Examine(lock, fib))
        {
            // ST_FILE (-3) ST_LINKFILE (-4)
            if(fib->fib_DirEntryType < 0)
            {
                // It's a file.
                type = LG_FILE;
            }
            // ST_ROOT (1) ST_USERDIR (2) ST_SOFTLINK (3) ST_LINKDIR (4)
            else if(fib->fib_DirEntryType > 0)
            {
                // It's a directory.
                type = LG_DIR;
            }
        }

        // Release lock to file or directory.
        UnLock(lock);
    }

    FreeDosObject(DOS_FIB, fib);
    return type;
}
#else
//------------------------------------------------------------------------------
// Name:        h_exists_posix_type
// Description: h_exists posix implementation.
// Input:       const char *name:   Path to file / dir.
// Return:      int:                LG_NONE/LG_FILE/LG_DIR
//------------------------------------------------------------------------------
static int h_exists_posix_type(const char *name)
{
    // This implementation doesn't work on MorphOS. I have no clue why, it works
    // on AROS. Let's use the implementation above on all Amiga systems for now.
    struct stat fst;

    // Does the file / dir exist?
    if(stat(name, &fst))
    {
        return LG_NONE;
    }

    // A file?
    if(S_ISREG(fst.st_mode))
    {
        return LG_FILE;
    }

    // A directory?
    if(S_ISDIR(fst.st_mode))
    {
        return LG_DIR;
    }

    // It's something else. Pretend that it doesn't exist.
    return LG_NONE;
}
#endif

//------------------------------------------------------------------------------
// Name:        h_exists
// Description: Get file / dir info. Return value according to the CBM Installer
//              documentation.
// Input:       entry_p contxt:     The execution context.
//              const char *name:   Path to file / dir.
// Return:      int:                LG_NONE/LG_FILE/LG_DIR
//------------------------------------------------------------------------------
int h_exists(const char *name)
{
    // NULL is a valid argument but this 'file' doesn't exist.
    if(!name)
    {
        return LG_NONE;
    }

    // Empty string = current dir.
    if(!(*name))
    {
        return LG_DIR;
    }

    #if defined(AMIGA) && !defined(LG_TEST)
    return h_exists_amiga_type(name);
    #else
    return h_exists_posix_type(name);
    #endif
}

//------------------------------------------------------------------------------
// Name:        h_fileonly
// Description: Get file part from full path.
// Input:       entry_p contxt:     The execution context.
//              const char *path:   Path to file.
// Return:      const char *:       On success, file part of path, otherwise an
//                                  empty string.
//------------------------------------------------------------------------------
static const char *h_fileonly(entry_p contxt, const char *path)
{
    if(!path && PANIC(contxt))
    {
        // Bad input. Always return a valid string.
        return "";
    }

    size_t len = strlen(path);

    // Do we have a string that doesn't look like a directory / volume?
    if(len-- && path[len] != '/' && path[len] != ':' )
    {
        // Back off until we find a delimiter or the beginning of the string.
        while(len && path[len - 1] != '/' && path[len - 1] != ':' )
        {
            len--;
        }

        // Return the new offset.
        return path + len;
    }

    // Empty string or dir / vol. Only fail if we're in 'strict' mode.
    if(get_num(contxt, "@strict"))
    {
        ERR(ERR_NOT_A_FILE, path);
    }

    // Always return a valid string.
    return "";
}

//------------------------------------------------------------------------------
// Name:        h_suffix
// Description: Append file / directory suffix.
// Input:       const char *name:     Name of file or directory.
//              const char *suffix:   Suffix to append.
// Return:      char *:               File or directory with suffix.
//------------------------------------------------------------------------------
static char *h_suffix(const char *name, const char *suffix)
{
    // Append suffix. Don't trust the input.
    if(name && suffix)
    {
        snprintf(get_buf(), buf_size(), "%s.%s", name, suffix);
    }

    // Success or failure.
    return get_buf();
}

//------------------------------------------------------------------------------
// Name:        h_suffix_append
// Description: Append file / directory suffix and append the result to a
//              node list. If the resulting file / directory doesn't exist,
//              nothing will be appended.
// Input:       entry_p node:   List tail.
//              char *suffix:   Suffix to append.
// Return:      entry_p:        New tail.
//------------------------------------------------------------------------------
static pnode_p h_suffix_append(entry_p contxt, pnode_p node, char *suffix)
{
    // Make sure that we have a node and that it's the tail of the list.
    if(!node || node->next)
    {
        return node;
    }

    // Save type of the result, it might not be the same as the original.
    int type = h_exists(h_suffix(node->name, suffix));

    // Make sure that the file / directory exists.
    if(!type)
    {
        return node;
    }

    // New list tail.
    pnode_p tail = node;

    // It's not necessary to check the return value.
    tail->next = DBG_ALLOC(calloc(1, sizeof(struct pnode_t)));

    if(!tail->next && PANIC(contxt))
    {
        // Out of memory.
        return tail;
    }

    // New list tail.
    tail = tail->next;
    tail->name = DBG_ALLOC(strdup(h_suffix(node->name, suffix)));
    tail->copy = DBG_ALLOC(strdup(h_suffix(node->copy, suffix)));
    tail->type = type;

    return tail;
}

//------------------------------------------------------------------------------
// Forward declaration needed by h_choices.
static pnode_p h_filetree(entry_p contxt, const char *src, const char *dst,
                          entry_p files, entry_p fonts, entry_p choices,
                          entry_p pattern, entry_p infos);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Name:        h_choices
// Description: Helper for h_filetree handling (choices). Generating a complete
//              file / directory tree with source and destination tuples.
// Input:       entry_p contxt:     The execution context.
//              entry_p choices:    * List of files.
//              entry_p fonts:      * Include fonts.
//              entry_p infos:      * Include icons.
//
//              * Refer to the Installer.guide.
//
//              const char *src:    Source directory.
//              const char *dst:    Destination directory.
// Return:      entry_p:            A linked list of file and dir pairs.
//------------------------------------------------------------------------------
static pnode_p h_choices(entry_p contxt, entry_p choices, entry_p fonts,
                         entry_p infos, const char *src, const char *dst)
{
    if(!contxt || !choices || !choices->children || !src || !dst)
    {
        // Bad input.
        PANIC(contxt);
        return NULL;
    }

    // Unless the parser is broken, we will have >= one child.
    entry_p *chl = choices->children;

    // Create head node.
    pnode_p node = DBG_ALLOC(calloc(1, sizeof(struct pnode_t))), head = node;

    if(!node && PANIC(contxt))
    {
        // Out of memory.
        return NULL;
    }

    // We already know the type of the first element; it's a directory.
    node->name = DBG_ALLOC(strdup(src));
    node->copy = DBG_ALLOC(strdup(dst));
    node->type = LG_DIR;

    // Not necessary to check the return value.
    node->next = DBG_ALLOC(calloc(1, sizeof(struct pnode_t)));
    node = node->next;

    // Iterate over all files / dirs.
    while(node)
    {
        // Resolve current file.
        char *f_nam = str(*chl);

        // Build source <-> dest pair.
        node->name = h_tackon(contxt, src, f_nam);
        node->copy = h_tackon(contxt, dst, h_fileonly(contxt, f_nam));
        node->type = h_exists(node->name);

        // Next file.
        chl++;

        // Make sure that the file / dir exists. But only in strict mode,
        // otherwise just go on, missing files will be skipped during file
        // copy anyway.
        if(node->type == LG_NONE && get_num(contxt, "@strict"))
        {
            // File or directory doesn't exist.
            ERR(ERR_NO_SUCH_FILE_OR_DIR, node->name);
            return head;
        }

        long type = node->type;
        char *name = node->name, *copy = node->copy;

        // Create .info and .font nodes if necessary. No need to check node
        // pointer. Bounce and PANIC in h_suffix_append.
        node = infos ? h_suffix_append(contxt, node, "info") : node;
        node = fonts ? h_suffix_append(contxt, node, "font") : node;

        // Traverse (old, if info or font) directory if applicable.
        if(type == LG_DIR
           #ifndef AMIGA
           && strcmp(f_nam, ".") && strcmp(f_nam, "..")
           #endif
           )
        {
            // Get tree of subdirectory. Don't promote (choices).
            node->next = h_filetree
            (
                contxt, name, copy, NULL, NULL, NULL, NULL, NULL
            );

            // Fast forward to the end of the list.
            while(node->next)
            {
                node = node->next;
            }
        }

        // If there are more files, allocate memory for the next node.
        if(*chl && *chl != end())
        {
            // Not necessary to check the return value.
            node->next = DBG_ALLOC(calloc(1, sizeof(struct pnode_t)));
        }

        // Next element.
        node = node ? node->next : node;
    }

    // List complete.
    return head;
}

//------------------------------------------------------------------------------
// Name:        h_filetree
// Description: Generate a complete file / directory tree with source and
//              destination tuples. Used by m_copyfiles.
// Input:       entry_p contxt:     The execution context.
//              const char *src:    Source directory / file.
//              const char *dst:    Destination directory.
//              entry_p files:      * Files only.
//              entry_p fonts:      * Skip fonts.
//              entry_p choices:    * List of files.
//              entry_p pattern:    * File / dir pattern.
//              entry_p infos:      * Include icons (choices).
//
//              * Refer to the Installer.guide.
//
// Return:      entry_p:            A linked list of file and dir pairs.
//------------------------------------------------------------------------------
static pnode_p h_filetree(entry_p contxt, const char *src, const char *dst,
                          entry_p files, entry_p fonts, entry_p choices,
                          entry_p pattern, entry_p infos)
{
    char *n_src = NULL, *n_dst = NULL;

    if((!src || !dst) && PANIC(contxt))
    {
        // Bad input.
        return NULL;
    }

    // File enumeration.
    if(choices)
    {
        // No need for recursion. Handle enumerations separately.
        return h_choices(contxt, choices, fonts, infos, src, dst);
    }

    int type = h_exists(src);

    // Is source a directory?
    if(type == LG_DIR)
    {
        DIR *dir = opendir(src);

        if(!dir)
        {
            // Could not read from dir.
            ERR(ERR_READ_DIR, src);
            return NULL;
        }

        // Create head node.
        pnode_p node = DBG_ALLOC(calloc(1, sizeof(struct pnode_t))),
                head = node;

        if(node)
        {
            struct dirent *entry = readdir(dir);

            // The type of the first element is known; it's a directory.
            node->name = DBG_ALLOC(strdup(src));
            node->copy = DBG_ALLOC(strdup(dst));
            node->type = 2;

            // Create .info node if necessary. No need to check node pointer.
            // Bounce and PANIC in h_suffix_append.
            node = infos ? h_suffix_append(contxt, node, "info") : node;

            // Iterate over all entries in the source directory.
            while(entry)
            {
                // Create the source destination tuple
                n_src = h_tackon(contxt, src, entry->d_name),
                n_dst = h_tackon(contxt, dst, entry->d_name);

                // Are we out of memory?
                if(!n_src || !n_dst)
                {
                    free(n_src);
                    free(n_dst);
                    break;
                }

                if(pattern)
                {
                    // Use a static buffer, Installer.guide restricts pattern
                    // length to 64. MatchPattern can use a lot of stack if we
                    // use long patterns, so let's not remove this limitation.
                    static char pat[BUFSIZ];
                    #if defined(AMIGA) && !defined(LG_TEST)
                    LONG w = ParsePatternNoCase(str(pattern), pat,
                                          sizeof(pat));

                    // Can we parse the pattern?
                    if(w >= 0)
                    {
                        // Use pattern matching if we have any wildcards, else
                        // use plain strcmp().
                        if((w && MatchPatternNoCase(pat, entry->d_name))
                           || (w && !strcmp(pat, entry->d_name)))
                        {
                            // Match, get proper type.
                            type = h_exists(n_src);
                        }
                        else
                        {
                            // Not a match, skip this.
                            type = LG_NONE;
                        }
                    }
                    else
                    {
                        // Buffer overflow. No more pattern matching today.
                        ERR(ERR_OVERFLOW, str(pattern));
                        pattern = NULL;
                    }
                    #else
                    // Get rid of warning.
                    *pat = '\0';
                    type = h_exists(n_src);
                    #endif
                }
                else
                {
                    // File or directory?
                    type = h_exists(n_src);
                }

                // If we have a directory, recur.
                if(type == LG_DIR)
                {
                    // Unless the (files) option is set.
                    if(!files
                       #ifndef AMIGA
                       && strcmp(entry->d_name, ".")
                       && strcmp(entry->d_name, "..")
                       #endif
                      )
                    {
                        // Get tree of subdirectory. Don't promote (choices),
                        // dirs will be considered files and things will break.
                        node->next = h_filetree
                        (
                            contxt,
                            n_src,
                            n_dst,
                            files,
                            fonts,
                            NULL,
                            pattern,
                            NULL
                        );

                        // Fast forward to the end of the list.
                        while(node->next)
                        {
                            node = node->next;
                        }
                    }

                    // No need to store directory names.
                    free(n_src);
                    free(n_dst);
                }
                else
                {
                    node->next = DBG_ALLOC(calloc(1,
                                           sizeof(struct pnode_t)));

                    if(!node->next && PANIC(contxt))
                    {
                        // Out of memory.
                        free(n_src);
                        free(n_dst);
                        break;
                    }

                    node->next->type = type;
                    node->next->name = n_src;
                    node->next->copy = n_dst;
                    node = node->next;
                }

                // Get next entry.
                entry = readdir(dir);
            }
        }

        // No more entries.
        closedir(dir);

        // The list is complete.
        return head;
    }

    // Is source a file?
    if(type == LG_FILE)
    {
        pnode_p file = DBG_ALLOC(calloc(1, sizeof(struct pnode_t))),
                head = DBG_ALLOC(calloc(1, sizeof(struct pnode_t)));

        if(head && file)
        {
            n_src = DBG_ALLOC(strdup(src));
            n_dst = DBG_ALLOC(strdup(dst));

            if(n_src && n_dst)
            {
                // The destination of the head element will be a directory
                // even though the source is a file. We need somewhere to
                // put the file.
                head->type = LG_DIR;
                head->next = file;
                head->name = n_src;
                head->copy = n_dst;

                // Create destination file path.
                n_dst = h_tackon(contxt, dst, h_fileonly(contxt, src));
                n_src = DBG_ALLOC(strdup(src));

                if(n_src && n_dst)
                {
                    // The second element in the list will be the file.
                    file->type = LG_FILE;
                    file->name = n_src;
                    file->copy = n_dst;

                    if(!fonts)
                    {
                        // The list is complete.
                        return head;
                    }

                    // Font = file + .font.
                    snprintf(get_buf(), buf_size(), "%s.font", n_src);

                    if(h_exists(get_buf()) == LG_FILE)
                    {
                        pnode_p font = DBG_ALLOC(calloc(1, sizeof(struct pnode_t)));

                        if(font)
                        {
                            font->name = DBG_ALLOC(strdup(get_buf()));
                            font->copy = h_tackon(contxt, dst,
                                                  h_fileonly(contxt, get_buf()));

                            // Add the font to the list.
                            if(font->name && font->copy)
                            {
                                font->type = LG_FILE;
                                file->next = font;

                                // The list is complete.
                                return head;
                            }

                            // Out of memory.
                            free(font->name);
                            free(font->copy);
                            free(font);
                        }
                    }
                }

                // Out of memory.
                free(head->name);
                free(head->copy);
            }
        }

        // Out of memory.
        free(head);
        free(file);
    }
    else
    {
        // It's neither a directory or a file.
        ERR(ERR_NO_SUCH_FILE_OR_DIR, src);
        return NULL;
    }

    // Out of memory.
    PANIC(contxt);

    // These will leak if we don't free them.
    free(n_src);
    free(n_dst);

    return NULL;
}

//------------------------------------------------------------------------------
// Name:        h_protect_get
// Description: Utility function used by m_protect and m_copyfiles to get file /
//              dir protection bits.
// Input:       entry_p contxt:     The execution context.
//              const char *file:   File / dir.
//              int32_t *mask:      Pointer to the result.
// Return:      int:                On success '1', else '0'.
//------------------------------------------------------------------------------
static int h_protect_get(entry_p contxt, char *file, int32_t *mask)
{
    if((!contxt || !mask || !file) && PANIC(contxt))
    {
        // Bad input.
        return LG_FALSE;
    }

    // On non Amiga systems, or in test mode, this is a stub.
    #if defined(AMIGA) && !defined(LG_TEST)
    struct FileInfoBlock *fib = (struct FileInfoBlock *)
           AllocDosObject(DOS_FIB, NULL);

    if(!fib && PANIC(contxt))
    {
        // Out of memory.
        return LG_FALSE;
    }

    // Attempt to lock file / dir.
    bool done = false;
    BPTR lock = (BPTR) Lock(file, ACCESS_READ);

    // Did we obtain a lock?
    if(lock)
    {
        // Fill up FIB and get bits.
        if(Examine(lock, fib))
        {
            *mask = fib->fib_Protection;
            done = true;
        }

        UnLock(lock);
    }

    // Free FIB memory.
    FreeDosObject(DOS_FIB, fib);

    // Did everything above succeed?
    if(!done)
    {
        // Only fail if we're in 'strict' mode.
        if(get_num(contxt, "@strict"))
        {
            // Set invalid mask.
            ERR(ERR_GET_PERM, file);
            *mask = -1;
        }
        else
        {
            // Fallback to RWED.
            *mask = 0;
        }
    }

    // If enabled, write to log file.
    h_log(contxt, tr(S_GMSK), file, *mask);
    return done ? LG_TRUE : LG_FALSE;
    #else
    // Always succeed on non Amiga systems.
    return LG_TRUE;
    #endif
}

//------------------------------------------------------------------------------
// Name:        h_protect_set
// Description: Utility function used by m_protect and m_copyfiles to set file /
//              dir protection bits.
// Input:       entry_p contxt:     The execution context.
//              const char *file:   File / dir.
//              LONG mask:          Protection bits
// Return:      int:                On success '1', else '0'.
//------------------------------------------------------------------------------
static int h_protect_set(entry_p contxt, const char *file, LONG mask)
{
    if((!contxt || !file) && PANIC(contxt))
    {
        // Bad input.
        return LG_FALSE;
    }

    // On non Amiga systems, or in test mode, this is a stub.
    #if defined(AMIGA) && !defined(LG_TEST)
    size_t len = strlen(file);

    // Filter out volumes.
    if(len && file[len - 1] != ':')
    {
        // Only fail if we're running in 'strict' mode.
        if(!SetProtection(file, mask) && get_num(contxt, "@strict"))
        {
            ERR(ERR_SET_PERM, file);
            return LG_FALSE;
        }
    }
    #endif

    // If logging is enabled, write to log.
    h_log(contxt, tr(S_PTCT), file, mask);
    return LG_TRUE;
}

#define CF_INFOS        (1 << 0)
#define CF_FONTS        (1 << 1)
#define CF_NOGAUGE      (1 << 2)
#define CF_NOFAIL       (1 << 3)
#define CF_OKNODELETE   (1 << 4)
#define CF_FORCE        (1 << 5)
#define CF_ASKUSER      (1 << 6)
#define CF_NOPOSITION   (1 << 7)
#define CF_SILENT       (1 << 8)

//------------------------------------------------------------------------------
// Name:        h_copyfile
// Description: Copy file. Helper used by m_copyfiles and m_copylib.
// Input:       entry_p contxt:     The execution context.
//              char *src:          Source file.
//              char *dst:          Destination file.
//              int mde:            Copy mode, see CF_*.
//              bool bck:           Enable back mode.
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
static inp_t h_copyfile(entry_p contxt, char *src, char *dst, bool bck, int mde)
{
    if((!contxt || !src || !dst) && PANIC(contxt))
    {
        // Bad input.
        return G_ERR;
    }

    // GUI return code.
    inp_t grc = G_TRUE;

    // Show GUI unless we're in silent mode.
    if(!(mde & CF_SILENT))
    {
        grc = gui_copyfiles_setcur(src, mde & CF_NOGAUGE, bck);
    }

    // Prepare GUI unless we're in silent mode as used by copylib.
    if((grc != G_TRUE) && HALT)
    {
        h_log(contxt, tr(S_ACPY), src, dst);
        return grc;
    }

    static char buf[BUFSIZ];
    FILE *file = fopen(src, "r");
    size_t cnt = file ? fread(buf, 1, BUFSIZ, file) : 0;
    int err =
        #if defined(AMIGA) && !defined(LG_TEST)
        IoErr();
        #else
        file ? ferror(file) : 0;
        #endif

    if(!file || err)
    {
        // The source handle might be open.
        if(file)
        {
            fclose(file);
        }

        if(mde & CF_NOFAIL)
        {
            // Ignore failure.
            h_log(contxt, tr(S_NCPY), src, dst);
            return G_TRUE;
        }

        // Fail for real.
        ERR(ERR_READ_FILE, src);
        return G_FALSE;
    }

    // Is there an existing destination file that is write protected?
    if(!access(dst, F_OK) && access(dst, W_OK))
    {
        // No need to ask if only (force).
        if((mde & CF_FORCE) && !(mde & CF_ASKUSER))
        {
            // Unprotect file.
            chmod(dst, S_IRWXU);
        }
        else
        // Confirm if (askuser) unless we're running in novice mode and (force)
        // at the same time.
        if((mde & CF_ASKUSER) && ((mde & CF_FORCE) ||
            get_num(contxt, "@user-level") != LG_NOVICE))
        {
            if(h_confirm(contxt, "", tr(S_OWRT), dst))
            {
                // Unprotect file.
                chmod(dst, S_IRWXU);
            }
            else
            {
                // Skip file or abort.
                fclose(file);
                return DID_HALT ? G_ABORT : G_TRUE;
            }
        }
    }

    // Create / overwrite file.
    FILE *dest = fopen(dst, "w");

    if(!dest)
    {
        // The source handle is open.
        fclose(file);

        if((mde & CF_NOFAIL) || (mde & CF_OKNODELETE))
        {
            // Ignore failure.
            h_log(contxt, tr(S_NCPY), src, dst);
            return G_TRUE;
        }

        // Fail for real.
        ERR(ERR_WRITE_FILE, dst);
        return G_FALSE;
    }

    // Read and write until there is nothing more to read.
    while(cnt)
    {
        if(fwrite(buf, 1, cnt, dest) == cnt)
        {
            // Update GUI unless we're in silent mode.
            if(!(mde & CF_SILENT))
            {
                grc = gui_copyfiles_setcur(NULL, mde & CF_NOGAUGE, bck);
            }

            if(grc == G_TRUE)
            {
                cnt = fread(buf, 1, sizeof(buf), file);
            }
            else
            {
                break;
            }
        }
        else
        {
            ERR(ERR_WRITE_FILE, dst);
            grc = G_FALSE;
            break;
        }
    }

    // Close input and output files.
    fclose(file);
    fclose(dest);

    // The number of bytes read and not written should be zero.
    if(cnt)
    {
        // Error or user abort.
        return grc;
    }

    // Write to the log file (if logging is enabled).
    h_log(contxt, tr(S_CPYD), src, dst);

    // Are we going to copy the icon as well?
    if(mde & CF_INFOS)
    {
        // The source icon.
        static char icon[PATH_MAX];
        snprintf(icon, sizeof(icon), "%s.info", src);

        // Only if it exists, it's not an error if it's missing.
        if(h_exists(icon) == LG_FILE)
        {
            static char copy[PATH_MAX];

            // The destination icon.
            snprintf(copy, sizeof(copy), "%s.info", dst);

            // Recur without info set.
            grc = h_copyfile(contxt, icon, copy, bck,
                             mde & ~CF_INFOS);

            #if defined(AMIGA) && !defined(LG_TEST)
            // Reset icon position?
            if(grc == G_TRUE && mde & CF_NOPOSITION)
            {
                struct DiskObject *obj = (struct DiskObject *)
                    GetDiskObject(dst);

                if(obj)
                {
                    // Reset icon position.
                    obj->do_CurrentX = NO_ICON_POSITION;
                    obj->do_CurrentY = NO_ICON_POSITION;

                    // Save the changes to the .info file.
                    if(!PutDiskObject(dst, obj))
                    {
                        // We failed for some unknown reason.
                        ERR(ERR_WRITE_FILE, copy);
                        grc = G_FALSE;
                    }

                    FreeDiskObject(obj);
                }
            }
            #endif
        }
    }

    // Preserve file permissions. On error, code will be set by h_protect_x().
    int32_t prm = 0;

    if(h_protect_get(contxt, src, &prm))
    {
        h_protect_set(contxt, dst, prm);
    }

    // Reset error codes if necessary.
    if(DID_ERR)
    {
        if(mde & CF_NOFAIL)
        {
            // Clear errors.
            RESET;
        }
        else
        {
            // Fail for real.
            grc = G_ABORT;
        }
    }

    // Unknown status.
    return grc;
}

//------------------------------------------------------------------------------
// Name:        h_makedir_create_icon
// Description: Create directory icon.
// Input:       entry_p contxt:     The execution context.
//              char *dst:          The directory.
// Return:      bool:               On success 'true', else 'false'.
//------------------------------------------------------------------------------
static bool h_makedir_create_icon(entry_p contxt, char *dst)
{
    if((!contxt || !dst) && PANIC(contxt))
    {
        // Bad input.
        return false;
    }

    #if defined(AMIGA) && !defined(LG_TEST)
    // Get the default drawer icon from the OS.
    struct DiskObject *obj = (struct DiskObject *) GetDefDiskObject(WBDRAWER);
    #else
    FILE *obj = fopen(h_suffix(dst, "info"), "w");
    #endif

    // Bail out if we can't open the default icon.
    if(!obj)
    {
        return false;
    }

    // Save default icon if we have one.
    #if defined(AMIGA) && !defined(LG_TEST)
    // Create new .info.
    bool done = PutDiskObject(dst, obj);
    #else
    bool done = fputs("icon", obj) != EOF;
    #endif

    #if defined(AMIGA) && !defined(LG_TEST)
    // Free def. icon.
    FreeDiskObject(obj);
    #else
    fclose(obj);
    #endif

    // Success or I/O error.
    return done;
}

//------------------------------------------------------------------------------
// Name:        h_makedir
// Description: Create directory / tree of directories.
// Input:       entry_p contxt:     The execution context.
//              char *dst:          The directory.
//              int mode:           FIXME.
// Return:      int:                On success '1', else '0'.
//------------------------------------------------------------------------------
static int h_makedir(entry_p contxt, char *dst, int mode)
{
    if((!contxt || !dst) && PANIC(contxt))
    {
        // Bad input.
        return LG_FALSE;
    }

    // Create icon if (infos) is set and there is no icon already.
    if(opt(contxt, OPT_INFOS) && !h_exists(h_suffix(dst, "info")) &&
      !h_makedir_create_icon(contxt, dst))
    {
        // Failed creating icon.
        ERR(ERR_WRITE_DIR, dst);
        return LG_FALSE;
    }

    // Return immediately if directory exists.
    if(h_exists(dst) == LG_DIR)
    {
        h_log(contxt, tr(S_EDIR), dst);
        return LG_TRUE;
    }

    // Create working copy.
    char *dir = DBG_ALLOC(strdup(dst));

    if(!dir && PANIC(contxt))
    {
        // Out of memory.
        return LG_FALSE;
    }

    int depth = 1, len = (int) strlen(dir);

    // Get directory depth.
    for(int i = 0; i < len; i++)
    {
        if(dir[i] == '/')
        {
            depth++;
        }
    }

    // Maximum number of retries == depth.
    while(depth--)
    {
        // Shrink scope until mkdir works.
        for(int i = len; i >= 0; i--)
        {
            // Skip non-delimiters.
            if(dir[i] != '/' && dir[i] != '\0')
            {
                continue;
            }

            // Save delimiter and truncate.
            char del = dir[i];
            dir[i] = '\0';

            // Attempt to create truncated path.
            if(mkdir(dir, 0777) == 0)
            {
                // We're done if this is the full path.
                if(i == len)
                {
                    free(dir);
                    h_log(contxt, tr(S_CRTD), dst);
                    return LG_TRUE;
                }

                // Not the full path, reinstate delimiter and start all over
                // again with the full path.
                dir[i] = del;
                break;
            }
            else
            {
                // Reinstate delimiter and shrink scope.
                dir[i] = del;
            }
        }
    }

    // Free working copy.
    free(dir);

    if(mode)
    {
        // FIXME
        return LG_TRUE;
    }

    // For some unknown reason, we can't create the directory.
    ERR(ERR_WRITE_DIR, dst);
    return LG_FALSE;
}

//------------------------------------------------------------------------------
// (copyfiles (prompt..) (help..) (source..) (dest..) (newname..) (choices..)
//     (all) (pattern..) (files) (infos) (confirm..) (safe) (optional
//     <option> <option> ...) (delopts <option> <option> ...) (nogauge))
//
//     copy files (and subdir's by default).  files option say NO
//     subdirectories
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_copyfiles(entry_p contxt)
{
    // One or more arguments / options.
    C_SANE(1, contxt);

    entry_p prompt     = opt(contxt, OPT_PROMPT),
            help       = opt(contxt, OPT_HELP),
            source     = opt(contxt, OPT_SOURCE),
            dest       = opt(contxt, OPT_DEST),
            newname    = opt(contxt, OPT_NEWNAME),
            choices    = opt(contxt, OPT_CHOICES),
            all        = opt(contxt, OPT_ALL),
            pattern    = opt(contxt, OPT_PATTERN),
            infos      = opt(contxt, OPT_INFOS),
            confirm    = opt(contxt, OPT_CONFIRM),
            safe       = opt(contxt, OPT_SAFE),
            nogauge    = opt(contxt, OPT_NOGAUGE),
            fonts      = opt(contxt, OPT_FONTS),
            back       = opt(contxt, OPT_BACK),
            fail       = opt(contxt, OPT_FAIL),
            nofail     = opt(contxt, OPT_NOFAIL),
            oknodelete = opt(contxt, OPT_OKNODELETE),
            force      = opt(contxt, OPT_FORCE),
            askuser    = opt(contxt, OPT_ASKUSER),
            files      = opt(contxt, OPT_FILES);

    D_NUM = LG_FALSE;

    // The (pattern) (choices) and (all) options are mutually exclusive.
    if((pattern && (choices || all)) || (choices && (pattern || all)) ||
       (all && (choices || pattern)))
    {
        ERR(ERR_OPTION_MUTEX, "pattern/choices/all");
        R_NUM(LG_FALSE);
    }

    // The (fail) (nofail) and (oknodelete) options are mutually exclusive.
    if((fail && (nofail || oknodelete)) || (nofail && (fail || oknodelete)) ||
       (oknodelete && (nofail || fail)))
    {
        ERR(ERR_OPTION_MUTEX, "fail/nofail/oknodelete");
        R_NUM(LG_FALSE);
    }

    // We need a source and a destination dir.
    if(!source || !dest)
    {
        ERR(ERR_MISSING_OPTION, source ? "dest" : "source");
        R_NUM(LG_FALSE);
    }

    const char *src = str(source), *dst = str(dest);

    // If source is a directory (all)/(choices)/(pattern) are needed.
    if(h_exists(src) == LG_DIR && !all && !choices && !pattern)
    {
        ERR(ERR_MISSING_OPTION, "all/choices/pattern");
        R_NUM(LG_FALSE);
    }

    // A non safe operation in pretend mode always succeeds.
    if(get_num(contxt, "@pretend") && !safe)
    {
        R_NUM(LG_TRUE);
    }

    // Does the destination already exist?
    if(h_exists(dst) == LG_DIR)
    {
        // Don't trust h_exists, this string might be empty.
        size_t dln = strlen(dst);

        // If it's not a volume, set permissions to allow overwriting.
        if(dln && dst[dln - 1] != ':')
        {
            chmod(dst, S_IRWXU);
        }
    }

    // Traverse source directory and create destination strings.
    pnode_p tree = h_filetree(contxt, src, dst, files, fonts, choices,
                              pattern, infos);

    if(!tree)
    {
        // Either we could not read from source directory or we're out of
        // memory. Error or PANIC is set by h_filetree.
        R_NUM(LG_FALSE);
    }

    // Start from the top of the list.
    pnode_p cur = tree;

    // Replace file name if single file and the 'newname' option is set
    if(newname && cur->next && cur->type == LG_DIR &&
       cur->next->type == LG_FILE && !cur->next->next)
    {
        free(cur->next->copy);
        cur->next->copy = h_tackon(contxt, dst, str(newname));
    }

    // Initialize GUI, set up file lists, events, and so on.
    inp_t grc = gui_copyfiles_start(prompt ? str(prompt) : NULL,
                                    confirm ? str(help) : NULL, cur,
                                    confirm != false, back != false);

    // Start copy unless skip / abort / back.
    if(grc == G_TRUE)
    {
        // Set file copy mode.
        int mode = (infos ? CF_INFOS : 0) | (fonts ? CF_FONTS : 0) |
                   (nogauge ? CF_NOGAUGE : 0) | (nofail ? CF_NOFAIL : 0) |
                   (oknodelete ? CF_OKNODELETE : 0) | (force ? CF_FORCE : 0) |
                   (askuser ? CF_ASKUSER : 0);

        // For all files / dirs in list, copy / create.
        for(; cur && grc == G_TRUE; cur = cur->next)
        {
            int32_t prm = 0;

            // Copy file / create dir / skip if non existing.
            switch(cur->type)
            {
                case LG_NONE:
                    continue;

                case LG_FILE:
                    grc = h_copyfile(contxt, cur->name, cur->copy,
                                     back != false, mode);
                    break;

                case LG_DIR:
                    // Make dir and replicate source protection bits.
                    if(!h_makedir(contxt, cur->copy, mode) ||
                       !h_protect_get(contxt, cur->name, &prm) ||
                       !h_protect_set(contxt, cur->copy, prm))
                    {
                        // Could not create directory.
                        grc = G_FALSE;
                    }
                    break;

                // Invalid type.
                default:
                    PANIC(contxt);
                    break;
            }
        }

        // Translate return code.
        D_NUM = (grc == G_TRUE) ? LG_TRUE : LG_FALSE;
    }

    // GUI teardown.
    gui_copyfiles_end();

    // Back return value.
    entry_p ret = NULL;

    // FIXME
    if(grc != G_TRUE)
    {
        // Is the back option available?
        if(back)
        {
            // Fake input?
            if(get_num(contxt, "@back"))
            {
                grc = G_ABORT;
            }

            // On abort execute.
            if(grc == G_ABORT)
            {
                ret = resolve(back);
            }
        }

        // FIXME
        if(grc == G_ABORT || grc == G_EXIT)
        {
            HALT;
        }
    }

    cur = tree;

    // Free list of files / dirs.
    while(cur)
    {
        tree = cur;
        free(cur->name);
        free(cur->copy);
        cur = cur->next;
        free(tree);
    }

    // If we've executed any 'back' code, return its return value.
    if(ret)
    {
        return ret;
    }

    // We don't know if we're successsful, at this point, return what we have.
    R_CUR;
}

//------------------------------------------------------------------------------
// (copylib (prompt..) (help..) (source..) (dest..) (newname..) (infos)
//     (confirm) (safe) (optional <option> <option> ...) (delopts <option>
//     <option> ...) (nogauge))
//
//     install a library if newer version
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_copylib(entry_p contxt)
{
    // One or more arguments / options.
    C_SANE(1, contxt);

    entry_p prompt     = opt(contxt, OPT_PROMPT),
            help       = opt(contxt, OPT_HELP),
            source     = opt(contxt, OPT_SOURCE),
            dest       = opt(contxt, OPT_DEST),
            newname    = opt(contxt, OPT_NEWNAME),
            infos      = opt(contxt, OPT_INFOS),
            confirm    = opt(contxt, OPT_CONFIRM),
            safe       = opt(contxt, OPT_SAFE),
            nogauge    = opt(contxt, OPT_NOGAUGE),
            noposition = opt(contxt, OPT_NOPOSITION),
            back       = opt(contxt, OPT_BACK),
            fail       = opt(contxt, OPT_FAIL),
            nofail     = opt(contxt, OPT_NOFAIL),
            oknodelete = opt(contxt, OPT_OKNODELETE),
            force      = opt(contxt, OPT_FORCE),
            askuser    = opt(contxt, OPT_ASKUSER);

    // The (fail) (nofail) and (oknodelete) options are mutually exclusive.
    if((fail && (nofail || oknodelete)) || (nofail && (fail || oknodelete)) ||
       (oknodelete && (nofail || fail)))
    {
        ERR(ERR_OPTION_MUTEX, "fail/nofail/oknodelete");
        R_NUM(LG_FALSE);
    }

    // We always need a prompt and help since trying to overwrite new files
    // with older ones will force a confirm if we're in expert mode. The CBM
    // Installer doesn't behave this way, but the Installer guide says so, and
    // it makes sense, so let's do it this way until we know for sure that this
    // will break existing scripts.
    if(!source || !dest || !prompt || !help)
    {
        ERR(ERR_MISSING_OPTION, source ? dest ? prompt ? "help" : "prompt" :
                                                         "dest" : "source");
        R_NUM(LG_FALSE);
    }

    char *src = str(source), *dst = str(dest);
    bool strict = get_num(contxt, "@strict");

    // Does the source file exist?
    if(h_exists(src) != LG_FILE)
    {
        // Only fail if we're in 'strict' mode.
        if(strict)
        {
            ERR(ERR_NOT_A_FILE, src);
        }

        // Fail silently.
        R_NUM(LG_FALSE);
    }

    // Source version and destination type.
    int new = h_getversion_file(src), type = h_exists(dst);

    // A non safe operation in pretend mode always succeeds.
    if(!safe && get_num(contxt, "@pretend"))
    {
        R_NUM(LG_TRUE);
    }

    // Only fail if we're in 'strict' mode.
    if(new < 0 && strict)
    {
        // Could not find version string.
        ERR(ERR_NO_VERSION, src);
        R_NUM(LG_FALSE);
    }

    // Only fail if we're in 'strict' mode.
    if(type == LG_FILE && strict)
    {
        // Destination is a file, not a dir.
        ERR(ERR_NOT_A_DIR, dst);
        R_NUM(LG_FALSE);
    }

    if(type == LG_NONE)
    {
        // Directory doesn't exist, create it. One level deep only.
        if(mkdir(dst, 0777))
        {
            // Permission problems or the dir is more than 1 level deeper
            // than the existing path.
            ERR(ERR_WRITE_DIR, dst);
            R_NUM(LG_FALSE);
        }

        // Log the success.
        h_log(contxt, tr(S_CRTD), dst);
    }

    // Destination file, old name and new path or new name and new path.
    char *name = newname ? h_tackon(contxt, dst, str(newname)) :
                           h_tackon(contxt, dst, h_fileonly(contxt, src));

    if(!name && PANIC(contxt))
    {
        // Out of memory.
        R_NUM(LG_FALSE);
    }

    // Set copy mode.
    int mode = CF_SILENT | (infos ? CF_INFOS : 0) |
               (noposition ? CF_NOPOSITION : 0) | (nogauge ? CF_NOGAUGE : 0) |
               (nofail ? CF_NOFAIL : 0) | (oknodelete ? CF_OKNODELETE : 0) |
               (force ? CF_FORCE : 0) | (askuser ? CF_ASKUSER : 0);

    // Get 'name' type info.
    type = h_exists(name);

    // There is no way to abort a file copy, but we need to handle the GUI
    // return values anyway.
    inp_t grc = G_FALSE;

    // Are we overwriting a file?
    if(type == LG_NONE)
    {
        // No such file, copy source to the destination directory. If needed
        // get confirmation.
        if(confirm)
        {
            // Is the version of the source file unknown?
            if(new < 0)
            {
                if(h_confirm(contxt, "", "%s\n\n%s: %s\n%s\n\n%s: %s",
                    str(prompt), tr(S_VINS), tr(S_VUNK), tr(S_NINS), tr(S_DDRW),
                    dst))
                {
                    grc = h_copyfile(contxt, src, name, back != false, mode);
                }
            }
            // The version of the source file is known.
            else
            {
                if(h_confirm(contxt, "", "%s\n\n%s: %d.%d\n%s\n\n%s: %s",
                    str(prompt), tr(S_VINS), new >> 16, new & 0xffff,
                    tr(S_NINS), tr(S_DDRW), dst))
                {
                    grc = h_copyfile(contxt, src, name, back != false, mode);
                }
            }
        }
        else
        {
            // No confirmation needed.
            grc = h_copyfile(contxt, src, name, back != false, mode);
        }
    }
    else
    // It's a file.
    if(type == LG_FILE)
    {
        // Get version of existing file.
        int old = h_getversion_file(name);

        // Is the version of the existing file unknown?
        if(old < 0)
        {
            // Only fail if we're in 'strict' mode.
            if(strict)
            {
                // Could not find version string.
                ERR(ERR_NO_VERSION, name);
                new = old;
            }
            else
            {
                // Is the version of the source file unknown?
                if(new < 0)
                {
                    // Both target and source file have an unknown version.
                    if(h_confirm(contxt, "", "%s\n\n%s: %s\n%s: %s\n\n%s: %s",
                        str(prompt), tr(S_VINS), tr(S_VUNK), tr(S_VCUR),
                        tr(S_VUNK), tr(S_DDRW), dst))
                    {
                        new = old + 1;
                    }
                    else
                    {
                        new = old;
                    }
                }
                else
                {
                    // The source file is version is known, thh target version
                    // is unknown.
                    if(h_confirm(contxt, "",
                        "%s\n\n%s: %d.%d\n%s: %s\n\n%s: %s",
                        str(prompt), tr(S_VINS), new >> 16, new & 0xffff,
                        tr(S_VCUR), tr(S_VUNK), tr(S_DDRW), dst))
                    {
                        new = old + 1;
                    }
                    else
                    {
                        new = old;
                    }
                }

                if(new > old)
                {
                    confirm = NULL;
                }
            }
        }
        // The target file version is known.
        else
        {
            // Is the version of the source file unknown?
            if(new < 0 && h_confirm(contxt, "",
               "%s\n\n%s: %s\n%s: %d.%d\n\n%s: %s", str(prompt), tr(S_VINS),
               tr(S_VUNK), tr(S_VCUR), old >> 16, old & 0xffff, tr(S_DDRW),
               dst))
            {
                new = old + 1;
                confirm = NULL;
            }
        }

        // Did we find a version not equal to that of the current file?
        if(new != old)
        {
            // If we ask for confirmation and get it, copy the file no matter
            // what version it (and the existing destination file) has.
            if(confirm)
            {
                if(h_confirm(contxt, "", "%s\n\n%s: %d.%d\n%s: %d.%d\n\n%s: %s",
                   str(prompt), tr(S_VINS), new >> 16, new & 0xffff, tr(S_VCUR),
                   old >> 16, old & 0xffff, tr(S_DDRW), dst))
                {
                    grc = h_copyfile(contxt, src, name, back != false, mode);
                }
            }
            else
            {
                // If the file to be copied has a higher version number than the
                // existing one, overwrite.
                if(new > old)
                {
                    grc = h_copyfile(contxt, src, name, back != false, mode);
                }
                else
                {
                    // If the file to be copied has a lower version number than
                    // the existing one, and we're in expert mode, ask the user
                    // to confirm. If we get a confirmation, overwrite.
                    if(get_num(contxt, "@user-level") == LG_EXPERT &&
                       h_confirm(contxt, "",
                       "%s\n\n%s: %d.%d\n%s: %d.%d\n\n%s: %s", str(prompt),
                       tr(S_VINS), new >> 16, new & 0xffff, tr(S_VCUR),
                       old >> 16, old & 0xffff, tr(S_DDRW), dst))
                    {
                        grc = h_copyfile(contxt, src, name, back != false, mode);
                    }
                }
            }
        }
    }
    // It's a dir.
    else
    {
        // Dest file exists, but is a directory. Fail in strict mode.
        if(strict)
        {
            ERR(ERR_NOT_A_FILE, name);
        }
    }

    // Free memory allocated by h_tackon.
    free(name);

    // Translate return code.
    R_NUM((grc == G_TRUE) ? LG_TRUE : LG_FALSE);
}

//------------------------------------------------------------------------------
// Name:        h_delete_file
// Description: Delete file. Helper used by m_delete.
// Input:       entry_p contxt:     The execution context.
//              const char *file:   File to delete.
// Return:      int:                On success '1', else '0'.
//------------------------------------------------------------------------------
static int h_delete_file(entry_p contxt, const char *file)
{
    if(!file && PANIC(contxt))
    {
        // Bad input.
        return LG_FALSE;
    }

    // If (force) is used, give permissions so that delete can succeed.
    if(opt(C_ARG(2), OPT_FORCE))
    {
        // No need to check to return value since errors will be caught below.
        chmod(file, S_IRWXU);
    }
    else
    {
        if(access(file, W_OK))
        {
            // Do we need to ask for confirmation?
            if(opt(C_ARG(2), OPT_ASKUSER))
            {
                // Ask for confirmation if we're not running in novice mode.
                if(get_num(contxt, "@user-level") != LG_NOVICE &&
                   h_confirm(contxt, "", tr(S_DWRT), file))
                {
                    // Give permissions so that delete can succeed. No need to
                    // check the return value since errors will be caught below.
                    chmod(file, S_IRWXU);
                }
                else
                {
                    // Halt is set by h_confirm. Skip will result in nothing.
                    return LG_FALSE;
                }
            }
            else
            {
                // Fail silently just like the original.
                return LG_FALSE;
            }
        }
    }

    // If yes, this must succeed, otherwise we will abort with an error.
    if(remove(file))
    {
        // Could not delete file.
        ERR(ERR_DELETE_FILE, file);
        return LG_FALSE;
    }

    // The file has been deleted.
    h_log(contxt, tr(S_DLTD), file);

    // Shall we delete the info file as well?
    if(!opt(C_ARG(2), OPT_INFOS))
    {
        // No, we're done.
        return LG_TRUE;
    }

    // Do we have a corresponding .info file?
    char *info = h_suffix(file, "info");

    if(h_exists(h_suffix(file, "info")) == LG_FILE)
    {
        // Set write permission and delete file.
        if(chmod(info, S_IRWXU) || remove(info))
        {
            ERR(ERR_DELETE_FILE, info);
            return LG_FALSE;
        }

        // The info file has been deleted.
        h_log(contxt, tr(S_DLTD), info);
    }

    // All done.
    return LG_TRUE;
}

//------------------------------------------------------------------------------
// Name:        h_delete_dir
// Description: Delete directory. Helper used by m_delete.
// Input:       entry_p contxt:     The execution context.
//              const char *name:   Directory to delete.
// Return:      int:                On success '1', else '0'.
//------------------------------------------------------------------------------
static int h_delete_dir(entry_p contxt, const char *name)
{
    if(!name && PANIC(contxt))
    {
        // Bad input.
        return LG_FALSE;
    }

    entry_p infos    = opt(C_ARG(2), OPT_INFOS),
            force    = opt(C_ARG(2), OPT_FORCE),
            askuser  = opt(C_ARG(2), OPT_ASKUSER),
            all      = opt(C_ARG(2), OPT_ALL);

    if(!force && access(name, W_OK))
    {
        // Do we need to ask for confirmation?
        if(askuser)
        {
            // Ask for confirmation if we're not running in novice mode.
            if(get_num(contxt, "@user-level") == LG_NOVICE ||
               !h_confirm(C_ARG(2), "", tr(S_DWRD), name))
            {
                // Halt will be set by h_confirm. Skip will result in nothing.
                return LG_FALSE;
            }
        }
        else
        {
            // Exit silently.
            return LG_FALSE;
        }
    }

    // Give permissions so that delete can succeed. No need to check the return
    // value since errors will be caught below.
    chmod(name, S_IRWXU);

    if(rmdir(name))
    {
        if(all)
        {
            DIR *dir = opendir(name);

            // Permission to read?
            if(dir)
            {
                struct dirent *entry = readdir(dir);

                // Find all files in the directory.
                while(entry)
                {
                    // Create full path.
                    char *path = h_tackon(contxt, name, entry->d_name);

                    // Is it a file?
                    if(path && h_exists(path) == LG_FILE)
                    {
                        // Delete it.
                        h_delete_file(contxt, path);
                    }

                    // Free full path.
                    free(path);

                    // Get next entry.
                    entry = readdir(dir);
                }

                // Restart from the beginning.
                rewinddir(dir);
                entry = readdir(dir);

                // Find all subdirectories in the directory.
                while(entry)
                {
                    #ifndef AMIGA
                    // Filter out the magic on non-Amigas.
                    if(strcmp(entry->d_name, ".") &&
                       strcmp(entry->d_name, ".."))
                    #endif
                    {
                        // Create full path.
                        char *path = h_tackon(contxt, name, entry->d_name);

                        // Is it a directory?
                        if(path && h_exists(path) == LG_DIR)
                        {
                            // Recur into subdirectory.
                            h_delete_dir(contxt, path);
                        }

                        // Free full path.
                        free(path);
                    }

                    // Get next entry.
                    entry = readdir(dir);
                }

                // Close the (by now, hopefully) empty dir.
                closedir(dir);
            }

            if(rmdir(name))
            {
                // Fail silently.
                return LG_FALSE;
            }
        }
        else
        {
            // Fail silently.
            return LG_FALSE;
        }
    }

    // Delete the icon as well?
    if(!infos)
    {
        // No, we're done.
        return LG_TRUE;
    }

    // Info = file + .info.
    char *info = get_buf();
    snprintf(info, buf_size(), "%s.info", name);

    // We're done if there's no icon.
    if(h_exists(info) != LG_FILE)
    {
        return LG_TRUE;
    }

    // Set permissions so that delete can succeed.
    chmod(info, S_IRWXU);

    // Delete the info file.
    if(!remove(info))
    {
        h_log(contxt, tr(S_DLTD), info);
        return LG_TRUE;
    }

    // Fail silently.
    return LG_FALSE;
}

//------------------------------------------------------------------------------
// Name:        h_delete_pattern
// Description: Delete file / dir matching pattern. Helper used by m_delete.
// Input:       entry_p contxt:     The execution context.
//              const char *pat:    Pattern.
// Return:      int:                On success '1', else '0'.
//------------------------------------------------------------------------------
static int h_delete_pattern(entry_p contxt, const char *pat)
{
    if((!contxt || !pat) && PANIC(contxt))
    {
        // Bad input.
        return LG_FALSE;
    }

    // Pattern matching is only done on Amiga systems in non test mode.
    #if defined(AMIGA) && !defined(LG_TEST)
    struct AnchorPath *apt =
        DBG_ALLOC(calloc(1, sizeof(struct AnchorPath) + PATH_MAX));

    if(!apt && PANIC(contxt))
    {
        // Out of memory.
        return LG_FALSE;
    }

    apt->ap_Strlen = PATH_MAX;
    int err;

    // For all matches, invoke the appropriate function for deletion.
    for(err = MatchFirst(pat, apt); !err; err = MatchNext(apt))
    {
        // ST_FILE (-3) ST_LINKFILE (-4)
        if(apt->ap_Info.fib_DirEntryType < 0)
        {
            if(!h_delete_file(contxt, apt->ap_Buf))
            {
                // Break out on trouble / user abort.
                break;
            }
        }
        else
        // ST_ROOT (1) ST_USERDIR (2) ST_SOFTLINK (3) ST_LINKDIR (4)
        if(apt->ap_Info.fib_DirEntryType > 0)
        {
            if(!h_delete_dir(contxt, apt->ap_Buf))
            {
                // Break out on trouble / user abort.
                break;
            }
        }
    }

    // Free all resources.
    MatchEnd(apt);
    free(apt);

    // Is there nothing left?
    if(!err || err == ERROR_NO_MORE_ENTRIES)
    {
        // Done.
        return LG_TRUE;
    }

    // Breaks will take us here, so will MatchFirst / MatchNext() problems.
    ERR(ERR_DELETE_FILE, pat);
    return LG_FALSE;
    #else
    // On non Amiga systems this is a stub.
    return LG_TRUE;
    #endif
}

//------------------------------------------------------------------------------
// (delete file (help..) (prompt..) (confirm..)
//     (infos) (optional <option> <option> ...) (all)
//     (delopts <option> <option> ...) (safe))
//
//     delete file
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_delete(entry_p contxt)
{
    // One argument and options.
    C_SANE(1, C_ARG(2));

    int wild = 0;
    char *file = str(C_ARG(1));

    #if defined(AMIGA) && !defined(LG_TEST)
    wild = ParsePatternNoCase(file, get_buf(), buf_size());
    #else
    wild = get_num(contxt, "@wild");
    #endif

    // Can we parse the input string?
    if(wild < 0)
    {
        // Buffer overflow.
        ERR(ERR_OVERFLOW, file);
        R_NUM(LG_FALSE);
    }

    entry_p help     = opt(C_ARG(2), OPT_HELP),
            prompt   = opt(C_ARG(2), OPT_PROMPT),
            confirm  = opt(C_ARG(2), OPT_CONFIRM);

    // If we need confirmation and the user skips or aborts, return. On
    // abort, the HALT will be set by h_confirm.
    if(confirm && !h_confirm(C_ARG(2), str(help), str(prompt)))
    {
        R_NUM(LG_FALSE);
    }

    // Succeed immediately if non-safe in pretend mode.
    if(!opt(C_ARG(2), OPT_SAFE) && get_num(contxt, "@pretend"))
    {
        R_NUM(LG_TRUE);
    }

    // Did the input string contain any wildcards?
    if(wild)
    {
        // Delete everything matching the wildcard pattern.
        R_NUM(h_delete_pattern(contxt, file));
    }

    switch(h_exists(file))
    {
        case LG_NONE:
            h_log(contxt, tr(S_NSFL), file);
            R_NUM(LG_FALSE);

        case LG_FILE:
            R_NUM(h_delete_file(contxt, file));

        case LG_DIR:
            R_NUM(h_delete_dir(contxt, file));

        default:
            R_NUM(PANIC(contxt));
    }
}

//------------------------------------------------------------------------------
// (exists <filename> (noreq))
//     0 if no, 1 if file, 2 if dir
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_exists(entry_p contxt)
{
    // One argument and option.
    C_SANE(1, contxt);

    // Supress volume requester?
    if(opt(contxt, OPT_NOREQ) || opt(contxt, OPT_QUIET))
    {
        #if defined(AMIGA) && !defined(LG_TEST)
        struct Process *p = (struct Process *) FindTask(NULL);

        // Save the current window ptr.
        APTR w = p->pr_WindowPtr;

        // Disable auto request.
        p->pr_WindowPtr = (APTR) -1L;
        #endif

        // Get type (file / dir / 0)
        int res = h_exists(str(C_ARG(1)));

        #if defined(AMIGA) && !defined(LG_TEST)
        // Restore auto request.
        p->pr_WindowPtr = w;
        #endif

        R_NUM(res);
    }

    // Get type (file / dir / 0)
    R_NUM(h_exists(str(C_ARG(1))));
}

//------------------------------------------------------------------------------
// (fileonly <path>)
//     return file part of path (see pathonly)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_fileonly(entry_p contxt)
{
    // One argument and no options.
    C_SANE(1, NULL);

    // Implementation in helper function.
    R_STR(strdup(h_fileonly(contxt, str(C_ARG(1)))));
}

//------------------------------------------------------------------------------
// (foreach <dir> <pattern> <statements>)
//     do for entries in directory
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_foreach(entry_p contxt)
{
    // Three arguments and no options.
    C_SANE(3, NULL);

    // Pattern matching is not done on non-Amiga systems and not in test mode.
    #if defined(AMIGA) && !defined(LG_TEST)
    const char *pt = str(C_ARG(2));
    #endif

    // Open dir and assume failure.
    const char *dname = str(C_ARG(1));
    DIR *dir = opendir(dname);
    pnode_p top = NULL;
    bool err = true;

    // Permission to read?
    if(dir)
    {
        // Use global buffer.
        char *cwd = get_buf();
        struct dirent *ent = readdir(dir);

        // Save current working directory and enter the directory <drawer name>
        if(getcwd(cwd, buf_size()) == cwd && !chdir(dname))
        {
            // Allocate memory for the start node.
            pnode_p cur;
            top = DBG_ALLOC(calloc(1, sizeof(struct pnode_t)));

            #if defined(AMIGA) && !defined(LG_TEST)
            // This file info block will be used for all files and subdirs.
            struct FileInfoBlock *fib = (struct FileInfoBlock *)
                   AllocDosObject(DOS_FIB, NULL);

            // Use cur as a gatekeeper. If set to NULL, nothing will take place
            // except clean ups.
            cur = fib ? top : NULL;
            #else
            // No pattern matching = no fib.
            cur = top;
            #endif

            // The dir might be empty but that's not an error.
            err = false;

            // Iterate over all entries in dir.
            while(ent && cur && !err)
            {
                // Name of file / dir.
                const char *name = ent->d_name;

                #ifndef AMIGA
                // Filter out the magic on non-Amigas.
                if(strcmp(name, ".") && strcmp(name, ".."))
                #endif
                {
                    #if defined(AMIGA) && !defined(LG_TEST)
                    // The dir is not empty, we should be able to go all the way
                    // here. Assume failure.
                    err = true;

                    // Lock and get information we need from the current entry.
                    BPTR lock = (BPTR) Lock(name, ACCESS_READ);

                    if(lock)
                    {
                        if(Examine(lock, fib))
                        {
                            // If lock / examine failed cur->name will be NULL.
                            cur->type = fib->fib_DirEntryType;
                            cur->name = DBG_ALLOC(strdup(name));

                            // We're good. PANIC:s will be caught further down.
                            err = false;
                        }

                        UnLock(lock);
                    }
                    #else
                    cur->type = h_exists(name);
                    cur->name = DBG_ALLOC(strdup(name));
                    #endif

                    // Empty name indicates a PANIC if the locking failed.
                    if(!cur->name)
                    {
                        // Reset cur to NULL will generate a PANIC further down.
                        if(!err)
                        {
                            cur = NULL;
                        }

                        // Always bail out.
                        break;
                    }
                }

                // Get next entry.
                ent = readdir(dir);

                // Need to check for cur->name or else the the filtering of '.'
                // and '..' would not work, we would get entries without names.
                if(ent && cur->name)
                {
                    cur->next = DBG_ALLOC(calloc(1, sizeof(struct pnode_t)));
                    cur = cur->next;
                }
            }

            #if defined(AMIGA) && !defined(LG_TEST)
            // If dir is empty, fib will be NULL.
            if(fib)
            {
                FreeDosObject(DOS_FIB, fib);
            }
            #endif

            if(!cur && PANIC(contxt))
            {
                // Out of memory.
                err = true;
            }

            // Go back where we started.
            chdir(cwd);
        }

        // Done.
        closedir(dir);
    }

    if(err)
    {
        // We could end up here for a number of reasons. More details perhaps?
        ERR(ERR_READ_DIR, dname);
    }

    // Iterate over the entire list of files / dirs and free entries one by one.
    // If the pattern matches the current entry, set variables and execute what
    // we have in argument 3.
    while(top)
    {
        bool skip = err;
        pnode_p old = top;

        // 'Export' name and type info if we have a name.
        if(top->name)
        {
            #if defined(AMIGA) && !defined(LG_TEST)
            if(!err)
            {
                // Use global buffer.
                char *buf = get_buf();

                // Parse pattern.
                switch(ParsePatternNoCase(pt, buf, buf_size()))
                {
                    // If we have any wildcards, try to match.
                    case 1:
                        skip = !MatchPatternNoCase(buf, top->name);
                        break;

                    // If no wildcards, do a simple string comparsion.
                    case 0:
                        skip = strcmp(top->name, pt);
                        break;

                    // We probably had a buffer overflow.
                    default:
                        ERR(ERR_OVERFLOW, pt);
                        err = true;
                }
            }
            #endif

            // We always export, for memory management reasons.
            set_num(contxt, "@each-type", (int) top->type);
            set_str(contxt, "@each-name", top->name);

            if(!skip)
            {
                // Execute the code contained in the third argument.
                invoke(C_ARG(3));
            }
        }

        // Free current entry and proceed with the next.
        top = top->next;
        free(old);
    }

    // Success or failure.
    R_NUM(err ? LG_FALSE : LG_TRUE);
}

//------------------------------------------------------------------------------
// (makeassign <assign> [<path>] (safe)) ; note: <assign> doesn't need `:''
//     create an assignment
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_makeassign(entry_p contxt)
{
    // One or more arguments and option.
    C_SANE(1, contxt);

    // Succeed immediately if non-safe in pretend mode.
    if(!opt(contxt, OPT_SAFE) && get_num(contxt, "@pretend"))
    {
        R_NUM(LG_TRUE);
    }

    // The name of the assign.
    char *asn = str(C_ARG(1));
    int res = LG_FALSE;

    // Are we going to create an assign?
    if(C_ARG(2) && C_ARG(2) != end() && C_ARG(2)->type != OPTION)
    {
        // The destination.
        char *dst = str(C_ARG(2));

        #if defined(AMIGA) && !defined(LG_TEST)
        BPTR lock = (BPTR) Lock(dst, ACCESS_READ);
        if(lock)
        {
            // Create the assign. After this the lock will be owned by the OS.
            if(AssignLock(asn, lock))
            {
                res = LG_TRUE;
            }
            // On failure we own the lock and therefore need to unlock it.
            else
            {
                UnLock(lock);
            }
        }
        #else
        res = LG_TRUE;
        #endif

        // Log the outcome.
        h_log(contxt, res ? tr(S_ACRT) : tr(S_ACRE), asn, dst);
    }
    else
    {
        #if defined(AMIGA) && !defined(LG_TEST)
        // Remove assign.
        res = AssignLock(str(C_ARG(1)), (BPTR) NULL) ? LG_TRUE : LG_FALSE;
        #else
        res = LG_FAKE;
        #endif

        // Log the outcome.
        h_log(contxt, res ? tr(S_ADEL) : tr(S_ADLE), asn);
    }

    if(!res)
    {
        // Could not create / rm assign / get lock.
        ERR(ERR_ASSIGN, str(C_ARG(1)));
    }

    // Failure or success.
    R_NUM(res);
}

//------------------------------------------------------------------------------
// (makedir <name> (prompt..) (help..) (infos) (confirm..) (safe))
//     make a directory
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_makedir(entry_p contxt)
{
    // One argument and options.
    C_SANE(1, C_ARG(2));

    entry_p prompt   = opt(C_ARG(2), OPT_PROMPT),
            help     = opt(C_ARG(2), OPT_HELP),
            confirm  = opt(C_ARG(2), OPT_CONFIRM);

    // If we need confirmation and the user skips or aborts, return. On abort,
    // the HALT will be set by h_confirm.
    if(confirm && !h_confirm(C_ARG(2), str(help), str(prompt)))
    {
        R_NUM(LG_FALSE);
    }

    // Succeed immediately if this operation is unsafe and we're running in
    // pretend mode.
    if(!opt(C_ARG(2), OPT_SAFE) && get_num(contxt, "@pretend"))
    {
        R_NUM(LG_TRUE);
    }

    // We need to pass a valid context to h_makedir. If we have a CONTXT with
    // options, that's the one to pass, otherwise we should pass the default.
    entry_p con = C_ARG(2) && C_ARG(2) != end() ? C_ARG(2) : contxt;

    // Create directory.
    R_NUM(h_makedir(con, str(C_ARG(1)), 0 /* FIXME */));
}

//------------------------------------------------------------------------------
// (protect <file> [<string of flags to change>] [<dec. mask>] <parameters>)
//     get/set file protection flags
//
// 8 7 6 5 4 3 2 1  <- Bit number
// h s p a r w e d  <- corresponding protection flag
// ^ ^ ^ ^ ^ ^ ^ ^
// | | | | | | | |
// | | | | | | | +- |
// | | | | | | +--- | 0 = flag set
// | | | | | +----- | 1 = flag clear
// | | | | +------- |
// | | | |
// | | | |
// | | | +--------- |
// | | +----------- | 0 = flag clear
// | +------------- | 1 = flag set
// +--------------- |
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_protect(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, C_ARG(2));

    char *file = str(C_ARG(1));
    D_NUM = LG_FALSE;

    if(C_ARG(2) && C_ARG(2) != end())
    {
        // Get with option.
        if(C_ARG(2)->type == CONTXT)
        {
            entry_p override = opt(C_ARG(2), OPT_OVERRIDE);

            if(override)
            {
                // From user (script).
                D_NUM = num(override);
            }
            else
            {
                // From file.
                h_protect_get(contxt, file, &D_NUM);
            }
        }
        // Set value.
        else
        {
            // Assume string operation.
            const char *flg = str(C_ARG(2));
            size_t len = strlen(flg);

            entry_p safe = opt(C_ARG(3), OPT_SAFE),
                    override = opt(C_ARG(3), OPT_OVERRIDE);

            // If any numbers are present in the string, treat it as an absolute
            // mask instead.
            for(size_t i = 0; i < len; i++)
            {
                if(flg[i] < 58 && flg[i] > 47)
                {
                    // We no longer have a string.
                    len = 0;
                    break;
                }
            }

            // Do we have a string?
            if(len)
            {
                // Mode (+/-).
                int mode = 0;

                // Use a real file or override?

                if(override)
                {
                    // Get flags from user (script).
                    D_NUM = num(override);
                }
                else
                {
                    // Get flags from file.
                    if(!h_protect_get(contxt, file, &D_NUM))
                    {
                        // Helper will set proper error
                        R_NUM(-1);
                    }
                }

                // Invert 1-4.
                D_NUM ^= 0x0f;

                // For all flags.
                for(size_t i = 0; i < len; i++)
                {
                    // Mask.
                    int bit = 0;

                    // Which protection bit?
                    switch(flg[i])
                    {
                        case '+': mode = 1; break;
                        case '-': mode = 2; break;
                        case 'h': bit = 1 << 7; break;
                        case 's': bit = 1 << 6; break;
                        case 'p': bit = 1 << 5; break;
                        case 'a': bit = 1 << 4; break;
                        case 'r': bit = 1 << 3; break;
                        case 'w': bit = 1 << 2; break;
                        case 'e': bit = 1 << 1; break;
                        case 'd': bit = 1 << 0; break;
                        default: break;
                    }

                    // Adding or subtracting?
                    switch(mode)
                    {
                        case 0: D_NUM = bit; mode = 1; break;
                        case 1: D_NUM |= bit; break;
                        case 2: D_NUM &= ~bit; break;
                        default: break;
                    }
                }

                // Invert 1-4.
                D_NUM ^= 0x0f;
            }
            else
            {
                // Use an absolute mask.
                D_NUM = num(C_ARG(2));
            }

            if(!override)
            {
                // A safe operation or are we not running in pretend mode?
                if(safe || !get_num(contxt, "@pretend"))
                {
                    // Helper will set error on failure.
                    D_NUM = h_protect_set(contxt, file, D_NUM);
                }
                else
                {
                    // A non safe operation in pretend mode always succeeds.
                    D_NUM = LG_TRUE;
                }
            }
        }
    }
    else
    {
        // Get without options.
        h_protect_get(contxt, file, &D_NUM);
    }

    // Success or failure.
    R_CUR;
}

//------------------------------------------------------------------------------
// (startup (prompt..) (command..))
//     add a command to the boot scripts (startup-sequence, user-startup)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_startup(entry_p contxt)
{
    // Two or more arguments / options.
    C_SANE(2, C_ARG(2));

    const char *app = str(C_ARG(1));

    entry_p command  = opt(C_ARG(2), OPT_COMMAND),
            help     = opt(C_ARG(2), OPT_HELP),
            prompt   = opt(C_ARG(2), OPT_PROMPT);

    // Expect failure.
    D_NUM = LG_FALSE;

    // We need a command and somewhere to put it.
    if((!*app && ERR(ERR_INVALID_APP, app)) ||
       (!command && ERR(ERR_MISSING_OPTION, "command")))
    {
        R_NUM(LG_FALSE);
    }

    // If we need confirmation and the user skips or aborts, return. On abort,
    // the HALT will be set by h_confirm. Confirmation is needed when user level
    // is expert or when (confirm) is used.
    if((opt(C_ARG(2), OPT_CONFIRM) ||
        get_num(contxt, "@user-level") == LG_EXPERT) &&
        !h_confirm(C_ARG(2), str(help), str(prompt)))
    {
        R_NUM(LG_FALSE);
    }

    // We're done if executing in pretend mode.
    if(get_num(contxt, "@pretend"))
    {
        R_NUM(LG_TRUE);
    }

    // Gather and merge all (command) strings.
    char *cmd = get_optstr(C_ARG(2), OPT_COMMAND);

    if(!cmd && PANIC(contxt))
    {
        // Out of memory.
        R_NUM(LG_FALSE);
    }

    const char *fln = get_str(contxt, "@user-startup");
    const size_t len = strlen(";BEGIN ") + strlen(app),
                 ins = strlen(cmd) + 2;

    char *pre = DBG_ALLOC(calloc(len + 1, 1)),
         *pst = DBG_ALLOC(calloc(len + 1, 1)),
         *buf = NULL;

    if(pre && pst)
    {
        // We don't need to write yet.
        FILE *file = fopen(fln, "r");

        // If the file doesn't exist, try to create it.
        if(!file && !h_exists(fln))
        {
            file = fopen(fln, "w");

            // If successful, close and reopen as read only.
            if(file)
            {
                fclose(file);
                file = fopen(fln, "r");
            }
        }

        if(file)
        {
            // Seek to the end so that we can use ftell below to get the size of
            // the file.
            if(!fseek(file, 0L, SEEK_END))
            {
                // Worst case: empty file + 3 NL + terminating 0 + BEGIN and END
                // markers + command.
                size_t osz = (size_t) ftell(file),
                       nsz = osz + 2 * len + ins;

                // Allocate enough memory so that we can keep the old file + any
                // changes that we need to do in memory at the same time.
                buf = DBG_ALLOC(calloc(nsz, 1));

                if(buf)
                {
                    // Read the whole file in one go.
                    if(!fseek(file, 0L, SEEK_SET) &&
                        fread(buf, 1, osz, file) == osz)
                    {
                        // Prepare the header and footer.
                        snprintf(pre, len + 1, ";BEGIN %s", app);
                        snprintf(pst, len + 1, ";END %s", app);

                        // Do we already have an entry in the current file?
                        char *beg = strstr(buf, pre), *fin = strstr(buf, pst);

                        // Replace the current entry by inserting the new one at
                        // the same location.
                        if(beg && fin)
                        {
                            // Move the tail of the buffer to the right place.
                            memmove(beg + len + ins, fin, (buf + osz) - fin + 1);

                            // Insert the command string.
                            memcpy(beg + len + 1, cmd, ins - 2);

                            // Add surrounding line feeds so that the command
                            // won't end up being a comment.
                            beg[len + ins - 1] = beg[len] = '\n';
                        }
                        // No existing entry. Append the new entry.
                        else
                        {
                            // Header.
                            memcpy(buf + osz, pre, len);

                            // Command.
                            memcpy(buf + osz + len + 1, cmd, ins - 2);

                            // Footer.
                            memcpy(buf + osz + len + ins, pst, len);

                            // Add surrounding line feeds so that the command
                            // won't end up being a comment.
                            buf[osz + len + ins - 1] = buf[osz + len] = '\n';

                            // Add a newline at the end.
                            buf[osz + len + ins + strlen(pst)] = '\n';
                        }
                    }
                    else
                    {
                        // Read problem, error will be set further down if
                        // buf == NULL.
                        free(buf);
                        buf = NULL;
                    }
                }
                else
                {
                    // Out of memory
                    PANIC(contxt);
                }
            }

            // Reading done.
            fclose(file);
        }
    }
    else
    {
        // Out of memory
        PANIC(contxt);
    }

    // We have no longer any use for the header, footer or command string.
    free(pre);
    free(pst);
    free(cmd);

    // If we have a buffer everything wen't fine above. Go ahead and write
    // buffer to file.
    if(buf)
    {
        // Use a temporary file to make sure that we don't mess up the current
        // file if disk space becomes a problem, the system crashes, the power
        // is lost and so on and so forth.
        size_t tln = strlen(fln) + sizeof(".XXXXXX\0");
        char *tmp = DBG_ALLOC(calloc(tln, 1));

        if(tmp)
        {
            // Create temporary file.
            snprintf(tmp, tln, "%s.XXXXXX", fln);
            FILE *file = fdopen(mkstemp(tmp), "w");

            if(file)
            {
                // Write everything to the temporary file at once.
                if(fputs(buf, file) == EOF)
                {
                    // Could not write to disk. The old file is still intact.
                    fclose(file);
                }
                else
                {
                    // Close file and release buffer.
                    fclose(file);
                    free(buf);
                    buf = NULL;

                    // Open the target file just to make sure that we have
                    // write permissions.
                    file = fopen(fln, "a");

                    if(file)
                    {
                        // Close it immediately, we're not going to write
                        // directly to it.
                        fclose(file);

                        // Do a less un-atomic write to the real file by
                        // renaming the temporary file.
                        if(!rename(tmp, fln))
                        {
                            // We're done.
                            free(tmp);
                            tmp = NULL;
                            D_NUM = LG_TRUE;
                        }
                    }
                    else
                    {
                        // We aren't allowed to write data to the target
                        // file so we need to clean up temp file.
                        if(remove(tmp))
                        {
                            ERR(ERR_WRITE_FILE, tmp);
                        }
                    }
                }
            }

            // If we haven't released tmp by now, we failed when attempting
            // one of the write operations above.
            if(tmp)
            {
                ERR(ERR_WRITE_FILE, fln);
                free(tmp);
            }
        }
        else
        {
            // Out of memory
            PANIC(contxt);
        }

        // We no longer need the buffer holding the new file contents.
        free(buf);
    }
    else
    {
        // No buffer == read problem, or out of memory but then we already
        // have a PANIC.
        ERR(ERR_READ_FILE, fln);
    }

    // Success, failure or out of memory.
    R_CUR;
}

//------------------------------------------------------------------------------
// (textfile (prompt..) (help..) (dest..) (append) (include..) (confirm..) (safe))
//      create text file from other text files and strings
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//
//------------------------------------------------------------------------------
entry_p m_textfile(entry_p contxt)
{
    // One or more arguments / options.
    C_SANE(1, contxt);

    entry_p prompt   = opt(contxt, OPT_PROMPT),
            help     = opt(contxt, OPT_HELP),
            dest     = opt(contxt, OPT_DEST),
            post     = opt(contxt, OPT_APPEND),
            include  = opt(contxt, OPT_INCLUDE),
            confirm  = opt(contxt, OPT_CONFIRM),
            safe     = opt(contxt, OPT_SAFE);

    D_NUM = LG_FALSE;

    if(!dest)
    {
        ERR(ERR_MISSING_OPTION, "dest");
        R_NUM(LG_FALSE);
    }

    // If we need confirmation and the user skips or aborts, return. On abort,
    // HALT will be set by h_confirm.
    if(confirm && !h_confirm(contxt, str(help), str(prompt)))
    {
        R_NUM(LG_FALSE);
    }

    // Is this a safe operation or are we not running in pretend mode?
    if(!safe && get_num(contxt, "@pretend"))
    {
        // A non safe operation in pretend mode always succeeds.
        R_NUM(LG_TRUE);
    }

    // Overwrite existing file.
    const char *name = str(dest);
    FILE *file = fopen(name, "w");

    if(!file)
    {
        ERR(ERR_WRITE_FILE, name);
        R_NUM(LG_FALSE);
    }

    // Assume success.
    D_NUM = LG_TRUE;

    // Append to empty file. Strange but it's how the CBM installer works.
    if(post)
    {
        // Gather and merge all (append) strings.
        char *app = get_optstr(contxt, OPT_APPEND);

        if(app)
        {
            // Log operation.
            h_log(contxt, tr(S_APND), app, name);

            if(fputs(app, file) == EOF)
            {
                ERR(ERR_WRITE_FILE, name);
                D_NUM = LG_FALSE;
            }

            // Free concatenation.
            free(app);
        }
        else
        {
            // Out of memory.
            PANIC(contxt);
            D_NUM = LG_FALSE;
        }
    }

    // Include a file at the end of the new file (append proper)?
    if(include && D_NUM)
    {
        // File to copy.
        const char *incl = str(include);
        FILE *finc = fopen(incl, "r");

        if(finc)
        {
            // Use the global buffer.
            char *buf = get_buf();
            size_t siz = buf_size(), cnt = fread(buf, 1, siz, finc);

            // Log operation.
            h_log(contxt, tr(S_INCL), incl, name);

            // Copy the whole file.
            while(cnt)
            {
                // Write to destination file.
                if(fwrite(buf, 1, cnt, file) != cnt)
                {
                    ERR(ERR_WRITE_FILE, name);
                    D_NUM = LG_FALSE;
                    break;
                }

                // Do we have more data?
                cnt = fread(buf, 1, siz, finc);
            }

            // We're done reading from the include file.
            fclose(finc);
        }
    }

    // We're done writing to the newly created file.
    fclose(file);

    // We must append and / or include, or else this doesn't make sense.
    if(!post && !include)
    {
        ERR(ERR_NOTHING_TO_DO, contxt->name);
        R_NUM(LG_FALSE);
    }

    // Success or failure.
    R_CUR;
}

//------------------------------------------------------------------------------
// (tooltype (prompt..) (help..) (dest..) (settooltype..) (setstack..)
//     (setdefaulttool..) (noposition) (confirm..) (safe))
//
//     modify an icon
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_tooltype(entry_p contxt)
{
    // Zero or more arguments / options.
    C_SANE(0, contxt);

    entry_p help            = opt(contxt, OPT_HELP),
            prompt          = opt(contxt, OPT_PROMPT),
            dest            = opt(contxt, OPT_DEST),
            settooltype     = opt(contxt, OPT_SETTOOLTYPE),
            setdefaulttool  = opt(contxt, OPT_SETDEFAULTTOOL),
            setstack        = opt(contxt, OPT_SETSTACK),
            noposition      = opt(contxt, OPT_NOPOSITION),
            setposition     = opt(contxt, OPT_SETPOSITION),
            confirm         = opt(contxt, OPT_CONFIRM);

    // Succeed immediately if non-safe in pretend mode.
    if(!opt(contxt, OPT_SAFE) && get_num(contxt, "@pretend"))
    {
        R_NUM(LG_TRUE);
    }

    D_NUM = LG_FALSE;

    // We need something to work with.
    if(!dest)
    {
        // We need an icon.
        ERR(ERR_MISSING_OPTION, "dest");
        R_NUM(LG_FALSE);
    }

    // Something is 'dest'.info
    char *file = str(dest);

    // The (noposition) and (setposition) options are mutually exclusive.
    if(noposition && setposition)
    {
        ERR(ERR_OPTION_MUTEX, "noposition/setposition");
        R_NUM(LG_FALSE);
    }

    // Get confirmation if necessary.
    if(!confirm || h_confirm(contxt, str(help), str(prompt)))
    {
        #if defined(AMIGA) && !defined(LG_TEST)
        // Get icon information.
        struct DiskObject *obj = (struct DiskObject *)
            GetDiskObject(file);

        if(obj)
        {
            // We need to save the current value of the tool type and default
            // tool members in order to not trash mem when free:ing diskobject.
            char *odt = obj->do_DefaultTool;
            char **tts = (char **) obj->do_ToolTypes;

            // If we're going to set tooltypes the option must have one or two
            // children.
            if(settooltype && c_sane(settooltype, 1))
            {
                // The number of tooltypes.
                size_t n = 0;

                // Get tooltype and current value (if it exists).
                char *t = str(settooltype->children[0]),
                     *o = FindToolType(obj->do_ToolTypes, t);

                // Get size of tooltype array.
                while(*(tts + n++));

                // Set value or create tooltype?
                if(settooltype->children[1] &&
                   settooltype->children[1] != end())
                {
                    // Resolve tooltype value.
                    const char *v = str(settooltype->children[1]);

                    // If it already exists, replace the old value with the new.
                    if(o)
                    {
                        // Allocate memory for a new temporary array.
                        obj->do_ToolTypes = DBG_ALLOC(calloc(n, sizeof(char *)));

                        if(obj->do_ToolTypes)
                        {
                            char **nts = (char **) obj->do_ToolTypes;

                            // Copy the current set of tooltypes.
                            memcpy(nts, tts, n  * sizeof(char **));

                            // Iterate over the current set.
                            while(*nts)
                            {
                                // Is the found value is within the bounds of the
                                // current string?
                                if(o >= *nts && o <= (*nts + strlen(*nts)))
                                {
                                    // Create either a new key -> value pair, or
                                    // a naked key.
                                    if(strlen(v))
                                    {
                                        // Tooltype with value.
                                        snprintf(get_buf(), buf_size(), "%s=%s", t, v);
                                    }
                                    else
                                    {
                                        // Naked tooltype.
                                        snprintf(get_buf(), buf_size(), "%s", t);
                                    }

                                    // Overwrite the old tooltype.
                                    *nts = get_buf();
                                    break;
                                }

                                // Next tooltype.
                                nts++;
                            }
                        }
                        else
                        {
                            // Out of memory.
                            PANIC(contxt);
                        }
                    }
                    // It doesn't exist, append new tooltype.
                    else
                    {
                        // Allocate memory for a new temporary array.
                        obj->do_ToolTypes = DBG_ALLOC(calloc(n + 1, sizeof(char *)));

                        if(obj->do_ToolTypes)
                        {
                            char **nts = (char **) obj->do_ToolTypes;

                            // Copy the current set of tooltypes.
                            memcpy(nts, tts, n * sizeof(char **));

                            if(strlen(v))
                            {
                                // Tooltype with value.
                                snprintf(get_buf(), buf_size(), "%s=%s", t, v);
                            }
                            else
                            {
                                // Naked tooltype.
                                snprintf(get_buf(), buf_size(), "%s", t);
                            }

                            // Append tooltype.
                            *(nts + n - 1) = get_buf();
                        }
                        else
                        {
                            // Out of memory.
                            PANIC(contxt);
                        }
                    }
                }
                // Delete tooltype.
                else
                {
                    // Is there anything to delete?
                    if(o && n > 1)
                    {
                        // Allocate memory for a new temporary array.
                        obj->do_ToolTypes = DBG_ALLOC(calloc(n, sizeof(char *)));

                        if(obj->do_ToolTypes)
                        {
                            char **nts = (char **) obj->do_ToolTypes,
                                 **ots = tts;

                            // Delete tooltype by copying everything except the
                            // tooltype to the new array.
                            while(*ots)
                            {
                                if((o < *ots) || (o > (*ots + strlen(*ots))))
                                {
                                    *nts = *ots;
                                    nts++;
                                }

                                ots++;
                            }
                        }
                        else
                        {
                            // Out of memory.
                            PANIC(contxt);
                        }
                    }
                }
            }

            // Change the default tool of project?
            if(setdefaulttool)
            {
                // Set temporary string.
                obj->do_DefaultTool = (char *) str(setdefaulttool);
            }

            // Set tool stacksize?
            if(setstack)
            {
                // Is a minimum value a good idea?
                obj->do_StackSize = num(setstack);
            }

            // Reset icon position?
            if(noposition)
            {
                obj->do_CurrentX = NO_ICON_POSITION;
                obj->do_CurrentY = NO_ICON_POSITION;
            }

            // Set icon position?
            if(setposition && c_sane(setposition, 2))
            {
                obj->do_CurrentX = num(setposition->children[0]);
                obj->do_CurrentY = num(setposition->children[1]);
            }

            // Save all changes to the .info file.
            if(PutDiskObject(file, obj))
            {
                // Done.
                D_NUM = LG_TRUE;
            }
            else
            {
                // We failed for some unknown reason.
                ERR(ERR_WRITE_FILE, file);
            }

            // Restore DiskObject, otherwise memory will be lost / trashed.
            // Refer to the icon.library documentation.

            // If we have a new tooltype array, free it and reinstate the old.
            if(tts != (char **) obj->do_ToolTypes)
            {
                free(obj->do_ToolTypes);
                obj->do_ToolTypes = (STRPTR *) tts;
            }

            // No need to free the current string, just overwrite what we have.
            obj->do_DefaultTool = odt;

            // Free the DiskObject after restoring it to the original state.
            FreeDiskObject(obj);
        }
        else
        {
            // More information? IoErr() is nice.
            ERR(ERR_READ_FILE, file);
        }
        #else
        // On non-Amiga systems we always succeed.
        D_NUM = LG_TRUE;

        // For testing purposes only.
        printf("%s%d%d%d", file, settooltype ? 1 : 0, setstack ? 1 : 0,
                setdefaulttool ? 1: 0);
        #endif
    }
    else
    {
        // The user did not confirm.
        D_NUM = LG_FALSE;
    }

    // Success or failure.
    R_CUR;
}

//------------------------------------------------------------------------------
// (transcript <string1> <string2>)
//     puts concatenated strings in log file
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_transcript(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, NULL);

    // Concatenate all children.
    char *msg = get_chlstr(contxt, false);

    // Make sure that we're not out of memory and that all children are valid.
    if((!msg && PANIC(contxt)) || DID_ERR)
    {
        free(msg);
        R_NUM(LG_FALSE);
    }

    // Write result to the log file.
    h_log(contxt, "%s\n", msg);

    // Free the temporary buffer and exit.
    free(msg);

    // h_log might fail silently.
    R_NUM(DID_ERR ? LG_FALSE : LG_TRUE);
}

//------------------------------------------------------------------------------
// (rename <old> <new> (help..) (prompt..) (confirm..) (safe))
//     rename files
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p m_rename(entry_p contxt)
{
    // Two or more arguments / options.
    C_SANE(2, C_ARG(3));

    entry_p help    = opt(C_ARG(3), OPT_HELP),
            prompt  = opt(C_ARG(3), OPT_PROMPT),
            confirm = opt(C_ARG(3), OPT_CONFIRM);

    // Old and new file name.
    const char *old = str(C_ARG(1)), *new = str(C_ARG(2));

    // If we need confirmation and the user skips or aborts, return. On abort,
    // HALT will be set by h_confirm.
    if(confirm && !h_confirm(C_ARG(3), str(help), str(prompt)))
    {
        R_NUM(LG_FALSE);
    }

    // Is this a safe operation or are we not running in pretend mode?
    if(!opt(C_ARG(3), OPT_SAFE) && get_num(contxt, "@pretend"))
    {
        R_NUM(-1);
    }

    // Are we going to rename a file/dir?
    if(!opt(C_ARG(3), OPT_DISK))
    {
        // Rename if target doesn't exist.
        if(h_exists(new) == LG_NONE && !rename(old, new))
        {
            // Success.
            h_log(contxt, tr(S_FRND), old, new);
            R_NUM(-1);
        }

        // Fail if target exists.
        ERR(ERR_RENAME_FILE, old);
        R_NUM(LG_FALSE);
    }

    // No, we're going to relabel a volume.
    #if defined(AMIGA) && !defined(LG_TEST)
    // Rename volume.
    if(!Relabel(old, new))
    {
        // Failure.
        R_NUM(LG_FALSE);
    }
    #endif

    // Successfully relabeled volume.
    h_log(contxt, tr(S_FRND), old, new);
    R_NUM(-1);
}

//------------------------------------------------------------------------------
// Name:        h_log
// Description: Write formatted message to log file.
// Input:       entry_p contxt:     The execution context.
//              const char *fmt:    Message format string.
//              ...:                Format string varargs.
// Return:      -
//------------------------------------------------------------------------------
void h_log(entry_p contxt, const char *fmt, ...)
{
    if((!contxt || !fmt) && PANIC(contxt))
    {
        // Bad input.
        return;
    }

    if(!get_num(contxt, "@log"))
    {
        // Logging is disabled.
        return;
    }

    // Use the log file set in init(..) or by the user.
    FILE *file = fopen(get_str(contxt, "@log-file"), "a");
    int cnt = -1;

    if(file)
    {
        // Line number and function name as prefix.
        cnt = fprintf(file, "[%d:%s] ", contxt->id, contxt->name);

        // Append formatted string.
        if(cnt > 0)
        {
            // Use whatever format and arguments we get
            va_list arg;

            va_start(arg, fmt);
            cnt = vfprintf(file, fmt, arg);
            va_end(arg);
        }

        // Done.
        fclose(file);
    }

    // Could we open the file AND write all data to it?
    if(cnt < 0)
    {
        ERR(ERR_WRITE_FILE, get_str(contxt, "@log-file"));
    }
}
