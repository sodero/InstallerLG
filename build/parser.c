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

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* parser.y:                                                                                                                                                                            */
/*                                                                                                                                                                                      */
/* InstallerLG parser                                                                                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Copyright (C) 2018-2020, Ola Söder. All rights reserved.                                                                                                                             */
/* Licensed under the AROS PUBLIC LICENSE (APL) Version 1.1                                                                                                                             */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

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
    EXECUTE = 276,
    REXX = 277,
    RUN = 278,
    ABORT = 279,
    EXIT = 280,
    ONERROR = 281,
    TRAP = 282,
    REBOOT = 283,
    COPYFILES = 284,
    COPYLIB = 285,
    DELETE = 286,
    EXISTS = 287,
    FILEONLY = 288,
    FOREACH = 289,
    MAKEASSIGN = 290,
    MAKEDIR = 291,
    PROTECT = 292,
    STARTUP = 293,
    TEXTFILE = 294,
    TOOLTYPE = 295,
    TRANSCRIPT = 296,
    RENAME = 297,
    COMPLETE = 298,
    DEBUG = 299,
    MESSAGE = 300,
    USER = 301,
    WELCOME = 302,
    WORKING = 303,
    AND = 304,
    BITAND = 305,
    BITNOT = 306,
    BITOR = 307,
    BITXOR = 308,
    NOT = 309,
    IN = 310,
    OR = 311,
    SHIFTLEFT = 312,
    SHIFTRIGHT = 313,
    XOR = 314,
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
    QUERYDISPLAY = 329,
    CUS = 330,
    DCL = 331,
    ASKBOOL = 332,
    ASKCHOICE = 333,
    ASKDIR = 334,
    ASKDISK = 335,
    ASKFILE = 336,
    ASKNUMBER = 337,
    ASKOPTIONS = 338,
    ASKSTRING = 339,
    CAT = 340,
    EXPANDPATH = 341,
    FMT = 342,
    PATHONLY = 343,
    PATMATCH = 344,
    STRLEN = 345,
    SUBSTR = 346,
    TACKON = 347,
    SET = 348,
    SYMBOLSET = 349,
    SYMBOLVAL = 350,
    OPENWBOBJECT = 351,
    SHOWWBOBJECT = 352,
    CLOSEWBOBJECT = 353,
    ALL = 354,
    APPEND = 355,
    ASSIGNS = 356,
    BACK = 357,
    CHOICES = 358,
    COMMAND = 359,
    COMPRESSION = 360,
    CONFIRM = 361,
    DEFAULT = 362,
    DELOPTS = 363,
    DEST = 364,
    DISK = 365,
    FILES = 366,
    FONTS = 367,
    GETDEFAULTTOOL = 368,
    GETPOSITION = 369,
    GETSTACK = 370,
    GETTOOLTYPE = 371,
    HELP = 372,
    INFOS = 373,
    INCLUDE = 374,
    NEWNAME = 375,
    NEWPATH = 376,
    NOGAUGE = 377,
    NOPOSITION = 378,
    NOREQ = 379,
    PATTERN = 380,
    PROMPT = 381,
    QUIET = 382,
    RANGE = 383,
    SAFE = 384,
    SETDEFAULTTOOL = 385,
    SETPOSITION = 386,
    SETSTACK = 387,
    SETTOOLTYPE = 388,
    SOURCE = 389,
    SWAPCOLORS = 390,
    OPTIONAL = 391,
    RESIDENT = 392,
    OVERRIDE = 393
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
#define YYFINAL  281
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2251

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  148
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  154
/* YYNRULES -- Number of rules.  */
#define YYNRULES  369
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  716

#define YYUNDEFTOK  2
#define YYMAXUTOK   393

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
     139,   140,   143,   141,     2,   144,     2,   142,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     147,   145,   146,     2,     2,     2,     2,     2,     2,     2,
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
     135,   136,   137,   138
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    87,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   269,   270,   271,   272,   276,   277,   278,
     279,   280,   281,   285,   286,   287,   288,   289,   290,   291,
     292,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   311,   312,   313,   314,   315,   316,   317,
     319,   320,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   387,   388,   389,   390,
     391,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   414,   415,   416,
     417,   418,   419,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   452,   453,   454,   458,
     459,   460,   461,   462,   463,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SYM", "STR", "OOM", "INT", "HEX", "BIN",
  "EQ", "GT", "GTE", "LT", "LTE", "NEQ", "IF", "SELECT", "UNTIL", "WHILE",
  "TRACE", "RETRACE", "EXECUTE", "REXX", "RUN", "ABORT", "EXIT", "ONERROR",
  "TRAP", "REBOOT", "COPYFILES", "COPYLIB", "DELETE", "EXISTS", "FILEONLY",
  "FOREACH", "MAKEASSIGN", "MAKEDIR", "PROTECT", "STARTUP", "TEXTFILE",
  "TOOLTYPE", "TRANSCRIPT", "RENAME", "COMPLETE", "DEBUG", "MESSAGE",
  "USER", "WELCOME", "WORKING", "AND", "BITAND", "BITNOT", "BITOR",
  "BITXOR", "NOT", "IN", "OR", "SHIFTLEFT", "SHIFTRIGHT", "XOR",
  "CLOSEMEDIA", "EFFECT", "SETMEDIA", "SHOWMEDIA", "DATABASE", "EARLIER",
  "GETASSIGN", "GETDEVICE", "GETDISKSPACE", "GETENV", "GETSIZE", "GETSUM",
  "GETVERSION", "ICONINFO", "QUERYDISPLAY", "CUS", "DCL", "ASKBOOL",
  "ASKCHOICE", "ASKDIR", "ASKDISK", "ASKFILE", "ASKNUMBER", "ASKOPTIONS",
  "ASKSTRING", "CAT", "EXPANDPATH", "FMT", "PATHONLY", "PATMATCH",
  "STRLEN", "SUBSTR", "TACKON", "SET", "SYMBOLSET", "SYMBOLVAL",
  "OPENWBOBJECT", "SHOWWBOBJECT", "CLOSEWBOBJECT", "ALL", "APPEND",
  "ASSIGNS", "BACK", "CHOICES", "COMMAND", "COMPRESSION", "CONFIRM",
  "DEFAULT", "DELOPTS", "DEST", "DISK", "FILES", "FONTS", "GETDEFAULTTOOL",
  "GETPOSITION", "GETSTACK", "GETTOOLTYPE", "HELP", "INFOS", "INCLUDE",
  "NEWNAME", "NEWPATH", "NOGAUGE", "NOPOSITION", "NOREQ", "PATTERN",
  "PROMPT", "QUIET", "RANGE", "SAFE", "SETDEFAULTTOOL", "SETPOSITION",
  "SETSTACK", "SETTOOLTYPE", "SOURCE", "SWAPCOLORS", "OPTIONAL",
  "RESIDENT", "OVERRIDE", "'('", "')'", "'+'", "'/'", "'*'", "'-'", "'='",
  "'>'", "'<'", "$accept", "start", "s", "p", "pp", "ps", "pps", "vp",
  "vps", "opts", "xpb", "xpbs", "np", "sps", "par", "cv", "cvv", "opt",
  "ivp", "add", "div", "mul", "sub", "eq", "gt", "gte", "lt", "lte", "neq",
  "if", "select", "until", "while", "trace", "retrace", "execute", "rexx",
  "run", "abort", "exit", "onerror", "reboot", "trap", "copyfiles",
  "copylib", "delete", "exists", "fileonly", "foreach", "makeassign",
  "makedir", "protect", "startup", "textfile", "tooltype", "transcript",
  "rename", "complete", "debug", "message", "user", "welcome", "working",
  "and", "bitand", "bitnot", "bitor", "bitxor", "not", "in", "or",
  "shiftleft", "shiftright", "xor", "closemedia", "effect", "setmedia",
  "showmedia", "database", "earlier", "getassign", "getdevice",
  "getdiskspace", "getenv", "getsize", "getsum", "getversion", "iconinfo",
  "querydisplay", "dcl", "cus", "askbool", "askchoice", "askdir",
  "askdisk", "askfile", "asknumber", "askoptions", "askstring", "cat",
  "expandpath", "fmt", "pathonly", "patmatch", "strlen", "substr",
  "tackon", "set", "symbolset", "symbolval", "openwbobject",
  "showwbobject", "closewbobject", "all", "append", "assigns", "back",
  "choices", "command", "compression", "confirm", "default", "delopts",
  "dest", "disk", "files", "fonts", "getdefaulttool", "getposition",
  "getstack", "gettooltype", "help", "infos", "include", "newname",
  "newpath", "nogauge", "noposition", "noreq", "pattern", "prompt",
  "quiet", "range", "safe", "setdefaulttool", "setposition", "setstack",
  "settooltype", "source", "swapcolors", "optional", "resident",
  "override", "dynopt", YY_NULLPTR
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
     385,   386,   387,   388,   389,   390,   391,   392,   393,    40,
      41,    43,    47,    42,    45,    61,    62,    60
};
# endif

