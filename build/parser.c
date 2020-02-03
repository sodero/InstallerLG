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
    EXECUTE = 279,
    REXX = 280,
    RUN = 281,
    ABORT = 282,
    EXIT = 283,
    ONERROR = 284,
    TRAP = 285,
    REBOOT = 286,
    COPYFILES = 287,
    COPYLIB = 288,
    DELETE = 289,
    EXISTS = 290,
    FILEONLY = 291,
    FOREACH = 292,
    MAKEASSIGN = 293,
    MAKEDIR = 294,
    PROTECT = 295,
    STARTUP = 296,
    TEXTFILE = 297,
    TOOLTYPE = 298,
    TRANSCRIPT = 299,
    RENAME = 300,
    COMPLETE = 301,
    DEBUG = 302,
    MESSAGE = 303,
    USER = 304,
    WELCOME = 305,
    WORKING = 306,
    AND = 307,
    BITAND = 308,
    BITNOT = 309,
    BITOR = 310,
    BITXOR = 311,
    NOT = 312,
    IN = 313,
    OR = 314,
    SHIFTLEFT = 315,
    SHIFTRIGHT = 316,
    XOR = 317,
    CLOSEMEDIA = 318,
    EFFECT = 319,
    SETMEDIA = 320,
    SHOWMEDIA = 321,
    DATABASE = 322,
    EARLIER = 323,
    GETASSIGN = 324,
    GETDEVICE = 325,
    GETDISKSPACE = 326,
    GETENV = 327,
    GETSIZE = 328,
    GETSUM = 329,
    GETVERSION = 330,
    ICONINFO = 331,
    QUERYDISPLAY = 332,
    CUS = 333,
    DCL = 334,
    ASKBOOL = 335,
    ASKCHOICE = 336,
    ASKDIR = 337,
    ASKDISK = 338,
    ASKFILE = 339,
    ASKNUMBER = 340,
    ASKOPTIONS = 341,
    ASKSTRING = 342,
    CAT = 343,
    EXPANDPATH = 344,
    FMT = 345,
    PATHONLY = 346,
    PATMATCH = 347,
    STRLEN = 348,
    SUBSTR = 349,
    TACKON = 350,
    SET = 351,
    SYMBOLSET = 352,
    SYMBOLVAL = 353,
    OPENWBOBJECT = 354,
    SHOWWBOBJECT = 355,
    CLOSEWBOBJECT = 356,
    ALL = 357,
    APPEND = 358,
    ASSIGNS = 359,
    BACK = 360,
    CHOICES = 361,
    COMMAND = 362,
    COMPRESSION = 363,
    CONFIRM = 364,
    DEFAULT = 365,
    DELOPTS = 366,
    DEST = 367,
    DISK = 368,
    FILES = 369,
    FONTS = 370,
    GETDEFAULTTOOL = 371,
    GETPOSITION = 372,
    GETSTACK = 373,
    GETTOOLTYPE = 374,
    HELP = 375,
    INFOS = 376,
    INCLUDE = 377,
    NEWNAME = 378,
    NEWPATH = 379,
    NOGAUGE = 380,
    NOPOSITION = 381,
    NOREQ = 382,
    PATTERN = 383,
    PROMPT = 384,
    QUIET = 385,
    RANGE = 386,
    SAFE = 387,
    SETDEFAULTTOOL = 388,
    SETPOSITION = 389,
    SETSTACK = 390,
    SETTOOLTYPE = 391,
    SOURCE = 392,
    SWAPCOLORS = 393,
    OPTIONAL = 394,
    RESIDENT = 395,
    OVERRIDE = 396
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
#define YYFINAL  287
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  151
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  157
/* YYNRULES -- Number of rules.  */
#define YYNRULES  375
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  727

#define YYUNDEFTOK  2
#define YYMAXUTOK   396


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
     142,   143,   146,   144,     2,   147,     2,   145,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     150,   148,   149,     2,     2,     2,     2,     2,     2,     2,
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
     135,   136,   137,   138,   139,   140,   141
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
     264,   265,   266,   267,   268,   269,   273,   274,   275,   276,
     280,   281,   282,   283,   284,   285,   289,   290,   291,   292,
     293,   294,   295,   296,   300,   301,   302,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   321,
     322,   323,   324,   325,   326,   327,   329,   330,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   397,   398,   399,   400,   401,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   424,   425,   426,   427,   428,   429,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   462,   463,   464,   468,   469,   470,   471,   472,
     473,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SYM", "STR", "OOM", "INT", "HEX", "BIN",
  "EQ", "GT", "GTE", "LT", "LTE", "NEQ", "IF", "SELECT", "UNTIL", "WHILE",
  "TRACE", "RETRACE", "ASTRAW", "ASBRAW", "ASBEVAL", "EXECUTE", "REXX",
  "RUN", "ABORT", "EXIT", "ONERROR", "TRAP", "REBOOT", "COPYFILES",
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
  "asbeval", "execute", "rexx", "run", "abort", "exit", "onerror",
  "reboot", "trap", "copyfiles", "copylib", "delete", "exists", "fileonly",
  "foreach", "makeassign", "makedir", "protect", "startup", "textfile",
  "tooltype", "transcript", "rename", "complete", "debug", "message",
  "user", "welcome", "working", "and", "bitand", "bitnot", "bitor",
  "bitxor", "not", "in", "or", "shiftleft", "shiftright", "xor",
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
     395,   396,    40,    41,    43,    47,    42,    45,    61,    62,
      60
};
# endif

