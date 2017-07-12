%{
#include <stdlib.h>
#include "types.h"
#include "parser.h"
#include "error.h"
#include "debug.h"

#ifdef _DEBUG
# define P(X) \
  TRACE("L:%s|%s|\n", #X, yytext)
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
    yylval.n = strtol(yytext, NULL, 10);      
    R(INT); 
}

    /*
    Hexadecimal numbers
    */
\$[0-9a-fA-F]+          { 
    yylval.n = strtol(yytext + 1, NULL, 16);  
    R(HEX); 
}

    /*
    Binary numbers
    */
%[01]+                  { 
    yylval.n = strtol(yytext + 1, NULL, 2);   
    R(BIN); 
}

    /*
    Syntactic markers
    */
"("                     { R('(');           }
")"                     { R(')');           }

    /*
    Builtin functions
    */
"="                     { R('=');           }
"<"                     { R('<');           }
"<="                    { R(LTE);           }
">"                     { R('>');           }
">="                    { R(GTE);           }
"+"                     { R('+');           }
"-"                     { R('-');           }
"*"                     { R('*');           }
"/"                     { R('/');           }
"AND"                   { R(AND);           }
"OR"                    { R(OR);            }
"XOR"                   { R(XOR);           }
"NOT"                   { R(NOT);           }
"BITAND"                { R(BITAND);        }
"BITOR"                 { R(BITOR);         }
"BITXOR"                { R(BITXOR);        }
"BITNOT"                { R(BITNOT);        }
"shiftleft"             { R(SHIFTLEFT);     }
"shiftright"            { R(SHIFTRIGHT);    }
"IN"                    { R(IN);            }
"set"                   { R(SET);           }
"procedure"             { R(DCL);           }
"if"                    { R(IF);            }
"while"                 { R(WHILE);         }
"until"                 { R(UNTIL);         }
"strlen"                { R(STRLEN);        }
"substr"                { R(SUBSTR);        }
"askdir"                { R(ASKDIR);        }
"askfile"               { R(ASKFILE);       }
"askstring"             { R(ASKSTRING);     }
"asknumber"             { R(ASKNUMBER);     }
"askchoice"             { R(ASKCHOICE);     }
"askoptions"            { R(ASKOPTIONS);    }
"askbool"               { R(ASKBOOL);       }
"askdisk"               { R(ASKDISK);       }
"cat"                   { R(CAT);           }
"exists"                { R(EXISTS);        }
"expandpath"            { R(EXPANDPATH);    }
"earlier"               { R(EARLIER);       }
"fileonly"              { R(FILEONLY);      }
"getassign"             { R(GETASSIGN);     }
"getdevice"             { R(GETDEVICE);     }
"getdiskspace"          { R(GETDISKSPACE);  }
"getenv"                { R(GETENV);        }
"getsize"               { R(GETSIZE);       }
"getsum"                { R(GETSUM);        }
"getversion"            { R(GETVERSION);    }
"iconinfo"              { R(ICONINFO);      }
"pathonly"              { R(PATHONLY);      }
"patmatch"              { R(PATMATCH);      }
"select"                { R(SELECT);        }
"symbolset"             { R(SYMBOLSET);     }
"symbolval"             { R(SYMBOLVAL);     }
"tackon"                { R(TACKON);        }
"transcript"            { R(TRANSCRIPT);    }
"complete"              { R(COMPLETE);      }
"user"                  { R(USER);          }
"working"               { R(WORKING);       }
"welcome"               { R(WELCOME);       }
"abort"                 { R(ABORT);         }
"all"                   { R(ALL);           }
"assigns"               { R(ASSIGNS);       }
"disk"                  { R(DISK);          }
"fonts"                 { R(FONTS);         }
"infos"                 { R(INFOS);         }
"newpath"               { R(NEWPATH);       }
"nogauge"               { R(NOGAUGE);       }
"noposition"            { R(NOPOSITION);    } 
"safe"                  { R(SAFE);          }
"swapcolors"            { R(SWAPCOLORS);    }
"resident"              { R(RESIDENT);      }

    /*
    Strings
    */
\"[^\"]*\"              { 
    yylval.s = strdup(yytext + 1); 
    yylval.s[yyleng - 2] = 0; 
    R(STR);        
}    

    /*
    Symbols
    */
[^" \n\t\(\)\+\*/]+    { 
    yylval.s = strdup(yytext); 
    R(SYM);        
}

    /*
    The bottom feeders
    */
\n                    { N(' '); yylineno++; }
[\t ]+                { N(' ');             }
;.*$                  { N(';');             }
%%

int yyerror(char *err)
{
    error(yylineno, err, yytext); 
    return 0;
}

