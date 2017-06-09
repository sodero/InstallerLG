#ifndef TYPES_H_
#define TYPES_H_

#define BUFSIZE 256
#define SENTINEL ((entry_p) push)

typedef struct entry_s * entry_p;
typedef entry_p (*call_t) (entry_p);

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
        CUSREF, 
        CONTXT,
        STATUS,
        DANGLE,
    } type;

    short id; 
    char *name; 
    call_t call; 
    entry_p expression; 
    entry_p resolved; 
    entry_p *children; 
    entry_p *symbols; 
    entry_p parent; 
}; 

typedef struct entry_s entry_t; 

#endif
