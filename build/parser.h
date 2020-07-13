/* A Bison parser, made by GNU Bison 3.6.4.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
