//----------------------------------------------------------------------------
// util.c: 
//
// Misc utility functions primarily used by the 'native' methods.
//----------------------------------------------------------------------------

#include "alloc.h"
#include "eval.h"
#include "util.h"

#include <limits.h> 
#include <stdio.h>
#include <string.h>

#ifdef AMIGA
#include <clib/debug_protos.h>
#define DBG(...) KPrintF((CONST_STRPTR)__VA_ARGS__)
#else
#define DBG(...) fprintf(stderr, __VA_ARGS__)
#endif

//----------------------------------------------------------------------------
// Name:        ror
// Description: Rotate array of entries to the right.
// Input:       entry_p *e: Array of entries.
// Return:      -
//----------------------------------------------------------------------------
void ror(entry_p *e)
{
    // We have an array and it contains something.
    if(e && *e)
    {
        int i = 0; 

        // Let 'i' be the index of the last entry. 
        while(e[i] && e[i] != end())
        {
            i++; 
        }
        i--; 

        // Nothing to do if we have < 2 entries.
        if(i > 0)
        {
            // Save the last entry.
            entry_p f = e[i]; 

            // Shift the rest to the right. 
            while(i)
            {
                e[i] = e[i - 1]; 
                i--; 
            }

            // Put the saved entry first.
            e[0] = f; 
        }
    }
}

//----------------------------------------------------------------------------
// Name:        local
// Description: Find the next context going upwards in the tree.
// Input:       entry_p e:  The starting point.
// Return:      entry_p:    The closest context found, or 
//                          NULL if no context was found. 
//----------------------------------------------------------------------------
entry_p local(entry_p e)
{
    // Go upwards until we find what we're
    // looking for, or hit the (broken) top. 
    for(; e && 
        e->type != CONTXT && 
        e->type != CUSTOM 
        ; e = e->parent);

    // Something or NULL: 
    return e; 
}

//----------------------------------------------------------------------------
// Name:        global
// Description: Find the root context. 
// Input:       entry_p e:  The starting point.
// Return:      entry_p:    The root context, or NULL
//                          if no context was found. 
//----------------------------------------------------------------------------
entry_p global(entry_p e)
{
    // Go upwards until we can't go 
    // any further.
    for(e = local(e); 
        e && local(e->parent); 
        e = local(e->parent)); 

    // Something or NULL: 
    return e; 
}

//----------------------------------------------------------------------------
// Name:        get_opt
// Description: Find option of a given type in a context.
// Input:       entry_p c:  The context to search in. 
//              opt_t t:    The type of option to search for.
// Return:      entry_p:    An OPTION entry if found, NULL otherwise.
//----------------------------------------------------------------------------
entry_p get_opt(entry_p c, opt_t t)
{
    // We need a context. 
    if(c && c != end() &&
       c->children)
    {
        // And we need children.
        entry_p *v = c->children;

        // Real option or (optional)?
        if(c->type != OPTION)
        {
            // Iterate over all options.
            while(*v && *v != end())
            {
                // ID == the type of option.
                if((*v)->type == OPTION)
                {
                    if(((opt_t) (*v)->id) == t)
                    {
                        // We found it.
                        return *v; 
                    }
                }
                
                // Nope, next. 
                v++; 
            }
        }
        // An (optional) string. 
        else
        {
            // Iterate over all strings.
            while(*v && *v != end())
            {
                if((t == OPT_FAIL && !strcmp(str(*v), "fail")) ||
                   (t == OPT_FORCE && !strcmp(str(*v), "force")) ||
                   (t == OPT_NOFAIL && !strcmp(str(*v), "nofail")) ||
                   (t == OPT_ASKUSER && !strcmp(str(*v), "askuser")) ||
                   (t == OPT_OKNODELETE && !strcmp(str(*v), "oknodelete")))
                {
                    return *v;
                }
                    
                // Nope, next. 
                v++; 
            }
        }
    }

    // Nothing found.
    return NULL; 
}

//----------------------------------------------------------------------------
// Name:        c_sane
// Description: Context sanity check used by the NATIVE functions to verify
//              that we have atleast the number of children needed and that 
//              these are valid. If this fails, it typically, but not always,
//              means that we have a parser problem.
// Input:       entry_p c:  The context. 
//              size_t n:   The number of children necessary.  
// Return:      int:        1 if context is valid, 0 otherwise. 
//----------------------------------------------------------------------------
int c_sane(entry_p c, size_t n)
{
    // Assume success; 
    int status = 1; 

    // All contexts used by NATIVE functions must allocate an
    // array for children, it could be empty though. 
    if(c && c->children)
    {
        // Expect atleast n children. 
        for(size_t i = 0; 
            i < n; i++)
        {
            // Assume failure; 
            status = 0; 

            // Make sure that something exists.
            if(c->children[i] == NULL)
            {
                DBG("c->children[%lu] == NULL\n", i);
                break;
            }

            // Make sure that it's not a sentinel.
            if(c->children[i] == end())
            {
                DBG("c->children[%lu] == end()\n", i);
                break;
            }

            // Make sure that it belongs to us. 
            if(c->children[i]->parent != c)
            {
                DBG("c->children[%lu]->parent != %p\n", i, (void *) c);
                break;
            }

            // Make sure that all NATIVE functions have
            // a default return value. 
            if(c->type == NATIVE && !c->resolved)
            {
                DBG("c->type == NATIVE && !c->resolved\n"); 
                break;
            }
            
            // We're OK; 
            status = 1; 
        }
    }
    else
    {
        // Badly broken.
        status = 0; 
        DBG("!c || !c->children\n");
    }

    // Did we fail? 
    if(!status)
    {
        // Additional debugging info.
        pretty_print(c); 
    }

    return status; 
}

