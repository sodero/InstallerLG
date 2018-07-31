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
    COPYFILES = 291,
    COPYLIB = 292,
    DELETE = 293,
    EXISTS = 294,
    FILEONLY = 295,
    FOREACH = 296,
    MAKEASSIGN = 297,
    MAKEDIR = 298,
    PROTECT = 299,
    STARTUP = 300,
    TEXTFILE = 301,
    TOOLTYPE = 302,
    TRANSCRIPT = 303,
    RENAME = 304,
    COMPLETE = 305,
    DEBUG = 306,
    MESSAGE = 307,
    USER = 308,
    WELCOME = 309,
    WORKING = 310,
    DATABASE = 311,
    EARLIER = 312,
    GETASSIGN = 313,
    GETDEVICE = 314,
    GETDISKSPACE = 315,
    GETENV = 316,
    GETSIZE = 317,
    GETSUM = 318,
    GETVERSION = 319,
    ICONINFO = 320,
    CUS = 321,
    DCL = 322,
    ASKBOOL = 323,
    ASKCHOICE = 324,
    ASKDIR = 325,
    ASKDISK = 326,
    ASKFILE = 327,
    ASKNUMBER = 328,
    ASKOPTIONS = 329,
    ASKSTRING = 330,
    CAT = 331,
    EXPANDPATH = 332,
    FMT = 333,
    PATHONLY = 334,
    PATMATCH = 335,
    STRLEN = 336,
    SUBSTR = 337,
    TACKON = 338,
    SET = 339,
    SYMBOLSET = 340,
    SYMBOLVAL = 341,
    ALL = 342,
    APPEND = 343,
    ASSIGNS = 344,
    CHOICES = 345,
    COMMAND = 346,
    COMPRESSION = 347,
    CONFIRM = 348,
    DEFAULT = 349,
    DELOPTS = 350,
    DEST = 351,
    DISK = 352,
    FILES = 353,
    FONTS = 354,
    GETDEFAULTTOOL = 355,
    GETPOSITION = 356,
    GETSTACK = 357,
    GETTOOLTYPE = 358,
    HELP = 359,
    INFOS = 360,
    INCLUDE = 361,
    NEWNAME = 362,
    NEWPATH = 363,
    NOGAUGE = 364,
    NOPOSITION = 365,
    NOREQ = 366,
    PATTERN = 367,
    PROMPT = 368,
    QUIET = 369,
    RANGE = 370,
    SAFE = 371,
    SETDEFAULTTOOL = 372,
    SETPOSITION = 373,
    SETSTACK = 374,
    SETTOOLTYPE = 375,
    SOURCE = 376,
    SWAPCOLORS = 377,
    OPTIONAL = 378,
    RESIDENT = 379,
    OVERRIDE = 380
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
#define COPYFILES 291
#define COPYLIB 292
#define DELETE 293
#define EXISTS 294
#define FILEONLY 295
#define FOREACH 296
#define MAKEASSIGN 297
#define MAKEDIR 298
#define PROTECT 299
#define STARTUP 300
#define TEXTFILE 301
#define TOOLTYPE 302
#define TRANSCRIPT 303
#define RENAME 304
#define COMPLETE 305
#define DEBUG 306
#define MESSAGE 307
#define USER 308
#define WELCOME 309
#define WORKING 310
#define DATABASE 311
#define EARLIER 312
#define GETASSIGN 313
#define GETDEVICE 314
#define GETDISKSPACE 315
#define GETENV 316
#define GETSIZE 317
#define GETSUM 318
#define GETVERSION 319
#define ICONINFO 320
#define CUS 321
#define DCL 322
#define ASKBOOL 323
#define ASKCHOICE 324
#define ASKDIR 325
#define ASKDISK 326
#define ASKFILE 327
#define ASKNUMBER 328
#define ASKOPTIONS 329
#define ASKSTRING 330
#define CAT 331
#define EXPANDPATH 332
#define FMT 333
#define PATHONLY 334
#define PATMATCH 335
#define STRLEN 336
#define SUBSTR 337
#define TACKON 338
#define SET 339
#define SYMBOLSET 340
#define SYMBOLVAL 341
#define ALL 342
#define APPEND 343
#define ASSIGNS 344
#define CHOICES 345
#define COMMAND 346
#define COMPRESSION 347
#define CONFIRM 348
#define DEFAULT 349
#define DELOPTS 350
#define DEST 351
#define DISK 352
#define FILES 353
#define FONTS 354
#define GETDEFAULTTOOL 355
#define GETPOSITION 356
#define GETSTACK 357
#define GETTOOLTYPE 358
#define HELP 359
#define INFOS 360
#define INCLUDE 361
#define NEWNAME 362
#define NEWPATH 363
#define NOGAUGE 364
#define NOPOSITION 365
#define NOREQ 366
#define PATTERN 367
#define PROMPT 368
#define QUIET 369
#define RANGE 370
#define SAFE 371
#define SETDEFAULTTOOL 372
#define SETPOSITION 373
#define SETSTACK 374
#define SETTOOLTYPE 375
#define SOURCE 376
#define SWAPCOLORS 377
#define OPTIONAL 378
#define RESIDENT 379
#define OVERRIDE 380

/* Value type.  */



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 380 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  175
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1938

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  135
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  143
/* YYNRULES -- Number of rules.  */
#define YYNRULES  330
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  639

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   380

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
     126,   127,   130,   128,     2,   131,     2,   129,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     134,   132,   133,     2,     2,     2,     2,     2,     2,     2,
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
     125
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
     247,   248,   249,   250,   251,   252,   253,   254,   257,   258,
     259,   260,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   276,   277,   278,   279,   280,   281,   284,
     285,   286,   287,   288,   289,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   306,   307,   308,
     309,   310,   311,   312,   314,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   349,   350,   351,   352,   353,
     354,   355,   356,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   375,   376,   377,
     378,   379,   380,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   410,   411,   412,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456
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
  "ONERROR", "TRAP", "COPYFILES", "COPYLIB", "DELETE", "EXISTS",
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
  "opts", "vpb", "xpb", "xpbs", "np", "sps", "par", "cv", "cvv", "opt",
  "ivp", "add", "div", "mul", "sub", "and", "bitand", "bitnot", "bitor",
  "bitxor", "not", "in", "or", "shiftleft", "shiftright", "xor", "eq",
  "gt", "gte", "lt", "lte", "neq", "if", "select", "until", "while",
  "execute", "rexx", "run", "abort", "exit", "onerror", "trap",
  "copyfiles", "copylib", "delete", "exists", "fileonly", "foreach",
  "makeassign", "makedir", "protect", "startup", "textfile", "tooltype",
  "transcript", "rename", "complete", "debug", "message", "user",
  "welcome", "working", "database", "earlier", "getassign", "getdevice",
  "getdiskspace", "getenv", "getsize", "getsum", "getversion", "iconinfo",
  "dcl", "cus", "askbool", "askchoice", "askdir", "askdisk", "askfile",
  "asknumber", "askoptions", "askstring", "cat", "expandpath", "fmt",
  "pathonly", "patmatch", "strlen", "substr", "tackon", "set", "symbolset",
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
     375,   376,   377,   378,   379,   380,    40,    41,    43,    47,
      42,    45,    61,    62,    60
};
# endif

