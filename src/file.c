//------------------------------------------------------------------------------
// file.c:
//
// File operations
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "debug.h"
#include "error.h"
#include "eval.h"
#include "file.h"
#include "gui.h"
#include "probe.h"
#include "resource.h"
#include "strop.h"
#include "util.h"
#include <ctype.h>
#include <dirent.h>
#include <limits.h>
#include <stdarg.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#if defined(__MINGW32__)
#define mkdir(a, b) mkdir(a)
#endif

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
entry_p n_expandpath(entry_p contxt)
{
    // One argument and no options.
    C_SANE(1, NULL);

    // Short path. No need to check for ERR.
    char *pth = str(C_ARG(1));

    #if defined(AMIGA) && !defined(LG_TEST)
    // Lock whatever resource the argument corresponds to.
    BPTR lock = (BPTR) Lock(pth, ACCESS_READ);

    if(lock)
    {
        // Get full name from lock.
        if(NameFromLock(lock, buf_get(B_KEY), buf_len()))
        {
            UnLock(lock);
            R_STR(DBG_ALLOC(strdup(buf_put(B_KEY))));
        }

        // Buffer overflow.
        ERR(ERR_OVERFLOW, buf_put(B_KEY));
        UnLock(lock);
    }

    // Empty string fallback.
    R_EST;
    #else
    // Testing only.
    R_STR(DBG_ALLOC(strdup(pth)));
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

    // Get confirmation unless @yes, @skip or @abort are set.
    if(grc == G_EXIT)
    {
        va_list ap;

        // Format messsage string.
        va_start(ap, msg);
        vsnprintf(buf_get(B_KEY), buf_len(), msg, ap);
        va_end(ap);

        entry_p back = opt(contxt, OPT_BACK);
        grc = gui_confirm(buf_put(B_KEY), hlp, back != false);

        // If (back) exists, execute body on user / fake abort.
        if(back && (grc == G_ABORT || get_num(contxt, "@back")))
        {
            grc = resolve(back) ? G_TRUE : G_ERR;
        }
    }

    // Translate response.
    return (grc == G_TRUE) || ((grc == G_ABORT || grc == G_EXIT) && HALT);
}

#if defined(AMIGA)
//------------------------------------------------------------------------------
// Name:        h_exists_amiga_type
// Description: h_exists amiga implementation.
// Input:       const char *name:   Path to file / dir.
// Return:      int32_t:            LG_NONE/LG_FILE/LG_DIR
//------------------------------------------------------------------------------
static int32_t h_exists_amiga_type(const char *name)
{
    struct FileInfoBlock *fib = (struct FileInfoBlock *)
           AllocDosObject(DOS_FIB, NULL);

    if(!fib && PANIC(NULL))
    {
        return LG_NONE;
    }

    // Attempt to lock file or directory.
    BPTR lock = (BPTR) Lock(name, ACCESS_READ);
    int32_t type = LG_NONE;

    // Get information from lock.
    if(lock && Examine(lock, fib))
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

    // Release lock to file, directory or nothing.
    UnLock(lock);

    FreeDosObject(DOS_FIB, fib);
    return type;
}
#else
//------------------------------------------------------------------------------
// Name:        h_exists_posix_type
// Description: h_exists posix implementation.
// Input:       const char *name:   Path to file / dir.
// Return:      int32_t:            LG_NONE/LG_FILE/LG_DIR
//------------------------------------------------------------------------------
static int32_t h_exists_posix_type(const char *name)
{
    struct stat fst;

    if(stat(name, &fst))
    {
        // No such file or directory.
        return LG_NONE;
    }

    // A file, a directory or something else.
    bool file = S_ISREG(fst.st_mode), dir = S_ISDIR(fst.st_mode);

    // Translate to Installer return values.
    return file ? LG_FILE : dir ? LG_DIR : LG_NONE;
}
#endif

//------------------------------------------------------------------------------
// Name:        h_exists
// Description: Get file / dir info. Return value according to the CBM Installer
//              documentation.
// Input:       entry_p contxt:     The execution context.
//              const char *name:   Path to file / dir.
// Return:      int32_t:            LG_NONE/LG_FILE/LG_DIR
//------------------------------------------------------------------------------
int32_t h_exists(const char *name)
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

    #if defined(AMIGA)
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
static char *h_suffix(const char *stem, const char *suffix)
{
    // Don't trust the input.
    if(!stem || !suffix)
    {
        return "";
    }

    // Copy file or directory stem.
    strncpy(buf_get(B_KEY), stem, buf_len());
    size_t len = strlen(buf_get(B_KEY));

    // Chomp trailing slashes if any.
    while(len && *(buf_get(B_KEY) + len - 1) == '/')
    {
        len--;
    }

    // Don't append to devices or empty strings.
    if(!len || *(buf_get(B_KEY) + len - 1) == ':')
    {
        *buf_get(B_KEY) = '\0';
        return buf_put(B_KEY);
    }

    // If suffix is empty, return chomp:ed stem.
    if(*suffix == '\0')
    {
        *(buf_get(B_KEY) + len) = '\0';
        return buf_put(B_KEY);
    }

    // Append suffix to chomp:ed stem.
    snprintf(buf_get(B_KEY) + len, buf_len() - len, ".%s", suffix);
    return buf_put(B_KEY);
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

    // Save type of the result, it might not be the same as the non suffixed
    // entry (e.g mydir -> mydir.info).
    int32_t type = h_exists(h_suffix(node->name, suffix));

    // Make sure that the source file / directory exists and that both source
    // and destination file / directories are valid as prefixes. They must be
    // non empty strings and volume names aren't allowed (e.g Work:.info).
    if(type == LG_NONE || !*h_suffix(node->copy, suffix) ||
       !*h_suffix(node->name, suffix))
    {
        return node;
    }

    // New list tail.
    pnode_p tail = node;

    // It's not necessary to check the return value.
    tail->next = DBG_ALLOC(calloc(1, sizeof(struct pnode_t)));

    if(!tail->next && PANIC(contxt))
    {
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
// Name:        h_filetree
// Description: Decl. needed by h_choices(). See description further down.
//------------------------------------------------------------------------------
static pnode_p h_filetree(entry_p contxt, const char *srt, const char *src,
                          const char *dst, entry_p files, entry_p fonts,
                          entry_p choices, entry_p pattern, entry_p infos);

//------------------------------------------------------------------------------
// Name:        h_choices
// Description: Helper for h_filetree handling (choices). Generating a complete
//              file / directory tree with source and destination tuples.
// Input:       entry_p contxt:     The execution context.
//              entry_p choices:    * List of files.
//              entry_p fonts:      * Include fonts.
//              entry_p infos:      * Include icons.
//                                  * Refer to the Installer.guide.
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
        node->name = DBG_ALLOC(h_tackon(contxt, src, f_nam));
        node->copy = h_tackon(contxt, dst, h_fileonly(contxt, f_nam));
        node->type = h_exists(node->name);

        // Next file.
        chl++;

        // Make sure that the file / dir exists. But only in strict mode,
        // otherwise just go on, missing files will be skipped during file
        // copy anyway.
        if(node->type == LG_NONE && get_num(contxt, "@strict") &&
          !opt(contxt, OPT_NOFAIL))
        {
            // File or directory doesn't exist.
            ERR(ERR_NO_SUCH_FILE_OR_DIR, node->name);
            return head;
        }

        int32_t type = node->type;
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
                contxt, src, name, copy, NULL, NULL, NULL, NULL, NULL
            );

            // Fast forward to the end of the list.
            while(node->next)
            {
                node = node->next;
            }
        }

        // If there are more files, allocate memory for the next node.
        if(exists(*chl))
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
//              destination tuples. Used by n_copyfiles.
// Input:       entry_p contxt:     The execution context.
//              const char *srt:    Source root.
//              const char *src:    Source directory / file.
//              const char *dst:    Destination directory.
//              entry_p files:      * Files only.
//              entry_p fonts:      * Skip fonts.
//              entry_p choices:    * List of files.
//              entry_p pattern:    * File / dir pattern.
//              entry_p infos:      * Include icons (choices).
//                                  * Refer to the Installer.guide.
// Return:      entry_p:            A linked list of file and dir pairs.
//------------------------------------------------------------------------------
static pnode_p h_filetree(entry_p contxt, const char *srt, const char *src,
                          const char *dst, entry_p files, entry_p fonts,
                          entry_p choices, entry_p pattern, entry_p infos)
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

    int32_t type = h_exists(src);

    if(type == LG_NONE)
    {
        if(!opt(contxt, OPT_NOFAIL))
        {
            // We shouldn't ignore this failure.
            ERR(ERR_NO_SUCH_FILE_OR_DIR, src);
        }

        // It's neither a directory or a file.
        return NULL;
    }

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
            node->type = LG_DIR;

            // Create .info node if necessary. No need to check node pointer.
            // Bounce and PANIC in h_suffix_append.
            node = infos ? h_suffix_append(contxt, node, "info") : node;

            // Iterate over all entries in the source directory.
            while(entry)
            {
                // Create the source destination tuple
                n_src = h_tackon(contxt, src, entry->d_name),
                n_dst = DBG_ALLOC(h_tackon(contxt, dst, entry->d_name));

                // Out of memory?
                if(!n_src || !n_dst)
                {
                    free(n_src);
                    free(n_dst);
                    break;
                }

                if(pattern)
                {
                    // Create full pattern temp buffer.
                    char *pat = h_tackon(contxt, srt, str(pattern));

                    // Out of memory?
                    if(!pat)
                    {
                        free(n_src);
                        free(n_dst);
                        break;
                    }

                    #if defined(AMIGA) && !defined(LG_TEST)
                    // The CBM implementation restricts pattern length to 64.
                    // MatchPattern() can use a lot of stack if patterns are
                    // long. To preserve stack, keep the static pattern size
                    // but increase it to whatever buf_len() is.
                    LONG w = ParsePatternNoCase(pat, buf_get(B_KEY), buf_len());

                    // Use string comparison if we don't have any wildcards.
                    if(w == 0 && strcasecmp(pat, n_src) == 0)
                    {
                        // Get type of match.
                        type = h_exists(n_src);
                    }
                    // Use pattern matching if we have any wildcards.
                    else if(w > 0 && MatchPatternNoCase(buf_get(B_KEY), n_src))
                    {
                        // Get type of match.
                        type = h_exists(n_src);
                    }
                    else
                    {
                        // Not a match.
                        type = LG_NONE;
                    }
                    #else
                    // Get rid of warning and increase test coverage.
                    snprintf(buf_get(B_KEY), buf_len(), "%s:%s", srt, n_src);
                    type = h_exists(n_src);
                    #endif

                    // Unlock buffer and release full pattern temp.
                    buf_put(B_KEY);
                    free(pat);
                }
                else
                {
                    // File or directory?
                    type = h_exists(n_src);
                }

                // Recur if we have a directory.
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
                        // Keep track of recursion depth.
                        static size_t dep;

                        if(dep++ < LG_MAXDEP)
                        {
                            // Get subdirectory tree. Don't promote (choices),
                            // dirs will be considered files.
                            node->next = h_filetree(contxt, srt, n_src, n_dst,
                                                    files, fonts, NULL, pattern,
                                                    NULL);
                            dep--;

                            // Fast forward to the end of the list.
                            while(node->next)
                            {
                                node = node->next;
                            }
                        }
                        else
                        {
                            // This is not a realistic path.
                            ERR(ERR_MAX_DEPTH, contxt->name);
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

                    // Font file = name + .font.
                    snprintf(buf_get(B_KEY), buf_len(), "%s.font", n_src);

                    if(h_exists(buf_get(B_KEY)) == LG_FILE)
                    {
                        pnode_p font = DBG_ALLOC(calloc(1, sizeof(struct pnode_t)));

                        if(font)
                        {
                            font->name = DBG_ALLOC(strdup(buf_get(B_KEY)));
                            font->copy = h_tackon(contxt, dst,
                                         h_fileonly(contxt, buf_get(B_KEY)));

                            // Add the font to the list.
                            if(font->name && font->copy)
                            {
                                font->type = LG_FILE;
                                file->next = font;

                                // Unlock before return.
                                buf_put(B_KEY);

                                // The list is complete.
                                return head;
                            }

                            free(font->name);
                            free(font->copy);
                            free(font);
                        }
                    }

                    // Name no longer needed.
                    buf_put(B_KEY);
                }

                free(head->name);
                free(head->copy);
            }
        }

        free(head);
        free(file);
    }

    PANIC(contxt);

    // These will leak if we don't free them.
    free(n_src);
    free(n_dst);

    return NULL;
}

