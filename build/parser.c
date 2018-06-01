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

#include "all.h"
#include "alloc.h"
#include "eval.h"
#include "init.h"
#include "lexer.h"

#include <string.h>

#line 76 "parser.c" /* yacc.c:339  */

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
    ASKUSER = 344,
    ASSIGNS = 345,
    CHOICES = 346,
    COMMAND = 347,
    COMPRESSION = 348,
    CONFIRM = 349,
    DEFAULT = 350,
    DELOPTS = 351,
    DEST = 352,
    DISK = 353,
    FAIL = 354,
    FILES = 355,
    FONTS = 356,
    FORCE = 357,
    GETDEFAULTTOOL = 358,
    GETPOSITION = 359,
    GETSTACK = 360,
    GETTOOLTYPE = 361,
    HELP = 362,
    INFOS = 363,
    INCLUDE = 364,
    NEWNAME = 365,
    NEWPATH = 366,
    NOFAIL = 367,
    NOGAUGE = 368,
    NOPOSITION = 369,
    NOREQ = 370,
    OKNODELETE = 371,
    PATTERN = 372,
    PROMPT = 373,
    QUIET = 374,
    RANGE = 375,
    SAFE = 376,
    SETDEFAULTTOOL = 377,
    SETPOSITION = 378,
    SETSTACK = 379,
    SETTOOLTYPE = 380,
    SOURCE = 381,
    SWAPCOLORS = 382,
    OPTIONAL = 383,
    RESIDENT = 384,
    OVERRIDE = 385
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
#define ASKUSER 344
#define ASSIGNS 345
#define CHOICES 346
#define COMMAND 347
#define COMPRESSION 348
#define CONFIRM 349
#define DEFAULT 350
#define DELOPTS 351
#define DEST 352
#define DISK 353
#define FAIL 354
#define FILES 355
#define FONTS 356
#define FORCE 357
#define GETDEFAULTTOOL 358
#define GETPOSITION 359
#define GETSTACK 360
#define GETTOOLTYPE 361
#define HELP 362
#define INFOS 363
#define INCLUDE 364
#define NEWNAME 365
#define NEWPATH 366
#define NOFAIL 367
#define NOGAUGE 368
#define NOPOSITION 369
#define NOREQ 370
#define OKNODELETE 371
#define PATTERN 372
#define PROMPT 373
#define QUIET 374
#define RANGE 375
#define SAFE 376
#define SETDEFAULTTOOL 377
#define SETPOSITION 378
#define SETSTACK 379
#define SETTOOLTYPE 380
#define SOURCE 381
#define SWAPCOLORS 382
#define OPTIONAL 383
#define RESIDENT 384
#define OVERRIDE 385

/* Value type.  */



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 381 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  172
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1468

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  140
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  145
/* YYNRULES -- Number of rules.  */
#define YYNRULES  316
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  600

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   385

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
     131,   132,   135,   133,     2,   136,     2,   134,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     139,   137,   138,     2,     2,     2,     2,     2,     2,     2,
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
     125,   126,   127,   128,   129,   130
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    86,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   248,   249,   250,
     251,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   267,   268,   269,   270,   271,   272,   275,   276,
     277,   278,   279,   282,   283,   284,   285,   286,   287,   290,
     291,   292,   293,   294,   295,   297,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     326,   327,   328,   329,   330,   332,   333,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   352,   353,   354,   355,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   385,   386,
     387,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435
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
  "TACKON", "SET", "SYMBOLSET", "SYMBOLVAL", "ALL", "APPEND", "ASKUSER",
  "ASSIGNS", "CHOICES", "COMMAND", "COMPRESSION", "CONFIRM", "DEFAULT",
  "DELOPTS", "DEST", "DISK", "FAIL", "FILES", "FONTS", "FORCE",
  "GETDEFAULTTOOL", "GETPOSITION", "GETSTACK", "GETTOOLTYPE", "HELP",
  "INFOS", "INCLUDE", "NEWNAME", "NEWPATH", "NOFAIL", "NOGAUGE",
  "NOPOSITION", "NOREQ", "OKNODELETE", "PATTERN", "PROMPT", "QUIET",
  "RANGE", "SAFE", "SETDEFAULTTOOL", "SETPOSITION", "SETSTACK",
  "SETTOOLTYPE", "SOURCE", "SWAPCOLORS", "OPTIONAL", "RESIDENT",
  "OVERRIDE", "'('", "')'", "'+'", "'/'", "'*'", "'-'", "'='", "'>'",
  "'<'", "$accept", "start", "s", "p", "pp", "ps", "pps", "vps", "opts",
  "vpb", "xpb", "np", "sps", "par", "cv", "cvv", "opt", "vp", "add", "div",
  "mul", "sub", "and", "bitand", "bitnot", "bitor", "bitxor", "not", "in",
  "or", "shiftleft", "shiftright", "xor", "eq", "gt", "gte", "lt", "lte",
  "neq", "if", "select", "until", "while", "execute", "rexx", "run",
  "abort", "exit", "onerror", "trap", "copyfiles", "copylib", "delete",
  "exists", "fileonly", "foreach", "makeassign", "makedir", "protect",
  "startup", "textfile", "tooltype", "transcript", "rename", "complete",
  "debug", "message", "user", "welcome", "working", "database", "earlier",
  "getassign", "getdevice", "getdiskspace", "getenv", "getsize", "getsum",
  "getversion", "iconinfo", "dcl", "cus", "askbool", "askchoice", "askdir",
  "askdisk", "askfile", "asknumber", "askoptions", "askstring", "cat",
  "expandpath", "fmt", "pathonly", "patmatch", "strlen", "substr",
  "tackon", "set", "symbolset", "symbolval", "all", "append", "askuser",
  "assigns", "choices", "command", "compression", "confirm", "default",
  "delopts", "dest", "disk", "fail", "files", "fonts", "force",
  "getdefaulttool", "getposition", "getstack", "gettooltype", "help",
  "infos", "include", "newname", "newpath", "nofail", "nogauge",
  "noposition", "noreq", "oknodelete", "pattern", "prompt", "quiet",
  "range", "safe", "setdefaulttool", "setposition", "setstack",
  "settooltype", "source", "swapcolors", "optional", "resident",
  "override", YY_NULLPTR
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
     385,    40,    41,    43,    47,    42,    45,    61,    62,    60
};
# endif

