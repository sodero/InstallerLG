%{
#include <stdio.h>
#include "builtin.h"

int yylex(void);
int yyerror(char *err);
%}

%union { char *s; int n; }

%token<s> SYM STR 
%token<n> INT HEX BIN AND OR XOR NOT BITAND BITOR BITXOR BITNOT SHIFTLEFT SHIFTRIGHT
%type<n> num add sub mul div and or xor not bitand bitor bitxor bitnot shiftleft shiftright 

%%
s:          add                         { printf("%d\n", $1);       } |
            sub                         { printf("%d\n", $1);       } |
            mul                         { printf("%d\n", $1);       } |
            div                         { printf("%d\n", $1);       } |
            and                         { printf("%d\n", $1);       } |
            or                          { printf("%d\n", $1);       } |
            xor                         { printf("%d\n", $1);       } |
            not                         { printf("%d\n", $1);       } |
            bitand                      { printf("%d\n", $1);       } |
            bitor                       { printf("%d\n", $1);       } |
            bitxor                      { printf("%d\n", $1);       } |
            bitnot                      { printf("%d\n", $1);       } |
            shiftleft                   { printf("%d\n", $1);       } |
            shiftright                  { printf("%d\n", $1);       } 
            ;

num:        INT                         { $$ = $1;                  } |
            HEX                         { $$ = $1;                  } |
            BIN                         { $$ = $1;                  } 
            ;

add:        '(' '+' num num ')'         { $$ = add($3, $4);         }
            ;

sub:        '(' '-' num num ')'         { $$ = sub($3, $4);         }
            ;

mul:        '(' '*' num num ')'         { $$ = mul($3, $4);         }
            ;

div:        '(' '/' num num ')'         { $$ = div($3, $4);         }
            ;

and:        '(' AND num num ')'         { $$ = and($3, $4);         }
            ;

or:         '(' OR num num ')'          { $$ = or($3, $4);          }
            ;

xor:        '(' XOR num num ')'         { $$ = xor($3, $4);         }
            ;

not:        '(' NOT num ')'             { $$ = not($3);             }
            ;

bitand:     '(' BITAND num num ')'      { $$ = bitand($3, $4);      }
            ;

bitor:      '(' BITOR num num ')'       { $$ = bitor($3, $4);       }
            ;

bitxor:     '(' BITXOR num num ')'      { $$ = bitxor($3, $4);      }
            ;

bitnot:     '(' BITNOT num ')'          { $$ = bitnot($3);          }
            ;

shiftleft: '(' SHIFTLEFT num num ')'    { $$ = shiftleft($3, $4);   }
            ;

shiftright: '(' SHIFTRIGHT num num ')'  { $$ = shiftright($3, $4);  }
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

