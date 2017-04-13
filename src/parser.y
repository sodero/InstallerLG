%{
#include <stdio.h>
#include "types.h"
#include "builtin.h"

static size_t i = 0;
static entry_t stack[255];

int yylex(void);
int yyerror(char *err);
%}

%token<value.str> SYM STR 
%token<value.num> INT HEX BIN AND OR XOR NOT BITAND BITOR BITXOR BITNOT SHIFTLEFT SHIFTRIGHT

/*
%type<value.num> np vp add sub mul div and or xor not bitand bitor bitxor bitnot shiftleft shiftright
%type<> n
*/

%type<value> vp np 
%type<value.num> add n 

%%
evaluate:   s { s(2); /*eval s w. n arg*/} 

s:          s { s(1); /*1 more arg*/ } vp |
            { s(0); /*new s + 1 arg*/ } vp 
            ;

vp:         add  { $$.num = $1; printf("%d\n", $$.num); } 
            ;

np:         n    { $$.num = $1; } 
            ;

n:          INT |
            HEX |
            BIN                          
            ;

add:        '(' '+' np np ')' { $$ = add($3.num, $4.num); } 
            ;
%%

int main(int argc, char **argv)
{
    yyparse();
}

int yyerror(char *err)
{
    fprintf(stderr, "%s\n", err);
    return 0;
}

