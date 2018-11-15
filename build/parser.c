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
// InstallerNG parser
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
    ALL = 343,
    APPEND = 344,
    ASSIGNS = 345,
    CHOICES = 346,
    COMMAND = 347,
    COMPRESSION = 348,
    CONFIRM = 349,
    DEFAULT = 350,
    DELOPTS = 351,
    DEST = 352,
    DISK = 353,
    FILES = 354,
    FONTS = 355,
    GETDEFAULTTOOL = 356,
    GETPOSITION = 357,
    GETSTACK = 358,
    GETTOOLTYPE = 359,
    HELP = 360,
    INFOS = 361,
    INCLUDE = 362,
    NEWNAME = 363,
    NEWPATH = 364,
    NOGAUGE = 365,
    NOPOSITION = 366,
    NOREQ = 367,
    PATTERN = 368,
    PROMPT = 369,
    QUIET = 370,
    RANGE = 371,
    SAFE = 372,
    SETDEFAULTTOOL = 373,
    SETPOSITION = 374,
    SETSTACK = 375,
    SETTOOLTYPE = 376,
    SOURCE = 377,
    SWAPCOLORS = 378,
    OPTIONAL = 379,
    RESIDENT = 380,
    OVERRIDE = 381
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
#define ALL 343
#define APPEND 344
#define ASSIGNS 345
#define CHOICES 346
#define COMMAND 347
#define COMPRESSION 348
#define CONFIRM 349
#define DEFAULT 350
#define DELOPTS 351
#define DEST 352
#define DISK 353
#define FILES 354
#define FONTS 355
#define GETDEFAULTTOOL 356
#define GETPOSITION 357
#define GETSTACK 358
#define GETTOOLTYPE 359
#define HELP 360
#define INFOS 361
#define INCLUDE 362
#define NEWNAME 363
#define NEWPATH 364
#define NOGAUGE 365
#define NOPOSITION 366
#define NOREQ 367
#define PATTERN 368
#define PROMPT 369
#define QUIET 370
#define RANGE 371
#define SAFE 372
#define SETDEFAULTTOOL 373
#define SETPOSITION 374
#define SETSTACK 375
#define SETTOOLTYPE 376
#define SOURCE 377
#define SWAPCOLORS 378
#define OPTIONAL 379
#define RESIDENT 380
#define OVERRIDE 381

/* Value type.  */



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 382 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  177
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1906

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  136
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  143
/* YYNRULES -- Number of rules.  */
#define YYNRULES  336
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  650

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   381

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
     127,   128,   131,   129,     2,   132,     2,   130,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     135,   133,   134,     2,     2,     2,     2,     2,     2,     2,
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
     125,   126
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,    94,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   258,
     259,   260,   261,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   277,   278,   279,   280,   281,   282,
     285,   286,   287,   288,   289,   290,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   307,   308,
     309,   310,   311,   312,   313,   315,   316,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   380,   381,   382,   383,   384,   385,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   415,   416,   417,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462
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
  "SELECT", "UNTIL", "WHILE", "EXECUTE", "REXX", "RUN", "ABORT", "EXIT",
  "ONERROR", "TRAP", "REBOOT", "COPYFILES", "COPYLIB", "DELETE", "EXISTS",
  "FILEONLY", "FOREACH", "MAKEASSIGN", "MAKEDIR", "PROTECT", "STARTUP",
  "TEXTFILE", "TOOLTYPE", "TRANSCRIPT", "RENAME", "COMPLETE", "DEBUG",
  "MESSAGE", "USER", "WELCOME", "WORKING", "DATABASE", "EARLIER",
  "GETASSIGN", "GETDEVICE", "GETDISKSPACE", "GETENV", "GETSIZE", "GETSUM",
  "GETVERSION", "ICONINFO", "CUS", "DCL", "ASKBOOL", "ASKCHOICE", "ASKDIR",
  "ASKDISK", "ASKFILE", "ASKNUMBER", "ASKOPTIONS", "ASKSTRING", "CAT",
  "EXPANDPATH", "FMT", "PATHONLY", "PATMATCH", "STRLEN", "SUBSTR",
  "TACKON", "SET", "SYMBOLSET", "SYMBOLVAL", "ALL", "APPEND", "ASSIGNS",
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
  "lt", "lte", "neq", "if", "select", "until", "while", "execute", "rexx",
  "run", "abort", "exit", "onerror", "trap", "reboot", "copyfiles",
  "copylib", "delete", "exists", "fileonly", "foreach", "makeassign",
  "makedir", "protect", "startup", "textfile", "tooltype", "transcript",
  "rename", "complete", "debug", "message", "user", "welcome", "working",
  "database", "earlier", "getassign", "getdevice", "getdiskspace",
  "getenv", "getsize", "getsum", "getversion", "iconinfo", "dcl", "cus",
  "askbool", "askchoice", "askdir", "askdisk", "askfile", "asknumber",
  "askoptions", "askstring", "cat", "expandpath", "fmt", "pathonly",
  "patmatch", "strlen", "substr", "tackon", "set", "symbolset",
  "symbolval", "all", "append", "assigns", "choices", "command",
  "compression", "confirm", "default", "delopts", "dest", "disk", "files",
  "fonts", "getdefaulttool", "getposition", "getstack", "gettooltype",
  "help", "infos", "include", "newname", "newpath", "nogauge",
  "noposition", "noreq", "pattern", "prompt", "quiet", "range", "safe",
  "setdefaulttool", "setposition", "setstack", "settooltype", "source",
  "swapcolors", "optional", "resident", "override", "dynopt", YY_NULLPTR
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
     375,   376,   377,   378,   379,   380,   381,    40,    41,    43,
      47,    42,    45,    61,    62,    60
};
# endif

