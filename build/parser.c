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
    OPTIONS = 279,
    EXECUTE = 280,
    REXX = 281,
    RUN = 282,
    ABORT = 283,
    EXIT = 284,
    ONERROR = 285,
    TRAP = 286,
    REBOOT = 287,
    COPYFILES = 288,
    COPYLIB = 289,
    DELETE = 290,
    EXISTS = 291,
    FILEONLY = 292,
    FOREACH = 293,
    MAKEASSIGN = 294,
    MAKEDIR = 295,
    PROTECT = 296,
    STARTUP = 297,
    TEXTFILE = 298,
    TOOLTYPE = 299,
    TRANSCRIPT = 300,
    RENAME = 301,
    COMPLETE = 302,
    DEBUG = 303,
    MESSAGE = 304,
    USER = 305,
    WELCOME = 306,
    WORKING = 307,
    AND = 308,
    BITAND = 309,
    BITNOT = 310,
    BITOR = 311,
    BITXOR = 312,
    NOT = 313,
    IN = 314,
    OR = 315,
    SHIFTLEFT = 316,
    SHIFTRIGHT = 317,
    XOR = 318,
    CLOSEMEDIA = 319,
    EFFECT = 320,
    SETMEDIA = 321,
    SHOWMEDIA = 322,
    DATABASE = 323,
    EARLIER = 324,
    GETASSIGN = 325,
    GETDEVICE = 326,
    GETDISKSPACE = 327,
    GETENV = 328,
    GETSIZE = 329,
    GETSUM = 330,
    GETVERSION = 331,
    ICONINFO = 332,
    QUERYDISPLAY = 333,
    CUS = 334,
    DCL = 335,
    ASKBOOL = 336,
    ASKCHOICE = 337,
    ASKDIR = 338,
    ASKDISK = 339,
    ASKFILE = 340,
    ASKNUMBER = 341,
    ASKOPTIONS = 342,
    ASKSTRING = 343,
    CAT = 344,
    EXPANDPATH = 345,
    FMT = 346,
    PATHONLY = 347,
    PATMATCH = 348,
    STRLEN = 349,
    SUBSTR = 350,
    TACKON = 351,
    SET = 352,
    SYMBOLSET = 353,
    SYMBOLVAL = 354,
    OPENWBOBJECT = 355,
    SHOWWBOBJECT = 356,
    CLOSEWBOBJECT = 357,
    ALL = 358,
    APPEND = 359,
    ASSIGNS = 360,
    BACK = 361,
    CHOICES = 362,
    COMMAND = 363,
    COMPRESSION = 364,
    CONFIRM = 365,
    DEFAULT = 366,
    DELOPTS = 367,
    DEST = 368,
    DISK = 369,
    FILES = 370,
    FONTS = 371,
    GETDEFAULTTOOL = 372,
    GETPOSITION = 373,
    GETSTACK = 374,
    GETTOOLTYPE = 375,
    HELP = 376,
    INFOS = 377,
    INCLUDE = 378,
    NEWNAME = 379,
    NEWPATH = 380,
    NOGAUGE = 381,
    NOPOSITION = 382,
    NOREQ = 383,
    PATTERN = 384,
    PROMPT = 385,
    QUIET = 386,
    RANGE = 387,
    SAFE = 388,
    SETDEFAULTTOOL = 389,
    SETPOSITION = 390,
    SETSTACK = 391,
    SETTOOLTYPE = 392,
    SOURCE = 393,
    SWAPCOLORS = 394,
    OPTIONAL = 395,
    RESIDENT = 396,
    OVERRIDE = 397
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
#define YYFINAL  289
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2288

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  152
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  158
/* YYNRULES -- Number of rules.  */
#define YYNRULES  377
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  730

#define YYUNDEFTOK  2
#define YYMAXUTOK   397


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
     143,   144,   147,   145,     2,   148,     2,   146,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     151,   149,   150,     2,     2,     2,     2,     2,     2,     2,
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
     135,   136,   137,   138,   139,   140,   141,   142
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
     264,   265,   266,   267,   268,   269,   270,   274,   275,   276,
     277,   281,   282,   283,   284,   285,   286,   290,   291,   292,
     293,   294,   295,   296,   297,   301,   302,   303,   304,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   323,   324,   325,   326,   327,   328,   329,   331,   332,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   399,   400,   401,   402,   403,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   426,   427,   428,   429,   430,
     431,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   464,   465,   466,   470,   471,   472,
     473,   474,   475,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SYM", "STR", "OOM", "INT", "HEX", "BIN",
  "EQ", "GT", "GTE", "LT", "LTE", "NEQ", "IF", "SELECT", "UNTIL", "WHILE",
  "TRACE", "RETRACE", "ASTRAW", "ASBRAW", "ASBEVAL", "OPTIONS", "EXECUTE",
  "REXX", "RUN", "ABORT", "EXIT", "ONERROR", "TRAP", "REBOOT", "COPYFILES",
  "COPYLIB", "DELETE", "EXISTS", "FILEONLY", "FOREACH", "MAKEASSIGN",
  "MAKEDIR", "PROTECT", "STARTUP", "TEXTFILE", "TOOLTYPE", "TRANSCRIPT",
  "RENAME", "COMPLETE", "DEBUG", "MESSAGE", "USER", "WELCOME", "WORKING",
  "AND", "BITAND", "BITNOT", "BITOR", "BITXOR", "NOT", "IN", "OR",
  "SHIFTLEFT", "SHIFTRIGHT", "XOR", "CLOSEMEDIA", "EFFECT", "SETMEDIA",
  "SHOWMEDIA", "DATABASE", "EARLIER", "GETASSIGN", "GETDEVICE",
  "GETDISKSPACE", "GETENV", "GETSIZE", "GETSUM", "GETVERSION", "ICONINFO",
  "QUERYDISPLAY", "CUS", "DCL", "ASKBOOL", "ASKCHOICE", "ASKDIR",
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
  "add", "div", "mul", "sub", "eq", "gt", "gte", "lt", "lte", "neq", "if",
  "select", "until", "while", "trace", "retrace", "astraw", "asbraw",
  "asbeval", "options", "execute", "rexx", "run", "abort", "exit",
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
     395,   396,   397,    40,    41,    43,    47,    42,    45,    61,
      62,    60
};
# endif