//------------------------------------------------------------------------------
// We don't care about the distinction between root, group and user since that
// doesn't matter on Amiga.
//------------------------------------------------------------------------------
#define POSIX_READ_MASK (S_IRUSR | S_IRGRP | S_IROTH)
#define POSIX_WRITE_MASK (S_IWUSR | S_IWGRP | S_IWOTH)
#define POSIX_EXEC_MASK (S_IXUSR | S_IXGRP | S_IXOTH)
#define POSIX_RWX_MASK (POSIX_READ_MASK | POSIX_WRITE_MASK | POSIX_EXEC_MASK)

//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
#define READ_MASK   (1 << 3)
#define WRITE_MASK  (1 << 2)
#define EXEC_MASK   (1 << 1)
#define DELETE_MASK (1 << 0)

//------------------------------------------------------------------------------
// Name:        h_perm_amiga_to_posix
// Description: Convert Amiga file permissions to POSIX file permissions.
// Input:       int32_t amiga:     Amiga file permission mask.
// Return:      mode_t:            POSIX file permission mask.
//------------------------------------------------------------------------------
static inline mode_t h_perm_amiga_to_posix(int32_t amiga)
{
    bool read = (amiga & READ_MASK) == 0, write = (amiga & WRITE_MASK) == 0,
         exec = (amiga & EXEC_MASK) == 0;

    // Always reset the delete flag since that's not a POSIX feature.
    return (read ? POSIX_READ_MASK : 0) | (write ? POSIX_WRITE_MASK : 0) |
           (exec ? POSIX_EXEC_MASK : 0) | DELETE_MASK;
}

//------------------------------------------------------------------------------
// Name:        h_perm_posix_to_amiga
// Description: Convert POSIX file permissions to Amiga file permissions.
// Input:       mode_t posix:      POSIX file permission mask.
// Return:      int32_t:           Amiga file permission mask.
//------------------------------------------------------------------------------
static inline int32_t h_perm_posix_to_amiga(mode_t posix)
{
    bool read = posix & POSIX_READ_MASK, write = posix & POSIX_WRITE_MASK,
         exec = posix & POSIX_EXEC_MASK;

    // On Amiga '0' == enabled, see above.
    return (read ? 0 : READ_MASK) | (write ? 0 : WRITE_MASK) |
           (exec ? 0 : EXEC_MASK ) | DELETE_MASK;
}

#if defined(AMIGA)
//------------------------------------------------------------------------------
// Name:        h_protect_get_amiga
// Description: Used by h_protect_get to get file / dir protection bits. Amiga
//              implementation supporting delete protection.
// Input:       entry_p contxt:     The execution context.
//              const char *file:   File / dir.
//              int32_t *mask:      Pointer to the result.
// Return:      int32_t:            LG_TRUE / LG_FALSE.
//------------------------------------------------------------------------------
static int32_t h_protect_get_amiga(entry_p contxt, const char *file,
                                   int32_t *mask)
{
    struct FileInfoBlock *fib = (struct FileInfoBlock *)
           AllocDosObject(DOS_FIB, NULL);

    if(*file == '\0' || (!fib && PANIC(contxt)))
    {
        return LG_FALSE;
    }

    // Attempt to lock file / directory.
    BPTR lock = (BPTR) Lock(file, ACCESS_READ);

    // Fill up FIB. Filter out non-POSIX flags in test mode.
    if(lock && Examine(lock, fib))
    {
        #ifdef LG_TEST
        *mask = (fib->fib_Protection & 0xff) | 0x01;
        #else
        *mask = fib->fib_Protection;
        #endif

        // Release lock and free FIB.
        FreeDosObject(DOS_FIB, fib);
        UnLock(lock);

        return LG_TRUE;
    }

    // Release lock and free FIB.
    FreeDosObject(DOS_FIB, fib);
    UnLock(lock);

    // Only fail if we're in 'strict' mode (and not in test mode).
    #ifndef LG_TEST
    if(get_num(contxt, "@strict"))
    {
        ERR(ERR_GET_PERM, file);
        *mask = -1;
    }
    else
    #endif
    {
        // Fallback to RWED.
        *mask = 0;
    }

    return LG_FALSE;
}
#else
//------------------------------------------------------------------------------
// Name:        h_protect_get_posix
// Description: Used by h_protect_get to get file / dir protection bits. POSIX
//              implementation without delete protection support.
// Input:       const char *file:   File / dir.
//              int32_t *mask:      Pointer to the result.
// Return:      int32_t:            LG_TRUE / LG_FALSE.
//------------------------------------------------------------------------------
static int32_t h_protect_get_posix(const char *file, int32_t *mask)
{
    struct stat fst;

    // Get POSIX file / dir permission.
    if(stat(file, &fst))
    {
        // Could not get file / dir permission.
        return LG_FALSE;
    }

    // Report permissions in Amiga format.
    *mask = h_perm_posix_to_amiga(fst.st_mode);

    return LG_TRUE;
}
#endif

//------------------------------------------------------------------------------
// Name:        h_protect_get
// Description: Utility function used by n_protect and n_copyfiles to get file /
//              dir protection bits.
// Input:       entry_p contxt:     The execution context.
//              const char *file:   File / dir.
//              int32_t *mask:      Pointer to the result.
// Return:      int32_t:            LG_TRUE / LG_FALSE.
//------------------------------------------------------------------------------
static int32_t h_protect_get(entry_p contxt, const char *file, int32_t *mask)
{
    if((!contxt || !mask || !file) && PANIC(contxt))
    {
        // Bad input.
        return LG_FALSE;
    }

    // Delete protection support only on Amiga.
    #if defined(AMIGA)
    return h_protect_get_amiga(contxt, file, mask);
    #else
    return h_protect_get_posix(file, mask);
    #endif
}

