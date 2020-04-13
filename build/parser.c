/* A Bison parser, made by GNU Bison 3.5.  */

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
#define YYBISON_VERSION "3.5"

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

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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
    ASTRAW = 276,
    ASBRAW = 277,
    ASBEVAL = 278,
    EVAL = 279,
    OPTIONS = 280,
    EXECUTE = 281,
    REXX = 282,
    RUN = 283,
    ABORT = 284,
    EXIT = 285,
    ONERROR = 286,
    TRAP = 287,
    REBOOT = 288,
    COPYFILES = 289,
    COPYLIB = 290,
    DELETE = 291,
    EXISTS = 292,
    FILEONLY = 293,
    FOREACH = 294,
    MAKEASSIGN = 295,
    MAKEDIR = 296,
    PROTECT = 297,
    STARTUP = 298,
    TEXTFILE = 299,
    TOOLTYPE = 300,
    TRANSCRIPT = 301,
    RENAME = 302,
    COMPLETE = 303,
    DEBUG = 304,
    MESSAGE = 305,
    USER = 306,
    WELCOME = 307,
    WORKING = 308,
    AND = 309,
    BITAND = 310,
    BITNOT = 311,
    BITOR = 312,
    BITXOR = 313,
    NOT = 314,
    IN = 315,
    OR = 316,
    SHIFTLEFT = 317,
    SHIFTRIGHT = 318,
    XOR = 319,
    CLOSEMEDIA = 320,
    EFFECT = 321,
    SETMEDIA = 322,
    SHOWMEDIA = 323,
    DATABASE = 324,
    EARLIER = 325,
    GETASSIGN = 326,
    GETDEVICE = 327,
    GETDISKSPACE = 328,
    GETENV = 329,
    GETSIZE = 330,
    GETSUM = 331,
    GETVERSION = 332,
    ICONINFO = 333,
    QUERYDISPLAY = 334,
    CUS = 335,
    DCL = 336,
    ASKBOOL = 337,
    ASKCHOICE = 338,
    ASKDIR = 339,
    ASKDISK = 340,
    ASKFILE = 341,
    ASKNUMBER = 342,
    ASKOPTIONS = 343,
    ASKSTRING = 344,
    CAT = 345,
    EXPANDPATH = 346,
    FMT = 347,
    PATHONLY = 348,
    PATMATCH = 349,
    STRLEN = 350,
    SUBSTR = 351,
    TACKON = 352,
    SET = 353,
    SYMBOLSET = 354,
    SYMBOLVAL = 355,
    OPENWBOBJECT = 356,
    SHOWWBOBJECT = 357,
    CLOSEWBOBJECT = 358,
    ALL = 359,
    APPEND = 360,
    ASSIGNS = 361,
    BACK = 362,
    CHOICES = 363,
    COMMAND = 364,
    COMPRESSION = 365,
    CONFIRM = 366,
    DEFAULT = 367,
    DELOPTS = 368,
    DEST = 369,
    DISK = 370,
    FILES = 371,
    FONTS = 372,
    GETDEFAULTTOOL = 373,
    GETPOSITION = 374,
    GETSTACK = 375,
    GETTOOLTYPE = 376,
    HELP = 377,
    INFOS = 378,
    INCLUDE = 379,
    NEWNAME = 380,
    NEWPATH = 381,
    NOGAUGE = 382,
    NOPOSITION = 383,
    NOREQ = 384,
    PATTERN = 385,
    PROMPT = 386,
    QUIET = 387,
    RANGE = 388,
    SAFE = 389,
    SETDEFAULTTOOL = 390,
    SETPOSITION = 391,
    SETSTACK = 392,
    SETTOOLTYPE = 393,
    SOURCE = 394,
    SWAPCOLORS = 395,
    OPTIONAL = 396,
    RESIDENT = 397,
    OVERRIDE = 398
  };
#endif

/* Value type.  */



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_PARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
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
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  291
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2374

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  153
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  159
/* YYNRULES -- Number of rules.  */
#define YYNRULES  383
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  739

#define YYUNDEFTOK  2
#define YYMAXUTOK   398


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     144,   145,   148,   146,     2,   149,     2,   147,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     152,   150,   151,     2,     2,     2,     2,     2,     2,     2,
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
     135,   136,   137,   138,   139,   140,   141,   142,   143
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    88,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   275,   276,
     277,   278,   282,   283,   284,   285,   286,   287,   291,   292,
     293,   294,   295,   296,   297,   298,   302,   303,   304,   305,
     306,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   325,   326,   327,   328,   329,   330,   331,
     333,   334,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   402,   403,   404,
     405,   406,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   429,   430,
     431,   432,   433,   434,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   467,   468,   469,
     473,   474,   475,   476,   477,   478,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SYM", "STR", "OOM", "INT", "HEX", "BIN",
  "EQ", "GT", "GTE", "LT", "LTE", "NEQ", "IF", "SELECT", "UNTIL", "WHILE",
  "TRACE", "RETRACE", "ASTRAW", "ASBRAW", "ASBEVAL", "EVAL", "OPTIONS",
  "EXECUTE", "REXX", "RUN", "ABORT", "EXIT", "ONERROR", "TRAP", "REBOOT",
  "COPYFILES", "COPYLIB", "DELETE", "EXISTS", "FILEONLY", "FOREACH",
  "MAKEASSIGN", "MAKEDIR", "PROTECT", "STARTUP", "TEXTFILE", "TOOLTYPE",
  "TRANSCRIPT", "RENAME", "COMPLETE", "DEBUG", "MESSAGE", "USER",
  "WELCOME", "WORKING", "AND", "BITAND", "BITNOT", "BITOR", "BITXOR",
  "NOT", "IN", "OR", "SHIFTLEFT", "SHIFTRIGHT", "XOR", "CLOSEMEDIA",
  "EFFECT", "SETMEDIA", "SHOWMEDIA", "DATABASE", "EARLIER", "GETASSIGN",
  "GETDEVICE", "GETDISKSPACE", "GETENV", "GETSIZE", "GETSUM", "GETVERSION",
  "ICONINFO", "QUERYDISPLAY", "CUS", "DCL", "ASKBOOL", "ASKCHOICE",
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
  "add", "div", "mul", "sub", "eq", "gt", "gte", "lt", "lte", "neq", "if",
  "select", "until", "while", "trace", "retrace", "astraw", "asbraw",
  "asbeval", "eval", "options", "execute", "rexx", "run", "abort", "exit",
  "onerror", "reboot", "trap", "copyfiles", "copylib", "delete", "exists",
  "fileonly", "foreach", "makeassign", "makedir", "protect", "startup",
  "textfile", "tooltype", "transcript", "rename", "complete", "debug",
  "message", "user", "welcome", "working", "and", "bitand", "bitnot",
  "bitor", "bitxor", "not", "in", "or", "shiftleft", "shiftright", "xor",
  "closemedia", "effect", "setmedia", "showmedia", "database", "earlier",
  "getassign", "getdevice", "getdiskspace", "getenv", "getsize", "getsum",
  "getversion", "iconinfo", "querydisplay", "dcl", "cus", "askbool",
  "askchoice", "askdir", "askdisk", "askfile", "asknumber", "askoptions",
  "askstring", "cat", "expandpath", "fmt", "pathonly", "patmatch",
  "strlen", "substr", "tackon", "set", "symbolset", "symbolval",
  "openwbobject", "showwbobject", "closewbobject", "all", "append",
  "assigns", "back", "choices", "command", "compression", "confirm",
  "default", "delopts", "dest", "disk", "files", "fonts", "getdefaulttool",
  "getposition", "getstack", "gettooltype", "help", "infos", "include",
  "newname", "newpath", "nogauge", "noposition", "noreq", "pattern",
  "prompt", "quiet", "range", "safe", "setdefaulttool", "setposition",
  "setstack", "settooltype", "source", "swapcolors", "optional",
  "resident", "override", "dynopt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
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
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,    40,    41,    43,    47,    42,    45,
      61,    62,    60
};
# endif

