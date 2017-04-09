#ifndef TYPES_H_
#define TYPES_H_

#define YYSTYPE node_t

typedef enum 
{
    STRING, 
    SYMBOL, 
    NUMBER
} data_t;

typedef struct
{
    union
    {
        int num; 
        char *str; 
    } val; 
    data_t type; 
} node_t; 

#endif
