#ifndef TYPES_H_
#define TYPES_H_

#define YYSTYPE entry_t
typedef struct entry_s * entry_p;

struct entry_s
{
    enum 
    {
        NUMBER,
        STRING, 
        SYMBOL, // Hmm
        BUILTIN, 
    } type;

    union
    {
        int num; 
        char *str; 
        struct 
        {
            char *name; 
            entry_p data; 
        } variable; 
        struct 
        {
            entry_p *args; 
            entry_p (*call) (entry_p);
        } builtin; 
        struct 
        {
            char *name; 
            entry_p *args; 
            entry_p (*call) (entry_p);
        } procedure; 
    } value; 
}; 

typedef struct entry_s entry_t; 



#endif