#define YYPACT_NINF -299

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-299)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -105,  1329,    45,  -299,  -105,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,     9,
      54,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,    83,   -82,   175,   -61,   -61,   175,   175,
     175,   175,   175,   175,   175,   175,   -61,   -61,   175,   175,
     175,   175,   175,    73,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   114,   -61,    93,  -103,   -61,   -68,
     -61,   -66,   -59,   -61,   -57,   175,   175,   175,   175,   175,
     175,   175,    96,   175,   175,   175,   175,   175,   175,   175,
     175,   175,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,   126,  -299,  -299,  -299,   150,   175,   -22,   -10,    -4,
       4,     6,    12,   175,    32,    40,    51,    65,    70,    81,
     101,   258,   106,   108,   175,   258,   112,   123,   -51,   -49,
     -40,   217,   781,  -299,   280,   138,   918,   146,  -299,   -82,
    1330,   -37,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,   -30,   -23,   -19,
     148,   -82,   308,     3,    29,   410,    37,   -61,    39,    43,
     415,    57,   161,   431,   443,   170,   453,   463,   469,   172,
     176,   474,   184,   190,   194,   196,   198,   200,  -299,    59,
      62,    35,  -299,    78,    80,  -299,    86,    94,  -299,    97,
    -299,    99,   104,  -299,   111,   479,   215,   218,   222,   223,
     484,   227,   175,    30,  -299,   489,   230,   503,   232,   532,
     233,   234,   237,   238,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,   874,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,   258,  -299,  -299,  -299,   879,  -299,  -299,
    -299,  -299,   116,  -299,   118,  -299,   120,  -299,   241,  -299,
     242,  -299,   122,  -299,   248,   249,   175,   252,   260,   175,
     175,   262,   884,   175,   175,   175,   263,   264,   266,   271,
     274,   175,   175,   175,   175,   175,   291,   175,   175,   292,
     293,   294,   297,   298,   299,   175,   175,   175,   300,   175,
     175,   175,   175,   175,   310,   175,   319,   175,  -299,  -299,
    -299,  -299,   128,    89,  -299,   320,  -299,   321,  1055,  -299,
     322,    56,  -299,   330,  -299,   136,   644,  -299,   145,  -299,
     158,   167,  -299,  -299,  -299,  -299,   188,  -299,  -299,  1192,
    -299,   331,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,   335,  -299,   365,  -299,  -299,
     366,    36,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,   367,  -299,  -299,   175,
    -299,  -299,   175,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,   368,  -299,  -299,   889,   898,  -299,  -299,   370,
     371,   903,   372,  -299,  -299,  -299,  -299,  -299,   373,   379,
     380,   381,  1019,  -299,   383,   384,  -299,  -299,  -299,  -299,
    -299,  -299,   386,  1033,   389,  -299,   390,   391,   392,  1038,
     394,   395,  -299,  1149,  -299,   396,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
     397,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,    12,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   137,   136,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,    11,    23,    22,    19,    20,    21,   244,
       8,     0,     5,     4,   261,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,     0,     0,     0,     0,    16,     0,
       0,     0,    14,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    52,    51,    53,    54,    55,    56,
      57,    58,    59,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    60,    73,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,     0,
       0,     0,   245,     0,     0,   248,     0,     0,   251,     0,
     253,     0,     0,   256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   243,     7,   260,     6,   161,   162,
     163,   164,   165,   166,     0,   168,   169,   170,   171,   174,
     176,   177,    17,    28,    18,   179,   178,     0,    28,   181,
     182,   184,     0,   186,     0,   188,     0,   189,     0,   192,
       0,   191,     0,   194,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   196,    13,
     197,   199,     0,     0,   200,     0,   202,     0,     0,   207,
       0,     0,   205,     0,   209,     0,     0,   213,     0,   211,
       0,     0,   215,   216,   217,   219,     0,   220,   221,     0,
     223,     0,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   238,     0,   240,    27,
       0,     0,   246,   247,   249,   250,   252,   254,   255,   257,
     258,   259,   262,   263,   264,   265,     0,   267,    25,     0,
     268,   269,     0,   270,   157,   158,   159,   160,   172,   173,
     175,   167,    29,   180,   183,   185,   187,   304,   190,    15,
     195,   271,     0,   273,   274,     0,     0,   277,   279,     0,
       0,     0,     0,   283,   284,   285,   286,   287,     0,     0,
       0,     0,     0,   293,     0,     0,   296,   297,   298,   299,
     300,   301,     0,     0,     0,   306,     0,     0,     0,     0,
       0,     0,   313,     0,   315,     0,   198,   201,   203,   206,
     204,   208,   212,   210,   214,   218,   222,   239,   242,    26,
       0,   266,    24,     9,   272,   275,   276,   278,   280,   281,
     282,   288,   289,   290,   291,   292,   294,   295,   302,   303,
     305,   307,   308,   309,   311,   310,   312,   314,   316,   241
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -299,  -299,  -298,   -88,   239,   -28,  -299,   155,    -2,  -108,
    -195,  -194,  -299,  -299,   228,  -299,    79,     0,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,   246,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,   265,
    -299,  -299,  -299,   -72,  -299,    72,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,   244,  -299
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   186,   187,   181,   325,     4,   221,   352,
     353,   182,   323,   471,   202,   203,   222,   183,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
       5,   180,   180,   470,   173,   189,   217,   354,   192,   193,
     358,   354,   174,   175,   176,   177,   178,   201,   204,   205,
     205,   208,   209,   210,   180,   180,     1,   219,   220,   302,
     268,   269,   270,   489,   272,   274,   275,   277,   469,   569,
     180,   215,   282,   180,   180,   172,   180,   180,   288,   216,
     291,   293,   294,   295,   296,   297,   299,   174,   175,   176,
     177,   178,   185,   220,   305,   220,   308,   180,   316,   317,
     220,   319,   220,   310,   220,   313,   326,   180,   285,   180,
     220,   361,   220,   363,   211,   214,   174,   175,   176,   177,
     178,   220,   365,   335,   220,   418,   301,   335,   337,   322,
     280,   220,   420,   283,   284,   180,   286,   287,   220,   421,
     338,   374,   423,   424,   218,   267,   180,   174,   175,   176,
     177,   178,   339,   335,   278,   279,   335,   315,   340,   174,
     175,   176,   177,   178,   431,   432,   341,   327,   342,   329,
       1,   179,   370,   300,   343,   303,   304,   306,   307,   309,
     311,   312,   314,   174,   175,   176,   177,   178,   502,   354,
     220,   434,   490,   427,   345,   344,     1,     1,   220,   439,
     220,   442,   346,   570,   220,   443,   357,   408,   174,   175,
     176,   177,   178,   347,   337,     1,   184,   337,   220,   445,
     465,   466,   335,   220,   468,   335,   335,   348,   335,   335,
     337,   218,   349,   337,   403,   218,   362,   364,   366,   220,
     472,   220,   473,   350,   212,   213,     5,   220,   474,   218,
     174,   175,   176,   177,   178,   220,   475,   335,   220,   476,
     220,   477,   486,   351,   488,   220,   478,   492,   355,   335,
     356,   335,   220,   479,   359,     1,   298,   220,   504,   220,
     505,   220,   506,     1,   509,   360,   335,     1,   334,   220,
     556,   174,   175,   176,   177,   178,   422,   220,   561,   335,
     371,   218,   435,   438,   440,   441,   220,   562,   373,   446,
     426,     1,   336,   174,   175,   176,   177,   178,   512,   220,
     563,   180,   180,   447,   519,   520,   180,   522,   220,   564,
     419,     5,   452,   528,   456,   530,     1,   180,   457,   534,
     535,   174,   175,   176,   177,   178,   459,   542,   180,   220,
     565,   546,   460,   548,   549,   551,   461,   180,   462,   555,
     463,   188,   464,   190,   191,   206,   207,   194,   195,   196,
     197,   198,   199,   200,   430,   433,   419,   481,     1,   367,
     482,   515,   516,   218,   483,   484,   521,   419,   419,   487,
     271,   273,   493,   276,   495,   497,   498,   532,   281,   499,
     500,   372,   173,   507,   508,   289,   290,   292,   543,   419,
     510,   511,   419,   419,   513,   419,   419,   553,   419,   216,
     419,   419,   514,   419,   517,   523,   524,   318,   525,   320,
     321,   572,   324,   526,   573,   328,   527,   330,   331,   332,
     333,   212,   369,   174,   175,   176,   177,   178,   174,   175,
     176,   177,   178,   533,   536,   537,   538,   335,   335,   539,
     540,   541,   545,   335,   174,   175,   176,   177,   178,   428,
     429,   419,   552,   419,   335,   419,   174,   175,   176,   177,
     178,   554,   557,   558,   559,   335,   174,   175,   176,   177,
     178,   337,   560,   566,   416,   335,   174,   175,   176,   177,
     178,     5,   174,   175,   176,   177,   178,   174,   175,   176,
     177,   178,   174,   175,   176,   177,   178,   174,   175,   176,
     177,   178,   174,   175,   176,   177,   178,   567,   568,   571,
     574,   419,   577,   578,   580,   581,   174,   175,   176,   177,
     178,   582,   583,   584,   419,   586,   587,   419,   588,   419,
     419,   590,   591,   592,   593,   419,   595,   596,   598,   599,
     451,     0,     0,     0,   425,   174,   175,   176,   177,   178,
       0,   436,   437,   467,     0,     0,     1,   444,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,   448,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   449,   450,     0,     0,     0,     0,
       0,     0,     0,     0,     1,   453,     0,     0,     0,     0,
       0,     0,     0,     0,     1,   454,     0,     0,     0,     0,
       1,   455,     0,     0,     0,     1,   458,     0,     0,     0,
       1,   480,     0,     0,     0,     1,   485,     0,     0,     0,
       1,   491,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   529,     0,   531,     1,   494,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   544,    89,    90,   547,
       0,   550,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,     1,   496,   102,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,     0,   157,   158,   159,   160,   161,   162,   163,
     164,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   368,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,     0,     0,   165,   166,   167,
     168,   169,   170,   171,    89,    90,     0,     0,     0,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
       0,     0,   102,     0,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,     0,
     157,   158,   159,   160,   161,   162,   163,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,   175,   176,
     177,   178,   174,   175,   176,   177,   178,   174,   175,   176,
     177,   178,   174,   175,   176,   177,   178,     0,     0,     0,
     368,   174,   175,   176,   177,   178,   174,   175,   176,   177,
     178,     0,     0,     0,   165,   166,   167,   168,   169,   170,
     171,    89,    90,     0,     0,     0,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,     0,     0,   102,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,     0,   157,   158,   159,
     160,   161,   162,   163,   164,     1,   501,     0,     0,     0,
       1,   503,     0,     0,     0,     1,   518,     0,     0,     0,
       1,   575,   174,   175,   176,   177,   178,     0,     0,     1,
     576,     0,     0,     0,     1,   579,   174,   175,   176,   177,
     178,   174,   175,   176,   177,   178,     0,     0,     0,     1,
       0,   165,   166,   167,   168,   169,   170,   171,    89,    90,
       0,     0,     0,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,     0,     0,   102,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     0,   157,   158,   159,   160,   161,   162,
     163,   164,     0,     0,     0,     0,     0,     0,     0,     0,
       1,   585,   174,   175,   176,   177,   178,     0,     0,     0,
       0,     0,     0,     0,     1,   589,     0,     0,     0,     1,
     594,     0,     0,     0,     0,     0,   408,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
     167,   168,   169,   170,   171,    89,    90,     0,     0,     0,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,     0,     0,   102,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
       0,   157,   158,   159,   160,   161,   162,   163,   164,   375,
       1,   597,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   171,    89,    90,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,     0,     0,
     102,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     0,   157,   158,
     159,   160,   161,   162,   163,   164,     0,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   368,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,     0,   165,   166,   167,   168,   169,   170,   171
};