#define YYPACT_NINF (-401)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -140,  1258,    12,  -401,  -401,  -140,  -140,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,    11,
      17,   904,   904,   904,   904,   904,   904,   904,  -108,   -92,
     -81,   904,   904,   904,   -68,   978,   978,   978,   904,    62,
    -140,   904,   -63,  -136,  -136,   978,   904,   904,   904,   904,
     978,   904,   978,  -136,  -136,   904,   904,   904,    68,   978,
     904,    89,    95,   904,   904,   904,   904,   904,   904,   904,
     904,   904,   904,   904,   904,   904,   904,   904,   904,   904,
     904,   904,   904,   904,   904,   904,   120,  -136,   904,   109,
    -118,  -136,  -110,  -136,  -105,  -101,  -136,   -99,   904,   904,
     904,   904,   904,   904,   904,   118,   904,   904,   978,   904,
     904,   -41,   904,    -5,  -140,   904,   904,     7,   129,   904,
     247,   904,     9,    27,    40,   904,   904,   904,   904,   254,
      43,   904,   904,    50,    52,    59,    63,   904,   904,    65,
     904,    71,   904,   904,   904,   904,   904,    83,   263,    87,
     904,   904,   904,   904,   904,   904,   904,   904,    92,   -95,
     -87,  -401,  -140,  -140,  -140,  -140,  -401,  -401,  -401,  -401,
    -401,  -401,  1858,  -401,  -401,   275,  -401,  -401,  -401,   293,
     904,   102,   104,   111,   300,   127,   132,  1194,  -140,  -140,
    -401,  -401,  -401,   139,   143,   146,  -401,  1408,   371,   978,
     379,   978,   418,   978,   426,  1558,  -401,   446,   452,   -85,
    -140,  -401,  2230,   -83,   -64,   458,   978,   -59,   157,  -140,
     464,   -57,   -55,   978,   470,   -38,  -136,   478,   -34,   -30,
     484,   -27,   168,  -401,   547,   633,   978,   170,  -401,   717,
    -401,   738,   786,   172,   184,   188,   190,   196,   904,   794,
     203,   208,   219,   221,   904,   815,   904,   891,   224,   250,
     898,   261,   271,   941,   291,   334,   348,   349,  -401,   -25,
     -15,   350,     4,  -401,    -6,    -2,  -401,    13,    15,  -401,
      19,  -401,    24,    32,  -401,    34,   960,   352,   353,   355,
     356,  1003,   357,  1194,     8,  -401,  1064,   359,    42,   978,
     360,   363,  -401,  1087,  -401,    46,  1103,  1668,  -401,  -401,
     364,   365,  -401,  1674,   366,  -401,  -401,  -401,   367,   372,
     374,   375,  -401,  1680,  -401,   377,   380,  -401,  -401,  -401,
    -401,   381,  1688,  -401,   382,  -401,   384,   385,   386,  1823,
     387,    55,  -401,  -401,  1831,  -401,   388,  1840,   390,  1974,
    1983,   391,   393,   394,  -401,  -401,  -401,   904,    92,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  1258,  -401,  -401,    58,
    1194,  -401,  -401,  2008,  -401,  1989,    70,    74,  -401,  -401,
    -401,    86,  -401,    91,  2109,  -136,  -401,    98,  2117,  -401,
     101,  2132,  -401,  -401,   396,  -401,  2138,  -401,   131,   904,
    -401,  -401,  -401,   142,  2158,   -96,  -401,   397,   398,  -401,
     165,  1708,  -401,   400,   412,  -401,   402,  -401,   167,   176,
    -401,   179,  -401,   181,   193,  -401,   199,  -401,  -401,  -401,
    -401,   202,  -401,  -401,  -401,   206,  2164,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  2170,  -401,  -401,  -401,
    -401,  -401,   403,  -401,   413,   904,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,     3,  -401,   414,
    -401,  -401,  -401,  -401,   415,     6,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
     416,  -401,  -401,  1194,  -401,  -401,  -401,  -401,  -401,   213,
     218,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,   159,  -401,   419,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  2176,  2182,
    -401,   244,  -401,  -401,  -401,  -401,  -401,  -401,  -401,   249,
    -401,  -401,   256,  -401,  -401,   259,  -401,  -401,  -401,  -136,
    -401,  -401,   265,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
     267,  -401,  -401,  -401,  -401,   270,  -401,  -401,  -401,   295,
    -401,  -401,  -401,  2188,  -401,  -401,  -401,  -401,   420,  -401,
    -401,  -401,  -401,   297,  -401,  -401,   422,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     2,    16,     3,     0,    19,    11,    79,
      80,    81,    82,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   118,   117,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   155,   154,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    58,    57,    59,
      60,    61,    62,    63,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    64,    78,    65,    77,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,     1,    13,    14,    15,    18,    30,    29,    31,    26,
      27,    28,     0,   303,     8,     0,     4,     5,   320,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,   195,   196,     0,     0,     0,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   218,     0,     0,     0,
       0,   220,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   256,     0,     0,     0,     0,   263,     0,
     265,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,     0,
       0,     0,     0,   304,     0,     0,   307,     0,     0,   310,
       0,   312,     0,     0,   315,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,   336,     0,   338,     0,     0,     0,   342,   344,
       0,     0,   347,     0,     0,   349,   350,   351,     0,     0,
       0,     0,   357,     0,   358,     0,     0,   361,   362,   363,
     364,     0,     0,   367,     0,   369,     0,     0,     0,     0,
       0,     0,   377,   379,     0,   380,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    17,    20,     0,     0,   302,
       7,   319,     6,   184,   186,   187,     0,   190,    23,     0,
      36,   189,   188,     0,    24,     0,     0,     0,   197,   198,
     199,     0,   204,     0,     0,    18,   208,     0,     0,   212,
       0,     0,   213,   217,     0,   216,     0,   219,     0,     0,
     222,   223,   227,     0,     0,     0,   228,     0,     0,   231,
       0,     0,   236,     0,     0,   234,     0,   240,     0,     0,
     244,     0,   242,     0,     0,   248,     0,   249,   250,   251,
     253,     0,   254,   255,   260,     0,     0,   261,   262,   264,
     266,   267,   268,   269,   270,   271,     0,   273,   274,   275,
     276,   277,     0,   279,     0,     0,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,     0,   294,     0,
     296,   297,    35,   301,     0,     0,   305,   306,   308,   309,
     311,   313,   314,   316,   317,   318,   321,   322,   323,   324,
       0,   326,    33,     0,   327,   328,     9,   329,   330,     0,
       0,   334,   335,   337,   339,   340,   341,   343,   345,   346,
     348,   352,   353,   354,   355,   356,   359,   360,   365,   366,
     368,   370,   371,   372,   374,   373,     0,   375,     0,   378,
     381,   178,   179,   180,   181,   182,   183,   185,     0,     0,
     382,     0,    37,   191,    25,   192,   193,   201,   202,     0,
     205,   206,     0,   209,   210,     0,   214,   215,   221,     0,
     224,   225,     0,   229,   230,   232,   235,   233,   237,   238,
       0,   243,   241,   245,   246,     0,   252,   257,   258,     0,
     272,   278,   280,     0,   295,   300,    34,   299,     0,   325,
      32,   331,   332,     0,   376,    21,     0,   383,   203,   207,
     211,   226,   239,   247,   259,   281,   298,   333,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -401,  -401,  -400,   500,   844,  -137,  -401,    78,    41,     0,
    -307,  -401,  -112,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,    97,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,  -401,
    -401,  -401,  -401,   222,  -401,  -401,  -166,  -401,    96,  -401,
    -401,  -401,  -401,  -401,  -401,  -401,   173,  -401,  -401
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   304,   311,   305,   426,   306,   292,   515,
     500,   505,   307,   424,   605,   315,   316,     7,     8,     9,
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
     140,   141,   142,   143,   144,   145,   146,   147,   148
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,   290,   604,   338,     1,   293,   295,   602,   342,   716,
     504,   623,   291,   309,   296,   297,   298,   299,   300,   301,
     296,   297,   298,   299,   300,   301,   342,   403,   328,   330,
     332,   334,   337,   266,   342,   406,   269,   320,   345,   342,
     409,     5,   289,   342,   411,   342,   414,   294,   360,     1,
     485,   364,   365,   321,   369,   371,   372,     1,   486,     1,
     527,   342,   530,   379,   322,   296,   297,   298,   299,   300,
     301,   296,   297,   298,   299,   300,   301,   326,     4,   288,
     342,   531,   341,     4,     4,   535,   536,   544,   545,   342,
     547,   416,   296,   297,   298,   299,   300,   301,   296,   297,
     298,   299,   300,   301,   432,   433,   342,   552,   436,   437,
     342,   557,   402,   443,   342,   558,   622,   342,   560,   597,
     598,   423,   453,   296,   297,   298,   299,   300,   301,   342,
     600,   462,   296,   297,   298,   299,   300,   301,   342,   606,
     434,   474,   342,   607,   477,   279,   479,   480,     1,   603,
       1,   717,   438,   624,   445,   302,   303,   342,   608,   342,
     609,   302,   308,   342,   610,   329,   331,   333,   342,   611,
       6,   524,   446,   343,   344,   346,   342,   612,   342,   613,
     353,   538,   357,   358,   359,   447,   342,   628,   454,   366,
       1,   634,   514,   672,   518,   457,   521,   458,   674,   656,
     657,   526,   342,   670,   459,   718,   335,   336,   460,   534,
     463,   339,   302,   363,     1,   675,   465,   400,     1,   676,
     404,   405,   407,   408,   410,   412,   413,   415,   472,   566,
     342,   486,   475,   302,   368,   342,   677,   484,   429,   302,
     370,   576,   342,   680,     6,   342,   683,   493,     4,   494,
     296,   297,   298,   299,   300,   301,   495,   296,   297,   298,
     299,   300,   301,   241,   302,   398,   296,   297,   298,   299,
     300,   301,   501,   302,   439,     1,   688,   502,   296,   297,
     298,   299,   300,   301,   508,   435,   342,   690,   509,   293,
     295,   510,   293,   295,   293,   295,   296,   297,   298,   299,
     300,   301,   539,   296,   297,   298,   299,   300,   301,     1,
     695,   342,   698,   562,   499,   567,   720,   571,     6,     6,
     342,   699,     4,   342,   701,   342,   702,   511,   513,   572,
     517,   294,   520,   573,   294,   574,   294,   342,   703,   293,
       6,   575,   511,   342,   704,   533,   342,   706,   578,     6,
     342,   707,   548,   579,   551,   553,   554,   342,   721,   506,
     507,   561,   342,   722,   580,   565,   581,     4,     4,   587,
       4,     4,     4,     4,   296,   297,   298,   299,   300,   301,
     488,   528,   296,   297,   298,   299,   300,   301,   342,   727,
     540,   302,   442,   342,   728,   588,     4,     4,   302,   452,
     342,   729,     6,   342,   730,   488,   590,   302,   473,   342,
     731,   342,   732,   488,   342,   733,   591,     4,     4,   302,
     489,   296,   297,   298,   299,   300,   301,     4,   629,   296,
     297,   298,   299,   300,   301,   293,   593,   302,   491,   342,
     734,   342,   737,     5,   496,   497,   543,   546,   713,   296,
     297,   298,   299,   300,   301,   296,   297,   298,   299,   300,
     301,   296,   297,   298,   299,   300,   301,   296,   297,   298,
     299,   300,   301,   296,   297,   298,   299,   300,   301,   594,
       4,   296,   297,   298,   299,   300,   301,   296,   297,   298,
     299,   300,   301,   595,   596,   601,   290,   615,   616,   671,
     617,   618,   621,     6,   627,   631,   293,   293,   632,   637,
     638,   640,   641,     4,   679,   327,   512,   642,   682,   643,
     644,   685,   646,   327,   516,   647,   648,   650,   293,   651,
     652,   653,   655,   660,   692,   662,   665,   669,   666,   667,
     293,   686,   693,   694,   669,   696,   271,   697,   711,   700,
     296,   297,   298,   299,   300,   301,   705,   726,   712,   714,
     715,   719,   327,   519,   724,   736,   709,   738,   658,   537,
     302,   522,   599,     0,   288,     0,     0,     0,     0,     0,
       0,   288,     0,     0,     4,     4,     0,     0,     0,     0,
     335,   523,     0,     0,     0,     0,   302,   525,     0,     0,
       0,     0,   327,   532,     0,     6,     4,     0,   541,   542,
       0,     0,     0,     0,   327,   550,     0,     0,     4,   488,
       0,     0,   327,   555,     0,     0,     0,     0,   302,   559,
     723,     0,     0,     0,     0,     0,   296,   297,   298,   299,
     300,   301,     0,     0,     0,     0,     5,     0,     0,     0,
       0,   310,   310,   310,   314,   317,   318,   319,     0,     0,
       0,   323,   324,   325,     0,     0,     0,     0,     0,   293,
       0,   340,     0,     0,     0,     0,   347,   348,   310,   350,
     352,   354,   356,     4,     0,     0,   310,   362,     0,   499,
     367,   302,   563,     0,   310,   374,   310,   310,   377,   378,
       0,   310,   310,   310,   383,   310,   310,   310,   387,   310,
     390,   392,   393,   395,   396,   397,   399,     0,   310,     0,
     296,   297,   298,   299,   300,   301,     0,     0,     0,   417,
     418,   310,   420,   310,   310,     0,   310,   427,   428,   430,
     431,   296,   297,   298,   299,   300,   301,     4,   440,   441,
       0,   444,     0,     0,     0,   448,   310,   450,   310,     0,
       0,   455,   456,     0,     0,     0,     0,   461,     0,     0,
     310,     0,   466,   310,   468,   469,   471,   327,   564,     0,
     476,     0,   310,     0,     0,   310,   310,   310,     0,   296,
     297,   298,   299,   300,   301,     0,     0,   296,   297,   298,
     299,   300,   301,     0,     0,   490,     0,     0,     0,   490,
     492,     0,     0,     0,   498,     0,     0,   498,   296,   297,
     298,   299,   300,   301,     0,     0,     0,     0,   490,     0,
     490,     0,   490,     0,   490,     0,     0,   490,     0,     0,
       0,     0,     0,     0,     0,   490,     0,     0,     0,     0,
     492,     0,     0,   549,   492,     0,     0,   556,     0,     0,
     490,   302,   568,     0,   490,   490,     0,     0,     0,   490,
       0,   490,   490,     0,     0,     0,     0,     0,     0,   490,
       0,     0,   302,   569,   310,   584,   310,   492,     0,     0,
     492,     0,     0,   492,   296,   297,   298,   299,   300,   301,
       0,   296,   297,   298,   299,   300,   301,   296,   297,   298,
     299,   300,   301,     0,     0,     0,   490,     0,     0,     0,
       0,   620,     0,   498,     0,     0,   310,     0,     0,   630,
     302,   570,     0,   490,     0,     0,   490,   490,   302,   577,
       0,     0,     0,   490,   296,   297,   298,   299,   300,   301,
       0,     0,     0,   490,     0,     0,     0,     0,     0,   302,
     583,     0,   490,   296,   297,   298,   299,   300,   301,   492,
       0,     0,     0,     0,   490,     0,     0,   490,     0,   490,
     490,   296,   297,   298,   299,   300,   301,   668,     0,     0,
       0,     0,     0,     0,     0,     0,   312,   313,     0,     0,
     498,     0,     0,     0,     0,   498,   296,   297,   298,   299,
     300,   301,     0,     0,   490,     0,     0,     0,   490,     0,
       0,   490,   349,   351,     0,   355,   490,     0,     0,   689,
     361,     0,     0,     0,   490,   302,   586,     0,   373,     0,
     375,   376,   302,   589,     0,   380,   381,   382,   302,   384,
     385,   386,   388,   389,   391,     0,   394,     0,     0,     0,
       0,     0,   401,     0,     0,     0,   490,   296,   297,   298,
     299,   300,   301,     0,     0,   419,   490,   421,   422,     0,
     425,     0,     0,     0,     0,   302,   592,     0,     0,     0,
     296,   297,   298,   299,   300,   301,     0,     0,     0,     0,
     449,     0,   451,     0,   302,   614,   296,   297,   298,   299,
     300,   301,     0,     0,   464,     0,     0,   467,     0,   470,
       0,     0,   327,   498,     0,     0,   478,     0,     0,   481,
     482,   483,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   302,   619,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   296,   297,   298,
     299,   300,   301,     0,     0,     0,     0,     0,   302,   625,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   582,     0,
     585,   302,   633,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   302,   635,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   149,   150,     0,     0,     0,     0,     0,     0,   151,
     626,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   503,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
       0,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,     1,     0,   281,   282,   283,   284,   285,   286,
     287,   149,   150,     0,     0,     0,     0,     0,     0,   151,
       0,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,     0,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
       0,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   327,     0,   281,   282,   283,   284,   285,   286,
     287,   149,   150,     0,     0,     0,     0,     0,     0,   151,
       0,   152,   153,   487,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,     0,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
       0,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   296,   297,   298,   299,   300,   301,   296,   297,   298,
     299,   300,   301,   296,   297,   298,   299,   300,   301,     0,
     269,   296,   297,   298,   299,   300,   301,     0,     0,     0,
       0,     0,   302,     0,   281,   282,   283,   284,   285,   286,
     287,   149,   150,     0,     0,     0,     0,     0,     0,   151,
       0,   152,   153,   487,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,     0,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
       0,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   302,   636,     0,     0,     0,     0,   302,   639,
       0,     0,     0,     0,   302,   645,   296,   297,   298,   299,
     300,   301,   302,   649,   296,   297,   298,   299,   300,   301,
       0,     0,   271,   296,   297,   298,   299,   300,   301,     0,
       0,     0,   302,     0,   281,   282,   283,   284,   285,   286,
     287,   149,   150,     0,     0,     0,     0,     0,     0,   151,
       0,   152,   153,   487,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,     0,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
       0,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,     0,     0,     0,     0,   302,   654,     0,
       0,     0,     0,     0,     0,   302,   659,   296,   297,   298,
     299,   300,   301,     0,   302,   661,   296,   297,   298,   299,
     300,   301,   296,   297,   298,   299,   300,   301,     0,     0,
       0,     0,   302,     0,   281,   282,   283,   284,   285,   286,
     287,   149,   150,     0,     0,     0,     0,     0,     0,   151,
       0,   152,   153,   487,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,     0,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
       0,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   296,   297,   298,   299,   300,   301,   302,   663,
     296,   297,   298,   299,   300,   301,     0,   302,   664,     0,
       0,     0,     0,   503,   673,   296,   297,   298,   299,   300,
     301,   296,   297,   298,   299,   300,   301,     0,     0,     0,
       0,     0,     1,     0,   281,   282,   283,   284,   285,   286,
     287,   296,   297,   298,   299,   300,   301,   296,   297,   298,
     299,   300,   301,   296,   297,   298,   299,   300,   301,   296,
     297,   298,   299,   300,   301,   296,   297,   298,   299,   300,
     301,   296,   297,   298,   299,   300,   301,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   529,     0,     0,     0,     0,
       0,     0,     0,   327,   678,     0,     0,     0,     0,     0,
       0,   327,   681,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   327,   684,     0,     0,
       0,     0,   302,   687,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   327,   691,     0,     0,     0,     0,   327,   708,
       0,     0,     0,     0,   302,   710,     0,     0,     0,     0,
     503,   497,     0,     0,     0,     0,     1,   725,     0,     0,
       0,     0,   302,   735,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   342
};

