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
#define YYFINAL  197
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2108

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  148
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  154
/* YYNRULES -- Number of rules.  */
#define YYNRULES  367
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  712

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
     271,   274,   275,   276,   277,   280,   281,   282,   283,   284,
     285,   288,   289,   290,   291,   292,   293,   294,   295,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   312,   313,   314,   315,   316,   317,   318,   320,   321,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   384,   385,   386,   387,   388,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   409,   410,   411,   412,   413,
     414,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   444,   445,   446,   449,   450,   451,
     452,   453,   454,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501
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

#define YYPACT_NINF -332

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-332)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -135,  1704,     8,  -332,  -332,  -135,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,    53,    77,    42,    42,    42,    42,    42,    42,    42,
    -127,  -125,   434,   434,   434,    42,    88,  -135,    42,  -116,
    -106,  -106,   434,    42,    42,    42,    42,   434,    42,   434,
    -106,  -106,    42,    42,    42,    96,   434,    42,   102,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,   108,  -106,    42,    41,  -128,  -106,  -119,
    -106,  -117,  -111,  -106,  -102,    42,    42,    42,    42,    42,
      42,    42,    52,    42,    42,   434,    42,    42,    42,    42,
      42,    42,    42,    42,    42,   -74,  -100,  -332,  -135,  -332,
    -332,  -332,  -332,  -332,  -332,  1849,  -332,  -332,   117,  -332,
    -332,  -332,   129,    42,   -72,   -70,   -22,   137,    27,    46,
     524,  -135,  -135,  -332,  -332,  1124,   144,   434,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
     158,   434,   166,   434,   246,  1414,  -332,   255,   296,   -97,
    -135,  -332,  1909,   -88,   -86,   -77,   434,   -75,    48,  -135,
     306,   -53,   -51,   434,   320,   -42,  -106,   326,   -13,   -11,
     332,    -1,    69,  -332,   352,   365,   434,    75,  -332,   371,
     402,   408,    78,    80,    86,    91,    93,    42,   414,   115,
     130,   138,   141,    42,   420,    42,   426,   150,   156,   480,
     176,   202,   509,   206,   226,   247,   253,  -332,    15,    55,
     258,    64,  -332,    72,    74,  -332,    90,    98,  -332,   100,
    -332,   104,   106,  -332,   125,   515,   263,   303,   311,   315,
     588,   322,    42,    13,  -332,   708,   324,   127,   434,   327,
     363,   731,   368,   738,   369,   384,   385,   386,  -332,  -332,
     -74,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  1704,  -332,
    -332,   524,  -332,  -332,  -332,   877,   134,   146,    42,   394,
      42,   397,  -135,    42,    42,   398,   938,    42,    42,    42,
     399,   400,   403,    42,    42,    42,    42,   944,   404,    42,
      42,   405,   406,   409,   410,    42,    42,   411,    42,   412,
      42,    42,    42,    42,    42,   415,    42,   416,    42,   148,
    -332,   153,   954,  -106,  -332,   155,   960,  -332,   168,   973,
    -332,  -332,   418,  -332,   983,  -332,   179,    42,  -332,  -332,
    -332,   181,   205,  -118,  -332,   421,   422,  -332,   209,  1559,
    -332,   423,   435,  -332,   427,  -332,   213,   223,  -332,   225,
    -332,   241,   244,  -332,   252,  -332,  -332,  -332,  -332,   261,
    -332,  -332,  -332,   310,  1519,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  1525,  -332,  -332,  -332,  -332,  -332,
     429,  -332,   430,    42,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,   439,  -332,   431,  -332,  -332,
    -332,  -332,   432,    68,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,   437,  -332,
    -332,    42,  -332,  -332,    42,  -332,  -332,   314,   318,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  1531,  -332,
    -332,  -332,  -332,  -332,  1539,  -332,  1669,  -332,   334,  1677,
    1686,  -332,  -332,   440,   441,  1815,   442,  -332,  -332,  -332,
     443,   457,   458,   460,  -332,  1824,  -332,   461,   462,  -332,
    -332,  -332,  -332,   471,  1830,  -332,   472,  -332,   476,   477,
     488,  1945,   505,   507,  -332,  1953,  -332,   510,  -332,  -332,
    -332,   336,  -332,  -332,   338,  -332,  -332,   342,  -332,  -332,
    -332,  -106,  -332,  -332,   350,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,   354,  -332,  -332,  -332,  -332,   356,  -332,  -332,
    -332,   358,  -332,  -332,  -332,  1968,  -332,  -332,  -332,  -332,
     511,  -332,  -332,  -332,  -332,  -332,   360,  -332,   512,  1269,
     362,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  1269,  -332,
     367,  -332
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,    14,     3,    11,    77,    78,    79,
      80,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   111,
     110,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   148,   147,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     1,    13,    28,
      27,    29,    24,    25,    26,     0,   290,     8,     0,     4,
       5,   307,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,   188,     0,     0,     0,    17,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    56,    55,
      57,    58,    59,    60,    61,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    62,    76,    63,    75,
       0,     0,     0,     0,     0,     0,   206,     0,     0,     0,
       0,   208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,     0,     0,     0,     0,   251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,     0,     0,
       0,     0,   291,     0,     0,   294,     0,     0,   297,     0,
     299,     0,     0,   302,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    15,
       0,   289,     7,   306,     6,   177,   179,   180,     0,   183,
      21,    34,   182,   181,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,     0,     0,    16,   196,     0,     0,   200,     0,     0,
     201,   205,     0,   204,     0,   207,     0,     0,   210,   211,
     215,     0,     0,     0,   216,     0,     0,   219,     0,     0,
     224,     0,     0,   222,     0,   228,     0,     0,   232,     0,
     230,     0,     0,   236,     0,   237,   238,   239,   241,     0,
     242,   243,   248,     0,     0,   249,   250,   252,   253,   254,
     255,   256,   257,   258,     0,   260,   261,   262,   263,   264,
       0,   266,     0,     0,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,     0,   281,     0,   283,   284,
      33,   288,     0,     0,   292,   293,   295,   296,   298,   300,
     301,   303,   304,   305,   308,   309,   310,   311,     0,   313,
      31,     0,   314,   315,     0,   316,   317,     0,     0,   321,
     322,   171,   172,   173,   174,   175,   176,   178,     0,    35,
     184,    23,   185,   186,     0,   323,     0,   325,     0,     0,
       0,   329,   331,     0,     0,     0,     0,   335,   336,   337,
       0,     0,     0,     0,   343,     0,   344,     0,     0,   347,
     348,   349,   350,     0,     0,   353,     0,   355,     0,     0,
       0,     0,     0,     0,   362,     0,   364,     0,    18,   189,
     190,     0,   193,   194,     0,   197,   198,     0,   202,   203,
     209,     0,   212,   213,     0,   217,   218,   220,   223,   221,
     225,   226,     0,   231,   229,   233,   234,     0,   240,   245,
     246,     0,   259,   265,   267,     0,   282,   287,    32,   286,
       0,   312,    30,     9,   318,   319,     0,    19,     0,     0,
       0,   324,   326,   327,   328,   330,   332,   333,   334,   338,
     339,   340,   341,   342,   345,   346,   351,   352,   354,   356,
     357,   358,   360,   359,   361,   363,   365,   191,   195,   199,
     214,   227,   235,   247,   268,   285,   320,    20,     0,   366,
       0,   367
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -332,  -332,  -331,   481,   675,    44,  -332,     0,     2,   -95,
    -206,  -332,    11,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,   366,  -332,
    -332,  -109,  -332,  -260,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,   283,  -332,  -332
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   207,   214,   208,   365,   209,   198,   443,
     391,   395,   210,   363,   533,   218,   219,   228,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
       4,   195,     5,   196,     1,     4,   424,   278,   197,   427,
     532,   282,   342,   223,   394,   224,   551,   227,   271,   273,
     282,   345,   282,   348,   281,   283,   284,   286,   282,   350,
     471,   474,   293,   282,   297,   298,   299,   282,   353,     1,
     379,   306,     1,   455,   341,   199,   200,   201,   202,   203,
     204,   282,   458,   282,   459,   362,   199,   200,   201,   202,
     203,   204,   282,   460,   463,   464,   378,   530,   385,   339,
     386,   658,   343,   344,   346,   347,   349,   351,   352,   354,
     199,   200,   201,   202,   203,   204,   472,   473,   282,   475,
     368,   199,   200,   201,   202,   203,   204,   282,   480,   199,
     200,   201,   202,   203,   204,   199,   200,   201,   202,   203,
     204,   199,   200,   201,   202,   203,   204,     4,   387,   279,
     199,   200,   201,   202,   203,   204,   282,   485,   282,   486,
     439,   441,   199,   200,   201,   202,   203,   204,   282,   488,
     199,   200,   201,   202,   203,   204,   212,   199,   200,   201,
     202,   203,   204,   552,   525,   526,   226,   270,   272,   274,
     277,   199,   200,   201,   202,   203,   204,   392,   452,   199,
     200,   201,   202,   203,   204,   445,   300,   448,   466,   304,
     305,   205,   309,   310,   311,   569,   393,   439,   467,   571,
     461,   318,   205,   206,   282,   528,     4,   476,     4,   479,
     481,   482,   660,     1,   531,   380,   489,     1,   659,   490,
     493,   282,   534,   282,   535,   495,   205,   211,   499,   355,
     500,     4,     4,   396,   397,   380,   501,   275,   276,   282,
     536,   502,   371,   503,   373,   205,   303,   282,   537,   282,
     538,   205,   308,   282,   539,   282,   540,   205,   337,   199,
     200,   201,   202,   203,   204,   506,   205,   381,   199,   200,
     201,   202,   203,   204,   282,   541,   282,   556,   205,   383,
     507,   442,   557,     1,   572,   380,   388,   389,   508,     4,
       4,   509,   456,   225,   440,     1,   573,   282,   618,     4,
     515,   468,   282,   619,   282,   622,   516,   225,   444,   199,
     200,   201,   202,   203,   204,   225,   447,   282,   625,   199,
     200,   201,   202,   203,   204,   446,   518,   449,     1,   630,
     282,   632,   454,   199,   200,   201,   202,   203,   204,   199,
     200,   201,   202,   203,   204,   199,   200,   201,   202,   203,
     204,     4,   519,     5,   282,   633,   521,   621,     1,   637,
     494,   624,   282,   640,   627,   199,   200,   201,   202,   203,
     204,   504,   282,   641,   282,   643,   522,   634,   199,   200,
     201,   202,   203,   204,   199,   200,   201,   202,   203,   204,
     282,   644,   642,   282,   645,   205,   450,   523,   195,   647,
     568,   282,   646,   524,   275,   451,     4,     4,   529,   651,
     282,   648,     4,   543,   578,   199,   200,   201,   202,   203,
     204,   199,   200,   201,   202,   203,   204,   199,   200,   201,
     202,   203,   204,   199,   200,   201,   202,   203,   204,   199,
     200,   201,   202,   203,   204,   205,   453,   199,   200,   201,
     202,   203,   204,   544,   576,   469,   470,   579,   580,   282,
     649,   545,   585,   282,   664,   546,     4,   282,   665,   225,
     478,   595,   549,   666,   555,   225,   483,   559,     4,   380,
     604,   205,   487,     1,   672,   282,   697,   282,   698,   670,
     615,   282,   699,   199,   200,   201,   202,   203,   204,   282,
     700,   205,   491,   282,   701,   282,   702,   282,   703,   282,
     706,   282,   709,   560,   225,   492,   282,   711,   562,   564,
     205,   496,   199,   200,   201,   202,   203,   204,   199,   200,
     201,   202,   203,   204,   565,   566,   567,   199,   200,   201,
     202,   203,   204,     4,   575,     5,   670,   577,   581,   587,
     588,   205,   497,   589,   596,   599,   600,   205,   498,   601,
     602,   605,   607,   205,   505,   614,   616,   655,   628,   205,
     511,   635,   636,   638,   429,   205,   514,   639,     4,   653,
     654,   656,   657,   225,   439,   710,   437,   661,     4,   668,
     675,   676,   678,   679,   213,   213,   213,   217,   220,   221,
     222,   199,   200,   201,   202,   203,   204,   680,   681,   280,
     682,   684,   685,   285,   287,   288,   213,   290,   292,   294,
     296,   686,   688,   439,   213,   302,   689,   690,   307,   205,
     517,   527,   213,   313,   213,   213,   316,   317,   691,   213,
     213,   213,   322,   213,   213,   213,   326,   213,   329,   331,
     332,   334,   335,   336,   338,   693,   213,   694,   205,   520,
     696,   705,   707,   465,   205,   542,     0,   356,   357,   213,
     359,   213,   213,   388,   213,   366,   367,   369,   370,   195,
     213,   568,   213,   213,   213,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   382,
       0,     0,     0,   382,   384,     0,     0,     0,   390,     0,
       0,   390,     0,     0,     0,     0,     0,   382,   195,     0,
     196,   199,   200,   201,   202,   203,   204,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   547,     0,
       0,     0,     0,     0,   199,   200,   201,   202,   203,   204,
       0,   199,   200,   201,   202,   203,   204,     0,     0,     0,
       0,   382,     0,   382,     0,   382,     0,     0,   382,     0,
       0,     0,     0,     0,     0,     0,     0,   462,     0,     0,
       0,   384,     0,     0,   477,   384,     0,     0,   484,   215,
     216,   382,     0,     0,     0,   382,   382,     0,     0,     0,
     382,   382,   382,     0,     0,     0,     0,     0,     0,   382,
     289,   291,     0,   295,   213,   512,   213,   384,   301,     0,
     384,     0,     0,   384,     0,     0,   312,     0,   314,   315,
       0,     0,     0,   319,   320,   321,     0,   323,   324,   325,
     327,   328,   330,     0,   333,     0,   382,     0,     0,     0,
     340,   548,     0,   550,     0,     0,   554,   205,   553,   558,
       0,     0,   382,   358,   382,   360,   361,     0,   364,     0,
       0,     0,     0,     0,   372,     0,   374,   375,   376,   377,
     205,   561,   390,     0,     0,     0,   390,   205,   563,   574,
     199,   200,   201,   202,   203,   204,     0,   583,   584,     0,
     586,     0,     0,     0,   590,   213,   592,   213,     0,     0,
     597,   598,     0,     0,     0,     0,   603,     0,     0,   213,
       0,   608,   213,   610,   611,   613,     0,     0,     0,   617,
       0,     0,     0,   382,     0,     0,     0,   382,     0,     0,
     382,     0,     0,     0,     0,   382,     0,     0,   631,     0,
       0,   199,   200,   201,   202,   203,   204,   199,   200,   201,
     202,   203,   204,     0,     0,     0,     0,   199,   200,   201,
     202,   203,   204,   199,   200,   201,   202,   203,   204,     0,
       0,     0,     0,     0,     0,   382,   199,   200,   201,   202,
     203,   204,     0,     0,     0,   382,   199,   200,   201,   202,
     203,   204,     0,     0,     0,     0,     0,     0,   510,     0,
     513,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   388,   570,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   662,     0,     0,   663,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   390,     0,   382,     0,     0,
     382,   382,     0,     0,     0,     0,   382,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   382,   205,   582,     0,
       0,     0,     0,   205,   594,   382,     0,     0,     0,   591,
       0,   593,   384,   225,   620,     0,   382,     0,     0,   225,
     623,     0,     0,   606,     0,     0,   609,     0,   612,     0,
       0,     0,   225,   626,     0,     0,     0,     0,     0,     0,
       0,     0,   205,   629,     0,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,   103,   382,   104,   105,   398,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     0,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,     0,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   225,     0,   188,   189,   190,   191,   192,
     193,   194,   101,   102,     0,     0,     0,     0,     0,     0,
     103,     0,   104,   105,   398,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   708,     0,
     188,   189,   190,   191,   192,   193,   194,   101,   102,     0,
       0,     0,     0,     0,     0,   103,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     0,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,     0,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,   200,   201,   202,   203,   204,   199,   200,
     201,   202,   203,   204,   199,   200,   201,   202,   203,   204,
       0,   427,   199,   200,   201,   202,   203,   204,     0,     0,
       0,     0,     0,   205,     0,   188,   189,   190,   191,   192,
     193,   194,   101,   102,     0,     0,     0,     0,     0,     0,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   225,   650,
       0,     0,     0,     0,   205,   652,     0,     0,     0,     0,
       1,   667,   199,   200,   201,   202,   203,   204,   669,   389,
     199,   200,   201,   202,   203,   204,     0,     0,   429,   199,
     200,   201,   202,   203,   204,     0,     0,     0,   205,     0,
     188,   189,   190,   191,   192,   193,   194,   101,   102,     0,
       0,     0,     0,     0,     0,   103,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     0,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,     0,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,     0,     0,     0,     0,   205,   671,
       0,     0,     0,     0,     0,     0,   205,   673,   199,   200,
     201,   202,   203,   204,     0,   205,   674,   199,   200,   201,
     202,   203,   204,   199,   200,   201,   202,   203,   204,     0,
       0,     0,     0,     1,     0,   188,   189,   190,   191,   192,
     193,   194,   101,   102,     0,     0,     0,     0,     0,     0,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   457,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   199,   200,
     201,   202,   203,   204,   205,   677,   199,   200,   201,   202,
     203,   204,     0,   205,   683,     0,     0,     0,     0,   205,
     687,   199,   200,   201,   202,   203,   204,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   205,     0,
     188,   189,   190,   191,   192,   193,   194,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   282,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   205,   692,     0,     0,     0,     0,
       0,     0,   205,   695,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   704
};

