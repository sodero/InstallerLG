/* A Bison parser, made by GNU Bison 3.1.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.1"

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

/* Copy the second part of user declarations.  */

#line 392 "parser.c" /* yacc.c:358  */

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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   2010

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  141
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  148
/* YYNRULES -- Number of rules.  */
#define YYNRULES  349
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  675

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   386

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     132,   133,   136,   134,     2,   137,     2,   135,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     140,   138,   139,     2,     2,     2,     2,     2,     2,     2,
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
     125,   126,   127,   128,   129,   130,   131
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
     168,   169,   170,   171,   172,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   266,   267,   268,   269,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   285,
     286,   287,   288,   289,   290,   293,   294,   295,   296,   297,
     298,   299,   300,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   317,   318,   319,   320,   321,
     322,   323,   325,   326,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   390,
     391,   392,   393,   394,   395,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   425,   426,
     427,   430,   431,   432,   433,   434,   435,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480
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
  "SHOWWBOBJECT", "CLOSEWBOBJECT", "ALL", "APPEND", "ASSIGNS", "CHOICES",
  "COMMAND", "COMPRESSION", "CONFIRM", "DEFAULT", "DELOPTS", "DEST",
  "DISK", "FILES", "FONTS", "GETDEFAULTTOOL", "GETPOSITION", "GETSTACK",
  "GETTOOLTYPE", "HELP", "INFOS", "INCLUDE", "NEWNAME", "NEWPATH",
  "NOGAUGE", "NOPOSITION", "NOREQ", "PATTERN", "PROMPT", "QUIET", "RANGE",
  "SAFE", "SETDEFAULTTOOL", "SETPOSITION", "SETSTACK", "SETTOOLTYPE",
  "SOURCE", "SWAPCOLORS", "OPTIONAL", "RESIDENT", "OVERRIDE", "'('", "')'",
  "'+'", "'/'", "'*'", "'-'", "'='", "'>'", "'<'", "$accept", "start", "s",
  "p", "pp", "ps", "pps", "vp", "vps", "opts", "xpb", "xpbs", "np", "sps",
  "par", "cv", "cvv", "opt", "ivp", "add", "div", "mul", "sub", "and",
  "bitand", "bitnot", "bitor", "bitxor", "not", "in", "or", "shiftleft",
  "shiftright", "xor", "eq", "gt", "gte", "lt", "lte", "neq", "if",
  "select", "until", "while", "trace", "retrace", "execute", "rexx", "run",
  "abort", "exit", "onerror", "reboot", "trap", "copyfiles", "copylib",
  "delete", "exists", "fileonly", "foreach", "makeassign", "makedir",
  "protect", "startup", "textfile", "tooltype", "transcript", "rename",
  "complete", "debug", "message", "user", "welcome", "working", "database",
  "earlier", "getassign", "getdevice", "getdiskspace", "getenv", "getsize",
  "getsum", "getversion", "iconinfo", "dcl", "cus", "askbool", "askchoice",
  "askdir", "askdisk", "askfile", "asknumber", "askoptions", "askstring",
  "cat", "expandpath", "fmt", "pathonly", "patmatch", "strlen", "substr",
  "tackon", "set", "symbolset", "symbolval", "openwbobject",
  "showwbobject", "closewbobject", "all", "append", "assigns", "choices",
  "command", "compression", "confirm", "default", "delopts", "dest",
  "disk", "files", "fonts", "getdefaulttool", "getposition", "getstack",
  "gettooltype", "help", "infos", "include", "newname", "newpath",
  "nogauge", "noposition", "noreq", "pattern", "prompt", "quiet", "range",
  "safe", "setdefaulttool", "setposition", "setstack", "settooltype",
  "source", "swapcolors", "optional", "resident", "override", "dynopt", YY_NULLPTR
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
     385,   386,    40,    41,    43,    47,    42,    45,    61,    62,
      60
};
# endif

