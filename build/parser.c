/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "../src/parser.y"

//------------------------------------------------------------------------------
// parser.y:
//
// InstallerLG parser
//------------------------------------------------------------------------------
// Copyright (C) 2018-2019, Ola Söder. All rights reserved.
// Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1
//------------------------------------------------------------------------------

#include "all.h"
#include "alloc.h"
#include "eval.h"
#include "init.h"
#include "lexer.h"

#include <string.h>

// Always debug.
#define YYDEBUG 1

#line 92 "parser.c"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    AND = 264,
    BITAND = 265,
    BITNOT = 266,
    BITOR = 267,
    BITXOR = 268,
    NOT = 269,
    IN = 270,
    OR = 271,
    SHIFTLEFT = 272,
    SHIFTRIGHT = 273,
    XOR = 274,
    EQ = 275,
    GT = 276,
    GTE = 277,
    LT = 278,
    LTE = 279,
    NEQ = 280,
    IF = 281,
    SELECT = 282,
    UNTIL = 283,
    WHILE = 284,
    TRACE = 285,
    RETRACE = 286,
    EXECUTE = 287,
    REXX = 288,
    RUN = 289,
    ABORT = 290,
    EXIT = 291,
    ONERROR = 292,
    TRAP = 293,
    REBOOT = 294,
    COPYFILES = 295,
    COPYLIB = 296,
    DELETE = 297,
    EXISTS = 298,
    FILEONLY = 299,
    FOREACH = 300,
    MAKEASSIGN = 301,
    MAKEDIR = 302,
    PROTECT = 303,
    STARTUP = 304,
    TEXTFILE = 305,
    TOOLTYPE = 306,
    TRANSCRIPT = 307,
    RENAME = 308,
    COMPLETE = 309,
    DEBUG = 310,
    MESSAGE = 311,
    USER = 312,
    WELCOME = 313,
    WORKING = 314,
    CLOSEMEDIA = 315,
    EFFECT = 316,
    SETMEDIA = 317,
    SHOWMEDIA = 318,
    DATABASE = 319,
    EARLIER = 320,
    GETASSIGN = 321,
    GETDEVICE = 322,
    GETDISKSPACE = 323,
    GETENV = 324,
    GETSIZE = 325,
    GETSUM = 326,
    GETVERSION = 327,
    ICONINFO = 328,
    CUS = 329,
    DCL = 330,
    ASKBOOL = 331,
    ASKCHOICE = 332,
    ASKDIR = 333,
    ASKDISK = 334,
    ASKFILE = 335,
    ASKNUMBER = 336,
    ASKOPTIONS = 337,
    ASKSTRING = 338,
    CAT = 339,
    EXPANDPATH = 340,
    FMT = 341,
    PATHONLY = 342,
    PATMATCH = 343,
    STRLEN = 344,
    SUBSTR = 345,
    TACKON = 346,
    SET = 347,
    SYMBOLSET = 348,
    SYMBOLVAL = 349,
    OPENWBOBJECT = 350,
    SHOWWBOBJECT = 351,
    CLOSEWBOBJECT = 352,
    ALL = 353,
    APPEND = 354,
    ASSIGNS = 355,
    BACK = 356,
    CHOICES = 357,
    COMMAND = 358,
    COMPRESSION = 359,
    CONFIRM = 360,
    DEFAULT = 361,
    DELOPTS = 362,
    DEST = 363,
    DISK = 364,
    FILES = 365,
    FONTS = 366,
    GETDEFAULTTOOL = 367,
    GETPOSITION = 368,
    GETSTACK = 369,
    GETTOOLTYPE = 370,
    HELP = 371,
    INFOS = 372,
    INCLUDE = 373,
    NEWNAME = 374,
    NEWPATH = 375,
    NOGAUGE = 376,
    NOPOSITION = 377,
    NOREQ = 378,
    PATTERN = 379,
    PROMPT = 380,
    QUIET = 381,
    RANGE = 382,
    SAFE = 383,
    SETDEFAULTTOOL = 384,
    SETPOSITION = 385,
    SETSTACK = 386,
    SETTOOLTYPE = 387,
    SOURCE = 388,
    SWAPCOLORS = 389,
    OPTIONAL = 390,
    RESIDENT = 391,
    OVERRIDE = 392
  };
#endif

/* Value type.  */



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */



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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  195
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2097

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  147
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  153
/* YYNRULES -- Number of rules.  */
#define YYNRULES  364
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  706

#define YYUNDEFTOK  2
#define YYMAXUTOK   392

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     138,   139,   142,   140,     2,   143,     2,   141,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     146,   144,   145,     2,     2,     2,     2,     2,     2,     2,
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
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,    98,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     273,   274,   275,   276,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   292,   293,   294,   295,   296,
     297,   300,   301,   302,   303,   304,   305,   306,   307,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   324,   325,   326,   327,   328,   329,   330,   332,   333,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   383,   384,   385,   386,   387,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   407,   408,   409,   410,   411,   412,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   442,   443,   444,   447,   448,   449,   450,   451,
     452,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SYM", "STR", "OOM", "INT", "HEX", "BIN",
  "AND", "BITAND", "BITNOT", "BITOR", "BITXOR", "NOT", "IN", "OR",
  "SHIFTLEFT", "SHIFTRIGHT", "XOR", "EQ", "GT", "GTE", "LT", "LTE", "NEQ",
  "IF", "SELECT", "UNTIL", "WHILE", "TRACE", "RETRACE", "EXECUTE", "REXX",
  "RUN", "ABORT", "EXIT", "ONERROR", "TRAP", "REBOOT", "COPYFILES",
  "COPYLIB", "DELETE", "EXISTS", "FILEONLY", "FOREACH", "MAKEASSIGN",
  "MAKEDIR", "PROTECT", "STARTUP", "TEXTFILE", "TOOLTYPE", "TRANSCRIPT",
  "RENAME", "COMPLETE", "DEBUG", "MESSAGE", "USER", "WELCOME", "WORKING",
  "CLOSEMEDIA", "EFFECT", "SETMEDIA", "SHOWMEDIA", "DATABASE", "EARLIER",
  "GETASSIGN", "GETDEVICE", "GETDISKSPACE", "GETENV", "GETSIZE", "GETSUM",
  "GETVERSION", "ICONINFO", "CUS", "DCL", "ASKBOOL", "ASKCHOICE", "ASKDIR",
  "ASKDISK", "ASKFILE", "ASKNUMBER", "ASKOPTIONS", "ASKSTRING", "CAT",
  "EXPANDPATH", "FMT", "PATHONLY", "PATMATCH", "STRLEN", "SUBSTR",
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
  "welcome", "working", "closemedia", "effect", "setmedia", "showmedia",
  "database", "earlier", "getassign", "getdevice", "getdiskspace",
  "getenv", "getsize", "getsum", "getversion", "iconinfo", "dcl", "cus",
  "askbool", "askchoice", "askdir", "askdisk", "askfile", "asknumber",
  "askoptions", "askstring", "cat", "expandpath", "fmt", "pathonly",
  "patmatch", "strlen", "substr", "tackon", "set", "symbolset",
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
     385,   386,   387,   388,   389,   390,   391,   392,    40,    41,
      43,    47,    42,    45,    61,    62,    60
};
# endif

