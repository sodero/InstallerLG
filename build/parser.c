/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "../src/parser.y" /* yacc.c:339  */

//----------------------------------------------------------------------------
// parser.y:
//
// InstallerLG parser
//----------------------------------------------------------------------------
// Copyright (C) 2018, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//----------------------------------------------------------------------------

#include "all.h"
#include "alloc.h"
#include "eval.h"
#include "init.h"
#include "lexer.h"

#include <string.h>

#line 85 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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
    BACK = 351,
    CHOICES = 352,
    COMMAND = 353,
    COMPRESSION = 354,
    CONFIRM = 355,
    DEFAULT = 356,
    DELOPTS = 357,
    DEST = 358,
    DISK = 359,
    FILES = 360,
    FONTS = 361,
    GETDEFAULTTOOL = 362,
    GETPOSITION = 363,
    GETSTACK = 364,
    GETTOOLTYPE = 365,
    HELP = 366,
    INFOS = 367,
    INCLUDE = 368,
    NEWNAME = 369,
    NEWPATH = 370,
    NOGAUGE = 371,
    NOPOSITION = 372,
    NOREQ = 373,
    PATTERN = 374,
    PROMPT = 375,
    QUIET = 376,
    RANGE = 377,
    SAFE = 378,
    SETDEFAULTTOOL = 379,
    SETPOSITION = 380,
    SETSTACK = 381,
    SETTOOLTYPE = 382,
    SOURCE = 383,
    SWAPCOLORS = 384,
    OPTIONAL = 385,
    RESIDENT = 386,
    OVERRIDE = 387
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
#define BACK 351
#define CHOICES 352
#define COMMAND 353
#define COMPRESSION 354
#define CONFIRM 355
#define DEFAULT 356
#define DELOPTS 357
#define DEST 358
#define DISK 359
#define FILES 360
#define FONTS 361
#define GETDEFAULTTOOL 362
#define GETPOSITION 363
#define GETSTACK 364
#define GETTOOLTYPE 365
#define HELP 366
#define INFOS 367
#define INCLUDE 368
#define NEWNAME 369
#define NEWPATH 370
#define NOGAUGE 371
#define NOPOSITION 372
#define NOREQ 373
#define PATTERN 374
#define PROMPT 375
#define QUIET 376
#define RANGE 377
#define SAFE 378
#define SETDEFAULTTOOL 379
#define SETPOSITION 380
#define SETSTACK 381
#define SETTOOLTYPE 382
#define SOURCE 383
#define SWAPCOLORS 384
#define OPTIONAL 385
#define RESIDENT 386
#define OVERRIDE 387

/* Value type.  */



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 394 "parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  187
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1927

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  142
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  149
/* YYNRULES -- Number of rules.  */
#define YYNRULES  353
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  683

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   387

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     133,   134,   137,   135,     2,   138,     2,   136,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     141,   139,   140,     2,     2,     2,     2,     2,     2,     2,
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
     125,   126,   127,   128,   129,   130,   131,   132
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,    97,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   267,   268,   269,   270,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     286,   287,   288,   289,   290,   291,   294,   295,   296,   297,
     298,   299,   300,   301,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   318,   319,   320,   321,
     322,   323,   324,   326,   327,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   393,   394,   395,   396,   397,   398,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   428,   429,   430,   433,   434,   435,   436,   437,   438,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SYM", "STR", "INT", "HEX", "BIN", "AND",
  "BITAND", "BITNOT", "BITOR", "BITXOR", "NOT", "IN", "OR", "SHIFTLEFT",
  "SHIFTRIGHT", "XOR", "EQ", "GT", "GTE", "LT", "LTE", "NEQ", "IF",
  "SELECT", "UNTIL", "WHILE", "TRACE", "RETRACE", "EXECUTE", "REXX", "RUN",
  "ABORT", "EXIT", "ONERROR", "TRAP", "REBOOT", "COPYFILES", "COPYLIB",
  "DELETE", "EXISTS", "FILEONLY", "FOREACH", "MAKEASSIGN", "MAKEDIR",
  "PROTECT", "STARTUP", "TEXTFILE", "TOOLTYPE", "TRANSCRIPT", "RENAME",
  "COMPLETE", "DEBUG", "MESSAGE", "USER", "WELCOME", "WORKING", "DATABASE",
  "EARLIER", "GETASSIGN", "GETDEVICE", "GETDISKSPACE", "GETENV", "GETSIZE",
  "GETSUM", "GETVERSION", "ICONINFO", "CUS", "DCL", "ASKBOOL", "ASKCHOICE",
  "ASKDIR", "ASKDISK", "ASKFILE", "ASKNUMBER", "ASKOPTIONS", "ASKSTRING",
  "CAT", "EXPANDPATH", "FMT", "PATHONLY", "PATMATCH", "STRLEN", "SUBSTR",
  "TACKON", "SET", "SYMBOLSET", "SYMBOLVAL", "OPENWBOBJECT",
  "SHOWWBOBJECT", "CLOSEWBOBJECT", "ALL", "APPEND", "ASSIGNS", "BACK",
  "CHOICES", "COMMAND", "COMPRESSION", "CONFIRM", "DEFAULT", "DELOPTS",
  "DEST", "DISK", "FILES", "FONTS", "GETDEFAULTTOOL", "GETPOSITION",
  "GETSTACK", "GETTOOLTYPE", "HELP", "INFOS", "INCLUDE", "NEWNAME",
  "NEWPATH", "NOGAUGE", "NOPOSITION", "NOREQ", "PATTERN", "PROMPT",
  "QUIET", "RANGE", "SAFE", "SETDEFAULTTOOL", "SETPOSITION", "SETSTACK",
  "SETTOOLTYPE", "SOURCE", "SWAPCOLORS", "OPTIONAL", "RESIDENT",
  "OVERRIDE", "'('", "')'", "'+'", "'/'", "'*'", "'-'", "'='", "'>'",
  "'<'", "$accept", "start", "s", "p", "pp", "ps", "pps", "vp", "vps",
  "opts", "xpb", "xpbs", "np", "sps", "par", "cv", "cvv", "opt", "ivp",
  "add", "div", "mul", "sub", "and", "bitand", "bitnot", "bitor", "bitxor",
  "not", "in", "or", "shiftleft", "shiftright", "xor", "eq", "gt", "gte",
  "lt", "lte", "neq", "if", "select", "until", "while", "trace", "retrace",
  "execute", "rexx", "run", "abort", "exit", "onerror", "reboot", "trap",
  "copyfiles", "copylib", "delete", "exists", "fileonly", "foreach",
  "makeassign", "makedir", "protect", "startup", "textfile", "tooltype",
  "transcript", "rename", "complete", "debug", "message", "user",
  "welcome", "working", "database", "earlier", "getassign", "getdevice",
  "getdiskspace", "getenv", "getsize", "getsum", "getversion", "iconinfo",
  "dcl", "cus", "askbool", "askchoice", "askdir", "askdisk", "askfile",
  "asknumber", "askoptions", "askstring", "cat", "expandpath", "fmt",
  "pathonly", "patmatch", "strlen", "substr", "tackon", "set", "symbolset",
  "symbolval", "openwbobject", "showwbobject", "closewbobject", "all",
  "append", "assigns", "back", "choices", "command", "compression",
  "confirm", "default", "delopts", "dest", "disk", "files", "fonts",
  "getdefaulttool", "getposition", "getstack", "gettooltype", "help",
  "infos", "include", "newname", "newpath", "nogauge", "noposition",
  "noreq", "pattern", "prompt", "quiet", "range", "safe", "setdefaulttool",
  "setposition", "setstack", "settooltype", "source", "swapcolors",
  "optional", "resident", "override", "dynopt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
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
     385,   386,   387,    40,    41,    43,    47,    42,    45,    61,
      62,    60
};
# endif

