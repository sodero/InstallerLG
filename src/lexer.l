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

%option noyywrap reentrant bison-bridge

%%
    /*
    Decimal numbers
    */
-?[0-9]+                { 
    yylval->n = strtol(yytext, NULL, 10);      
    R(INT); 
}

    /*
    Hexadecimal numbers
    */
\$[0-9a-fA-F]+          { 
    yylval->n = strtol(yytext + 1, NULL, 16);  
    R(HEX); 
}

    /*
    Binary numbers
    */
%[01]+                  { 
    yylval->n = strtol(yytext + 1, NULL, 2);   
    R(BIN); 
}

    /*
    Syntactic markers
    */
"("                     { R('(');            }
")"                     { R(')');            }

    /*
    Builtin functions
    */
"="                     { R('=');            }
"<"                     { R('<');            }
"<="                    { R(LTE);            }
">"                     { R('>');            }
">="                    { R(GTE);            }
"+"                     { R('+');            }
"-"                     { R('-');            }
"*"                     { R('*');            }
"/"                     { R('/');            }
"AND"                   { R(AND);            }
"OR"                    { R(OR);             }
"XOR"                   { R(XOR);            }
"NOT"                   { R(NOT);            }
"BITAND"                { R(BITAND);         }
"BITOR"                 { R(BITOR);          }
"BITXOR"                { R(BITXOR);         }
"BITNOT"                { R(BITNOT);         }
"shiftleft"             { R(SHIFTLEFT);      }
"shiftright"            { R(SHIFTRIGHT);     }
"IN"                    { R(IN);             }
"set"                   { R(SET);            }
"procedure"             { R(DCL);            }
"if"                    { R(IF);             }
"while"                 { R(WHILE);          }
"until"                 { R(UNTIL);          }
"strlen"                { R(STRLEN);         }
"substr"                { R(SUBSTR);         }
"askdir"                { R(ASKDIR);         }
"askfile"               { R(ASKFILE);        }
"askstring"             { R(ASKSTRING);      }
"asknumber"             { R(ASKNUMBER);      }
"askchoice"             { R(ASKCHOICE);      }
"askoptions"            { R(ASKOPTIONS);     }
"askbool"               { R(ASKBOOL);        }
"askdisk"               { R(ASKDISK);        }
"cat"                   { R(CAT);            }
"exists"                { R(EXISTS);         }
"expandpath"            { R(EXPANDPATH);     }
"earlier"               { R(EARLIER);        }
"fileonly"              { R(FILEONLY);       }
"getassign"             { R(GETASSIGN);      }
"getdevice"             { R(GETDEVICE);      }
"getdiskspace"          { R(GETDISKSPACE);   }
"getenv"                { R(GETENV);         }
"getsize"               { R(GETSIZE);        }
"getsum"                { R(GETSUM);         }
"getversion"            { R(GETVERSION);     }
"iconinfo"              { R(ICONINFO);       }
"pathonly"              { R(PATHONLY);       }
"patmatch"              { R(PATMATCH);       }
"select"                { R(SELECT);         }
"symbolset"             { R(SYMBOLSET);      }
"symbolval"             { R(SYMBOLVAL);      }
"tackon"                { R(TACKON);         }
"transcript"            { R(TRANSCRIPT);     }
"complete"              { R(COMPLETE);       }
"user"                  { R(USER);           }
"working"               { R(WORKING);        }
"welcome"               { R(WELCOME);        }
"abort"                 { R(ABORT);          }
"copyfiles"             { R(COPYFILES);      }
"copylib"               { R(COPYLIB);        }
"database"              { R(DATABASE);       }
"debug"                 { R(DEBUG);          }
"delete"                { R(DELETE);         }
"execute"               { R(EXECUTE);        }
"exit"                  { R(EXIT);           }
"foreach"               { R(FOREACH);        }
"makeassign"            { R(MAKEASSIGN);     }
"makedir"               { R(MAKEDIR);        }
"message"               { R(MESSAGE);        }
"onerror"               { R(ONERROR);        }
"protect"               { R(PROTECT);        }
"rename"                { R(RENAME);         }
"rexx"                  { R(REXX);           }
"run"                   { R(RUN);            }
"startup"               { R(STARTUP);        }
"textfile"              { R(TEXTFILE);       }
"tooltype"              { R(TOOLTYPE);       }
"trap"                  { R(TRAP);           }
"all"                   { R(ALL);            }
"append"                { R(APPEND);         }
"askuser"               { R(ASKUSER);        }
"assigns"               { R(ASSIGNS);        }
"choices"               { R(CHOICES);        }
"command"               { R(COMMAND);        }
"compression"           { R(COMPRESSION);    }
"confirm"               { R(CONFIRM);        }
"default"               { R(DEFAULT);        }
"delopts"               { R(DELOPTS);        }
"dest"                  { R(DEST);           }
"disk"                  { R(DISK);           }
"fail"                  { R(FAIL);           }
"files"                 { R(FILES);          }
"fonts"                 { R(FONTS);          }
"force"                 { R(FORCE);          }
"help"                  { R(HELP);           }
"infos"                 { R(INFOS);          }
"include"               { R(INCLUDE);        }
"newname"               { R(NEWNAME);        }
"newpath"               { R(NEWPATH);        }
"nofail"                { R(NOFAIL);         }
"nogauge"               { R(NOGAUGE);        }
"noposition"            { R(NOPOSITION);     } 
"noreq"                 { R(NOREQ);          } 
"oknodelete"            { R(OKNODELETE);     } 
"pattern"               { R(PATTERN);        }
"prompt"                { R(PROMPT);         }
"quiet"                 { R(QUIET);          }
"range"                 { R(RANGE);          }
"safe"                  { R(SAFE);           }
"setdefaulttool"        { R(SETDEFAULTTOOL); }
"setstack"              { R(SETSTACK);       }
"settooltype"           { R(SETTOOLTYPE);    }
"source"                { R(SOURCE);         }
"swapcolors"            { R(SWAPCOLORS);     }
"optional"              { R(OPTIONAL);       }
"resident"              { R(RESIDENT);       }

    /*
    Strings
    */
\"[^\"]*\"              { 
    yylval->s = strdup(yytext + 1); 
    yylval->s[yyleng - 2] = 0; 
    R(STR);        
}    

    /*
    Symbols
    */
[^" \n\t\(\)\+\*/]+    { 
    yylval->s = strdup(yytext); 
    R(SYM);        
}

    /*
    The bottom feeders
    */
\n                    { N(' '); yylineno++; }
[\t ]+                { N(' ');             }
;.*$                  { N(';');             }
%%

int yyerror(yyscan_t scanner, char *err)
{                                                                                                                                                                                                                                       
    int line = yyget_lineno(scanner); 
    char *who = yyget_text(scanner);
    error(line, err, who); 
    return 0;
}

int main(int argc, char **argv)
{
    yyscan_t lexer; 
    if(argc != 2)
    {
        printf("Syntax: installer <install script>\n"); 
        return 1; 
    }
    if(yylex_init(&lexer) == 0)
    {
        FILE *f = fopen(argv[1], "r");
        if(f)
        {
            yyset_in(f, lexer); 
            yyparse(lexer);
            yylex_destroy(lexer);
            fclose(f); 
            return 0; 
        }
        else
        {
            printf("Error: Could not open file '%s'\n", argv[1]); 
            yylex_destroy(lexer);
        }
    }
    else
    {
        printf("Unknown error\n"); 
    }
    return 1; 
}

