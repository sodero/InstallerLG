#include <stdio.h>
#include "util.h"
#include "debug.h"
#include "alloc.h"

void eval_print(entry_p entry)
{
    if(entry)
    {
        if(entry->type == NUMBER)
        {
            printf ("%d\n", entry->id);
        }
        else if(entry->type == STRING)
        {
            printf ("%s\n", entry->name);
        }
    }
    else
    {
        printf ("NULL\n");
    }
    return;     
}

static char *tabs(unsigned int n)
{
    static char t[16]; 
    n = n < sizeof(t) ? n : sizeof(t); 
    for(t[n] = '\0'; n--; t[n] = '\t'); 
    return t; 
}

void print_list(entry_p *entry)
{
    if(entry)
    {
        printf ("List:%p\n", (void *) entry);
        while(*entry != end())
        {
            printf ("Item:%p\n", (void *) *entry);
            entry++; 
        }
    }
    else
    {
        printf ("List:NULL\n");
    }
}

void short_print(entry_p entry)
{
    if(entry)
    {
        printf("T:%p P:%p Type:%d Id:%d Name:%s\n", 
                (void *) entry, 
                (void *) entry->parent, 
                entry->type, 
                entry->id, 
                entry->name ? entry->name : "-");
    }
    else
    {
        printf ("NULL\n\n");
        return; 
    }
}


void pretty_print(entry_p entry)
{
    static unsigned int ind = 0; 
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
    if(entry)
    {
        printf("%s\n", tps[entry->type]);
        printf("%sThis:%p\n", tabs(ind), (void *) entry);
        printf("%sParent:%p\n", tabs(ind), (void *) entry->parent);
        printf("%sId:\t%d\n", tabs(ind), entry->id);
        if(entry->name) 
        {
            printf("%sName:\t%s\n", tabs(ind), entry->name);
        }
        if(entry->resolved) 
        {
            printf ("%sRes:\t", tabs(ind));
            ind++; 
            pretty_print (entry->resolved);
            ind--; 
        }
        if(entry->children) 
        {
            entry_p *e = entry->children;
            if(e && *e)
            {
                while(*e && *e != end())
                {
                    printf ("%sChl:\t", tabs(ind)); 
                    ind++; 
                    pretty_print(*e); 
                    ind--; 
                    e++; 
                }
            }
        }
        if(entry->symbols) 
        {
            entry_p *e = entry->symbols;
            if(e && *e)
            {
                while(*e && *e != end())
                {
                    printf ("%sSym:\t", tabs(ind)); 
                    ind++; 
                    pretty_print(*e); 
                    ind--; 
                    e++; 
                }
            }
        }
    }
    else
    {
        printf ("NULL\n\n");
        return; 
    }
}

void ror(entry_p *e)
{
    if(e && *e)
    {
        int i = 0; 
        while(e[i] && e[i] != end())
        {
            i++; 
        }
        i--; 
        if(i)
        {
            entry_p f = e[i]; 
            while(i)
            {
                e[i] = e[i - 1]; 
                i--; 
            }
            e[0] = f; 
        }
    }
}

entry_p local(entry_p e)
{
    for(; e && 
        e->type != CONTXT && 
        e->type != CUSTOM 
        ; e = e->parent);
    return e; 
}

entry_p global(entry_p e)
{
    for(e = local(e); 
        local(e->parent); 
        e = local(e->parent)); 
    return e; 
}

entry_p get_opt(entry_p c, opt_t t)
{
    if(c && 
       c != end() &&
       c->children)
    {
        entry_p *v = c->children;
        while(*v && *v != end())
        {
            if((*v)->type == OPTION &&
               (*v)->id == t)
            {
                return *v; 
            }
            v++; 
        }
    }
    return NULL; 
}

int c_sane(entry_p c, size_t n)
{
    if(c && c->children)
    {
        for(size_t i = 0; 
            i < n; i++)
        {
            if(c->children[i] == NULL ||
               c->children[i] == end() ||
               c->children[i]->parent != c)
            {
                return 0; 
            } 
        }
        return 1; 
    }
    return 0; 
}

int s_sane(entry_p c, size_t n)
{
    if(c && c->symbols)
    {
        for(size_t i = 0; 
            i < n; i++)
        {
            if(c->symbols[i] == NULL ||
               c->symbols[i] == end() ||
               c->symbols[i]->parent != c)
            {
                return 0; 
            } 
        }
        return 1; 
    }
    return 0; 
}

