%{
#include <stdio.h>
#include "native.h"

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

%type<e> s p vp np v n 
%type<e> add

%%
entry:      s    
            { 
                eval ($1); 
                kill ($1);           
            } 

s:          s vp 
            { 
                push ($$, $2);                  
            } 
            |
            vp   
            { 
                $$ = new_s();   
                push ($$, $1);    
            } 
            ;

p:          vp 
            |
            np
            ;

vp:         v  
            ;

np:         n     
            ;

v:          add
            ;

n:          INT  
            { 
                $$ = new_number ($1); 
            } 
            |
            HEX  
            { 
                $$ = new_number ($1); 
            } 
            |
            BIN  
            { 
                $$ = new_number ($1); 
            }                        
            ;

add:        '(' '+' p p ')' 
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