//----------------------------------------------------------------------------
// Name:        s_sane
// Description: Context sanity check used by the NATIVE functions to verify
//              that we have atleast the number of symbols needed and that 
//              these are valid. If this fails it typically, but not always,
//              means that we have a parser problem.
// Input:       entry_p c:  The context. 
//              size_t n:   The number of symbols necessary.  
// Return:      int:        1 if context is valid, 0 otherwise. 
//----------------------------------------------------------------------------
int s_sane(entry_p c, size_t n)
{
    // Assume success; 
    int status = 1; 

    if(c && c->symbols)
    {
        // Expect atleast n symbols. 
        for(size_t i = 0; 
            i < n; i++)
        {
            // Assume failure; 
            status = 0; 

            // Make sure that somethings exists.
            if(c->symbols[i] == NULL)
            {
                DBG("c->symbols[%lu] == NULL\n", i);
                break;
            }

            // Make sure that it's not a sentinel.
            if(c->symbols[i] == end())
            {
                DBG("c->symbols[%lu] == end()\n", i);
                break;
            }

            // Make sure that it belongs to us. 
            if(c->symbols[i]->parent != c)
            {
                DBG("c->symbols[%lu]->parent != %p\n", i, (void *) c);
                break;
            }

            // We're OK; 
            status = 1; 
        }
    }
    else
    {
        // Badly broken.
        status = 0; 
        DBG("!c || !c->symbols\n");
    }

    return status; 
}

//----------------------------------------------------------------------------
// Name:        set_numvar
// Description: Give an existing numerical variable a new value. Please note
//              that the variable must exist and that the current resolved
//              value must be a NUMBER, if not, this function will silently
//              fail. 
// Input:       entry_p c:  The context. 
//              char *v:    The name of the variable.   
//              int n:      The new value of the variable. 
// Return:      -
//----------------------------------------------------------------------------
void set_numvar(entry_p c, char *v, int n)
{
    // We need a name and a context. 
    if(c && v)
    {
        // Dummy reference used to find
        // the variable.
        entry_p s; 
        static entry_t ref = { .type = SYMREF }; 

        // Name and reparent dummy. 
        ref.name = v; 
        ref.parent = c; 

        // Find whatever 'v' is. 
        s = find_symbol(&ref);

        // This should be a symbol.
        if(s && s->type == SYMBOL)
        {
            // And it should be a resolved
            // numerical one. 
            if(s->resolved &&
               s->resolved->type == NUMBER)
            {
                // Success. 
                s->resolved->id = n;
                return; 
            }
        }
    }

    // Failure. 
}

//----------------------------------------------------------------------------
// Name:        get_numvar
// Description: Get the value of an existing numerical variable. Please note
//              that the variable must exist and that the current resolved
//              value must be a NUMBER.
// Input:       entry_p c:  The context. 
//              char *v:    The name of the variable.   
// Return:      int:        The value of the variable or zero if the variable
//                          can't be found.  
//----------------------------------------------------------------------------
int get_numvar(entry_p c, char *v)
{
    // We need a name and a context. 
    if(c && v)
    {
        // Dummy reference used to find
        // the variable.
        entry_p s; 
        static entry_t ref = { .type = SYMREF }; 

        // Name and reparent dummy. 
        ref.name = v; 
        ref.parent = c; 

        // Find whatever 'v' is. 
        s = find_symbol(&ref);

        // This should be a symbol.
        if(s && s->type == SYMBOL)
        {
            // And it should be a resolved
            // numerical one. 
            if(s->resolved &&
               s->resolved->type == NUMBER)
            {
                // Success.
                return s->resolved->id; 
            }
        }
    }

    // Failure. 
    return 0; 
}

//----------------------------------------------------------------------------
// Name:        get_strvar
// Description: Get the value of an existing string variable. Please note
//              that the variable must exist and that the current resolved
//              value must be a STRING.
// Input:       entry_p c:  The context. 
//              char *v:    The name of the variable.   
// Return:      char *:     The value of the variable or an empty string if 
//                          the variable can't be found.  
//----------------------------------------------------------------------------
char *get_strvar(entry_p c, char *v)
{
    // We need a name and a context. 
    if(c && v)
    {
        // Dummy reference used to find
        // the variable.
        entry_p s; 
        static entry_t ref = { .type = SYMREF }; 

        // Name and reparent dummy. 
        ref.name = v; 
        ref.parent = c; 

        // Find whatever 'v' is. 
        s = find_symbol(&ref);

        // This should be a symbol.
        if(s && s->type == SYMBOL)
        {
            // And it should be a resolved
            // string. 
            if(s->resolved &&
               s->resolved->name &&
               s->resolved->type == STRING)
            {
                // Success.
                return s->resolved->name; 
            }
        }
    }

    // Failure. 
    return ""; 
}

