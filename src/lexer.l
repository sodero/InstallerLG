%{
#include <stdlib.h>
#include "types.h"
#include "parser.h"
#include "error.h"
#include "debug.h"
#include "lexer.h"
%}

%option noyywrap reentrant bison-bridge

%%
    /*
    Decimal numbers
    */
-?[0-9]+                { 
    yylval->n = strtol(yytext, NULL, 10);      
    return INT; 
}

    /*
    Hexadecimal numbers
    */
\$[0-9a-fA-F]+          { 
    yylval->n = strtol(yytext + 1, NULL, 16);  
    return HEX; 
}

    /*
    Binary numbers
    */
%[01]+                  { 
    yylval->n = strtol(yytext + 1, NULL, 2);   
    return BIN; 
}

    /*
    Syntactic markers
    */
"("                     { return '(';            }
")"                     { return ')';            }

    /*
    Builtin functions
    */
"="                     { return '=';            }
"<"                     { return '<';            }
"<="                    { return LTE;            }
">"                     { return '>';            }
">="                    { return GTE;            }
"+"                     { return '+';            }
"-"                     { return '-';            }
"*"                     { return '*';            }
"/"                     { return '/';            }
"AND"                   { return AND;            }
"OR"                    { return OR;             }
"XOR"                   { return XOR;            }
"NOT"                   { return NOT;            }
"BITAND"                { return BITAND;         }
"BITOR"                 { return BITOR;          }
"BITXOR"                { return BITXOR;         }
"BITNOT"                { return BITNOT;         }
"shiftleft"             { return SHIFTLEFT;      }
"shiftright"            { return SHIFTRIGHT;     }
"IN"                    { return IN;             }
"set"                   { return SET;            }
"procedure"             { return DCL;            }
"if"                    { return IF;             }
"while"                 { return WHILE;          }
"until"                 { return UNTIL;          }
"strlen"                { return STRLEN;         }
"substr"                { return SUBSTR;         }
"askdir"                { return ASKDIR;         }
"askfile"               { return ASKFILE;        }
"askstring"             { return ASKSTRING;      }
"asknumber"             { return ASKNUMBER;      }
"askchoice"             { return ASKCHOICE;      }
"askoptions"            { return ASKOPTIONS;     }
"askbool"               { return ASKBOOL;        }
"askdisk"               { return ASKDISK;        }
"cat"                   { return CAT;            }
"exists"                { return EXISTS;         }
"expandpath"            { return EXPANDPATH;     }
"earlier"               { return EARLIER;        }
"fileonly"              { return FILEONLY;       }
"getassign"             { return GETASSIGN;      }
"getdevice"             { return GETDEVICE;      }
"getdiskspace"          { return GETDISKSPACE;   }
"getenv"                { return GETENV;         }
"getsize"               { return GETSIZE;        }
"getsum"                { return GETSUM;         }
"getversion"            { return GETVERSION;     }
"iconinfo"              { return ICONINFO;       }
"pathonly"              { return PATHONLY;       }
"patmatch"              { return PATMATCH;       }
"select"                { return SELECT;         }
"symbolset"             { return SYMBOLSET;      }
"symbolval"             { return SYMBOLVAL;      }
"tackon"                { return TACKON;         }
"transcript"            { return TRANSCRIPT;     }
"complete"              { return COMPLETE;       }
"user"                  { return USER;           }
"working"               { return WORKING;        }
"welcome"               { return WELCOME;        }
"abort"                 { return ABORT;          }
"copyfiles"             { return COPYFILES;      }
"copylib"               { return COPYLIB;        }
"database"              { return DATABASE;       }
"debug"                 { return DEBUG;          }
"delete"                { return DELETE;         }
"execute"               { return EXECUTE;        }
"exit"                  { return EXIT;           }
"foreach"               { return FOREACH;        }
"makeassign"            { return MAKEASSIGN;     }
"makedir"               { return MAKEDIR;        }
"message"               { return MESSAGE;        }
"onerror"               { return ONERROR;        }
"protect"               { return PROTECT;        }
"rename"                { return RENAME;         }
"rexx"                  { return REXX;           }
"run"                   { return RUN;            }
"startup"               { return STARTUP;        }
"textfile"              { return TEXTFILE;       }
"tooltype"              { return TOOLTYPE;       }
"trap"                  { return TRAP;           }
"all"                   { return ALL;            }
"append"                { return APPEND;         }
"askuser"               { return ASKUSER;        }
"assigns"               { return ASSIGNS;        }
"choices"               { return CHOICES;        }
"command"               { return COMMAND;        }
"compression"           { return COMPRESSION;    }
"confirm"               { return CONFIRM;        }
"default"               { return DEFAULT;        }
"delopts"               { return DELOPTS;        }
"dest"                  { return DEST;           }
"disk"                  { return DISK;           }
"fail"                  { return FAIL;           }
"files"                 { return FILES;          }
"fonts"                 { return FONTS;          }
"force"                 { return FORCE;          }
"help"                  { return HELP;           }
"infos"                 { return INFOS;          }
"include"               { return INCLUDE;        }
"newname"               { return NEWNAME;        }
"newpath"               { return NEWPATH;        }
"nofail"                { return NOFAIL;         }
"nogauge"               { return NOGAUGE;        }
"noposition"            { return NOPOSITION;     } 
"noreq"                 { return NOREQ;          } 
"oknodelete"            { return OKNODELETE;     } 
"pattern"               { return PATTERN;        }
"prompt"                { return PROMPT;         }
"quiet"                 { return QUIET;          }
"range"                 { return RANGE;          }
"safe"                  { return SAFE;           }
"setdefaulttool"        { return SETDEFAULTTOOL; }
"setstack"              { return SETSTACK;       }
"settooltype"           { return SETTOOLTYPE;    }
"source"                { return SOURCE;         }
"swapcolors"            { return SWAPCOLORS;     }
"optional"              { return OPTIONAL;       }
"resident"              { return RESIDENT;       }
"override"              { return OVERRIDE;       }

    /*
    Strings
    */
\"[^\"]*\"              { 
    yylval->s = strdup(yytext + 1); 
    yylval->s[yyleng - 2] = 0; 
    return STR;        
}    

    /*
    Symbols
    */
[^" \n\t\(\)\+\*/]+    { 
    yylval->s = strdup(yytext); 
    return SYM;        
}

    /*
    The bottom feeders
    */
\n                    { yylineno++;         }
[\t ]+                {                     }
;.*$                  {                     }
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