#define YYPACT_NINF -497

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-497)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -92,  1553,    58,  -497,  -497,   -92,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,     8,    24,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,   295,   295,   295,    50,    33,   -92,    50,   -85,   -65,
     -65,   295,    50,    50,    50,    50,   295,    50,   295,   -65,
     -65,    50,    50,    50,    68,    50,    50,    73,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    92,   -65,    67,
    -120,   -65,  -109,   -65,   -94,   -86,   -65,   -79,    50,    50,
      50,    50,    50,    50,    50,    79,    50,    50,    50,    50,
      50,    50,    50,    50,    50,   -43,   -77,  -497,   -92,  -497,
    -497,  -497,  -497,  -497,  1686,  -497,  -497,    97,  -497,  -497,
    -497,   102,   107,    50,   -41,   -38,   -13,   -10,    -1,    50,
     117,    27,    34,    53,    55,    71,    90,   125,    95,   100,
    1239,   -92,   -92,   888,   136,   295,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,   203,   295,   277,
     295,   282,  1154,  -497,   329,   338,   -63,   -92,  -497,  1740,
     -61,   -59,    -2,   295,    10,   105,   -92,   431,    19,    26,
     295,   445,    42,   -65,   473,    45,    47,   478,    52,   137,
    -497,   496,   503,   147,  -497,   558,   563,   689,   167,   169,
     696,   177,   185,   701,   187,   189,   195,   198,  -497,    70,
      75,     6,  -497,    77,    89,  -497,    94,    99,  -497,   104,
    -497,   109,   111,  -497,   113,   706,   200,   226,   244,   257,
     711,   274,    50,    43,  -497,   716,   275,   721,   278,   726,
     279,   280,   283,   284,  -497,  -497,   -43,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,   731,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  1553,  -497,  -497,  1239,  -497,
    -497,  -497,   746,   115,   119,    50,   291,    50,   296,    50,
      50,   301,   751,    50,    50,    50,   302,   303,   305,    50,
      50,    50,    50,   766,   311,    50,    50,   312,   314,   325,
     330,    50,    50,   332,    50,   335,    50,    50,    50,    50,
      50,   341,    50,   342,    50,   121,  -497,   127,  1248,   -65,
    -497,   129,  1253,  -497,   131,  1258,  -497,  -497,   343,  -497,
    1267,  -497,   133,    50,  -497,  -497,  -497,   141,   144,    74,
    -497,   344,  -497,   146,  1287,  -497,   345,   357,  -497,   358,
    -497,   150,   163,  -497,   165,  -497,   176,   180,  -497,   194,
    -497,  -497,  -497,  -497,   210,  -497,  -497,  1420,  -497,   359,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,   363,  -497,   362,  -497,  -497,  -497,
     364,    17,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,   365,  -497,  -497,    50,
    -497,  -497,    50,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  1272,  -497,  -497,  -497,  -497,  -497,  1384,  -497,
    1402,  -497,  1514,  1519,  -497,  -497,   367,   369,  1528,   370,
    -497,  -497,  -497,   376,   377,   384,   386,  -497,  1533,  -497,
     388,   389,  -497,  -497,  -497,  -497,   391,  1538,  -497,   392,
    -497,   393,   395,   396,  1647,   397,   398,  -497,  1664,  -497,
     400,  -497,  -497,  -497,   212,  -497,  -497,   219,  -497,  -497,
     239,  -497,  -497,  -497,   402,  -497,  -497,   242,  -497,  -497,
    -497,  -497,  -497,  -497,   256,  -497,  -497,  -497,  -497,   261,
    -497,  -497,  -497,  -497,  -497,  -497,   404,  -497,  -497,  -497,
    -497,   405,  1021,   402,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  1780,  -497,  -497,  -497,  -497,  -497,   408,  -497
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
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     139,   138,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     1,    13,    28,
      27,    24,    25,    26,     0,   267,     8,     0,     4,     5,
     284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    54,    53,    55,    56,    57,
      58,    59,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    60,    74,    61,    73,     0,     0,     0,
       0,     0,     0,   203,     0,     0,     0,     0,   206,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   258,     0,
       0,     0,   268,     0,     0,   271,     0,     0,   274,     0,
     276,     0,     0,   279,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    15,     0,   266,     7,   283,
     163,     6,   164,   165,   166,   167,   168,     0,   170,   171,
     172,   173,   176,   178,   179,     0,   182,    21,    33,   181,
     180,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   189,     0,     0,    16,
     193,     0,     0,   197,     0,     0,   198,   202,     0,   201,
       0,   204,     0,     0,   207,   208,   212,     0,     0,     0,
     213,     0,   215,     0,     0,   220,     0,     0,   218,     0,
     224,     0,     0,   228,     0,   226,     0,     0,   232,     0,
     233,   234,   235,   237,     0,   238,   239,     0,   242,     0,
     243,   244,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,     0,   259,     0,   261,    32,   265,
       0,     0,   269,   270,   272,   273,   275,   277,   278,   280,
     281,   282,   285,   286,   287,   288,     0,   290,    30,     0,
     291,   292,     0,   293,   159,   160,   161,   162,   174,   175,
     177,   169,     0,    34,   183,    23,   184,   185,     0,   294,
       0,   296,     0,     0,   299,   301,     0,     0,     0,     0,
     305,   306,   307,     0,     0,     0,     0,   313,     0,   314,
       0,     0,   317,   318,   319,   320,     0,     0,   323,     0,
     325,     0,     0,     0,     0,     0,     0,   332,     0,   334,
       0,    18,   186,   187,     0,   190,   191,     0,   194,   195,
       0,   199,   200,   205,     0,   209,   210,     0,   214,   216,
     219,   217,   221,   222,     0,   227,   225,   229,   230,     0,
     236,   241,   260,   264,    31,   263,     0,   289,    29,     9,
      19,     0,     0,     0,   295,   297,   298,   300,   302,   303,
     304,   308,   309,   310,   311,   312,   315,   316,   321,   322,
     324,   326,   327,   328,   330,   329,   331,   333,   335,   188,
     192,   196,     0,   211,   223,   231,   262,    20,     0,   336
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -497,  -497,  -309,   254,   -80,   483,  -497,     0,     3,    37,
    -204,  -497,    15,  -497,  -497,  -497,  -497,  -496,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,   238,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
    -497,  -497,  -497,  -497,  -497,  -497,  -497,   265,  -497,  -497,
    -105,  -497,   114,  -497,  -497,  -497,  -497,  -497,  -497,  -497,
     231,  -497,  -497
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   186,   194,   187,   335,   188,   178,   419,
     368,   372,   189,   333,   491,   208,   209,   216,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
       4,   175,   490,     5,   176,     4,   371,   269,   312,   488,
     265,   179,   180,   181,   182,   183,   196,   197,   269,   315,
     604,   201,   202,   203,   204,   205,   206,   179,   180,   181,
     182,   183,   613,   269,   318,     1,   179,   180,   181,   182,
     183,   269,   320,   268,   276,   278,   509,   282,   269,   323,
       1,   345,   288,   179,   180,   181,   182,   183,   177,   298,
     299,   301,   269,   304,     1,   431,   269,   434,   269,   435,
     311,   179,   180,   181,   182,   183,   179,   180,   181,   182,
     183,   328,   332,   330,   331,   344,   334,   352,   613,   338,
     353,   340,   341,   342,   343,   179,   180,   181,   182,   183,
     179,   180,   181,   182,   183,   179,   180,   181,   182,   183,
     179,   180,   181,   182,   183,   354,     4,   648,   355,   266,
     179,   180,   181,   182,   183,   269,   436,   356,   179,   180,
     181,   182,   183,     1,   489,   184,   185,   439,   440,   179,
     180,   181,   182,   183,     1,   605,   447,   448,   215,   258,
     260,   184,   190,   269,   450,   359,   270,   271,   273,   428,
     262,   263,   360,   280,   523,   284,   285,   286,   525,   269,
     455,   510,   269,   460,   269,   461,     4,   184,     4,   269,
     463,   361,   606,   362,   346,   310,   400,   313,   314,   316,
     317,   319,   321,   322,   324,   184,   290,   484,   485,   363,
     184,   294,   269,   487,   269,   492,   179,   180,   181,   182,
     183,     4,     4,   346,   373,   374,   269,   493,   364,   184,
     308,   269,   494,   369,   184,   347,   269,   495,   370,   184,
     349,   269,   496,   442,   184,   350,   269,   497,   269,   498,
     269,   499,     1,   526,   184,   358,     1,   527,   269,   571,
     415,   417,   365,   366,   269,   572,   269,   575,   269,   578,
       1,   583,   346,   213,   416,   465,     4,     4,   269,   585,
     432,   269,   586,     1,   589,   470,     4,   269,   592,   443,
     179,   180,   181,   182,   183,   179,   180,   181,   182,   183,
     269,   593,   269,   595,   421,   474,   424,   475,   179,   180,
     181,   182,   183,   269,   596,   477,   415,   269,   597,   437,
     544,     4,   546,   478,     5,   480,   451,   481,   454,   456,
     457,   269,   598,   482,   559,   464,   483,   562,   501,   565,
     213,   420,   179,   180,   181,   182,   183,   269,   600,   269,
     639,   179,   180,   181,   182,   183,   269,   640,   193,   195,
     193,   193,   198,   199,   502,   193,   193,   193,   193,   193,
     193,   207,   210,   211,   212,   175,   269,   641,   522,   269,
     643,   267,   503,     4,     4,   272,   274,   275,   193,   277,
     279,   281,   283,   269,   644,   504,   193,   289,   269,   645,
     293,   446,   449,   297,   193,   300,   302,   303,   305,   306,
     307,   309,   507,   513,   213,   423,   515,   517,   518,   184,
     426,   519,   520,   326,   327,   193,   329,   193,   193,   529,
     193,   336,   213,   193,   531,   193,   193,   193,   193,   534,
     540,   541,     4,   542,   179,   180,   181,   182,   183,   549,
     552,   348,   553,     4,   346,   348,   348,   351,   179,   180,
     181,   182,   183,   554,   348,   574,   262,   427,   555,   577,
     558,   367,   580,   560,   367,   184,   429,   346,   348,   567,
     569,   581,   588,   590,   405,   587,   179,   180,   181,   182,
     183,   179,   180,   181,   182,   183,   591,   601,   413,   594,
     602,     4,   603,   607,     5,   617,   599,   618,   620,   179,
     180,   181,   182,   183,   621,   622,   179,   180,   181,   182,
     183,   348,   623,   348,   624,   348,   626,   627,   348,   628,
     630,   631,     4,   632,   633,   635,   636,   438,   638,   642,
     469,   351,   646,   647,   452,   351,   649,   611,   459,   441,
     486,   348,     0,     0,     0,   348,   348,     0,     0,   348,
     348,   351,     0,     0,   351,     0,     0,   351,   444,   445,
       0,   179,   180,   181,   182,   183,   179,   180,   181,   182,
     183,     0,   213,   453,     0,   191,   192,     0,     0,   348,
       0,     0,     0,   200,   506,     0,   508,     0,     0,   512,
       0,   348,     0,   348,   214,   257,   259,   261,   264,     0,
     213,   458,     0,     0,     0,   184,   462,     0,     0,     0,
       0,   348,   175,     0,   287,   522,     0,   291,   292,     0,
     295,   296,   367,   184,   466,     0,   367,     0,     0,   528,
     467,   468,     0,     0,     0,     0,   536,   537,     0,   539,
       0,   325,     0,   543,   193,   545,   193,     0,     0,   550,
     551,   337,     0,   339,     0,   556,     0,     0,   193,     0,
     561,   193,   563,   564,   566,     0,     0,     0,   570,     0,
       0,     0,   348,     0,     0,     0,   348,     0,     0,   348,
       0,     0,   357,     0,   348,   184,   471,   584,     0,     0,
     184,   472,   179,   180,   181,   182,   183,     0,   418,   179,
     180,   181,   182,   183,   179,   180,   181,   182,   183,   179,
     180,   181,   182,   183,   179,   180,   181,   182,   183,   179,
     180,   181,   182,   183,   179,   180,   181,   182,   183,   179,
     180,   181,   182,   183,   179,   180,   181,   182,   183,     0,
       0,   422,     0,   425,     0,     0,     0,     0,   430,   179,
     180,   181,   182,   183,   179,   180,   181,   182,   183,     0,
       0,     0,     0,   608,     0,     0,   609,     0,     0,   179,
     180,   181,   182,   183,     0,     0,     0,     0,     0,     0,
       0,     0,   367,     0,   348,     0,   348,   348,     0,     0,
       0,     0,   348,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   348,     0,     0,     0,     0,     0,     0,     0,
       0,   348,     0,     0,     0,     0,   184,   473,   351,     0,
       0,     0,   348,   184,   476,     0,     0,     0,   184,   479,
       0,     0,     0,   184,   500,     0,     0,     0,   184,   505,
       0,     0,     0,   184,   511,     0,     0,     0,   184,   514,
       0,     0,     0,   184,   516,     0,     0,     0,   184,   521,
     530,     0,   532,   533,     0,     0,     0,   538,     0,     0,
       0,     0,     0,   365,   524,     0,   548,     0,   184,   535,
       0,     0,     0,     0,     0,   557,     0,     0,     0,     0,
       0,    91,    92,   184,   547,   568,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,     0,   104,
       0,   105,   106,   375,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,     0,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,   164,   165,   166,   167,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   213,     0,   168,   169,   170,
     171,   172,   173,   174,    91,    92,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,   104,     0,   105,   106,   375,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,     0,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       0,   160,   161,   162,   163,   164,   165,   166,   167,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,     1,     0,
     168,   169,   170,   171,   172,   173,   174,    91,    92,     0,
       0,     0,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,     0,   104,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,     0,   160,   161,   162,   163,   164,   165,
     166,   167,   179,   180,   181,   182,   183,     0,     0,     0,
       0,   179,   180,   181,   182,   183,   179,   180,   181,   182,
     183,   179,   180,   181,   182,   183,     0,     0,     0,   403,
     179,   180,   181,   182,   183,   179,   180,   181,   182,   183,
       0,   184,     0,   168,   169,   170,   171,   172,   173,   174,
      91,    92,     0,     0,     0,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,   104,     0,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   365,   160,   161,   162,
     163,   164,   165,   166,   167,   213,   573,     0,     0,     0,
     213,   576,     0,     0,     0,   213,   579,   179,   180,   181,
     182,   183,     0,     0,   184,   582,     0,     0,     0,     1,
     610,     0,     0,     0,   405,   179,   180,   181,   182,   183,
       0,     0,     0,     0,   184,     0,   168,   169,   170,   171,
     172,   173,   174,    91,    92,     0,     0,     0,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
       0,   104,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,     0,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,     0,
     160,   161,   162,   163,   164,   165,   166,   167,   376,     0,
       0,   612,   366,     0,     0,     0,     0,   179,   180,   181,
     182,   183,   179,   180,   181,   182,   183,     0,     0,   184,
     614,   179,   180,   181,   182,   183,   179,   180,   181,   182,
     183,   179,   180,   181,   182,   183,     0,   184,     0,   168,
     169,   170,   171,   172,   173,   174,    91,    92,     0,     0,
       0,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,     0,   104,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     0,   160,   161,   162,   163,   164,   165,   166,
     167,   184,   615,     0,     0,     0,   184,   616,     0,     0,
     179,   180,   181,   182,   183,   184,   619,     0,     0,     0,
     184,   625,     0,     0,     0,   184,   629,   179,   180,   181,
     182,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,   168,   169,   170,   171,   172,   173,   174,    91,
      92,     0,     0,     0,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,     0,   104,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,     0,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   433,   160,   161,   162,   163,
     164,   165,   166,   167,   184,   634,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,   637,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   433,     0,     0,     0,     0,
       0,     0,     0,   184,     0,   168,   169,   170,   171,   172,
     173,   174,     0,     0,     0,     0,     0,     0,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   269,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414
};

