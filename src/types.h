#ifndef TYPES_H_
#define TYPES_H_

typedef struct entry_s * entry_p;
typedef entry_p (*call_t) (entry_p *);

struct entry_s
{
    enum 
    {
        NUMBER,
        STRING, 
        SYMBOL,
        NATIVE, 
        CUSTOM, 
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
            call_t call; 
            entry_p *args; 
        } native; 
        struct 
        {
            char *name; 
            call_t call; 
            entry_p *args; 
        } custom; 
    } value; 
}; 

typedef struct entry_s entry_t; 



#endif
