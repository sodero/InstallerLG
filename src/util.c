//------------------------------------------------------------------------------
// util.c:
//
// Misc utility functions primarily used by the 'native' methods.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "error.h"
#include "eval.h"
#include "util.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#ifdef AMIGA
#include <clib/debug_protos.h>
#define DBG(...) KPrintF((CONST_STRPTR)__VA_ARGS__)
#else
#define DBG(...) fprintf(stderr, __VA_ARGS__)
#endif

//------------------------------------------------------------------------------
// Name:        ror
// Description: Rotate array of entries to the right.
// Input:       entry_p *e: Array of entries.
// Return:      -
//------------------------------------------------------------------------------
void ror(entry_p *entry)
{
    // Something to rotate?
    if(!entry)
    {
        // Nope.
        return;
    }

    int lst = 0;

    // Let 'lst' be the index of the last entry.
    while(exists(entry[lst]))
    {
        lst++;
    }

    // Nothing to do if we have < 2 entries.
    if(--lst > 0)
    {
        // Save the last entry.
        entry_p last = entry[lst];

        // Shift the rest to the right.
        while(lst)
        {
            entry[lst] = entry[lst - 1];
            lst--;
        }

        // Put the saved entry first.
        entry[0] = last;
    }
}

//------------------------------------------------------------------------------
// Name:        local
// Description: Find the next context going upwards in the tree.
// Input:       entry_p entry:  The starting point.
// Return:      entry_p:        The closest context found, or
//                              NULL if no context was found.
//------------------------------------------------------------------------------
entry_p local(entry_p entry)
{
    // Go upwards until we find what we're looking for, or hit the (broken) top.
    for(entry_p contxt = entry; contxt; contxt = contxt->parent)
    {
        if(contxt->type == CONTXT || contxt->type == CUSTOM)
        {
            return contxt;
        }

        if(contxt->parent == contxt)
        {
            dump(contxt);
            break;
        }
    }

    // Nothing:
    return NULL;
}

//------------------------------------------------------------------------------
// Name:        global
// Description: Find the root context.
// Input:       entry_p entry:  The starting point.
// Return:      entry_p:        The root context, or NULL
//                              if no context was found.
//------------------------------------------------------------------------------
entry_p global(entry_p entry)
{
    // Go all the way up.
    for(entry_p contxt = local(entry); contxt;)
    {
        // Find the next context.
        entry_p next = local(contxt->parent);

        // If there is no higher context, we're at the global level.
        if(!next)
        {
            return contxt;
        }

        // Next level.
        contxt = next;
    }

    // Nothing:
    return NULL;
}

//------------------------------------------------------------------------------
// Name:        parent
// Description: Find parent of a given type if such exists.
// Input:       entry_p entry:  The starting point.
//              type_t type:    The parent type.
// Return:      entry_p:        The parent, or NULL if no parent of the given
//                              type was found.
//------------------------------------------------------------------------------
static entry_p parent(entry_p entry, type_t type)
{
    // Check current level then go all the way up.
    for(entry_p cur = entry; cur; cur = cur->parent)
    {
        // Is this parent of the correct type?
        if(cur->type == type)
        {
            // Found it.
            return cur;
        }
    }

    // Parent not found.
    return NULL;
}

//------------------------------------------------------------------------------
// Name:        custom
// Description: Find CUSTOM parent if such exists.
// Input:       entry_p entry:  The starting point.
// Return:      entry_p:        The CUSTUM entry, or NULL
//                              if no CUSTOM was found.
//------------------------------------------------------------------------------
entry_p custom(entry_p entry)
{
    return parent(entry, CUSTOM);
}

//------------------------------------------------------------------------------
// Name:        native
// Description: Find NATIVE parent if such exists.
// Input:       entry_p entry:  The starting point.
// Return:      entry_p:        The NATIVE entry, or NULL
//                              if no NATIVE was found.
//------------------------------------------------------------------------------
entry_p native(entry_p entry)
{
    return parent(entry, NATIVE);
}