#define YYPACT_NINF -528

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-528)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -118,  1449,    24,  -528,  -528,  -118,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,     7,    14,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,   -97,   -95,   351,   351,
     351,    54,    74,  -118,    54,   -86,   -82,   -82,   351,    54,
      54,    54,    54,   351,    54,   351,   -82,   -82,    54,    54,
      54,    81,   351,    54,    93,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    98,   -82,    51,  -111,   -82,   -87,
     -82,   -60,   -41,   -82,   -39,    54,    54,    54,    54,    54,
      54,    54,    59,    54,    54,   351,    54,    54,    54,    54,
      54,    54,    54,    54,    54,   -70,   -16,  -528,  -118,  -528,
    -528,  -528,  -528,  -528,  1588,  -528,  -528,   103,  -528,  -528,
    -528,   108,   123,    54,   -59,   -44,   -15,   -10,     1,    54,
     139,     5,    43,    45,    47,    49,    58,   150,    65,    67,
     765,  -118,  -118,  -528,  -528,   893,   160,   351,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
     240,   351,   247,   351,   260,  1171,  -528,   292,   298,   -12,
    -118,  -528,  1668,    -2,     3,    16,   351,    18,    78,  -118,
     314,    25,    27,   351,   331,    42,   -82,   397,    62,    64,
     464,    72,    82,  -528,   538,   544,   351,    86,  -528,   561,
     623,   628,    96,   101,   633,   106,   121,   662,   124,   128,
     140,   144,  -528,    77,    85,    35,  -528,    95,   100,  -528,
     105,   115,  -528,   127,  -528,   135,   137,  -528,   143,   681,
     147,   156,   158,   166,   697,   179,    54,    37,  -528,   779,
     188,   152,   351,   190,   192,  1270,   199,  1275,   207,   214,
     219,   238,  -528,  -528,   -70,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  1280,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  1449,  -528,  -528,   765,  -528,  -528,  -528,
    1290,   154,   174,    54,   248,    54,   250,  -118,    54,    54,
     261,  1295,    54,    54,    54,   264,   277,   290,    54,    54,
      54,    54,  1412,   295,    54,    54,   299,   308,   310,   316,
      54,    54,   327,    54,   332,    54,    54,    54,    54,    54,
     344,    54,   352,    54,   178,  -528,   182,  1431,   -82,  -528,
     195,  1548,  -528,   197,  1553,  -528,  -528,   361,  -528,  1563,
    -528,   206,    54,  -528,  -528,  -528,   210,   213,   388,  -528,
     368,  -528,   217,  1310,  -528,   377,   392,  -528,   391,  -528,
     226,   228,  -528,   230,  -528,   233,   235,  -528,   237,  -528,
    -528,  -528,  -528,   242,  -528,  -528,  -528,   244,  1568,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,   404,  -528,   405,  -528,  -528,  -528,   420,
      39,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,   421,  -528,  -528,    54,  -528,
    -528,    54,  -528,  -528,   254,   256,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  1573,  -528,  -528,  -528,
    -528,  -528,  1685,  -528,  1705,  -528,   289,  1710,  1727,  -528,
    -528,   423,   425,  1732,   428,  -528,  -528,  -528,   436,   441,
     443,   445,  -528,  1737,  -528,   447,   448,  -528,  -528,  -528,
    -528,   450,  1742,  -528,   451,  -528,   452,   453,   454,  1747,
     455,   456,  -528,  1752,  -528,   457,  -528,  -528,  -528,   294,
    -528,  -528,   360,  -528,  -528,   371,  -528,  -528,  -528,    52,
    -528,  -528,   380,  -528,  -528,  -528,  -528,  -528,  -528,   384,
    -528,  -528,  -528,  -528,   386,  -528,  -528,  -528,   394,  -528,
    -528,  -528,  -528,   459,  -528,  -528,  -528,  -528,  -528,   400,
    -528,   460,  1032,    52,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  1795,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,   461,  -528
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,    14,     3,    11,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     110,   109,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   142,   141,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     1,    13,    28,
      27,    24,    25,    26,     0,   277,     8,     0,     4,     5,
     294,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   192,   193,     0,     0,     0,    17,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    55,    54,
      56,    57,    58,    59,    60,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    61,    75,    62,    74,
       0,     0,     0,     0,     0,     0,   211,     0,     0,     0,
       0,   213,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,     0,     0,     0,     0,   255,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   268,     0,     0,     0,   278,     0,     0,   281,
       0,     0,   284,     0,   286,     0,     0,   289,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    15,     0,   276,     7,   293,   169,     6,
     170,   171,   172,   173,   174,     0,   176,   177,   178,   179,
     182,   184,   185,     0,   188,    21,    33,   187,   186,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   197,     0,     0,    16,   201,
       0,     0,   205,     0,     0,   206,   210,     0,   209,     0,
     212,     0,     0,   215,   216,   220,     0,     0,     0,   221,
       0,   223,     0,     0,   228,     0,     0,   226,     0,   232,
       0,     0,   236,     0,   234,     0,     0,   240,     0,   241,
     242,   243,   245,     0,   246,   247,   252,     0,     0,   253,
     254,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,     0,   269,     0,   271,    32,   275,     0,
       0,   279,   280,   282,   283,   285,   287,   288,   290,   291,
     292,   295,   296,   297,   298,     0,   300,    30,     0,   301,
     302,     0,   303,   304,     0,     0,   308,   309,   165,   166,
     167,   168,   180,   181,   183,   175,     0,    34,   189,    23,
     190,   191,     0,   310,     0,   312,     0,     0,     0,   316,
     318,     0,     0,     0,     0,   322,   323,   324,     0,     0,
       0,     0,   330,     0,   331,     0,     0,   334,   335,   336,
     337,     0,     0,   340,     0,   342,     0,     0,     0,     0,
       0,     0,   349,     0,   351,     0,    18,   194,   195,     0,
     198,   199,     0,   202,   203,     0,   207,   208,   214,     0,
     217,   218,     0,   222,   224,   227,   225,   229,   230,     0,
     235,   233,   237,   238,     0,   244,   249,   250,     0,   270,
     274,    31,   273,     0,   299,    29,     9,   305,   306,     0,
      19,     0,     0,     0,   311,   313,   314,   315,   317,   319,
     320,   321,   325,   326,   327,   328,   329,   332,   333,   338,
     339,   341,   343,   344,   345,   347,   346,   348,   350,   352,
     196,   200,   204,     0,   219,   231,   239,   251,   272,   307,
      20,     0,   353
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -528,  -528,  -319,   306,   390,   -89,  -528,     0,     2,   -92,
    -216,  -528,    55,  -528,  -528,  -528,  -528,  -527,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,  -528,
    -528,  -528,  -528,   315,  -528,  -528,  -115,  -528,   262,  -528,
    -528,  -528,  -528,  -528,  -528,  -528,   281,  -528,  -528
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   196,   204,   197,   349,   198,   188,   438,
     386,   390,   199,   347,   510,   218,   219,   228,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
       4,   185,     5,   186,   389,     4,   509,   278,   201,   202,
     189,   190,   191,   192,   193,     1,   210,   189,   190,   191,
     192,   193,   282,   326,   187,   643,   227,   271,   273,   226,
     270,   272,   274,   277,   283,   284,   286,   223,   507,   224,
     528,   293,   631,   297,   298,   299,   282,   329,   281,   300,
     306,   282,   304,   305,   325,   309,   310,   189,   190,   191,
     192,   193,   346,   324,   362,   327,   328,   330,   331,   333,
     335,   336,   338,   282,   332,   370,   339,   189,   190,   191,
     192,   193,   643,   352,   189,   190,   191,   192,   193,   355,
     371,   357,   282,   334,   282,   337,   189,   190,   191,   192,
     193,   189,   190,   191,   192,   193,   189,   190,   191,   192,
     193,   189,   190,   191,   192,   193,   681,     1,   363,   372,
     375,     1,   450,     4,   373,   279,   189,   190,   191,   192,
     193,   282,   453,   434,   436,   374,   282,   454,   437,   377,
     194,   195,   189,   190,   191,   192,   193,   194,   200,   282,
     455,   458,   459,   189,   190,   191,   192,   193,   466,   467,
     282,   469,   447,   189,   190,   191,   192,   193,     1,   508,
     547,   529,     1,   632,   549,   282,   474,   378,   440,   379,
     443,   380,   441,   381,   444,   673,     4,   194,     4,   449,
     434,   633,   382,   456,   364,   282,   479,   282,   480,   387,
     470,   388,   473,   475,   476,   282,   482,   275,   276,   483,
     503,   504,   461,   487,   194,   303,   484,   488,   282,   506,
     489,     4,     4,   391,   392,   364,   194,   308,   282,   511,
     493,   194,   322,   282,   512,   494,   194,   365,   282,   513,
     496,   194,   367,   189,   190,   191,   192,   193,   282,   514,
     189,   190,   191,   192,   193,   497,   194,   368,   499,   534,
     282,   515,   500,   189,   190,   191,   192,   193,   282,   516,
     282,   517,   194,   376,   501,   364,   282,   518,   502,     4,
       4,   520,   451,   383,   384,   282,   533,     1,   550,     4,
     521,   462,   522,   225,   435,   189,   190,   191,   192,   193,
     523,   189,   190,   191,   192,   193,   554,     1,   551,   557,
     558,   282,   596,   526,   563,   282,   597,   189,   190,   191,
     192,   193,   532,   573,   536,     4,   537,     5,   282,   600,
     282,   603,   582,   539,   189,   190,   191,   192,   193,     1,
     608,   541,   593,   282,   610,   599,   282,   611,   542,   602,
       1,   614,   605,   543,   189,   190,   191,   192,   193,   282,
     617,   282,   618,   282,   620,   612,   282,   621,   282,   622,
     282,   623,   544,   225,   439,   282,   625,   282,   626,   619,
     225,   442,   553,   185,   555,   546,   624,   282,   637,   282,
     638,     4,     4,   194,   445,   559,   628,     4,   565,   556,
     189,   190,   191,   192,   193,   203,   205,   203,   203,   208,
     209,   566,   203,   203,   203,   203,   203,   203,   217,   220,
     221,   222,     1,   645,   567,   275,   446,   282,   670,   574,
     280,   194,   448,   577,   285,   287,   288,   203,   290,   292,
     294,   296,   578,   639,   579,   203,   302,   463,   464,   307,
     580,     4,   311,   203,   314,   316,   317,   319,   320,   321,
     323,   583,     4,   364,   225,   472,   585,   189,   190,   191,
     192,   193,   340,   341,   203,   343,   203,   203,   592,   203,
     350,   351,   353,   354,   225,   203,   594,   203,   203,   203,
     203,   206,   207,   282,   671,   606,   211,   212,   213,   214,
     215,   216,   613,   366,   282,   672,   419,   366,   366,   369,
       4,   615,     5,   282,   674,   424,   366,   282,   675,   282,
     676,   289,   291,   385,   295,   616,   385,   282,   677,   301,
     225,   477,   366,   282,   679,   432,   312,   313,   315,   629,
     318,   189,   190,   191,   192,   193,     4,   189,   190,   191,
     192,   193,   465,   468,   630,   634,     4,   648,   342,   649,
     344,   345,   651,   348,   189,   190,   191,   192,   193,   356,
     652,   358,   359,   360,   361,   653,   366,   654,   366,   655,
     366,   657,   658,   366,   659,   661,   662,   663,   664,   666,
     667,   669,   457,   678,   680,   682,   369,   194,   481,   471,
     369,   641,   460,   478,   505,     0,   366,     0,     0,     0,
     366,   366,     0,     0,     0,   366,   366,   369,     0,     0,
     369,     0,     0,   369,     0,     0,   189,   190,   191,   192,
     193,   189,   190,   191,   192,   193,   189,   190,   191,   192,
     193,     0,   185,     0,   546,   366,     0,     0,     0,     0,
     525,     0,   527,     0,     0,   531,     0,     0,   535,     0,
       0,   366,     0,   366,     0,   189,   190,   191,   192,   193,
       0,   194,   485,     0,     0,     0,     0,   225,   486,     0,
       0,   366,     0,     0,   189,   190,   191,   192,   193,     0,
       0,     0,   385,     0,   194,   490,   385,     0,     0,   552,
     189,   190,   191,   192,   193,     0,     0,   561,   562,     0,
     564,     0,     0,     0,   568,   203,   570,   203,     0,     0,
     575,   576,     0,     0,     0,     0,   581,     0,     0,   203,
       0,   586,   203,   588,   589,   591,     0,     0,     0,   595,
       0,     0,     0,   366,     0,     0,     0,   366,     0,     0,
     366,     0,     0,     0,     0,   366,   194,   491,   609,     0,
       0,   194,   492,     0,     0,     0,   194,   495,   189,   190,
     191,   192,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   189,   190,   191,   192,   193,     0,     0,     0,
       0,     0,     0,     0,   366,   194,   498,     0,     0,   569,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   584,   194,   519,   587,     0,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,   524,     0,     0,   635,     0,     0,   636,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   385,     0,
     366,     0,     0,   366,   366,     0,     0,     0,     0,   366,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   366,
       0,     0,     0,     0,     0,     0,     0,     0,   366,     0,
       0,     0,     0,     0,     0,   369,    96,    97,   383,   366,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   194,   530,   109,     0,   110,   111,   393,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   225,     0,   178,   179,
     180,   181,   182,   183,   184,    96,    97,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,   109,     0,   110,   111,   393,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,     0,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     1,     0,   178,   179,   180,
     181,   182,   183,   184,    96,    97,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
       0,     0,   109,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,   190,   191,   192,   193,   189,   190,
     191,   192,   193,   189,   190,   191,   192,   193,     0,     0,
       0,     0,   422,   189,   190,   191,   192,   193,   189,   190,
     191,   192,   193,     0,   194,     0,   178,   179,   180,   181,
     182,   183,   184,    96,    97,     0,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,   109,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,     0,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   194,   538,     0,     0,     0,   194,   540,
       0,     0,     0,   194,   545,   189,   190,   191,   192,   193,
       0,     0,     0,   383,   548,     0,     0,     0,   194,   560,
       0,     0,     0,   424,   189,   190,   191,   192,   193,     0,
       0,     0,     0,   194,     0,   178,   179,   180,   181,   182,
     183,   184,    96,    97,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
     109,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,     0,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,     0,     0,   194,   572,     0,     0,     0,
       0,   189,   190,   191,   192,   193,   189,   190,   191,   192,
     193,     0,     0,     0,   225,   598,   189,   190,   191,   192,
     193,   189,   190,   191,   192,   193,   189,   190,   191,   192,
     193,     0,     1,     0,   178,   179,   180,   181,   182,   183,
     184,    96,    97,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,   109,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,     0,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   225,   601,     0,     0,     0,   225,   604,   189,   190,
     191,   192,   193,   452,     0,     0,   194,   607,     0,     0,
       0,   225,   627,     0,     0,     0,     1,   640,   189,   190,
     191,   192,   193,   189,   190,   191,   192,   193,     0,     0,
       0,   194,     0,   178,   179,   180,   181,   182,   183,   184,
     189,   190,   191,   192,   193,   189,   190,   191,   192,   193,
     189,   190,   191,   192,   193,   189,   190,   191,   192,   193,
     189,   190,   191,   192,   193,   189,   190,   191,   192,   193,
       0,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   282,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   642,   384,
     452,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   194,   644,
       0,     0,     0,   194,   646,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,   647,     0,     0,     0,   194,   650,     0,     0,     0,
     194,   656,     0,     0,     0,   194,   660,     0,     0,     0,
     194,   665,     0,     0,     0,   194,   668,     0,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433
};

