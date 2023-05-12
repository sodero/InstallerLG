/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
    EXPANDPATH = 293,              /* EXPANDPATH  */
    FILEONLY = 294,                /* FILEONLY  */
    FOREACH = 295,                 /* FOREACH  */
    MAKEASSIGN = 296,              /* MAKEASSIGN  */
    MAKEDIR = 297,                 /* MAKEDIR  */
    PROTECT = 298,                 /* PROTECT  */
    STARTUP = 299,                 /* STARTUP  */
    TEXTFILE = 300,                /* TEXTFILE  */
    TOOLTYPE = 301,                /* TOOLTYPE  */
    TRANSCRIPT = 302,              /* TRANSCRIPT  */
    RENAME = 303,                  /* RENAME  */
    COMPLETE = 304,                /* COMPLETE  */
    DEBUG = 305,                   /* DEBUG  */
    MESSAGE = 306,                 /* MESSAGE  */
    USER = 307,                    /* USER  */
    WELCOME = 308,                 /* WELCOME  */
    WORKING = 309,                 /* WORKING  */
    AND = 310,                     /* AND  */
    BITAND = 311,                  /* BITAND  */
    BITNOT = 312,                  /* BITNOT  */
    BITOR = 313,                   /* BITOR  */
    BITXOR = 314,                  /* BITXOR  */
    NOT = 315,                     /* NOT  */
    IN = 316,                      /* IN  */
    OR = 317,                      /* OR  */
    SHIFTLEFT = 318,               /* SHIFTLEFT  */
    SHIFTRIGHT = 319,              /* SHIFTRIGHT  */
    XOR = 320,                     /* XOR  */
    CLOSEMEDIA = 321,              /* CLOSEMEDIA  */
    EFFECT = 322,                  /* EFFECT  */
    SETMEDIA = 323,                /* SETMEDIA  */
    SHOWMEDIA = 324,               /* SHOWMEDIA  */
    DATABASE = 325,                /* DATABASE  */
    EARLIER = 326,                 /* EARLIER  */
    GETASSIGN = 327,               /* GETASSIGN  */
    GETDEVICE = 328,               /* GETDEVICE  */
    GETDISKSPACE = 329,            /* GETDISKSPACE  */
    GETENV = 330,                  /* GETENV  */
    GETSIZE = 331,                 /* GETSIZE  */
    GETSUM = 332,                  /* GETSUM  */
    GETVERSION = 333,              /* GETVERSION  */
    ICONINFO = 334,                /* ICONINFO  */
    QUERYDISPLAY = 335,            /* QUERYDISPLAY  */
    CUS = 336,                     /* CUS  */
    DCL = 337,                     /* DCL  */
    ASKBOOL = 338,                 /* ASKBOOL  */
    ASKCHOICE = 339,               /* ASKCHOICE  */
    ASKDIR = 340,                  /* ASKDIR  */
    ASKDISK = 341,                 /* ASKDISK  */
    ASKFILE = 342,                 /* ASKFILE  */
    ASKNUMBER = 343,               /* ASKNUMBER  */
    ASKOPTIONS = 344,              /* ASKOPTIONS  */
    ASKSTRING = 345,               /* ASKSTRING  */
    CAT = 346,                     /* CAT  */
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
    OPTIONAL = 385,                /* OPTIONAL  */
    OVERRIDE = 386,                /* OVERRIDE  */
    PATTERN = 387,                 /* PATTERN  */
    PROMPT = 388,                  /* PROMPT  */
    QUIET = 389,                   /* QUIET  */
    RANGE = 390,                   /* RANGE  */
    RESIDENT = 391,                /* RESIDENT  */
    SAFE = 392,                    /* SAFE  */
    SETDEFAULTTOOL = 393,          /* SETDEFAULTTOOL  */
    SETPOSITION = 394,             /* SETPOSITION  */
    SETSTACK = 395,                /* SETSTACK  */
    SETTOOLTYPE = 396,             /* SETTOOLTYPE  */
    SOURCE = 397,                  /* SOURCE  */
    SWAPCOLORS = 398,              /* SWAPCOLORS  */
    UNIX = 399                     /* UNIX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