//------------------------------------------------------------------------------
// FIXME
//------------------------------------------------------------------------------
static void get_fake_opt(entry_p fake, entry_p *cache)
{
    // Translate strings to options.
    for(size_t i = 0; exists(fake->children[i]); i++)
    {
        entry_p cur = fake->children[i];
        bool del = cur->parent->id == OPT_DELOPTS;
        char *fop = str(cur);

        // Set or delete option.
        cache[OPT_FAIL] = strcasecmp(fop, "fail") ?
        cache[OPT_FAIL] : (del ? NULL : cur);
        cache[OPT_FORCE] = strcasecmp(fop, "force") ?
        cache[OPT_FORCE] : (del ? NULL : cur);
        cache[OPT_NOFAIL] = strcasecmp(fop, "nofail") ?
        cache[OPT_NOFAIL] : (del ? NULL : cur);
        cache[OPT_ASKUSER] = strcasecmp(fop, "askuser") ?
        cache[OPT_ASKUSER] : (del ? NULL : cur);
        cache[OPT_OKNODELETE] = strcasecmp(fop, "oknodelete") ?
        cache[OPT_OKNODELETE] : (del ? NULL : cur);
    }
}

//------------------------------------------------------------------------------
// FIXME
//------------------------------------------------------------------------------
static void prune_opt(entry_p contxt, entry_p *cache)
{
    // Sanity check.
    if(!cache)
    {
        PANIC(contxt);
        return;
    }

    if(cache[OPT_CONFIRM])
    {
        // Make sure that we a prompt and help string.
        if(!cache[OPT_PROMPT] || !cache[OPT_HELP])
        {
            char * msg = cache[OPT_PROMPT] ? "help" : "prompt";
            ERR_C(native(contxt), ERR_MISSING_OPTION, msg);
        }

        // The default threshold is expert.
        int level = get_num(contxt, "@user-level"), thres = LG_EXPERT;

        // If the (cache[OPT_CONFIRM] ...) option contains something that can be
        // translated into a new threshold value...
        if(cache[OPT_CONFIRM]->children &&
           exists(cache[OPT_CONFIRM]->children[0]))
        {
            // ...then do so.
            thres = num(cache[OPT_CONFIRM]);
        }

        // If we are below the threshold value, or user input has been
        // short-circuited by @yes, skip cache[OPT_CONFIRM]ation.
        if(level < thres || get_num(contxt, "@yes"))
        {
            cache[OPT_CONFIRM] = NULL;
        }
    }

    if(cache[OPT_ALL])
    {
        cache[OPT_FILES] = NULL;
    }
}

//------------------------------------------------------------------------------
// FIXME
//------------------------------------------------------------------------------
static void opt_fill_cache(entry_p contxt, entry_p *cache)
{
    // Iterate over all options to fill up the cache.
    for(size_t i = 0; i < OPT_LAST && exists(contxt->children[i]); i++)
    {
        entry_p entry = contxt->children[i];

        // Skip non options.
        if(entry->type != OPTION)
        {
            continue;
        }

        // Cast dake options to real options.
        if(entry->id == OPT_OPTIONAL || entry->id == OPT_DELOPTS)
        {
            get_fake_opt(entry, cache);
        }
        // Dynamic options must be resolved.
        else if(entry->id == OPT_DYNOPT)
        {
            entry_p res = resolve(entry);

            if(res->type != OPTION)
            {
                // Non-existing conditional path.
                continue;
            }

            // Cache all options if we're in a block.
            if(res->parent->type == CONTXT)
            {
                opt_fill_cache(res->parent, cache);
            }

            // Resolved value is a real option.
            cache[res->id] = res;
        }
        else
        {
            // Save real options as they are.
            cache[entry->id] = entry;
        }
    }
}

