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
    EXECUTE = 279,
    REXX = 280,
    RUN = 281,
    ABORT = 282,
    EXIT = 283,
    ONERROR = 284,
    TRAP = 285,
    REBOOT = 286,
    COPYFILES = 287,
    COPYLIB = 288,
    DELETE = 289,
    EXISTS = 290,
    FILEONLY = 291,
    FOREACH = 292,
    MAKEASSIGN = 293,
    MAKEDIR = 294,
    PROTECT = 295,
    STARTUP = 296,
    TEXTFILE = 297,
    TOOLTYPE = 298,
    TRANSCRIPT = 299,
    RENAME = 300,
    COMPLETE = 301,
    DEBUG = 302,
    MESSAGE = 303,
    USER = 304,
    WELCOME = 305,
    WORKING = 306,
    AND = 307,
    BITAND = 308,
    BITNOT = 309,
    BITOR = 310,
    BITXOR = 311,
    NOT = 312,
    IN = 313,
    OR = 314,
    SHIFTLEFT = 315,
    SHIFTRIGHT = 316,
    XOR = 317,
    CLOSEMEDIA = 318,
    EFFECT = 319,
    SETMEDIA = 320,
    SHOWMEDIA = 321,
    DATABASE = 322,
    EARLIER = 323,
    GETASSIGN = 324,
    GETDEVICE = 325,
    GETDISKSPACE = 326,
    GETENV = 327,
    GETSIZE = 328,
    GETSUM = 329,
    GETVERSION = 330,
    ICONINFO = 331,
    QUERYDISPLAY = 332,
    CUS = 333,
    DCL = 334,
    ASKBOOL = 335,
    ASKCHOICE = 336,
    ASKDIR = 337,
    ASKDISK = 338,
    ASKFILE = 339,
    ASKNUMBER = 340,
    ASKOPTIONS = 341,
    ASKSTRING = 342,
    CAT = 343,
    EXPANDPATH = 344,
    FMT = 345,
    PATHONLY = 346,
    PATMATCH = 347,
    STRLEN = 348,
    SUBSTR = 349,
    TACKON = 350,
    SET = 351,
    SYMBOLSET = 352,
    SYMBOLVAL = 353,
    OPENWBOBJECT = 354,
    SHOWWBOBJECT = 355,
    CLOSEWBOBJECT = 356,
    ALL = 357,
    APPEND = 358,
    ASSIGNS = 359,
    BACK = 360,
    CHOICES = 361,
    COMMAND = 362,
    COMPRESSION = 363,
    CONFIRM = 364,
    DEFAULT = 365,
    DELOPTS = 366,
    DEST = 367,
    DISK = 368,
    FILES = 369,
    FONTS = 370,
    GETDEFAULTTOOL = 371,
    GETPOSITION = 372,
    GETSTACK = 373,
    GETTOOLTYPE = 374,
    HELP = 375,
    INFOS = 376,
    INCLUDE = 377,
    NEWNAME = 378,
    NEWPATH = 379,
    NOGAUGE = 380,
    NOPOSITION = 381,
    NOREQ = 382,
    PATTERN = 383,
    PROMPT = 384,
    QUIET = 385,
    RANGE = 386,
    SAFE = 387,
    SETDEFAULTTOOL = 388,
    SETPOSITION = 389,
    SETSTACK = 390,
    SETTOOLTYPE = 391,
    SOURCE = 392,
    SWAPCOLORS = 393,
    OPTIONAL = 394,
    RESIDENT = 395,
    OVERRIDE = 396
  };
#endif

/* Value type.  */



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
