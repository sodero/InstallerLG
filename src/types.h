#ifndef TYPES_H_
#define TYPES_H_

#define SYMSIZE 8 
#define BUFSIZE 256
#define SENTINEL ((entry_p) push)

typedef struct entry_s * entry_p;
typedef entry_p (*call_t) (entry_p);
typedef enum 
{ 
    ALL,
    RESIDENT, 
    NOREQ, 

} opt_t; 
typedef enum 
{
    NUMBER,
    STRING, 
    SYMBOL,
    SYMREF,
    NATIVE, 
    OPTION, 
    CUSTOM, 
    CUSREF, 
    CONTXT,
    STATUS,
    DANGLE
} type_t;

struct entry_s
{
    type_t type; 
    int id; 
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
