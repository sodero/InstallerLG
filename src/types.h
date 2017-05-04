#ifndef TYPES_H_
#define TYPES_H_

#define ENTRIES 64 
#define BUFSIZE 256
#define SENTINEL ((entry_p) push)

typedef struct entry_s * entry_p;
typedef entry_p (*call_t) (entry_p *);

struct entry_s
{
    enum 
    {
        NUMBER,
        STRING, 
        SYMBOL,
        SYMREF,
        NATIVE, 
        CUSTOM, 
        CONTXT,
        STATUS,
    } type;
    union
    {
        int number; 
        char *string; 
        struct 
        {
            char *name; 
            entry_p data; 
        } symbol; 
        struct 
        {
            char *name; 
            int line; 
        } symref; 
        struct 
        {
            call_t call; 
            entry_p *args; 
        } native; 
        struct 
        {
            char *name; 
            call_t call; 
            entry_p *args; 
        } custom; 
        struct 
        {
            entry_p *syms; 
            entry_p *args; 
        } contxt; 
        struct 
        {
            char *name; 
            int value; 
        } status; 
    } value; 
    entry_p parent; 
}; 

typedef struct entry_s entry_t; 



#endif
