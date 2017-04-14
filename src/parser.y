%{
#include <stdio.h>
#include "native.h"

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
entry:      s    { eval ($1); kill ($1);           } 

s:          s vp { push ($$, $2);                  } |
            vp   { $$ = new_s(); push ($$, $1); } 
            ;

vp:         add   
            ;

np:         n     
            ;

n:          INT  { $$ = new_number ($1); } |
            HEX  { $$ = new_number ($1); } |
            BIN  { $$ = new_number ($1); }                        
            ;

add:        '(' '+' np np ')' 
            { 
                $$ = new_native (m_add, 2); 
                push ($$, $3);  
                push ($$, $4);  
            } 
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