#define YYPACT_NINF -385

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-385)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -109,  1164,    35,  -385,  -385,  -109,  -109,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,     4,    11,    90,    90,    90,    90,
      90,    90,    90,   -92,   -69,   244,   244,   244,    90,    49,
    -109,    90,   -64,   -54,   -54,   244,    90,    90,    90,    90,
     244,    90,   244,   -54,   -54,    90,    90,    90,    58,   244,
      90,    84,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,   106,   -54,    90,    96,
    -119,   -54,  -106,   -54,  -101,   -99,   -54,   -95,    90,    90,
      90,    90,    90,    90,    90,   132,    90,    90,   244,    90,
      90,   -33,    90,     2,  -109,    90,    90,     9,   115,    90,
      90,    90,    14,    31,    45,    90,    90,    90,    90,   124,
      47,    90,    90,    50,    59,    78,    82,    90,    90,    87,
      90,    91,    90,    90,    90,    90,    90,    93,    90,   113,
      90,    90,    90,    90,    90,    90,    90,    90,   116,   -80,
     -72,  -385,  -109,  -109,  -109,  -109,  -385,  -385,  -385,  -385,
    -385,  -385,  1744,  -385,  -385,   232,  -385,  -385,  -385,   254,
      90,   129,   141,   146,   268,   163,   165,   410,  -109,  -109,
    -385,  -385,  1309,   284,   244,   290,   244,   370,   244,   397,
    1454,  -385,   430,   436,   -70,  -109,  -385,  2112,   -65,   -60,
     -58,   244,   -56,   167,  -109,   442,   -38,   -34,   244,   448,
     -24,   -54,   456,   -15,    -6,   462,    -2,   174,  -385,   468,
     498,   244,   178,  -385,   559,   611,   758,   180,   186,   193,
     198,   209,    90,   766,   213,   220,   229,   239,    90,   870,
      90,   907,   242,   245,   917,   251,   255,   952,   271,   291,
     317,   337,  -385,     6,     8,   344,    19,  -385,    13,    22,
    -385,    41,    53,  -385,    55,  -385,    62,    64,  -385,    66,
    1012,   350,   352,   356,   358,  1018,   359,    90,    26,  -385,
    1559,   368,    69,   244,   371,   372,  -385,  1565,  -385,    81,
    1571,  1579,  -385,  -385,   375,   376,  1709,   377,  -385,  -385,
    -385,   378,   380,   382,   383,  -385,  1717,  -385,   384,   385,
    -385,  -385,  -385,  -385,   386,  1726,  -385,   387,  -385,   389,
     390,   391,  1855,   392,   393,  -385,  1864,  -385,   394,  1870,
     398,  1985,   399,   400,   401,   402,  -385,  -385,  -385,    90,
     116,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  1164,  -385,
    -385,    86,   410,  -385,  -385,  1889,  -385,  1993,   102,   104,
     126,  -385,   128,  2008,   -54,  -385,   138,  2014,  -385,   160,
    2034,  -385,  -385,   403,  -385,  2040,  -385,   162,    90,  -385,
    -385,  -385,   171,   183,   -96,  -385,   404,   406,  -385,   189,
    1599,  -385,   407,   419,  -385,   411,  -385,   192,   196,  -385,
     203,  -385,   208,   219,  -385,   223,  -385,  -385,  -385,  -385,
     226,  -385,  -385,  -385,   228,  2046,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  2052,  -385,  -385,  -385,  -385,
    -385,   412,  -385,   413,    90,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,     3,  -385,   414,  -385,
    -385,  -385,  -385,   415,    29,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,   416,
    -385,  -385,    90,  -385,  -385,    90,  -385,  -385,   248,   250,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  2058,  2064,  -385,   259,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,   270,  -385,  -385,   281,
    -385,  -385,   286,  -385,  -385,  -385,   -54,  -385,  -385,   288,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,   340,  -385,  -385,
    -385,  -385,   343,  -385,  -385,  -385,   347,  -385,  -385,  -385,
    2070,  -385,  -385,  -385,  -385,   418,  -385,  -385,  -385,  -385,
    -385,   355,  -385,   428,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,    16,     3,     0,    19,    11,    79,
      80,    81,    82,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   113,   112,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   150,
     149,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    58,    57,    59,    60,    61,    62,    63,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      64,    78,    65,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,     1,    13,    14,    15,    18,    30,    29,    31,    26,
      27,    28,     0,   292,     8,     0,     4,     5,   309,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     189,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   208,     0,     0,     0,     0,   210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,     0,
       0,     0,     0,   253,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   282,     0,     0,     0,     0,   293,     0,     0,
     296,     0,     0,   299,     0,   301,     0,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,   325,     0,   327,     0,
       0,     0,   331,   333,     0,     0,     0,     0,   337,   338,
     339,     0,     0,     0,     0,   345,     0,   346,     0,     0,
     349,   350,   351,   352,     0,     0,   355,     0,   357,     0,
       0,     0,     0,     0,     0,   364,     0,   366,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    17,    20,     0,
       0,   291,     7,   308,     6,   179,   181,   182,     0,   185,
      23,     0,    36,   184,   183,     0,    24,     0,     0,     0,
       0,   194,     0,     0,    18,   198,     0,     0,   202,     0,
       0,   203,   207,     0,   206,     0,   209,     0,     0,   212,
     213,   217,     0,     0,     0,   218,     0,     0,   221,     0,
       0,   226,     0,     0,   224,     0,   230,     0,     0,   234,
       0,   232,     0,     0,   238,     0,   239,   240,   241,   243,
       0,   244,   245,   250,     0,     0,   251,   252,   254,   255,
     256,   257,   258,   259,   260,     0,   262,   263,   264,   265,
     266,     0,   268,     0,     0,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,     0,   283,     0,   285,
     286,    35,   290,     0,     0,   294,   295,   297,   298,   300,
     302,   303,   305,   306,   307,   310,   311,   312,   313,     0,
     315,    33,     0,   316,   317,     0,   318,   319,     0,     0,
     323,   324,   326,   328,   329,   330,   332,   334,   335,   336,
     340,   341,   342,   343,   344,   347,   348,   353,   354,   356,
     358,   359,   360,   362,   361,   363,   365,   367,   173,   174,
     175,   176,   177,   178,   180,     0,     0,   368,     0,    37,
     186,    25,   187,   188,   191,   192,     0,   195,   196,     0,
     199,   200,     0,   204,   205,   211,     0,   214,   215,     0,
     219,   220,   222,   225,   223,   227,   228,     0,   233,   231,
     235,   236,     0,   242,   247,   248,     0,   261,   267,   269,
       0,   284,   289,    34,   288,     0,   314,    32,     9,   320,
     321,     0,    21,     0,   369,   193,   197,   201,   216,   229,
     237,   249,   270,   287,   322,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -385,  -385,  -384,   483,   806,  -132,  -385,    72,    36,     0,
    -304,  -385,   -87,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,   240,  -385,
    -385,  -155,  -385,  -160,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,   188,  -385,  -385
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   294,   301,   295,   410,   296,   282,   494,
     482,   487,   297,   408,   584,   305,   306,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
       6,   280,   583,   486,   323,   283,   285,   286,   287,   288,
     289,   290,   291,   299,   286,   287,   288,   289,   290,   291,
     327,   387,   581,   313,   315,   317,   319,   322,   256,   602,
       1,   259,   693,   327,   390,   281,     5,   279,   327,   393,
     327,   395,   284,   345,   327,   398,   349,   350,   310,   354,
     355,   356,   286,   287,   288,   289,   290,   291,   363,     1,
     467,   286,   287,   288,   289,   290,   291,     1,   468,     1,
     506,   311,     4,   278,   327,   509,   326,     4,     4,   327,
     510,   327,   511,   514,   515,   327,   400,   286,   287,   288,
     289,   290,   291,   286,   287,   288,   289,   290,   291,   386,
     417,   523,   524,   420,   421,   327,   526,   416,   426,   286,
     287,   288,   289,   290,   291,   327,   531,   436,   286,   287,
     288,   289,   290,   291,   327,   536,   445,   286,   287,   288,
     289,   290,   291,   327,   537,   407,   456,   327,   539,   459,
     269,   461,   418,   292,   293,   576,   577,   327,   579,   422,
     292,   298,   327,   585,   428,   314,   316,   318,     1,   582,
       6,   327,   586,   328,   329,   331,   603,   503,     1,   694,
     338,   429,   342,   343,   344,   522,   525,   517,   649,   351,
     327,   587,   493,   651,   497,   430,   500,   437,   320,   321,
     440,   505,   327,   588,   327,   589,   324,   292,   348,   441,
     695,   327,   590,   327,   591,   327,   592,   384,   327,   607,
     388,   389,   391,   392,   394,   396,   397,   399,   442,   545,
       1,   613,   443,   292,   353,   327,   647,   446,   413,   292,
     555,   448,     4,   455,     6,   286,   287,   288,   289,   290,
     291,     1,   652,     1,   653,   292,   382,   286,   287,   288,
     289,   290,   291,   457,   292,   423,   466,   286,   287,   288,
     289,   290,   291,   292,   435,   327,   468,   327,   654,   475,
     419,   286,   287,   288,   289,   290,   291,   327,   657,   283,
     285,   476,   283,   285,   283,   285,   477,   286,   287,   288,
     289,   290,   291,   286,   287,   288,   289,   290,   291,   327,
     660,     1,   665,   483,   481,   484,     4,   518,     6,     6,
     327,   667,   490,   492,   541,   496,   284,   499,   546,   284,
     550,   284,   327,   668,   283,     6,   551,   490,     1,   672,
     512,   327,   675,   552,     6,   327,   676,   527,   553,   530,
     532,   533,   327,   678,   488,   489,   540,   327,   679,   554,
     544,     4,     4,   557,     4,     4,     4,     4,   327,   680,
     558,   507,   327,   681,   470,   327,   683,   327,   684,   559,
     519,   292,   471,   286,   287,   288,   289,   290,   291,   560,
       4,     4,   566,   312,   470,   567,     6,   327,   699,   327,
     700,   569,   470,   292,   473,   570,     4,     4,   327,   704,
     286,   287,   288,   289,   290,   291,     4,   478,   479,   327,
     705,   572,   608,   286,   287,   288,   289,   290,   291,   283,
     327,   706,     5,   312,   491,   327,   707,   327,   708,   312,
     495,   573,   690,   286,   287,   288,   289,   290,   291,   286,
     287,   288,   289,   290,   291,   286,   287,   288,   289,   290,
     291,   286,   287,   288,   289,   290,   291,   574,     4,   286,
     287,   288,   289,   290,   291,   286,   287,   288,   289,   290,
     291,   286,   287,   288,   289,   290,   291,   575,   280,   327,
     709,   648,   327,   710,   580,     6,   327,   711,   283,   283,
     594,     4,   595,   656,   327,   714,   596,   659,   597,   600,
     662,   286,   287,   288,   289,   290,   291,   283,   606,   312,
     498,   610,   611,   669,   646,   616,   617,   619,   620,   283,
     621,   646,   622,   623,   625,   626,   627,   629,   677,   630,
     631,   632,   634,   635,   637,   682,   292,   501,   639,   641,
     642,   643,   644,   663,   670,   686,   671,   673,   261,   485,
     278,   674,   688,   689,   691,   692,   696,   278,   713,   703,
       4,     4,   286,   287,   288,   289,   290,   291,   715,   320,
     502,   578,   516,     0,     0,   292,   504,     0,     0,     4,
       0,   520,   521,     0,     6,     0,     0,   312,   529,     0,
       0,     4,   470,     0,     0,   312,   534,     0,     0,     0,
       0,   292,   538,     0,     0,     0,     0,   292,   542,   701,
       0,     0,     0,     0,   286,   287,   288,   289,   290,   291,
       5,     0,     0,     0,     0,     0,     0,     0,     0,   300,
     300,   300,   304,   307,   308,   309,     0,   312,   543,     0,
       0,     0,     0,     0,   325,     0,   283,     0,   330,   332,
     333,   300,   335,   337,   339,   341,     4,     0,     0,   300,
     347,     0,     0,   352,     0,     0,   481,   300,   358,   300,
     300,   361,   362,     0,   300,   300,   300,   367,   300,   300,
     300,   371,   300,   374,   376,   377,   379,   380,   381,   383,
       0,   300,     0,     0,     0,     0,     0,     0,   292,   547,
       0,     0,   401,   402,   300,   404,   300,   300,     0,   300,
     411,   412,   414,   415,     0,     0,     0,     0,     4,     0,
       0,   424,   425,     0,   427,     0,     0,     0,   431,   300,
     433,   300,     0,     0,   438,   439,     0,     0,     0,     0,
     444,     0,     0,   300,     0,   449,   300,   451,   452,   454,
     292,   548,     0,   458,     0,   300,     0,   300,   300,   300,
     300,   286,   287,   288,   289,   290,   291,     0,     0,   286,
     287,   288,   289,   290,   291,     0,     0,     0,   472,     0,
       0,     0,   472,   474,     0,     0,     0,   480,     0,     0,
     480,     0,     0,     0,     0,     0,   472,     0,   472,     0,
     472,     0,   472,     0,     0,   472,     0,     0,     0,     0,
       0,     0,     0,     0,   513,     0,     0,     0,   474,     0,
       0,   528,   474,     0,     0,   535,     0,     0,   472,     0,
       0,     0,   472,   472,     0,     0,     0,   472,   472,   472,
       0,     0,     0,     0,     0,     0,   472,     0,     0,     0,
       0,   300,   563,   300,   474,     0,     0,   474,     0,     0,
     474,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,   472,     0,     0,     0,     0,   599,     0,
     601,     0,     0,   605,     0,     0,   609,   292,   549,     0,
     472,     0,     0,   472,   472,   292,   556,     0,     0,   472,
     286,   287,   288,   289,   290,   291,     0,     0,     0,   472,
     286,   287,   288,   289,   290,   291,     0,     0,   472,     0,
       0,     0,     0,     0,     0,   474,     0,     0,     0,   472,
       0,     0,   472,     0,   472,     0,     0,     0,     0,     0,
       0,     0,   645,   302,   303,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,   480,     0,     0,     0,     0,
     480,     0,     0,     0,   334,   336,   472,   340,     0,     0,
     472,     0,   346,   472,     0,     0,     0,     0,   472,     0,
     357,   666,   359,   360,     0,     0,     0,   364,   365,   366,
       0,   368,   369,   370,   372,   373,   375,     0,   378,   292,
     562,     0,     0,     0,   385,   286,   287,   288,   289,   290,
     291,   286,   287,   288,   289,   290,   291,   403,   472,   405,
     406,     0,   409,     0,     0,     0,     0,     0,   472,     0,
       0,     0,     0,     0,     0,     0,   292,   565,     0,     0,
       0,     0,   432,     0,   434,     0,   292,   568,     0,     0,
       0,     0,     0,     0,     0,     0,   447,     0,     0,   450,
       0,   453,     0,     0,     0,     0,     0,     0,   460,     0,
     462,   463,   464,   465,     0,   697,     0,     0,   698,     0,
       0,   292,   571,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   292,   593,     0,     0,     0,     0,   292,   598,     0,
       0,     0,     0,     0,     0,     0,     0,   144,   145,     0,
       0,     0,     0,   472,   561,   146,   564,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,     1,     0,   271,   272,   273,   274,   275,
     276,   277,   144,   145,     0,     0,     0,     0,     0,     0,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   312,     0,
     271,   272,   273,   274,   275,   276,   277,   144,   145,     0,
       0,     0,     0,     0,     0,   146,     0,   147,   148,   469,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   286,   287,   288,   289,   290,   291,   286,   287,
     288,   289,   290,   291,   286,   287,   288,   289,   290,   291,
       0,   259,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   292,     0,   271,   272,   273,   274,   275,
     276,   277,   144,   145,     0,     0,     0,     0,     0,     0,
     146,     0,   147,   148,   469,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   292,   604,
       0,     0,     0,     0,   292,   612,     0,     0,     0,     0,
     292,   614,   286,   287,   288,   289,   290,   291,   292,   615,
     286,   287,   288,   289,   290,   291,     0,     0,   261,   286,
     287,   288,   289,   290,   291,     0,     0,     0,   292,     0,
     271,   272,   273,   274,   275,   276,   277,   144,   145,     0,
       0,     0,     0,     0,     0,   146,     0,   147,   148,   469,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,     0,     0,     0,     0,     0,   292,   618,
       0,     0,     0,     0,     0,     0,   292,   624,   286,   287,
     288,   289,   290,   291,     0,   292,   628,   286,   287,   288,
     289,   290,   291,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,   292,     0,   271,   272,   273,   274,   275,
     276,   277,   144,   145,     0,     0,     0,     0,     0,     0,
     146,     0,   147,   148,   469,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   286,   287,
     288,   289,   290,   291,   292,   633,   286,   287,   288,   289,
     290,   291,     0,   292,   636,     0,     0,     0,     0,   292,
     638,   286,   287,   288,   289,   290,   291,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,     1,     0,
     271,   272,   273,   274,   275,   276,   277,   286,   287,   288,
     289,   290,   291,   286,   287,   288,   289,   290,   291,   286,
     287,   288,   289,   290,   291,   286,   287,   288,   289,   290,
     291,   286,   287,   288,   289,   290,   291,   286,   287,   288,
     289,   290,   291,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   292,   640,     0,   508,     0,     0,
       0,     0,   485,   650,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   312,   655,     0,
       0,     0,     0,   312,   658,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   312,   661,     0,     0,     0,     0,   292,
     664,     0,     0,     0,     0,   312,   685,     0,     0,     0,
       0,   292,   687,     0,     0,     0,     0,   485,   479,     0,
       0,     0,     0,     1,   702,     0,     0,     0,     0,   292,
     712,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   327
};