#define YYPACT_NINF -305

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-305)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -114,  1628,    22,  -305,  -305,  -114,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
      31,    36,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
     190,   190,   190,    54,    59,  -114,    54,   -93,   -93,   190,
      54,    54,    54,    54,   190,    54,   190,   -93,   -93,    54,
      54,    54,    54,    54,    54,    64,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    75,   -93,    41,  -112,   -93,
     -98,   -93,   -96,   -71,   -93,   -54,    54,    54,    54,    54,
      54,    54,    54,    43,    54,    54,    54,    54,    54,    54,
      54,    54,    54,   -53,   -43,  -305,  -114,  -305,  -305,  -305,
    -305,  -305,  1760,  -305,  -305,    88,  -305,  -305,  -305,   100,
     116,    54,   -51,   -42,   -39,   -37,   -28,    54,   136,   -17,
     -13,     2,     5,     7,    19,   213,    26,    34,   218,  -114,
    -114,   968,   241,   190,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,   250,   190,   280,   190,   286,
    1232,  -305,   291,   323,   -29,  -114,  1813,   -18,   -14,   -10,
     190,    -1,    46,  -114,   331,    23,    25,   190,   376,    33,
     -93,   190,    40,    45,   426,    61,    56,   431,   541,    62,
    -305,   586,   608,   617,    65,    73,   674,   108,   124,   134,
     140,   143,   150,  -305,    72,    77,    18,  -305,    80,   102,
    -305,   104,   107,  -305,   111,  -305,   114,   123,  -305,   132,
     679,   152,   155,   185,   192,   711,   219,    54,    10,  -305,
     720,   225,   806,   227,   811,   229,   251,   257,   260,  -305,
    -305,   -53,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,   816,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    1628,  -305,  -305,  -305,   218,  -305,  -305,  -305,  -305,   821,
     148,   178,    54,   267,    54,   274,    54,    54,   284,   826,
      54,    54,    54,   289,   297,   298,    54,    54,    54,    54,
      54,   299,    54,    54,   300,   314,   315,   316,    54,    54,
     317,    54,   319,    54,    54,    54,    54,    54,   321,    54,
     324,    54,  -305,   181,   836,  -305,  -305,   184,   861,  -305,
     188,  1325,  -305,  -305,   326,  -305,  1330,  -305,   205,    54,
    -305,  -305,  -305,   216,   222,   343,  -305,   328,  -305,   224,
    1364,  -305,   329,   344,  -305,   332,  -305,   232,   235,  -305,
     239,  -305,   246,   248,   263,  -305,  -305,  -305,  -305,   266,
    -305,  -305,  1496,  -305,   334,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,   345,  -305,
     353,  -305,  -305,  -305,   354,    21,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
     355,  -305,  -305,    54,  -305,  -305,    54,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,   270,  -305,  -305,  -305,
    -305,  -305,  1335,  -305,  1344,  -305,  1349,  1460,  -305,  -305,
     356,   357,  1478,   360,  -305,  -305,  -305,   371,   372,   378,
     379,  1589,  -305,   390,   391,  -305,  -305,  -305,  -305,   392,
    1594,  -305,   393,  -305,   394,   396,   397,  1603,   398,   399,
    -305,  1608,  -305,   406,  -305,  -305,   273,  -305,  -305,   277,
    -305,  -305,   282,  -305,  -305,  -305,   -93,  -305,  -305,   288,
    -305,  -305,  -305,  -305,  -305,  -305,   293,  -305,  -305,  -305,
    -305,   295,  -305,  -305,  -305,  -305,  -305,  -305,   409,  -305,
    -305,  -305,  -305,  1100,   -93,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,   411,  -305
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
     128,   129,   130,   131,   132,   133,   134,   135,   136,   138,
     137,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     1,    13,    28,    27,    24,
      25,    26,     0,   262,     8,     0,     4,     5,   279,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    54,    53,    55,    56,    57,    58,    59,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    60,    74,    61,    73,     0,     0,     0,     0,     0,
       0,   202,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   253,     0,     0,     0,   263,     0,     0,
     266,     0,     0,   269,     0,   271,     0,     0,   274,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
      15,     0,   261,     7,   278,   162,     6,   163,   164,   165,
     166,   167,     0,   169,   170,   171,   172,   175,   177,   178,
       0,   181,    19,    20,    33,    21,   180,   179,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   188,     0,     0,    16,   192,     0,     0,   196,
       0,     0,   197,   201,     0,   200,     0,   203,     0,     0,
     205,   206,   210,     0,     0,     0,   211,     0,   213,     0,
       0,   218,     0,     0,   216,     0,   222,     0,     0,   226,
       0,   224,     0,     0,     0,   230,   231,   232,   234,     0,
     235,   236,     0,   238,     0,   239,   240,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,   254,
       0,   256,    32,   260,     0,     0,   264,   265,   267,   268,
     270,   272,   273,   275,   276,   277,   280,   281,   282,   283,
       0,   285,    30,     0,   286,   287,     0,   288,   158,   159,
     160,   161,   173,   174,   176,   168,     0,    34,   182,    23,
     183,   184,     0,   289,     0,   291,     0,     0,   294,   296,
       0,     0,     0,     0,   300,   301,   302,     0,     0,     0,
       0,     0,   308,     0,     0,   311,   312,   313,   314,     0,
       0,   317,     0,   319,     0,     0,     0,     0,     0,     0,
     326,     0,   328,     0,   185,   186,     0,   189,   190,     0,
     193,   194,     0,   198,   199,   204,     0,   207,   208,     0,
     212,   214,   217,   215,   219,   220,     0,   225,   223,   227,
     228,     0,   233,   237,   255,   259,    31,   258,     0,   284,
      29,     9,    18,     0,     0,   290,   292,   293,   295,   297,
     298,   299,   303,   304,   305,   306,   307,   309,   310,   315,
     316,   318,   320,   321,   322,   324,   323,   325,   327,   329,
     187,   191,   195,   209,   221,   229,   257,     0,   330
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -305,  -305,  -304,   370,   569,   189,  -305,     0,     3,  -101,
    -305,  -200,  -305,  -199,  -305,  -305,  -305,  -305,  -181,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,   209,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,   272,  -305,  -305,
    -107,  -305,  -255,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
     245,  -305,  -305
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   184,   192,   185,   330,   186,   176,   213,
     363,   364,   369,   187,   328,   485,   206,   207,   214,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
       4,   173,   484,     5,   174,     4,   365,   263,   368,   365,
     256,   258,     1,   503,   266,   307,   267,   268,   270,   442,
     445,   482,   175,   277,   596,   281,   282,   283,   266,   310,
     266,   313,   415,   266,   177,   178,   179,   180,   181,   177,
     178,   179,   180,   181,   306,   305,   327,   308,   309,   311,
     312,   314,   316,   317,   319,   266,   315,   177,   178,   179,
     180,   181,   177,   178,   179,   180,   181,   177,   178,   179,
     180,   181,   266,   318,   339,   415,   347,   415,   177,   178,
     179,   180,   181,     1,   340,   348,   415,   415,   349,   415,
     350,   177,   178,   179,   180,   181,   415,     1,   427,   351,
     415,   415,   415,   177,   178,   179,   180,   181,   266,   430,
     354,   413,   266,   431,   355,     4,   266,   432,   264,   177,
     178,   179,   180,   181,   415,   435,   436,   415,   415,   356,
     415,   415,   357,   415,   358,   415,   415,   504,   415,   177,
     178,   179,   180,   181,     1,   483,   359,     1,   597,   443,
     444,   266,   446,   366,   417,   424,   420,   182,   183,   266,
     451,   367,   182,   188,   517,   365,   266,   455,   433,   519,
     365,   266,   456,   438,     4,   447,     4,   450,   452,   453,
     182,   598,   341,   460,   459,   260,   261,   266,   458,   465,
     182,   290,   469,   177,   178,   179,   180,   181,   478,   479,
     470,   182,   303,   266,   481,   362,   266,   486,   362,     4,
       4,   341,   370,   371,   182,   342,   177,   178,   179,   180,
     181,   177,   178,   179,   180,   181,   182,   344,   266,   487,
     266,   488,   415,   266,   489,   472,   415,   266,   490,   415,
     266,   491,   182,   345,   177,   178,   179,   180,   181,   266,
     492,   473,   415,   177,   178,   179,   180,   181,   266,   493,
     341,   474,   182,   353,     4,     4,   415,   475,   428,   415,
     476,   415,   415,     4,     1,   520,   439,   477,   415,   495,
     189,   190,   496,   177,   178,   179,   180,   181,   198,   177,
     178,   179,   180,   181,   177,   178,   179,   180,   181,   212,
     255,   257,   259,   262,     1,   521,     4,   266,   564,     5,
     266,   567,   497,   566,   266,   570,   211,   569,   284,   498,
     572,   287,   288,   365,   291,   292,   177,   178,   179,   180,
     181,     1,   575,   579,   177,   178,   179,   180,   181,   360,
     361,   604,   266,   577,   360,   320,   501,   586,   266,   578,
       1,   581,   507,   591,   509,   332,   511,   334,   266,   584,
     173,   266,   585,   516,   362,   266,   587,   211,   412,   362,
       4,     4,   266,   588,   266,   589,   211,   416,   512,   177,
     178,   179,   180,   181,   513,   415,   352,   514,   415,   266,
     590,   415,   266,   592,   523,   604,     1,   602,   415,   266,
     630,   525,   414,   266,   631,   415,   211,   419,   266,   632,
     415,   528,   182,   422,   266,   633,   534,   260,   423,   266,
     634,   266,   635,   637,   535,   536,   542,   545,     4,   177,
     178,   179,   180,   181,   177,   178,   179,   180,   181,     4,
     341,   546,   547,   548,   551,   418,   553,   421,   560,   182,
     425,   562,   426,   573,   397,   580,   582,   440,   441,   583,
     402,   593,   341,   191,   193,   191,   191,   196,   197,   410,
     191,   191,   191,   191,   191,   191,   205,   208,   209,   210,
     594,   595,   599,   608,   609,     4,   265,   611,     5,   269,
     271,   272,   191,   274,   276,   278,   280,   464,   612,   613,
     191,   286,   211,   449,   289,   614,   615,   293,   191,   296,
     298,   299,   300,   301,   302,   304,     4,   617,   618,   619,
     621,   622,   362,   623,   624,   626,   627,   321,   322,   191,
     324,   191,   191,   629,   191,   331,   636,   191,   638,   191,
     191,   191,   191,   437,   177,   178,   179,   180,   181,   480,
       0,     0,   182,   457,     0,   343,     0,   182,   461,   343,
     343,   346,     0,   524,     0,   526,   527,     0,   343,     0,
     532,     0,     0,     0,     0,     0,     0,     0,     0,   541,
       0,     0,   343,     0,     0,     0,     0,     0,   550,   177,
     178,   179,   180,   181,     0,     0,     0,     0,   561,     0,
       0,     0,     0,   173,     0,     0,   516,     0,     0,     0,
       0,   177,   178,   179,   180,   181,     0,     0,     0,     0,
     177,   178,   179,   180,   181,   343,     0,   343,     0,   343,
       0,     0,   343,     0,     0,     0,     0,     0,     0,     0,
     434,     0,     0,     0,   346,     0,     0,   448,   346,     0,
       0,   454,     0,     0,   343,     0,     0,   343,   343,     0,
       0,   343,   343,   346,   194,   195,   346,   462,   463,   199,
     200,   201,   202,   203,   204,     0,     0,   177,   178,   179,
     180,   181,   177,   178,   179,   180,   181,     0,     0,     0,
     343,   273,   275,     0,   279,   500,     0,   502,     0,   285,
     506,     0,   343,     0,   343,     0,   294,   295,   297,     0,
       0,     0,   182,   466,   177,   178,   179,   180,   181,     0,
       0,     0,   343,   177,   178,   179,   180,   181,   323,     0,
     325,   326,     0,   329,   182,   467,   333,     0,   335,   336,
     337,   338,   522,   182,   468,     0,     0,     0,     0,   530,
     531,     0,   533,     0,     0,     0,   537,   191,   539,   191,
       0,     0,   543,   544,     0,     0,     0,     0,   549,     0,
       0,   191,     0,   554,   191,   556,   557,   559,     0,     0,
       0,   563,     0,     0,   343,     0,     0,     0,   343,     0,
       0,   343,     0,     0,     0,     0,   343,     0,     0,   576,
     182,   471,     0,     0,     0,   182,   494,     0,     0,   177,
     178,   179,   180,   181,   177,   178,   179,   180,   181,   177,
     178,   179,   180,   181,   177,   178,   179,   180,   181,   177,
     178,   179,   180,   181,     0,     0,     0,   182,   499,   177,
     178,   179,   180,   181,     0,     0,   182,   505,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,   179,   180,   181,     0,
       0,     0,     0,   600,     0,     0,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   343,     0,   343,   343,     0,     0,
       0,     0,   343,     0,     0,     0,     0,     0,     0,     0,
       0,   343,     0,     0,     0,     0,     0,     0,     0,     0,
     343,     0,     0,     0,     0,     0,     0,   346,     0,     0,
       0,   343,   182,   508,     0,     0,     0,   182,   510,     0,
       0,     0,   182,   515,     0,     0,     0,   360,   518,     0,
       0,     0,   182,   529,     0,     0,   538,     0,   540,     0,
       0,     0,   211,   565,     0,     0,     0,     0,     0,     0,
     552,    90,    91,   555,     0,   558,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   211,   568,   103,
       0,   104,   105,   372,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   182,     0,   166,   167,   168,   169,
     170,   171,   172,    90,    91,     0,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,   103,     0,   104,   105,   372,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,     1,     0,   166,   167,
     168,   169,   170,   171,   172,    90,    91,     0,     0,     0,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,   103,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,   158,   159,   160,   161,   162,   163,   164,   165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,   180,   181,   177,   178,   179,   180,   181,   177,   178,
     179,   180,   181,     0,     0,     0,   400,   177,   178,   179,
     180,   181,   177,   178,   179,   180,   181,     0,   182,     0,
     166,   167,   168,   169,   170,   171,   172,    90,    91,     0,
       0,     0,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,     0,     0,   103,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,   158,   159,   160,   161,   162,   163,   164,
     165,   211,   571,     0,     0,     0,   182,   574,     0,     0,
       0,   603,   361,   177,   178,   179,   180,   181,     0,     0,
     182,   605,     0,     0,     0,   182,   606,     0,     0,     0,
     402,   177,   178,   179,   180,   181,     0,     0,     0,     0,
     182,     0,   166,   167,   168,   169,   170,   171,   172,    90,
      91,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,     0,   103,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   373,     0,     0,   182,   607,     0,     0,
       0,     0,   177,   178,   179,   180,   181,   177,   178,   179,
     180,   181,     0,     0,   182,   610,   177,   178,   179,   180,
     181,   177,   178,   179,   180,   181,     0,     0,     0,     0,
       0,     0,   182,     0,   166,   167,   168,   169,   170,   171,
     172,    90,    91,     0,     0,     0,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     0,     0,   103,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   182,   616,     0,     0,     0,
     182,   620,     0,     0,     0,     0,     0,     0,     0,   182,
     625,     0,     0,     0,   182,   628,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,   166,   167,   168,   169,
     170,   171,   172,    90,    91,     0,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,   103,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   429,   158,
     159,   160,   161,   162,   163,   164,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,     0,   166,   167,
     168,   169,   170,   171,   172,     0,     0,     0,     0,     0,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411
};