//------------------------------------------------------------------------------
// Name:        h_protect_set
// Description: Utility function used by n_protect and n_copyfiles to set file /
//              dir protection bits.
// Input:       entry_p contxt:     The execution context.
//              const char *file:   File / dir.
//              int32_t mask:       Protection bits
// Return:      int32_t:            LG_TRUE / LG_FALSE.
//------------------------------------------------------------------------------
static int32_t h_protect_set(entry_p contxt, const char *file, int32_t mask)
{
    if((!contxt || !file) && PANIC(contxt))
    {
        // Bad input.
        return LG_FALSE;
    }

    // On non Amiga systems, or in test mode, this is a stub.
    #if defined(AMIGA)
    size_t len = strlen(file);

    // Filter out volumes.
    if(len && file[len - 1] != ':')
    {
        // Only fail if we're in 'strict' mode (and not in test mode).
        #ifndef LG_TEST
        if(!SetProtection(file, mask) && get_num(contxt, "@strict"))
        {
            ERR(ERR_SET_PERM, file);
            return LG_FALSE;
        }
        #else
        // Disable delete protection in test mode otherwise rm will fail.
        (void) SetProtection(file, mask | 0x01);
        #endif
    }
    #else
    chmod(file, h_perm_amiga_to_posix(mask));
    #endif

    return LG_TRUE;
}

//------------------------------------------------------------------------------
// Name:        h_copyfile_reset
// Description: Reset icon position.
// Input:       char *name: File / directory name.
// Return:      inp_t:      G_TRUE / G_FALSE.
//------------------------------------------------------------------------------
static inp_t h_copyfile_reset(char *name)
{
    inp_t grc = G_TRUE;

    #if defined(AMIGA) && !defined(LG_TEST)
    // Read from icon, .info suffix should'nt be there.
    struct DiskObject *obj = (struct DiskObject *) GetDiskObject(name);

    if(obj)
    {
        // Reset icon position.
        obj->do_CurrentX = NO_ICON_POSITION;
        obj->do_CurrentY = NO_ICON_POSITION;

        // Save changes to the .info file.
        if(!PutDiskObject(name, obj))
        {
            grc = G_FALSE;
        }

        FreeDiskObject(obj);
    }
    #else
    printf("R:%s\n", name);
    #endif

    return grc;
}

//------------------------------------------------------------------------------
// Name:        h_copyfile
// Description: Copy file. Helper used by n_copyfiles and n_copylib.
// Input:       entry_p contxt:     The execution context.
//              char *src:          Source file.
//              char *dst:          Destination file.
//              bool bck:           Enable back mode.
//              bool sln:           Silent mode.
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
static inp_t h_copyfile(entry_p contxt, char *src, char *dst, bool bck, bool sln)
{
    if((!contxt || !src || !dst) && PANIC(contxt))
    {
        // Bad input.
        return G_ERR;
    }

    // GUI return code.
    inp_t grc = G_TRUE;

    // Show GUI unless we're in silent mode.
    if(!sln)
    {
        grc = gui_copyfiles_setcur(src, opt(contxt, OPT_NOGAUGE) != NULL, bck);
    }

    // Prepare GUI unless we're in silent mode as used by copylib.
    if((grc != G_TRUE) && HALT)
    {
        h_log(contxt, tr(S_ACPY), src, dst);
        return grc;
    }

    static char buf[BUFSIZ];
    FILE *file = h_fopen(contxt, src, "r", false);
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
            h_fclose(&file);
        }

        if(opt(contxt, OPT_NOFAIL))
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
        if(opt(contxt, OPT_FORCE) && !opt(contxt, OPT_ASKUSER))
        {
            // Unprotect file.
            chmod(dst, POSIX_RWX_MASK);
        }
        else
        // Confirm if (askuser) unless we're running in novice mode and (force)
        // at the same time.
        if(opt(contxt, OPT_ASKUSER) && (opt(contxt, OPT_FORCE) ||
           get_num(contxt, "@user-level") != LG_NOVICE))
        {
            if(h_confirm(contxt, "", tr(S_OWRT), dst))
            {
                // Unprotect file.
                chmod(dst, POSIX_RWX_MASK);
            }
            else
            {
                // Skip file or abort.
                h_fclose(&file);
                return DID_HALT ? G_ABORT : G_TRUE;
            }
        }
    }

    // Create / overwrite file.
    FILE *dest = h_fopen(contxt, dst, "w", false);

    if(!dest)
    {
        // The source handle is open.
        h_fclose(&file);

        if(opt(contxt, OPT_NOFAIL) || opt(contxt, OPT_OKNODELETE))
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
            if(!sln)
            {
                grc = gui_copyfiles_setcur(NULL, opt(contxt, OPT_NOGAUGE) != NULL, bck);
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
            if(opt(contxt, OPT_NOFAIL) || opt(contxt, OPT_OKNODELETE))
            {
                // Ignore failure.
                h_log(contxt, tr(S_NCPY), src, dst);
                grc = G_TRUE;
            }
            else
            {
                ERR(ERR_WRITE_FILE, dst);
                grc = G_FALSE;
            }
            break;
        }
    }

    // Close input and output files.
    h_fclose(&file);
    h_fclose(&dest);

    // The number of bytes read and not written should be zero.
    if(cnt)
    {
        // Reported / ignored error or user abort.
        return grc;
    }

    // Write to the log file (if logging is enabled).
    h_log(contxt, tr(S_CPYD), src, dst);

    // Are we going to copy the icon as well?
    if(opt(contxt, OPT_INFOS))
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

            // Recur to copy icon. If info.[...].info exist, they will all be
            // copied as well.
            grc = h_copyfile(contxt, icon, copy, bck, sln);

            // Reset icon position?
            if(grc == G_TRUE && opt(contxt, OPT_NOPOSITION))
            {
                grc = h_copyfile_reset(dst);
            }
        }
    }

    // Try to preserve file permissions.
    int32_t prm = 0;

    if(h_protect_get(contxt, src, &prm))
    {
        h_protect_set(contxt, dst, prm);
    }

    // Reset error codes if necessary.
    if(DID_ERR)
    {
        if(opt(contxt, OPT_NOFAIL))
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
    if(!dst && PANIC(contxt))
    {
        return false;
    }

    // Don't overwrite existing icons.
    if(h_exists(h_suffix(dst, "info")) == LG_FILE)
    {
        return true;
    }

    #if defined(AMIGA) && !defined(LG_TEST)
    // Get the default drawer icon from the OS.
    struct DiskObject *obj = (struct DiskObject *) GetDefDiskObject(WBDRAWER);
    #else
    FILE *obj = h_fopen(contxt, h_suffix(dst, "info"), "w", true);
    #endif

    // Bail out if we can't open the default icon.
    if(!obj)
    {
        return false;
    }

    // Save default icon if we have one.
    #if defined(AMIGA) && !defined(LG_TEST)
    // Create new .info.
    bool done = PutDiskObject(h_suffix(dst, ""), obj);
    #else
    bool done = fputs("icon", obj) != EOF;
    #endif

    #if defined(AMIGA) && !defined(LG_TEST)
    // Free def. icon.
    FreeDiskObject(obj);
    #else
    h_fclose(&obj);
    #endif

    // Success or I/O error.
    return done;
}

//------------------------------------------------------------------------------
// Name:        h_makedir_path
// Description: Create directory and all its parent directories.
// Input:       char *dst:          Directory to be created.
// Return:      bool:               'true' on succes, 'false' otherwise.
//------------------------------------------------------------------------------
static bool h_makedir_path(char *dst)
{
    if(h_exists(dst) == LG_DIR)
    {
        // Nothing to do,
        return true;
    }

    // Create working copy.
    char *buf = buf_get(B_KEY);
    strncpy(buf, dst, buf_len());

    // Create all directories one by one.
    for(size_t ndx = 0; buf[ndx]; ndx++)
    {
        // Find separator or end of string.
        if(buf[ndx] == '/')
        {
            // Terminate string.
            buf[ndx] = '\0';

            // Create directory if it doesn't exist.
            if(h_exists(buf) == LG_NONE && mkdir(buf, 0777))
            {
                buf_put(B_KEY);
                return false;
            }

            // Reinstate separator.
            buf[ndx] = '/';
        }
    }

    // Unlock buffer.
    buf_put(B_KEY);

    // The path as a whole exists or the final directory needs to be created.
    return h_exists(dst) == LG_DIR || !mkdir(dst, 0777);
}

