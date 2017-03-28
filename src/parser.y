%{
#include <stdio.h>

int yylex(void);
int yyerror(char *err);
%}

%union { char *str; int num; }
%token<num> INT HEX BIN
%token<str> SYM STR
%type<str> var

%%
s:      '(' SYM ')'         { printf("P:%s\n", $2); } 
        ;
%%

int main(int argc, char **argv)
{
    yyparse();
}

int yyerror(char *err)
{
    fprintf(stderr, "err:%s\n", err);
    return 0;
}

