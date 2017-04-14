%{
#include <stdio.h>
#include "builtin.h"

entry_p q; 

int yylex(void);
int yyerror(char *err);
%}

%union 
{
    int n; 
    char *s; 
    entry_p e;
}

%token<s> SYM STR 
%token<n> INT HEX BIN 
%token AND OR XOR NOT BITAND BITOR BITXOR BITNOT SHIFTLEFT SHIFTRIGHT

/*
%type<value.num> np vp add sub mul div and or xor not bitand bitor bitxor bitnot shiftleft shiftright
%type<> n
*/

%type<e> s vp np n add

%%
entry:      s { eval ($1); kill ($1); } 

s:          s { /*1 more arg*/ } vp |
            vp { $$ = create_s(); push ($$, $1); push ($$, $1); } 
            ;

vp:         add   
            ;

np:         n     
            ;

n:          INT  { $$ = create_num ($1); } |
            HEX  { $$ = create_num ($1); } |
            BIN  { $$ = create_num ($1); }                        
            ;

add:        '(' '+' np np ')' { $$ = $3;  m_add($3->value.num, $4->value.num); } 
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