#define YYPACT_NINF -539

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-539)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -117,  1576,    24,  -539,  -539,  -117,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,    25,    82,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,  -114,  -112,   201,   201,
     201,    35,   133,  -117,    35,   -98,   -89,   -89,   201,    35,
      35,    35,    35,   201,    35,   201,   -89,   -89,    35,    35,
      35,   172,    35,    35,   194,    35,    35,    35,    35,    35,
      35,    35,    35,    35,   223,   -89,    43,  -119,   -89,   -99,
     -89,   -77,   -58,   -89,   -54,    35,    35,    35,    35,    35,
      35,    35,    59,    35,    35,   201,    35,    35,    35,    35,
      35,    35,    35,    35,    35,   -67,   -42,  -539,  -117,  -539,
    -539,  -539,  -539,  -539,  1714,  -539,  -539,   228,  -539,  -539,
    -539,   239,   244,    35,   -57,   -51,   -41,   -33,   -26,    35,
     264,   -22,   -15,   -11,    -9,    -2,     1,   288,    14,    40,
     252,  -117,  -117,  -539,  -539,   886,   293,   201,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,   307,
     201,   312,   201,   458,  1162,  -539,   487,   492,   -35,  -117,
    -539,  1770,   -30,   -27,   -19,   201,   -12,    47,  -117,   511,
      -6,    -4,   201,   527,    21,   -89,   532,    23,    30,   541,
      32,    49,  -539,   546,   551,    54,  -539,   556,   563,   580,
      56,    77,   623,   105,   121,   628,   131,   144,   147,   156,
    -539,    37,    60,    17,  -539,    63,    70,  -539,    80,    85,
    -539,    87,  -539,   104,   108,  -539,   120,   663,   170,   189,
     205,   214,   773,   226,    35,     9,  -539,  1261,   231,   128,
     201,   233,   236,  1266,   242,  1271,   247,   253,   255,   262,
    -539,  -539,   -67,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  1280,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  1576,  -539,  -539,   252,  -539,  -539,  -539,  1285,   130,
     140,    35,   275,    35,   286,    35,    35,   297,  1402,    35,
      35,    35,   308,   314,   325,    35,    35,    35,    35,  1420,
     333,    35,    35,   334,   335,   342,   348,    35,    35,   355,
      35,   356,    35,    35,    35,    35,    35,   368,    35,   369,
      35,   143,  -539,   150,  1537,   -89,  -539,   152,  1542,  -539,
     154,  1551,  -539,  -539,   370,  -539,  1556,  -539,   169,    35,
    -539,  -539,  -539,   174,   176,   391,  -539,   377,  -539,   188,
    1300,  -539,   378,   390,  -539,   386,  -539,   197,   204,  -539,
     208,  -539,   210,   213,  -539,   217,  -539,  -539,  -539,  -539,
     219,  -539,  -539,  1438,  -539,   388,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
     392,  -539,   393,  -539,  -539,  -539,   394,    19,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,   395,  -539,  -539,    35,  -539,  -539,    35,  -539,
    -539,   221,   230,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  1561,  -539,  -539,  -539,  -539,  -539,  1675,
    -539,  1692,  -539,  1697,  1806,  -539,  -539,   407,   408,  1811,
     409,  -539,  -539,  -539,   431,   432,   438,   440,  -539,  1816,
    -539,   442,   444,  -539,  -539,  -539,  -539,   445,  1828,  -539,
     447,  -539,   448,   449,   456,  1833,   460,   461,  -539,  1838,
    -539,   464,  -539,  -539,  -539,   241,  -539,  -539,   246,  -539,
    -539,   259,  -539,  -539,  -539,   -37,  -539,  -539,   261,  -539,
    -539,  -539,  -539,  -539,  -539,   266,  -539,  -539,  -539,  -539,
     268,  -539,  -539,  -539,  -539,  -539,  -539,   465,  -539,  -539,
    -539,  -539,  -539,   291,  -539,   467,  1024,   -37,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  1879,  -539,  -539,  -539,
    -539,  -539,  -539,   468,  -539
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,    14,     3,    11,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     109,   108,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   141,   140,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     1,    13,    28,
      27,    24,    25,    26,     0,   274,     8,     0,     4,     5,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   192,     0,     0,     0,    17,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    54,    53,    55,
      56,    57,    58,    59,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    60,    74,    61,    73,     0,
       0,     0,     0,     0,     0,   210,     0,     0,     0,     0,
     212,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,     0,     0,     0,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265,     0,     0,     0,   275,     0,     0,   278,     0,     0,
     281,     0,   283,     0,     0,   286,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    15,     0,   273,     7,   290,   168,     6,   169,   170,
     171,   172,   173,     0,   175,   176,   177,   178,   181,   183,
     184,     0,   187,    21,    33,   186,   185,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   196,     0,     0,    16,   200,     0,     0,   204,
       0,     0,   205,   209,     0,   208,     0,   211,     0,     0,
     214,   215,   219,     0,     0,     0,   220,     0,   222,     0,
       0,   227,     0,     0,   225,     0,   231,     0,     0,   235,
       0,   233,     0,     0,   239,     0,   240,   241,   242,   244,
       0,   245,   246,     0,   249,     0,   250,   251,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
       0,   266,     0,   268,    32,   272,     0,     0,   276,   277,
     279,   280,   282,   284,   285,   287,   288,   289,   292,   293,
     294,   295,     0,   297,    30,     0,   298,   299,     0,   300,
     301,     0,     0,   305,   306,   164,   165,   166,   167,   179,
     180,   182,   174,     0,    34,   188,    23,   189,   190,     0,
     307,     0,   309,     0,     0,   312,   314,     0,     0,     0,
       0,   318,   319,   320,     0,     0,     0,     0,   326,     0,
     327,     0,     0,   330,   331,   332,   333,     0,     0,   336,
       0,   338,     0,     0,     0,     0,     0,     0,   345,     0,
     347,     0,    18,   193,   194,     0,   197,   198,     0,   201,
     202,     0,   206,   207,   213,     0,   216,   217,     0,   221,
     223,   226,   224,   228,   229,     0,   234,   232,   236,   237,
       0,   243,   248,   267,   271,    31,   270,     0,   296,    29,
       9,   302,   303,     0,    19,     0,     0,     0,   308,   310,
     311,   313,   315,   316,   317,   321,   322,   323,   324,   325,
     328,   329,   334,   335,   337,   339,   340,   341,   343,   342,
     344,   346,   348,   195,   199,   203,     0,   218,   230,   238,
     269,   304,    20,     0,   349
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -539,  -539,  -316,   303,   -38,   -61,  -539,     0,     2,  -110,
    -216,  -539,   -18,  -539,  -539,  -539,  -539,  -538,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,   220,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,  -539,
    -539,  -539,   317,  -539,  -539,  -116,  -539,   139,  -539,  -539,
    -539,  -539,  -539,  -539,  -539,   283,  -539,  -539
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   196,   204,   197,   347,   198,   188,   435,
     384,   388,   199,   345,   507,   218,   219,   228,     6,     7,
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
     261,   262,   263,   264,   265,   266,   267,   268
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
       4,   185,     5,   186,   387,     4,   277,   506,   227,   270,
     272,   637,   525,   281,   324,     1,   282,   283,   285,   223,
     504,   224,   625,   292,   187,   296,   297,   298,   189,   190,
     191,   192,   193,   281,   327,   280,   201,   202,   189,   190,
     191,   192,   193,   281,   210,   322,   323,   325,   326,   328,
     329,   331,   333,   334,   336,   281,   330,   226,   269,   271,
     273,   276,   344,   206,   207,   350,   360,   637,   211,   212,
     213,   214,   215,   216,   281,   332,   368,   299,   281,   335,
     303,   304,   369,   307,   308,   189,   190,   191,   192,   193,
       1,   361,   370,   288,   290,   666,   294,     1,   447,   673,
     371,   300,   281,   450,   337,   281,   451,   372,   310,   311,
     313,   375,   316,   281,   452,   431,   433,   353,   376,   355,
     455,   456,   377,     4,   378,   278,   463,   464,   281,   466,
     340,   379,   342,   343,   380,   346,   189,   190,   191,   192,
     193,   354,   526,   356,   357,   358,   359,   385,   373,     1,
     505,     1,   626,   281,   471,   281,   476,   194,   195,   437,
     444,   440,   281,   477,   281,   479,   434,   194,   544,   500,
     501,   431,   546,   386,   453,   189,   190,   191,   192,   193,
     458,   467,   481,   470,   472,   473,     4,   486,     4,   490,
     480,   627,   281,   503,   362,   281,   508,   189,   190,   191,
     192,   193,   281,   509,   189,   190,   191,   192,   193,   438,
     491,   441,   281,   510,   194,   200,   446,   281,   511,   281,
     512,     4,     4,   389,   390,   362,   189,   190,   191,   192,
     193,   189,   190,   191,   192,   193,   281,   513,   493,   531,
     281,   514,   189,   190,   191,   192,   193,   189,   190,   191,
     192,   193,   281,   515,   494,   189,   190,   191,   192,   193,
     281,   530,     1,   547,   496,   274,   275,   189,   190,   191,
     192,   193,     1,   548,   362,   281,   592,   497,     4,     4,
     498,   448,   281,   593,   281,   596,   281,   599,     4,   499,
     459,   189,   190,   191,   192,   193,   189,   190,   191,   192,
     193,     1,   604,   517,   194,   302,   281,   606,   281,   607,
     189,   190,   191,   192,   193,   189,   190,   191,   192,   193,
       1,   610,   518,     4,   595,     5,   194,   306,   598,   281,
     613,   601,   551,   225,   553,   554,   281,   614,   519,   559,
     281,   616,   281,   617,   608,   281,   618,   520,   569,   281,
     619,   281,   621,   281,   631,   194,   320,   578,   615,   523,
     194,   363,   281,   632,   529,   620,   533,   589,   565,   534,
     567,   194,   365,   281,   663,   536,   194,   366,   281,   664,
     538,   185,   580,   543,   381,   583,   539,   586,   540,     4,
       4,   281,   665,   281,   667,   541,   194,   374,   281,   668,
     281,   669,   203,   205,   203,   203,   208,   209,   550,   203,
     203,   203,   203,   203,   203,   217,   220,   221,   222,   552,
     381,   382,   633,   281,   671,   225,   432,   279,   462,   465,
     555,   284,   286,   287,   203,   289,   291,   293,   295,   225,
     436,   561,   203,   301,   225,   439,   305,   562,     4,   309,
     203,   312,   314,   315,   317,   318,   319,   321,   563,     4,
     362,   189,   190,   191,   192,   193,   570,   573,   574,   338,
     339,   203,   341,   203,   203,   575,   203,   348,   349,   351,
     352,   576,   203,   362,   203,   203,   203,   203,   579,   581,
     189,   190,   191,   192,   193,   189,   190,   191,   192,   193,
     364,   588,   590,   602,   364,   364,   367,     4,   416,     5,
     609,   611,   421,   364,   189,   190,   191,   192,   193,   612,
     383,   622,   429,   383,   485,   635,   623,   624,   628,   364,
     189,   190,   191,   192,   193,   189,   190,   191,   192,   193,
     641,   642,   644,     4,   189,   190,   191,   192,   193,   189,
     190,   191,   192,   193,   189,   190,   191,   192,   193,   189,
     190,   191,   192,   193,   645,   646,   189,   190,   191,   192,
     193,   647,   364,   648,   364,   650,   364,   651,   652,   364,
     654,   655,   656,   189,   190,   191,   192,   193,   454,   657,
     194,   442,   367,   659,   660,   468,   367,   662,   670,   475,
     672,   674,   364,   457,   502,     0,   364,   364,     0,     0,
     364,   364,   367,     0,     0,   367,     0,     0,   367,   274,
     443,     0,     0,     0,   194,   445,   189,   190,   191,   192,
     193,   189,   190,   191,   192,   193,   185,     0,   543,     0,
     364,     0,     0,   460,   461,   522,     0,   524,     0,     0,
     528,     0,     0,   532,     0,     0,   364,     0,   364,   225,
     469,     0,     0,     0,   225,   474,   189,   190,   191,   192,
     193,     0,     0,   194,   478,     0,   364,     0,   194,   482,
       0,     0,     0,   483,   484,     0,     0,   383,   194,   487,
       0,   383,     0,     0,   549,   194,   488,     0,     0,     0,
       0,   557,   558,     0,   560,     0,     0,     0,   564,   203,
     566,   203,   194,   489,   571,   572,     0,     0,     0,     0,
     577,     0,     0,   203,     0,   582,   203,   584,   585,   587,
       0,     0,     0,   591,     0,     0,     0,   364,     0,     0,
       0,   364,     0,     0,   364,     0,     0,     0,     0,   364,
       0,     0,   605,     0,     0,   194,   492,     0,     0,     0,
     194,   495,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   189,   190,   191,   192,
     193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   194,   516,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   629,     0,
       0,   630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   383,     0,   364,     0,   364,   364,     0,     0,
       0,     0,   364,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   364,     0,     0,     0,     0,     0,     0,     0,
       0,   364,     0,     0,     0,     0,     0,     0,   367,    96,
      97,     0,   364,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   194,   521,   109,     0,   110,
     111,   391,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,     0,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   225,     0,
     178,   179,   180,   181,   182,   183,   184,    96,    97,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,   109,     0,   110,   111,   391,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,     1,     0,   178,   179,
     180,   181,   182,   183,   184,    96,    97,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,   109,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,     0,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   189,   190,   191,   192,   193,   189,
     190,   191,   192,   193,   189,   190,   191,   192,   193,     0,
       0,     0,   419,   189,   190,   191,   192,   193,   189,   190,
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
     175,   176,   177,   194,   527,     0,     0,     0,   194,   535,
       0,     0,     0,   194,   537,   189,   190,   191,   192,   193,
       0,     0,   194,   542,     0,     0,     0,   381,   545,     0,
       0,     0,   421,   189,   190,   191,   192,   193,     0,     0,
       0,     0,   194,     0,   178,   179,   180,   181,   182,   183,
     184,    96,    97,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,   109,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,     0,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,     0,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   392,     0,     0,   194,   556,     0,     0,     0,     0,
     189,   190,   191,   192,   193,   189,   190,   191,   192,   193,
       0,     0,   194,   568,   189,   190,   191,   192,   193,   189,
     190,   191,   192,   193,   189,   190,   191,   192,   193,     0,
     194,     0,   178,   179,   180,   181,   182,   183,   184,    96,
      97,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,   109,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,     0,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   225,
     594,     0,     0,     0,   225,   597,     0,     0,   189,   190,
     191,   192,   193,   225,   600,     0,     0,     0,   194,   603,
       0,     0,     0,     1,   634,   189,   190,   191,   192,   193,
     189,   190,   191,   192,   193,     0,     0,     0,     1,     0,
     178,   179,   180,   181,   182,   183,   184,    96,    97,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,   109,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   449,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   636,   382,   189,
     190,   191,   192,   193,   189,   190,   191,   192,   193,   189,
     190,   191,   192,   193,   194,   638,     0,     0,     0,   194,
     639,   189,   190,   191,   192,   193,   189,   190,   191,   192,
     193,   189,   190,   191,   192,   193,   194,     0,   178,   179,
     180,   181,   182,   183,   184,     0,     0,     0,     0,     0,
       0,     0,     0,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   281,     0,   449,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   194,   640,
       0,     0,     0,   194,   643,     0,     0,     0,   194,   649,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,   653,     0,     0,     0,   194,   658,     0,     0,     0,
     194,   661,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430
};