static const yytype_int16 yycheck[] =
{
       0,     1,   306,     0,     1,     5,   205,   114,   208,   208,
     111,   112,   126,     3,   126,   127,   117,   118,   119,   274,
     275,     3,     0,   124,     3,   126,   127,   128,   126,   127,
     126,   127,   213,   126,     3,     4,     5,     6,     7,     3,
       4,     5,     6,     7,     3,   146,     3,   148,   149,   150,
     151,   152,   153,   154,   155,   126,   127,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,   126,   127,   127,   256,   127,   258,     3,     4,
       5,     6,     7,   126,   127,   127,   267,   268,   127,   270,
     127,     3,     4,     5,     6,     7,   277,   126,   127,   127,
     281,   282,   283,     3,     4,     5,     6,     7,   126,   127,
     127,   212,   126,   127,   127,   115,   126,   127,   115,     3,
       4,     5,     6,     7,   305,   126,   127,   308,   309,   127,
     311,   312,   127,   314,   127,   316,   317,   127,   319,     3,
       4,     5,     6,     7,   126,   127,   127,   126,   127,   126,
     127,   126,   127,   127,   255,   262,   257,   126,   127,   126,
     127,   127,   126,   127,   364,   364,   126,   127,   269,   369,
     369,   126,   127,   127,   174,   276,   176,   278,   279,   280,
     126,   485,   182,   127,   285,   126,   127,   126,   127,   127,
     126,   127,   127,     3,     4,     5,     6,     7,   126,   127,
     127,   126,   127,   126,   127,   205,   126,   127,   208,   209,
     210,   211,   209,   210,   126,   127,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,   126,   127,   126,   127,
     126,   127,   413,   126,   127,   127,   417,   126,   127,   420,
     126,   127,   126,   127,     3,     4,     5,     6,     7,   126,
     127,   127,   433,     3,     4,     5,     6,     7,   126,   127,
     260,   127,   126,   127,   264,   265,   447,   127,   265,   450,
     127,   452,   453,   273,   126,   127,   273,   127,   459,   127,
      91,    92,   127,     3,     4,     5,     6,     7,    99,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,   110,
     111,   112,   113,   114,   126,   127,   306,   126,   127,   306,
     126,   127,   127,   414,   126,   127,   126,   418,   129,   127,
     421,   132,   133,   522,   135,   136,     3,     4,     5,     6,
       7,   126,   127,   434,     3,     4,     5,     6,     7,   126,
     127,   522,   126,   127,   126,   156,   127,   448,   126,   127,
     126,   127,   127,   454,   127,   166,   127,   168,   126,   127,
     360,   126,   127,   360,   364,   126,   127,   126,   127,   369,
     370,   371,   126,   127,   126,   127,   126,   127,   127,     3,
       4,     5,     6,     7,   127,   566,   197,   127,   569,   126,
     127,   572,   126,   127,   127,   576,   126,   127,   579,   126,
     127,   127,   213,   126,   127,   586,   126,   127,   126,   127,
     591,   127,   126,   127,   126,   127,   127,   126,   127,   126,
     127,   126,   127,   604,   127,   127,   127,   127,   428,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,   439,
     440,   127,   127,   127,   127,   256,   127,   258,   127,   126,
     127,   127,   263,   127,   111,   127,   127,   126,   127,   127,
     116,   127,   462,    93,    94,    95,    96,    97,    98,   124,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     127,   127,   127,   127,   127,   485,   116,   127,   485,   119,
     120,   121,   122,   123,   124,   125,   126,   288,   127,   127,
     130,   131,   126,   127,   134,   127,   127,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   516,   127,   127,   127,
     127,   127,   522,   127,   127,   127,   127,   157,   158,   159,
     160,   161,   162,   127,   164,   165,   127,   167,   127,   169,
     170,   171,   172,   271,     3,     4,     5,     6,     7,   304,
      -1,    -1,   126,   127,    -1,   185,    -1,   126,   127,   189,
     190,   191,    -1,   374,    -1,   376,   377,    -1,   198,    -1,
     381,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,
      -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,   399,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,   409,    -1,
      -1,    -1,    -1,   603,    -1,    -1,   603,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,   255,    -1,   257,    -1,   259,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     270,    -1,    -1,    -1,   274,    -1,    -1,   277,   278,    -1,
      -1,   281,    -1,    -1,   284,    -1,    -1,   287,   288,    -1,
      -1,   291,   292,   293,    95,    96,   296,   126,   127,   100,
     101,   102,   103,   104,   105,    -1,    -1,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,    -1,    -1,    -1,
     320,   122,   123,    -1,   125,   325,    -1,   327,    -1,   130,
     330,    -1,   332,    -1,   334,    -1,   137,   138,   139,    -1,
      -1,    -1,   126,   127,     3,     4,     5,     6,     7,    -1,
      -1,    -1,   352,     3,     4,     5,     6,     7,   159,    -1,
     161,   162,    -1,   164,   126,   127,   167,    -1,   169,   170,
     171,   172,   372,   126,   127,    -1,    -1,    -1,    -1,   379,
     380,    -1,   382,    -1,    -1,    -1,   386,   387,   388,   389,
      -1,    -1,   392,   393,    -1,    -1,    -1,    -1,   398,    -1,
      -1,   401,    -1,   403,   404,   405,   406,   407,    -1,    -1,
      -1,   411,    -1,    -1,   414,    -1,    -1,    -1,   418,    -1,
      -1,   421,    -1,    -1,    -1,    -1,   426,    -1,    -1,   429,
     126,   127,    -1,    -1,    -1,   126,   127,    -1,    -1,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,     3,
       4,     5,     6,     7,    -1,    -1,    -1,   126,   127,     3,
       4,     5,     6,     7,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,   503,    -1,    -1,   506,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   524,    -1,   526,   527,    -1,    -1,
      -1,    -1,   532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   541,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     550,    -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,    -1,
      -1,   561,   126,   127,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,   126,   127,    -1,    -1,   387,    -1,   389,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
     401,     3,     4,   404,    -1,   406,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,   126,   127,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,   128,   129,   130,   131,
     132,   133,   134,     3,     4,    -1,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,   128,   129,
     130,   131,   132,   133,   134,     3,     4,    -1,    -1,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,    -1,    -1,    -1,   114,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,    -1,   126,    -1,
     128,   129,   130,   131,   132,   133,   134,     3,     4,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    79,    80,    81,    82,    83,    84,    85,
      86,   126,   127,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,   126,   127,     3,     4,     5,     6,     7,    -1,    -1,
     126,   127,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
     116,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,   132,   133,   134,     3,
       4,    -1,    -1,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,    -1,    -1,   126,   127,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,   132,   133,
     134,     3,     4,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    79,    80,    81,
      82,    83,    84,    85,    86,   126,   127,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
     132,   133,   134,     3,     4,    -1,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    25,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   126,   136,   137,   142,   143,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       3,     4,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    21,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    79,    80,
      81,    82,    83,    84,    85,    86,   128,   129,   130,   131,
     132,   133,   134,   142,   143,     0,   143,     3,     4,     5,
       6,     7,   126,   127,   138,   140,   142,   148,   127,   140,
     140,   138,   139,   138,   139,   139,   138,   138,   140,   139,
     139,   139,   139,   139,   139,   138,   151,   152,   138,   138,
     138,   126,   140,   144,   153,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   140,   144,   140,   144,   140,
     126,   127,   140,   265,   143,   138,   126,   144,   144,   138,
     144,   138,   138,   139,   138,   139,   138,   144,   138,   139,
     138,   144,   144,   144,   140,   139,   138,   140,   140,   138,
     127,   140,   140,   138,   139,   139,   138,   139,   138,   138,
     138,   138,   138,   127,   138,   144,     3,   127,   144,   144,
     127,   144,   144,   127,   144,   127,   144,   144,   127,   144,
     140,   138,   138,   139,   138,   139,   139,     3,   149,   139,
     141,   138,   140,   139,   140,   139,   139,   139,   139,   127,
     127,   142,   127,   138,   127,   127,   138,   127,   127,   127,
     127,   127,   140,   127,   127,   127,   127,   127,   127,   127,
     126,   127,   142,   145,   146,   148,   127,   127,   146,   147,
     143,   143,    25,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   127,   144,   140,   153,   127,   144,   140,   127,
     144,   140,   127,   127,   265,   127,   140,   127,   143,    25,
     127,   127,   127,   144,   138,   126,   127,   262,   127,   143,
     126,   127,   267,   126,   127,   267,   127,   144,   138,   127,
     144,   127,   144,   144,   138,   127,   127,   127,   127,   144,
     127,   127,   126,   127,   238,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   126,   127,
     275,   127,     3,   127,   137,   150,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     138,   127,   138,     3,   127,   127,   138,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   143,   146,   127,   146,
     127,   127,   138,   127,   140,   127,   140,   140,   127,   127,
     138,   138,   140,   138,   127,   127,   127,   138,   139,   138,
     139,   140,   127,   138,   138,   127,   127,   127,   127,   138,
     140,   127,   139,   127,   138,   139,   138,   138,   139,   138,
     127,   140,   127,   138,   127,   127,   144,   127,   127,   144,
     127,   127,   144,   127,   127,   127,   138,   127,   127,   144,
     127,   127,   127,   127,   127,   127,   144,   127,   127,   127,
     127,   144,   127,   127,   127,   127,     3,   127,   137,   127,
     138,   138,   127,   126,   153,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   153,   127
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   135,   136,   137,   138,   138,   139,   140,   140,   141,
     141,   142,   142,   143,   143,   143,   144,   144,   145,   145,
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
     154,   154,   154,   154,   154,   154,   154,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     176,   176,   177,   178,   179,   180,   180,   180,   180,   181,
     181,   181,   181,   182,   182,   182,   182,   183,   184,   184,
     184,   184,   184,   185,   186,   187,   188,   189,   189,   189,
     189,   190,   190,   191,   192,   193,   193,   193,   193,   194,
     194,   194,   194,   195,   195,   195,   195,   196,   196,   196,
     197,   198,   199,   200,   200,   201,   202,   203,   203,   204,
     205,   205,   206,   207,   207,   208,   209,   209,   210,   211,
     212,   213,   214,   215,   215,   215,   216,   217,   217,   217,
     217,   218,   218,   219,   219,   220,   221,   221,   222,   223,
     223,   224,   224,   225,   226,   226,   227,   228,   229,   229,
     230,   231,   232,   233,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   271,   272,   273,   274,   275,   276,
     277
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     1,     3,
       1,     1,     3,     2,     1,     3,     2,     1,     3,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     3,
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     5,     5,     5,     5,     6,     4,     5,
       5,     6,     4,     5,     5,     6,     4,     4,     5,     5,
       4,     4,     3,     4,     5,     4,     4,     5,     5,     6,
       4,     4,     5,     4,     5,     5,     4,     5,     4,     5,
       5,     6,     4,     5,     4,     5,     4,     5,     5,     6,
       4,     4,     4,     5,     4,     4,     4,     5,     4,     4,
       4,     3,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     4,     5,     4,     6,     5,     5,
       4,     4,     3,     3,     4,     4,     3,     4,     4,     3,
       4,     3,     4,     4,     3,     4,     4,     4,     4,     3,
       4,     4,     4,     4,     5,     4,     4,     4,     4,     3,
       4,     3,     4,     4,     3,     4,     3,     4,     4,     4,
       3,     3,     3,     4,     4,     4,     4,     4,     3,     4,
       4,     3,     3,     3,     3,     4,     4,     3,     4,     3,
       4,     4,     4,     4,     4,     4,     3,     4,     3,     4,
       6
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
#line 75 "../src/parser.y" /* yacc.c:1257  */
      { free(((*yyvaluep).s)); }
#line 1961 "parser.c" /* yacc.c:1257  */
        break;

    case 4: /* STR  */
#line 75 "../src/parser.y" /* yacc.c:1257  */
      { free(((*yyvaluep).s)); }
#line 1967 "parser.c" /* yacc.c:1257  */
        break;

    case 136: /* start  */
#line 73 "../src/parser.y" /* yacc.c:1257  */
      { run(((*yyvaluep).e));  }
#line 1973 "parser.c" /* yacc.c:1257  */
        break;

    case 137: /* s  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1979 "parser.c" /* yacc.c:1257  */
        break;

    case 138: /* p  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1985 "parser.c" /* yacc.c:1257  */
        break;

    case 139: /* pp  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1991 "parser.c" /* yacc.c:1257  */
        break;

    case 140: /* ps  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1997 "parser.c" /* yacc.c:1257  */
        break;

    case 141: /* pps  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2003 "parser.c" /* yacc.c:1257  */
        break;

    case 142: /* vp  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2009 "parser.c" /* yacc.c:1257  */
        break;

    case 143: /* vps  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2015 "parser.c" /* yacc.c:1257  */
        break;

    case 144: /* opts  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2021 "parser.c" /* yacc.c:1257  */
        break;

    case 145: /* vpb  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2027 "parser.c" /* yacc.c:1257  */
        break;

    case 146: /* xpb  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2033 "parser.c" /* yacc.c:1257  */
        break;

    case 147: /* xpbs  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2039 "parser.c" /* yacc.c:1257  */
        break;

    case 148: /* np  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2045 "parser.c" /* yacc.c:1257  */
        break;

    case 149: /* sps  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2051 "parser.c" /* yacc.c:1257  */
        break;

    case 150: /* par  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2057 "parser.c" /* yacc.c:1257  */
        break;

    case 151: /* cv  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2063 "parser.c" /* yacc.c:1257  */
        break;

    case 152: /* cvv  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2069 "parser.c" /* yacc.c:1257  */
        break;

    case 153: /* opt  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2075 "parser.c" /* yacc.c:1257  */
        break;

    case 154: /* ivp  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2081 "parser.c" /* yacc.c:1257  */
        break;

    case 155: /* add  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2087 "parser.c" /* yacc.c:1257  */
        break;

    case 156: /* div  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2093 "parser.c" /* yacc.c:1257  */
        break;

    case 157: /* mul  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2099 "parser.c" /* yacc.c:1257  */
        break;

    case 158: /* sub  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2105 "parser.c" /* yacc.c:1257  */
        break;

    case 159: /* and  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2111 "parser.c" /* yacc.c:1257  */
        break;

    case 160: /* bitand  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2117 "parser.c" /* yacc.c:1257  */
        break;

    case 161: /* bitnot  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2123 "parser.c" /* yacc.c:1257  */
        break;

    case 162: /* bitor  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2129 "parser.c" /* yacc.c:1257  */
        break;

    case 163: /* bitxor  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2135 "parser.c" /* yacc.c:1257  */
        break;

    case 164: /* not  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2141 "parser.c" /* yacc.c:1257  */
        break;

    case 165: /* in  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2147 "parser.c" /* yacc.c:1257  */
        break;

    case 166: /* or  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2153 "parser.c" /* yacc.c:1257  */
        break;

    case 167: /* shiftleft  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2159 "parser.c" /* yacc.c:1257  */
        break;

    case 168: /* shiftright  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2165 "parser.c" /* yacc.c:1257  */
        break;

    case 169: /* xor  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2171 "parser.c" /* yacc.c:1257  */
        break;

    case 170: /* eq  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2177 "parser.c" /* yacc.c:1257  */
        break;

    case 171: /* gt  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2183 "parser.c" /* yacc.c:1257  */
        break;

    case 172: /* gte  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2189 "parser.c" /* yacc.c:1257  */
        break;

    case 173: /* lt  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2195 "parser.c" /* yacc.c:1257  */
        break;

    case 174: /* lte  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2201 "parser.c" /* yacc.c:1257  */
        break;

    case 175: /* neq  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2207 "parser.c" /* yacc.c:1257  */
        break;

    case 176: /* if  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2213 "parser.c" /* yacc.c:1257  */
        break;

    case 177: /* select  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2219 "parser.c" /* yacc.c:1257  */
        break;

    case 178: /* until  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2225 "parser.c" /* yacc.c:1257  */
        break;

    case 179: /* while  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2231 "parser.c" /* yacc.c:1257  */
        break;

    case 180: /* execute  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2237 "parser.c" /* yacc.c:1257  */
        break;

    case 181: /* rexx  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2243 "parser.c" /* yacc.c:1257  */
        break;

    case 182: /* run  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2249 "parser.c" /* yacc.c:1257  */
        break;

    case 183: /* abort  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2255 "parser.c" /* yacc.c:1257  */
        break;

    case 184: /* exit  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2261 "parser.c" /* yacc.c:1257  */
        break;

    case 185: /* onerror  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2267 "parser.c" /* yacc.c:1257  */
        break;

    case 186: /* trap  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2273 "parser.c" /* yacc.c:1257  */
        break;

    case 187: /* copyfiles  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2279 "parser.c" /* yacc.c:1257  */
        break;

    case 188: /* copylib  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2285 "parser.c" /* yacc.c:1257  */
        break;

    case 189: /* delete  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2291 "parser.c" /* yacc.c:1257  */
        break;

    case 190: /* exists  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2297 "parser.c" /* yacc.c:1257  */
        break;

    case 191: /* fileonly  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2303 "parser.c" /* yacc.c:1257  */
        break;

    case 192: /* foreach  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2309 "parser.c" /* yacc.c:1257  */
        break;

    case 193: /* makeassign  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2315 "parser.c" /* yacc.c:1257  */
        break;

    case 194: /* makedir  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2321 "parser.c" /* yacc.c:1257  */
        break;

    case 195: /* protect  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2327 "parser.c" /* yacc.c:1257  */
        break;

    case 196: /* startup  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2333 "parser.c" /* yacc.c:1257  */
        break;

    case 197: /* textfile  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2339 "parser.c" /* yacc.c:1257  */
        break;

    case 198: /* tooltype  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2345 "parser.c" /* yacc.c:1257  */
        break;

    case 199: /* transcript  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2351 "parser.c" /* yacc.c:1257  */
        break;

    case 200: /* rename  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2357 "parser.c" /* yacc.c:1257  */
        break;

    case 201: /* complete  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2363 "parser.c" /* yacc.c:1257  */
        break;

    case 202: /* debug  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2369 "parser.c" /* yacc.c:1257  */
        break;

    case 203: /* message  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2375 "parser.c" /* yacc.c:1257  */
        break;

    case 204: /* user  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2381 "parser.c" /* yacc.c:1257  */
        break;

    case 205: /* welcome  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2387 "parser.c" /* yacc.c:1257  */
        break;

    case 206: /* working  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2393 "parser.c" /* yacc.c:1257  */
        break;

    case 207: /* database  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2399 "parser.c" /* yacc.c:1257  */
        break;

    case 208: /* earlier  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2405 "parser.c" /* yacc.c:1257  */
        break;

    case 209: /* getassign  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2411 "parser.c" /* yacc.c:1257  */
        break;

    case 210: /* getdevice  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2417 "parser.c" /* yacc.c:1257  */
        break;

    case 211: /* getdiskspace  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2423 "parser.c" /* yacc.c:1257  */
        break;

    case 212: /* getenv  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2429 "parser.c" /* yacc.c:1257  */
        break;

    case 213: /* getsize  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2435 "parser.c" /* yacc.c:1257  */
        break;

    case 214: /* getsum  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2441 "parser.c" /* yacc.c:1257  */
        break;

    case 215: /* getversion  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2447 "parser.c" /* yacc.c:1257  */
        break;

    case 216: /* iconinfo  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2453 "parser.c" /* yacc.c:1257  */
        break;

    case 217: /* dcl  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2459 "parser.c" /* yacc.c:1257  */
        break;

    case 218: /* cus  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2465 "parser.c" /* yacc.c:1257  */
        break;

    case 219: /* askbool  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2471 "parser.c" /* yacc.c:1257  */
        break;

    case 220: /* askchoice  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2477 "parser.c" /* yacc.c:1257  */
        break;

    case 221: /* askdir  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2483 "parser.c" /* yacc.c:1257  */
        break;

    case 222: /* askdisk  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2489 "parser.c" /* yacc.c:1257  */
        break;

    case 223: /* askfile  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2495 "parser.c" /* yacc.c:1257  */
        break;

    case 224: /* asknumber  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2501 "parser.c" /* yacc.c:1257  */
        break;

    case 225: /* askoptions  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2507 "parser.c" /* yacc.c:1257  */
        break;

    case 226: /* askstring  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2513 "parser.c" /* yacc.c:1257  */
        break;

    case 227: /* cat  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2519 "parser.c" /* yacc.c:1257  */
        break;

    case 228: /* expandpath  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2525 "parser.c" /* yacc.c:1257  */
        break;

    case 229: /* fmt  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2531 "parser.c" /* yacc.c:1257  */
        break;

    case 230: /* pathonly  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2537 "parser.c" /* yacc.c:1257  */
        break;

    case 231: /* patmatch  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2543 "parser.c" /* yacc.c:1257  */
        break;

    case 232: /* strlen  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2549 "parser.c" /* yacc.c:1257  */
        break;

    case 233: /* substr  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2555 "parser.c" /* yacc.c:1257  */
        break;

    case 234: /* tackon  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2561 "parser.c" /* yacc.c:1257  */
        break;

    case 235: /* set  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2567 "parser.c" /* yacc.c:1257  */
        break;

    case 236: /* symbolset  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2573 "parser.c" /* yacc.c:1257  */
        break;

    case 237: /* symbolval  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2579 "parser.c" /* yacc.c:1257  */
        break;

    case 238: /* all  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2585 "parser.c" /* yacc.c:1257  */
        break;

    case 239: /* append  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2591 "parser.c" /* yacc.c:1257  */
        break;

    case 240: /* assigns  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2597 "parser.c" /* yacc.c:1257  */
        break;

    case 241: /* choices  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2603 "parser.c" /* yacc.c:1257  */
        break;

    case 242: /* command  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2609 "parser.c" /* yacc.c:1257  */
        break;

    case 243: /* compression  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2615 "parser.c" /* yacc.c:1257  */
        break;

    case 244: /* confirm  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2621 "parser.c" /* yacc.c:1257  */
        break;

    case 245: /* default  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2627 "parser.c" /* yacc.c:1257  */
        break;

    case 246: /* delopts  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2633 "parser.c" /* yacc.c:1257  */
        break;

    case 247: /* dest  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2639 "parser.c" /* yacc.c:1257  */
        break;

    case 248: /* disk  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2645 "parser.c" /* yacc.c:1257  */
        break;

    case 249: /* files  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2651 "parser.c" /* yacc.c:1257  */
        break;

    case 250: /* fonts  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2657 "parser.c" /* yacc.c:1257  */
        break;

    case 251: /* getdefaulttool  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2663 "parser.c" /* yacc.c:1257  */
        break;

    case 252: /* getposition  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2669 "parser.c" /* yacc.c:1257  */
        break;

    case 253: /* getstack  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2675 "parser.c" /* yacc.c:1257  */
        break;

    case 254: /* gettooltype  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2681 "parser.c" /* yacc.c:1257  */
        break;

    case 255: /* help  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2687 "parser.c" /* yacc.c:1257  */
        break;

    case 256: /* infos  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2693 "parser.c" /* yacc.c:1257  */
        break;

    case 257: /* include  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2699 "parser.c" /* yacc.c:1257  */
        break;

    case 258: /* newname  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2705 "parser.c" /* yacc.c:1257  */
        break;

    case 259: /* newpath  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2711 "parser.c" /* yacc.c:1257  */
        break;

    case 260: /* nogauge  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2717 "parser.c" /* yacc.c:1257  */
        break;

    case 261: /* noposition  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2723 "parser.c" /* yacc.c:1257  */
        break;

    case 262: /* noreq  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2729 "parser.c" /* yacc.c:1257  */
        break;

    case 263: /* pattern  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2735 "parser.c" /* yacc.c:1257  */
        break;

    case 264: /* prompt  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2741 "parser.c" /* yacc.c:1257  */
        break;

    case 265: /* quiet  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2747 "parser.c" /* yacc.c:1257  */
        break;

    case 266: /* range  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2753 "parser.c" /* yacc.c:1257  */
        break;

    case 267: /* safe  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2759 "parser.c" /* yacc.c:1257  */
        break;

    case 268: /* setdefaulttool  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2765 "parser.c" /* yacc.c:1257  */
        break;

    case 269: /* setposition  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2771 "parser.c" /* yacc.c:1257  */
        break;

    case 270: /* setstack  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2777 "parser.c" /* yacc.c:1257  */
        break;

    case 271: /* settooltype  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2783 "parser.c" /* yacc.c:1257  */
        break;

    case 272: /* source  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2789 "parser.c" /* yacc.c:1257  */
        break;

    case 273: /* swapcolors  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2795 "parser.c" /* yacc.c:1257  */
        break;

    case 274: /* optional  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2801 "parser.c" /* yacc.c:1257  */
        break;

    case 275: /* resident  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2807 "parser.c" /* yacc.c:1257  */
        break;

    case 276: /* override  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2813 "parser.c" /* yacc.c:1257  */
        break;

    case 277: /* dynopt  */
#line 78 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2819 "parser.c" /* yacc.c:1257  */
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
#line 93 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = init((yyvsp[0].e)); }
#line 3087 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 99 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3093 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 100 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3099 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 101 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3105 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 102 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push((yyvsp[-2].e), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3111 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 105 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3117 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 106 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3123 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 107 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3129 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 108 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3135 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 109 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3141 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 110 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3147 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 111 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3153 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 112 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3159 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 115 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3165 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 116 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3171 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 117 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3177 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 118 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3183 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 119 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3189 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 120 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_string((yyvsp[0].s)); }
#line 3195 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 121 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_symref((yyvsp[0].s), LINE); }
#line 3201 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 122 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push((yyvsp[-2].e), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)) ; }
#line 3207 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 123 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push(new_contxt(), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)); }
#line 3213 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 124 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push((yyvsp[-1].e), new_symbol((yyvsp[0].s))); }
#line 3219 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 125 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), new_symbol((yyvsp[0].s))); }
#line 3225 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 126 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3231 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 127 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3237 "parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 257 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("+"), LINE, m_add, (yyvsp[-1].e), NUMBER); }
#line 3243 "parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 258 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("/"), LINE, m_div, (yyvsp[-1].e), NUMBER); }
#line 3249 "parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 259 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("*"), LINE, m_mul, (yyvsp[-1].e), NUMBER); }
#line 3255 "parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 260 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("-"), LINE, m_sub, (yyvsp[-1].e), NUMBER); }
#line 3261 "parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 263 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("AND"), LINE, m_and, (yyvsp[-1].e), NUMBER); }
#line 3267 "parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 264 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("BITAND"), LINE, m_bitand, (yyvsp[-1].e), NUMBER); }
#line 3273 "parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 265 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("BITNOT"), LINE, m_bitnot, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3279 "parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 266 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("BITOR"), LINE, m_bitor, (yyvsp[-1].e), NUMBER); }
#line 3285 "parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 267 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("BITXOR"), LINE, m_bitxor, (yyvsp[-1].e), NUMBER); }
#line 3291 "parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 268 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("NOT"), LINE, m_not, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3297 "parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 269 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("IN"), LINE, m_in, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3303 "parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 270 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("OR"), LINE, m_or, (yyvsp[-1].e), NUMBER); }
#line 3309 "parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 271 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("shiftleft"), LINE, m_shiftleft, (yyvsp[-1].e), NUMBER); }
#line 3315 "parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 272 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("shiftright"), LINE, m_shiftright, (yyvsp[-1].e), NUMBER); }
#line 3321 "parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 273 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("XOR"), LINE, m_xor, (yyvsp[-1].e), NUMBER); }
#line 3327 "parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 276 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("="), LINE, m_eq, (yyvsp[-1].e), NUMBER); }
#line 3333 "parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 277 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup(">"), LINE, m_gt, (yyvsp[-1].e), NUMBER); }
#line 3339 "parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 278 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup(">="), LINE, m_gte, (yyvsp[-1].e), NUMBER); }
#line 3345 "parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 279 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("<"), LINE, m_lt, (yyvsp[-1].e), NUMBER); }
#line 3351 "parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 280 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("<="), LINE, m_lte, (yyvsp[-1].e), NUMBER); }
#line 3357 "parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 281 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("<>"), LINE, m_neq, (yyvsp[-1].e), NUMBER); }
#line 3363 "parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 284 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3369 "parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 285 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3375 "parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 286 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3381 "parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 287 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("select"), LINE, m_select, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3387 "parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 288 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("until"), LINE, m_until, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3393 "parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 289 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("while"), LINE, m_while, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3399 "parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 292 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3405 "parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 293 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3411 "parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 294 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push(push((yyvsp[-2].e), (yyvsp[-3].e)), (yyvsp[-1].e)), NUMBER); }
#line 3417 "parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 295 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, (yyvsp[-1].e), NUMBER); }
#line 3423 "parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 296 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3429 "parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 297 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3435 "parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 298 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push(push((yyvsp[-2].e), (yyvsp[-3].e)), (yyvsp[-1].e)), NUMBER); }
#line 3441 "parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 299 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, (yyvsp[-1].e), NUMBER); }
#line 3447 "parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 300 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3453 "parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 301 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3459 "parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 302 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push(push((yyvsp[-2].e), (yyvsp[-3].e)), (yyvsp[-1].e)), NUMBER); }
#line 3465 "parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 303 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, (yyvsp[-1].e), NUMBER); }
#line 3471 "parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 306 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("abort"), LINE, m_abort, (yyvsp[-1].e), NUMBER); }
#line 3477 "parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 307 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3483 "parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 308 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3489 "parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 309 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3495 "parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 310 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, (yyvsp[-1].e), NUMBER); }
#line 3501 "parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 311 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, NULL, NUMBER); }
#line 3507 "parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 312 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("onerror"), LINE, m_procedure, push(new_contxt(), 
                                                       new_custom(strdup("@onerror"), LINE, NULL, (yyvsp[-1].e))), DANGLE); }
