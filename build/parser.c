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
#define YYLAST   2420

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  153
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  159
/* YYNRULES -- Number of rules.  */
#define YYNRULES  390
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  753

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
     277,   278,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   297,   298,   299,   300,   301,   302,
     303,   304,   308,   309,   310,   311,   312,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   331,
     332,   333,   334,   335,   336,   337,   339,   340,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   408,   409,   410,   411,   412,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   435,   436,   437,   438,   439,   440,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   473,   474,   475,   479,   480,   481,   482,
     483,   484,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536
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

#define YYPACT_NINF (-405)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -141,  1286,    36,  -405,  -405,  -141,  -141,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,     8,
      14,    93,    93,    93,    93,    93,    93,    93,  -137,  -102,
     -95,    93,    93,    93,   -65,   567,   567,   567,    93,    34,
    -141,    93,   -60,   -55,   -55,   567,   567,    93,    93,    93,
     567,    93,   567,   -55,   -55,    93,    93,    93,    58,   567,
      93,    87,   110,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,   117,   -55,    93,   104,
    -121,   -55,  -113,   -55,  -111,   -98,   -55,   -90,    93,    93,
      93,    93,    93,    93,    93,   106,    93,    93,   567,    93,
      93,   -34,    93,    -8,  -141,    93,    93,    -3,   126,    93,
     142,    93,    19,    45,    47,    93,    93,    93,    93,   242,
      49,    93,    93,   260,    54,    98,   115,    93,    93,   124,
      93,   127,    93,    93,    93,    93,    93,   140,   270,   143,
      93,    93,    93,    93,    93,    93,    93,    93,   146,   -88,
     -86,  -405,  -141,  -141,  -141,  -141,  -405,  -405,  -405,  -405,
    -405,  -405,  1886,  -405,  -405,   276,  -405,  -405,  -405,   293,
     299,   169,   305,   172,   390,   174,   423,   179,   183,   848,
    -141,  -141,  -405,  -405,  -405,   186,   188,   198,  -405,  1436,
     456,   567,   462,   567,   468,   567,   477,  1586,  -405,   485,
     491,   -77,  -141,  -405,  2276,   -75,   -71,   497,   567,   -69,
     567,   203,    93,  -141,   550,   -66,   -61,   567,   586,   -41,
     -55,   644,   -18,    -9,   650,    -5,   207,  -405,   673,   729,
     567,   212,  -405,   751,  -405,   798,   805,   227,   245,   258,
     264,   274,    93,   828,   280,   288,   297,   308,    93,   885,
      93,   908,   309,   311,   914,   312,   313,   922,   333,   334,
     341,   361,  -405,    10,    12,   363,    27,  -405,    16,    18,
    -405,    24,    43,  -405,    53,  -405,    60,    62,  -405,    65,
     976,   364,   366,   367,   368,  1004,   370,   848,     6,  -405,
    1085,   371,    68,   567,   374,   376,  -405,  1102,  -405,    70,
    1108,  1124,  -405,  -405,  1696,   377,  -405,  1702,   378,  -405,
    -405,  -405,   379,   381,   382,   383,  -405,  1708,  -405,   385,
     386,  -405,   388,  -405,  -405,  -405,   391,  1716,  -405,   392,
    -405,   393,   395,   396,  1851,   397,    74,  -405,  -405,  1859,
    -405,   398,  1868,   399,  2002,  2011,  2017,   401,  2137,   402,
    2145,   403,  -405,  -405,  -405,    93,   146,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  1286,  -405,  -405,
      84,   848,  -405,  -405,  2036,  -405,  2160,    89,    91,  -405,
    -405,  -405,    95,  -405,   108,  2166,   -55,  -405,   112,  2186,
    -405,   114,  2192,  -405,  -405,   404,  -405,  2198,  -405,   178,
      93,  -405,  -405,  -405,   182,  2204,  -405,   191,   406,  -405,
     193,  1736,  -405,   407,    82,  -405,   415,  -405,   195,   201,
    -405,   206,  -405,   210,   218,  -405,   223,  -405,  -405,  -405,
    -405,   233,  -405,  -405,  -405,   235,  2210,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  2216,  -405,  -405,  -405,
    -405,  -405,   416,  -405,   417,    93,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,    39,  -405,   418,
    -405,  -405,  -405,  -405,   419,    41,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
     420,  -405,  -405,   848,  -405,  -405,  -405,  -405,  -405,   237,
     240,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,   465,  -405,   432,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  2222,  2228,  -405,   244,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,   255,  -405,  -405,   263,  -405,  -405,   267,
    -405,  -405,  -405,   -55,  -405,  -405,   272,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,   291,  -405,  -405,  -405,  -405,   296,
    -405,  -405,  -405,   301,  -405,  -405,  -405,  2234,  -405,  -405,
    -405,  -405,   434,  -405,  -405,  -405,  -405,   303,  -405,  -405,
     435,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405
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
      27,    28,     0,   309,     8,     0,     4,     5,   326,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,   201,   202,     0,     0,     0,   206,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   224,     0,
       0,     0,     0,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,     0,
       0,     0,   269,     0,   271,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   299,     0,     0,     0,     0,   310,     0,     0,
     313,     0,     0,   316,     0,   318,     0,     0,   321,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,   342,     0,   344,     0,
       0,     0,   348,   350,     0,     0,   353,     0,     0,   355,
     356,   357,     0,     0,     0,     0,   363,     0,   364,     0,
       0,   367,     0,   369,   370,   371,     0,     0,   374,     0,
     376,     0,     0,     0,     0,     0,     0,   384,   386,     0,
     387,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    17,    20,     0,     0,   308,     7,   325,
     187,     6,   186,   191,   190,   193,   192,     0,   196,    23,
       0,    36,   195,   194,     0,    24,     0,     0,     0,   203,
     204,   205,     0,   210,     0,     0,    18,   214,     0,     0,
     218,     0,     0,   219,   223,     0,   222,     0,   225,     0,
       0,   228,   229,   233,     0,     0,   234,     0,     0,   237,
       0,     0,   242,     0,     0,   240,     0,   246,     0,     0,
     250,     0,   248,     0,     0,   254,     0,   255,   256,   257,
     259,     0,   260,   261,   266,     0,     0,   267,   268,   270,
     272,   273,   274,   275,   276,   277,     0,   279,   280,   281,
     282,   283,     0,   285,     0,     0,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,   300,     0,
     302,   303,    35,   307,     0,     0,   311,   312,   314,   315,
     317,   319,   320,   322,   323,   324,   327,   328,   329,   330,
       0,   332,    33,     0,   333,   334,     9,   335,   336,     0,
       0,   340,   341,   343,   345,   346,   347,   349,   351,   352,
     354,   358,   359,   360,   361,   362,   365,   366,   368,   372,
     373,   375,   377,   378,   379,   381,   380,     0,   382,     0,
     385,   388,   178,   179,   180,   181,   183,   182,   185,   184,
     189,   188,     0,     0,   389,     0,    37,   197,    25,   198,
     199,   207,   208,     0,   211,   212,     0,   215,   216,     0,
     220,   221,   227,     0,   230,   231,     0,   235,   236,   238,
     241,   239,   243,   244,     0,   249,   247,   251,   252,     0,
     258,   263,   264,     0,   278,   284,   286,     0,   301,   306,
      34,   305,     0,   331,    32,   337,   338,     0,   383,    21,
       0,   390,   209,   213,   217,   232,   245,   253,   265,   287,
     304,   339,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -405,  -405,  -404,   511,   868,  -140,  -405,    81,    71,     0,
    -315,  -405,  -101,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,   105,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,  -162,  -405,    97,  -405,
    -405,  -405,  -405,  -405,  -405,  -405,   180,  -405,  -405
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   304,   311,   305,   430,   306,   292,   526,
     511,   516,   307,   428,   615,   317,   318,     7,     8,     9,
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
       6,   290,   614,     1,   515,   293,   295,   340,   322,   633,
     309,   296,   297,   298,   299,   300,   301,   296,   297,   298,
     299,   300,   301,   344,   407,   330,   332,   334,   336,   339,
     612,   344,   410,   344,   413,   347,   291,   296,   297,   298,
     299,   300,   301,   323,   730,   364,   344,   415,   368,   369,
     324,   373,   375,   376,   344,   418,     1,   493,     1,   494,
     383,   296,   297,   298,   299,   300,   301,     1,   538,   344,
     541,     5,   289,   344,   542,   344,   546,   294,   554,   555,
     328,     4,   288,   344,   557,   343,     4,     4,   420,   344,
     296,   297,   298,   299,   300,   301,   296,   297,   298,   299,
     300,   301,   437,   344,   562,   440,   441,   406,   444,   427,
     447,   436,   632,   296,   297,   298,   299,   300,   301,   457,
     296,   297,   298,   299,   300,   301,   344,   567,   467,   296,
     297,   298,   299,   300,   301,   344,   568,   438,   479,   344,
     570,   482,   442,   484,   485,   296,   297,   298,   299,   300,
     301,   634,   302,   303,   607,   608,   344,   610,   302,   308,
     344,   616,   344,   617,   449,   331,   333,   335,   344,   618,
       6,     1,   613,   345,   346,   348,   350,   535,   337,   338,
     357,   279,   361,   362,   363,     1,   731,   344,   619,   370,
     450,   525,   451,   529,   458,   532,   686,   344,   620,   463,
     537,   688,   302,   367,   344,   621,   344,   622,   545,   344,
     623,   732,   344,   638,     1,   644,   271,   404,   667,   668,
     408,   409,   411,   412,   414,   416,   417,   419,   344,   684,
     576,   302,   372,     1,   689,     1,   690,   302,   433,   344,
     494,   341,   586,   464,     6,   296,   297,   298,   299,   300,
     301,     4,   344,   691,   302,   374,   344,   694,   344,   697,
     465,   302,   402,   296,   297,   298,   299,   300,   301,   468,
     302,   443,   470,   296,   297,   298,   299,   300,   301,   296,
     297,   298,   299,   300,   301,   477,   302,   446,   480,   293,
     295,   492,   293,   295,   293,   295,   296,   297,   298,   299,
     300,   301,   296,   297,   298,   299,   300,   301,   296,   297,
     298,   299,   300,   301,   502,   439,   510,   504,   734,   506,
       6,     6,     1,   702,   512,     4,   344,   704,   513,   522,
     524,   519,   528,   520,   531,   344,   707,     1,   709,   344,
     712,   293,     6,   521,   522,   344,   713,   544,   549,   547,
     344,   715,   572,     6,   344,   716,   558,   577,   561,   563,
     564,   294,   344,   717,   294,   571,   294,   344,   718,   575,
       4,     4,   581,     4,     4,     4,     4,   344,   720,   344,
     721,   344,   735,   496,   344,   736,   302,   456,   344,   741,
     582,   517,   518,   296,   297,   298,   299,   300,   301,   344,
     742,     4,     4,   583,   302,   461,     6,   344,   743,   584,
     496,   344,   744,   539,   302,   478,   344,   745,   496,   585,
     302,   497,     4,     4,   550,   588,   296,   297,   298,   299,
     300,   301,   639,   589,     4,   344,   746,   302,   499,   293,
     344,   747,   590,   302,   500,   344,   748,   344,   751,   302,
     503,   553,   556,   591,   597,   727,   598,   600,   601,   296,
     297,   298,   299,   300,   301,   296,   297,   298,   299,   300,
     301,   296,   297,   298,   299,   300,   301,     5,   603,   604,
     296,   297,   298,   299,   300,   301,   605,     4,   296,   297,
     298,   299,   300,   301,   296,   297,   298,   299,   300,   301,
     296,   297,   298,   299,   300,   301,   606,   290,   611,   625,
     685,   626,   627,   628,     6,   631,   637,   293,   293,   641,
       4,   642,   648,   650,   651,   693,   652,   653,   654,   696,
     656,   657,   699,   658,   302,   505,   659,   661,   662,   293,
     663,   664,   666,   671,   673,   706,   677,   679,   681,   700,
     293,   708,   710,   296,   297,   298,   299,   300,   301,   714,
     711,   725,   726,   728,   729,   733,   719,   507,   508,   241,
     296,   297,   298,   299,   300,   301,   723,   738,   683,   750,
     752,   669,   740,   609,     0,   683,     0,     0,   288,   296,
     297,   298,   299,   300,   301,   288,     0,     0,     4,     4,
     329,   523,     0,     0,     0,     0,   329,   527,     0,     0,
       0,     0,   329,   530,     0,     6,     0,     0,     0,     0,
       4,   302,   533,     0,     0,     0,     0,     0,     0,   337,
     534,     4,   496,     0,     0,   302,   536,     0,     0,     0,
     737,   329,   543,     0,     0,     0,     0,   296,   297,   298,
     299,   300,   301,   296,   297,   298,   299,   300,   301,     0,
       0,     0,   310,   312,   314,   316,   319,   320,   321,     0,
       0,     0,   325,   326,   327,     0,   296,   297,   298,   299,
     300,   301,   342,   293,     0,     0,     5,   349,   351,   352,
     354,   356,   358,   360,   551,   552,     4,   352,   366,     0,
       0,   371,     0,   510,     0,   352,   378,   352,   352,   381,
     382,   329,   352,   352,   352,   387,   352,   352,   352,   391,
     352,   394,   396,   397,   399,   400,   401,   403,     0,   352,
     329,   560,   296,   297,   298,   299,   300,   301,     0,     0,
     421,   422,   352,   424,   352,   352,     0,   352,   431,   432,
     434,   435,     0,     0,   296,   297,   298,   299,   300,   301,
     445,     0,   448,     0,     4,     0,   452,   352,   454,   352,
       0,     0,   459,   460,   462,     0,     0,     0,   466,     0,
       0,   352,     0,   471,   352,   473,   474,   476,   329,   565,
       0,   481,     0,   352,   302,   569,   486,   488,   490,     0,
       0,   296,   297,   298,   299,   300,   301,     0,   296,   297,
     298,   299,   300,   301,     0,     0,   498,   302,   573,     0,
     498,   501,     0,   501,     0,   501,     0,   509,     0,     0,
     509,   296,   297,   298,   299,   300,   301,     0,     0,     0,
       0,   498,     0,   498,     0,   498,     0,   498,     0,     0,
     498,   296,   297,   298,   299,   300,   301,     0,   498,     0,
       0,   548,     0,   501,     0,   501,     0,     0,   559,   501,
       0,     0,   566,   329,   574,   498,     0,     0,     0,   498,
     498,     0,     0,     0,   498,     0,   498,   498,   296,   297,
     298,   299,   300,   301,   498,   302,   578,     0,     0,   352,
     594,   352,   501,     0,     0,   501,     0,     0,   501,     0,
       0,   296,   297,   298,   299,   300,   301,   296,   297,   298,
     299,   300,   301,     0,     0,   296,   297,   298,   299,   300,
     301,   498,     0,     0,     0,     0,   630,     0,   509,     0,
       0,   352,   302,   579,   640,     0,     0,     0,   498,   302,
     580,   498,   498,     0,     0,   498,     0,     0,   498,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   498,     0,
       0,     0,   302,   587,     0,     0,     0,     0,   498,   296,
     297,   298,   299,   300,   301,   501,     0,     0,     0,     0,
     498,     0,   514,   498,     0,   498,   498,   501,     0,   501,
       0,   501,     0,     0,     0,     0,   682,   296,   297,   298,
     299,   300,   301,     0,     0,     0,     0,     0,     0,     0,
     313,   315,   509,     0,     0,     0,     0,   509,     0,   302,
     593,     0,     0,     0,     0,     0,   498,     0,     0,     0,
     498,     0,     0,   498,     0,     0,   353,   355,   498,   359,
       0,   703,   302,   596,   365,     0,   498,     0,   302,   599,
       0,     0,   377,     0,   379,   380,   302,   602,     0,   384,
     385,   386,     0,   388,   389,   390,   392,   393,   395,     0,
     398,     0,     0,     0,     0,     0,   405,   498,   296,   297,
     298,   299,   300,   301,     0,     0,     0,   498,     0,   423,
       0,   425,   426,     0,   429,   296,   297,   298,   299,   300,
     301,   296,   297,   298,   299,   300,   301,     0,     0,     0,
     302,   624,     0,     0,   453,     0,   455,   296,   297,   298,
     299,   300,   301,     0,     0,     0,     0,     0,   469,     0,
       0,   472,     0,   475,   509,     0,     0,     0,   302,   629,
     483,     0,     0,   487,   489,   491,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   509,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   302,
     635,     0,     0,     0,     0,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,     0,   302,   643,     0,     0,
       0,     0,   302,   645,     0,     0,   592,     0,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,   646,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   149,
     150,     0,     0,     0,     0,     0,     0,   151,   636,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,     0,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     0,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
       1,     0,   281,   282,   283,   284,   285,   286,   287,   149,
     150,     0,     0,     0,     0,     0,     0,   151,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,     0,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     0,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     329,     0,   281,   282,   283,   284,   285,   286,   287,   149,
     150,     0,     0,     0,     0,     0,     0,   151,     0,   152,
     153,   495,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,     0,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     0,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   296,
     297,   298,   299,   300,   301,   296,   297,   298,   299,   300,
     301,   296,   297,   298,   299,   300,   301,     0,   269,   296,
     297,   298,   299,   300,   301,     0,     0,     0,     0,     0,
     302,     0,   281,   282,   283,   284,   285,   286,   287,   149,
     150,     0,     0,     0,     0,     0,     0,   151,     0,   152,
     153,   495,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,     0,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     0,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     302,   647,     0,     0,     0,     0,   302,   649,     0,     0,
       0,     0,   302,   655,   296,   297,   298,   299,   300,   301,
     302,   660,   296,   297,   298,   299,   300,   301,     0,     0,
     271,   296,   297,   298,   299,   300,   301,     0,     0,     0,
     302,     0,   281,   282,   283,   284,   285,   286,   287,   149,
     150,     0,     0,     0,     0,     0,     0,   151,     0,   152,
     153,   495,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,     0,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     0,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     0,     0,     0,   302,   665,     0,     0,     0,
       0,     0,     0,   302,   670,   296,   297,   298,   299,   300,
     301,     0,   302,   672,   296,   297,   298,   299,   300,   301,
     296,   297,   298,   299,   300,   301,     0,     0,     0,     0,
     302,     0,   281,   282,   283,   284,   285,   286,   287,   149,
     150,     0,     0,     0,     0,     0,     0,   151,     0,   152,
     153,   495,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,     0,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     0,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     296,   297,   298,   299,   300,   301,   302,   674,   296,   297,
     298,   299,   300,   301,     0,   302,   675,     0,     0,     0,
       0,   302,   676,   296,   297,   298,   299,   300,   301,   296,
     297,   298,   299,   300,   301,     0,     0,     0,     0,     0,
       1,     0,   281,   282,   283,   284,   285,   286,   287,   296,
     297,   298,   299,   300,   301,   296,   297,   298,   299,   300,
     301,   296,   297,   298,   299,   300,   301,   296,   297,   298,
     299,   300,   301,   296,   297,   298,   299,   300,   301,   296,
     297,   298,   299,   300,   301,   296,   297,   298,   299,   300,
     301,   296,   297,   298,   299,   300,   301,   296,   297,   298,
     299,   300,   301,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,   678,     0,     0,     0,     0,     0,     0,   302,
     680,   540,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   514,   687,     0,     0,     0,     0,
     329,   692,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     329,   695,     0,     0,     0,     0,   329,   698,     0,     0,
       0,     0,   302,   701,     0,     0,     0,     0,   329,   705,
       0,     0,     0,     0,   329,   722,     0,     0,     0,     0,
     302,   724,     0,     0,     0,     0,   514,   508,     0,     0,
       0,     0,     1,   739,     0,     0,     0,     0,   302,   749,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     344
};

