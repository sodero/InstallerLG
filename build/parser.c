/* A Bison parser, made by GNU Bison 3.6.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "../src/parser.y"

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* parser.y:                                                                                                                                                                            */
/*                                                                                                                                                                                      */
/* InstallerLG parser                                                                                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Copyright (C) 2018-2020, Ola Söder. All rights reserved.                                                                                                                             */
/* Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1                                                                                                                             */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include "all.h"
#include "alloc.h"
#include "eval.h"
#include "init.h"
#include "lexer.h"
#include "util.h"

#include <string.h>

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Always debug.                                                                                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define YYDEBUG 1

#line 96 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SYM = 258,                     /* SYM  */
    STR = 259,                     /* STR  */
    OOM = 260,                     /* OOM  */
    INT = 261,                     /* INT  */
    HEX = 262,                     /* HEX  */
    BIN = 263,                     /* BIN  */
    EQ = 264,                      /* EQ  */
    GT = 265,                      /* GT  */
    GTE = 266,                     /* GTE  */
    LT = 267,                      /* LT  */
    LTE = 268,                     /* LTE  */
    NEQ = 269,                     /* NEQ  */
    IF = 270,                      /* IF  */
    SELECT = 271,                  /* SELECT  */
    UNTIL = 272,                   /* UNTIL  */
    WHILE = 273,                   /* WHILE  */
    TRACE = 274,                   /* TRACE  */
    RETRACE = 275,                 /* RETRACE  */
    ASTRAW = 276,                  /* ASTRAW  */
    ASBRAW = 277,                  /* ASBRAW  */
    ASBEVAL = 278,                 /* ASBEVAL  */
    EVAL = 279,                    /* EVAL  */
    OPTIONS = 280,                 /* OPTIONS  */
    EXECUTE = 281,                 /* EXECUTE  */
    REXX = 282,                    /* REXX  */
    RUN = 283,                     /* RUN  */
    ABORT = 284,                   /* ABORT  */
    EXIT = 285,                    /* EXIT  */
    ONERROR = 286,                 /* ONERROR  */
    TRAP = 287,                    /* TRAP  */
    REBOOT = 288,                  /* REBOOT  */
    COPYFILES = 289,               /* COPYFILES  */
    COPYLIB = 290,                 /* COPYLIB  */
    DELETE = 291,                  /* DELETE  */
    EXISTS = 292,                  /* EXISTS  */
    FILEONLY = 293,                /* FILEONLY  */
    FOREACH = 294,                 /* FOREACH  */
    MAKEASSIGN = 295,              /* MAKEASSIGN  */
    MAKEDIR = 296,                 /* MAKEDIR  */
    PROTECT = 297,                 /* PROTECT  */
    STARTUP = 298,                 /* STARTUP  */
    TEXTFILE = 299,                /* TEXTFILE  */
    TOOLTYPE = 300,                /* TOOLTYPE  */
    TRANSCRIPT = 301,              /* TRANSCRIPT  */
    RENAME = 302,                  /* RENAME  */
    COMPLETE = 303,                /* COMPLETE  */
    DEBUG = 304,                   /* DEBUG  */
    MESSAGE = 305,                 /* MESSAGE  */
    USER = 306,                    /* USER  */
    WELCOME = 307,                 /* WELCOME  */
    WORKING = 308,                 /* WORKING  */
    AND = 309,                     /* AND  */
    BITAND = 310,                  /* BITAND  */
    BITNOT = 311,                  /* BITNOT  */
    BITOR = 312,                   /* BITOR  */
    BITXOR = 313,                  /* BITXOR  */
    NOT = 314,                     /* NOT  */
    IN = 315,                      /* IN  */
    OR = 316,                      /* OR  */
    SHIFTLEFT = 317,               /* SHIFTLEFT  */
    SHIFTRIGHT = 318,              /* SHIFTRIGHT  */
    XOR = 319,                     /* XOR  */
    CLOSEMEDIA = 320,              /* CLOSEMEDIA  */
    EFFECT = 321,                  /* EFFECT  */
    SETMEDIA = 322,                /* SETMEDIA  */
    SHOWMEDIA = 323,               /* SHOWMEDIA  */
    DATABASE = 324,                /* DATABASE  */
    EARLIER = 325,                 /* EARLIER  */
    GETASSIGN = 326,               /* GETASSIGN  */
    GETDEVICE = 327,               /* GETDEVICE  */
    GETDISKSPACE = 328,            /* GETDISKSPACE  */
    GETENV = 329,                  /* GETENV  */
    GETSIZE = 330,                 /* GETSIZE  */
    GETSUM = 331,                  /* GETSUM  */
    GETVERSION = 332,              /* GETVERSION  */
    ICONINFO = 333,                /* ICONINFO  */
    QUERYDISPLAY = 334,            /* QUERYDISPLAY  */
    CUS = 335,                     /* CUS  */
    DCL = 336,                     /* DCL  */
    ASKBOOL = 337,                 /* ASKBOOL  */
    ASKCHOICE = 338,               /* ASKCHOICE  */
    ASKDIR = 339,                  /* ASKDIR  */
    ASKDISK = 340,                 /* ASKDISK  */
    ASKFILE = 341,                 /* ASKFILE  */
    ASKNUMBER = 342,               /* ASKNUMBER  */
    ASKOPTIONS = 343,              /* ASKOPTIONS  */
    ASKSTRING = 344,               /* ASKSTRING  */
    CAT = 345,                     /* CAT  */
    EXPANDPATH = 346,              /* EXPANDPATH  */
    FMT = 347,                     /* FMT  */
    PATHONLY = 348,                /* PATHONLY  */
    PATMATCH = 349,                /* PATMATCH  */
    STRLEN = 350,                  /* STRLEN  */
    SUBSTR = 351,                  /* SUBSTR  */
    TACKON = 352,                  /* TACKON  */
    SET = 353,                     /* SET  */
    SYMBOLSET = 354,               /* SYMBOLSET  */
    SYMBOLVAL = 355,               /* SYMBOLVAL  */
    OPENWBOBJECT = 356,            /* OPENWBOBJECT  */
    SHOWWBOBJECT = 357,            /* SHOWWBOBJECT  */
    CLOSEWBOBJECT = 358,           /* CLOSEWBOBJECT  */
    ALL = 359,                     /* ALL  */
    APPEND = 360,                  /* APPEND  */
    ASSIGNS = 361,                 /* ASSIGNS  */
    BACK = 362,                    /* BACK  */
    CHOICES = 363,                 /* CHOICES  */
    COMMAND = 364,                 /* COMMAND  */
    COMPRESSION = 365,             /* COMPRESSION  */
    CONFIRM = 366,                 /* CONFIRM  */
    DEFAULT = 367,                 /* DEFAULT  */
    DELOPTS = 368,                 /* DELOPTS  */
    DEST = 369,                    /* DEST  */
    DISK = 370,                    /* DISK  */
    FILES = 371,                   /* FILES  */
    FONTS = 372,                   /* FONTS  */
    GETDEFAULTTOOL = 373,          /* GETDEFAULTTOOL  */
    GETPOSITION = 374,             /* GETPOSITION  */
    GETSTACK = 375,                /* GETSTACK  */
    GETTOOLTYPE = 376,             /* GETTOOLTYPE  */
    HELP = 377,                    /* HELP  */
    INFOS = 378,                   /* INFOS  */
    INCLUDE = 379,                 /* INCLUDE  */
    NEWNAME = 380,                 /* NEWNAME  */
    NEWPATH = 381,                 /* NEWPATH  */
    NOGAUGE = 382,                 /* NOGAUGE  */
    NOPOSITION = 383,              /* NOPOSITION  */
    NOREQ = 384,                   /* NOREQ  */
    PATTERN = 385,                 /* PATTERN  */
    PROMPT = 386,                  /* PROMPT  */
    QUIET = 387,                   /* QUIET  */
    RANGE = 388,                   /* RANGE  */
    SAFE = 389,                    /* SAFE  */
    SETDEFAULTTOOL = 390,          /* SETDEFAULTTOOL  */
    SETPOSITION = 391,             /* SETPOSITION  */
    SETSTACK = 392,                /* SETSTACK  */
    SETTOOLTYPE = 393,             /* SETTOOLTYPE  */
    SOURCE = 394,                  /* SOURCE  */
    SWAPCOLORS = 395,              /* SWAPCOLORS  */
    OPTIONAL = 396,                /* OPTIONAL  */
    RESIDENT = 397,                /* RESIDENT  */
    OVERRIDE = 398                 /* OVERRIDE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SYM = 3,                        /* SYM  */
  YYSYMBOL_STR = 4,                        /* STR  */
  YYSYMBOL_OOM = 5,                        /* OOM  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_HEX = 7,                        /* HEX  */
  YYSYMBOL_BIN = 8,                        /* BIN  */
  YYSYMBOL_EQ = 9,                         /* EQ  */
  YYSYMBOL_GT = 10,                        /* GT  */
  YYSYMBOL_GTE = 11,                       /* GTE  */
  YYSYMBOL_LT = 12,                        /* LT  */
  YYSYMBOL_LTE = 13,                       /* LTE  */
  YYSYMBOL_NEQ = 14,                       /* NEQ  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_SELECT = 16,                    /* SELECT  */
  YYSYMBOL_UNTIL = 17,                     /* UNTIL  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_TRACE = 19,                     /* TRACE  */
  YYSYMBOL_RETRACE = 20,                   /* RETRACE  */
  YYSYMBOL_ASTRAW = 21,                    /* ASTRAW  */
  YYSYMBOL_ASBRAW = 22,                    /* ASBRAW  */
  YYSYMBOL_ASBEVAL = 23,                   /* ASBEVAL  */
  YYSYMBOL_EVAL = 24,                      /* EVAL  */
  YYSYMBOL_OPTIONS = 25,                   /* OPTIONS  */
  YYSYMBOL_EXECUTE = 26,                   /* EXECUTE  */
  YYSYMBOL_REXX = 27,                      /* REXX  */
  YYSYMBOL_RUN = 28,                       /* RUN  */
  YYSYMBOL_ABORT = 29,                     /* ABORT  */
  YYSYMBOL_EXIT = 30,                      /* EXIT  */
  YYSYMBOL_ONERROR = 31,                   /* ONERROR  */
  YYSYMBOL_TRAP = 32,                      /* TRAP  */
  YYSYMBOL_REBOOT = 33,                    /* REBOOT  */
  YYSYMBOL_COPYFILES = 34,                 /* COPYFILES  */
  YYSYMBOL_COPYLIB = 35,                   /* COPYLIB  */
  YYSYMBOL_DELETE = 36,                    /* DELETE  */
  YYSYMBOL_EXISTS = 37,                    /* EXISTS  */
  YYSYMBOL_FILEONLY = 38,                  /* FILEONLY  */
  YYSYMBOL_FOREACH = 39,                   /* FOREACH  */
  YYSYMBOL_MAKEASSIGN = 40,                /* MAKEASSIGN  */
  YYSYMBOL_MAKEDIR = 41,                   /* MAKEDIR  */
  YYSYMBOL_PROTECT = 42,                   /* PROTECT  */
  YYSYMBOL_STARTUP = 43,                   /* STARTUP  */
  YYSYMBOL_TEXTFILE = 44,                  /* TEXTFILE  */
  YYSYMBOL_TOOLTYPE = 45,                  /* TOOLTYPE  */
  YYSYMBOL_TRANSCRIPT = 46,                /* TRANSCRIPT  */
  YYSYMBOL_RENAME = 47,                    /* RENAME  */
  YYSYMBOL_COMPLETE = 48,                  /* COMPLETE  */
  YYSYMBOL_DEBUG = 49,                     /* DEBUG  */
  YYSYMBOL_MESSAGE = 50,                   /* MESSAGE  */
  YYSYMBOL_USER = 51,                      /* USER  */
  YYSYMBOL_WELCOME = 52,                   /* WELCOME  */
  YYSYMBOL_WORKING = 53,                   /* WORKING  */
  YYSYMBOL_AND = 54,                       /* AND  */
  YYSYMBOL_BITAND = 55,                    /* BITAND  */
  YYSYMBOL_BITNOT = 56,                    /* BITNOT  */
  YYSYMBOL_BITOR = 57,                     /* BITOR  */
  YYSYMBOL_BITXOR = 58,                    /* BITXOR  */
  YYSYMBOL_NOT = 59,                       /* NOT  */
  YYSYMBOL_IN = 60,                        /* IN  */
  YYSYMBOL_OR = 61,                        /* OR  */
  YYSYMBOL_SHIFTLEFT = 62,                 /* SHIFTLEFT  */
  YYSYMBOL_SHIFTRIGHT = 63,                /* SHIFTRIGHT  */
  YYSYMBOL_XOR = 64,                       /* XOR  */
  YYSYMBOL_CLOSEMEDIA = 65,                /* CLOSEMEDIA  */
  YYSYMBOL_EFFECT = 66,                    /* EFFECT  */
  YYSYMBOL_SETMEDIA = 67,                  /* SETMEDIA  */
  YYSYMBOL_SHOWMEDIA = 68,                 /* SHOWMEDIA  */
  YYSYMBOL_DATABASE = 69,                  /* DATABASE  */
  YYSYMBOL_EARLIER = 70,                   /* EARLIER  */
  YYSYMBOL_GETASSIGN = 71,                 /* GETASSIGN  */
  YYSYMBOL_GETDEVICE = 72,                 /* GETDEVICE  */
  YYSYMBOL_GETDISKSPACE = 73,              /* GETDISKSPACE  */
  YYSYMBOL_GETENV = 74,                    /* GETENV  */
  YYSYMBOL_GETSIZE = 75,                   /* GETSIZE  */
  YYSYMBOL_GETSUM = 76,                    /* GETSUM  */
  YYSYMBOL_GETVERSION = 77,                /* GETVERSION  */
  YYSYMBOL_ICONINFO = 78,                  /* ICONINFO  */
  YYSYMBOL_QUERYDISPLAY = 79,              /* QUERYDISPLAY  */
  YYSYMBOL_CUS = 80,                       /* CUS  */
  YYSYMBOL_DCL = 81,                       /* DCL  */
  YYSYMBOL_ASKBOOL = 82,                   /* ASKBOOL  */
  YYSYMBOL_ASKCHOICE = 83,                 /* ASKCHOICE  */
  YYSYMBOL_ASKDIR = 84,                    /* ASKDIR  */
  YYSYMBOL_ASKDISK = 85,                   /* ASKDISK  */
  YYSYMBOL_ASKFILE = 86,                   /* ASKFILE  */
  YYSYMBOL_ASKNUMBER = 87,                 /* ASKNUMBER  */
  YYSYMBOL_ASKOPTIONS = 88,                /* ASKOPTIONS  */
  YYSYMBOL_ASKSTRING = 89,                 /* ASKSTRING  */
  YYSYMBOL_CAT = 90,                       /* CAT  */
  YYSYMBOL_EXPANDPATH = 91,                /* EXPANDPATH  */
  YYSYMBOL_FMT = 92,                       /* FMT  */
  YYSYMBOL_PATHONLY = 93,                  /* PATHONLY  */
  YYSYMBOL_PATMATCH = 94,                  /* PATMATCH  */
  YYSYMBOL_STRLEN = 95,                    /* STRLEN  */
  YYSYMBOL_SUBSTR = 96,                    /* SUBSTR  */
  YYSYMBOL_TACKON = 97,                    /* TACKON  */
  YYSYMBOL_SET = 98,                       /* SET  */
  YYSYMBOL_SYMBOLSET = 99,                 /* SYMBOLSET  */
  YYSYMBOL_SYMBOLVAL = 100,                /* SYMBOLVAL  */
  YYSYMBOL_OPENWBOBJECT = 101,             /* OPENWBOBJECT  */
  YYSYMBOL_SHOWWBOBJECT = 102,             /* SHOWWBOBJECT  */
  YYSYMBOL_CLOSEWBOBJECT = 103,            /* CLOSEWBOBJECT  */
  YYSYMBOL_ALL = 104,                      /* ALL  */
  YYSYMBOL_APPEND = 105,                   /* APPEND  */
  YYSYMBOL_ASSIGNS = 106,                  /* ASSIGNS  */
  YYSYMBOL_BACK = 107,                     /* BACK  */
  YYSYMBOL_CHOICES = 108,                  /* CHOICES  */
  YYSYMBOL_COMMAND = 109,                  /* COMMAND  */
  YYSYMBOL_COMPRESSION = 110,              /* COMPRESSION  */
  YYSYMBOL_CONFIRM = 111,                  /* CONFIRM  */
  YYSYMBOL_DEFAULT = 112,                  /* DEFAULT  */
  YYSYMBOL_DELOPTS = 113,                  /* DELOPTS  */
  YYSYMBOL_DEST = 114,                     /* DEST  */
  YYSYMBOL_DISK = 115,                     /* DISK  */
  YYSYMBOL_FILES = 116,                    /* FILES  */
  YYSYMBOL_FONTS = 117,                    /* FONTS  */
  YYSYMBOL_GETDEFAULTTOOL = 118,           /* GETDEFAULTTOOL  */
  YYSYMBOL_GETPOSITION = 119,              /* GETPOSITION  */
  YYSYMBOL_GETSTACK = 120,                 /* GETSTACK  */
  YYSYMBOL_GETTOOLTYPE = 121,              /* GETTOOLTYPE  */
  YYSYMBOL_HELP = 122,                     /* HELP  */
  YYSYMBOL_INFOS = 123,                    /* INFOS  */
  YYSYMBOL_INCLUDE = 124,                  /* INCLUDE  */
  YYSYMBOL_NEWNAME = 125,                  /* NEWNAME  */
  YYSYMBOL_NEWPATH = 126,                  /* NEWPATH  */
  YYSYMBOL_NOGAUGE = 127,                  /* NOGAUGE  */
  YYSYMBOL_NOPOSITION = 128,               /* NOPOSITION  */
  YYSYMBOL_NOREQ = 129,                    /* NOREQ  */
  YYSYMBOL_PATTERN = 130,                  /* PATTERN  */
  YYSYMBOL_PROMPT = 131,                   /* PROMPT  */
  YYSYMBOL_QUIET = 132,                    /* QUIET  */
  YYSYMBOL_RANGE = 133,                    /* RANGE  */
  YYSYMBOL_SAFE = 134,                     /* SAFE  */
  YYSYMBOL_SETDEFAULTTOOL = 135,           /* SETDEFAULTTOOL  */
  YYSYMBOL_SETPOSITION = 136,              /* SETPOSITION  */
  YYSYMBOL_SETSTACK = 137,                 /* SETSTACK  */
  YYSYMBOL_SETTOOLTYPE = 138,              /* SETTOOLTYPE  */
  YYSYMBOL_SOURCE = 139,                   /* SOURCE  */
  YYSYMBOL_SWAPCOLORS = 140,               /* SWAPCOLORS  */
  YYSYMBOL_OPTIONAL = 141,                 /* OPTIONAL  */
  YYSYMBOL_RESIDENT = 142,                 /* RESIDENT  */
  YYSYMBOL_OVERRIDE = 143,                 /* OVERRIDE  */
  YYSYMBOL_144_ = 144,                     /* '('  */
  YYSYMBOL_145_ = 145,                     /* ')'  */
  YYSYMBOL_146_ = 146,                     /* '+'  */
  YYSYMBOL_147_ = 147,                     /* '/'  */
  YYSYMBOL_148_ = 148,                     /* '*'  */
  YYSYMBOL_149_ = 149,                     /* '-'  */
  YYSYMBOL_150_ = 150,                     /* '='  */
  YYSYMBOL_151_ = 151,                     /* '>'  */
  YYSYMBOL_152_ = 152,                     /* '<'  */
  YYSYMBOL_YYACCEPT = 153,                 /* $accept  */
  YYSYMBOL_start = 154,                    /* start  */
  YYSYMBOL_s = 155,                        /* s  */
  YYSYMBOL_p = 156,                        /* p  */
  YYSYMBOL_pp = 157,                       /* pp  */
  YYSYMBOL_ps = 158,                       /* ps  */
  YYSYMBOL_pps = 159,                      /* pps  */
  YYSYMBOL_vp = 160,                       /* vp  */
  YYSYMBOL_vps = 161,                      /* vps  */
  YYSYMBOL_opts = 162,                     /* opts  */
  YYSYMBOL_xpb = 163,                      /* xpb  */
  YYSYMBOL_xpbs = 164,                     /* xpbs  */
  YYSYMBOL_np = 165,                       /* np  */
  YYSYMBOL_sps = 166,                      /* sps  */
  YYSYMBOL_par = 167,                      /* par  */
  YYSYMBOL_cv = 168,                       /* cv  */
  YYSYMBOL_cvv = 169,                      /* cvv  */
  YYSYMBOL_opt = 170,                      /* opt  */
  YYSYMBOL_ivp = 171,                      /* ivp  */
  YYSYMBOL_add = 172,                      /* add  */
  YYSYMBOL_div = 173,                      /* div  */
  YYSYMBOL_mul = 174,                      /* mul  */
  YYSYMBOL_sub = 175,                      /* sub  */
  YYSYMBOL_eq = 176,                       /* eq  */
  YYSYMBOL_gt = 177,                       /* gt  */
  YYSYMBOL_gte = 178,                      /* gte  */
  YYSYMBOL_lt = 179,                       /* lt  */
  YYSYMBOL_lte = 180,                      /* lte  */
  YYSYMBOL_neq = 181,                      /* neq  */
  YYSYMBOL_if = 182,                       /* if  */
  YYSYMBOL_select = 183,                   /* select  */
  YYSYMBOL_until = 184,                    /* until  */
  YYSYMBOL_while = 185,                    /* while  */
  YYSYMBOL_trace = 186,                    /* trace  */
  YYSYMBOL_retrace = 187,                  /* retrace  */
  YYSYMBOL_astraw = 188,                   /* astraw  */
  YYSYMBOL_asbraw = 189,                   /* asbraw  */
  YYSYMBOL_asbeval = 190,                  /* asbeval  */
  YYSYMBOL_eval = 191,                     /* eval  */
  YYSYMBOL_options = 192,                  /* options  */
  YYSYMBOL_execute = 193,                  /* execute  */
  YYSYMBOL_rexx = 194,                     /* rexx  */
  YYSYMBOL_run = 195,                      /* run  */
  YYSYMBOL_abort = 196,                    /* abort  */
  YYSYMBOL_exit = 197,                     /* exit  */
  YYSYMBOL_onerror = 198,                  /* onerror  */
  YYSYMBOL_reboot = 199,                   /* reboot  */
  YYSYMBOL_trap = 200,                     /* trap  */
  YYSYMBOL_copyfiles = 201,                /* copyfiles  */
  YYSYMBOL_copylib = 202,                  /* copylib  */
  YYSYMBOL_delete = 203,                   /* delete  */
  YYSYMBOL_exists = 204,                   /* exists  */
  YYSYMBOL_fileonly = 205,                 /* fileonly  */
  YYSYMBOL_foreach = 206,                  /* foreach  */
  YYSYMBOL_makeassign = 207,               /* makeassign  */
  YYSYMBOL_makedir = 208,                  /* makedir  */
  YYSYMBOL_protect = 209,                  /* protect  */
  YYSYMBOL_startup = 210,                  /* startup  */
  YYSYMBOL_textfile = 211,                 /* textfile  */
  YYSYMBOL_tooltype = 212,                 /* tooltype  */
  YYSYMBOL_transcript = 213,               /* transcript  */
  YYSYMBOL_rename = 214,                   /* rename  */
  YYSYMBOL_complete = 215,                 /* complete  */
  YYSYMBOL_debug = 216,                    /* debug  */
  YYSYMBOL_message = 217,                  /* message  */
  YYSYMBOL_user = 218,                     /* user  */
  YYSYMBOL_welcome = 219,                  /* welcome  */
  YYSYMBOL_working = 220,                  /* working  */
  YYSYMBOL_and = 221,                      /* and  */
  YYSYMBOL_bitand = 222,                   /* bitand  */
  YYSYMBOL_bitnot = 223,                   /* bitnot  */
  YYSYMBOL_bitor = 224,                    /* bitor  */
  YYSYMBOL_bitxor = 225,                   /* bitxor  */
  YYSYMBOL_not = 226,                      /* not  */
  YYSYMBOL_in = 227,                       /* in  */
  YYSYMBOL_or = 228,                       /* or  */
  YYSYMBOL_shiftleft = 229,                /* shiftleft  */
  YYSYMBOL_shiftright = 230,               /* shiftright  */
  YYSYMBOL_xor = 231,                      /* xor  */
  YYSYMBOL_closemedia = 232,               /* closemedia  */
  YYSYMBOL_effect = 233,                   /* effect  */
  YYSYMBOL_setmedia = 234,                 /* setmedia  */
  YYSYMBOL_showmedia = 235,                /* showmedia  */
  YYSYMBOL_database = 236,                 /* database  */
  YYSYMBOL_earlier = 237,                  /* earlier  */
  YYSYMBOL_getassign = 238,                /* getassign  */
  YYSYMBOL_getdevice = 239,                /* getdevice  */
  YYSYMBOL_getdiskspace = 240,             /* getdiskspace  */
  YYSYMBOL_getenv = 241,                   /* getenv  */
  YYSYMBOL_getsize = 242,                  /* getsize  */
  YYSYMBOL_getsum = 243,                   /* getsum  */
  YYSYMBOL_getversion = 244,               /* getversion  */
  YYSYMBOL_iconinfo = 245,                 /* iconinfo  */
  YYSYMBOL_querydisplay = 246,             /* querydisplay  */
  YYSYMBOL_dcl = 247,                      /* dcl  */
  YYSYMBOL_cus = 248,                      /* cus  */
  YYSYMBOL_askbool = 249,                  /* askbool  */
  YYSYMBOL_askchoice = 250,                /* askchoice  */
  YYSYMBOL_askdir = 251,                   /* askdir  */
  YYSYMBOL_askdisk = 252,                  /* askdisk  */
  YYSYMBOL_askfile = 253,                  /* askfile  */
  YYSYMBOL_asknumber = 254,                /* asknumber  */
  YYSYMBOL_askoptions = 255,               /* askoptions  */
  YYSYMBOL_askstring = 256,                /* askstring  */
  YYSYMBOL_cat = 257,                      /* cat  */
  YYSYMBOL_expandpath = 258,               /* expandpath  */
  YYSYMBOL_fmt = 259,                      /* fmt  */
  YYSYMBOL_pathonly = 260,                 /* pathonly  */
  YYSYMBOL_patmatch = 261,                 /* patmatch  */
  YYSYMBOL_strlen = 262,                   /* strlen  */
  YYSYMBOL_substr = 263,                   /* substr  */
  YYSYMBOL_tackon = 264,                   /* tackon  */
  YYSYMBOL_set = 265,                      /* set  */
  YYSYMBOL_symbolset = 266,                /* symbolset  */
  YYSYMBOL_symbolval = 267,                /* symbolval  */
  YYSYMBOL_openwbobject = 268,             /* openwbobject  */
  YYSYMBOL_showwbobject = 269,             /* showwbobject  */
  YYSYMBOL_closewbobject = 270,            /* closewbobject  */
  YYSYMBOL_all = 271,                      /* all  */
  YYSYMBOL_append = 272,                   /* append  */
  YYSYMBOL_assigns = 273,                  /* assigns  */
  YYSYMBOL_back = 274,                     /* back  */
  YYSYMBOL_choices = 275,                  /* choices  */
  YYSYMBOL_command = 276,                  /* command  */
  YYSYMBOL_compression = 277,              /* compression  */
  YYSYMBOL_confirm = 278,                  /* confirm  */
  YYSYMBOL_default = 279,                  /* default  */
  YYSYMBOL_delopts = 280,                  /* delopts  */
  YYSYMBOL_dest = 281,                     /* dest  */
  YYSYMBOL_disk = 282,                     /* disk  */
  YYSYMBOL_files = 283,                    /* files  */
  YYSYMBOL_fonts = 284,                    /* fonts  */
  YYSYMBOL_getdefaulttool = 285,           /* getdefaulttool  */
  YYSYMBOL_getposition = 286,              /* getposition  */
  YYSYMBOL_getstack = 287,                 /* getstack  */
  YYSYMBOL_gettooltype = 288,              /* gettooltype  */
  YYSYMBOL_help = 289,                     /* help  */
  YYSYMBOL_infos = 290,                    /* infos  */
  YYSYMBOL_include = 291,                  /* include  */
  YYSYMBOL_newname = 292,                  /* newname  */
  YYSYMBOL_newpath = 293,                  /* newpath  */
  YYSYMBOL_nogauge = 294,                  /* nogauge  */
  YYSYMBOL_noposition = 295,               /* noposition  */
  YYSYMBOL_noreq = 296,                    /* noreq  */
  YYSYMBOL_pattern = 297,                  /* pattern  */
  YYSYMBOL_prompt = 298,                   /* prompt  */
  YYSYMBOL_quiet = 299,                    /* quiet  */
  YYSYMBOL_range = 300,                    /* range  */
  YYSYMBOL_safe = 301,                     /* safe  */
  YYSYMBOL_setdefaulttool = 302,           /* setdefaulttool  */
  YYSYMBOL_setposition = 303,              /* setposition  */
  YYSYMBOL_setstack = 304,                 /* setstack  */
  YYSYMBOL_settooltype = 305,              /* settooltype  */
  YYSYMBOL_source = 306,                   /* source  */
  YYSYMBOL_swapcolors = 307,               /* swapcolors  */
  YYSYMBOL_optional = 308,                 /* optional  */
  YYSYMBOL_resident = 309,                 /* resident  */
  YYSYMBOL_override = 310,                 /* override  */
  YYSYMBOL_dynopt = 311                    /* dynopt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  291
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2447

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  153
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  159
/* YYNRULES -- Number of rules.  */
#define YYNRULES  391
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  754

