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
    /*
    Decimal numbers
    */
-?[0-9]+                { 
    yylval.val.num = strtol(yytext, NULL, 10);      
    yylval.type = NUMBER; 
    R(INT); 
}

    /*
    Hexadecimal numbers
    */
\$[0-9a-fA-F]+          { 
    yylval.val.num = strtol(yytext + 1, NULL, 16);  
    yylval.type = NUMBER; 
    R(HEX); 
}

    /*
    Binary numbers
    */
%[01]+                  { 
    yylval.val.num = strtol(yytext + 1, NULL, 2);   
    yylval.type = NUMBER; 
    R(BIN); 
}

    /*
    Operators
    */
"("                     { R('(');        }
")"                     { R(')');        }
"+"                     { R('+');        }
"-"                     { R('-');        }
"*"                     { R('*');        }
"/"                     { R('/');        }

    /*
    Builtin functions
    */
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

    /*
    Strings
    */
\"[^\"]*\"              { 
    yylval.val.str = yytext; // Who's copying?
    yylval.type = STRING; 
    R(STR);        
}    

    /*
    Symbols
    */
[^" \n\t\(\)\+\*/-]+    { 
    yylval.val.str = yytext; // Who's copying?
    yylval.type = SYMBOL; 
    R(SYM);        
}

    /*
    The bottom feeders
    */
[\n\t ]+                { N(' ');        }
;.*$                    { N(';');        }
%%