#line 3514 "parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 314 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("trap"), LINE, m_trap, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3520 "parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 317 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("copyfiles"), LINE, m_copyfiles, (yyvsp[-1].e), NUMBER); }
#line 3526 "parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 318 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("copylib"), LINE, m_copylib, (yyvsp[-1].e), NUMBER); }
#line 3532 "parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 319 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3538 "parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 320 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3544 "parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 321 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-3].e)), (yyvsp[-1].e)), NUMBER); }
#line 3550 "parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 322 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3556 "parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 323 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3562 "parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 324 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3568 "parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 325 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("fileonly"), LINE, m_fileonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3574 "parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 326 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("foreach"), LINE, m_foreach, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3580 "parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 327 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3586 "parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 328 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, (yyvsp[-1].e), NUMBER); }
#line 3592 "parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 329 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3598 "parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 330 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3604 "parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 331 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3610 "parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 332 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3616 "parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 333 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-3].e)), (yyvsp[-1].e)), NUMBER); }
#line 3622 "parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 334 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3628 "parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 335 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3634 "parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 336 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, (yyvsp[-1].e), NUMBER); }
#line 3640 "parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 337 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3646 "parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 338 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3652 "parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 339 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3658 "parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 340 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3664 "parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 341 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-3].e)), (yyvsp[-1].e)), NUMBER); }
#line 3670 "parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 342 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("textfile"), LINE, m_textfile, (yyvsp[-1].e), NUMBER); }
#line 3676 "parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 343 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("tooltype"), LINE, m_tooltype, (yyvsp[-1].e), NUMBER); }
#line 3682 "parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 344 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("transcript"), LINE, m_transcript, (yyvsp[-1].e), NUMBER); }
#line 3688 "parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 345 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3694 "parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 346 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, (yyvsp[-1].e), NUMBER); }
#line 3700 "parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 349 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("complete"), LINE, m_complete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3706 "parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 350 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, (yyvsp[-1].e), NUMBER); }
#line 3712 "parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 351 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3718 "parser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 352 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, (yyvsp[-1].e), NUMBER); }
#line 3724 "parser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 353 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("user"), LINE, m_user, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3730 "parser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 354 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, (yyvsp[-1].e), NUMBER); }
#line 3736 "parser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 355 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, NULL, NUMBER); }
#line 3742 "parser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 356 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("working"), LINE, m_working, (yyvsp[-1].e), NUMBER); }
#line 3748 "parser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 359 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3754 "parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 360 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, (yyvsp[-1].e), STRING); }
#line 3760 "parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 361 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("earlier"), LINE, m_earlier, (yyvsp[-1].e), NUMBER); }
#line 3766 "parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 362 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3772 "parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 363 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, (yyvsp[-1].e), STRING); }
#line 3778 "parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 364 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getdevice"), LINE, m_getdevice, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3784 "parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 365 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3790 "parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 366 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getenv"), LINE, m_getenv, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3796 "parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 367 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getsize"), LINE, m_getsize, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3802 "parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 368 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getsum"), LINE, m_getsum, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3808 "parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 369 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, NULL, NUMBER); }
#line 3814 "parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 370 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3820 "parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 371 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3826 "parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 372 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("iconinfo"), LINE, m_iconinfo, (yyvsp[-1].e), NUMBER); }
#line 3832 "parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 375 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-3].s), LINE, (yyvsp[-2].e), (yyvsp[-1].e))), NUMBER); }
#line 3838 "parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 376 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, (yyvsp[-1].e), NULL)), NUMBER); }
#line 3844 "parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 377 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, NULL, (yyvsp[-1].e))), NUMBER); }
#line 3850 "parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 378 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-1].s), LINE, NULL, NULL)), NUMBER); }
#line 3856 "parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 379 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_cusref((yyvsp[-2].s), LINE, (yyvsp[-1].e)); }
#line 3862 "parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 380 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_cusref((yyvsp[-1].s), LINE, NULL); }
#line 3868 "parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 383 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, NULL, NUMBER); }
#line 3874 "parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 384 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, (yyvsp[-1].e), NUMBER); }
#line 3880 "parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 385 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askchoice"), LINE, m_askchoice, (yyvsp[-1].e), NUMBER); }
#line 3886 "parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 386 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, NULL, STRING); }
#line 3892 "parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 387 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, (yyvsp[-1].e), STRING); }
#line 3898 "parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 388 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askdisk"), LINE, m_askdisk, (yyvsp[-1].e), NUMBER); }
#line 3904 "parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 389 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, NULL, STRING); }
#line 3910 "parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 390 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, (yyvsp[-1].e), STRING); }
#line 3916 "parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 391 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, NULL, NUMBER); }
#line 3922 "parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 392 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, (yyvsp[-1].e), NUMBER); }
#line 3928 "parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 393 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askoptions"), LINE, m_askoptions, (yyvsp[-1].e), NUMBER); }
#line 3934 "parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 394 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, NULL, STRING); }
#line 3940 "parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 395 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, (yyvsp[-1].e), STRING); }
#line 3946 "parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 398 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("cat"), LINE, m_cat, (yyvsp[-1].e), STRING); }
#line 3952 "parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 399 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("expandpath"), LINE, m_expandpath, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3958 "parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 400 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native((yyvsp[-2].s), LINE, m_fmt, (yyvsp[-1].e), STRING); }
#line 3964 "parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 401 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native((yyvsp[-1].s), LINE, m_fmt, NULL, STRING); }
#line 3970 "parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 402 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("pathonly"), LINE, m_pathonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3976 "parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 403 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("patmatch"), LINE, m_patmatch, (yyvsp[-1].e), NUMBER); }
#line 3982 "parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 404 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("strlen"), LINE, m_strlen, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3988 "parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 405 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, (yyvsp[-1].e), STRING); }
#line 3994 "parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 406 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, push((yyvsp[-2].e), (yyvsp[-1].e)), STRING); }
#line 4000 "parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 407 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("tackon"), LINE, m_tackon, (yyvsp[-1].e), STRING); }
#line 4006 "parser.c" /* yacc.c:1646  */
    break;

  case 286:
#line 410 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("set"), LINE, m_set, (yyvsp[-1].e), DANGLE); }
#line 4012 "parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 411 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("symbolset"), LINE, m_symbolset, (yyvsp[-1].e), DANGLE); }
#line 4018 "parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 412 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("symbolval"), LINE, m_symbolval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4024 "parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 415 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("all"), OPT_ALL, NULL); }
#line 4030 "parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 416 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("append"), OPT_APPEND, (yyvsp[-1].e)); }
#line 4036 "parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 417 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); }
#line 4042 "parser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 418 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("choices"), OPT_CHOICES, (yyvsp[-1].e)); }
#line 4048 "parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 419 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("command"), OPT_COMMAND, (yyvsp[-1].e)); }
#line 4054 "parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 420 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("compression"), OPT_COMPRESSION, NULL); }
#line 4060 "parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 421 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, push(new_contxt(), (yyvsp[-1].e))); }
#line 4066 "parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 422 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, NULL); }
#line 4072 "parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 423 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), (yyvsp[-1].e))); }
#line 4078 "parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 424 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, (yyvsp[-1].e)); }
#line 4084 "parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 425 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), (yyvsp[-1].e))); }
#line 4090 "parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 426 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("disk"), OPT_DISK, NULL); }
#line 4096 "parser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 427 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("files"), OPT_FILES, NULL); }
#line 4102 "parser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 428 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("fonts"), OPT_FONTS, NULL); }
#line 4108 "parser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 429 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4114 "parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 430 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("getposition"), OPT_GETPOSITION, (yyvsp[-1].e)); }
#line 4120 "parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 431 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4126 "parser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 432 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, (yyvsp[-1].e)); }
#line 4132 "parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 433 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, (yyvsp[-1].e)); }
#line 4138 "parser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 434 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("infos"), OPT_INFOS, NULL); }
#line 4144 "parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 435 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4150 "parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 436 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), (yyvsp[-1].e))); }
#line 4156 "parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 437 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("newpath"), OPT_NEWPATH, NULL); }
#line 4162 "parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 438 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); }
#line 4168 "parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 439 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); }
#line 4174 "parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 440 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("noreq"), OPT_NOREQ, NULL); }
#line 4180 "parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 441 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), (yyvsp[-1].e))); }
#line 4186 "parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 442 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("prompt"), OPT_PROMPT, (yyvsp[-1].e)); }
#line 4192 "parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 443 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("quiet"), OPT_QUIET, NULL); }
#line 4198 "parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 444 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("range"), OPT_RANGE, (yyvsp[-1].e)); }
#line 4204 "parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 445 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("safe"), OPT_SAFE, NULL); }
#line 4210 "parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 446 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4216 "parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 447 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("setposition"), OPT_SETPOSITION, (yyvsp[-1].e)); }
#line 4222 "parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 448 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4228 "parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 449 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, (yyvsp[-1].e)); }
#line 4234 "parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 450 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4240 "parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 451 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4246 "parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 452 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); }
#line 4252 "parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 453 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, (yyvsp[-1].e)); }
#line 4258 "parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 454 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("resident"), OPT_RESIDENT, NULL); }
#line 4264 "parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 455 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4270 "parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 456 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(push(new_contxt(), (yyvsp[-3].e)), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4276 "parser.c" /* yacc.c:1646  */
    break;


#line 4280 "parser.c" /* yacc.c:1646  */
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
#line 458 "../src/parser.y" /* yacc.c:1906  */