static const yytype_int16 yycheck[] =
{
       0,     1,     0,     1,   139,     5,   124,   116,     0,   127,
     341,   139,   140,   140,   220,   140,     3,   112,   113,   114,
     139,   140,   139,   140,   140,   120,   121,   122,   139,   140,
     290,   291,   127,   139,   129,   130,   131,   139,   140,   139,
     140,   136,   139,   140,     3,     3,     4,     5,     6,     7,
       8,   139,   140,   139,   140,     3,     3,     4,     5,     6,
       7,     8,   139,   140,   139,   140,   140,     3,   140,   164,
     140,     3,   167,   168,   169,   170,   171,   172,   173,   174,
       3,     4,     5,     6,     7,     8,   139,   140,   139,   140,
     185,     3,     4,     5,     6,     7,     8,   139,   140,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,   117,   140,   117,
       3,     4,     5,     6,     7,     8,   139,   140,   139,   140,
     225,   226,     3,     4,     5,     6,     7,     8,   139,   140,
       3,     4,     5,     6,     7,     8,   102,     3,     4,     5,
       6,     7,     8,   140,   139,   140,   112,   113,   114,   115,
     116,     3,     4,     5,     6,     7,     8,   140,   277,     3,
       4,     5,     6,     7,     8,   270,   132,   272,   287,   135,
     136,   139,   138,   139,   140,   391,   140,   282,   140,   395,
     285,   147,   139,   140,   139,   140,   196,   292,   198,   294,
     295,   296,   533,   139,   140,   205,   301,   139,   140,   140,
     305,   139,   140,   139,   140,   140,   139,   140,   140,   175,
     140,   221,   222,   221,   222,   225,   140,   139,   140,   139,
     140,   140,   188,   140,   190,   139,   140,   139,   140,   139,
     140,   139,   140,   139,   140,   139,   140,   139,   140,     3,
       4,     5,     6,     7,     8,   140,   139,   140,     3,     4,
       5,     6,     7,     8,   139,   140,   139,   140,   139,   140,
     140,   227,   367,   139,   140,   275,   139,   140,   140,   279,
     280,   140,   280,   139,   140,   139,   140,   139,   140,   289,
     140,   289,   139,   140,   139,   140,   140,   139,   140,     3,
       4,     5,     6,     7,     8,   139,   140,   139,   140,     3,
       4,     5,     6,     7,     8,   271,   140,   273,   139,   140,
     139,   140,   278,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,   341,   140,   341,   139,   140,   140,   442,   139,   140,
     306,   446,   139,   140,   449,     3,     4,     5,     6,     7,
       8,   317,   139,   140,   139,   140,   140,   462,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
     139,   140,   477,   139,   140,   139,   140,   140,   388,   484,
     388,   139,   140,   140,   139,   140,   396,   397,   140,   494,
     139,   140,   402,   140,   402,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,   139,   140,     3,     4,     5,
       6,     7,     8,   140,   400,   139,   140,   403,   404,   139,
     140,   140,   408,   139,   140,   140,   456,   139,   140,   139,
     140,   417,   140,   558,   140,   139,   140,   140,   468,   469,
     426,   139,   140,   139,   140,   139,   140,   139,   140,   574,
     436,   139,   140,     3,     4,     5,     6,     7,     8,   139,
     140,   139,   140,   139,   140,   139,   140,   139,   140,   139,
     140,   139,   140,   140,   139,   140,   139,   140,   140,   140,
     139,   140,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,   140,   140,   140,     3,     4,     5,
       6,     7,     8,   533,   140,   533,   631,   140,   140,   140,
     140,   139,   140,   140,   140,   140,   140,   139,   140,   140,
     140,   140,   140,   139,   140,   140,   140,   513,   140,   139,
     140,   140,   140,   140,   129,   139,   140,   140,   568,   140,
     140,   140,   140,   139,   669,   670,   137,   140,   578,   568,
     140,   140,   140,   140,   103,   104,   105,   106,   107,   108,
     109,     3,     4,     5,     6,     7,     8,   140,   140,   118,
     140,   140,   140,   122,   123,   124,   125,   126,   127,   128,
     129,   140,   140,   708,   133,   134,   140,   140,   137,   139,
     140,   338,   141,   142,   143,   144,   145,   146,   140,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   140,   165,   140,   139,   140,
     140,   140,   140,   287,   139,   140,    -1,   176,   177,   178,
     179,   180,   181,   139,   183,   184,   185,   186,   187,   669,
     189,   669,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,
      -1,    -1,    -1,   212,   213,    -1,    -1,    -1,   217,    -1,
      -1,   220,    -1,    -1,    -1,    -1,    -1,   226,   708,    -1,
     708,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,   270,    -1,   272,    -1,   274,    -1,    -1,   277,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,    -1,    -1,
      -1,   290,    -1,    -1,   293,   294,    -1,    -1,   297,   104,
     105,   300,    -1,    -1,    -1,   304,   305,    -1,    -1,    -1,
     309,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,   318,
     125,   126,    -1,   128,   323,   324,   325,   326,   133,    -1,
     329,    -1,    -1,   332,    -1,    -1,   141,    -1,   143,   144,
      -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,   154,
     155,   156,   157,    -1,   159,    -1,   355,    -1,    -1,    -1,
     165,   360,    -1,   362,    -1,    -1,   365,   139,   140,   368,
      -1,    -1,   371,   178,   373,   180,   181,    -1,   183,    -1,
      -1,    -1,    -1,    -1,   189,    -1,   191,   192,   193,   194,
     139,   140,   391,    -1,    -1,    -1,   395,   139,   140,   398,
       3,     4,     5,     6,     7,     8,    -1,   406,   407,    -1,
     409,    -1,    -1,    -1,   413,   414,   415,   416,    -1,    -1,
     419,   420,    -1,    -1,    -1,    -1,   425,    -1,    -1,   428,
      -1,   430,   431,   432,   433,   434,    -1,    -1,    -1,   438,
      -1,    -1,    -1,   442,    -1,    -1,    -1,   446,    -1,    -1,
     449,    -1,    -1,    -1,    -1,   454,    -1,    -1,   457,    -1,
      -1,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,   494,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,   504,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,   323,    -1,
     325,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   551,    -1,    -1,   554,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   574,    -1,   576,    -1,    -1,
     579,   580,    -1,    -1,    -1,    -1,   585,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   595,   139,   140,    -1,
      -1,    -1,    -1,   139,   140,   604,    -1,    -1,    -1,   414,
      -1,   416,   611,   139,   140,    -1,   615,    -1,    -1,   139,
     140,    -1,    -1,   428,    -1,    -1,   431,    -1,   433,    -1,
      -1,    -1,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   140,    -1,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    11,   655,    13,    14,    15,
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
      71,    72,    73,    74,    15,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,     3,     4,
       5,     6,     7,     8,   139,   140,     3,     4,     5,     6,
       7,     8,    -1,   139,   140,    -1,    -1,    -1,    -1,   139,
     140,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   139,   149,   150,   155,   156,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,     3,     4,    11,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   141,   142,
     143,   144,   145,   146,   147,   155,   156,     0,   156,     3,
       4,     5,     6,     7,     8,   139,   140,   151,   153,   155,
     160,   140,   153,   151,   152,   152,   152,   151,   163,   164,
     151,   151,   151,   140,   140,   139,   153,   157,   165,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     153,   157,   153,   157,   153,   139,   140,   153,   289,   156,
     151,   140,   139,   157,   157,   151,   157,   151,   151,   152,
     151,   152,   151,   157,   151,   152,   151,   157,   157,   157,
     153,   152,   151,   140,   153,   153,   157,   151,   140,   153,
     153,   153,   152,   151,   152,   152,   151,   151,   153,   152,
     152,   152,   151,   152,   152,   152,   151,   152,   152,   151,
     152,   151,   151,   152,   151,   151,   151,   140,   151,   157,
     152,     3,   140,   157,   157,   140,   157,   157,   140,   157,
     140,   157,   157,   140,   157,   153,   151,   151,   152,   151,
     152,   152,     3,   161,   152,   154,   151,   151,   157,   151,
     151,   153,   152,   153,   152,   152,   152,   152,   140,   140,
     155,   140,   151,   140,   151,   140,   140,   140,   139,   140,
     151,   158,   140,   140,   158,   159,   156,   156,    15,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   157,
     140,   157,   153,   157,   140,   157,   153,   140,   157,   153,
     140,   140,   289,   140,   153,   140,   156,    15,   140,   140,
     140,   157,   151,   139,   140,   286,   289,   140,   156,   139,
     140,   291,   139,   140,   291,   140,   157,   151,   140,   157,
     140,   157,   157,   140,   151,   140,   140,   140,   140,   157,
     140,   140,   140,   157,   153,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   153,   140,   140,   140,   140,   140,
     152,   140,   151,   152,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   139,   140,   299,   140,   140,
       3,   140,   150,   162,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   151,   140,
     151,     3,   140,   140,   151,   140,   140,   157,   151,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   156,   158,
     140,   158,   140,   140,   151,   140,   153,   140,   156,   153,
     153,   140,   140,   151,   151,   153,   151,   140,   140,   140,
     151,   152,   151,   152,   140,   153,   140,   151,   151,   140,
     140,   140,   140,   151,   153,   140,   152,   140,   151,   152,
     151,   151,   152,   151,   140,   153,   140,   151,   140,   140,
     140,   157,   140,   140,   157,   140,   140,   157,   140,   140,
     140,   151,   140,   140,   157,   140,   140,   140,   140,   140,
     140,   140,   157,   140,   140,   140,   140,   157,   140,   140,
     140,   157,   140,   140,   140,   153,   140,   140,     3,   140,
     150,   140,   151,   151,   140,   140,   157,   140,   160,   139,
     157,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   139,   140,
     157,   140
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   148,   149,   150,   151,   151,   152,   153,   153,   154,
     154,   155,   155,   156,   156,   156,   157,   157,   157,   158,
     158,   158,   159,   159,   160,   160,   160,   160,   160,   160,
     161,   161,   162,   162,   163,   164,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   177,   177,   178,   179,   180,   181,   182,   183,
     183,   183,   183,   184,   184,   184,   184,   185,   185,   185,
     185,   186,   187,   187,   187,   187,   187,   188,   189,   190,
     191,   192,   193,   193,   193,   193,   194,   194,   194,   195,
     196,   197,   197,   197,   197,   198,   198,   198,   198,   199,
     199,   199,   199,   200,   200,   200,   200,   201,   202,   203,
     204,   204,   205,   206,   206,   207,   207,   207,   207,   208,
     209,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   224,   225,   226,
     226,   227,   228,   228,   229,   230,   230,   231,   232,   233,
     234,   234,   234,   235,   236,   237,   237,   237,   237,   238,
     238,   239,   239,   240,   241,   241,   242,   243,   243,   244,
     244,   245,   246,   246,   247,   248,   249,   249,   250,   251,
     252,   253,   253,   254,   255,   256,   257,   258,   258,   258,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     295,   296,   297,   298,   299,   300,   301,   301
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
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     5,     5,     3,     3,     5,
       5,     6,     4,     5,     5,     6,     4,     5,     5,     6,
       4,     4,     5,     5,     4,     4,     3,     4,     3,     5,
       4,     4,     5,     5,     6,     4,     4,     5,     5,     4,
       5,     5,     4,     5,     4,     5,     5,     6,     4,     5,
       4,     5,     4,     5,     5,     6,     4,     4,     4,     4,
       5,     4,     4,     4,     3,     5,     5,     6,     4,     4,
       4,     3,     4,     4,     4,     4,     4,     4,     4,     5,
       4,     4,     4,     4,     4,     5,     4,     5,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       3,     4,     5,     4,     4,     6,     5,     5,     4,     4,
       3,     3,     4,     4,     3,     4,     4,     3,     4,     3,
       4,     4,     3,     4,     4,     4,     4,     3,     4,     4,
       4,     4,     5,     4,     4,     4,     4,     4,     5,     5,
       6,     4,     4,     3,     4,     3,     4,     4,     4,     3,
       4,     3,     4,     4,     4,     3,     3,     3,     4,     4,
       4,     4,     4,     3,     3,     4,     4,     3,     3,     3,
       3,     4,     4,     3,     4,     3,     4,     4,     4,     4,
       4,     4,     3,     4,     3,     4,     5,     6
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
#line 1933 "parser.c"
        break;

    case 4: /* STR  */
#line 78 "../src/parser.y"
      { free(((*yyvaluep).s)); }
#line 1939 "parser.c"
        break;

    case 149: /* start  */
#line 76 "../src/parser.y"
      { run(((*yyvaluep).e));  }
#line 1945 "parser.c"
        break;

    case 150: /* s  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1951 "parser.c"
        break;

    case 151: /* p  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1957 "parser.c"
        break;

    case 152: /* pp  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1963 "parser.c"
        break;

    case 153: /* ps  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1969 "parser.c"
        break;

    case 154: /* pps  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1975 "parser.c"
        break;

    case 155: /* vp  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1981 "parser.c"
        break;

    case 156: /* vps  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1987 "parser.c"
        break;

    case 157: /* opts  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1993 "parser.c"
        break;

    case 158: /* xpb  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 1999 "parser.c"
        break;

    case 159: /* xpbs  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2005 "parser.c"
        break;

    case 160: /* np  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2011 "parser.c"
        break;

    case 161: /* sps  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2017 "parser.c"
        break;

    case 162: /* par  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2023 "parser.c"
        break;

    case 163: /* cv  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2029 "parser.c"
        break;

    case 164: /* cvv  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2035 "parser.c"
        break;

    case 165: /* opt  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2041 "parser.c"
        break;

    case 166: /* ivp  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2047 "parser.c"
        break;

    case 167: /* add  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2053 "parser.c"
        break;

    case 168: /* div  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2059 "parser.c"
        break;

    case 169: /* mul  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2065 "parser.c"
        break;

    case 170: /* sub  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2071 "parser.c"
        break;

    case 171: /* eq  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2077 "parser.c"
        break;

    case 172: /* gt  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2083 "parser.c"
        break;

    case 173: /* gte  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2089 "parser.c"
        break;

    case 174: /* lt  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2095 "parser.c"
        break;

    case 175: /* lte  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2101 "parser.c"
        break;

    case 176: /* neq  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2107 "parser.c"
        break;

    case 177: /* if  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2113 "parser.c"
        break;

    case 178: /* select  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2119 "parser.c"
        break;

    case 179: /* until  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2125 "parser.c"
        break;

    case 180: /* while  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2131 "parser.c"
        break;

    case 181: /* trace  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2137 "parser.c"
        break;

    case 182: /* retrace  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2143 "parser.c"
        break;

    case 183: /* execute  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2149 "parser.c"
        break;

    case 184: /* rexx  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2155 "parser.c"
        break;

    case 185: /* run  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2161 "parser.c"
        break;

    case 186: /* abort  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2167 "parser.c"
        break;

    case 187: /* exit  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2173 "parser.c"
        break;

    case 188: /* onerror  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2179 "parser.c"
        break;

    case 189: /* reboot  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2185 "parser.c"
        break;

    case 190: /* trap  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2191 "parser.c"
        break;

    case 191: /* copyfiles  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2197 "parser.c"
        break;

    case 192: /* copylib  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2203 "parser.c"
        break;

    case 193: /* delete  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2209 "parser.c"
        break;

    case 194: /* exists  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2215 "parser.c"
        break;

    case 195: /* fileonly  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2221 "parser.c"
        break;

    case 196: /* foreach  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2227 "parser.c"
        break;

    case 197: /* makeassign  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2233 "parser.c"
        break;

    case 198: /* makedir  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2239 "parser.c"
        break;

    case 199: /* protect  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2245 "parser.c"
        break;

    case 200: /* startup  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2251 "parser.c"
        break;

    case 201: /* textfile  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2257 "parser.c"
        break;

    case 202: /* tooltype  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2263 "parser.c"
        break;

    case 203: /* transcript  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2269 "parser.c"
        break;

    case 204: /* rename  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2275 "parser.c"
        break;

    case 205: /* complete  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2281 "parser.c"
        break;

    case 206: /* debug  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2287 "parser.c"
        break;

    case 207: /* message  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2293 "parser.c"
        break;

    case 208: /* user  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2299 "parser.c"
        break;

    case 209: /* welcome  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2305 "parser.c"
        break;

    case 210: /* working  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2311 "parser.c"
        break;

    case 211: /* and  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2317 "parser.c"
        break;

    case 212: /* bitand  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2323 "parser.c"
        break;

    case 213: /* bitnot  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2329 "parser.c"
        break;

    case 214: /* bitor  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2335 "parser.c"
        break;

    case 215: /* bitxor  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2341 "parser.c"
        break;

    case 216: /* not  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2347 "parser.c"
        break;

    case 217: /* in  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2353 "parser.c"
        break;

    case 218: /* or  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2359 "parser.c"
        break;

    case 219: /* shiftleft  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2365 "parser.c"
        break;

    case 220: /* shiftright  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2371 "parser.c"
        break;

    case 221: /* xor  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2377 "parser.c"
        break;

    case 222: /* closemedia  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2383 "parser.c"
        break;

    case 223: /* effect  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2389 "parser.c"
        break;

    case 224: /* setmedia  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2395 "parser.c"
        break;

    case 225: /* showmedia  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2401 "parser.c"
        break;

    case 226: /* database  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2407 "parser.c"
        break;

    case 227: /* earlier  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2413 "parser.c"
        break;

    case 228: /* getassign  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2419 "parser.c"
        break;

    case 229: /* getdevice  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2425 "parser.c"
        break;

    case 230: /* getdiskspace  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2431 "parser.c"
        break;

    case 231: /* getenv  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2437 "parser.c"
        break;

    case 232: /* getsize  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2443 "parser.c"
        break;

    case 233: /* getsum  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2449 "parser.c"
        break;

    case 234: /* getversion  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2455 "parser.c"
        break;

    case 235: /* iconinfo  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2461 "parser.c"
        break;

    case 236: /* querydisplay  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2467 "parser.c"
        break;

    case 237: /* dcl  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2473 "parser.c"
        break;

    case 238: /* cus  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2479 "parser.c"
        break;

    case 239: /* askbool  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2485 "parser.c"
        break;

    case 240: /* askchoice  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2491 "parser.c"
        break;

    case 241: /* askdir  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2497 "parser.c"
        break;

    case 242: /* askdisk  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2503 "parser.c"
        break;

    case 243: /* askfile  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2509 "parser.c"
        break;

    case 244: /* asknumber  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2515 "parser.c"
        break;

    case 245: /* askoptions  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2521 "parser.c"
        break;

    case 246: /* askstring  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2527 "parser.c"
        break;

    case 247: /* cat  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2533 "parser.c"
        break;

    case 248: /* expandpath  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2539 "parser.c"
        break;

    case 249: /* fmt  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2545 "parser.c"
        break;

    case 250: /* pathonly  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2551 "parser.c"
        break;

    case 251: /* patmatch  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2557 "parser.c"
        break;

    case 252: /* strlen  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2563 "parser.c"
        break;

    case 253: /* substr  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2569 "parser.c"
        break;

    case 254: /* tackon  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2575 "parser.c"
        break;

    case 255: /* set  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2581 "parser.c"
        break;

    case 256: /* symbolset  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2587 "parser.c"
        break;

    case 257: /* symbolval  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2593 "parser.c"
        break;

    case 258: /* openwbobject  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2599 "parser.c"
        break;

    case 259: /* showwbobject  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2605 "parser.c"
        break;

    case 260: /* closewbobject  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2611 "parser.c"
        break;

    case 261: /* all  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2617 "parser.c"
        break;

    case 262: /* append  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2623 "parser.c"
        break;

    case 263: /* assigns  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2629 "parser.c"
        break;

    case 264: /* back  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2635 "parser.c"
        break;

    case 265: /* choices  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2641 "parser.c"
        break;

    case 266: /* command  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2647 "parser.c"
        break;

    case 267: /* compression  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2653 "parser.c"
        break;

    case 268: /* confirm  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2659 "parser.c"
        break;

    case 269: /* default  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2665 "parser.c"
        break;

    case 270: /* delopts  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2671 "parser.c"
        break;

    case 271: /* dest  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2677 "parser.c"
        break;

    case 272: /* disk  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2683 "parser.c"
        break;

    case 273: /* files  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2689 "parser.c"
        break;

    case 274: /* fonts  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2695 "parser.c"
        break;

    case 275: /* getdefaulttool  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2701 "parser.c"
        break;

    case 276: /* getposition  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2707 "parser.c"
        break;

    case 277: /* getstack  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2713 "parser.c"
        break;

    case 278: /* gettooltype  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2719 "parser.c"
        break;

    case 279: /* help  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2725 "parser.c"
        break;

    case 280: /* infos  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2731 "parser.c"
        break;

    case 281: /* include  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2737 "parser.c"
        break;

    case 282: /* newname  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2743 "parser.c"
        break;

    case 283: /* newpath  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2749 "parser.c"
        break;

    case 284: /* nogauge  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2755 "parser.c"
        break;

    case 285: /* noposition  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2761 "parser.c"
        break;

    case 286: /* noreq  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2767 "parser.c"
        break;

    case 287: /* pattern  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2773 "parser.c"
        break;

    case 288: /* prompt  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2779 "parser.c"
        break;

    case 289: /* quiet  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2785 "parser.c"
        break;

    case 290: /* range  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2791 "parser.c"
        break;

    case 291: /* safe  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2797 "parser.c"
        break;

    case 292: /* setdefaulttool  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2803 "parser.c"
        break;

    case 293: /* setposition  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2809 "parser.c"
        break;

    case 294: /* setstack  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2815 "parser.c"
        break;

    case 295: /* settooltype  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2821 "parser.c"
        break;

    case 296: /* source  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2827 "parser.c"
        break;

    case 297: /* swapcolors  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2833 "parser.c"
        break;

    case 298: /* optional  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2839 "parser.c"
        break;

    case 299: /* resident  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2845 "parser.c"
        break;

    case 300: /* override  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2851 "parser.c"
        break;

    case 301: /* dynopt  */
#line 80 "../src/parser.y"
      { kill(((*yyvaluep).e)); }
#line 2857 "parser.c"
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
#line 3127 "parser.c"
    break;

  case 6:
#line 103 "../src/parser.y"
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3133 "parser.c"
    break;

  case 7:
#line 104 "../src/parser.y"
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3139 "parser.c"
    break;

  case 8:
#line 105 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3145 "parser.c"
    break;

  case 9:
#line 106 "../src/parser.y"
    { (yyval.e) = push(push((yyvsp[-2].e), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3151 "parser.c"
    break;

  case 12:
#line 109 "../src/parser.y"
    { (yyval.e) = (yyvsp[-1].e); }
#line 3157 "parser.c"
    break;

  case 13:
#line 110 "../src/parser.y"
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3163 "parser.c"
    break;

  case 14:
#line 111 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3169 "parser.c"
    break;

  case 15:
#line 112 "../src/parser.y"
    { (yyval.e) = (yyvsp[-1].e); }
#line 3175 "parser.c"
    break;

  case 16:
#line 113 "../src/parser.y"
    { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3181 "parser.c"
    break;

  case 17:
#line 114 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3187 "parser.c"
    break;

  case 18:
#line 115 "../src/parser.y"
    { (yyval.e) = (yyvsp[-1].e); }
#line 3193 "parser.c"
    break;

  case 19:
#line 116 "../src/parser.y"
    { (yyval.e) = (yyvsp[-1].e); }
#line 3199 "parser.c"
    break;

  case 20:
#line 117 "../src/parser.y"
    { (yyval.e) = push((yyvsp[-2].e), (yyvsp[-1].e)); }
#line 3205 "parser.c"
    break;

  case 21:
#line 118 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3211 "parser.c"
    break;

  case 22:
#line 119 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3217 "parser.c"
    break;

  case 23:
#line 120 "../src/parser.y"
    { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3223 "parser.c"
    break;

  case 24:
#line 121 "../src/parser.y"
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3229 "parser.c"
    break;

  case 25:
#line 122 "../src/parser.y"
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3235 "parser.c"
    break;

  case 26:
#line 123 "../src/parser.y"
    { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3241 "parser.c"
    break;

  case 27:
#line 124 "../src/parser.y"
    { (yyval.e) = new_string((yyvsp[0].s)); }
#line 3247 "parser.c"
    break;

  case 28:
#line 125 "../src/parser.y"
    { (yyval.e) = new_symref((yyvsp[0].s), LINE); }
#line 3253 "parser.c"
    break;

  case 29:
#line 126 "../src/parser.y"
    { (yyval.e) = NULL; YYFPRINTF(stderr, "Out of memory in line %d\n", LINE); YYABORT; }
#line 3259 "parser.c"
    break;

  case 30:
#line 127 "../src/parser.y"
    { (yyval.e) = push(push((yyvsp[-2].e), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)) ; }
#line 3265 "parser.c"
    break;

  case 31:
#line 128 "../src/parser.y"
    { (yyval.e) = push(push(new_contxt(), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)); }
#line 3271 "parser.c"
    break;

  case 32:
#line 129 "../src/parser.y"
    { (yyval.e) = push((yyvsp[-1].e), new_symbol((yyvsp[0].s))); }
#line 3277 "parser.c"
    break;

  case 33:
#line 130 "../src/parser.y"
    { (yyval.e) = push(new_contxt(), new_symbol((yyvsp[0].s))); }
#line 3283 "parser.c"
    break;

  case 34:
#line 131 "../src/parser.y"
    { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3289 "parser.c"
    break;

  case 35:
#line 132 "../src/parser.y"
    { (yyval.e) = push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3295 "parser.c"
    break;

  case 171:
#line 274 "../src/parser.y"
    { (yyval.e) = new_native(strdup("+"), LINE, m_add, (yyvsp[-1].e), NUMBER); }
#line 3301 "parser.c"
    break;

  case 172:
#line 275 "../src/parser.y"
    { (yyval.e) = new_native(strdup("/"), LINE, m_div, (yyvsp[-1].e), NUMBER); }
#line 3307 "parser.c"
    break;

  case 173:
#line 276 "../src/parser.y"
    { (yyval.e) = new_native(strdup("*"), LINE, m_mul, (yyvsp[-1].e), NUMBER); }
#line 3313 "parser.c"
    break;

  case 174:
#line 277 "../src/parser.y"
    { (yyval.e) = new_native(strdup("-"), LINE, m_sub, (yyvsp[-1].e), NUMBER); }
#line 3319 "parser.c"
    break;

  case 175:
#line 280 "../src/parser.y"
    { (yyval.e) = new_native(strdup("="), LINE, m_eq, (yyvsp[-1].e), NUMBER); }
#line 3325 "parser.c"
    break;

  case 176:
#line 281 "../src/parser.y"
    { (yyval.e) = new_native(strdup(">"), LINE, m_gt, (yyvsp[-1].e), NUMBER); }
#line 3331 "parser.c"
    break;

  case 177:
#line 282 "../src/parser.y"
    { (yyval.e) = new_native(strdup(">="), LINE, m_gte, (yyvsp[-1].e), NUMBER); }
#line 3337 "parser.c"
    break;

  case 178:
#line 283 "../src/parser.y"
    { (yyval.e) = new_native(strdup("<"), LINE, m_lt, (yyvsp[-1].e), NUMBER); }
#line 3343 "parser.c"
    break;

  case 179:
#line 284 "../src/parser.y"
    { (yyval.e) = new_native(strdup("<="), LINE, m_lte, (yyvsp[-1].e), NUMBER); }
#line 3349 "parser.c"
    break;

  case 180:
#line 285 "../src/parser.y"
    { (yyval.e) = new_native(strdup("<>"), LINE, m_neq, (yyvsp[-1].e), NUMBER); }
#line 3355 "parser.c"
    break;

  case 181:
#line 288 "../src/parser.y"
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3361 "parser.c"
    break;

  case 182:
#line 289 "../src/parser.y"
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3367 "parser.c"
    break;

  case 183:
#line 290 "../src/parser.y"
    { (yyval.e) = new_native(strdup("if"), LINE, m_if, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3373 "parser.c"
    break;

  case 184:
#line 291 "../src/parser.y"
    { (yyval.e) = new_native(strdup("select"), LINE, m_select, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3379 "parser.c"
    break;

  case 185:
#line 292 "../src/parser.y"
    { (yyval.e) = new_native(strdup("until"), LINE, m_until, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3385 "parser.c"
    break;

  case 186:
#line 293 "../src/parser.y"
    { (yyval.e) = new_native(strdup("while"), LINE, m_while, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3391 "parser.c"
    break;

  case 187:
#line 294 "../src/parser.y"
    { (yyval.e) = new_native(strdup("trace"), LINE, m_trace, NULL, NUMBER); }
#line 3397 "parser.c"
    break;

  case 188:
#line 295 "../src/parser.y"
    { (yyval.e) = new_native(strdup("retrace"), LINE, m_retrace, NULL, NUMBER); }
#line 3403 "parser.c"
    break;

  case 189:
#line 298 "../src/parser.y"
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3409 "parser.c"
    break;

  case 190:
#line 299 "../src/parser.y"
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3415 "parser.c"
    break;

  case 191:
#line 300 "../src/parser.y"
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3421 "parser.c"
    break;

  case 192:
#line 301 "../src/parser.y"
    { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, (yyvsp[-1].e), NUMBER); }
#line 3427 "parser.c"
    break;

  case 193:
#line 302 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3433 "parser.c"
    break;

  case 194:
#line 303 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3439 "parser.c"
    break;

  case 195:
#line 304 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3445 "parser.c"
    break;

  case 196:
#line 305 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, (yyvsp[-1].e), NUMBER); }
#line 3451 "parser.c"
    break;

  case 197:
#line 306 "../src/parser.y"
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3457 "parser.c"
    break;

  case 198:
#line 307 "../src/parser.y"
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3463 "parser.c"
    break;

  case 199:
#line 308 "../src/parser.y"
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3469 "parser.c"
    break;

  case 200:
#line 309 "../src/parser.y"
    { (yyval.e) = new_native(strdup("run"), LINE, m_run, (yyvsp[-1].e), NUMBER); }
#line 3475 "parser.c"
    break;

  case 201:
#line 312 "../src/parser.y"
    { (yyval.e) = new_native(strdup("abort"), LINE, m_abort, (yyvsp[-1].e), NUMBER); }
#line 3481 "parser.c"
    break;

  case 202:
#line 313 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3487 "parser.c"
    break;

  case 203:
#line 314 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3493 "parser.c"
    break;

  case 204:
#line 315 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3499 "parser.c"
    break;

  case 205:
#line 316 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, (yyvsp[-1].e), NUMBER); }
#line 3505 "parser.c"
    break;

  case 206:
#line 317 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, NULL, NUMBER); }
#line 3511 "parser.c"
    break;

  case 207:
#line 318 "../src/parser.y"
    { (yyval.e) = new_native(strdup("onerror"), LINE, m_procedure, push(new_contxt(),
                                                        new_custom(strdup("@onerror"), LINE, NULL, (yyvsp[-1].e))), DANGLE); }
#line 3518 "parser.c"
    break;

  case 208:
#line 320 "../src/parser.y"
    { (yyval.e) = new_native(strdup("reboot"), LINE, m_reboot, NULL, NUMBER); }
#line 3524 "parser.c"
    break;

  case 209:
#line 321 "../src/parser.y"
    { (yyval.e) = new_native(strdup("trap"), LINE, m_trap, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3530 "parser.c"
    break;

  case 210:
#line 324 "../src/parser.y"
    { (yyval.e) = new_native(strdup("copyfiles"), LINE, m_copyfiles, (yyvsp[-1].e), NUMBER); }
#line 3536 "parser.c"
    break;

  case 211:
#line 325 "../src/parser.y"
    { (yyval.e) = new_native(strdup("copylib"), LINE, m_copylib, (yyvsp[-1].e), NUMBER); }
#line 3542 "parser.c"
    break;

  case 212:
#line 326 "../src/parser.y"
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3548 "parser.c"
    break;

  case 213:
#line 327 "../src/parser.y"
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3554 "parser.c"
    break;

  case 214:
#line 328 "../src/parser.y"
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3560 "parser.c"
    break;

  case 215:
#line 329 "../src/parser.y"
    { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3566 "parser.c"
    break;

  case 216:
#line 330 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3572 "parser.c"
    break;

  case 217:
#line 331 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3578 "parser.c"
    break;

  case 218:
#line 332 "../src/parser.y"
    { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3584 "parser.c"
    break;

  case 219:
#line 333 "../src/parser.y"
    { (yyval.e) = new_native(strdup("fileonly"), LINE, m_fileonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3590 "parser.c"
    break;

  case 220:
#line 334 "../src/parser.y"
    { (yyval.e) = new_native(strdup("foreach"), LINE, m_foreach, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3596 "parser.c"
    break;

  case 221:
#line 335 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3602 "parser.c"
    break;

  case 222:
#line 336 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, (yyvsp[-1].e), NUMBER); }
#line 3608 "parser.c"
    break;

  case 223:
#line 337 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3614 "parser.c"
    break;

  case 224:
#line 338 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3620 "parser.c"
    break;

  case 225:
#line 339 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3626 "parser.c"
    break;

  case 226:
#line 340 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3632 "parser.c"
    break;

  case 227:
#line 341 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3638 "parser.c"
    break;

  case 228:
#line 342 "../src/parser.y"
    { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3644 "parser.c"
    break;

  case 229:
#line 343 "../src/parser.y"
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3650 "parser.c"
    break;

  case 230:
#line 344 "../src/parser.y"
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, (yyvsp[-1].e), NUMBER); }
#line 3656 "parser.c"
    break;

  case 231:
#line 345 "../src/parser.y"
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3662 "parser.c"
    break;

  case 232:
#line 346 "../src/parser.y"
    { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3668 "parser.c"
    break;

  case 233:
#line 347 "../src/parser.y"
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3674 "parser.c"
    break;

  case 234:
#line 348 "../src/parser.y"
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3680 "parser.c"
    break;

  case 235:
#line 349 "../src/parser.y"
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3686 "parser.c"
    break;

  case 236:
#line 350 "../src/parser.y"
    { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), new_symref(strdup("@app-name"), LINE)), (yyvsp[-1].e)), NUMBER); }
#line 3692 "parser.c"
    break;

  case 237:
#line 351 "../src/parser.y"
    { (yyval.e) = new_native(strdup("textfile"), LINE, m_textfile, (yyvsp[-1].e), NUMBER); }
#line 3698 "parser.c"
    break;

  case 238:
#line 352 "../src/parser.y"
    { (yyval.e) = new_native(strdup("tooltype"), LINE, m_tooltype, (yyvsp[-1].e), NUMBER); }
#line 3704 "parser.c"
    break;

  case 239:
#line 353 "../src/parser.y"
    { (yyval.e) = new_native(strdup("transcript"), LINE, m_transcript, (yyvsp[-1].e), NUMBER); }
#line 3710 "parser.c"
    break;

  case 240:
#line 354 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3716 "parser.c"
    break;

  case 241:
#line 355 "../src/parser.y"
    { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, (yyvsp[-1].e), NUMBER); }
#line 3722 "parser.c"
    break;

  case 242:
#line 358 "../src/parser.y"
    { (yyval.e) = new_native(strdup("complete"), LINE, m_complete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3728 "parser.c"
    break;

  case 243:
#line 359 "../src/parser.y"
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, (yyvsp[-1].e), NUMBER); }
#line 3734 "parser.c"
    break;

  case 244:
#line 360 "../src/parser.y"
    { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, NULL, NUMBER); }
#line 3740 "parser.c"
    break;

  case 245:
#line 361 "../src/parser.y"
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, merge((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3746 "parser.c"
    break;

  case 246:
#line 362 "../src/parser.y"
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3752 "parser.c"
    break;

  case 247:
#line 363 "../src/parser.y"
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, push(merge((yyvsp[-3].e), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3758 "parser.c"
    break;

  case 248:
#line 364 "../src/parser.y"
    { (yyval.e) = new_native(strdup("message"), LINE, m_message, (yyvsp[-1].e), NUMBER); }
#line 3764 "parser.c"
    break;

  case 249:
#line 365 "../src/parser.y"
    { (yyval.e) = new_native(strdup("user"), LINE, m_user, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3770 "parser.c"
    break;

  case 250:
#line 366 "../src/parser.y"
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, (yyvsp[-1].e), NUMBER); }
#line 3776 "parser.c"
    break;

  case 251:
#line 367 "../src/parser.y"
    { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, NULL, NUMBER); }
#line 3782 "parser.c"
    break;

  case 252:
#line 368 "../src/parser.y"
    { (yyval.e) = new_native(strdup("working"), LINE, m_working, (yyvsp[-1].e), NUMBER); }
#line 3788 "parser.c"
    break;

  case 253:
#line 371 "../src/parser.y"
    { (yyval.e) = new_native(strdup("AND"), LINE, m_and, (yyvsp[-1].e), NUMBER); }
#line 3794 "parser.c"
    break;

  case 254:
#line 372 "../src/parser.y"
    { (yyval.e) = new_native(strdup("BITAND"), LINE, m_bitand, (yyvsp[-1].e), NUMBER); }
#line 3800 "parser.c"
    break;

  case 255:
#line 373 "../src/parser.y"
    { (yyval.e) = new_native(strdup("BITNOT"), LINE, m_bitnot, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3806 "parser.c"
    break;

  case 256:
#line 374 "../src/parser.y"
    { (yyval.e) = new_native(strdup("BITOR"), LINE, m_bitor, (yyvsp[-1].e), NUMBER); }
#line 3812 "parser.c"
    break;

  case 257:
#line 375 "../src/parser.y"
    { (yyval.e) = new_native(strdup("BITXOR"), LINE, m_bitxor, (yyvsp[-1].e), NUMBER); }
#line 3818 "parser.c"
    break;

  case 258:
#line 376 "../src/parser.y"
    { (yyval.e) = new_native(strdup("NOT"), LINE, m_not, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3824 "parser.c"
    break;

  case 259:
#line 377 "../src/parser.y"
    { (yyval.e) = new_native(strdup("IN"), LINE, m_in, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3830 "parser.c"
    break;

  case 260:
#line 378 "../src/parser.y"
    { (yyval.e) = new_native(strdup("OR"), LINE, m_or, (yyvsp[-1].e), NUMBER); }
#line 3836 "parser.c"
    break;

  case 261:
#line 379 "../src/parser.y"
    { (yyval.e) = new_native(strdup("shiftleft"), LINE, m_shiftleft, (yyvsp[-1].e), NUMBER); }
#line 3842 "parser.c"
    break;

  case 262:
#line 380 "../src/parser.y"
    { (yyval.e) = new_native(strdup("shiftright"), LINE, m_shiftright, (yyvsp[-1].e), NUMBER); }
#line 3848 "parser.c"
    break;

  case 263:
#line 381 "../src/parser.y"
    { (yyval.e) = new_native(strdup("XOR"), LINE, m_xor, (yyvsp[-1].e), NUMBER); }
#line 3854 "parser.c"
    break;

  case 264:
#line 384 "../src/parser.y"
    { (yyval.e) = new_native(strdup("closemedia"), LINE, m_closemedia, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3860 "parser.c"
    break;

  case 265:
#line 385 "../src/parser.y"
    { (yyval.e) = new_native(strdup("effect"), LINE, m_effect, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3866 "parser.c"
    break;

  case 266:
#line 386 "../src/parser.y"
    { (yyval.e) = new_native(strdup("setmedia"), LINE, m_setmedia, (yyvsp[-1].e), NUMBER); }
#line 3872 "parser.c"
    break;

  case 267:
#line 387 "../src/parser.y"
    { (yyval.e) = new_native(strdup("setmedia"), LINE, m_setmedia, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3878 "parser.c"
    break;

  case 268:
#line 388 "../src/parser.y"
    { (yyval.e) = new_native(strdup("showmedia"), LINE, m_showmedia, merge(merge((yyvsp[-3].e), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3884 "parser.c"
    break;

  case 269:
#line 391 "../src/parser.y"
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3890 "parser.c"
    break;

  case 270:
#line 392 "../src/parser.y"
    { (yyval.e) = new_native(strdup("database"), LINE, m_database, (yyvsp[-1].e), STRING); }
#line 3896 "parser.c"
    break;

  case 271:
#line 393 "../src/parser.y"
    { (yyval.e) = new_native(strdup("earlier"), LINE, m_earlier, (yyvsp[-1].e), NUMBER); }
#line 3902 "parser.c"
    break;

  case 272:
#line 394 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3908 "parser.c"
    break;

  case 273:
#line 395 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, (yyvsp[-1].e), STRING); }
#line 3914 "parser.c"
    break;

  case 274:
#line 396 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getdevice"), LINE, m_getdevice, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3920 "parser.c"
    break;

  case 275:
#line 397 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3926 "parser.c"
    break;

  case 276:
#line 398 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, (yyvsp[-1].e), NUMBER); }
#line 3932 "parser.c"
    break;

  case 277:
#line 399 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getenv"), LINE, m_getenv, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3938 "parser.c"
    break;

  case 278:
#line 400 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getsize"), LINE, m_getsize, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3944 "parser.c"
    break;

  case 279:
#line 401 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getsum"), LINE, m_getsum, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3950 "parser.c"
    break;

  case 280:
#line 402 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, NULL, NUMBER); }
#line 3956 "parser.c"
    break;

  case 281:
#line 403 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3962 "parser.c"
    break;

  case 282:
#line 404 "../src/parser.y"
    { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3968 "parser.c"
    break;

  case 283:
#line 405 "../src/parser.y"
    { (yyval.e) = new_native(strdup("iconinfo"), LINE, m_iconinfo, (yyvsp[-1].e), NUMBER); }
#line 3974 "parser.c"
    break;

  case 284:
#line 406 "../src/parser.y"
    { (yyval.e) = new_native(strdup("querydisplay"), LINE, m_querydisplay, (yyvsp[-1].e), NUMBER); }
#line 3980 "parser.c"
    break;

  case 285:
#line 409 "../src/parser.y"
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-3].s), LINE, (yyvsp[-2].e), (yyvsp[-1].e))), NUMBER); }
#line 3986 "parser.c"
    break;

  case 286:
#line 410 "../src/parser.y"
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, (yyvsp[-1].e), NULL)), NUMBER); }
#line 3992 "parser.c"
    break;

  case 287:
#line 411 "../src/parser.y"
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, NULL, (yyvsp[-1].e))), NUMBER); }
#line 3998 "parser.c"
    break;

  case 288:
#line 412 "../src/parser.y"
    { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-1].s), LINE, NULL, NULL)), NUMBER); }
#line 4004 "parser.c"
    break;

  case 289:
#line 413 "../src/parser.y"
    { (yyval.e) = new_cusref((yyvsp[-2].s), LINE, (yyvsp[-1].e)); }
#line 4010 "parser.c"
    break;

  case 290:
#line 414 "../src/parser.y"
    { (yyval.e) = new_cusref((yyvsp[-1].s), LINE, NULL); }
#line 4016 "parser.c"
    break;

  case 291:
#line 417 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, NULL, NUMBER); }
#line 4022 "parser.c"
    break;

  case 292:
#line 418 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, (yyvsp[-1].e), NUMBER); }
#line 4028 "parser.c"
    break;

  case 293:
#line 419 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askchoice"), LINE, m_askchoice, (yyvsp[-1].e), NUMBER); }
#line 4034 "parser.c"
    break;

  case 294:
#line 420 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, NULL, STRING); }
#line 4040 "parser.c"
    break;

  case 295:
#line 421 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, (yyvsp[-1].e), STRING); }
#line 4046 "parser.c"
    break;

  case 296:
#line 422 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askdisk"), LINE, m_askdisk, (yyvsp[-1].e), NUMBER); }
#line 4052 "parser.c"
    break;

  case 297:
#line 423 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, NULL, STRING); }
#line 4058 "parser.c"
    break;

  case 298:
#line 424 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, (yyvsp[-1].e), STRING); }
#line 4064 "parser.c"
    break;

  case 299:
#line 425 "../src/parser.y"
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, NULL, NUMBER); }
#line 4070 "parser.c"
    break;

  case 300:
#line 426 "../src/parser.y"
    { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, (yyvsp[-1].e), NUMBER); }
#line 4076 "parser.c"
    break;

  case 301:
#line 427 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askoptions"), LINE, m_askoptions, (yyvsp[-1].e), NUMBER); }
#line 4082 "parser.c"
    break;

  case 302:
#line 428 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, NULL, STRING); }
#line 4088 "parser.c"
    break;

  case 303:
#line 429 "../src/parser.y"
    { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, (yyvsp[-1].e), STRING); }
#line 4094 "parser.c"
    break;

  case 304:
#line 432 "../src/parser.y"
    { (yyval.e) = new_native(strdup("cat"), LINE, m_cat, (yyvsp[-1].e), STRING); }
#line 4100 "parser.c"
    break;

  case 305:
#line 433 "../src/parser.y"
    { (yyval.e) = new_native(strdup("expandpath"), LINE, m_expandpath, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4106 "parser.c"
    break;

  case 306:
#line 434 "../src/parser.y"
    { (yyval.e) = new_native((yyvsp[-2].s), LINE, m_fmt, (yyvsp[-1].e), STRING); }
#line 4112 "parser.c"
    break;

  case 307:
#line 435 "../src/parser.y"
    { (yyval.e) = new_native((yyvsp[-1].s), LINE, m_fmt, NULL, STRING); }
#line 4118 "parser.c"
    break;

  case 308:
#line 436 "../src/parser.y"
    { (yyval.e) = new_native(strdup("pathonly"), LINE, m_pathonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4124 "parser.c"
    break;

  case 309:
#line 437 "../src/parser.y"
    { (yyval.e) = new_native(strdup("patmatch"), LINE, m_patmatch, (yyvsp[-1].e), NUMBER); }
#line 4130 "parser.c"
    break;

  case 310:
#line 438 "../src/parser.y"
    { (yyval.e) = new_native(strdup("strlen"), LINE, m_strlen, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4136 "parser.c"
    break;

  case 311:
#line 439 "../src/parser.y"
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, (yyvsp[-1].e), STRING); }
#line 4142 "parser.c"
    break;

  case 312:
#line 440 "../src/parser.y"
    { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, push((yyvsp[-2].e), (yyvsp[-1].e)), STRING); }
#line 4148 "parser.c"
    break;

  case 313:
#line 441 "../src/parser.y"
    { (yyval.e) = new_native(strdup("tackon"), LINE, m_tackon, (yyvsp[-1].e), STRING); }
#line 4154 "parser.c"
    break;

  case 314:
#line 444 "../src/parser.y"
    { (yyval.e) = new_native(strdup("set"), LINE, m_set, (yyvsp[-1].e), DANGLE); }
#line 4160 "parser.c"
    break;

  case 315:
#line 445 "../src/parser.y"
    { (yyval.e) = new_native(strdup("symbolset"), LINE, m_symbolset, (yyvsp[-1].e), DANGLE); }
#line 4166 "parser.c"
    break;

  case 316:
#line 446 "../src/parser.y"
    { (yyval.e) = new_native(strdup("symbolval"), LINE, m_symbolval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4172 "parser.c"
    break;

  case 317:
#line 449 "../src/parser.y"
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4178 "parser.c"
    break;

  case 318:
#line 450 "../src/parser.y"
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4184 "parser.c"
    break;

  case 319:
#line 451 "../src/parser.y"
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4190 "parser.c"
    break;

  case 320:
#line 452 "../src/parser.y"
    { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4196 "parser.c"
    break;

  case 321:
#line 453 "../src/parser.y"
    { (yyval.e) = new_native(strdup("showwbobject"), LINE, m_showwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4202 "parser.c"
    break;

  case 322:
#line 454 "../src/parser.y"
    { (yyval.e) = new_native(strdup("closewbobject"), LINE, m_closewbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4208 "parser.c"
    break;

  case 323:
#line 457 "../src/parser.y"
    { (yyval.e) = new_option(strdup("all"), OPT_ALL, NULL); }
#line 4214 "parser.c"
    break;

  case 324:
#line 458 "../src/parser.y"
    { (yyval.e) = new_option(strdup("append"), OPT_APPEND, (yyvsp[-1].e)); }
#line 4220 "parser.c"
    break;

  case 325:
#line 459 "../src/parser.y"
    { (yyval.e) = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); }
#line 4226 "parser.c"
    break;

  case 326:
#line 460 "../src/parser.y"
    { (yyval.e) = new_option(strdup("back"), OPT_BACK, (yyvsp[-1].e)); }
#line 4232 "parser.c"
    break;

  case 327:
#line 461 "../src/parser.y"
    { (yyval.e) = new_option(strdup("choices"), OPT_CHOICES, (yyvsp[-1].e)); }
#line 4238 "parser.c"
    break;

  case 328:
#line 462 "../src/parser.y"
    { (yyval.e) = new_option(strdup("command"), OPT_COMMAND, (yyvsp[-1].e)); }
#line 4244 "parser.c"
    break;

  case 329:
#line 463 "../src/parser.y"
    { (yyval.e) = new_option(strdup("compression"), OPT_COMPRESSION, NULL); }
#line 4250 "parser.c"
    break;

  case 330:
#line 464 "../src/parser.y"
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, push(new_contxt(), (yyvsp[-1].e))); }
#line 4256 "parser.c"
    break;

  case 331:
#line 465 "../src/parser.y"
    { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, NULL); }
#line 4262 "parser.c"
    break;

  case 332:
#line 466 "../src/parser.y"
    { (yyval.e) = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), (yyvsp[-1].e))); }
#line 4268 "parser.c"
    break;

  case 333:
#line 467 "../src/parser.y"
    { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, (yyvsp[-1].e)); }
#line 4274 "parser.c"
    break;

  case 334:
#line 468 "../src/parser.y"
    { (yyval.e) = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), (yyvsp[-1].e))); }
#line 4280 "parser.c"
    break;

  case 335:
#line 469 "../src/parser.y"
    { (yyval.e) = new_option(strdup("disk"), OPT_DISK, NULL); }
#line 4286 "parser.c"
    break;

  case 336:
#line 470 "../src/parser.y"
    { (yyval.e) = new_option(strdup("files"), OPT_FILES, NULL); }
#line 4292 "parser.c"
    break;

  case 337:
#line 471 "../src/parser.y"
    { (yyval.e) = new_option(strdup("fonts"), OPT_FONTS, NULL); }
#line 4298 "parser.c"
    break;

  case 338:
#line 472 "../src/parser.y"
    { (yyval.e) = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4304 "parser.c"
    break;

  case 339:
#line 473 "../src/parser.y"
    { (yyval.e) = new_option(strdup("getposition"), OPT_GETPOSITION, (yyvsp[-1].e)); }
#line 4310 "parser.c"
    break;

  case 340:
#line 474 "../src/parser.y"
    { (yyval.e) = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4316 "parser.c"
    break;

  case 341:
#line 475 "../src/parser.y"
    { (yyval.e) = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, (yyvsp[-1].e)); }
#line 4322 "parser.c"
    break;

  case 342:
#line 476 "../src/parser.y"
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, (yyvsp[-1].e)); }
#line 4328 "parser.c"
    break;

  case 343:
#line 477 "../src/parser.y"
    { (yyval.e) = new_option(strdup("help"), OPT_HELP, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4334 "parser.c"
    break;

  case 344:
#line 478 "../src/parser.y"
    { (yyval.e) = new_option(strdup("infos"), OPT_INFOS, NULL); }
#line 4340 "parser.c"
    break;

  case 345:
#line 479 "../src/parser.y"
    { (yyval.e) = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4346 "parser.c"
    break;

  case 346:
#line 480 "../src/parser.y"
    { (yyval.e) = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), (yyvsp[-1].e))); }
#line 4352 "parser.c"
    break;

  case 347:
#line 481 "../src/parser.y"
    { (yyval.e) = new_option(strdup("newpath"), OPT_NEWPATH, NULL); }
#line 4358 "parser.c"
    break;

  case 348:
#line 482 "../src/parser.y"
    { (yyval.e) = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); }
#line 4364 "parser.c"
    break;

  case 349:
#line 483 "../src/parser.y"
    { (yyval.e) = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); }
#line 4370 "parser.c"
    break;

  case 350:
#line 484 "../src/parser.y"
    { (yyval.e) = new_option(strdup("noreq"), OPT_NOREQ, NULL); }
#line 4376 "parser.c"
    break;

  case 351:
#line 485 "../src/parser.y"
    { (yyval.e) = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), (yyvsp[-1].e))); }
#line 4382 "parser.c"
    break;

  case 352:
#line 486 "../src/parser.y"
    { (yyval.e) = new_option(strdup("prompt"), OPT_PROMPT, (yyvsp[-1].e)); }
#line 4388 "parser.c"
    break;

  case 353:
#line 487 "../src/parser.y"
    { (yyval.e) = new_option(strdup("quiet"), OPT_QUIET, NULL); }
#line 4394 "parser.c"
    break;

  case 354:
#line 488 "../src/parser.y"
    { (yyval.e) = new_option(strdup("range"), OPT_RANGE, (yyvsp[-1].e)); }
#line 4400 "parser.c"
    break;

  case 355:
#line 489 "../src/parser.y"
    { (yyval.e) = new_option(strdup("safe"), OPT_SAFE, NULL); }
#line 4406 "parser.c"
    break;

  case 356:
#line 490 "../src/parser.y"
    { (yyval.e) = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4412 "parser.c"
    break;

  case 357:
#line 491 "../src/parser.y"
    { (yyval.e) = new_option(strdup("setposition"), OPT_SETPOSITION, (yyvsp[-1].e)); }
#line 4418 "parser.c"
    break;

  case 358:
#line 492 "../src/parser.y"
    { (yyval.e) = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4424 "parser.c"
    break;

  case 359:
#line 493 "../src/parser.y"
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, (yyvsp[-1].e)); }
#line 4430 "parser.c"
    break;

  case 360:
#line 494 "../src/parser.y"
    { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4436 "parser.c"
    break;

  case 361:
#line 495 "../src/parser.y"
    { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4442 "parser.c"
    break;

  case 362:
#line 496 "../src/parser.y"
    { (yyval.e) = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); }
#line 4448 "parser.c"
    break;

  case 363:
#line 497 "../src/parser.y"
    { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, (yyvsp[-1].e)); }
#line 4454 "parser.c"
    break;

  case 364:
#line 498 "../src/parser.y"
    { (yyval.e) = new_option(strdup("resident"), OPT_RESIDENT, NULL); }
#line 4460 "parser.c"
    break;

  case 365:
#line 499 "../src/parser.y"
    { (yyval.e) = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4466 "parser.c"
    break;

  case 366:
#line 500 "../src/parser.y"
    { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4472 "parser.c"
    break;

  case 367:
#line 501 "../src/parser.y"
    { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(push(new_contxt(), (yyvsp[-3].e)), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4478 "parser.c"
    break;


#line 4482 "parser.c"

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
#line 503 "../src/parser.y"

