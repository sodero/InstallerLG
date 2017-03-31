%{
#include <stdio.h>
#include "builtin.h"

int yylex(void);
int yyerror(char *err);
%}

%union { char *s; int n; }

%token<s> SYM STR 
%token<n> INT HEX BIN 
%type<n> num plus

%%
s:      plus                    { printf("%d\n", $1); }
        ;

num:    INT                     { $$ = $1; } |
        HEX                     { $$ = $1; } |
        BIN                     { $$ = $1; } 
        ;

plus:   '(' '+' num num ')'     { $$ = plus($3, $4); }
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