//------------------------------------------------------------------------------
// Name:        h_makedir
// Description: Create directory / icon / tree of directories.
// Input:       entry_p contxt:     The execution context.
//              char *dst:          The directory.
// Return:      bool:               'true' on succes, 'false' otherwise.
//------------------------------------------------------------------------------
static bool h_makedir(entry_p contxt, char *dst)
{
    if(!dst && PANIC(contxt))
    {
        return false;
    }

    // Make full path if it doesn't exist.
    if(!h_makedir_path(dst))
    {
        return false;
    }

    // Create icon if (infos) is set. Ignore errors.
    if(opt(contxt, OPT_INFOS))
    {
        h_makedir_create_icon(contxt, dst);
    }

    return true;
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
entry_p n_copyfiles(entry_p contxt)
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
            fonts      = opt(contxt, OPT_FONTS),
            back       = opt(contxt, OPT_BACK),
            fail       = opt(contxt, OPT_FAIL),
            nofail     = opt(contxt, OPT_NOFAIL),
            oknodelete = opt(contxt, OPT_OKNODELETE),
            files      = opt(contxt, OPT_FILES);

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
        // Path might be empty.
        size_t dln = strlen(dst);

        // If it's not a volume, set permissions to allow overwriting.
        if(dln && dst[dln - 1] != ':')
        {
            chmod(dst, POSIX_RWX_MASK);
        }
    }

    // Traverse source directory and create destination strings.
    pnode_p tree = h_filetree(contxt, src, src, dst, files, fonts, choices,
                              pattern, infos);

    if(!tree)
    {
        // I/O error or out of memory. Status set by h_filetree.
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

    // Return value.
    int32_t ret = LG_FALSE;

    // Start copy unless skip / abort / back.
    if(grc == G_TRUE)
    {
        // For all files / dirs in list, copy / create.
        for(; cur && grc == G_TRUE; cur = cur->next)
        {
            // Copy file / create dir / skip if non existing.
            if(cur->type == LG_FILE)
            {
                grc = h_copyfile(contxt, cur->name, cur->copy, back != false,
                                 false);
            }
            else if(cur->type == LG_DIR && !h_makedir(contxt, cur->copy))
            {
                ERR(ERR_WRITE_DIR, dst);
                grc = G_FALSE;
            }
        }

        // Translate return value.
        ret = (grc == G_TRUE) ? LG_TRUE : LG_FALSE;
    }

    // GUI teardown.
    gui_copyfiles_end();

    // Back return value.
    entry_p bck = NULL;

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
                bck = resolve(back);
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

    // Return resolved (back) if it exists.
    if(bck)
    {
        return bck;
    }

    // Success or failure.
    R_NUM(ret);
}

//------------------------------------------------------------------------------
// Name:        h_copylib_unknown_none
// Description: Prompt and copy without overwriting anything. Source version is
//              unknown. Options must be validated before calling this function.
//              Used by h_copylib_none.
//
// Prompt example:
//
// Version to install: Unknown version
// There is no currently installed version
//
// Input:       entry_p contxt:     The execution context.
//              char *src:          Source file.
//              char *dst:          Destination file.
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
static inp_t h_copylib_unknown_none(entry_p contxt, char *src, char *dst)
{
    if(!h_confirm(contxt, "", "%s\n\n%s: %s\n%s\n\n%s: %s",
       str(opt(contxt, OPT_PROMPT)), tr(S_VINS), tr(S_VUNK), tr(S_NINS),
       tr(S_DDRW), str(opt(contxt, OPT_DEST))))
    {
        // No confirmation.
        return G_FALSE;
    }

    // User confirmed. Go ahead and copy file.
    return h_copyfile(contxt, src, dst, false, true);
}

//------------------------------------------------------------------------------
// Name:        h_copylib_known_none
// Description: Prompt and copy without overwriting anything. Source version is
//              known. Options must be validated before calling this function.
//              Used by h_copylib_none.
//
// Prompt example:
//
// Version to install: 12.3
// There is no currently installed version
//
// Input:       entry_p contxt:     The execution context.
//              char *src:          Source file.
//              char *dst:          Destination file.
//              int32_t ver:        Source version.
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
static inp_t h_copylib_known_none(entry_p contxt, char *src, char *dst,
                                  int32_t ver)
{
    // Major and minor version.
    int32_t maj = ver >> 16, min = ver & 0xffff;

    if(!h_confirm(contxt, "", "%s\n\n%s: %d.%d\n%s\n\n%s: %s",
       str(opt(contxt, OPT_PROMPT)), tr(S_VINS), maj, min, tr(S_NINS),
       tr(S_DDRW), str(opt(contxt, OPT_DEST))))
    {
        // No confirmation.
        return G_FALSE;
    }

    // User confirmed. Go ahead and copy file.
    return h_copyfile(contxt, src, dst, false, true);
}

//------------------------------------------------------------------------------
// Name:        h_copylib_none
// Description: Prompt and copy without overwriting anything. Source version
//              can be either known or unknown. Options must be validated before
//              calling this function.
//
// Input:       entry_p contxt:     The execution context.
//              char *src:          Source file.
//              char *dst:          Destination file.
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
static inp_t h_copylib_none(entry_p contxt, char *src, char *dst)
{
    if(!opt(contxt, OPT_CONFIRM))
    {
        // No confirmation needed.
        return h_copyfile(contxt, src, dst, false, true);
    }

    // Get source file version.
    int32_t ver = h_getversion_file(src);

    if(ver == LG_NOVER)
    {
        // Unknown source version.
        return h_copylib_unknown_none(contxt, src, dst);
    }

    // Source version is known.
    return h_copylib_known_none(contxt, src, dst, ver);
}

//------------------------------------------------------------------------------
// Name:        h_copylib_unknown_unknown
// Description: Prompt and copy with file overwrite. Both destination and
//              source version are unknown. Options must be validated before
//              calling this function.
//
// Prompt example:
//
// Version to install: Unknown version
// Version currently installed: Unknown version
//
// Input:       entry_p contxt:     The execution context.
//              char *src:          Source file.
//              char *dst:          Destination file.
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
static inp_t h_copylib_unknown_unknown(entry_p contxt, char *src, char *dst)
{
    if(!h_confirm(contxt, "", "%s\n\n%s: %s\n%s: %s\n\n%s: %s",
       str(opt(contxt, OPT_PROMPT)), tr(S_VINS), tr(S_VUNK), tr(S_VCUR),
       tr(S_VUNK), tr(S_DDRW), str(opt(contxt, OPT_DEST))))
    {
        // No confirmation.
        return G_FALSE;
    }

    // User confirmed. Go ahead and copy file.
    return h_copyfile(contxt, src, dst, false, true);
}

//------------------------------------------------------------------------------
// Name:        h_copylib_unknown_known
// Description: Prompt and copy with file overwrite. Destination version is
//              known but source version is unknown. Options must be validated
//              before calling this function.
//
// Prompt example:
//
// Version to install: Unknown version
// Version currently installed: 12.3
//
// Input:       entry_p contxt:     The execution context.
//              char *src:          Source file.
//              char *dst:          Destination file.
//              int32_t ver:        Destination file version.
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
static inp_t h_copylib_unknown_known(entry_p contxt, char *src, char *dst,
                                     int32_t ver)
{
    // Destination major and minor version.
    int32_t maj = ver >> 16, min = ver & 0xffff;

    if(!h_confirm(contxt, "", "%s\n\n%s: %s\n%s: %d.%d\n\n%s: %s",
       str(opt(contxt, OPT_PROMPT)), tr(S_VINS), tr(S_VUNK), tr(S_VCUR),
       maj, min, tr(S_DDRW), str(opt(contxt, OPT_DEST))))
    {
        // No confirmation.
        return G_FALSE;
    }

    // User confirmed. Go ahead and copy file.
    return h_copyfile(contxt, src, dst, false, true);
}

//------------------------------------------------------------------------------
// Name:        h_copylib_known_unknown
// Description: Prompt and copy with file overwrite. Source version is known but
//              destination version is unknown. Options must be validated before
//              calling this function.
//
// Prompt example:
//
// Version to install: 12.3
// Version currently installed: Unknown version
//
// Input:       entry_p contxt:     The execution context.
//              char *src:          Source file.
//              char *dst:          Destination file.
//              int32_t ver:        Source file version.
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
static inp_t h_copylib_known_unknown(entry_p contxt, char *src, char *dst,
                                     int32_t ver)
{
    // Source major and minor version.
    int32_t maj = ver >> 16, min = ver & 0xffff;

    if(!h_confirm(contxt, "", "%s\n\n%s: %d.%d\n%s: %s\n\n%s: %s",
       str(opt(contxt, OPT_PROMPT)), tr(S_VINS), maj, min, tr(S_VCUR),
       tr(S_VUNK), tr(S_DDRW), str(opt(contxt, OPT_DEST))))
    {
        // No confirmation.
        return G_FALSE;
    }

    // User confirmed. Go ahead and copy file.
    return h_copyfile(contxt, src, dst, false, true);
}

