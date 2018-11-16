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
    EXECUTE = 284,
    REXX = 285,
    RUN = 286,
    ABORT = 287,
    EXIT = 288,
    ONERROR = 289,
    TRAP = 290,
    REBOOT = 291,
    COPYFILES = 292,
    COPYLIB = 293,
    DELETE = 294,
    EXISTS = 295,
    FILEONLY = 296,
    FOREACH = 297,
    MAKEASSIGN = 298,
    MAKEDIR = 299,
    PROTECT = 300,
    STARTUP = 301,
    TEXTFILE = 302,
    TOOLTYPE = 303,
    TRANSCRIPT = 304,
    RENAME = 305,
    COMPLETE = 306,
    DEBUG = 307,
    MESSAGE = 308,
    USER = 309,
    WELCOME = 310,
    WORKING = 311,
    DATABASE = 312,
    EARLIER = 313,
    GETASSIGN = 314,
    GETDEVICE = 315,
    GETDISKSPACE = 316,
    GETENV = 317,
    GETSIZE = 318,
    GETSUM = 319,
    GETVERSION = 320,
    ICONINFO = 321,
    CUS = 322,
    DCL = 323,
    ASKBOOL = 324,
    ASKCHOICE = 325,
    ASKDIR = 326,
    ASKDISK = 327,
    ASKFILE = 328,
    ASKNUMBER = 329,
    ASKOPTIONS = 330,
    ASKSTRING = 331,
    CAT = 332,
    EXPANDPATH = 333,
    FMT = 334,
    PATHONLY = 335,
    PATMATCH = 336,
    STRLEN = 337,
    SUBSTR = 338,
    TACKON = 339,
    SET = 340,
    SYMBOLSET = 341,
    SYMBOLVAL = 342,
    OPENWBOBJECT = 343,
    SHOWWBOBJECT = 344,
    CLOSEWBOBJECT = 345,
    ALL = 346,
    APPEND = 347,
    ASSIGNS = 348,
    CHOICES = 349,
    COMMAND = 350,
    COMPRESSION = 351,
    CONFIRM = 352,
    DEFAULT = 353,
    DELOPTS = 354,
    DEST = 355,
    DISK = 356,
    FILES = 357,
    FONTS = 358,
    GETDEFAULTTOOL = 359,
    GETPOSITION = 360,
    GETSTACK = 361,
    GETTOOLTYPE = 362,
    HELP = 363,
    INFOS = 364,
    INCLUDE = 365,
    NEWNAME = 366,
    NEWPATH = 367,
    NOGAUGE = 368,
    NOPOSITION = 369,
    NOREQ = 370,
    PATTERN = 371,
    PROMPT = 372,
    QUIET = 373,
    RANGE = 374,
    SAFE = 375,
    SETDEFAULTTOOL = 376,
    SETPOSITION = 377,
    SETSTACK = 378,
    SETTOOLTYPE = 379,
    SOURCE = 380,
    SWAPCOLORS = 381,
    OPTIONAL = 382,
    RESIDENT = 383,
    OVERRIDE = 384
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
#define EXECUTE 284
#define REXX 285
#define RUN 286
#define ABORT 287
#define EXIT 288
#define ONERROR 289
#define TRAP 290
#define REBOOT 291
#define COPYFILES 292
#define COPYLIB 293
#define DELETE 294
#define EXISTS 295
#define FILEONLY 296
#define FOREACH 297
#define MAKEASSIGN 298
#define MAKEDIR 299
#define PROTECT 300
#define STARTUP 301
#define TEXTFILE 302
#define TOOLTYPE 303
#define TRANSCRIPT 304
#define RENAME 305
#define COMPLETE 306
#define DEBUG 307
#define MESSAGE 308
#define USER 309
#define WELCOME 310
#define WORKING 311
#define DATABASE 312
#define EARLIER 313
#define GETASSIGN 314
#define GETDEVICE 315
#define GETDISKSPACE 316
#define GETENV 317
#define GETSIZE 318
#define GETSUM 319
#define GETVERSION 320
#define ICONINFO 321
#define CUS 322
#define DCL 323
#define ASKBOOL 324
#define ASKCHOICE 325
#define ASKDIR 326
#define ASKDISK 327
#define ASKFILE 328
#define ASKNUMBER 329
#define ASKOPTIONS 330
#define ASKSTRING 331
#define CAT 332
#define EXPANDPATH 333
#define FMT 334
#define PATHONLY 335
#define PATMATCH 336
#define STRLEN 337
#define SUBSTR 338
#define TACKON 339
#define SET 340
#define SYMBOLSET 341
#define SYMBOLVAL 342
#define OPENWBOBJECT 343
#define SHOWWBOBJECT 344
#define CLOSEWBOBJECT 345
#define ALL 346
#define APPEND 347
#define ASSIGNS 348
#define CHOICES 349
#define COMMAND 350
#define COMPRESSION 351
#define CONFIRM 352
#define DEFAULT 353
#define DELOPTS 354
#define DEST 355
#define DISK 356
#define FILES 357
#define FONTS 358
#define GETDEFAULTTOOL 359
#define GETPOSITION 360
#define GETSTACK 361
#define GETTOOLTYPE 362
#define HELP 363
#define INFOS 364
#define INCLUDE 365
#define NEWNAME 366
#define NEWPATH 367
#define NOGAUGE 368
#define NOPOSITION 369
#define NOREQ 370
#define PATTERN 371
#define PROMPT 372
#define QUIET 373
#define RANGE 374
#define SAFE 375
#define SETDEFAULTTOOL 376
#define SETPOSITION 377
#define SETSTACK 378
#define SETTOOLTYPE 379
#define SOURCE 380
#define SWAPCOLORS 381
#define OPTIONAL 382
#define RESIDENT 383
#define OVERRIDE 384

/* Value type.  */



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