#define YYPACT_NINF (-397)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -140,  1185,    52,  -397,  -397,  -140,  -140,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,    11,    17,
      94,    94,    94,    94,    94,    94,    94,  -118,   -67,   -41,
      94,    94,   -33,   572,   572,   572,    94,    53,  -140,    94,
      -5,     1,     1,   572,    94,    94,    94,    94,   572,    94,
     572,     1,     1,    94,    94,    94,    60,   572,    94,    88,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,   110,     1,    94,   150,  -111,     1,
    -109,     1,  -107,  -105,     1,  -101,    94,    94,    94,    94,
      94,    94,    94,   159,    94,    94,   572,    94,    94,    33,
      94,    35,  -140,    94,    94,    45,   119,    94,    94,    94,
      47,    49,    51,    94,    94,    94,    94,   128,    54,    94,
      94,    63,    82,    86,    91,    94,    94,   117,    94,   126,
      94,    94,    94,    94,    94,   137,    94,   145,    94,    94,
      94,    94,    94,    94,    94,    94,   182,   -99,   -95,  -397,
    -140,  -140,  -140,  -140,  -397,  -397,  -397,  -397,  -397,  -397,
    1781,  -397,  -397,   240,  -397,  -397,  -397,   252,    94,   186,
     188,   194,   270,   201,   206,   579,  -140,  -140,  -397,  -397,
    -397,   215,   232,  -397,  1334,   291,   572,   297,   572,   303,
     572,   315,  1483,  -397,   396,   422,   -74,  -140,  -397,  2145,
     -72,   -68,   -63,   572,   -61,   238,  -140,   445,   -59,   -57,
     572,   457,   -55,     1,   469,   -38,   -34,   475,   -24,   241,
    -397,   481,   512,   572,   264,  -397,   704,   772,   780,   267,
     268,   271,   272,   273,    94,   804,   274,   276,   277,   278,
      94,   821,    94,   883,   279,   288,   889,   289,   292,   935,
     293,   295,   299,   300,  -397,   -15,    -6,   301,     5,  -397,
      -2,     3,  -397,    13,    15,  -397,    23,  -397,    26,    32,
    -397,    42,   968,   310,   311,   312,   313,   974,   322,    94,
       8,  -397,  1031,   323,    57,   572,   324,   325,  -397,  1047,
    -397,    62,  1592,  1598,  -397,  -397,   326,   347,  1604,   348,
    -397,  -397,  -397,   350,   351,   352,   354,  -397,  1612,  -397,
     355,   358,  -397,  -397,  -397,  -397,   359,  1746,  -397,   361,
    -397,   362,   364,   365,  1754,   366,   368,  -397,  1763,  -397,
     369,  1896,   378,  1905,   379,   380,   381,   382,  -397,  -397,
    -397,    94,   182,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    1185,  -397,  -397,    66,   579,  -397,  -397,  1930,  -397,  1911,
      68,    70,  -397,  -397,    85,  -397,    90,  2030,     1,  -397,
      96,  2038,  -397,   106,  2053,  -397,  -397,   384,  -397,  2059,
    -397,   108,    94,  -397,  -397,  -397,   121,   123,  -119,  -397,
     385,   387,  -397,   125,  1632,  -397,   388,   401,  -397,   391,
    -397,   136,   140,  -397,   142,  -397,   170,   191,  -397,   197,
    -397,  -397,  -397,  -397,   200,  -397,  -397,  -397,   204,  2079,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  2085,
    -397,  -397,  -397,  -397,  -397,   392,  -397,   394,    94,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
     400,  -397,   399,  -397,  -397,  -397,  -397,   402,     7,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,   403,  -397,  -397,    94,  -397,  -397,    94,
    -397,  -397,   211,   224,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  2091,
    2097,  -397,   226,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
     228,  -397,  -397,   231,  -397,  -397,   235,  -397,  -397,  -397,
       1,  -397,  -397,   237,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,   244,  -397,  -397,  -397,  -397,   248,  -397,  -397,  -397,
     250,  -397,  -397,  -397,  2103,  -397,  -397,  -397,  -397,   404,
    -397,  -397,  -397,  -397,  -397,   263,  -397,   406,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     2,    16,     3,     0,    19,    11,    79,
      80,    81,    82,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   117,   116,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   154,   153,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    58,    57,    59,    60,
      61,    62,    63,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    64,    78,    65,    77,     0,     0,
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
       0,     0,     0,     0,     0,     0,    16,     0,     0,     1,
      13,    14,    15,    18,    30,    29,    31,    26,    27,    28,
       0,   300,     8,     0,     4,     5,   317,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,   194,
     195,     0,     0,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   216,     0,     0,     0,     0,   218,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,     0,     0,     0,     0,   261,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   290,     0,     0,     0,     0,   301,
       0,     0,   304,     0,     0,   307,     0,   309,     0,     0,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,   333,     0,
     335,     0,     0,     0,   339,   341,     0,     0,     0,     0,
     345,   346,   347,     0,     0,     0,     0,   353,     0,   354,
       0,     0,   357,   358,   359,   360,     0,     0,   363,     0,
     365,     0,     0,     0,     0,     0,     0,   372,     0,   374,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    17,
      20,     0,     0,   299,     7,   316,     6,   183,   185,   186,
       0,   189,    23,     0,    36,   188,   187,     0,    24,     0,
       0,     0,   196,   197,     0,   202,     0,     0,    18,   206,
       0,     0,   210,     0,     0,   211,   215,     0,   214,     0,
     217,     0,     0,   220,   221,   225,     0,     0,     0,   226,
       0,     0,   229,     0,     0,   234,     0,     0,   232,     0,
     238,     0,     0,   242,     0,   240,     0,     0,   246,     0,
     247,   248,   249,   251,     0,   252,   253,   258,     0,     0,
     259,   260,   262,   263,   264,   265,   266,   267,   268,     0,
     270,   271,   272,   273,   274,     0,   276,     0,     0,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
       0,   291,     0,   293,   294,    35,   298,     0,     0,   302,
     303,   305,   306,   308,   310,   311,   313,   314,   315,   318,
     319,   320,   321,     0,   323,    33,     0,   324,   325,     0,
     326,   327,     0,     0,   331,   332,   334,   336,   337,   338,
     340,   342,   343,   344,   348,   349,   350,   351,   352,   355,
     356,   361,   362,   364,   366,   367,   368,   370,   369,   371,
     373,   375,   177,   178,   179,   180,   181,   182,   184,     0,
       0,   376,     0,    37,   190,    25,   191,   192,   199,   200,
       0,   203,   204,     0,   207,   208,     0,   212,   213,   219,
       0,   222,   223,     0,   227,   228,   230,   233,   231,   235,
     236,     0,   241,   239,   243,   244,     0,   250,   255,   256,
       0,   269,   275,   277,     0,   292,   297,    34,   296,     0,
     322,    32,     9,   328,   329,     0,    21,     0,   377,   201,
     205,   209,   224,   237,   245,   257,   278,   295,   330,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -397,  -397,  -396,   489,   815,  -136,  -397,    73,    40,     0,
    -311,  -397,  -116,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,   207,  -397,  -397,  -160,  -397,  -131,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,   157,  -397,  -397
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   302,   309,   303,   422,   304,   290,   508,
     494,   499,   305,   420,   598,   313,   314,     7,     8,     9,
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
     140,   141,   142,   143,   144,   145,   146,   147
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,   288,   597,     1,   498,   291,   293,   335,   595,   264,
     707,   616,   267,   307,   294,   295,   296,   297,   298,   299,
     294,   295,   296,   297,   298,   299,   318,   325,   327,   329,
     331,   334,   339,   399,   339,   402,   339,   405,   339,   407,
       5,   287,   339,   410,     1,   479,   292,   357,     1,   480,
     361,   362,   289,   366,   367,   368,   294,   295,   296,   297,
     298,   299,   375,   294,   295,   296,   297,   298,   299,     1,
     520,   339,   523,     4,   286,   339,   524,   319,     4,     4,
     339,   525,   528,   529,   537,   538,   339,   540,   339,   545,
     412,   294,   295,   296,   297,   298,   299,   294,   295,   296,
     297,   298,   299,   320,   429,   339,   550,   432,   433,   339,
     551,   323,   438,   294,   295,   296,   297,   298,   299,   339,
     553,   448,   294,   295,   296,   297,   298,   299,   590,   591,
     457,   294,   295,   296,   297,   298,   299,   339,   593,   338,
     468,   339,   599,   471,   339,   473,   339,   600,     1,   596,
       1,   708,   617,   398,   300,   301,   339,   601,   339,   602,
     300,   306,   419,   326,   328,   330,   339,   603,     6,   339,
     604,   340,   341,   343,   517,   339,   605,   428,   350,   430,
     354,   355,   356,   663,   531,   339,   606,   363,   665,   434,
     507,   440,   511,   441,   514,   442,   332,   333,   449,   519,
     339,   621,   709,   300,   360,     1,   627,   452,   336,   339,
     661,     1,   666,     1,   667,   396,   536,   539,   400,   401,
     403,   404,   406,   408,   409,   411,   453,   559,   339,   480,
     454,   300,   365,   339,   668,   455,   425,   300,   569,   339,
     671,     4,     6,   294,   295,   296,   297,   298,   299,   339,
     674,     1,   679,   300,   394,   294,   295,   296,   297,   298,
     299,   458,   300,   435,   339,   681,   339,   682,     1,   686,
     460,   300,   447,   294,   295,   296,   297,   298,   299,   339,
     689,   467,   431,   339,   690,   339,   692,   291,   293,   469,
     291,   293,   291,   293,   294,   295,   296,   297,   298,   299,
     294,   295,   296,   297,   298,   299,   294,   295,   296,   297,
     298,   299,   493,   339,   693,     4,     6,     6,   294,   295,
     296,   297,   298,   299,   504,   506,   478,   510,   292,   513,
     487,   292,   488,   292,   339,   694,   291,     6,   489,   504,
     339,   695,   526,   339,   697,   495,     6,   339,   698,   541,
     496,   544,   546,   547,   339,   713,   500,   501,   554,   502,
       4,     4,   558,     4,     4,     4,     4,   339,   714,   339,
     718,   339,   719,   482,   339,   720,   503,   521,   339,   721,
     339,   722,   532,   300,   483,   555,   533,   339,   723,     4,
       4,   339,   724,   339,   725,   300,   485,   482,     6,   294,
     295,   296,   297,   298,   299,   482,   339,   728,   560,     4,
       4,   564,   565,   490,   491,   566,   567,   568,   571,     4,
     572,   573,   574,   580,   622,   294,   295,   296,   297,   298,
     299,   291,   581,   583,   324,   505,   584,   586,     5,   587,
     324,   509,   704,   588,   589,   594,   324,   512,   294,   295,
     296,   297,   298,   299,   608,   609,   610,   611,   300,   515,
     294,   295,   296,   297,   298,   299,   614,   620,   624,   625,
     630,     4,   294,   295,   296,   297,   298,   299,   294,   295,
     296,   297,   298,   299,   294,   295,   296,   297,   298,   299,
     288,   631,   633,   662,   634,   635,   636,     6,   637,   639,
     291,   291,   640,   641,     4,   643,   644,   670,   645,   646,
     648,   673,   649,   651,   676,   294,   295,   296,   297,   298,
     299,   291,   653,   655,   656,   657,   658,   683,   677,   684,
     660,   685,   687,   291,   269,   688,   702,   660,   703,   332,
     516,   277,   691,   705,   717,     0,   706,   710,   727,   696,
     729,   530,   592,     0,     0,     0,     0,     0,     0,   700,
       0,     0,     0,   286,     0,   300,   518,     0,     0,     0,
     286,     0,     0,     4,     4,   294,   295,   296,   297,   298,
     299,     0,   294,   295,   296,   297,   298,   299,   534,   535,
       0,     0,     0,     0,     4,     0,     0,     0,     6,     0,
     324,   543,     0,     0,     0,     0,     4,   482,     0,     0,
       0,     0,   324,   548,     0,     0,     0,     0,   300,   552,
       0,     0,     0,   715,   300,   556,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,   308,
     308,   308,   312,   315,   316,   317,     0,     0,     0,   321,
     322,     0,     0,     0,     0,   324,   557,     0,   337,     0,
     291,     0,   342,   344,   345,   308,   347,   349,   351,   353,
       0,     4,     0,   308,   359,     0,     0,   364,     0,     0,
     493,   308,   370,   308,   308,   373,   374,     0,   308,   308,
     308,   379,   308,   308,   308,   383,   308,   386,   388,   389,
     391,   392,   393,   395,     0,   308,     0,   294,   295,   296,
     297,   298,   299,     0,     0,   324,   413,   414,   308,   416,
     308,   308,   497,   308,   423,   424,   426,   427,     0,     0,
       0,     0,     0,     4,     0,   436,   437,     0,   439,     0,
       0,     0,   443,   308,   445,   308,     0,     0,   450,   451,
       0,     0,     0,     0,   456,     0,     0,   308,     0,   461,
     308,   463,   464,   466,     0,     0,     0,   470,     0,   308,
       0,   308,   308,   308,   308,   294,   295,   296,   297,   298,
     299,     0,     0,   294,   295,   296,   297,   298,   299,     0,
       0,     0,   484,     0,     0,     0,   484,   486,     0,     0,
       0,   492,     0,     0,   492,     0,     0,   294,   295,   296,
     297,   298,   299,     0,   484,     0,   484,     0,   484,     0,
     484,     0,     0,   484,   294,   295,   296,   297,   298,   299,
       0,     0,   527,     0,     0,     0,   486,     0,     0,   542,
     486,     0,     0,   549,     0,     0,   484,   300,   561,     0,
     484,   484,     0,     0,     0,   484,   484,   484,     0,     0,
       0,     0,     0,     0,   484,     0,     0,     0,     0,   308,
     577,   308,   486,     0,     0,   486,     0,     0,   486,     0,
       0,     0,     0,     0,     0,     0,   294,   295,   296,   297,
     298,   299,   294,   295,   296,   297,   298,   299,     0,     0,
       0,   484,     0,     0,     0,     0,   613,     0,   615,     0,
       0,   619,     0,     0,   623,   300,   562,     0,   484,     0,
       0,   484,   484,   300,   563,     0,     0,   484,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,   294,   295,
     296,   297,   298,   299,     0,     0,   484,   300,   570,     0,
       0,     0,     0,   486,     0,     0,     0,   484,     0,     0,
     484,     0,   484,     0,   300,   576,   310,   311,     0,     0,
     659,   294,   295,   296,   297,   298,   299,   294,   295,   296,
     297,   298,   299,   492,     0,     0,     0,     0,   492,     0,
       0,   346,   348,     0,   352,     0,   484,     0,     0,   358,
     484,     0,     0,   484,     0,     0,     0,   369,   484,   371,
     372,   680,     0,     0,   376,   377,   378,     0,   380,   381,
     382,   384,   385,   387,     0,   390,   300,   579,     0,     0,
       0,   397,   300,   582,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   415,     0,   417,   418,   484,   421,
     294,   295,   296,   297,   298,   299,     0,     0,   484,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   444,
       0,   446,     0,     0,     0,     0,     0,     0,   300,   585,
       0,     0,     0,   459,     0,     0,   462,     0,   465,     0,
       0,     0,     0,     0,     0,   472,     0,   474,   475,   476,
     477,     0,     0,     0,     0,   711,     0,     0,   712,     0,
       0,   300,   607,     0,     0,     0,     0,   300,   612,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   492,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   300,   618,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   149,
     300,   626,     0,   484,     0,   575,   150,   578,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,     0,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,     0,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,     1,     0,
     279,   280,   281,   282,   283,   284,   285,   148,   149,     0,
       0,     0,     0,     0,     0,   150,     0,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,     0,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   324,     0,   279,
     280,   281,   282,   283,   284,   285,   148,   149,     0,     0,
       0,     0,     0,     0,   150,     0,   151,   152,   481,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,     0,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   294,   295,   296,   297,   298,
     299,   294,   295,   296,   297,   298,   299,   294,   295,   296,
     297,   298,   299,     0,   267,   294,   295,   296,   297,   298,
     299,     0,     0,     0,     0,     0,   300,     0,   279,   280,
     281,   282,   283,   284,   285,   148,   149,     0,     0,     0,
       0,     0,     0,   150,     0,   151,   152,   481,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,     0,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,     0,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   300,   628,     0,     0,     0,
       0,   300,   629,     0,     0,     0,     0,   300,   632,   294,
     295,   296,   297,   298,   299,   300,   638,   294,   295,   296,
     297,   298,   299,     0,     0,   269,   294,   295,   296,   297,
     298,   299,     0,     0,     0,   300,     0,   279,   280,   281,
     282,   283,   284,   285,   148,   149,     0,     0,     0,     0,
       0,     0,   150,     0,   151,   152,   481,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
       0,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,     0,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   300,
     642,     0,     0,     0,     0,     0,     0,   300,   647,   294,
     295,   296,   297,   298,   299,     0,   300,   650,   294,   295,
     296,   297,   298,   299,   294,   295,   296,   297,   298,   299,
       0,     0,     0,     0,   300,     0,   279,   280,   281,   282,
     283,   284,   285,   148,   149,     0,     0,     0,     0,     0,
       0,   150,     0,   151,   152,   481,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,     0,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   294,   295,   296,   297,   298,   299,   300,
     652,   294,   295,   296,   297,   298,   299,     0,   300,   654,
       0,     0,     0,     0,   497,   664,   294,   295,   296,   297,
     298,   299,   294,   295,   296,   297,   298,   299,     0,     0,
       0,     0,     0,     1,     0,   279,   280,   281,   282,   283,
     284,   285,   294,   295,   296,   297,   298,   299,   294,   295,
     296,   297,   298,   299,   294,   295,   296,   297,   298,   299,
     294,   295,   296,   297,   298,   299,   294,   295,   296,   297,
     298,   299,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     522,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   324,   669,     0,     0,     0,     0,     0,
       0,   324,   672,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   324,   675,     0,     0,
       0,     0,   300,   678,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   324,   699,     0,     0,     0,     0,   300,   701,
       0,     0,     0,     0,   497,   491,     0,     0,     0,     0,
       1,   716,     0,     0,     0,     0,   300,   726,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   339
};