//------------------------------------------------------------------------------
// Name:        opt
// Description: Find option of a given type in a context.
// Input:       entry_p contxt:  The context to search in.
//              opt_t type:      The type of option to search for.
// Return:      entry_p:         An OPTION entry if found, NULL otherwise.
//------------------------------------------------------------------------------
entry_p opt(entry_p contxt, opt_t type)
{
    static entry_p cache[OPT_LAST], last;

    // We need a valid context.
    if(!contxt || !contxt->children)
    {
        return NULL;
    }

    // Return cached value if cache is full.
    if(contxt == last)
    {
        return cache[type];
    }

    // New context, clear cache.
    memset(cache, 0, sizeof(cache));
    cache[OPT_INIT] = end();
    last = contxt;

    // Populate cache.
    opt_fill_cache(contxt, cache);

    // If in non strict mode, allow the absense of (prompt) and (help).
    if(!get_num(contxt, "@strict"))
    {
        if(!cache[OPT_HELP])
        {
            // Will be resolved as "".
            cache[OPT_HELP] = end();
        }

        if(!cache[OPT_PROMPT])
        {
            // Will be resolved as "".
            cache[OPT_PROMPT] = end();
        }
    }

    // Prune options.
    prune_opt(contxt, cache);

    // Use the (full) cache.
    return cache[type];
}

//------------------------------------------------------------------------------
// Name:        x_exists
// Description: Existence and ownership sanity check.
// Input:       entry_p contxt:  The context.
// Return:      bool:            'true' if child is valid, 'false' otherwise.
//------------------------------------------------------------------------------
static bool x_exists(entry_p contxt, entry_p child)
{
    // Make sure we have something that belongs to us.
    return exists(child) && child->parent == contxt;
}

//------------------------------------------------------------------------------
// Name:        x_name
// Description: Child sanity check.
// Input:       entry_p contxt:  The context.
// Return:      bool:            'true' if child is valid, 'false' otherwise.
//------------------------------------------------------------------------------
static bool x_name(entry_p child)
{
    // All but CONTXT and NUMBER are named.
    return child->name || (child->type == CONTXT || child->type == NUMBER);
}

//------------------------------------------------------------------------------
// Name:        x_children
// Description: Context sanity check.
// Input:       entry_p contxt:  The context.
// Return:      bool:            'true' if context is valid, 'false' otherwise.
//------------------------------------------------------------------------------
static bool x_children(entry_p contxt)
{
    // A CONTXT must have room for children.
    return contxt->type != CONTXT || contxt->children;
}

//------------------------------------------------------------------------------
// Name:        x_sane
// Description: Sanity check to verify that we have the required number of
//              children or symbols needed and that these are valid. This
//              might fail if we're out of memory or if the parser is broken.
// Input:       entry_p contxt:  The context.
//              type_t:          NATIVE or SYMBOL.
//              size_t num:      The number of children / symbols needed.
// Return:      bool:            'true' if context is valid, 'false' otherwise.
//------------------------------------------------------------------------------
static bool x_sane(entry_p contxt, type_t type, size_t num)
{
    // Verification of symbols or children.
    entry_p *vec = type == NATIVE ? contxt->children : contxt->symbols;

    // Array of num or more, and if NATIVE, a resolved value is needed.
    if((num && !vec) || (contxt->type == NATIVE && !contxt->resolved))
    {
        dump(contxt);
        return false;
    }

    // Expect at least num children.
    for(size_t i = 0; i < num; i++)
    {
        // Make sure we have something, and that it belongs to us.
        if(!x_exists(contxt, vec[i]))
        {
            dump(contxt);
            return false;
        }

        // Make sure that names exist, if applicable.
        if(!x_name(vec[i]))
        {
            dump(vec[i]);
            return false;
        }

        // Make sure that there's room for children, if applicable.
        if(!x_children(vec[i]))
        {
            dump(vec[i]);
            return false;
        }
    }

    // We're OK;
    return true;
}