#define YYMAXUTOK   398


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     144,   145,   148,   146,     2,   149,     2,   147,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     152,   150,   151,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    96,    96,    97,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   284,   285,
     286,   287,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   306,   307,   308,   309,   310,   311,
     312,   313,   317,   318,   319,   320,   321,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   340,
     341,   342,   343,   344,   345,   346,   348,   349,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   417,   418,   419,   420,   421,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   444,   445,   446,   447,   448,   449,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   482,   483,   484,   488,   489,   490,   491,
     492,   493,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SYM", "STR", "OOM",
  "INT", "HEX", "BIN", "EQ", "GT", "GTE", "LT", "LTE", "NEQ", "IF",
  "SELECT", "UNTIL", "WHILE", "TRACE", "RETRACE", "ASTRAW", "ASBRAW",
  "ASBEVAL", "EVAL", "OPTIONS", "EXECUTE", "REXX", "RUN", "ABORT", "EXIT",
  "ONERROR", "TRAP", "REBOOT", "COPYFILES", "COPYLIB", "DELETE", "EXISTS",
  "FILEONLY", "FOREACH", "MAKEASSIGN", "MAKEDIR", "PROTECT", "STARTUP",
  "TEXTFILE", "TOOLTYPE", "TRANSCRIPT", "RENAME", "COMPLETE", "DEBUG",
  "MESSAGE", "USER", "WELCOME", "WORKING", "AND", "BITAND", "BITNOT",
  "BITOR", "BITXOR", "NOT", "IN", "OR", "SHIFTLEFT", "SHIFTRIGHT", "XOR",
  "CLOSEMEDIA", "EFFECT", "SETMEDIA", "SHOWMEDIA", "DATABASE", "EARLIER",
  "GETASSIGN", "GETDEVICE", "GETDISKSPACE", "GETENV", "GETSIZE", "GETSUM",
  "GETVERSION", "ICONINFO", "QUERYDISPLAY", "CUS", "DCL", "ASKBOOL",
  "ASKCHOICE", "ASKDIR", "ASKDISK", "ASKFILE", "ASKNUMBER", "ASKOPTIONS",
  "ASKSTRING", "CAT", "EXPANDPATH", "FMT", "PATHONLY", "PATMATCH",
  "STRLEN", "SUBSTR", "TACKON", "SET", "SYMBOLSET", "SYMBOLVAL",
  "OPENWBOBJECT", "SHOWWBOBJECT", "CLOSEWBOBJECT", "ALL", "APPEND",
  "ASSIGNS", "BACK", "CHOICES", "COMMAND", "COMPRESSION", "CONFIRM",
  "DEFAULT", "DELOPTS", "DEST", "DISK", "FILES", "FONTS", "GETDEFAULTTOOL",
  "GETPOSITION", "GETSTACK", "GETTOOLTYPE", "HELP", "INFOS", "INCLUDE",
  "NEWNAME", "NEWPATH", "NOGAUGE", "NOPOSITION", "NOREQ", "PATTERN",
  "PROMPT", "QUIET", "RANGE", "SAFE", "SETDEFAULTTOOL", "SETPOSITION",
  "SETSTACK", "SETTOOLTYPE", "SOURCE", "SWAPCOLORS", "OPTIONAL",
  "RESIDENT", "OVERRIDE", "'('", "')'", "'+'", "'/'", "'*'", "'-'", "'='",
  "'>'", "'<'", "$accept", "start", "s", "p", "pp", "ps", "pps", "vp",
  "vps", "opts", "xpb", "xpbs", "np", "sps", "par", "cv", "cvv", "opt",
  "ivp", "add", "div", "mul", "sub", "eq", "gt", "gte", "lt", "lte", "neq",
  "if", "select", "until", "while", "trace", "retrace", "astraw", "asbraw",
  "asbeval", "eval", "options", "execute", "rexx", "run", "abort", "exit",
  "onerror", "reboot", "trap", "copyfiles", "copylib", "delete", "exists",
  "fileonly", "foreach", "makeassign", "makedir", "protect", "startup",
  "textfile", "tooltype", "transcript", "rename", "complete", "debug",
  "message", "user", "welcome", "working", "and", "bitand", "bitnot",
  "bitor", "bitxor", "not", "in", "or", "shiftleft", "shiftright", "xor",
  "closemedia", "effect", "setmedia", "showmedia", "database", "earlier",
  "getassign", "getdevice", "getdiskspace", "getenv", "getsize", "getsum",
  "getversion", "iconinfo", "querydisplay", "dcl", "cus", "askbool",
  "askchoice", "askdir", "askdisk", "askfile", "asknumber", "askoptions",
  "askstring", "cat", "expandpath", "fmt", "pathonly", "patmatch",
  "strlen", "substr", "tackon", "set", "symbolset", "symbolval",
  "openwbobject", "showwbobject", "closewbobject", "all", "append",
  "assigns", "back", "choices", "command", "compression", "confirm",
  "default", "delopts", "dest", "disk", "files", "fonts", "getdefaulttool",
  "getposition", "getstack", "gettooltype", "help", "infos", "include",
  "newname", "newpath", "nogauge", "noposition", "noreq", "pattern",
  "prompt", "quiet", "range", "safe", "setdefaulttool", "setposition",
  "setstack", "settooltype", "source", "swapcolors", "optional",
  "resident", "override", "dynopt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,    40,    41,    43,    47,    42,    45,
      61,    62,    60
};
#endif