//------------------------------------------------------------------------------
// Name:        h_copylib_known_known
// Description: Prompt and copy with file overwrite. Source and destination
//              versions are known. Options must be validated before calling
//              this function.
//
// Prompt example:
//
// Version to install: 12.3
// Version currently installed: 45.6
//
// Input:       entry_p contxt:     The execution context.
//              char *src:          Source file.
//              char *dst:          Destination file.
//              int32_t old:        Source file version.
//              int32_t new:        Destination file version.
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
static inp_t h_copylib_known_known(entry_p contxt, char *src, char *dst,
                                   int32_t old, int32_t new)
{
    // Source and destination files major and minor versions.
    int32_t nmj = new >> 16, nmn = new & 0xffff, omj = old >> 16,
            omn = old & 0xffff;

    if(!h_confirm(contxt, "", "%s\n\n%s: %d.%d\n%s: %d.%d\n\n%s: %s",
       str(opt(contxt, OPT_PROMPT)), tr(S_VINS), nmj, nmn, tr(S_VCUR), omj, omn,
       tr(S_DDRW), str(opt(contxt, OPT_DEST))))
    {
        // No confirmation.
        return G_FALSE;
    }

    // User confirmed. Go ahead and copy file.
    return h_copyfile(contxt, src, dst, false, true);
}

