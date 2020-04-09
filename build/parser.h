/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SYM = 258,
    STR = 259,
    OOM = 260,
    INT = 261,
    HEX = 262,
    BIN = 263,
    EQ = 264,
    GT = 265,
    GTE = 266,
    LT = 267,
    LTE = 268,
    NEQ = 269,
    IF = 270,
    SELECT = 271,
    UNTIL = 272,
    WHILE = 273,
    TRACE = 274,
    RETRACE = 275,
    ASTRAW = 276,
    ASBRAW = 277,
    ASBEVAL = 278,
    EVAL = 279,
    OPTIONS = 280,
    EXECUTE = 281,
    REXX = 282,
    RUN = 283,
    ABORT = 284,
    EXIT = 285,
    ONERROR = 286,
    TRAP = 287,
    REBOOT = 288,
    COPYFILES = 289,
    COPYLIB = 290,
    DELETE = 291,
    EXISTS = 292,
    FILEONLY = 293,
    FOREACH = 294,
    MAKEASSIGN = 295,
    MAKEDIR = 296,
    PROTECT = 297,
    STARTUP = 298,
    TEXTFILE = 299,
    TOOLTYPE = 300,
    TRANSCRIPT = 301,
    RENAME = 302,
    COMPLETE = 303,
    DEBUG = 304,
    MESSAGE = 305,
    USER = 306,
    WELCOME = 307,
    WORKING = 308,
    AND = 309,
    BITAND = 310,
    BITNOT = 311,
    BITOR = 312,
    BITXOR = 313,
    NOT = 314,
    IN = 315,
    OR = 316,
    SHIFTLEFT = 317,
    SHIFTRIGHT = 318,
    XOR = 319,
    CLOSEMEDIA = 320,
    EFFECT = 321,
    SETMEDIA = 322,
    SHOWMEDIA = 323,
    DATABASE = 324,
    EARLIER = 325,
    GETASSIGN = 326,
    GETDEVICE = 327,
    GETDISKSPACE = 328,
    GETENV = 329,
    GETSIZE = 330,
    GETSUM = 331,
    GETVERSION = 332,
    ICONINFO = 333,
    QUERYDISPLAY = 334,
    CUS = 335,
    DCL = 336,
    ASKBOOL = 337,
    ASKCHOICE = 338,
    ASKDIR = 339,
    ASKDISK = 340,
    ASKFILE = 341,
    ASKNUMBER = 342,
    ASKOPTIONS = 343,
    ASKSTRING = 344,
    CAT = 345,
    EXPANDPATH = 346,
    FMT = 347,
    PATHONLY = 348,
    PATMATCH = 349,
    STRLEN = 350,
    SUBSTR = 351,
    TACKON = 352,
    SET = 353,
    SYMBOLSET = 354,
    SYMBOLVAL = 355,
    OPENWBOBJECT = 356,
    SHOWWBOBJECT = 357,
    CLOSEWBOBJECT = 358,
    ALL = 359,
    APPEND = 360,
    ASSIGNS = 361,
    BACK = 362,
    CHOICES = 363,
    COMMAND = 364,
    COMPRESSION = 365,
    CONFIRM = 366,
    DEFAULT = 367,
    DELOPTS = 368,
    DEST = 369,
    DISK = 370,
    FILES = 371,
    FONTS = 372,
    GETDEFAULTTOOL = 373,
    GETPOSITION = 374,
    GETSTACK = 375,
    GETTOOLTYPE = 376,
    HELP = 377,
    INFOS = 378,
    INCLUDE = 379,
    NEWNAME = 380,
    NEWPATH = 381,
    NOGAUGE = 382,
    NOPOSITION = 383,
    NOREQ = 384,
    PATTERN = 385,
    PROMPT = 386,
    QUIET = 387,
    RANGE = 388,
    SAFE = 389,
    SETDEFAULTTOOL = 390,
    SETPOSITION = 391,
    SETSTACK = 392,
    SETTOOLTYPE = 393,
    SOURCE = 394,
    SWAPCOLORS = 395,
    OPTIONAL = 396,
    RESIDENT = 397,
    OVERRIDE = 398
  };
#endif

/* Value type.  */



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
