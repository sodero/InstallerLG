%{
#include <stdlib.h>
#include "types.h"
#include "parser.h"

#ifdef _DEBUG
# define P(X) printf("L:%s|%s|\n", #X, yytext)
#else
# define P(X)
#endif
#define R(X) P(X); return X
#define N(X) P(X)
%}

%option noyywrap

%%
-?[0-9]+                { yylval.val.num = strtol(yytext, NULL, 10);      R(INT); }
\$[0-9a-fA-F]+          { yylval.val.num = strtol(yytext + 1, NULL, 16);  R(HEX); }
%[01]+                  { yylval.val.num = strtol(yytext + 1, NULL, 2);   R(BIN); }

"("                     { R('(');        }
")"                     { R(')');        }
"+"                     { R('+');        }
"-"                     { R('-');        }
"*"                     { R('*');        }
"/"                     { R('/');        }

"AND"                   { R(AND);        }
"OR"                    { R(OR);         }
"XOR"                   { R(XOR);        }
"NOT"                   { R(NOT);        }
"BITAND"                { R(BITAND);     }
"BITOR"                 { R(BITOR);      }
"BITXOR"                { R(BITXOR);     }
"BITNOT"                { R(BITNOT);     }
"shiftleft"             { R(SHIFTLEFT);  }
"shiftright"            { R(SHIFTRIGHT); }
"IN"                    { R(IN);         }

\"[^\"]*\"              { R(STR);        }    
[^" \n\t\(\)\+\*/-]+    { R(SYM);        }

[\n\t ]+                { N(' ');        }
;.*$                    { N(';');        }
%%