static const yytype_int16 yycheck[] =
{
       0,     1,   386,   307,   159,     5,     6,     3,     4,     5,
       6,     7,     8,   145,     3,     4,     5,     6,     7,     8,
     139,   140,     3,   155,   156,   157,   158,   159,   124,     3,
     139,   127,     3,   139,   140,     0,     0,     1,   139,   140,
     139,   140,     6,   175,   139,   140,   178,   179,   140,   181,
     182,   183,     3,     4,     5,     6,     7,     8,   190,   139,
     140,     3,     4,     5,     6,     7,     8,   139,   140,   139,
     140,   140,     0,     1,   139,   140,   140,     5,     6,   139,
     140,   139,   140,   139,   140,   139,   218,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,     3,
     232,   139,   140,   235,   236,   139,   140,   140,   240,     3,
       4,     5,     6,     7,     8,   139,   140,   249,     3,     4,
       5,     6,     7,     8,   139,   140,   258,     3,     4,     5,
       6,     7,     8,   139,   140,     3,   268,   139,   140,   271,
     137,   273,   140,   139,   140,   139,   140,   139,   140,   140,
     139,   140,   139,   140,   140,   155,   156,   157,   139,   140,
     160,   139,   140,   163,   164,   165,   140,   322,   139,   140,
     170,   140,   172,   173,   174,   335,   336,   332,   482,   179,
     139,   140,   314,   487,   316,   140,   318,   140,   139,   140,
     140,   323,   139,   140,   139,   140,   160,   139,   140,   140,
     584,   139,   140,   139,   140,   139,   140,   207,   139,   140,
     210,   211,   212,   213,   214,   215,   216,   217,   140,   351,
     139,   140,   140,   139,   140,   139,   140,   140,   228,   139,
     362,   140,   160,   140,   234,     3,     4,     5,     6,     7,
       8,   139,   140,   139,   140,   139,   140,     3,     4,     5,
       6,     7,     8,   140,   139,   140,   140,     3,     4,     5,
       6,     7,     8,   139,   140,   139,   140,   139,   140,   140,
     234,     3,     4,     5,     6,     7,     8,   139,   140,   279,
     280,   140,   282,   283,   284,   285,   140,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,   139,
     140,   139,   140,   140,   304,   140,   234,   140,   308,   309,
     139,   140,   312,   313,   140,   315,   280,   317,   140,   283,
     140,   285,   139,   140,   324,   325,   140,   327,   139,   140,
     330,   139,   140,   140,   334,   139,   140,   337,   140,   339,
     340,   341,   139,   140,   308,   309,   346,   139,   140,   140,
     350,   279,   280,   140,   282,   283,   284,   285,   139,   140,
     140,   325,   139,   140,   292,   139,   140,   139,   140,   140,
     334,   139,   140,     3,     4,     5,     6,     7,     8,   140,
     308,   309,   140,   139,   312,   140,   386,   139,   140,   139,
     140,   140,   320,   139,   140,   140,   324,   325,   139,   140,
       3,     4,     5,     6,     7,     8,   334,   139,   140,   139,
     140,   140,   412,     3,     4,     5,     6,     7,     8,   419,
     139,   140,   386,   139,   140,   139,   140,   139,   140,   139,
     140,   140,   564,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,   140,   386,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,   140,   478,   139,
     140,   481,   139,   140,   140,   485,   139,   140,   488,   489,
     140,   419,   140,   493,   139,   140,   140,   497,   140,   140,
     500,     3,     4,     5,     6,     7,     8,   507,   140,   139,
     140,   140,   140,   513,   478,   140,   140,   140,   140,   519,
     140,   485,   140,   140,   140,   140,   140,   140,   528,   140,
     140,   140,   140,   140,   140,   535,   139,   140,   140,   140,
     140,   140,   140,   140,   140,   545,   140,   140,   129,   139,
     478,   140,   140,   140,   140,   140,   140,   485,   140,   646,
     488,   489,     3,     4,     5,     6,     7,     8,   140,   139,
     140,   383,   332,    -1,    -1,   139,   140,    -1,    -1,   507,
      -1,   139,   140,    -1,   584,    -1,    -1,   139,   140,    -1,
      -1,   519,   520,    -1,    -1,   139,   140,    -1,    -1,    -1,
      -1,   139,   140,    -1,    -1,    -1,    -1,   139,   140,   609,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
     584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,    -1,   139,   140,    -1,
      -1,    -1,    -1,    -1,   161,    -1,   646,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,   584,    -1,    -1,   176,
     177,    -1,    -1,   180,    -1,    -1,   666,   184,   185,   186,
     187,   188,   189,    -1,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
      -1,    -1,   219,   220,   221,   222,   223,   224,    -1,   226,
     227,   228,   229,   230,    -1,    -1,    -1,    -1,   646,    -1,
      -1,   238,   239,    -1,   241,    -1,    -1,    -1,   245,   246,
     247,   248,    -1,    -1,   251,   252,    -1,    -1,    -1,    -1,
     257,    -1,    -1,   260,    -1,   262,   263,   264,   265,   266,
     139,   140,    -1,   270,    -1,   272,    -1,   274,   275,   276,
     277,     3,     4,     5,     6,     7,     8,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,   295,    -1,
      -1,    -1,   299,   300,    -1,    -1,    -1,   304,    -1,    -1,
     307,    -1,    -1,    -1,    -1,    -1,   313,    -1,   315,    -1,
     317,    -1,   319,    -1,    -1,   322,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   331,    -1,    -1,    -1,   335,    -1,
      -1,   338,   339,    -1,    -1,   342,    -1,    -1,   345,    -1,
      -1,    -1,   349,   350,    -1,    -1,    -1,   354,   355,   356,
      -1,    -1,    -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,
      -1,   368,   369,   370,   371,    -1,    -1,   374,    -1,    -1,
     377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,   400,    -1,    -1,    -1,    -1,   405,    -1,
     407,    -1,    -1,   410,    -1,    -1,   413,   139,   140,    -1,
     417,    -1,    -1,   420,   421,   139,   140,    -1,    -1,   426,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,   436,
       3,     4,     5,     6,     7,     8,    -1,    -1,   445,    -1,
      -1,    -1,    -1,    -1,    -1,   452,    -1,    -1,    -1,   456,
      -1,    -1,   459,    -1,   461,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   469,   147,   148,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,   482,    -1,    -1,    -1,    -1,
     487,    -1,    -1,    -1,   168,   169,   493,   171,    -1,    -1,
     497,    -1,   176,   500,    -1,    -1,    -1,    -1,   505,    -1,
     184,   508,   186,   187,    -1,    -1,    -1,   191,   192,   193,
      -1,   195,   196,   197,   198,   199,   200,    -1,   202,   139,
     140,    -1,    -1,    -1,   208,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,   221,   545,   223,
     224,    -1,   226,    -1,    -1,    -1,    -1,    -1,   555,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,    -1,
      -1,    -1,   246,    -1,   248,    -1,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,   263,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,   272,    -1,
     274,   275,   276,   277,    -1,   602,    -1,    -1,   605,    -1,
      -1,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   645,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,    -1,    -1,    -1,    -1,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,   690,   368,    11,   370,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
     146,   147,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,   146,   147,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
      -1,   127,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,   139,    -1,   141,   142,   143,   144,   145,
     146,   147,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   139,   140,
      -1,    -1,    -1,    -1,   139,   140,    -1,    -1,    -1,    -1,
     139,   140,     3,     4,     5,     6,     7,     8,   139,   140,
       3,     4,     5,     6,     7,     8,    -1,    -1,   129,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,   139,    -1,
     141,   142,   143,   144,   145,   146,   147,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,    -1,    -1,    -1,    -1,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   140,     3,     4,
       5,     6,     7,     8,    -1,   139,   140,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,   139,    -1,   141,   142,   143,   144,   145,
     146,   147,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     3,     4,
       5,     6,     7,     8,   139,   140,     3,     4,     5,     6,
       7,     8,    -1,   139,   140,    -1,    -1,    -1,    -1,   139,
     140,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,   139,    -1,
     141,   142,   143,   144,   145,   146,   147,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,    -1,    15,    -1,    -1,
      -1,    -1,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,
      -1,    -1,    -1,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,    -1,    -1,    -1,    -1,   139,
     140,    -1,    -1,    -1,    -1,   139,   140,    -1,    -1,    -1,
      -1,   139,   140,    -1,    -1,    -1,    -1,   139,   140,    -1,
      -1,    -1,    -1,   139,   140,    -1,    -1,    -1,    -1,   139,
     140,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   139,   149,   150,   155,   156,   157,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,     3,     4,    11,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   141,   142,   143,   144,   145,   146,   147,   155,   156,
     157,     0,   156,   157,   156,   157,     3,     4,     5,     6,
       7,     8,   139,   140,   151,   153,   155,   160,   140,   153,
     151,   152,   152,   152,   151,   163,   164,   151,   151,   151,
     140,   140,   139,   153,   157,   153,   157,   153,   157,   153,
     139,   140,   153,   289,   156,   151,   140,   139,   157,   157,
     151,   157,   151,   151,   152,   151,   152,   151,   157,   151,
     152,   151,   157,   157,   157,   153,   152,   151,   140,   153,
     153,   157,   151,   140,   153,   153,   153,   152,   151,   152,
     152,   151,   151,   153,   152,   152,   152,   151,   152,   152,
     152,   151,   152,   152,   151,   152,   151,   151,   152,   151,
     151,   151,   140,   151,   157,   152,     3,   140,   157,   157,
     140,   157,   157,   140,   157,   140,   157,   157,   140,   157,
     153,   151,   151,   152,   151,   152,   152,     3,   161,   152,
     154,   151,   151,   157,   151,   151,   140,   153,   140,   156,
     153,   153,   140,   140,   151,   151,   153,   151,   140,   140,
     140,   151,   152,   151,   152,   140,   153,   140,   151,   151,
     140,   140,   140,   140,   151,   153,   140,   152,   140,   151,
     152,   151,   151,   152,   151,   140,   153,   140,   151,   153,
     152,   153,   152,   152,   152,   152,   140,   140,   140,    15,
     155,   140,   151,   140,   151,   140,   140,   140,   139,   140,
     151,   157,   158,   140,   140,   139,   158,   159,   156,   156,
     157,   140,   157,   153,   157,   140,   157,   153,   140,   157,
     153,   140,   140,   289,   140,   153,   140,   156,    15,   140,
     140,   140,   157,   151,   139,   140,   286,   289,   140,   156,
     139,   140,   291,   139,   140,   291,   140,   157,   151,   140,
     157,   140,   157,   157,   140,   151,   140,   140,   140,   140,
     157,   140,   140,   140,   157,   153,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   153,   140,   140,   140,   140,
     140,   152,   140,   151,   152,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   139,   140,   299,   140,
     140,     3,   140,   150,   162,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   151,
     140,   151,     3,   140,   140,   151,   140,   140,   157,   151,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   151,   156,   140,   157,   158,
     140,   158,   140,   140,   140,   140,   157,   140,   140,   157,
     140,   140,   157,   140,   140,   140,   151,   140,   140,   157,
     140,   140,   140,   140,   140,   140,   140,   157,   140,   140,
     140,   140,   157,   140,   140,   140,   157,   140,   140,   140,
     153,   140,   140,     3,   140,   150,   140,   151,   151,   140,
     140,   157,   140,   160,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   148,   149,   150,   151,   151,   152,   153,   153,   154,
     154,   155,   155,   156,   156,   156,   156,   156,   157,   157,
     157,   158,   158,   158,   159,   159,   160,   160,   160,   160,
     160,   160,   161,   161,   162,   162,   163,   164,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   177,   177,   178,   179,   180,   181,
     182,   183,   183,   183,   183,   184,   184,   184,   184,   185,
     185,   185,   185,   186,   187,   187,   187,   187,   187,   188,
     189,   190,   191,   192,   193,   193,   193,   193,   194,   194,
     194,   195,   196,   197,   197,   197,   197,   198,   198,   198,
     198,   199,   199,   199,   199,   200,   200,   200,   200,   201,
     202,   203,   204,   204,   205,   206,   206,   207,   207,   207,
     207,   208,   209,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   224,
     225,   226,   226,   227,   228,   228,   229,   230,   230,   231,
     232,   233,   234,   234,   234,   235,   236,   237,   237,   237,
     237,   238,   238,   239,   239,   240,   241,   241,   242,   243,
     243,   244,   244,   245,   246,   246,   247,   248,   249,   249,
     250,   251,   252,   253,   253,   254,   255,   256,   257,   258,
     258,   258,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   295,   296,   297,   298,   299,   300,   301,   301
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     1,     3,
       1,     1,     3,     2,     2,     2,     1,     3,     2,     1,
       3,     3,     4,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     3,     2,     2,     1,     2,     3,     1,     1,
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
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     5,     5,     3,
       3,     5,     5,     6,     4,     5,     5,     6,     4,     5,
       5,     6,     4,     4,     5,     5,     4,     4,     3,     4,
       3,     5,     4,     4,     5,     5,     6,     4,     4,     5,
       5,     4,     5,     5,     4,     5,     4,     5,     5,     6,
       4,     5,     4,     5,     4,     5,     5,     6,     4,     4,
       4,     4,     5,     4,     4,     4,     3,     5,     5,     6,
       4,     4,     4,     3,     4,     4,     4,     4,     4,     4,
       4,     5,     4,     4,     4,     4,     4,     5,     4,     5,
       6,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     4,     5,     4,     4,     6,     5,     5,
       4,     4,     3,     3,     4,     4,     3,     4,     4,     3,
       4,     3,     4,     4,     3,     4,     4,     4,     4,     3,
       4,     4,     4,     4,     5,     4,     4,     4,     4,     4,
       5,     5,     6,     4,     4,     3,     4,     3,     4,     4,
       4,     3,     4,     3,     4,     4,     4,     3,     3,     3,
       4,     4,     4,     4,     4,     3,     3,     4,     4,     3,
       3,     3,     3,     4,     4,     3,     4,     3,     4,     4,
       4,     4,     4,     4,     3,     4,     3,     4,     5,     6
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
#line 72 "../src/parser.y"
      { free(((*yyvaluep).s)); }
#line 1963 "parser.c"
        break;

    case 4: /* STR  */
#line 72 "../src/parser.y"
      { free(((*yyvaluep).s)); }
#line 1969 "parser.c"
        break;

    case 149: /* start  */
#line 70 "../src/parser.y"
      { run(((*yyvaluep).e));  }
#line 1975 "parser.c"
        break;

    case 150: /* s  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1981 "parser.c"
        break;

    case 151: /* p  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1987 "parser.c"
        break;

    case 152: /* pp  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1993 "parser.c"
        break;

    case 153: /* ps  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1999 "parser.c"
        break;

    case 154: /* pps  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2005 "parser.c"
        break;

    case 155: /* vp  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2011 "parser.c"
        break;

    case 156: /* vps  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2017 "parser.c"
        break;

    case 157: /* opts  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2023 "parser.c"
        break;

    case 158: /* xpb  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2029 "parser.c"
        break;

    case 159: /* xpbs  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2035 "parser.c"
        break;

    case 160: /* np  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2041 "parser.c"
        break;

    case 161: /* sps  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2047 "parser.c"
        break;

    case 162: /* par  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2053 "parser.c"
        break;

    case 163: /* cv  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2059 "parser.c"
        break;

    case 164: /* cvv  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2065 "parser.c"
        break;

    case 165: /* opt  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2071 "parser.c"
        break;

    case 166: /* ivp  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2077 "parser.c"
        break;

    case 167: /* add  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2083 "parser.c"
        break;

    case 168: /* div  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2089 "parser.c"
        break;

    case 169: /* mul  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2095 "parser.c"
        break;

    case 170: /* sub  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2101 "parser.c"
        break;

    case 171: /* eq  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2107 "parser.c"
        break;

    case 172: /* gt  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2113 "parser.c"
        break;

    case 173: /* gte  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2119 "parser.c"
        break;

    case 174: /* lt  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2125 "parser.c"
        break;

    case 175: /* lte  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2131 "parser.c"
        break;

    case 176: /* neq  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2137 "parser.c"
        break;

    case 177: /* if  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2143 "parser.c"
        break;

    case 178: /* select  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2149 "parser.c"
        break;

    case 179: /* until  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2155 "parser.c"
        break;

    case 180: /* while  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2161 "parser.c"
        break;

    case 181: /* trace  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2167 "parser.c"
        break;

    case 182: /* retrace  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2173 "parser.c"
        break;

    case 183: /* execute  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2179 "parser.c"
        break;

    case 184: /* rexx  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2185 "parser.c"
        break;

    case 185: /* run  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2191 "parser.c"
        break;

    case 186: /* abort  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2197 "parser.c"
        break;

    case 187: /* exit  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2203 "parser.c"
        break;

    case 188: /* onerror  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2209 "parser.c"
        break;

    case 189: /* reboot  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2215 "parser.c"
        break;

    case 190: /* trap  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2221 "parser.c"
        break;

    case 191: /* copyfiles  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2227 "parser.c"
        break;

    case 192: /* copylib  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2233 "parser.c"
        break;

    case 193: /* delete  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2239 "parser.c"
        break;

    case 194: /* exists  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2245 "parser.c"
        break;

    case 195: /* fileonly  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2251 "parser.c"
        break;

    case 196: /* foreach  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2257 "parser.c"
        break;

    case 197: /* makeassign  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2263 "parser.c"
        break;

    case 198: /* makedir  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2269 "parser.c"
        break;

    case 199: /* protect  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2275 "parser.c"
        break;

    case 200: /* startup  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2281 "parser.c"
        break;

    case 201: /* textfile  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2287 "parser.c"
        break;

    case 202: /* tooltype  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2293 "parser.c"
        break;

    case 203: /* transcript  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2299 "parser.c"
        break;

    case 204: /* rename  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2305 "parser.c"
        break;

    case 205: /* complete  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2311 "parser.c"
        break;

    case 206: /* debug  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2317 "parser.c"
        break;

    case 207: /* message  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2323 "parser.c"
        break;

    case 208: /* user  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2329 "parser.c"
        break;

    case 209: /* welcome  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2335 "parser.c"
        break;

    case 210: /* working  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2341 "parser.c"
        break;

    case 211: /* and  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2347 "parser.c"
        break;

    case 212: /* bitand  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2353 "parser.c"
        break;

    case 213: /* bitnot  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2359 "parser.c"
        break;

    case 214: /* bitor  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2365 "parser.c"
        break;

    case 215: /* bitxor  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2371 "parser.c"
        break;

    case 216: /* not  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2377 "parser.c"
        break;

    case 217: /* in  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2383 "parser.c"
        break;

    case 218: /* or  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2389 "parser.c"
        break;

    case 219: /* shiftleft  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2395 "parser.c"
        break;

    case 220: /* shiftright  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2401 "parser.c"
        break;

    case 221: /* xor  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2407 "parser.c"
        break;

    case 222: /* closemedia  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2413 "parser.c"
        break;

    case 223: /* effect  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2419 "parser.c"
        break;

    case 224: /* setmedia  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2425 "parser.c"
        break;

    case 225: /* showmedia  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2431 "parser.c"
        break;

    case 226: /* database  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2437 "parser.c"
        break;

    case 227: /* earlier  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2443 "parser.c"
        break;

    case 228: /* getassign  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2449 "parser.c"
        break;

    case 229: /* getdevice  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2455 "parser.c"
        break;

    case 230: /* getdiskspace  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2461 "parser.c"
        break;

    case 231: /* getenv  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2467 "parser.c"
        break;

    case 232: /* getsize  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2473 "parser.c"
        break;

    case 233: /* getsum  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2479 "parser.c"
        break;

    case 234: /* getversion  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2485 "parser.c"
        break;

    case 235: /* iconinfo  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2491 "parser.c"
        break;

    case 236: /* querydisplay  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2497 "parser.c"
        break;

    case 237: /* dcl  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2503 "parser.c"
        break;

    case 238: /* cus  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2509 "parser.c"
        break;

    case 239: /* askbool  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2515 "parser.c"
        break;

    case 240: /* askchoice  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2521 "parser.c"
        break;

    case 241: /* askdir  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2527 "parser.c"
        break;

    case 242: /* askdisk  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2533 "parser.c"
        break;

    case 243: /* askfile  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2539 "parser.c"
        break;

    case 244: /* asknumber  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2545 "parser.c"
        break;

    case 245: /* askoptions  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2551 "parser.c"
        break;

    case 246: /* askstring  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2557 "parser.c"
        break;

    case 247: /* cat  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2563 "parser.c"
        break;

    case 248: /* expandpath  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2569 "parser.c"
        break;

    case 249: /* fmt  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2575 "parser.c"
        break;

    case 250: /* pathonly  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2581 "parser.c"
        break;

    case 251: /* patmatch  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2587 "parser.c"
        break;

    case 252: /* strlen  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2593 "parser.c"
        break;

    case 253: /* substr  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2599 "parser.c"
        break;

    case 254: /* tackon  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2605 "parser.c"
        break;

    case 255: /* set  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2611 "parser.c"
        break;

    case 256: /* symbolset  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2617 "parser.c"
        break;

    case 257: /* symbolval  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2623 "parser.c"
        break;

    case 258: /* openwbobject  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2629 "parser.c"
        break;

    case 259: /* showwbobject  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2635 "parser.c"
        break;

    case 260: /* closewbobject  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2641 "parser.c"
        break;

    case 261: /* all  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2647 "parser.c"
        break;

    case 262: /* append  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2653 "parser.c"
        break;

    case 263: /* assigns  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2659 "parser.c"
        break;

    case 264: /* back  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2665 "parser.c"
        break;

    case 265: /* choices  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2671 "parser.c"
        break;

    case 266: /* command  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2677 "parser.c"
        break;

    case 267: /* compression  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2683 "parser.c"
        break;

    case 268: /* confirm  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2689 "parser.c"
        break;

    case 269: /* default  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2695 "parser.c"
        break;

    case 270: /* delopts  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2701 "parser.c"
        break;

    case 271: /* dest  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2707 "parser.c"
        break;

    case 272: /* disk  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2713 "parser.c"
        break;

    case 273: /* files  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2719 "parser.c"
        break;

    case 274: /* fonts  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2725 "parser.c"
        break;

    case 275: /* getdefaulttool  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2731 "parser.c"
        break;

    case 276: /* getposition  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2737 "parser.c"
        break;

    case 277: /* getstack  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2743 "parser.c"
        break;

    case 278: /* gettooltype  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2749 "parser.c"
        break;

    case 279: /* help  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2755 "parser.c"
        break;

    case 280: /* infos  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2761 "parser.c"
        break;

    case 281: /* include  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2767 "parser.c"
        break;

    case 282: /* newname  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2773 "parser.c"
        break;

    case 283: /* newpath  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2779 "parser.c"
        break;

    case 284: /* nogauge  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2785 "parser.c"
        break;

    case 285: /* noposition  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2791 "parser.c"
        break;

    case 286: /* noreq  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2797 "parser.c"
        break;

    case 287: /* pattern  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2803 "parser.c"
        break;

    case 288: /* prompt  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2809 "parser.c"
        break;

    case 289: /* quiet  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2815 "parser.c"
        break;

    case 290: /* range  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2821 "parser.c"
        break;

    case 291: /* safe  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2827 "parser.c"
        break;

    case 292: /* setdefaulttool  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2833 "parser.c"
        break;

    case 293: /* setposition  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2839 "parser.c"
        break;

    case 294: /* setstack  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2845 "parser.c"
        break;

    case 295: /* settooltype  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2851 "parser.c"
        break;

    case 296: /* source  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2857 "parser.c"
        break;

    case 297: /* swapcolors  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2863 "parser.c"
        break;

    case 298: /* optional  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2869 "parser.c"
        break;

    case 299: /* resident  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2875 "parser.c"
        break;

    case 300: /* override  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2881 "parser.c"
        break;

    case 301: /* dynopt  */
#line 74 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2887 "parser.c"
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
#line 86 "../src/parser.y"
    { (yyval.e) = init((yyvsp[0].e)); }
#line 3157 "parser.c"
    break;

  case 6:
#line 93 "../src/parser.y"
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3163 "parser.c"
    break;

  case 7:
#line 94 "../src/parser.y"
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3169 "parser.c"
    break;

  case 8:
#line 95 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3175 "parser.c"
    break;

  case 9:
#line 96 "../src/parser.y"
    { (yyval.e) = push(push((yyvsp[-2].e), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3181 "parser.c"
    break;

  case 12:
#line 99 "../src/parser.y"
    { (yyval.e) = (yyvsp[-1].e); }
#line 3187 "parser.c"
    break;

  case 13:
#line 100 "../src/parser.y"
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3193 "parser.c"
    break;

  case 14:
#line 101 "../src/parser.y"
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e));  }
#line 3199 "parser.c"
    break;

  case 15:
#line 102 "../src/parser.y"
    { (yyval.e) = merge((yyvsp[0].e), (yyvsp[-1].e));  }
#line 3205 "parser.c"
    break;

  case 16:
#line 103 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3211 "parser.c"
    break;

  case 17:
#line 104 "../src/parser.y"
    { (yyval.e) = (yyvsp[-1].e); }
#line 3217 "parser.c"
    break;

  case 18:
#line 105 "../src/parser.y"
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3223 "parser.c"
    break;

  case 19:
#line 106 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3229 "parser.c"
    break;

  case 20:
#line 107 "../src/parser.y"
    { (yyval.e) = (yyvsp[-1].e); }
#line 3235 "parser.c"
    break;

  case 21:
#line 108 "../src/parser.y"
    { (yyval.e) = (yyvsp[-1].e); }
#line 3241 "parser.c"
    break;

  case 22:
#line 109 "../src/parser.y"
    { (yyval.e) = push((yyvsp[-2].e), (yyvsp[-1].e)); }
#line 3247 "parser.c"
    break;

  case 23:
#line 110 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3253 "parser.c"
    break;

  case 24:
#line 111 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3259 "parser.c"
    break;

  case 25:
#line 112 "../src/parser.y"
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3265 "parser.c"
    break;

  case 26:
#line 113 "../src/parser.y"
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3271 "parser.c"
    break;

  case 27:
#line 114 "../src/parser.y"
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3277 "parser.c"
    break;

  case 28:
#line 115 "../src/parser.y"
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3283 "parser.c"
    break;

  case 29:
#line 116 "../src/parser.y"
    { (yyval.e) = new_string((yyvsp[0].s)); }
#line 3289 "parser.c"
    break;

  case 30:
#line 117 "../src/parser.y"
    { (yyval.e) = new_symref((yyvsp[0].s), LINE); }
#line 3295 "parser.c"
    break;

  case 31:
#line 118 "../src/parser.y"
    { (yyval.e) = NULL; YYFPRINTF(stderr, "Out of memory in line %d\n", LINE); YYABORT; }
#line 3301 "parser.c"
    break;

  case 32:
#line 119 "../src/parser.y"
    { (yyval.e) = push(push((yyvsp[-2].e), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)) ; }
#line 3307 "parser.c"
    break;

  case 33:
#line 120 "../src/parser.y"
    { (yyval.e) = push(push(new_contxt(), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)); }
#line 3313 "parser.c"
    break;

  case 34:
#line 121 "../src/parser.y"
    { (yyval.e) = push((yyvsp[-1].e), new_symbol((yyvsp[0].s))); }
#line 3319 "parser.c"
    break;

  case 35:
#line 122 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), new_symbol((yyvsp[0].s))); }
#line 3325 "parser.c"
    break;

  case 36:
#line 123 "../src/parser.y"
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3331 "parser.c"
    break;

  case 37:
#line 124 "../src/parser.y"
    { (yyval.e) = push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3337 "parser.c"
    break;

  case 173:
#line 269 "../src/parser.y"
    { (yyval.e) = new_native(strdup("+"), LINE, m_add, (yyvsp[-1].e), NUMBER); }
#line 3343 "parser.c"
    break;

  case 174:
#line 270 "../src/parser.y"
    { (yyval.e) = new_native(strdup("/"), LINE, m_div, (yyvsp[-1].e), NUMBER); }
#line 3349 "parser.c"
    break;

  case 175:
#line 271 "../src/parser.y"
    { (yyval.e) = new_native(strdup("*"), LINE, m_mul, (yyvsp[-1].e), NUMBER); }
#line 3355 "parser.c"
    break;

  case 176:
#line 272 "../src/parser.y"
    { (yyval.e) = new_native(strdup("-"), LINE, m_sub, (yyvsp[-1].e), NUMBER); }
#line 3361 "parser.c"
    break;

  case 177:
#line 276 "../src/parser.y"
    { (yyval.e) = new_native(strdup("="), LINE, m_eq, (yyvsp[-1].e), NUMBER); }
#line 3367 "parser.c"
    break;

  case 178:
#line 277 "../src/parser.y"
    { (yyval.e) = new_native(strdup(">"), LINE, m_gt, (yyvsp[-1].e), NUMBER); }
#line 3373 "parser.c"
    break;

  case 179:
#line 278 "../src/parser.y"
    { (yyval.e) = new_native(strdup(">="), LINE, m_gte, (yyvsp[-1].e), NUMBER); }
#line 3379 "parser.c"
    break;

  case 180:
#line 279 "../src/parser.y"
    { (yyval.e) = new_native(strdup("<"), LINE, m_lt, (yyvsp[-1].e), NUMBER); }
#line 3385 "parser.c"
    break;

  case 181:
#line 280 "../src/parser.y"
    { (yyval.e) = new_native(strdup("<="), LINE, m_lte, (yyvsp[-1].e), NUMBER); }
#line 3391 "parser.c"
    break;

  case 182:
#line 281 "../src/parser.y"
    { (yyval.e) = new_native(strdup("<>"), LINE, m_neq, (yyvsp[-1].e), NUMBER); }
#line 3397 "parser.c"
    break;

  case 183:
#line 285 "../src/parser.y"
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3403 "parser.c"
    break;

  case 184:
#line 286 "../src/parser.y"
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3409 "parser.c"
    break;

  case 185:
#line 287 "../src/parser.y"
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3415 "parser.c"
    break;

  case 186:
#line 288 "../src/parser.y"
    { (yyval.e) = new_native(strdup("select"), LINE, m_select, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3421 "parser.c"
    break;

  case 187:
#line 289 "../src/parser.y"
    { (yyval.e) = new_native(strdup("until"), LINE, m_until, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3427 "parser.c"
    break;

  case 188:
#line 290 "../src/parser.y"
    { (yyval.e) = new_native(strdup("while"), LINE, m_while, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3433 "parser.c"
    break;

  case 189:
#line 291 "../src/parser.y"
    { (yyval.e) = new_native(strdup("trace"), LINE, m_trace, NULL, NUMBER); }
#line 3439 "parser.c"
    break;

  case 190:
#line 292 "../src/parser.y"
    { (yyval.e) = new_native(strdup("retrace"), LINE, m_retrace, NULL, NUMBER); }
#line 3445 "parser.c"
    break;

  case 191:
#line 296 "../src/parser.y"
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3451 "parser.c"
    break;

  case 192:
#line 297 "../src/parser.y"
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3457 "parser.c"
    break;

  case 193:
#line 298 "../src/parser.y"
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3463 "parser.c"
    break;

  case 194:
#line 299 "../src/parser.y"
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, (yyvsp[-1].e), NUMBER); }
#line 3469 "parser.c"
    break;

  case 195:
#line 300 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3475 "parser.c"
    break;

  case 196:
#line 301 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3481 "parser.c"
    break;

  case 197:
#line 302 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3487 "parser.c"
    break;

  case 198:
#line 303 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, (yyvsp[-1].e), NUMBER); }
#line 3493 "parser.c"
    break;

  case 199:
#line 304 "../src/parser.y"
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3499 "parser.c"
    break;

  case 200:
#line 305 "../src/parser.y"
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3505 "parser.c"
    break;

  case 201:
#line 306 "../src/parser.y"
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3511 "parser.c"
    break;

  case 202:
#line 307 "../src/parser.y"
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, (yyvsp[-1].e), NUMBER); }
#line 3517 "parser.c"
    break;

  case 203:
#line 311 "../src/parser.y"
    { (yyval.e) = new_native(strdup("abort"), LINE, m_abort, (yyvsp[-1].e), NUMBER); }
#line 3523 "parser.c"
    break;

  case 204:
#line 312 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3529 "parser.c"
    break;

  case 205:
#line 313 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3535 "parser.c"
    break;

  case 206:
#line 314 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3541 "parser.c"
    break;

  case 207:
#line 315 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, (yyvsp[-1].e), NUMBER); }
#line 3547 "parser.c"
    break;

  case 208:
#line 316 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, NULL, NUMBER); }
#line 3553 "parser.c"
    break;

  case 209:
#line 317 "../src/parser.y"
    { (yyval.e) = new_native(strdup("onerror"), LINE, m_procedure, push(new_contxt(),
                                                        new_custom(strdup("@onerror"), LINE, NULL, (yyvsp[-1].e))), DANGLE); }
#line 3560 "parser.c"
    break;

  case 210:
#line 319 "../src/parser.y"
    { (yyval.e) = new_native(strdup("reboot"), LINE, m_reboot, NULL, NUMBER); }
#line 3566 "parser.c"
    break;

  case 211:
#line 320 "../src/parser.y"
    { (yyval.e) = new_native(strdup("trap"), LINE, m_trap, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3572 "parser.c"
    break;

  case 212:
#line 324 "../src/parser.y"
    { (yyval.e) = new_native(strdup("copyfiles"), LINE, m_copyfiles, (yyvsp[-1].e), NUMBER); }
#line 3578 "parser.c"
    break;

  case 213:
#line 325 "../src/parser.y"
    { (yyval.e) = new_native(strdup("copylib"), LINE, m_copylib, (yyvsp[-1].e), NUMBER); }
#line 3584 "parser.c"
    break;

  case 214:
#line 326 "../src/parser.y"
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3590 "parser.c"
    break;

  case 215:
#line 327 "../src/parser.y"
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3596 "parser.c"
    break;

  case 216:
#line 328 "../src/parser.y"
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3602 "parser.c"
    break;

  case 217:
#line 329 "../src/parser.y"
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3608 "parser.c"
    break;

  case 218:
#line 330 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3614 "parser.c"
    break;

  case 219:
#line 331 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3620 "parser.c"
    break;

  case 220:
#line 332 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3626 "parser.c"
    break;

  case 221:
#line 333 "../src/parser.y"
    { (yyval.e) = new_native(strdup("fileonly"), LINE, m_fileonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3632 "parser.c"
    break;

  case 222:
#line 334 "../src/parser.y"
    { (yyval.e) = new_native(strdup("foreach"), LINE, m_foreach, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3638 "parser.c"
    break;

  case 223:
#line 335 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3644 "parser.c"
    break;

  case 224:
#line 336 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, (yyvsp[-1].e), NUMBER); }
#line 3650 "parser.c"
    break;

  case 225:
#line 337 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3656 "parser.c"
    break;

  case 226:
#line 338 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3662 "parser.c"
    break;

  case 227:
#line 339 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3668 "parser.c"
    break;

  case 228:
#line 340 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3674 "parser.c"
    break;

  case 229:
#line 341 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3680 "parser.c"
    break;

  case 230:
#line 342 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3686 "parser.c"
    break;

  case 231:
#line 343 "../src/parser.y"
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3692 "parser.c"
    break;

  case 232:
#line 344 "../src/parser.y"
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, (yyvsp[-1].e), NUMBER); }
#line 3698 "parser.c"
    break;

  case 233:
#line 345 "../src/parser.y"
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3704 "parser.c"
    break;

  case 234:
#line 346 "../src/parser.y"
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3710 "parser.c"
    break;

  case 235:
#line 347 "../src/parser.y"
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3716 "parser.c"
    break;

  case 236:
#line 348 "../src/parser.y"
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3722 "parser.c"
    break;

  case 237:
#line 349 "../src/parser.y"
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3728 "parser.c"
    break;

  case 238:
#line 350 "../src/parser.y"
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), new_symref(strdup("@app-name"), LINE)), (yyvsp[-1].e)), NUMBER); }
#line 3734 "parser.c"
    break;

  case 239:
#line 351 "../src/parser.y"
    { (yyval.e) = new_native(strdup("textfile"), LINE, m_textfile, (yyvsp[-1].e), NUMBER); }
#line 3740 "parser.c"
    break;

  case 240:
#line 352 "../src/parser.y"
    { (yyval.e) = new_native(strdup("tooltype"), LINE, m_tooltype, (yyvsp[-1].e), NUMBER); }
#line 3746 "parser.c"
    break;

  case 241:
#line 353 "../src/parser.y"
    { (yyval.e) = new_native(strdup("transcript"), LINE, m_transcript, (yyvsp[-1].e), NUMBER); }
#line 3752 "parser.c"
    break;

  case 242:
#line 354 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3758 "parser.c"
    break;

  case 243:
#line 355 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, (yyvsp[-1].e), NUMBER); }
#line 3764 "parser.c"
    break;

  case 244:
#line 359 "../src/parser.y"
    { (yyval.e) = new_native(strdup("complete"), LINE, m_complete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3770 "parser.c"
    break;

  case 245:
#line 360 "../src/parser.y"
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, (yyvsp[-1].e), NUMBER); }
#line 3776 "parser.c"
    break;

  case 246:
#line 361 "../src/parser.y"
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, NULL, NUMBER); }
#line 3782 "parser.c"
    break;

  case 247:
#line 362 "../src/parser.y"
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, merge((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3788 "parser.c"
    break;

  case 248:
#line 363 "../src/parser.y"
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3794 "parser.c"
    break;

  case 249:
#line 364 "../src/parser.y"
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, push(merge((yyvsp[-3].e), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3800 "parser.c"
    break;

  case 250:
#line 365 "../src/parser.y"
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, (yyvsp[-1].e), NUMBER); }
#line 3806 "parser.c"
    break;

  case 251:
#line 366 "../src/parser.y"
    { (yyval.e) = new_native(strdup("user"), LINE, m_user, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3812 "parser.c"
    break;

  case 252:
#line 367 "../src/parser.y"
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, (yyvsp[-1].e), NUMBER); }
#line 3818 "parser.c"
    break;

  case 253:
#line 368 "../src/parser.y"
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, NULL, NUMBER); }
#line 3824 "parser.c"
    break;

  case 254:
#line 369 "../src/parser.y"
    { (yyval.e) = new_native(strdup("working"), LINE, m_working, (yyvsp[-1].e), NUMBER); }
#line 3830 "parser.c"
    break;

  case 255:
#line 373 "../src/parser.y"
    { (yyval.e) = new_native(strdup("AND"), LINE, m_and, (yyvsp[-1].e), NUMBER); }
#line 3836 "parser.c"
    break;

  case 256:
#line 374 "../src/parser.y"
    { (yyval.e) = new_native(strdup("BITAND"), LINE, m_bitand, (yyvsp[-1].e), NUMBER); }
#line 3842 "parser.c"
    break;

  case 257:
#line 375 "../src/parser.y"
    { (yyval.e) = new_native(strdup("BITNOT"), LINE, m_bitnot, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3848 "parser.c"
    break;

  case 258:
#line 376 "../src/parser.y"
    { (yyval.e) = new_native(strdup("BITOR"), LINE, m_bitor, (yyvsp[-1].e), NUMBER); }
#line 3854 "parser.c"
    break;

  case 259:
#line 377 "../src/parser.y"
    { (yyval.e) = new_native(strdup("BITXOR"), LINE, m_bitxor, (yyvsp[-1].e), NUMBER); }
#line 3860 "parser.c"
    break;

  case 260:
#line 378 "../src/parser.y"
    { (yyval.e) = new_native(strdup("NOT"), LINE, m_not, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3866 "parser.c"
    break;

  case 261:
#line 379 "../src/parser.y"
    { (yyval.e) = new_native(strdup("IN"), LINE, m_in, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3872 "parser.c"
    break;

  case 262:
#line 380 "../src/parser.y"
    { (yyval.e) = new_native(strdup("OR"), LINE, m_or, (yyvsp[-1].e), NUMBER); }
#line 3878 "parser.c"
    break;

  case 263:
#line 381 "../src/parser.y"
    { (yyval.e) = new_native(strdup("shiftleft"), LINE, m_shiftleft, (yyvsp[-1].e), NUMBER); }
#line 3884 "parser.c"
    break;

  case 264:
#line 382 "../src/parser.y"
    { (yyval.e) = new_native(strdup("shiftright"), LINE, m_shiftright, (yyvsp[-1].e), NUMBER); }
#line 3890 "parser.c"
    break;

  case 265:
#line 383 "../src/parser.y"
    { (yyval.e) = new_native(strdup("XOR"), LINE, m_xor, (yyvsp[-1].e), NUMBER); }
#line 3896 "parser.c"
    break;

  case 266:
#line 387 "../src/parser.y"
    { (yyval.e) = new_native(strdup("closemedia"), LINE, m_closemedia, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3902 "parser.c"
    break;

  case 267:
#line 388 "../src/parser.y"
    { (yyval.e) = new_native(strdup("effect"), LINE, m_effect, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3908 "parser.c"
    break;

  case 268:
#line 389 "../src/parser.y"
    { (yyval.e) = new_native(strdup("setmedia"), LINE, m_setmedia, (yyvsp[-1].e), NUMBER); }
#line 3914 "parser.c"
    break;

  case 269:
#line 390 "../src/parser.y"
    { (yyval.e) = new_native(strdup("setmedia"), LINE, m_setmedia, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3920 "parser.c"
    break;

  case 270:
#line 391 "../src/parser.y"
    { (yyval.e) = new_native(strdup("showmedia"), LINE, m_showmedia, merge(merge((yyvsp[-3].e), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3926 "parser.c"
    break;

  case 271:
#line 395 "../src/parser.y"
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3932 "parser.c"
    break;

  case 272:
#line 396 "../src/parser.y"
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, (yyvsp[-1].e), STRING); }
#line 3938 "parser.c"
    break;

  case 273:
#line 397 "../src/parser.y"
    { (yyval.e) = new_native(strdup("earlier"), LINE, m_earlier, (yyvsp[-1].e), NUMBER); }
#line 3944 "parser.c"
    break;

  case 274:
#line 398 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3950 "parser.c"
    break;

  case 275:
#line 399 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, (yyvsp[-1].e), STRING); }
#line 3956 "parser.c"
    break;

  case 276:
#line 400 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getdevice"), LINE, m_getdevice, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3962 "parser.c"
    break;

  case 277:
#line 401 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3968 "parser.c"
    break;

  case 278:
#line 402 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, (yyvsp[-1].e), NUMBER); }
#line 3974 "parser.c"
    break;

  case 279:
#line 403 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getenv"), LINE, m_getenv, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3980 "parser.c"
    break;

  case 280:
#line 404 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getsize"), LINE, m_getsize, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3986 "parser.c"
    break;

  case 281:
#line 405 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getsum"), LINE, m_getsum, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3992 "parser.c"
    break;

  case 282:
#line 406 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, NULL, NUMBER); }
#line 3998 "parser.c"
    break;

  case 283:
#line 407 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4004 "parser.c"
    break;

  case 284:
#line 408 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4010 "parser.c"
    break;

  case 285:
#line 409 "../src/parser.y"
    { (yyval.e) = new_native(strdup("iconinfo"), LINE, m_iconinfo, (yyvsp[-1].e), NUMBER); }
#line 4016 "parser.c"
    break;

  case 286:
#line 410 "../src/parser.y"
    { (yyval.e) = new_native(strdup("querydisplay"), LINE, m_querydisplay, (yyvsp[-1].e), NUMBER); }
#line 4022 "parser.c"
    break;

  case 287:
#line 414 "../src/parser.y"
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-3].s), LINE, (yyvsp[-2].e), (yyvsp[-1].e))), NUMBER); }
#line 4028 "parser.c"
    break;

  case 288:
#line 415 "../src/parser.y"
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, (yyvsp[-1].e), NULL)), NUMBER); }
#line 4034 "parser.c"
    break;

  case 289:
#line 416 "../src/parser.y"
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, NULL, (yyvsp[-1].e))), NUMBER); }
#line 4040 "parser.c"
    break;

  case 290:
#line 417 "../src/parser.y"
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-1].s), LINE, NULL, NULL)), NUMBER); }
#line 4046 "parser.c"
    break;

  case 291:
#line 418 "../src/parser.y"
    { (yyval.e) = new_cusref((yyvsp[-2].s), LINE, (yyvsp[-1].e)); }
#line 4052 "parser.c"
    break;

  case 292:
#line 419 "../src/parser.y"
    { (yyval.e) = new_cusref((yyvsp[-1].s), LINE, NULL); }
#line 4058 "parser.c"
    break;

  case 293:
#line 423 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, NULL, NUMBER); }
#line 4064 "parser.c"
    break;

  case 294:
#line 424 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, (yyvsp[-1].e), NUMBER); }
#line 4070 "parser.c"
    break;

  case 295:
#line 425 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askchoice"), LINE, m_askchoice, (yyvsp[-1].e), NUMBER); }
#line 4076 "parser.c"
    break;

  case 296:
#line 426 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, NULL, STRING); }
#line 4082 "parser.c"
    break;

  case 297:
#line 427 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, (yyvsp[-1].e), STRING); }
#line 4088 "parser.c"
    break;

  case 298:
#line 428 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askdisk"), LINE, m_askdisk, (yyvsp[-1].e), NUMBER); }
#line 4094 "parser.c"
    break;

  case 299:
#line 429 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, NULL, STRING); }
#line 4100 "parser.c"
    break;

  case 300:
#line 430 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, (yyvsp[-1].e), STRING); }
#line 4106 "parser.c"
    break;

  case 301:
