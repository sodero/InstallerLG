%{
#include <stdio.h>
#include "builtin.h"

entry_p start; 

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
evaluate:   s { start = create_s (); 
                m_s (start); 
                destroy (start); 
              } 

s:          s { /*1 more arg*/ } vp |
            { /*new s + 1 arg*/ } vp 
            ;

vp:         add  { $$.num = $1; printf("%d\n", $$.num); } 
            ;

np:         n    { $$.num = $1; } 
            ;

n:          INT |
            HEX |
            BIN                          
            ;

add:        '(' '+' np np ')' { $$ = m_add($3.num, $4.num); } 
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