static const yytype_int16 yycheck[] =
{
       0,     1,   402,   169,   144,     5,     6,     3,   144,     3,
     317,     3,     0,   150,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,   144,   145,   165,   166,
     167,   168,   169,   129,   144,   145,   132,   145,   175,   144,
     145,     0,     1,   144,   145,   144,   145,     6,   185,   144,
     145,   188,   189,   145,   191,   192,   193,   144,   145,   144,
     145,   144,   145,   200,   145,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,   145,     0,     1,
     144,   145,   145,     5,     6,   144,   145,   144,   145,   144,
     145,   228,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,   145,   242,   144,   145,   245,   246,
     144,   145,     3,   250,   144,   145,   423,   144,   145,   144,
     145,     3,   259,     3,     4,     5,     6,     7,     8,   144,
     145,   268,     3,     4,     5,     6,     7,     8,   144,   145,
     145,   278,   144,   145,   281,   142,   283,   284,   144,   145,
     144,   145,   145,   145,   145,   144,   145,   144,   145,   144,
     145,   144,   145,   144,   145,   165,   166,   167,   144,   145,
     170,   337,   145,   173,   174,   175,   144,   145,   144,   145,
     180,   347,   182,   183,   184,   145,   144,   145,   145,   189,
     144,   145,   329,   500,   331,   145,   333,   145,   505,   144,
     145,   338,   144,   145,   145,   605,   144,   145,   145,   346,
     145,   170,   144,   145,   144,   145,   145,   217,   144,   145,
     220,   221,   222,   223,   224,   225,   226,   227,   145,   366,
     144,   145,   145,   144,   145,   144,   145,   145,   238,   144,
     145,   378,   144,   145,   244,   144,   145,   145,   170,   145,
       3,     4,     5,     6,     7,     8,   145,     3,     4,     5,
       6,     7,     8,   104,   144,   145,     3,     4,     5,     6,
       7,     8,   145,   144,   145,   144,   145,   145,     3,     4,
       5,     6,     7,     8,   145,   244,   144,   145,   145,   289,
     290,   145,   292,   293,   294,   295,     3,     4,     5,     6,
       7,     8,   145,     3,     4,     5,     6,     7,     8,   144,
     145,   144,   145,   145,   314,   145,   623,   145,   318,   319,
     144,   145,   244,   144,   145,   144,   145,   327,   328,   145,
     330,   290,   332,   145,   293,   145,   295,   144,   145,   339,
     340,   145,   342,   144,   145,   345,   144,   145,   145,   349,
     144,   145,   352,   145,   354,   355,   356,   144,   145,   318,
     319,   361,   144,   145,   145,   365,   145,   289,   290,   145,
     292,   293,   294,   295,     3,     4,     5,     6,     7,     8,
     302,   340,     3,     4,     5,     6,     7,     8,   144,   145,
     349,   144,   145,   144,   145,   145,   318,   319,   144,   145,
     144,   145,   402,   144,   145,   327,   145,   144,   145,   144,
     145,   144,   145,   335,   144,   145,   145,   339,   340,   144,
     145,     3,     4,     5,     6,     7,     8,   349,   428,     3,
       4,     5,     6,     7,     8,   435,   145,   144,   145,   144,
     145,   144,   145,   402,   144,   145,   350,   351,   585,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,   145,
     402,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,   145,   145,   145,   496,   145,   145,   499,
     145,   145,   145,   503,   145,   145,   506,   507,   145,   145,
     145,   145,   145,   435,   514,   144,   145,   145,   518,   145,
     145,   521,   145,   144,   145,   145,   145,   145,   528,   145,
     145,   145,   145,   145,   534,   145,   145,   496,   145,   145,
     540,   145,   145,   145,   503,   145,   134,   145,   145,   549,
       3,     4,     5,     6,     7,     8,   556,   669,   145,   145,
     145,   145,   144,   145,   145,   145,   566,   145,   471,   347,
     144,   145,   399,    -1,   496,    -1,    -1,    -1,    -1,    -1,
      -1,   503,    -1,    -1,   506,   507,    -1,    -1,    -1,    -1,
     144,   145,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,
      -1,    -1,   144,   145,    -1,   605,   528,    -1,   144,   145,
      -1,    -1,    -1,    -1,   144,   145,    -1,    -1,   540,   541,
      -1,    -1,   144,   145,    -1,    -1,    -1,    -1,   144,   145,
     630,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,   605,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,   156,   157,    -1,    -1,
      -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,   669,
      -1,   171,    -1,    -1,    -1,    -1,   176,   177,   178,   179,
     180,   181,   182,   605,    -1,    -1,   186,   187,    -1,   689,
     190,   144,   145,    -1,   194,   195,   196,   197,   198,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,   218,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,   229,
     230,   231,   232,   233,   234,    -1,   236,   237,   238,   239,
     240,     3,     4,     5,     6,     7,     8,   669,   248,   249,
      -1,   251,    -1,    -1,    -1,   255,   256,   257,   258,    -1,
      -1,   261,   262,    -1,    -1,    -1,    -1,   267,    -1,    -1,
     270,    -1,   272,   273,   274,   275,   276,   144,   145,    -1,
     280,    -1,   282,    -1,    -1,   285,   286,   287,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,   305,    -1,    -1,    -1,   309,
     310,    -1,    -1,    -1,   314,    -1,    -1,   317,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,   328,    -1,
     330,    -1,   332,    -1,   334,    -1,    -1,   337,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   345,    -1,    -1,    -1,    -1,
     350,    -1,    -1,   353,   354,    -1,    -1,   357,    -1,    -1,
     360,   144,   145,    -1,   364,   365,    -1,    -1,    -1,   369,
      -1,   371,   372,    -1,    -1,    -1,    -1,    -1,    -1,   379,
      -1,    -1,   144,   145,   384,   385,   386,   387,    -1,    -1,
     390,    -1,    -1,   393,     3,     4,     5,     6,     7,     8,
      -1,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,   416,    -1,    -1,    -1,
      -1,   421,    -1,   423,    -1,    -1,   426,    -1,    -1,   429,
     144,   145,    -1,   433,    -1,    -1,   436,   437,   144,   145,
      -1,    -1,    -1,   443,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,   453,    -1,    -1,    -1,    -1,    -1,   144,
     145,    -1,   462,     3,     4,     5,     6,     7,     8,   469,
      -1,    -1,    -1,    -1,   474,    -1,    -1,   477,    -1,   479,
     480,     3,     4,     5,     6,     7,     8,   487,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   152,   153,    -1,    -1,
     500,    -1,    -1,    -1,    -1,   505,     3,     4,     5,     6,
       7,     8,    -1,    -1,   514,    -1,    -1,    -1,   518,    -1,
      -1,   521,   178,   179,    -1,   181,   526,    -1,    -1,   529,
     186,    -1,    -1,    -1,   534,   144,   145,    -1,   194,    -1,
     196,   197,   144,   145,    -1,   201,   202,   203,   144,   205,
     206,   207,   208,   209,   210,    -1,   212,    -1,    -1,    -1,
      -1,    -1,   218,    -1,    -1,    -1,   566,     3,     4,     5,
       6,     7,     8,    -1,    -1,   231,   576,   233,   234,    -1,
     236,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
     256,    -1,   258,    -1,   144,   145,     3,     4,     5,     6,
       7,     8,    -1,    -1,   270,    -1,    -1,   273,    -1,   275,
      -1,    -1,   144,   623,    -1,    -1,   282,    -1,    -1,   285,
     286,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   668,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,   144,   145,
      -1,    -1,    -1,   713,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,    -1,
     386,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    11,
     426,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,   144,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,    -1,
     132,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   144,   145,    -1,    -1,    -1,    -1,   144,   145,
      -1,    -1,    -1,    -1,   144,   145,     3,     4,     5,     6,
       7,     8,   144,   145,     3,     4,     5,     6,     7,     8,
      -1,    -1,   134,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,   144,   145,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,     3,     4,     5,
       6,     7,     8,    -1,   144,   145,     3,     4,     5,     6,
       7,     8,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     3,     4,     5,     6,     7,     8,   144,   145,
       3,     4,     5,     6,     7,     8,    -1,   144,   145,    -1,
      -1,    -1,    -1,   144,   145,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,
      -1,    -1,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,    -1,    -1,    -1,    -1,   144,   145,
      -1,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,    -1,
     144,   145,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,
      -1,    -1,   144,   145,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   144,   154,   155,   160,   161,   162,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,     3,
       4,    11,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   146,   147,   148,   149,   150,   151,   152,   160,   161,
     162,     0,   161,   162,   161,   162,     3,     4,     5,     6,
       7,     8,   144,   145,   156,   158,   160,   165,   145,   158,
     156,   157,   157,   157,   156,   168,   169,   156,   156,   156,
     145,   145,   145,   156,   156,   156,   145,   144,   158,   162,
     158,   162,   158,   162,   158,   144,   145,   158,   299,   161,
     156,   145,   144,   162,   162,   158,   162,   156,   156,   157,
     156,   157,   156,   162,   156,   157,   156,   162,   162,   162,
     158,   157,   156,   145,   158,   158,   162,   156,   145,   158,
     145,   158,   158,   157,   156,   157,   157,   156,   156,   158,
     157,   157,   157,   156,   157,   157,   157,   156,   157,   157,
     156,   157,   156,   156,   157,   156,   156,   156,   145,   156,
     162,   157,     3,   145,   162,   162,   145,   162,   162,   145,
     162,   145,   162,   162,   145,   162,   158,   156,   156,   157,
     156,   157,   157,     3,   166,   157,   159,   156,   156,   162,
     156,   156,   145,   158,   145,   161,   158,   158,   145,   145,
     156,   156,   145,   158,   156,   145,   145,   145,   156,   157,
     156,   157,   145,   158,   145,   156,   156,   145,   145,   145,
     145,   156,   158,   145,   157,   145,   156,   157,   156,   156,
     157,   156,   145,   145,   158,   145,   156,   158,   157,   158,
     158,   157,   157,   157,   145,   145,   145,    15,   160,   145,
     156,   145,   156,   145,   145,   145,   144,   145,   156,   162,
     163,   145,   145,   144,   163,   164,   161,   161,   145,   145,
     145,   162,   145,   162,   158,   162,   145,   162,   158,   145,
     162,   158,   145,   145,   299,   145,   158,   145,   161,    15,
     145,   145,   145,   162,   158,   144,   145,   296,   299,   145,
     161,   144,   145,   301,   144,   145,   301,   145,   162,   156,
     145,   162,   145,   162,   162,   145,   156,   145,   145,   145,
     145,   162,   145,   145,   145,   162,   158,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   158,   145,   145,   145,
     145,   145,   157,   145,   156,   157,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   144,   145,   309,
     145,   145,     3,   145,   155,   167,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     156,   145,   163,     3,   145,   145,   157,   145,   145,   162,
     156,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   144,   145,   271,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   156,   161,
     145,   162,   163,   145,   163,   145,   145,   145,   145,   162,
     145,   145,   162,   145,   145,   162,   145,   145,   145,   156,
     145,   145,   162,   145,   145,   145,   145,   145,   145,   145,
     162,   145,   145,   145,   145,   162,   145,   145,   145,   162,
     145,   145,   145,   158,   145,   145,     3,   145,   155,   145,
     163,   145,   145,   162,   145,   145,   165,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   153,   154,   155,   156,   156,   157,   158,   158,   159,
     159,   160,   160,   161,   161,   161,   161,   161,   162,   162,
     162,   163,   163,   163,   164,   164,   165,   165,   165,   165,
     165,   165,   166,   166,   167,   167,   168,   169,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   182,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   193,   193,   193,   194,   194,   194,   194,   195,
     195,   195,   195,   196,   197,   197,   197,   197,   197,   198,
     199,   200,   201,   202,   203,   203,   203,   203,   204,   204,
     204,   205,   206,   207,   207,   207,   207,   208,   208,   208,
     208,   209,   209,   209,   209,   210,   210,   210,   210,   211,
     212,   213,   214,   214,   215,   216,   216,   217,   217,   217,
     217,   218,   219,   219,   220,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     234,   235,   236,   236,   237,   238,   238,   239,   240,   240,
     241,   242,   243,   244,   244,   244,   245,   246,   247,   247,
     247,   247,   248,   248,   249,   249,   250,   251,   251,   252,
     253,   253,   254,   254,   255,   256,   256,   257,   258,   259,
     259,   260,   261,   262,   263,   263,   264,   265,   266,   267,
     268,   268,   268,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   278,   279,   280,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   305,   306,   306,   307,   308,   308,
     309,   310,   311,   311
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     1,     2,
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     5,     5,     3,     3,     3,     4,     4,     4,
       3,     5,     5,     6,     4,     5,     5,     6,     4,     5,
       5,     6,     4,     4,     5,     5,     4,     4,     3,     4,
       3,     5,     4,     4,     5,     5,     6,     4,     4,     5,
       5,     4,     5,     5,     4,     5,     4,     5,     5,     6,
       4,     5,     4,     5,     4,     5,     5,     6,     4,     4,
       4,     4,     5,     4,     4,     4,     3,     5,     5,     6,
       4,     4,     4,     3,     4,     3,     4,     4,     4,     4,
       4,     4,     5,     4,     4,     4,     4,     4,     5,     4,
       5,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     4,     5,     4,     4,     6,     5,
       5,     4,     4,     3,     3,     4,     4,     3,     4,     4,
       3,     4,     3,     4,     4,     3,     4,     4,     4,     4,
       3,     4,     4,     4,     4,     5,     4,     4,     4,     4,
       4,     5,     5,     6,     4,     4,     3,     4,     3,     4,
       4,     4,     3,     4,     3,     4,     4,     3,     4,     3,
       3,     3,     4,     4,     4,     4,     4,     3,     3,     4,
       4,     3,     3,     3,     3,     4,     4,     3,     4,     3,
       4,     4,     4,     4,     4,     4,     5,     3,     4,     3,
       3,     4,     5,     6
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, yyscan_t scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
#line 73 "../src/parser.y"
            { free(((*yyvaluep).s)); }
#line 2092 "parser.c"
        break;

    case 4: /* STR  */
#line 73 "../src/parser.y"
            { free(((*yyvaluep).s)); }
#line 2098 "parser.c"
        break;

    case 154: /* start  */
#line 71 "../src/parser.y"
            { run(((*yyvaluep).e));  }
#line 2104 "parser.c"
        break;

    case 155: /* s  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2110 "parser.c"
        break;

    case 156: /* p  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2116 "parser.c"
        break;

    case 157: /* pp  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2122 "parser.c"
        break;

    case 158: /* ps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2128 "parser.c"
        break;

    case 159: /* pps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2134 "parser.c"
        break;

    case 160: /* vp  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2140 "parser.c"
        break;

    case 161: /* vps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2146 "parser.c"
        break;

    case 162: /* opts  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2152 "parser.c"
        break;

    case 163: /* xpb  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2158 "parser.c"
        break;

    case 164: /* xpbs  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2164 "parser.c"
        break;

    case 165: /* np  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2170 "parser.c"
        break;

    case 166: /* sps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2176 "parser.c"
        break;

    case 167: /* par  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2182 "parser.c"
        break;

    case 168: /* cv  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2188 "parser.c"
        break;

    case 169: /* cvv  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2194 "parser.c"
        break;

    case 170: /* opt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2200 "parser.c"
        break;

    case 171: /* ivp  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2206 "parser.c"
        break;

    case 172: /* add  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2212 "parser.c"
        break;

    case 173: /* div  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2218 "parser.c"
        break;

    case 174: /* mul  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2224 "parser.c"
        break;

    case 175: /* sub  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2230 "parser.c"
        break;

    case 176: /* eq  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2236 "parser.c"
        break;

    case 177: /* gt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2242 "parser.c"
        break;

    case 178: /* gte  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2248 "parser.c"
        break;

    case 179: /* lt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2254 "parser.c"
        break;

    case 180: /* lte  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2260 "parser.c"
        break;

    case 181: /* neq  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2266 "parser.c"
        break;

    case 182: /* if  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2272 "parser.c"
        break;

    case 183: /* select  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2278 "parser.c"
        break;

    case 184: /* until  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2284 "parser.c"
        break;

    case 185: /* while  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2290 "parser.c"
        break;

    case 186: /* trace  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2296 "parser.c"
        break;

    case 187: /* retrace  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2302 "parser.c"
        break;

    case 188: /* astraw  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2308 "parser.c"
        break;

    case 189: /* asbraw  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2314 "parser.c"
        break;

    case 190: /* asbeval  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2320 "parser.c"
        break;

    case 191: /* eval  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2326 "parser.c"
        break;

    case 192: /* options  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2332 "parser.c"
        break;

    case 193: /* execute  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2338 "parser.c"
        break;

    case 194: /* rexx  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2344 "parser.c"
        break;

    case 195: /* run  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2350 "parser.c"
        break;

    case 196: /* abort  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2356 "parser.c"
        break;

    case 197: /* exit  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2362 "parser.c"
        break;

    case 198: /* onerror  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2368 "parser.c"
        break;

    case 199: /* reboot  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2374 "parser.c"
        break;

    case 200: /* trap  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2380 "parser.c"
        break;

    case 201: /* copyfiles  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2386 "parser.c"
        break;

    case 202: /* copylib  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2392 "parser.c"
        break;

    case 203: /* delete  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2398 "parser.c"
        break;

    case 204: /* exists  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2404 "parser.c"
        break;

    case 205: /* fileonly  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2410 "parser.c"
        break;

    case 206: /* foreach  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2416 "parser.c"
        break;

    case 207: /* makeassign  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2422 "parser.c"
        break;

    case 208: /* makedir  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2428 "parser.c"
        break;

    case 209: /* protect  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2434 "parser.c"
        break;

    case 210: /* startup  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2440 "parser.c"
        break;

    case 211: /* textfile  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2446 "parser.c"
        break;

    case 212: /* tooltype  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2452 "parser.c"
        break;

    case 213: /* transcript  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2458 "parser.c"
        break;

    case 214: /* rename  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2464 "parser.c"
        break;

    case 215: /* complete  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2470 "parser.c"
        break;

    case 216: /* debug  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2476 "parser.c"
        break;

    case 217: /* message  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2482 "parser.c"
        break;

    case 218: /* user  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2488 "parser.c"
        break;

    case 219: /* welcome  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2494 "parser.c"
        break;

    case 220: /* working  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2500 "parser.c"
        break;

    case 221: /* and  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2506 "parser.c"
        break;

    case 222: /* bitand  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2512 "parser.c"
        break;

    case 223: /* bitnot  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2518 "parser.c"
        break;

    case 224: /* bitor  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2524 "parser.c"
        break;

    case 225: /* bitxor  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2530 "parser.c"
        break;

    case 226: /* not  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2536 "parser.c"
        break;

    case 227: /* in  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2542 "parser.c"
        break;

    case 228: /* or  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2548 "parser.c"
        break;

    case 229: /* shiftleft  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2554 "parser.c"
        break;

    case 230: /* shiftright  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2560 "parser.c"
        break;

    case 231: /* xor  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2566 "parser.c"
        break;

    case 232: /* closemedia  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2572 "parser.c"
        break;

    case 233: /* effect  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2578 "parser.c"
        break;

    case 234: /* setmedia  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2584 "parser.c"
        break;

    case 235: /* showmedia  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2590 "parser.c"
        break;

    case 236: /* database  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2596 "parser.c"
        break;

    case 237: /* earlier  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2602 "parser.c"
        break;

    case 238: /* getassign  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2608 "parser.c"
        break;

    case 239: /* getdevice  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2614 "parser.c"
        break;

    case 240: /* getdiskspace  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2620 "parser.c"
        break;

    case 241: /* getenv  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2626 "parser.c"
        break;

    case 242: /* getsize  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2632 "parser.c"
        break;

    case 243: /* getsum  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2638 "parser.c"
        break;

    case 244: /* getversion  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2644 "parser.c"
        break;

    case 245: /* iconinfo  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2650 "parser.c"
        break;

    case 246: /* querydisplay  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2656 "parser.c"
        break;

    case 247: /* dcl  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2662 "parser.c"
        break;

    case 248: /* cus  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2668 "parser.c"
        break;

    case 249: /* askbool  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2674 "parser.c"
        break;

    case 250: /* askchoice  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2680 "parser.c"
        break;

    case 251: /* askdir  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2686 "parser.c"
        break;

    case 252: /* askdisk  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2692 "parser.c"
        break;

    case 253: /* askfile  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2698 "parser.c"
        break;

    case 254: /* asknumber  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2704 "parser.c"
        break;

    case 255: /* askoptions  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2710 "parser.c"
        break;

    case 256: /* askstring  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2716 "parser.c"
        break;

    case 257: /* cat  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2722 "parser.c"
        break;

    case 258: /* expandpath  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2728 "parser.c"
        break;

    case 259: /* fmt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2734 "parser.c"
        break;

    case 260: /* pathonly  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2740 "parser.c"
        break;

    case 261: /* patmatch  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2746 "parser.c"
        break;

    case 262: /* strlen  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2752 "parser.c"
        break;

    case 263: /* substr  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2758 "parser.c"
        break;

    case 264: /* tackon  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2764 "parser.c"
        break;

    case 265: /* set  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2770 "parser.c"
        break;

    case 266: /* symbolset  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2776 "parser.c"
        break;

    case 267: /* symbolval  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2782 "parser.c"
        break;

    case 268: /* openwbobject  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2788 "parser.c"
        break;

    case 269: /* showwbobject  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2794 "parser.c"
        break;

    case 270: /* closewbobject  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2800 "parser.c"
        break;

    case 271: /* all  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2806 "parser.c"
        break;

    case 272: /* append  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2812 "parser.c"
        break;

    case 273: /* assigns  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2818 "parser.c"
        break;

    case 274: /* back  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2824 "parser.c"
        break;

    case 275: /* choices  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2830 "parser.c"
        break;

    case 276: /* command  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2836 "parser.c"
        break;

    case 277: /* compression  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2842 "parser.c"
        break;

    case 278: /* confirm  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2848 "parser.c"
        break;

    case 279: /* default  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2854 "parser.c"
        break;

    case 280: /* delopts  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2860 "parser.c"
        break;

    case 281: /* dest  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2866 "parser.c"
        break;

    case 282: /* disk  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2872 "parser.c"
        break;

    case 283: /* files  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2878 "parser.c"
        break;

    case 284: /* fonts  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2884 "parser.c"
        break;

    case 285: /* getdefaulttool  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2890 "parser.c"
        break;

    case 286: /* getposition  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2896 "parser.c"
        break;

    case 287: /* getstack  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2902 "parser.c"
        break;

    case 288: /* gettooltype  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2908 "parser.c"
        break;

    case 289: /* help  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2914 "parser.c"
        break;

    case 290: /* infos  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2920 "parser.c"
        break;

    case 291: /* include  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2926 "parser.c"
        break;

    case 292: /* newname  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2932 "parser.c"
        break;

    case 293: /* newpath  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2938 "parser.c"
        break;

    case 294: /* nogauge  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2944 "parser.c"
        break;

    case 295: /* noposition  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2950 "parser.c"
        break;

    case 296: /* noreq  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2956 "parser.c"
        break;

    case 297: /* pattern  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2962 "parser.c"
        break;

    case 298: /* prompt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2968 "parser.c"
        break;

    case 299: /* quiet  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2974 "parser.c"
        break;

    case 300: /* range  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2980 "parser.c"
        break;

    case 301: /* safe  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2986 "parser.c"
        break;

    case 302: /* setdefaulttool  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2992 "parser.c"
        break;

    case 303: /* setposition  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2998 "parser.c"
        break;

    case 304: /* setstack  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3004 "parser.c"
        break;

    case 305: /* settooltype  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3010 "parser.c"
        break;

    case 306: /* source  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3016 "parser.c"
        break;

    case 307: /* swapcolors  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3022 "parser.c"
        break;

    case 308: /* optional  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3028 "parser.c"
        break;

    case 309: /* resident  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3034 "parser.c"
        break;

    case 310: /* override  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3040 "parser.c"
        break;

    case 311: /* dynopt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3046 "parser.c"
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

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
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

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
#line 87 "../src/parser.y"
                                                 { (yyval.e) = init((yyvsp[0].e)); }
#line 3320 "parser.c"
    break;

  case 6:
#line 94 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3326 "parser.c"
    break;

  case 7:
#line 95 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3332 "parser.c"
    break;

  case 8:
#line 96 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3338 "parser.c"
    break;

  case 9:
#line 97 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3344 "parser.c"
    break;

  case 12:
#line 100 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3350 "parser.c"
    break;

  case 13:
#line 101 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3356 "parser.c"
    break;

  case 14:
#line 102 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e));  }
#line 3362 "parser.c"
    break;

  case 15:
#line 103 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e));  }
#line 3368 "parser.c"
    break;

  case 16:
#line 104 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3374 "parser.c"
    break;

  case 17:
#line 105 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3380 "parser.c"
    break;

  case 18:
#line 106 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3386 "parser.c"
    break;

  case 19:
#line 107 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3392 "parser.c"
    break;

  case 20:
#line 108 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3398 "parser.c"
    break;

  case 21:
#line 109 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3404 "parser.c"
    break;

  case 22:
#line 110 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-2].e), (yyvsp[-1].e)); }
#line 3410 "parser.c"
    break;

  case 23:
#line 111 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3416 "parser.c"
    break;

  case 24:
#line 112 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3422 "parser.c"
    break;

  case 25:
#line 113 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3428 "parser.c"
    break;

  case 26:
#line 114 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3434 "parser.c"
    break;

  case 27:
#line 115 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3440 "parser.c"
    break;

  case 28:
#line 116 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3446 "parser.c"
    break;

  case 29:
#line 117 "../src/parser.y"
                                                 { (yyval.e) = new_string((yyvsp[0].s)); }
#line 3452 "parser.c"
    break;

  case 30:
#line 118 "../src/parser.y"
                                                 { (yyval.e) = new_symref((yyvsp[0].s), LINE); }
#line 3458 "parser.c"
    break;

  case 31:
#line 119 "../src/parser.y"
                                                 { (yyval.e) = NULL; YYFPRINTF(stderr, "Out of memory in line %d\n", LINE); YYABORT; }
#line 3464 "parser.c"
    break;

  case 32:
#line 120 "../src/parser.y"
                                                 { (yyval.e) = push(push((yyvsp[-2].e), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)) ; }
#line 3470 "parser.c"
    break;

  case 33:
#line 121 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)); }
#line 3476 "parser.c"
    break;

  case 34:
#line 122 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), new_symbol((yyvsp[0].s))); }
#line 3482 "parser.c"
    break;

  case 35:
#line 123 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), new_symbol((yyvsp[0].s))); }
#line 3488 "parser.c"
    break;

  case 36:
#line 124 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3494 "parser.c"
    break;

  case 37:
#line 125 "../src/parser.y"
                                                 { (yyval.e) = push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3500 "parser.c"
    break;

  case 178:
#line 275 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("+"), LINE, n_add, (yyvsp[-1].e), NUMBER); }
#line 3506 "parser.c"
    break;

  case 179:
#line 276 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("/"), LINE, n_div, (yyvsp[-1].e), NUMBER); }
#line 3512 "parser.c"
    break;

  case 180:
#line 277 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("*"), LINE, n_mul, (yyvsp[-1].e), NUMBER); }
#line 3518 "parser.c"
    break;

  case 181:
#line 278 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("-"), LINE, n_sub, (yyvsp[-1].e), NUMBER); }
#line 3524 "parser.c"
    break;

  case 182:
#line 282 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("="), LINE, n_eq, (yyvsp[-1].e), NUMBER); }
#line 3530 "parser.c"
    break;

  case 183:
#line 283 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup(">"), LINE, n_gt, (yyvsp[-1].e), NUMBER); }
#line 3536 "parser.c"
    break;

  case 184:
#line 284 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup(">="), LINE, n_gte, (yyvsp[-1].e), NUMBER); }
#line 3542 "parser.c"
    break;

  case 185:
#line 285 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<"), LINE, n_lt, (yyvsp[-1].e), NUMBER); }
#line 3548 "parser.c"
    break;

  case 186:
#line 286 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<="), LINE, n_lte, (yyvsp[-1].e), NUMBER); }
#line 3554 "parser.c"
    break;

  case 187:
#line 287 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<>"), LINE, n_neq, (yyvsp[-1].e), NUMBER); }
#line 3560 "parser.c"
    break;

  case 188:
#line 291 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("if"), LINE, n_if, (yyvsp[-1].e), NUMBER); }
#line 3566 "parser.c"
    break;

  case 189:
#line 292 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("if"), LINE, n_if, (yyvsp[-1].e), NUMBER); }
#line 3572 "parser.c"
    break;

  case 190:
#line 293 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("if"), LINE, n_if, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3578 "parser.c"
    break;

  case 191:
#line 294 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("select"), LINE, n_select, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3584 "parser.c"
    break;

  case 192:
#line 295 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("until"), LINE, n_until, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3590 "parser.c"
    break;

  case 193:
#line 296 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("while"), LINE, n_while, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3596 "parser.c"
    break;

  case 194:
#line 297 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("trace"), LINE, n_trace, NULL, NUMBER); }
#line 3602 "parser.c"
    break;

  case 195:
#line 298 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("retrace"), LINE, n_retrace, NULL, NUMBER); }
#line 3608 "parser.c"
    break;

  case 196:
#line 302 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___astraw"), LINE, n_astraw, NULL, NUMBER); }
#line 3614 "parser.c"
    break;

  case 197:
#line 303 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___asbraw"), LINE, n_asbraw, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3620 "parser.c"
    break;

  case 198:
#line 304 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___asbeval"), LINE, n_asbeval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3626 "parser.c"
    break;

  case 199:
#line 305 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___eval"), LINE, n_eval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3632 "parser.c"
    break;

  case 200:
#line 306 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___options"), LINE, n_options, NULL, NUMBER); }
#line 3638 "parser.c"
    break;

  case 201:
#line 310 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, n_execute, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3644 "parser.c"
    break;

  case 202:
#line 311 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, n_execute, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3650 "parser.c"
    break;

  case 203:
#line 312 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, n_execute, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3656 "parser.c"
    break;

  case 204:
#line 313 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, n_execute, (yyvsp[-1].e), NUMBER); }
#line 3662 "parser.c"
    break;

  case 205:
#line 314 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, n_rexx, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3668 "parser.c"
    break;

  case 206:
#line 315 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, n_rexx, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3674 "parser.c"
    break;

  case 207:
#line 316 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, n_rexx, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3680 "parser.c"
    break;

  case 208:
#line 317 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, n_rexx, (yyvsp[-1].e), NUMBER); }
#line 3686 "parser.c"
    break;

  case 209:
#line 318 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, n_run, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3692 "parser.c"
    break;

  case 210:
#line 319 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, n_run, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3698 "parser.c"
    break;

  case 211:
#line 320 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, n_run, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3704 "parser.c"
    break;

  case 212:
#line 321 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, n_run, (yyvsp[-1].e), NUMBER); }
#line 3710 "parser.c"
    break;

  case 213:
#line 325 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("abort"), LINE, n_abort, (yyvsp[-1].e), NUMBER); }
#line 3716 "parser.c"
    break;

  case 214:
#line 326 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, n_exit, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3722 "parser.c"
    break;

  case 215:
#line 327 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, n_exit, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3728 "parser.c"
    break;

  case 216:
#line 328 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, n_exit, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3734 "parser.c"
    break;

  case 217:
#line 329 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, n_exit, (yyvsp[-1].e), NUMBER); }
#line 3740 "parser.c"
    break;

  case 218:
#line 330 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, n_exit, NULL, NUMBER); }
#line 3746 "parser.c"
    break;

  case 219:
#line 331 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("onerror"), LINE, n_procedure, push(new_contxt(),
                                                        new_custom(strdup("@onerror"), LINE, NULL, (yyvsp[-1].e))), DANGLE); }
#line 3753 "parser.c"
    break;

  case 220:
#line 333 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("reboot"), LINE, n_reboot, NULL, NUMBER); }
#line 3759 "parser.c"
    break;

  case 221:
#line 334 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("trap"), LINE, n_trap, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3765 "parser.c"
    break;

  case 222:
#line 338 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("copyfiles"), LINE, n_copyfiles, (yyvsp[-1].e), NUMBER); }
#line 3771 "parser.c"
    break;

  case 223:
#line 339 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("copylib"), LINE, n_copylib, (yyvsp[-1].e), NUMBER); }
#line 3777 "parser.c"
    break;

  case 224:
#line 340 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, n_delete, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3783 "parser.c"
    break;

  case 225:
#line 341 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, n_delete, merge((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3789 "parser.c"
    break;

  case 226:
#line 342 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, n_delete, merge((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3795 "parser.c"
    break;

  case 227:
#line 343 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, n_delete, (yyvsp[-1].e), NUMBER); }
#line 3801 "parser.c"
    break;

  case 228:
#line 344 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exists"), LINE, n_exists, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3807 "parser.c"
    break;

  case 229:
#line 345 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exists"), LINE, n_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3813 "parser.c"
    break;

  case 230:
#line 346 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exists"), LINE, n_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3819 "parser.c"
    break;

  case 231:
#line 347 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("fileonly"), LINE, n_fileonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3825 "parser.c"
    break;

  case 232:
#line 348 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("foreach"), LINE, n_foreach, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3831 "parser.c"
    break;

  case 233:
#line 349 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, n_makeassign, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3837 "parser.c"
    break;

  case 234:
#line 350 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, n_makeassign, (yyvsp[-1].e), NUMBER); }
#line 3843 "parser.c"
    break;

  case 235:
#line 351 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, n_makeassign, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3849 "parser.c"
    break;

  case 236:
#line 352 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, n_makeassign, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3855 "parser.c"
    break;

  case 237:
#line 353 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, n_makedir, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3861 "parser.c"
    break;

  case 238:
#line 354 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, n_makedir, merge(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3867 "parser.c"
    break;

  case 239:
#line 355 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, n_makedir, merge(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3873 "parser.c"
    break;

  case 240:
#line 356 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, n_makedir, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3879 "parser.c"
    break;

  case 241:
#line 357 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, n_protect, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3885 "parser.c"
    break;

  case 242:
#line 358 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, n_protect, (yyvsp[-1].e), NUMBER); }
#line 3891 "parser.c"
    break;

  case 243:
#line 359 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, n_protect, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3897 "parser.c"
    break;

  case 244:
#line 360 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, n_protect, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3903 "parser.c"
    break;

  case 245:
#line 361 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, n_startup, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3909 "parser.c"
    break;

  case 246:
#line 362 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, n_startup, merge(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3915 "parser.c"
    break;

  case 247:
#line 363 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, n_startup, merge(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3921 "parser.c"
    break;

  case 248:
#line 364 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, n_startup, merge(push(new_contxt(), new_symref(strdup("@app-name"), LINE)), (yyvsp[-1].e)), NUMBER); }
#line 3927 "parser.c"
    break;

  case 249:
#line 365 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("textfile"), LINE, n_textfile, (yyvsp[-1].e), NUMBER); }
#line 3933 "parser.c"
    break;

  case 250:
#line 366 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("tooltype"), LINE, n_tooltype, (yyvsp[-1].e), NUMBER); }
#line 3939 "parser.c"
    break;

  case 251:
#line 367 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("transcript"), LINE, n_transcript, (yyvsp[-1].e), NUMBER); }
#line 3945 "parser.c"
    break;

  case 252:
#line 368 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rename"), LINE, n_rename, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3951 "parser.c"
    break;

  case 253:
#line 369 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rename"), LINE, n_rename, (yyvsp[-1].e), NUMBER); }
#line 3957 "parser.c"
    break;

  case 254:
#line 373 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("complete"), LINE, n_complete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3963 "parser.c"
    break;

  case 255:
#line 374 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("debug"), LINE, n_debug, (yyvsp[-1].e), NUMBER); }
#line 3969 "parser.c"
    break;

  case 256:
#line 375 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("debug"), LINE, n_debug, NULL, NUMBER); }
#line 3975 "parser.c"
    break;

  case 257:
#line 376 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, n_message, merge((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3981 "parser.c"
    break;

  case 258:
#line 377 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, n_message, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3987 "parser.c"
    break;

  case 259:
#line 378 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, n_message, push(merge((yyvsp[-3].e), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3993 "parser.c"
    break;

  case 260:
#line 379 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, n_message, (yyvsp[-1].e), NUMBER); }
#line 3999 "parser.c"
    break;

  case 261:
#line 380 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("user"), LINE, n_user, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4005 "parser.c"
    break;

  case 262:
#line 381 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("welcome"), LINE, n_welcome, (yyvsp[-1].e), NUMBER); }
#line 4011 "parser.c"
    break;

  case 263:
#line 382 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("welcome"), LINE, n_welcome, NULL, NUMBER); }
#line 4017 "parser.c"
    break;

  case 264:
#line 383 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("working"), LINE, n_working, (yyvsp[-1].e), NUMBER); }
#line 4023 "parser.c"
    break;

  case 265:
#line 384 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("working"), LINE, n_working, NULL, NUMBER); }
#line 4029 "parser.c"
    break;

  case 266:
#line 388 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("AND"), LINE, n_and, (yyvsp[-1].e), NUMBER); }
#line 4035 "parser.c"
    break;

  case 267:
#line 389 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITAND"), LINE, n_bitand, (yyvsp[-1].e), NUMBER); }
#line 4041 "parser.c"
    break;

  case 268:
#line 390 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITNOT"), LINE, n_bitnot, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4047 "parser.c"
    break;

  case 269:
#line 391 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITOR"), LINE, n_bitor, (yyvsp[-1].e), NUMBER); }
#line 4053 "parser.c"
    break;

  case 270:
#line 392 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITXOR"), LINE, n_bitxor, (yyvsp[-1].e), NUMBER); }
#line 4059 "parser.c"
    break;

  case 271:
#line 393 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("NOT"), LINE, n_not, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4065 "parser.c"
    break;

  case 272:
#line 394 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("IN"), LINE, n_in, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4071 "parser.c"
    break;

  case 273:
#line 395 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("OR"), LINE, n_or, (yyvsp[-1].e), NUMBER); }
#line 4077 "parser.c"
    break;

  case 274:
#line 396 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("shiftleft"), LINE, n_shiftleft, (yyvsp[-1].e), NUMBER); }
#line 4083 "parser.c"
    break;

  case 275:
#line 397 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("shiftright"), LINE, n_shiftright, (yyvsp[-1].e), NUMBER); }
#line 4089 "parser.c"
    break;

  case 276:
#line 398 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("XOR"), LINE, n_xor, (yyvsp[-1].e), NUMBER); }
#line 4095 "parser.c"
    break;

  case 277:
#line 402 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("closemedia"), LINE, n_closemedia, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4101 "parser.c"
    break;

  case 278:
#line 403 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("effect"), LINE, n_effect, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4107 "parser.c"
    break;

  case 279:
#line 404 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("setmedia"), LINE, n_setmedia, (yyvsp[-1].e), NUMBER); }
#line 4113 "parser.c"
    break;

  case 280:
#line 405 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("setmedia"), LINE, n_setmedia, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4119 "parser.c"
    break;

  case 281:
#line 406 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("showmedia"), LINE, n_showmedia, merge(merge((yyvsp[-3].e), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4125 "parser.c"
    break;

  case 282:
#line 410 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("database"), LINE, n_database, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4131 "parser.c"
    break;

  case 283:
#line 411 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("database"), LINE, n_database, (yyvsp[-1].e), STRING); }
#line 4137 "parser.c"
    break;

  case 284:
#line 412 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("earlier"), LINE, n_earlier, (yyvsp[-1].e), NUMBER); }
#line 4143 "parser.c"
    break;

  case 285:
#line 413 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getassign"), LINE, n_getassign, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4149 "parser.c"
    break;

  case 286:
#line 414 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getassign"), LINE, n_getassign, (yyvsp[-1].e), STRING); }
#line 4155 "parser.c"
    break;

  case 287:
#line 415 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getdevice"), LINE, n_getdevice, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4161 "parser.c"
    break;

  case 288:
#line 416 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getdiskspace"), LINE, n_getdiskspace, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4167 "parser.c"
    break;

  case 289:
#line 417 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getdiskspace"), LINE, n_getdiskspace, (yyvsp[-1].e), NUMBER); }
#line 4173 "parser.c"
    break;

  case 290:
#line 418 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getenv"), LINE, n_getenv, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4179 "parser.c"
    break;

  case 291:
#line 419 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getsize"), LINE, n_getsize, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4185 "parser.c"
    break;

  case 292:
#line 420 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getsum"), LINE, n_getsum, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4191 "parser.c"
    break;

  case 293:
#line 421 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getversion"), LINE, n_getversion, NULL, NUMBER); }
#line 4197 "parser.c"
    break;

  case 294:
#line 422 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getversion"), LINE, n_getversion, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4203 "parser.c"
    break;

  case 295:
#line 423 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getversion"), LINE, n_getversion, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4209 "parser.c"
    break;

  case 296:
#line 424 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("iconinfo"), LINE, n_iconinfo, (yyvsp[-1].e), NUMBER); }
#line 4215 "parser.c"
    break;

  case 297:
#line 425 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("querydisplay"), LINE, n_querydisplay, (yyvsp[-1].e), NUMBER); }
#line 4221 "parser.c"
    break;

  case 298:
#line 429 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, n_procedure, push(new_contxt(), new_custom((yyvsp[-3].s), LINE, (yyvsp[-2].e), (yyvsp[-1].e))), NUMBER); }
#line 4227 "parser.c"
    break;

  case 299:
#line 430 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, n_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, (yyvsp[-1].e), NULL)), NUMBER); }
#line 4233 "parser.c"
    break;

  case 300:
#line 431 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, n_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, NULL, (yyvsp[-1].e))), NUMBER); }
#line 4239 "parser.c"
    break;

  case 301:
#line 432 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, n_procedure, push(new_contxt(), new_custom((yyvsp[-1].s), LINE, NULL, NULL)), NUMBER); }
#line 4245 "parser.c"
    break;

  case 302:
#line 433 "../src/parser.y"
                                                 { (yyval.e) = new_cusref((yyvsp[-2].s), LINE, (yyvsp[-1].e)); }
#line 4251 "parser.c"
    break;

  case 303:
#line 434 "../src/parser.y"
                                                 { (yyval.e) = new_cusref((yyvsp[-1].s), LINE, NULL); }
#line 4257 "parser.c"
    break;

  case 304:
#line 438 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askbool"), LINE, n_askbool, NULL, NUMBER); }
#line 4263 "parser.c"
    break;

  case 305:
#line 439 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askbool"), LINE, n_askbool, (yyvsp[-1].e), NUMBER); }
#line 4269 "parser.c"
    break;

  case 306:
#line 440 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askchoice"), LINE, n_askchoice, (yyvsp[-1].e), NUMBER); }
#line 4275 "parser.c"
    break;

  case 307:
#line 441 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askdir"), LINE, n_askdir, NULL, STRING); }
#line 4281 "parser.c"
    break;

  case 308:
#line 442 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askdir"), LINE, n_askdir, (yyvsp[-1].e), STRING); }
#line 4287 "parser.c"
    break;

  case 309:
#line 443 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askdisk"), LINE, n_askdisk, (yyvsp[-1].e), NUMBER); }
#line 4293 "parser.c"
    break;

  case 310:
#line 444 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askfile"), LINE, n_askfile, NULL, STRING); }
#line 4299 "parser.c"
    break;

  case 311:
#line 445 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askfile"), LINE, n_askfile, (yyvsp[-1].e), STRING); }
#line 4305 "parser.c"
    break;

  case 312:
#line 446 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("asknumber"), LINE, n_asknumber, NULL, NUMBER); }
#line 4311 "parser.c"
    break;

  case 313:
#line 447 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("asknumber"), LINE, n_asknumber, (yyvsp[-1].e), NUMBER); }
#line 4317 "parser.c"
    break;

  case 314:
#line 448 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askoptions"), LINE, n_askoptions, (yyvsp[-1].e), NUMBER); }
#line 4323 "parser.c"
    break;

  case 315:
#line 449 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askstring"), LINE, n_askstring, NULL, STRING); }
#line 4329 "parser.c"
    break;

  case 316:
#line 450 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askstring"), LINE, n_askstring, (yyvsp[-1].e), STRING); }
#line 4335 "parser.c"
    break;

  case 317:
#line 454 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("cat"), LINE, n_cat, (yyvsp[-1].e), STRING); }
#line 4341 "parser.c"
    break;

  case 318:
#line 455 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("expandpath"), LINE, n_expandpath, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4347 "parser.c"
    break;

  case 319:
#line 456 "../src/parser.y"
                                                 { (yyval.e) = new_native((yyvsp[-2].s), LINE, n_fmt, (yyvsp[-1].e), STRING); }
#line 4353 "parser.c"
    break;

  case 320:
#line 457 "../src/parser.y"
                                                 { (yyval.e) = new_native((yyvsp[-1].s), LINE, n_fmt, NULL, STRING); }
#line 4359 "parser.c"
    break;

  case 321:
#line 458 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("pathonly"), LINE, n_pathonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4365 "parser.c"
    break;

  case 322:
#line 459 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("patmatch"), LINE, n_patmatch, (yyvsp[-1].e), NUMBER); }
#line 4371 "parser.c"
    break;

  case 323:
#line 460 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("strlen"), LINE, n_strlen, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4377 "parser.c"
    break;

  case 324:
#line 461 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("substr"), LINE, n_substr, (yyvsp[-1].e), STRING); }
#line 4383 "parser.c"
    break;

  case 325:
#line 462 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("substr"), LINE, n_substr, push((yyvsp[-2].e), (yyvsp[-1].e)), STRING); }
#line 4389 "parser.c"
    break;

  case 326:
#line 463 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("tackon"), LINE, n_tackon, (yyvsp[-1].e), STRING); }
#line 4395 "parser.c"
    break;

  case 327:
#line 467 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("set"), LINE, n_set, (yyvsp[-1].e), DANGLE); }
#line 4401 "parser.c"
    break;

  case 328:
#line 468 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("symbolset"), LINE, n_symbolset, (yyvsp[-1].e), DANGLE); }
#line 4407 "parser.c"
    break;

  case 329:
#line 469 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("symbolval"), LINE, n_symbolval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4413 "parser.c"
    break;

  case 330:
#line 473 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, n_openwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4419 "parser.c"
    break;

  case 331:
#line 474 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, n_openwbobject, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4425 "parser.c"
    break;

  case 332:
#line 475 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, n_openwbobject, merge(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4431 "parser.c"
    break;

  case 333:
#line 476 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, n_openwbobject, merge(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4437 "parser.c"
    break;

  case 334:
#line 477 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("showwbobject"), LINE, n_showwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4443 "parser.c"
    break;

  case 335:
#line 478 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("closewbobject"), LINE, n_closewbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4449 "parser.c"
    break;

  case 336:
#line 482 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("all"), OPT_ALL, NULL); }
#line 4455 "parser.c"
    break;

  case 337:
#line 483 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("append"), OPT_APPEND, (yyvsp[-1].e)); }
#line 4461 "parser.c"
    break;

  case 338:
#line 484 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); }
#line 4467 "parser.c"
    break;

  case 339:
#line 485 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("back"), OPT_BACK, (yyvsp[-1].e)); }
#line 4473 "parser.c"
    break;

  case 340:
#line 486 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("choices"), OPT_CHOICES, (yyvsp[-1].e)); }
#line 4479 "parser.c"
    break;

  case 341:
#line 487 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("command"), OPT_COMMAND, (yyvsp[-1].e)); }
#line 4485 "parser.c"
    break;

  case 342:
#line 488 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("compression"), OPT_COMPRESSION, NULL); }
#line 4491 "parser.c"
    break;

  case 343:
#line 489 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, push(new_contxt(), (yyvsp[-1].e))); }
#line 4497 "parser.c"
    break;

  case 344:
#line 490 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, NULL); }
#line 4503 "parser.c"
    break;

  case 345:
#line 491 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), (yyvsp[-1].e))); }
#line 4509 "parser.c"
    break;

  case 346:
#line 492 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, (yyvsp[-1].e)); }
#line 4515 "parser.c"
    break;

  case 347:
#line 493 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4521 "parser.c"
    break;

  case 348:
#line 494 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), (yyvsp[-1].e))); }
#line 4527 "parser.c"
    break;

  case 349:
#line 495 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("disk"), OPT_DISK, NULL); }
#line 4533 "parser.c"
    break;

  case 350:
#line 496 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("files"), OPT_FILES, NULL); }
#line 4539 "parser.c"
    break;

  case 351:
#line 497 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("fonts"), OPT_FONTS, NULL); }
#line 4545 "parser.c"
    break;

  case 352:
#line 498 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4551 "parser.c"
    break;

  case 353:
#line 499 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("getposition"), OPT_GETPOSITION, (yyvsp[-1].e)); }
#line 4557 "parser.c"
    break;

  case 354:
#line 500 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4563 "parser.c"
    break;

  case 355:
#line 501 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, (yyvsp[-1].e)); }
#line 4569 "parser.c"
    break;

  case 356:
#line 502 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("help"), OPT_HELP, (yyvsp[-1].e)); }
#line 4575 "parser.c"
    break;

  case 357:
#line 503 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("help"), OPT_HELP, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4581 "parser.c"
    break;

  case 358:
#line 504 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("infos"), OPT_INFOS, NULL); }
#line 4587 "parser.c"
    break;

  case 359:
#line 505 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4593 "parser.c"
    break;

  case 360:
#line 506 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), (yyvsp[-1].e))); }
#line 4599 "parser.c"
    break;

  case 361:
#line 507 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("newpath"), OPT_NEWPATH, NULL); }
#line 4605 "parser.c"
    break;

  case 362:
#line 508 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); }
#line 4611 "parser.c"
    break;

  case 363:
#line 509 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); }
#line 4617 "parser.c"
    break;

  case 364:
#line 510 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("noreq"), OPT_NOREQ, NULL); }
#line 4623 "parser.c"
    break;

  case 365:
#line 511 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), (yyvsp[-1].e))); }
#line 4629 "parser.c"
    break;

  case 366:
#line 512 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("prompt"), OPT_PROMPT, (yyvsp[-1].e)); }
#line 4635 "parser.c"
    break;

  case 367:
#line 513 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("quiet"), OPT_QUIET, NULL); }
#line 4641 "parser.c"
    break;

  case 368:
#line 514 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("range"), OPT_RANGE, (yyvsp[-1].e)); }
#line 4647 "parser.c"
    break;

  case 369:
#line 515 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("safe"), OPT_SAFE, NULL); }
#line 4653 "parser.c"
    break;

  case 370:
#line 516 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4659 "parser.c"
    break;

  case 371:
#line 517 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("setposition"), OPT_SETPOSITION, (yyvsp[-1].e)); }
#line 4665 "parser.c"
    break;

  case 372:
#line 518 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4671 "parser.c"
    break;

  case 373:
#line 519 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, (yyvsp[-1].e)); }
#line 4677 "parser.c"
    break;

  case 374:
#line 520 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4683 "parser.c"
    break;

  case 375:
#line 521 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4689 "parser.c"
    break;

  case 376:
#line 522 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4695 "parser.c"
    break;

  case 377:
#line 523 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); }
#line 4701 "parser.c"
    break;

  case 378:
#line 524 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, (yyvsp[-1].e)); }
#line 4707 "parser.c"
    break;

  case 379:
#line 525 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4713 "parser.c"
    break;

  case 380:
#line 526 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("resident"), OPT_RESIDENT, NULL); }
#line 4719 "parser.c"
    break;

  case 381:
#line 527 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4725 "parser.c"
    break;

  case 382:
#line 528 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4731 "parser.c"
    break;

  case 383:
#line 529 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(push(new_contxt(), (yyvsp[-3].e)), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4737 "parser.c"
    break;


#line 4741 "parser.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
#line 531 "../src/parser.y"