static const yytype_int16 yycheck[] =
{
       0,     1,   398,   143,   315,     5,     6,   167,     3,   128,
       3,     3,   131,   149,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,   144,   163,   164,   165,
     166,   167,   143,   144,   143,   144,   143,   144,   143,   144,
       0,     1,   143,   144,   143,   144,     6,   183,   143,   144,
     186,   187,     0,   189,   190,   191,     3,     4,     5,     6,
       7,     8,   198,     3,     4,     5,     6,     7,     8,   143,
     144,   143,   144,     0,     1,   143,   144,   144,     5,     6,
     143,   144,   143,   144,   143,   144,   143,   144,   143,   144,
     226,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,   144,   240,   143,   144,   243,   244,   143,
     144,   144,   248,     3,     4,     5,     6,     7,     8,   143,
     144,   257,     3,     4,     5,     6,     7,     8,   143,   144,
     266,     3,     4,     5,     6,     7,     8,   143,   144,   144,
     276,   143,   144,   279,   143,   281,   143,   144,   143,   144,
     143,   144,   144,     3,   143,   144,   143,   144,   143,   144,
     143,   144,     3,   163,   164,   165,   143,   144,   168,   143,
     144,   171,   172,   173,   334,   143,   144,   144,   178,   144,
     180,   181,   182,   494,   344,   143,   144,   187,   499,   144,
     326,   144,   328,   144,   330,   144,   143,   144,   144,   335,
     143,   144,   598,   143,   144,   143,   144,   144,   168,   143,
     144,   143,   144,   143,   144,   215,   347,   348,   218,   219,
     220,   221,   222,   223,   224,   225,   144,   363,   143,   144,
     144,   143,   144,   143,   144,   144,   236,   143,   374,   143,
     144,   168,   242,     3,     4,     5,     6,     7,     8,   143,
     144,   143,   144,   143,   144,     3,     4,     5,     6,     7,
       8,   144,   143,   144,   143,   144,   143,   144,   143,   144,
     144,   143,   144,     3,     4,     5,     6,     7,     8,   143,
     144,   144,   242,   143,   144,   143,   144,   287,   288,   144,
     290,   291,   292,   293,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,   312,   143,   144,   242,   316,   317,     3,     4,
       5,     6,     7,     8,   324,   325,   144,   327,   288,   329,
     144,   291,   144,   293,   143,   144,   336,   337,   144,   339,
     143,   144,   342,   143,   144,   144,   346,   143,   144,   349,
     144,   351,   352,   353,   143,   144,   316,   317,   358,   144,
     287,   288,   362,   290,   291,   292,   293,   143,   144,   143,
     144,   143,   144,   300,   143,   144,   144,   337,   143,   144,
     143,   144,   144,   143,   144,   144,   346,   143,   144,   316,
     317,   143,   144,   143,   144,   143,   144,   324,   398,     3,
       4,     5,     6,     7,     8,   332,   143,   144,   144,   336,
     337,   144,   144,   143,   144,   144,   144,   144,   144,   346,
     144,   144,   144,   144,   424,     3,     4,     5,     6,     7,
       8,   431,   144,   144,   143,   144,   144,   144,   398,   144,
     143,   144,   578,   144,   144,   144,   143,   144,     3,     4,
       5,     6,     7,     8,   144,   144,   144,   144,   143,   144,
       3,     4,     5,     6,     7,     8,   144,   144,   144,   144,
     144,   398,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
     490,   144,   144,   493,   144,   144,   144,   497,   144,   144,
     500,   501,   144,   144,   431,   144,   144,   507,   144,   144,
     144,   511,   144,   144,   514,     3,     4,     5,     6,     7,
       8,   521,   144,   144,   144,   144,   144,   527,   144,   144,
     490,   144,   144,   533,   133,   144,   144,   497,   144,   143,
     144,   141,   542,   144,   660,    -1,   144,   144,   144,   549,
     144,   344,   395,    -1,    -1,    -1,    -1,    -1,    -1,   559,
      -1,    -1,    -1,   490,    -1,   143,   144,    -1,    -1,    -1,
     497,    -1,    -1,   500,   501,     3,     4,     5,     6,     7,
       8,    -1,     3,     4,     5,     6,     7,     8,   143,   144,
      -1,    -1,    -1,    -1,   521,    -1,    -1,    -1,   598,    -1,
     143,   144,    -1,    -1,    -1,    -1,   533,   534,    -1,    -1,
      -1,    -1,   143,   144,    -1,    -1,    -1,    -1,   143,   144,
      -1,    -1,    -1,   623,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   598,   150,
     151,   152,   153,   154,   155,   156,    -1,    -1,    -1,   160,
     161,    -1,    -1,    -1,    -1,   143,   144,    -1,   169,    -1,
     660,    -1,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,   598,    -1,   184,   185,    -1,    -1,   188,    -1,    -1,
     680,   192,   193,   194,   195,   196,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,    -1,   216,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,   143,   227,   228,   229,   230,
     231,   232,   143,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,    -1,   660,    -1,   246,   247,    -1,   249,    -1,
      -1,    -1,   253,   254,   255,   256,    -1,    -1,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,   268,    -1,   270,
     271,   272,   273,   274,    -1,    -1,    -1,   278,    -1,   280,
      -1,   282,   283,   284,   285,     3,     4,     5,     6,     7,
       8,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,   303,    -1,    -1,    -1,   307,   308,    -1,    -1,
      -1,   312,    -1,    -1,   315,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,   325,    -1,   327,    -1,   329,    -1,
     331,    -1,    -1,   334,     3,     4,     5,     6,     7,     8,
      -1,    -1,   343,    -1,    -1,    -1,   347,    -1,    -1,   350,
     351,    -1,    -1,   354,    -1,    -1,   357,   143,   144,    -1,
     361,   362,    -1,    -1,    -1,   366,   367,   368,    -1,    -1,
      -1,    -1,    -1,    -1,   375,    -1,    -1,    -1,    -1,   380,
     381,   382,   383,    -1,    -1,   386,    -1,    -1,   389,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,   412,    -1,    -1,    -1,    -1,   417,    -1,   419,    -1,
      -1,   422,    -1,    -1,   425,   143,   144,    -1,   429,    -1,
      -1,   432,   433,   143,   144,    -1,    -1,   438,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,     3,     4,
       5,     6,     7,     8,    -1,    -1,   457,   143,   144,    -1,
      -1,    -1,    -1,   464,    -1,    -1,    -1,   468,    -1,    -1,
     471,    -1,   473,    -1,   143,   144,   151,   152,    -1,    -1,
     481,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,   494,    -1,    -1,    -1,    -1,   499,    -1,
      -1,   176,   177,    -1,   179,    -1,   507,    -1,    -1,   184,
     511,    -1,    -1,   514,    -1,    -1,    -1,   192,   519,   194,
     195,   522,    -1,    -1,   199,   200,   201,    -1,   203,   204,
     205,   206,   207,   208,    -1,   210,   143,   144,    -1,    -1,
      -1,   216,   143,   144,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,   229,    -1,   231,   232,   559,   234,
       3,     4,     5,     6,     7,     8,    -1,    -1,   569,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
      -1,    -1,    -1,   268,    -1,    -1,   271,    -1,   273,    -1,
      -1,    -1,    -1,    -1,    -1,   280,    -1,   282,   283,   284,
     285,    -1,    -1,    -1,    -1,   616,    -1,    -1,   619,    -1,
      -1,   143,   144,    -1,    -1,    -1,    -1,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   659,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
     143,   144,    -1,   704,    -1,   380,    11,   382,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
     145,   146,   147,   148,   149,   150,   151,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,   145,
     146,   147,   148,   149,   150,   151,     3,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,    -1,   131,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,   143,    -1,   145,   146,
     147,   148,   149,   150,   151,     3,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   143,   144,    -1,    -1,    -1,
      -1,   143,   144,    -1,    -1,    -1,    -1,   143,   144,     3,
       4,     5,     6,     7,     8,   143,   144,     3,     4,     5,
       6,     7,     8,    -1,    -1,   133,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,   143,    -1,   145,   146,   147,
     148,   149,   150,   151,     3,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,     3,
       4,     5,     6,     7,     8,    -1,   143,   144,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,   143,    -1,   145,   146,   147,   148,
     149,   150,   151,     3,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,     3,     4,     5,     6,     7,     8,   143,
     144,     3,     4,     5,     6,     7,     8,    -1,   143,   144,
      -1,    -1,    -1,    -1,   143,   144,     3,     4,     5,     6,
       7,     8,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,   143,    -1,   145,   146,   147,   148,   149,
     150,   151,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,    -1,    -1,
      -1,    -1,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,    -1,    -1,    -1,    -1,   143,   144,
      -1,    -1,    -1,    -1,   143,   144,    -1,    -1,    -1,    -1,
     143,   144,    -1,    -1,    -1,    -1,   143,   144,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   143,   153,   154,   159,   160,   161,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,     3,     4,
      11,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   145,
     146,   147,   148,   149,   150,   151,   159,   160,   161,     0,
     160,   161,   160,   161,     3,     4,     5,     6,     7,     8,
     143,   144,   155,   157,   159,   164,   144,   157,   155,   156,
     156,   156,   155,   167,   168,   155,   155,   155,   144,   144,
     144,   155,   155,   144,   143,   157,   161,   157,   161,   157,
     161,   157,   143,   144,   157,   297,   160,   155,   144,   143,
     161,   161,   155,   161,   155,   155,   156,   155,   156,   155,
     161,   155,   156,   155,   161,   161,   161,   157,   156,   155,
     144,   157,   157,   161,   155,   144,   157,   157,   157,   156,
     155,   156,   156,   155,   155,   157,   156,   156,   156,   155,
     156,   156,   156,   155,   156,   156,   155,   156,   155,   155,
     156,   155,   155,   155,   144,   155,   161,   156,     3,   144,
     161,   161,   144,   161,   161,   144,   161,   144,   161,   161,
     144,   161,   157,   155,   155,   156,   155,   156,   156,     3,
     165,   156,   158,   155,   155,   161,   155,   155,   144,   157,
     144,   160,   157,   157,   144,   144,   155,   155,   157,   155,
     144,   144,   144,   155,   156,   155,   156,   144,   157,   144,
     155,   155,   144,   144,   144,   144,   155,   157,   144,   156,
     144,   155,   156,   155,   155,   156,   155,   144,   157,   144,
     155,   157,   156,   157,   156,   156,   156,   156,   144,   144,
     144,    15,   159,   144,   155,   144,   155,   144,   144,   144,
     143,   144,   155,   161,   162,   144,   144,   143,   162,   163,
     160,   160,   144,   144,   161,   144,   161,   157,   161,   144,
     161,   157,   144,   161,   157,   144,   144,   297,   144,   157,
     144,   160,    15,   144,   144,   144,   161,   155,   143,   144,
     294,   297,   144,   160,   143,   144,   299,   143,   144,   299,
     144,   161,   155,   144,   161,   144,   161,   161,   144,   155,
     144,   144,   144,   144,   161,   144,   144,   144,   161,   157,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   157,
     144,   144,   144,   144,   144,   156,   144,   155,   156,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     143,   144,   307,   144,   144,     3,   144,   154,   166,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   155,   144,   155,     3,   144,   144,   155,
     144,   144,   161,   155,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   155,
     160,   144,   161,   162,   144,   162,   144,   144,   144,   144,
     161,   144,   144,   161,   144,   144,   161,   144,   144,   144,
     155,   144,   144,   161,   144,   144,   144,   144,   144,   144,
     144,   161,   144,   144,   144,   144,   161,   144,   144,   144,
     161,   144,   144,   144,   157,   144,   144,     3,   144,   154,
     144,   155,   155,   144,   144,   161,   144,   164,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   152,   153,   154,   155,   155,   156,   157,   157,   158,
     158,   159,   159,   160,   160,   160,   160,   160,   161,   161,
     161,   162,   162,   162,   163,   163,   164,   164,   164,   164,
     164,   164,   165,   165,   166,   166,   167,   168,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   181,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     191,   191,   191,   192,   192,   192,   192,   193,   193,   193,
     193,   194,   195,   195,   195,   195,   195,   196,   197,   198,
     199,   200,   201,   201,   201,   201,   202,   202,   202,   203,
     204,   205,   205,   205,   205,   206,   206,   206,   206,   207,
     207,   207,   207,   208,   208,   208,   208,   209,   210,   211,
     212,   212,   213,   214,   214,   215,   215,   215,   215,   216,
     217,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   232,   233,   234,
     234,   235,   236,   236,   237,   238,   238,   239,   240,   241,
     242,   242,   242,   243,   244,   245,   245,   245,   245,   246,
     246,   247,   247,   248,   249,   249,   250,   251,   251,   252,
     252,   253,   254,   254,   255,   256,   257,   257,   258,   259,
     260,   261,   261,   262,   263,   264,   265,   266,   266,   266,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     303,   304,   305,   306,   307,   308,   309,   309
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     5,     5,     3,     3,     3,     4,     4,     3,     5,
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
#line 2067 "parser.c"
        break;

    case 4: /* STR  */
#line 73 "../src/parser.y"
            { free(((*yyvaluep).s)); }
#line 2073 "parser.c"
        break;

    case 153: /* start  */
#line 71 "../src/parser.y"
            { run(((*yyvaluep).e));  }
#line 2079 "parser.c"
        break;

    case 154: /* s  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2085 "parser.c"
        break;

    case 155: /* p  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2091 "parser.c"
        break;

    case 156: /* pp  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2097 "parser.c"
        break;

    case 157: /* ps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2103 "parser.c"
        break;

    case 158: /* pps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2109 "parser.c"
        break;

    case 159: /* vp  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2115 "parser.c"
        break;

    case 160: /* vps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2121 "parser.c"
        break;

    case 161: /* opts  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2127 "parser.c"
        break;

    case 162: /* xpb  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2133 "parser.c"
        break;

    case 163: /* xpbs  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2139 "parser.c"
        break;

    case 164: /* np  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2145 "parser.c"
        break;

    case 165: /* sps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2151 "parser.c"
        break;

    case 166: /* par  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2157 "parser.c"
        break;

    case 167: /* cv  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2163 "parser.c"
        break;

    case 168: /* cvv  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2169 "parser.c"
        break;

    case 169: /* opt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2175 "parser.c"
        break;

    case 170: /* ivp  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2181 "parser.c"
        break;

    case 171: /* add  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2187 "parser.c"
        break;

    case 172: /* div  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2193 "parser.c"
        break;

    case 173: /* mul  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2199 "parser.c"
        break;

    case 174: /* sub  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2205 "parser.c"
        break;

    case 175: /* eq  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2211 "parser.c"
        break;

    case 176: /* gt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2217 "parser.c"
        break;

    case 177: /* gte  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2223 "parser.c"
        break;

    case 178: /* lt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2229 "parser.c"
        break;

    case 179: /* lte  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2235 "parser.c"
        break;

    case 180: /* neq  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2241 "parser.c"
        break;

    case 181: /* if  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2247 "parser.c"
        break;

    case 182: /* select  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2253 "parser.c"
        break;

    case 183: /* until  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2259 "parser.c"
        break;

    case 184: /* while  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2265 "parser.c"
        break;

    case 185: /* trace  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2271 "parser.c"
        break;

    case 186: /* retrace  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2277 "parser.c"
        break;

    case 187: /* astraw  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2283 "parser.c"
        break;

    case 188: /* asbraw  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2289 "parser.c"
        break;

    case 189: /* asbeval  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2295 "parser.c"
        break;

    case 190: /* options  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2301 "parser.c"
        break;

    case 191: /* execute  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2307 "parser.c"
        break;

    case 192: /* rexx  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2313 "parser.c"
        break;

    case 193: /* run  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2319 "parser.c"
        break;

    case 194: /* abort  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2325 "parser.c"
        break;

    case 195: /* exit  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2331 "parser.c"
        break;

    case 196: /* onerror  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2337 "parser.c"
        break;

    case 197: /* reboot  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2343 "parser.c"
        break;

    case 198: /* trap  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2349 "parser.c"
        break;

    case 199: /* copyfiles  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2355 "parser.c"
        break;

    case 200: /* copylib  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2361 "parser.c"
        break;

    case 201: /* delete  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2367 "parser.c"
        break;

    case 202: /* exists  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2373 "parser.c"
        break;

    case 203: /* fileonly  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2379 "parser.c"
        break;

    case 204: /* foreach  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2385 "parser.c"
        break;

    case 205: /* makeassign  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2391 "parser.c"
        break;

    case 206: /* makedir  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2397 "parser.c"
        break;

    case 207: /* protect  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2403 "parser.c"
        break;

    case 208: /* startup  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2409 "parser.c"
        break;

    case 209: /* textfile  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2415 "parser.c"
        break;

    case 210: /* tooltype  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2421 "parser.c"
        break;

    case 211: /* transcript  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2427 "parser.c"
        break;

    case 212: /* rename  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2433 "parser.c"
        break;

    case 213: /* complete  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2439 "parser.c"
        break;

    case 214: /* debug  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2445 "parser.c"
        break;

    case 215: /* message  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2451 "parser.c"
        break;

    case 216: /* user  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2457 "parser.c"
        break;

    case 217: /* welcome  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2463 "parser.c"
        break;

    case 218: /* working  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2469 "parser.c"
        break;

    case 219: /* and  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2475 "parser.c"
        break;

    case 220: /* bitand  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2481 "parser.c"
        break;

    case 221: /* bitnot  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2487 "parser.c"
        break;

    case 222: /* bitor  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2493 "parser.c"
        break;

    case 223: /* bitxor  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2499 "parser.c"
        break;

    case 224: /* not  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2505 "parser.c"
        break;

    case 225: /* in  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2511 "parser.c"
        break;

    case 226: /* or  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2517 "parser.c"
        break;

    case 227: /* shiftleft  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2523 "parser.c"
        break;

    case 228: /* shiftright  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2529 "parser.c"
        break;

    case 229: /* xor  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2535 "parser.c"
        break;

    case 230: /* closemedia  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2541 "parser.c"
        break;

    case 231: /* effect  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2547 "parser.c"
        break;

    case 232: /* setmedia  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2553 "parser.c"
        break;

    case 233: /* showmedia  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2559 "parser.c"
        break;

    case 234: /* database  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2565 "parser.c"
        break;

    case 235: /* earlier  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2571 "parser.c"
        break;

    case 236: /* getassign  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2577 "parser.c"
        break;

    case 237: /* getdevice  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2583 "parser.c"
        break;

    case 238: /* getdiskspace  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2589 "parser.c"
        break;

    case 239: /* getenv  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2595 "parser.c"
        break;

    case 240: /* getsize  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2601 "parser.c"
        break;

    case 241: /* getsum  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2607 "parser.c"
        break;

    case 242: /* getversion  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2613 "parser.c"
        break;

    case 243: /* iconinfo  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2619 "parser.c"
        break;

    case 244: /* querydisplay  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2625 "parser.c"
        break;

    case 245: /* dcl  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2631 "parser.c"
        break;

    case 246: /* cus  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2637 "parser.c"
        break;

    case 247: /* askbool  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2643 "parser.c"
        break;

    case 248: /* askchoice  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2649 "parser.c"
        break;

    case 249: /* askdir  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2655 "parser.c"
        break;

    case 250: /* askdisk  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2661 "parser.c"
        break;

    case 251: /* askfile  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2667 "parser.c"
        break;

    case 252: /* asknumber  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2673 "parser.c"
        break;

    case 253: /* askoptions  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2679 "parser.c"
        break;

    case 254: /* askstring  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2685 "parser.c"
        break;

    case 255: /* cat  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2691 "parser.c"
        break;

    case 256: /* expandpath  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2697 "parser.c"
        break;

    case 257: /* fmt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2703 "parser.c"
        break;

    case 258: /* pathonly  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2709 "parser.c"
        break;

    case 259: /* patmatch  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2715 "parser.c"
        break;

    case 260: /* strlen  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2721 "parser.c"
        break;

    case 261: /* substr  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2727 "parser.c"
        break;

    case 262: /* tackon  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2733 "parser.c"
        break;

    case 263: /* set  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2739 "parser.c"
        break;

    case 264: /* symbolset  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2745 "parser.c"
        break;

    case 265: /* symbolval  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2751 "parser.c"
        break;

    case 266: /* openwbobject  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2757 "parser.c"
        break;

    case 267: /* showwbobject  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2763 "parser.c"
        break;

    case 268: /* closewbobject  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2769 "parser.c"
        break;

    case 269: /* all  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2775 "parser.c"
        break;

    case 270: /* append  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2781 "parser.c"
        break;

    case 271: /* assigns  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2787 "parser.c"
        break;

    case 272: /* back  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2793 "parser.c"
        break;

    case 273: /* choices  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2799 "parser.c"
        break;

    case 274: /* command  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2805 "parser.c"
        break;

    case 275: /* compression  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2811 "parser.c"
        break;

    case 276: /* confirm  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2817 "parser.c"
        break;

    case 277: /* default  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2823 "parser.c"
        break;

    case 278: /* delopts  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2829 "parser.c"
        break;

    case 279: /* dest  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2835 "parser.c"
        break;

    case 280: /* disk  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2841 "parser.c"
        break;

    case 281: /* files  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2847 "parser.c"
        break;

    case 282: /* fonts  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2853 "parser.c"
        break;

    case 283: /* getdefaulttool  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2859 "parser.c"
        break;

    case 284: /* getposition  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2865 "parser.c"
        break;

    case 285: /* getstack  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2871 "parser.c"
        break;

    case 286: /* gettooltype  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2877 "parser.c"
        break;

    case 287: /* help  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2883 "parser.c"
        break;

    case 288: /* infos  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2889 "parser.c"
        break;

    case 289: /* include  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2895 "parser.c"
        break;

    case 290: /* newname  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2901 "parser.c"
        break;

    case 291: /* newpath  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2907 "parser.c"
        break;

    case 292: /* nogauge  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2913 "parser.c"
        break;

    case 293: /* noposition  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2919 "parser.c"
        break;

    case 294: /* noreq  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2925 "parser.c"
        break;

    case 295: /* pattern  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2931 "parser.c"
        break;

    case 296: /* prompt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2937 "parser.c"
        break;

    case 297: /* quiet  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2943 "parser.c"
        break;

    case 298: /* range  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2949 "parser.c"
        break;

    case 299: /* safe  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2955 "parser.c"
        break;

    case 300: /* setdefaulttool  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2961 "parser.c"
        break;

    case 301: /* setposition  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2967 "parser.c"
        break;

    case 302: /* setstack  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2973 "parser.c"
        break;

    case 303: /* settooltype  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2979 "parser.c"
        break;

    case 304: /* source  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2985 "parser.c"
        break;

    case 305: /* swapcolors  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2991 "parser.c"
        break;

    case 306: /* optional  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2997 "parser.c"
        break;

    case 307: /* resident  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3003 "parser.c"
        break;

    case 308: /* override  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3009 "parser.c"
        break;

    case 309: /* dynopt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3015 "parser.c"
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
#line 3289 "parser.c"
    break;

  case 6:
#line 94 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3295 "parser.c"
    break;

  case 7:
#line 95 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3301 "parser.c"
    break;

  case 8:
#line 96 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3307 "parser.c"
    break;

  case 9:
#line 97 "../src/parser.y"
                                                 { (yyval.e) = push(push((yyvsp[-2].e), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3313 "parser.c"
    break;

  case 12:
#line 100 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3319 "parser.c"
    break;

  case 13:
#line 101 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3325 "parser.c"
    break;

  case 14:
#line 102 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e));  }
#line 3331 "parser.c"
    break;

  case 15:
#line 103 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e));  }
#line 3337 "parser.c"
    break;

  case 16:
#line 104 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3343 "parser.c"
    break;

  case 17:
#line 105 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3349 "parser.c"
    break;

  case 18:
#line 106 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3355 "parser.c"
    break;

  case 19:
#line 107 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3361 "parser.c"
    break;

  case 20:
#line 108 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3367 "parser.c"
    break;

  case 21:
#line 109 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3373 "parser.c"
    break;

  case 22:
#line 110 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-2].e), (yyvsp[-1].e)); }
#line 3379 "parser.c"
    break;

  case 23:
#line 111 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3385 "parser.c"
    break;

  case 24:
#line 112 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3391 "parser.c"
    break;

  case 25:
#line 113 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3397 "parser.c"
    break;

  case 26:
#line 114 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3403 "parser.c"
    break;

  case 27:
#line 115 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3409 "parser.c"
    break;

  case 28:
#line 116 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3415 "parser.c"
    break;

  case 29:
#line 117 "../src/parser.y"
                                                 { (yyval.e) = new_string((yyvsp[0].s)); }
#line 3421 "parser.c"
    break;

  case 30:
#line 118 "../src/parser.y"
                                                 { (yyval.e) = new_symref((yyvsp[0].s), LINE); }
#line 3427 "parser.c"
    break;

  case 31:
#line 119 "../src/parser.y"
                                                 { (yyval.e) = NULL; YYFPRINTF(stderr, "Out of memory in line %d\n", LINE); YYABORT; }
#line 3433 "parser.c"
    break;

  case 32:
#line 120 "../src/parser.y"
                                                 { (yyval.e) = push(push((yyvsp[-2].e), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)) ; }
#line 3439 "parser.c"
    break;

  case 33:
#line 121 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)); }
#line 3445 "parser.c"
    break;

  case 34:
#line 122 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), new_symbol((yyvsp[0].s))); }
#line 3451 "parser.c"
    break;

  case 35:
#line 123 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), new_symbol((yyvsp[0].s))); }
#line 3457 "parser.c"
    break;

  case 36:
#line 124 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3463 "parser.c"
    break;

  case 37:
#line 125 "../src/parser.y"
                                                 { (yyval.e) = push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3469 "parser.c"
    break;

  case 177:
#line 274 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("+"), LINE, m_add, (yyvsp[-1].e), NUMBER); }
#line 3475 "parser.c"
    break;

  case 178:
#line 275 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("/"), LINE, m_div, (yyvsp[-1].e), NUMBER); }
#line 3481 "parser.c"
    break;

  case 179:
#line 276 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("*"), LINE, m_mul, (yyvsp[-1].e), NUMBER); }
#line 3487 "parser.c"
    break;

  case 180:
#line 277 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("-"), LINE, m_sub, (yyvsp[-1].e), NUMBER); }
#line 3493 "parser.c"
    break;

  case 181:
#line 281 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("="), LINE, m_eq, (yyvsp[-1].e), NUMBER); }
#line 3499 "parser.c"
    break;

  case 182:
#line 282 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup(">"), LINE, m_gt, (yyvsp[-1].e), NUMBER); }
#line 3505 "parser.c"
    break;

  case 183:
#line 283 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup(">="), LINE, m_gte, (yyvsp[-1].e), NUMBER); }
#line 3511 "parser.c"
    break;

  case 184:
#line 284 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<"), LINE, m_lt, (yyvsp[-1].e), NUMBER); }
#line 3517 "parser.c"
    break;

  case 185:
#line 285 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<="), LINE, m_lte, (yyvsp[-1].e), NUMBER); }
#line 3523 "parser.c"
    break;

  case 186:
#line 286 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<>"), LINE, m_neq, (yyvsp[-1].e), NUMBER); }
#line 3529 "parser.c"
    break;

  case 187:
#line 290 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3535 "parser.c"
    break;

  case 188:
#line 291 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3541 "parser.c"
    break;

  case 189:
#line 292 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("if"), LINE, m_if, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3547 "parser.c"
    break;

  case 190:
#line 293 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("select"), LINE, m_select, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3553 "parser.c"
    break;

  case 191:
#line 294 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("until"), LINE, m_until, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3559 "parser.c"
    break;

  case 192:
#line 295 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("while"), LINE, m_while, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3565 "parser.c"
    break;

  case 193:
#line 296 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("trace"), LINE, m_trace, NULL, NUMBER); }
#line 3571 "parser.c"
    break;

  case 194:
#line 297 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("retrace"), LINE, m_retrace, NULL, NUMBER); }
#line 3577 "parser.c"
    break;

  case 195:
#line 301 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___astraw"), LINE, m_astraw, NULL, NUMBER); }
#line 3583 "parser.c"
    break;

  case 196:
#line 302 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___asbraw"), LINE, m_asbraw, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3589 "parser.c"
    break;

  case 197:
#line 303 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___asbeval"), LINE, m_asbeval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3595 "parser.c"
    break;

  case 198:
#line 304 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___options"), LINE, m_options, NULL, NUMBER); }
#line 3601 "parser.c"
    break;

  case 199:
#line 308 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3607 "parser.c"
    break;

  case 200:
#line 309 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3613 "parser.c"
    break;

  case 201:
#line 310 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3619 "parser.c"
    break;

  case 202:
#line 311 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, (yyvsp[-1].e), NUMBER); }
#line 3625 "parser.c"
    break;

  case 203:
#line 312 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3631 "parser.c"
    break;

  case 204:
#line 313 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3637 "parser.c"
    break;

  case 205:
#line 314 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3643 "parser.c"
    break;

  case 206:
#line 315 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, (yyvsp[-1].e), NUMBER); }
#line 3649 "parser.c"
    break;

  case 207:
#line 316 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3655 "parser.c"
    break;

  case 208:
#line 317 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3661 "parser.c"
    break;

  case 209:
#line 318 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3667 "parser.c"
    break;

  case 210:
#line 319 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, m_run, (yyvsp[-1].e), NUMBER); }
#line 3673 "parser.c"
    break;

  case 211:
#line 323 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("abort"), LINE, m_abort, (yyvsp[-1].e), NUMBER); }
#line 3679 "parser.c"
    break;

  case 212:
#line 324 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3685 "parser.c"
    break;

  case 213:
#line 325 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3691 "parser.c"
    break;

  case 214:
#line 326 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3697 "parser.c"
    break;

  case 215:
#line 327 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, (yyvsp[-1].e), NUMBER); }
#line 3703 "parser.c"
    break;

  case 216:
#line 328 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, NULL, NUMBER); }
#line 3709 "parser.c"
    break;

  case 217:
#line 329 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("onerror"), LINE, m_procedure, push(new_contxt(),
                                                        new_custom(strdup("@onerror"), LINE, NULL, (yyvsp[-1].e))), DANGLE); }
#line 3716 "parser.c"
    break;

  case 218:
#line 331 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("reboot"), LINE, m_reboot, NULL, NUMBER); }
#line 3722 "parser.c"
    break;

  case 219:
#line 332 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("trap"), LINE, m_trap, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3728 "parser.c"
    break;

  case 220:
#line 336 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("copyfiles"), LINE, m_copyfiles, (yyvsp[-1].e), NUMBER); }
#line 3734 "parser.c"
    break;

  case 221:
#line 337 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("copylib"), LINE, m_copylib, (yyvsp[-1].e), NUMBER); }
#line 3740 "parser.c"
    break;

  case 222:
#line 338 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3746 "parser.c"
    break;

  case 223:
#line 339 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3752 "parser.c"
    break;

  case 224:
#line 340 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3758 "parser.c"
    break;

  case 225:
#line 341 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3764 "parser.c"
    break;

  case 226:
#line 342 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3770 "parser.c"
    break;

  case 227:
#line 343 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3776 "parser.c"
    break;

  case 228:
#line 344 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3782 "parser.c"
    break;

  case 229:
#line 345 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("fileonly"), LINE, m_fileonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3788 "parser.c"
    break;

  case 230:
#line 346 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("foreach"), LINE, m_foreach, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3794 "parser.c"
    break;

  case 231:
#line 347 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3800 "parser.c"
    break;

  case 232:
#line 348 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, (yyvsp[-1].e), NUMBER); }
#line 3806 "parser.c"
    break;

  case 233:
#line 349 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3812 "parser.c"
    break;

  case 234:
#line 350 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3818 "parser.c"
    break;

  case 235:
#line 351 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3824 "parser.c"
    break;

  case 236:
#line 352 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3830 "parser.c"
    break;

  case 237:
#line 353 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3836 "parser.c"
    break;

  case 238:
#line 354 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3842 "parser.c"
    break;

  case 239:
#line 355 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3848 "parser.c"
    break;

  case 240:
#line 356 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, (yyvsp[-1].e), NUMBER); }
#line 3854 "parser.c"
    break;

  case 241:
#line 357 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3860 "parser.c"
    break;

  case 242:
#line 358 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3866 "parser.c"
    break;

  case 243:
#line 359 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3872 "parser.c"
    break;

  case 244:
#line 360 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3878 "parser.c"
    break;

  case 245:
#line 361 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3884 "parser.c"
    break;

  case 246:
#line 362 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), new_symref(strdup("@app-name"), LINE)), (yyvsp[-1].e)), NUMBER); }
#line 3890 "parser.c"
    break;

  case 247:
#line 363 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("textfile"), LINE, m_textfile, (yyvsp[-1].e), NUMBER); }
#line 3896 "parser.c"
    break;

  case 248:
#line 364 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("tooltype"), LINE, m_tooltype, (yyvsp[-1].e), NUMBER); }
#line 3902 "parser.c"
    break;

  case 249:
#line 365 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("transcript"), LINE, m_transcript, (yyvsp[-1].e), NUMBER); }
#line 3908 "parser.c"
    break;

  case 250:
#line 366 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3914 "parser.c"
    break;

  case 251:
#line 367 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, (yyvsp[-1].e), NUMBER); }
#line 3920 "parser.c"
    break;

  case 252:
#line 371 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("complete"), LINE, m_complete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3926 "parser.c"
    break;

  case 253:
#line 372 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, (yyvsp[-1].e), NUMBER); }
#line 3932 "parser.c"
    break;

  case 254:
#line 373 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, NULL, NUMBER); }
#line 3938 "parser.c"
    break;

  case 255:
#line 374 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, m_message, merge((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3944 "parser.c"
    break;

  case 256:
#line 375 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, m_message, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3950 "parser.c"
    break;

  case 257:
#line 376 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, m_message, push(merge((yyvsp[-3].e), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3956 "parser.c"
    break;

  case 258:
#line 377 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, m_message, (yyvsp[-1].e), NUMBER); }
#line 3962 "parser.c"
    break;

  case 259:
#line 378 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("user"), LINE, m_user, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3968 "parser.c"
    break;

  case 260:
#line 379 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, (yyvsp[-1].e), NUMBER); }
#line 3974 "parser.c"
    break;

  case 261:
#line 380 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, NULL, NUMBER); }
#line 3980 "parser.c"
    break;

  case 262:
#line 381 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("working"), LINE, m_working, (yyvsp[-1].e), NUMBER); }
#line 3986 "parser.c"
    break;

  case 263:
#line 385 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("AND"), LINE, m_and, (yyvsp[-1].e), NUMBER); }
#line 3992 "parser.c"
    break;

  case 264:
#line 386 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITAND"), LINE, m_bitand, (yyvsp[-1].e), NUMBER); }
#line 3998 "parser.c"
    break;

  case 265:
#line 387 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITNOT"), LINE, m_bitnot, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4004 "parser.c"
    break;

  case 266:
#line 388 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITOR"), LINE, m_bitor, (yyvsp[-1].e), NUMBER); }
#line 4010 "parser.c"
    break;

  case 267:
#line 389 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITXOR"), LINE, m_bitxor, (yyvsp[-1].e), NUMBER); }
#line 4016 "parser.c"
    break;

  case 268:
#line 390 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("NOT"), LINE, m_not, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4022 "parser.c"
    break;

  case 269:
#line 391 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("IN"), LINE, m_in, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4028 "parser.c"
    break;

  case 270:
#line 392 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("OR"), LINE, m_or, (yyvsp[-1].e), NUMBER); }
#line 4034 "parser.c"
    break;

  case 271:
#line 393 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("shiftleft"), LINE, m_shiftleft, (yyvsp[-1].e), NUMBER); }
#line 4040 "parser.c"
    break;

  case 272:
#line 394 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("shiftright"), LINE, m_shiftright, (yyvsp[-1].e), NUMBER); }
#line 4046 "parser.c"
    break;

  case 273:
#line 395 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("XOR"), LINE, m_xor, (yyvsp[-1].e), NUMBER); }
#line 4052 "parser.c"
    break;

  case 274:
#line 399 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("closemedia"), LINE, m_closemedia, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4058 "parser.c"
    break;

  case 275:
#line 400 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("effect"), LINE, m_effect, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4064 "parser.c"
    break;

  case 276:
#line 401 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("setmedia"), LINE, m_setmedia, (yyvsp[-1].e), NUMBER); }
#line 4070 "parser.c"
    break;

  case 277:
#line 402 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("setmedia"), LINE, m_setmedia, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4076 "parser.c"
    break;

  case 278:
#line 403 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("showmedia"), LINE, m_showmedia, merge(merge((yyvsp[-3].e), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4082 "parser.c"
    break;

  case 279:
#line 407 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("database"), LINE, m_database, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4088 "parser.c"
    break;

  case 280:
#line 408 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("database"), LINE, m_database, (yyvsp[-1].e), STRING); }
#line 4094 "parser.c"
    break;

  case 281:
#line 409 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("earlier"), LINE, m_earlier, (yyvsp[-1].e), NUMBER); }
#line 4100 "parser.c"
    break;

  case 282:
#line 410 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4106 "parser.c"
    break;

  case 283:
#line 411 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, (yyvsp[-1].e), STRING); }
#line 4112 "parser.c"
    break;

  case 284:
#line 412 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getdevice"), LINE, m_getdevice, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4118 "parser.c"
    break;

  case 285:
#line 413 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4124 "parser.c"
    break;

  case 286:
#line 414 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, (yyvsp[-1].e), NUMBER); }
#line 4130 "parser.c"
    break;

  case 287:
#line 415 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getenv"), LINE, m_getenv, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4136 "parser.c"
    break;

  case 288:
#line 416 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getsize"), LINE, m_getsize, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4142 "parser.c"
    break;

  case 289:
#line 417 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getsum"), LINE, m_getsum, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4148 "parser.c"
    break;

  case 290:
#line 418 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, NULL, NUMBER); }
#line 4154 "parser.c"
    break;

  case 291:
#line 419 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4160 "parser.c"
    break;

  case 292:
#line 420 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4166 "parser.c"
    break;

  case 293:
#line 421 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("iconinfo"), LINE, m_iconinfo, (yyvsp[-1].e), NUMBER); }
#line 4172 "parser.c"
    break;

  case 294:
#line 422 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("querydisplay"), LINE, m_querydisplay, (yyvsp[-1].e), NUMBER); }
#line 4178 "parser.c"
    break;

  case 295:
#line 426 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-3].s), LINE, (yyvsp[-2].e), (yyvsp[-1].e))), NUMBER); }
#line 4184 "parser.c"
    break;

  case 296:
#line 427 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, (yyvsp[-1].e), NULL)), NUMBER); }
#line 4190 "parser.c"
    break;

  case 297:
#line 428 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, NULL, (yyvsp[-1].e))), NUMBER); }
#line 4196 "parser.c"
    break;

  case 298:
#line 429 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-1].s), LINE, NULL, NULL)), NUMBER); }
#line 4202 "parser.c"
    break;

  case 299:
#line 430 "../src/parser.y"
                                                 { (yyval.e) = new_cusref((yyvsp[-2].s), LINE, (yyvsp[-1].e)); }
#line 4208 "parser.c"
    break;

  case 300:
#line 431 "../src/parser.y"
                                                 { (yyval.e) = new_cusref((yyvsp[-1].s), LINE, NULL); }
#line 4214 "parser.c"
    break;

  case 301:
#line 435 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, NULL, NUMBER); }
#line 4220 "parser.c"
    break;

  case 302:
#line 436 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, (yyvsp[-1].e), NUMBER); }
#line 4226 "parser.c"
    break;

  case 303:
#line 437 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askchoice"), LINE, m_askchoice, (yyvsp[-1].e), NUMBER); }
#line 4232 "parser.c"
    break;

  case 304:
#line 438 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, NULL, STRING); }
#line 4238 "parser.c"
    break;

  case 305:
#line 439 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, (yyvsp[-1].e), STRING); }
#line 4244 "parser.c"
    break;

  case 306:
#line 440 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askdisk"), LINE, m_askdisk, (yyvsp[-1].e), NUMBER); }
#line 4250 "parser.c"
    break;

  case 307:
#line 441 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, NULL, STRING); }
#line 4256 "parser.c"
    break;

  case 308:
#line 442 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, (yyvsp[-1].e), STRING); }
#line 4262 "parser.c"
    break;

  case 309:
#line 443 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, NULL, NUMBER); }
#line 4268 "parser.c"
    break;

  case 310:
#line 444 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, (yyvsp[-1].e), NUMBER); }
#line 4274 "parser.c"
    break;

  case 311:
#line 445 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askoptions"), LINE, m_askoptions, (yyvsp[-1].e), NUMBER); }
#line 4280 "parser.c"
    break;

  case 312:
#line 446 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, NULL, STRING); }
#line 4286 "parser.c"
    break;

  case 313:
#line 447 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, (yyvsp[-1].e), STRING); }
#line 4292 "parser.c"
    break;

  case 314:
#line 451 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("cat"), LINE, m_cat, (yyvsp[-1].e), STRING); }
#line 4298 "parser.c"
    break;

  case 315:
#line 452 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("expandpath"), LINE, m_expandpath, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4304 "parser.c"
    break;

  case 316:
#line 453 "../src/parser.y"
                                                 { (yyval.e) = new_native((yyvsp[-2].s), LINE, m_fmt, (yyvsp[-1].e), STRING); }
#line 4310 "parser.c"
    break;

  case 317:
#line 454 "../src/parser.y"
                                                 { (yyval.e) = new_native((yyvsp[-1].s), LINE, m_fmt, NULL, STRING); }
#line 4316 "parser.c"
    break;

  case 318:
#line 455 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("pathonly"), LINE, m_pathonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4322 "parser.c"
    break;

  case 319:
#line 456 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("patmatch"), LINE, m_patmatch, (yyvsp[-1].e), NUMBER); }
#line 4328 "parser.c"
    break;

  case 320:
#line 457 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("strlen"), LINE, m_strlen, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4334 "parser.c"
    break;

  case 321:
#line 458 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, (yyvsp[-1].e), STRING); }
#line 4340 "parser.c"
    break;

  case 322:
#line 459 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, push((yyvsp[-2].e), (yyvsp[-1].e)), STRING); }
#line 4346 "parser.c"
    break;

  case 323:
#line 460 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("tackon"), LINE, m_tackon, (yyvsp[-1].e), STRING); }
#line 4352 "parser.c"
    break;

  case 324:
#line 464 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("set"), LINE, m_set, (yyvsp[-1].e), DANGLE); }
#line 4358 "parser.c"
    break;

  case 325:
#line 465 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("symbolset"), LINE, m_symbolset, (yyvsp[-1].e), DANGLE); }
#line 4364 "parser.c"
    break;

  case 326:
#line 466 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("symbolval"), LINE, m_symbolval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4370 "parser.c"
    break;

  case 327:
#line 470 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4376 "parser.c"
    break;

  case 328:
#line 471 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4382 "parser.c"
    break;

  case 329:
#line 472 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4388 "parser.c"
    break;

  case 330:
#line 473 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4394 "parser.c"
    break;

  case 331:
#line 474 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("showwbobject"), LINE, m_showwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4400 "parser.c"
    break;

  case 332:
#line 475 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("closewbobject"), LINE, m_closewbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4406 "parser.c"
    break;

  case 333:
#line 479 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("all"), OPT_ALL, NULL); }
#line 4412 "parser.c"
    break;

  case 334:
#line 480 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("append"), OPT_APPEND, (yyvsp[-1].e)); }
#line 4418 "parser.c"
    break;

  case 335:
#line 481 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); }
#line 4424 "parser.c"
    break;

  case 336:
#line 482 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("back"), OPT_BACK, (yyvsp[-1].e)); }
#line 4430 "parser.c"
    break;

  case 337:
#line 483 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("choices"), OPT_CHOICES, (yyvsp[-1].e)); }
#line 4436 "parser.c"
    break;

  case 338:
#line 484 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("command"), OPT_COMMAND, (yyvsp[-1].e)); }
#line 4442 "parser.c"
    break;

  case 339:
#line 485 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("compression"), OPT_COMPRESSION, NULL); }
#line 4448 "parser.c"
    break;

  case 340:
#line 486 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, push(new_contxt(), (yyvsp[-1].e))); }
#line 4454 "parser.c"
    break;

  case 341:
#line 487 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, NULL); }
#line 4460 "parser.c"
    break;

  case 342:
#line 488 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), (yyvsp[-1].e))); }
#line 4466 "parser.c"
    break;

  case 343:
#line 489 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, (yyvsp[-1].e)); }
#line 4472 "parser.c"
    break;

  case 344:
#line 490 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), (yyvsp[-1].e))); }
#line 4478 "parser.c"
    break;

  case 345:
#line 491 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("disk"), OPT_DISK, NULL); }
#line 4484 "parser.c"
    break;

  case 346:
#line 492 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("files"), OPT_FILES, NULL); }
#line 4490 "parser.c"
    break;

  case 347:
#line 493 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("fonts"), OPT_FONTS, NULL); }
#line 4496 "parser.c"
    break;

  case 348:
#line 494 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4502 "parser.c"
    break;

  case 349:
#line 495 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("getposition"), OPT_GETPOSITION, (yyvsp[-1].e)); }
#line 4508 "parser.c"
    break;

  case 350:
#line 496 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4514 "parser.c"
    break;

  case 351:
#line 497 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, (yyvsp[-1].e)); }
#line 4520 "parser.c"
    break;

  case 352:
#line 498 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("help"), OPT_HELP, (yyvsp[-1].e)); }
#line 4526 "parser.c"
    break;

  case 353:
#line 499 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("help"), OPT_HELP, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4532 "parser.c"
    break;

  case 354:
#line 500 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("infos"), OPT_INFOS, NULL); }
#line 4538 "parser.c"
    break;

  case 355:
#line 501 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4544 "parser.c"
    break;

  case 356:
#line 502 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), (yyvsp[-1].e))); }
#line 4550 "parser.c"
    break;

  case 357:
#line 503 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("newpath"), OPT_NEWPATH, NULL); }
#line 4556 "parser.c"
    break;

  case 358:
#line 504 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); }
#line 4562 "parser.c"
    break;

  case 359:
#line 505 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); }
#line 4568 "parser.c"
    break;

  case 360:
#line 506 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("noreq"), OPT_NOREQ, NULL); }
#line 4574 "parser.c"
    break;

  case 361:
#line 507 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), (yyvsp[-1].e))); }
#line 4580 "parser.c"
    break;

  case 362:
#line 508 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("prompt"), OPT_PROMPT, (yyvsp[-1].e)); }
#line 4586 "parser.c"
    break;

  case 363:
#line 509 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("quiet"), OPT_QUIET, NULL); }
#line 4592 "parser.c"
    break;

  case 364:
#line 510 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("range"), OPT_RANGE, (yyvsp[-1].e)); }
#line 4598 "parser.c"
    break;

  case 365:
#line 511 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("safe"), OPT_SAFE, NULL); }
#line 4604 "parser.c"
    break;

  case 366:
#line 512 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4610 "parser.c"
    break;

  case 367:
#line 513 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("setposition"), OPT_SETPOSITION, (yyvsp[-1].e)); }
#line 4616 "parser.c"
    break;

  case 368:
#line 514 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4622 "parser.c"
    break;

  case 369:
#line 515 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, (yyvsp[-1].e)); }
#line 4628 "parser.c"
    break;

  case 370:
#line 516 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4634 "parser.c"
    break;

  case 371:
#line 517 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4640 "parser.c"
    break;

  case 372:
#line 518 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); }
#line 4646 "parser.c"
    break;

  case 373:
#line 519 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, (yyvsp[-1].e)); }
#line 4652 "parser.c"
    break;

  case 374:
#line 520 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("resident"), OPT_RESIDENT, NULL); }
#line 4658 "parser.c"
    break;

  case 375:
#line 521 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4664 "parser.c"
    break;

  case 376:
#line 522 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4670 "parser.c"
    break;

  case 377:
#line 523 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(push(new_contxt(), (yyvsp[-3].e)), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4676 "parser.c"
    break;


#line 4680 "parser.c"

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
#line 525 "../src/parser.y"

