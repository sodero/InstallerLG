%{
#include <stdio.h>
#include "types.h"
#include "builtin.h"

int yylex(void);
int yyerror(char *err);
%}

%token<val.str> SYM STR 
%token<val.num> INT HEX BIN AND OR XOR NOT BITAND BITOR BITXOR BITNOT SHIFTLEFT SHIFTRIGHT
%type<val.num> n np vp add sub mul div and or xor not bitand bitor bitxor bitnot shiftleft shiftright

%%
s:          s vp                        { printf("%d\n", $2);       } |
            vp                          { printf("%d\n", $1);       }
            ;

vp:         add                         { $$ = $1;                  } |
            sub                         { $$ = $1;                  } |
            mul                         { $$ = $1;                  } |
            div                         { $$ = $1;                  } |
            and                         { $$ = $1;                  } |
            or                          { $$ = $1;                  } |
            xor                         { $$ = $1;                  } |
            not                         { $$ = $1;                  } |
            bitand                      { $$ = $1;                  } |
            bitor                       { $$ = $1;                  } |
            bitxor                      { $$ = $1;                  } |
            bitnot                      { $$ = $1;                  } |
            shiftleft                   { $$ = $1;                  } |
            shiftright                  { $$ = $1;                  } 
            ;

np:         n                           { $$ = $1;                  } 
            ;

n:          INT                         { $$ = $1;                  } |
            HEX                         { $$ = $1;                  } |
            BIN                         { $$ = $1;                  } 
            ;

add:        '(' '+' np np ')'           { $$ = add($3, $4);         } 
            ;

sub:        '(' '-' np np ')'           { $$ = sub($3, $4);         } 
            ;

mul:        '(' '*' np np ')'           { $$ = mul($3, $4);         } 
            ;

div:        '(' '/' np np ')'           { $$ = div($3, $4);         } 
            ;

and:        '(' AND np np ')'           { $$ = and($3, $4);         } 
            ;

or:         '(' OR np np ')'            { $$ = or($3, $4);          } 
            ;

xor:        '(' XOR np np ')'           { $$ = xor($3, $4);         } 
            ;

not:        '(' NOT np ')'              { $$ = not($3);             } 
            ;

bitand:     '(' BITAND np np ')'        { $$ = bitand($3, $4);      } 
            ;

bitor:      '(' BITOR np np ')'         { $$ = bitor($3, $4);       } 
            ;

bitxor:     '(' BITXOR np np ')'        { $$ = bitxor($3, $4);      } 
            ;

bitnot:     '(' BITNOT np ')'           { $$ = bitnot($3);          } 
            ;

shiftleft:  '(' SHIFTLEFT np np ')'     { $$ = shiftleft($3, $4);   } 
            ;

shiftright: '(' SHIFTRIGHT np np ')'    { $$ = shiftright($3, $4);  } 
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