//------------------------------------------------------------------------------
// Name:        c_sane
// Description: Context sanity check used by the NATIVE functions to verify
//              that we have atleast the number of children needed and that
//              these are valid. If this fails it means that we have a parser
//              or an out of memory problem.
// Input:       entry_p contxt:  The context.
//              size_t num:      The number of children necessary.
// Return:      bool:            'true' if context is valid, 'false' otherwise.
//------------------------------------------------------------------------------
bool c_sane(entry_p contxt, size_t num)
{
    return contxt && x_sane(contxt, NATIVE, num);
}

//------------------------------------------------------------------------------
// Name:        s_sane
// Description: Context sanity check used by the NATIVE functions to verify
//              that we have atleast the number of symbols needed and that
//              these are valid. If this fails it means that we have a parser
//              or an out of memory problem.
// Input:       entry_p contxt:  The context.
//              size_t num:      The number of symbols necessary.
// Return:      bool:            'true' if context is valid, 'false' otherwise.
//------------------------------------------------------------------------------
bool s_sane(entry_p contxt, size_t num)
{
    return contxt && contxt->symbols && global(contxt) &&
           x_sane(contxt, SYMBOL, num);
}

//------------------------------------------------------------------------------
// Name:        set_num
// Description: Give an existing numerical variable a new value. Please note
//              that the variable must exist and that the current resolved
//              value must be a NUMBER, if not, this function will silently
//              fail.
// Input:       entry_p contxt:  The context.
//              char *var:       The name of the variable.
//              int val:         The new value of the variable.
// Return:      -
//------------------------------------------------------------------------------
void set_num(entry_p contxt, char *var, int val)
{
    // Dummy reference used for searching.
    static entry_t ref = { .type = SYMREF };

    // We need a name and a context.
    if(!contxt || !var)
    {
        PANIC(contxt);
        return;
    }

    // Name and reparent.
    ref.parent = contxt;
    ref.name = var;

    // Find whatever 'var' is.
    entry_p sym = find_symbol(&ref);

    // This should be a symbol and it should be a resolved numerical one.
    if(sym && sym->type == SYMBOL && sym->resolved &&
       sym->resolved->type == NUMBER)
    {
        // Success.
        sym->resolved->id = val;
    }
}

//------------------------------------------------------------------------------
// Name:        get_num
// Description: Get the value of an existing numerical variable. Please note
//              that the variable must exist and that the current resolved value
//              must be a NUMBER.
// Input:       entry_p contxt:  The context.
//              char *var:       The name of the variable.
// Return:      int:             The value of the variable or zero if the
//                               variable can't be found.
//------------------------------------------------------------------------------
int get_num(entry_p contxt, char *var)
{
    // We need a name and a context.
    if(!contxt || !var)
    {
        PANIC(contxt);
        return 0;
    }

    // Dummy reference used for searching.
    static entry_t ref = { .type = SYMREF };

    // Name and reparent dummy.
    ref.parent = contxt;
    ref.name = var;

    // Find whatever 'var' is.
    entry_p sym = find_symbol(&ref);

    // This should be a symbol. And it should be a resolved numerical one.
    if(sym && sym->type == SYMBOL && sym->resolved &&
       sym->resolved->type == NUMBER)
    {
        // Success.
        return sym->resolved->id;
    }

    // Failure.
    return 0;
}