//----------------------------------------------------------------------------
// Name:        set_strvar
// Description: Give an existing string variable a new value. Please note
//              that the variable must exist and that the current resolved
//              value must be a STRING, if not, this function will silently
//              fail. 
// Input:       entry_p c:  The context. 
//              char *v:    The name of the variable.   
//              char *n:    The new value of the variable. 
// Return:      -
//----------------------------------------------------------------------------
void set_strvar(entry_p c, char *v, char *n)
{
    // We need a name and a context. 
    if(c && v)
    {
        // Dummy reference used to find
        // the variable.
        entry_p s; 
        static entry_t ref = { .type = SYMREF }; 

        // Name and reparent dummy. 
        ref.name = v; 
        ref.parent = c; 

        // Find whatever 'v' is. 
        s = find_symbol(&ref);

        // This should be a symbol.
        if(s && s->type == SYMBOL)
        {
            // And it should be a resolved
            // STRING. 
            if(s->resolved &&
               s->resolved->type == STRING)
            {
                // Taking ownership of 'n'. 
                free(s->resolved->name); 
                s->resolved->name = n; 
            }
        }
    }
}

//----------------------------------------------------------------------------
// Name:        pp_aux
// Description: Refer to pretty_print below. 
// Input:       entry_p entry:  The tree to print.  
//              int indent:     Indentation level.
// Return:      -
//----------------------------------------------------------------------------
static void pp_aux(entry_p entry, int indent)
{
    // Indentation galore. 
    static char t[16] = "\t\t\t\t"
                        "\t\t\t\t"
                        "\t\t\t\t"
                        "\t\t\t\0"; 
    
    // Going backwards to go forward. 
    char *ts = t + sizeof(t) - 1 - indent; 
    ts = ts < t ? t : ts; 

    // Data type descriptions. 
    static char *tps[] = 
    {
        "NUMBER",
        "STRING", 
        "SYMBOL",
        "SYMREF",
        "NATIVE", 
        "OPTION", 
        "CUSTOM", 
        "CUSREF", 
        "CONTXT",
        "STATUS",
        "DANGLE"
    };

    // NULL is a valid value.
    if(entry)
    {
        // All entries have a type, a parent and an ID.
        DBG("%s\n", tps[entry->type]);
        DBG("%sThis:%p\n", ts, (void *) entry);
        DBG("%sParent:%p\n", ts, (void *) entry->parent);
        DBG("%sId:\t%d\n", ts, entry->id);

        // Most, but not all, have a name.
        if(entry->name) 
        {
            DBG("%sName:\t%s\n", ts, entry->name);
        }

        // Functions / symbols can be 'resolved'.
        if(entry->resolved) 
        {
            DBG("%sRes:\t", ts);

            // Pretty print the 'resolved' entry, 
            // last / default return value and 
            // values refered to by symbols. 
            pp_aux(entry->resolved, indent + 1);
        }

        // Pretty print all children.
        if(entry->children) 
        {
            entry_p *e = entry->children;

            while(*e && *e != end())
            {
                DBG("%sChl:\t", ts); 
                pp_aux(*e, indent + 1); 
                e++; 
            }
        }

        // Pretty print all symbols.
        if(entry->symbols) 
        {
            entry_p *e = entry->symbols;

            while(*e && *e != end())
            {
                DBG("%sSym:\t", ts); 
                pp_aux(*e, indent + 1); 
                e++; 
            }
        }
    }
    else
    {
        DBG("NULL\n\n");
    }
}

//----------------------------------------------------------------------------
// Name:        pretty_print
// Description: Pretty print the complete tree in 'entry'.
// Input:       entry_p entry:  The tree to print.  
// Return:      -
//----------------------------------------------------------------------------
void pretty_print(entry_p entry)
{
    // Start with no indentation.
    pp_aux(entry, 0); 
}

#define LG_BUFSIZ ((BUFSIZ > PATH_MAX ? BUFSIZ : PATH_MAX) + 1)

//----------------------------------------------------------------------------
// Name:        get_buf
// Description: Get pointer to temporary buffer.
// Input:       - 
// Return:      char *: Buffer pointer.
//----------------------------------------------------------------------------
char *get_buf(void)
{
    static char buf[LG_BUFSIZ];
    return buf; 
}

//----------------------------------------------------------------------------
// Name:        buf_size
// Description: Get size of temporary buffer.
// Input:       - 
// Return:      size_t: Buffer size.
//----------------------------------------------------------------------------
size_t buf_size(void)
{
    return LG_BUFSIZ - 1; 
}

