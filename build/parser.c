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

/* Copy the second part of user declarations.  */

#line 388 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  183
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1983

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  139
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  146
/* YYNRULES -- Number of rules.  */
#define YYNRULES  345
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  669

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   384

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
     130,   131,   134,   132,     2,   135,     2,   133,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     138,   136,   137,     2,     2,     2,     2,     2,     2,     2,
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
     125,   126,   127,   128,   129
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
     260,   261,   264,   265,   266,   267,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   283,   284,   285,
     286,   287,   288,   291,   292,   293,   294,   295,   296,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   313,   314,   315,   316,   317,   318,   319,   321,   322,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   386,   387,   388,   389,   390,
     391,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   421,   422,   423,   426,   427,   428,
     429,   430,   431,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476
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
  "select", "until", "while", "execute", "rexx", "run", "abort", "exit",
  "onerror", "reboot", "trap", "copyfiles", "copylib", "delete", "exists",
  "fileonly", "foreach", "makeassign", "makedir", "protect", "startup",
  "textfile", "tooltype", "transcript", "rename", "complete", "debug",
  "message", "user", "welcome", "working", "database", "earlier",
  "getassign", "getdevice", "getdiskspace", "getenv", "getsize", "getsum",
  "getversion", "iconinfo", "dcl", "cus", "askbool", "askchoice", "askdir",
  "askdisk", "askfile", "asknumber", "askoptions", "askstring", "cat",
  "expandpath", "fmt", "pathonly", "patmatch", "strlen", "substr",
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
      40,    41,    43,    47,    42,    45,    61,    62,    60
};
# endif

