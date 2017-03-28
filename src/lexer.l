%{
#include "parser.h"

#ifdef DEBUG
# define PUT(X) printf("L:%s|%s|\n", #X, yytext)
#else
# define PUT(X)
#endif
#define RET(X) PUT(X); return X
#define NOT(X) PUT(X)
%}

%option noyywrap

%%
-?[0-9]+            { RET(INT); }
\$[0-9a-fA-F]+      { RET(HEX); }
%[01]+              { RET(BIN); }
\"[^\"]*\"          { RET(STR); }
[^" \n\t\(\)]+      { yylval.str = yytext ; RET(SYM); }
\(                  { RET('('); }
\)                  { RET(')'); }
[\n\t ]+            { NOT(' '); }
;.*$                { NOT(';'); }
%%

