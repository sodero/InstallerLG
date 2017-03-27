%{
#include "parser.h"
%}

%option noyywrap

%%
[\t\n ]+    ;
"("         { return '(';                        }
")"         { return ')';                        }
[a-zA-Z]+   { yylval.str = yytext; return ALPHA; }
.           ; 
%%