static const yytype_int16 yycheck[] =
{
       0,    89,    90,   301,     4,    93,   114,   201,    96,    97,
     205,   205,     3,     4,     5,     6,     7,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   131,   115,   131,   132,
     118,   119,   120,     3,   122,   123,   124,   125,     3,     3,
     128,   113,   130,   131,   132,     0,   134,   135,   136,   131,
     138,   139,   140,   141,   142,   143,   144,     3,     4,     5,
       6,     7,    90,   131,   132,   131,   132,   155,   156,   157,
     131,   159,   131,   132,   131,   132,   164,   165,     5,   167,
     131,   132,   131,   132,   112,   113,     3,     4,     5,     6,
       7,   131,   132,   181,   131,   132,     3,   185,   186,     3,
     128,   131,   132,   131,   132,   193,   134,   135,   131,   132,
     132,   219,   131,   132,   114,   117,   204,     3,     4,     5,
       6,     7,   132,   211,   126,   127,   214,   155,   132,     3,
       4,     5,     6,     7,   131,   132,   132,   165,   132,   167,
     131,   132,   214,   145,   132,   147,   148,   149,   150,   151,
     152,   153,   154,     3,     4,     5,     6,     7,   353,   353,
     131,   132,   132,   271,   132,   193,   131,   131,   131,   132,
     131,   132,   132,   471,   131,   132,   204,   121,     3,     4,
       5,     6,     7,   132,   272,   131,   132,   275,   131,   132,
     131,   132,   280,   131,   132,   283,   284,   132,   286,   287,
     288,   201,   132,   291,   115,   205,   208,   209,   210,   131,
     132,   131,   132,   132,   131,   132,   216,   131,   132,   219,
       3,     4,     5,     6,     7,   131,   132,   315,   131,   132,
     131,   132,   320,   132,   322,   131,   132,   325,   132,   327,
     132,   329,   131,   132,   132,   131,   132,   131,   132,   131,
     132,   131,   132,   131,   132,   132,   344,   131,   132,   131,
     132,     3,     4,     5,     6,     7,   268,   131,   132,   357,
     132,   271,   274,   275,   276,   277,   131,   132,   132,   281,
     132,   131,   132,     3,     4,     5,     6,     7,   376,   131,
     132,   379,   380,   132,   382,   383,   384,   385,   131,   132,
     221,   301,   132,   391,   132,   393,   131,   395,   132,   397,
     398,     3,     4,     5,     6,     7,   132,   405,   406,   131,
     132,   409,   132,   411,   412,   413,   132,   415,   132,   417,
     132,    92,   132,    94,    95,   107,   108,    98,    99,   100,
     101,   102,   103,   104,   272,   273,   267,   132,   131,   132,
     132,   379,   380,   353,   132,   132,   384,   278,   279,   132,
     121,   122,   132,   124,   132,   132,   132,   395,   129,   132,
     132,   216,   372,   132,   132,   136,   137,   138,   406,   300,
     132,   132,   303,   304,   132,   306,   307,   415,   309,   131,
     311,   312,   132,   314,   132,   132,   132,   158,   132,   160,
     161,   489,   163,   132,   492,   166,   132,   168,   169,   170,
     171,   131,   132,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,   132,   132,   132,   132,   515,   516,   132,
     132,   132,   132,   521,     3,     4,     5,     6,     7,   131,
     132,   362,   132,   364,   532,   366,     3,     4,     5,     6,
       7,   132,   132,   132,   132,   543,     3,     4,     5,     6,
       7,   549,   132,   132,   129,   553,     3,     4,     5,     6,
       7,   471,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,   132,   132,   132,
     132,   422,   132,   132,   132,   132,     3,     4,     5,     6,
       7,   132,   132,   132,   435,   132,   132,   438,   132,   440,
     441,   132,   132,   132,   132,   446,   132,   132,   132,   132,
     284,    -1,    -1,    -1,   269,     3,     4,     5,     6,     7,
      -1,   131,   132,   299,    -1,    -1,   131,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,    -1,    -1,    -1,    -1,
     131,   132,    -1,    -1,    -1,   131,   132,    -1,    -1,    -1,
     131,   132,    -1,    -1,    -1,   131,   132,    -1,    -1,    -1,
     131,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   392,    -1,   394,   131,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   407,     3,     4,   410,
      -1,   412,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,   131,   132,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,     3,     4,    -1,    -1,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,    -1,    -1,    -1,
     119,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,    -1,    -1,    -1,   133,   134,   135,   136,   137,   138,
     139,     3,     4,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    79,    80,    81,
      82,    83,    84,    85,    86,   131,   132,    -1,    -1,    -1,
     131,   132,    -1,    -1,    -1,   131,   132,    -1,    -1,    -1,
     131,   132,     3,     4,     5,     6,     7,    -1,    -1,   131,
     132,    -1,    -1,    -1,   131,   132,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,    -1,    -1,    -1,   131,
      -1,   133,   134,   135,   136,   137,   138,   139,     3,     4,
      -1,    -1,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,    -1,    -1,    -1,   131,
     132,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,   136,   137,   138,   139,     3,     4,    -1,    -1,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    79,    80,    81,    82,    83,    84,    85,    86,    87,
     131,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,
     138,   139,     3,     4,    -1,    -1,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,   133,   134,   135,   136,   137,   138,   139
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   131,   141,   142,   147,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     3,
       4,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    21,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    79,    80,    81,
      82,    83,    84,    85,    86,   133,   134,   135,   136,   137,
     138,   139,     0,   157,     3,     4,     5,     6,     7,   132,
     143,   145,   151,   157,   132,   145,   143,   144,   144,   143,
     144,   144,   143,   143,   144,   144,   144,   144,   144,   144,
     144,   143,   154,   155,   143,   143,   154,   154,   143,   143,
     143,   145,   131,   132,   145,   273,   131,   149,   157,   143,
     131,   148,   156,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   148,   143,   143,
     143,   144,   143,   144,   143,   143,   144,   143,   148,   148,
     145,   144,   143,   145,   145,     5,   145,   145,   143,   144,
     144,   143,   144,   143,   143,   143,   143,   143,   132,   143,
     148,     3,   132,   148,   148,   132,   148,   148,   132,   148,
     132,   148,   148,   132,   148,   145,   143,   143,   144,   143,
     144,   144,     3,   152,   144,   146,   143,   145,   144,   145,
     144,   144,   144,   144,   132,   143,   132,   143,   132,   132,
     132,   132,   132,   132,   145,   132,   132,   132,   132,   132,
     132,   132,   149,   150,   151,   132,   132,   145,   150,   132,
     132,   132,   148,   132,   148,   132,   148,   132,   119,   132,
     273,   132,   147,   132,   149,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   132,   156,
     132,   132,   148,   131,   132,   269,   132,   149,   131,   132,
     275,   131,   132,   275,   132,   148,   131,   132,   148,   132,
     148,   148,   132,   132,   132,   132,   148,   132,   132,   131,
     132,   241,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   131,   132,   283,   132,     3,
     142,   153,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   143,   132,   143,     3,
     132,   132,   143,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   150,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   143,   132,   132,   145,   145,   132,   132,   143,
     143,   145,   143,   132,   132,   132,   132,   132,   143,   144,
     143,   144,   145,   132,   143,   143,   132,   132,   132,   132,
     132,   132,   143,   145,   144,   132,   143,   144,   143,   143,
     144,   143,   132,   145,   132,   143,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,     3,
     142,   132,   143,   143,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   140,   141,   142,   143,   143,   144,   145,   145,   146,
     146,   147,   147,   148,   148,   149,   149,   150,   150,   151,
     151,   151,   151,   151,   152,   152,   153,   153,   154,   155,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   179,
     180,   181,   182,   183,   183,   184,   184,   185,   185,   186,
     187,   187,   187,   187,   188,   189,   190,   191,   192,   192,
     193,   193,   194,   195,   196,   196,   196,   196,   197,   197,
     198,   198,   198,   198,   199,   200,   201,   202,   203,   203,
     204,   205,   206,   206,   207,   208,   209,   210,   210,   211,
     212,   212,   213,   214,   215,   216,   217,   218,   218,   218,
     219,   220,   220,   221,   221,   222,   222,   223,   224,   224,
     225,   226,   226,   227,   227,   228,   229,   229,   230,   231,
     232,   232,   233,   234,   235,   236,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   279,   280,   281,   282,   283,   284
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     1,     3,
       1,     2,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     2,     1,     2,     3,
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
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     4,     4,     5,     4,     5,     4,     5,     4,     4,
       5,     4,     4,     3,     4,     5,     4,     4,     5,     4,
       4,     5,     4,     5,     5,     4,     5,     4,     5,     4,
       5,     4,     5,     4,     5,     4,     4,     4,     5,     4,
       4,     4,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     4,     5,
       4,     6,     5,     4,     3,     3,     4,     4,     3,     4,
       4,     3,     4,     3,     4,     4,     3,     4,     4,     4,
       4,     3,     4,     4,     4,     4,     5,     4,     4,     4,
       4,     3,     4,     3,     3,     4,     4,     3,     4,     3,
       4,     4,     4,     3,     3,     3,     3,     3,     4,     4,
       4,     4,     4,     3,     4,     4,     3,     3,     3,     3,
       3,     3,     4,     4,     3,     4,     3,     4,     4,     4,
       4,     4,     4,     3,     4,     3,     4
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
#line 66 "../src/parser.y" /* yacc.c:1257  */
      { free(((*yyvaluep).s)); }
#line 1852 "parser.c" /* yacc.c:1257  */
        break;

    case 4: /* STR  */
#line 66 "../src/parser.y" /* yacc.c:1257  */
      { free(((*yyvaluep).s)); }
#line 1858 "parser.c" /* yacc.c:1257  */
        break;

    case 141: /* start  */
#line 64 "../src/parser.y" /* yacc.c:1257  */
      { run(((*yyvaluep).e));  }
#line 1864 "parser.c" /* yacc.c:1257  */
        break;

    case 142: /* s  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1870 "parser.c" /* yacc.c:1257  */
        break;

    case 143: /* p  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1876 "parser.c" /* yacc.c:1257  */
        break;

    case 144: /* pp  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1882 "parser.c" /* yacc.c:1257  */
        break;

    case 145: /* ps  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1888 "parser.c" /* yacc.c:1257  */
        break;

    case 146: /* pps  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1894 "parser.c" /* yacc.c:1257  */
        break;

    case 147: /* vps  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1900 "parser.c" /* yacc.c:1257  */
        break;

    case 148: /* opts  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1906 "parser.c" /* yacc.c:1257  */
        break;

    case 149: /* vpb  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1912 "parser.c" /* yacc.c:1257  */
        break;

    case 150: /* xpb  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1918 "parser.c" /* yacc.c:1257  */
        break;

    case 151: /* np  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1924 "parser.c" /* yacc.c:1257  */
        break;

    case 152: /* sps  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1930 "parser.c" /* yacc.c:1257  */
        break;

    case 153: /* par  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1936 "parser.c" /* yacc.c:1257  */
        break;

    case 154: /* cv  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1942 "parser.c" /* yacc.c:1257  */
        break;

    case 155: /* cvv  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1948 "parser.c" /* yacc.c:1257  */
        break;

    case 156: /* opt  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1954 "parser.c" /* yacc.c:1257  */
        break;

    case 157: /* vp  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1960 "parser.c" /* yacc.c:1257  */
        break;

    case 158: /* add  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1966 "parser.c" /* yacc.c:1257  */
        break;

    case 159: /* div  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1972 "parser.c" /* yacc.c:1257  */
        break;

    case 160: /* mul  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1978 "parser.c" /* yacc.c:1257  */
        break;

    case 161: /* sub  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1984 "parser.c" /* yacc.c:1257  */
        break;

    case 162: /* and  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1990 "parser.c" /* yacc.c:1257  */
        break;

    case 163: /* bitand  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 1996 "parser.c" /* yacc.c:1257  */
        break;

    case 164: /* bitnot  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2002 "parser.c" /* yacc.c:1257  */
        break;

    case 165: /* bitor  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2008 "parser.c" /* yacc.c:1257  */
        break;

    case 166: /* bitxor  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2014 "parser.c" /* yacc.c:1257  */
        break;

    case 167: /* not  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2020 "parser.c" /* yacc.c:1257  */
        break;

    case 168: /* in  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2026 "parser.c" /* yacc.c:1257  */
        break;

    case 169: /* or  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2032 "parser.c" /* yacc.c:1257  */
        break;

    case 170: /* shiftleft  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2038 "parser.c" /* yacc.c:1257  */
        break;

    case 171: /* shiftright  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2044 "parser.c" /* yacc.c:1257  */
        break;

    case 172: /* xor  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2050 "parser.c" /* yacc.c:1257  */
        break;

    case 173: /* eq  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2056 "parser.c" /* yacc.c:1257  */
        break;

    case 174: /* gt  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2062 "parser.c" /* yacc.c:1257  */
        break;

    case 175: /* gte  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2068 "parser.c" /* yacc.c:1257  */
        break;

    case 176: /* lt  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2074 "parser.c" /* yacc.c:1257  */
        break;

    case 177: /* lte  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2080 "parser.c" /* yacc.c:1257  */
        break;

    case 178: /* neq  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2086 "parser.c" /* yacc.c:1257  */
        break;

    case 179: /* if  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2092 "parser.c" /* yacc.c:1257  */
        break;

    case 180: /* select  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2098 "parser.c" /* yacc.c:1257  */
        break;

    case 181: /* until  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2104 "parser.c" /* yacc.c:1257  */
        break;

    case 182: /* while  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2110 "parser.c" /* yacc.c:1257  */
        break;

    case 183: /* execute  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2116 "parser.c" /* yacc.c:1257  */
        break;

    case 184: /* rexx  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2122 "parser.c" /* yacc.c:1257  */
        break;

    case 185: /* run  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2128 "parser.c" /* yacc.c:1257  */
        break;

    case 186: /* abort  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2134 "parser.c" /* yacc.c:1257  */
        break;

    case 187: /* exit  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2140 "parser.c" /* yacc.c:1257  */
        break;

    case 188: /* onerror  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2146 "parser.c" /* yacc.c:1257  */
        break;

    case 189: /* trap  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2152 "parser.c" /* yacc.c:1257  */
        break;

    case 190: /* copyfiles  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2158 "parser.c" /* yacc.c:1257  */
        break;

    case 191: /* copylib  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2164 "parser.c" /* yacc.c:1257  */
        break;

    case 192: /* delete  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2170 "parser.c" /* yacc.c:1257  */
        break;

    case 193: /* exists  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2176 "parser.c" /* yacc.c:1257  */
        break;

    case 194: /* fileonly  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2182 "parser.c" /* yacc.c:1257  */
        break;

    case 195: /* foreach  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2188 "parser.c" /* yacc.c:1257  */
        break;

    case 196: /* makeassign  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2194 "parser.c" /* yacc.c:1257  */
        break;

    case 197: /* makedir  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2200 "parser.c" /* yacc.c:1257  */
        break;

    case 198: /* protect  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2206 "parser.c" /* yacc.c:1257  */
        break;

    case 199: /* startup  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2212 "parser.c" /* yacc.c:1257  */
        break;

    case 200: /* textfile  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2218 "parser.c" /* yacc.c:1257  */
        break;

    case 201: /* tooltype  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2224 "parser.c" /* yacc.c:1257  */
        break;

    case 202: /* transcript  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2230 "parser.c" /* yacc.c:1257  */
        break;

    case 203: /* rename  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2236 "parser.c" /* yacc.c:1257  */
        break;

    case 204: /* complete  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2242 "parser.c" /* yacc.c:1257  */
        break;

    case 205: /* debug  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2248 "parser.c" /* yacc.c:1257  */
        break;

    case 206: /* message  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2254 "parser.c" /* yacc.c:1257  */
        break;

    case 207: /* user  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2260 "parser.c" /* yacc.c:1257  */
        break;

    case 208: /* welcome  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2266 "parser.c" /* yacc.c:1257  */
        break;

    case 209: /* working  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2272 "parser.c" /* yacc.c:1257  */
        break;

    case 210: /* database  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2278 "parser.c" /* yacc.c:1257  */
        break;

    case 211: /* earlier  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2284 "parser.c" /* yacc.c:1257  */
        break;

    case 212: /* getassign  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2290 "parser.c" /* yacc.c:1257  */
        break;

    case 213: /* getdevice  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2296 "parser.c" /* yacc.c:1257  */
        break;

    case 214: /* getdiskspace  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2302 "parser.c" /* yacc.c:1257  */
        break;

    case 215: /* getenv  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2308 "parser.c" /* yacc.c:1257  */
        break;

    case 216: /* getsize  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2314 "parser.c" /* yacc.c:1257  */
        break;

    case 217: /* getsum  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2320 "parser.c" /* yacc.c:1257  */
        break;

    case 218: /* getversion  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2326 "parser.c" /* yacc.c:1257  */
        break;

    case 219: /* iconinfo  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2332 "parser.c" /* yacc.c:1257  */
        break;

    case 220: /* dcl  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2338 "parser.c" /* yacc.c:1257  */
        break;

    case 221: /* cus  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2344 "parser.c" /* yacc.c:1257  */
        break;

    case 222: /* askbool  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2350 "parser.c" /* yacc.c:1257  */
        break;

    case 223: /* askchoice  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2356 "parser.c" /* yacc.c:1257  */
        break;

    case 224: /* askdir  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2362 "parser.c" /* yacc.c:1257  */
        break;

    case 225: /* askdisk  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2368 "parser.c" /* yacc.c:1257  */
        break;

    case 226: /* askfile  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2374 "parser.c" /* yacc.c:1257  */
        break;

    case 227: /* asknumber  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2380 "parser.c" /* yacc.c:1257  */
        break;

    case 228: /* askoptions  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2386 "parser.c" /* yacc.c:1257  */
        break;

    case 229: /* askstring  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2392 "parser.c" /* yacc.c:1257  */
        break;

    case 230: /* cat  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2398 "parser.c" /* yacc.c:1257  */
        break;

    case 231: /* expandpath  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2404 "parser.c" /* yacc.c:1257  */
        break;

    case 232: /* fmt  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2410 "parser.c" /* yacc.c:1257  */
        break;

    case 233: /* pathonly  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2416 "parser.c" /* yacc.c:1257  */
        break;

    case 234: /* patmatch  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2422 "parser.c" /* yacc.c:1257  */
        break;

    case 235: /* strlen  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2428 "parser.c" /* yacc.c:1257  */
        break;

    case 236: /* substr  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2434 "parser.c" /* yacc.c:1257  */
        break;

    case 237: /* tackon  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2440 "parser.c" /* yacc.c:1257  */
        break;

    case 238: /* set  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2446 "parser.c" /* yacc.c:1257  */
        break;

    case 239: /* symbolset  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2452 "parser.c" /* yacc.c:1257  */
        break;

    case 240: /* symbolval  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2458 "parser.c" /* yacc.c:1257  */
        break;

    case 241: /* all  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2464 "parser.c" /* yacc.c:1257  */
        break;

    case 242: /* append  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2470 "parser.c" /* yacc.c:1257  */
        break;

    case 243: /* askuser  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2476 "parser.c" /* yacc.c:1257  */
        break;

    case 244: /* assigns  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2482 "parser.c" /* yacc.c:1257  */
        break;

    case 245: /* choices  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2488 "parser.c" /* yacc.c:1257  */
        break;

    case 246: /* command  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2494 "parser.c" /* yacc.c:1257  */
        break;

    case 247: /* compression  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2500 "parser.c" /* yacc.c:1257  */
        break;

    case 248: /* confirm  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2506 "parser.c" /* yacc.c:1257  */
        break;

    case 249: /* default  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2512 "parser.c" /* yacc.c:1257  */
        break;

    case 250: /* delopts  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2518 "parser.c" /* yacc.c:1257  */
        break;

    case 251: /* dest  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2524 "parser.c" /* yacc.c:1257  */
        break;

    case 252: /* disk  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2530 "parser.c" /* yacc.c:1257  */
        break;

    case 253: /* fail  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2536 "parser.c" /* yacc.c:1257  */
        break;

    case 254: /* files  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2542 "parser.c" /* yacc.c:1257  */
        break;

    case 255: /* fonts  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2548 "parser.c" /* yacc.c:1257  */
        break;

    case 256: /* force  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2554 "parser.c" /* yacc.c:1257  */
        break;

    case 257: /* getdefaulttool  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2560 "parser.c" /* yacc.c:1257  */
        break;

    case 258: /* getposition  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2566 "parser.c" /* yacc.c:1257  */
        break;

    case 259: /* getstack  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2572 "parser.c" /* yacc.c:1257  */
        break;

    case 260: /* gettooltype  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2578 "parser.c" /* yacc.c:1257  */
        break;

    case 261: /* help  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2584 "parser.c" /* yacc.c:1257  */
        break;

    case 262: /* infos  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2590 "parser.c" /* yacc.c:1257  */
        break;

    case 263: /* include  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2596 "parser.c" /* yacc.c:1257  */
        break;

    case 264: /* newname  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2602 "parser.c" /* yacc.c:1257  */
        break;

    case 265: /* newpath  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2608 "parser.c" /* yacc.c:1257  */
        break;

    case 266: /* nofail  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2614 "parser.c" /* yacc.c:1257  */
        break;

    case 267: /* nogauge  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2620 "parser.c" /* yacc.c:1257  */
        break;

    case 268: /* noposition  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2626 "parser.c" /* yacc.c:1257  */
        break;

    case 269: /* noreq  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2632 "parser.c" /* yacc.c:1257  */
        break;

    case 270: /* oknodelete  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2638 "parser.c" /* yacc.c:1257  */
        break;

    case 271: /* pattern  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2644 "parser.c" /* yacc.c:1257  */
        break;

    case 272: /* prompt  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2650 "parser.c" /* yacc.c:1257  */
        break;

    case 273: /* quiet  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2656 "parser.c" /* yacc.c:1257  */
        break;

    case 274: /* range  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2662 "parser.c" /* yacc.c:1257  */
        break;

    case 275: /* safe  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2668 "parser.c" /* yacc.c:1257  */
        break;

    case 276: /* setdefaulttool  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2674 "parser.c" /* yacc.c:1257  */
        break;

    case 277: /* setposition  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2680 "parser.c" /* yacc.c:1257  */
        break;

    case 278: /* setstack  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2686 "parser.c" /* yacc.c:1257  */
        break;

    case 279: /* settooltype  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2692 "parser.c" /* yacc.c:1257  */
        break;

    case 280: /* source  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2698 "parser.c" /* yacc.c:1257  */
        break;

    case 281: /* swapcolors  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2704 "parser.c" /* yacc.c:1257  */
        break;

    case 282: /* optional  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2710 "parser.c" /* yacc.c:1257  */
        break;

    case 283: /* resident  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2716 "parser.c" /* yacc.c:1257  */
        break;

    case 284: /* override  */
#line 69 "../src/parser.y" /* yacc.c:1257  */
      { kill(((*yyvaluep).e)); }
#line 2722 "parser.c" /* yacc.c:1257  */
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
#line 85 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = init((yyvsp[0].e)); }
#line 2990 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 91 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 2996 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 92 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3002 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 93 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3008 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 94 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push((yyvsp[-2].e), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3014 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 95 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = (yyvsp[0].e); }
#line 3020 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 96 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3026 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 97 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3032 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 98 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3038 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 99 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3044 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 100 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = (yyvsp[-1].e); }
#line 3050 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 101 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3056 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 102 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = (yyvsp[0].e); }
#line 3062 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 103 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = (yyvsp[0].e); }
#line 3068 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 104 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3074 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 105 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3080 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 106 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3086 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 107 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_string((yyvsp[0].s)); }
#line 3092 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 108 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_symref((yyvsp[0].s), LINE); }
#line 3098 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 109 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push((yyvsp[-2].e), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)) ; }
#line 3104 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 110 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push(new_contxt(), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)); }
#line 3110 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 111 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push((yyvsp[-1].e), new_symbol((yyvsp[0].s))); }
#line 3116 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 112 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(new_contxt(), new_symbol((yyvsp[0].s))); }
#line 3122 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 113 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3128 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 114 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3134 "parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 248 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("+"), LINE, m_add, (yyvsp[-1].e), NUMBER); }
#line 3140 "parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 249 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("/"), LINE, m_div, (yyvsp[-1].e), NUMBER); }
#line 3146 "parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 250 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("*"), LINE, m_mul, (yyvsp[-1].e), NUMBER); }
#line 3152 "parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 251 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("-"), LINE, m_sub, (yyvsp[-1].e), NUMBER); }
#line 3158 "parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 254 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("AND"), LINE, m_and, (yyvsp[-1].e), NUMBER); }
#line 3164 "parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 255 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("BITAND"), LINE, m_bitand, (yyvsp[-1].e), NUMBER); }
#line 3170 "parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 256 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("BITNOT"), LINE, m_bitnot, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3176 "parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 257 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("BITOR"), LINE, m_bitor, (yyvsp[-1].e), NUMBER); }
#line 3182 "parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 258 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("BITXOR"), LINE, m_bitxor, (yyvsp[-1].e), NUMBER); }
#line 3188 "parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 259 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("NOT"), LINE, m_not, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3194 "parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 260 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("IN"), LINE, m_in, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3200 "parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 261 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("OR"), LINE, m_or, (yyvsp[-1].e), NUMBER); }
#line 3206 "parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 262 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("shiftleft"), LINE, m_shiftleft, (yyvsp[-1].e), NUMBER); }
#line 3212 "parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 263 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("shiftright"), LINE, m_shiftright, (yyvsp[-1].e), NUMBER); }
#line 3218 "parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 264 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("XOR"), LINE, m_xor, (yyvsp[-1].e), NUMBER); }
#line 3224 "parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 267 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("="), LINE, m_eq, (yyvsp[-1].e), NUMBER); }
#line 3230 "parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 268 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup(">"), LINE, m_gt, (yyvsp[-1].e), NUMBER); }
#line 3236 "parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 269 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup(">="), LINE, m_gte, (yyvsp[-1].e), NUMBER); }
#line 3242 "parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 270 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("<"), LINE, m_lt, (yyvsp[-1].e), NUMBER); }
#line 3248 "parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 271 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("<="), LINE, m_lte, (yyvsp[-1].e), NUMBER); }
#line 3254 "parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 272 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("<>"), LINE, m_neq, (yyvsp[-1].e), NUMBER); }
#line 3260 "parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 275 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3266 "parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 276 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3272 "parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 277 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("select"), LINE, m_select, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3278 "parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 278 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("until"), LINE, m_until, (yyvsp[-1].e), NUMBER); }
#line 3284 "parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 279 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("while"), LINE, m_while, (yyvsp[-1].e), NUMBER); }
#line 3290 "parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 282 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3296 "parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 283 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3302 "parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 284 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3308 "parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 285 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3314 "parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 286 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3320 "parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 287 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3326 "parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 290 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("abort"), LINE, m_abort, (yyvsp[-1].e), NUMBER); }
#line 3332 "parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 291 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3338 "parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 292 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3344 "parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 293 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, (yyvsp[-1].e), NUMBER); }
#line 3350 "parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 294 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, NULL, NUMBER); }
#line 3356 "parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 295 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("onerror"), LINE, m_procedure, push(new_contxt(), 
                                                       new_custom(strdup("@onerror"), LINE, NULL, (yyvsp[-1].e))), DANGLE); }