static const yytype_int16 yycheck[] =
{
       0,     1,   406,   144,   319,     5,     6,   169,   145,     3,
     150,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,   144,   145,   165,   166,   167,   168,   169,
       3,   144,   145,   144,   145,   175,     0,     3,     4,     5,
       6,     7,     8,   145,     3,   185,   144,   145,   188,   189,
     145,   191,   192,   193,   144,   145,   144,   145,   144,   145,
     200,     3,     4,     5,     6,     7,     8,   144,   145,   144,
     145,     0,     1,   144,   145,   144,   145,     6,   144,   145,
     145,     0,     1,   144,   145,   145,     5,     6,   228,   144,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,   242,   144,   145,   245,   246,     3,   248,     3,
     250,   145,   427,     3,     4,     5,     6,     7,     8,   259,
       3,     4,     5,     6,     7,     8,   144,   145,   268,     3,
       4,     5,     6,     7,     8,   144,   145,   145,   278,   144,
     145,   281,   145,   283,   284,     3,     4,     5,     6,     7,
       8,   145,   144,   145,   144,   145,   144,   145,   144,   145,
     144,   145,   144,   145,   145,   165,   166,   167,   144,   145,
     170,   144,   145,   173,   174,   175,   176,   339,   144,   145,
     180,   142,   182,   183,   184,   144,   145,   144,   145,   189,
     145,   331,   145,   333,   145,   335,   511,   144,   145,   145,
     340,   516,   144,   145,   144,   145,   144,   145,   348,   144,
     145,   615,   144,   145,   144,   145,   134,   217,   144,   145,
     220,   221,   222,   223,   224,   225,   226,   227,   144,   145,
     370,   144,   145,   144,   145,   144,   145,   144,   238,   144,
     145,   170,   382,   145,   244,     3,     4,     5,     6,     7,
       8,   170,   144,   145,   144,   145,   144,   145,   144,   145,
     145,   144,   145,     3,     4,     5,     6,     7,     8,   145,
     144,   145,   145,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,   145,   144,   145,   145,   289,
     290,   145,   292,   293,   294,   295,     3,     4,     5,     6,
       7,     8,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,   145,   244,   316,   145,   633,   145,
     320,   321,   144,   145,   145,   244,   144,   145,   145,   329,
     330,   145,   332,   145,   334,   144,   145,   144,   145,   144,
     145,   341,   342,   145,   344,   144,   145,   347,   145,   349,
     144,   145,   145,   353,   144,   145,   356,   145,   358,   359,
     360,   290,   144,   145,   293,   365,   295,   144,   145,   369,
     289,   290,   145,   292,   293,   294,   295,   144,   145,   144,
     145,   144,   145,   302,   144,   145,   144,   145,   144,   145,
     145,   320,   321,     3,     4,     5,     6,     7,     8,   144,
     145,   320,   321,   145,   144,   145,   406,   144,   145,   145,
     329,   144,   145,   342,   144,   145,   144,   145,   337,   145,
     144,   145,   341,   342,   353,   145,     3,     4,     5,     6,
       7,     8,   432,   145,   353,   144,   145,   144,   145,   439,
     144,   145,   145,   144,   145,   144,   145,   144,   145,   144,
     145,   354,   355,   145,   145,   595,   145,   145,   145,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,   406,   145,   145,
       3,     4,     5,     6,     7,     8,   145,   406,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,   145,   507,   145,   145,
     510,   145,   145,   145,   514,   145,   145,   517,   518,   145,
     439,   145,   145,   145,   145,   525,   145,   145,   145,   529,
     145,   145,   532,   145,   144,   145,   145,   145,   145,   539,
     145,   145,   145,   145,   145,   545,   145,   145,   145,   145,
     550,   145,   145,     3,     4,     5,     6,     7,     8,   559,
     145,   145,   145,   145,   145,   145,   566,   144,   145,   104,
       3,     4,     5,     6,     7,     8,   576,   145,   507,   145,
     145,   476,   683,   403,    -1,   514,    -1,    -1,   507,     3,
       4,     5,     6,     7,     8,   514,    -1,    -1,   517,   518,
     144,   145,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,
      -1,    -1,   144,   145,    -1,   615,    -1,    -1,    -1,    -1,
     539,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   550,   551,    -1,    -1,   144,   145,    -1,    -1,    -1,
     640,   144,   145,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,   151,   152,   153,   154,   155,   156,   157,    -1,
      -1,    -1,   161,   162,   163,    -1,     3,     4,     5,     6,
       7,     8,   171,   683,    -1,    -1,   615,   176,   177,   178,
     179,   180,   181,   182,   144,   145,   615,   186,   187,    -1,
      -1,   190,    -1,   703,    -1,   194,   195,   196,   197,   198,
     199,   144,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,   218,
     144,   145,     3,     4,     5,     6,     7,     8,    -1,    -1,
     229,   230,   231,   232,   233,   234,    -1,   236,   237,   238,
     239,   240,    -1,    -1,     3,     4,     5,     6,     7,     8,
     249,    -1,   251,    -1,   683,    -1,   255,   256,   257,   258,
      -1,    -1,   261,   262,   263,    -1,    -1,    -1,   267,    -1,
      -1,   270,    -1,   272,   273,   274,   275,   276,   144,   145,
      -1,   280,    -1,   282,   144,   145,   285,   286,   287,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,     3,     4,
       5,     6,     7,     8,    -1,    -1,   305,   144,   145,    -1,
     309,   310,    -1,   312,    -1,   314,    -1,   316,    -1,    -1,
     319,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,   330,    -1,   332,    -1,   334,    -1,   336,    -1,    -1,
     339,     3,     4,     5,     6,     7,     8,    -1,   347,    -1,
      -1,   350,    -1,   352,    -1,   354,    -1,    -1,   357,   358,
      -1,    -1,   361,   144,   145,   364,    -1,    -1,    -1,   368,
     369,    -1,    -1,    -1,   373,    -1,   375,   376,     3,     4,
       5,     6,     7,     8,   383,   144,   145,    -1,    -1,   388,
     389,   390,   391,    -1,    -1,   394,    -1,    -1,   397,    -1,
      -1,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,    -1,    -1,     3,     4,     5,     6,     7,
       8,   420,    -1,    -1,    -1,    -1,   425,    -1,   427,    -1,
      -1,   430,   144,   145,   433,    -1,    -1,    -1,   437,   144,
     145,   440,   441,    -1,    -1,   444,    -1,    -1,   447,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   457,    -1,
      -1,    -1,   144,   145,    -1,    -1,    -1,    -1,   467,     3,
       4,     5,     6,     7,     8,   474,    -1,    -1,    -1,    -1,
     479,    -1,   144,   482,    -1,   484,   485,   486,    -1,   488,
      -1,   490,    -1,    -1,    -1,    -1,   495,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,   153,   511,    -1,    -1,    -1,    -1,   516,    -1,   144,
     145,    -1,    -1,    -1,    -1,    -1,   525,    -1,    -1,    -1,
     529,    -1,    -1,   532,    -1,    -1,   178,   179,   537,   181,
      -1,   540,   144,   145,   186,    -1,   545,    -1,   144,   145,
      -1,    -1,   194,    -1,   196,   197,   144,   145,    -1,   201,
     202,   203,    -1,   205,   206,   207,   208,   209,   210,    -1,
     212,    -1,    -1,    -1,    -1,    -1,   218,   576,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,   586,    -1,   231,
      -1,   233,   234,    -1,   236,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
     144,   145,    -1,    -1,   256,    -1,   258,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,   270,    -1,
      -1,   273,    -1,   275,   633,    -1,    -1,    -1,   144,   145,
     282,    -1,    -1,   285,   286,   287,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   682,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   727,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,
      -1,    -1,   144,   145,    -1,    -1,   388,    -1,   390,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    11,   430,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,    -1,   132,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     144,   145,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,
      -1,    -1,   144,   145,     3,     4,     5,     6,     7,     8,
     144,   145,     3,     4,     5,     6,     7,     8,    -1,    -1,
     134,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,     3,     4,     5,     6,     7,
       8,    -1,   144,   145,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       3,     4,     5,     6,     7,     8,   144,   145,     3,     4,
       5,     6,     7,     8,    -1,   144,   145,    -1,    -1,    -1,
      -1,   144,   145,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,    -1,
     144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,
      -1,    -1,   144,   145,    -1,    -1,    -1,    -1,   144,   145,
      -1,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,    -1,
     144,   145,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,
      -1,    -1,   144,   145,    -1,    -1,    -1,    -1,   144,   145,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144
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
     156,   157,   156,   157,   156,   157,   156,   168,   169,   156,
     156,   156,   145,   145,   145,   156,   156,   156,   145,   144,
     158,   162,   158,   162,   158,   162,   158,   144,   145,   158,
     299,   161,   156,   145,   144,   162,   162,   158,   162,   156,
     162,   156,   156,   157,   156,   157,   156,   162,   156,   157,
     156,   162,   162,   162,   158,   157,   156,   145,   158,   158,
     162,   156,   145,   158,   145,   158,   158,   157,   156,   157,
     157,   156,   156,   158,   157,   157,   157,   156,   157,   157,
     157,   156,   157,   157,   156,   157,   156,   156,   157,   156,
     156,   156,   145,   156,   162,   157,     3,   145,   162,   162,
     145,   162,   162,   145,   162,   145,   162,   162,   145,   162,
     158,   156,   156,   157,   156,   157,   157,     3,   166,   157,
     159,   156,   156,   162,   156,   156,   145,   158,   145,   161,
     158,   158,   145,   145,   158,   156,   145,   158,   156,   145,
     145,   145,   156,   157,   156,   157,   145,   158,   145,   156,
     156,   145,   156,   145,   145,   145,   156,   158,   145,   157,
     145,   156,   157,   156,   156,   157,   156,   145,   145,   158,
     145,   156,   158,   157,   158,   158,   156,   157,   156,   157,
     156,   157,   145,   145,   145,    15,   160,   145,   156,   145,
     145,   156,   145,   145,   145,   145,   145,   144,   145,   156,
     162,   163,   145,   145,   144,   163,   164,   161,   161,   145,
     145,   145,   162,   145,   162,   158,   162,   145,   162,   158,
     145,   162,   158,   145,   145,   299,   145,   158,   145,   161,
      15,   145,   145,   145,   162,   158,   145,   162,   156,   145,
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
     145,   145,   145,   145,   145,   145,   145,   144,   145,   271,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   156,   161,   145,   162,   163,   145,   163,   145,
     145,   145,   145,   162,   145,   145,   162,   145,   145,   162,
     145,   145,   145,   156,   145,   145,   162,   145,   145,   145,
     145,   145,   145,   145,   162,   145,   145,   145,   145,   162,
     145,   145,   145,   162,   145,   145,   145,   158,   145,   145,
       3,   145,   155,   145,   163,   145,   145,   162,   145,   145,
     165,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145
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
     174,   175,   176,   176,   177,   177,   178,   178,   179,   179,
     180,   180,   181,   181,   182,   182,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   193,   193,
     193,   194,   194,   194,   194,   195,   195,   195,   195,   196,
     197,   197,   197,   197,   197,   198,   199,   200,   201,   202,
     203,   203,   203,   203,   204,   204,   204,   205,   206,   207,
     207,   207,   207,   208,   208,   208,   208,   209,   209,   209,
     209,   210,   210,   210,   210,   211,   212,   213,   214,   214,
     215,   216,   216,   217,   217,   217,   217,   218,   219,   219,
     220,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   234,   235,   236,   236,
     237,   238,   238,   239,   240,   240,   241,   242,   243,   244,
     244,   244,   245,   246,   247,   247,   247,   247,   248,   248,
     249,   249,   250,   251,   251,   252,   253,   253,   254,   254,
     255,   256,   256,   257,   258,   259,   259,   260,   261,   262,
     263,   263,   264,   265,   266,   267,   268,   268,   268,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     278,   279,   280,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   289,   290,   291,   292,   293,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   305,   306,   306,   307,   308,   308,   309,   310,   311,
     311
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
       4,     4,     4,     4,     4,     4,     4,     5,     5,     5,
       3,     3,     3,     4,     4,     4,     3,     5,     5,     6,
       4,     5,     5,     6,     4,     5,     5,     6,     4,     4,
       5,     5,     4,     4,     3,     4,     3,     5,     4,     4,
       5,     5,     6,     4,     4,     5,     5,     4,     5,     5,
       4,     5,     4,     5,     5,     6,     4,     5,     4,     5,
       4,     5,     5,     6,     4,     4,     4,     4,     5,     4,
       4,     4,     3,     5,     5,     6,     4,     4,     4,     3,
       4,     3,     4,     4,     4,     4,     4,     4,     5,     4,
       4,     4,     4,     4,     5,     4,     5,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       4,     5,     4,     4,     6,     5,     5,     4,     4,     3,
       3,     4,     4,     3,     4,     4,     3,     4,     3,     4,
       4,     3,     4,     4,     4,     4,     3,     4,     4,     4,
       4,     5,     4,     4,     4,     4,     4,     5,     5,     6,
       4,     4,     3,     4,     3,     4,     4,     4,     3,     4,
       3,     4,     4,     3,     4,     3,     3,     3,     4,     4,
       4,     4,     4,     3,     3,     4,     4,     3,     4,     3,
       3,     3,     4,     4,     3,     4,     3,     4,     4,     4,
       4,     4,     4,     5,     3,     4,     3,     3,     4,     5,
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
#line 2111 "parser.c"
        break;

    case 4: /* STR  */
#line 73 "../src/parser.y"
            { free(((*yyvaluep).s)); }
#line 2117 "parser.c"
        break;

    case 154: /* start  */
#line 71 "../src/parser.y"
            { run(((*yyvaluep).e));  }
#line 2123 "parser.c"
        break;

    case 155: /* s  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2129 "parser.c"
        break;

    case 156: /* p  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2135 "parser.c"
        break;

    case 157: /* pp  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2141 "parser.c"
        break;

    case 158: /* ps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2147 "parser.c"
        break;

    case 159: /* pps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2153 "parser.c"
        break;

    case 160: /* vp  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2159 "parser.c"
        break;

    case 161: /* vps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2165 "parser.c"
        break;

    case 162: /* opts  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2171 "parser.c"
        break;

    case 163: /* xpb  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2177 "parser.c"
        break;

    case 164: /* xpbs  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2183 "parser.c"
        break;

    case 165: /* np  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2189 "parser.c"
        break;

    case 166: /* sps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2195 "parser.c"
        break;

    case 167: /* par  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2201 "parser.c"
        break;

    case 168: /* cv  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2207 "parser.c"
        break;

    case 169: /* cvv  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2213 "parser.c"
        break;

    case 170: /* opt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2219 "parser.c"
        break;

    case 171: /* ivp  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2225 "parser.c"
        break;

    case 172: /* add  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2231 "parser.c"
        break;

    case 173: /* div  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2237 "parser.c"
        break;

    case 174: /* mul  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2243 "parser.c"
        break;

    case 175: /* sub  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2249 "parser.c"
        break;

    case 176: /* eq  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2255 "parser.c"
        break;

    case 177: /* gt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2261 "parser.c"
        break;

    case 178: /* gte  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2267 "parser.c"
        break;

    case 179: /* lt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2273 "parser.c"
        break;

    case 180: /* lte  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2279 "parser.c"
        break;

    case 181: /* neq  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2285 "parser.c"
        break;

    case 182: /* if  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2291 "parser.c"
        break;

    case 183: /* select  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2297 "parser.c"
        break;

    case 184: /* until  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2303 "parser.c"
        break;

    case 185: /* while  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2309 "parser.c"
        break;

    case 186: /* trace  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2315 "parser.c"
        break;

    case 187: /* retrace  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2321 "parser.c"
        break;

    case 188: /* astraw  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2327 "parser.c"
        break;

    case 189: /* asbraw  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2333 "parser.c"
        break;

    case 190: /* asbeval  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2339 "parser.c"
        break;

    case 191: /* eval  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2345 "parser.c"
        break;

    case 192: /* options  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2351 "parser.c"
        break;

    case 193: /* execute  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2357 "parser.c"
        break;

    case 194: /* rexx  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2363 "parser.c"
        break;

    case 195: /* run  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2369 "parser.c"
        break;

    case 196: /* abort  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2375 "parser.c"
        break;

    case 197: /* exit  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2381 "parser.c"
        break;

    case 198: /* onerror  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2387 "parser.c"
        break;

    case 199: /* reboot  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2393 "parser.c"
        break;

    case 200: /* trap  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2399 "parser.c"
        break;

    case 201: /* copyfiles  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2405 "parser.c"
        break;

    case 202: /* copylib  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2411 "parser.c"
        break;

    case 203: /* delete  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2417 "parser.c"
        break;

    case 204: /* exists  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2423 "parser.c"
        break;

    case 205: /* fileonly  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2429 "parser.c"
        break;

    case 206: /* foreach  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2435 "parser.c"
        break;

    case 207: /* makeassign  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2441 "parser.c"
        break;

    case 208: /* makedir  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2447 "parser.c"
        break;

    case 209: /* protect  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2453 "parser.c"
        break;

    case 210: /* startup  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2459 "parser.c"
        break;

    case 211: /* textfile  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2465 "parser.c"
        break;

    case 212: /* tooltype  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2471 "parser.c"
        break;

    case 213: /* transcript  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2477 "parser.c"
        break;

    case 214: /* rename  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2483 "parser.c"
        break;

    case 215: /* complete  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2489 "parser.c"
        break;

    case 216: /* debug  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2495 "parser.c"
        break;

    case 217: /* message  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2501 "parser.c"
        break;

    case 218: /* user  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2507 "parser.c"
        break;

    case 219: /* welcome  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2513 "parser.c"
        break;

    case 220: /* working  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2519 "parser.c"
        break;

    case 221: /* and  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2525 "parser.c"
        break;

    case 222: /* bitand  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2531 "parser.c"
        break;

    case 223: /* bitnot  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2537 "parser.c"
        break;

    case 224: /* bitor  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2543 "parser.c"
        break;

    case 225: /* bitxor  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2549 "parser.c"
        break;

    case 226: /* not  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2555 "parser.c"
        break;

    case 227: /* in  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2561 "parser.c"
        break;

    case 228: /* or  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2567 "parser.c"
        break;

    case 229: /* shiftleft  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2573 "parser.c"
        break;

    case 230: /* shiftright  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2579 "parser.c"
        break;

    case 231: /* xor  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2585 "parser.c"
        break;

    case 232: /* closemedia  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2591 "parser.c"
        break;

    case 233: /* effect  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2597 "parser.c"
        break;

    case 234: /* setmedia  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2603 "parser.c"
        break;

    case 235: /* showmedia  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2609 "parser.c"
        break;

    case 236: /* database  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2615 "parser.c"
        break;

    case 237: /* earlier  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2621 "parser.c"
        break;

    case 238: /* getassign  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2627 "parser.c"
        break;

    case 239: /* getdevice  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2633 "parser.c"
        break;

    case 240: /* getdiskspace  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2639 "parser.c"
        break;

    case 241: /* getenv  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2645 "parser.c"
        break;

    case 242: /* getsize  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2651 "parser.c"
        break;

    case 243: /* getsum  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2657 "parser.c"
        break;

    case 244: /* getversion  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2663 "parser.c"
        break;

    case 245: /* iconinfo  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2669 "parser.c"
        break;

    case 246: /* querydisplay  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2675 "parser.c"
        break;

    case 247: /* dcl  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2681 "parser.c"
        break;

    case 248: /* cus  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2687 "parser.c"
        break;

    case 249: /* askbool  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2693 "parser.c"
        break;

    case 250: /* askchoice  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2699 "parser.c"
        break;

    case 251: /* askdir  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2705 "parser.c"
        break;

    case 252: /* askdisk  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2711 "parser.c"
        break;

    case 253: /* askfile  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2717 "parser.c"
        break;

    case 254: /* asknumber  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2723 "parser.c"
        break;

    case 255: /* askoptions  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2729 "parser.c"
        break;

    case 256: /* askstring  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2735 "parser.c"
        break;

    case 257: /* cat  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2741 "parser.c"
        break;

    case 258: /* expandpath  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2747 "parser.c"
        break;

    case 259: /* fmt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2753 "parser.c"
        break;

    case 260: /* pathonly  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2759 "parser.c"
        break;

    case 261: /* patmatch  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2765 "parser.c"
        break;

    case 262: /* strlen  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2771 "parser.c"
        break;

    case 263: /* substr  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2777 "parser.c"
        break;

    case 264: /* tackon  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2783 "parser.c"
        break;

    case 265: /* set  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2789 "parser.c"
        break;

    case 266: /* symbolset  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2795 "parser.c"
        break;

    case 267: /* symbolval  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2801 "parser.c"
        break;

    case 268: /* openwbobject  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2807 "parser.c"
        break;

    case 269: /* showwbobject  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2813 "parser.c"
        break;

    case 270: /* closewbobject  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2819 "parser.c"
        break;

    case 271: /* all  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2825 "parser.c"
        break;

    case 272: /* append  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2831 "parser.c"
        break;

    case 273: /* assigns  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2837 "parser.c"
        break;

    case 274: /* back  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2843 "parser.c"
        break;

    case 275: /* choices  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2849 "parser.c"
        break;

    case 276: /* command  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2855 "parser.c"
        break;

    case 277: /* compression  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2861 "parser.c"
        break;

    case 278: /* confirm  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2867 "parser.c"
        break;

    case 279: /* default  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2873 "parser.c"
        break;

    case 280: /* delopts  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2879 "parser.c"
        break;

    case 281: /* dest  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2885 "parser.c"
        break;

    case 282: /* disk  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2891 "parser.c"
        break;

    case 283: /* files  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2897 "parser.c"
        break;

    case 284: /* fonts  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2903 "parser.c"
        break;

    case 285: /* getdefaulttool  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2909 "parser.c"
        break;

    case 286: /* getposition  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2915 "parser.c"
        break;

    case 287: /* getstack  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2921 "parser.c"
        break;

    case 288: /* gettooltype  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2927 "parser.c"
        break;

    case 289: /* help  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2933 "parser.c"
        break;

    case 290: /* infos  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2939 "parser.c"
        break;

    case 291: /* include  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2945 "parser.c"
        break;

    case 292: /* newname  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2951 "parser.c"
        break;

    case 293: /* newpath  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2957 "parser.c"
        break;

    case 294: /* nogauge  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2963 "parser.c"
        break;

    case 295: /* noposition  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2969 "parser.c"
        break;

    case 296: /* noreq  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2975 "parser.c"
        break;

    case 297: /* pattern  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2981 "parser.c"
        break;

    case 298: /* prompt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2987 "parser.c"
        break;

    case 299: /* quiet  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2993 "parser.c"
        break;

    case 300: /* range  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2999 "parser.c"
        break;

    case 301: /* safe  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3005 "parser.c"
        break;

    case 302: /* setdefaulttool  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3011 "parser.c"
        break;

    case 303: /* setposition  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3017 "parser.c"
        break;

    case 304: /* setstack  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3023 "parser.c"
        break;

    case 305: /* settooltype  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3029 "parser.c"
        break;

    case 306: /* source  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3035 "parser.c"
        break;

    case 307: /* swapcolors  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3041 "parser.c"
        break;

    case 308: /* optional  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3047 "parser.c"
        break;

    case 309: /* resident  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3053 "parser.c"
        break;

    case 310: /* override  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3059 "parser.c"
        break;

    case 311: /* dynopt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3065 "parser.c"
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
#line 3339 "parser.c"
    break;

  case 6:
#line 94 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3345 "parser.c"
    break;

  case 7:
#line 95 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3351 "parser.c"
    break;

  case 8:
#line 96 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3357 "parser.c"
    break;

  case 9:
#line 97 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3363 "parser.c"
    break;

  case 12:
#line 100 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3369 "parser.c"
    break;

  case 13:
#line 101 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3375 "parser.c"
    break;

  case 14:
#line 102 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e));  }
#line 3381 "parser.c"
    break;

  case 15:
#line 103 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e));  }
#line 3387 "parser.c"
    break;

  case 16:
#line 104 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3393 "parser.c"
    break;

  case 17:
#line 105 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3399 "parser.c"
    break;

  case 18:
#line 106 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3405 "parser.c"
    break;

  case 19:
#line 107 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3411 "parser.c"
    break;

  case 20:
#line 108 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3417 "parser.c"
    break;

  case 21:
#line 109 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3423 "parser.c"
    break;

  case 22:
#line 110 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-2].e), (yyvsp[-1].e)); }
#line 3429 "parser.c"
    break;

  case 23:
#line 111 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3435 "parser.c"
    break;

  case 24:
#line 112 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3441 "parser.c"
    break;

  case 25:
#line 113 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3447 "parser.c"
    break;

  case 26:
#line 114 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3453 "parser.c"
    break;

  case 27:
#line 115 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3459 "parser.c"
    break;

  case 28:
#line 116 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3465 "parser.c"
    break;

  case 29:
#line 117 "../src/parser.y"
                                                 { (yyval.e) = new_string((yyvsp[0].s)); }
#line 3471 "parser.c"
    break;

  case 30:
#line 118 "../src/parser.y"
                                                 { (yyval.e) = new_symref((yyvsp[0].s), LINE); }
#line 3477 "parser.c"
    break;

  case 31:
#line 119 "../src/parser.y"
                                                 { (yyval.e) = NULL; YYFPRINTF(stderr, "Out of memory in line %d\n", LINE); YYABORT; }
#line 3483 "parser.c"
    break;

  case 32:
#line 120 "../src/parser.y"
                                                 { (yyval.e) = push(push((yyvsp[-2].e), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)) ; }
#line 3489 "parser.c"
    break;

  case 33:
#line 121 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)); }
#line 3495 "parser.c"
    break;

  case 34:
#line 122 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), new_symbol((yyvsp[0].s))); }
#line 3501 "parser.c"
    break;

  case 35:
#line 123 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), new_symbol((yyvsp[0].s))); }
#line 3507 "parser.c"
    break;

  case 36:
#line 124 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3513 "parser.c"
    break;

  case 37:
#line 125 "../src/parser.y"
                                                 { (yyval.e) = push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3519 "parser.c"
    break;

  case 178:
#line 275 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("+"), LINE, n_add, (yyvsp[-1].e), NUMBER); }
#line 3525 "parser.c"
    break;

  case 179:
#line 276 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("/"), LINE, n_div, (yyvsp[-1].e), NUMBER); }
#line 3531 "parser.c"
    break;

  case 180:
#line 277 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("*"), LINE, n_mul, (yyvsp[-1].e), NUMBER); }
#line 3537 "parser.c"
    break;

  case 181:
#line 278 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("-"), LINE, n_sub, (yyvsp[-1].e), NUMBER); }
#line 3543 "parser.c"
    break;

  case 182:
#line 282 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("="), LINE, n_eq, (yyvsp[-1].e), NUMBER); }
#line 3549 "parser.c"
    break;

  case 183:
#line 283 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("="), LINE, n_eq, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3555 "parser.c"
    break;

  case 184:
#line 284 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup(">"), LINE, n_gt, (yyvsp[-1].e), NUMBER); }
#line 3561 "parser.c"
    break;

  case 185:
#line 285 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup(">"), LINE, n_gt, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3567 "parser.c"
    break;

  case 186:
#line 286 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup(">="), LINE, n_gte, (yyvsp[-1].e), NUMBER); }
#line 3573 "parser.c"
    break;

  case 187:
#line 287 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup(">="), LINE, n_gte, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3579 "parser.c"
    break;

  case 188:
#line 288 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<"), LINE, n_lt, (yyvsp[-1].e), NUMBER); }
#line 3585 "parser.c"
    break;

  case 189:
#line 289 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<"), LINE, n_lt, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3591 "parser.c"
    break;

  case 190:
#line 290 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<="), LINE, n_lte, (yyvsp[-1].e), NUMBER); }
#line 3597 "parser.c"
    break;

  case 191:
#line 291 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<="), LINE, n_lte, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3603 "parser.c"
    break;

  case 192:
#line 292 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<>"), LINE, n_neq, (yyvsp[-1].e), NUMBER); }
#line 3609 "parser.c"
    break;

  case 193:
#line 293 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<>"), LINE, n_neq, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3615 "parser.c"
    break;

  case 194:
#line 297 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("if"), LINE, n_if, (yyvsp[-1].e), NUMBER); }
#line 3621 "parser.c"
    break;

  case 195:
#line 298 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("if"), LINE, n_if, (yyvsp[-1].e), NUMBER); }
#line 3627 "parser.c"
    break;

  case 196:
#line 299 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("if"), LINE, n_if, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3633 "parser.c"
    break;

  case 197:
#line 300 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("select"), LINE, n_select, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3639 "parser.c"
    break;

  case 198:
#line 301 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("until"), LINE, n_until, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3645 "parser.c"
    break;

  case 199:
#line 302 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("while"), LINE, n_while, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3651 "parser.c"
    break;

  case 200:
#line 303 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("trace"), LINE, n_trace, NULL, NUMBER); }
#line 3657 "parser.c"
    break;

  case 201:
#line 304 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("retrace"), LINE, n_retrace, NULL, NUMBER); }
#line 3663 "parser.c"
    break;

  case 202:
#line 308 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___astraw"), LINE, n_astraw, NULL, NUMBER); }
#line 3669 "parser.c"
    break;

  case 203:
#line 309 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___asbraw"), LINE, n_asbraw, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3675 "parser.c"
    break;

  case 204:
#line 310 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___asbeval"), LINE, n_asbeval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3681 "parser.c"
    break;

  case 205:
#line 311 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___eval"), LINE, n_eval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3687 "parser.c"
    break;

  case 206:
#line 312 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___options"), LINE, n_options, NULL, NUMBER); }
#line 3693 "parser.c"
    break;

  case 207:
#line 316 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, n_execute, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3699 "parser.c"
    break;

  case 208:
#line 317 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, n_execute, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3705 "parser.c"
    break;

  case 209:
#line 318 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, n_execute, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3711 "parser.c"
    break;

  case 210:
#line 319 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, n_execute, (yyvsp[-1].e), NUMBER); }
#line 3717 "parser.c"
    break;

  case 211:
#line 320 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, n_rexx, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3723 "parser.c"
    break;

  case 212:
#line 321 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, n_rexx, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3729 "parser.c"
    break;

  case 213:
#line 322 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, n_rexx, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3735 "parser.c"
    break;

  case 214:
#line 323 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, n_rexx, (yyvsp[-1].e), NUMBER); }
#line 3741 "parser.c"
    break;

  case 215:
#line 324 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, n_run, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3747 "parser.c"
    break;

  case 216:
#line 325 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, n_run, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3753 "parser.c"
    break;

  case 217:
#line 326 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, n_run, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3759 "parser.c"
    break;

  case 218:
#line 327 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, n_run, (yyvsp[-1].e), NUMBER); }
#line 3765 "parser.c"
    break;

  case 219:
#line 331 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("abort"), LINE, n_abort, (yyvsp[-1].e), NUMBER); }
#line 3771 "parser.c"
    break;

  case 220:
#line 332 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, n_exit, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3777 "parser.c"
    break;

  case 221:
#line 333 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, n_exit, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3783 "parser.c"
    break;

  case 222:
#line 334 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, n_exit, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3789 "parser.c"
    break;

  case 223:
#line 335 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, n_exit, (yyvsp[-1].e), NUMBER); }
#line 3795 "parser.c"
    break;

  case 224:
#line 336 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, n_exit, NULL, NUMBER); }
#line 3801 "parser.c"
    break;

  case 225:
#line 337 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("onerror"), LINE, n_procedure, push(new_contxt(),
                                                        new_custom(strdup("@onerror"), LINE, NULL, (yyvsp[-1].e))), DANGLE); }
#line 3808 "parser.c"
    break;

  case 226:
#line 339 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("reboot"), LINE, n_reboot, NULL, NUMBER); }
#line 3814 "parser.c"
    break;

  case 227:
#line 340 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("trap"), LINE, n_trap, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3820 "parser.c"
    break;

  case 228:
#line 344 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("copyfiles"), LINE, n_copyfiles, (yyvsp[-1].e), NUMBER); }
#line 3826 "parser.c"
    break;

  case 229:
#line 345 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("copylib"), LINE, n_copylib, (yyvsp[-1].e), NUMBER); }
#line 3832 "parser.c"
    break;

  case 230:
#line 346 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, n_delete, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3838 "parser.c"
    break;

  case 231:
#line 347 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, n_delete, merge((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3844 "parser.c"
    break;

  case 232:
#line 348 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, n_delete, merge((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3850 "parser.c"
    break;

  case 233:
#line 349 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, n_delete, (yyvsp[-1].e), NUMBER); }
#line 3856 "parser.c"
    break;

  case 234:
#line 350 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exists"), LINE, n_exists, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3862 "parser.c"
    break;

  case 235:
#line 351 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exists"), LINE, n_exists, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3868 "parser.c"
    break;

  case 236:
#line 352 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exists"), LINE, n_exists, merge(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3874 "parser.c"
    break;

  case 237:
#line 353 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("fileonly"), LINE, n_fileonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3880 "parser.c"
    break;

  case 238:
#line 354 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("foreach"), LINE, n_foreach, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3886 "parser.c"
    break;

  case 239:
#line 355 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, n_makeassign, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3892 "parser.c"
    break;

  case 240:
#line 356 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, n_makeassign, (yyvsp[-1].e), NUMBER); }
#line 3898 "parser.c"
    break;

  case 241:
#line 357 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, n_makeassign, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3904 "parser.c"
    break;

  case 242:
#line 358 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, n_makeassign, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3910 "parser.c"
    break;

  case 243:
#line 359 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, n_makedir, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3916 "parser.c"
    break;

  case 244:
#line 360 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, n_makedir, merge(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3922 "parser.c"
    break;

  case 245:
#line 361 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, n_makedir, merge(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3928 "parser.c"
    break;

  case 246:
#line 362 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, n_makedir, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3934 "parser.c"
    break;

  case 247:
#line 363 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, n_protect, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3940 "parser.c"
    break;

  case 248:
#line 364 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, n_protect, (yyvsp[-1].e), NUMBER); }
#line 3946 "parser.c"
    break;

  case 249:
#line 365 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, n_protect, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3952 "parser.c"
    break;

  case 250:
#line 366 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, n_protect, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3958 "parser.c"
    break;

  case 251:
#line 367 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, n_startup, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3964 "parser.c"
    break;

  case 252:
#line 368 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, n_startup, merge(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3970 "parser.c"
    break;

  case 253:
#line 369 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, n_startup, merge(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3976 "parser.c"
    break;

  case 254:
#line 370 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, n_startup, merge(push(new_contxt(), new_symref(strdup("@app-name"), LINE)), (yyvsp[-1].e)), NUMBER); }
#line 3982 "parser.c"
    break;

  case 255:
#line 371 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("textfile"), LINE, n_textfile, (yyvsp[-1].e), NUMBER); }
#line 3988 "parser.c"
    break;

  case 256:
#line 372 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("tooltype"), LINE, n_tooltype, (yyvsp[-1].e), NUMBER); }
#line 3994 "parser.c"
    break;

  case 257:
#line 373 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("transcript"), LINE, n_transcript, (yyvsp[-1].e), NUMBER); }
#line 4000 "parser.c"
    break;

  case 258:
#line 374 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rename"), LINE, n_rename, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4006 "parser.c"
    break;

  case 259:
#line 375 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rename"), LINE, n_rename, (yyvsp[-1].e), NUMBER); }
#line 4012 "parser.c"
    break;

  case 260:
#line 379 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("complete"), LINE, n_complete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4018 "parser.c"
    break;

  case 261:
#line 380 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("debug"), LINE, n_debug, (yyvsp[-1].e), NUMBER); }
#line 4024 "parser.c"
    break;

  case 262:
#line 381 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("debug"), LINE, n_debug, NULL, NUMBER); }
#line 4030 "parser.c"
    break;

  case 263:
#line 382 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, n_message, merge((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 4036 "parser.c"
    break;

  case 264:
#line 383 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, n_message, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4042 "parser.c"
    break;

  case 265:
#line 384 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, n_message, push(merge((yyvsp[-3].e), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4048 "parser.c"
    break;

  case 266:
#line 385 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, n_message, (yyvsp[-1].e), NUMBER); }
#line 4054 "parser.c"
    break;

  case 267:
#line 386 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("user"), LINE, n_user, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4060 "parser.c"
    break;

  case 268:
#line 387 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("welcome"), LINE, n_welcome, (yyvsp[-1].e), NUMBER); }
#line 4066 "parser.c"
    break;

  case 269:
#line 388 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("welcome"), LINE, n_welcome, NULL, NUMBER); }
#line 4072 "parser.c"
    break;

  case 270:
#line 389 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("working"), LINE, n_working, (yyvsp[-1].e), NUMBER); }
#line 4078 "parser.c"
    break;

  case 271:
#line 390 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("working"), LINE, n_working, NULL, NUMBER); }
#line 4084 "parser.c"
    break;

  case 272:
#line 394 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("AND"), LINE, n_and, (yyvsp[-1].e), NUMBER); }
#line 4090 "parser.c"
    break;

  case 273:
#line 395 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITAND"), LINE, n_bitand, (yyvsp[-1].e), NUMBER); }
#line 4096 "parser.c"
    break;

  case 274:
#line 396 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITNOT"), LINE, n_bitnot, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4102 "parser.c"
    break;

  case 275:
#line 397 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITOR"), LINE, n_bitor, (yyvsp[-1].e), NUMBER); }
#line 4108 "parser.c"
    break;

  case 276:
#line 398 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITXOR"), LINE, n_bitxor, (yyvsp[-1].e), NUMBER); }
#line 4114 "parser.c"
    break;

  case 277:
#line 399 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("NOT"), LINE, n_not, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4120 "parser.c"
    break;

  case 278:
#line 400 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("IN"), LINE, n_in, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4126 "parser.c"
    break;

  case 279:
#line 401 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("OR"), LINE, n_or, (yyvsp[-1].e), NUMBER); }
#line 4132 "parser.c"
    break;

  case 280:
#line 402 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("shiftleft"), LINE, n_shiftleft, (yyvsp[-1].e), NUMBER); }
#line 4138 "parser.c"
    break;

  case 281:
#line 403 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("shiftright"), LINE, n_shiftright, (yyvsp[-1].e), NUMBER); }
#line 4144 "parser.c"
    break;

  case 282:
#line 404 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("XOR"), LINE, n_xor, (yyvsp[-1].e), NUMBER); }
#line 4150 "parser.c"
    break;

  case 283:
#line 408 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("closemedia"), LINE, n_closemedia, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4156 "parser.c"
    break;

  case 284:
#line 409 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("effect"), LINE, n_effect, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4162 "parser.c"
    break;

  case 285:
#line 410 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("setmedia"), LINE, n_setmedia, (yyvsp[-1].e), NUMBER); }
#line 4168 "parser.c"
    break;

  case 286:
#line 411 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("setmedia"), LINE, n_setmedia, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4174 "parser.c"
    break;

  case 287:
#line 412 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("showmedia"), LINE, n_showmedia, merge(merge((yyvsp[-3].e), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4180 "parser.c"
    break;

  case 288:
#line 416 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("database"), LINE, n_database, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4186 "parser.c"
    break;

  case 289:
#line 417 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("database"), LINE, n_database, (yyvsp[-1].e), STRING); }
#line 4192 "parser.c"
    break;

  case 290:
#line 418 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("earlier"), LINE, n_earlier, (yyvsp[-1].e), NUMBER); }
#line 4198 "parser.c"
    break;

  case 291:
#line 419 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getassign"), LINE, n_getassign, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4204 "parser.c"
    break;

  case 292:
#line 420 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getassign"), LINE, n_getassign, (yyvsp[-1].e), STRING); }
#line 4210 "parser.c"
    break;

  case 293:
#line 421 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getdevice"), LINE, n_getdevice, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4216 "parser.c"
    break;

  case 294:
#line 422 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getdiskspace"), LINE, n_getdiskspace, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4222 "parser.c"
    break;

  case 295:
#line 423 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getdiskspace"), LINE, n_getdiskspace, (yyvsp[-1].e), NUMBER); }
#line 4228 "parser.c"
    break;

  case 296:
#line 424 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getenv"), LINE, n_getenv, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4234 "parser.c"
    break;

  case 297:
#line 425 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getsize"), LINE, n_getsize, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4240 "parser.c"
    break;

  case 298:
#line 426 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getsum"), LINE, n_getsum, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4246 "parser.c"
    break;

  case 299:
#line 427 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getversion"), LINE, n_getversion, NULL, NUMBER); }
#line 4252 "parser.c"
    break;

  case 300:
#line 428 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getversion"), LINE, n_getversion, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4258 "parser.c"
    break;

  case 301:
#line 429 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getversion"), LINE, n_getversion, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4264 "parser.c"
    break;

  case 302:
#line 430 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("iconinfo"), LINE, n_iconinfo, (yyvsp[-1].e), NUMBER); }
#line 4270 "parser.c"
    break;

  case 303:
#line 431 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("querydisplay"), LINE, n_querydisplay, (yyvsp[-1].e), NUMBER); }
#line 4276 "parser.c"
    break;

  case 304:
#line 435 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, n_procedure, push(new_contxt(), new_custom((yyvsp[-3].s), LINE, (yyvsp[-2].e), (yyvsp[-1].e))), NUMBER); }
#line 4282 "parser.c"
    break;

  case 305:
#line 436 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, n_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, (yyvsp[-1].e), NULL)), NUMBER); }
#line 4288 "parser.c"
    break;

  case 306:
#line 437 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, n_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, NULL, (yyvsp[-1].e))), NUMBER); }
#line 4294 "parser.c"
    break;

  case 307:
#line 438 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, n_procedure, push(new_contxt(), new_custom((yyvsp[-1].s), LINE, NULL, NULL)), NUMBER); }
#line 4300 "parser.c"
    break;

  case 308:
#line 439 "../src/parser.y"
                                                 { (yyval.e) = new_cusref((yyvsp[-2].s), LINE, (yyvsp[-1].e)); }
#line 4306 "parser.c"
    break;

  case 309:
#line 440 "../src/parser.y"
                                                 { (yyval.e) = new_cusref((yyvsp[-1].s), LINE, NULL); }
#line 4312 "parser.c"
    break;

  case 310:
#line 444 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askbool"), LINE, n_askbool, NULL, NUMBER); }
#line 4318 "parser.c"
    break;

  case 311:
#line 445 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askbool"), LINE, n_askbool, (yyvsp[-1].e), NUMBER); }
#line 4324 "parser.c"
    break;

  case 312:
#line 446 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askchoice"), LINE, n_askchoice, (yyvsp[-1].e), NUMBER); }
#line 4330 "parser.c"
    break;

  case 313:
#line 447 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askdir"), LINE, n_askdir, NULL, STRING); }
#line 4336 "parser.c"
    break;

  case 314:
#line 448 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askdir"), LINE, n_askdir, (yyvsp[-1].e), STRING); }
#line 4342 "parser.c"
    break;

  case 315:
#line 449 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askdisk"), LINE, n_askdisk, (yyvsp[-1].e), NUMBER); }
#line 4348 "parser.c"
    break;

  case 316:
#line 450 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askfile"), LINE, n_askfile, NULL, STRING); }
#line 4354 "parser.c"
    break;

  case 317:
#line 451 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askfile"), LINE, n_askfile, (yyvsp[-1].e), STRING); }
#line 4360 "parser.c"
    break;

  case 318:
#line 452 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("asknumber"), LINE, n_asknumber, NULL, NUMBER); }
#line 4366 "parser.c"
    break;

  case 319:
#line 453 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("asknumber"), LINE, n_asknumber, (yyvsp[-1].e), NUMBER); }
#line 4372 "parser.c"
    break;

  case 320:
#line 454 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askoptions"), LINE, n_askoptions, (yyvsp[-1].e), NUMBER); }
#line 4378 "parser.c"
    break;

  case 321:
#line 455 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askstring"), LINE, n_askstring, NULL, STRING); }
#line 4384 "parser.c"
    break;

  case 322:
#line 456 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askstring"), LINE, n_askstring, (yyvsp[-1].e), STRING); }
#line 4390 "parser.c"
    break;

  case 323:
#line 460 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("cat"), LINE, n_cat, (yyvsp[-1].e), STRING); }
#line 4396 "parser.c"
    break;

  case 324:
#line 461 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("expandpath"), LINE, n_expandpath, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4402 "parser.c"
    break;

  case 325:
#line 462 "../src/parser.y"
                                                 { (yyval.e) = new_native((yyvsp[-2].s), LINE, n_fmt, (yyvsp[-1].e), STRING); }
#line 4408 "parser.c"
    break;

  case 326:
#line 463 "../src/parser.y"
                                                 { (yyval.e) = new_native((yyvsp[-1].s), LINE, n_fmt, NULL, STRING); }
#line 4414 "parser.c"
    break;

  case 327:
#line 464 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("pathonly"), LINE, n_pathonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4420 "parser.c"
    break;

  case 328:
#line 465 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("patmatch"), LINE, n_patmatch, (yyvsp[-1].e), NUMBER); }
#line 4426 "parser.c"
    break;

  case 329:
#line 466 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("strlen"), LINE, n_strlen, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4432 "parser.c"
    break;

  case 330:
#line 467 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("substr"), LINE, n_substr, (yyvsp[-1].e), STRING); }
#line 4438 "parser.c"
    break;

  case 331:
#line 468 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("substr"), LINE, n_substr, push((yyvsp[-2].e), (yyvsp[-1].e)), STRING); }
#line 4444 "parser.c"
    break;

  case 332:
#line 469 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("tackon"), LINE, n_tackon, (yyvsp[-1].e), STRING); }
#line 4450 "parser.c"
    break;

  case 333:
#line 473 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("set"), LINE, n_set, (yyvsp[-1].e), DANGLE); }
#line 4456 "parser.c"
    break;

  case 334:
#line 474 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("symbolset"), LINE, n_symbolset, (yyvsp[-1].e), DANGLE); }
#line 4462 "parser.c"
    break;

  case 335:
#line 475 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("symbolval"), LINE, n_symbolval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4468 "parser.c"
    break;

  case 336:
#line 479 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, n_openwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4474 "parser.c"
    break;

  case 337:
#line 480 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, n_openwbobject, merge(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4480 "parser.c"
    break;

  case 338:
#line 481 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, n_openwbobject, merge(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4486 "parser.c"
    break;

  case 339:
#line 482 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, n_openwbobject, merge(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4492 "parser.c"
    break;

  case 340:
#line 483 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("showwbobject"), LINE, n_showwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4498 "parser.c"
    break;

  case 341:
#line 484 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("closewbobject"), LINE, n_closewbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4504 "parser.c"
    break;

  case 342:
#line 488 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("all"), OPT_ALL, NULL); }
#line 4510 "parser.c"
    break;

  case 343:
#line 489 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("append"), OPT_APPEND, (yyvsp[-1].e)); }
#line 4516 "parser.c"
    break;

  case 344:
#line 490 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); }
#line 4522 "parser.c"
    break;

  case 345:
#line 491 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("back"), OPT_BACK, (yyvsp[-1].e)); }
#line 4528 "parser.c"
    break;

  case 346:
#line 492 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("choices"), OPT_CHOICES, (yyvsp[-1].e)); }
#line 4534 "parser.c"
    break;

  case 347:
#line 493 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("command"), OPT_COMMAND, (yyvsp[-1].e)); }
#line 4540 "parser.c"
    break;

  case 348:
#line 494 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("compression"), OPT_COMPRESSION, NULL); }
#line 4546 "parser.c"
    break;

  case 349:
#line 495 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, (yyvsp[-1].e)); }
#line 4552 "parser.c"
    break;

  case 350:
#line 496 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, NULL); }
#line 4558 "parser.c"
    break;

  case 351:
#line 497 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), (yyvsp[-1].e))); }
#line 4564 "parser.c"
    break;

  case 352:
#line 498 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, (yyvsp[-1].e)); }
#line 4570 "parser.c"
    break;

  case 353:
#line 499 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4576 "parser.c"
    break;

  case 354:
#line 500 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), (yyvsp[-1].e))); }
#line 4582 "parser.c"
    break;

  case 355:
#line 501 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("disk"), OPT_DISK, NULL); }
#line 4588 "parser.c"
    break;

  case 356:
#line 502 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("files"), OPT_FILES, NULL); }
#line 4594 "parser.c"
    break;

  case 357:
#line 503 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("fonts"), OPT_FONTS, NULL); }
#line 4600 "parser.c"
    break;

  case 358:
#line 504 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4606 "parser.c"
    break;

  case 359:
#line 505 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("getposition"), OPT_GETPOSITION, (yyvsp[-1].e)); }
#line 4612 "parser.c"
    break;

  case 360:
#line 506 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4618 "parser.c"
    break;

  case 361:
#line 507 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, (yyvsp[-1].e)); }
#line 4624 "parser.c"
    break;

  case 362:
#line 508 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("help"), OPT_HELP, (yyvsp[-1].e)); }
#line 4630 "parser.c"
    break;

  case 363:
#line 509 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("help"), OPT_HELP, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4636 "parser.c"
    break;

  case 364:
#line 510 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("infos"), OPT_INFOS, NULL); }
#line 4642 "parser.c"
    break;

  case 365:
#line 511 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4648 "parser.c"
    break;

  case 366:
#line 512 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), (yyvsp[-1].e))); }
#line 4654 "parser.c"
    break;

  case 367:
#line 513 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("newpath"), OPT_NEWPATH, NULL); }
#line 4660 "parser.c"
    break;

  case 368:
#line 514 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("newpath"), OPT_NEWPATH, push(new_contxt(), (yyvsp[-1].e))); }
#line 4666 "parser.c"
    break;

  case 369:
#line 515 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); }
#line 4672 "parser.c"
    break;

  case 370:
#line 516 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); }
#line 4678 "parser.c"
    break;

  case 371:
#line 517 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("noreq"), OPT_NOREQ, NULL); }
#line 4684 "parser.c"
    break;

  case 372:
#line 518 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), (yyvsp[-1].e))); }
#line 4690 "parser.c"
    break;

  case 373:
#line 519 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("prompt"), OPT_PROMPT, (yyvsp[-1].e)); }
#line 4696 "parser.c"
    break;

  case 374:
#line 520 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("quiet"), OPT_QUIET, NULL); }
#line 4702 "parser.c"
    break;

  case 375:
#line 521 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("range"), OPT_RANGE, (yyvsp[-1].e)); }
#line 4708 "parser.c"
    break;

  case 376:
#line 522 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("safe"), OPT_SAFE, NULL); }
#line 4714 "parser.c"
    break;

  case 377:
#line 523 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4720 "parser.c"
    break;

  case 378:
#line 524 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("setposition"), OPT_SETPOSITION, (yyvsp[-1].e)); }
#line 4726 "parser.c"
    break;

  case 379:
#line 525 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4732 "parser.c"
    break;

  case 380:
#line 526 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, (yyvsp[-1].e)); }
#line 4738 "parser.c"
    break;

  case 381:
#line 527 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4744 "parser.c"
    break;

  case 382:
#line 528 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4750 "parser.c"
    break;

  case 383:
#line 529 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4756 "parser.c"
    break;

  case 384:
#line 530 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); }
#line 4762 "parser.c"
    break;

  case 385:
#line 531 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, (yyvsp[-1].e)); }
#line 4768 "parser.c"
    break;

  case 386:
#line 532 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4774 "parser.c"
    break;

  case 387:
#line 533 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("resident"), OPT_RESIDENT, NULL); }
#line 4780 "parser.c"
    break;

  case 388:
#line 534 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4786 "parser.c"
    break;

  case 389:
#line 535 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4792 "parser.c"
    break;

  case 390:
#line 536 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(push(new_contxt(), (yyvsp[-3].e)), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4798 "parser.c"
    break;


#line 4802 "parser.c"

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
#line 538 "../src/parser.y"