//------------------------------------------------------------------------------
// Name:        get_str
// Description: Get the value of an existing string variable. Please note
//              that the variable must exist and that the current resolved
//              value must be a STRING.
// Input:       entry_p contxt:  The context.
//              char *var:       The name of the variable.
// Return:      char *:          The value of the variable or an empty string
//                               if the variable can't be found.
//------------------------------------------------------------------------------
char *get_str(entry_p contxt, char *var)
{
    // We need a name and a context.
    if(!contxt || !var)
    {
        PANIC(contxt);
        return "";
    }

    // Dummy reference used to find the variable.
    static entry_t ref = { .type = SYMREF };

    // Name and reparent dummy.
    ref.name = var;
    ref.parent = contxt;

    // Find whatever 'v' is.
    entry_p sym = find_symbol(&ref);

    // This should be a symbol. And it should be a resolved string.
    if(sym && sym->type == SYMBOL && sym->resolved && sym->resolved->name &&
       sym->resolved->type == STRING)
    {
        // Success.
        return sym->resolved->name;
    }

    // Failure.
    return "";
}

//------------------------------------------------------------------------------
// Name:        get_optstr
// Description: Concatenate all the strings in all the options of a given type.
// Input:       entry_p contxt:    The context.
//              opt_t type:        The option type.
// Return:      char *:            A concatenation of all the strings found.
//------------------------------------------------------------------------------
char *get_optstr(entry_p contxt, opt_t type)
{
    size_t cnt = 0;
    entry_p *child = contxt->children;

    // Count options of the given type.
    while(exists(*child))
    {
        if((*child)->type == OPTION && (*child)->id == (int32_t) type)
        {
            // Found one.
            cnt++;
        }

        // Next child.
        child++;
    }

    // Did we find the right type?
    if(!cnt)
    {
        // Not found.
        return NULL;
    }

    // References to strings of options of the right type.
    char **val = DBG_ALLOC(calloc(cnt + 1, sizeof(char *)));

    if(!val && PANIC(contxt))
    {
        // Out of memory.
        return NULL;
    }

    // Empty string.
    child = contxt->children;
    size_t len = 1;

    // Evaluate options once and save strings.
    for(size_t i = 0; i < cnt && exists(*child); child++)
    {
        if((*child)->id == (int32_t) type && (*child)->type == OPTION)
        {
            // Sum up the length.
            char *cur = get_chlstr(*child, false);

            if(cur)
            {
                val[i++] = cur;
                len += strlen(cur);
            }
        }
    }

    // Memory for the sum of all strings.
    char *ret = DBG_ALLOC(calloc(len, 1));

    if(ret)
    {
        // Concatenate substrings.
        for(size_t i = 0; val[i]; i++)
        {
            strncat(ret, val[i], len - strlen(ret));
        }
    }

    // Free substrings.
    for(size_t i = 0; val[i]; i++)
    {
        free(val[i]);
    }

    // Free references.
    free(val);

    // Success or out of memory.
    return ret;
}

//------------------------------------------------------------------------------
// Name:        get_chlstr
// Description: Concatenate the string representations of all non context
//              children of a context.
// Input:       entry_p contxt:  The context.
//              bool pad:        Whitespace padding.
// Return:      char *:          The concatenation of the string representations
//                               of all non context children of 'contxt'.
//------------------------------------------------------------------------------
char *get_chlstr(entry_p contxt, bool pad)
{
    // We don't really need anything to concatenate but we expect a sane contxt.
    if(!c_sane(contxt, 0))
    {
        return NULL;
    }

    // Concatenation.
    entry_p *child = contxt->children;
    size_t cnt = 0;

    // We might not have any children.
    if(child)
    {
        // Count non context children.
        while(child && exists(*child))
        {
            cnt += ((*child)->type != CONTXT) ? 1 : 0;
            child++;
        }
    }

    if(!cnt)
    {
        // No children to concatenate.
        return DBG_ALLOC(strdup(""));
    }

    // Return value.
    char *ret = NULL;

    // Allocate memory to hold one string pointer per child.
    char **stv = DBG_ALLOC(calloc(cnt + 1, sizeof(char *)));

    if(!stv)
    {
        // Out of memory.
        return NULL;
    }

    // Total length.
    size_t len = 0;

    // Save all string pointers so that we don't evaluate children twice
    // and thereby set of side effects more than once.
    while(cnt > 0)
    {
        entry_p cur = *(--child);

        // Ignore contexts.
        if(cur->type == CONTXT)
        {
            continue;
        }

        // Go backwards, evaluate and increase total string length as
        // we go. Also, include padding if necessary.
        stv[--cnt] = str(cur);
        len += strlen(stv[cnt]) + (pad ? 1 : 0);
    }

    // Memory to hold the full concatenation.
    ret = len ? DBG_ALLOC(calloc(len + 1, 1)) : NULL;

    if(ret)
    {
        // The concatenation, 'stv' is null terminated.
        while(stv[cnt])
        {
            strncat(ret, stv[cnt], len + 1 - strlen(ret));
            cnt++;

            // Is padding applicable?
            if(pad && stv[cnt])
            {
                // Insert whitespace.
                strncat(ret, " ", len + 1 - strlen(ret));
            }
        }
    }
    else
    {
        // No data to concatenate.
        ret = DBG_ALLOC(strdup(""));
    }

    // Free references before returning.
    free(stv);

    // We could be in any state here, success or panic.
    return ret;
}