static const yytype_int16 yycheck[] =
{
       0,     1,     0,     1,   220,     5,   325,   122,    97,    98,
       3,     4,     5,     6,     7,   133,   105,     3,     4,     5,
       6,     7,   133,   134,     0,   552,   118,   119,   120,   118,
     119,   120,   121,   122,   126,   127,   128,   134,     3,   134,
       3,   133,     3,   135,   136,   137,   133,   134,   134,   138,
     142,   133,   141,   142,     3,   144,   145,     3,     4,     5,
       6,     7,     3,   155,   134,   157,   158,   159,   160,   161,
     162,   163,   164,   133,   134,   134,   165,     3,     4,     5,
       6,     7,   609,   175,     3,     4,     5,     6,     7,   178,
     134,   180,   133,   134,   133,   134,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,   643,   133,   134,   134,
     209,   133,   134,   123,   134,   123,     3,     4,     5,     6,
       7,   133,   134,   225,   226,   134,   133,   134,   227,   134,
     133,   134,     3,     4,     5,     6,     7,   133,   134,   133,
     134,   133,   134,     3,     4,     5,     6,     7,   133,   134,
     133,   134,   277,     3,     4,     5,     6,     7,   133,   134,
     386,   134,   133,   134,   390,   133,   134,   134,   270,   134,
     272,   134,   271,   134,   273,   133,   186,   133,   188,   278,
     282,   510,   134,   285,   194,   133,   134,   133,   134,   134,
     292,   134,   294,   295,   296,   133,   134,   133,   134,   301,
     133,   134,   134,   305,   133,   134,   134,   306,   133,   134,
     134,   221,   222,   221,   222,   225,   133,   134,   133,   134,
     134,   133,   134,   133,   134,   134,   133,   134,   133,   134,
     134,   133,   134,     3,     4,     5,     6,     7,   133,   134,
       3,     4,     5,     6,     7,   134,   133,   134,   134,   351,
     133,   134,   134,     3,     4,     5,     6,     7,   133,   134,
     133,   134,   133,   134,   134,   275,   133,   134,   134,   279,
     280,   134,   280,   133,   134,   133,   134,   133,   134,   289,
     134,   289,   134,   133,   134,     3,     4,     5,     6,     7,
     134,     3,     4,     5,     6,     7,   395,   133,   134,   398,
     399,   133,   134,   134,   403,   133,   134,     3,     4,     5,
       6,     7,   134,   412,   134,   325,   134,   325,   133,   134,
     133,   134,   421,   134,     3,     4,     5,     6,     7,   133,
     134,   134,   431,   133,   134,   437,   133,   134,   134,   441,
     133,   134,   444,   134,     3,     4,     5,     6,     7,   133,
     134,   133,   134,   133,   134,   457,   133,   134,   133,   134,
     133,   134,   134,   133,   134,   133,   134,   133,   134,   471,
     133,   134,   134,   383,   134,   383,   478,   133,   134,   133,
     134,   391,   392,   133,   134,   134,   488,   397,   134,   397,
       3,     4,     5,     6,     7,    99,   100,   101,   102,   103,
     104,   134,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   133,   134,   134,   133,   134,   133,   134,   134,
     124,   133,   134,   134,   128,   129,   130,   131,   132,   133,
     134,   135,   134,   535,   134,   139,   140,   133,   134,   143,
     134,   451,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   134,   462,   463,   133,   134,   134,     3,     4,     5,
       6,     7,   166,   167,   168,   169,   170,   171,   134,   173,
     174,   175,   176,   177,   133,   179,   134,   181,   182,   183,
     184,   101,   102,   133,   134,   134,   106,   107,   108,   109,
     110,   111,   134,   197,   133,   134,   118,   201,   202,   203,
     510,   134,   510,   133,   134,   123,   210,   133,   134,   133,
     134,   131,   132,   217,   134,   134,   220,   133,   134,   139,
     133,   134,   226,   133,   134,   131,   146,   147,   148,   134,
     150,     3,     4,     5,     6,     7,   546,     3,     4,     5,
       6,     7,   290,   291,   134,   134,   556,   134,   168,   134,
     170,   171,   134,   173,     3,     4,     5,     6,     7,   179,
     134,   181,   182,   183,   184,   134,   270,   134,   272,   134,
     274,   134,   134,   277,   134,   134,   134,   134,   134,   134,
     134,   134,   286,   134,   134,   134,   290,   133,   134,   293,
     294,   546,   287,   297,   323,    -1,   300,    -1,    -1,    -1,
     304,   305,    -1,    -1,    -1,   309,   310,   311,    -1,    -1,
     314,    -1,    -1,   317,    -1,    -1,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,    -1,   642,    -1,   642,   339,    -1,    -1,    -1,    -1,
     344,    -1,   346,    -1,    -1,   349,    -1,    -1,   352,    -1,
      -1,   355,    -1,   357,    -1,     3,     4,     5,     6,     7,
      -1,   133,   134,    -1,    -1,    -1,    -1,   133,   134,    -1,
      -1,   375,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,   386,    -1,   133,   134,   390,    -1,    -1,   393,
       3,     4,     5,     6,     7,    -1,    -1,   401,   402,    -1,
     404,    -1,    -1,    -1,   408,   409,   410,   411,    -1,    -1,
     414,   415,    -1,    -1,    -1,    -1,   420,    -1,    -1,   423,
      -1,   425,   426,   427,   428,   429,    -1,    -1,    -1,   433,
      -1,    -1,    -1,   437,    -1,    -1,    -1,   441,    -1,    -1,
     444,    -1,    -1,    -1,    -1,   449,   133,   134,   452,    -1,
      -1,   133,   134,    -1,    -1,    -1,   133,   134,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   488,   133,   134,    -1,    -1,   409,
      -1,   411,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   423,   133,   134,   426,    -1,   428,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     133,   134,    -1,    -1,   528,    -1,    -1,   531,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   552,    -1,
     554,    -1,    -1,   557,   558,    -1,    -1,    -1,    -1,   563,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   573,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   582,    -1,
      -1,    -1,    -1,    -1,    -1,   589,     3,     4,   133,   593,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,   133,   134,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,   135,   136,
     137,   138,   139,   140,   141,     3,     4,    -1,    -1,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    -1,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,   135,   136,   137,
     138,   139,   140,   141,     3,     4,    -1,    -1,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,   121,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,    -1,   133,    -1,   135,   136,   137,   138,
     139,   140,   141,     3,     4,    -1,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   133,   134,    -1,    -1,    -1,   133,   134,
      -1,    -1,    -1,   133,   134,     3,     4,     5,     6,     7,
      -1,    -1,    -1,   133,   134,    -1,    -1,    -1,   133,   134,
      -1,    -1,    -1,   123,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,   133,    -1,   135,   136,   137,   138,   139,
     140,   141,     3,     4,    -1,    -1,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    -1,   133,   134,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,    -1,    -1,    -1,   133,   134,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,    -1,   133,    -1,   135,   136,   137,   138,   139,   140,
     141,     3,     4,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,   133,   134,    -1,    -1,    -1,   133,   134,     3,     4,
       5,     6,     7,    25,    -1,    -1,   133,   134,    -1,    -1,
      -1,   133,   134,    -1,    -1,    -1,   133,   134,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,    -1,    -1,
      -1,   133,    -1,   135,   136,   137,   138,   139,   140,   141,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
      -1,    -1,    -1,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     133,   134,    -1,    -1,    -1,   133,   134,    -1,    -1,    -1,
     133,   134,    -1,    -1,    -1,   133,   134,    -1,    -1,    -1,
     133,   134,    -1,    -1,    -1,   133,   134,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   133,   143,   144,   149,   150,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,     3,     4,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    21,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,   135,   136,
     137,   138,   139,   140,   141,   149,   150,     0,   150,     3,
       4,     5,     6,     7,   133,   134,   145,   147,   149,   154,
     134,   147,   147,   145,   146,   145,   146,   146,   145,   145,
     147,   146,   146,   146,   146,   146,   146,   145,   157,   158,
     145,   145,   145,   134,   134,   133,   147,   151,   159,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     147,   151,   147,   151,   147,   133,   134,   147,   278,   150,
     145,   134,   133,   151,   151,   145,   151,   145,   145,   146,
     145,   146,   145,   151,   145,   146,   145,   151,   151,   151,
     147,   146,   145,   134,   147,   147,   151,   145,   134,   147,
     147,   145,   146,   146,   145,   146,   145,   145,   146,   145,
     145,   145,   134,   145,   151,     3,   134,   151,   151,   134,
     151,   151,   134,   151,   134,   151,   151,   134,   151,   147,
     145,   145,   146,   145,   146,   146,     3,   155,   146,   148,
     145,   145,   151,   145,   145,   147,   146,   147,   146,   146,
     146,   146,   134,   134,   149,   134,   145,   134,   134,   145,
     134,   134,   134,   134,   134,   147,   134,   134,   134,   134,
     134,   134,   134,   133,   134,   145,   152,   134,   134,   152,
     153,   150,   150,    25,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   151,   134,   151,   147,   151,   134,
     151,   147,   134,   151,   147,   134,   134,   278,   134,   147,
     134,   150,    25,   134,   134,   134,   151,   145,   133,   134,
     275,   134,   150,   133,   134,   280,   133,   134,   280,   134,
     151,   145,   134,   151,   134,   151,   151,   134,   145,   134,
     134,   134,   134,   151,   134,   134,   134,   151,   147,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   133,   134,   288,   134,     3,   134,   144,
     156,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   145,   134,   145,     3,   134,
     134,   145,   134,   134,   151,   145,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   150,   152,   134,   152,
     134,   134,   145,   134,   147,   134,   150,   147,   147,   134,
     134,   145,   145,   147,   145,   134,   134,   134,   145,   146,
     145,   146,   134,   147,   134,   145,   145,   134,   134,   134,
     134,   145,   147,   134,   146,   134,   145,   146,   145,   145,
     146,   145,   134,   147,   134,   145,   134,   134,   134,   151,
     134,   134,   151,   134,   134,   151,   134,   134,   134,   145,
     134,   134,   151,   134,   134,   134,   134,   134,   134,   151,
     134,   134,   134,   134,   151,   134,   134,   134,   151,   134,
     134,     3,   134,   144,   134,   145,   145,   134,   134,   151,
     134,   154,   133,   159,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   133,   134,   134,   134,   134,   134,   134,
     134,   159,   134
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   142,   143,   144,   145,   145,   146,   147,   147,   148,
     148,   149,   149,   150,   150,   150,   151,   151,   151,   152,
     152,   152,   153,   153,   154,   154,   154,   154,   154,   155,
     155,   156,   156,   157,   158,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   182,   182,   183,
     184,   185,   186,   187,   188,   188,   188,   188,   189,   189,
     189,   189,   190,   190,   190,   190,   191,   192,   192,   192,
     192,   192,   193,   194,   195,   196,   197,   198,   198,   198,
     198,   199,   199,   200,   201,   202,   202,   202,   202,   203,
     203,   203,   203,   204,   204,   204,   204,   205,   205,   205,
     205,   206,   207,   208,   209,   209,   210,   211,   211,   212,
     212,   212,   212,   213,   214,   214,   215,   216,   216,   217,
     218,   218,   219,   220,   220,   221,   222,   223,   224,   224,
     224,   225,   226,   226,   226,   226,   227,   227,   228,   228,
     229,   230,   230,   231,   232,   232,   233,   233,   234,   235,
     235,   236,   237,   238,   238,   239,   240,   241,   242,   242,
     243,   244,   245,   246,   247,   247,   247,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   284,   285,   286,
     287,   288,   289,   290
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     1,     3,
       1,     1,     3,     2,     1,     3,     2,     1,     3,     3,
       4,     1,     1,     2,     1,     1,     1,     1,     1,     3,
       2,     2,     1,     2,     3,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     5,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       5,     5,     3,     3,     5,     5,     6,     4,     5,     5,
       6,     4,     5,     5,     6,     4,     4,     5,     5,     4,
       4,     3,     4,     3,     5,     4,     4,     5,     5,     6,
       4,     4,     5,     4,     5,     5,     4,     5,     4,     5,
       5,     6,     4,     5,     4,     5,     4,     5,     5,     6,
       4,     4,     4,     4,     5,     4,     4,     4,     3,     5,
       5,     6,     4,     4,     4,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     4,
       5,     4,     6,     5,     5,     4,     4,     3,     3,     4,
       4,     3,     4,     4,     3,     4,     3,     4,     4,     3,
       4,     4,     4,     4,     3,     4,     4,     4,     4,     5,
       4,     4,     4,     4,     4,     5,     5,     6,     4,     4,
       3,     4,     3,     4,     4,     4,     3,     4,     3,     4,
       4,     4,     3,     3,     3,     4,     4,     4,     4,     4,
       3,     3,     4,     4,     3,     3,     3,     3,     4,     4,
       3,     4,     3,     4,     4,     4,     4,     4,     4,     3,
       4,     3,     4,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, yyscan_t scanner)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , scanner);
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* SYM  */
#line 77 "../src/parser.y" /* yacc.c:1257  */
      { free(((*yyvaluep).s)); }