#define YYPACT_NINF (-404)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -140,  1295,    29,  -404,  -404,  -140,  -140,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,     7,
      13,   454,   454,   454,   454,   454,   454,   454,  -112,  -102,
     -99,   454,   454,   454,   -96,   549,   549,   549,   454,    34,
    -140,   454,   -79,   -67,   -67,   549,   549,   454,   454,   454,
     549,   454,   549,   -67,   -67,   454,   454,   454,    57,   549,
     454,    64,   108,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   118,   -67,   454,    79,
    -122,   -67,  -113,   -67,  -109,   -91,   -67,   -89,   454,   454,
     454,   454,   454,   454,   454,    87,   454,   454,   549,   454,
     454,   -45,   454,   -39,  -140,   454,   454,   -37,   125,   454,
     141,   454,   -28,    -9,    -4,   454,   454,   454,   454,   156,
      36,   454,   454,   251,    40,    43,    46,   454,   269,    48,
     454,    53,   454,   454,   454,   454,   454,    67,   301,    71,
     454,   454,   454,   454,   454,   454,   454,   454,    83,   -87,
     -71,  -404,  -140,  -140,  -140,  -140,  -404,  -404,  -404,  -404,
    -404,  -404,  1895,  -404,  -404,   307,  -404,  -404,  -404,   320,
     384,   102,   397,   106,   418,   115,   463,   123,   126,   575,
    -140,  -140,  -404,  -404,  -404,   139,   146,   186,  -404,  1445,
     469,   549,   475,   549,   482,   549,   488,  1595,  -404,   495,
     517,   -69,  -140,  -404,  2303,   -64,   -59,   566,   549,   -56,
     549,   188,   454,  -140,   597,   -51,   -49,   549,   639,   -46,
     -67,   652,   -42,   -25,   806,   -10,   195,  -404,   813,   836,
     549,   198,  -404,   856,  -404,   893,   917,   203,   207,   212,
     221,   240,   454,   923,   252,   265,   273,   289,   454,   985,
     454,  1013,   290,   291,  1036,   292,   293,  1094,   295,   296,
     297,   298,  -404,    -6,     9,   302,    27,  -404,    11,    24,
    -404,    52,    59,  -404,    61,  -404,    66,    70,  -404,    74,
    1111,   303,   304,   305,   308,  1117,   309,   575,     5,  -404,
    1133,   311,    86,   549,   318,   359,  -404,  1705,  -404,    88,
    1711,  1717,  -404,  -404,  1725,   360,  -404,  1860,   361,  -404,
    -404,  -404,   362,   364,   365,   367,  -404,  1868,  -404,   368,
     369,  -404,   371,  -404,  -404,  -404,   382,  -404,  1877,  -404,
     386,  -404,   387,   389,   390,  2011,   391,    90,  -404,  -404,
    2020,  -404,   392,  2026,   393,  2146,  2154,  2169,   394,  2175,
     398,  2195,   399,  -404,  -404,  -404,   454,    83,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  1295,  -404,
    -404,    92,   575,  -404,  -404,  2045,  -404,  2201,    95,    98,
    -404,  -404,  -404,   101,  -404,   105,  2207,   -67,  -404,   120,
    2213,  -404,   122,  2219,  -404,  -404,   400,  -404,  2225,  -404,
     134,   454,  -404,  -404,  -404,   136,  2231,  -404,   138,   402,
    -404,   143,  1745,  -404,   403,   415,  -404,   405,  -404,   152,
     154,  -404,   158,  -404,   174,   192,  -404,   194,  -404,  -404,
    -404,  -404,   201,  -404,  -404,  -404,   206,  2237,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  2243,  -404,  -404,
    -404,  -404,  -404,   413,  -404,   414,   454,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,   419,  -404,
     420,  -404,  -404,  -404,  -404,   421,    42,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,   423,  -404,  -404,   575,  -404,  -404,  -404,  -404,  -404,
     210,   217,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,   460,  -404,
     430,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  2249,  2255,  -404,   219,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,   230,  -404,  -404,   232,  -404,  -404,
     234,  -404,  -404,  -404,   -67,  -404,  -404,   238,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,   249,  -404,  -404,  -404,  -404,
     264,  -404,  -404,  -404,   272,  -404,  -404,  -404,  2261,  -404,
    -404,  -404,  -404,   431,  -404,  -404,  -404,  -404,   283,  -404,
    -404,   439,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     2,    16,     3,     0,    19,    11,    79,
      80,    81,    82,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   118,   117,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   155,   154,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    58,    57,    59,
      60,    61,    62,    63,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    64,    78,    65,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,     1,    13,    14,    15,    18,    30,    29,    31,    26,
      27,    28,     0,   309,     8,     0,     4,     5,   326,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,   201,   202,     0,     0,     0,   206,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   224,     0,
       0,     0,     0,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,     0,
       0,     0,   269,     0,   271,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   299,     0,     0,     0,     0,   310,     0,     0,
     313,     0,     0,   316,     0,   318,     0,     0,   321,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,   342,     0,   344,     0,
       0,     0,   348,   350,     0,     0,   353,     0,     0,   355,
     356,   357,     0,     0,     0,     0,   363,     0,   364,     0,
       0,   367,     0,   369,   370,   371,     0,   374,     0,   375,
       0,   377,     0,     0,     0,     0,     0,     0,   385,   387,
       0,   388,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    17,    20,     0,     0,   308,     7,
     325,   187,     6,   186,   191,   190,   193,   192,     0,   196,
      23,     0,    36,   195,   194,     0,    24,     0,     0,     0,
     203,   204,   205,     0,   210,     0,     0,    18,   214,     0,
       0,   218,     0,     0,   219,   223,     0,   222,     0,   225,
       0,     0,   228,   229,   233,     0,     0,   234,     0,     0,
     237,     0,     0,   242,     0,     0,   240,     0,   246,     0,
       0,   250,     0,   248,     0,     0,   254,     0,   255,   256,
     257,   259,     0,   260,   261,   266,     0,     0,   267,   268,
     270,   272,   273,   274,   275,   276,   277,     0,   279,   280,
     281,   282,   283,     0,   285,     0,     0,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,   300,
       0,   302,   303,    35,   307,     0,     0,   311,   312,   314,
     315,   317,   319,   320,   322,   323,   324,   327,   328,   329,
     330,     0,   332,    33,     0,   333,   334,     9,   335,   336,
       0,     0,   340,   341,   343,   345,   346,   347,   349,   351,
     352,   354,   358,   359,   360,   361,   362,   365,   366,   368,
     372,   373,   376,   378,   379,   380,   382,   381,     0,   383,
       0,   386,   389,   178,   179,   180,   181,   183,   182,   185,
     184,   189,   188,     0,     0,   390,     0,    37,   197,    25,
     198,   199,   207,   208,     0,   211,   212,     0,   215,   216,
       0,   220,   221,   227,     0,   230,   231,     0,   235,   236,
     238,   241,   239,   243,   244,     0,   249,   247,   251,   252,
       0,   258,   263,   264,     0,   278,   284,   286,     0,   301,
     306,    34,   305,     0,   331,    32,   337,   338,     0,   384,
      21,     0,   391,   209,   213,   217,   232,   245,   253,   265,
     287,   304,   339,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -404,  -404,  -403,   519,   877,  -141,  -404,    78,    91,     0,
    -317,  -404,   -97,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,   111,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,  -162,  -404,    75,  -404,
    -404,  -404,  -404,  -404,  -404,  -404,   182,  -404,  -404
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   304,   311,   305,   430,   306,   292,   527,
     512,   517,   307,   428,   616,   317,   318,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,   290,   516,   615,     1,   293,   295,   340,   634,   309,
     296,   297,   298,   299,   300,   301,   296,   297,   298,   299,
     300,   301,   344,   407,   330,   332,   334,   336,   339,   291,
     613,   344,   410,   322,   347,   344,   413,   296,   297,   298,
     299,   300,   301,   323,   364,   731,   324,   368,   369,   328,
     373,   375,   376,   344,   415,   344,   418,     1,   494,   383,
     296,   297,   298,   299,   300,   301,   343,   296,   297,   298,
     299,   300,   301,     1,   495,     1,   539,   344,     4,   288,
     344,   542,   406,     4,     4,   344,   543,   420,   344,   547,
     427,     5,   289,   555,   556,   344,   558,   294,   344,   563,
     436,   437,   344,   568,   440,   441,   438,   444,   442,   447,
     633,   296,   297,   298,   299,   300,   301,   449,   457,   344,
     569,   296,   297,   298,   299,   300,   301,   468,   296,   297,
     298,   299,   300,   301,   344,   571,   450,   480,   608,   609,
     483,   451,   485,   486,   296,   297,   298,   299,   300,   301,
     635,   302,   303,   344,   611,   344,   617,   302,   308,   296,
     297,   298,   299,   300,   301,   331,   333,   335,   344,   618,
       6,     1,   614,   345,   346,   348,   350,   536,   337,   338,
     357,   458,   361,   362,   363,   463,     1,   732,   464,   370,
     526,   465,   530,   469,   533,   687,   344,   619,   471,   538,
     689,   302,   367,   344,   620,   344,   621,   546,   302,   372,
     344,   622,   478,   733,   344,   623,   481,   404,   344,   624,
     408,   409,   411,   412,   414,   416,   417,   419,   493,   577,
     344,   639,     1,   645,   668,   669,   344,   685,   433,     1,
     690,   587,     1,   691,     6,   344,   495,   503,     4,   344,
     692,   505,   302,   374,   296,   297,   298,   299,   300,   301,
     507,   341,   302,   402,   344,   695,   344,   698,   513,   302,
     443,   514,   296,   297,   298,   299,   300,   301,     1,   703,
     344,   705,   344,   708,   520,   302,   446,     1,   710,   293,
     295,   521,   293,   295,   293,   295,   344,   713,   344,   714,
     302,   456,   344,   716,   296,   297,   298,   299,   300,   301,
     296,   297,   298,   299,   300,   301,   511,   735,   344,   717,
       6,     6,     4,   296,   297,   298,   299,   300,   301,   523,
     525,   522,   529,   550,   532,   439,   344,   718,   344,   719,
     573,   293,     6,   578,   523,   344,   721,   545,   582,   548,
     344,   722,   583,     6,   344,   736,   559,   584,   562,   564,
     565,   344,   737,   344,   742,   572,   585,     4,     4,   576,
       4,     4,     4,     4,   344,   743,   344,   744,   344,   745,
     497,   294,   344,   746,   294,   586,   294,   296,   297,   298,
     299,   300,   301,   344,   747,   302,   461,   589,     4,     4,
     296,   297,   298,   299,   300,   301,     6,   497,   344,   748,
     590,   518,   519,   302,   467,   497,   344,   749,   591,     4,
       4,   296,   297,   298,   299,   300,   301,   344,   752,   554,
     557,     4,   640,   540,   592,   598,   599,   601,   602,   293,
     604,   605,   606,   607,   551,   302,   479,   612,   626,   627,
     628,   302,   498,   629,   632,   728,   638,   296,   297,   298,
     299,   300,   301,   642,   302,   500,   296,   297,   298,   299,
     300,   301,   296,   297,   298,   299,   300,   301,   296,   297,
     298,   299,   300,   301,     4,   296,   297,   298,   299,   300,
     301,   296,   297,   298,   299,   300,   301,     5,   296,   297,
     298,   299,   300,   301,   643,   649,   651,   652,   290,   653,
     654,   686,   655,   657,   658,     6,   659,     4,   293,   293,
     296,   297,   298,   299,   300,   301,   694,   660,   302,   501,
     697,   662,   663,   700,   664,   665,   667,   672,   674,   678,
     293,   302,   504,   680,   682,   701,   707,   709,   711,   271,
     712,   293,   296,   297,   298,   299,   300,   301,   726,   727,
     715,   279,   302,   506,   241,   729,   730,   720,   734,   296,
     297,   298,   299,   300,   301,   739,   751,   724,   296,   297,
     298,   299,   300,   301,   753,   610,   288,   741,   670,     0,
       0,     0,     0,   288,     0,     0,     4,     4,   302,   684,
     296,   297,   298,   299,   300,   301,   684,   508,   509,     0,
       0,     0,     0,   329,   524,     0,     6,     0,     4,   329,
     528,     0,     0,     0,     0,     0,   329,   531,     0,     4,
     497,     0,   302,   534,     0,     0,     0,     0,     0,   337,
     535,   738,   296,   297,   298,   299,   300,   301,     0,     0,
       0,     0,     0,     0,     0,   296,   297,   298,   299,   300,
     301,   302,   537,     0,     0,     0,     0,     0,     0,     0,
     310,   312,   314,   316,   319,   320,   321,     0,     0,     0,
     325,   326,   327,     0,   293,     0,     0,     0,     0,     0,
     342,     0,     0,   329,     4,   349,   351,   352,   354,   356,
     358,   360,     0,     0,   511,   352,   366,     5,     0,   371,
     329,   544,     0,   352,   378,   352,   352,   381,   382,   515,
     352,   352,   352,   387,   352,   352,   352,   391,   352,   394,
     396,   397,   399,   400,   401,   403,     0,   352,     0,     0,
       0,   552,   553,     0,     0,     0,     0,     0,   421,   422,
     352,   424,   352,   352,     0,   352,   431,   432,   434,   435,
       0,     0,     4,     0,     0,     0,     0,     0,   445,     0,
     448,     0,     0,     0,   452,   352,   454,   352,     0,     0,
     459,   460,   462,   329,   561,     0,   466,     0,     0,   352,
       0,   472,   352,   474,   475,   477,   329,   566,     0,   482,
       0,   352,     0,     0,   487,   489,   491,     0,     0,   296,
     297,   298,   299,   300,   301,     0,   296,   297,   298,   299,
     300,   301,     0,     0,   499,     0,     0,     0,   499,   502,
       0,   502,     0,   502,     0,   510,     0,     0,   510,   296,
     297,   298,   299,   300,   301,     0,     0,     0,     0,   499,
       0,   499,     0,   499,     0,   499,     0,     0,   499,   296,
     297,   298,   299,   300,   301,     0,   499,     0,     0,   549,
       0,   502,     0,   502,     0,     0,   560,   502,     0,     0,
     567,     0,     0,   499,     0,     0,     0,   499,   499,     0,
       0,     0,   499,     0,   499,   499,   296,   297,   298,   299,
     300,   301,   499,     0,     0,     0,     0,   352,   595,   352,
     502,     0,     0,   502,     0,     0,   502,     0,     0,     0,
     296,   297,   298,   299,   300,   301,   296,   297,   298,   299,
     300,   301,     0,     0,     0,     0,     0,     0,     0,   499,
       0,     0,     0,     0,   631,     0,   510,     0,     0,   352,
     302,   570,   641,     0,     0,     0,   499,   302,   574,   499,
     499,     0,     0,   499,     0,     0,   499,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   499,     0,     0,     0,
     329,   575,     0,     0,     0,     0,     0,   499,   296,   297,
     298,   299,   300,   301,   502,     0,     0,     0,     0,   499,
     302,   579,   499,     0,   499,   499,   502,     0,   502,     0,
     502,     0,     0,     0,     0,   683,   296,   297,   298,   299,
     300,   301,     0,     0,     0,     0,     0,     0,     0,   313,
     315,   510,     0,     0,     0,     0,   510,   302,   580,   296,
     297,   298,   299,   300,   301,   499,     0,     0,     0,   499,
       0,     0,   499,     0,     0,   353,   355,   499,   359,     0,
     704,   302,   581,   365,     0,   499,     0,   302,   588,     0,
       0,   377,     0,   379,   380,     0,     0,     0,   384,   385,
     386,     0,   388,   389,   390,   392,   393,   395,     0,   398,
       0,     0,     0,     0,     0,   405,   499,   296,   297,   298,
     299,   300,   301,     0,     0,     0,   499,     0,   423,     0,
     425,   426,     0,   429,   296,   297,   298,   299,   300,   301,
     296,   297,   298,   299,   300,   301,     0,     0,     0,   302,
     594,     0,     0,   453,     0,   455,   296,   297,   298,   299,
     300,   301,     0,     0,     0,     0,     0,   470,     0,     0,
     473,     0,   476,   510,     0,     0,     0,   302,   597,   484,
       0,     0,   488,   490,   492,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     302,   600,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   510,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,   603,
       0,     0,     0,     0,     0,     0,     0,   499,     0,     0,
       0,     0,     0,     0,     0,   302,   625,     0,     0,     0,
       0,   302,   630,     0,     0,   593,     0,   596,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   302,   636,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   149,   150,
       0,     0,     0,     0,     0,     0,   151,   637,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,     0,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,     1,
       0,   281,   282,   283,   284,   285,   286,   287,   149,   150,
       0,     0,     0,     0,     0,     0,   151,     0,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,     0,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   329,
       0,   281,   282,   283,   284,   285,   286,   287,   149,   150,
       0,     0,     0,     0,     0,     0,   151,     0,   152,   153,
     496,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,     0,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   296,   297,
     298,   299,   300,   301,   296,   297,   298,   299,   300,   301,
     296,   297,   298,   299,   300,   301,     0,   269,   296,   297,
     298,   299,   300,   301,     0,     0,     0,     0,     0,   302,
       0,   281,   282,   283,   284,   285,   286,   287,   149,   150,
       0,     0,     0,     0,     0,     0,   151,     0,   152,   153,
     496,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,     0,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   302,
     644,     0,     0,     0,     0,   302,   646,     0,     0,     0,
       0,   302,   647,   296,   297,   298,   299,   300,   301,   302,
     648,   296,   297,   298,   299,   300,   301,     0,     0,   271,
     296,   297,   298,   299,   300,   301,     0,     0,     0,   302,
       0,   281,   282,   283,   284,   285,   286,   287,   149,   150,
       0,     0,     0,     0,     0,     0,   151,     0,   152,   153,
     496,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,     0,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
       0,     0,     0,     0,   302,   650,     0,     0,     0,     0,
       0,     0,   302,   656,   296,   297,   298,   299,   300,   301,
       0,   302,   661,   296,   297,   298,   299,   300,   301,   296,
     297,   298,   299,   300,   301,     0,     0,     0,     0,   302,
       0,   281,   282,   283,   284,   285,   286,   287,   149,   150,
       0,     0,     0,     0,     0,     0,   151,     0,   152,   153,
     496,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,     0,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   296,
     297,   298,   299,   300,   301,   302,   666,   296,   297,   298,
     299,   300,   301,     0,   302,   671,     0,     0,     0,     0,
     302,   673,   296,   297,   298,   299,   300,   301,   296,   297,
     298,   299,   300,   301,     0,     0,     0,     0,     0,     1,
       0,   281,   282,   283,   284,   285,   286,   287,   296,   297,
     298,   299,   300,   301,   296,   297,   298,   299,   300,   301,
     296,   297,   298,   299,   300,   301,   296,   297,   298,   299,
     300,   301,   296,   297,   298,   299,   300,   301,   296,   297,
     298,   299,   300,   301,   296,   297,   298,   299,   300,   301,
     296,   297,   298,   299,   300,   301,   296,   297,   298,   299,
     300,   301,   296,   297,   298,   299,   300,   301,   296,   297,
     298,   299,   300,   301,   296,   297,   298,   299,   300,   301,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     302,   675,     0,     0,     0,     0,     0,     0,   302,   676,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   302,   677,     0,     0,     0,   541,   302,
     679,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   302,
     681,     0,     0,     0,     0,   515,   688,     0,     0,     0,
       0,   329,   693,     0,     0,     0,     0,   329,   696,     0,
       0,     0,     0,   329,   699,     0,     0,     0,     0,   302,
     702,     0,     0,     0,     0,   329,   706,     0,     0,     0,
       0,   329,   723,     0,     0,     0,     0,   302,   725,     0,
       0,     0,     0,   515,   509,     0,     0,     0,     0,     1,
     740,     0,     0,     0,     0,   302,   750,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   344
};