//------------------------------------------------------------------------------
// Name:        set_str
// Description: Give an existing string variable a new value. Please note
//              that the variable must exist and that the current resolved
//              value must be a STRING, if not, this function will silently
//              fail.
// Input:       entry_p contxt:  The context.
//              char *var:       The name of the variable.
//              char *val:       The new value of the variable.
// Return:      -
//------------------------------------------------------------------------------
void set_str(entry_p contxt, char *var, char *val)
{
    // We need a name and a context.
    if(!contxt || !var)
    {
        PANIC(contxt);
        return;
    }

    // Dummy reference used for searching.
    static entry_t ref = { .type = SYMREF };

    // Name and reparent dummy.
    ref.parent = contxt;
    ref.name = var;

    // Find whatever 'v' is.
    entry_p sym = find_symbol(&ref);

    // This should be a symbol. And it
    // should be a resolved string.
    if(sym && sym->type == SYMBOL && sym->resolved &&
       sym->resolved->type == STRING)
    {
        // Taking ownership of 'val'.
        free(sym->resolved->name);
        sym->resolved->name = val;
    }
}

//------------------------------------------------------------------------------
// Name:        dump_indent
// Description: Refer to dump below.
// Input:       entry_p entry:  The tree to print.
//              int indent:     Indentation level.
// Return:      -
//------------------------------------------------------------------------------
static void dump_indent(entry_p entry, int indent)
{
    // Indentation galore.
    char ind[16] = "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\0";

    // Going backwards to go forward.
    char *type = ind + sizeof(ind) - 1 - indent;
    type = type < ind ? ind : type;

    // NULL is a valid value.
    if(!entry)
    {
        DBG("NULL\n\n");
        return;
    }

    // Data type descriptions.
    char *tps[] = { "NUMBER", "STRING", "SYMBOL", "SYMREF", "NATIVE",
                    "OPTION", "CUSTOM", "CUSREF", "CONTXT", "DANGLE" };

    // All entries have a type, a parent and an ID.
    DBG("%s\n", tps[entry->type]);
    DBG("%sThis:%p\n", type, (void *) entry);
    DBG("%sParent:%p\n", type, (void *) entry->parent);
    DBG("%sId:\t%d\n", type, entry->id);

    // Most, but not all, have a name.
    if(entry->name)
    {
        DBG("%sName:\t%s\n", type, entry->name);
    }

     // Natives and cusrefs have callbacks.
    if(entry->call)
    {
        DBG("%sCall:\t%p\n", type, (void *) entry->call);
    }

    // Functions / symbols can be 'resolved'.
    if(entry->resolved)
    {
        DBG("%sRes:\t", type);

        // Pretty print the 'resolved' entry, last / default return value
        // and values refered to by symbols.
        dump_indent(entry->resolved, indent + 1);
    }

    // Pretty print all children.
    if(entry->children)
    {
        for(entry_p *chl = entry->children; exists(*chl); chl++)
        {
            DBG("%sChl:\t", type);
            dump_indent(*chl, indent + 1);
        }
    }

    // Pretty print all symbols.
    if(entry->symbols)
    {
        for(entry_p *sym = entry->symbols; exists(*sym); sym++)
        {
            DBG("%sSym:\t", type);
            dump_indent(*sym, indent + 1);
        }
    }
}