#define YYPACT_NINF (-515)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -127,  1177,    51,  -515,  -515,  -127,  -127,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,    14,   223,   203,
     203,   203,   203,   203,   203,   203,   -81,   -74,   -67,   203,
     203,   477,   477,   477,   203,   238,  -127,   203,   -47,   -26,
     -26,   477,   203,   203,   203,   203,   477,   203,   477,   -26,
     -26,   203,   203,   203,   246,   477,   203,   254,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   260,   -26,   203,   124,  -140,   -26,  -132,   -26,
    -119,  -111,   -26,  -109,   203,   203,   203,   203,   203,   203,
     203,   148,   203,   203,   477,   203,   203,    12,   203,    17,
    -127,   203,   203,    32,   266,   203,   203,   203,    34,    41,
      44,   203,   203,   203,   203,   299,    50,   203,   203,    69,
      71,    81,    92,   203,   203,    94,   203,    96,   203,   203,
     203,   203,   203,   141,   203,   144,   203,   203,   203,   203,
     203,   203,   203,   203,   153,  -107,  -105,  -515,  -127,  -127,
    -127,  -127,  -515,  -515,  -515,  -515,  -515,  -515,  1769,  -515,
    -515,   371,  -515,  -515,  -515,   419,   203,   155,   168,   170,
     440,   177,   180,   625,  -127,  -127,  -515,  -515,  -515,   184,
     186,  1325,   446,   477,   454,   477,   465,   477,   471,  1473,
    -515,   568,   619,  -101,  -127,  -515,  2131,   -99,   -95,   -87,
     477,   -85,   192,  -127,   701,   -83,   -79,   477,   769,   -77,
     -26,   777,   -75,   -68,   801,   -63,   199,  -515,   817,   851,
     477,   201,  -515,   872,   878,   884,   204,   213,   221,   226,
     242,   203,   921,   249,   251,   257,   261,   203,   931,   203,
     964,   264,   267,   970,   268,   269,   982,   270,   271,   273,
     274,  -515,   -61,   -59,   275,    11,  -515,   -57,   -55,  -515,
     -52,   -50,  -515,   -44,  -515,   -42,   -38,  -515,   -34,  1005,
     276,   277,   286,   287,  1025,   288,   203,     5,  -515,  1031,
     289,   -28,   477,   290,   292,  -515,  1042,  -515,   -12,  1581,
    1587,  -515,  -515,   293,   294,  1593,   295,  -515,  -515,  -515,
     296,   312,   313,   320,  -515,  1601,  -515,   321,   322,  -515,
    -515,  -515,  -515,   323,  1734,  -515,   343,  -515,   345,   346,
     348,  1742,   349,   350,  -515,  1751,  -515,   352,  1883,   353,
    1892,   356,   358,   359,   360,  -515,  -515,  -515,   203,   153,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  1177,  -515,  -515,
     -10,   625,  -515,  -515,  1917,  -515,  1898,    -7,    -5,  -515,
    -515,    -2,  -515,     3,  2016,   -26,  -515,    16,  2024,  -515,
      25,  2039,  -515,  -515,   362,  -515,  2045,  -515,    53,   203,
    -515,  -515,  -515,    90,   105,  -118,  -515,   363,   364,  -515,
     113,  1621,  -515,   366,    83,  -515,   367,  -515,   133,   135,
    -515,   138,  -515,   140,   150,  -515,   152,  -515,  -515,  -515,
    -515,   158,  -515,  -515,  -515,   166,  2065,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  2071,  -515,  -515,  -515,
    -515,  -515,   369,  -515,   372,   203,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,   376,  -515,   374,
    -515,  -515,  -515,  -515,   377,    22,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
     378,  -515,  -515,   203,  -515,  -515,   203,  -515,  -515,   174,
     176,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  2077,  2083,  -515,   189,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,   195,  -515,  -515,
     198,  -515,  -515,   209,  -515,  -515,  -515,   -26,  -515,  -515,
     225,  -515,  -515,  -515,  -515,  -515,  -515,  -515,   229,  -515,
    -515,  -515,  -515,   241,  -515,  -515,  -515,   248,  -515,  -515,
    -515,  2089,  -515,  -515,  -515,  -515,   379,  -515,  -515,  -515,
    -515,  -515,   256,  -515,   380,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     2,    16,     3,     0,    19,    11,    79,
      80,    81,    82,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   116,   115,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   153,   152,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    58,    57,    59,    60,    61,
      62,    63,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    64,    78,    65,    77,     0,     0,     0,
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
       0,     0,     0,     0,    16,     0,     0,     1,    13,    14,
      15,    18,    30,    29,    31,    26,    27,    28,     0,   298,
       8,     0,     4,     5,   315,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,   193,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     214,     0,     0,     0,     0,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   288,     0,     0,     0,     0,   299,     0,     0,   302,
       0,     0,   305,     0,   307,     0,     0,   310,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,   331,     0,   333,     0,     0,
       0,   337,   339,     0,     0,     0,     0,   343,   344,   345,
       0,     0,     0,     0,   351,     0,   352,     0,     0,   355,
     356,   357,   358,     0,     0,   361,     0,   363,     0,     0,
       0,     0,     0,     0,   370,     0,   372,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    17,    20,     0,     0,
     297,     7,   314,     6,   182,   184,   185,     0,   188,    23,
       0,    36,   187,   186,     0,    24,     0,     0,     0,   195,
     196,     0,   200,     0,     0,    18,   204,     0,     0,   208,
       0,     0,   209,   213,     0,   212,     0,   215,     0,     0,
     218,   219,   223,     0,     0,     0,   224,     0,     0,   227,
       0,     0,   232,     0,     0,   230,     0,   236,     0,     0,
     240,     0,   238,     0,     0,   244,     0,   245,   246,   247,
     249,     0,   250,   251,   256,     0,     0,   257,   258,   260,
     261,   262,   263,   264,   265,   266,     0,   268,   269,   270,
     271,   272,     0,   274,     0,     0,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,     0,   289,     0,
     291,   292,    35,   296,     0,     0,   300,   301,   303,   304,
     306,   308,   309,   311,   312,   313,   316,   317,   318,   319,
       0,   321,    33,     0,   322,   323,     0,   324,   325,     0,
       0,   329,   330,   332,   334,   335,   336,   338,   340,   341,
     342,   346,   347,   348,   349,   350,   353,   354,   359,   360,
     362,   364,   365,   366,   368,   367,   369,   371,   373,   176,
     177,   178,   179,   180,   181,   183,     0,     0,   374,     0,
      37,   189,    25,   190,   191,   197,   198,     0,   201,   202,
       0,   205,   206,     0,   210,   211,   217,     0,   220,   221,
       0,   225,   226,   228,   231,   229,   233,   234,     0,   239,
     237,   241,   242,     0,   248,   253,   254,     0,   267,   273,
     275,     0,   290,   295,    34,   294,     0,   320,    32,     9,
     326,   327,     0,    21,     0,   375,   199,   203,   207,   222,
     235,   243,   255,   276,   293,   328,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -515,  -515,  -391,   488,   -80,  -135,  -515,    72,    39,     0,
    -297,  -515,  -514,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,   178,  -515,  -515,  -158,  -515,  -163,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,   136,  -515,  -515
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   300,   307,   301,   419,   302,   288,   505,
     491,   496,   303,   417,   595,   311,   312,     7,     8,     9,
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
     140,   141,   142,   143,   144,   145,   146
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,   286,   336,   396,   594,   289,   291,   332,   613,   262,
     336,   399,   265,   305,   592,     1,   495,   292,   293,   294,
     295,   296,   297,   336,   402,   704,   322,   324,   326,   328,
     331,   336,   404,   336,   407,     1,   476,     1,   477,     5,
     285,     1,   517,   336,   520,   290,   354,   336,   521,   358,
     359,   287,   363,   364,   365,   336,   522,   525,   526,   534,
     535,   372,   316,   336,   537,   336,   542,   336,   547,   317,
     308,   309,     4,   284,   336,   548,   318,     4,     4,   336,
     550,   587,   588,   336,   590,   336,   596,   336,   597,   409,
     336,   598,   336,   599,   343,   345,   335,   349,   336,   600,
     336,   601,   355,   426,   336,   602,   429,   430,   336,   603,
     366,   435,   368,   369,   336,   618,   336,   373,   374,   375,
     445,   377,   378,   379,   381,   382,   384,   395,   387,   454,
       1,   624,   336,   658,   394,     1,   663,     1,   664,   465,
     336,   477,   468,   714,   470,   336,   665,   412,   614,   414,
     415,   416,   418,     1,   593,   425,   298,   299,   336,   668,
     427,   323,   325,   327,     1,   705,     6,   336,   671,   337,
     338,   340,   441,   514,   443,   431,   347,   437,   351,   352,
     353,   533,   536,   528,   438,   360,   456,   439,   504,   459,
     508,   462,   511,   446,   660,     1,   676,   516,   469,   662,
     471,   472,   473,   474,   706,   333,   292,   293,   294,   295,
     296,   297,   449,   393,   450,   267,   397,   398,   400,   401,
     403,   405,   406,   408,   451,   556,   292,   293,   294,   295,
     296,   297,   336,   678,   422,   452,   566,   455,     4,   457,
       6,   292,   293,   294,   295,   296,   297,   336,   679,   292,
     293,   294,   295,   296,   297,     1,   683,   292,   293,   294,
     295,   296,   297,   292,   293,   294,   295,   296,   297,   292,
     293,   294,   295,   296,   297,   336,   686,   336,   687,   428,
     336,   689,   336,   690,   464,   289,   291,   466,   289,   291,
     289,   291,   336,   691,   336,   692,   475,   572,   484,   575,
     336,   694,   292,   293,   294,   295,   296,   297,   336,   695,
     490,   485,     4,   486,     6,     6,   336,   710,   336,   711,
     492,   501,   503,   493,   507,   290,   510,   499,   290,   500,
     290,   336,   715,   289,     6,   529,   501,   336,   716,   523,
     336,   717,   552,     6,   557,   298,   538,   561,   541,   543,
     544,   336,   718,   497,   498,   551,   562,     4,     4,   555,
       4,     4,     4,     4,   563,   298,   304,   336,   719,   564,
     479,   336,   720,   518,   292,   293,   294,   295,   296,   297,
     329,   330,   530,   336,   721,   565,     4,     4,   298,   357,
     336,   722,   568,   479,   569,     6,   298,   362,   336,   725,
     570,   479,   298,   391,   571,     4,     4,   577,   298,   432,
     578,   580,   581,   583,   584,     4,   585,   586,   591,   605,
     606,   619,   292,   293,   294,   295,   296,   297,   289,   607,
     608,   611,   617,   621,     5,   622,   627,   628,   630,   631,
     701,   298,   444,   292,   293,   294,   295,   296,   297,   292,
     293,   294,   295,   296,   297,   632,   633,   292,   293,   294,
     295,   296,   297,   634,   636,   637,   638,     4,   292,   293,
     294,   295,   296,   297,   292,   293,   294,   295,   296,   297,
     292,   293,   294,   295,   296,   297,   640,   286,   641,   642,
     659,   643,   645,   646,     6,   648,   650,   289,   289,   652,
       4,   653,   654,   655,   667,   674,   681,   682,   670,   684,
     685,   673,   699,   298,   480,   700,   275,   702,   289,   527,
     703,   707,   724,   726,   680,     0,   657,     0,   589,     0,
     289,     0,     0,   657,     0,     0,     0,     0,     0,   688,
       0,     0,     0,     0,     0,     0,   693,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   697,     0,     0,   284,
       0,   298,   482,     0,     0,     0,   284,     0,     0,     4,
       4,   292,   293,   294,   295,   296,   297,     0,     0,     0,
       0,     0,   487,   488,     0,     0,     0,     0,   321,   502,
       4,     0,     0,     0,     0,     6,   321,   506,     0,     0,
       0,     0,     4,   479,     0,     0,     0,   321,   509,     0,
       0,     0,     0,   298,   512,     0,     0,     0,     0,   321,
     712,     0,   292,   293,   294,   295,   296,   297,   292,   293,
     294,   295,   296,   297,     5,     0,     0,   306,   306,   306,
     310,   313,   314,   315,     0,     0,     0,   319,   320,     0,
       0,     0,     0,     0,     0,   334,     0,   289,     0,   339,
     341,   342,   306,   344,   346,   348,   350,     4,     0,     0,
     306,   356,     0,     0,   361,     0,     0,   490,   306,   367,
     306,   306,   370,   371,     0,   306,   306,   306,   376,   306,
     306,   306,   380,   306,   383,   385,   386,   388,   389,   390,
     392,     0,   306,     0,   292,   293,   294,   295,   296,   297,
     329,   513,     0,   410,   411,   306,   413,   306,   306,     0,
     306,   420,   421,   423,   424,     0,     0,     0,     0,     4,
       0,     0,   433,   434,     0,   436,     0,     0,     0,   440,
     306,   442,   306,     0,     0,   447,   448,     0,     0,     0,
       0,   453,     0,     0,   306,     0,   458,   306,   460,   461,
     463,   298,   515,     0,   467,     0,   306,   494,   306,   306,
     306,   306,   292,   293,   294,   295,   296,   297,     0,     0,
     292,   293,   294,   295,   296,   297,     0,     0,     0,   481,
       0,     0,     0,   481,   483,     0,     0,     0,   489,     0,
       0,   489,     0,     0,   292,   293,   294,   295,   296,   297,
     481,     0,   481,     0,   481,     0,   481,     0,     0,   481,
     292,   293,   294,   295,   296,   297,     0,     0,   524,     0,
       0,     0,   483,     0,     0,   539,   483,     0,     0,   546,
       0,     0,   481,   531,   532,     0,   481,   481,     0,     0,
       0,   481,   481,   481,   292,   293,   294,   295,   296,   297,
     481,     0,     0,     0,     0,   306,   574,   306,   483,     0,
       0,   483,     0,     0,   483,   292,   293,   294,   295,   296,
     297,   292,   293,   294,   295,   296,   297,   292,   293,   294,
     295,   296,   297,     0,     0,     0,     0,   481,     0,     0,
       0,     0,   610,     0,   612,     0,     0,   616,     0,     0,
     620,   321,   540,     0,   481,     0,     0,   481,   481,   321,
     545,     0,     0,   481,   292,   293,   294,   295,   296,   297,
       0,     0,     0,   481,   292,   293,   294,   295,   296,   297,
       0,     0,   481,   298,   549,     0,     0,     0,     0,   483,
       0,     0,     0,   481,     0,     0,   481,     0,   481,   298,
     553,     0,     0,     0,     0,     0,   656,   292,   293,   294,
     295,   296,   297,   292,   293,   294,   295,   296,   297,   489,
       0,     0,     0,     0,   489,   292,   293,   294,   295,   296,
     297,     0,   481,   321,   554,     0,   481,     0,     0,   481,
       0,     0,     0,     0,   481,     0,     0,   677,   292,   293,
     294,   295,   296,   297,   298,   558,     0,     0,     0,     0,
     298,   559,     0,     0,     0,     0,   298,   560,   292,   293,
     294,   295,   296,   297,   292,   293,   294,   295,   296,   297,
       0,     0,     0,     0,   481,   292,   293,   294,   295,   296,
     297,     0,     0,     0,   481,     0,     0,     0,     0,     0,
       0,     0,     0,   298,   567,     0,     0,     0,     0,     0,
       0,     0,     0,   298,   573,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   708,     0,     0,   709,     0,   298,   576,     0,     0,
       0,     0,   298,   579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   298,   582,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   489,     0,     0,   298,   604,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   298,   609,     0,
       0,     0,     0,   298,   615,     0,     0,     0,     0,     0,
     147,   148,     0,     0,   298,   623,     0,     0,   149,   481,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,     0,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,     0,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,     1,
       0,   277,   278,   279,   280,   281,   282,   283,   147,   148,
       0,     0,     0,     0,     0,     0,   149,     0,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,     0,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,     0,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   321,     0,   277,
     278,   279,   280,   281,   282,   283,   147,   148,     0,     0,
       0,     0,     0,     0,   149,     0,   150,   151,   478,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,     0,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,     0,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   292,   293,   294,   295,   296,   297,
     292,   293,   294,   295,   296,   297,   292,   293,   294,   295,
     296,   297,     0,   265,   292,   293,   294,   295,   296,   297,
       0,     0,     0,     0,     0,   298,     0,   277,   278,   279,
     280,   281,   282,   283,   147,   148,     0,     0,     0,     0,
       0,     0,   149,     0,   150,   151,   478,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,     0,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,     0,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   298,   625,     0,     0,     0,     0,   298,
     626,     0,     0,     0,     0,   298,   629,   292,   293,   294,
     295,   296,   297,   298,   635,   292,   293,   294,   295,   296,
     297,     0,     0,   267,   292,   293,   294,   295,   296,   297,
       0,     0,     0,   298,     0,   277,   278,   279,   280,   281,
     282,   283,   147,   148,     0,     0,     0,     0,     0,     0,
     149,     0,   150,   151,   478,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,     0,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,     0,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     0,     0,     0,     0,     0,   298,   639,     0,     0,
       0,     0,     0,     0,   298,   644,   292,   293,   294,   295,
     296,   297,     0,   298,   647,   292,   293,   294,   295,   296,
     297,   292,   293,   294,   295,   296,   297,     0,     0,     0,
       0,   298,     0,   277,   278,   279,   280,   281,   282,   283,
     147,   148,     0,     0,     0,     0,     0,     0,   149,     0,
     150,   151,   478,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,     0,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,     0,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   292,
     293,   294,   295,   296,   297,   298,   649,   292,   293,   294,
     295,   296,   297,     0,   298,   651,     0,     0,     0,     0,
     494,   661,   292,   293,   294,   295,   296,   297,   292,   293,
     294,   295,   296,   297,     0,     0,     0,     0,     0,     1,
       0,   277,   278,   279,   280,   281,   282,   283,   292,   293,
     294,   295,   296,   297,   292,   293,   294,   295,   296,   297,
     292,   293,   294,   295,   296,   297,   292,   293,   294,   295,
     296,   297,   292,   293,   294,   295,   296,   297,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   519,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   321,   666,
       0,     0,     0,     0,     0,     0,   321,   669,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   321,   672,     0,     0,     0,     0,   298,   675,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   321,   696,     0,
       0,     0,     0,   298,   698,     0,     0,     0,     0,   494,
     488,     0,     0,     0,     0,     1,   713,     0,     0,     0,
       0,   298,   723,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   336
};

