%{
#include <stdio.h>
#include <string.h>
#include "debug.h"
#include "native.h"
#include "eval.h"
#include "util.h"
#include "sysenv.h"

int yylex(void);
int yyerror(char *err);

extern int yylineno; 
%}

%union 
{
    int n; 
    char *s; 
    entry_p e;
}

%token                      SET DCL IF WHILE
%token                      AND OR XOR NOT LTE GTE
%token                      BITAND BITOR BITXOR BITNOT 
%token                      SHIFTLEFT SHIFTRIGHT IN
%token                      STRLEN SUBSTR
%token<s>                   SYM STR 
%destructor { free($$); }   SYM STR
%token<n>                   INT HEX BIN 

%type<e>                    start 
%destructor { run($$);  }   start 
%type<e>                    s p pp ps vp vps vpb np sp sps par cv cvv
%destructor { kill($$); }   s p pp ps vp vps vpb np sp sps par cv cvv
%type<e>                    add sub div mul lt lte gt gte eq set cus dcl fmt if while
%destructor { kill($$); }   add sub div mul lt lte gt gte eq set cus dcl fmt if while
%type<e>                    and or xor not bitand bitor bitxor bitnot shiftleft shiftright in
%destructor { kill($$); }   and or xor not bitand bitor bitxor bitnot shiftleft shiftright in
%type<e>                    strlen substr 
%destructor { kill($$); }   strlen substr

%%
start:      s                       { $$ = init($1); };
s:          vps                     ;
p:          vp                      |
            np                      ;
pp:         p p                     { $$ = push(push(new_contxt(), $1), $2); };
ps:         ps p                    { $$ = push($1, $2); } |
            p                       { $$ = push(new_contxt(), $1); };
vps:        vps vp                  { $$ = push($1, $2); } |
            vp                      { $$ = push(new_contxt(), $1); };
vpb:        '(' vps ')'             { $$ = $2; } |
            vp                      ;
np:         INT                     { $$ = new_number($1); } |
            HEX                     { $$ = new_number($1); } |
            BIN                     { $$ = new_number($1); } |
            STR                     { $$ = new_string($1); } |
            SYM                     { $$ = new_symref($1, yylineno); };
sp:         SYM p                   { $$ = new_symbol($1, $2); };
sps:        sps sp                  { $$ = push($1, $2); } |
            sp                      { $$ = push(new_contxt(), $1); };
par:        par SYM                 { $$ = push($1, new_symbol($2, new_dangle())); } |
            SYM                     { $$ = push(new_contxt(), new_symbol($1, new_dangle())); };
cv:         p vpb                   { $$ = push(push(new_contxt(), $1), $2); };
cvv:        p vpb vpb               { $$ = push(push(push(new_contxt(), $1), $2), $3); };
vp:         add                     |
            sub                     |
            div                     |
            mul                     |
            lt                      |
            lte                     |
            gt                      |
            gte                     |
            eq                      |
            set                     |
            cus                     |
            dcl                     |
            fmt                     |
            if                      |
            while                   |
            and                     |
            or                      |
            xor                     |
            not                     |
            bitand                  |
            bitor                   |
            bitxor                  |
            bitnot                  |
            shiftleft               | 
            shiftright              |
            in                      | 
            strlen                  | 
            substr                  ;
fmt:        '(' STR ps ')'          { $$ = new_native($2, yylineno, m_fmt, $3); } |
            '(' STR ')'             { $$ = new_native($2, yylineno, m_fmt, NULL); };
dcl:        '(' DCL SYM par s ')'   { $$ = new_custom($3, yylineno, $4, $5); } |
            '(' DCL SYM s ')'       { $$ = new_custom($3, yylineno, NULL, $4); };
cus:        '(' SYM ps ')'          { $$ = new_cusref($2, yylineno, $3); } |
            '(' SYM ')'             { $$ = new_cusref($2, yylineno, NULL); };
add:        '(' '+' ps ')'          { $$ = new_native(strdup("+"), yylineno, m_add, $3); };
mul:        '(' '*' ps ')'          { $$ = new_native(strdup("*"), yylineno, m_mul, $3); };
sub:        '(' '-' pp ')'          { $$ = new_native(strdup("-"), yylineno, m_sub, $3); };
div:        '(' '/' pp ')'          { $$ = new_native(strdup("/"), yylineno, m_div, $3); };
lt:         '(' '<' pp ')'          { $$ = new_native(strdup("<"), yylineno, m_lt, $3); };
lte:        '(' LTE pp ')'          { $$ = new_native(strdup("<="), yylineno, m_lte, $3); };
gt:         '(' '>' pp ')'          { $$ = new_native(strdup(">"), yylineno, m_gt, $3); };
gte:        '(' GTE pp ')'          { $$ = new_native(strdup(">="), yylineno, m_gte, $3); };
eq:         '(' '=' pp ')'          { $$ = new_native(strdup("="), yylineno, m_eq, $3); };
set:        '(' SET sps ')'         { $$ = new_native(strdup("set"), yylineno, m_set, $3); };
if:         '(' IF cvv ')'          { $$ = new_native(strdup("if"), yylineno, m_if, $3); };
while:      '(' WHILE cv ')'        { $$ = new_native(strdup("while"), yylineno, m_while, $3); };
and:        '(' AND pp ')'          { $$ = new_native(strdup("AND"), yylineno, m_and, $3); }; 
or:         '(' OR pp ')'           { $$ = new_native(strdup("OR"), yylineno, m_or, $3); }; 
xor:        '(' XOR pp ')'          { $$ = new_native(strdup("XOR"), yylineno, m_xor, $3); }; 
not:        '(' NOT p ')'           { $$ = new_native(strdup("NOT"), yylineno, m_not, push(new_contxt(), $3)); }; 
bitand:     '(' BITAND pp ')'       { $$ = new_native(strdup("BITAND"), yylineno, m_bitand, $3); }; 
bitor:      '(' BITOR pp ')'        { $$ = new_native(strdup("BITOR"), yylineno, m_bitor, $3); }; 
bitxor:     '(' BITXOR pp ')'       { $$ = new_native(strdup("BITXOR"), yylineno, m_bitxor, $3); }; 
bitnot:     '(' BITNOT p ')'        { $$ = new_native(strdup("BITNOT"), yylineno, m_bitnot, push(new_contxt(), $3)); }; 
shiftleft:  '(' SHIFTLEFT pp ')'    { $$ = new_native(strdup("shiftleft"), yylineno, m_shiftleft, $3); }; 
shiftright: '(' SHIFTRIGHT pp ')'   { $$ = new_native(strdup("shiftright"), yylineno, m_shiftright, $3); }; 
in:         '(' IN ps ')'           { $$ = new_native(strdup("IN"), yylineno, m_in, $3); }; 
strlen:     '(' STRLEN p ')'        { $$ = new_native(strdup("strlen"), yylineno, m_strlen, push(new_contxt(), $3)); }; 
substr:     '(' SUBSTR ps ')'       { $$ = new_native(strdup("substr"), yylineno, m_substr, $3); }; 
%%

int main(int argc, char **argv)
{
    yyparse();
    leak_check();
}

