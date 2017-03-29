%{
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
-?[0-9]+            { yylval.n = atoi(yytext) ; R(INT); }
\$[0-9a-fA-F]+      { R(HEX); }
%[01]+              { R(BIN); }
\"[^\"]*\"          { R(STR); }
[^" \n\t\(\)\+]+    { R(SYM); }
"("                 { R('('); }
")"                 { R(')'); }
"+"                 { R('+'); }
[\n\t ]+            { N(' '); }
;.*$                { N(';'); }

%%