#line 431 "../src/parser.y"
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, NULL, NUMBER); }
#line 4112 "parser.c"
    break;

  case 302:
#line 432 "../src/parser.y"
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, (yyvsp[-1].e), NUMBER); }
#line 4118 "parser.c"
    break;

  case 303:
#line 433 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askoptions"), LINE, m_askoptions, (yyvsp[-1].e), NUMBER); }
#line 4124 "parser.c"
    break;

  case 304:
#line 434 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, NULL, STRING); }
#line 4130 "parser.c"
    break;

  case 305:
#line 435 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, (yyvsp[-1].e), STRING); }
#line 4136 "parser.c"
    break;

  case 306:
#line 439 "../src/parser.y"
    { (yyval.e) = new_native(strdup("cat"), LINE, m_cat, (yyvsp[-1].e), STRING); }
#line 4142 "parser.c"
    break;

  case 307:
#line 440 "../src/parser.y"
    { (yyval.e) = new_native(strdup("expandpath"), LINE, m_expandpath, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4148 "parser.c"
    break;

  case 308:
#line 441 "../src/parser.y"
    { (yyval.e) = new_native((yyvsp[-2].s), LINE, m_fmt, (yyvsp[-1].e), STRING); }
#line 4154 "parser.c"
    break;

  case 309:
#line 442 "../src/parser.y"
    { (yyval.e) = new_native((yyvsp[-1].s), LINE, m_fmt, NULL, STRING); }
#line 4160 "parser.c"
    break;

  case 310:
#line 443 "../src/parser.y"
    { (yyval.e) = new_native(strdup("pathonly"), LINE, m_pathonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4166 "parser.c"
    break;

  case 311:
#line 444 "../src/parser.y"
    { (yyval.e) = new_native(strdup("patmatch"), LINE, m_patmatch, (yyvsp[-1].e), NUMBER); }
#line 4172 "parser.c"
    break;

  case 312:
#line 445 "../src/parser.y"
    { (yyval.e) = new_native(strdup("strlen"), LINE, m_strlen, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4178 "parser.c"
    break;

  case 313:
#line 446 "../src/parser.y"
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, (yyvsp[-1].e), STRING); }
#line 4184 "parser.c"
    break;

  case 314:
#line 447 "../src/parser.y"
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, push((yyvsp[-2].e), (yyvsp[-1].e)), STRING); }
#line 4190 "parser.c"
    break;

  case 315:
#line 448 "../src/parser.y"
    { (yyval.e) = new_native(strdup("tackon"), LINE, m_tackon, (yyvsp[-1].e), STRING); }
#line 4196 "parser.c"
    break;

  case 316:
#line 452 "../src/parser.y"
    { (yyval.e) = new_native(strdup("set"), LINE, m_set, (yyvsp[-1].e), DANGLE); }
#line 4202 "parser.c"
    break;

  case 317:
#line 453 "../src/parser.y"
    { (yyval.e) = new_native(strdup("symbolset"), LINE, m_symbolset, (yyvsp[-1].e), DANGLE); }
#line 4208 "parser.c"
    break;

  case 318:
#line 454 "../src/parser.y"
    { (yyval.e) = new_native(strdup("symbolval"), LINE, m_symbolval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4214 "parser.c"
    break;

  case 319:
#line 458 "../src/parser.y"
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4220 "parser.c"
    break;

  case 320:
#line 459 "../src/parser.y"
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4226 "parser.c"
    break;

  case 321:
#line 460 "../src/parser.y"
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4232 "parser.c"
    break;

  case 322:
#line 461 "../src/parser.y"
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4238 "parser.c"
    break;

  case 323:
#line 462 "../src/parser.y"
    { (yyval.e) = new_native(strdup("showwbobject"), LINE, m_showwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4244 "parser.c"
    break;

  case 324:
#line 463 "../src/parser.y"
    { (yyval.e) = new_native(strdup("closewbobject"), LINE, m_closewbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4250 "parser.c"
    break;

  case 325:
#line 467 "../src/parser.y"
    { (yyval.e) = new_option(strdup("all"), OPT_ALL, NULL); }
#line 4256 "parser.c"
    break;

  case 326:
#line 468 "../src/parser.y"
    { (yyval.e) = new_option(strdup("append"), OPT_APPEND, (yyvsp[-1].e)); }
#line 4262 "parser.c"
    break;

  case 327:
#line 469 "../src/parser.y"
    { (yyval.e) = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); }
#line 4268 "parser.c"
    break;

  case 328:
#line 470 "../src/parser.y"
    { (yyval.e) = new_option(strdup("back"), OPT_BACK, (yyvsp[-1].e)); }
#line 4274 "parser.c"
    break;

  case 329:
#line 471 "../src/parser.y"
    { (yyval.e) = new_option(strdup("choices"), OPT_CHOICES, (yyvsp[-1].e)); }
#line 4280 "parser.c"
    break;

  case 330:
#line 472 "../src/parser.y"
    { (yyval.e) = new_option(strdup("command"), OPT_COMMAND, (yyvsp[-1].e)); }
#line 4286 "parser.c"
    break;

  case 331:
#line 473 "../src/parser.y"
    { (yyval.e) = new_option(strdup("compression"), OPT_COMPRESSION, NULL); }
#line 4292 "parser.c"
    break;

  case 332:
#line 474 "../src/parser.y"
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, push(new_contxt(), (yyvsp[-1].e))); }
#line 4298 "parser.c"
    break;

  case 333:
#line 475 "../src/parser.y"
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, NULL); }
#line 4304 "parser.c"
    break;

  case 334:
#line 476 "../src/parser.y"
    { (yyval.e) = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), (yyvsp[-1].e))); }