//------------------------------------------------------------------------------
// Name:        dump
// Description: Pretty print the complete tree in 'entry'.
// Input:       entry_p entry:  The tree to print.
// Return:      -
//------------------------------------------------------------------------------
void dump(entry_p entry)
{
    static entry_p last;

    // Don't duplicate.
    if(entry != last)
    {
        // Start with no indentation.
        dump_indent(entry, 0);

        // Remember this one.
        last = entry;
    }
}

#define LG_BUFSIZ (BUFSIZ + PATH_MAX + 1)
static char buf[LG_BUFSIZ];
static const char *buf_usr;

//------------------------------------------------------------------------------
// Name:        buf_raw
// Description: Unsafe access to temporary buffer.
// Input:       -
// Return:      char *: Buffer pointer.
//------------------------------------------------------------------------------
char *buf_raw(void)
{
    if(buf_usr)
    {
        // Buffer shouldn't be locked.
        DBG("Invalid peek. Lock owned by %s\n", buf_usr ? buf_usr : "NULL");
    }

    // Return buffer no matter what.
    return buf;
}

//------------------------------------------------------------------------------
// Name:        buf_get
// Description: Safe access to temporary buffer. Initial call will lock buffer.
// Input:       const char *usr: Unique string pointer used as key.
// Return:      char *: Buffer pointer.
//------------------------------------------------------------------------------
char *buf_get(const char *usr)
{
    // Lock buffer if it's unlocked.
    if(!buf_usr)
    {
        buf_usr = usr;
        return buf;
    }

    // The lock should belong to the caller.
    if(buf_usr != usr)
    {
        // The lock doesn't belong to the caller.
        DBG("Invalid lock by %s. Lock owned by %s\n", usr ? usr : "NULL",
            buf_usr ? buf_usr : "NULL");
    }

    // Return buffer no matter what.
    return buf;
}

//------------------------------------------------------------------------------
// Name:        buf_put
// Description: Unlock temporary buffer.
// Input:       const char *usr: Unique string pointer used as key.
// Return:      char *: Buffer pointer.
//------------------------------------------------------------------------------
char *buf_put(const char *usr)
{
    // Unlock buffer if the lock belongs to the caller.
    if(buf_usr == usr)
    {
        buf_usr = NULL;
        return buf;
    }

    // The lock doesn't belong to the caller.
    DBG("Invalid unlock by %s. Lock owned by %s\n", usr ? usr : "NULL",
        buf_usr ? buf_usr : "NULL");

    // Return buffer no matter what.
    return buf;
}

//------------------------------------------------------------------------------
// Name:        buf_len
// Description: Get length of temporary buffer.
// Input:       -
// Return:      size_t: Buffer size.
//------------------------------------------------------------------------------
size_t buf_len(void)
{
    return sizeof(buf) - 1;
}

