#ifndef TYPES_H_
#define TYPES_H_

#define YYSTYPE node_t

typedef enum 
{
    STRING, 
    SYMBOL, 
    NUMBER
} data_t;

typedef union
{
    int num; 
    char *str; 
} value_t; 

typedef struct
{
    value_t val; 
    data_t type; 
} node_t; 

#endif