#line 4310 "parser.c"
    break;

  case 335:
#line 477 "../src/parser.y"
    { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, (yyvsp[-1].e)); }
#line 4316 "parser.c"
    break;

  case 336:
#line 478 "../src/parser.y"
    { (yyval.e) = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), (yyvsp[-1].e))); }
#line 4322 "parser.c"
    break;

  case 337:
#line 479 "../src/parser.y"
    { (yyval.e) = new_option(strdup("disk"), OPT_DISK, NULL); }
#line 4328 "parser.c"
    break;

  case 338:
#line 480 "../src/parser.y"
    { (yyval.e) = new_option(strdup("files"), OPT_FILES, NULL); }
#line 4334 "parser.c"
    break;

  case 339:
#line 481 "../src/parser.y"
    { (yyval.e) = new_option(strdup("fonts"), OPT_FONTS, NULL); }
#line 4340 "parser.c"
    break;

  case 340:
#line 482 "../src/parser.y"
    { (yyval.e) = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4346 "parser.c"
    break;

  case 341:
#line 483 "../src/parser.y"
    { (yyval.e) = new_option(strdup("getposition"), OPT_GETPOSITION, (yyvsp[-1].e)); }
#line 4352 "parser.c"
    break;

  case 342:
#line 484 "../src/parser.y"
    { (yyval.e) = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4358 "parser.c"
    break;

  case 343:
#line 485 "../src/parser.y"
    { (yyval.e) = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, (yyvsp[-1].e)); }
#line 4364 "parser.c"
    break;

  case 344:
#line 486 "../src/parser.y"
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, (yyvsp[-1].e)); }
#line 4370 "parser.c"
    break;

  case 345:
#line 487 "../src/parser.y"
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4376 "parser.c"
    break;

  case 346:
#line 488 "../src/parser.y"
    { (yyval.e) = new_option(strdup("infos"), OPT_INFOS, NULL); }
#line 4382 "parser.c"
    break;

  case 347:
#line 489 "../src/parser.y"
    { (yyval.e) = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4388 "parser.c"
    break;

  case 348:
#line 490 "../src/parser.y"
    { (yyval.e) = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), (yyvsp[-1].e))); }
#line 4394 "parser.c"
    break;

  case 349:
#line 491 "../src/parser.y"
    { (yyval.e) = new_option(strdup("newpath"), OPT_NEWPATH, NULL); }
#line 4400 "parser.c"
    break;

  case 350:
#line 492 "../src/parser.y"
    { (yyval.e) = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); }
#line 4406 "parser.c"
    break;

  case 351:
#line 493 "../src/parser.y"
    { (yyval.e) = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); }
#line 4412 "parser.c"
    break;

  case 352:
#line 494 "../src/parser.y"
    { (yyval.e) = new_option(strdup("noreq"), OPT_NOREQ, NULL); }
#line 4418 "parser.c"
    break;

  case 353:
#line 495 "../src/parser.y"
    { (yyval.e) = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), (yyvsp[-1].e))); }
