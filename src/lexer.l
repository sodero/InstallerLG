%{
//----------------------------------------------------------------------------
// lexer.l:
//
// InstallerNG tokenizer
//----------------------------------------------------------------------------
// Copyright (C) 2018, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//----------------------------------------------------------------------------

#include "args.h"
#include "error.h"
#include "parser.h"
#include "types.h"
#include "resource.h"
#include "lexer.h"

#include <stdlib.h>

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/* strduptr(const char *str) - Duplicate string and translate */
/* escpate characters according to the Installer V42.6 guide  */
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
static char *strduptr(const char *str);
%}
    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
    /* We need the parser to be reentrant, not */
    /* because we want to, but because it will */
    /* will leak memory otherwise.             */
    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
%option noyywrap reentrant bison-bridge caseless

%%
    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
    /*- decimal numbers ----------------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
-?[0-9]+(\.?[0-9]+)?    {
    yylval->n = (int32_t) strtoul(yytext, NULL, 10);
    return INT;
}

    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
    /*- hexadecimal numbers ------------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
\$[0-9a-fA-F]+          {
    yylval->n = (int32_t) strtoul(yytext + 1, NULL, 16);
    return HEX;
}

    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
    /*- binary numbers -----------------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
%[01]+                  {
    yylval->n = (int32_t) strtoul(yytext + 1, NULL, 2);
    return BIN;
}

    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
    /*- syntactic markers --------------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
"("                     { return '(';            }
")"                     { return ')';            }

    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
    /*- builting functions and options -------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
"="                     { return '=';            }
"<"                     { return '<';            }
"<="                    { return LTE;            }
">"                     { return '>';            }
">="                    { return GTE;            }
"<>"                    { return NEQ;            }
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
"reboot"                { return REBOOT;         }
"openwbobject"          { return OPENWBOBJECT;   }
"showwbobject"          { return SHOWWBOBJECT;   }
"closewbobject"         { return CLOSEWBOBJECT;  }
"all"                   { return ALL;            }
"append"                { return APPEND;         }
"assigns"               { return ASSIGNS;        }
"choices"               { return CHOICES;        }
"command"               { return COMMAND;        }
"compression"           { return COMPRESSION;    }
"confirm"               { return CONFIRM;        }
"default"               { return DEFAULT;        }
"delopts"               { return DELOPTS;        }
"dest"                  { return DEST;           }
"disk"                  { return DISK;           }
"files"                 { return FILES;          }
"fonts"                 { return FONTS;          }
"getdefaulttool"        { return GETDEFAULTTOOL; }
"getposition"           { return GETPOSITION;    }
"getstack"              { return GETSTACK;       }
"gettooltype"           { return GETTOOLTYPE;    }
"help"                  { return HELP;           }
"infos"                 { return INFOS;          }
"include"               { return INCLUDE;        }
"newname"               { return NEWNAME;        }
"newpath"               { return NEWPATH;        }
"nogauge"               { return NOGAUGE;        }
"noposition"            { return NOPOSITION;     }
"noreq"                 { return NOREQ;          }
"pattern"               { return PATTERN;        }
"prompt"                { return PROMPT;         }
"quiet"                 { return QUIET;          }
"range"                 { return RANGE;          }
"safe"                  { return SAFE;           }
"setdefaulttool"        { return SETDEFAULTTOOL; }
"setstack"              { return SETSTACK;       }
"settooltype"           { return SETTOOLTYPE;    }
"setposition"           { return SETPOSITION;    }
"source"                { return SOURCE;         }
"swapcolors"            { return SWAPCOLORS;     }
"optional"              { return OPTIONAL;       }
"resident"              { return RESIDENT;       }
"override"              { return OVERRIDE;       }

    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
    /*- strings ------------------------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
\"(\\.|[^"])*\"         |
'(\\.|[^'])*'           {
    yylval->s = strduptr(yytext);
    return STR;
}

    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
    /*- symbols ------------------------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
[^"' \n\t\(\)\+\*/]+    {
    yylval->s = strdup(yytext);
    return SYM;
}

    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
    /*- the bottom feeders -------------------------------------------------------------------------------------------------------------------------*/
    /*----------------------------------------------------------------------------------------------------------------------------------------------*/