#line 1997 "parser.c" /* yacc.c:1257  */
        break;

    case 4: /* STR  */
#line 77 "../src/parser.y" /* yacc.c:1257  */
      { free(((*yyvaluep).s)); }
#line 2003 "parser.c" /* yacc.c:1257  */
        break;

    case 143: /* start  */
#line 75 "../src/parser.y" /* yacc.c:1257  */
      { run(((*yyvaluep).e));  }
#line 2009 "parser.c" /* yacc.c:1257  */
        break;

    case 144: /* s  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2015 "parser.c" /* yacc.c:1257  */
        break;

    case 145: /* p  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2021 "parser.c" /* yacc.c:1257  */
        break;

    case 146: /* pp  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2027 "parser.c" /* yacc.c:1257  */
        break;

    case 147: /* ps  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2033 "parser.c" /* yacc.c:1257  */
        break;

    case 148: /* pps  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2039 "parser.c" /* yacc.c:1257  */
        break;

    case 149: /* vp  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2045 "parser.c" /* yacc.c:1257  */
        break;

    case 150: /* vps  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2051 "parser.c" /* yacc.c:1257  */
        break;

    case 151: /* opts  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2057 "parser.c" /* yacc.c:1257  */
        break;

    case 152: /* xpb  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2063 "parser.c" /* yacc.c:1257  */
        break;

    case 153: /* xpbs  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2069 "parser.c" /* yacc.c:1257  */
        break;

    case 154: /* np  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2075 "parser.c" /* yacc.c:1257  */
        break;

    case 155: /* sps  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2081 "parser.c" /* yacc.c:1257  */
        break;

    case 156: /* par  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2087 "parser.c" /* yacc.c:1257  */
        break;

    case 157: /* cv  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2093 "parser.c" /* yacc.c:1257  */
        break;

    case 158: /* cvv  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2099 "parser.c" /* yacc.c:1257  */
        break;

    case 159: /* opt  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2105 "parser.c" /* yacc.c:1257  */
        break;

    case 160: /* ivp  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2111 "parser.c" /* yacc.c:1257  */
        break;

    case 161: /* add  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2117 "parser.c" /* yacc.c:1257  */
        break;

    case 162: /* div  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2123 "parser.c" /* yacc.c:1257  */
        break;

    case 163: /* mul  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2129 "parser.c" /* yacc.c:1257  */
        break;

    case 164: /* sub  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2135 "parser.c" /* yacc.c:1257  */
        break;

    case 165: /* and  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2141 "parser.c" /* yacc.c:1257  */
        break;

    case 166: /* bitand  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2147 "parser.c" /* yacc.c:1257  */
        break;

    case 167: /* bitnot  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2153 "parser.c" /* yacc.c:1257  */
        break;

    case 168: /* bitor  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2159 "parser.c" /* yacc.c:1257  */
        break;

    case 169: /* bitxor  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2165 "parser.c" /* yacc.c:1257  */
        break;

    case 170: /* not  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2171 "parser.c" /* yacc.c:1257  */
        break;

    case 171: /* in  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2177 "parser.c" /* yacc.c:1257  */
        break;

    case 172: /* or  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2183 "parser.c" /* yacc.c:1257  */
        break;

    case 173: /* shiftleft  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2189 "parser.c" /* yacc.c:1257  */
        break;

    case 174: /* shiftright  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2195 "parser.c" /* yacc.c:1257  */
        break;

    case 175: /* xor  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2201 "parser.c" /* yacc.c:1257  */
        break;

    case 176: /* eq  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2207 "parser.c" /* yacc.c:1257  */
        break;

    case 177: /* gt  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2213 "parser.c" /* yacc.c:1257  */
        break;

    case 178: /* gte  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2219 "parser.c" /* yacc.c:1257  */
        break;

    case 179: /* lt  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2225 "parser.c" /* yacc.c:1257  */
        break;

    case 180: /* lte  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2231 "parser.c" /* yacc.c:1257  */
        break;

    case 181: /* neq  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2237 "parser.c" /* yacc.c:1257  */
        break;

    case 182: /* if  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2243 "parser.c" /* yacc.c:1257  */
        break;

    case 183: /* select  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2249 "parser.c" /* yacc.c:1257  */
        break;

    case 184: /* until  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2255 "parser.c" /* yacc.c:1257  */
        break;

    case 185: /* while  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2261 "parser.c" /* yacc.c:1257  */
        break;

    case 186: /* trace  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2267 "parser.c" /* yacc.c:1257  */
        break;

    case 187: /* retrace  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2273 "parser.c" /* yacc.c:1257  */
        break;

    case 188: /* execute  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2279 "parser.c" /* yacc.c:1257  */
        break;

    case 189: /* rexx  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2285 "parser.c" /* yacc.c:1257  */
        break;

    case 190: /* run  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2291 "parser.c" /* yacc.c:1257  */
        break;

    case 191: /* abort  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2297 "parser.c" /* yacc.c:1257  */
        break;

    case 192: /* exit  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2303 "parser.c" /* yacc.c:1257  */
        break;

    case 193: /* onerror  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2309 "parser.c" /* yacc.c:1257  */
        break;

    case 194: /* reboot  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2315 "parser.c" /* yacc.c:1257  */
        break;

    case 195: /* trap  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2321 "parser.c" /* yacc.c:1257  */
        break;

    case 196: /* copyfiles  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2327 "parser.c" /* yacc.c:1257  */
        break;

    case 197: /* copylib  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2333 "parser.c" /* yacc.c:1257  */
        break;

    case 198: /* delete  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2339 "parser.c" /* yacc.c:1257  */
        break;

    case 199: /* exists  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2345 "parser.c" /* yacc.c:1257  */
        break;

    case 200: /* fileonly  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2351 "parser.c" /* yacc.c:1257  */
        break;

    case 201: /* foreach  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2357 "parser.c" /* yacc.c:1257  */
        break;

    case 202: /* makeassign  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2363 "parser.c" /* yacc.c:1257  */
        break;

    case 203: /* makedir  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2369 "parser.c" /* yacc.c:1257  */
        break;

    case 204: /* protect  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2375 "parser.c" /* yacc.c:1257  */
        break;

    case 205: /* startup  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2381 "parser.c" /* yacc.c:1257  */
        break;

    case 206: /* textfile  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2387 "parser.c" /* yacc.c:1257  */
        break;

    case 207: /* tooltype  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2393 "parser.c" /* yacc.c:1257  */
        break;

    case 208: /* transcript  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2399 "parser.c" /* yacc.c:1257  */
        break;

    case 209: /* rename  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2405 "parser.c" /* yacc.c:1257  */
        break;

    case 210: /* complete  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2411 "parser.c" /* yacc.c:1257  */
        break;

    case 211: /* debug  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2417 "parser.c" /* yacc.c:1257  */
        break;

    case 212: /* message  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2423 "parser.c" /* yacc.c:1257  */
        break;

    case 213: /* user  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2429 "parser.c" /* yacc.c:1257  */
        break;

    case 214: /* welcome  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2435 "parser.c" /* yacc.c:1257  */
        break;

    case 215: /* working  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2441 "parser.c" /* yacc.c:1257  */
        break;

    case 216: /* database  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2447 "parser.c" /* yacc.c:1257  */
        break;

    case 217: /* earlier  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2453 "parser.c" /* yacc.c:1257  */
        break;

    case 218: /* getassign  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2459 "parser.c" /* yacc.c:1257  */
        break;

    case 219: /* getdevice  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2465 "parser.c" /* yacc.c:1257  */
        break;

    case 220: /* getdiskspace  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2471 "parser.c" /* yacc.c:1257  */
        break;

    case 221: /* getenv  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2477 "parser.c" /* yacc.c:1257  */
        break;

    case 222: /* getsize  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2483 "parser.c" /* yacc.c:1257  */
        break;

    case 223: /* getsum  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2489 "parser.c" /* yacc.c:1257  */
        break;

    case 224: /* getversion  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2495 "parser.c" /* yacc.c:1257  */
        break;

    case 225: /* iconinfo  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2501 "parser.c" /* yacc.c:1257  */
        break;

    case 226: /* dcl  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2507 "parser.c" /* yacc.c:1257  */
        break;

    case 227: /* cus  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2513 "parser.c" /* yacc.c:1257  */
        break;

    case 228: /* askbool  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2519 "parser.c" /* yacc.c:1257  */
        break;

    case 229: /* askchoice  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2525 "parser.c" /* yacc.c:1257  */
        break;

    case 230: /* askdir  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2531 "parser.c" /* yacc.c:1257  */
        break;

    case 231: /* askdisk  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2537 "parser.c" /* yacc.c:1257  */
        break;

    case 232: /* askfile  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2543 "parser.c" /* yacc.c:1257  */
        break;

    case 233: /* asknumber  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2549 "parser.c" /* yacc.c:1257  */
        break;

    case 234: /* askoptions  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2555 "parser.c" /* yacc.c:1257  */
        break;

    case 235: /* askstring  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2561 "parser.c" /* yacc.c:1257  */
        break;

    case 236: /* cat  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2567 "parser.c" /* yacc.c:1257  */
        break;

    case 237: /* expandpath  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2573 "parser.c" /* yacc.c:1257  */
        break;

    case 238: /* fmt  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2579 "parser.c" /* yacc.c:1257  */
        break;

    case 239: /* pathonly  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2585 "parser.c" /* yacc.c:1257  */
        break;

    case 240: /* patmatch  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2591 "parser.c" /* yacc.c:1257  */
        break;

    case 241: /* strlen  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2597 "parser.c" /* yacc.c:1257  */
        break;

    case 242: /* substr  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2603 "parser.c" /* yacc.c:1257  */
        break;

    case 243: /* tackon  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2609 "parser.c" /* yacc.c:1257  */
        break;

    case 244: /* set  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2615 "parser.c" /* yacc.c:1257  */
        break;

    case 245: /* symbolset  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2621 "parser.c" /* yacc.c:1257  */
        break;

    case 246: /* symbolval  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2627 "parser.c" /* yacc.c:1257  */
        break;

    case 247: /* openwbobject  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2633 "parser.c" /* yacc.c:1257  */
        break;

    case 248: /* showwbobject  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2639 "parser.c" /* yacc.c:1257  */
        break;

    case 249: /* closewbobject  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2645 "parser.c" /* yacc.c:1257  */
        break;

    case 250: /* all  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2651 "parser.c" /* yacc.c:1257  */
        break;

    case 251: /* append  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2657 "parser.c" /* yacc.c:1257  */
        break;

    case 252: /* assigns  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2663 "parser.c" /* yacc.c:1257  */
        break;

    case 253: /* back  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2669 "parser.c" /* yacc.c:1257  */
        break;

    case 254: /* choices  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2675 "parser.c" /* yacc.c:1257  */
        break;

    case 255: /* command  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2681 "parser.c" /* yacc.c:1257  */
        break;

    case 256: /* compression  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2687 "parser.c" /* yacc.c:1257  */
        break;

    case 257: /* confirm  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2693 "parser.c" /* yacc.c:1257  */
        break;

    case 258: /* default  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2699 "parser.c" /* yacc.c:1257  */
        break;

    case 259: /* delopts  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2705 "parser.c" /* yacc.c:1257  */
        break;

    case 260: /* dest  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2711 "parser.c" /* yacc.c:1257  */
        break;

    case 261: /* disk  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2717 "parser.c" /* yacc.c:1257  */
        break;

    case 262: /* files  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2723 "parser.c" /* yacc.c:1257  */
        break;

    case 263: /* fonts  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2729 "parser.c" /* yacc.c:1257  */
        break;

    case 264: /* getdefaulttool  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2735 "parser.c" /* yacc.c:1257  */
        break;

    case 265: /* getposition  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2741 "parser.c" /* yacc.c:1257  */
        break;

    case 266: /* getstack  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2747 "parser.c" /* yacc.c:1257  */
        break;

    case 267: /* gettooltype  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2753 "parser.c" /* yacc.c:1257  */
        break;

    case 268: /* help  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2759 "parser.c" /* yacc.c:1257  */
        break;

    case 269: /* infos  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2765 "parser.c" /* yacc.c:1257  */
        break;

    case 270: /* include  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2771 "parser.c" /* yacc.c:1257  */
        break;

    case 271: /* newname  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2777 "parser.c" /* yacc.c:1257  */
        break;

    case 272: /* newpath  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2783 "parser.c" /* yacc.c:1257  */
        break;

    case 273: /* nogauge  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2789 "parser.c" /* yacc.c:1257  */
        break;

    case 274: /* noposition  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2795 "parser.c" /* yacc.c:1257  */
        break;

    case 275: /* noreq  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2801 "parser.c" /* yacc.c:1257  */
        break;

    case 276: /* pattern  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2807 "parser.c" /* yacc.c:1257  */
        break;

    case 277: /* prompt  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2813 "parser.c" /* yacc.c:1257  */
        break;

    case 278: /* quiet  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2819 "parser.c" /* yacc.c:1257  */
        break;

    case 279: /* range  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2825 "parser.c" /* yacc.c:1257  */
        break;

    case 280: /* safe  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2831 "parser.c" /* yacc.c:1257  */
        break;

    case 281: /* setdefaulttool  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2837 "parser.c" /* yacc.c:1257  */
        break;

    case 282: /* setposition  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2843 "parser.c" /* yacc.c:1257  */
        break;

    case 283: /* setstack  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2849 "parser.c" /* yacc.c:1257  */
        break;

    case 284: /* settooltype  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2855 "parser.c" /* yacc.c:1257  */
        break;

    case 285: /* source  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2861 "parser.c" /* yacc.c:1257  */
        break;

    case 286: /* swapcolors  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2867 "parser.c" /* yacc.c:1257  */
        break;

    case 287: /* optional  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2873 "parser.c" /* yacc.c:1257  */
        break;

    case 288: /* resident  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2879 "parser.c" /* yacc.c:1257  */
        break;

    case 289: /* override  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2885 "parser.c" /* yacc.c:1257  */
        break;

    case 290: /* dynopt  */