#define YYPACT_NINF -398

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-398)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -120,  1558,    28,  -398,  -398,  -120,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,    29,    35,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   749,   749,   749,   569,    40,  -120,
     569,   -94,   -82,   -82,   749,   569,   569,   569,   569,   749,
     569,   749,   -82,   -82,   569,   569,   569,    68,   569,   569,
      73,   569,   569,   569,   569,   569,   569,   569,   569,   569,
      83,   -82,    47,  -122,   -82,  -115,   -82,  -107,  -105,   -82,
     -71,   569,   569,   569,   569,   569,   569,   569,    58,   569,
     569,   749,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   -31,   -66,  -398,  -120,  -398,  -398,  -398,  -398,  -398,
    1694,  -398,  -398,    92,  -398,  -398,  -398,   106,   120,   569,
     -25,   -15,     9,    11,    26,   569,   126,    31,    36,    38,
      66,    81,   101,   131,   104,   118,   755,  -120,  -120,   878,
     144,   749,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,   149,   749,   174,   749,   204,  1150,  -398,
     221,   241,   -63,  -120,  -398,  1748,   -39,   -37,   -28,   749,
     -16,   129,  -120,   260,   -10,    44,   749,   285,    65,   -82,
     292,    70,    75,   303,    85,   140,  -398,   308,   389,   150,
    -398,   452,   527,   535,   185,   194,   550,   198,   222,   608,
     224,   235,   251,   266,  -398,    99,   109,    14,  -398,   112,
     122,  -398,   124,   128,  -398,   139,  -398,   147,   153,  -398,
     156,   615,   273,   304,   310,   321,   620,   331,   569,     8,
    -398,   648,   338,   163,   749,   344,   353,   656,   354,   668,
     355,   362,   364,   365,  -398,  -398,   -31,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,   684,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  1558,  -398,  -398,   755,  -398,
    -398,  -398,   767,   170,   172,   569,   366,   569,   371,   569,
     569,   372,  1247,   569,   569,   569,   374,   375,   377,   569,
     569,   569,   569,  1252,   378,   569,   569,   381,   384,   385,
     391,   569,   569,   392,   569,   393,   569,   569,   569,   569,
     569,   397,   569,   404,   569,   188,  -398,   191,  1257,   -82,
    -398,   193,  1266,  -398,   197,  1271,  -398,  -398,   405,  -398,
    1386,  -398,   201,   569,  -398,  -398,  -398,   206,   208,    74,
    -398,   412,  -398,   210,  1286,  -398,   413,   425,  -398,   415,
    -398,   212,   214,  -398,   217,  -398,   219,   228,  -398,   232,
    -398,  -398,  -398,  -398,   234,  -398,  -398,  1422,  -398,   417,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,   423,  -398,   428,  -398,  -398,  -398,
     434,    63,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,   436,  -398,  -398,   569,
    -398,  -398,   569,  -398,  -398,   238,   243,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  1404,  -398,  -398,
    -398,  -398,  -398,  1519,  -398,  1524,  -398,  1533,  1538,  -398,
    -398,   438,   439,  1543,   446,  -398,  -398,  -398,   447,   448,
     450,   454,  -398,  1655,  -398,   455,   458,  -398,  -398,  -398,
    -398,   459,  1672,  -398,   461,  -398,   462,   464,   465,  1677,
     466,   469,  -398,  1784,  -398,   470,  -398,  -398,  -398,   246,
    -398,  -398,   250,  -398,  -398,   255,  -398,  -398,  -398,   475,
    -398,  -398,   257,  -398,  -398,  -398,  -398,  -398,  -398,   287,
    -398,  -398,  -398,  -398,   289,  -398,  -398,  -398,  -398,  -398,
    -398,   477,  -398,  -398,  -398,  -398,  -398,   330,  -398,   478,
    1014,   475,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    1854,  -398,  -398,  -398,  -398,  -398,  -398,   485,  -398
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,    14,     3,    11,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   107,   106,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     139,   138,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     1,    13,    28,    27,    24,    25,    26,
       0,   270,     8,     0,     4,     5,   287,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    54,    53,    55,    56,    57,    58,    59,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    60,
      74,    61,    73,     0,     0,     0,     0,     0,     0,   206,
       0,     0,     0,     0,   208,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,     0,     0,     0,
     248,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   261,     0,     0,     0,   271,     0,
       0,   274,     0,     0,   277,     0,   279,     0,     0,   282,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    15,     0,   269,     7,   286,
     166,     6,   167,   168,   169,   170,   171,     0,   173,   174,
     175,   176,   179,   181,   182,     0,   185,    21,    33,   184,
     183,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,     0,     0,    16,
     196,     0,     0,   200,     0,     0,   201,   205,     0,   204,
       0,   207,     0,     0,   210,   211,   215,     0,     0,     0,
     216,     0,   218,     0,     0,   223,     0,     0,   221,     0,
     227,     0,     0,   231,     0,   229,     0,     0,   235,     0,
     236,   237,   238,   240,     0,   241,   242,     0,   245,     0,
     246,   247,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,     0,   262,     0,   264,    32,   268,
       0,     0,   272,   273,   275,   276,   278,   280,   281,   283,
     284,   285,   288,   289,   290,   291,     0,   293,    30,     0,
     294,   295,     0,   296,   297,     0,     0,   301,   302,   162,
     163,   164,   165,   177,   178,   180,   172,     0,    34,   186,
      23,   187,   188,     0,   303,     0,   305,     0,     0,   308,
     310,     0,     0,     0,     0,   314,   315,   316,     0,     0,
       0,     0,   322,     0,   323,     0,     0,   326,   327,   328,
     329,     0,     0,   332,     0,   334,     0,     0,     0,     0,
       0,     0,   341,     0,   343,     0,    18,   189,   190,     0,
     193,   194,     0,   197,   198,     0,   202,   203,   209,     0,
     212,   213,     0,   217,   219,   222,   220,   224,   225,     0,
     230,   228,   232,   233,     0,   239,   244,   263,   267,    31,
     266,     0,   292,    29,     9,   298,   299,     0,    19,     0,
       0,     0,   304,   306,   307,   309,   311,   312,   313,   317,
     318,   319,   320,   321,   324,   325,   330,   331,   333,   335,
     336,   337,   339,   338,   340,   342,   344,   191,   195,   199,
       0,   214,   226,   234,   265,   300,    20,     0,   345
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -398,  -398,  -310,   301,   383,   -33,  -398,     0,     3,  -102,
    -214,  -398,    69,  -398,  -398,  -398,  -398,  -397,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,   319,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,  -398,
     348,  -398,  -398,  -112,  -398,  -265,  -398,  -398,  -398,  -398,
    -398,  -398,  -398,   314,  -398,  -398
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   192,   200,   193,   341,   194,   184,   429,
     378,   382,   195,   339,   501,   214,   215,   222,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
       4,   181,   381,     5,   182,     4,   271,   500,   275,   318,
       1,   519,   221,   264,   266,   275,   321,   498,   456,   459,
     276,   277,   279,   275,   324,   275,   326,   286,   183,   290,
     291,   292,   185,   186,   187,   188,   189,   274,   185,   186,
     187,   188,   189,   185,   186,   187,   188,   189,   275,   316,
     317,   319,   320,   322,   323,   325,   327,   328,   330,   275,
     329,   338,   197,   198,     1,   355,   619,     1,   441,   344,
     206,   185,   186,   187,   188,   189,   185,   186,   187,   188,
     189,   220,   263,   265,   267,   270,   185,   186,   187,   188,
     189,   275,   444,   275,   445,   185,   186,   187,   188,   189,
     354,   293,   275,   446,   297,   298,   362,   301,   302,   185,
     186,   187,   188,   189,   449,   450,   363,   425,   427,     4,
     457,   458,   272,   185,   186,   187,   188,   189,   331,   185,
     186,   187,   188,   189,   185,   186,   187,   188,   189,   520,
     364,   347,   365,   349,     1,   499,   631,   185,   186,   187,
     188,   189,   185,   186,   187,   188,   189,   366,   438,   190,
     191,   431,   369,   434,   538,   190,   196,   370,   540,   371,
     268,   269,   367,   425,   275,   460,   447,   185,   186,   187,
     188,   189,     4,   461,     4,   464,   466,   467,   428,   410,
     356,   621,   474,     1,   620,   275,   465,   372,   190,   296,
     275,   470,   631,   190,   300,   275,   471,   185,   186,   187,
     188,   189,   373,   190,   314,   275,   473,     4,     4,   356,
     383,   384,   190,   357,   185,   186,   187,   188,   189,   494,
     495,   432,   374,   435,   667,   379,   190,   359,   440,   275,
     497,   525,   275,   502,   185,   186,   187,   188,   189,   380,
     190,   360,   275,   503,   275,   504,   190,   368,   275,   505,
     452,   375,   376,   185,   186,   187,   188,   189,   356,   275,
     506,   475,     4,     4,   219,   426,   442,   275,   507,   219,
     430,   480,     4,   275,   508,   453,   275,   509,   185,   186,
     187,   188,   189,   275,   524,   185,   186,   187,   188,   189,
       1,   541,     1,   542,   219,   433,   185,   186,   187,   188,
     189,   185,   186,   187,   188,   189,   484,     4,   275,   586,
       5,   275,   587,   275,   590,   485,   589,   275,   593,   487,
     592,     1,   598,   595,   190,   436,   275,   600,   275,   601,
       1,   604,   275,   607,   275,   608,   602,   275,   610,   275,
     611,   268,   437,   488,   545,   490,   547,   548,   275,   612,
     609,   553,   275,   613,   275,   615,   491,   614,   275,   625,
     563,   190,   439,   275,   626,   181,   275,   657,   537,   572,
     275,   658,   492,     4,     4,   275,   659,   275,   661,   583,
     454,   455,   185,   186,   187,   188,   189,   493,   199,   201,
     199,   199,   204,   205,   511,   199,   199,   199,   199,   199,
     199,   213,   216,   217,   218,   219,   463,   275,   662,   275,
     663,   273,   219,   468,   627,   278,   280,   281,   199,   283,
     285,   287,   289,   190,   472,   512,   199,   295,   190,   476,
     299,   513,     4,   303,   199,   306,   308,   309,   311,   312,
     313,   315,   514,     4,   356,   185,   186,   187,   188,   189,
     275,   665,   517,   332,   333,   199,   335,   199,   199,   523,
     199,   342,   343,   345,   346,   527,   199,   356,   199,   199,
     199,   199,   202,   203,   528,   530,   532,   207,   208,   209,
     210,   211,   212,   533,   358,   534,   535,   544,   358,   358,
     361,     4,   546,   549,     5,   555,   556,   358,   557,   564,
     282,   284,   567,   288,   377,   568,   569,   377,   294,   477,
     478,   358,   570,   573,   575,   304,   305,   307,   582,   310,
     185,   186,   187,   188,   189,   584,   596,     4,   185,   186,
     187,   188,   189,   603,   605,   415,   606,   334,   616,   336,
     337,   423,   340,   185,   186,   187,   188,   189,   348,   617,
     350,   351,   352,   353,   358,   618,   358,   622,   358,   635,
     636,   358,   185,   186,   187,   188,   189,   638,   639,   640,
     448,   641,   190,   481,   361,   642,   644,   462,   361,   645,
     646,   469,   648,   649,   358,   650,   651,   653,   358,   358,
     654,   656,   358,   358,   361,   660,   629,   361,   664,   666,
     361,   185,   186,   187,   188,   189,   668,   479,   185,   186,
     187,   188,   189,   185,   186,   187,   188,   189,   451,   496,
     181,     0,   358,   537,     0,     0,     0,   516,     0,   518,
       0,     0,   522,     0,     0,   526,     0,     0,   358,     0,
     358,   185,   186,   187,   188,   189,     0,   190,   482,   185,
     186,   187,   188,   189,     0,   190,   483,     0,   358,     0,
       0,   185,   186,   187,   188,   189,     0,     0,     0,   377,
     190,   486,     0,   377,     0,     0,   543,   185,   186,   187,
     188,   189,     0,   551,   552,     0,   554,     0,     0,   190,
     558,   199,   560,   199,     0,     0,   565,   566,     0,     0,
       0,     0,   571,     0,     0,   199,     0,   576,   199,   578,
     579,   581,     0,     0,     0,   585,     0,     0,     0,   358,
       0,     0,     0,   358,     0,     0,   358,     0,   190,   489,
       0,   358,     0,     0,   599,   190,   510,     0,     0,     0,
     190,   515,   185,   186,   187,   188,   189,     0,   185,   186,
     187,   188,   189,     0,     0,     0,     0,     0,     0,     0,
     185,   186,   187,   188,   189,     0,     0,     0,   190,   521,
       0,     0,     0,   559,     0,   561,   190,   529,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   574,   190,   531,
     577,     0,   580,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,   536,     0,     0,     0,     0,
     623,     0,     0,   624,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   377,     0,   358,     0,   358,   358,
       0,     0,     0,     0,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   358,     0,     0,     0,     0,     0,
       0,     0,     0,   358,     0,     0,     0,     0,     0,   219,
     361,    94,    95,     0,   358,   375,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   375,   539,   107,
       0,   108,   109,   385,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   219,     0,
     174,   175,   176,   177,   178,   179,   180,    94,    95,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,   107,     0,   108,   109,   385,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,     1,     0,   174,   175,   176,   177,
     178,   179,   180,    94,    95,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
       0,   107,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     185,   186,   187,   188,   189,   185,   186,   187,   188,   189,
     185,   186,   187,   188,   189,     0,     0,     0,   413,   185,
     186,   187,   188,   189,   185,   186,   187,   188,   189,     0,
     190,     0,   174,   175,   176,   177,   178,   179,   180,    94,
      95,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,     0,   107,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   190,   550,     0,
       0,     0,   190,   562,     0,     0,     0,   219,   588,   185,
     186,   187,   188,   189,     0,     0,   219,   591,     0,     0,
       0,   219,   594,     0,     0,     0,   415,   185,   186,   187,
     188,   189,     0,     0,     0,     0,   190,     0,   174,   175,
     176,   177,   178,   179,   180,    94,    95,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,     0,   107,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   386,     0,     0,   190,   597,     0,     0,
       0,     0,   185,   186,   187,   188,   189,   185,   186,   187,
     188,   189,     0,     0,     1,   628,   185,   186,   187,   188,
     189,   185,   186,   187,   188,   189,   185,   186,   187,   188,
     189,     0,   190,     0,   174,   175,   176,   177,   178,   179,
     180,    94,    95,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,   107,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   630,
     376,     0,     0,     0,   190,   632,     0,     0,   185,   186,
     187,   188,   189,   190,   633,     0,     0,     0,   190,   634,
       0,     0,     0,   190,   637,   185,   186,   187,   188,   189,
     185,   186,   187,   188,   189,     0,     0,     0,     1,     0,
     174,   175,   176,   177,   178,   179,   180,    94,    95,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,   107,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   443,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   190,   643,   185,   186,   187,
     188,   189,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   190,   647,     0,     0,     0,   190,   652,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,     0,   174,   175,   176,   177,
     178,   179,   180,     0,     0,     0,     0,     0,     0,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   275,   443,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,   655,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424
};

