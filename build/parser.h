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
    OPTIONS = 279,
    EXECUTE = 280,
    REXX = 281,
    RUN = 282,
    ABORT = 283,
    EXIT = 284,
    ONERROR = 285,
    TRAP = 286,
    REBOOT = 287,
    COPYFILES = 288,
    COPYLIB = 289,
    DELETE = 290,
    EXISTS = 291,
    FILEONLY = 292,
    FOREACH = 293,
    MAKEASSIGN = 294,
    MAKEDIR = 295,
    PROTECT = 296,
    STARTUP = 297,
    TEXTFILE = 298,
    TOOLTYPE = 299,
    TRANSCRIPT = 300,
    RENAME = 301,
    COMPLETE = 302,
    DEBUG = 303,
    MESSAGE = 304,
    USER = 305,
    WELCOME = 306,
    WORKING = 307,
    AND = 308,
    BITAND = 309,
    BITNOT = 310,
    BITOR = 311,
    BITXOR = 312,
    NOT = 313,
    IN = 314,
    OR = 315,
    SHIFTLEFT = 316,
    SHIFTRIGHT = 317,
    XOR = 318,
    CLOSEMEDIA = 319,
    EFFECT = 320,
    SETMEDIA = 321,
    SHOWMEDIA = 322,
    DATABASE = 323,
    EARLIER = 324,
    GETASSIGN = 325,
    GETDEVICE = 326,
    GETDISKSPACE = 327,
    GETENV = 328,
    GETSIZE = 329,
    GETSUM = 330,
    GETVERSION = 331,
    ICONINFO = 332,
    QUERYDISPLAY = 333,
    CUS = 334,
    DCL = 335,
    ASKBOOL = 336,
    ASKCHOICE = 337,
    ASKDIR = 338,
    ASKDISK = 339,
    ASKFILE = 340,
    ASKNUMBER = 341,
    ASKOPTIONS = 342,
    ASKSTRING = 343,
    CAT = 344,
    EXPANDPATH = 345,
    FMT = 346,
    PATHONLY = 347,
    PATMATCH = 348,
    STRLEN = 349,
    SUBSTR = 350,
    TACKON = 351,
    SET = 352,
    SYMBOLSET = 353,
    SYMBOLVAL = 354,
    OPENWBOBJECT = 355,
    SHOWWBOBJECT = 356,
    CLOSEWBOBJECT = 357,
    ALL = 358,
    APPEND = 359,
    ASSIGNS = 360,
    BACK = 361,
    CHOICES = 362,
    COMMAND = 363,
    COMPRESSION = 364,
    CONFIRM = 365,
    DEFAULT = 366,
    DELOPTS = 367,
    DEST = 368,
    DISK = 369,
    FILES = 370,
    FONTS = 371,
    GETDEFAULTTOOL = 372,
    GETPOSITION = 373,
    GETSTACK = 374,
    GETTOOLTYPE = 375,
    HELP = 376,
    INFOS = 377,
    INCLUDE = 378,
    NEWNAME = 379,
    NEWPATH = 380,
    NOGAUGE = 381,
    NOPOSITION = 382,
    NOREQ = 383,
    PATTERN = 384,
    PROMPT = 385,
    QUIET = 386,
    RANGE = 387,
    SAFE = 388,
    SETDEFAULTTOOL = 389,
    SETPOSITION = 390,
    SETSTACK = 391,
    SETTOOLTYPE = 392,
    SOURCE = 393,
    SWAPCOLORS = 394,
    OPTIONAL = 395,
    RESIDENT = 396,
    OVERRIDE = 397
  };
#endif

/* Value type.  */



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