static const yytype_int16 yycheck[] =
{
       0,     1,   311,     0,     1,     5,   210,   127,   128,     3,
     115,     3,     4,     5,     6,     7,    96,    97,   127,   128,
       3,   101,   102,   103,   104,   105,   106,     3,     4,     5,
       6,     7,   528,   127,   128,   127,     3,     4,     5,     6,
       7,   127,   128,   128,   124,   125,     3,   127,   127,   128,
     127,   128,   132,     3,     4,     5,     6,     7,     0,   139,
     140,   141,   127,   143,   127,   128,   127,   128,   127,   128,
       3,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,   161,     3,   163,   164,   128,   166,   128,   584,   169,
     128,   171,   172,   173,   174,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,   128,   116,   613,   128,   116,
       3,     4,     5,     6,     7,   127,   128,   128,     3,     4,
       5,     6,     7,   127,   128,   127,   128,   127,   128,     3,
       4,     5,     6,     7,   127,   128,   127,   128,   111,   112,
     113,   127,   128,   127,   128,   128,   119,   120,   121,   264,
     127,   128,   128,   126,   368,   128,   129,   130,   372,   127,
     128,   128,   127,   128,   127,   128,   176,   127,   178,   127,
     128,   128,   491,   128,   184,   148,   112,   150,   151,   152,
     153,   154,   155,   156,   157,   127,   128,   127,   128,   128,
     127,   128,   127,   128,   127,   128,     3,     4,     5,     6,
       7,   211,   212,   213,   211,   212,   127,   128,   128,   127,
     128,   127,   128,   128,   127,   128,   127,   128,   128,   127,
     128,   127,   128,   128,   127,   128,   127,   128,   127,   128,
     127,   128,   127,   128,   127,   128,   127,   128,   127,   128,
     213,   214,   127,   128,   127,   128,   127,   128,   127,   128,
     127,   128,   262,   127,   128,   128,   266,   267,   127,   128,
     267,   127,   128,   127,   128,   128,   276,   127,   128,   276,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
     127,   128,   127,   128,   257,   128,   259,   128,     3,     4,
       5,     6,     7,   127,   128,   128,   269,   127,   128,   272,
     390,   311,   392,   128,   311,   128,   279,   128,   281,   282,
     283,   127,   128,   128,   404,   288,   128,   407,   128,   409,
     127,   128,     3,     4,     5,     6,     7,   127,   128,   127,
     128,     3,     4,     5,     6,     7,   127,   128,    94,    95,
      96,    97,    98,    99,   128,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   365,   127,   128,   365,   127,
     128,   117,   128,   373,   374,   121,   122,   123,   124,   125,
     126,   127,   128,   127,   128,   128,   132,   133,   127,   128,
     136,   277,   278,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   128,   128,   127,   128,   128,   128,   128,   127,
     128,   128,   128,   159,   160,   161,   162,   163,   164,   128,
     166,   167,   127,   169,   128,   171,   172,   173,   174,   128,
     128,   128,   432,   128,     3,     4,     5,     6,     7,   128,
     128,   187,   128,   443,   444,   191,   192,   193,     3,     4,
       5,     6,     7,   128,   200,   418,   127,   128,   128,   422,
     128,   207,   425,   128,   210,   127,   128,   467,   214,   128,
     128,   128,   128,   128,   117,   438,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,   128,   128,   125,   452,
     128,   491,   128,   128,   491,   128,   459,   128,   128,     3,
       4,     5,     6,     7,   128,   128,     3,     4,     5,     6,
       7,   257,   128,   259,   128,   261,   128,   128,   264,   128,
     128,   128,   522,   128,   128,   128,   128,   273,   128,   127,
     292,   277,   128,   128,   280,   281,   128,   522,   284,   274,
     309,   287,    -1,    -1,    -1,   291,   292,    -1,    -1,   295,
     296,   297,    -1,    -1,   300,    -1,    -1,   303,   127,   128,
      -1,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,    -1,   127,   128,    -1,    92,    93,    -1,    -1,   325,
      -1,    -1,    -1,   100,   330,    -1,   332,    -1,    -1,   335,
      -1,   337,    -1,   339,   111,   112,   113,   114,   115,    -1,
     127,   128,    -1,    -1,    -1,   127,   128,    -1,    -1,    -1,
      -1,   357,   612,    -1,   131,   612,    -1,   134,   135,    -1,
     137,   138,   368,   127,   128,    -1,   372,    -1,    -1,   375,
     127,   128,    -1,    -1,    -1,    -1,   382,   383,    -1,   385,
      -1,   158,    -1,   389,   390,   391,   392,    -1,    -1,   395,
     396,   168,    -1,   170,    -1,   401,    -1,    -1,   404,    -1,
     406,   407,   408,   409,   410,    -1,    -1,    -1,   414,    -1,
      -1,    -1,   418,    -1,    -1,    -1,   422,    -1,    -1,   425,
      -1,    -1,   199,    -1,   430,   127,   128,   433,    -1,    -1,
     127,   128,     3,     4,     5,     6,     7,    -1,   215,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,    -1,
      -1,   258,    -1,   260,    -1,    -1,    -1,    -1,   265,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,   509,    -1,    -1,   512,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   528,    -1,   530,    -1,   532,   533,    -1,    -1,
      -1,    -1,   538,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   557,    -1,    -1,    -1,    -1,   127,   128,   564,    -1,
      -1,    -1,   568,   127,   128,    -1,    -1,    -1,   127,   128,
      -1,    -1,    -1,   127,   128,    -1,    -1,    -1,   127,   128,
      -1,    -1,    -1,   127,   128,    -1,    -1,    -1,   127,   128,
      -1,    -1,    -1,   127,   128,    -1,    -1,    -1,   127,   128,
     377,    -1,   379,   380,    -1,    -1,    -1,   384,    -1,    -1,
      -1,    -1,    -1,   127,   128,    -1,   393,    -1,   127,   128,
      -1,    -1,    -1,    -1,    -1,   402,    -1,    -1,    -1,    -1,
      -1,     3,     4,   127,   128,   412,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,   129,   130,   131,
     132,   133,   134,   135,     3,     4,    -1,    -1,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
     129,   130,   131,   132,   133,   134,   135,     3,     4,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,    -1,    -1,    -1,   115,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
      -1,   127,    -1,   129,   130,   131,   132,   133,   134,   135,
       3,     4,    -1,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,   127,    80,    81,    82,
      83,    84,    85,    86,    87,   127,   128,    -1,    -1,    -1,
     127,   128,    -1,    -1,    -1,   127,   128,     3,     4,     5,
       6,     7,    -1,    -1,   127,   128,    -1,    -1,    -1,   127,
     128,    -1,    -1,    -1,   117,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,
     133,   134,   135,     3,     4,    -1,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,   127,   128,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,    -1,    -1,   127,
     128,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,    -1,   127,    -1,   129,
     130,   131,   132,   133,   134,   135,     3,     4,    -1,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,   127,   128,    -1,    -1,    -1,   127,   128,    -1,    -1,
       3,     4,     5,     6,     7,   127,   128,    -1,    -1,    -1,
     127,   128,    -1,    -1,    -1,   127,   128,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,    -1,   129,   130,   131,   132,   133,   134,   135,     3,
       4,    -1,    -1,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    25,    80,    81,    82,    83,
      84,    85,    86,    87,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,   133,
     134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   127,   137,   138,   143,   144,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     3,     4,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    21,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      80,    81,    82,    83,    84,    85,    86,    87,   129,   130,
     131,   132,   133,   134,   135,   143,   144,     0,   144,     3,
       4,     5,     6,     7,   127,   128,   139,   141,   143,   148,
     128,   141,   141,   139,   140,   139,   140,   140,   139,   139,
     141,   140,   140,   140,   140,   140,   140,   139,   151,   152,
     139,   139,   139,   127,   141,   145,   153,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   141,   145,   141,
     145,   141,   127,   128,   141,   266,   144,   139,   128,   127,
     145,   145,   139,   145,   139,   139,   140,   139,   140,   139,
     145,   139,   140,   139,   145,   145,   145,   141,   140,   139,
     128,   141,   141,   139,   128,   141,   141,   139,   140,   140,
     139,   140,   139,   139,   140,   139,   139,   139,   128,   139,
     145,     3,   128,   145,   145,   128,   145,   145,   128,   145,
     128,   145,   145,   128,   145,   141,   139,   139,   140,   139,
     140,   140,     3,   149,   140,   142,   139,   141,   140,   141,
     140,   140,   140,   140,   128,   128,   143,   128,   139,   128,
     128,   139,   128,   128,   128,   128,   128,   141,   128,   128,
     128,   128,   128,   128,   128,   127,   128,   139,   146,   128,
     128,   146,   147,   144,   144,    25,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   145,   128,   145,   141,   145,
     128,   145,   141,   128,   145,   141,   128,   128,   266,   128,
     141,   128,   144,    25,   128,   128,   128,   145,   139,   127,
     128,   263,   128,   144,   127,   128,   268,   127,   128,   268,
     128,   145,   139,   128,   145,   128,   145,   145,   128,   139,
     128,   128,   128,   128,   145,   128,   128,   127,   128,   239,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   127,   128,   276,   128,     3,   128,
     138,   150,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   139,   128,   139,     3,
     128,   128,   139,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   144,   146,   128,   146,   128,   128,   139,   128,
     141,   128,   141,   141,   128,   128,   139,   139,   141,   139,
     128,   128,   128,   139,   140,   139,   140,   128,   141,   128,
     139,   139,   128,   128,   128,   128,   139,   141,   128,   140,
     128,   139,   140,   139,   139,   140,   139,   128,   141,   128,
     139,   128,   128,   128,   145,   128,   128,   145,   128,   128,
     145,   128,   128,   128,   139,   128,   128,   145,   128,   128,
     128,   128,   128,   128,   145,   128,   128,   128,   128,   145,
     128,   128,   128,   128,     3,   128,   138,   128,   139,   139,
     128,   148,   127,   153,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   127,   128,   128,   128,   128,   128,   153,   128
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   136,   137,   138,   139,   139,   140,   141,   141,   142,
     142,   143,   143,   144,   144,   144,   145,   145,   145,   146,
     146,   146,   147,   147,   148,   148,   148,   148,   148,   149,
     149,   150,   150,   151,   152,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   176,   176,   177,   178,   179,   180,   180,   180,   180,
     181,   181,   181,   181,   182,   182,   182,   182,   183,   184,
     184,   184,   184,   184,   185,   186,   187,   188,   189,   190,
     190,   190,   190,   191,   191,   192,   193,   194,   194,   194,
     194,   195,   195,   195,   195,   196,   196,   196,   196,   197,
     197,   197,   197,   198,   199,   200,   201,   201,   202,   203,
     203,   204,   204,   205,   206,   206,   207,   208,   208,   209,
     210,   210,   211,   212,   212,   213,   214,   215,   216,   216,
     216,   217,   218,   218,   218,   218,   219,   219,   220,   220,
     221,   222,   222,   223,   224,   224,   225,   225,   226,   227,
     227,   228,   229,   230,   230,   231,   232,   233,   234,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     272,   273,   274,   275,   276,   277,   278
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     5,     5,     5,     5,     5,     6,     4,
       5,     5,     6,     4,     5,     5,     6,     4,     4,     5,
       5,     4,     4,     3,     4,     5,     3,     4,     4,     5,
       5,     6,     4,     4,     5,     4,     5,     5,     4,     5,
       4,     5,     5,     6,     4,     5,     4,     5,     4,     5,
       5,     6,     4,     4,     4,     4,     5,     4,     4,     4,
       3,     5,     4,     4,     4,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     4,
       5,     4,     6,     5,     5,     4,     4,     3,     3,     4,
       4,     3,     4,     4,     3,     4,     3,     4,     4,     3,
       4,     4,     4,     4,     3,     4,     4,     4,     4,     5,
       4,     4,     4,     4,     3,     4,     3,     4,     4,     3,
       4,     3,     4,     4,     4,     3,     3,     3,     4,     4,
       4,     4,     4,     3,     3,     4,     4,     3,     3,     3,
       3,     4,     4,     3,     4,     3,     4,     4,     4,     4,
       4,     4,     3,     4,     3,     4,     6
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
#line 75 "../src/parser.y" /* yacc.c:1258  */
      { free(((*yyvaluep).s)); }
#line 1961 "parser.c" /* yacc.c:1258  */
        break;

    case 4: /* STR  */
#line 75 "../src/parser.y" /* yacc.c:1258  */
      { free(((*yyvaluep).s)); }
#line 1967 "parser.c" /* yacc.c:1258  */
        break;

    case 137: /* start  */
#line 73 "../src/parser.y" /* yacc.c:1258  */
      { run(((*yyvaluep).e));  }
#line 1973 "parser.c" /* yacc.c:1258  */
        break;

    case 138: /* s  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 1979 "parser.c" /* yacc.c:1258  */
        break;

    case 139: /* p  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 1985 "parser.c" /* yacc.c:1258  */
        break;

    case 140: /* pp  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 1991 "parser.c" /* yacc.c:1258  */
        break;

    case 141: /* ps  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 1997 "parser.c" /* yacc.c:1258  */
        break;

    case 142: /* pps  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2003 "parser.c" /* yacc.c:1258  */
        break;

    case 143: /* vp  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2009 "parser.c" /* yacc.c:1258  */
        break;

    case 144: /* vps  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2015 "parser.c" /* yacc.c:1258  */
        break;

    case 145: /* opts  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2021 "parser.c" /* yacc.c:1258  */
        break;

    case 146: /* xpb  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2027 "parser.c" /* yacc.c:1258  */
        break;

    case 147: /* xpbs  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2033 "parser.c" /* yacc.c:1258  */
        break;

    case 148: /* np  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2039 "parser.c" /* yacc.c:1258  */
        break;

    case 149: /* sps  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2045 "parser.c" /* yacc.c:1258  */
        break;

    case 150: /* par  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2051 "parser.c" /* yacc.c:1258  */
        break;

    case 151: /* cv  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2057 "parser.c" /* yacc.c:1258  */
        break;

    case 152: /* cvv  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2063 "parser.c" /* yacc.c:1258  */
        break;

    case 153: /* opt  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2069 "parser.c" /* yacc.c:1258  */
        break;

    case 154: /* ivp  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2075 "parser.c" /* yacc.c:1258  */
        break;

    case 155: /* add  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2081 "parser.c" /* yacc.c:1258  */
        break;

    case 156: /* div  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2087 "parser.c" /* yacc.c:1258  */
        break;

    case 157: /* mul  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2093 "parser.c" /* yacc.c:1258  */
        break;

    case 158: /* sub  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2099 "parser.c" /* yacc.c:1258  */
        break;

    case 159: /* and  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2105 "parser.c" /* yacc.c:1258  */
        break;

    case 160: /* bitand  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2111 "parser.c" /* yacc.c:1258  */
        break;

    case 161: /* bitnot  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2117 "parser.c" /* yacc.c:1258  */
        break;

    case 162: /* bitor  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2123 "parser.c" /* yacc.c:1258  */
        break;

    case 163: /* bitxor  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2129 "parser.c" /* yacc.c:1258  */
        break;

    case 164: /* not  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2135 "parser.c" /* yacc.c:1258  */
        break;

    case 165: /* in  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2141 "parser.c" /* yacc.c:1258  */
        break;

    case 166: /* or  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2147 "parser.c" /* yacc.c:1258  */
        break;

    case 167: /* shiftleft  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2153 "parser.c" /* yacc.c:1258  */
        break;

    case 168: /* shiftright  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2159 "parser.c" /* yacc.c:1258  */
        break;

    case 169: /* xor  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2165 "parser.c" /* yacc.c:1258  */
        break;

    case 170: /* eq  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2171 "parser.c" /* yacc.c:1258  */
        break;

    case 171: /* gt  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2177 "parser.c" /* yacc.c:1258  */
        break;

    case 172: /* gte  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2183 "parser.c" /* yacc.c:1258  */
        break;

    case 173: /* lt  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2189 "parser.c" /* yacc.c:1258  */
        break;

    case 174: /* lte  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2195 "parser.c" /* yacc.c:1258  */
        break;

    case 175: /* neq  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2201 "parser.c" /* yacc.c:1258  */
        break;

    case 176: /* if  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2207 "parser.c" /* yacc.c:1258  */
        break;

    case 177: /* select  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2213 "parser.c" /* yacc.c:1258  */
        break;

    case 178: /* until  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2219 "parser.c" /* yacc.c:1258  */
        break;

    case 179: /* while  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2225 "parser.c" /* yacc.c:1258  */
        break;

    case 180: /* execute  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2231 "parser.c" /* yacc.c:1258  */
        break;

    case 181: /* rexx  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2237 "parser.c" /* yacc.c:1258  */
        break;

    case 182: /* run  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2243 "parser.c" /* yacc.c:1258  */
        break;

    case 183: /* abort  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2249 "parser.c" /* yacc.c:1258  */
        break;

    case 184: /* exit  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2255 "parser.c" /* yacc.c:1258  */
        break;

    case 185: /* onerror  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2261 "parser.c" /* yacc.c:1258  */
        break;

    case 186: /* trap  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2267 "parser.c" /* yacc.c:1258  */
        break;

    case 187: /* reboot  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2273 "parser.c" /* yacc.c:1258  */
        break;

    case 188: /* copyfiles  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2279 "parser.c" /* yacc.c:1258  */
        break;

    case 189: /* copylib  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2285 "parser.c" /* yacc.c:1258  */
        break;

    case 190: /* delete  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2291 "parser.c" /* yacc.c:1258  */
        break;

    case 191: /* exists  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2297 "parser.c" /* yacc.c:1258  */
        break;

    case 192: /* fileonly  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2303 "parser.c" /* yacc.c:1258  */
        break;

    case 193: /* foreach  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2309 "parser.c" /* yacc.c:1258  */
        break;

    case 194: /* makeassign  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2315 "parser.c" /* yacc.c:1258  */
        break;

    case 195: /* makedir  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2321 "parser.c" /* yacc.c:1258  */
        break;

    case 196: /* protect  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2327 "parser.c" /* yacc.c:1258  */
        break;

    case 197: /* startup  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2333 "parser.c" /* yacc.c:1258  */
        break;

    case 198: /* textfile  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2339 "parser.c" /* yacc.c:1258  */
        break;

    case 199: /* tooltype  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2345 "parser.c" /* yacc.c:1258  */
        break;

    case 200: /* transcript  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2351 "parser.c" /* yacc.c:1258  */
        break;

    case 201: /* rename  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2357 "parser.c" /* yacc.c:1258  */
        break;

    case 202: /* complete  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2363 "parser.c" /* yacc.c:1258  */
        break;

    case 203: /* debug  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2369 "parser.c" /* yacc.c:1258  */
        break;

    case 204: /* message  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2375 "parser.c" /* yacc.c:1258  */
        break;

    case 205: /* user  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2381 "parser.c" /* yacc.c:1258  */
        break;

    case 206: /* welcome  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2387 "parser.c" /* yacc.c:1258  */
        break;

    case 207: /* working  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2393 "parser.c" /* yacc.c:1258  */
        break;

    case 208: /* database  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2399 "parser.c" /* yacc.c:1258  */
        break;

    case 209: /* earlier  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2405 "parser.c" /* yacc.c:1258  */
        break;

    case 210: /* getassign  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2411 "parser.c" /* yacc.c:1258  */
        break;

    case 211: /* getdevice  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2417 "parser.c" /* yacc.c:1258  */
        break;

    case 212: /* getdiskspace  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2423 "parser.c" /* yacc.c:1258  */
        break;

    case 213: /* getenv  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2429 "parser.c" /* yacc.c:1258  */
        break;

    case 214: /* getsize  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2435 "parser.c" /* yacc.c:1258  */
        break;

    case 215: /* getsum  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2441 "parser.c" /* yacc.c:1258  */
        break;

    case 216: /* getversion  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2447 "parser.c" /* yacc.c:1258  */
        break;

    case 217: /* iconinfo  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2453 "parser.c" /* yacc.c:1258  */
        break;

    case 218: /* dcl  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2459 "parser.c" /* yacc.c:1258  */
        break;

    case 219: /* cus  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2465 "parser.c" /* yacc.c:1258  */
        break;

    case 220: /* askbool  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2471 "parser.c" /* yacc.c:1258  */
        break;

    case 221: /* askchoice  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2477 "parser.c" /* yacc.c:1258  */
        break;

    case 222: /* askdir  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2483 "parser.c" /* yacc.c:1258  */
        break;

    case 223: /* askdisk  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2489 "parser.c" /* yacc.c:1258  */
        break;

    case 224: /* askfile  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2495 "parser.c" /* yacc.c:1258  */
        break;

    case 225: /* asknumber  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2501 "parser.c" /* yacc.c:1258  */
        break;

    case 226: /* askoptions  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2507 "parser.c" /* yacc.c:1258  */
        break;

    case 227: /* askstring  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2513 "parser.c" /* yacc.c:1258  */
        break;

    case 228: /* cat  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2519 "parser.c" /* yacc.c:1258  */
        break;

    case 229: /* expandpath  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2525 "parser.c" /* yacc.c:1258  */
        break;

    case 230: /* fmt  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2531 "parser.c" /* yacc.c:1258  */
        break;

    case 231: /* pathonly  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2537 "parser.c" /* yacc.c:1258  */
        break;

    case 232: /* patmatch  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2543 "parser.c" /* yacc.c:1258  */
        break;

    case 233: /* strlen  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2549 "parser.c" /* yacc.c:1258  */
        break;

    case 234: /* substr  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2555 "parser.c" /* yacc.c:1258  */
        break;

    case 235: /* tackon  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2561 "parser.c" /* yacc.c:1258  */
        break;

    case 236: /* set  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2567 "parser.c" /* yacc.c:1258  */
        break;

    case 237: /* symbolset  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2573 "parser.c" /* yacc.c:1258  */
        break;

    case 238: /* symbolval  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2579 "parser.c" /* yacc.c:1258  */
        break;

    case 239: /* all  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2585 "parser.c" /* yacc.c:1258  */
        break;

    case 240: /* append  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2591 "parser.c" /* yacc.c:1258  */
        break;

    case 241: /* assigns  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2597 "parser.c" /* yacc.c:1258  */
        break;

    case 242: /* choices  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2603 "parser.c" /* yacc.c:1258  */
        break;

    case 243: /* command  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2609 "parser.c" /* yacc.c:1258  */
        break;

    case 244: /* compression  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2615 "parser.c" /* yacc.c:1258  */
        break;

    case 245: /* confirm  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2621 "parser.c" /* yacc.c:1258  */
        break;

    case 246: /* default  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2627 "parser.c" /* yacc.c:1258  */
        break;

    case 247: /* delopts  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2633 "parser.c" /* yacc.c:1258  */
        break;

    case 248: /* dest  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2639 "parser.c" /* yacc.c:1258  */
        break;

    case 249: /* disk  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2645 "parser.c" /* yacc.c:1258  */
        break;

    case 250: /* files  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2651 "parser.c" /* yacc.c:1258  */
        break;

    case 251: /* fonts  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2657 "parser.c" /* yacc.c:1258  */
        break;

    case 252: /* getdefaulttool  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2663 "parser.c" /* yacc.c:1258  */
        break;

    case 253: /* getposition  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2669 "parser.c" /* yacc.c:1258  */
        break;

    case 254: /* getstack  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2675 "parser.c" /* yacc.c:1258  */
        break;

    case 255: /* gettooltype  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2681 "parser.c" /* yacc.c:1258  */
        break;

    case 256: /* help  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2687 "parser.c" /* yacc.c:1258  */
        break;

    case 257: /* infos  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2693 "parser.c" /* yacc.c:1258  */
        break;

    case 258: /* include  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2699 "parser.c" /* yacc.c:1258  */
        break;

    case 259: /* newname  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2705 "parser.c" /* yacc.c:1258  */
        break;

    case 260: /* newpath  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2711 "parser.c" /* yacc.c:1258  */
        break;

    case 261: /* nogauge  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2717 "parser.c" /* yacc.c:1258  */
        break;

    case 262: /* noposition  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2723 "parser.c" /* yacc.c:1258  */
        break;

    case 263: /* noreq  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2729 "parser.c" /* yacc.c:1258  */
        break;

    case 264: /* pattern  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2735 "parser.c" /* yacc.c:1258  */
        break;

    case 265: /* prompt  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2741 "parser.c" /* yacc.c:1258  */
        break;

    case 266: /* quiet  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2747 "parser.c" /* yacc.c:1258  */
        break;

    case 267: /* range  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2753 "parser.c" /* yacc.c:1258  */
        break;

    case 268: /* safe  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2759 "parser.c" /* yacc.c:1258  */
        break;

    case 269: /* setdefaulttool  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2765 "parser.c" /* yacc.c:1258  */
        break;

    case 270: /* setposition  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2771 "parser.c" /* yacc.c:1258  */
        break;

    case 271: /* setstack  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2777 "parser.c" /* yacc.c:1258  */
        break;

    case 272: /* settooltype  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2783 "parser.c" /* yacc.c:1258  */
        break;

    case 273: /* source  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2789 "parser.c" /* yacc.c:1258  */
        break;

    case 274: /* swapcolors  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2795 "parser.c" /* yacc.c:1258  */
        break;

    case 275: /* optional  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2801 "parser.c" /* yacc.c:1258  */
        break;

    case 276: /* resident  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2807 "parser.c" /* yacc.c:1258  */
        break;

    case 277: /* override  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2813 "parser.c" /* yacc.c:1258  */
        break;

    case 278: /* dynopt  */
#line 78 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2819 "parser.c" /* yacc.c:1258  */
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
#line 93 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = init((yyvsp[0].e)); }
#line 3087 "parser.c" /* yacc.c:1651  */
    break;

  case 6:
#line 99 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3093 "parser.c" /* yacc.c:1651  */
    break;

  case 7:
#line 100 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3099 "parser.c" /* yacc.c:1651  */
    break;

  case 8:
#line 101 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3105 "parser.c" /* yacc.c:1651  */
    break;

  case 9:
#line 102 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push((yyvsp[-2].e), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3111 "parser.c" /* yacc.c:1651  */
    break;

  case 12:
#line 105 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3117 "parser.c" /* yacc.c:1651  */
    break;

  case 13:
#line 106 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3123 "parser.c" /* yacc.c:1651  */
    break;

  case 14:
#line 107 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3129 "parser.c" /* yacc.c:1651  */
    break;

  case 15:
#line 108 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3135 "parser.c" /* yacc.c:1651  */
    break;

  case 16:
#line 109 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3141 "parser.c" /* yacc.c:1651  */
    break;

  case 17:
#line 110 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3147 "parser.c" /* yacc.c:1651  */
    break;

  case 18:
#line 111 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3153 "parser.c" /* yacc.c:1651  */
    break;

  case 19:
#line 112 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3159 "parser.c" /* yacc.c:1651  */
    break;

  case 20:
#line 113 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push((yyvsp[-2].e), (yyvsp[-1].e)); }
#line 3165 "parser.c" /* yacc.c:1651  */
    break;

  case 21:
#line 114 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3171 "parser.c" /* yacc.c:1651  */
    break;

  case 22:
#line 115 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3177 "parser.c" /* yacc.c:1651  */
    break;

  case 23:
#line 116 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3183 "parser.c" /* yacc.c:1651  */
    break;

  case 24:
#line 117 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3189 "parser.c" /* yacc.c:1651  */
    break;

  case 25:
#line 118 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3195 "parser.c" /* yacc.c:1651  */
    break;

  case 26:
#line 119 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3201 "parser.c" /* yacc.c:1651  */
    break;

  case 27:
#line 120 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_string((yyvsp[0].s)); }
#line 3207 "parser.c" /* yacc.c:1651  */
    break;

  case 28:
#line 121 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_symref((yyvsp[0].s), LINE); }
#line 3213 "parser.c" /* yacc.c:1651  */
    break;

  case 29:
#line 122 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push((yyvsp[-2].e), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)) ; }
#line 3219 "parser.c" /* yacc.c:1651  */
    break;

  case 30:
#line 123 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push(new_contxt(), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)); }
#line 3225 "parser.c" /* yacc.c:1651  */
    break;

  case 31:
#line 124 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push((yyvsp[-1].e), new_symbol((yyvsp[0].s))); }
#line 3231 "parser.c" /* yacc.c:1651  */
    break;

  case 32:
#line 125 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), new_symbol((yyvsp[0].s))); }
#line 3237 "parser.c" /* yacc.c:1651  */
    break;

  case 33:
#line 126 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3243 "parser.c" /* yacc.c:1651  */
    break;

  case 34:
#line 127 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3249 "parser.c" /* yacc.c:1651  */
    break;

  case 159:
#line 258 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("+"), LINE, m_add, (yyvsp[-1].e), NUMBER); }
#line 3255 "parser.c" /* yacc.c:1651  */
    break;

  case 160:
#line 259 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("/"), LINE, m_div, (yyvsp[-1].e), NUMBER); }
#line 3261 "parser.c" /* yacc.c:1651  */
    break;

  case 161:
#line 260 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("*"), LINE, m_mul, (yyvsp[-1].e), NUMBER); }
#line 3267 "parser.c" /* yacc.c:1651  */
    break;

  case 162:
#line 261 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("-"), LINE, m_sub, (yyvsp[-1].e), NUMBER); }
#line 3273 "parser.c" /* yacc.c:1651  */
    break;

  case 163:
#line 264 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("AND"), LINE, m_and, (yyvsp[-1].e), NUMBER); }
#line 3279 "parser.c" /* yacc.c:1651  */
    break;

  case 164:
#line 265 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("BITAND"), LINE, m_bitand, (yyvsp[-1].e), NUMBER); }
#line 3285 "parser.c" /* yacc.c:1651  */
    break;

  case 165:
#line 266 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("BITNOT"), LINE, m_bitnot, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3291 "parser.c" /* yacc.c:1651  */
    break;

  case 166:
#line 267 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("BITOR"), LINE, m_bitor, (yyvsp[-1].e), NUMBER); }
#line 3297 "parser.c" /* yacc.c:1651  */
    break;

  case 167:
#line 268 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("BITXOR"), LINE, m_bitxor, (yyvsp[-1].e), NUMBER); }
#line 3303 "parser.c" /* yacc.c:1651  */
    break;

  case 168:
#line 269 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("NOT"), LINE, m_not, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3309 "parser.c" /* yacc.c:1651  */
    break;

  case 169:
#line 270 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("IN"), LINE, m_in, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3315 "parser.c" /* yacc.c:1651  */
    break;

  case 170:
#line 271 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("OR"), LINE, m_or, (yyvsp[-1].e), NUMBER); }
#line 3321 "parser.c" /* yacc.c:1651  */
    break;

  case 171:
#line 272 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("shiftleft"), LINE, m_shiftleft, (yyvsp[-1].e), NUMBER); }
#line 3327 "parser.c" /* yacc.c:1651  */
    break;

  case 172:
#line 273 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("shiftright"), LINE, m_shiftright, (yyvsp[-1].e), NUMBER); }
#line 3333 "parser.c" /* yacc.c:1651  */
    break;

  case 173:
#line 274 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("XOR"), LINE, m_xor, (yyvsp[-1].e), NUMBER); }
#line 3339 "parser.c" /* yacc.c:1651  */
    break;

  case 174:
#line 277 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("="), LINE, m_eq, (yyvsp[-1].e), NUMBER); }
#line 3345 "parser.c" /* yacc.c:1651  */
    break;

  case 175:
#line 278 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup(">"), LINE, m_gt, (yyvsp[-1].e), NUMBER); }
#line 3351 "parser.c" /* yacc.c:1651  */
    break;

  case 176:
#line 279 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup(">="), LINE, m_gte, (yyvsp[-1].e), NUMBER); }
#line 3357 "parser.c" /* yacc.c:1651  */
    break;

  case 177:
#line 280 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("<"), LINE, m_lt, (yyvsp[-1].e), NUMBER); }
#line 3363 "parser.c" /* yacc.c:1651  */
    break;

  case 178:
#line 281 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("<="), LINE, m_lte, (yyvsp[-1].e), NUMBER); }
#line 3369 "parser.c" /* yacc.c:1651  */
    break;

  case 179:
#line 282 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("<>"), LINE, m_neq, (yyvsp[-1].e), NUMBER); }
#line 3375 "parser.c" /* yacc.c:1651  */
    break;

  case 180:
#line 285 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3381 "parser.c" /* yacc.c:1651  */
    break;

  case 181:
#line 286 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3387 "parser.c" /* yacc.c:1651  */
    break;

  case 182:
#line 287 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3393 "parser.c" /* yacc.c:1651  */
    break;

  case 183:
#line 288 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("select"), LINE, m_select, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3399 "parser.c" /* yacc.c:1651  */
    break;

  case 184:
#line 289 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("until"), LINE, m_until, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3405 "parser.c" /* yacc.c:1651  */
    break;

  case 185:
#line 290 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("while"), LINE, m_while, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3411 "parser.c" /* yacc.c:1651  */
    break;

  case 186:
#line 293 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3417 "parser.c" /* yacc.c:1651  */
    break;

  case 187:
#line 294 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3423 "parser.c" /* yacc.c:1651  */
    break;

  case 188:
#line 295 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3429 "parser.c" /* yacc.c:1651  */
    break;

  case 189:
#line 296 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, (yyvsp[-1].e), NUMBER); }
#line 3435 "parser.c" /* yacc.c:1651  */
    break;

  case 190:
#line 297 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3441 "parser.c" /* yacc.c:1651  */
    break;

  case 191:
#line 298 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3447 "parser.c" /* yacc.c:1651  */
    break;

  case 192:
#line 299 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3453 "parser.c" /* yacc.c:1651  */
    break;

  case 193:
#line 300 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, (yyvsp[-1].e), NUMBER); }
#line 3459 "parser.c" /* yacc.c:1651  */
    break;

  case 194:
#line 301 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3465 "parser.c" /* yacc.c:1651  */
    break;

  case 195:
#line 302 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3471 "parser.c" /* yacc.c:1651  */
    break;

  case 196:
#line 303 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3477 "parser.c" /* yacc.c:1651  */
    break;

  case 197:
#line 304 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, (yyvsp[-1].e), NUMBER); }
#line 3483 "parser.c" /* yacc.c:1651  */
    break;

  case 198:
#line 307 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("abort"), LINE, m_abort, (yyvsp[-1].e), NUMBER); }
#line 3489 "parser.c" /* yacc.c:1651  */
    break;

  case 199:
#line 308 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3495 "parser.c" /* yacc.c:1651  */
    break;

  case 200:
#line 309 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3501 "parser.c" /* yacc.c:1651  */
    break;

  case 201:
#line 310 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3507 "parser.c" /* yacc.c:1651  */
    break;

  case 202:
#line 311 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, (yyvsp[-1].e), NUMBER); }
#line 3513 "parser.c" /* yacc.c:1651  */
    break;

  case 203:
#line 312 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, NULL, NUMBER); }
#line 3519 "parser.c" /* yacc.c:1651  */
    break;

  case 204:
#line 313 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("onerror"), LINE, m_procedure, push(new_contxt(),
                                                       new_custom(strdup("@onerror"), LINE, NULL, (yyvsp[-1].e))), DANGLE); }