//------------------------------------------------------------------------------
// Name:        h_copylib_file
// Description: Copy with file overwrite. Used by n_copylib. Options must be
//              validated before calling this function. If necessary user will
//              be prompted for confirmation.
// Input:       entry_p contxt:     The execution context.
//              char *src:          Source file.
//              char *dst:          Destination file.
//              int32_t ver:        Source file version.
// Return:      inp_t:              G_TRUE / G_FALSE / G_ABORT / G_ERR.
//------------------------------------------------------------------------------
static inp_t h_copylib_file(entry_p contxt, char *src, char *dst)
{
    // Get version of source and destination file.
    int32_t old = h_getversion_file(dst), new = h_getversion_file(src);

    if(!opt(contxt, OPT_CONFIRM))
    {
        // No confirmation. Copy file unless it's older than the destination.
        return new >= old ? h_copyfile(contxt, src, dst, false, true) : G_FALSE;
    }

    if(new == old && new == LG_NOVER)
    {
        // Both source and destination versions are unknown.
        return h_copylib_unknown_unknown(contxt, src, dst);
    }

    if(new == LG_NOVER)
    {
        // Destination version is known, source version is not.
        return h_copylib_unknown_known(contxt, src, dst, old);
    }

    if(old == LG_NOVER)
    {
        // Source version is known, destination version is not.
        return h_copylib_known_unknown(contxt, src, dst, new);
    }

    // Source and destination versions are known but differ.
    return h_copylib_known_known(contxt, src, dst, old, new);
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
entry_p n_copylib(entry_p contxt)
{
    // One or more arguments / options.
    C_SANE(1, contxt);

    entry_p prompt     = opt(contxt, OPT_PROMPT),
            help       = opt(contxt, OPT_HELP),
            source     = opt(contxt, OPT_SOURCE),
            dest       = opt(contxt, OPT_DEST),
            fail       = opt(contxt, OPT_FAIL),
            nofail     = opt(contxt, OPT_NOFAIL),
            oknodelete = opt(contxt, OPT_OKNODELETE);

    // The (fail) (nofail) and (oknodelete) options are mutually exclusive.
    if((fail && (nofail || oknodelete)) || (nofail && (fail || oknodelete)) ||
       (oknodelete && (nofail || fail)))
    {
        ERR(ERR_OPTION_MUTEX, "fail/nofail/oknodelete");
        R_NUM(LG_FALSE);
    }

    // We always need a prompt and help since trying to overwrite new files
    // with older ones will force a confirm if we're in expert mode. In sloppy
    // mode we'll always have them, but they will be empty if not provided. This
    // is how the CBM behaves, despite what the documentation says.
    if(!source || !dest || !prompt || !help)
    {
        ERR(ERR_MISSING_OPTION, source ? dest ? prompt ? "help" : "prompt" :
                                                         "dest" : "source");
        R_NUM(LG_FALSE);
    }

    char *src = str(source), *dst = str(dest);

    // Does the source file exist?
    if(h_exists(src) != LG_FILE)
    {
        // Only fail if we're in 'strict' mode.
        if(get_num(contxt, "@strict"))
        {
            ERR(ERR_NOT_A_FILE, src);
        }

        // Fail silently.
        R_NUM(LG_FALSE);
    }

    // Destination type.
    int32_t type = h_exists(dst);

    // A non safe operation in pretend mode always succeeds.
    if(!opt(contxt, OPT_SAFE) && get_num(contxt, "@pretend"))
    {
        R_NUM(LG_TRUE);
    }

    // Destination must be a directory.
    if(type == LG_FILE)
    {
        // Fail silently in sloppy mode.
        if(get_num(contxt, "@strict"))
        {
            ERR(ERR_NOT_A_DIR, dst);
        }

        // Nothing to do.
        R_NUM(LG_FALSE);
    }

    if(type == LG_NONE)
    {
        // Clang scan-build dead code false positive.
#ifndef __clang_analyzer__
        // Create non-existing directory.
        if(!h_makedir_path(dst))
        {
            // Permission problems.
            ERR(ERR_WRITE_DIR, dst);
            R_NUM(LG_FALSE);
        }
#endif
        // Log the success.
        h_log(contxt, tr(S_CRTD), dst);
    }

    // Destination file, old name and new path or new name and new path.
    char *name = opt(contxt, OPT_NEWNAME) ?
                 h_tackon(contxt, dst, str(opt(contxt, OPT_NEWNAME))) :
                 DBG_ALLOC(h_tackon(contxt, dst, h_fileonly(contxt, src)));

    if(!name && PANIC(contxt))
    {
        R_NUM(LG_FALSE);
    }

    // Get 'name' type info.
    type = h_exists(name);

    // There is no way to abort a file copy, but we need to handle the GUI
    // return values anyway.
    inp_t grc = G_FALSE;

    // Are we overwriting anything?
    if(type == LG_NONE)
    {
        // No we're not overwriting anything.
        grc = h_copylib_none(contxt, src, name);
    }
    else
    // It's a file.
    if(type == LG_FILE)
    {
        grc = h_copylib_file(contxt, src, name);
    }
    // It's a dir.
    else
    {
        // Dest file exists, but is a directory. Fail in strict mode.
        if(get_num(contxt, "@strict"))
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
// Name:        h_delete_info
// Description: Delete .info file. Helper used by h_delete_file.
// Input:       entry_p contxt:     The execution context.
//              const char *file:   File whose .info to delete.
// Return:      int32_t:            LG_TRUE / LG_FALSE.
//------------------------------------------------------------------------------
static int32_t h_delete_info(entry_p contxt, const char *file)
{
    // Do we have an .info file?
    char *info = h_suffix(file, "info");

    if(h_exists(info) == LG_FILE)
    {
        // Set write permission and delete file.
        mode_t perm = POSIX_WRITE_MASK;

        if(chmod(info, perm) || remove(info))
        {
            ERR(ERR_DELETE_FILE, info);
            return LG_FALSE;
        }

        // The info file has been deleted.
        h_log(contxt, tr(S_DLTD), info);
    }

    // Succeed if .info deleted or non existent.
    return LG_TRUE;
}

//------------------------------------------------------------------------------
// Name:        h_delete_perm
// Description: Check for file / dir delete permission.
// Input:       const char *name:   File / dir to check.
// Return:      bool:               'true' if deleteable, 'false' otherwise.
//------------------------------------------------------------------------------
static bool h_delete_perm(const char *name)
{
    #if defined(AMIGA) && !defined(LG_TEST)
    struct FileInfoBlock *fib = (struct FileInfoBlock *)
           AllocDosObject(DOS_FIB, NULL);

    if(!fib)
    {
        return false;
    }

    // Attempt to lock file or directory.
    BPTR lock = (BPTR) Lock(name, ACCESS_READ);
    bool perm = false;

    // Get information from lock.
    if(lock && Examine(lock, fib))
    {
        perm = (fib->fib_Protection & FIBF_DELETE) == 0;
    }

    // Release lock and free info block.
    UnLock(lock);
    FreeDosObject(DOS_FIB, fib);

    return perm;
    #else
    // Proper delete protection doesn't exist on non Amigas.
    return access(name, W_OK) == 0;
    #endif
}

//------------------------------------------------------------------------------
// Name:        h_delete_file
// Description: Delete file. Helper used by n_delete.
// Input:       entry_p contxt:     The execution context.
//              const char *file:   File to delete.
// Return:      int32_t:            LG_TRUE / LG_FALSE.
//------------------------------------------------------------------------------
static int32_t h_delete_file(entry_p contxt, const char *file)
{
    if(!file && PANIC(contxt))
    {
        // Bad input.
        return LG_FALSE;
    }

    // If (force) is used, give permissions so that delete can succeed.
    if(opt(contxt, OPT_FORCE))
    {
        chmod(file, POSIX_RWX_MASK);
    }
    else
    {
        if(!h_delete_perm(file))
        {
            if(!opt(contxt, OPT_ASKUSER))
            {
                // Fail silently just like the original.
                return LG_FALSE;
            }

            // Ask for confirmation if we're not running in novice mode.
            if(get_num(contxt, "@user-level") != LG_NOVICE &&
               h_confirm(contxt, "", tr(S_DWRT), file))
            {
                // Give permissions so that delete can succeed.
                chmod(file, POSIX_RWX_MASK);
            }
            else
            {
                // Halt is set by h_confirm. Skip will result in nothing.
                return LG_FALSE;
            }
        }
    }

    if(remove(file))
    {
        // Could not delete file.
        ERR(ERR_DELETE_FILE, file);
        return LG_FALSE;
    }

    // The file has been deleted.
    h_log(contxt, tr(S_DLTD), file);

    // Delete .info file or LG_TRUE.
    return opt(contxt, OPT_INFOS) ? h_delete_info(contxt, file) : LG_TRUE;
}

//------------------------------------------------------------------------------
// Name:        h_delete_dir
// Description: Delete directory. Helper used by n_delete.
// Input:       entry_p contxt:     The execution context.
//              const char *name:   Directory to delete.
// Return:      int32_t:            LG_TRUE / LG_FALSE.
//------------------------------------------------------------------------------
static int32_t h_delete_dir(entry_p contxt, const char *name)
{
    if(!name && PANIC(contxt))
    {
        // Bad input.
        return LG_FALSE;
    }

    entry_p infos    = opt(contxt, OPT_INFOS),
            force    = opt(contxt, OPT_FORCE),
            askuser  = opt(contxt, OPT_ASKUSER),
            all      = opt(contxt, OPT_ALL);

    if(!force && !h_delete_perm(name))
    {
        // Do we need to ask for confirmation?
        if(!askuser)
        {
            // Exit silently.
            return LG_FALSE;
        }

        // Ask for confirmation if we're not running in novice mode.
        if(get_num(contxt, "@user-level") == LG_NOVICE ||
           !h_confirm(contxt, "", tr(S_DWRD), name))
        {
            // Halt will be set by h_confirm. Skip will result in nothing.
            return LG_FALSE;
        }
    }

    // Give permissions so that delete can succeed. No need to check the return
    // value since errors will be caught below.
    chmod(name, POSIX_RWX_MASK);

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
    snprintf(buf_get(B_KEY), buf_len(), "%s.info", name);
    char *info = buf_put(B_KEY);

    // We're done if there's no icon.
    if(h_exists(info) != LG_FILE)
    {
        return LG_TRUE;
    }

    // Set permissions so that delete can succeed.
    chmod(info, POSIX_RWX_MASK);

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
// Description: Delete file / dir matching pattern. Helper used by n_delete.
// Input:       entry_p contxt:     The execution context.
//              const char *pat:    Pattern.
// Return:      int32_t:            LG_TRUE / LG_FALSE.
//------------------------------------------------------------------------------
static int32_t h_delete_pattern(entry_p contxt, const char *pat)
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
// Name:        h_delete
// Description: Delete file / dir.
// Input:       entry_p contxt:     The execution context.
//              const char *file:   The file / dir.
// Return:      int32_t:            LG_TRUE / LG_FALSE / ERR_PANIC.
//------------------------------------------------------------------------------
static int32_t h_delete(entry_p contxt, const char *file)
{
    switch(h_exists(file))
    {
        case LG_NONE:
            h_log(contxt, tr(S_NSFL), file);
            return LG_FALSE;

        case LG_FILE:
            return h_delete_file(contxt, file);

        case LG_DIR:
            return h_delete_dir(contxt, file);

        default:
            return PANIC(contxt);
    }
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
entry_p n_delete(entry_p contxt)
{
    // One argument and options.
    C_SANE(1, contxt);
    int32_t status = LG_TRUE;

    // Delete all files leading up to the first option
    for(size_t ndx = 1; NOT_ERR && exists(C_ARG(ndx)) &&
        C_ARG(ndx)->type != OPTION; ndx++)
    {
        char *file = str(C_ARG(ndx));

        #if defined(AMIGA) && !defined(LG_TEST)
        int wild = ParsePatternNoCase(file, buf_raw(), buf_len());
        #else
        int wild = get_num(contxt, "@wild");
        #endif

        // 0 == no pattern, 1 == pattern, -1 == buffer overflow.
        if(wild < 0)
        {
            ERR(ERR_OVERFLOW, file);
            R_NUM(LG_FALSE);
        }

        // Return on abort or if the user doesn't confirm when (confirm) is set.
        if(opt(contxt, OPT_CONFIRM) && !h_confirm(contxt,
           str(opt(contxt, OPT_HELP)), str(opt(contxt, OPT_PROMPT))))
        {
            R_NUM(LG_FALSE);
        }

        // Succeed immediately if non-safe in pretend mode.
        if(!opt(contxt, OPT_SAFE) && get_num(contxt, "@pretend"))
        {
            R_NUM(LG_TRUE);
        }

        // Delete verbatim or matching files.
        status = wild ? h_delete_pattern(contxt, file) :
                        h_delete(contxt, file);
    }

    // Success or failure.
    R_NUM(status);
}

//------------------------------------------------------------------------------
// (exists <filename> (noreq))
//     0 if no, 1 if file, 2 if dir
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_exists(entry_p contxt)
{
    // One argument and option.
    C_SANE(1, contxt);

    // Supress volume requester. Despite what the CBM documentation says,
    // requesters are always supressed. Let's follow the documentation in
    // strict mode and the implementation in sloppy mode.
    if(!get_num(contxt, "@strict") || opt(contxt, OPT_NOREQ) ||
        opt(contxt, OPT_QUIET))
    {
        #if defined(AMIGA) && !defined(LG_TEST)
        struct Process *p = (struct Process *) FindTask(NULL);

        // Save the current window ptr.
        APTR w = p->pr_WindowPtr;

        // Disable auto request.
        p->pr_WindowPtr = (APTR) -1L;
        #endif

        // Get type (file / dir / 0)
        int32_t res = h_exists(str(C_ARG(1)));

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
entry_p n_fileonly(entry_p contxt)
{
    // One argument and no options.
    C_SANE(1, NULL);

    // Implementation in helper function.
    R_STR(DBG_ALLOC(strdup(h_fileonly(contxt, str(C_ARG(1))))));
}

//------------------------------------------------------------------------------
// (foreach <dir> <pattern> <statements>)
//     do for entries in directory
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_foreach(entry_p contxt)
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
        char *cwd = buf_raw();
        struct dirent *ent = readdir(dir);

        // Save current working directory and enter the directory <drawer name>
        if(getcwd(cwd, buf_len()) == cwd && !chdir(dname))
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
                char *buf = buf_raw();

                // Parse pattern.
                switch(ParsePatternNoCase(pt, buf, buf_len()))
                {
                    // If we have any wildcards, try to match.
                    case 1:
                        skip = !MatchPatternNoCase(buf, top->name);
                        break;

                    // If no wildcards, do a simple string comparsion.
                    case 0:
                        skip = strcmp(top->name, pt);
                        break;

                    // Could not parse pattern.
                    default:
                        err = true;
                }
            }
            #endif

            // We always export, for memory management reasons.
            set_num(contxt, "@each-type", (int32_t) top->type);
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
entry_p n_makeassign(entry_p contxt)
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
    int32_t res = LG_FALSE;

    // Are we going to create an assign?
    if(exists(C_ARG(2)) && C_ARG(2)->type != OPTION)
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
        h_log(contxt,
        // Clang scan-build dead code true positive.
#ifndef __clang_analyzer__
              res ? tr(S_ACRT) :
#endif
              tr(S_ACRE), asn, dst);
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
        h_log(contxt,
        // Clang scan-build dead code true positive.
#ifndef __clang_analyzer__
              res ? tr(S_ADEL) :
#endif
              tr(S_ADLE), asn);
    }

    // Clang scan-build dead code true positive.
#ifndef __clang_analyzer__
    if(!res)
#endif
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
entry_p n_makedir(entry_p contxt)
{
    // One argument and options.
    C_SANE(1, contxt);

    // Return on abort or if the user doesn't confirm when (confirm) is set.
    if(opt(contxt, OPT_CONFIRM) && !h_confirm(contxt,
       str(opt(contxt, OPT_HELP)), str(opt(contxt, OPT_PROMPT))))
    {
        R_NUM(LG_FALSE);
    }

    // Succeed immediately if non-safe in pretend mode.
    if(!opt(contxt, OPT_SAFE) && get_num(contxt, "@pretend"))
    {
        R_NUM(LG_TRUE);
    }

    // The directory to be created.
    char *dir = str(C_ARG(1));

    // Create directory.
    if(!h_makedir(contxt, dir))
    {
        // Could not create directory.
        ERR(ERR_WRITE_DIR, dir);
        R_NUM(LG_FALSE);
    }

    // Directory created.
    R_NUM(LG_TRUE);
}

//------------------------------------------------------------------------------
// Name:        h_protect_arg_get
// Description: n_protect get file pemission mask.
// Input:       entry_p contxt: The execution context.
// Return:      int32_t:        The resulting bitmask.
//------------------------------------------------------------------------------
static int32_t h_protect_arg_get(entry_p contxt)
{
    // Test (override) option.
    entry_p override = opt(contxt, OPT_OVERRIDE);

    if(override)
    {
        // Ignore file.
        return num(override);
    }

    // ----rwed.
    int32_t msk = 0;

    // Get is considered (safe).
    h_protect_get(contxt, str(C_ARG(1)), &msk);

    return msk;
}

//------------------------------------------------------------------------------
// Name:        h_protect_mask
// Description: n_protect helper generating bitmasks from '+rw..' like strings.
// Input:       entry_p contxt: The execution context.
// Return:      int32_t:        The resulting bitmask.
//------------------------------------------------------------------------------
static int32_t h_protect_mask(char *flags, int32_t cms)
{
    // Start with current mask.
    size_t len = strlen(flags);
    int32_t msk = cms;

    // Inverting 1-4 in the name of clarity.
    msk ^= 0x0f;

    // Parser state.
    int mode = 0;

    for(size_t i = 0; i < len; i++)
    {
        // Temp mask.
        int32_t bit = 0;

        // Identify protection bit.
        switch(flags[i])
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

        // Add or remove.
        switch(mode)
        {
            case 0: msk = bit; mode = 1; break;
            case 1: msk |= bit; break;
            case 2: msk &= ~bit; break;
            default: break;
        }
    }

    // Inverting 1-4 in the name of Amiga.
    msk ^= 0x0f;

    return msk;
}

//------------------------------------------------------------------------------
// Name:        h_protect_delta
// Description: n_protect delta setter.
// Input:       entry_p contxt: The execution context.
// Return:      int32_t:        The resulting bitmask.
//------------------------------------------------------------------------------
static int32_t h_protect_delta(entry_p contxt, char *flags, char *file)
{
    // Test (override) option.
    entry_p override = opt(contxt, OPT_OVERRIDE);
    int32_t msk = 0;

    if(override)
    {
        // Use override instead of file flags.
        msk = num(override);
    }
    else if(!h_protect_get(contxt, file, &msk))
    {
        return msk;
    }

    // Apply permission string to mask.
    msk = h_protect_mask(flags, msk);

    // Apply final mask to file unless pretend mode is active.
    if(opt(contxt, OPT_SAFE) || !get_num(contxt, "@pretend"))
    {
        h_protect_set(contxt, file, msk);
    }

    // Return final mask.
    return msk;
}

//------------------------------------------------------------------------------
// Name:        h_protect_arg_set
// Description: n_protect setter dispatch.
// Input:       entry_p contxt: The execution context.
// Return:      int32_t:        The resulting bitmask.
//------------------------------------------------------------------------------
static int32_t h_protect_arg_set(entry_p contxt)
{
    // Resolve once only. Used both as number and string below.
    entry_p val = resolve(C_ARG(2));

    int32_t msk = num(val);
    char *file = str(C_ARG(1));

    // Non-strings and strings that can be treated like non-zero numbers are
    // used as absolute permission values.
    if(msk || val->type != STRING)
    {
        // Apply mask to file unless pretend mode is active.
        if(opt(contxt, OPT_SAFE) || !get_num(contxt, "@pretend"))
        {
            h_protect_set(contxt, file, msk);
        }

        return msk;
    }

    // All other strings are interpreted as '+hspa-r' and so on.
    return h_protect_delta(contxt, str(val), file);
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
entry_p n_protect(entry_p contxt)
{
    // One or more arguments.
    C_SANE(1, contxt);

    size_t args = 0;

    // Get number of arguments leading up to the first option.
    while(exists(C_ARG(args + 1)) && C_ARG(args + 1)->type != OPTION)
    {
        args++;
    }

    // File name only. Get file permissions.
    if(args == 1)
    {
        R_NUM(h_protect_arg_get(contxt));
    }

    // File name and permission mask / delta. Set file permissions.
    if(args == 2)
    {
        R_NUM(h_protect_arg_set(contxt));
    }

    // Broken parser.
    PANIC(contxt);
    return end();
}

//------------------------------------------------------------------------------
// (startup (prompt..) (command..))
//     add a command to the boot scripts (startup-sequence, user-startup)
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_startup(entry_p contxt)
{
    // Two or more arguments / options.
    C_SANE(2, contxt);

    const char *app = str(C_ARG(1));

    entry_p command  = opt(contxt, OPT_COMMAND),
            help     = opt(contxt, OPT_HELP),
            prompt   = opt(contxt, OPT_PROMPT);

    // Expect failure.
    D_NUM = LG_FALSE;

    // We need a command and somewhere to put it.
    if((!*app && ERR(ERR_INVALID_APP, app)) ||
       (!command && ERR(ERR_MISSING_OPTION, "command")))
    {
        R_NUM(LG_FALSE);
    }

    // Return on abort or if the user doesn't confirm when (confirm) is set or
    // when the user level is expert.
    if((opt(contxt, OPT_CONFIRM) ||
        get_num(contxt, "@user-level") == LG_EXPERT) &&
        !h_confirm(contxt, str(help), str(prompt)))
    {
        R_NUM(LG_FALSE);
    }

    // We're done if executing in pretend mode.
    if(get_num(contxt, "@pretend"))
    {
        R_NUM(LG_TRUE);
    }

    // Gather and merge all (command) strings.
    char *cmd = get_optstr(contxt, OPT_COMMAND);

    if(!cmd && PANIC(contxt))
    {
        R_NUM(LG_FALSE);
    }

    const char *fln = get_str(contxt, "@user-startup");
    const size_t len = strlen(";BEGIN ") + strlen(app);
    size_t ins = strlen(cmd);

    // The CBM installer chomps one (and only one) line feed if it exists.
    ins += (ins == 0 || cmd[ins - 1] != '\n') ? 2 : 1;

    char *pre = DBG_ALLOC(calloc(len + 1, 1)),
         *pst = DBG_ALLOC(calloc(len + 1, 1)), *buf = NULL;

    if(pre && pst)
    {
        // We don't need to write yet.
        FILE *file = h_fopen(contxt, fln, "r", false);

        // If the file doesn't exist, try to create it.
        if(!file && h_exists(fln) == LG_NONE)
        {
            file = h_fopen(contxt, fln, "w", false);

            // If successful, close and reopen as read only.
            if(file)
            {
                h_fclose(&file);
                file = h_fopen(contxt, fln, "r", false);
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
                    PANIC(contxt);
                }
            }

            // Reading done.
            h_fclose(&file);
        }
    }
    else
    {
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
                    h_fclose(&file);
                }
                else
                {
                    // Close file and release buffer.
                    h_fclose(&file);
                    free(buf);
                    buf = NULL;

                    // Open the target file just to make sure that we have
                    // write permissions.
                    file = h_fopen(contxt, fln, "a", false);

                    if(file)
                    {
                        // Close it immediately, we're not going to write
                        // directly to it.
                        h_fclose(&file);

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
// Name:        h_copy_simple
// Description: Copy source file to destination file using already open file
//              handles.
// Input:       entry_p contxt:     The execution context.
//              FILE *src:          Source file handle.
//              FILE *dst:          Destination file handle.
//              const char *nfo:    Write error message.
// Return:      -
//------------------------------------------------------------------------------
static void h_copy_simple(entry_p contxt, FILE *src, FILE *dst, const char *nfo)
{
    // Copy source file to destination in buf_len() sized chunks.
    for(size_t cnt = fread(buf_get(B_KEY), 1, buf_len(), src); cnt;
        cnt = fread(buf_get(B_KEY), 1, buf_len(), src))
    {
        if(fwrite(buf_get(B_KEY), 1, cnt, dst) != cnt)
        {
            ERR(ERR_WRITE_FILE, nfo);
            break;
        }
    }

    // Unlock buffer.
    buf_put(B_KEY);
}

//------------------------------------------------------------------------------
// Name:        h_fclose
// Description: Safe file close.
// Input:       FILE **file:     Pointer to file handle.
// Return:      -
//------------------------------------------------------------------------------
void h_fclose(FILE **file)
{
    if(file && *file)
    {
        (void) fclose(*file);
        *file = NULL;
    }
}

//------------------------------------------------------------------------------
// Name:        h_fopen
// Description: Open file after checking permissions. If necessary, permissions
//              are modified to enable 'mode' if 'force' us used.
// Input:       entry_p contxt:     Execution context.
//              const char *name:   File name.
//              const char *mode:   Mode (fopen).
//              bool force:         Change file permissions if necessary.
// Return:      FILE *:             File handle on success, NULL otherwise.
//------------------------------------------------------------------------------
FILE *h_fopen(entry_p contxt, const char *name, const char *mode, bool force)
{
    if(h_exists(name) == LG_DIR)
    {
        // Don't open directories.
        return NULL;
    }

    if(h_exists(name) == LG_NONE)
    {
        // Create file if it doesn't exist.
        return fopen(name, mode);
    }

    int32_t prm = 0;

    if(!h_protect_get(contxt, name, &prm))
    {
        // Couldn't get file permissions.
        return NULL;
    }

    // If mode isn't 'read*', it's 'write*' or 'append*'.
    bool read = (prm & READ_MASK) == 0, write = (prm & WRITE_MASK) == 0,
         perm = *mode == 'r' ? read : write;

    // Flip permissions to enable the outcome of above.
    prm ^= *mode == 'r' ? READ_MASK : WRITE_MASK;

    // In non-strict mode; use force if needed / wanted.
    if(perm || (force && !get_num(contxt, "@strict") &&
       h_protect_set(contxt, name, prm)))
    {
        return fopen(name, mode);
    }

    // Couldn't set file permissions.
    return NULL;
}

//------------------------------------------------------------------------------
// Name:        h_textfile_append
// Description: Append h_textfile helper.
// Input:       entry_p contxt:     The execution context.
//              const char *name:   Output file name.
// Return:      int32_t:            LG_TRUE or LG_FALSE.
//------------------------------------------------------------------------------
static int32_t h_textfile_append(entry_p contxt, const char *name)
{
    // Gather and merge all (append) strings.
    char *app = get_optstr(contxt, OPT_APPEND);

    if(DID_ERR || (!app && PANIC(contxt)))
    {
        free(app);
        return LG_FALSE;
    }

    // Append without include truncates / creates a new file.
    const char *mode = opt(contxt, OPT_INCLUDE) ? "a" : "w";

    FILE *file = h_fopen(contxt, name, mode, true);

    if(!file)
    {
        free(app);

        if(get_num(contxt, "@strict"))
        {
            // Couldn't write to file.
            ERR(ERR_WRITE_FILE, name);
            return LG_FALSE;
        }

        // Fail silently in non-strict mode.
        return LG_TRUE;
    }

    // Write to log if logging is enabled.
    h_log(contxt, tr(S_APND), app, file);

    // Get length of string to append.
    size_t len = strlen(app);

    // Append to file if string is non-empty.
    if(len && fwrite(app, 1, len, file) != len)
    {
        // Couldn't write to file.
        ERR(ERR_WRITE_FILE, name);
    }

    free(app);
    h_fclose(&file);

    // Success or failure.
    return NOT_ERR ? LG_TRUE : LG_FALSE;
}

//------------------------------------------------------------------------------
// Name:        h_textfile_include
// Description: Include h_textfile helper.
// Input:       entry_p contxt:     The execution context.
//              const char *name:   Output file name.
// Return:      int32_t:            LG_TRUE or LG_FALSE.
//------------------------------------------------------------------------------
static int32_t h_textfile_include(entry_p contxt, const char *name)
{
    const char *incl = str(opt(contxt, OPT_INCLUDE));

    if(DID_ERR)
    {
        return LG_FALSE;
    }

    if(!strcasecmp(incl, name))
    {
        // Nothing to do.
        return LG_TRUE;
    }

    // Try to open files, with force (non-strict mode only) if necessary.
    FILE *finc = h_fopen(contxt, incl, "r", true),
         *fdst = h_fopen(contxt, name, "w", true);

    if(!finc || !fdst)
    {
        if(get_num(contxt, "@strict"))
        {
            // Determine whether we have a read or a write problem.
            ERR(finc ? ERR_WRITE_FILE : ERR_READ_FILE, finc ? name : incl);
        }

        h_fclose(&finc);
        h_fclose(&fdst);

        // Fail silently.
        return NOT_ERR ? LG_TRUE : LG_FALSE;
    }

    // Copy include file to destination file.
    h_copy_simple(contxt, finc, fdst, name);

    // Close input and output files.
    h_fclose(&finc);
    h_fclose(&fdst);

    return NOT_ERR ? LG_TRUE : LG_FALSE;
}

//------------------------------------------------------------------------------
// Name:        h_textfile
// Description: Include / append n_textfile helper.
// Input:       entry_p contxt:     The execution context.
// Return:      int32_t:            LG_TRUE or LG_FALSE.
//------------------------------------------------------------------------------
static int32_t h_textfile(entry_p contxt)
{
    // Overwrite existing file.
    const char *name = str(opt(contxt, OPT_DEST));

    // Assume success.
    int32_t ret = LG_TRUE;

    if(ret == LG_TRUE && opt(contxt, OPT_INCLUDE))
    {
        ret = h_textfile_include(contxt, name);
    }

    if(opt(contxt, OPT_APPEND))
    {
        ret = h_textfile_append(contxt, name);
    }

    // Success or failure.
    return ret;
}

//------------------------------------------------------------------------------
// (textfile (prompt..) (help..) (dest..) (append) (include..) (confirm..)
//           (safe))
//
//      create text file from other text files and strings
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_textfile(entry_p contxt)
{
    // One or more arguments / options.
    C_SANE(1, contxt);

    if(!opt(contxt, OPT_DEST))
    {
        ERR(ERR_MISSING_OPTION, "dest");
        R_NUM(LG_FALSE);
    }

    // We must append and / or include, or else this doesn't make sense.
    if(!opt(contxt, OPT_APPEND) && !opt(contxt, OPT_INCLUDE))
    {
        ERR(ERR_NOTHING_TO_DO, contxt->name);
        R_NUM(LG_FALSE);
    }

    // Return on abort or if the user doesn't confirm when (confirm) is set.
    if(opt(contxt, OPT_CONFIRM) && !h_confirm(contxt,
       str(opt(contxt, OPT_HELP)), str(opt(contxt, OPT_PROMPT))))
    {
        R_NUM(LG_FALSE);
    }

    // Succeed immediately if non-safe in pretend mode.
    if(!opt(contxt, OPT_SAFE) && get_num(contxt, "@pretend"))
    {
        R_NUM(LG_TRUE);
    }

    // The real work is done by the helper.
    R_NUM(h_textfile(contxt));
}

//------------------------------------------------------------------------------
// (tooltype (prompt..) (help..) (dest..) (settooltype..) (setstack..)
//     (setdefaulttool..) (noposition) (confirm..) (safe))
//
//     modify an icon
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_tooltype(entry_p contxt)
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
                if(exists(settooltype->children[1]))
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
                                        snprintf(buf_raw(), buf_len(), "%s=%s", t, v);
                                    }
                                    else
                                    {
                                        // Naked tooltype.
                                        snprintf(buf_raw(), buf_len(), "%s", t);
                                    }

                                    // Overwrite the old tooltype.
                                    *nts = buf_raw();
                                    break;
                                }

                                // Next tooltype.
                                nts++;
                            }
                        }
                        else
                        {
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
                                snprintf(buf_raw(), buf_len(), "%s=%s", t, v);
                            }
                            else
                            {
                                // Naked tooltype.
                                snprintf(buf_raw(), buf_len(), "%s", t);
                            }

                            // Append tooltype.
                            *(nts + n - 1) = buf_raw();
                        }
                        else
                        {
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
            // Don't fail in sloppy mode.
            else if(get_num(contxt, "@strict"))
            {
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
        // Don't fail in sloppy mode.
        else if(get_num(contxt, "@strict"))
        {
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
entry_p n_transcript(entry_p contxt)
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
    R_NUM(NOT_ERR ? LG_TRUE : LG_FALSE);
}

//------------------------------------------------------------------------------
// (rename <old> <new> (help..) (prompt..) (confirm..) (safe))
//     rename files
//
// Refer to Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
//------------------------------------------------------------------------------
entry_p n_rename(entry_p contxt)
{
    // Two or more arguments / options.
    C_SANE(2, contxt);

    // Old and new file name.
    const char *old = str(C_ARG(1)), *new = str(C_ARG(2));

    // Return on abort or if the user doesn't confirm when (confirm) is set.
    if(opt(contxt, OPT_CONFIRM) && !h_confirm(contxt,
       str(opt(contxt, OPT_HELP)), str(opt(contxt, OPT_PROMPT))))
    {
        R_NUM(LG_FALSE);
    }

    // Is this a safe operation or are we not running in pretend mode?
    if(!opt(contxt, OPT_SAFE) && get_num(contxt, "@pretend"))
    {
        R_NUM(-1);
    }

    // Are we going to rename a file/dir?
    if(!opt(contxt, OPT_DISK))
    {
        // Rename if target doesn't exist.
        if(h_exists(new) == LG_NONE && !rename(old, new))
        {
            h_log(contxt, tr(S_FRND), old, new);
            R_NUM(-1);
        }

        // Fail if target exists in strict mode.
        if(get_num(contxt, "@strict"))
        {
            ERR(ERR_RENAME_FILE, old);
        }

        R_NUM(LG_FALSE);
    }
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
    FILE *file = h_fopen(contxt, get_str(contxt, "@log-file"), "a", true);
    int cnt = -1;

    if(file)
    {
        // Line number and function name as prefix.
        cnt = fprintf(file, "[%d:%s] ", contxt->id, contxt->name);

        // Append formatted string.
        if(cnt > 0)
        {
            va_list arg;
            va_start(arg, fmt);
            cnt = vfprintf(file, fmt, arg);
            va_end(arg);
        }

        h_fclose(&file);
    }

    // Could we open the file and write all data to it?
    if(cnt < 0)
    {
        ERR(ERR_WRITE_FILE, get_str(contxt, "@log-file"));
    }
}
