%{
#include "parser.h"
%}

%option noyywrap

%%
"("         { return '('; }
")"         { return ')'; }
.           {             }
%%