static const yytype_int16 yycheck[] =
{
       0,     1,   319,   406,   144,     5,     6,   169,     3,   150,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,   144,   145,   165,   166,   167,   168,   169,     0,
       3,   144,   145,   145,   175,   144,   145,     3,     4,     5,
       6,     7,     8,   145,   185,     3,   145,   188,   189,   145,
     191,   192,   193,   144,   145,   144,   145,   144,   145,   200,
       3,     4,     5,     6,     7,     8,   145,     3,     4,     5,
       6,     7,     8,   144,   145,   144,   145,   144,     0,     1,
     144,   145,     3,     5,     6,   144,   145,   228,   144,   145,
       3,     0,     1,   144,   145,   144,   145,     6,   144,   145,
     145,   242,   144,   145,   245,   246,   145,   248,   145,   250,
     427,     3,     4,     5,     6,     7,     8,   145,   259,   144,
     145,     3,     4,     5,     6,     7,     8,   268,     3,     4,
       5,     6,     7,     8,   144,   145,   145,   278,   144,   145,
     281,   145,   283,   284,     3,     4,     5,     6,     7,     8,
     145,   144,   145,   144,   145,   144,   145,   144,   145,     3,
       4,     5,     6,     7,     8,   165,   166,   167,   144,   145,
     170,   144,   145,   173,   174,   175,   176,   339,   144,   145,
     180,   145,   182,   183,   184,   145,   144,   145,   145,   189,
     331,   145,   333,   145,   335,   512,   144,   145,   145,   340,
     517,   144,   145,   144,   145,   144,   145,   348,   144,   145,
     144,   145,   145,   616,   144,   145,   145,   217,   144,   145,
     220,   221,   222,   223,   224,   225,   226,   227,   145,   370,
     144,   145,   144,   145,   144,   145,   144,   145,   238,   144,
     145,   382,   144,   145,   244,   144,   145,   145,   170,   144,
     145,   145,   144,   145,     3,     4,     5,     6,     7,     8,
     145,   170,   144,   145,   144,   145,   144,   145,   145,   144,
     145,   145,     3,     4,     5,     6,     7,     8,   144,   145,
     144,   145,   144,   145,   145,   144,   145,   144,   145,   289,
     290,   145,   292,   293,   294,   295,   144,   145,   144,   145,
     144,   145,   144,   145,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,   316,   634,   144,   145,
     320,   321,   244,     3,     4,     5,     6,     7,     8,   329,
     330,   145,   332,   145,   334,   244,   144,   145,   144,   145,
     145,   341,   342,   145,   344,   144,   145,   347,   145,   349,
     144,   145,   145,   353,   144,   145,   356,   145,   358,   359,
     360,   144,   145,   144,   145,   365,   145,   289,   290,   369,
     292,   293,   294,   295,   144,   145,   144,   145,   144,   145,
     302,   290,   144,   145,   293,   145,   295,     3,     4,     5,
       6,     7,     8,   144,   145,   144,   145,   145,   320,   321,
       3,     4,     5,     6,     7,     8,   406,   329,   144,   145,
     145,   320,   321,   144,   145,   337,   144,   145,   145,   341,
     342,     3,     4,     5,     6,     7,     8,   144,   145,   354,
     355,   353,   432,   342,   145,   145,   145,   145,   145,   439,
     145,   145,   145,   145,   353,   144,   145,   145,   145,   145,
     145,   144,   145,   145,   145,   596,   145,     3,     4,     5,
       6,     7,     8,   145,   144,   145,     3,     4,     5,     6,
       7,     8,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,   406,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,   406,     3,     4,
       5,     6,     7,     8,   145,   145,   145,   145,   508,   145,
     145,   511,   145,   145,   145,   515,   145,   439,   518,   519,
       3,     4,     5,     6,     7,     8,   526,   145,   144,   145,
     530,   145,   145,   533,   145,   145,   145,   145,   145,   145,
     540,   144,   145,   145,   145,   145,   546,   145,   145,   134,
     145,   551,     3,     4,     5,     6,     7,     8,   145,   145,
     560,   142,   144,   145,   104,   145,   145,   567,   145,     3,
       4,     5,     6,     7,     8,   145,   145,   577,     3,     4,
       5,     6,     7,     8,   145,   403,   508,   684,   477,    -1,
      -1,    -1,    -1,   515,    -1,    -1,   518,   519,   144,   508,
       3,     4,     5,     6,     7,     8,   515,   144,   145,    -1,
      -1,    -1,    -1,   144,   145,    -1,   616,    -1,   540,   144,
     145,    -1,    -1,    -1,    -1,    -1,   144,   145,    -1,   551,
     552,    -1,   144,   145,    -1,    -1,    -1,    -1,    -1,   144,
     145,   641,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     151,   152,   153,   154,   155,   156,   157,    -1,    -1,    -1,
     161,   162,   163,    -1,   684,    -1,    -1,    -1,    -1,    -1,
     171,    -1,    -1,   144,   616,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,   704,   186,   187,   616,    -1,   190,
     144,   145,    -1,   194,   195,   196,   197,   198,   199,   144,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,   218,    -1,    -1,
      -1,   144,   145,    -1,    -1,    -1,    -1,    -1,   229,   230,
     231,   232,   233,   234,    -1,   236,   237,   238,   239,   240,
      -1,    -1,   684,    -1,    -1,    -1,    -1,    -1,   249,    -1,
     251,    -1,    -1,    -1,   255,   256,   257,   258,    -1,    -1,
     261,   262,   263,   144,   145,    -1,   267,    -1,    -1,   270,
      -1,   272,   273,   274,   275,   276,   144,   145,    -1,   280,
      -1,   282,    -1,    -1,   285,   286,   287,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,   305,    -1,    -1,    -1,   309,   310,
      -1,   312,    -1,   314,    -1,   316,    -1,    -1,   319,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,   330,
      -1,   332,    -1,   334,    -1,   336,    -1,    -1,   339,     3,
       4,     5,     6,     7,     8,    -1,   347,    -1,    -1,   350,
      -1,   352,    -1,   354,    -1,    -1,   357,   358,    -1,    -1,
     361,    -1,    -1,   364,    -1,    -1,    -1,   368,   369,    -1,
      -1,    -1,   373,    -1,   375,   376,     3,     4,     5,     6,
       7,     8,   383,    -1,    -1,    -1,    -1,   388,   389,   390,
     391,    -1,    -1,   394,    -1,    -1,   397,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,
      -1,    -1,    -1,    -1,   425,    -1,   427,    -1,    -1,   430,
     144,   145,   433,    -1,    -1,    -1,   437,   144,   145,   440,
     441,    -1,    -1,   444,    -1,    -1,   447,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   457,    -1,    -1,    -1,
     144,   145,    -1,    -1,    -1,    -1,    -1,   468,     3,     4,
       5,     6,     7,     8,   475,    -1,    -1,    -1,    -1,   480,
     144,   145,   483,    -1,   485,   486,   487,    -1,   489,    -1,
     491,    -1,    -1,    -1,    -1,   496,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,
     153,   512,    -1,    -1,    -1,    -1,   517,   144,   145,     3,
       4,     5,     6,     7,     8,   526,    -1,    -1,    -1,   530,
      -1,    -1,   533,    -1,    -1,   178,   179,   538,   181,    -1,
     541,   144,   145,   186,    -1,   546,    -1,   144,   145,    -1,
      -1,   194,    -1,   196,   197,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,   206,   207,   208,   209,   210,    -1,   212,
      -1,    -1,    -1,    -1,    -1,   218,   577,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,   587,    -1,   231,    -1,
     233,   234,    -1,   236,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,   144,
     145,    -1,    -1,   256,    -1,   258,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,
     273,    -1,   275,   634,    -1,    -1,    -1,   144,   145,   282,
      -1,    -1,   285,   286,   287,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   683,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   728,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,
      -1,   144,   145,    -1,    -1,   388,    -1,   390,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    11,   430,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,     3,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,     3,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,    -1,   132,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,     3,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   144,
     145,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,
      -1,   144,   145,     3,     4,     5,     6,     7,     8,   144,
     145,     3,     4,     5,     6,     7,     8,    -1,    -1,   134,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,     3,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,     3,     4,     5,     6,     7,     8,
      -1,   144,   145,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,     3,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     3,
       4,     5,     6,     7,     8,   144,   145,     3,     4,     5,
       6,     7,     8,    -1,   144,   145,    -1,    -1,    -1,    -1,
     144,   145,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,    -1,    -1,    -1,    15,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,
      -1,   144,   145,    -1,    -1,    -1,    -1,   144,   145,    -1,
      -1,    -1,    -1,   144,   145,    -1,    -1,    -1,    -1,   144,
     145,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,
      -1,   144,   145,    -1,    -1,    -1,    -1,   144,   145,    -1,
      -1,    -1,    -1,   144,   145,    -1,    -1,    -1,    -1,   144,
     145,    -1,    -1,    -1,    -1,   144,   145,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   144,   154,   155,   160,   161,   162,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,     3,
       4,    11,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   146,   147,   148,   149,   150,   151,   152,   160,   161,
     162,     0,   161,   162,   161,   162,     3,     4,     5,     6,
       7,     8,   144,   145,   156,   158,   160,   165,   145,   158,
     156,   157,   156,   157,   156,   157,   156,   168,   169,   156,
     156,   156,   145,   145,   145,   156,   156,   156,   145,   144,
     158,   162,   158,   162,   158,   162,   158,   144,   145,   158,
     299,   161,   156,   145,   144,   162,   162,   158,   162,   156,
     162,   156,   156,   157,   156,   157,   156,   162,   156,   157,
     156,   162,   162,   162,   158,   157,   156,   145,   158,   158,
     162,   156,   145,   158,   145,   158,   158,   157,   156,   157,
     157,   156,   156,   158,   157,   157,   157,   156,   157,   157,
     157,   156,   157,   157,   156,   157,   156,   156,   157,   156,
     156,   156,   145,   156,   162,   157,     3,   145,   162,   162,
     145,   162,   162,   145,   162,   145,   162,   162,   145,   162,
     158,   156,   156,   157,   156,   157,   157,     3,   166,   157,
     159,   156,   156,   162,   156,   156,   145,   158,   145,   161,
     158,   158,   145,   145,   158,   156,   145,   158,   156,   145,
     145,   145,   156,   157,   156,   157,   145,   158,   145,   156,
     156,   145,   156,   145,   145,   145,   156,   145,   158,   145,
     157,   145,   156,   157,   156,   156,   157,   156,   145,   145,
     158,   145,   156,   158,   157,   158,   158,   156,   157,   156,
     157,   156,   157,   145,   145,   145,    15,   160,   145,   156,
     145,   145,   156,   145,   145,   145,   145,   145,   144,   145,
     156,   162,   163,   145,   145,   144,   163,   164,   161,   161,
     145,   145,   145,   162,   145,   162,   158,   162,   145,   162,
     158,   145,   162,   158,   145,   145,   299,   145,   158,   145,
     161,    15,   145,   145,   145,   162,   158,   145,   162,   156,
     145,   161,   144,   145,   301,   144,   145,   301,   145,   162,
     156,   145,   162,   145,   162,   162,   145,   156,   145,   145,
     145,   145,   162,   145,   145,   145,   162,   158,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   158,   145,   145,
     145,   145,   145,   157,   145,   156,   157,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   144,   145,
     309,   145,   145,     3,   145,   155,   167,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   156,   145,   163,     3,   145,   145,   157,   145,   145,
     162,   156,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   144,   145,
     271,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   156,   161,   145,   162,   163,   145,   163,
     145,   145,   145,   145,   162,   145,   145,   162,   145,   145,
     162,   145,   145,   145,   156,   145,   145,   162,   145,   145,
     145,   145,   145,   145,   145,   162,   145,   145,   145,   145,
     162,   145,   145,   145,   162,   145,   145,   145,   158,   145,
     145,     3,   145,   155,   145,   163,   145,   145,   162,   145,
     145,   165,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   153,   154,   155,   156,   156,   157,   158,   158,   159,
     159,   160,   160,   161,   161,   161,   161,   161,   162,   162,
     162,   163,   163,   163,   164,   164,   165,   165,   165,   165,
     165,   165,   166,   166,   167,   167,   168,   169,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   172,   173,
     174,   175,   176,   176,   177,   177,   178,   178,   179,   179,
     180,   180,   181,   181,   182,   182,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   193,   193,
     193,   194,   194,   194,   194,   195,   195,   195,   195,   196,
     197,   197,   197,   197,   197,   198,   199,   200,   201,   202,
     203,   203,   203,   203,   204,   204,   204,   205,   206,   207,
     207,   207,   207,   208,   208,   208,   208,   209,   209,   209,
     209,   210,   210,   210,   210,   211,   212,   213,   214,   214,
     215,   216,   216,   217,   217,   217,   217,   218,   219,   219,
     220,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   234,   235,   236,   236,
     237,   238,   238,   239,   240,   240,   241,   242,   243,   244,
     244,   244,   245,   246,   247,   247,   247,   247,   248,   248,
     249,   249,   250,   251,   251,   252,   253,   253,   254,   254,
     255,   256,   256,   257,   258,   259,   259,   260,   261,   262,
     263,   263,   264,   265,   266,   267,   268,   268,   268,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     278,   279,   280,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   289,   290,   291,   292,   293,   293,   294,
     295,   296,   297,   298,   298,   299,   300,   301,   302,   303,
     304,   305,   305,   306,   306,   307,   308,   308,   309,   310,
     311,   311
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     1,     2,
       1,     1,     3,     2,     2,     2,     1,     3,     2,     1,
       3,     3,     4,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     3,     2,     2,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     5,     5,
       3,     3,     3,     4,     4,     4,     3,     5,     5,     6,
       4,     5,     5,     6,     4,     5,     5,     6,     4,     4,
       5,     5,     4,     4,     3,     4,     3,     5,     4,     4,
       5,     5,     6,     4,     4,     5,     5,     4,     5,     5,
       4,     5,     4,     5,     5,     6,     4,     5,     4,     5,
       4,     5,     5,     6,     4,     4,     4,     4,     5,     4,
       4,     4,     3,     5,     5,     6,     4,     4,     4,     3,
       4,     3,     4,     4,     4,     4,     4,     4,     5,     4,
       4,     4,     4,     4,     5,     4,     5,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       4,     5,     4,     4,     6,     5,     5,     4,     4,     3,
       3,     4,     4,     3,     4,     4,     3,     4,     3,     4,
       4,     3,     4,     4,     4,     4,     3,     4,     4,     4,
       4,     5,     4,     4,     4,     4,     4,     5,     5,     6,
       4,     4,     3,     4,     3,     4,     4,     4,     3,     4,
       3,     4,     4,     3,     4,     3,     3,     3,     4,     4,
       4,     4,     4,     3,     3,     4,     4,     3,     4,     3,
       3,     3,     4,     4,     3,     3,     4,     3,     4,     4,
       4,     4,     4,     4,     5,     3,     4,     3,     3,     4,
       5,     6
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, yyscan_t scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case 3: /* SYM  */
#line 82 "../src/parser.y"
            { free(((*yyvaluep).s)); }
#line 2491 "parser.c"
        break;

    case 4: /* STR  */
#line 82 "../src/parser.y"
            { free(((*yyvaluep).s)); }
#line 2497 "parser.c"
        break;

    case 154: /* start  */
#line 80 "../src/parser.y"
            { run(((*yyvaluep).e));  }
#line 2503 "parser.c"
        break;

    case 155: /* s  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2509 "parser.c"
        break;

    case 156: /* p  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2515 "parser.c"
        break;

    case 157: /* pp  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2521 "parser.c"
        break;

    case 158: /* ps  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2527 "parser.c"
        break;

    case 159: /* pps  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2533 "parser.c"
        break;

    case 160: /* vp  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2539 "parser.c"
        break;

    case 161: /* vps  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2545 "parser.c"
        break;

    case 162: /* opts  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2551 "parser.c"
        break;

    case 163: /* xpb  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2557 "parser.c"
        break;

    case 164: /* xpbs  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2563 "parser.c"
        break;

    case 165: /* np  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2569 "parser.c"
        break;

    case 166: /* sps  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2575 "parser.c"
        break;

    case 167: /* par  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2581 "parser.c"
        break;

    case 168: /* cv  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2587 "parser.c"
        break;

    case 169: /* cvv  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2593 "parser.c"
        break;

    case 170: /* opt  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2599 "parser.c"
        break;

    case 171: /* ivp  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2605 "parser.c"
        break;

    case 172: /* add  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2611 "parser.c"
        break;

    case 173: /* div  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2617 "parser.c"
        break;

    case 174: /* mul  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2623 "parser.c"
        break;

    case 175: /* sub  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2629 "parser.c"
        break;

    case 176: /* eq  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2635 "parser.c"
        break;

    case 177: /* gt  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2641 "parser.c"
        break;

    case 178: /* gte  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2647 "parser.c"
        break;

    case 179: /* lt  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2653 "parser.c"
        break;

    case 180: /* lte  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2659 "parser.c"
        break;

    case 181: /* neq  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2665 "parser.c"
        break;

    case 182: /* if  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2671 "parser.c"
        break;

    case 183: /* select  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2677 "parser.c"
        break;

    case 184: /* until  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2683 "parser.c"
        break;

    case 185: /* while  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2689 "parser.c"
        break;

    case 186: /* trace  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2695 "parser.c"
        break;

    case 187: /* retrace  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2701 "parser.c"
        break;

    case 188: /* astraw  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2707 "parser.c"
        break;

    case 189: /* asbraw  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2713 "parser.c"
        break;

    case 190: /* asbeval  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2719 "parser.c"
        break;

    case 191: /* eval  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2725 "parser.c"
        break;

    case 192: /* options  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2731 "parser.c"
        break;

    case 193: /* execute  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2737 "parser.c"
        break;

    case 194: /* rexx  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2743 "parser.c"
        break;

    case 195: /* run  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2749 "parser.c"
        break;

    case 196: /* abort  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2755 "parser.c"
        break;

    case 197: /* exit  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2761 "parser.c"
        break;

    case 198: /* onerror  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2767 "parser.c"
        break;

    case 199: /* reboot  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2773 "parser.c"
        break;

    case 200: /* trap  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2779 "parser.c"
        break;

    case 201: /* copyfiles  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2785 "parser.c"
        break;

    case 202: /* copylib  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2791 "parser.c"
        break;

    case 203: /* delete  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2797 "parser.c"
        break;

    case 204: /* exists  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2803 "parser.c"
        break;

    case 205: /* fileonly  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2809 "parser.c"
        break;

    case 206: /* foreach  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2815 "parser.c"
        break;

    case 207: /* makeassign  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2821 "parser.c"
        break;

    case 208: /* makedir  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2827 "parser.c"
        break;

    case 209: /* protect  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2833 "parser.c"
        break;

    case 210: /* startup  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2839 "parser.c"
        break;

    case 211: /* textfile  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2845 "parser.c"
        break;

    case 212: /* tooltype  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2851 "parser.c"
        break;

    case 213: /* transcript  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2857 "parser.c"
        break;

    case 214: /* rename  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2863 "parser.c"
        break;

    case 215: /* complete  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2869 "parser.c"
        break;

    case 216: /* debug  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2875 "parser.c"
        break;

    case 217: /* message  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2881 "parser.c"
        break;

    case 218: /* user  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2887 "parser.c"
        break;

    case 219: /* welcome  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2893 "parser.c"
        break;

    case 220: /* working  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2899 "parser.c"
        break;

    case 221: /* and  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2905 "parser.c"
        break;

    case 222: /* bitand  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2911 "parser.c"
        break;

    case 223: /* bitnot  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2917 "parser.c"
        break;

    case 224: /* bitor  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2923 "parser.c"
        break;

    case 225: /* bitxor  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2929 "parser.c"
        break;

    case 226: /* not  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2935 "parser.c"
        break;

    case 227: /* in  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2941 "parser.c"
        break;

    case 228: /* or  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2947 "parser.c"
        break;

    case 229: /* shiftleft  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2953 "parser.c"
        break;

    case 230: /* shiftright  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2959 "parser.c"
        break;

    case 231: /* xor  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2965 "parser.c"
        break;

    case 232: /* closemedia  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2971 "parser.c"
        break;

    case 233: /* effect  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2977 "parser.c"
        break;

    case 234: /* setmedia  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2983 "parser.c"
        break;

    case 235: /* showmedia  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2989 "parser.c"
        break;

    case 236: /* database  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2995 "parser.c"
        break;

    case 237: /* earlier  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3001 "parser.c"
        break;

    case 238: /* getassign  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3007 "parser.c"
        break;

    case 239: /* getdevice  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3013 "parser.c"
        break;

    case 240: /* getdiskspace  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3019 "parser.c"
        break;

    case 241: /* getenv  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3025 "parser.c"
        break;

    case 242: /* getsize  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3031 "parser.c"
        break;

    case 243: /* getsum  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3037 "parser.c"
        break;

    case 244: /* getversion  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3043 "parser.c"
        break;

    case 245: /* iconinfo  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3049 "parser.c"
        break;

    case 246: /* querydisplay  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3055 "parser.c"
        break;

    case 247: /* dcl  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3061 "parser.c"
        break;

    case 248: /* cus  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3067 "parser.c"
        break;

    case 249: /* askbool  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3073 "parser.c"
        break;

    case 250: /* askchoice  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3079 "parser.c"
        break;

    case 251: /* askdir  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3085 "parser.c"
        break;

    case 252: /* askdisk  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3091 "parser.c"
        break;

    case 253: /* askfile  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3097 "parser.c"
        break;

    case 254: /* asknumber  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3103 "parser.c"
        break;

    case 255: /* askoptions  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3109 "parser.c"
        break;

    case 256: /* askstring  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3115 "parser.c"
        break;

    case 257: /* cat  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3121 "parser.c"
        break;

    case 258: /* expandpath  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3127 "parser.c"
        break;

    case 259: /* fmt  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3133 "parser.c"
        break;

    case 260: /* pathonly  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3139 "parser.c"
        break;

    case 261: /* patmatch  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3145 "parser.c"
        break;

    case 262: /* strlen  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3151 "parser.c"
        break;

    case 263: /* substr  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3157 "parser.c"
        break;

    case 264: /* tackon  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3163 "parser.c"
        break;

    case 265: /* set  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3169 "parser.c"
        break;

    case 266: /* symbolset  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3175 "parser.c"
        break;

    case 267: /* symbolval  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3181 "parser.c"
        break;

    case 268: /* openwbobject  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3187 "parser.c"
        break;

    case 269: /* showwbobject  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3193 "parser.c"
        break;

    case 270: /* closewbobject  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3199 "parser.c"
        break;

    case 271: /* all  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3205 "parser.c"
        break;

    case 272: /* append  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3211 "parser.c"
        break;

    case 273: /* assigns  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3217 "parser.c"
        break;

    case 274: /* back  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3223 "parser.c"
        break;

    case 275: /* choices  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3229 "parser.c"
        break;

    case 276: /* command  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3235 "parser.c"
        break;

    case 277: /* compression  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3241 "parser.c"
        break;

    case 278: /* confirm  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3247 "parser.c"
        break;

    case 279: /* default  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3253 "parser.c"
        break;

    case 280: /* delopts  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3259 "parser.c"
        break;

    case 281: /* dest  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3265 "parser.c"
        break;

    case 282: /* disk  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3271 "parser.c"
        break;

    case 283: /* files  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3277 "parser.c"
        break;

    case 284: /* fonts  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3283 "parser.c"
        break;

    case 285: /* getdefaulttool  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3289 "parser.c"
        break;

    case 286: /* getposition  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3295 "parser.c"
        break;

    case 287: /* getstack  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3301 "parser.c"
        break;

    case 288: /* gettooltype  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3307 "parser.c"
        break;

    case 289: /* help  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3313 "parser.c"
        break;

    case 290: /* infos  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3319 "parser.c"
        break;

    case 291: /* include  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3325 "parser.c"
        break;

    case 292: /* newname  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3331 "parser.c"
        break;

    case 293: /* newpath  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3337 "parser.c"
        break;

    case 294: /* nogauge  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3343 "parser.c"
        break;

    case 295: /* noposition  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3349 "parser.c"
        break;

    case 296: /* noreq  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3355 "parser.c"
        break;

    case 297: /* pattern  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3361 "parser.c"
        break;

    case 298: /* prompt  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3367 "parser.c"
        break;

    case 299: /* quiet  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3373 "parser.c"
        break;

    case 300: /* range  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3379 "parser.c"
        break;

    case 301: /* safe  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3385 "parser.c"
        break;

    case 302: /* setdefaulttool  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3391 "parser.c"
        break;

    case 303: /* setposition  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3397 "parser.c"
        break;

    case 304: /* setstack  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3403 "parser.c"
        break;

    case 305: /* settooltype  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3409 "parser.c"
        break;

    case 306: /* source  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3415 "parser.c"
        break;

    case 307: /* swapcolors  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3421 "parser.c"
        break;

    case 308: /* optional  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3427 "parser.c"
        break;

    case 309: /* resident  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3433 "parser.c"
        break;

    case 310: /* override  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3439 "parser.c"
        break;

    case 311: /* dynopt  */
#line 84 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3445 "parser.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 96 "../src/parser.y"
                                                 { (yyval.e) = init((yyvsp[0].e)); }
#line 3735 "parser.c"
    break;

  case 6:
#line 103 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3741 "parser.c"
    break;

  case 7:
#line 104 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3747 "parser.c"
    break;

  case 8:
#line 105 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3753 "parser.c"
    break;

  case 9:
#line 106 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3759 "parser.c"
    break;

  case 12:
#line 109 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3765 "parser.c"
    break;

  case 13:
#line 110 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3771 "parser.c"
    break;

  case 14:
#line 111 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e));  }
#line 3777 "parser.c"
    break;

  case 15:
#line 112 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e));  }
#line 3783 "parser.c"
    break;

  case 16:
#line 113 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3789 "parser.c"
    break;

  case 17:
#line 114 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3795 "parser.c"
    break;

  case 18:
#line 115 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3801 "parser.c"
    break;

  case 19:
#line 116 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3807 "parser.c"
    break;

  case 20:
#line 117 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3813 "parser.c"
    break;

  case 21:
#line 118 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3819 "parser.c"
    break;

  case 22:
#line 119 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-2].e), (yyvsp[-1].e)); }
#line 3825 "parser.c"
    break;

  case 23:
#line 120 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3831 "parser.c"
    break;

  case 24:
#line 121 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3837 "parser.c"
    break;

  case 25:
#line 122 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3843 "parser.c"
    break;

  case 26:
#line 123 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3849 "parser.c"
    break;

  case 27:
#line 124 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3855 "parser.c"
    break;

  case 28:
#line 125 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3861 "parser.c"
    break;

  case 29:
#line 126 "../src/parser.y"
                                                 { (yyval.e) = new_string((yyvsp[0].s)); }
#line 3867 "parser.c"
    break;

  case 30:
#line 127 "../src/parser.y"
                                                 { (yyval.e) = new_symref((yyvsp[0].s), LINE); }
#line 3873 "parser.c"
    break;

  case 31:
#line 128 "../src/parser.y"
                                                 { (yyval.e) = NULL; YYFPRINTF(stderr, "Out of memory in line %d\n", LINE); YYABORT; }
#line 3879 "parser.c"
    break;

  case 32:
#line 129 "../src/parser.y"
                                                 { (yyval.e) = push(push((yyvsp[-2].e), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)) ; }
#line 3885 "parser.c"
    break;

  case 33:
#line 130 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)); }
#line 3891 "parser.c"
    break;

  case 34:
#line 131 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), new_symbol((yyvsp[0].s))); }
#line 3897 "parser.c"
    break;

  case 35:
#line 132 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), new_symbol((yyvsp[0].s))); }
#line 3903 "parser.c"
    break;

  case 36:
#line 133 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3909 "parser.c"
    break;

  case 37:
#line 134 "../src/parser.y"
                                                 { (yyval.e) = push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3915 "parser.c"
    break;

  case 178:
#line 284 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("+")), LINE, n_add, (yyvsp[-1].e), NUMBER); }
#line 3921 "parser.c"
    break;

  case 179:
#line 285 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("/")), LINE, n_div, (yyvsp[-1].e), NUMBER); }
#line 3927 "parser.c"
    break;

  case 180:
#line 286 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("*")), LINE, n_mul, (yyvsp[-1].e), NUMBER); }
#line 3933 "parser.c"
    break;

  case 181:
#line 287 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("-")), LINE, n_sub, (yyvsp[-1].e), NUMBER); }
#line 3939 "parser.c"
    break;

  case 182:
#line 291 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("=")), LINE, n_eq, (yyvsp[-1].e), NUMBER); }
#line 3945 "parser.c"
    break;

  case 183:
#line 292 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("=")), LINE, n_eq, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3951 "parser.c"
    break;

  case 184:
#line 293 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup(">")), LINE, n_gt, (yyvsp[-1].e), NUMBER); }
#line 3957 "parser.c"
    break;

  case 185:
#line 294 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup(">")), LINE, n_gt, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3963 "parser.c"
    break;

  case 186:
#line 295 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup(">=")), LINE, n_gte, (yyvsp[-1].e), NUMBER); }
#line 3969 "parser.c"
    break;

  case 187:
#line 296 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup(">=")), LINE, n_gte, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3975 "parser.c"
    break;

  case 188:
#line 297 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("<")), LINE, n_lt, (yyvsp[-1].e), NUMBER); }
#line 3981 "parser.c"
    break;

  case 189:
#line 298 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("<")), LINE, n_lt, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3987 "parser.c"
    break;

  case 190:
#line 299 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("<=")), LINE, n_lte, (yyvsp[-1].e), NUMBER); }
#line 3993 "parser.c"
    break;

  case 191:
#line 300 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("<=")), LINE, n_lte, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3999 "parser.c"
    break;

  case 192:
#line 301 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("<>")), LINE, n_neq, (yyvsp[-1].e), NUMBER); }
#line 4005 "parser.c"
    break;

  case 193:
#line 302 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("<>")), LINE, n_neq, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4011 "parser.c"
    break;

  case 194:
#line 306 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("if")), LINE, n_if, (yyvsp[-1].e), NUMBER); }
#line 4017 "parser.c"
    break;

  case 195:
#line 307 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("if")), LINE, n_if, (yyvsp[-1].e), NUMBER); }
#line 4023 "parser.c"
    break;

  case 196:
#line 308 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("if")), LINE, n_if, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4029 "parser.c"
    break;

  case 197:
#line 309 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("select")), LINE, n_select, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4035 "parser.c"
    break;

  case 198:
#line 310 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("until")), LINE, n_until, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4041 "parser.c"
    break;

  case 199:
#line 311 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("while")), LINE, n_while, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4047 "parser.c"
    break;

  case 200:
#line 312 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("trace")), LINE, n_trace, NULL, NUMBER); }
#line 4053 "parser.c"
    break;

  case 201:
#line 313 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("retrace")), LINE, n_retrace, NULL, NUMBER); }
#line 4059 "parser.c"
    break;

  case 202:
#line 317 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("___astraw")), LINE, n_astraw, NULL, NUMBER); }
#line 4065 "parser.c"
    break;

  case 203:
#line 318 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("___asbraw")), LINE, n_asbraw, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4071 "parser.c"
    break;

  case 204:
#line 319 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("___asbeval")), LINE, n_asbeval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4077 "parser.c"
    break;

  case 205:
#line 320 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("___eval")), LINE, n_eval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4083 "parser.c"
    break;

  case 206:
#line 321 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("___options")), LINE, n_options, NULL, NUMBER); }
#line 4089 "parser.c"
    break;

  case 207:
#line 325 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("execute")), LINE, n_execute, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4095 "parser.c"
    break;

  case 208:
#line 326 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("execute")), LINE, n_execute, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 4101 "parser.c"
    break;

  case 209:
#line 327 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("execute")), LINE, n_execute, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4107 "parser.c"
    break;

  case 210:
#line 328 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("execute")), LINE, n_execute, (yyvsp[-1].e), NUMBER); }
#line 4113 "parser.c"
    break;

  case 211:
#line 329 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("rexx")), LINE, n_rexx, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4119 "parser.c"
    break;

  case 212:
#line 330 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("rexx")), LINE, n_rexx, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 4125 "parser.c"
    break;

  case 213:
#line 331 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("rexx")), LINE, n_rexx, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4131 "parser.c"
    break;

  case 214:
#line 332 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("rexx")), LINE, n_rexx, (yyvsp[-1].e), NUMBER); }
#line 4137 "parser.c"
    break;

  case 215:
#line 333 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("run")), LINE, n_run, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4143 "parser.c"
    break;

  case 216:
#line 334 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("run")), LINE, n_run, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 4149 "parser.c"
    break;

  case 217:
#line 335 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("run")), LINE, n_run, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4155 "parser.c"
    break;

  case 218:
#line 336 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("run")), LINE, n_run, (yyvsp[-1].e), NUMBER); }
#line 4161 "parser.c"
    break;

  case 219:
#line 340 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("abort")), LINE, n_abort, (yyvsp[-1].e), NUMBER); }
#line 4167 "parser.c"
    break;

  case 220:
#line 341 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("exit")), LINE, n_exit, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4173 "parser.c"
    break;

  case 221:
#line 342 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("exit")), LINE, n_exit, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 4179 "parser.c"
    break;

  case 222:
#line 343 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("exit")), LINE, n_exit, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4185 "parser.c"
    break;

  case 223:
#line 344 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("exit")), LINE, n_exit, (yyvsp[-1].e), NUMBER); }
#line 4191 "parser.c"
    break;

  case 224:
#line 345 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("exit")), LINE, n_exit, NULL, NUMBER); }
#line 4197 "parser.c"
    break;

  case 225:
#line 346 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("onerror")), LINE, n_procedure, push(new_contxt(),
                                                        new_custom(DBG_ALLOC(strdup("@onerror")), LINE, NULL, (yyvsp[-1].e))), DANGLE); }