#define YYPACT_NINF -333

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-333)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -119,  1670,    21,  -333,  -333,  -119,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
      29,    66,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
     -92,   -90,   353,   353,   353,    37,    84,  -119,    37,   -81,
     -60,   -60,   353,    37,    37,    37,    37,   353,    37,   353,
     -60,   -60,    37,    37,    37,    90,   353,    37,    97,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,   108,   -60,    72,  -127,   -60,  -111,   -60,  -109,
     -74,   -60,   -72,    37,    37,    37,    37,    37,    37,    37,
      81,    37,    37,   353,    37,    37,    37,    37,    37,    37,
      37,    37,    37,   -40,   -62,  -333,  -119,  -333,  -333,  -333,
    -333,  -333,  -333,  1814,  -333,  -333,   127,  -333,  -333,  -333,
     133,   139,    37,   -15,   -13,   -11,    17,    24,    37,   154,
      26,    30,    38,    46,    48,    54,   205,    59,    63,   514,
    -119,  -119,  -333,  -333,  1094,   234,   353,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,   250,
     353,   256,   353,   298,  1382,  -333,   304,   315,   -58,  -119,
    -333,  1874,   -32,   -30,   -21,   353,   -17,    77,  -119,   321,
      13,    33,   353,   360,    43,   -60,   410,    45,    53,   476,
      62,    79,  -333,   530,   536,   353,    88,  -333,   548,   555,
     106,    37,   656,    37,   676,   109,   144,   704,   148,   151,
     710,   160,   178,   195,   202,  -333,    68,    76,    10,  -333,
      82,    87,  -333,   105,   112,  -333,   129,  -333,   131,   135,
    -333,   137,   717,   213,   215,   230,   237,   723,   241,    37,
      11,  -333,   736,   247,   141,   353,   258,   264,   794,   272,
     800,   284,   299,   307,   309,  -333,  -333,   -40,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,   937,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  1670,  -333,  -333,   514,
    -333,  -333,  -333,   943,   143,   147,    37,   312,    37,   316,
    -119,    37,    37,   319,   949,    37,    37,    37,   324,   332,
     336,    37,    37,    37,    37,   955,   339,    37,    37,   350,
     355,   357,   358,    37,    37,   361,    37,   363,    37,    37,
      37,    37,    37,   368,    37,   369,    37,   156,  -333,   158,
     976,   -60,  -333,   175,  1486,  -333,   177,  1492,  -333,  -333,
     370,  -333,  1498,  -333,   192,    37,  -333,  -333,  -333,   194,
     198,  -103,  -333,   371,   372,  -333,   208,  1526,  -333,   373,
     386,  -333,   376,  -333,   212,   236,  -333,   240,  -333,   244,
     246,  -333,   252,  -333,  -333,  -333,  -333,   254,  -333,  -333,
    -333,   261,  1506,  -333,  -333,  -333,  -333,   377,  -333,   384,
      37,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,   388,  -333,   387,  -333,  -333,  -333,   389,    15,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,   391,  -333,  -333,    37,  -333,  -333,
      37,  -333,  -333,   263,   268,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  1635,  -333,  -333,  -333,  -333,
    -333,  1643,  -333,  1652,  -333,   270,  1780,  1789,  -333,  -333,
     393,   406,  1795,   407,  -333,  -333,  -333,   408,   418,   425,
     427,  -333,  1909,  -333,   428,   429,  -333,  -333,  -333,  -333,
     447,  1917,  -333,   448,  -333,   449,   451,   452,  1932,   453,
     454,  -333,  1938,  -333,   456,  -333,  -333,  -333,   283,  -333,
    -333,   292,  -333,  -333,   294,  -333,  -333,  -333,   -60,  -333,
    -333,   296,  -333,  -333,  -333,  -333,  -333,  -333,  -333,   302,
    -333,  -333,  -333,  -333,   306,  -333,  -333,  -333,   323,  -333,
    -333,  1958,  -333,  -333,  -333,  -333,   457,  -333,  -333,  -333,
    -333,  -333,   335,  -333,   458,  1238,   347,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  1238,  -333
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,    14,     3,    11,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     111,   110,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   147,   146,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     1,    13,    28,    27,    29,
      24,    25,    26,     0,   288,     8,     0,     4,     5,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   197,   198,     0,     0,     0,    17,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    56,    55,    57,
      58,    59,    60,    61,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    62,    76,    63,    75,     0,
       0,     0,     0,     0,     0,   216,     0,     0,     0,     0,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,     0,     0,     0,     0,   261,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   279,     0,     0,     0,   289,
       0,     0,   292,     0,     0,   295,     0,   297,     0,     0,
     300,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    15,     0,   287,     7,
     304,   174,     6,   175,   176,   177,   178,   179,     0,   181,
     182,   183,   184,   187,   189,   190,     0,   193,    21,    34,
     192,   191,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,    16,   206,     0,     0,   210,     0,     0,   211,   215,
       0,   214,     0,   217,     0,     0,   220,   221,   225,     0,
       0,     0,   226,     0,     0,   229,     0,     0,   234,     0,
       0,   232,     0,   238,     0,     0,   242,     0,   240,     0,
       0,   246,     0,   247,   248,   249,   251,     0,   252,   253,
     258,     0,     0,   259,   260,   262,   263,     0,   265,     0,
       0,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,     0,   280,     0,   282,    33,   286,     0,     0,
     290,   291,   293,   294,   296,   298,   299,   301,   302,   303,
     306,   307,   308,   309,     0,   311,    31,     0,   312,   313,
       0,   314,   315,     0,     0,   319,   320,   170,   171,   172,
     173,   185,   186,   188,   180,     0,    35,   194,    23,   195,
     196,     0,   321,     0,   323,     0,     0,     0,   327,   329,
       0,     0,     0,     0,   333,   334,   335,     0,     0,     0,
       0,   341,     0,   342,     0,     0,   345,   346,   347,   348,
       0,     0,   351,     0,   353,     0,     0,     0,     0,     0,
       0,   360,     0,   362,     0,    18,   199,   200,     0,   203,
     204,     0,   207,   208,     0,   212,   213,   219,     0,   222,
     223,     0,   227,   228,   230,   233,   231,   235,   236,     0,
     241,   239,   243,   244,     0,   250,   255,   256,     0,   264,
     266,     0,   281,   285,    32,   284,     0,   310,    30,     9,
     316,   317,     0,    19,     0,     0,     0,   322,   324,   325,
     326,   328,   330,   331,   332,   336,   337,   338,   339,   340,
     343,   344,   349,   350,   352,   354,   355,   356,   358,   357,
     359,   361,   363,   201,   205,   209,   224,   237,   245,   257,
     267,   283,   318,    20,     0,   364
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -333,  -333,  -332,   466,   314,   -63,  -333,     0,     2,  -115,
    -225,  -333,   -38,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
    -333,  -333,  -333,  -333,  -333,  -333,  -333,   229,  -333,  -333,
    -116,  -333,   188,  -333,  -333,  -333,  -333,  -333,  -333,  -333,
     271,  -333,  -333
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   205,   213,   206,   362,   207,   196,   451,
     399,   403,   208,   360,   529,   227,   228,   237,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
       4,   193,     5,   194,   402,     4,   528,   236,   280,   282,
     287,   291,   339,   526,   547,   292,   293,   295,   654,     1,
     432,   195,   302,   435,   306,   307,   308,   291,   342,   291,
     345,   315,   197,   198,   199,   200,   201,   202,   210,   211,
     197,   198,   199,   200,   201,   202,   219,   232,   337,   233,
     340,   341,   343,   344,   346,   348,   349,   351,   290,   235,
     279,   281,   283,   286,   291,   347,   291,   350,   365,   197,
     198,   199,   200,   201,   202,   338,     1,   376,   291,   309,
       1,   463,   313,   314,   359,   318,   319,   197,   198,   199,
     200,   201,   202,   197,   198,   199,   200,   201,   202,   375,
     197,   198,   199,   200,   201,   202,   291,   466,   291,   467,
     352,   197,   198,   199,   200,   201,   202,   291,   468,   447,
     449,   471,   472,   368,   383,   370,   384,     4,   385,   288,
     197,   198,   199,   200,   201,   202,   197,   198,   199,   200,
     201,   202,   197,   198,   199,   200,   201,   202,     1,   527,
     548,   480,   481,     1,   655,   388,   386,   197,   198,   199,
     200,   201,   202,   387,   453,   390,   456,   203,   204,   391,
     460,   291,   483,   450,   566,   203,   447,   392,   568,   469,
     474,   291,   488,   291,   493,   393,   484,   394,   487,   489,
     490,   291,   494,   395,     4,   497,     4,   656,   400,   501,
     291,   496,   401,   377,   203,   209,   522,   523,   197,   198,
     199,   200,   201,   202,   291,   525,   475,   454,   498,   457,
     291,   530,   284,   285,   462,   291,   531,   503,   203,   312,
       4,     4,   404,   405,   377,   203,   317,   197,   198,   199,
     200,   201,   202,   291,   532,   506,   203,   335,   512,   553,
     291,   533,   502,   197,   198,   199,   200,   201,   202,   197,
     198,   199,   200,   201,   202,   203,   378,   291,   534,   291,
     535,   203,   380,   291,   536,   291,   537,   203,   381,   291,
     552,     1,   569,   513,   377,     1,   570,   515,     4,     4,
     516,   464,   203,   389,   291,   615,   291,   616,     4,   518,
     476,   197,   198,   199,   200,   201,   202,   197,   198,   199,
     200,   201,   202,   291,   619,   291,   622,   519,   197,   198,
     199,   200,   201,   202,   197,   198,   199,   200,   201,   202,
       1,   627,   291,   629,   520,   618,   291,   630,     4,   621,
       5,   521,   624,   396,   397,   573,     1,   634,   576,   577,
     291,   637,   539,   582,   540,   631,   197,   198,   199,   200,
     201,   202,   592,   197,   198,   199,   200,   201,   202,   541,
     639,   601,   234,   448,   291,   638,   542,   644,   291,   640,
     545,   612,   291,   641,   291,   642,   551,   648,   234,   452,
     291,   643,   291,   645,   234,   455,   193,   555,   565,   291,
     646,   291,   660,   556,     4,     4,   291,   661,     1,   668,
       4,   558,   575,   197,   198,   199,   200,   201,   202,   215,
     216,   291,   693,   560,   220,   221,   222,   223,   224,   225,
     291,   694,   291,   695,   291,   696,   203,   458,   561,   662,
     291,   697,   284,   459,   291,   698,   562,   651,   563,   298,
     300,   572,   304,   203,   461,   574,   666,   310,   578,   477,
     478,   291,   699,   584,     4,   321,   322,   323,   325,   326,
     328,   585,   331,   291,   702,   586,     4,   377,   593,   197,
     198,   199,   200,   201,   202,   291,   705,   479,   482,   596,
     355,   234,   357,   358,   597,   361,   598,   599,   234,   486,
     602,   369,   604,   371,   372,   373,   374,   611,   613,   625,
     632,   633,   635,   666,   437,   636,   649,   197,   198,   199,
     200,   201,   202,   650,   445,   473,   652,   664,   653,     4,
     657,     5,   671,   197,   198,   199,   200,   201,   202,   197,
     198,   199,   200,   201,   202,   672,   674,   675,   234,   491,
     447,   197,   198,   199,   200,   201,   202,   676,   197,   198,
     199,   200,   201,   202,   677,     4,   678,   680,   681,   212,
     214,   212,   212,   217,   218,     4,   212,   212,   212,   212,
     212,   212,   226,   229,   230,   231,   682,   684,   685,   447,
     686,   687,   689,   690,   289,   692,   701,   703,   294,   296,
     297,   212,   299,   301,   303,   305,     0,   524,     0,   212,
     311,     0,     0,   316,   203,   495,   320,   212,   212,   212,
     324,   212,   327,   329,   330,   332,   333,   334,   336,     0,
       0,     0,     0,     0,     0,   507,     0,   510,     0,     0,
     353,   354,   212,   356,   212,   212,     0,   212,   363,   364,
     366,   367,   396,   212,     0,   212,   212,   212,   212,   197,
     198,   199,   200,   201,   202,   193,     0,   565,   203,   499,
       0,     0,   379,     0,   234,   500,   379,   379,   382,   197,
     198,   199,   200,   201,   202,   379,   203,   504,     0,     0,
       0,     0,   398,   203,   505,   398,     0,     0,     0,     0,
       0,   379,     0,     0,   193,     0,   194,   197,   198,   199,
     200,   201,   202,   197,   198,   199,   200,   201,   202,     0,
     197,   198,   199,   200,   201,   202,   197,   198,   199,   200,
     201,   202,     0,     0,     0,     0,   588,     0,   590,   197,
     198,   199,   200,   201,   202,   379,     0,   379,     0,   379,
     603,     0,   379,   606,     0,   609,     0,     0,     0,     0,
       0,   470,     0,     0,     0,   382,     0,     0,   485,   382,
       0,     0,   492,     0,     0,   379,     0,     0,     0,   379,
     379,     0,     0,     0,   379,   379,     0,   212,   509,   212,
     382,     0,     0,   382,   203,   508,   382,   197,   198,   199,
     200,   201,   202,   197,   198,   199,   200,   201,   202,     0,
       0,     0,     0,     0,   203,   511,     0,     0,   379,     0,
       0,     0,     0,   544,     0,   546,     0,     0,   550,     0,
       0,   554,     0,     0,   379,     0,   379,     0,     0,     0,
       0,     0,   203,   514,     0,     0,     0,     0,   203,   517,
       0,     0,     0,     0,   379,   203,   538,     0,     0,     0,
       0,   203,   543,     0,     0,   398,     0,     0,     0,   398,
       0,     0,   571,     0,   203,   549,     0,     0,     0,     0,
     580,   581,     0,   583,     0,     0,     0,   587,   212,   589,
     212,     0,     0,   594,   595,     0,     0,     0,     0,   600,
       0,     0,   212,     0,   605,   212,   607,   608,   610,     0,
       0,     0,   614,     0,     0,     0,   379,     0,     0,     0,
     379,     0,     0,   379,     0,     0,     0,     0,   379,     0,
       0,   628,   203,   557,     0,     0,     0,     0,   203,   559,
     197,   198,   199,   200,   201,   202,   197,   198,   199,   200,
     201,   202,   197,   198,   199,   200,   201,   202,   197,   198,
     199,   200,   201,   202,     0,     0,     0,     0,   379,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   197,
     198,   199,   200,   201,   202,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   658,     0,     0,   659,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   398,     0,   379,
       0,     0,   379,   379,     0,     0,     0,     0,   379,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   379,     0,
       0,     0,     0,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,   382,   203,   564,     0,   379,     0,
       0,   396,   567,     0,     0,     0,     0,   203,   579,     0,
       0,     0,     0,   203,   591,     0,     0,   100,   101,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   234,   617,   113,   379,   114,   115,
     406,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
       0,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   234,     0,   186,   187,   188,   189,   190,   191,
     192,   100,   101,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,     0,
     113,     0,   114,   115,   406,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,     0,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,     0,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   704,     0,   186,   187,
     188,   189,   190,   191,   192,   100,   101,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,     0,   113,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,     0,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   197,
     198,   199,   200,   201,   202,   197,   198,   199,   200,   201,
     202,   197,   198,   199,   200,   201,   202,     0,   435,   197,
     198,   199,   200,   201,   202,     0,     0,     0,     0,     0,
     203,     0,   186,   187,   188,   189,   190,   191,   192,   100,
     101,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,     0,   113,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
       0,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   234,   620,     0,     0,     0,     0,
     234,   623,     0,     0,     0,     0,   203,   626,   197,   198,
     199,   200,   201,   202,   234,   647,   197,   198,   199,   200,
     201,   202,     0,     0,   437,   197,   198,   199,   200,   201,
     202,     0,     0,     0,   203,     0,   186,   187,   188,   189,
     190,   191,   192,   100,   101,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,     0,   113,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,     0,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,     0,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,     0,
       0,     0,     0,     1,   663,     0,     0,     0,     0,     0,
       0,   665,   397,   197,   198,   199,   200,   201,   202,     0,
     203,   667,   197,   198,   199,   200,   201,   202,   197,   198,
     199,   200,   201,   202,     0,     0,     0,     0,     1,     0,
     186,   187,   188,   189,   190,   191,   192,   100,   101,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,     0,   113,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     465,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   197,   198,   199,   200,   201,   202,   203,   669,
     197,   198,   199,   200,   201,   202,     0,   203,   670,     0,
       0,     0,     0,   203,   673,   197,   198,   199,   200,   201,
     202,   197,   198,   199,   200,   201,   202,     0,     0,     0,
       0,     0,   203,     0,   186,   187,   188,   189,   190,   191,
     192,   197,   198,   199,   200,   201,   202,     0,     0,     0,
       0,     0,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   203,   679,     0,
       0,     0,     0,     0,     0,   203,   683,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     203,   688,     0,     0,     0,     0,   203,   691,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,   700
};