static const yytype_int16 yycheck[] =
{
       0,     1,   216,     0,     1,     5,   118,   317,   130,   131,
     130,     3,   114,   115,   116,   130,   131,     3,   283,   284,
     122,   123,   124,   130,   131,   130,   131,   129,     0,   131,
     132,   133,     3,     4,     5,     6,     7,   131,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,   130,   151,
       3,   153,   154,   155,   156,   157,   158,   159,   160,   130,
     131,     3,    95,    96,   130,   131,     3,   130,   131,   171,
     103,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,   114,   115,   116,   117,   118,     3,     4,     5,     6,
       7,   130,   131,   130,   131,     3,     4,     5,     6,     7,
     131,   134,   130,   131,   137,   138,   131,   140,   141,     3,
       4,     5,     6,     7,   130,   131,   131,   219,   220,   119,
     130,   131,   119,     3,     4,     5,     6,     7,   161,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,   131,
     131,   174,   131,   176,   130,   131,   543,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,   131,   270,   130,
     131,   263,   131,   265,   378,   130,   131,   131,   382,   131,
     130,   131,   205,   275,   130,   131,   278,     3,     4,     5,
       6,     7,   182,   285,   184,   287,   288,   289,   221,   115,
     190,   501,   294,   130,   131,   130,   131,   131,   130,   131,
     130,   131,   599,   130,   131,   130,   131,     3,     4,     5,
       6,     7,   131,   130,   131,   130,   131,   217,   218,   219,
     217,   218,   130,   131,     3,     4,     5,     6,     7,   130,
     131,   264,   131,   266,   631,   131,   130,   131,   271,   130,
     131,   343,   130,   131,     3,     4,     5,     6,     7,   131,
     130,   131,   130,   131,   130,   131,   130,   131,   130,   131,
     131,   130,   131,     3,     4,     5,     6,     7,   268,   130,
     131,   131,   272,   273,   130,   131,   273,   130,   131,   130,
     131,   131,   282,   130,   131,   282,   130,   131,     3,     4,
       5,     6,     7,   130,   131,     3,     4,     5,     6,     7,
     130,   131,   130,   131,   130,   131,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,   131,   317,   130,   131,
     317,   130,   131,   130,   131,   131,   428,   130,   131,   131,
     432,   130,   131,   435,   130,   131,   130,   131,   130,   131,
     130,   131,   130,   131,   130,   131,   448,   130,   131,   130,
     131,   130,   131,   131,   387,   131,   389,   390,   130,   131,
     462,   394,   130,   131,   130,   131,   131,   469,   130,   131,
     403,   130,   131,   130,   131,   375,   130,   131,   375,   412,
     130,   131,   131,   383,   384,   130,   131,   130,   131,   422,
     130,   131,     3,     4,     5,     6,     7,   131,    97,    98,
      99,   100,   101,   102,   131,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   130,   131,   130,   131,   130,
     131,   120,   130,   131,   526,   124,   125,   126,   127,   128,
     129,   130,   131,   130,   131,   131,   135,   136,   130,   131,
     139,   131,   442,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   131,   453,   454,     3,     4,     5,     6,     7,
     130,   131,   131,   162,   163,   164,   165,   166,   167,   131,
     169,   170,   171,   172,   173,   131,   175,   477,   177,   178,
     179,   180,    99,   100,   131,   131,   131,   104,   105,   106,
     107,   108,   109,   131,   193,   131,   131,   131,   197,   198,
     199,   501,   131,   131,   501,   131,   131,   206,   131,   131,
     127,   128,   131,   130,   213,   131,   131,   216,   135,   130,
     131,   220,   131,   131,   131,   142,   143,   144,   131,   146,
       3,     4,     5,     6,     7,   131,   131,   537,     3,     4,
       5,     6,     7,   131,   131,   120,   131,   164,   131,   166,
     167,   128,   169,     3,     4,     5,     6,     7,   175,   131,
     177,   178,   179,   180,   263,   131,   265,   131,   267,   131,
     131,   270,     3,     4,     5,     6,     7,   131,   131,   131,
     279,   131,   130,   131,   283,   131,   131,   286,   287,   131,
     131,   290,   131,   131,   293,   131,   131,   131,   297,   298,
     131,   131,   301,   302,   303,   130,   537,   306,   131,   131,
     309,     3,     4,     5,     6,     7,   131,   298,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,   280,   315,
     630,    -1,   331,   630,    -1,    -1,    -1,   336,    -1,   338,
      -1,    -1,   341,    -1,    -1,   344,    -1,    -1,   347,    -1,
     349,     3,     4,     5,     6,     7,    -1,   130,   131,     3,
       4,     5,     6,     7,    -1,   130,   131,    -1,   367,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,   378,
     130,   131,    -1,   382,    -1,    -1,   385,     3,     4,     5,
       6,     7,    -1,   392,   393,    -1,   395,    -1,    -1,   130,
     399,   400,   401,   402,    -1,    -1,   405,   406,    -1,    -1,
      -1,    -1,   411,    -1,    -1,   414,    -1,   416,   417,   418,
     419,   420,    -1,    -1,    -1,   424,    -1,    -1,    -1,   428,
      -1,    -1,    -1,   432,    -1,    -1,   435,    -1,   130,   131,
      -1,   440,    -1,    -1,   443,   130,   131,    -1,    -1,    -1,
     130,   131,     3,     4,     5,     6,     7,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,   130,   131,
      -1,    -1,    -1,   400,    -1,   402,   130,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,   130,   131,
     417,    -1,   419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    -1,    -1,    -1,    -1,
     519,    -1,    -1,   522,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   543,    -1,   545,    -1,   547,   548,
      -1,    -1,    -1,    -1,   553,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   563,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   572,    -1,    -1,    -1,    -1,    -1,   130,
     579,     3,     4,    -1,   583,   130,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,   130,   131,    21,
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
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
     132,   133,   134,   135,   136,   137,   138,     3,     4,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,   132,   133,   134,   135,
     136,   137,   138,     3,     4,    -1,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,    -1,    -1,    -1,   118,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,    -1,
     130,    -1,   132,   133,   134,   135,   136,   137,   138,     3,
       4,    -1,    -1,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   130,   131,    -1,
      -1,    -1,   130,   131,    -1,    -1,    -1,   130,   131,     3,
       4,     5,     6,     7,    -1,    -1,   130,   131,    -1,    -1,
      -1,   130,   131,    -1,    -1,    -1,   120,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,   130,    -1,   132,   133,
     134,   135,   136,   137,   138,     3,     4,    -1,    -1,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    -1,   130,   131,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,    -1,    -1,   130,   131,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,    -1,   130,    -1,   132,   133,   134,   135,   136,   137,
     138,     3,     4,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   130,
     131,    -1,    -1,    -1,   130,   131,    -1,    -1,     3,     4,
       5,     6,     7,   130,   131,    -1,    -1,    -1,   130,   131,
      -1,    -1,    -1,   130,   131,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,    -1,    -1,    -1,   130,    -1,
     132,   133,   134,   135,   136,   137,   138,     3,     4,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    25,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,   130,   131,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,    -1,    -1,    -1,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,    -1,   132,   133,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   130,   140,   141,   146,   147,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,     3,     4,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    21,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,   132,   133,   134,   135,   136,   137,
     138,   146,   147,     0,   147,     3,     4,     5,     6,     7,
     130,   131,   142,   144,   146,   151,   131,   144,   144,   142,
     143,   142,   143,   143,   142,   142,   144,   143,   143,   143,
     143,   143,   143,   142,   154,   155,   142,   142,   142,   130,
     144,   148,   156,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   144,   148,   144,   148,   144,   130,   131,
     144,   272,   147,   142,   131,   130,   148,   148,   142,   148,
     142,   142,   143,   142,   143,   142,   148,   142,   143,   142,
     148,   148,   148,   144,   143,   142,   131,   144,   144,   142,
     131,   144,   144,   142,   143,   143,   142,   143,   142,   142,
     143,   142,   142,   142,   131,   142,   148,     3,   131,   148,
     148,   131,   148,   148,   131,   148,   131,   148,   148,   131,
     148,   144,   142,   142,   143,   142,   143,   143,     3,   152,
     143,   145,   142,   142,   148,   142,   142,   144,   143,   144,
     143,   143,   143,   143,   131,   131,   146,   131,   142,   131,
     131,   142,   131,   131,   131,   131,   131,   144,   131,   131,
     131,   131,   131,   131,   131,   130,   131,   142,   149,   131,
     131,   149,   150,   147,   147,    25,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   148,   131,   148,   144,   148,
     131,   148,   144,   131,   148,   144,   131,   131,   272,   131,
     144,   131,   147,    25,   131,   131,   131,   148,   142,   130,
     131,   269,   131,   147,   130,   131,   274,   130,   131,   274,
     131,   148,   142,   131,   148,   131,   148,   148,   131,   142,
     131,   131,   131,   131,   148,   131,   131,   130,   131,   245,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   130,   131,   282,   131,     3,   131,
     141,   153,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   142,   131,   142,     3,
     131,   131,   142,   131,   131,   148,   142,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   147,   149,   131,
     149,   131,   131,   142,   131,   144,   131,   144,   144,   131,
     131,   142,   142,   144,   142,   131,   131,   131,   142,   143,
     142,   143,   131,   144,   131,   142,   142,   131,   131,   131,
     131,   142,   144,   131,   143,   131,   142,   143,   142,   142,
     143,   142,   131,   144,   131,   142,   131,   131,   131,   148,
     131,   131,   148,   131,   131,   148,   131,   131,   131,   142,
     131,   131,   148,   131,   131,   131,   131,   131,   131,   148,
     131,   131,   131,   131,   148,   131,   131,   131,   131,     3,
     131,   141,   131,   142,   142,   131,   131,   148,   131,   151,
     130,   156,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     130,   131,   131,   131,   131,   131,   131,   156,   131
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   139,   140,   141,   142,   142,   143,   144,   144,   145,
     145,   146,   146,   147,   147,   147,   148,   148,   148,   149,
     149,   149,   150,   150,   151,   151,   151,   151,   151,   152,
     152,   153,   153,   154,   155,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   179,   179,   180,   181,   182,   183,
     183,   183,   183,   184,   184,   184,   184,   185,   185,   185,
     185,   186,   187,   187,   187,   187,   187,   188,   189,   190,
     191,   192,   193,   193,   193,   193,   194,   194,   195,   196,
     197,   197,   197,   197,   198,   198,   198,   198,   199,   199,
     199,   199,   200,   200,   200,   200,   201,   202,   203,   204,
     204,   205,   206,   206,   207,   207,   208,   209,   209,   210,
     211,   211,   212,   213,   213,   214,   215,   215,   216,   217,
     218,   219,   219,   219,   220,   221,   221,   221,   221,   222,
     222,   223,   223,   224,   225,   225,   226,   227,   227,   228,
     228,   229,   230,   230,   231,   232,   233,   233,   234,   235,
     236,   237,   237,   238,   239,   240,   241,   242,   242,   242,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   278,
     279,   280,   281,   282,   283,   284
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
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     5,     5,     5,
       5,     6,     4,     5,     5,     6,     4,     5,     5,     6,
       4,     4,     5,     5,     4,     4,     3,     4,     3,     5,
       4,     4,     5,     5,     6,     4,     4,     5,     4,     5,
       5,     4,     5,     4,     5,     5,     6,     4,     5,     4,
       5,     4,     5,     5,     6,     4,     4,     4,     4,     5,
       4,     4,     4,     3,     5,     4,     4,     4,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     3,     4,     5,     4,     6,     5,     5,     4,     4,
       3,     3,     4,     4,     3,     4,     4,     3,     4,     3,
       4,     4,     3,     4,     4,     4,     4,     3,     4,     4,
       4,     4,     5,     4,     4,     4,     4,     4,     5,     5,
       6,     4,     4,     3,     4,     3,     4,     4,     3,     4,
       3,     4,     4,     4,     3,     3,     3,     4,     4,     4,
       4,     4,     3,     3,     4,     4,     3,     3,     3,     3,
       4,     4,     3,     4,     3,     4,     4,     4,     4,     4,
       4,     3,     4,     3,     4,     6
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
#line 1993 "parser.c" /* yacc.c:1258  */
        break;

    case 4: /* STR  */
#line 77 "../src/parser.y" /* yacc.c:1258  */
      { free(((*yyvaluep).s)); }
#line 1999 "parser.c" /* yacc.c:1258  */
        break;

    case 140: /* start  */
#line 75 "../src/parser.y" /* yacc.c:1258  */
      { run(((*yyvaluep).e));  }
#line 2005 "parser.c" /* yacc.c:1258  */
        break;

    case 141: /* s  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2011 "parser.c" /* yacc.c:1258  */
        break;

    case 142: /* p  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2017 "parser.c" /* yacc.c:1258  */
        break;

    case 143: /* pp  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2023 "parser.c" /* yacc.c:1258  */
        break;

    case 144: /* ps  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2029 "parser.c" /* yacc.c:1258  */
        break;

    case 145: /* pps  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2035 "parser.c" /* yacc.c:1258  */
        break;

    case 146: /* vp  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2041 "parser.c" /* yacc.c:1258  */
        break;

    case 147: /* vps  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2047 "parser.c" /* yacc.c:1258  */
        break;

    case 148: /* opts  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2053 "parser.c" /* yacc.c:1258  */
        break;

    case 149: /* xpb  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2059 "parser.c" /* yacc.c:1258  */
        break;

    case 150: /* xpbs  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2065 "parser.c" /* yacc.c:1258  */
        break;

    case 151: /* np  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2071 "parser.c" /* yacc.c:1258  */
        break;

    case 152: /* sps  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2077 "parser.c" /* yacc.c:1258  */
        break;

    case 153: /* par  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2083 "parser.c" /* yacc.c:1258  */
        break;

    case 154: /* cv  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2089 "parser.c" /* yacc.c:1258  */
        break;

    case 155: /* cvv  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2095 "parser.c" /* yacc.c:1258  */
        break;

    case 156: /* opt  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2101 "parser.c" /* yacc.c:1258  */
        break;

    case 157: /* ivp  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2107 "parser.c" /* yacc.c:1258  */
        break;

    case 158: /* add  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2113 "parser.c" /* yacc.c:1258  */
        break;

    case 159: /* div  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2119 "parser.c" /* yacc.c:1258  */
        break;

    case 160: /* mul  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2125 "parser.c" /* yacc.c:1258  */
        break;

    case 161: /* sub  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2131 "parser.c" /* yacc.c:1258  */
        break;

    case 162: /* and  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2137 "parser.c" /* yacc.c:1258  */
        break;

    case 163: /* bitand  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2143 "parser.c" /* yacc.c:1258  */
        break;

    case 164: /* bitnot  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2149 "parser.c" /* yacc.c:1258  */
        break;

    case 165: /* bitor  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2155 "parser.c" /* yacc.c:1258  */
        break;

    case 166: /* bitxor  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2161 "parser.c" /* yacc.c:1258  */
        break;

    case 167: /* not  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2167 "parser.c" /* yacc.c:1258  */
        break;

    case 168: /* in  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2173 "parser.c" /* yacc.c:1258  */
        break;

    case 169: /* or  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2179 "parser.c" /* yacc.c:1258  */
        break;

    case 170: /* shiftleft  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2185 "parser.c" /* yacc.c:1258  */
        break;

    case 171: /* shiftright  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2191 "parser.c" /* yacc.c:1258  */
        break;

    case 172: /* xor  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2197 "parser.c" /* yacc.c:1258  */
        break;

    case 173: /* eq  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2203 "parser.c" /* yacc.c:1258  */
        break;

    case 174: /* gt  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2209 "parser.c" /* yacc.c:1258  */
        break;

    case 175: /* gte  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2215 "parser.c" /* yacc.c:1258  */
        break;

    case 176: /* lt  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2221 "parser.c" /* yacc.c:1258  */
        break;

    case 177: /* lte  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2227 "parser.c" /* yacc.c:1258  */
        break;

    case 178: /* neq  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2233 "parser.c" /* yacc.c:1258  */
        break;

    case 179: /* if  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2239 "parser.c" /* yacc.c:1258  */
        break;

    case 180: /* select  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2245 "parser.c" /* yacc.c:1258  */
        break;

    case 181: /* until  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2251 "parser.c" /* yacc.c:1258  */
        break;

    case 182: /* while  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2257 "parser.c" /* yacc.c:1258  */
        break;

    case 183: /* execute  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2263 "parser.c" /* yacc.c:1258  */
        break;

    case 184: /* rexx  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2269 "parser.c" /* yacc.c:1258  */
        break;

    case 185: /* run  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2275 "parser.c" /* yacc.c:1258  */
        break;

    case 186: /* abort  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2281 "parser.c" /* yacc.c:1258  */
        break;

    case 187: /* exit  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2287 "parser.c" /* yacc.c:1258  */
        break;

    case 188: /* onerror  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2293 "parser.c" /* yacc.c:1258  */
        break;

    case 189: /* reboot  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2299 "parser.c" /* yacc.c:1258  */
        break;

    case 190: /* trap  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2305 "parser.c" /* yacc.c:1258  */
        break;

    case 191: /* copyfiles  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2311 "parser.c" /* yacc.c:1258  */
        break;

    case 192: /* copylib  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2317 "parser.c" /* yacc.c:1258  */
        break;

    case 193: /* delete  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2323 "parser.c" /* yacc.c:1258  */
        break;

    case 194: /* exists  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2329 "parser.c" /* yacc.c:1258  */
        break;

    case 195: /* fileonly  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2335 "parser.c" /* yacc.c:1258  */
        break;

    case 196: /* foreach  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2341 "parser.c" /* yacc.c:1258  */
        break;

    case 197: /* makeassign  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2347 "parser.c" /* yacc.c:1258  */
        break;

    case 198: /* makedir  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2353 "parser.c" /* yacc.c:1258  */
        break;

    case 199: /* protect  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2359 "parser.c" /* yacc.c:1258  */
        break;

    case 200: /* startup  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2365 "parser.c" /* yacc.c:1258  */
        break;

    case 201: /* textfile  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2371 "parser.c" /* yacc.c:1258  */
        break;

    case 202: /* tooltype  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2377 "parser.c" /* yacc.c:1258  */
        break;

    case 203: /* transcript  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2383 "parser.c" /* yacc.c:1258  */
        break;

    case 204: /* rename  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2389 "parser.c" /* yacc.c:1258  */
        break;

    case 205: /* complete  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2395 "parser.c" /* yacc.c:1258  */
        break;

    case 206: /* debug  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2401 "parser.c" /* yacc.c:1258  */
        break;

    case 207: /* message  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2407 "parser.c" /* yacc.c:1258  */
        break;

    case 208: /* user  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2413 "parser.c" /* yacc.c:1258  */
        break;

    case 209: /* welcome  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2419 "parser.c" /* yacc.c:1258  */
        break;

    case 210: /* working  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2425 "parser.c" /* yacc.c:1258  */
        break;

    case 211: /* database  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2431 "parser.c" /* yacc.c:1258  */
        break;

    case 212: /* earlier  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2437 "parser.c" /* yacc.c:1258  */
        break;

    case 213: /* getassign  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2443 "parser.c" /* yacc.c:1258  */
        break;

    case 214: /* getdevice  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2449 "parser.c" /* yacc.c:1258  */
        break;

    case 215: /* getdiskspace  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2455 "parser.c" /* yacc.c:1258  */
        break;

    case 216: /* getenv  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2461 "parser.c" /* yacc.c:1258  */
        break;

    case 217: /* getsize  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2467 "parser.c" /* yacc.c:1258  */
        break;

    case 218: /* getsum  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2473 "parser.c" /* yacc.c:1258  */
        break;

    case 219: /* getversion  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2479 "parser.c" /* yacc.c:1258  */
        break;

    case 220: /* iconinfo  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2485 "parser.c" /* yacc.c:1258  */
        break;

    case 221: /* dcl  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2491 "parser.c" /* yacc.c:1258  */
        break;

    case 222: /* cus  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2497 "parser.c" /* yacc.c:1258  */
        break;

    case 223: /* askbool  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2503 "parser.c" /* yacc.c:1258  */
        break;

    case 224: /* askchoice  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2509 "parser.c" /* yacc.c:1258  */
        break;

    case 225: /* askdir  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2515 "parser.c" /* yacc.c:1258  */
        break;

    case 226: /* askdisk  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2521 "parser.c" /* yacc.c:1258  */
        break;

    case 227: /* askfile  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2527 "parser.c" /* yacc.c:1258  */
        break;

    case 228: /* asknumber  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2533 "parser.c" /* yacc.c:1258  */
        break;

    case 229: /* askoptions  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2539 "parser.c" /* yacc.c:1258  */
        break;

    case 230: /* askstring  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2545 "parser.c" /* yacc.c:1258  */
        break;

    case 231: /* cat  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2551 "parser.c" /* yacc.c:1258  */
        break;

    case 232: /* expandpath  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2557 "parser.c" /* yacc.c:1258  */
        break;

    case 233: /* fmt  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2563 "parser.c" /* yacc.c:1258  */
        break;

    case 234: /* pathonly  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2569 "parser.c" /* yacc.c:1258  */
        break;

    case 235: /* patmatch  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2575 "parser.c" /* yacc.c:1258  */
        break;

    case 236: /* strlen  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2581 "parser.c" /* yacc.c:1258  */
        break;

    case 237: /* substr  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2587 "parser.c" /* yacc.c:1258  */
        break;

    case 238: /* tackon  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2593 "parser.c" /* yacc.c:1258  */
        break;

    case 239: /* set  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2599 "parser.c" /* yacc.c:1258  */
        break;

    case 240: /* symbolset  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2605 "parser.c" /* yacc.c:1258  */
        break;

    case 241: /* symbolval  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2611 "parser.c" /* yacc.c:1258  */
        break;

    case 242: /* openwbobject  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2617 "parser.c" /* yacc.c:1258  */
        break;

    case 243: /* showwbobject  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2623 "parser.c" /* yacc.c:1258  */
        break;

    case 244: /* closewbobject  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2629 "parser.c" /* yacc.c:1258  */
        break;

    case 245: /* all  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2635 "parser.c" /* yacc.c:1258  */
        break;

    case 246: /* append  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2641 "parser.c" /* yacc.c:1258  */
        break;

    case 247: /* assigns  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2647 "parser.c" /* yacc.c:1258  */
        break;

    case 248: /* choices  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2653 "parser.c" /* yacc.c:1258  */
        break;

    case 249: /* command  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2659 "parser.c" /* yacc.c:1258  */
        break;

    case 250: /* compression  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2665 "parser.c" /* yacc.c:1258  */
        break;

    case 251: /* confirm  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2671 "parser.c" /* yacc.c:1258  */
        break;

    case 252: /* default  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2677 "parser.c" /* yacc.c:1258  */
        break;

    case 253: /* delopts  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2683 "parser.c" /* yacc.c:1258  */
        break;

    case 254: /* dest  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2689 "parser.c" /* yacc.c:1258  */
        break;

    case 255: /* disk  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2695 "parser.c" /* yacc.c:1258  */
        break;

    case 256: /* files  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2701 "parser.c" /* yacc.c:1258  */
        break;

    case 257: /* fonts  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2707 "parser.c" /* yacc.c:1258  */
        break;

    case 258: /* getdefaulttool  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2713 "parser.c" /* yacc.c:1258  */
        break;

    case 259: /* getposition  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2719 "parser.c" /* yacc.c:1258  */
        break;

    case 260: /* getstack  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2725 "parser.c" /* yacc.c:1258  */
        break;

    case 261: /* gettooltype  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2731 "parser.c" /* yacc.c:1258  */
        break;

    case 262: /* help  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2737 "parser.c" /* yacc.c:1258  */
        break;

    case 263: /* infos  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2743 "parser.c" /* yacc.c:1258  */
        break;

    case 264: /* include  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2749 "parser.c" /* yacc.c:1258  */
        break;

    case 265: /* newname  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2755 "parser.c" /* yacc.c:1258  */
        break;

    case 266: /* newpath  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2761 "parser.c" /* yacc.c:1258  */
        break;

    case 267: /* nogauge  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2767 "parser.c" /* yacc.c:1258  */
        break;

    case 268: /* noposition  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2773 "parser.c" /* yacc.c:1258  */
        break;

    case 269: /* noreq  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2779 "parser.c" /* yacc.c:1258  */
        break;

    case 270: /* pattern  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2785 "parser.c" /* yacc.c:1258  */
        break;

    case 271: /* prompt  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2791 "parser.c" /* yacc.c:1258  */
        break;

    case 272: /* quiet  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2797 "parser.c" /* yacc.c:1258  */
        break;

    case 273: /* range  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2803 "parser.c" /* yacc.c:1258  */
        break;

    case 274: /* safe  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2809 "parser.c" /* yacc.c:1258  */
        break;

    case 275: /* setdefaulttool  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2815 "parser.c" /* yacc.c:1258  */
        break;

    case 276: /* setposition  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2821 "parser.c" /* yacc.c:1258  */
        break;

    case 277: /* setstack  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2827 "parser.c" /* yacc.c:1258  */
        break;

    case 278: /* settooltype  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2833 "parser.c" /* yacc.c:1258  */
        break;

    case 279: /* source  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2839 "parser.c" /* yacc.c:1258  */
        break;

    case 280: /* swapcolors  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2845 "parser.c" /* yacc.c:1258  */
        break;

    case 281: /* optional  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2851 "parser.c" /* yacc.c:1258  */
        break;

    case 282: /* resident  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2857 "parser.c" /* yacc.c:1258  */
        break;

    case 283: /* override  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2863 "parser.c" /* yacc.c:1258  */
        break;

    case 284: /* dynopt  */
#line 80 "../src/parser.y" /* yacc.c:1258  */
      { kill(((*yyvaluep).e)); }
#line 2869 "parser.c" /* yacc.c:1258  */
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
#line 3137 "parser.c" /* yacc.c:1651  */
    break;

  case 6:
#line 102 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3143 "parser.c" /* yacc.c:1651  */
    break;

  case 7:
#line 103 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3149 "parser.c" /* yacc.c:1651  */
    break;

  case 8:
#line 104 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3155 "parser.c" /* yacc.c:1651  */
    break;

  case 9:
#line 105 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push((yyvsp[-2].e), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3161 "parser.c" /* yacc.c:1651  */
    break;

  case 12:
#line 108 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3167 "parser.c" /* yacc.c:1651  */
    break;

  case 13:
#line 109 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3173 "parser.c" /* yacc.c:1651  */
    break;

  case 14:
#line 110 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3179 "parser.c" /* yacc.c:1651  */
    break;

  case 15:
#line 111 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3185 "parser.c" /* yacc.c:1651  */
    break;

  case 16:
#line 112 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3191 "parser.c" /* yacc.c:1651  */
    break;

  case 17:
#line 113 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3197 "parser.c" /* yacc.c:1651  */
    break;

  case 18:
#line 114 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3203 "parser.c" /* yacc.c:1651  */
    break;

  case 19:
#line 115 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3209 "parser.c" /* yacc.c:1651  */
    break;

  case 20:
#line 116 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push((yyvsp[-2].e), (yyvsp[-1].e)); }
#line 3215 "parser.c" /* yacc.c:1651  */
    break;

  case 21:
#line 117 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3221 "parser.c" /* yacc.c:1651  */
    break;

  case 22:
#line 118 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3227 "parser.c" /* yacc.c:1651  */
    break;

  case 23:
#line 119 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3233 "parser.c" /* yacc.c:1651  */
    break;

  case 24:
#line 120 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3239 "parser.c" /* yacc.c:1651  */
    break;

  case 25:
#line 121 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3245 "parser.c" /* yacc.c:1651  */
    break;

  case 26:
#line 122 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3251 "parser.c" /* yacc.c:1651  */
    break;

  case 27:
#line 123 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_string((yyvsp[0].s)); }
#line 3257 "parser.c" /* yacc.c:1651  */
    break;

  case 28:
#line 124 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_symref((yyvsp[0].s), LINE); }
#line 3263 "parser.c" /* yacc.c:1651  */
    break;

  case 29:
#line 125 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push((yyvsp[-2].e), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)) ; }
#line 3269 "parser.c" /* yacc.c:1651  */
    break;

  case 30:
#line 126 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push(new_contxt(), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)); }
#line 3275 "parser.c" /* yacc.c:1651  */
    break;

  case 31:
#line 127 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push((yyvsp[-1].e), new_symbol((yyvsp[0].s))); }
#line 3281 "parser.c" /* yacc.c:1651  */
    break;

  case 32:
#line 128 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(new_contxt(), new_symbol((yyvsp[0].s))); }
#line 3287 "parser.c" /* yacc.c:1651  */
    break;

  case 33:
#line 129 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3293 "parser.c" /* yacc.c:1651  */
    break;

  case 34:
#line 130 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3299 "parser.c" /* yacc.c:1651  */
    break;

  case 162:
#line 264 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("+"), LINE, m_add, (yyvsp[-1].e), NUMBER); }
#line 3305 "parser.c" /* yacc.c:1651  */
    break;

  case 163:
#line 265 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("/"), LINE, m_div, (yyvsp[-1].e), NUMBER); }
#line 3311 "parser.c" /* yacc.c:1651  */
    break;

  case 164:
#line 266 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("*"), LINE, m_mul, (yyvsp[-1].e), NUMBER); }
#line 3317 "parser.c" /* yacc.c:1651  */
    break;

  case 165:
#line 267 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("-"), LINE, m_sub, (yyvsp[-1].e), NUMBER); }
#line 3323 "parser.c" /* yacc.c:1651  */
    break;

  case 166:
#line 270 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("AND"), LINE, m_and, (yyvsp[-1].e), NUMBER); }
#line 3329 "parser.c" /* yacc.c:1651  */
    break;

  case 167:
#line 271 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("BITAND"), LINE, m_bitand, (yyvsp[-1].e), NUMBER); }
#line 3335 "parser.c" /* yacc.c:1651  */
    break;

  case 168:
#line 272 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("BITNOT"), LINE, m_bitnot, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3341 "parser.c" /* yacc.c:1651  */
    break;

  case 169:
#line 273 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("BITOR"), LINE, m_bitor, (yyvsp[-1].e), NUMBER); }
#line 3347 "parser.c" /* yacc.c:1651  */
    break;

  case 170:
#line 274 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("BITXOR"), LINE, m_bitxor, (yyvsp[-1].e), NUMBER); }
#line 3353 "parser.c" /* yacc.c:1651  */
    break;

  case 171:
#line 275 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("NOT"), LINE, m_not, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3359 "parser.c" /* yacc.c:1651  */
    break;

  case 172:
#line 276 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("IN"), LINE, m_in, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3365 "parser.c" /* yacc.c:1651  */
    break;

  case 173:
#line 277 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("OR"), LINE, m_or, (yyvsp[-1].e), NUMBER); }
#line 3371 "parser.c" /* yacc.c:1651  */
    break;

  case 174:
#line 278 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("shiftleft"), LINE, m_shiftleft, (yyvsp[-1].e), NUMBER); }
#line 3377 "parser.c" /* yacc.c:1651  */
    break;

  case 175:
#line 279 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("shiftright"), LINE, m_shiftright, (yyvsp[-1].e), NUMBER); }
#line 3383 "parser.c" /* yacc.c:1651  */
    break;

  case 176:
#line 280 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("XOR"), LINE, m_xor, (yyvsp[-1].e), NUMBER); }
#line 3389 "parser.c" /* yacc.c:1651  */
    break;

  case 177:
#line 283 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("="), LINE, m_eq, (yyvsp[-1].e), NUMBER); }
#line 3395 "parser.c" /* yacc.c:1651  */
    break;

  case 178:
#line 284 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup(">"), LINE, m_gt, (yyvsp[-1].e), NUMBER); }
#line 3401 "parser.c" /* yacc.c:1651  */
    break;

  case 179:
#line 285 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup(">="), LINE, m_gte, (yyvsp[-1].e), NUMBER); }
#line 3407 "parser.c" /* yacc.c:1651  */
    break;

  case 180:
#line 286 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("<"), LINE, m_lt, (yyvsp[-1].e), NUMBER); }
#line 3413 "parser.c" /* yacc.c:1651  */
    break;

  case 181:
#line 287 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("<="), LINE, m_lte, (yyvsp[-1].e), NUMBER); }
#line 3419 "parser.c" /* yacc.c:1651  */
    break;

  case 182:
#line 288 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("<>"), LINE, m_neq, (yyvsp[-1].e), NUMBER); }
#line 3425 "parser.c" /* yacc.c:1651  */
    break;

  case 183:
#line 291 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3431 "parser.c" /* yacc.c:1651  */
    break;

  case 184:
#line 292 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3437 "parser.c" /* yacc.c:1651  */
    break;

  case 185:
#line 293 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3443 "parser.c" /* yacc.c:1651  */
    break;

  case 186:
#line 294 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("select"), LINE, m_select, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3449 "parser.c" /* yacc.c:1651  */
    break;

  case 187:
#line 295 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("until"), LINE, m_until, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3455 "parser.c" /* yacc.c:1651  */
    break;

  case 188:
#line 296 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("while"), LINE, m_while, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3461 "parser.c" /* yacc.c:1651  */
    break;

  case 189:
#line 299 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3467 "parser.c" /* yacc.c:1651  */
    break;

  case 190:
#line 300 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3473 "parser.c" /* yacc.c:1651  */
    break;

  case 191:
#line 301 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3479 "parser.c" /* yacc.c:1651  */
    break;

  case 192:
#line 302 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, (yyvsp[-1].e), NUMBER); }
#line 3485 "parser.c" /* yacc.c:1651  */
    break;

  case 193:
#line 303 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3491 "parser.c" /* yacc.c:1651  */
    break;

  case 194:
#line 304 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3497 "parser.c" /* yacc.c:1651  */
    break;

  case 195:
#line 305 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3503 "parser.c" /* yacc.c:1651  */
    break;

  case 196:
#line 306 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, (yyvsp[-1].e), NUMBER); }
#line 3509 "parser.c" /* yacc.c:1651  */
    break;

  case 197:
#line 307 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3515 "parser.c" /* yacc.c:1651  */
    break;

  case 198:
#line 308 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3521 "parser.c" /* yacc.c:1651  */
    break;

  case 199:
#line 309 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3527 "parser.c" /* yacc.c:1651  */
    break;

  case 200:
#line 310 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, (yyvsp[-1].e), NUMBER); }
#line 3533 "parser.c" /* yacc.c:1651  */
    break;

  case 201:
#line 313 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("abort"), LINE, m_abort, (yyvsp[-1].e), NUMBER); }
#line 3539 "parser.c" /* yacc.c:1651  */
    break;

  case 202:
#line 314 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3545 "parser.c" /* yacc.c:1651  */
    break;

  case 203:
#line 315 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3551 "parser.c" /* yacc.c:1651  */
    break;

  case 204:
#line 316 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3557 "parser.c" /* yacc.c:1651  */
    break;

  case 205:
#line 317 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, (yyvsp[-1].e), NUMBER); }
#line 3563 "parser.c" /* yacc.c:1651  */
    break;

  case 206:
#line 318 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, NULL, NUMBER); }
#line 3569 "parser.c" /* yacc.c:1651  */
    break;

  case 207:
#line 319 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("onerror"), LINE, m_procedure, push(new_contxt(),
                                                        new_custom(strdup("@onerror"), LINE, NULL, (yyvsp[-1].e))), DANGLE); }
