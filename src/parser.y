%{
#include <stdio.h>

int yylex(void);
int yyerror(char *err);
%}

%union { char *str; }
%token ALPHA

%%
s:      '(' ALPHA ')'         { printf("not empty\n"); } |
        '(' ')'               { printf("empty\n");     } 
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