#line 4424 "parser.c"
    break;

  case 354:
#line 496 "../src/parser.y"
    { (yyval.e) = new_option(strdup("prompt"), OPT_PROMPT, (yyvsp[-1].e)); }
#line 4430 "parser.c"
    break;

  case 355:
#line 497 "../src/parser.y"
    { (yyval.e) = new_option(strdup("quiet"), OPT_QUIET, NULL); }
#line 4436 "parser.c"
    break;

  case 356:
#line 498 "../src/parser.y"
    { (yyval.e) = new_option(strdup("range"), OPT_RANGE, (yyvsp[-1].e)); }
#line 4442 "parser.c"
    break;

  case 357:
#line 499 "../src/parser.y"
    { (yyval.e) = new_option(strdup("safe"), OPT_SAFE, NULL); }
#line 4448 "parser.c"
    break;

  case 358:
#line 500 "../src/parser.y"
    { (yyval.e) = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4454 "parser.c"
    break;

  case 359:
#line 501 "../src/parser.y"
    { (yyval.e) = new_option(strdup("setposition"), OPT_SETPOSITION, (yyvsp[-1].e)); }
#line 4460 "parser.c"
    break;

  case 360:
#line 502 "../src/parser.y"
    { (yyval.e) = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4466 "parser.c"
    break;

  case 361:
#line 503 "../src/parser.y"
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, (yyvsp[-1].e)); }
#line 4472 "parser.c"
    break;

  case 362:
#line 504 "../src/parser.y"
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4478 "parser.c"
    break;

  case 363:
#line 505 "../src/parser.y"
    { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4484 "parser.c"
    break;

  case 364:
#line 506 "../src/parser.y"
    { (yyval.e) = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); }
#line 4490 "parser.c"
    break;

  case 365:
#line 507 "../src/parser.y"
    { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, (yyvsp[-1].e)); }
#line 4496 "parser.c"
    break;

  case 366:
#line 508 "../src/parser.y"
    { (yyval.e) = new_option(strdup("resident"), OPT_RESIDENT, NULL); }
#line 4502 "parser.c"
    break;

  case 367:
#line 509 "../src/parser.y"
    { (yyval.e) = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4508 "parser.c"
    break;

  case 368:
#line 510 "../src/parser.y"
    { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4514 "parser.c"
    break;

  case 369:
#line 511 "../src/parser.y"
    { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(push(new_contxt(), (yyvsp[-3].e)), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4520 "parser.c"
    break;


#line 4524 "parser.c"

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
#line 513 "../src/parser.y"