static const yytype_int16 yycheck[] =
{
       0,     1,     0,     1,   229,     5,   338,   122,   123,   124,
     126,   138,   139,     3,     3,   130,   131,   132,     3,   138,
     123,     0,   137,   126,   139,   140,   141,   138,   139,   138,
     139,   146,     3,     4,     5,     6,     7,     8,   101,   102,
       3,     4,     5,     6,     7,     8,   109,   139,   163,   139,
     165,   166,   167,   168,   169,   170,   171,   172,   139,   122,
     123,   124,   125,   126,   138,   139,   138,   139,   183,     3,
       4,     5,     6,     7,     8,     3,   138,   139,   138,   142,
     138,   139,   145,   146,     3,   148,   149,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,   139,
       3,     4,     5,     6,     7,     8,   138,   139,   138,   139,
     173,     3,     4,     5,     6,     7,     8,   138,   139,   234,
     235,   138,   139,   186,   139,   188,   139,   127,   139,   127,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,     3,     4,     5,     6,     7,     8,   138,   139,
     139,   138,   139,   138,   139,   218,   139,     3,     4,     5,
       6,     7,     8,   139,   279,   139,   281,   138,   139,   139,
     286,   138,   139,   236,   399,   138,   291,   139,   403,   294,
     296,   138,   139,   138,   139,   139,   301,   139,   303,   304,
     305,   138,   139,   139,   194,   310,   196,   529,   139,   314,
     138,   139,   139,   203,   138,   139,   138,   139,     3,     4,
       5,     6,     7,     8,   138,   139,   139,   280,   139,   282,
     138,   139,   138,   139,   287,   138,   139,   139,   138,   139,
     230,   231,   230,   231,   234,   138,   139,     3,     4,     5,
       6,     7,     8,   138,   139,   139,   138,   139,   139,   364,
     138,   139,   315,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,   138,   139,   138,   139,   138,
     139,   138,   139,   138,   139,   138,   139,   138,   139,   138,
     139,   138,   139,   139,   284,   138,   139,   139,   288,   289,
     139,   289,   138,   139,   138,   139,   138,   139,   298,   139,
     298,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,   138,   139,   138,   139,   139,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
     138,   139,   138,   139,   139,   450,   138,   139,   338,   454,
     338,   139,   457,   138,   139,   408,   138,   139,   411,   412,
     138,   139,   139,   416,   139,   470,     3,     4,     5,     6,
       7,     8,   425,     3,     4,     5,     6,     7,     8,   139,
     485,   434,   138,   139,   138,   139,   139,   492,   138,   139,
     139,   444,   138,   139,   138,   139,   139,   502,   138,   139,
     138,   139,   138,   139,   138,   139,   396,   139,   396,   138,
     139,   138,   139,   139,   404,   405,   138,   139,   138,   139,
     410,   139,   410,     3,     4,     5,     6,     7,     8,   105,
     106,   138,   139,   139,   110,   111,   112,   113,   114,   115,
     138,   139,   138,   139,   138,   139,   138,   139,   139,   554,
     138,   139,   138,   139,   138,   139,   139,   510,   139,   135,
     136,   139,   138,   138,   139,   139,   571,   143,   139,   138,
     139,   138,   139,   139,   464,   151,   152,   153,   154,   155,
     156,   139,   158,   138,   139,   139,   476,   477,   139,     3,
       4,     5,     6,     7,     8,   138,   139,   299,   300,   139,
     176,   138,   178,   179,   139,   181,   139,   139,   138,   139,
     139,   187,   139,   189,   190,   191,   192,   139,   139,   139,
     139,   139,   139,   628,   128,   139,   139,     3,     4,     5,
       6,     7,     8,   139,   136,   296,   139,   565,   139,   529,
     139,   529,   139,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,   139,   139,   139,   138,   139,
     665,     3,     4,     5,     6,     7,     8,   139,     3,     4,
       5,     6,     7,     8,   139,   565,   139,   139,   139,   103,
     104,   105,   106,   107,   108,   575,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   139,   139,   139,   704,
     139,   139,   139,   139,   128,   139,   139,   139,   132,   133,
     134,   135,   136,   137,   138,   139,    -1,   336,    -1,   143,
     144,    -1,    -1,   147,   138,   139,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,    -1,    -1,   321,    -1,   323,    -1,    -1,
     174,   175,   176,   177,   178,   179,    -1,   181,   182,   183,
     184,   185,   138,   187,    -1,   189,   190,   191,   192,     3,
       4,     5,     6,     7,     8,   665,    -1,   665,   138,   139,
      -1,    -1,   206,    -1,   138,   139,   210,   211,   212,     3,
       4,     5,     6,     7,     8,   219,   138,   139,    -1,    -1,
      -1,    -1,   226,   138,   139,   229,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,   704,    -1,   704,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,    -1,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,   422,    -1,   424,     3,
       4,     5,     6,     7,     8,   279,    -1,   281,    -1,   283,
     436,    -1,   286,   439,    -1,   441,    -1,    -1,    -1,    -1,
      -1,   295,    -1,    -1,    -1,   299,    -1,    -1,   302,   303,
      -1,    -1,   306,    -1,    -1,   309,    -1,    -1,    -1,   313,
     314,    -1,    -1,    -1,   318,   319,    -1,   321,   322,   323,
     324,    -1,    -1,   327,   138,   139,   330,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,   138,   139,    -1,    -1,   352,    -1,
      -1,    -1,    -1,   357,    -1,   359,    -1,    -1,   362,    -1,
      -1,   365,    -1,    -1,   368,    -1,   370,    -1,    -1,    -1,
      -1,    -1,   138,   139,    -1,    -1,    -1,    -1,   138,   139,
      -1,    -1,    -1,    -1,   388,   138,   139,    -1,    -1,    -1,
      -1,   138,   139,    -1,    -1,   399,    -1,    -1,    -1,   403,
      -1,    -1,   406,    -1,   138,   139,    -1,    -1,    -1,    -1,
     414,   415,    -1,   417,    -1,    -1,    -1,   421,   422,   423,
     424,    -1,    -1,   427,   428,    -1,    -1,    -1,    -1,   433,
      -1,    -1,   436,    -1,   438,   439,   440,   441,   442,    -1,
      -1,    -1,   446,    -1,    -1,    -1,   450,    -1,    -1,    -1,
     454,    -1,    -1,   457,    -1,    -1,    -1,    -1,   462,    -1,
      -1,   465,   138,   139,    -1,    -1,    -1,    -1,   138,   139,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,   502,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   547,    -1,    -1,   550,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   571,    -1,   573,
      -1,    -1,   576,   577,    -1,    -1,    -1,    -1,   582,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   592,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   601,    -1,    -1,
      -1,    -1,    -1,    -1,   608,   138,   139,    -1,   612,    -1,
      -1,   138,   139,    -1,    -1,    -1,    -1,   138,   139,    -1,
      -1,    -1,    -1,   138,   139,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   138,   139,    22,   651,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,    -1,   140,   141,   142,   143,   144,   145,
     146,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    -1,   140,   141,
     142,   143,   144,   145,   146,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,    -1,   126,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,   142,   143,   144,   145,   146,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    22,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   138,   139,    -1,    -1,    -1,    -1,
     138,   139,    -1,    -1,    -1,    -1,   138,   139,     3,     4,
       5,     6,     7,     8,   138,   139,     3,     4,     5,     6,
       7,     8,    -1,    -1,   128,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,   138,    -1,   140,   141,   142,   143,
     144,   145,   146,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,     3,     4,     5,     6,     7,     8,    -1,
     138,   139,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,   142,   143,   144,   145,   146,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      26,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,     3,     4,     5,     6,     7,     8,   138,   139,
       3,     4,     5,     6,     7,     8,    -1,   138,   139,    -1,
      -1,    -1,    -1,   138,   139,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,   142,   143,   144,   145,
     146,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   138,   148,   149,   154,   155,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
       3,     4,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    22,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   140,   141,   142,   143,
     144,   145,   146,   154,   155,     0,   155,     3,     4,     5,
       6,     7,     8,   138,   139,   150,   152,   154,   159,   139,
     152,   152,   150,   151,   150,   151,   151,   150,   150,   152,
     151,   151,   151,   151,   151,   151,   150,   162,   163,   150,
     150,   150,   139,   139,   138,   152,   156,   164,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   152,
     156,   152,   156,   152,   138,   139,   152,   287,   155,   150,
     139,   138,   156,   156,   150,   156,   150,   150,   151,   150,
     151,   150,   156,   150,   151,   150,   156,   156,   156,   152,
     151,   150,   139,   152,   152,   156,   150,   139,   152,   152,
     150,   151,   151,   151,   150,   151,   151,   150,   151,   150,
     150,   151,   150,   150,   150,   139,   150,   156,     3,   139,
     156,   156,   139,   156,   156,   139,   156,   139,   156,   156,
     139,   156,   152,   150,   150,   151,   150,   151,   151,     3,
     160,   151,   153,   150,   150,   156,   150,   150,   152,   151,
     152,   151,   151,   151,   151,   139,   139,   154,   139,   150,
     139,   139,   150,   139,   139,   139,   139,   139,   152,   139,
     139,   139,   139,   139,   139,   139,   138,   139,   150,   157,
     139,   139,   157,   158,   155,   155,    26,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   156,   139,   156,
     152,   156,   139,   156,   152,   139,   156,   152,   139,   139,
     287,   139,   152,   139,   155,    26,   139,   139,   139,   156,
     150,   138,   139,   284,   287,   139,   155,   138,   139,   289,
     138,   139,   289,   139,   156,   150,   139,   156,   139,   156,
     156,   139,   150,   139,   139,   139,   139,   156,   139,   139,
     139,   156,   152,   139,   139,   139,   139,   151,   139,   150,
     151,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   138,   139,   297,   139,     3,   139,   149,   161,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   150,   139,   150,     3,   139,   139,
     150,   139,   139,   156,   150,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   155,   157,   139,   157,   139,
     139,   150,   139,   152,   139,   155,   152,   152,   139,   139,
     150,   150,   152,   150,   139,   139,   139,   150,   151,   150,
     151,   139,   152,   139,   150,   150,   139,   139,   139,   139,
     150,   152,   139,   151,   139,   150,   151,   150,   150,   151,
     150,   139,   152,   139,   150,   139,   139,   139,   156,   139,
     139,   156,   139,   139,   156,   139,   139,   139,   150,   139,
     139,   156,   139,   139,   139,   139,   139,   139,   139,   156,
     139,   139,   139,   139,   156,   139,   139,   139,   156,   139,
     139,   152,   139,   139,     3,   139,   149,   139,   150,   150,
     139,   139,   156,   139,   159,   138,   156,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   138,   139
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   147,   148,   149,   150,   150,   151,   152,   152,   153,
     153,   154,   154,   155,   155,   155,   156,   156,   156,   157,
     157,   157,   158,   158,   159,   159,   159,   159,   159,   159,
     160,   160,   161,   161,   162,   163,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   187,   187,   188,   189,   190,   191,   192,   193,
     193,   193,   193,   194,   194,   194,   194,   195,   195,   195,
     195,   196,   197,   197,   197,   197,   197,   198,   199,   200,
     201,   202,   203,   203,   203,   203,   204,   204,   204,   205,
     206,   207,   207,   207,   207,   208,   208,   208,   208,   209,
     209,   209,   209,   210,   210,   210,   210,   211,   212,   213,
     214,   214,   215,   216,   216,   217,   217,   217,   217,   218,
     219,   219,   220,   221,   222,   223,   223,   224,   225,   225,
     226,   227,   227,   228,   229,   229,   230,   231,   232,   233,
     233,   233,   234,   235,   235,   235,   235,   236,   236,   237,
     237,   238,   239,   239,   240,   241,   241,   242,   242,   243,
     244,   244,   245,   246,   247,   247,   248,   249,   250,   251,
     251,   252,   253,   254,   255,   256,   256,   256,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   293,   294,
     295,   296,   297,   298,   299
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     1,     3,
       1,     1,     3,     2,     1,     3,     2,     1,     3,     3,
       4,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     2,     2,     1,     2,     3,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     5,     5,     3,     3,     5,
       5,     6,     4,     5,     5,     6,     4,     5,     5,     6,
       4,     4,     5,     5,     4,     4,     3,     4,     3,     5,
       4,     4,     5,     5,     6,     4,     4,     5,     5,     4,
       5,     5,     4,     5,     4,     5,     5,     6,     4,     5,
       4,     5,     4,     5,     5,     6,     4,     4,     4,     4,
       5,     4,     4,     4,     3,     5,     5,     6,     4,     4,
       4,     3,     4,     4,     5,     4,     5,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       4,     5,     4,     6,     5,     5,     4,     4,     3,     3,
       4,     4,     3,     4,     4,     3,     4,     3,     4,     4,
       3,     4,     4,     4,     4,     3,     4,     4,     4,     4,
       5,     4,     4,     4,     4,     4,     5,     5,     6,     4,
       4,     3,     4,     3,     4,     4,     4,     3,     4,     3,
       4,     4,     4,     3,     3,     3,     4,     4,     4,     4,
       4,     3,     3,     4,     4,     3,     3,     3,     3,     4,
       4,     3,     4,     3,     4,     4,     4,     4,     4,     4,
       3,     4,     3,     4,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, scanner);
  YYFPRINTF (yyo, ")");
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
#line 78 "../src/parser.y"
      { free(((*yyvaluep).s)); }
