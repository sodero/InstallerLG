%{
#include <stdio.h>
#include "builtin.h"

int yylex(void);
int yyerror(char *err);
%}

%union { char *s; int n; }

%token<s> SYM STR 
%token<n> INT HEX BIN 
%type<n> num add sub mul div

%%
s:      add                     { printf("%d\n", $1); } |
        sub                     { printf("%d\n", $1); } |
        mul                     { printf("%d\n", $1); } |
        div                     { printf("%d\n", $1); } 
        ;

num:    INT                     { $$ = $1; } |
        HEX                     { $$ = $1; } |
        BIN                     { $$ = $1; } 
        ;

add:    '(' '+' num num ')'     { $$ = add($3, $4); }
        ;

sub:    '(' '-' num num ')'     { $$ = sub($3, $4); }
        ;

mul:    '(' '*' num num ')'     { $$ = mul($3, $4); }
        ;

div:    '(' '/' num num ')'     { $$ = div($3, $4); }
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