#line 3363 "parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 297 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("trap"), LINE, m_trap, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3369 "parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 300 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("copyfiles"), LINE, m_copyfiles, (yyvsp[-1].e), NUMBER); }
#line 3375 "parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 301 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("copylib"), LINE, m_copylib, (yyvsp[-1].e), NUMBER); }
#line 3381 "parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 302 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3387 "parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 303 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3393 "parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 304 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3399 "parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 305 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3405 "parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 306 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("fileonly"), LINE, m_fileonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3411 "parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 307 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("foreach"), LINE, m_foreach, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3417 "parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 308 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3423 "parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 309 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, (yyvsp[-1].e), NUMBER); }
#line 3429 "parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 310 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3435 "parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 311 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3441 "parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 312 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3447 "parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 313 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3453 "parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 314 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3459 "parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 315 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, (yyvsp[-1].e), NUMBER); }
#line 3465 "parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 316 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3471 "parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 317 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3477 "parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 318 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3483 "parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 319 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("textfile"), LINE, m_textfile, (yyvsp[-1].e), NUMBER); }
#line 3489 "parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 320 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("tooltype"), LINE, m_tooltype, (yyvsp[-1].e), NUMBER); }
#line 3495 "parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 321 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("transcript"), LINE, m_transcript, (yyvsp[-1].e), NUMBER); }
#line 3501 "parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 322 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3507 "parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 323 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, (yyvsp[-1].e), NUMBER); }
#line 3513 "parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 326 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("complete"), LINE, m_complete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3519 "parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 327 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, (yyvsp[-1].e), NUMBER); }
#line 3525 "parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 328 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3531 "parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 329 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, (yyvsp[-1].e), NUMBER); }
#line 3537 "parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 330 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("user"), LINE, m_set, push(push(new_contxt(), 
                                                       new_symbol(strdup("@user-level"))), new_number((yyvsp[-1].n))), DANGLE); }