#line 3526 "parser.c" /* yacc.c:1651  */
    break;

  case 205:
#line 315 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("trap"), LINE, m_trap, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3532 "parser.c" /* yacc.c:1651  */
    break;

  case 206:
#line 316 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("reboot"), LINE, m_reboot, NULL, NUMBER); }
#line 3538 "parser.c" /* yacc.c:1651  */
    break;

  case 207:
#line 319 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("copyfiles"), LINE, m_copyfiles, (yyvsp[-1].e), NUMBER); }
#line 3544 "parser.c" /* yacc.c:1651  */
    break;

  case 208:
#line 320 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("copylib"), LINE, m_copylib, (yyvsp[-1].e), NUMBER); }
#line 3550 "parser.c" /* yacc.c:1651  */
    break;

  case 209:
#line 321 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3556 "parser.c" /* yacc.c:1651  */
    break;

  case 210:
#line 322 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3562 "parser.c" /* yacc.c:1651  */
    break;

  case 211:
#line 323 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3568 "parser.c" /* yacc.c:1651  */
    break;

  case 212:
#line 324 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3574 "parser.c" /* yacc.c:1651  */
    break;

  case 213:
#line 325 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3580 "parser.c" /* yacc.c:1651  */
    break;

  case 214:
#line 326 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3586 "parser.c" /* yacc.c:1651  */
    break;

  case 215:
#line 327 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("fileonly"), LINE, m_fileonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3592 "parser.c" /* yacc.c:1651  */
    break;

  case 216:
#line 328 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("foreach"), LINE, m_foreach, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3598 "parser.c" /* yacc.c:1651  */
    break;

  case 217:
#line 329 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3604 "parser.c" /* yacc.c:1651  */
    break;

  case 218:
#line 330 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, (yyvsp[-1].e), NUMBER); }
#line 3610 "parser.c" /* yacc.c:1651  */
    break;

  case 219:
#line 331 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3616 "parser.c" /* yacc.c:1651  */
    break;

  case 220:
#line 332 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3622 "parser.c" /* yacc.c:1651  */
    break;

  case 221:
#line 333 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3628 "parser.c" /* yacc.c:1651  */
    break;

  case 222:
#line 334 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3634 "parser.c" /* yacc.c:1651  */
    break;

  case 223:
#line 335 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3640 "parser.c" /* yacc.c:1651  */
    break;

  case 224:
#line 336 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3646 "parser.c" /* yacc.c:1651  */
    break;

  case 225:
#line 337 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3652 "parser.c" /* yacc.c:1651  */
    break;

  case 226:
#line 338 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, (yyvsp[-1].e), NUMBER); }
#line 3658 "parser.c" /* yacc.c:1651  */
    break;

  case 227:
#line 339 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3664 "parser.c" /* yacc.c:1651  */
    break;

  case 228:
#line 340 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3670 "parser.c" /* yacc.c:1651  */
    break;

  case 229:
#line 341 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3676 "parser.c" /* yacc.c:1651  */
    break;

  case 230:
#line 342 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3682 "parser.c" /* yacc.c:1651  */
    break;

  case 231:
#line 343 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3688 "parser.c" /* yacc.c:1651  */
    break;

  case 232:
#line 344 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), new_symref(strdup("@app-name"), LINE)), (yyvsp[-1].e)), NUMBER); }
#line 3694 "parser.c" /* yacc.c:1651  */
    break;

  case 233:
#line 345 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("textfile"), LINE, m_textfile, (yyvsp[-1].e), NUMBER); }
#line 3700 "parser.c" /* yacc.c:1651  */
    break;

  case 234:
#line 346 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("tooltype"), LINE, m_tooltype, (yyvsp[-1].e), NUMBER); }
#line 3706 "parser.c" /* yacc.c:1651  */
    break;

  case 235:
#line 347 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("transcript"), LINE, m_transcript, (yyvsp[-1].e), NUMBER); }
#line 3712 "parser.c" /* yacc.c:1651  */
    break;

  case 236:
#line 348 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3718 "parser.c" /* yacc.c:1651  */
    break;

  case 237:
#line 349 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, (yyvsp[-1].e), NUMBER); }
#line 3724 "parser.c" /* yacc.c:1651  */
    break;

  case 238:
#line 352 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("complete"), LINE, m_complete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3730 "parser.c" /* yacc.c:1651  */
    break;

  case 239:
#line 353 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, (yyvsp[-1].e), NUMBER); }
#line 3736 "parser.c" /* yacc.c:1651  */
    break;

  case 240:
#line 354 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, NULL, NUMBER); }
#line 3742 "parser.c" /* yacc.c:1651  */
    break;

  case 241:
#line 355 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3748 "parser.c" /* yacc.c:1651  */
    break;

  case 242:
#line 356 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, (yyvsp[-1].e), NUMBER); }
#line 3754 "parser.c" /* yacc.c:1651  */
    break;

  case 243:
#line 357 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("user"), LINE, m_user, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3760 "parser.c" /* yacc.c:1651  */
    break;

  case 244:
#line 358 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, (yyvsp[-1].e), NUMBER); }
#line 3766 "parser.c" /* yacc.c:1651  */
    break;

  case 245:
#line 359 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, NULL, NUMBER); }
#line 3772 "parser.c" /* yacc.c:1651  */
    break;

  case 246:
#line 360 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("working"), LINE, m_working, (yyvsp[-1].e), NUMBER); }
#line 3778 "parser.c" /* yacc.c:1651  */
    break;

  case 247:
#line 363 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3784 "parser.c" /* yacc.c:1651  */
    break;

  case 248:
#line 364 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, (yyvsp[-1].e), STRING); }
#line 3790 "parser.c" /* yacc.c:1651  */
    break;

  case 249:
#line 365 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("earlier"), LINE, m_earlier, (yyvsp[-1].e), NUMBER); }
#line 3796 "parser.c" /* yacc.c:1651  */
    break;

  case 250:
#line 366 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3802 "parser.c" /* yacc.c:1651  */
    break;

  case 251:
#line 367 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, (yyvsp[-1].e), STRING); }
#line 3808 "parser.c" /* yacc.c:1651  */
    break;

  case 252:
#line 368 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getdevice"), LINE, m_getdevice, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3814 "parser.c" /* yacc.c:1651  */
    break;

  case 253:
#line 369 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3820 "parser.c" /* yacc.c:1651  */
    break;

  case 254:
#line 370 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, (yyvsp[-1].e), NUMBER); }
#line 3826 "parser.c" /* yacc.c:1651  */
    break;

  case 255:
#line 371 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getenv"), LINE, m_getenv, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3832 "parser.c" /* yacc.c:1651  */
    break;

  case 256:
#line 372 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getsize"), LINE, m_getsize, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3838 "parser.c" /* yacc.c:1651  */
    break;

  case 257:
#line 373 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getsum"), LINE, m_getsum, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3844 "parser.c" /* yacc.c:1651  */
    break;

  case 258:
#line 374 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, NULL, NUMBER); }
#line 3850 "parser.c" /* yacc.c:1651  */
    break;

  case 259:
#line 375 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3856 "parser.c" /* yacc.c:1651  */
    break;

  case 260:
#line 376 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3862 "parser.c" /* yacc.c:1651  */
    break;

  case 261:
#line 377 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("iconinfo"), LINE, m_iconinfo, (yyvsp[-1].e), NUMBER); }
#line 3868 "parser.c" /* yacc.c:1651  */
    break;

  case 262:
#line 380 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-3].s), LINE, (yyvsp[-2].e), (yyvsp[-1].e))), NUMBER); }
#line 3874 "parser.c" /* yacc.c:1651  */
    break;

  case 263:
#line 381 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, (yyvsp[-1].e), NULL)), NUMBER); }
#line 3880 "parser.c" /* yacc.c:1651  */
    break;

  case 264:
#line 382 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, NULL, (yyvsp[-1].e))), NUMBER); }
#line 3886 "parser.c" /* yacc.c:1651  */
    break;

  case 265:
#line 383 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-1].s), LINE, NULL, NULL)), NUMBER); }
#line 3892 "parser.c" /* yacc.c:1651  */
    break;

  case 266:
#line 384 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_cusref((yyvsp[-2].s), LINE, (yyvsp[-1].e)); }
#line 3898 "parser.c" /* yacc.c:1651  */
    break;

  case 267:
#line 385 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_cusref((yyvsp[-1].s), LINE, NULL); }
#line 3904 "parser.c" /* yacc.c:1651  */
    break;

  case 268:
#line 388 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, NULL, NUMBER); }
#line 3910 "parser.c" /* yacc.c:1651  */
    break;

  case 269:
#line 389 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, (yyvsp[-1].e), NUMBER); }
#line 3916 "parser.c" /* yacc.c:1651  */
    break;

  case 270:
#line 390 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askchoice"), LINE, m_askchoice, (yyvsp[-1].e), NUMBER); }
#line 3922 "parser.c" /* yacc.c:1651  */
    break;

  case 271:
#line 391 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, NULL, STRING); }
#line 3928 "parser.c" /* yacc.c:1651  */
    break;

  case 272:
#line 392 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, (yyvsp[-1].e), STRING); }
#line 3934 "parser.c" /* yacc.c:1651  */
    break;

  case 273:
#line 393 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askdisk"), LINE, m_askdisk, (yyvsp[-1].e), NUMBER); }
#line 3940 "parser.c" /* yacc.c:1651  */
    break;

  case 274:
#line 394 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, NULL, STRING); }
#line 3946 "parser.c" /* yacc.c:1651  */
    break;

  case 275:
#line 395 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, (yyvsp[-1].e), STRING); }
#line 3952 "parser.c" /* yacc.c:1651  */
    break;

  case 276:
#line 396 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, NULL, NUMBER); }
#line 3958 "parser.c" /* yacc.c:1651  */
    break;

  case 277:
#line 397 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, (yyvsp[-1].e), NUMBER); }
#line 3964 "parser.c" /* yacc.c:1651  */
    break;

  case 278:
#line 398 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askoptions"), LINE, m_askoptions, (yyvsp[-1].e), NUMBER); }
#line 3970 "parser.c" /* yacc.c:1651  */
    break;

  case 279:
#line 399 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, NULL, STRING); }
#line 3976 "parser.c" /* yacc.c:1651  */
    break;

  case 280:
#line 400 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, (yyvsp[-1].e), STRING); }
#line 3982 "parser.c" /* yacc.c:1651  */
    break;

  case 281:
#line 403 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("cat"), LINE, m_cat, (yyvsp[-1].e), STRING); }
#line 3988 "parser.c" /* yacc.c:1651  */
    break;

  case 282:
#line 404 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("expandpath"), LINE, m_expandpath, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3994 "parser.c" /* yacc.c:1651  */
    break;

  case 283:
#line 405 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native((yyvsp[-2].s), LINE, m_fmt, (yyvsp[-1].e), STRING); }
#line 4000 "parser.c" /* yacc.c:1651  */
    break;

  case 284:
#line 406 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native((yyvsp[-1].s), LINE, m_fmt, NULL, STRING); }
#line 4006 "parser.c" /* yacc.c:1651  */
    break;

  case 285:
#line 407 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("pathonly"), LINE, m_pathonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4012 "parser.c" /* yacc.c:1651  */
    break;

  case 286:
#line 408 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("patmatch"), LINE, m_patmatch, (yyvsp[-1].e), NUMBER); }
#line 4018 "parser.c" /* yacc.c:1651  */
    break;

  case 287:
#line 409 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("strlen"), LINE, m_strlen, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4024 "parser.c" /* yacc.c:1651  */
    break;

  case 288:
#line 410 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, (yyvsp[-1].e), STRING); }
#line 4030 "parser.c" /* yacc.c:1651  */
    break;

  case 289:
#line 411 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, push((yyvsp[-2].e), (yyvsp[-1].e)), STRING); }
#line 4036 "parser.c" /* yacc.c:1651  */
    break;

  case 290:
#line 412 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("tackon"), LINE, m_tackon, (yyvsp[-1].e), STRING); }
#line 4042 "parser.c" /* yacc.c:1651  */
    break;

  case 291:
#line 415 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("set"), LINE, m_set, (yyvsp[-1].e), DANGLE); }
#line 4048 "parser.c" /* yacc.c:1651  */
    break;

  case 292:
#line 416 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("symbolset"), LINE, m_symbolset, (yyvsp[-1].e), DANGLE); }
#line 4054 "parser.c" /* yacc.c:1651  */
    break;

  case 293:
#line 417 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("symbolval"), LINE, m_symbolval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4060 "parser.c" /* yacc.c:1651  */
    break;

  case 294:
#line 420 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("all"), OPT_ALL, NULL); }
#line 4066 "parser.c" /* yacc.c:1651  */
    break;

  case 295:
#line 421 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("append"), OPT_APPEND, (yyvsp[-1].e)); }
#line 4072 "parser.c" /* yacc.c:1651  */
    break;

  case 296:
#line 422 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); }
#line 4078 "parser.c" /* yacc.c:1651  */
    break;

  case 297:
#line 423 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("choices"), OPT_CHOICES, (yyvsp[-1].e)); }
#line 4084 "parser.c" /* yacc.c:1651  */
    break;

  case 298:
#line 424 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("command"), OPT_COMMAND, (yyvsp[-1].e)); }
#line 4090 "parser.c" /* yacc.c:1651  */
    break;

  case 299:
#line 425 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("compression"), OPT_COMPRESSION, NULL); }
#line 4096 "parser.c" /* yacc.c:1651  */
    break;

  case 300:
#line 426 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, push(new_contxt(), (yyvsp[-1].e))); }
#line 4102 "parser.c" /* yacc.c:1651  */
    break;

  case 301:
#line 427 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, NULL); }
#line 4108 "parser.c" /* yacc.c:1651  */
    break;

  case 302:
#line 428 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), (yyvsp[-1].e))); }
#line 4114 "parser.c" /* yacc.c:1651  */
    break;

  case 303:
#line 429 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, (yyvsp[-1].e)); }
#line 4120 "parser.c" /* yacc.c:1651  */
    break;

  case 304:
#line 430 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), (yyvsp[-1].e))); }
#line 4126 "parser.c" /* yacc.c:1651  */
    break;

  case 305:
#line 431 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("disk"), OPT_DISK, NULL); }
#line 4132 "parser.c" /* yacc.c:1651  */
    break;

  case 306:
#line 432 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("files"), OPT_FILES, NULL); }
#line 4138 "parser.c" /* yacc.c:1651  */
    break;

  case 307:
#line 433 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("fonts"), OPT_FONTS, NULL); }
#line 4144 "parser.c" /* yacc.c:1651  */
    break;

  case 308:
#line 434 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4150 "parser.c" /* yacc.c:1651  */
    break;

  case 309:
#line 435 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("getposition"), OPT_GETPOSITION, (yyvsp[-1].e)); }
#line 4156 "parser.c" /* yacc.c:1651  */
    break;

  case 310:
#line 436 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4162 "parser.c" /* yacc.c:1651  */
    break;

  case 311:
#line 437 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, (yyvsp[-1].e)); }
#line 4168 "parser.c" /* yacc.c:1651  */
    break;

  case 312:
#line 438 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, (yyvsp[-1].e)); }
#line 4174 "parser.c" /* yacc.c:1651  */
    break;

  case 313:
#line 439 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4180 "parser.c" /* yacc.c:1651  */
    break;

  case 314:
#line 440 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("infos"), OPT_INFOS, NULL); }
#line 4186 "parser.c" /* yacc.c:1651  */
    break;

  case 315:
#line 441 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4192 "parser.c" /* yacc.c:1651  */
    break;

  case 316:
#line 442 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), (yyvsp[-1].e))); }
#line 4198 "parser.c" /* yacc.c:1651  */
    break;

  case 317:
#line 443 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("newpath"), OPT_NEWPATH, NULL); }
#line 4204 "parser.c" /* yacc.c:1651  */
    break;

  case 318:
#line 444 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); }
#line 4210 "parser.c" /* yacc.c:1651  */
    break;

  case 319:
#line 445 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); }
#line 4216 "parser.c" /* yacc.c:1651  */
    break;

  case 320:
#line 446 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("noreq"), OPT_NOREQ, NULL); }
#line 4222 "parser.c" /* yacc.c:1651  */
    break;

  case 321:
#line 447 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), (yyvsp[-1].e))); }
#line 4228 "parser.c" /* yacc.c:1651  */
    break;

  case 322:
#line 448 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("prompt"), OPT_PROMPT, (yyvsp[-1].e)); }
#line 4234 "parser.c" /* yacc.c:1651  */
    break;

  case 323:
#line 449 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("quiet"), OPT_QUIET, NULL); }
#line 4240 "parser.c" /* yacc.c:1651  */
    break;

  case 324:
#line 450 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("range"), OPT_RANGE, (yyvsp[-1].e)); }
#line 4246 "parser.c" /* yacc.c:1651  */
    break;

  case 325:
#line 451 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("safe"), OPT_SAFE, NULL); }
#line 4252 "parser.c" /* yacc.c:1651  */
    break;

  case 326:
#line 452 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4258 "parser.c" /* yacc.c:1651  */
    break;

  case 327:
#line 453 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("setposition"), OPT_SETPOSITION, (yyvsp[-1].e)); }
#line 4264 "parser.c" /* yacc.c:1651  */
    break;

  case 328:
#line 454 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4270 "parser.c" /* yacc.c:1651  */
    break;

  case 329:
#line 455 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, (yyvsp[-1].e)); }
#line 4276 "parser.c" /* yacc.c:1651  */
    break;

  case 330:
#line 456 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4282 "parser.c" /* yacc.c:1651  */
    break;

  case 331:
#line 457 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4288 "parser.c" /* yacc.c:1651  */
    break;

  case 332:
#line 458 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); }
#line 4294 "parser.c" /* yacc.c:1651  */
    break;

  case 333:
#line 459 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, (yyvsp[-1].e)); }
#line 4300 "parser.c" /* yacc.c:1651  */
    break;

  case 334:
#line 460 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("resident"), OPT_RESIDENT, NULL); }
#line 4306 "parser.c" /* yacc.c:1651  */
    break;

  case 335:
#line 461 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4312 "parser.c" /* yacc.c:1651  */
    break;

  case 336:
#line 462 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(push(new_contxt(), (yyvsp[-3].e)), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4318 "parser.c" /* yacc.c:1651  */
    break;


#line 4322 "parser.c" /* yacc.c:1651  */
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
#line 464 "../src/parser.y" /* yacc.c:1910  */