#line 80 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2891 "parser.c" /* yacc.c:1257  */
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

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 96 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = init((yyvsp[0].e)); }
#line 3159 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 102 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3165 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 103 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3171 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 104 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3177 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 105 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push((yyvsp[-2].e), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3183 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 108 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3189 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 109 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3195 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 110 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3201 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 111 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3207 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 112 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3213 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 113 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3219 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 114 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3225 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 115 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3231 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 116 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push((yyvsp[-2].e), (yyvsp[-1].e)); }
#line 3237 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 117 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3243 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 118 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3249 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 119 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3255 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3261 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 121 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3267 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 122 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3273 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 123 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_string((yyvsp[0].s)); }
#line 3279 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 124 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_symref((yyvsp[0].s), LINE); }
#line 3285 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 125 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push((yyvsp[-2].e), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)) ; }
#line 3291 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 126 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push(new_contxt(), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)); }
#line 3297 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 127 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push((yyvsp[-1].e), new_symbol((yyvsp[0].s))); }
#line 3303 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 128 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), new_symbol((yyvsp[0].s))); }
#line 3309 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 129 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3315 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 130 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3321 "parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 267 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("+"), LINE, m_add, (yyvsp[-1].e), NUMBER); }
#line 3327 "parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 268 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("/"), LINE, m_div, (yyvsp[-1].e), NUMBER); }
#line 3333 "parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 269 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("*"), LINE, m_mul, (yyvsp[-1].e), NUMBER); }
#line 3339 "parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 270 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("-"), LINE, m_sub, (yyvsp[-1].e), NUMBER); }
#line 3345 "parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 273 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("AND"), LINE, m_and, (yyvsp[-1].e), NUMBER); }
#line 3351 "parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 274 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("BITAND"), LINE, m_bitand, (yyvsp[-1].e), NUMBER); }
#line 3357 "parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 275 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("BITNOT"), LINE, m_bitnot, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3363 "parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 276 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("BITOR"), LINE, m_bitor, (yyvsp[-1].e), NUMBER); }
#line 3369 "parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 277 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("BITXOR"), LINE, m_bitxor, (yyvsp[-1].e), NUMBER); }
#line 3375 "parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 278 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("NOT"), LINE, m_not, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3381 "parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 279 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("IN"), LINE, m_in, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3387 "parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 280 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("OR"), LINE, m_or, (yyvsp[-1].e), NUMBER); }
#line 3393 "parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 281 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("shiftleft"), LINE, m_shiftleft, (yyvsp[-1].e), NUMBER); }
#line 3399 "parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 282 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("shiftright"), LINE, m_shiftright, (yyvsp[-1].e), NUMBER); }
#line 3405 "parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 283 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("XOR"), LINE, m_xor, (yyvsp[-1].e), NUMBER); }
#line 3411 "parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 286 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("="), LINE, m_eq, (yyvsp[-1].e), NUMBER); }
#line 3417 "parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 287 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup(">"), LINE, m_gt, (yyvsp[-1].e), NUMBER); }
#line 3423 "parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 288 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup(">="), LINE, m_gte, (yyvsp[-1].e), NUMBER); }
#line 3429 "parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 289 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("<"), LINE, m_lt, (yyvsp[-1].e), NUMBER); }
#line 3435 "parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 290 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("<="), LINE, m_lte, (yyvsp[-1].e), NUMBER); }
#line 3441 "parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 291 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("<>"), LINE, m_neq, (yyvsp[-1].e), NUMBER); }
#line 3447 "parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 294 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3453 "parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 295 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3459 "parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 296 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3465 "parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 297 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("select"), LINE, m_select, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3471 "parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 298 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("until"), LINE, m_until, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3477 "parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 299 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("while"), LINE, m_while, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3483 "parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 300 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("trace"), LINE, m_trace, NULL, NUMBER); }
#line 3489 "parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 301 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("retrace"), LINE, m_retrace, NULL, DANGLE); }
#line 3495 "parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 304 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3501 "parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 305 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3507 "parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 306 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3513 "parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 307 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, (yyvsp[-1].e), NUMBER); }
#line 3519 "parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 308 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3525 "parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 309 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3531 "parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 310 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3537 "parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 311 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, (yyvsp[-1].e), NUMBER); }
#line 3543 "parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 312 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3549 "parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 313 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3555 "parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 314 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3561 "parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 315 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, (yyvsp[-1].e), NUMBER); }
#line 3567 "parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 318 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("abort"), LINE, m_abort, (yyvsp[-1].e), NUMBER); }
#line 3573 "parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 319 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3579 "parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 320 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3585 "parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 321 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3591 "parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 322 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, (yyvsp[-1].e), NUMBER); }
#line 3597 "parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 323 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, NULL, NUMBER); }
#line 3603 "parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 324 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("onerror"), LINE, m_procedure, push(new_contxt(),
                                                        new_custom(strdup("@onerror"), LINE, NULL, (yyvsp[-1].e))), DANGLE); }