static const yytype_int16 yycheck[] =
{
       0,     1,   142,   143,   395,     5,     6,   165,     3,   127,
     142,   143,   130,   148,     3,   142,   313,     3,     4,     5,
       6,     7,     8,   142,   143,     3,   161,   162,   163,   164,
     165,   142,   143,   142,   143,   142,   143,   142,   143,     0,
       1,   142,   143,   142,   143,     6,   181,   142,   143,   184,
     185,     0,   187,   188,   189,   142,   143,   142,   143,   142,
     143,   196,   143,   142,   143,   142,   143,   142,   143,   143,
     150,   151,     0,     1,   142,   143,   143,     5,     6,   142,
     143,   142,   143,   142,   143,   142,   143,   142,   143,   224,
     142,   143,   142,   143,   174,   175,   143,   177,   142,   143,
     142,   143,   182,   238,   142,   143,   241,   242,   142,   143,
     190,   246,   192,   193,   142,   143,   142,   197,   198,   199,
     255,   201,   202,   203,   204,   205,   206,     3,   208,   264,
     142,   143,   142,   143,   214,   142,   143,   142,   143,   274,
     142,   143,   277,   657,   279,   142,   143,   227,   143,   229,
     230,     3,   232,   142,   143,   143,   142,   143,   142,   143,
     143,   161,   162,   163,   142,   143,   166,   142,   143,   169,
     170,   171,   252,   331,   254,   143,   176,   143,   178,   179,
     180,   344,   345,   341,   143,   185,   266,   143,   323,   269,
     325,   271,   327,   143,   491,   142,   143,   332,   278,   496,
     280,   281,   282,   283,   595,   166,     3,     4,     5,     6,
       7,     8,   143,   213,   143,   132,   216,   217,   218,   219,
     220,   221,   222,   223,   143,   360,     3,     4,     5,     6,
       7,     8,   142,   143,   234,   143,   371,   143,   166,   143,
     240,     3,     4,     5,     6,     7,     8,   142,   143,     3,
       4,     5,     6,     7,     8,   142,   143,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,   142,   143,   142,   143,   240,
     142,   143,   142,   143,   143,   285,   286,   143,   288,   289,
     290,   291,   142,   143,   142,   143,   143,   377,   143,   379,
     142,   143,     3,     4,     5,     6,     7,     8,   142,   143,
     310,   143,   240,   143,   314,   315,   142,   143,   142,   143,
     143,   321,   322,   143,   324,   286,   326,   143,   289,   143,
     291,   142,   143,   333,   334,   143,   336,   142,   143,   339,
     142,   143,   143,   343,   143,   142,   346,   143,   348,   349,
     350,   142,   143,   314,   315,   355,   143,   285,   286,   359,
     288,   289,   290,   291,   143,   142,   143,   142,   143,   143,
     298,   142,   143,   334,     3,     4,     5,     6,     7,     8,
     142,   143,   343,   142,   143,   143,   314,   315,   142,   143,
     142,   143,   143,   321,   143,   395,   142,   143,   142,   143,
     143,   329,   142,   143,   143,   333,   334,   143,   142,   143,
     143,   143,   143,   143,   143,   343,   143,   143,   143,   143,
     143,   421,     3,     4,     5,     6,     7,     8,   428,   143,
     143,   143,   143,   143,   395,   143,   143,   143,   143,   143,
     575,   142,   143,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,   143,   143,     3,     4,     5,
       6,     7,     8,   143,   143,   143,   143,   395,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,   143,   487,   143,   143,
     490,   143,   143,   143,   494,   143,   143,   497,   498,   143,
     428,   143,   143,   143,   504,   143,   143,   143,   508,   143,
     143,   511,   143,   142,   143,   143,   140,   143,   518,   341,
     143,   143,   143,   143,   524,    -1,   487,    -1,   392,    -1,
     530,    -1,    -1,   494,    -1,    -1,    -1,    -1,    -1,   539,
      -1,    -1,    -1,    -1,    -1,    -1,   546,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,   487,
      -1,   142,   143,    -1,    -1,    -1,   494,    -1,    -1,   497,
     498,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,   142,   143,    -1,    -1,    -1,    -1,   142,   143,
     518,    -1,    -1,    -1,    -1,   595,   142,   143,    -1,    -1,
      -1,    -1,   530,   531,    -1,    -1,    -1,   142,   143,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,    -1,    -1,   142,
     620,    -1,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,   595,    -1,    -1,   149,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,   159,   160,    -1,
      -1,    -1,    -1,    -1,    -1,   167,    -1,   657,    -1,   171,
     172,   173,   174,   175,   176,   177,   178,   595,    -1,    -1,
     182,   183,    -1,    -1,   186,    -1,    -1,   677,   190,   191,
     192,   193,   194,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,   214,    -1,     3,     4,     5,     6,     7,     8,
     142,   143,    -1,   225,   226,   227,   228,   229,   230,    -1,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,   657,
      -1,    -1,   244,   245,    -1,   247,    -1,    -1,    -1,   251,
     252,   253,   254,    -1,    -1,   257,   258,    -1,    -1,    -1,
      -1,   263,    -1,    -1,   266,    -1,   268,   269,   270,   271,
     272,   142,   143,    -1,   276,    -1,   278,   142,   280,   281,
     282,   283,     3,     4,     5,     6,     7,     8,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,   301,
      -1,    -1,    -1,   305,   306,    -1,    -1,    -1,   310,    -1,
      -1,   313,    -1,    -1,     3,     4,     5,     6,     7,     8,
     322,    -1,   324,    -1,   326,    -1,   328,    -1,    -1,   331,
       3,     4,     5,     6,     7,     8,    -1,    -1,   340,    -1,
      -1,    -1,   344,    -1,    -1,   347,   348,    -1,    -1,   351,
      -1,    -1,   354,   142,   143,    -1,   358,   359,    -1,    -1,
      -1,   363,   364,   365,     3,     4,     5,     6,     7,     8,
     372,    -1,    -1,    -1,    -1,   377,   378,   379,   380,    -1,
      -1,   383,    -1,    -1,   386,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,   409,    -1,    -1,
      -1,    -1,   414,    -1,   416,    -1,    -1,   419,    -1,    -1,
     422,   142,   143,    -1,   426,    -1,    -1,   429,   430,   142,
     143,    -1,    -1,   435,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,   445,     3,     4,     5,     6,     7,     8,
      -1,    -1,   454,   142,   143,    -1,    -1,    -1,    -1,   461,
      -1,    -1,    -1,   465,    -1,    -1,   468,    -1,   470,   142,
     143,    -1,    -1,    -1,    -1,    -1,   478,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,   491,
      -1,    -1,    -1,    -1,   496,     3,     4,     5,     6,     7,
       8,    -1,   504,   142,   143,    -1,   508,    -1,    -1,   511,
      -1,    -1,    -1,    -1,   516,    -1,    -1,   519,     3,     4,
       5,     6,     7,     8,   142,   143,    -1,    -1,    -1,    -1,
     142,   143,    -1,    -1,    -1,    -1,   142,   143,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,   556,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,   566,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   613,    -1,    -1,   616,    -1,   142,   143,    -1,    -1,
      -1,    -1,   142,   143,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   656,    -1,    -1,   142,   143,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,   142,   143,    -1,    -1,    11,   701,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,   144,   145,   146,   147,   148,   149,   150,     3,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,   144,
     145,   146,   147,   148,   149,   150,     3,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,    -1,   130,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,   142,    -1,   144,   145,   146,
     147,   148,   149,   150,     3,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   142,   143,    -1,    -1,    -1,    -1,   142,
     143,    -1,    -1,    -1,    -1,   142,   143,     3,     4,     5,
       6,     7,     8,   142,   143,     3,     4,     5,     6,     7,
       8,    -1,    -1,   132,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,   142,    -1,   144,   145,   146,   147,   148,
     149,   150,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,     3,     4,     5,     6,
       7,     8,    -1,   142,   143,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,   142,    -1,   144,   145,   146,   147,   148,   149,   150,
       3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,     3,
       4,     5,     6,     7,     8,   142,   143,     3,     4,     5,
       6,     7,     8,    -1,   142,   143,    -1,    -1,    -1,    -1,
     142,   143,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,   142,
      -1,   144,   145,   146,   147,   148,   149,   150,     3,     4,
       5,     6,     7,     8,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,    -1,    -1,    -1,    -1,   142,   143,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,    -1,    -1,   142,
     143,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,    -1,
      -1,   142,   143,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   142,   152,   153,   158,   159,   160,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,     3,     4,    11,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   144,   145,   146,
     147,   148,   149,   150,   158,   159,   160,     0,   159,   160,
     159,   160,     3,     4,     5,     6,     7,     8,   142,   143,
     154,   156,   158,   163,   143,   156,   154,   155,   155,   155,
     154,   166,   167,   154,   154,   154,   143,   143,   143,   154,
     154,   142,   156,   160,   156,   160,   156,   160,   156,   142,
     143,   156,   295,   159,   154,   143,   142,   160,   160,   154,
     160,   154,   154,   155,   154,   155,   154,   160,   154,   155,
     154,   160,   160,   160,   156,   155,   154,   143,   156,   156,
     160,   154,   143,   156,   156,   156,   155,   154,   155,   155,
     154,   154,   156,   155,   155,   155,   154,   155,   155,   155,
     154,   155,   155,   154,   155,   154,   154,   155,   154,   154,
     154,   143,   154,   160,   155,     3,   143,   160,   160,   143,
     160,   160,   143,   160,   143,   160,   160,   143,   160,   156,
     154,   154,   155,   154,   155,   155,     3,   164,   155,   157,
     154,   154,   160,   154,   154,   143,   156,   143,   159,   156,
     156,   143,   143,   154,   154,   156,   154,   143,   143,   143,
     154,   155,   154,   155,   143,   156,   143,   154,   154,   143,
     143,   143,   143,   154,   156,   143,   155,   143,   154,   155,
     154,   154,   155,   154,   143,   156,   143,   154,   156,   155,
     156,   155,   155,   155,   155,   143,   143,   143,    15,   158,
     143,   154,   143,   154,   143,   143,   143,   142,   143,   154,
     160,   161,   143,   143,   142,   161,   162,   159,   159,   143,
     143,   160,   143,   160,   156,   160,   143,   160,   156,   143,
     160,   156,   143,   143,   295,   143,   156,   143,   159,    15,
     143,   143,   143,   160,   154,   142,   143,   292,   295,   143,
     159,   142,   143,   297,   142,   143,   297,   143,   160,   154,
     143,   160,   143,   160,   160,   143,   154,   143,   143,   143,
     143,   160,   143,   143,   143,   160,   156,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   156,   143,   143,   143,
     143,   143,   155,   143,   154,   155,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   142,   143,   305,
     143,   143,     3,   143,   153,   165,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     154,   143,   154,     3,   143,   143,   154,   143,   143,   160,
     154,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   154,   159,   143,   160,
     161,   143,   161,   143,   143,   143,   143,   160,   143,   143,
     160,   143,   143,   160,   143,   143,   143,   154,   143,   143,
     160,   143,   143,   143,   143,   143,   143,   143,   160,   143,
     143,   143,   143,   160,   143,   143,   143,   160,   143,   143,
     143,   156,   143,   143,     3,   143,   153,   143,   154,   154,
     143,   143,   160,   143,   163,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   151,   152,   153,   154,   154,   155,   156,   156,   157,
     157,   158,   158,   159,   159,   159,   159,   159,   160,   160,
     160,   161,   161,   161,   162,   162,   163,   163,   163,   163,
     163,   163,   164,   164,   165,   165,   166,   167,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   180,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   189,   189,
     189,   190,   190,   190,   190,   191,   191,   191,   191,   192,
     193,   193,   193,   193,   193,   194,   195,   196,   197,   198,
     199,   199,   199,   199,   200,   200,   200,   201,   202,   203,
     203,   203,   203,   204,   204,   204,   204,   205,   205,   205,
     205,   206,   206,   206,   206,   207,   208,   209,   210,   210,
     211,   212,   212,   213,   213,   213,   213,   214,   215,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   230,   231,   232,   232,   233,
     234,   234,   235,   236,   236,   237,   238,   239,   240,   240,
     240,   241,   242,   243,   243,   243,   243,   244,   244,   245,
     245,   246,   247,   247,   248,   249,   249,   250,   250,   251,
     252,   252,   253,   254,   255,   255,   256,   257,   258,   259,
     259,   260,   261,   262,   263,   264,   264,   264,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   301,   302,
     303,   304,   305,   306,   307,   307
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
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       5,     5,     3,     3,     3,     4,     4,     5,     5,     6,
       4,     5,     5,     6,     4,     5,     5,     6,     4,     4,
       5,     5,     4,     4,     3,     4,     3,     5,     4,     4,
       5,     5,     6,     4,     4,     5,     5,     4,     5,     5,
       4,     5,     4,     5,     5,     6,     4,     5,     4,     5,
       4,     5,     5,     6,     4,     4,     4,     4,     5,     4,
       4,     4,     3,     5,     5,     6,     4,     4,     4,     3,
       4,     4,     4,     4,     4,     4,     4,     5,     4,     4,
       4,     4,     4,     5,     4,     5,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     4,
       5,     4,     4,     6,     5,     5,     4,     4,     3,     3,
       4,     4,     3,     4,     4,     3,     4,     3,     4,     4,
       3,     4,     4,     4,     4,     3,     4,     4,     4,     4,
       5,     4,     4,     4,     4,     4,     5,     5,     6,     4,
       4,     3,     4,     3,     4,     4,     4,     3,     4,     3,
       4,     4,     4,     3,     3,     3,     4,     4,     4,     4,
       4,     3,     3,     4,     4,     3,     3,     3,     3,     4,
       4,     3,     4,     3,     4,     4,     4,     4,     4,     4,
       3,     4,     3,     4,     5,     6
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
#line 2064 "parser.c"
        break;

    case 4: /* STR  */
#line 73 "../src/parser.y"
            { free(((*yyvaluep).s)); }
#line 2070 "parser.c"
        break;

    case 152: /* start  */
#line 71 "../src/parser.y"
            { run(((*yyvaluep).e));  }
#line 2076 "parser.c"
        break;

    case 153: /* s  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2082 "parser.c"
        break;

    case 154: /* p  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2088 "parser.c"
        break;

    case 155: /* pp  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2094 "parser.c"
        break;

    case 156: /* ps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2100 "parser.c"
        break;

    case 157: /* pps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2106 "parser.c"
        break;

    case 158: /* vp  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2112 "parser.c"
        break;

    case 159: /* vps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2118 "parser.c"
        break;

    case 160: /* opts  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2124 "parser.c"
        break;

    case 161: /* xpb  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2130 "parser.c"
        break;

    case 162: /* xpbs  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2136 "parser.c"
        break;

    case 163: /* np  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2142 "parser.c"
        break;

    case 164: /* sps  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2148 "parser.c"
        break;

    case 165: /* par  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2154 "parser.c"
        break;

    case 166: /* cv  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2160 "parser.c"
        break;

    case 167: /* cvv  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2166 "parser.c"
        break;

    case 168: /* opt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2172 "parser.c"
        break;

    case 169: /* ivp  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2178 "parser.c"
        break;

    case 170: /* add  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2184 "parser.c"
        break;

    case 171: /* div  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2190 "parser.c"
        break;

    case 172: /* mul  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2196 "parser.c"
        break;

    case 173: /* sub  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2202 "parser.c"
        break;

    case 174: /* eq  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2208 "parser.c"
        break;

    case 175: /* gt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2214 "parser.c"
        break;

    case 176: /* gte  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2220 "parser.c"
        break;

    case 177: /* lt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2226 "parser.c"
        break;

    case 178: /* lte  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2232 "parser.c"
        break;

    case 179: /* neq  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2238 "parser.c"
        break;

    case 180: /* if  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2244 "parser.c"
        break;

    case 181: /* select  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2250 "parser.c"
        break;

    case 182: /* until  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2256 "parser.c"
        break;

    case 183: /* while  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2262 "parser.c"
        break;

    case 184: /* trace  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2268 "parser.c"
        break;

    case 185: /* retrace  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2274 "parser.c"
        break;

    case 186: /* astraw  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2280 "parser.c"
        break;

    case 187: /* asbraw  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2286 "parser.c"
        break;

    case 188: /* asbeval  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2292 "parser.c"
        break;

    case 189: /* execute  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2298 "parser.c"
        break;

    case 190: /* rexx  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2304 "parser.c"
        break;

    case 191: /* run  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2310 "parser.c"
        break;

    case 192: /* abort  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2316 "parser.c"
        break;

    case 193: /* exit  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2322 "parser.c"
        break;

    case 194: /* onerror  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2328 "parser.c"
        break;

    case 195: /* reboot  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2334 "parser.c"
        break;

    case 196: /* trap  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2340 "parser.c"
        break;

    case 197: /* copyfiles  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2346 "parser.c"
        break;

    case 198: /* copylib  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2352 "parser.c"
        break;

    case 199: /* delete  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2358 "parser.c"
        break;

    case 200: /* exists  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2364 "parser.c"
        break;

    case 201: /* fileonly  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2370 "parser.c"
        break;

    case 202: /* foreach  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2376 "parser.c"
        break;

    case 203: /* makeassign  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2382 "parser.c"
        break;

    case 204: /* makedir  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2388 "parser.c"
        break;

    case 205: /* protect  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2394 "parser.c"
        break;

    case 206: /* startup  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2400 "parser.c"
        break;

    case 207: /* textfile  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2406 "parser.c"
        break;

    case 208: /* tooltype  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2412 "parser.c"
        break;

    case 209: /* transcript  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2418 "parser.c"
        break;

    case 210: /* rename  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2424 "parser.c"
        break;

    case 211: /* complete  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2430 "parser.c"
        break;

    case 212: /* debug  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2436 "parser.c"
        break;

    case 213: /* message  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2442 "parser.c"
        break;

    case 214: /* user  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2448 "parser.c"
        break;

    case 215: /* welcome  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2454 "parser.c"
        break;

    case 216: /* working  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2460 "parser.c"
        break;

    case 217: /* and  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2466 "parser.c"
        break;

    case 218: /* bitand  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2472 "parser.c"
        break;

    case 219: /* bitnot  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2478 "parser.c"
        break;

    case 220: /* bitor  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2484 "parser.c"
        break;

    case 221: /* bitxor  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2490 "parser.c"
        break;

    case 222: /* not  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2496 "parser.c"
        break;

    case 223: /* in  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2502 "parser.c"
        break;

    case 224: /* or  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2508 "parser.c"
        break;

    case 225: /* shiftleft  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2514 "parser.c"
        break;

    case 226: /* shiftright  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2520 "parser.c"
        break;

    case 227: /* xor  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2526 "parser.c"
        break;

    case 228: /* closemedia  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2532 "parser.c"
        break;

    case 229: /* effect  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2538 "parser.c"
        break;

    case 230: /* setmedia  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2544 "parser.c"
        break;

    case 231: /* showmedia  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2550 "parser.c"
        break;

    case 232: /* database  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2556 "parser.c"
        break;

    case 233: /* earlier  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2562 "parser.c"
        break;

    case 234: /* getassign  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2568 "parser.c"
        break;

    case 235: /* getdevice  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2574 "parser.c"
        break;

    case 236: /* getdiskspace  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2580 "parser.c"
        break;

    case 237: /* getenv  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2586 "parser.c"
        break;

    case 238: /* getsize  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2592 "parser.c"
        break;

    case 239: /* getsum  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2598 "parser.c"
        break;

    case 240: /* getversion  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2604 "parser.c"
        break;

    case 241: /* iconinfo  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2610 "parser.c"
        break;

    case 242: /* querydisplay  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2616 "parser.c"
        break;

    case 243: /* dcl  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2622 "parser.c"
        break;

    case 244: /* cus  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2628 "parser.c"
        break;

    case 245: /* askbool  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2634 "parser.c"
        break;

    case 246: /* askchoice  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2640 "parser.c"
        break;

    case 247: /* askdir  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2646 "parser.c"
        break;

    case 248: /* askdisk  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2652 "parser.c"
        break;

    case 249: /* askfile  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2658 "parser.c"
        break;

    case 250: /* asknumber  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2664 "parser.c"
        break;

    case 251: /* askoptions  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2670 "parser.c"
        break;

    case 252: /* askstring  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2676 "parser.c"
        break;

    case 253: /* cat  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2682 "parser.c"
        break;

    case 254: /* expandpath  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2688 "parser.c"
        break;

    case 255: /* fmt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2694 "parser.c"
        break;

    case 256: /* pathonly  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2700 "parser.c"
        break;

    case 257: /* patmatch  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2706 "parser.c"
        break;

    case 258: /* strlen  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2712 "parser.c"
        break;

    case 259: /* substr  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2718 "parser.c"
        break;

    case 260: /* tackon  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2724 "parser.c"
        break;

    case 261: /* set  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2730 "parser.c"
        break;

    case 262: /* symbolset  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2736 "parser.c"
        break;

    case 263: /* symbolval  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2742 "parser.c"
        break;

    case 264: /* openwbobject  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2748 "parser.c"
        break;

    case 265: /* showwbobject  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2754 "parser.c"
        break;

    case 266: /* closewbobject  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2760 "parser.c"
        break;

    case 267: /* all  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2766 "parser.c"
        break;

    case 268: /* append  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2772 "parser.c"
        break;

    case 269: /* assigns  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2778 "parser.c"
        break;

    case 270: /* back  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2784 "parser.c"
        break;

    case 271: /* choices  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2790 "parser.c"
        break;

    case 272: /* command  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2796 "parser.c"
        break;

    case 273: /* compression  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2802 "parser.c"
        break;

    case 274: /* confirm  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2808 "parser.c"
        break;

    case 275: /* default  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2814 "parser.c"
        break;

    case 276: /* delopts  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2820 "parser.c"
        break;

    case 277: /* dest  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2826 "parser.c"
        break;

    case 278: /* disk  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2832 "parser.c"
        break;

    case 279: /* files  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2838 "parser.c"
        break;

    case 280: /* fonts  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2844 "parser.c"
        break;

    case 281: /* getdefaulttool  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2850 "parser.c"
        break;

    case 282: /* getposition  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2856 "parser.c"
        break;

    case 283: /* getstack  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2862 "parser.c"
        break;

    case 284: /* gettooltype  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2868 "parser.c"
        break;

    case 285: /* help  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2874 "parser.c"
        break;

    case 286: /* infos  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2880 "parser.c"
        break;

    case 287: /* include  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2886 "parser.c"
        break;

    case 288: /* newname  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2892 "parser.c"
        break;

    case 289: /* newpath  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2898 "parser.c"
        break;

    case 290: /* nogauge  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2904 "parser.c"
        break;

    case 291: /* noposition  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2910 "parser.c"
        break;

    case 292: /* noreq  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2916 "parser.c"
        break;

    case 293: /* pattern  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2922 "parser.c"
        break;

    case 294: /* prompt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2928 "parser.c"
        break;

    case 295: /* quiet  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2934 "parser.c"
        break;

    case 296: /* range  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2940 "parser.c"
        break;

    case 297: /* safe  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2946 "parser.c"
        break;

    case 298: /* setdefaulttool  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2952 "parser.c"
        break;

    case 299: /* setposition  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2958 "parser.c"
        break;

    case 300: /* setstack  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2964 "parser.c"
        break;

    case 301: /* settooltype  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2970 "parser.c"
        break;

    case 302: /* source  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2976 "parser.c"
        break;

    case 303: /* swapcolors  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2982 "parser.c"
        break;

    case 304: /* optional  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2988 "parser.c"
        break;

    case 305: /* resident  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 2994 "parser.c"
        break;

    case 306: /* override  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3000 "parser.c"
        break;

    case 307: /* dynopt  */
#line 75 "../src/parser.y"
            { kill(((*yyvaluep).e)); }
#line 3006 "parser.c"
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
#line 3280 "parser.c"
    break;

  case 6:
#line 94 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3286 "parser.c"
    break;

  case 7:
#line 95 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3292 "parser.c"
    break;

  case 8:
#line 96 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3298 "parser.c"
    break;

  case 9:
#line 97 "../src/parser.y"
                                                 { (yyval.e) = push(push((yyvsp[-2].e), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3304 "parser.c"
    break;

  case 12:
#line 100 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3310 "parser.c"
    break;

  case 13:
#line 101 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3316 "parser.c"
    break;

  case 14:
#line 102 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e));  }
#line 3322 "parser.c"
    break;

  case 15:
#line 103 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e));  }
#line 3328 "parser.c"
    break;

  case 16:
#line 104 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3334 "parser.c"
    break;

  case 17:
#line 105 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3340 "parser.c"
    break;

  case 18:
#line 106 "../src/parser.y"
                                                 { (yyval.e) = merge((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3346 "parser.c"
    break;

  case 19:
#line 107 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3352 "parser.c"
    break;

  case 20:
#line 108 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3358 "parser.c"
    break;

  case 21:
#line 109 "../src/parser.y"
                                                 { (yyval.e) = (yyvsp[-1].e); }
#line 3364 "parser.c"
    break;

  case 22:
#line 110 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-2].e), (yyvsp[-1].e)); }
#line 3370 "parser.c"
    break;

  case 23:
#line 111 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3376 "parser.c"
    break;

  case 24:
#line 112 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), (yyvsp[0].e)); }
#line 3382 "parser.c"
    break;

  case 25:
#line 113 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), (yyvsp[0].e)); }
#line 3388 "parser.c"
    break;

  case 26:
#line 114 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3394 "parser.c"
    break;

  case 27:
#line 115 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3400 "parser.c"
    break;

  case 28:
#line 116 "../src/parser.y"
                                                 { (yyval.e) = new_number((yyvsp[0].n)); }
#line 3406 "parser.c"
    break;

  case 29:
#line 117 "../src/parser.y"
                                                 { (yyval.e) = new_string((yyvsp[0].s)); }
#line 3412 "parser.c"
    break;

  case 30:
#line 118 "../src/parser.y"
                                                 { (yyval.e) = new_symref((yyvsp[0].s), LINE); }
#line 3418 "parser.c"
    break;

  case 31:
#line 119 "../src/parser.y"
                                                 { (yyval.e) = NULL; YYFPRINTF(stderr, "Out of memory in line %d\n", LINE); YYABORT; }
#line 3424 "parser.c"
    break;

  case 32:
#line 120 "../src/parser.y"
                                                 { (yyval.e) = push(push((yyvsp[-2].e), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)) ; }
#line 3430 "parser.c"
    break;

  case 33:
#line 121 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), new_symbol((yyvsp[-1].s))), (yyvsp[0].e)); }
#line 3436 "parser.c"
    break;

  case 34:
#line 122 "../src/parser.y"
                                                 { (yyval.e) = push((yyvsp[-1].e), new_symbol((yyvsp[0].s))); }
#line 3442 "parser.c"
    break;

  case 35:
#line 123 "../src/parser.y"
                                                 { (yyval.e) = push(new_contxt(), new_symbol((yyvsp[0].s))); }
#line 3448 "parser.c"
    break;

  case 36:
#line 124 "../src/parser.y"
                                                 { (yyval.e) = push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3454 "parser.c"
    break;

  case 37:
#line 125 "../src/parser.y"
                                                 { (yyval.e) = push(push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), (yyvsp[0].e)); }
#line 3460 "parser.c"
    break;

  case 176:
#line 273 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("+"), LINE, m_add, (yyvsp[-1].e), NUMBER); }
#line 3466 "parser.c"
    break;

  case 177:
#line 274 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("/"), LINE, m_div, (yyvsp[-1].e), NUMBER); }
#line 3472 "parser.c"
    break;

  case 178:
#line 275 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("*"), LINE, m_mul, (yyvsp[-1].e), NUMBER); }
#line 3478 "parser.c"
    break;

  case 179:
#line 276 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("-"), LINE, m_sub, (yyvsp[-1].e), NUMBER); }
#line 3484 "parser.c"
    break;

  case 180:
#line 280 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("="), LINE, m_eq, (yyvsp[-1].e), NUMBER); }
#line 3490 "parser.c"
    break;

  case 181:
#line 281 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup(">"), LINE, m_gt, (yyvsp[-1].e), NUMBER); }
#line 3496 "parser.c"
    break;

  case 182:
#line 282 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup(">="), LINE, m_gte, (yyvsp[-1].e), NUMBER); }
#line 3502 "parser.c"
    break;

  case 183:
#line 283 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<"), LINE, m_lt, (yyvsp[-1].e), NUMBER); }
#line 3508 "parser.c"
    break;

  case 184:
#line 284 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<="), LINE, m_lte, (yyvsp[-1].e), NUMBER); }
#line 3514 "parser.c"
    break;

  case 185:
#line 285 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("<>"), LINE, m_neq, (yyvsp[-1].e), NUMBER); }
#line 3520 "parser.c"
    break;

  case 186:
#line 289 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3526 "parser.c"
    break;

  case 187:
#line 290 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("if"), LINE, m_if, (yyvsp[-1].e), NUMBER); }
#line 3532 "parser.c"
    break;

  case 188:
#line 291 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("if"), LINE, m_if, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3538 "parser.c"
    break;

  case 189:
#line 292 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("select"), LINE, m_select, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3544 "parser.c"
    break;

  case 190:
#line 293 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("until"), LINE, m_until, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3550 "parser.c"
    break;

  case 191:
#line 294 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("while"), LINE, m_while, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3556 "parser.c"
    break;

  case 192:
#line 295 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("trace"), LINE, m_trace, NULL, NUMBER); }
#line 3562 "parser.c"
    break;

  case 193:
#line 296 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("retrace"), LINE, m_retrace, NULL, NUMBER); }
#line 3568 "parser.c"
    break;

  case 194:
#line 300 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___astraw"), LINE, m_astraw, NULL, NUMBER); }
#line 3574 "parser.c"
    break;

  case 195:
#line 301 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___asbraw"), LINE, m_asbraw, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3580 "parser.c"
    break;

  case 196:
#line 302 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("___asbeval"), LINE, m_asbeval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3586 "parser.c"
    break;

  case 197:
#line 306 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3592 "parser.c"
    break;

  case 198:
#line 307 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3598 "parser.c"
    break;

  case 199:
#line 308 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3604 "parser.c"
    break;

  case 200:
#line 309 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("execute"), LINE, m_execute, (yyvsp[-1].e), NUMBER); }
#line 3610 "parser.c"
    break;

  case 201:
#line 310 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3616 "parser.c"
    break;

  case 202:
#line 311 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3622 "parser.c"
    break;

  case 203:
#line 312 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3628 "parser.c"
    break;

  case 204:
#line 313 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rexx"), LINE, m_rexx, (yyvsp[-1].e), NUMBER); }
#line 3634 "parser.c"
    break;

  case 205:
#line 314 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3640 "parser.c"
    break;

  case 206:
#line 315 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3646 "parser.c"
    break;

  case 207:
#line 316 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, m_run, push((yyvsp[-2].e), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3652 "parser.c"
    break;

  case 208:
#line 317 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("run"), LINE, m_run, (yyvsp[-1].e), NUMBER); }
#line 3658 "parser.c"
    break;

  case 209:
#line 321 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("abort"), LINE, m_abort, (yyvsp[-1].e), NUMBER); }
#line 3664 "parser.c"
    break;

  case 210:
#line 322 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3670 "parser.c"
    break;

  case 211:
#line 323 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3676 "parser.c"
    break;

  case 212:
#line 324 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3682 "parser.c"
    break;

  case 213:
#line 325 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, (yyvsp[-1].e), NUMBER); }
#line 3688 "parser.c"
    break;

  case 214:
#line 326 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exit"), LINE, m_exit, NULL, NUMBER); }
#line 3694 "parser.c"
    break;

  case 215:
#line 327 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("onerror"), LINE, m_procedure, push(new_contxt(),
                                                        new_custom(strdup("@onerror"), LINE, NULL, (yyvsp[-1].e))), DANGLE); }
#line 3701 "parser.c"
    break;

  case 216:
#line 329 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("reboot"), LINE, m_reboot, NULL, NUMBER); }
#line 3707 "parser.c"
    break;

  case 217:
#line 330 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("trap"), LINE, m_trap, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3713 "parser.c"
    break;

  case 218:
#line 334 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("copyfiles"), LINE, m_copyfiles, (yyvsp[-1].e), NUMBER); }
#line 3719 "parser.c"
    break;

  case 219:
#line 335 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("copylib"), LINE, m_copylib, (yyvsp[-1].e), NUMBER); }
#line 3725 "parser.c"
    break;

  case 220:
#line 336 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3731 "parser.c"
    break;

  case 221:
#line 337 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3737 "parser.c"
    break;

  case 222:
#line 338 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3743 "parser.c"
    break;

  case 223:
#line 339 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("delete"), LINE, m_delete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3749 "parser.c"
    break;

  case 224:
#line 340 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3755 "parser.c"
    break;

  case 225:
#line 341 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3761 "parser.c"
    break;

  case 226:
#line 342 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("exists"), LINE, m_exists, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3767 "parser.c"
    break;

  case 227:
#line 343 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("fileonly"), LINE, m_fileonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 3773 "parser.c"
    break;

  case 228:
#line 344 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("foreach"), LINE, m_foreach, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3779 "parser.c"
    break;

  case 229:
#line 345 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3785 "parser.c"
    break;

  case 230:
#line 346 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, (yyvsp[-1].e), NUMBER); }
#line 3791 "parser.c"
    break;

  case 231:
#line 347 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3797 "parser.c"
    break;

  case 232:
#line 348 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makeassign"), LINE, m_makeassign, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3803 "parser.c"
    break;

  case 233:
#line 349 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3809 "parser.c"
    break;

  case 234:
#line 350 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3815 "parser.c"
    break;

  case 235:
#line 351 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3821 "parser.c"
    break;

  case 236:
#line 352 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("makedir"), LINE, m_makedir, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3827 "parser.c"
    break;

  case 237:
#line 353 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3833 "parser.c"
    break;

  case 238:
#line 354 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, (yyvsp[-1].e), NUMBER); }
#line 3839 "parser.c"
    break;

  case 239:
#line 355 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3845 "parser.c"
    break;

  case 240:
#line 356 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("protect"), LINE, m_protect, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3851 "parser.c"
    break;

  case 241:
#line 357 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 3857 "parser.c"
    break;

  case 242:
#line 358 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3863 "parser.c"
    break;

  case 243:
#line 359 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 3869 "parser.c"
    break;

  case 244:
#line 360 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("startup"), LINE, m_startup, push(push(new_contxt(), new_symref(strdup("@app-name"), LINE)), (yyvsp[-1].e)), NUMBER); }
#line 3875 "parser.c"
    break;

  case 245:
#line 361 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("textfile"), LINE, m_textfile, (yyvsp[-1].e), NUMBER); }
#line 3881 "parser.c"
    break;

  case 246:
#line 362 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("tooltype"), LINE, m_tooltype, (yyvsp[-1].e), NUMBER); }
#line 3887 "parser.c"
    break;

  case 247:
#line 363 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("transcript"), LINE, m_transcript, (yyvsp[-1].e), NUMBER); }
#line 3893 "parser.c"
    break;

  case 248:
#line 364 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3899 "parser.c"
    break;

  case 249:
#line 365 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("rename"), LINE, m_rename, (yyvsp[-1].e), NUMBER); }
#line 3905 "parser.c"
    break;

  case 250:
#line 369 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("complete"), LINE, m_complete, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3911 "parser.c"
    break;

  case 251:
#line 370 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, (yyvsp[-1].e), NUMBER); }
#line 3917 "parser.c"
    break;

  case 252:
#line 371 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("debug"), LINE, m_debug, NULL, NUMBER); }
#line 3923 "parser.c"
    break;

  case 253:
#line 372 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, m_message, merge((yyvsp[-1].e), (yyvsp[-2].e)), NUMBER); }
#line 3929 "parser.c"
    break;

  case 254:
#line 373 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, m_message, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 3935 "parser.c"
    break;

  case 255:
#line 374 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, m_message, push(merge((yyvsp[-3].e), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 3941 "parser.c"
    break;

  case 256:
#line 375 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("message"), LINE, m_message, (yyvsp[-1].e), NUMBER); }
#line 3947 "parser.c"
    break;

  case 257:
#line 376 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("user"), LINE, m_user, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3953 "parser.c"
    break;

  case 258:
#line 377 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, (yyvsp[-1].e), NUMBER); }
#line 3959 "parser.c"
    break;

  case 259:
#line 378 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("welcome"), LINE, m_welcome, NULL, NUMBER); }
#line 3965 "parser.c"
    break;

  case 260:
#line 379 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("working"), LINE, m_working, (yyvsp[-1].e), NUMBER); }
#line 3971 "parser.c"
    break;

  case 261:
#line 383 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("AND"), LINE, m_and, (yyvsp[-1].e), NUMBER); }
#line 3977 "parser.c"
    break;

  case 262:
#line 384 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITAND"), LINE, m_bitand, (yyvsp[-1].e), NUMBER); }
#line 3983 "parser.c"
    break;

  case 263:
#line 385 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITNOT"), LINE, m_bitnot, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 3989 "parser.c"
    break;

  case 264:
#line 386 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITOR"), LINE, m_bitor, (yyvsp[-1].e), NUMBER); }
#line 3995 "parser.c"
    break;

  case 265:
#line 387 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("BITXOR"), LINE, m_bitxor, (yyvsp[-1].e), NUMBER); }
#line 4001 "parser.c"
    break;

  case 266:
#line 388 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("NOT"), LINE, m_not, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4007 "parser.c"
    break;

  case 267:
#line 389 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("IN"), LINE, m_in, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4013 "parser.c"
    break;

  case 268:
#line 390 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("OR"), LINE, m_or, (yyvsp[-1].e), NUMBER); }
#line 4019 "parser.c"
    break;

  case 269:
#line 391 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("shiftleft"), LINE, m_shiftleft, (yyvsp[-1].e), NUMBER); }
#line 4025 "parser.c"
    break;

  case 270:
#line 392 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("shiftright"), LINE, m_shiftright, (yyvsp[-1].e), NUMBER); }
#line 4031 "parser.c"
    break;

  case 271:
#line 393 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("XOR"), LINE, m_xor, (yyvsp[-1].e), NUMBER); }
#line 4037 "parser.c"
    break;

  case 272:
#line 397 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("closemedia"), LINE, m_closemedia, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4043 "parser.c"
    break;

  case 273:
#line 398 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("effect"), LINE, m_effect, merge((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4049 "parser.c"
    break;

  case 274:
#line 399 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("setmedia"), LINE, m_setmedia, (yyvsp[-1].e), NUMBER); }
#line 4055 "parser.c"
    break;

  case 275:
#line 400 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("setmedia"), LINE, m_setmedia, push((yyvsp[-2].e), (yyvsp[-1].e)), NUMBER); }
#line 4061 "parser.c"
    break;

  case 276:
#line 401 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("showmedia"), LINE, m_showmedia, merge(merge((yyvsp[-3].e), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4067 "parser.c"
    break;

  case 277:
#line 405 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("database"), LINE, m_database, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4073 "parser.c"
    break;

  case 278:
#line 406 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("database"), LINE, m_database, (yyvsp[-1].e), STRING); }
#line 4079 "parser.c"
    break;

  case 279:
#line 407 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("earlier"), LINE, m_earlier, (yyvsp[-1].e), NUMBER); }
#line 4085 "parser.c"
    break;

  case 280:
#line 408 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4091 "parser.c"
    break;

  case 281:
#line 409 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getassign"), LINE, m_getassign, (yyvsp[-1].e), STRING); }
#line 4097 "parser.c"
    break;

  case 282:
#line 410 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getdevice"), LINE, m_getdevice, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4103 "parser.c"
    break;

  case 283:
#line 411 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4109 "parser.c"
    break;

  case 284:
#line 412 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getdiskspace"), LINE, m_getdiskspace, (yyvsp[-1].e), NUMBER); }
#line 4115 "parser.c"
    break;

  case 285:
#line 413 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getenv"), LINE, m_getenv, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4121 "parser.c"
    break;

  case 286:
#line 414 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getsize"), LINE, m_getsize, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4127 "parser.c"
    break;

  case 287:
#line 415 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getsum"), LINE, m_getsum, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4133 "parser.c"
    break;

  case 288:
#line 416 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, NULL, NUMBER); }
#line 4139 "parser.c"
    break;

  case 289:
#line 417 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4145 "parser.c"
    break;

  case 290:
#line 418 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("getversion"), LINE, m_getversion, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4151 "parser.c"
    break;

  case 291:
#line 419 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("iconinfo"), LINE, m_iconinfo, (yyvsp[-1].e), NUMBER); }
#line 4157 "parser.c"
    break;

  case 292:
#line 420 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("querydisplay"), LINE, m_querydisplay, (yyvsp[-1].e), NUMBER); }
#line 4163 "parser.c"
    break;

  case 293:
#line 424 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-3].s), LINE, (yyvsp[-2].e), (yyvsp[-1].e))), NUMBER); }
#line 4169 "parser.c"
    break;

  case 294:
#line 425 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, (yyvsp[-1].e), NULL)), NUMBER); }
#line 4175 "parser.c"
    break;

  case 295:
#line 426 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-2].s), LINE, NULL, (yyvsp[-1].e))), NUMBER); }
#line 4181 "parser.c"
    break;

  case 296:
#line 427 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("procedure"), LINE, m_procedure, push(new_contxt(), new_custom((yyvsp[-1].s), LINE, NULL, NULL)), NUMBER); }
#line 4187 "parser.c"
    break;

  case 297:
#line 428 "../src/parser.y"
                                                 { (yyval.e) = new_cusref((yyvsp[-2].s), LINE, (yyvsp[-1].e)); }
#line 4193 "parser.c"
    break;

  case 298:
#line 429 "../src/parser.y"
                                                 { (yyval.e) = new_cusref((yyvsp[-1].s), LINE, NULL); }
#line 4199 "parser.c"
    break;

  case 299:
#line 433 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, NULL, NUMBER); }
#line 4205 "parser.c"
    break;

  case 300:
#line 434 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askbool"), LINE, m_askbool, (yyvsp[-1].e), NUMBER); }
#line 4211 "parser.c"
    break;

  case 301:
#line 435 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askchoice"), LINE, m_askchoice, (yyvsp[-1].e), NUMBER); }
#line 4217 "parser.c"
    break;

  case 302:
#line 436 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, NULL, STRING); }
#line 4223 "parser.c"
    break;

  case 303:
#line 437 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askdir"), LINE, m_askdir, (yyvsp[-1].e), STRING); }
#line 4229 "parser.c"
    break;

  case 304:
#line 438 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askdisk"), LINE, m_askdisk, (yyvsp[-1].e), NUMBER); }
#line 4235 "parser.c"
    break;

  case 305:
#line 439 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, NULL, STRING); }
#line 4241 "parser.c"
    break;

  case 306:
#line 440 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askfile"), LINE, m_askfile, (yyvsp[-1].e), STRING); }
#line 4247 "parser.c"
    break;

  case 307:
#line 441 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, NULL, NUMBER); }
#line 4253 "parser.c"
    break;

  case 308:
#line 442 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("asknumber"), LINE, m_asknumber, (yyvsp[-1].e), NUMBER); }
#line 4259 "parser.c"
    break;

  case 309:
#line 443 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askoptions"), LINE, m_askoptions, (yyvsp[-1].e), NUMBER); }
#line 4265 "parser.c"
    break;

  case 310:
#line 444 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, NULL, STRING); }
#line 4271 "parser.c"
    break;

  case 311:
#line 445 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("askstring"), LINE, m_askstring, (yyvsp[-1].e), STRING); }
#line 4277 "parser.c"
    break;

  case 312:
#line 449 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("cat"), LINE, m_cat, (yyvsp[-1].e), STRING); }
#line 4283 "parser.c"
    break;

  case 313:
#line 450 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("expandpath"), LINE, m_expandpath, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4289 "parser.c"
    break;

  case 314:
#line 451 "../src/parser.y"
                                                 { (yyval.e) = new_native((yyvsp[-2].s), LINE, m_fmt, (yyvsp[-1].e), STRING); }
#line 4295 "parser.c"
    break;

  case 315:
#line 452 "../src/parser.y"
                                                 { (yyval.e) = new_native((yyvsp[-1].s), LINE, m_fmt, NULL, STRING); }
#line 4301 "parser.c"
    break;

  case 316:
#line 453 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("pathonly"), LINE, m_pathonly, push(new_contxt(), (yyvsp[-1].e)), STRING); }
#line 4307 "parser.c"
    break;

  case 317:
#line 454 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("patmatch"), LINE, m_patmatch, (yyvsp[-1].e), NUMBER); }
#line 4313 "parser.c"
    break;

  case 318:
#line 455 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("strlen"), LINE, m_strlen, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4319 "parser.c"
    break;

  case 319:
#line 456 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, (yyvsp[-1].e), STRING); }
#line 4325 "parser.c"
    break;

  case 320:
#line 457 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("substr"), LINE, m_substr, push((yyvsp[-2].e), (yyvsp[-1].e)), STRING); }
#line 4331 "parser.c"
    break;

  case 321:
#line 458 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("tackon"), LINE, m_tackon, (yyvsp[-1].e), STRING); }
#line 4337 "parser.c"
    break;

  case 322:
#line 462 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("set"), LINE, m_set, (yyvsp[-1].e), DANGLE); }
#line 4343 "parser.c"
    break;

  case 323:
#line 463 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("symbolset"), LINE, m_symbolset, (yyvsp[-1].e), DANGLE); }
#line 4349 "parser.c"
    break;

  case 324:
#line 464 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("symbolval"), LINE, m_symbolval, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4355 "parser.c"
    break;

  case 325:
#line 468 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4361 "parser.c"
    break;

  case 326:
#line 469 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e)), NUMBER); }
#line 4367 "parser.c"
    break;

  case 327:
#line 470 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-1].e)), (yyvsp[-2].e)), NUMBER); }
#line 4373 "parser.c"
    break;

  case 328:
#line 471 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("openwbobject"), LINE, m_openwbobject, push(push(new_contxt(), (yyvsp[-2].e)), merge((yyvsp[-3].e), (yyvsp[-1].e))), NUMBER); }
#line 4379 "parser.c"
    break;

  case 329:
#line 472 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("showwbobject"), LINE, m_showwbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4385 "parser.c"
    break;

  case 330:
#line 473 "../src/parser.y"
                                                 { (yyval.e) = new_native(strdup("closewbobject"), LINE, m_closewbobject, push(new_contxt(), (yyvsp[-1].e)), NUMBER); }
#line 4391 "parser.c"
    break;

  case 331:
#line 477 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("all"), OPT_ALL, NULL); }
#line 4397 "parser.c"
    break;

  case 332:
#line 478 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("append"), OPT_APPEND, (yyvsp[-1].e)); }
#line 4403 "parser.c"
    break;

  case 333:
#line 479 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("assigns"), OPT_ASSIGNS, NULL); }
#line 4409 "parser.c"
    break;

  case 334:
#line 480 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("back"), OPT_BACK, (yyvsp[-1].e)); }
#line 4415 "parser.c"
    break;

  case 335:
#line 481 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("choices"), OPT_CHOICES, (yyvsp[-1].e)); }
#line 4421 "parser.c"
    break;

  case 336:
#line 482 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("command"), OPT_COMMAND, (yyvsp[-1].e)); }
#line 4427 "parser.c"
    break;

  case 337:
#line 483 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("compression"), OPT_COMPRESSION, NULL); }
#line 4433 "parser.c"
    break;

  case 338:
#line 484 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, push(new_contxt(), (yyvsp[-1].e))); }
#line 4439 "parser.c"
    break;

  case 339:
#line 485 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("confirm"), OPT_CONFIRM, NULL); }
#line 4445 "parser.c"
    break;

  case 340:
#line 486 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("default"), OPT_DEFAULT, push(new_contxt(), (yyvsp[-1].e))); }
#line 4451 "parser.c"
    break;

  case 341:
#line 487 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("delopts"), OPT_DELOPTS, (yyvsp[-1].e)); }
#line 4457 "parser.c"
    break;

  case 342:
#line 488 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("dest"), OPT_DEST, push(new_contxt(), (yyvsp[-1].e))); }
#line 4463 "parser.c"
    break;

  case 343:
#line 489 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("disk"), OPT_DISK, NULL); }
#line 4469 "parser.c"
    break;

  case 344:
#line 490 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("files"), OPT_FILES, NULL); }
#line 4475 "parser.c"
    break;

  case 345:
#line 491 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("fonts"), OPT_FONTS, NULL); }
#line 4481 "parser.c"
    break;

  case 346:
#line 492 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("getdefaulttool"), OPT_GETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4487 "parser.c"
    break;

  case 347:
#line 493 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("getposition"), OPT_GETPOSITION, (yyvsp[-1].e)); }
#line 4493 "parser.c"
    break;

  case 348:
#line 494 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("getstack"), OPT_GETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4499 "parser.c"
    break;

  case 349:
#line 495 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("gettooltype"), OPT_GETTOOLTYPE, (yyvsp[-1].e)); }
#line 4505 "parser.c"
    break;

  case 350:
#line 496 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("help"), OPT_HELP, (yyvsp[-1].e)); }
#line 4511 "parser.c"
    break;

  case 351:
#line 497 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("help"), OPT_HELP, push(new_contxt(), new_symref(strdup("@null"), LINE))); }
#line 4517 "parser.c"
    break;

  case 352:
#line 498 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("infos"), OPT_INFOS, NULL); }
#line 4523 "parser.c"
    break;

  case 353:
#line 499 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("include"), OPT_INCLUDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4529 "parser.c"
    break;

  case 354:
#line 500 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("newname"), OPT_NEWNAME, push(new_contxt(), (yyvsp[-1].e))); }
#line 4535 "parser.c"
    break;

  case 355:
#line 501 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("newpath"), OPT_NEWPATH, NULL); }
#line 4541 "parser.c"
    break;

  case 356:
#line 502 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("nogauge"), OPT_NOGAUGE, NULL); }
#line 4547 "parser.c"
    break;

  case 357:
#line 503 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("noposition"), OPT_NOPOSITION, NULL); }
#line 4553 "parser.c"
    break;

  case 358:
#line 504 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("noreq"), OPT_NOREQ, NULL); }
#line 4559 "parser.c"
    break;

  case 359:
#line 505 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("pattern"), OPT_PATTERN, push(new_contxt(), (yyvsp[-1].e))); }
#line 4565 "parser.c"
    break;

  case 360:
#line 506 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("prompt"), OPT_PROMPT, (yyvsp[-1].e)); }
#line 4571 "parser.c"
    break;

  case 361:
#line 507 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("quiet"), OPT_QUIET, NULL); }
#line 4577 "parser.c"
    break;

  case 362:
#line 508 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("range"), OPT_RANGE, (yyvsp[-1].e)); }
#line 4583 "parser.c"
    break;

  case 363:
#line 509 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("safe"), OPT_SAFE, NULL); }
#line 4589 "parser.c"
    break;

  case 364:
#line 510 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("setdefaulttool"), OPT_SETDEFAULTTOOL, push(new_contxt(), (yyvsp[-1].e))); }
#line 4595 "parser.c"
    break;

  case 365:
#line 511 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("setposition"), OPT_SETPOSITION, (yyvsp[-1].e)); }
#line 4601 "parser.c"
    break;

  case 366:
#line 512 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("setstack"), OPT_SETSTACK, push(new_contxt(), (yyvsp[-1].e))); }
#line 4607 "parser.c"
    break;

  case 367:
#line 513 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, (yyvsp[-1].e)); }
#line 4613 "parser.c"
    break;

  case 368:
#line 514 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("settooltype"), OPT_SETTOOLTYPE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4619 "parser.c"
    break;

  case 369:
#line 515 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("source"), OPT_SOURCE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4625 "parser.c"
    break;

  case 370:
#line 516 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("swapcolors"), OPT_SWAPCOLORS, NULL); }
#line 4631 "parser.c"
    break;

  case 371:
#line 517 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("optional"), OPT_OPTIONAL, (yyvsp[-1].e)); }
#line 4637 "parser.c"
    break;

  case 372:
#line 518 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("resident"), OPT_RESIDENT, NULL); }
#line 4643 "parser.c"
    break;

  case 373:
#line 519 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("override"), OPT_OVERRIDE, push(new_contxt(), (yyvsp[-1].e))); }
#line 4649 "parser.c"
    break;

  case 374:
#line 520 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(new_contxt(), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4655 "parser.c"
    break;

  case 375:
#line 521 "../src/parser.y"
                                                 { (yyval.e) = new_option(strdup("dynopt"), OPT_DYNOPT, push(push(push(new_contxt(), (yyvsp[-3].e)), (yyvsp[-2].e)), (yyvsp[-1].e))); }
#line 4661 "parser.c"
    break;


#line 4665 "parser.c"

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
#line 523 "../src/parser.y"