static const yytype_int16 yycheck[] =
{
       0,     1,     0,     1,   220,     5,   122,   323,   118,   119,
     120,   549,     3,   132,   133,   132,   126,   127,   128,   133,
       3,   133,     3,   133,     0,   135,   136,   137,     3,     4,
       5,     6,     7,   132,   133,   133,    97,    98,     3,     4,
       5,     6,     7,   132,   105,   155,     3,   157,   158,   159,
     160,   161,   162,   163,   164,   132,   133,   118,   119,   120,
     121,   122,     3,   101,   102,   175,   133,   605,   106,   107,
     108,   109,   110,   111,   132,   133,   133,   138,   132,   133,
     141,   142,   133,   144,   145,     3,     4,     5,     6,     7,
     132,   133,   133,   131,   132,   132,   134,   132,   133,   637,
     133,   139,   132,   133,   165,   132,   133,   133,   146,   147,
     148,   133,   150,   132,   133,   225,   226,   178,   133,   180,
     132,   133,   133,   123,   133,   123,   132,   133,   132,   133,
     168,   133,   170,   171,   133,   173,     3,     4,     5,     6,
       7,   179,   133,   181,   182,   183,   184,   133,   209,   132,
     133,   132,   133,   132,   133,   132,   133,   132,   133,   269,
     276,   271,   132,   133,   132,   133,   227,   132,   384,   132,
     133,   281,   388,   133,   284,     3,     4,     5,     6,     7,
     133,   291,   133,   293,   294,   295,   186,   133,   188,   133,
     300,   507,   132,   133,   194,   132,   133,     3,     4,     5,
       6,     7,   132,   133,     3,     4,     5,     6,     7,   270,
     133,   272,   132,   133,   132,   133,   277,   132,   133,   132,
     133,   221,   222,   221,   222,   225,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,   132,   133,   133,   349,
     132,   133,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,   132,   133,   133,     3,     4,     5,     6,     7,
     132,   133,   132,   133,   133,   132,   133,     3,     4,     5,
       6,     7,   132,   133,   274,   132,   133,   133,   278,   279,
     133,   279,   132,   133,   132,   133,   132,   133,   288,   133,
     288,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,   132,   133,   133,   132,   133,   132,   133,   132,   133,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
     132,   133,   133,   323,   434,   323,   132,   133,   438,   132,
     133,   441,   393,   132,   395,   396,   132,   133,   133,   400,
     132,   133,   132,   133,   454,   132,   133,   133,   409,   132,
     133,   132,   133,   132,   133,   132,   133,   418,   468,   133,
     132,   133,   132,   133,   133,   475,   133,   428,   406,   133,
     408,   132,   133,   132,   133,   133,   132,   133,   132,   133,
     133,   381,   420,   381,   132,   423,   133,   425,   133,   389,
     390,   132,   133,   132,   133,   133,   132,   133,   132,   133,
     132,   133,    99,   100,   101,   102,   103,   104,   133,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   133,
     132,   133,   532,   132,   133,   132,   133,   124,   289,   290,
     133,   128,   129,   130,   131,   132,   133,   134,   135,   132,
     133,   133,   139,   140,   132,   133,   143,   133,   448,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   133,   459,
     460,     3,     4,     5,     6,     7,   133,   133,   133,   166,
     167,   168,   169,   170,   171,   133,   173,   174,   175,   176,
     177,   133,   179,   483,   181,   182,   183,   184,   133,   133,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
     197,   133,   133,   133,   201,   202,   203,   507,   117,   507,
     133,   133,   122,   210,     3,     4,     5,     6,     7,   133,
     217,   133,   130,   220,   304,   543,   133,   133,   133,   226,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
     133,   133,   133,   543,     3,     4,     5,     6,     7,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,     3,
       4,     5,     6,     7,   133,   133,     3,     4,     5,     6,
       7,   133,   269,   133,   271,   133,   273,   133,   133,   276,
     133,   133,   133,     3,     4,     5,     6,     7,   285,   133,
     132,   133,   289,   133,   133,   292,   293,   133,   133,   296,
     133,   133,   299,   286,   321,    -1,   303,   304,    -1,    -1,
     307,   308,   309,    -1,    -1,   312,    -1,    -1,   315,   132,
     133,    -1,    -1,    -1,   132,   133,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,   636,    -1,   636,    -1,
     337,    -1,    -1,   132,   133,   342,    -1,   344,    -1,    -1,
     347,    -1,    -1,   350,    -1,    -1,   353,    -1,   355,   132,
     133,    -1,    -1,    -1,   132,   133,     3,     4,     5,     6,
       7,    -1,    -1,   132,   133,    -1,   373,    -1,   132,   133,
      -1,    -1,    -1,   132,   133,    -1,    -1,   384,   132,   133,
      -1,   388,    -1,    -1,   391,   132,   133,    -1,    -1,    -1,
      -1,   398,   399,    -1,   401,    -1,    -1,    -1,   405,   406,
     407,   408,   132,   133,   411,   412,    -1,    -1,    -1,    -1,
     417,    -1,    -1,   420,    -1,   422,   423,   424,   425,   426,
      -1,    -1,    -1,   430,    -1,    -1,    -1,   434,    -1,    -1,
      -1,   438,    -1,    -1,   441,    -1,    -1,    -1,    -1,   446,
      -1,    -1,   449,    -1,    -1,   132,   133,    -1,    -1,    -1,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,    -1,
      -1,   528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   549,    -1,   551,    -1,   553,   554,    -1,    -1,
      -1,    -1,   559,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   578,    -1,    -1,    -1,    -1,    -1,    -1,   585,     3,
       4,    -1,   589,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,   132,   133,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    -1,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
     134,   135,   136,   137,   138,   139,   140,     3,     4,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    -1,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,   134,   135,
     136,   137,   138,   139,   140,     3,     4,    -1,    -1,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    -1,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,    -1,
      -1,    -1,   120,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,    -1,   132,    -1,   134,   135,   136,   137,
     138,   139,   140,     3,     4,    -1,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   132,   133,    -1,    -1,    -1,   132,   133,
      -1,    -1,    -1,   132,   133,     3,     4,     5,     6,     7,
      -1,    -1,   132,   133,    -1,    -1,    -1,   132,   133,    -1,
      -1,    -1,   122,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,   132,    -1,   134,   135,   136,   137,   138,   139,
     140,     3,     4,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    -1,   132,   133,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
      -1,    -1,   132,   133,     3,     4,     5,     6,     7,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,    -1,
     132,    -1,   134,   135,   136,   137,   138,   139,   140,     3,
       4,    -1,    -1,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    -1,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,   132,
     133,    -1,    -1,    -1,   132,   133,    -1,    -1,     3,     4,
       5,     6,     7,   132,   133,    -1,    -1,    -1,   132,   133,
      -1,    -1,    -1,   132,   133,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,    -1,    -1,    -1,   132,    -1,
     134,   135,   136,   137,   138,   139,   140,     3,     4,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    25,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,   132,   133,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,     3,
       4,     5,     6,     7,   132,   133,    -1,    -1,    -1,   132,
     133,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,   132,    -1,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
      -1,    -1,    -1,   132,   133,    -1,    -1,    -1,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     132,   133,    -1,    -1,    -1,   132,   133,    -1,    -1,    -1,
     132,   133,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   132,   142,   143,   148,   149,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,     3,     4,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    21,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,   134,   135,
     136,   137,   138,   139,   140,   148,   149,     0,   149,     3,
       4,     5,     6,     7,   132,   133,   144,   146,   148,   153,
     133,   146,   146,   144,   145,   144,   145,   145,   144,   144,
     146,   145,   145,   145,   145,   145,   145,   144,   156,   157,
     144,   144,   144,   133,   133,   132,   146,   150,   158,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   146,
     150,   146,   150,   146,   132,   133,   146,   276,   149,   144,
     133,   132,   150,   150,   144,   150,   144,   144,   145,   144,
     145,   144,   150,   144,   145,   144,   150,   150,   150,   146,
     145,   144,   133,   146,   146,   144,   133,   146,   146,   144,
     145,   145,   144,   145,   144,   144,   145,   144,   144,   144,
     133,   144,   150,     3,   133,   150,   150,   133,   150,   150,
     133,   150,   133,   150,   150,   133,   150,   146,   144,   144,
     145,   144,   145,   145,     3,   154,   145,   147,   144,   144,
     150,   144,   144,   146,   145,   146,   145,   145,   145,   145,
     133,   133,   148,   133,   144,   133,   133,   144,   133,   133,
     133,   133,   133,   146,   133,   133,   133,   133,   133,   133,
     133,   132,   133,   144,   151,   133,   133,   151,   152,   149,
     149,    25,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   150,   133,   150,   146,   150,   133,   150,   146,   133,
     150,   146,   133,   133,   276,   133,   146,   133,   149,    25,
     133,   133,   133,   150,   144,   132,   133,   273,   133,   149,
     132,   133,   278,   132,   133,   278,   133,   150,   144,   133,
     150,   133,   150,   150,   133,   144,   133,   133,   133,   133,
     150,   133,   133,   132,   133,   249,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     132,   133,   286,   133,     3,   133,   143,   155,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   144,   133,   144,     3,   133,   133,   144,   133,
     133,   150,   144,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   149,   151,   133,   151,   133,   133,   144,
     133,   146,   133,   146,   146,   133,   133,   144,   144,   146,
     144,   133,   133,   133,   144,   145,   144,   145,   133,   146,
     133,   144,   144,   133,   133,   133,   133,   144,   146,   133,
     145,   133,   144,   145,   144,   144,   145,   144,   133,   146,
     133,   144,   133,   133,   133,   150,   133,   133,   150,   133,
     133,   150,   133,   133,   133,   144,   133,   133,   150,   133,
     133,   133,   133,   133,   133,   150,   133,   133,   133,   133,
     150,   133,   133,   133,   133,     3,   133,   143,   133,   144,
     144,   133,   133,   150,   133,   153,   132,   158,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   132,   133,   133,   133,
     133,   133,   133,   158,   133
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   141,   142,   143,   144,   144,   145,   146,   146,   147,
     147,   148,   148,   149,   149,   149,   150,   150,   150,   151,
     151,   151,   152,   152,   153,   153,   153,   153,   153,   154,
     154,   155,   155,   156,   157,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   181,   181,   182,   183,
     184,   185,   186,   187,   187,   187,   187,   188,   188,   188,
     188,   189,   189,   189,   189,   190,   191,   191,   191,   191,
     191,   192,   193,   194,   195,   196,   197,   197,   197,   197,
     198,   198,   199,   200,   201,   201,   201,   201,   202,   202,
     202,   202,   203,   203,   203,   203,   204,   204,   204,   204,
     205,   206,   207,   208,   208,   209,   210,   210,   211,   211,
     212,   213,   213,   214,   215,   215,   216,   217,   217,   218,
     219,   219,   220,   221,   222,   223,   223,   223,   224,   225,
     225,   225,   225,   226,   226,   227,   227,   228,   229,   229,
     230,   231,   231,   232,   232,   233,   234,   234,   235,   236,
     237,   237,   238,   239,   240,   241,   241,   242,   243,   244,
     245,   246,   246,   246,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   282,   283,   284,   285,   286,   287,   288
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
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     5,
       5,     3,     3,     5,     5,     6,     4,     5,     5,     6,
       4,     5,     5,     6,     4,     4,     5,     5,     4,     4,
       3,     4,     3,     5,     4,     4,     5,     5,     6,     4,
       4,     5,     4,     5,     5,     4,     5,     4,     5,     5,
       6,     4,     5,     4,     5,     4,     5,     5,     6,     4,
       4,     4,     4,     5,     4,     4,     4,     3,     5,     4,
       4,     4,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     3,     4,     5,     4,     6,
       5,     5,     4,     4,     3,     3,     4,     4,     3,     4,
       4,     3,     4,     3,     4,     4,     3,     4,     4,     4,
       4,     3,     4,     4,     4,     4,     5,     4,     4,     4,
       4,     4,     5,     5,     6,     4,     4,     3,     4,     3,
       4,     4,     3,     4,     3,     4,     4,     4,     3,     3,
       3,     4,     4,     4,     4,     4,     3,     3,     4,     4,
       3,     3,     3,     3,     4,     4,     3,     4,     3,     4,
       4,     4,     4,     4,     4,     3,     4,     3,     4,     6
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
  unsigned long yylno = yyrline[yyrule];
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
    default: /* Avoid compiler warnings. */
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
#line 77 "../src/parser.y" /* yacc.c:1258  */
      { free(((*yyvaluep).s)); }
#line 2007 "parser.c" /* yacc.c:1258  */
        break;

    case 4: /* STR  */
#line 77 "../src/parser.y" /* yacc.c:1258  */
      { free(((*yyvaluep).s)); }
#line 2013 "parser.c" /* yacc.c:1258  */
        break;

    case 142: /* start  */
#line 75 "../src/parser.y" /* yacc.c:1258  */
      { run(((*yyvaluep).e));  }
#line 2019 "parser.c" /* yacc.c:1258  */
        break;

    case 143: /* s  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2025 "parser.c" /* yacc.c:1258  */
        break;

    case 144: /* p  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2031 "parser.c" /* yacc.c:1258  */
        break;

    case 145: /* pp  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2037 "parser.c" /* yacc.c:1258  */
        break;

    case 146: /* ps  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2043 "parser.c" /* yacc.c:1258  */
        break;

    case 147: /* pps  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2049 "parser.c" /* yacc.c:1258  */
        break;

    case 148: /* vp  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2055 "parser.c" /* yacc.c:1258  */
        break;

    case 149: /* vps  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2061 "parser.c" /* yacc.c:1258  */
        break;

    case 150: /* opts  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2067 "parser.c" /* yacc.c:1258  */
        break;

    case 151: /* xpb  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2073 "parser.c" /* yacc.c:1258  */
        break;

    case 152: /* xpbs  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2079 "parser.c" /* yacc.c:1258  */
        break;

    case 153: /* np  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2085 "parser.c" /* yacc.c:1258  */
        break;

    case 154: /* sps  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2091 "parser.c" /* yacc.c:1258  */
        break;

    case 155: /* par  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2097 "parser.c" /* yacc.c:1258  */
        break;

    case 156: /* cv  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2103 "parser.c" /* yacc.c:1258  */
        break;

    case 157: /* cvv  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2109 "parser.c" /* yacc.c:1258  */
        break;

    case 158: /* opt  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2115 "parser.c" /* yacc.c:1258  */
        break;

    case 159: /* ivp  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2121 "parser.c" /* yacc.c:1258  */
        break;

    case 160: /* add  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2127 "parser.c" /* yacc.c:1258  */
        break;

    case 161: /* div  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2133 "parser.c" /* yacc.c:1258  */
        break;

    case 162: /* mul  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2139 "parser.c" /* yacc.c:1258  */
        break;

    case 163: /* sub  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2145 "parser.c" /* yacc.c:1258  */
        break;

    case 164: /* and  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2151 "parser.c" /* yacc.c:1258  */
        break;

    case 165: /* bitand  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2157 "parser.c" /* yacc.c:1258  */
        break;

    case 166: /* bitnot  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2163 "parser.c" /* yacc.c:1258  */
        break;

    case 167: /* bitor  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2169 "parser.c" /* yacc.c:1258  */
        break;

    case 168: /* bitxor  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2175 "parser.c" /* yacc.c:1258  */
        break;

    case 169: /* not  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2181 "parser.c" /* yacc.c:1258  */
        break;

    case 170: /* in  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2187 "parser.c" /* yacc.c:1258  */
        break;

    case 171: /* or  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2193 "parser.c" /* yacc.c:1258  */
        break;

    case 172: /* shiftleft  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2199 "parser.c" /* yacc.c:1258  */
        break;

    case 173: /* shiftright  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2205 "parser.c" /* yacc.c:1258  */
        break;

    case 174: /* xor  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2211 "parser.c" /* yacc.c:1258  */
        break;

    case 175: /* eq  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2217 "parser.c" /* yacc.c:1258  */
        break;

    case 176: /* gt  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2223 "parser.c" /* yacc.c:1258  */
        break;

    case 177: /* gte  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2229 "parser.c" /* yacc.c:1258  */
        break;

    case 178: /* lt  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2235 "parser.c" /* yacc.c:1258  */
        break;

    case 179: /* lte  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2241 "parser.c" /* yacc.c:1258  */
        break;

    case 180: /* neq  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2247 "parser.c" /* yacc.c:1258  */
        break;

    case 181: /* if  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2253 "parser.c" /* yacc.c:1258  */
        break;

    case 182: /* select  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2259 "parser.c" /* yacc.c:1258  */
        break;

    case 183: /* until  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2265 "parser.c" /* yacc.c:1258  */
        break;

    case 184: /* while  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2271 "parser.c" /* yacc.c:1258  */
        break;

    case 185: /* trace  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2277 "parser.c" /* yacc.c:1258  */
        break;

    case 186: /* retrace  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2283 "parser.c" /* yacc.c:1258  */
        break;

    case 187: /* execute  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2289 "parser.c" /* yacc.c:1258  */
        break;

    case 188: /* rexx  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2295 "parser.c" /* yacc.c:1258  */
        break;

    case 189: /* run  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2301 "parser.c" /* yacc.c:1258  */
        break;

    case 190: /* abort  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2307 "parser.c" /* yacc.c:1258  */
        break;

    case 191: /* exit  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2313 "parser.c" /* yacc.c:1258  */
        break;

    case 192: /* onerror  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2319 "parser.c" /* yacc.c:1258  */
        break;

    case 193: /* reboot  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2325 "parser.c" /* yacc.c:1258  */
        break;

    case 194: /* trap  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2331 "parser.c" /* yacc.c:1258  */
        break;

    case 195: /* copyfiles  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2337 "parser.c" /* yacc.c:1258  */
        break;

    case 196: /* copylib  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2343 "parser.c" /* yacc.c:1258  */
        break;

    case 197: /* delete  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2349 "parser.c" /* yacc.c:1258  */
        break;

    case 198: /* exists  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2355 "parser.c" /* yacc.c:1258  */
        break;

    case 199: /* fileonly  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2361 "parser.c" /* yacc.c:1258  */
        break;

    case 200: /* foreach  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2367 "parser.c" /* yacc.c:1258  */
        break;

    case 201: /* makeassign  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2373 "parser.c" /* yacc.c:1258  */
        break;

    case 202: /* makedir  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2379 "parser.c" /* yacc.c:1258  */
        break;

    case 203: /* protect  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2385 "parser.c" /* yacc.c:1258  */
        break;

    case 204: /* startup  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2391 "parser.c" /* yacc.c:1258  */
        break;

    case 205: /* textfile  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2397 "parser.c" /* yacc.c:1258  */
        break;

    case 206: /* tooltype  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2403 "parser.c" /* yacc.c:1258  */
        break;

    case 207: /* transcript  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2409 "parser.c" /* yacc.c:1258  */
        break;

    case 208: /* rename  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2415 "parser.c" /* yacc.c:1258  */
        break;

    case 209: /* complete  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2421 "parser.c" /* yacc.c:1258  */
        break;

    case 210: /* debug  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2427 "parser.c" /* yacc.c:1258  */
        break;

    case 211: /* message  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2433 "parser.c" /* yacc.c:1258  */
        break;

    case 212: /* user  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2439 "parser.c" /* yacc.c:1258  */
        break;

    case 213: /* welcome  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2445 "parser.c" /* yacc.c:1258  */
        break;

    case 214: /* working  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2451 "parser.c" /* yacc.c:1258  */
        break;

    case 215: /* database  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2457 "parser.c" /* yacc.c:1258  */
        break;

    case 216: /* earlier  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2463 "parser.c" /* yacc.c:1258  */
        break;

    case 217: /* getassign  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2469 "parser.c" /* yacc.c:1258  */
        break;

    case 218: /* getdevice  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2475 "parser.c" /* yacc.c:1258  */
        break;

    case 219: /* getdiskspace  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2481 "parser.c" /* yacc.c:1258  */
        break;

    case 220: /* getenv  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2487 "parser.c" /* yacc.c:1258  */
        break;

    case 221: /* getsize  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2493 "parser.c" /* yacc.c:1258  */
        break;

    case 222: /* getsum  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2499 "parser.c" /* yacc.c:1258  */
        break;

    case 223: /* getversion  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2505 "parser.c" /* yacc.c:1258  */
        break;

    case 224: /* iconinfo  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2511 "parser.c" /* yacc.c:1258  */
        break;

    case 225: /* dcl  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2517 "parser.c" /* yacc.c:1258  */
        break;

    case 226: /* cus  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2523 "parser.c" /* yacc.c:1258  */
        break;

    case 227: /* askbool  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2529 "parser.c" /* yacc.c:1258  */
        break;

    case 228: /* askchoice  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2535 "parser.c" /* yacc.c:1258  */
        break;

    case 229: /* askdir  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2541 "parser.c" /* yacc.c:1258  */
        break;

    case 230: /* askdisk  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2547 "parser.c" /* yacc.c:1258  */
        break;

    case 231: /* askfile  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2553 "parser.c" /* yacc.c:1258  */
        break;

    case 232: /* asknumber  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2559 "parser.c" /* yacc.c:1258  */
        break;

    case 233: /* askoptions  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2565 "parser.c" /* yacc.c:1258  */
        break;

    case 234: /* askstring  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2571 "parser.c" /* yacc.c:1258  */
        break;

    case 235: /* cat  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2577 "parser.c" /* yacc.c:1258  */
        break;

    case 236: /* expandpath  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2583 "parser.c" /* yacc.c:1258  */
        break;

    case 237: /* fmt  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2589 "parser.c" /* yacc.c:1258  */
        break;

    case 238: /* pathonly  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2595 "parser.c" /* yacc.c:1258  */
        break;

    case 239: /* patmatch  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2601 "parser.c" /* yacc.c:1258  */
        break;

    case 240: /* strlen  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2607 "parser.c" /* yacc.c:1258  */
        break;

    case 241: /* substr  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2613 "parser.c" /* yacc.c:1258  */
        break;

    case 242: /* tackon  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2619 "parser.c" /* yacc.c:1258  */
        break;

    case 243: /* set  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2625 "parser.c" /* yacc.c:1258  */
        break;

    case 244: /* symbolset  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2631 "parser.c" /* yacc.c:1258  */
        break;

    case 245: /* symbolval  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2637 "parser.c" /* yacc.c:1258  */
        break;

    case 246: /* openwbobject  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2643 "parser.c" /* yacc.c:1258  */
        break;

    case 247: /* showwbobject  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2649 "parser.c" /* yacc.c:1258  */
        break;

    case 248: /* closewbobject  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2655 "parser.c" /* yacc.c:1258  */
        break;

    case 249: /* all  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2661 "parser.c" /* yacc.c:1258  */
        break;

    case 250: /* append  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2667 "parser.c" /* yacc.c:1258  */
        break;

    case 251: /* assigns  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2673 "parser.c" /* yacc.c:1258  */
        break;

    case 252: /* choices  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2679 "parser.c" /* yacc.c:1258  */
        break;

    case 253: /* command  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2685 "parser.c" /* yacc.c:1258  */
        break;

    case 254: /* compression  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2691 "parser.c" /* yacc.c:1258  */
        break;

    case 255: /* confirm  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2697 "parser.c" /* yacc.c:1258  */
        break;

    case 256: /* default  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2703 "parser.c" /* yacc.c:1258  */
        break;

    case 257: /* delopts  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2709 "parser.c" /* yacc.c:1258  */
        break;

    case 258: /* dest  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2715 "parser.c" /* yacc.c:1258  */
        break;

    case 259: /* disk  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2721 "parser.c" /* yacc.c:1258  */
        break;

    case 260: /* files  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2727 "parser.c" /* yacc.c:1258  */
        break;

    case 261: /* fonts  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2733 "parser.c" /* yacc.c:1258  */
        break;

    case 262: /* getdefaulttool  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2739 "parser.c" /* yacc.c:1258  */
        break;

    case 263: /* getposition  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2745 "parser.c" /* yacc.c:1258  */
        break;

    case 264: /* getstack  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2751 "parser.c" /* yacc.c:1258  */
        break;

    case 265: /* gettooltype  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2757 "parser.c" /* yacc.c:1258  */
        break;

    case 266: /* help  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2763 "parser.c" /* yacc.c:1258  */
        break;

    case 267: /* infos  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2769 "parser.c" /* yacc.c:1258  */
        break;

    case 268: /* include  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2775 "parser.c" /* yacc.c:1258  */
        break;

    case 269: /* newname  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2781 "parser.c" /* yacc.c:1258  */
        break;

    case 270: /* newpath  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2787 "parser.c" /* yacc.c:1258  */
        break;

    case 271: /* nogauge  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2793 "parser.c" /* yacc.c:1258  */
        break;

    case 272: /* noposition  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2799 "parser.c" /* yacc.c:1258  */
        break;

    case 273: /* noreq  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2805 "parser.c" /* yacc.c:1258  */
        break;

    case 274: /* pattern  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2811 "parser.c" /* yacc.c:1258  */
        break;

    case 275: /* prompt  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2817 "parser.c" /* yacc.c:1258  */
        break;

    case 276: /* quiet  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2823 "parser.c" /* yacc.c:1258  */
        break;

    case 277: /* range  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2829 "parser.c" /* yacc.c:1258  */
        break;

    case 278: /* safe  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2835 "parser.c" /* yacc.c:1258  */
        break;

    case 279: /* setdefaulttool  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2841 "parser.c" /* yacc.c:1258  */
        break;

    case 280: /* setposition  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2847 "parser.c" /* yacc.c:1258  */
        break;

    case 281: /* setstack  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2853 "parser.c" /* yacc.c:1258  */
        break;

    case 282: /* settooltype  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2859 "parser.c" /* yacc.c:1258  */
        break;

    case 283: /* source  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2865 "parser.c" /* yacc.c:1258  */
        break;

    case 284: /* swapcolors  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2871 "parser.c" /* yacc.c:1258  */
        break;

    case 285: /* optional  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2877 "parser.c" /* yacc.c:1258  */
        break;

    case 286: /* resident  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2883 "parser.c" /* yacc.c:1258  */
        break;

    case 287: /* override  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2889 "parser.c" /* yacc.c:1258  */
        break;

    case 288: /* dynopt  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2895 "parser.c" /* yacc.c:1258  */
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
                  (unsigned long) yystacksize));

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
#line 96 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = init((yyvsp[0].e)); }
#line 3163 "parser.c" /* yacc.c:1651  */
    break;

  case 6:
#line 102 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3169 "parser.c" /* yacc.c:1651  */
    break;

  case 7:
#line 103 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3175 "parser.c" /* yacc.c:1651  */
    break;

  case 8:
#line 104 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3181 "parser.c" /* yacc.c:1651  */
    break;

  case 9:
#line 105 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push((yyvsp[-2].e), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3187 "parser.c" /* yacc.c:1651  */
    break;

  case 12:
#line 108 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3193 "parser.c" /* yacc.c:1651  */
    break;

  case 13:
#line 109 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3199 "parser.c" /* yacc.c:1651  */
    break;

  case 14:
#line 110 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3205 "parser.c" /* yacc.c:1651  */
    break;

  case 15:
#line 111 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3211 "parser.c" /* yacc.c:1651  */
    break;

  case 16:
#line 112 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3217 "parser.c" /* yacc.c:1651  */
    break;

  case 17:
#line 113 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3223 "parser.c" /* yacc.c:1651  */
    break;

  case 18:
#line 114 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3229 "parser.c" /* yacc.c:1651  */
    break;

  case 19:
#line 115 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3235 "parser.c" /* yacc.c:1651  */
    break;

  case 20:
#line 116 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push((yyvsp[-2].e), (yyvsp[-1].e)); }
#line 3241 "parser.c" /* yacc.c:1651  */
    break;

  case 21:
#line 117 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3247 "parser.c" /* yacc.c:1651  */
    break;

  case 22:
#line 118 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3253 "parser.c" /* yacc.c:1651  */
    break;

  case 23:
#line 119 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3259 "parser.c" /* yacc.c:1651  */
    break;

  case 24:
#line 120 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3265 "parser.c" /* yacc.c:1651  */
    break;

  case 25:
#line 121 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3271 "parser.c" /* yacc.c:1651  */
    break;

  case 26:
#line 122 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3277 "parser.c" /* yacc.c:1651  */
    break;

  case 27:
#line 123 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_string((yyvsp[0].s)); }
#line 3283 "parser.c" /* yacc.c:1651  */
    break;

  case 28:
#line 124 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_symref((yyvsp[0].s), LINE); }
#line 3289 "parser.c" /* yacc.c:1651  */
    break;

  case 29:
#line 125 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push((yyvsp[-2].e), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)) ; }
#line 3295 "parser.c" /* yacc.c:1651  */
    break;

  case 30:
#line 126 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push(new_contxt(), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)); }
#line 3301 "parser.c" /* yacc.c:1651  */
    break;

  case 31:
#line 127 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push((yyvsp[-1].e), new_symbol((yyvsp[0].s))); }
#line 3307 "parser.c" /* yacc.c:1651  */
    break;

  case 32:
#line 128 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), new_symbol((yyvsp[0].s))); }
#line 3313 "parser.c" /* yacc.c:1651  */
    break;

  case 33:
#line 129 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3319 "parser.c" /* yacc.c:1651  */
    break;

  case 34:
#line 130 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3325 "parser.c" /* yacc.c:1651  */
    break;

  case 164:
#line 266 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("+"), LINE, m_add, (yyvsp[-1].e), NUMBER); }
#line 3331 "parser.c" /* yacc.c:1651  */
    break;

  case 165:
#line 267 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("/"), LINE, m_div, (yyvsp[-1].e), NUMBER); }
#line 3337 "parser.c" /* yacc.c:1651  */
    break;

  case 166:
#line 268 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("*"), LINE, m_mul, (yyvsp[-1].e), NUMBER); }
#line 3343 "parser.c" /* yacc.c:1651  */
    break;

  case 167:
#line 269 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("-"), LINE, m_sub, (yyvsp[-1].e), NUMBER); }
#line 3349 "parser.c" /* yacc.c:1651  */
    break;

  case 168:
#line 272 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("AND"), LINE, m_and, (yyvsp[-1].e), NUMBER); }
#line 3355 "parser.c" /* yacc.c:1651  */
    break;

  case 169:
#line 273 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("BITAND"), LINE, m_bitand, (yyvsp[-1].e), NUMBER); }
#line 3361 "parser.c" /* yacc.c:1651  */
    break;

  case 170:
#line 274 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("BITNOT"), LINE, m_bitnot, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3367 "parser.c" /* yacc.c:1651  */
    break;

  case 171:
#line 275 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("BITOR"), LINE, m_bitor, (yyvsp[-1].e), NUMBER); }
#line 3373 "parser.c" /* yacc.c:1651  */
    break;

  case 172:
#line 276 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("BITXOR"), LINE, m_bitxor, (yyvsp[-1].e), NUMBER); }
#line 3379 "parser.c" /* yacc.c:1651  */
    break;

  case 173:
#line 277 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("NOT"), LINE, m_not, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3385 "parser.c" /* yacc.c:1651  */
    break;

  case 174:
#line 278 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("IN"), LINE, m_in, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3391 "parser.c" /* yacc.c:1651  */
    break;

  case 175:
#line 279 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("OR"), LINE, m_or, (yyvsp[-1].e), NUMBER); }
#line 3397 "parser.c" /* yacc.c:1651  */
    break;

  case 176:
#line 280 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("shiftleft"), LINE, m_shiftleft, (yyvsp[-1].e), NUMBER); }
#line 3403 "parser.c" /* yacc.c:1651  */
    break;

  case 177:
#line 281 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("shiftright"), LINE, m_shiftright, (yyvsp[-1].e), NUMBER); }
#line 3409 "parser.c" /* yacc.c:1651  */
    break;

  case 178:
#line 282 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("XOR"), LINE, m_xor, (yyvsp[-1].e), NUMBER); }
#line 3415 "parser.c" /* yacc.c:1651  */
    break;

  case 179:
#line 285 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("="), LINE, m_eq, (yyvsp[-1].e), NUMBER); }
#line 3421 "parser.c" /* yacc.c:1651  */
    break;

  case 180:
#line 286 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup(">"), LINE, m_gt, (yyvsp[-1].e), NUMBER); }
#line 3427 "parser.c" /* yacc.c:1651  */
    break;

  case 181:
#line 287 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup(">="), LINE, m_gte, (yyvsp[-1].e), NUMBER); }
#line 3433 "parser.c" /* yacc.c:1651  */
    break;

  case 182:
#line 288 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("<"), LINE, m_lt, (yyvsp[-1].e), NUMBER); }
#line 3439 "parser.c" /* yacc.c:1651  */
    break;

  case 183:
#line 289 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("<="), LINE, m_lte, (yyvsp[-1].e), NUMBER); }
#line 3445 "parser.c" /* yacc.c:1651  */
    break;

  case 184:
#line 290 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("<>"), LINE, m_neq, (yyvsp[-1].e), NUMBER); }
#line 3451 "parser.c" /* yacc.c:1651  */
    break;

  case 185:
#line 293 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3457 "parser.c" /* yacc.c:1651  */
    break;

  case 186:
#line 294 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3463 "parser.c" /* yacc.c:1651  */
    break;

  case 187:
#line 295 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3469 "parser.c" /* yacc.c:1651  */
    break;

  case 188:
#line 296 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("select"), LINE, m_select, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3475 "parser.c" /* yacc.c:1651  */
    break;

  case 189:
#line 297 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("until"), LINE, m_until, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3481 "parser.c" /* yacc.c:1651  */
    break;

  case 190:
#line 298 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("while"), LINE, m_while, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3487 "parser.c" /* yacc.c:1651  */
    break;

  case 191:
#line 299 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("trace"), LINE, m_trace, NULL, NUMBER); }
#line 3493 "parser.c" /* yacc.c:1651  */
    break;

  case 192:
#line 300 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("retrace"), LINE, m_retrace, NULL, NUMBER); }
#line 3499 "parser.c" /* yacc.c:1651  */
    break;

  case 193:
#line 303 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3505 "parser.c" /* yacc.c:1651  */
    break;

  case 194:
#line 304 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3511 "parser.c" /* yacc.c:1651  */
    break;

  case 195:
#line 305 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3517 "parser.c" /* yacc.c:1651  */
    break;

  case 196:
#line 306 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, (yyvsp[-1].e), NUMBER); }
#line 3523 "parser.c" /* yacc.c:1651  */
    break;

  case 197:
#line 307 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3529 "parser.c" /* yacc.c:1651  */
    break;

  case 198:
#line 308 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3535 "parser.c" /* yacc.c:1651  */
    break;

  case 199:
#line 309 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3541 "parser.c" /* yacc.c:1651  */
    break;

  case 200:
#line 310 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, (yyvsp[-1].e), NUMBER); }
#line 3547 "parser.c" /* yacc.c:1651  */
    break;

  case 201:
#line 311 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3553 "parser.c" /* yacc.c:1651  */
    break;

  case 202:
#line 312 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3559 "parser.c" /* yacc.c:1651  */
    break;

  case 203:
#line 313 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3565 "parser.c" /* yacc.c:1651  */
    break;

  case 204:
#line 314 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, (yyvsp[-1].e), NUMBER); }
#line 3571 "parser.c" /* yacc.c:1651  */
    break;

  case 205:
#line 317 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("abort"), LINE, m_abort, (yyvsp[-1].e), NUMBER); }
#line 3577 "parser.c" /* yacc.c:1651  */
    break;

  case 206:
#line 318 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3583 "parser.c" /* yacc.c:1651  */
    break;

  case 207:
#line 319 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3589 "parser.c" /* yacc.c:1651  */
    break;

  case 208:
#line 320 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3595 "parser.c" /* yacc.c:1651  */
    break;

  case 209:
#line 321 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, (yyvsp[-1].e), NUMBER); }
#line 3601 "parser.c" /* yacc.c:1651  */
    break;

  case 210:
#line 322 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, NULL, NUMBER); }
#line 3607 "parser.c" /* yacc.c:1651  */
    break;

  case 211:
#line 323 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("onerror"), LINE, m_procedure, push(new_contxt(),
                                                        new_custom(strdup("@onerror"), LINE, NULL, (yyvsp[-1].e))), DANGLE); }
#line 3614 "parser.c" /* yacc.c:1651  */
    break;

  case 212:
#line 325 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("reboot"), LINE, m_reboot, NULL, NUMBER); }
#line 3620 "parser.c" /* yacc.c:1651  */
    break;

  case 213:
#line 326 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("trap"), LINE, m_trap, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3626 "parser.c" /* yacc.c:1651  */
    break;

  case 214:
#line 329 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("copyfiles"), LINE, m_copyfiles, (yyvsp[-1].e), NUMBER); }
#line 3632 "parser.c" /* yacc.c:1651  */
    break;

  case 215:
#line 330 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("copylib"), LINE, m_copylib, (yyvsp[-1].e), NUMBER); }
#line 3638 "parser.c" /* yacc.c:1651  */
    break;

  case 216:
#line 331 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3644 "parser.c" /* yacc.c:1651  */
    break;

  case 217:
#line 332 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3650 "parser.c" /* yacc.c:1651  */
    break;

  case 218:
#line 333 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3656 "parser.c" /* yacc.c:1651  */
    break;

  case 219:
#line 334 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3662 "parser.c" /* yacc.c:1651  */
    break;

  case 220:
#line 335 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3668 "parser.c" /* yacc.c:1651  */
    break;

  case 221:
#line 336 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3674 "parser.c" /* yacc.c:1651  */
    break;

  case 222:
#line 337 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("fileonly"), LINE, m_fileonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3680 "parser.c" /* yacc.c:1651  */
    break;

  case 223:
#line 338 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("foreach"), LINE, m_foreach, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3686 "parser.c" /* yacc.c:1651  */
    break;

  case 224:
#line 339 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3692 "parser.c" /* yacc.c:1651  */
    break;

  case 225:
#line 340 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, (yyvsp[-1].e), NUMBER); }
#line 3698 "parser.c" /* yacc.c:1651  */
    break;

  case 226:
#line 341 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3704 "parser.c" /* yacc.c:1651  */
    break;

  case 227:
#line 342 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3710 "parser.c" /* yacc.c:1651  */
    break;

  case 228:
#line 343 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3716 "parser.c" /* yacc.c:1651  */
    break;

  case 229:
#line 344 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3722 "parser.c" /* yacc.c:1651  */
    break;

  case 230:
#line 345 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3728 "parser.c" /* yacc.c:1651  */
    break;

  case 231:
#line 346 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3734 "parser.c" /* yacc.c:1651  */
    break;

  case 232:
#line 347 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3740 "parser.c" /* yacc.c:1651  */
    break;

  case 233:
#line 348 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, (yyvsp[-1].e), NUMBER); }
#line 3746 "parser.c" /* yacc.c:1651  */
    break;

  case 234:
#line 349 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3752 "parser.c" /* yacc.c:1651  */
    break;

  case 235:
#line 350 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3758 "parser.c" /* yacc.c:1651  */
    break;

  case 236:
#line 351 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3764 "parser.c" /* yacc.c:1651  */
    break;

  case 237:
#line 352 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3770 "parser.c" /* yacc.c:1651  */
    break;

  case 238:
#line 353 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3776 "parser.c" /* yacc.c:1651  */
    break;

  case 239:
#line 354 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), new_symref(strdup("@app-name"), LINE)), (yyvsp[-1].e)), NUMBER); }
#line 3782 "parser.c" /* yacc.c:1651  */
    break;

  case 240:
#line 355 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("textfile"), LINE, m_textfile, (yyvsp[-1].e), NUMBER); }
#line 3788 "parser.c" /* yacc.c:1651  */
    break;

  case 241:
#line 356 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("tooltype"), LINE, m_tooltype, (yyvsp[-1].e), NUMBER); }
#line 3794 "parser.c" /* yacc.c:1651  */
    break;

  case 242:
#line 357 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("transcript"), LINE, m_transcript, (yyvsp[-1].e), NUMBER); }
#line 3800 "parser.c" /* yacc.c:1651  */
    break;

  case 243:
#line 358 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3806 "parser.c" /* yacc.c:1651  */
    break;

  case 244:
#line 359 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, (yyvsp[-1].e), NUMBER); }
#line 3812 "parser.c" /* yacc.c:1651  */
    break;

  case 245:
#line 362 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("complete"), LINE, m_complete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3818 "parser.c" /* yacc.c:1651  */
    break;

  case 246:
#line 363 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, (yyvsp[-1].e), NUMBER); }
#line 3824 "parser.c" /* yacc.c:1651  */
    break;

  case 247:
#line 364 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, NULL, NUMBER); }
#line 3830 "parser.c" /* yacc.c:1651  */
    break;

  case 248:
#line 365 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3836 "parser.c" /* yacc.c:1651  */
    break;

  case 249:
#line 366 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, (yyvsp[-1].e), NUMBER); }
#line 3842 "parser.c" /* yacc.c:1651  */
    break;

  case 250:
#line 367 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("user"), LINE, m_user, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3848 "parser.c" /* yacc.c:1651  */
    break;

  case 251:
#line 368 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, (yyvsp[-1].e), NUMBER); }
#line 3854 "parser.c" /* yacc.c:1651  */
    break;

  case 252:
#line 369 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, NULL, NUMBER); }
#line 3860 "parser.c" /* yacc.c:1651  */
    break;

  case 253:
#line 370 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("working"), LINE, m_working, (yyvsp[-1].e), NUMBER); }
#line 3866 "parser.c" /* yacc.c:1651  */
    break;

  case 254:
#line 373 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3872 "parser.c" /* yacc.c:1651  */
    break;

  case 255:
#line 374 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, (yyvsp[-1].e), STRING); }
#line 3878 "parser.c" /* yacc.c:1651  */
    break;

  case 256:
#line 375 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("earlier"), LINE, m_earlier, (yyvsp[-1].e), NUMBER); }
#line 3884 "parser.c" /* yacc.c:1651  */
    break;

  case 257:
#line 376 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3890 "parser.c" /* yacc.c:1651  */
    break;

  case 258:
#line 377 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, (yyvsp[-1].e), STRING); }
#line 3896 "parser.c" /* yacc.c:1651  */
    break;

  case 259:
#line 378 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getdevice"), LINE, m_getdevice, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3902 "parser.c" /* yacc.c:1651  */
    break;

  case 260:
#line 379 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3908 "parser.c" /* yacc.c:1651  */
    break;

  case 261:
#line 380 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, (yyvsp[-1].e), NUMBER); }
#line 3914 "parser.c" /* yacc.c:1651  */
    break;

  case 262:
#line 381 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getenv"), LINE, m_getenv, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3920 "parser.c" /* yacc.c:1651  */
    break;

  case 263:
#line 382 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getsize"), LINE, m_getsize, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3926 "parser.c" /* yacc.c:1651  */
    break;

  case 264:
#line 383 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getsum"), LINE, m_getsum, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3932 "parser.c" /* yacc.c:1651  */
    break;

  case 265:
#line 384 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, NULL, NUMBER); }
#line 3938 "parser.c" /* yacc.c:1651  */
    break;

  case 266:
#line 385 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3944 "parser.c" /* yacc.c:1651  */
    break;

  case 267:
#line 386 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3950 "parser.c" /* yacc.c:1651  */
    break;

  case 268:
#line 387 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("iconinfo"), LINE, m_iconinfo, (yyvsp[-1].e), NUMBER); }
#line 3956 "parser.c" /* yacc.c:1651  */
    break;

  case 269:
#line 390 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-3].s), LINE, (yyvsp[-2].e), (yyvsp[-1].e))), NUMBER); }
#line 3962 "parser.c" /* yacc.c:1651  */
    break;

  case 270:
#line 391 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, (yyvsp[-1].e), NULL)), NUMBER); }
#line 3968 "parser.c" /* yacc.c:1651  */
    break;

  case 271:
#line 392 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, NULL, (yyvsp[-1].e))), NUMBER); }
#line 3974 "parser.c" /* yacc.c:1651  */
    break;

  case 272:
#line 393 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-1].s), LINE, NULL, NULL)), NUMBER); }
#line 3980 "parser.c" /* yacc.c:1651  */
    break;

  case 273:
#line 394 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_cusref((yyvsp[-2].s), LINE, (yyvsp[-1].e)); }
#line 3986 "parser.c" /* yacc.c:1651  */
    break;

  case 274:
#line 395 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_cusref((yyvsp[-1].s), LINE, NULL); }
#line 3992 "parser.c" /* yacc.c:1651  */
    break;

  case 275:
#line 398 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, NULL, NUMBER); }
#line 3998 "parser.c" /* yacc.c:1651  */
    break;

  case 276:
#line 399 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, (yyvsp[-1].e), NUMBER); }
#line 4004 "parser.c" /* yacc.c:1651  */
    break;

  case 277:
#line 400 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askchoice"), LINE, m_askchoice, (yyvsp[-1].e), NUMBER); }
#line 4010 "parser.c" /* yacc.c:1651  */
    break;

  case 278:
#line 401 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, NULL, STRING); }
#line 4016 "parser.c" /* yacc.c:1651  */
    break;

  case 279:
#line 402 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, (yyvsp[-1].e), STRING); }
#line 4022 "parser.c" /* yacc.c:1651  */
    break;

  case 280:
#line 403 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askdisk"), LINE, m_askdisk, (yyvsp[-1].e), NUMBER); }
#line 4028 "parser.c" /* yacc.c:1651  */
    break;

  case 281:
#line 404 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, NULL, STRING); }
#line 4034 "parser.c" /* yacc.c:1651  */
    break;

  case 282:
#line 405 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, (yyvsp[-1].e), STRING); }
#line 4040 "parser.c" /* yacc.c:1651  */
    break;

  case 283:
#line 406 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, NULL, NUMBER); }
#line 4046 "parser.c" /* yacc.c:1651  */
    break;

  case 284:
#line 407 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, (yyvsp[-1].e), NUMBER); }
#line 4052 "parser.c" /* yacc.c:1651  */
    break;

  case 285:
#line 408 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askoptions"), LINE, m_askoptions, (yyvsp[-1].e), NUMBER); }
#line 4058 "parser.c" /* yacc.c:1651  */
    break;

  case 286:
#line 409 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, NULL, STRING); }
#line 4064 "parser.c" /* yacc.c:1651  */
    break;

  case 287:
#line 410 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, (yyvsp[-1].e), STRING); }
#line 4070 "parser.c" /* yacc.c:1651  */
    break;

  case 288:
#line 413 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("cat"), LINE, m_cat, (yyvsp[-1].e), STRING); }
#line 4076 "parser.c" /* yacc.c:1651  */
    break;

  case 289:
#line 414 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("expandpath"), LINE, m_expandpath, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4082 "parser.c" /* yacc.c:1651  */
    break;

  case 290:
#line 415 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native((yyvsp[-2].s), LINE, m_fmt, (yyvsp[-1].e), STRING); }
#line 4088 "parser.c" /* yacc.c:1651  */
    break;

  case 291:
#line 416 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native((yyvsp[-1].s), LINE, m_fmt, NULL, STRING); }
#line 4094 "parser.c" /* yacc.c:1651  */
    break;

  case 292:
#line 417 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("pathonly"), LINE, m_pathonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4100 "parser.c" /* yacc.c:1651  */
    break;

  case 293:
#line 418 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("patmatch"), LINE, m_patmatch, (yyvsp[-1].e), NUMBER); }
#line 4106 "parser.c" /* yacc.c:1651  */
    break;

  case 294:
#line 419 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("strlen"), LINE, m_strlen, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4112 "parser.c" /* yacc.c:1651  */
    break;

  case 295:
#line 420 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, (yyvsp[-1].e), STRING); }
#line 4118 "parser.c" /* yacc.c:1651  */
    break;

  case 296:
#line 421 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, push((yyvsp[-2].e), (yyvsp[-1].e)), STRING); }
#line 4124 "parser.c" /* yacc.c:1651  */
    break;

  case 297:
#line 422 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("tackon"), LINE, m_tackon, (yyvsp[-1].e), STRING); }
#line 4130 "parser.c" /* yacc.c:1651  */
    break;

  case 298:
#line 425 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("set"), LINE, m_set, (yyvsp[-1].e), DANGLE); }
#line 4136 "parser.c" /* yacc.c:1651  */
    break;

  case 299:
#line 426 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("symbolset"), LINE, m_symbolset, (yyvsp[-1].e), DANGLE); }
#line 4142 "parser.c" /* yacc.c:1651  */
    break;

  case 300:
#line 427 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("symbolval"), LINE, m_symbolval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4148 "parser.c" /* yacc.c:1651  */
    break;

  case 301:
#line 430 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4154 "parser.c" /* yacc.c:1651  */
    break;

  case 302:
#line 431 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4160 "parser.c" /* yacc.c:1651  */
    break;

  case 303:
#line 432 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4166 "parser.c" /* yacc.c:1651  */
    break;

  case 304:
#line 433 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4172 "parser.c" /* yacc.c:1651  */
    break;

  case 305:
#line 434 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("showwbobject"), LINE, m_showwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4178 "parser.c" /* yacc.c:1651  */
    break;

  case 306:
#line 435 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("closewbobject"), LINE, m_closewbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4184 "parser.c" /* yacc.c:1651  */
    break;

  case 307:
#line 438 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("all"), OPT_ALL, NULL); }
#line 4190 "parser.c" /* yacc.c:1651  */
    break;

  case 308:
#line 439 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("append"), OPT_APPEND, (yyvsp[-1].e)); }
#line 4196 "parser.c" /* yacc.c:1651  */
    break;

  case 309:
#line 440 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); }
#line 4202 "parser.c" /* yacc.c:1651  */
    break;

  case 310:
#line 441 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("choices"), OPT_CHOICES, (yyvsp[-1].e)); }
#line 4208 "parser.c" /* yacc.c:1651  */
    break;

  case 311:
#line 442 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("command"), OPT_COMMAND, (yyvsp[-1].e)); }
#line 4214 "parser.c" /* yacc.c:1651  */
    break;

  case 312:
#line 443 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("compression"), OPT_COMPRESSION, NULL); }
#line 4220 "parser.c" /* yacc.c:1651  */
    break;

  case 313:
#line 444 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, push(new_contxt(), (yyvsp[-1].e))); }
#line 4226 "parser.c" /* yacc.c:1651  */
    break;

  case 314:
#line 445 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, NULL); }
#line 4232 "parser.c" /* yacc.c:1651  */
    break;

  case 315:
#line 446 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), (yyvsp[-1].e))); }
#line 4238 "parser.c" /* yacc.c:1651  */
    break;

  case 316:
#line 447 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, (yyvsp[-1].e)); }
#line 4244 "parser.c" /* yacc.c:1651  */
    break;

  case 317:
#line 448 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), (yyvsp[-1].e))); }
#line 4250 "parser.c" /* yacc.c:1651  */
    break;

  case 318:
#line 449 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("disk"), OPT_DISK, NULL); }
#line 4256 "parser.c" /* yacc.c:1651  */
    break;

  case 319:
#line 450 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("files"), OPT_FILES, NULL); }
#line 4262 "parser.c" /* yacc.c:1651  */
    break;

  case 320:
#line 451 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("fonts"), OPT_FONTS, NULL); }
#line 4268 "parser.c" /* yacc.c:1651  */
    break;

  case 321:
#line 452 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4274 "parser.c" /* yacc.c:1651  */
    break;

  case 322:
#line 453 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("getposition"), OPT_GETPOSITION, (yyvsp[-1].e)); }
#line 4280 "parser.c" /* yacc.c:1651  */
    break;

  case 323:
#line 454 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4286 "parser.c" /* yacc.c:1651  */
    break;

  case 324:
#line 455 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, (yyvsp[-1].e)); }
#line 4292 "parser.c" /* yacc.c:1651  */
    break;

  case 325:
#line 456 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, (yyvsp[-1].e)); }
#line 4298 "parser.c" /* yacc.c:1651  */
    break;

  case 326:
#line 457 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4304 "parser.c" /* yacc.c:1651  */
    break;

  case 327:
#line 458 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("infos"), OPT_INFOS, NULL); }
#line 4310 "parser.c" /* yacc.c:1651  */
    break;

  case 328:
#line 459 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4316 "parser.c" /* yacc.c:1651  */
    break;

  case 329:
#line 460 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), (yyvsp[-1].e))); }
#line 4322 "parser.c" /* yacc.c:1651  */
    break;

  case 330:
#line 461 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("newpath"), OPT_NEWPATH, NULL); }
#line 4328 "parser.c" /* yacc.c:1651  */
    break;

  case 331:
#line 462 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); }
#line 4334 "parser.c" /* yacc.c:1651  */
    break;

  case 332:
#line 463 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); }
#line 4340 "parser.c" /* yacc.c:1651  */
    break;

  case 333:
#line 464 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("noreq"), OPT_NOREQ, NULL); }
#line 4346 "parser.c" /* yacc.c:1651  */
    break;

  case 334:
#line 465 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), (yyvsp[-1].e))); }
#line 4352 "parser.c" /* yacc.c:1651  */
    break;

  case 335:
#line 466 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("prompt"), OPT_PROMPT, (yyvsp[-1].e)); }
#line 4358 "parser.c" /* yacc.c:1651  */
    break;

  case 336:
#line 467 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("quiet"), OPT_QUIET, NULL); }
#line 4364 "parser.c" /* yacc.c:1651  */
    break;

  case 337:
#line 468 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("range"), OPT_RANGE, (yyvsp[-1].e)); }
#line 4370 "parser.c" /* yacc.c:1651  */
    break;

  case 338:
#line 469 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("safe"), OPT_SAFE, NULL); }
#line 4376 "parser.c" /* yacc.c:1651  */
    break;

  case 339:
#line 470 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4382 "parser.c" /* yacc.c:1651  */
    break;

  case 340:
#line 471 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("setposition"), OPT_SETPOSITION, (yyvsp[-1].e)); }
#line 4388 "parser.c" /* yacc.c:1651  */
    break;

  case 341:
#line 472 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4394 "parser.c" /* yacc.c:1651  */
    break;

  case 342:
#line 473 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, (yyvsp[-1].e)); }
#line 4400 "parser.c" /* yacc.c:1651  */
    break;

  case 343:
#line 474 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4406 "parser.c" /* yacc.c:1651  */
    break;

  case 344:
#line 475 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4412 "parser.c" /* yacc.c:1651  */
    break;

  case 345:
#line 476 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); }
#line 4418 "parser.c" /* yacc.c:1651  */
    break;

  case 346:
#line 477 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, (yyvsp[-1].e)); }
#line 4424 "parser.c" /* yacc.c:1651  */
    break;

  case 347:
#line 478 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("resident"), OPT_RESIDENT, NULL); }
#line 4430 "parser.c" /* yacc.c:1651  */
    break;

  case 348:
#line 479 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4436 "parser.c" /* yacc.c:1651  */
    break;

  case 349:
#line 480 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(push(new_contxt(), (yyvsp[-3].e)), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4442 "parser.c" /* yacc.c:1651  */
    break;


#line 4446 "parser.c" /* yacc.c:1651  */
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
#line 482 "../src/parser.y" /* yacc.c:1910  */