#line 3576 "parser.c" /* yacc.c:1651  */
    break;

  case 208:
#line 321 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("reboot"), LINE, m_reboot, NULL, NUMBER); }
#line 3582 "parser.c" /* yacc.c:1651  */
    break;

  case 209:
#line 322 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("trap"), LINE, m_trap, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3588 "parser.c" /* yacc.c:1651  */
    break;

  case 210:
#line 325 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("copyfiles"), LINE, m_copyfiles, (yyvsp[-1].e), NUMBER); }
#line 3594 "parser.c" /* yacc.c:1651  */
    break;

  case 211:
#line 326 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("copylib"), LINE, m_copylib, (yyvsp[-1].e), NUMBER); }
#line 3600 "parser.c" /* yacc.c:1651  */
    break;

  case 212:
#line 327 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3606 "parser.c" /* yacc.c:1651  */
    break;

  case 213:
#line 328 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3612 "parser.c" /* yacc.c:1651  */
    break;

  case 214:
#line 329 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3618 "parser.c" /* yacc.c:1651  */
    break;

  case 215:
#line 330 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3624 "parser.c" /* yacc.c:1651  */
    break;

  case 216:
#line 331 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3630 "parser.c" /* yacc.c:1651  */
    break;

  case 217:
#line 332 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3636 "parser.c" /* yacc.c:1651  */
    break;

  case 218:
#line 333 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("fileonly"), LINE, m_fileonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3642 "parser.c" /* yacc.c:1651  */
    break;

  case 219:
#line 334 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("foreach"), LINE, m_foreach, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3648 "parser.c" /* yacc.c:1651  */
    break;

  case 220:
#line 335 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3654 "parser.c" /* yacc.c:1651  */
    break;

  case 221:
#line 336 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, (yyvsp[-1].e), NUMBER); }
#line 3660 "parser.c" /* yacc.c:1651  */
    break;

  case 222:
#line 337 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3666 "parser.c" /* yacc.c:1651  */
    break;

  case 223:
#line 338 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3672 "parser.c" /* yacc.c:1651  */
    break;

  case 224:
#line 339 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3678 "parser.c" /* yacc.c:1651  */
    break;

  case 225:
#line 340 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3684 "parser.c" /* yacc.c:1651  */
    break;

  case 226:
#line 341 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3690 "parser.c" /* yacc.c:1651  */
    break;

  case 227:
#line 342 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3696 "parser.c" /* yacc.c:1651  */
    break;

  case 228:
#line 343 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3702 "parser.c" /* yacc.c:1651  */
    break;

  case 229:
#line 344 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, (yyvsp[-1].e), NUMBER); }
#line 3708 "parser.c" /* yacc.c:1651  */
    break;

  case 230:
#line 345 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3714 "parser.c" /* yacc.c:1651  */
    break;

  case 231:
#line 346 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3720 "parser.c" /* yacc.c:1651  */
    break;

  case 232:
#line 347 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3726 "parser.c" /* yacc.c:1651  */
    break;

  case 233:
#line 348 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3732 "parser.c" /* yacc.c:1651  */
    break;

  case 234:
#line 349 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3738 "parser.c" /* yacc.c:1651  */
    break;

  case 235:
#line 350 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), new_symref(strdup("@app-name"), LINE)), (yyvsp[-1].e)), NUMBER); }
#line 3744 "parser.c" /* yacc.c:1651  */
    break;

  case 236:
#line 351 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("textfile"), LINE, m_textfile, (yyvsp[-1].e), NUMBER); }
#line 3750 "parser.c" /* yacc.c:1651  */
    break;

  case 237:
#line 352 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("tooltype"), LINE, m_tooltype, (yyvsp[-1].e), NUMBER); }
#line 3756 "parser.c" /* yacc.c:1651  */
    break;

  case 238:
#line 353 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("transcript"), LINE, m_transcript, (yyvsp[-1].e), NUMBER); }
#line 3762 "parser.c" /* yacc.c:1651  */
    break;

  case 239:
#line 354 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3768 "parser.c" /* yacc.c:1651  */
    break;

  case 240:
#line 355 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, (yyvsp[-1].e), NUMBER); }
#line 3774 "parser.c" /* yacc.c:1651  */
    break;

  case 241:
#line 358 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("complete"), LINE, m_complete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3780 "parser.c" /* yacc.c:1651  */
    break;

  case 242:
#line 359 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, (yyvsp[-1].e), NUMBER); }
#line 3786 "parser.c" /* yacc.c:1651  */
    break;

  case 243:
#line 360 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, NULL, NUMBER); }
#line 3792 "parser.c" /* yacc.c:1651  */
    break;

  case 244:
#line 361 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3798 "parser.c" /* yacc.c:1651  */
    break;

  case 245:
#line 362 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, (yyvsp[-1].e), NUMBER); }
#line 3804 "parser.c" /* yacc.c:1651  */
    break;

  case 246:
#line 363 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("user"), LINE, m_user, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3810 "parser.c" /* yacc.c:1651  */
    break;

  case 247:
#line 364 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, (yyvsp[-1].e), NUMBER); }
#line 3816 "parser.c" /* yacc.c:1651  */
    break;

  case 248:
#line 365 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, NULL, NUMBER); }
#line 3822 "parser.c" /* yacc.c:1651  */
    break;

  case 249:
#line 366 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("working"), LINE, m_working, (yyvsp[-1].e), NUMBER); }
#line 3828 "parser.c" /* yacc.c:1651  */
    break;

  case 250:
#line 369 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3834 "parser.c" /* yacc.c:1651  */
    break;

  case 251:
#line 370 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, (yyvsp[-1].e), STRING); }
#line 3840 "parser.c" /* yacc.c:1651  */
    break;

  case 252:
#line 371 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("earlier"), LINE, m_earlier, (yyvsp[-1].e), NUMBER); }
#line 3846 "parser.c" /* yacc.c:1651  */
    break;

  case 253:
#line 372 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3852 "parser.c" /* yacc.c:1651  */
    break;

  case 254:
#line 373 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, (yyvsp[-1].e), STRING); }
#line 3858 "parser.c" /* yacc.c:1651  */
    break;

  case 255:
#line 374 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getdevice"), LINE, m_getdevice, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3864 "parser.c" /* yacc.c:1651  */
    break;

  case 256:
#line 375 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3870 "parser.c" /* yacc.c:1651  */
    break;

  case 257:
#line 376 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, (yyvsp[-1].e), NUMBER); }
#line 3876 "parser.c" /* yacc.c:1651  */
    break;

  case 258:
#line 377 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getenv"), LINE, m_getenv, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3882 "parser.c" /* yacc.c:1651  */
    break;

  case 259:
#line 378 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getsize"), LINE, m_getsize, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3888 "parser.c" /* yacc.c:1651  */
    break;

  case 260:
#line 379 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getsum"), LINE, m_getsum, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3894 "parser.c" /* yacc.c:1651  */
    break;

  case 261:
#line 380 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, NULL, NUMBER); }
#line 3900 "parser.c" /* yacc.c:1651  */
    break;

  case 262:
#line 381 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3906 "parser.c" /* yacc.c:1651  */
    break;

  case 263:
#line 382 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3912 "parser.c" /* yacc.c:1651  */
    break;

  case 264:
#line 383 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("iconinfo"), LINE, m_iconinfo, (yyvsp[-1].e), NUMBER); }
#line 3918 "parser.c" /* yacc.c:1651  */
    break;

  case 265:
#line 386 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-3].s), LINE, (yyvsp[-2].e), (yyvsp[-1].e))), NUMBER); }
#line 3924 "parser.c" /* yacc.c:1651  */
    break;

  case 266:
#line 387 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, (yyvsp[-1].e), NULL)), NUMBER); }
#line 3930 "parser.c" /* yacc.c:1651  */
    break;

  case 267:
#line 388 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, NULL, (yyvsp[-1].e))), NUMBER); }
#line 3936 "parser.c" /* yacc.c:1651  */
    break;

  case 268:
#line 389 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-1].s), LINE, NULL, NULL)), NUMBER); }
#line 3942 "parser.c" /* yacc.c:1651  */
    break;

  case 269:
#line 390 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_cusref((yyvsp[-2].s), LINE, (yyvsp[-1].e)); }
#line 3948 "parser.c" /* yacc.c:1651  */
    break;

  case 270:
#line 391 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_cusref((yyvsp[-1].s), LINE, NULL); }
#line 3954 "parser.c" /* yacc.c:1651  */
    break;

  case 271:
#line 394 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, NULL, NUMBER); }
#line 3960 "parser.c" /* yacc.c:1651  */
    break;

  case 272:
#line 395 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, (yyvsp[-1].e), NUMBER); }
#line 3966 "parser.c" /* yacc.c:1651  */
    break;

  case 273:
#line 396 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askchoice"), LINE, m_askchoice, (yyvsp[-1].e), NUMBER); }
#line 3972 "parser.c" /* yacc.c:1651  */
    break;

  case 274:
#line 397 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, NULL, STRING); }
#line 3978 "parser.c" /* yacc.c:1651  */
    break;

  case 275:
#line 398 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, (yyvsp[-1].e), STRING); }
#line 3984 "parser.c" /* yacc.c:1651  */
    break;

  case 276:
#line 399 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askdisk"), LINE, m_askdisk, (yyvsp[-1].e), NUMBER); }
#line 3990 "parser.c" /* yacc.c:1651  */
    break;

  case 277:
#line 400 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, NULL, STRING); }
#line 3996 "parser.c" /* yacc.c:1651  */
    break;

  case 278:
#line 401 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, (yyvsp[-1].e), STRING); }
#line 4002 "parser.c" /* yacc.c:1651  */
    break;

  case 279:
#line 402 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, NULL, NUMBER); }
#line 4008 "parser.c" /* yacc.c:1651  */
    break;

  case 280:
#line 403 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, (yyvsp[-1].e), NUMBER); }
#line 4014 "parser.c" /* yacc.c:1651  */
    break;

  case 281:
#line 404 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askoptions"), LINE, m_askoptions, (yyvsp[-1].e), NUMBER); }
#line 4020 "parser.c" /* yacc.c:1651  */
    break;

  case 282:
#line 405 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, NULL, STRING); }
#line 4026 "parser.c" /* yacc.c:1651  */
    break;

  case 283:
#line 406 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, (yyvsp[-1].e), STRING); }
#line 4032 "parser.c" /* yacc.c:1651  */
    break;

  case 284:
#line 409 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("cat"), LINE, m_cat, (yyvsp[-1].e), STRING); }
#line 4038 "parser.c" /* yacc.c:1651  */
    break;

  case 285:
#line 410 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("expandpath"), LINE, m_expandpath, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4044 "parser.c" /* yacc.c:1651  */
    break;

  case 286:
#line 411 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native((yyvsp[-2].s), LINE, m_fmt, (yyvsp[-1].e), STRING); }
#line 4050 "parser.c" /* yacc.c:1651  */
    break;

  case 287:
#line 412 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native((yyvsp[-1].s), LINE, m_fmt, NULL, STRING); }
#line 4056 "parser.c" /* yacc.c:1651  */
    break;

  case 288:
#line 413 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("pathonly"), LINE, m_pathonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4062 "parser.c" /* yacc.c:1651  */
    break;

  case 289:
#line 414 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("patmatch"), LINE, m_patmatch, (yyvsp[-1].e), NUMBER); }
#line 4068 "parser.c" /* yacc.c:1651  */
    break;

  case 290:
#line 415 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("strlen"), LINE, m_strlen, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4074 "parser.c" /* yacc.c:1651  */
    break;

  case 291:
#line 416 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, (yyvsp[-1].e), STRING); }
#line 4080 "parser.c" /* yacc.c:1651  */
    break;

  case 292:
#line 417 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, push((yyvsp[-2].e), (yyvsp[-1].e)), STRING); }
#line 4086 "parser.c" /* yacc.c:1651  */
    break;

  case 293:
#line 418 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("tackon"), LINE, m_tackon, (yyvsp[-1].e), STRING); }
#line 4092 "parser.c" /* yacc.c:1651  */
    break;

  case 294:
#line 421 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("set"), LINE, m_set, (yyvsp[-1].e), DANGLE); }
#line 4098 "parser.c" /* yacc.c:1651  */
    break;

  case 295:
#line 422 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("symbolset"), LINE, m_symbolset, (yyvsp[-1].e), DANGLE); }
#line 4104 "parser.c" /* yacc.c:1651  */
    break;

  case 296:
#line 423 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("symbolval"), LINE, m_symbolval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4110 "parser.c" /* yacc.c:1651  */
    break;

  case 297:
#line 426 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4116 "parser.c" /* yacc.c:1651  */
    break;

  case 298:
#line 427 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4122 "parser.c" /* yacc.c:1651  */
    break;

  case 299:
#line 428 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4128 "parser.c" /* yacc.c:1651  */
    break;

  case 300:
#line 429 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4134 "parser.c" /* yacc.c:1651  */
    break;

  case 301:
#line 430 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("showwbobject"), LINE, m_showwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4140 "parser.c" /* yacc.c:1651  */
    break;

  case 302:
#line 431 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_native(strdup("closewbobject"), LINE, m_closewbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4146 "parser.c" /* yacc.c:1651  */
    break;

  case 303:
#line 434 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("all"), OPT_ALL, NULL); }
#line 4152 "parser.c" /* yacc.c:1651  */
    break;

  case 304:
#line 435 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("append"), OPT_APPEND, (yyvsp[-1].e)); }
#line 4158 "parser.c" /* yacc.c:1651  */
    break;

  case 305:
#line 436 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); }
#line 4164 "parser.c" /* yacc.c:1651  */
    break;

  case 306:
#line 437 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("choices"), OPT_CHOICES, (yyvsp[-1].e)); }
#line 4170 "parser.c" /* yacc.c:1651  */
    break;

  case 307:
#line 438 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("command"), OPT_COMMAND, (yyvsp[-1].e)); }
#line 4176 "parser.c" /* yacc.c:1651  */
    break;

  case 308:
#line 439 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("compression"), OPT_COMPRESSION, NULL); }
#line 4182 "parser.c" /* yacc.c:1651  */
    break;

  case 309:
#line 440 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, push(new_contxt(), (yyvsp[-1].e))); }
#line 4188 "parser.c" /* yacc.c:1651  */
    break;

  case 310:
#line 441 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, NULL); }
#line 4194 "parser.c" /* yacc.c:1651  */
    break;

  case 311:
#line 442 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), (yyvsp[-1].e))); }
#line 4200 "parser.c" /* yacc.c:1651  */
    break;

  case 312:
#line 443 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, (yyvsp[-1].e)); }
#line 4206 "parser.c" /* yacc.c:1651  */
    break;

  case 313:
#line 444 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), (yyvsp[-1].e))); }
#line 4212 "parser.c" /* yacc.c:1651  */
    break;

  case 314:
#line 445 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("disk"), OPT_DISK, NULL); }
#line 4218 "parser.c" /* yacc.c:1651  */
    break;

  case 315:
#line 446 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("files"), OPT_FILES, NULL); }
#line 4224 "parser.c" /* yacc.c:1651  */
    break;

  case 316:
#line 447 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("fonts"), OPT_FONTS, NULL); }
#line 4230 "parser.c" /* yacc.c:1651  */
    break;

  case 317:
#line 448 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4236 "parser.c" /* yacc.c:1651  */
    break;

  case 318:
#line 449 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("getposition"), OPT_GETPOSITION, (yyvsp[-1].e)); }
#line 4242 "parser.c" /* yacc.c:1651  */
    break;

  case 319:
#line 450 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4248 "parser.c" /* yacc.c:1651  */
    break;

  case 320:
#line 451 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, (yyvsp[-1].e)); }
#line 4254 "parser.c" /* yacc.c:1651  */
    break;

  case 321:
#line 452 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, (yyvsp[-1].e)); }
#line 4260 "parser.c" /* yacc.c:1651  */
    break;

  case 322:
#line 453 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4266 "parser.c" /* yacc.c:1651  */
    break;

  case 323:
#line 454 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("infos"), OPT_INFOS, NULL); }
#line 4272 "parser.c" /* yacc.c:1651  */
    break;

  case 324:
#line 455 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4278 "parser.c" /* yacc.c:1651  */
    break;

  case 325:
#line 456 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), (yyvsp[-1].e))); }
#line 4284 "parser.c" /* yacc.c:1651  */
    break;

  case 326:
#line 457 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("newpath"), OPT_NEWPATH, NULL); }
#line 4290 "parser.c" /* yacc.c:1651  */
    break;

  case 327:
#line 458 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); }
#line 4296 "parser.c" /* yacc.c:1651  */
    break;

  case 328:
#line 459 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); }
#line 4302 "parser.c" /* yacc.c:1651  */
    break;

  case 329:
#line 460 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("noreq"), OPT_NOREQ, NULL); }
#line 4308 "parser.c" /* yacc.c:1651  */
    break;

  case 330:
#line 461 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), (yyvsp[-1].e))); }
#line 4314 "parser.c" /* yacc.c:1651  */
    break;

  case 331:
#line 462 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("prompt"), OPT_PROMPT, (yyvsp[-1].e)); }
#line 4320 "parser.c" /* yacc.c:1651  */
    break;

  case 332:
#line 463 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("quiet"), OPT_QUIET, NULL); }
#line 4326 "parser.c" /* yacc.c:1651  */
    break;

  case 333:
#line 464 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("range"), OPT_RANGE, (yyvsp[-1].e)); }
#line 4332 "parser.c" /* yacc.c:1651  */
    break;

  case 334:
#line 465 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("safe"), OPT_SAFE, NULL); }
#line 4338 "parser.c" /* yacc.c:1651  */
    break;

  case 335:
#line 466 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4344 "parser.c" /* yacc.c:1651  */
    break;

  case 336:
#line 467 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("setposition"), OPT_SETPOSITION, (yyvsp[-1].e)); }
#line 4350 "parser.c" /* yacc.c:1651  */
    break;

  case 337:
#line 468 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4356 "parser.c" /* yacc.c:1651  */
    break;

  case 338:
#line 469 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, (yyvsp[-1].e)); }
#line 4362 "parser.c" /* yacc.c:1651  */
    break;

  case 339:
#line 470 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4368 "parser.c" /* yacc.c:1651  */
    break;

  case 340:
#line 471 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4374 "parser.c" /* yacc.c:1651  */
    break;

  case 341:
#line 472 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); }
#line 4380 "parser.c" /* yacc.c:1651  */
    break;

  case 342:
#line 473 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, (yyvsp[-1].e)); }
#line 4386 "parser.c" /* yacc.c:1651  */
    break;

  case 343:
#line 474 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("resident"), OPT_RESIDENT, NULL); }
#line 4392 "parser.c" /* yacc.c:1651  */
    break;

  case 344:
#line 475 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4398 "parser.c" /* yacc.c:1651  */
    break;

  case 345:
#line 476 "../src/parser.y" /* yacc.c:1651  */
    { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(push(new_contxt(), (yyvsp[-3].e)), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4404 "parser.c" /* yacc.c:1651  */
    break;


#line 4408 "parser.c" /* yacc.c:1651  */
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
#line 478 "../src/parser.y" /* yacc.c:1910  */


