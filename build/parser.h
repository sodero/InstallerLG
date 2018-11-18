/* A Bison parser, made by GNU Bison 3.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
    INT = 260,
    HEX = 261,
    BIN = 262,
    AND = 263,
    BITAND = 264,
    BITNOT = 265,
    BITOR = 266,
    BITXOR = 267,
    NOT = 268,
    IN = 269,
    OR = 270,
    SHIFTLEFT = 271,
    SHIFTRIGHT = 272,
    XOR = 273,
    EQ = 274,
    GT = 275,
    GTE = 276,
    LT = 277,
    LTE = 278,
    NEQ = 279,
    IF = 280,
    SELECT = 281,
    UNTIL = 282,
    WHILE = 283,
    TRACE = 284,
    RETRACE = 285,
    EXECUTE = 286,
    REXX = 287,
    RUN = 288,
    ABORT = 289,
    EXIT = 290,
    ONERROR = 291,
    TRAP = 292,
    REBOOT = 293,
    COPYFILES = 294,
    COPYLIB = 295,
    DELETE = 296,
    EXISTS = 297,
    FILEONLY = 298,
    FOREACH = 299,
    MAKEASSIGN = 300,
    MAKEDIR = 301,
    PROTECT = 302,
    STARTUP = 303,
    TEXTFILE = 304,
    TOOLTYPE = 305,
    TRANSCRIPT = 306,
    RENAME = 307,
    COMPLETE = 308,
    DEBUG = 309,
    MESSAGE = 310,
    USER = 311,
    WELCOME = 312,
    WORKING = 313,
    DATABASE = 314,
    EARLIER = 315,
    GETASSIGN = 316,
    GETDEVICE = 317,
    GETDISKSPACE = 318,
    GETENV = 319,
    GETSIZE = 320,
    GETSUM = 321,
    GETVERSION = 322,
    ICONINFO = 323,
    CUS = 324,
    DCL = 325,
    ASKBOOL = 326,
    ASKCHOICE = 327,
    ASKDIR = 328,
    ASKDISK = 329,
    ASKFILE = 330,
    ASKNUMBER = 331,
    ASKOPTIONS = 332,
    ASKSTRING = 333,
    CAT = 334,
    EXPANDPATH = 335,
    FMT = 336,
    PATHONLY = 337,
    PATMATCH = 338,
    STRLEN = 339,
    SUBSTR = 340,
    TACKON = 341,
    SET = 342,
    SYMBOLSET = 343,
    SYMBOLVAL = 344,
    OPENWBOBJECT = 345,
    SHOWWBOBJECT = 346,
    CLOSEWBOBJECT = 347,
    ALL = 348,
    APPEND = 349,
    ASSIGNS = 350,
    CHOICES = 351,
    COMMAND = 352,
    COMPRESSION = 353,
    CONFIRM = 354,
    DEFAULT = 355,
    DELOPTS = 356,
    DEST = 357,
    DISK = 358,
    FILES = 359,
    FONTS = 360,
    GETDEFAULTTOOL = 361,
    GETPOSITION = 362,
    GETSTACK = 363,
    GETTOOLTYPE = 364,
    HELP = 365,
    INFOS = 366,
    INCLUDE = 367,
    NEWNAME = 368,
    NEWPATH = 369,
    NOGAUGE = 370,
    NOPOSITION = 371,
    NOREQ = 372,
    PATTERN = 373,
    PROMPT = 374,
    QUIET = 375,
    RANGE = 376,
    SAFE = 377,
    SETDEFAULTTOOL = 378,
    SETPOSITION = 379,
    SETSTACK = 380,
    SETTOOLTYPE = 381,
    SOURCE = 382,
    SWAPCOLORS = 383,
    OPTIONAL = 384,
    RESIDENT = 385,
    OVERRIDE = 386
  };
#endif
/* Tokens.  */
#define SYM 258
#define STR 259
#define INT 260
#define HEX 261
#define BIN 262
#define AND 263
#define BITAND 264
#define BITNOT 265
#define BITOR 266
#define BITXOR 267
#define NOT 268
#define IN 269
#define OR 270
#define SHIFTLEFT 271
#define SHIFTRIGHT 272
#define XOR 273
#define EQ 274
#define GT 275
#define GTE 276
#define LT 277
#define LTE 278
#define NEQ 279
#define IF 280
#define SELECT 281
#define UNTIL 282
#define WHILE 283
#define TRACE 284
#define RETRACE 285
#define EXECUTE 286
#define REXX 287
#define RUN 288
#define ABORT 289
#define EXIT 290
#define ONERROR 291
#define TRAP 292
#define REBOOT 293
#define COPYFILES 294
#define COPYLIB 295
#define DELETE 296
#define EXISTS 297
#define FILEONLY 298
#define FOREACH 299
#define MAKEASSIGN 300
#define MAKEDIR 301
#define PROTECT 302
#define STARTUP 303
#define TEXTFILE 304
#define TOOLTYPE 305
#define TRANSCRIPT 306
#define RENAME 307
#define COMPLETE 308
#define DEBUG 309
#define MESSAGE 310
#define USER 311
#define WELCOME 312
#define WORKING 313
#define DATABASE 314
#define EARLIER 315
#define GETASSIGN 316
#define GETDEVICE 317
#define GETDISKSPACE 318
#define GETENV 319
#define GETSIZE 320
#define GETSUM 321
#define GETVERSION 322
#define ICONINFO 323
#define CUS 324
#define DCL 325
#define ASKBOOL 326
#define ASKCHOICE 327
#define ASKDIR 328
#define ASKDISK 329
#define ASKFILE 330
#define ASKNUMBER 331
#define ASKOPTIONS 332
#define ASKSTRING 333
#define CAT 334
#define EXPANDPATH 335
#define FMT 336
#define PATHONLY 337
#define PATMATCH 338
#define STRLEN 339
#define SUBSTR 340
#define TACKON 341
#define SET 342
#define SYMBOLSET 343
#define SYMBOLVAL 344
#define OPENWBOBJECT 345
#define SHOWWBOBJECT 346
#define CLOSEWBOBJECT 347
#define ALL 348
#define APPEND 349
#define ASSIGNS 350
#define CHOICES 351
#define COMMAND 352
#define COMPRESSION 353
#define CONFIRM 354
#define DEFAULT 355
#define DELOPTS 356
#define DEST 357
#define DISK 358
#define FILES 359
#define FONTS 360
#define GETDEFAULTTOOL 361
#define GETPOSITION 362
#define GETSTACK 363
#define GETTOOLTYPE 364
#define HELP 365
#define INFOS 366
#define INCLUDE 367
#define NEWNAME 368
#define NEWPATH 369
#define NOGAUGE 370
#define NOPOSITION 371
#define NOREQ 372
#define PATTERN 373
#define PROMPT 374
#define QUIET 375
#define RANGE 376
#define SAFE 377
#define SETDEFAULTTOOL 378
#define SETPOSITION 379
#define SETSTACK 380
#define SETTOOLTYPE 381
#define SOURCE 382
#define SWAPCOLORS 383
#define OPTIONAL 384
#define RESIDENT 385
#define OVERRIDE 386

/* Value type.  */



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