#line 3610 "parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 326 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("reboot"), LINE, m_reboot, NULL, NUMBER); }
#line 3616 "parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 327 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("trap"), LINE, m_trap, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3622 "parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 330 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("copyfiles"), LINE, m_copyfiles, (yyvsp[-1].e), NUMBER); }
#line 3628 "parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 331 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("copylib"), LINE, m_copylib, (yyvsp[-1].e), NUMBER); }
#line 3634 "parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 332 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3640 "parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 333 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3646 "parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 334 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3652 "parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 335 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3658 "parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 336 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3664 "parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 337 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3670 "parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 338 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("fileonly"), LINE, m_fileonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3676 "parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 339 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("foreach"), LINE, m_foreach, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3682 "parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 340 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3688 "parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 341 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, (yyvsp[-1].e), NUMBER); }
#line 3694 "parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 342 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3700 "parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 343 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3706 "parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 344 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3712 "parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 345 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3718 "parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 346 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3724 "parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 347 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3730 "parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 348 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3736 "parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 349 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, (yyvsp[-1].e), NUMBER); }
#line 3742 "parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 350 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3748 "parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 351 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3754 "parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 352 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3760 "parser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 353 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3766 "parser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 354 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3772 "parser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 355 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), new_symref(strdup("@app-name"), LINE)), (yyvsp[-1].e)), NUMBER); }
#line 3778 "parser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 356 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("textfile"), LINE, m_textfile, (yyvsp[-1].e), NUMBER); }
#line 3784 "parser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 357 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("tooltype"), LINE, m_tooltype, (yyvsp[-1].e), NUMBER); }
#line 3790 "parser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 358 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("transcript"), LINE, m_transcript, (yyvsp[-1].e), NUMBER); }
#line 3796 "parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 359 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3802 "parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 360 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, (yyvsp[-1].e), NUMBER); }
#line 3808 "parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 363 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("complete"), LINE, m_complete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3814 "parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 364 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, (yyvsp[-1].e), NUMBER); }
#line 3820 "parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 365 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, NULL, NUMBER); }
#line 3826 "parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 366 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, merge((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3832 "parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 367 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3838 "parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 368 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, push(merge((yyvsp[-3].e), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3844 "parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 369 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, (yyvsp[-1].e), NUMBER); }
#line 3850 "parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 370 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("user"), LINE, m_user, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3856 "parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 371 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, (yyvsp[-1].e), NUMBER); }
#line 3862 "parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 372 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, NULL, NUMBER); }
#line 3868 "parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 373 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("working"), LINE, m_working, (yyvsp[-1].e), NUMBER); }
#line 3874 "parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 376 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3880 "parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 377 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, (yyvsp[-1].e), STRING); }
#line 3886 "parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 378 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("earlier"), LINE, m_earlier, (yyvsp[-1].e), NUMBER); }
#line 3892 "parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 379 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3898 "parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 380 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, (yyvsp[-1].e), STRING); }
#line 3904 "parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 381 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getdevice"), LINE, m_getdevice, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3910 "parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 382 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3916 "parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 383 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, (yyvsp[-1].e), NUMBER); }
#line 3922 "parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 384 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getenv"), LINE, m_getenv, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3928 "parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 385 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getsize"), LINE, m_getsize, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3934 "parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 386 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getsum"), LINE, m_getsum, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3940 "parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 387 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, NULL, NUMBER); }
#line 3946 "parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 388 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3952 "parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 389 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3958 "parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 390 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("iconinfo"), LINE, m_iconinfo, (yyvsp[-1].e), NUMBER); }
#line 3964 "parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 393 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-3].s), LINE, (yyvsp[-2].e), (yyvsp[-1].e))), NUMBER); }
#line 3970 "parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 394 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, (yyvsp[-1].e), NULL)), NUMBER); }
#line 3976 "parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 395 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, NULL, (yyvsp[-1].e))), NUMBER); }
#line 3982 "parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 396 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-1].s), LINE, NULL, NULL)), NUMBER); }
#line 3988 "parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 397 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_cusref((yyvsp[-2].s), LINE, (yyvsp[-1].e)); }
#line 3994 "parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 398 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_cusref((yyvsp[-1].s), LINE, NULL); }
#line 4000 "parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 401 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, NULL, NUMBER); }
#line 4006 "parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 402 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, (yyvsp[-1].e), NUMBER); }
#line 4012 "parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 403 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askchoice"), LINE, m_askchoice, (yyvsp[-1].e), NUMBER); }
#line 4018 "parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 404 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, NULL, STRING); }
#line 4024 "parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 405 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, (yyvsp[-1].e), STRING); }
#line 4030 "parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 406 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askdisk"), LINE, m_askdisk, (yyvsp[-1].e), NUMBER); }
#line 4036 "parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 407 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, NULL, STRING); }
#line 4042 "parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 408 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, (yyvsp[-1].e), STRING); }
#line 4048 "parser.c" /* yacc.c:1646  */
    break;

  case 286:
#line 409 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, NULL, NUMBER); }
#line 4054 "parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 410 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, (yyvsp[-1].e), NUMBER); }
#line 4060 "parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 411 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askoptions"), LINE, m_askoptions, (yyvsp[-1].e), NUMBER); }
#line 4066 "parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 412 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, NULL, STRING); }
#line 4072 "parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 413 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, (yyvsp[-1].e), STRING); }
#line 4078 "parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 416 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("cat"), LINE, m_cat, (yyvsp[-1].e), STRING); }
#line 4084 "parser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 417 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("expandpath"), LINE, m_expandpath, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4090 "parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 418 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native((yyvsp[-2].s), LINE, m_fmt, (yyvsp[-1].e), STRING); }
#line 4096 "parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 419 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native((yyvsp[-1].s), LINE, m_fmt, NULL, STRING); }
#line 4102 "parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 420 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("pathonly"), LINE, m_pathonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4108 "parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 421 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("patmatch"), LINE, m_patmatch, (yyvsp[-1].e), NUMBER); }
#line 4114 "parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 422 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("strlen"), LINE, m_strlen, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4120 "parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 423 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, (yyvsp[-1].e), STRING); }
#line 4126 "parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 424 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, push((yyvsp[-2].e), (yyvsp[-1].e)), STRING); }
#line 4132 "parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 425 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("tackon"), LINE, m_tackon, (yyvsp[-1].e), STRING); }
#line 4138 "parser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 428 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("set"), LINE, m_set, (yyvsp[-1].e), DANGLE); }
#line 4144 "parser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 429 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("symbolset"), LINE, m_symbolset, (yyvsp[-1].e), DANGLE); }
#line 4150 "parser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 430 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("symbolval"), LINE, m_symbolval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4156 "parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 433 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4162 "parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 434 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4168 "parser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 435 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4174 "parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 436 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4180 "parser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 437 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("showwbobject"), LINE, m_showwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4186 "parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 438 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("closewbobject"), LINE, m_closewbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4192 "parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 441 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("all"), OPT_ALL, NULL); }
#line 4198 "parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 442 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("append"), OPT_APPEND, (yyvsp[-1].e)); }
#line 4204 "parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 443 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); }
#line 4210 "parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 444 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("back"), OPT_BACK, (yyvsp[-1].e)); }
#line 4216 "parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 445 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("choices"), OPT_CHOICES, (yyvsp[-1].e)); }
#line 4222 "parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 446 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("command"), OPT_COMMAND, (yyvsp[-1].e)); }
#line 4228 "parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 447 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("compression"), OPT_COMPRESSION, NULL); }
#line 4234 "parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 448 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, push(new_contxt(), (yyvsp[-1].e))); }
#line 4240 "parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 449 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, NULL); }
#line 4246 "parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 450 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), (yyvsp[-1].e))); }
#line 4252 "parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 451 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, (yyvsp[-1].e)); }
#line 4258 "parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 452 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), (yyvsp[-1].e))); }
#line 4264 "parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 453 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("disk"), OPT_DISK, NULL); }
#line 4270 "parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 454 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("files"), OPT_FILES, NULL); }
#line 4276 "parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 455 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("fonts"), OPT_FONTS, NULL); }
#line 4282 "parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 456 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4288 "parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 457 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("getposition"), OPT_GETPOSITION, (yyvsp[-1].e)); }
#line 4294 "parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 458 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4300 "parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 459 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, (yyvsp[-1].e)); }
#line 4306 "parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 460 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, (yyvsp[-1].e)); }
#line 4312 "parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 461 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4318 "parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 462 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("infos"), OPT_INFOS, NULL); }
#line 4324 "parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 463 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4330 "parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 464 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), (yyvsp[-1].e))); }
#line 4336 "parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 465 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("newpath"), OPT_NEWPATH, NULL); }
#line 4342 "parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 466 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); }
#line 4348 "parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 467 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); }
#line 4354 "parser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 468 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("noreq"), OPT_NOREQ, NULL); }
#line 4360 "parser.c" /* yacc.c:1646  */
    break;

  case 338:
#line 469 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), (yyvsp[-1].e))); }
#line 4366 "parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 470 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("prompt"), OPT_PROMPT, (yyvsp[-1].e)); }
#line 4372 "parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 471 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("quiet"), OPT_QUIET, NULL); }
#line 4378 "parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 472 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("range"), OPT_RANGE, (yyvsp[-1].e)); }
#line 4384 "parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 473 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("safe"), OPT_SAFE, NULL); }
#line 4390 "parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 474 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4396 "parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 475 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("setposition"), OPT_SETPOSITION, (yyvsp[-1].e)); }
#line 4402 "parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 476 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4408 "parser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 477 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, (yyvsp[-1].e)); }
#line 4414 "parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 478 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4420 "parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 479 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4426 "parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 480 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); }
#line 4432 "parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 481 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, (yyvsp[-1].e)); }
#line 4438 "parser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 482 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("resident"), OPT_RESIDENT, NULL); }
#line 4444 "parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 483 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4450 "parser.c" /* yacc.c:1646  */
    break;

  case 353:
#line 484 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(push(new_contxt(), (yyvsp[-3].e)), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4456 "parser.c" /* yacc.c:1646  */
    break;


#line 4460 "parser.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 486 "../src/parser.y" /* yacc.c:1906  */


