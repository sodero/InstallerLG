%{

#include <stdlib.h>
#include "parser.h"

#if 0
# define P(X) printf("L:%s|%s|\n", #X, yytext)
#else
# define P(X)
#endif
#define R(X) P(X); return X
#define N(X) P(X)
%}

%option noyywrap

%%
-?[0-9]+            { yylval.n = strtol(yytext, NULL, 10);      return INT; }
\$[0-9a-fA-F]+      { yylval.n = strtol(yytext + 1, NULL, 16);  return HEX; }
%[01]+              { yylval.n = strtol(yytext + 1, NULL, 2);   return BIN; }

\"[^\"]*\"          { return STR; }
[^" \n\t\(\)\+]+    { return SYM; }

"("                 { return '('; }
")"                 { return ')'; }
"+"                 { return '+'; }

[\n\t ]+            ; 
;.*$                ; 

%%