//------------------------------------------------------------------------------
// Name:        dbg_alloc
// Description: Used by DBG-ALLOC to provide more info when failing to
//              allocate memory and to fail deliberately when testing.
// Input:       int line: Source code line.
//              const char *file: Source code file.
//              const char *func: Source code function.
//              void *mem: Pointer to allocated memory.
// Return:      void *: Pointer to allocated memory.
//------------------------------------------------------------------------------
void *dbg_alloc(int line, const char *file, const char *func, void *mem)
{
    // Fail deliberately if file or line defines are set.
    #if defined(FAIL_LINE) || defined(FAIL_FILE)
    const char *fail_file =
    #ifdef FAIL_FILE
    FAIL_FILE;
    #else
    NULL;
    #endif
    int fail_line =
    #ifdef FAIL_LINE
    FAIL_LINE;
    #else
    0;
    #endif

    // Do we have a line number restriction?
    if(!fail_line || line == fail_line)
    {
        // Do we have a file restriction?
        if(!fail_file || !strcmp(file, fail_file))
        {
            // Free memory and pass NULL to the calling function.
            free(mem);
            mem = NULL;
        }
    }
    #endif

    // Debug info.
    if(!mem)
    {
        DBG("Out of memory in %s (%s) line %d\n", func, file, line);
    }

    // Pass this on.
    return mem;
}

//------------------------------------------------------------------------------
// Name:        native_exists
// Description: Find first occurence of callback in AST.
// Input:       entry_p contxt:  CONTXT.
// Return:      entry_p:         NATIVE callback if found, NULL otherwise.
//------------------------------------------------------------------------------
entry_p native_exists(entry_p contxt, call_t func)
{
    if(!contxt)
    {
        // Not here.
        return NULL;
    }

    // Nothing found yet.
    entry_p entry = NULL;

    if(contxt->children)
    {
        // Iterate over all children and recur if needed.
        for(entry_p *cur = contxt->children; exists(*cur) && !entry; cur++)
        {
            if((*cur)->type == NATIVE && (*cur)->call == func)
            {
                // It exists.
                return *cur;
            }

            // Recur, depth first.
            entry = native_exists(*cur, func);
        }
    }

    if(!entry && contxt->symbols)
    {
        // Iterate over all symbols and recur if needed.
        for(entry_p *cur = contxt->symbols; exists(*cur) && !entry; cur++)
        {
            if((*cur)->type == NATIVE && (*cur)->call == func)
            {
                // It exists.
                return *cur;
            }

            // Recur, depth first.
            entry = native_exists(*cur, func);
        }
    }

    // NATIVE or NULL.
    return entry;
}

//------------------------------------------------------------------------------
// Name:        num_children
// Description: Get number of children in vector.
// Input:       entry_p *vec: Vector containing children.
// Return:      size_t:       The number of children in vector.
//------------------------------------------------------------------------------
size_t num_children(entry_p *vec)
{
    // Counter.
    size_t count = 0;

    // Count the number children.
    while(vec && exists(vec[count]))
    {
        count++;
    }

    // Total count.
    return count;
}

//------------------------------------------------------------------------------
// Name:        exists
// Description: Verify that an entry exists.
// Input:       entry_p entry: The entry to be verified.
// Return:      bool:          If entry exists, 'true', 'false' otherwise..
//------------------------------------------------------------------------------
bool exists(entry_p entry)
{
    return entry && entry != end();
}

//------------------------------------------------------------------------------
// Name:        str_to_userlevel
// Description: Convert userlevel strings to numeric userlevel.
// Input:       const char *user: Userlevel string representation.
//              int def:          Default value used if translation fails.
// Return:      int:              Numeric Userlevel.
//------------------------------------------------------------------------------
int str_to_userlevel(const char *user, int def)
{
    // NULL is a valid value. Return default.
    if(!user)
    {
        return def;
    }

    // Case insensitve 'NOVICE'
    if(*user == '0' || strcasecmp(user, "novice") == 0)
    {
        return LG_NOVICE;
    }

    // Case insensitve 'AVERAGE'
    if(*user == '1' || strcasecmp(user, "average") == 0)
    {
        return LG_AVERAGE;
    }

    // Case insensitve 'EXPERT'
    if(*user == '2' || strcasecmp(user, "expert") == 0)
    {
        return LG_EXPERT;
    }

    // Not a userlevel. Return default user.
    return def;
}