#line 4204 "parser.c"
    break;

  case 226:
#line 348 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("reboot")), LINE, n_reboot, NULL, NUMBER); }
#line 4210 "parser.c"
    break;

  case 227:
#line 349 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("trap")), LINE, n_trap, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4216 "parser.c"
    break;

  case 228:
#line 353 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("copyfiles")), LINE, n_copyfiles, (yyvsp[-1].e), STRING); }
#line 4222 "parser.c"
    break;

  case 229:
#line 354 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("copylib")), LINE, n_copylib, (yyvsp[-1].e), NUMBER); }
#line 4228 "parser.c"
    break;

  case 230:
#line 355 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("delete")), LINE, n_delete, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4234 "parser.c"
    break;

  case 231:
#line 356 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("delete")), LINE, n_delete, merge((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 4240 "parser.c"
    break;

  case 232:
#line 357 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("delete")), LINE, n_delete, merge((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4246 "parser.c"
    break;

  case 233:
#line 358 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("delete")), LINE, n_delete, (yyvsp[-1].e), NUMBER); }
#line 4252 "parser.c"
    break;

  case 234:
#line 359 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("exists")), LINE, n_exists, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4258 "parser.c"
    break;

  case 235:
#line 360 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("exists")), LINE, n_exists, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4264 "parser.c"
    break;

  case 236:
#line 361 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("exists")), LINE, n_exists, merge(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4270 "parser.c"
    break;

  case 237:
#line 362 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("fileonly")), LINE, n_fileonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4276 "parser.c"
    break;

  case 238:
#line 363 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("foreach")), LINE, n_foreach, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4282 "parser.c"
    break;

  case 239:
#line 364 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("makeassign")), LINE, n_makeassign, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4288 "parser.c"
    break;

  case 240:
#line 365 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("makeassign")), LINE, n_makeassign, (yyvsp[-1].e), NUMBER); }
#line 4294 "parser.c"
    break;

  case 241:
#line 366 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("makeassign")), LINE, n_makeassign, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4300 "parser.c"
    break;

  case 242:
#line 367 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("makeassign")), LINE, n_makeassign, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4306 "parser.c"
    break;

  case 243:
#line 368 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("makedir")), LINE, n_makedir, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4312 "parser.c"
    break;

  case 244:
#line 369 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("makedir")), LINE, n_makedir, merge(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4318 "parser.c"
    break;

  case 245:
#line 370 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("makedir")), LINE, n_makedir, merge(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4324 "parser.c"
    break;

  case 246:
#line 371 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("makedir")), LINE, n_makedir, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4330 "parser.c"
    break;

  case 247:
#line 372 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("protect")), LINE, n_protect, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4336 "parser.c"
    break;

  case 248:
#line 373 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("protect")), LINE, n_protect, (yyvsp[-1].e), NUMBER); }
#line 4342 "parser.c"
    break;

  case 249:
#line 374 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("protect")), LINE, n_protect, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4348 "parser.c"
    break;

  case 250:
#line 375 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("protect")), LINE, n_protect, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4354 "parser.c"
    break;

  case 251:
#line 376 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("startup")), LINE, n_startup, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4360 "parser.c"
    break;

  case 252:
#line 377 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("startup")), LINE, n_startup, merge(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4366 "parser.c"
    break;

  case 253:
#line 378 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("startup")), LINE, n_startup, merge(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4372 "parser.c"
    break;

  case 254:
#line 379 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("startup")), LINE, n_startup, merge(push(new_contxt(), new_symref(DBG_ALLOC(strdup("@app-name")), LINE)), (yyvsp[-1].e)), NUMBER); }
#line 4378 "parser.c"
    break;

  case 255:
#line 380 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("textfile")), LINE, n_textfile, (yyvsp[-1].e), NUMBER); }
#line 4384 "parser.c"
    break;

  case 256:
#line 381 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("tooltype")), LINE, n_tooltype, (yyvsp[-1].e), NUMBER); }
#line 4390 "parser.c"
    break;

  case 257:
#line 382 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("transcript")), LINE, n_transcript, (yyvsp[-1].e), NUMBER); }
#line 4396 "parser.c"
    break;

  case 258:
#line 383 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("rename")), LINE, n_rename, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4402 "parser.c"
    break;

  case 259:
#line 384 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("rename")), LINE, n_rename, (yyvsp[-1].e), NUMBER); }
#line 4408 "parser.c"
    break;

  case 260:
#line 388 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("complete")), LINE, n_complete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4414 "parser.c"
    break;

  case 261:
#line 389 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("debug")), LINE, n_debug, (yyvsp[-1].e), NUMBER); }
#line 4420 "parser.c"
    break;

  case 262:
#line 390 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("debug")), LINE, n_debug, NULL, NUMBER); }
#line 4426 "parser.c"
    break;

  case 263:
#line 391 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("message")), LINE, n_message, merge((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 4432 "parser.c"
    break;

  case 264:
#line 392 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("message")), LINE, n_message, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4438 "parser.c"
    break;

  case 265:
#line 393 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("message")), LINE, n_message, push(merge((yyvsp[-3].e), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4444 "parser.c"
    break;

  case 266:
#line 394 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("message")), LINE, n_message, (yyvsp[-1].e), NUMBER); }
#line 4450 "parser.c"
    break;

  case 267:
#line 395 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("user")), LINE, n_user, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4456 "parser.c"
    break;

  case 268:
#line 396 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("welcome")), LINE, n_welcome, (yyvsp[-1].e), NUMBER); }
#line 4462 "parser.c"
    break;

  case 269:
#line 397 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("welcome")), LINE, n_welcome, NULL, NUMBER); }
#line 4468 "parser.c"
    break;

  case 270:
#line 398 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("working")), LINE, n_working, (yyvsp[-1].e), NUMBER); }
#line 4474 "parser.c"
    break;

  case 271:
#line 399 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("working")), LINE, n_working, NULL, NUMBER); }
#line 4480 "parser.c"
    break;

  case 272:
#line 403 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("AND")), LINE, n_and, (yyvsp[-1].e), NUMBER); }
#line 4486 "parser.c"
    break;

  case 273:
#line 404 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("BITAND")), LINE, n_bitand, (yyvsp[-1].e), NUMBER); }
#line 4492 "parser.c"
    break;

  case 274:
#line 405 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("BITNOT")), LINE, n_bitnot, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4498 "parser.c"
    break;

  case 275:
#line 406 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("BITOR")), LINE, n_bitor, (yyvsp[-1].e), NUMBER); }
#line 4504 "parser.c"
    break;

  case 276:
#line 407 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("BITXOR")), LINE, n_bitxor, (yyvsp[-1].e), NUMBER); }
#line 4510 "parser.c"
    break;

  case 277:
#line 408 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("NOT")), LINE, n_not, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4516 "parser.c"
    break;

  case 278:
#line 409 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("IN")), LINE, n_in, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4522 "parser.c"
    break;

  case 279:
#line 410 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("OR")), LINE, n_or, (yyvsp[-1].e), NUMBER); }
#line 4528 "parser.c"
    break;

  case 280:
#line 411 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("shiftleft")), LINE, n_shiftleft, (yyvsp[-1].e), NUMBER); }
#line 4534 "parser.c"
    break;

  case 281:
#line 412 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("shiftright")), LINE, n_shiftright, (yyvsp[-1].e), NUMBER); }
#line 4540 "parser.c"
    break;

  case 282:
#line 413 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("XOR")), LINE, n_xor, (yyvsp[-1].e), NUMBER); }
#line 4546 "parser.c"
    break;

  case 283:
#line 417 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("closemedia")), LINE, n_closemedia, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4552 "parser.c"
    break;

  case 284:
#line 418 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("effect")), LINE, n_effect, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4558 "parser.c"
    break;

  case 285:
#line 419 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("setmedia")), LINE, n_setmedia, (yyvsp[-1].e), NUMBER); }
#line 4564 "parser.c"
    break;

  case 286:
#line 420 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("setmedia")), LINE, n_setmedia, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4570 "parser.c"
    break;

  case 287:
#line 421 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("showmedia")), LINE, n_showmedia, merge(merge((yyvsp[-3].e), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4576 "parser.c"
    break;

  case 288:
#line 425 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("database")), LINE, n_database, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4582 "parser.c"
    break;

  case 289:
#line 426 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("database")), LINE, n_database, (yyvsp[-1].e), STRING); }
#line 4588 "parser.c"
    break;

  case 290:
#line 427 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("earlier")), LINE, n_earlier, (yyvsp[-1].e), NUMBER); }
#line 4594 "parser.c"
    break;

  case 291:
#line 428 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("getassign")), LINE, n_getassign, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4600 "parser.c"
    break;

  case 292:
#line 429 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("getassign")), LINE, n_getassign, (yyvsp[-1].e), STRING); }
#line 4606 "parser.c"
    break;

  case 293:
#line 430 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("getdevice")), LINE, n_getdevice, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4612 "parser.c"
    break;

  case 294:
#line 431 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("getdiskspace")), LINE, n_getdiskspace, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4618 "parser.c"
    break;

  case 295:
#line 432 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("getdiskspace")), LINE, n_getdiskspace, (yyvsp[-1].e), NUMBER); }
#line 4624 "parser.c"
    break;

  case 296:
#line 433 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("getenv")), LINE, n_getenv, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4630 "parser.c"
    break;

  case 297:
#line 434 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("getsize")), LINE, n_getsize, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4636 "parser.c"
    break;

  case 298:
#line 435 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("getsum")), LINE, n_getsum, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4642 "parser.c"
    break;

  case 299:
#line 436 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("getversion")), LINE, n_getversion, NULL, NUMBER); }
#line 4648 "parser.c"
    break;

  case 300:
#line 437 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("getversion")), LINE, n_getversion, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4654 "parser.c"
    break;

  case 301:
#line 438 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("getversion")), LINE, n_getversion, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4660 "parser.c"
    break;

  case 302:
#line 439 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("iconinfo")), LINE, n_iconinfo, (yyvsp[-1].e), NUMBER); }
#line 4666 "parser.c"
    break;

  case 303:
#line 440 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("querydisplay")), LINE, n_querydisplay, (yyvsp[-1].e), NUMBER); }
#line 4672 "parser.c"
    break;

  case 304:
#line 444 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("procedure")), LINE, n_procedure, push(new_contxt(), new_custom((yyvsp[-3].s), LINE, (yyvsp[-2].e), (yyvsp[-1].e))), NUMBER); }
#line 4678 "parser.c"
    break;

  case 305:
#line 445 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("procedure")), LINE, n_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, (yyvsp[-1].e), NULL)), NUMBER); }
#line 4684 "parser.c"
    break;

  case 306:
#line 446 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("procedure")), LINE, n_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, NULL, (yyvsp[-1].e))), NUMBER); }
#line 4690 "parser.c"
    break;

  case 307:
#line 447 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("procedure")), LINE, n_procedure, push(new_contxt(), new_custom((yyvsp[-1].s), LINE, NULL, NULL)), NUMBER); }
#line 4696 "parser.c"
    break;

  case 308:
#line 448 "../src/parser.y"
                                                 { (yyval.e) = new_cusref((yyvsp[-2].s), LINE, (yyvsp[-1].e)); }
#line 4702 "parser.c"
    break;

  case 309:
#line 449 "../src/parser.y"
                                                 { (yyval.e) = new_cusref((yyvsp[-1].s), LINE, NULL); }
#line 4708 "parser.c"
    break;

  case 310:
#line 453 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("askbool")), LINE, n_askbool, NULL, NUMBER); }
#line 4714 "parser.c"
    break;

  case 311:
#line 454 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("askbool")), LINE, n_askbool, (yyvsp[-1].e), NUMBER); }
#line 4720 "parser.c"
    break;

  case 312:
#line 455 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("askchoice")), LINE, n_askchoice, (yyvsp[-1].e), NUMBER); }
#line 4726 "parser.c"
    break;

  case 313:
#line 456 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("askdir")), LINE, n_askdir, NULL, STRING); }
#line 4732 "parser.c"
    break;

  case 314:
#line 457 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("askdir")), LINE, n_askdir, (yyvsp[-1].e), STRING); }
#line 4738 "parser.c"
    break;

  case 315:
#line 458 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("askdisk")), LINE, n_askdisk, (yyvsp[-1].e), NUMBER); }
#line 4744 "parser.c"
    break;

  case 316:
#line 459 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("askfile")), LINE, n_askfile, NULL, STRING); }
#line 4750 "parser.c"
    break;

  case 317:
#line 460 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("askfile")), LINE, n_askfile, (yyvsp[-1].e), STRING); }
#line 4756 "parser.c"
    break;

  case 318:
#line 461 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("asknumber")), LINE, n_asknumber, NULL, NUMBER); }
#line 4762 "parser.c"
    break;

  case 319:
#line 462 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("asknumber")), LINE, n_asknumber, (yyvsp[-1].e), NUMBER); }
#line 4768 "parser.c"
    break;

  case 320:
#line 463 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("askoptions")), LINE, n_askoptions, (yyvsp[-1].e), NUMBER); }
#line 4774 "parser.c"
    break;

  case 321:
#line 464 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("askstring")), LINE, n_askstring, NULL, STRING); }
#line 4780 "parser.c"
    break;

  case 322:
#line 465 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("askstring")), LINE, n_askstring, (yyvsp[-1].e), STRING); }
#line 4786 "parser.c"
    break;

  case 323:
#line 469 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("cat")), LINE, n_cat, (yyvsp[-1].e), STRING); }
#line 4792 "parser.c"
    break;

  case 324:
#line 470 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("expandpath")), LINE, n_expandpath, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4798 "parser.c"
    break;

  case 325:
#line 471 "../src/parser.y"
                                                 { (yyval.e) = new_native((yyvsp[-2].s), LINE, n_fmt, (yyvsp[-1].e), STRING); }
#line 4804 "parser.c"
    break;

  case 326:
#line 472 "../src/parser.y"
                                                 { (yyval.e) = new_native((yyvsp[-1].s), LINE, n_fmt, NULL, STRING); }
#line 4810 "parser.c"
    break;

  case 327:
#line 473 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("pathonly")), LINE, n_pathonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4816 "parser.c"
    break;

  case 328:
#line 474 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("patmatch")), LINE, n_patmatch, (yyvsp[-1].e), NUMBER); }
#line 4822 "parser.c"
    break;

  case 329:
#line 475 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("strlen")), LINE, n_strlen, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4828 "parser.c"
    break;

  case 330:
#line 476 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("substr")), LINE, n_substr, (yyvsp[-1].e), STRING); }
#line 4834 "parser.c"
    break;

  case 331:
#line 477 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("substr")), LINE, n_substr, push((yyvsp[-2].e), (yyvsp[-1].e)), STRING); }
#line 4840 "parser.c"
    break;

  case 332:
#line 478 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("tackon")), LINE, n_tackon, (yyvsp[-1].e), STRING); }
#line 4846 "parser.c"
    break;

  case 333:
#line 482 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("set")), LINE, n_set, (yyvsp[-1].e), DANGLE); }
#line 4852 "parser.c"
    break;

  case 334:
#line 483 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("symbolset")), LINE, n_symbolset, (yyvsp[-1].e), DANGLE); }
#line 4858 "parser.c"
    break;

  case 335:
#line 484 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("symbolval")), LINE, n_symbolval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4864 "parser.c"
    break;

  case 336:
#line 488 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("openwbobject")), LINE, n_openwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4870 "parser.c"
    break;

  case 337:
#line 489 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("openwbobject")), LINE, n_openwbobject, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4876 "parser.c"
    break;

  case 338:
#line 490 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("openwbobject")), LINE, n_openwbobject, merge(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4882 "parser.c"
    break;

  case 339:
#line 491 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("openwbobject")), LINE, n_openwbobject, merge(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4888 "parser.c"
    break;

  case 340:
#line 492 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("showwbobject")), LINE, n_showwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4894 "parser.c"
    break;

  case 341:
#line 493 "../src/parser.y"
                                                 { (yyval.e) = new_native(DBG_ALLOC(strdup("closewbobject")), LINE, n_closewbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4900 "parser.c"
    break;

  case 342:
#line 497 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("all")), OPT_ALL, NULL); }
#line 4906 "parser.c"
    break;

  case 343:
#line 498 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("append")), OPT_APPEND, (yyvsp[-1].e)); }
#line 4912 "parser.c"
    break;

  case 344:
#line 499 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("assigns")), OPT_ASSIGNS, NULL); }
#line 4918 "parser.c"
    break;

  case 345:
#line 500 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("back")), OPT_BACK, (yyvsp[-1].e)); }
#line 4924 "parser.c"
    break;

  case 346:
#line 501 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("choices")), OPT_CHOICES, (yyvsp[-1].e)); }
#line 4930 "parser.c"
    break;

  case 347:
#line 502 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("command")), OPT_COMMAND, (yyvsp[-1].e)); }
#line 4936 "parser.c"
    break;

  case 348:
#line 503 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("compression")), OPT_COMPRESSION, NULL); }
#line 4942 "parser.c"
    break;

  case 349:
#line 504 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("confirm")), OPT_CONFIRM, (yyvsp[-1].e)); }
#line 4948 "parser.c"
    break;

  case 350:
#line 505 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("confirm")), OPT_CONFIRM, NULL); }
#line 4954 "parser.c"
    break;

  case 351:
#line 506 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("default")), OPT_DEFAULT, push(new_contxt(), (yyvsp[-1].e))); }
#line 4960 "parser.c"
    break;

  case 352:
#line 507 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("delopts")), OPT_DELOPTS, (yyvsp[-1].e)); }
#line 4966 "parser.c"
    break;

  case 353:
#line 508 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("delopts")), OPT_DELOPTS, push(new_contxt(), new_symref(DBG_ALLOC(strdup("@null")), LINE))); }
#line 4972 "parser.c"
    break;

  case 354:
#line 509 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("dest")), OPT_DEST, push(new_contxt(), (yyvsp[-1].e))); }
#line 4978 "parser.c"
    break;

  case 355:
#line 510 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("disk")), OPT_DISK, NULL); }
#line 4984 "parser.c"
    break;

  case 356:
#line 511 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("files")), OPT_FILES, NULL); }
#line 4990 "parser.c"
    break;

  case 357:
#line 512 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("fonts")), OPT_FONTS, NULL); }
#line 4996 "parser.c"
    break;

  case 358:
#line 513 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("getdefaulttool")), OPT_GETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 5002 "parser.c"
    break;

  case 359:
#line 514 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("getposition")), OPT_GETPOSITION, (yyvsp[-1].e)); }
#line 5008 "parser.c"
    break;

  case 360:
#line 515 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("getstack")), OPT_GETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 5014 "parser.c"
    break;

  case 361:
#line 516 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("gettooltype")), OPT_GETTOOLTYPE, (yyvsp[-1].e)); }
#line 5020 "parser.c"
    break;

  case 362:
#line 517 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("help")), OPT_HELP, (yyvsp[-1].e)); }
#line 5026 "parser.c"
    break;

  case 363:
#line 518 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("help")), OPT_HELP, push(new_contxt(), new_symref(DBG_ALLOC(strdup("@null")), LINE))); }
#line 5032 "parser.c"
    break;

  case 364:
#line 519 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("infos")), OPT_INFOS, NULL); }
#line 5038 "parser.c"
    break;

  case 365:
#line 520 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("include")), OPT_INCLUDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 5044 "parser.c"
    break;

  case 366:
#line 521 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("newname")), OPT_NEWNAME, push(new_contxt(), (yyvsp[-1].e))); }
#line 5050 "parser.c"
    break;

  case 367:
#line 522 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("newpath")), OPT_NEWPATH, NULL); }
#line 5056 "parser.c"
    break;

  case 368:
#line 523 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("newpath")), OPT_NEWPATH, push(new_contxt(), (yyvsp[-1].e))); }
#line 5062 "parser.c"
    break;

  case 369:
#line 524 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("nogauge")), OPT_NOGAUGE, NULL); }
#line 5068 "parser.c"
    break;

  case 370:
#line 525 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("noposition")), OPT_NOPOSITION, NULL); }
#line 5074 "parser.c"
    break;

  case 371:
#line 526 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("noreq")), OPT_NOREQ, NULL); }
#line 5080 "parser.c"
    break;

  case 372:
#line 527 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("pattern")), OPT_PATTERN, push(new_contxt(), (yyvsp[-1].e))); }
#line 5086 "parser.c"
    break;

  case 373:
#line 528 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("prompt")), OPT_PROMPT, (yyvsp[-1].e)); }
#line 5092 "parser.c"
    break;

  case 374:
#line 529 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("prompt")), OPT_PROMPT, push(new_contxt(), new_symref(DBG_ALLOC(strdup("@null")), LINE))); }
#line 5098 "parser.c"
    break;

  case 375:
#line 530 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("quiet")), OPT_QUIET, NULL); }
#line 5104 "parser.c"
    break;

  case 376:
#line 531 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("range")), OPT_RANGE, (yyvsp[-1].e)); }
#line 5110 "parser.c"
    break;

  case 377:
#line 532 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("safe")), OPT_SAFE, NULL); }
#line 5116 "parser.c"
    break;

  case 378:
#line 533 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("setdefaulttool")), OPT_SETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 5122 "parser.c"
    break;

  case 379:
#line 534 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("setposition")), OPT_SETPOSITION, (yyvsp[-1].e)); }
#line 5128 "parser.c"
    break;

  case 380:
#line 535 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("setstack")), OPT_SETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 5134 "parser.c"
    break;

  case 381:
#line 536 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("settooltype")), OPT_SETTOOLTYPE, (yyvsp[-1].e)); }
#line 5140 "parser.c"
    break;

  case 382:
#line 537 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("settooltype")), OPT_SETTOOLTYPE, push(new_contxt(), (yyvsp[-1].e))); }
#line 5146 "parser.c"
    break;

  case 383:
#line 538 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("source")), OPT_SOURCE, push(new_contxt(), (yyvsp[-1].e))); }
#line 5152 "parser.c"
    break;

  case 384:
#line 539 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("source")), OPT_SOURCE, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 5158 "parser.c"
    break;

  case 385:
#line 540 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("swapcolors")), OPT_SWAPCOLORS, NULL); }
#line 5164 "parser.c"
    break;

  case 386:
#line 541 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("optional")), OPT_OPTIONAL, (yyvsp[-1].e)); }
#line 5170 "parser.c"
    break;

  case 387:
#line 542 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("optional")), OPT_OPTIONAL, push(new_contxt(), new_symref(DBG_ALLOC(strdup("@null")), LINE))); }
#line 5176 "parser.c"
    break;

  case 388:
#line 543 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("resident")), OPT_RESIDENT, NULL); }
#line 5182 "parser.c"
    break;

  case 389:
#line 544 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("override")), OPT_OVERRIDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 5188 "parser.c"
    break;

  case 390:
#line 545 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("dynopt")), OPT_DYNOPT, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 5194 "parser.c"
    break;

  case 391:
#line 546 "../src/parser.y"
                                                 { (yyval.e) = new_option(DBG_ALLOC(strdup("dynopt")), OPT_DYNOPT, push(push(push(new_contxt(), (yyvsp[-3].e)), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 5200 "parser.c"
    break;


#line 5204 "parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 548 "../src/parser.y"

