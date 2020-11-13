//------------------------------------------------------------------------------
// util.c:
//
// Misc utility functions primarily used by the 'native' methods.
//------------------------------------------------------------------------------
// Copyright (C) 2018-2020, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "alloc.h"
#include "debug.h"
#include "error.h"
#include "eval.h"
#include "util.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

//------------------------------------------------------------------------------
// Name:        ror
// Description: Rotate array of entries to the right.
// Input:       entry_p *e: Array of entries.
// Return:      -
//------------------------------------------------------------------------------
void ror(entry_p *entry)
{
    // Something to rotate?
    if(!DBG_ADDR(entry))
    {
        // Nope.
        return;
    }

    size_t lst = 0;

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
    for(entry_p contxt = DBG_ADDR(entry); contxt; contxt = contxt->parent)
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
    for(entry_p cur = DBG_ADDR(entry); cur; cur = cur->parent)
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
// Name:        get_fake_opt
// Description: Populate option cache using fake option.
// Input:       entry_p fake:   OPT_OPTIONAL or OPT_DELOPTS.
//              entry_p *cache: Option cache.
// Return:      -
//------------------------------------------------------------------------------
/*
static void get_fake_opt(entry_p fake, entry_p *cache)
{
    // Translate strings to options.
    for(size_t i = 0; exists(fake->children[i]); i++)
    {
        static entry_p save[OPT_LAST];

        // Cache may be invalidated by str().
        memcpy(save, cache, sizeof(entry_p) * OPT_LAST);
        char *name = str(fake->children[i]);
        memcpy(cache, save, sizeof(entry_p) * OPT_LAST);

        bool del = fake->children[i]->parent->id == OPT_DELOPTS;

        // Compare all strings unless the current option is deleted.
        if(cache[OPT_FAIL] != end() && !strcasecmp(name, "fail"))
        {
//dump(fake->children[i]);
            // Delete or set depending on parent.
            cache[OPT_FAIL] = del ? end() : fake->children[i];
        }
        else
        if(cache[OPT_FORCE] != end() && !strcasecmp(name, "force"))
        {
//dump(fake->children[i]);
            // Delete or set depending on parent.
            cache[OPT_FORCE] = del ? end() : fake->children[i];
        }
        else
        if(cache[OPT_NOFAIL] != end() && !strcasecmp(name, "nofail"))
        {
//dump(fake->children[i]);
            // Delete or set depending on parent.
            cache[OPT_NOFAIL] = del ? end() : fake->children[i];
        }
        else
        if(cache[OPT_ASKUSER] != end() && !strcasecmp(name, "askuser"))
        {
//dump(fake->children[i]);
            // Delete or set depending on parent.
            cache[OPT_ASKUSER] = del ? end() : fake->children[i];
        }
        else
        if(cache[OPT_OKNODELETE] != end() && !strcasecmp(name, "oknodelete"))
        {
//dump(fake->children[i]);
            // Delete or set depending on parent.
            cache[OPT_OKNODELETE] = del ? end() : fake->children[i];
        }
    }
}

//------------------------------------------------------------------------------
// Name:        prune_opt
// Description: Delete non applicable options.
// Input:       entry_p contxt: Execution context.
//              entry_p *cache: Option cache.
// Return:      -
//------------------------------------------------------------------------------
static void prune_opt(entry_p contxt, entry_p *cache)
{
    if(cache[OPT_CONFIRM])
    {
        // Make sure that we a prompt and help string.
        if(!cache[OPT_PROMPT] || !cache[OPT_HELP])
        {
            char * msg = cache[OPT_PROMPT] ? "help" : "prompt";
            ERR_C(native(contxt), ERR_MISSING_OPTION, msg);
        }

        // The default threshold is expert.
        int32_t level = get_num(contxt, "@user-level"), thres = LG_EXPERT;

        // Evaluate (confirm) if children exist.
        if(cache[OPT_CONFIRM]->children &&
           exists(cache[OPT_CONFIRM]->children[0]))
        {
            // Set new user threshold value.
            thres = num(cache[OPT_CONFIRM]);
        }

        // Clear cache[OPT_CONFIRM] if below threshold or fake 'yes' is set.
        if(level < thres || get_num(contxt, "@yes"))
        {
            cache[OPT_CONFIRM] = NULL;
        }
    }

    if(cache[OPT_ALL])
    {
        // The (all) option invalidates (files).
        cache[OPT_FILES] = NULL;
    }
}
*/
/*
//------------------------------------------------------------------------------
static void opt_fill_cache(entry_p contxt, entry_p *cache);
//------------------------------------------------------------------------------
// Name:        opt_push_cache
// Description: Push OPTION to cache.
// Input:       entry_p *option:  OPTION to be cached.
// Return:      -
//------------------------------------------------------------------------------
static void opt_push_cache(entry_p option, entry_p *cache)
{
    // Transform fake options to real options.
    if(option->id == OPT_OPTIONAL || option->id == OPT_DELOPTS)
    {
        get_fake_opt(option, cache);
    }
    */
    // Dynamic options must be resolved.
/*    else if(option->id == OPT_IFOPT || option->id == OPT_SELOPT)
    {
        static entry_p save[OPT_LAST];

        // Cache may be invalidated by resolve().
        memcpy(save, cache, sizeof(entry_p) * OPT_LAST);
        entry_p res = resolve(option);
        memcpy(cache, save, sizeof(entry_p) * OPT_LAST);

        if(res->type != OPTION)
        {
            // Non-existing conditional path.
            return;
        }

        // Cache all options if we're in a block.
        if(res->parent->type == CONTXT)
        {
            opt_fill_cache(res->parent, cache);
        }

        // Resolved value is a real option.
        cache[res->id] = res;
    }*/
    // Don't trust the caller.
   /*
    else if(option->id >= OPT_ALL && option->id < OPT_ASKUSER)
    {
        // Save real options as they are.
        cache[option->id] = option;
    }
    else
    {
        // Broken caller / parser.
        PANIC(option);
    }
}
*/

//------------------------------------------------------------------------------
// Name:        opt_clear_cache
// Description: Clear option cache while taking (delopts) into account.
// Input:       entry_p *cache:  Option cache.
// Return:      -
//------------------------------------------------------------------------------
/*
static void opt_clear_cache(entry_p *cache)
{
    // Reset all options that aren't affected by (delopts).
    for(size_t i = OPT_ALL; i < OPT_ASKUSER; i++)
    {
        cache[i] = NULL;
    }

    // Reset options affected by (delopts) unless they're deleted.
    for(size_t i = OPT_ASKUSER; i < OPT_INIT; i++)
    {
        // Sentinel value is used if deleted by (delopts).
        if(cache[i] != end())
        {
            cache[i] = NULL;
        }
    }

    // Set final sentinel.
    cache[OPT_INIT] = end();
}
*/
//------------------------------------------------------------------------------
// Name:        opt_fill_cache
// Description: Initialize option cache.
// Input:       entry_p *contxt:  Execution context.
// Return:      -
//------------------------------------------------------------------------------
/*
static void opt_fill_cache(entry_p contxt, entry_p *cache)
{
     // Naked option.
     if(contxt->type == OPTION)
     {
         // Push directly to cache.
         opt_push_cache(contxt, cache);

         // Check for embedded options.
 //      if(!contxt->children)
 //      {
              return;
  //     }
    }

    for(size_t i = 1; exists(C_ARG(i)); i++)
    {
        entry_p cur = C_ARG(i);

        if(cur->type == NATIVE)
        {
            // Save context.
            entry_p save[OPT_ASKUSER];
            memcpy(save, cache, sizeof(entry_p) * OPT_ASKUSER);

            cur = resolve(cur);

            // Restore context.
            memcpy(cache, save, sizeof(entry_p) * OPT_ASKUSER);
            opt(contxt, OPT_LAST);
        }

        if(cur->type != OPTION)
        {
            continue;
        }

    //    LG_ASSERT(cur->id >= OPT_ALL && cur->id < OPT_LAST, LG_VOID);
    //    draft[cur->id] = cur;
        opt_fill_cache(cur, cache);
    }
}*/

bool opt_init(entry_p contxt)
{

    for(size_t cur = 1; exists(C_ARG(cur)); cur++)
    {
        C_SYM(cur) = C_ARG(cur)->type == OPTION ?
        C_ARG(cur) : resolve(C_ARG(cur));
    }
    
    return NOT_ERR;
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
    for(size_t cur = 1; exists(C_SYM(cur)); cur++)
    {
        if(C_SYM(cur)->type == OPTION && C_SYM(cur)->id == (int32_t) type)
        {
            return C_SYM(cur);
        }
    }

    return NULL;
    /*
    static entry_p cache[OPT_LAST], last;

    // We need a valid context.
    if(!contxt || !contxt->children)
    {
        // Return cached value if permanently set (delopts).
        return cache[type] == end() ? end() : NULL;
    }

    // Restore context.
    if(type == OPT_LAST)
    {
        last = contxt;
        return end();
    }

    // Return cached value if cache is full.
    if(contxt == last)
    {
        return cache[type];
    }

    // Start fram scratch with new context.
    opt_clear_cache(cache);
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
    */
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
    if((num && !vec) || (contxt->type == NATIVE && (!contxt->resolved ||
       (contxt->resolved->type == STRING && !contxt->resolved->name))))
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
    return global(contxt) && x_sane(contxt, NATIVE, num);
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
    return global(contxt) && contxt->symbols &&
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
//              int32_t val:     The new value of the variable.
// Return:      -
//------------------------------------------------------------------------------
void set_num(entry_p contxt, char *var, int32_t val)
{
    // Dummy reference used for searching.
    static entry_t ref = { .type = SYMREF };

    // Validate input.
    LG_ASSERT(contxt && var, LG_VOID);

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
// Return:      int32_t:         The value of the variable or zero if the
//                               variable can't be found.
//------------------------------------------------------------------------------
int32_t get_num(entry_p contxt, char *var)
{
    // Validate input.
    LG_ASSERT(contxt && var, 0);

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
    // Validate input.
    LG_ASSERT(contxt && var, "");

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

    // Exit on OOM.
    LG_ASSERT(val, NULL);

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
// Name:        is_mergeable
// Description: Helper used by get_chlstr to determinet whether to concatenate
//              the string representation of a child or not.
// Input:       entry_p contxt: The context.
// Return:      bool:           If it's possible to cancatenate 'true', 'false'
//                              otherwise.
//------------------------------------------------------------------------------
static bool is_mergeable(entry_p entry)
{
    return entry != end() && entry->type != OPTION &&
           (!entry->resolved || (entry->resolved != end() &&
           entry->resolved->type != OPTION));
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
    LG_ASSERT(c_sane(contxt, 0), NULL);

    // Concatenation.
    entry_p *child = contxt->children;
    size_t cnt = 0;

    // We might not have any children.
    if(child)
    {
        // Count non context children.
        while(child && exists(*child))
        {
            cnt += is_mergeable(*child) ? 1 : 0;
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

    // Exit on OOM.
    LG_ASSERT(stv, NULL);

    // Total length.
    size_t len = 0;

    // Save all string pointers so that we don't evaluate children twice
    // and thereby set of side effects more than once.
    while(cnt > 0)
    {
        entry_p cur = *(--child);

        if(!is_mergeable(cur))
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
    // Validate input.
    LG_ASSERT(contxt && var, LG_VOID);

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
//              size_t indent:     Indentation level.
// Return:      -
//------------------------------------------------------------------------------
static void dump_indent(entry_p entry, size_t indent)
{
    // Indentation galore.
    char ind[16] = "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\0";

    // Going backwards to go forward.
    char *type = ind + sizeof(ind) - 1 - indent;
    type = type < ind ? ind : type;

    // NULL is a valid value.
    if(!entry)
    {
        OUT("NULL\n\n");
        return;
    }

    // Data type descriptions.
    char *tps[] = { "NUMBER", "STRING", "SYMBOL", "SYMREF", "NATIVE",
                    "OPTION", "CUSTOM", "CUSREF", "CONTXT", "DANGLE" };

    // All entries have a type, a parent and an ID.
    OUT("%s\n", tps[entry->type]);
    OUT("%sThis:%p\n", type, (void *) entry);
    OUT("%sParent:%p\n", type, (void *) entry->parent);
    OUT("%sId:\t%d\n", type, entry->id);

    // Most, but not all, have a name.
    if(entry->name)
    {
        OUT("%sName:\t%s\n", type, entry->name);
    }

     // Natives and cusrefs have callbacks.
    if(entry->call)
    {
        OUT("%sCall:\t%d\n", type, entry->call != NULL);
    }

    // Functions / symbols can be 'resolved'.
    if(entry->resolved)
    {
        OUT("%sRes:\t", type);

        // Pretty print the 'resolved' entry, last / default return value
        // and values refered to by symbols.
        dump_indent(entry->resolved, indent + 1);
    }

    // Pretty print all children.
    if(entry->children)
    {
        for(entry_p *chl = entry->children; exists(*chl); chl++)
        {
            OUT("%sChl:\t", type);
            dump_indent(*chl, indent + 1);
        }
    }

    // Pretty print all symbols.
    if(entry->symbols)
    {
        for(entry_p *sym = entry->symbols; exists(*sym); sym++)
        {
            OUT("%sSym:\t", type);
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
// Description: Used by DBG_ALLOC to provide more info when failing to allocate
//              memory and to fail deliberately when testing.
// Input:       int32_t line: Source code line.
//              const char *file: Source code file.
//              void *mem: Pointer to allocated memory.
// Return:      void *: Pointer to allocated memory or NULL.
//------------------------------------------------------------------------------
#if defined(FAIL_LINE_ALLOC) && defined(FAIL_FILE_ALLOC)
void *dbg_alloc(int32_t line, const char *file, void *mem)
{
    // Fail deliberately if file and line defines match.
    if(line == FAIL_LINE_ALLOC && !strcmp(file, FAIL_FILE_ALLOC))
    {
        free(mem);
        return NULL;
    }

    // No match. Pass this on.
    return mem;
}
#endif

//------------------------------------------------------------------------------
// Name:        dbg_fopen
// Description: Used by DBG_FOPEN to provide more info when failing to open
//              files and to fail deliberately when testing.
// Input:       int32_t line: Source code line.
//              const char *file: Source code file.
//              FILE *hand: File handle.
// Return:      FILE *: File handle or NULL.
//------------------------------------------------------------------------------
#if defined(FAIL_LINE_FOPEN) && defined(FAIL_FILE_FOPEN)
FILE *dbg_fopen(int32_t line, const char *file, FILE *hand)
{
    // Fail deliberately if file and line defines match.
    if(hand && line == FAIL_LINE_FOPEN && !strcmp(file, FAIL_FILE_FOPEN))
    {
        fclose(hand);
        return NULL;
    }

    // No match. Pass this on.
    return hand;
}
#endif

//------------------------------------------------------------------------------
// Name:        dbg_dopen
// Description: Used by DBG_DOPEN to provide more info when failing to open
//              directories and to fail deliberately when testing.
// Input:       int32_t line: Source code line.
//              const char *file: Source code file.
//              DIR *hand: Directory handle.
// Return:      DIR *: Directory handle or NULL.
//------------------------------------------------------------------------------
#if defined(FAIL_LINE_DOPEN) && defined(FAIL_FILE_DOPEN)
DIR *dbg_dopen(int32_t line, const char *file, DIR *hand)
{
    // Fail deliberately if file and line defines match.
    if(hand && line == FAIL_LINE_DOPEN && !strcmp(file, FAIL_FILE_DOPEN))
    {
        closedir(hand);
        return NULL;
    }

    // No match. Pass this on.
    return hand;
}
#endif

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
// Name:        num_entries
// Description: Get number of entries in vector.
// Input:       entry_p *vec: Vector containing children.
// Return:      size_t:       The number of children in vector.
//------------------------------------------------------------------------------
size_t num_entries(entry_p *vec)
{
    // Counter.
    size_t count = 0;

    while(vec && exists(vec[count]))
    {
        count++;
    }

    // Total count.
    return count;
}

//------------------------------------------------------------------------------
// Name:        ordo
// Description: Order positional children of context by moving non-positional
//              children (options) to the back.
// Input:       entry_p contxt: The execution context.
// Return:      context:        The same context with ordered children.
//------------------------------------------------------------------------------
entry_p ordo(entry_p contxt)
{
    for(size_t cur = 1; exists(C_ARG(cur)); cur++)
    {
        // Find the next option (if any).
        if(C_ARG(cur)->type == OPTION)
        {
            // Find the next non-option.
            for(size_t swp = cur + 1; exists(C_ARG(swp)); swp++)
            {
                if(C_ARG(swp)->type != OPTION)
                {
                    // Swap children and continue.
                    entry_p mov = C_ARG(cur);
                    C_ARG(cur) = C_ARG(swp);
                    C_ARG(swp) = mov;
                    cur = swp - 1;
                    break;
                }
            }
        }
    }

    // Fall through.
    return contxt;
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
//              int32_t def:      Default value used if translation fails.
// Return:      int32_t:              Numeric Userlevel.
//------------------------------------------------------------------------------
int32_t str_to_userlevel(const char *user, int32_t def)
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