#line 3544 "parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 332 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, (yyvsp[-1].e), NUMBER); }
#line 3550 "parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 333 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("working"), LINE, m_working, (yyvsp[-1].e), NUMBER); }
#line 3556 "parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 336 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3562 "parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 337 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, (yyvsp[-1].e), STRING); }
#line 3568 "parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 338 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("earlier"), LINE, m_earlier, (yyvsp[-1].e), NUMBER); }
#line 3574 "parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 339 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3580 "parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 340 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, (yyvsp[-1].e), STRING); }
#line 3586 "parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 341 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getdevice"), LINE, m_getdevice, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3592 "parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 342 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3598 "parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 343 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getenv"), LINE, m_getenv, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3604 "parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 344 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getsize"), LINE, m_getsize, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3610 "parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 345 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getsum"), LINE, m_getsum, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3616 "parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 346 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, NULL, NUMBER); }
#line 3622 "parser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 347 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3628 "parser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 348 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3634 "parser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 349 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("iconinfo"), LINE, m_iconinfo, (yyvsp[-1].e), NUMBER); }
#line 3640 "parser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 352 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-3].s), LINE, (yyvsp[-2].e), (yyvsp[-1].e))), NUMBER); }
#line 3646 "parser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 353 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, NULL, (yyvsp[-1].e))), NUMBER); }
#line 3652 "parser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 354 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_cusref((yyvsp[-2].s), LINE, (yyvsp[-1].e)); }
#line 3658 "parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 355 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_cusref((yyvsp[-1].s), LINE, NULL); }
#line 3664 "parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 358 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, NULL, NUMBER); }
#line 3670 "parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 359 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, (yyvsp[-1].e), NUMBER); }
#line 3676 "parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 360 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askchoice"), LINE, m_askchoice, (yyvsp[-1].e), NUMBER); }
#line 3682 "parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 361 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, NULL, STRING); }
#line 3688 "parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 362 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, (yyvsp[-1].e), STRING); }
#line 3694 "parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 363 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askdisk"), LINE, m_askdisk, (yyvsp[-1].e), NUMBER); }
#line 3700 "parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 364 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, NULL, STRING); }
#line 3706 "parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 365 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, (yyvsp[-1].e), STRING); }
#line 3712 "parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 366 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, NULL, NUMBER); }
#line 3718 "parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 367 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, (yyvsp[-1].e), NUMBER); }
#line 3724 "parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 368 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askoptions"), LINE, m_askoptions, (yyvsp[-1].e), NUMBER); }
#line 3730 "parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 369 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, NULL, STRING); }
#line 3736 "parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 370 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, (yyvsp[-1].e), STRING); }
#line 3742 "parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 373 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("cat"), LINE, m_cat, (yyvsp[-1].e), STRING); }
#line 3748 "parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 374 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("expandpath"), LINE, m_expandpath, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3754 "parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 375 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native((yyvsp[-2].s), LINE, m_fmt, (yyvsp[-1].e), STRING); }
#line 3760 "parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 376 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native((yyvsp[-1].s), LINE, m_fmt, NULL, STRING); }
#line 3766 "parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 377 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("pathonly"), LINE, m_pathonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3772 "parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 378 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("patmatch"), LINE, m_patmatch, (yyvsp[-1].e), NUMBER); }
#line 3778 "parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 379 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("strlen"), LINE, m_strlen, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3784 "parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 380 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, (yyvsp[-1].e), STRING); }
#line 3790 "parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 381 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, push((yyvsp[-2].e), (yyvsp[-1].e)), STRING); }
#line 3796 "parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 382 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("tackon"), LINE, m_tackon, (yyvsp[-1].e), STRING); }
#line 3802 "parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 385 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("set"), LINE, m_set, (yyvsp[-1].e), DANGLE); }
#line 3808 "parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 386 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("symbolset"), LINE, m_symbolset, (yyvsp[-1].e), DANGLE); }
#line 3814 "parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 387 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_native(strdup("symbolval"), LINE, m_symbolval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3820 "parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 390 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("all"), OPT_ALL, NULL); }
#line 3826 "parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 391 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("append"), OPT_APPEND, push(new_contxt(), (yyvsp[-1].e))); }
#line 3832 "parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 392 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("askuser"), OPT_ASKUSER, NULL); }
#line 3838 "parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 393 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); }
#line 3844 "parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 394 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("choices"), OPT_CHOICES, (yyvsp[-1].e)); }
#line 3850 "parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 395 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("command"), OPT_COMMAND, (yyvsp[-1].e)); }
#line 3856 "parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 396 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("compression"), OPT_COMPRESSION, NULL); }
#line 3862 "parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 397 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, push(new_contxt(), (yyvsp[-1].e))); }
#line 3868 "parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 398 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, NULL); }
#line 3874 "parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 399 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), (yyvsp[-1].e))); }
#line 3880 "parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 400 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, (yyvsp[-1].e)); }
#line 3886 "parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 401 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), (yyvsp[-1].e))); }
#line 3892 "parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 402 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("disk"), OPT_DISK, NULL); }
#line 3898 "parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 403 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("fail"), OPT_FAIL, NULL); }
#line 3904 "parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 404 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("files"), OPT_FILES, NULL); }
#line 3910 "parser.c" /* yacc.c:1646  */
    break;

  case 286:
#line 405 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("fonts"), OPT_FONTS, NULL); }
#line 3916 "parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 406 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("force"), OPT_FORCE, NULL); }
#line 3922 "parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 407 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 3928 "parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 408 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("getposition"), OPT_GETPOSITION, (yyvsp[-1].e)); }
#line 3934 "parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 409 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 3940 "parser.c" /* yacc.c:1646  */
    break;

  case 291:
#line 410 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, (yyvsp[-1].e)); }
#line 3946 "parser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 411 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, (yyvsp[-1].e)); }
#line 3952 "parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 412 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("infos"), OPT_INFOS, NULL); }
#line 3958 "parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 413 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 3964 "parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 414 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), (yyvsp[-1].e))); }
#line 3970 "parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 415 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("newpath"), OPT_NEWPATH, NULL); }
#line 3976 "parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 416 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("nofail"), OPT_NOFAIL, NULL); }
#line 3982 "parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 417 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); }
#line 3988 "parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 418 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); }
#line 3994 "parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 419 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("noreq"), OPT_NOREQ, NULL); }
#line 4000 "parser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 420 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("oknodelete"), OPT_OKNODELETE, NULL); }
#line 4006 "parser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 421 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), (yyvsp[-1].e))); }
#line 4012 "parser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 422 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("prompt"), OPT_PROMPT, (yyvsp[-1].e)); }
#line 4018 "parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 423 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("quiet"), OPT_QUIET, NULL); }
#line 4024 "parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 424 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("range"), OPT_RANGE, (yyvsp[-1].e)); }
#line 4030 "parser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 425 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("safe"), OPT_SAFE, NULL); }
#line 4036 "parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 426 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4042 "parser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 427 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("setposition"), OPT_SETPOSITION, (yyvsp[-1].e)); }
#line 4048 "parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 428 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4054 "parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 429 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, (yyvsp[-1].e)); }
#line 4060 "parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 430 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4066 "parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 431 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4072 "parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 432 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); }
#line 4078 "parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 433 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, (yyvsp[-1].e)); }
#line 4084 "parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 434 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("resident"), OPT_RESIDENT, NULL); }
#line 4090 "parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 435 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.e) = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4096 "parser.c" /* yacc.c:1646  */
    break;


#line 4100 "parser.c" /* yacc.c:1646  */
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
#line 437 "../src/parser.y" /* yacc.c:1906  */