\n                    { yylineno++;         }
[\t ]+                {                     }
;.*$                  {                     }
%%

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*- yyerror ----------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
int yyerror(yyscan_t scanner, const char *err)
{
    // Get line number and error info.
    int line = yyget_lineno(scanner);
    const char *info = yyget_text(scanner);

    // Print to stderr if we're executing
    // from shell, show dialogue if we're
    // executing from WB.
    if(arg_argc(-1))
    {
        // All details to stderr.
        fprintf(stderr, tr(S_SYNT), line, err, info);
    }
    else
    {
        // A slightly less detailed
        // graphical error report.
        error(NULL, line, ERR_PARSE, err);
    }

    // Return a bogus value, not the
    // number of bytes printed, like
    // the default yyerror function.
    return line;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*- main -------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
int main(int argc, char **argv)
{
    // Assume failure.
    int r = -1;

    // Initialize the argument handling. Transparent
    // handling of Workbench and CLI arguments.
    if(arg_init(argc, argv))
    {
        yyscan_t lexer;

        // Allocate and initialize whatever the lexer
        // needs. Reentrant, see comment at the top.
        if(yylex_init(&lexer) == 0)
        {
            // Get the name of the script from CLI
            // or tooltypes / wb.
            char *n = arg_get(ARG_SCRIPT);
            FILE *f = fopen(n, "r");

            if(f)
            {
                // Set input file and parse.
                yyset_in(f, lexer);

                // Save parser return value.
                r = yyparse(lexer);

                // r = 1 on syntax error.
                // r = 0 on success.

                // Close the input file.
                fclose(f);
            }
            else
            {
                // We can't read from the file.
                fprintf(stderr, tr(S_CNOF), n);
            }

            // Free all resources allocated by
            // the lexer.
            yylex_destroy(lexer);
        }
        else
        {
            // We most likely ran out of memory.
            fprintf(stderr, "%s\n", tr(S_UNER));
        }

        // Free all resources allocated by
        // the argument handling routines.
        arg_done();
    }

#ifdef AMIGA
    // Translate value of r to the appropriate
    // Amiga DOS return value. Syntax error is
    // an ERROR and file not found / readable
    // a FAIL.
    return (!r ? r :
           (r == 1 ? RETURN_ERROR : RETURN_FAIL));
#else
    // Ignore syntax error on non Amiga systems.
    return (r == 1 ? 0 : r);
#endif
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/* strduptr(const char *str) - Duplicate string and translate */
/* escpate characters according to the Installer V42.6 guide  */
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
static char *strduptr(const char *str)
{
    /* Installer.guide 1.19 (29.4.96) 1995-96 by ESCOM AG
     -------------------------------------------------------
    `\n' newline character
    `\r' return character
    `\t' tab character
    `\h' horizontal tab character (V42.6)
    `\v' vertical tab character (V42.6)
    `\b' backspace character (V42.6)
    `\f' formfeed character (V42.6)
    `\"' double quote
    `\'' single quote
    `\\' backslash
    `\ooo' some octal number `ooo' (V42.6)
    `\xXX' some hex number `XX' (V42.6) */
    int len = strlen(str);

    // Translations
    static char chr[] = "nrthvbf\"'\\\0";
    static char raw[] = "\n\r\t\t\v\b\f\"'\\\0";

    // Please note 'len -1', we strip the " from the string
    // at this point, str index starts at 1 and we skip the
    // last character.
    char *out = calloc(len - 1, 1);

    if(out)
    {
        int io = 0;

        for(int i = 1; i < len - 1; i++)
        {
            char cr = str[i];

            // Are we dealing with a control character?
            if(str[i] == '\\' &&
               i + 1 < len - 1)
            {
                // Are we within the limits of the string?
                if(i + 3 < len - 1)
                {
                    // Is this a hex number that needs to be
                    // translated into a character?
                    if(str[i + 1] == 'x' && (
                      ((str[i + 2] >= 48 && str[i + 2] <= 57) ||
                       (str[i + 2] >= 65 && str[i + 2] <= 70) ||
                       (str[i + 2] >= 97 && str[i + 2] <= 102)) &&
                      ((str[i + 3] >= 48 && str[i + 3] <= 57) ||
                       (str[i + 3] >= 65 && str[i + 3] <= 70) ||
                       (str[i + 3] >= 97 && str[i + 3] <= 102))))
                    {
                        // Temporary string for conversion
                        char h[] =
                        {
                            str[i + 2],
                            str[i + 3],
                            '\0'
                        };

                        // Three digits, \ooo.
                        i += 3;

                        // Convert temp string to character.
                        out[io++] = (char) strtol(h, NULL, 16);

                        // Continue with the rest of the string.
                        continue;
                    }
                    // Is this a oct number that needs to be
                    // translated into a character?
                    if(str[i + 1] >= 48 && str[i + 1] <= 55 &&
                       str[i + 2] >= 48 && str[i + 2] <= 55 &&
                       str[i + 3] >= 48 && str[i + 3] <= 55)
                    {
                        // Temporary string for conversion
                        char h[] =
                        {
                            str[i + 1],
                            str[i + 2],
                            str[i + 3],
                            '\0'
                        };

                        // Two digits + 'x', \xXX.
                        i += 3;

                        // Convert temp string to character.
                        out[io++] = (char) strtol(h, NULL, 8);

                        // Continue with the rest of the string.
                        continue;
                    }
                }

                // Standard escape sequence.
                for(int j = 0;
                    chr[j]; j++)
                {
                    // A direct mapping between the current
                    // character and the value representing
                    // the full escape sequence.
                    if(str[i + 1] == chr[j])
                    {
                        i++;
                        cr = raw[j];
                        break;
                    }
                }
            }

            // Copy input to ouput. The 'cr' might have
            // been translated, maybe it's just a copy.
            out[io++] = cr;
        }
    }

    // Unless we're out of memory,
    // out will be a copy of str.
    return out;
}