#line 1926 "parser.c"
        break;

    case 4: /* STR  */
#line 78 "../src/parser.y"
      { free(((*yyvaluep).s)); }
#line 1932 "parser.c"
        break;

    case 148: /* start  */
#line 76 "../src/parser.y"
      { run(((*yyvaluep).e));  }
#line 1938 "parser.c"
        break;

    case 149: /* s  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1944 "parser.c"
        break;

    case 150: /* p  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1950 "parser.c"
        break;

    case 151: /* pp  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1956 "parser.c"
        break;

    case 152: /* ps  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1962 "parser.c"
        break;

    case 153: /* pps  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1968 "parser.c"
        break;

    case 154: /* vp  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1974 "parser.c"
        break;

    case 155: /* vps  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1980 "parser.c"
        break;

    case 156: /* opts  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1986 "parser.c"
        break;

    case 157: /* xpb  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1992 "parser.c"
        break;

    case 158: /* xpbs  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1998 "parser.c"
        break;

    case 159: /* np  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2004 "parser.c"
        break;

    case 160: /* sps  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2010 "parser.c"
        break;

    case 161: /* par  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2016 "parser.c"
        break;

    case 162: /* cv  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2022 "parser.c"
        break;

    case 163: /* cvv  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2028 "parser.c"
        break;

    case 164: /* opt  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2034 "parser.c"
        break;

    case 165: /* ivp  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2040 "parser.c"
        break;

    case 166: /* add  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2046 "parser.c"
        break;

    case 167: /* div  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2052 "parser.c"
        break;

    case 168: /* mul  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2058 "parser.c"
        break;

    case 169: /* sub  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2064 "parser.c"
        break;

    case 170: /* and  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2070 "parser.c"
        break;

    case 171: /* bitand  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2076 "parser.c"
        break;

    case 172: /* bitnot  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2082 "parser.c"
        break;

    case 173: /* bitor  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2088 "parser.c"
        break;

    case 174: /* bitxor  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2094 "parser.c"
        break;

    case 175: /* not  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2100 "parser.c"
        break;

    case 176: /* in  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2106 "parser.c"
        break;

    case 177: /* or  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2112 "parser.c"
        break;

    case 178: /* shiftleft  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2118 "parser.c"
        break;

    case 179: /* shiftright  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2124 "parser.c"
        break;

    case 180: /* xor  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2130 "parser.c"
        break;

    case 181: /* eq  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2136 "parser.c"
        break;

    case 182: /* gt  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2142 "parser.c"
        break;

    case 183: /* gte  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2148 "parser.c"
        break;

    case 184: /* lt  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2154 "parser.c"
        break;

    case 185: /* lte  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2160 "parser.c"
        break;

    case 186: /* neq  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2166 "parser.c"
        break;

    case 187: /* if  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2172 "parser.c"
        break;

    case 188: /* select  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2178 "parser.c"
        break;

    case 189: /* until  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2184 "parser.c"
        break;

    case 190: /* while  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2190 "parser.c"
        break;

    case 191: /* trace  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2196 "parser.c"
        break;

    case 192: /* retrace  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2202 "parser.c"
        break;

    case 193: /* execute  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2208 "parser.c"
        break;

    case 194: /* rexx  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2214 "parser.c"
        break;

    case 195: /* run  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2220 "parser.c"
        break;

    case 196: /* abort  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2226 "parser.c"
        break;

    case 197: /* exit  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2232 "parser.c"
        break;

    case 198: /* onerror  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2238 "parser.c"
        break;

    case 199: /* reboot  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2244 "parser.c"
        break;

    case 200: /* trap  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2250 "parser.c"
        break;

    case 201: /* copyfiles  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2256 "parser.c"
        break;

    case 202: /* copylib  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2262 "parser.c"
        break;

    case 203: /* delete  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2268 "parser.c"
        break;

    case 204: /* exists  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2274 "parser.c"
        break;

    case 205: /* fileonly  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2280 "parser.c"
        break;

    case 206: /* foreach  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2286 "parser.c"
        break;

    case 207: /* makeassign  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2292 "parser.c"
        break;

    case 208: /* makedir  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2298 "parser.c"
        break;

    case 209: /* protect  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2304 "parser.c"
        break;

    case 210: /* startup  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2310 "parser.c"
        break;

    case 211: /* textfile  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2316 "parser.c"
        break;

    case 212: /* tooltype  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2322 "parser.c"
        break;

    case 213: /* transcript  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2328 "parser.c"
        break;

    case 214: /* rename  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2334 "parser.c"
        break;

    case 215: /* complete  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2340 "parser.c"
        break;

    case 216: /* debug  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2346 "parser.c"
        break;

    case 217: /* message  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2352 "parser.c"
        break;

    case 218: /* user  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2358 "parser.c"
        break;

    case 219: /* welcome  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2364 "parser.c"
        break;

    case 220: /* working  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2370 "parser.c"
        break;

    case 221: /* closemedia  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2376 "parser.c"
        break;

    case 222: /* effect  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2382 "parser.c"
        break;

    case 223: /* setmedia  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2388 "parser.c"
        break;

    case 224: /* showmedia  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2394 "parser.c"
        break;

    case 225: /* database  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2400 "parser.c"
        break;

    case 226: /* earlier  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2406 "parser.c"
        break;

    case 227: /* getassign  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2412 "parser.c"
        break;

    case 228: /* getdevice  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2418 "parser.c"
        break;

    case 229: /* getdiskspace  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2424 "parser.c"
        break;

    case 230: /* getenv  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2430 "parser.c"
        break;

    case 231: /* getsize  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2436 "parser.c"
        break;

    case 232: /* getsum  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2442 "parser.c"
        break;

    case 233: /* getversion  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2448 "parser.c"
        break;

    case 234: /* iconinfo  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2454 "parser.c"
        break;

    case 235: /* dcl  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2460 "parser.c"
        break;

    case 236: /* cus  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2466 "parser.c"
        break;

    case 237: /* askbool  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2472 "parser.c"
        break;

    case 238: /* askchoice  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2478 "parser.c"
        break;

    case 239: /* askdir  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2484 "parser.c"
        break;

    case 240: /* askdisk  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2490 "parser.c"
        break;

    case 241: /* askfile  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2496 "parser.c"
        break;

    case 242: /* asknumber  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2502 "parser.c"
        break;

    case 243: /* askoptions  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2508 "parser.c"
        break;

    case 244: /* askstring  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2514 "parser.c"
        break;

    case 245: /* cat  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2520 "parser.c"
        break;

    case 246: /* expandpath  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2526 "parser.c"
        break;

    case 247: /* fmt  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2532 "parser.c"
        break;

    case 248: /* pathonly  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2538 "parser.c"
        break;

    case 249: /* patmatch  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2544 "parser.c"
        break;

    case 250: /* strlen  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2550 "parser.c"
        break;

    case 251: /* substr  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2556 "parser.c"
        break;

    case 252: /* tackon  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2562 "parser.c"
        break;

    case 253: /* set  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2568 "parser.c"
        break;

    case 254: /* symbolset  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2574 "parser.c"
        break;

    case 255: /* symbolval  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2580 "parser.c"
        break;

    case 256: /* openwbobject  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2586 "parser.c"
        break;

    case 257: /* showwbobject  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2592 "parser.c"
        break;

    case 258: /* closewbobject  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2598 "parser.c"
        break;

    case 259: /* all  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2604 "parser.c"
        break;

    case 260: /* append  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2610 "parser.c"
        break;

    case 261: /* assigns  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2616 "parser.c"
        break;

    case 262: /* back  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2622 "parser.c"
        break;

    case 263: /* choices  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2628 "parser.c"
        break;

    case 264: /* command  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2634 "parser.c"
        break;

    case 265: /* compression  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2640 "parser.c"
        break;

    case 266: /* confirm  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2646 "parser.c"
        break;

    case 267: /* default  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2652 "parser.c"
        break;

    case 268: /* delopts  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2658 "parser.c"
        break;

    case 269: /* dest  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2664 "parser.c"
        break;

    case 270: /* disk  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2670 "parser.c"
        break;

    case 271: /* files  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2676 "parser.c"
        break;

    case 272: /* fonts  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2682 "parser.c"
        break;

    case 273: /* getdefaulttool  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2688 "parser.c"
        break;

    case 274: /* getposition  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2694 "parser.c"
        break;

    case 275: /* getstack  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2700 "parser.c"
        break;

    case 276: /* gettooltype  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2706 "parser.c"
        break;

    case 277: /* help  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2712 "parser.c"
        break;

    case 278: /* infos  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2718 "parser.c"
        break;

    case 279: /* include  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2724 "parser.c"
        break;

    case 280: /* newname  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2730 "parser.c"
        break;

    case 281: /* newpath  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2736 "parser.c"
        break;

    case 282: /* nogauge  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2742 "parser.c"
        break;

    case 283: /* noposition  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2748 "parser.c"
        break;

    case 284: /* noreq  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2754 "parser.c"
        break;

    case 285: /* pattern  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2760 "parser.c"
        break;

    case 286: /* prompt  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2766 "parser.c"
        break;

    case 287: /* quiet  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2772 "parser.c"
        break;

    case 288: /* range  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2778 "parser.c"
        break;

    case 289: /* safe  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2784 "parser.c"
        break;

    case 290: /* setdefaulttool  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2790 "parser.c"
        break;

    case 291: /* setposition  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2796 "parser.c"
        break;

    case 292: /* setstack  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2802 "parser.c"
        break;

    case 293: /* settooltype  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2808 "parser.c"
        break;

    case 294: /* source  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2814 "parser.c"
        break;

    case 295: /* swapcolors  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2820 "parser.c"
        break;

    case 296: /* optional  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2826 "parser.c"
        break;

    case 297: /* resident  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2832 "parser.c"
        break;

    case 298: /* override  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2838 "parser.c"
        break;

    case 299: /* dynopt  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2844 "parser.c"
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
#line 97 "../src/parser.y"
    { (yyval.e) = init((yyvsp[0].e)); }
#line 3114 "parser.c"
    break;

  case 6:
#line 103 "../src/parser.y"
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3120 "parser.c"
    break;

  case 7:
#line 104 "../src/parser.y"
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3126 "parser.c"
    break;

  case 8:
#line 105 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3132 "parser.c"
    break;

  case 9:
#line 106 "../src/parser.y"
    { (yyval.e) = push(push((yyvsp[-2].e), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3138 "parser.c"
    break;

  case 12:
#line 109 "../src/parser.y"
    { (yyval.e) = (yyvsp[-1].e); }
#line 3144 "parser.c"
    break;

  case 13:
#line 110 "../src/parser.y"
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3150 "parser.c"
    break;

  case 14:
#line 111 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3156 "parser.c"
    break;

  case 15:
#line 112 "../src/parser.y"
    { (yyval.e) = (yyvsp[-1].e); }
#line 3162 "parser.c"
    break;

  case 16:
#line 113 "../src/parser.y"
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3168 "parser.c"
    break;

  case 17:
#line 114 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3174 "parser.c"
    break;

  case 18:
#line 115 "../src/parser.y"
    { (yyval.e) = (yyvsp[-1].e); }
#line 3180 "parser.c"
    break;

  case 19:
#line 116 "../src/parser.y"
    { (yyval.e) = (yyvsp[-1].e); }
#line 3186 "parser.c"
    break;

  case 20:
#line 117 "../src/parser.y"
    { (yyval.e) = push((yyvsp[-2].e), (yyvsp[-1].e)); }
#line 3192 "parser.c"
    break;

  case 21:
#line 118 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3198 "parser.c"
    break;

  case 22:
#line 119 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3204 "parser.c"
    break;

  case 23:
#line 120 "../src/parser.y"
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3210 "parser.c"
    break;

  case 24:
#line 121 "../src/parser.y"
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3216 "parser.c"
    break;

  case 25:
#line 122 "../src/parser.y"
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3222 "parser.c"
    break;

  case 26:
#line 123 "../src/parser.y"
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3228 "parser.c"
    break;

  case 27:
#line 124 "../src/parser.y"
    { (yyval.e) = new_string((yyvsp[0].s)); }
#line 3234 "parser.c"
    break;

  case 28:
#line 125 "../src/parser.y"
    { (yyval.e) = new_symref((yyvsp[0].s), LINE); }
#line 3240 "parser.c"
    break;

  case 29:
#line 126 "../src/parser.y"
    { (yyval.e) = NULL; YYFPRINTF(stderr, "Out of memory in line %d\n", LINE); YYABORT; }
#line 3246 "parser.c"
    break;

  case 30:
#line 127 "../src/parser.y"
    { (yyval.e) = push(push((yyvsp[-2].e), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)) ; }
#line 3252 "parser.c"
    break;

  case 31:
#line 128 "../src/parser.y"
    { (yyval.e) = push(push(new_contxt(), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)); }
#line 3258 "parser.c"
    break;

  case 32:
#line 129 "../src/parser.y"
    { (yyval.e) = push((yyvsp[-1].e), new_symbol((yyvsp[0].s))); }
#line 3264 "parser.c"
    break;

  case 33:
#line 130 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), new_symbol((yyvsp[0].s))); }
#line 3270 "parser.c"
    break;

  case 34:
#line 131 "../src/parser.y"
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3276 "parser.c"
    break;

  case 35:
#line 132 "../src/parser.y"
    { (yyval.e) = push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3282 "parser.c"
    break;

  case 170:
#line 273 "../src/parser.y"
    { (yyval.e) = new_native(strdup("+"), LINE, m_add, (yyvsp[-1].e), NUMBER); }
#line 3288 "parser.c"
    break;

  case 171:
#line 274 "../src/parser.y"
    { (yyval.e) = new_native(strdup("/"), LINE, m_div, (yyvsp[-1].e), NUMBER); }
#line 3294 "parser.c"
    break;

  case 172:
#line 275 "../src/parser.y"
    { (yyval.e) = new_native(strdup("*"), LINE, m_mul, (yyvsp[-1].e), NUMBER); }
#line 3300 "parser.c"
    break;

  case 173:
#line 276 "../src/parser.y"
    { (yyval.e) = new_native(strdup("-"), LINE, m_sub, (yyvsp[-1].e), NUMBER); }
#line 3306 "parser.c"
    break;

  case 174:
#line 279 "../src/parser.y"
    { (yyval.e) = new_native(strdup("AND"), LINE, m_and, (yyvsp[-1].e), NUMBER); }
#line 3312 "parser.c"
    break;

  case 175:
#line 280 "../src/parser.y"
    { (yyval.e) = new_native(strdup("BITAND"), LINE, m_bitand, (yyvsp[-1].e), NUMBER); }
#line 3318 "parser.c"
    break;

  case 176:
#line 281 "../src/parser.y"
    { (yyval.e) = new_native(strdup("BITNOT"), LINE, m_bitnot, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3324 "parser.c"
    break;

  case 177:
#line 282 "../src/parser.y"
    { (yyval.e) = new_native(strdup("BITOR"), LINE, m_bitor, (yyvsp[-1].e), NUMBER); }
#line 3330 "parser.c"
    break;

  case 178:
#line 283 "../src/parser.y"
    { (yyval.e) = new_native(strdup("BITXOR"), LINE, m_bitxor, (yyvsp[-1].e), NUMBER); }
#line 3336 "parser.c"
    break;

  case 179:
#line 284 "../src/parser.y"
    { (yyval.e) = new_native(strdup("NOT"), LINE, m_not, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3342 "parser.c"
    break;

  case 180:
#line 285 "../src/parser.y"
    { (yyval.e) = new_native(strdup("IN"), LINE, m_in, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3348 "parser.c"
    break;

  case 181:
#line 286 "../src/parser.y"
    { (yyval.e) = new_native(strdup("OR"), LINE, m_or, (yyvsp[-1].e), NUMBER); }
#line 3354 "parser.c"
    break;

  case 182:
#line 287 "../src/parser.y"
    { (yyval.e) = new_native(strdup("shiftleft"), LINE, m_shiftleft, (yyvsp[-1].e), NUMBER); }
#line 3360 "parser.c"
    break;

  case 183:
#line 288 "../src/parser.y"
    { (yyval.e) = new_native(strdup("shiftright"), LINE, m_shiftright, (yyvsp[-1].e), NUMBER); }
#line 3366 "parser.c"
    break;

  case 184:
#line 289 "../src/parser.y"
    { (yyval.e) = new_native(strdup("XOR"), LINE, m_xor, (yyvsp[-1].e), NUMBER); }
#line 3372 "parser.c"
    break;

  case 185:
#line 292 "../src/parser.y"
    { (yyval.e) = new_native(strdup("="), LINE, m_eq, (yyvsp[-1].e), NUMBER); }
#line 3378 "parser.c"
    break;

  case 186:
#line 293 "../src/parser.y"
    { (yyval.e) = new_native(strdup(">"), LINE, m_gt, (yyvsp[-1].e), NUMBER); }
#line 3384 "parser.c"
    break;

  case 187:
#line 294 "../src/parser.y"
    { (yyval.e) = new_native(strdup(">="), LINE, m_gte, (yyvsp[-1].e), NUMBER); }
#line 3390 "parser.c"
    break;

  case 188:
#line 295 "../src/parser.y"
    { (yyval.e) = new_native(strdup("<"), LINE, m_lt, (yyvsp[-1].e), NUMBER); }
#line 3396 "parser.c"
    break;

  case 189:
#line 296 "../src/parser.y"
    { (yyval.e) = new_native(strdup("<="), LINE, m_lte, (yyvsp[-1].e), NUMBER); }
#line 3402 "parser.c"
    break;

  case 190:
#line 297 "../src/parser.y"
    { (yyval.e) = new_native(strdup("<>"), LINE, m_neq, (yyvsp[-1].e), NUMBER); }
#line 3408 "parser.c"
    break;

  case 191:
#line 300 "../src/parser.y"
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3414 "parser.c"
    break;

  case 192:
#line 301 "../src/parser.y"
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3420 "parser.c"
    break;

  case 193:
#line 302 "../src/parser.y"
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3426 "parser.c"
    break;

  case 194:
#line 303 "../src/parser.y"
    { (yyval.e) = new_native(strdup("select"), LINE, m_select, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3432 "parser.c"
    break;

  case 195:
#line 304 "../src/parser.y"
    { (yyval.e) = new_native(strdup("until"), LINE, m_until, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3438 "parser.c"
    break;

  case 196:
#line 305 "../src/parser.y"
    { (yyval.e) = new_native(strdup("while"), LINE, m_while, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3444 "parser.c"
    break;

  case 197:
#line 306 "../src/parser.y"
    { (yyval.e) = new_native(strdup("trace"), LINE, m_trace, NULL, NUMBER); }
#line 3450 "parser.c"
    break;

  case 198:
#line 307 "../src/parser.y"
    { (yyval.e) = new_native(strdup("retrace"), LINE, m_retrace, NULL, NUMBER); }
#line 3456 "parser.c"
    break;

  case 199:
#line 310 "../src/parser.y"
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3462 "parser.c"
    break;

  case 200:
#line 311 "../src/parser.y"
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3468 "parser.c"
    break;

  case 201:
#line 312 "../src/parser.y"
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3474 "parser.c"
    break;

  case 202:
#line 313 "../src/parser.y"
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, (yyvsp[-1].e), NUMBER); }
#line 3480 "parser.c"
    break;

  case 203:
#line 314 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3486 "parser.c"
    break;

  case 204:
#line 315 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3492 "parser.c"
    break;

  case 205:
#line 316 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3498 "parser.c"
    break;

  case 206:
#line 317 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, (yyvsp[-1].e), NUMBER); }
#line 3504 "parser.c"
    break;

  case 207:
#line 318 "../src/parser.y"
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3510 "parser.c"
    break;

  case 208:
#line 319 "../src/parser.y"
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3516 "parser.c"
    break;

  case 209:
#line 320 "../src/parser.y"
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3522 "parser.c"
    break;

  case 210:
#line 321 "../src/parser.y"
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, (yyvsp[-1].e), NUMBER); }
#line 3528 "parser.c"
    break;

  case 211:
#line 324 "../src/parser.y"
    { (yyval.e) = new_native(strdup("abort"), LINE, m_abort, (yyvsp[-1].e), NUMBER); }
#line 3534 "parser.c"
    break;

  case 212:
#line 325 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3540 "parser.c"
    break;

  case 213:
#line 326 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3546 "parser.c"
    break;

  case 214:
#line 327 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3552 "parser.c"
    break;

  case 215:
#line 328 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, (yyvsp[-1].e), NUMBER); }
#line 3558 "parser.c"
    break;

  case 216:
#line 329 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, NULL, NUMBER); }
#line 3564 "parser.c"
    break;

  case 217:
#line 330 "../src/parser.y"
    { (yyval.e) = new_native(strdup("onerror"), LINE, m_procedure, push(new_contxt(),
                                                        new_custom(strdup("@onerror"), LINE, NULL, (yyvsp[-1].e))), DANGLE); }
#line 3571 "parser.c"
    break;

  case 218:
#line 332 "../src/parser.y"
    { (yyval.e) = new_native(strdup("reboot"), LINE, m_reboot, NULL, NUMBER); }
#line 3577 "parser.c"
    break;

  case 219:
#line 333 "../src/parser.y"
    { (yyval.e) = new_native(strdup("trap"), LINE, m_trap, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3583 "parser.c"
    break;

  case 220:
#line 336 "../src/parser.y"
    { (yyval.e) = new_native(strdup("copyfiles"), LINE, m_copyfiles, (yyvsp[-1].e), NUMBER); }
#line 3589 "parser.c"
    break;

  case 221:
#line 337 "../src/parser.y"
    { (yyval.e) = new_native(strdup("copylib"), LINE, m_copylib, (yyvsp[-1].e), NUMBER); }
#line 3595 "parser.c"
    break;

  case 222:
#line 338 "../src/parser.y"
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3601 "parser.c"
    break;

  case 223:
#line 339 "../src/parser.y"
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3607 "parser.c"
    break;

  case 224:
#line 340 "../src/parser.y"
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3613 "parser.c"
    break;

  case 225:
#line 341 "../src/parser.y"
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3619 "parser.c"
    break;

  case 226:
#line 342 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3625 "parser.c"
    break;

  case 227:
#line 343 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3631 "parser.c"
    break;

  case 228:
#line 344 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3637 "parser.c"
    break;

  case 229:
#line 345 "../src/parser.y"
    { (yyval.e) = new_native(strdup("fileonly"), LINE, m_fileonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3643 "parser.c"
    break;

  case 230:
#line 346 "../src/parser.y"
    { (yyval.e) = new_native(strdup("foreach"), LINE, m_foreach, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3649 "parser.c"
    break;

  case 231:
#line 347 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3655 "parser.c"
    break;

  case 232:
#line 348 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, (yyvsp[-1].e), NUMBER); }
#line 3661 "parser.c"
    break;

  case 233:
#line 349 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3667 "parser.c"
    break;

  case 234:
#line 350 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3673 "parser.c"
    break;

  case 235:
#line 351 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3679 "parser.c"
    break;

  case 236:
#line 352 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3685 "parser.c"
    break;

  case 237:
#line 353 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3691 "parser.c"
    break;

  case 238:
#line 354 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3697 "parser.c"
    break;

  case 239:
#line 355 "../src/parser.y"
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3703 "parser.c"
    break;

  case 240:
#line 356 "../src/parser.y"
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, (yyvsp[-1].e), NUMBER); }
#line 3709 "parser.c"
    break;

  case 241:
#line 357 "../src/parser.y"
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3715 "parser.c"
    break;

  case 242:
#line 358 "../src/parser.y"
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3721 "parser.c"
    break;

  case 243:
#line 359 "../src/parser.y"
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3727 "parser.c"
    break;

  case 244:
#line 360 "../src/parser.y"
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3733 "parser.c"
    break;

  case 245:
#line 361 "../src/parser.y"
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3739 "parser.c"
    break;

  case 246:
#line 362 "../src/parser.y"
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), new_symref(strdup("@app-name"), LINE)), (yyvsp[-1].e)), NUMBER); }
#line 3745 "parser.c"
    break;

  case 247:
#line 363 "../src/parser.y"
    { (yyval.e) = new_native(strdup("textfile"), LINE, m_textfile, (yyvsp[-1].e), NUMBER); }
#line 3751 "parser.c"
    break;

  case 248:
#line 364 "../src/parser.y"
    { (yyval.e) = new_native(strdup("tooltype"), LINE, m_tooltype, (yyvsp[-1].e), NUMBER); }
#line 3757 "parser.c"
    break;

  case 249:
#line 365 "../src/parser.y"
    { (yyval.e) = new_native(strdup("transcript"), LINE, m_transcript, (yyvsp[-1].e), NUMBER); }
#line 3763 "parser.c"
    break;

  case 250:
#line 366 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3769 "parser.c"
    break;

  case 251:
#line 367 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, (yyvsp[-1].e), NUMBER); }
#line 3775 "parser.c"
    break;

  case 252:
#line 370 "../src/parser.y"
    { (yyval.e) = new_native(strdup("complete"), LINE, m_complete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3781 "parser.c"
    break;

  case 253:
#line 371 "../src/parser.y"
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, (yyvsp[-1].e), NUMBER); }
#line 3787 "parser.c"
    break;

  case 254:
#line 372 "../src/parser.y"
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, NULL, NUMBER); }
#line 3793 "parser.c"
    break;

  case 255:
#line 373 "../src/parser.y"
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, merge((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3799 "parser.c"
    break;

  case 256:
#line 374 "../src/parser.y"
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3805 "parser.c"
    break;

  case 257:
#line 375 "../src/parser.y"
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, push(merge((yyvsp[-3].e), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3811 "parser.c"
    break;

  case 258:
#line 376 "../src/parser.y"
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, (yyvsp[-1].e), NUMBER); }
#line 3817 "parser.c"
    break;

  case 259:
#line 377 "../src/parser.y"
    { (yyval.e) = new_native(strdup("user"), LINE, m_user, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3823 "parser.c"
    break;

  case 260:
#line 378 "../src/parser.y"
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, (yyvsp[-1].e), NUMBER); }
#line 3829 "parser.c"
    break;

  case 261:
#line 379 "../src/parser.y"
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, NULL, NUMBER); }
#line 3835 "parser.c"
    break;

  case 262:
#line 380 "../src/parser.y"
    { (yyval.e) = new_native(strdup("working"), LINE, m_working, (yyvsp[-1].e), NUMBER); }
#line 3841 "parser.c"
    break;

  case 263:
#line 383 "../src/parser.y"
    { (yyval.e) = new_native(strdup("closemedia"), LINE, m_closemedia, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3847 "parser.c"
    break;

  case 264:
#line 384 "../src/parser.y"
    { (yyval.e) = new_native(strdup("effect"), LINE, m_effect, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3853 "parser.c"
    break;

  case 265:
#line 385 "../src/parser.y"
    { (yyval.e) = new_native(strdup("setmedia"), LINE, m_setmedia, (yyvsp[-1].e), NUMBER); }
#line 3859 "parser.c"
    break;

  case 266:
#line 386 "../src/parser.y"
    { (yyval.e) = new_native(strdup("setmedia"), LINE, m_setmedia, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3865 "parser.c"
    break;

  case 267:
#line 387 "../src/parser.y"
    { (yyval.e) = new_native(strdup("showmedia"), LINE, m_showmedia, merge(merge((yyvsp[-3].e), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3871 "parser.c"
    break;

  case 268:
#line 390 "../src/parser.y"
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3877 "parser.c"
    break;

  case 269:
#line 391 "../src/parser.y"
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, (yyvsp[-1].e), STRING); }
#line 3883 "parser.c"
    break;

  case 270:
#line 392 "../src/parser.y"
    { (yyval.e) = new_native(strdup("earlier"), LINE, m_earlier, (yyvsp[-1].e), NUMBER); }
#line 3889 "parser.c"
    break;

  case 271:
#line 393 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3895 "parser.c"
    break;

  case 272:
#line 394 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, (yyvsp[-1].e), STRING); }
#line 3901 "parser.c"
    break;

  case 273:
#line 395 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getdevice"), LINE, m_getdevice, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3907 "parser.c"
    break;

  case 274:
#line 396 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3913 "parser.c"
    break;

  case 275:
#line 397 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, (yyvsp[-1].e), NUMBER); }
#line 3919 "parser.c"
    break;

  case 276:
#line 398 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getenv"), LINE, m_getenv, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3925 "parser.c"
    break;

  case 277:
#line 399 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getsize"), LINE, m_getsize, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3931 "parser.c"
    break;

  case 278:
#line 400 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getsum"), LINE, m_getsum, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3937 "parser.c"
    break;

  case 279:
#line 401 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, NULL, NUMBER); }
#line 3943 "parser.c"
    break;

  case 280:
#line 402 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3949 "parser.c"
    break;

  case 281:
#line 403 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3955 "parser.c"
    break;

  case 282:
#line 404 "../src/parser.y"
    { (yyval.e) = new_native(strdup("iconinfo"), LINE, m_iconinfo, (yyvsp[-1].e), NUMBER); }
#line 3961 "parser.c"
    break;

  case 283:
#line 407 "../src/parser.y"
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-3].s), LINE, (yyvsp[-2].e), (yyvsp[-1].e))), NUMBER); }
#line 3967 "parser.c"
    break;

  case 284:
#line 408 "../src/parser.y"
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, (yyvsp[-1].e), NULL)), NUMBER); }
#line 3973 "parser.c"
    break;

  case 285:
#line 409 "../src/parser.y"
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, NULL, (yyvsp[-1].e))), NUMBER); }
#line 3979 "parser.c"
    break;

  case 286:
#line 410 "../src/parser.y"
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-1].s), LINE, NULL, NULL)), NUMBER); }
#line 3985 "parser.c"
    break;

  case 287:
#line 411 "../src/parser.y"
    { (yyval.e) = new_cusref((yyvsp[-2].s), LINE, (yyvsp[-1].e)); }
#line 3991 "parser.c"
    break;

  case 288:
#line 412 "../src/parser.y"
    { (yyval.e) = new_cusref((yyvsp[-1].s), LINE, NULL); }
#line 3997 "parser.c"
    break;

  case 289:
#line 415 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, NULL, NUMBER); }
#line 4003 "parser.c"
    break;

  case 290:
#line 416 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, (yyvsp[-1].e), NUMBER); }
#line 4009 "parser.c"
    break;

  case 291:
#line 417 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askchoice"), LINE, m_askchoice, (yyvsp[-1].e), NUMBER); }
#line 4015 "parser.c"
    break;

  case 292:
#line 418 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, NULL, STRING); }
#line 4021 "parser.c"
    break;

  case 293:
#line 419 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, (yyvsp[-1].e), STRING); }
#line 4027 "parser.c"
    break;

  case 294:
#line 420 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askdisk"), LINE, m_askdisk, (yyvsp[-1].e), NUMBER); }
#line 4033 "parser.c"
    break;

  case 295:
#line 421 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, NULL, STRING); }
#line 4039 "parser.c"
    break;

  case 296:
#line 422 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, (yyvsp[-1].e), STRING); }
#line 4045 "parser.c"
    break;

  case 297:
#line 423 "../src/parser.y"
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, NULL, NUMBER); }
#line 4051 "parser.c"
    break;

  case 298:
#line 424 "../src/parser.y"
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, (yyvsp[-1].e), NUMBER); }
#line 4057 "parser.c"
    break;

  case 299:
#line 425 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askoptions"), LINE, m_askoptions, (yyvsp[-1].e), NUMBER); }
#line 4063 "parser.c"
    break;

  case 300:
#line 426 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, NULL, STRING); }
#line 4069 "parser.c"
    break;

  case 301:
#line 427 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, (yyvsp[-1].e), STRING); }
#line 4075 "parser.c"
    break;

  case 302:
#line 430 "../src/parser.y"
    { (yyval.e) = new_native(strdup("cat"), LINE, m_cat, (yyvsp[-1].e), STRING); }
#line 4081 "parser.c"
    break;

  case 303:
#line 431 "../src/parser.y"
    { (yyval.e) = new_native(strdup("expandpath"), LINE, m_expandpath, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4087 "parser.c"
    break;

  case 304:
#line 432 "../src/parser.y"
    { (yyval.e) = new_native((yyvsp[-2].s), LINE, m_fmt, (yyvsp[-1].e), STRING); }
#line 4093 "parser.c"
    break;

  case 305:
#line 433 "../src/parser.y"
    { (yyval.e) = new_native((yyvsp[-1].s), LINE, m_fmt, NULL, STRING); }
#line 4099 "parser.c"
    break;

  case 306:
#line 434 "../src/parser.y"
    { (yyval.e) = new_native(strdup("pathonly"), LINE, m_pathonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4105 "parser.c"
    break;

  case 307:
#line 435 "../src/parser.y"
    { (yyval.e) = new_native(strdup("patmatch"), LINE, m_patmatch, (yyvsp[-1].e), NUMBER); }
#line 4111 "parser.c"
    break;

  case 308:
#line 436 "../src/parser.y"
    { (yyval.e) = new_native(strdup("strlen"), LINE, m_strlen, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4117 "parser.c"
    break;

  case 309:
#line 437 "../src/parser.y"
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, (yyvsp[-1].e), STRING); }
#line 4123 "parser.c"
    break;

  case 310:
#line 438 "../src/parser.y"
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, push((yyvsp[-2].e), (yyvsp[-1].e)), STRING); }
#line 4129 "parser.c"
    break;

  case 311:
#line 439 "../src/parser.y"
    { (yyval.e) = new_native(strdup("tackon"), LINE, m_tackon, (yyvsp[-1].e), STRING); }
#line 4135 "parser.c"
    break;

  case 312:
#line 442 "../src/parser.y"
    { (yyval.e) = new_native(strdup("set"), LINE, m_set, (yyvsp[-1].e), DANGLE); }
#line 4141 "parser.c"
    break;

  case 313:
#line 443 "../src/parser.y"
    { (yyval.e) = new_native(strdup("symbolset"), LINE, m_symbolset, (yyvsp[-1].e), DANGLE); }
#line 4147 "parser.c"
    break;

  case 314:
#line 444 "../src/parser.y"
    { (yyval.e) = new_native(strdup("symbolval"), LINE, m_symbolval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4153 "parser.c"
    break;

  case 315:
#line 447 "../src/parser.y"
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4159 "parser.c"
    break;

  case 316:
#line 448 "../src/parser.y"
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4165 "parser.c"
    break;

  case 317:
#line 449 "../src/parser.y"
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4171 "parser.c"
    break;

  case 318:
#line 450 "../src/parser.y"
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4177 "parser.c"
    break;

  case 319:
#line 451 "../src/parser.y"
    { (yyval.e) = new_native(strdup("showwbobject"), LINE, m_showwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4183 "parser.c"
    break;

  case 320:
#line 452 "../src/parser.y"
    { (yyval.e) = new_native(strdup("closewbobject"), LINE, m_closewbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4189 "parser.c"
    break;

  case 321:
#line 455 "../src/parser.y"
    { (yyval.e) = new_option(strdup("all"), OPT_ALL, NULL); }
#line 4195 "parser.c"
    break;

  case 322:
#line 456 "../src/parser.y"
    { (yyval.e) = new_option(strdup("append"), OPT_APPEND, (yyvsp[-1].e)); }
#line 4201 "parser.c"
    break;

  case 323:
#line 457 "../src/parser.y"
    { (yyval.e) = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); }
#line 4207 "parser.c"
    break;

  case 324:
#line 458 "../src/parser.y"
    { (yyval.e) = new_option(strdup("back"), OPT_BACK, (yyvsp[-1].e)); }
#line 4213 "parser.c"
    break;

  case 325:
#line 459 "../src/parser.y"
    { (yyval.e) = new_option(strdup("choices"), OPT_CHOICES, (yyvsp[-1].e)); }
#line 4219 "parser.c"
    break;

  case 326:
#line 460 "../src/parser.y"
    { (yyval.e) = new_option(strdup("command"), OPT_COMMAND, (yyvsp[-1].e)); }
#line 4225 "parser.c"
    break;

  case 327:
#line 461 "../src/parser.y"
    { (yyval.e) = new_option(strdup("compression"), OPT_COMPRESSION, NULL); }
#line 4231 "parser.c"
    break;

  case 328:
#line 462 "../src/parser.y"
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, push(new_contxt(), (yyvsp[-1].e))); }
#line 4237 "parser.c"
    break;

  case 329:
#line 463 "../src/parser.y"
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, NULL); }
#line 4243 "parser.c"
    break;

  case 330:
#line 464 "../src/parser.y"
    { (yyval.e) = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), (yyvsp[-1].e))); }
#line 4249 "parser.c"
    break;

  case 331:
#line 465 "../src/parser.y"
    { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, (yyvsp[-1].e)); }
#line 4255 "parser.c"
    break;

  case 332:
#line 466 "../src/parser.y"
    { (yyval.e) = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), (yyvsp[-1].e))); }
#line 4261 "parser.c"
    break;

  case 333:
#line 467 "../src/parser.y"
    { (yyval.e) = new_option(strdup("disk"), OPT_DISK, NULL); }
#line 4267 "parser.c"
    break;

  case 334:
#line 468 "../src/parser.y"
    { (yyval.e) = new_option(strdup("files"), OPT_FILES, NULL); }
#line 4273 "parser.c"
    break;

  case 335:
#line 469 "../src/parser.y"
    { (yyval.e) = new_option(strdup("fonts"), OPT_FONTS, NULL); }
#line 4279 "parser.c"
    break;

  case 336:
#line 470 "../src/parser.y"
    { (yyval.e) = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4285 "parser.c"
    break;

  case 337:
#line 471 "../src/parser.y"
    { (yyval.e) = new_option(strdup("getposition"), OPT_GETPOSITION, (yyvsp[-1].e)); }
#line 4291 "parser.c"
    break;

  case 338:
#line 472 "../src/parser.y"
    { (yyval.e) = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4297 "parser.c"
    break;

  case 339:
#line 473 "../src/parser.y"
    { (yyval.e) = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, (yyvsp[-1].e)); }
#line 4303 "parser.c"
    break;

  case 340:
#line 474 "../src/parser.y"
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, (yyvsp[-1].e)); }
#line 4309 "parser.c"
    break;

  case 341:
#line 475 "../src/parser.y"
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4315 "parser.c"
    break;

  case 342:
#line 476 "../src/parser.y"
    { (yyval.e) = new_option(strdup("infos"), OPT_INFOS, NULL); }
#line 4321 "parser.c"
    break;

  case 343:
#line 477 "../src/parser.y"
    { (yyval.e) = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4327 "parser.c"
    break;

  case 344:
#line 478 "../src/parser.y"
    { (yyval.e) = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), (yyvsp[-1].e))); }
#line 4333 "parser.c"
    break;

  case 345:
#line 479 "../src/parser.y"
    { (yyval.e) = new_option(strdup("newpath"), OPT_NEWPATH, NULL); }
#line 4339 "parser.c"
    break;

  case 346:
#line 480 "../src/parser.y"
    { (yyval.e) = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); }
#line 4345 "parser.c"
    break;

  case 347:
#line 481 "../src/parser.y"
    { (yyval.e) = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); }
#line 4351 "parser.c"
    break;

  case 348:
#line 482 "../src/parser.y"
    { (yyval.e) = new_option(strdup("noreq"), OPT_NOREQ, NULL); }
#line 4357 "parser.c"
    break;

  case 349:
#line 483 "../src/parser.y"
    { (yyval.e) = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), (yyvsp[-1].e))); }
#line 4363 "parser.c"
    break;

  case 350:
#line 484 "../src/parser.y"
    { (yyval.e) = new_option(strdup("prompt"), OPT_PROMPT, (yyvsp[-1].e)); }
#line 4369 "parser.c"
    break;

  case 351:
#line 485 "../src/parser.y"
    { (yyval.e) = new_option(strdup("quiet"), OPT_QUIET, NULL); }
#line 4375 "parser.c"
    break;

  case 352:
#line 486 "../src/parser.y"
    { (yyval.e) = new_option(strdup("range"), OPT_RANGE, (yyvsp[-1].e)); }
#line 4381 "parser.c"
    break;

  case 353:
#line 487 "../src/parser.y"
    { (yyval.e) = new_option(strdup("safe"), OPT_SAFE, NULL); }
#line 4387 "parser.c"
    break;

  case 354:
#line 488 "../src/parser.y"
    { (yyval.e) = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4393 "parser.c"
    break;

  case 355:
#line 489 "../src/parser.y"
    { (yyval.e) = new_option(strdup("setposition"), OPT_SETPOSITION, (yyvsp[-1].e)); }
#line 4399 "parser.c"
    break;

  case 356:
#line 490 "../src/parser.y"
    { (yyval.e) = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4405 "parser.c"
    break;

  case 357:
#line 491 "../src/parser.y"
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, (yyvsp[-1].e)); }
#line 4411 "parser.c"
    break;

  case 358:
#line 492 "../src/parser.y"
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4417 "parser.c"
    break;

  case 359:
#line 493 "../src/parser.y"
    { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4423 "parser.c"
    break;

  case 360:
#line 494 "../src/parser.y"
    { (yyval.e) = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); }
#line 4429 "parser.c"
    break;

  case 361:
#line 495 "../src/parser.y"
    { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, (yyvsp[-1].e)); }
#line 4435 "parser.c"
    break;

  case 362:
#line 496 "../src/parser.y"
    { (yyval.e) = new_option(strdup("resident"), OPT_RESIDENT, NULL); }
#line 4441 "parser.c"
    break;

  case 363:
#line 497 "../src/parser.y"
    { (yyval.e) = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4447 "parser.c"
    break;

  case 364:
#line 498 "../src/parser.y"
    { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4453 "parser.c"
    break;


#line 4457 "parser.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 500 "../src/parser.y"

