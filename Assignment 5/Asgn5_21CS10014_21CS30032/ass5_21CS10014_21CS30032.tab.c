/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ass5_21CS10014_21CS30032.y"

    #include <iostream>
    #include "ass5_21CS10014_21CS30032_translator.h"
    using namespace std;

    extern int yylex();         
    void yyerror(string s);     
    extern char* yytext;        
    extern int yylineno;        
    extern string typevar;      

#line 82 "ass5_21CS10014_21CS30032.tab.c"

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
#ifndef YY_YY_ASS5_21CS10014_21CS30032_TAB_H_INCLUDED
# define YY_YY_ASS5_21CS10014_21CS30032_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AUTO = 258,
    BREAK = 259,
    CASE = 260,
    CHAR = 261,
    CONST = 262,
    CONTINUE = 263,
    DEFAULT = 264,
    DO = 265,
    DOUBLE = 266,
    ELSE = 267,
    ENUM = 268,
    EXTERN = 269,
    FLOAT = 270,
    FOR = 271,
    GOTO = 272,
    IF = 273,
    INLINE = 274,
    INT = 275,
    LONG = 276,
    REGISTER = 277,
    RESTRICT = 278,
    RETURN = 279,
    SHORT = 280,
    SIGNED = 281,
    SIZEOF = 282,
    STATIC = 283,
    STRUCT = 284,
    SWITCH = 285,
    TYPEDEF = 286,
    UNION = 287,
    UNSIGNED = 288,
    VOID = 289,
    VOLATILE = 290,
    WHILE = 291,
    BOOL = 292,
    COMPLEX = 293,
    IMAGINARY = 294,
    SQUARE_BRACKET_OPEN = 295,
    SQUARE_BRACKET_CLOSE = 296,
    ROUND_BRACKET_OPEN = 297,
    ROUND_BRACKET_CLOSE = 298,
    CURLY_BRACKET_OPEN = 299,
    CURLY_BRACKET_CLOSE = 300,
    DOT = 301,
    ARROW = 302,
    INCREMENT = 303,
    DECREMENT = 304,
    BITWISE_AND = 305,
    BITWISE_OR = 306,
    BITWISE_XOR = 307,
    BITWISE_NOT = 308,
    LOGICAL_AND = 309,
    LOGICAL_OR = 310,
    LOGICAL_NOT = 311,
    MULTIPLY = 312,
    DIVIDE = 313,
    MODULO = 314,
    PLUS = 315,
    MINUS = 316,
    LEFT_SHIFT = 317,
    RIGHT_SHIFT = 318,
    LESS_THAN = 319,
    GREATER_THAN = 320,
    LESS_THAN_EQUAL = 321,
    GREATER_THAN_EQUAL = 322,
    EQUAL = 323,
    NOT_EQUAL = 324,
    ASSIGN = 325,
    PLUS_ASSIGN = 326,
    MINUS_ASSIGN = 327,
    MULTIPLY_ASSIGN = 328,
    DIVIDE_ASSIGN = 329,
    MODULO_ASSIGN = 330,
    LEFT_SHIFT_ASSIGN = 331,
    RIGHT_SHIFT_ASSIGN = 332,
    BITWISE_AND_ASSIGN = 333,
    BITWISE_XOR_ASSIGN = 334,
    BITWISE_OR_ASSIGN = 335,
    COMMA = 336,
    COLON = 337,
    SEMICOLON = 338,
    ELLIPSIS = 339,
    QUESTION_MARK = 340,
    HASH = 341,
    INTEGER_CONSTANT = 342,
    FLOATING_CONSTANT = 343,
    CHAR_CONSTANT = 344,
    STRING_LITERAL = 345,
    IDENTIFIER = 346,
    THEN = 347,
    WS = 348
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "ass5_21CS10014_21CS30032.y"

    int intval;
    float floatval;
    char charval;
    char* strval;
    char op;
    int nparam;
    expression* expr;
    statement* stmt;
    int bp;
    symbol* sym;
    symbol_type* symtyp;
    Array* arr;

#line 243 "ass5_21CS10014_21CS30032.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASS5_21CS10014_21CS30032_TAB_H_INCLUDED  */



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
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1329

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  228
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  407

#define YYUNDEFTOK  2
#define YYMAXUTOK   348


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    70,    71,    72,    76,    80,    84,    91,
      98,   118,   120,   126,   128,   130,   136,   142,   144,   149,
     150,   155,   159,   166,   167,   171,   175,   212,   214,   219,
     220,   221,   222,   223,   224,   228,   229,   236,   252,   265,
     278,   294,   295,   308,   324,   325,   338,   354,   355,   371,
     386,   402,   422,   423,   441,   462,   463,   482,   483,   502,
     503,   522,   523,   541,   542,   555,   556,   580,   588,   599,
     600,   621,   623,   625,   627,   629,   631,   633,   635,   637,
     639,   641,   648,   649,   653,   658,   662,   663,   668,   669,
     670,   671,   675,   676,   681,   682,   686,   687,   698,   699,
     700,   701,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   723,   724,   728,   729,   734,
     735,   736,   740,   741,   745,   746,   750,   751,   755,   756,
     757,   761,   766,   776,   780,   785,   786,   787,   788,   810,
     830,   843,   856,   857,   858,   859,   860,   861,   866,   867,
     871,   872,   876,   877,   881,   882,   886,   887,   891,   892,
     896,   897,   901,   905,   906,   907,   911,   912,   916,   917,
     922,   926,   927,   931,   932,   938,   939,   940,   945,   946,
     947,   951,   952,   953,   958,   959,   960,   964,   965,   966,
     970,   978,   979,   984,   985,   993,   994,   998,   999,  1002,
    1012,  1023,  1028,  1040,  1052,  1063,  1074,  1087,  1100,  1113,
    1129,  1133,  1137,  1141,  1153,  1168,  1169,  1170,  1171,  1176,
    1185,  1186,  1190,  1191,  1196,  1205,  1206,  1211,  1212
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INLINE", "INT", "LONG", "REGISTER", "RESTRICT",
  "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH",
  "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE", "BOOL",
  "COMPLEX", "IMAGINARY", "SQUARE_BRACKET_OPEN", "SQUARE_BRACKET_CLOSE",
  "ROUND_BRACKET_OPEN", "ROUND_BRACKET_CLOSE", "CURLY_BRACKET_OPEN",
  "CURLY_BRACKET_CLOSE", "DOT", "ARROW", "INCREMENT", "DECREMENT",
  "BITWISE_AND", "BITWISE_OR", "BITWISE_XOR", "BITWISE_NOT", "LOGICAL_AND",
  "LOGICAL_OR", "LOGICAL_NOT", "MULTIPLY", "DIVIDE", "MODULO", "PLUS",
  "MINUS", "LEFT_SHIFT", "RIGHT_SHIFT", "LESS_THAN", "GREATER_THAN",
  "LESS_THAN_EQUAL", "GREATER_THAN_EQUAL", "EQUAL", "NOT_EQUAL", "ASSIGN",
  "PLUS_ASSIGN", "MINUS_ASSIGN", "MULTIPLY_ASSIGN", "DIVIDE_ASSIGN",
  "MODULO_ASSIGN", "LEFT_SHIFT_ASSIGN", "RIGHT_SHIFT_ASSIGN",
  "BITWISE_AND_ASSIGN", "BITWISE_XOR_ASSIGN", "BITWISE_OR_ASSIGN", "COMMA",
  "COLON", "SEMICOLON", "ELLIPSIS", "QUESTION_MARK", "HASH",
  "INTEGER_CONSTANT", "FLOATING_CONSTANT", "CHAR_CONSTANT",
  "STRING_LITERAL", "IDENTIFIER", "THEN", "WS", "$accept",
  "primary_expression", "constant", "postfix_expression",
  "argument_expression_list_opt", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "AND_expression",
  "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "M", "N", "assignment_expression",
  "assignment_operator", "expression", "constant_expression",
  "declaration", "init_declarator_list_opt", "declaration_specifiers",
  "declaration_specifiers_opt", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "specifier_qualifier_list",
  "specifier_qualifier_list_opt", "enum_specifier", "identifier_opt",
  "enumerator_list", "enumerator", "type_qualifier", "function_specifier",
  "declarator", "direct_declarator", "type_qualifier_list_opt", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name", "initializer",
  "initializer_list", "designation_opt", "designation", "designator_list",
  "designator", "statement", "loop_statement", "labeled_statement",
  "compound_statement", "block_item_list_opt", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "F", "W", "D", "X", "change_table",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list_opt", "declaration_list", YY_NULLPTR
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
     345,   346,   347,   348
};
# endif

#define YYPACT_NINF (-298)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-227)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1256,  -298,  -298,  -298,  -298,   -56,  -298,  -298,  -298,  -298,
    -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,  -298,   -21,  1256,  1256,  -298,  1256,  1256,  1219,
    -298,  -298,   -26,     6,   -21,   157,  -298,   -30,   -12,  -298,
     867,   172,   -27,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
      44,   100,  -298,    98,   157,  -298,   -21,   871,  -298,   -21,
    -298,  1256,   697,    69,   172,   108,    30,  -298,  -298,  -298,
    -298,  -298,   118,  1023,   653,     9,  1073,  1073,  -298,  -298,
    -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,   334,   293,  1089,  -298,   171,   195,   196,   138,   198,
     143,   116,   122,   162,    -1,  -298,  -298,  -298,   192,  -298,
     204,  -298,   200,   203,   741,  -298,   -29,  1178,  1089,  -298,
     -20,   653,  -298,  -298,   -19,  1290,  -298,  1290,   206,  1089,
     160,    65,   871,  -298,   111,  -298,   653,  -298,  -298,  1089,
     891,   179,   185,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,  -298,  -298,  -298,  -298,  1089,  -298,  -298,  1089,
    1089,  1089,  1089,  1089,  1089,  1089,  1089,  1089,  1089,  1089,
    1089,  1089,  1089,  1089,  1089,  -298,  -298,   199,   301,   237,
     204,  -298,  -298,  1089,  -298,   240,   244,  -298,   197,  -298,
     -21,   247,   215,  -298,  -298,  -298,  -298,  -298,   254,  -298,
    1089,  -298,  -298,  -298,   941,   246,  -298,  -298,    -3,  -298,
    -298,  -298,   255,   -24,  -298,   256,   220,  -298,  -298,  -298,
    -298,  -298,  -298,  -298,   171,   171,   195,   195,   196,   196,
     196,   196,   138,   138,   198,   143,   116,  1089,  1089,  -298,
     230,  1089,   249,   248,  -298,  -298,   242,   299,   957,   300,
    -298,  -298,  -298,   262,   151,  -298,  -298,  -298,  -298,   302,
     307,  -298,  -298,  -298,  -298,  -298,  -298,   305,   312,  -298,
    -298,  -298,  -298,  -298,   830,   311,  -298,     9,  -298,  -298,
    -298,   871,   311,  -298,  -298,  1089,   122,   162,  1089,  -298,
     274,  -298,   458,   315,   318,   292,  1089,  -298,   152,  1089,
     335,  -298,   458,  -298,  -298,   301,  -298,  -298,  -298,  -298,
     104,  -298,  -298,   297,   458,  -298,  -298,   458,  -298,  -298,
     297,  -298,    -9,  -298,   301,  -298,  -298,  -298,    72,   303,
    -298,   301,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
     336,   458,  -298,   341,  -298,  -298,   342,   358,   390,  -298,
    -298,  -298,  -298,  1089,  -298,   353,  -298,  -298,   458,  1089,
    -298,   362,  1089,  1007,  1007,  -298,    -5,   357,    -4,  -298,
    -298,    21,   356,  1089,   319,  1089,  1089,  -298,  -298,  -298,
     458,     2,  -298,   297,   297,   458,   301,  -298,   323,   364,
     365,  -298,   369,  -298,  -298,  -298,  -298,   526,   594,   301,
    -298,   301,  -298,   374,   375,  -298,  -298
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   100,   103,   128,   108,   123,    98,   107,   131,   105,
     106,   101,   129,   104,   109,    99,   110,   102,   130,   111,
     112,   113,   223,    87,    93,    93,   114,    93,    93,     0,
     220,   222,   121,     0,     0,   149,   134,     0,    86,    94,
      96,   133,     0,    92,    88,    89,    90,    91,     1,   221,
       0,     0,   152,   150,   148,    85,     0,     0,   227,    87,
     214,   225,     0,   214,   132,   126,     0,   124,   135,   151,
     153,    95,    96,     0,     0,   169,     0,     0,    29,    33,
      34,    30,    31,    32,     6,     7,     8,     4,     2,     9,
       3,    23,    35,     0,    37,    41,    44,    47,    52,    55,
      57,    59,    61,    63,    65,    69,   163,    97,     0,   228,
       0,   139,    30,     0,     0,   160,     0,     0,     0,   119,
       0,     0,    27,    82,     0,   118,   162,   118,     0,     0,
       0,     0,     0,   168,     0,   171,     0,    24,    25,     0,
       0,     0,     0,    15,    16,    71,    75,    76,    72,    73,
      74,    77,    78,    79,    80,    81,     0,    35,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    67,     0,   192,     0,
       0,   147,   138,     0,   137,    30,     0,   142,     0,   141,
     159,     0,   154,   156,    84,   127,   120,   125,     0,     5,
       0,   117,   115,   116,     0,     0,   174,   164,   169,   166,
     170,   172,     0,     0,    11,     0,    19,    21,    13,    14,
      70,    38,    39,    40,    42,    43,    45,    46,    48,    49,
      50,    51,    53,    54,    56,    58,    60,     0,     0,    67,
       0,     0,     0,     0,   212,   210,     0,     0,     0,     0,
     211,   213,   198,     2,     0,   195,   196,   175,   176,     0,
      67,   193,   177,   178,   179,   180,   144,     0,     0,   146,
     136,   161,   158,   140,     0,    28,    83,   169,    36,   173,
     165,     0,     0,    10,    12,     0,    62,    64,     0,   217,
       0,   216,     0,    67,     0,     0,     0,   219,     0,     0,
       0,   214,     0,   197,   224,     0,   143,   145,   155,   157,
       0,   167,    22,    68,     0,   189,    67,     0,   213,   215,
      68,   218,     0,   213,   192,   187,   194,    17,   169,     0,
     188,   192,    67,   181,   182,   183,   184,   185,   186,   214,
       0,     0,   214,     0,    18,    67,     0,     0,     0,    67,
     201,    67,   190,     0,    67,     0,    67,    67,     0,     0,
      66,     0,     0,     0,     0,    68,     0,     0,     0,    67,
      67,     0,    67,     0,     0,     0,     0,    67,   199,    67,
       0,     0,   204,    68,    68,     0,   192,   202,     0,     0,
       0,   200,     0,   205,    67,    67,   203,     0,     0,   192,
     206,   192,   207,     0,     0,   209,   208
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -298,  -298,  -298,  -298,  -298,  -298,   -71,  -298,   -80,   106,
     107,    40,   103,   250,   253,   257,   184,   207,  -298,  -110,
    -132,  -297,    -6,  -298,   -73,  -118,     0,  -298,     3,   193,
    -298,   377,  -298,    74,   123,   308,  -298,  -298,  -298,   310,
      11,  -298,   -14,   392,  -298,   383,   -50,  -298,  -298,   163,
    -298,   -95,  -125,   164,  -198,  -298,  -298,   314,  -187,  -215,
    -258,  -239,  -257,  -298,   137,  -211,  -235,  -208,  -298,  -298,
    -298,  -204,   -59,  -201,  -298,   415,  -298,  -298,  -298
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    89,    90,    91,   215,   216,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     237,   177,   123,   156,   254,   195,   255,    37,    59,    44,
      38,    39,    24,    25,   126,   202,    26,    33,    66,    67,
      27,    28,    72,    41,    53,    42,    54,   191,   192,   193,
     116,   128,   107,   131,   132,   133,   134,   135,   256,   332,
     257,   258,   259,   260,   261,   262,   263,   264,   294,   300,
     293,   301,   108,   265,    29,    30,    31,    60,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,   124,   122,    23,   117,   137,   138,   209,   194,    40,
     281,   205,   114,   158,   187,    34,   329,   283,  -122,   194,
      51,    34,   157,   340,   199,   196,   198,    43,    43,    22,
      43,    43,    23,   377,   341,    32,    35,   129,   372,   374,
      58,   212,   280,   130,   238,   388,    52,   157,   124,   129,
      50,   106,   188,    55,   176,   130,   113,   200,   157,   333,
     180,   109,   200,   124,    36,    70,   213,   343,   371,    56,
      36,    65,   200,    52,   346,   119,   200,   200,   334,   221,
     222,   223,   336,   200,   -68,   127,   389,   390,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   179,   315,   335,   288,   186,   337,
     207,   120,   129,   378,   339,   325,   338,   344,   130,   342,
     190,    52,   333,   290,   278,    70,   106,   330,   305,   392,
     281,   194,   127,   157,   217,    65,   127,   357,   127,   333,
     333,   334,   403,    68,   404,   336,   208,   127,   125,   327,
     220,   129,   369,   370,   350,    35,   311,   130,   334,   334,
     115,   317,   336,   336,     3,   387,   157,   157,   173,   335,
     157,   365,   337,   174,   267,   298,   272,   268,   118,   338,
      12,   210,   400,   402,   331,   328,   335,   335,    57,   337,
     337,    70,    18,   172,   276,   125,   338,   338,   391,   125,
     347,   125,   166,   167,   168,   169,   228,   229,   230,   231,
     125,     3,    62,   353,    63,   313,   175,   358,    45,   359,
      46,    47,   361,   320,   363,   364,   322,    12,   159,   160,
     161,    73,   200,   200,   303,   321,   178,   375,   376,    18,
     380,   181,   324,   360,   182,   385,    74,   386,   201,   204,
     201,   206,    76,    77,    78,   162,   163,    79,   164,   165,
      80,    81,   397,   398,    82,    83,   170,   171,   224,   225,
     218,   226,   227,   232,   233,   106,   219,   190,   266,   312,
     348,   269,   157,   351,   239,   270,   366,   279,   271,   368,
     273,    84,    85,    86,    87,    88,   274,   275,   282,   284,
     381,   285,   383,   384,     1,   240,   241,     2,     3,   242,
     243,   244,     4,   289,     5,     6,     7,   245,   246,   247,
       8,     9,    10,    11,    12,   248,    13,    14,    73,    15,
     292,   249,   291,   295,    16,    17,    18,   250,    19,    20,
      21,   296,   299,    74,   302,   251,   306,   304,   356,    76,
      77,    78,  -191,   307,    79,   277,   314,    80,    81,   316,
     318,    82,    83,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   139,   319,   140,   323,   200,   349,
     141,   142,   143,   144,   252,   345,   352,   354,    84,    85,
      86,    87,   253,     1,   355,   362,     2,     3,   367,   373,
     379,     4,   382,     5,     6,     7,   393,   394,   395,     8,
       9,    10,    11,    12,   396,    13,    14,    73,    15,   405,
     406,   286,   234,    16,    17,    18,   235,    19,    20,    21,
     197,   236,    74,    71,    64,   203,    69,   309,    76,    77,
      78,   310,   326,    79,    49,   287,    80,    81,   211,     0,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   241,     0,     0,   242,   243,   244,     0,
       0,     0,     0,   252,   245,   246,   247,    84,    85,    86,
      87,    88,   248,     0,     0,    73,     0,     0,   249,     0,
       0,     0,     0,     0,   250,     0,     0,     0,     0,     0,
      74,     0,   251,     0,     0,     0,    76,    77,    78,     0,
       0,    79,     0,     0,    80,    81,     0,     0,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   241,     0,     0,   242,   243,   244,     0,     0,     0,
       0,   252,   245,   246,   247,    84,    85,    86,    87,   253,
     248,     0,     0,    73,     0,     0,   249,     0,     0,     0,
       0,     0,   250,     0,     0,     0,     0,     0,    74,     0,
     399,     0,     0,     0,    76,    77,    78,     0,     0,    79,
       0,     0,    80,    81,     0,     0,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,   241,
       0,     0,   242,   243,   244,     0,     0,     0,     0,   252,
     245,   246,   247,    84,    85,    86,    87,   253,   248,     0,
       0,    73,     0,     0,   249,     0,     0,     0,     0,     0,
     250,     0,     0,     0,     0,     0,    74,     0,   401,     0,
       0,     0,    76,    77,    78,     0,     0,    79,     0,     0,
      80,    81,     0,     0,    82,    83,     0,     0,     0,     2,
       3,     0,     0,     0,     4,     0,     5,     0,     7,     0,
       0,     0,     0,     9,    10,     0,    12,   252,    13,    14,
      73,    84,    85,    86,    87,   253,    16,    17,    18,     0,
      19,    20,    21,     0,     0,    74,     0,     0,     0,     0,
       0,    76,    77,    78,     3,     0,    79,     0,     0,    80,
      81,     0,     0,    82,    83,     0,     0,     0,     0,     0,
      12,     0,     0,     0,    73,   110,     0,     0,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,   111,    74,
      84,    85,    86,    87,    88,    76,    77,    78,     3,     0,
      79,     0,     0,    80,   112,     0,     0,    82,    83,     0,
       0,     0,     0,     0,    12,     0,     0,     0,    73,   183,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,   184,    74,    84,    85,    86,    87,    88,    76,
      77,    78,     0,     0,    79,     0,     0,    80,   185,     0,
       0,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,    87,    88,     1,     0,     0,     2,     3,     0,     0,
       0,     4,     0,     5,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,     0,    13,    14,     0,    15,     0,
       0,     0,     0,    16,    17,    18,     0,    19,    20,    21,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,     0,    13,    14,     0,    15,     0,     0,    73,     0,
      16,    17,    18,     0,    19,    20,    21,     0,     0,     0,
       0,  -226,     0,    74,   308,    75,     0,     0,    73,    76,
      77,    78,     0,     0,    79,     0,     0,    80,    81,     0,
       0,    82,    83,    74,   214,     0,     0,    57,     0,    76,
      77,    78,     0,     0,    79,     0,     0,    80,    81,     0,
       0,    82,    83,     0,     0,     0,     0,     0,    84,    85,
      86,    87,    88,     0,     0,     0,     0,     0,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,    87,    88,    74,    73,   277,     0,     0,     0,    76,
      77,    78,     0,     0,    79,     0,     0,    80,    81,    74,
       0,    82,    83,     0,     0,    76,    77,    78,     0,     0,
      79,     0,     0,    80,    81,     0,     0,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,    87,    88,     0,    73,     0,     0,     0,     0,     0,
     297,     0,     0,     0,    84,    85,    86,    87,    88,    74,
      73,     0,     0,     0,     0,    76,    77,    78,     0,     0,
      79,     0,     0,    80,    81,   121,     0,    82,    83,     0,
       0,    76,    77,    78,     0,     0,    79,     0,     0,    80,
      81,     0,     0,    82,    83,     0,     0,     0,     0,     0,
     252,     0,     0,     0,    84,    85,    86,    87,    88,     0,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,    86,    87,    88,   136,    73,     0,     0,     0,
       0,    76,    77,    78,     0,     0,    79,     0,     0,    80,
      81,    74,     0,    82,    83,     0,     0,    76,    77,    78,
       0,     0,    79,     0,     0,    80,    81,     0,     0,    82,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,    86,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,     0,    13,    14,     0,    15,     0,     0,     0,
       0,    16,    17,    18,     0,    19,    20,    21,     0,    48,
       0,   189,     1,     0,     0,     2,     3,     0,     0,     0,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,     0,    13,    14,     0,    15,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21,     1,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     5,
       6,     7,     0,     0,     0,     8,     9,    10,    11,    12,
       0,    13,    14,     0,    15,     0,     0,     0,     0,    16,
      17,    18,     0,    19,    20,    21,     2,     3,     0,     0,
       0,     4,     0,     5,     0,     7,     0,     0,     0,     0,
       9,    10,     0,    12,     0,    13,    14,     0,     0,     0,
       0,     0,     0,    16,    17,    18,     0,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    74,    73,     0,    63,    76,    77,   132,   118,    23,
     208,   129,    62,    93,    43,    42,   313,    41,    44,   129,
      34,    42,    93,   320,    43,    45,   121,    24,    25,    29,
      27,    28,    29,    12,    43,    91,    57,    40,    43,    43,
      40,   136,    45,    46,   176,    43,    35,   118,   121,    40,
      44,    57,    81,    83,    55,    46,    62,    81,   129,   317,
     110,    61,    81,   136,    91,    54,   139,   324,   365,    81,
      91,    91,    81,    62,   331,    45,    81,    81,   317,   159,
     160,   161,   317,    81,    85,    74,   383,   384,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   110,   292,   317,   239,   114,   317,
      45,    81,    40,    92,   318,   302,   317,    45,    46,   323,
     117,   110,   380,   241,   204,   114,   132,   314,   260,   386,
     328,   241,   121,   204,   140,    91,   125,   348,   127,   397,
     398,   380,   399,    43,   401,   380,    81,   136,    74,    45,
     156,    40,   363,   364,   341,    57,   281,    46,   397,   398,
      91,   293,   397,   398,     7,   380,   237,   238,    52,   380,
     241,   358,   380,    51,   180,   248,   190,   183,    70,   380,
      23,    70,   397,   398,   316,    81,   397,   398,    70,   397,
     398,   180,    35,    50,   200,   121,   397,   398,   385,   125,
     332,   127,    64,    65,    66,    67,   166,   167,   168,   169,
     136,     7,    40,   345,    42,   288,    54,   349,    25,   351,
      27,    28,   354,   296,   356,   357,   299,    23,    57,    58,
      59,    27,    81,    81,    83,    83,    44,   369,   370,    35,
     372,    41,   301,   353,    41,   377,    42,   379,   125,    43,
     127,    91,    48,    49,    50,    60,    61,    53,    62,    63,
      56,    57,   394,   395,    60,    61,    68,    69,   162,   163,
      91,   164,   165,   170,   171,   281,    91,   274,    41,   285,
     339,    41,   353,   342,    85,    41,   359,    41,    91,   362,
      43,    87,    88,    89,    90,    91,    81,    43,    43,    43,
     373,    81,   375,   376,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    83,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      82,    30,    83,    91,    33,    34,    35,    36,    37,    38,
      39,    42,    42,    42,    82,    44,    41,    45,   348,    48,
      49,    50,    45,    41,    53,    44,    82,    56,    57,    44,
      42,    60,    61,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    40,    83,    42,    42,    81,    43,
      46,    47,    48,    49,    83,    82,    45,    45,    87,    88,
      89,    90,    91,     3,    36,    42,     6,     7,    36,    42,
      44,    11,    83,    13,    14,    15,    83,    43,    43,    19,
      20,    21,    22,    23,    45,    25,    26,    27,    28,    45,
      45,   237,   172,    33,    34,    35,   173,    37,    38,    39,
     120,   174,    42,    56,    42,   127,    53,   274,    48,    49,
      50,   277,   305,    53,    29,   238,    56,    57,   134,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,    -1,     8,     9,    10,    -1,
      -1,    -1,    -1,    83,    16,    17,    18,    87,    88,    89,
      90,    91,    24,    -1,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    44,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,    53,    -1,    -1,    56,    57,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,    -1,     8,     9,    10,    -1,    -1,    -1,
      -1,    83,    16,    17,    18,    87,    88,    89,    90,    91,
      24,    -1,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      44,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    53,
      -1,    -1,    56,    57,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,    -1,     8,     9,    10,    -1,    -1,    -1,    -1,    83,
      16,    17,    18,    87,    88,    89,    90,    91,    24,    -1,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    44,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    53,    -1,    -1,
      56,    57,    -1,    -1,    60,    61,    -1,    -1,    -1,     6,
       7,    -1,    -1,    -1,    11,    -1,    13,    -1,    15,    -1,
      -1,    -1,    -1,    20,    21,    -1,    23,    83,    25,    26,
      27,    87,    88,    89,    90,    91,    33,    34,    35,    -1,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,     7,    -1,    53,    -1,    -1,    56,
      57,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    41,    42,
      87,    88,    89,    90,    91,    48,    49,    50,     7,    -1,
      53,    -1,    -1,    56,    57,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    41,    42,    87,    88,    89,    90,    91,    48,
      49,    50,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,     3,    -1,    -1,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,    39,
       3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    -1,    25,    26,    -1,    28,    -1,    -1,    27,    -1,
      33,    34,    35,    -1,    37,    38,    39,    -1,    -1,    -1,
      -1,    44,    -1,    42,    84,    44,    -1,    -1,    27,    48,
      49,    50,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,
      -1,    60,    61,    42,    43,    -1,    -1,    70,    -1,    48,
      49,    50,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    42,    27,    44,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    53,    -1,    -1,    56,    57,    42,
      -1,    60,    61,    -1,    -1,    48,    49,    50,    -1,    -1,
      53,    -1,    -1,    56,    57,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    91,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    87,    88,    89,    90,    91,    42,
      27,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      53,    -1,    -1,    56,    57,    42,    -1,    60,    61,    -1,
      -1,    48,    49,    50,    -1,    -1,    53,    -1,    -1,    56,
      57,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    87,    88,    89,    90,    91,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    42,    27,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    -1,    53,    -1,    -1,    56,
      57,    42,    -1,    60,    61,    -1,    -1,    48,    49,    50,
      -1,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    37,    38,    39,    -1,     0,
      -1,    43,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39,     3,
      -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      -1,    25,    26,    -1,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    -1,    37,    38,    39,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,    -1,
      20,    21,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    22,    23,    25,    26,    28,    33,    34,    35,    37,
      38,    39,   120,   122,   126,   127,   130,   134,   135,   168,
     169,   170,    91,   131,    42,    57,    91,   121,   124,   125,
     136,   137,   139,   122,   123,   123,   123,   123,     0,   169,
      44,   136,   134,   138,   140,    83,    81,    70,   120,   122,
     171,   172,    40,    42,   137,    91,   132,   133,    43,   139,
     134,   125,   136,    27,    42,    44,    48,    49,    50,    53,
      56,    57,    60,    61,    87,    88,    89,    90,    91,    95,
      96,    97,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   116,   146,   166,   120,
      28,    41,    57,   116,   140,    91,   144,   166,    70,    45,
      81,    42,   100,   116,   118,   127,   128,   134,   145,    40,
      46,   147,   148,   149,   150,   151,    42,   100,   100,    40,
      42,    46,    47,    48,    49,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   117,   100,   102,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    50,    52,    51,    54,    55,   115,    44,   116,
     140,    41,    41,    28,    41,    57,   116,    43,    81,    43,
     122,   141,   142,   143,   113,   119,    45,   133,   145,    43,
      81,   128,   129,   129,    43,   119,    91,    45,    81,   146,
      70,   151,   145,   118,    43,    98,    99,   116,    91,    91,
     116,   102,   102,   102,   103,   103,   104,   104,   105,   105,
     105,   105,   106,   106,   107,   108,   109,   114,   114,    85,
       4,     5,     8,     9,    10,    16,    17,    18,    24,    30,
      36,    44,    83,    91,   118,   120,   152,   154,   155,   156,
     157,   158,   159,   160,   161,   167,    41,   116,   116,    41,
      41,    91,   136,    43,    81,    43,   116,    44,   102,    41,
      45,   148,    43,    41,    43,    81,   110,   111,   114,    83,
     119,    83,    82,   164,   162,    91,    42,    83,   118,    42,
     163,   165,    82,    83,    45,   114,    41,    41,    84,   143,
     147,   146,   116,   118,    82,   152,    44,   114,    42,    83,
     118,    83,   118,    42,   166,   152,   158,    45,    81,   115,
     152,   114,   153,   154,   155,   159,   160,   161,   167,   165,
     115,    43,   165,   156,    45,    82,   156,   114,   166,    43,
     152,   166,    45,   114,    45,    36,   120,   159,   114,   114,
     113,   114,    42,   114,   114,   152,   118,    36,   118,   159,
     159,   115,    43,    42,    43,   114,   114,    12,    92,    44,
     114,   118,    83,   118,   118,   114,   114,   153,    43,   115,
     115,   152,   156,    83,    43,    43,    45,   114,   114,    44,
     153,    44,   153,   156,   156,    45,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    95,    95,    96,    96,    96,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
      98,    99,    99,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   101,   101,   102,   102,   103,   103,   103,
     103,   104,   104,   104,   105,   105,   105,   106,   106,   106,
     106,   106,   107,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   115,   116,
     116,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   118,   118,   119,   120,   121,   121,   122,   122,
     122,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     126,   126,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   128,   128,   129,   129,   130,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   134,
     134,   135,   136,   136,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   138,   138,
     139,   139,   140,   140,   141,   141,   142,   142,   143,   143,
     144,   144,   145,   146,   146,   146,   147,   147,   148,   148,
     149,   150,   150,   151,   151,   152,   152,   152,   152,   152,
     152,   153,   153,   153,   153,   153,   153,   154,   154,   154,
     155,   156,   156,   157,   157,   158,   158,   159,   159,   160,
     160,   160,   161,   161,   161,   161,   161,   161,   161,   161,
     162,   163,   164,   165,   166,   167,   167,   167,   167,   167,
     168,   168,   169,   169,   170,   171,   171,   172,   172
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       4,     3,     4,     3,     3,     2,     2,     6,     7,     1,
       0,     1,     3,     1,     2,     2,     2,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     4,     1,     4,     1,     9,     0,     0,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     0,     2,     2,
       2,     2,     1,     0,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     0,     5,
       6,     2,     1,     0,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     3,     5,     4,     4,     3,
       5,     4,     4,     6,     5,     6,     5,     4,     1,     0,
       2,     3,     1,     2,     1,     3,     1,     3,     2,     1,
       1,     3,     1,     1,     3,     4,     2,     4,     1,     0,
       2,     1,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       5,     1,     0,     1,     3,     1,     1,     2,     1,     9,
      11,     5,    10,    12,    10,    12,    14,    14,    16,    16,
       0,     0,     0,     0,     0,     3,     2,     2,     3,     2,
       1,     2,     1,     1,     7,     1,     0,     1,     2
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
      int yyn = yypact[+*yyssp];
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
      yychar = yylex ();
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
#line 69 "ass5_21CS10014_21CS30032.y"
                 { (yyval.expr) = new expression(); (yyval.expr)->loc = (yyvsp[0].sym) ; (yyval.expr)->type = "non_bool"; }
#line 1927 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 3:
#line 70 "ass5_21CS10014_21CS30032.y"
               { (yyval.expr) = new expression(); (yyval.expr)->loc = (yyvsp[0].sym) ; }
#line 1933 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 4:
#line 71 "ass5_21CS10014_21CS30032.y"
                     { (yyval.expr) = new expression() ; (yyval.expr)->loc = symbol_table :: gentemp(new symbol_type("ptr"),(yyvsp[0].strval)); (yyval.expr)->loc->type->ptr = new symbol_type("char"); }
#line 1939 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 5:
#line 72 "ass5_21CS10014_21CS30032.y"
                                                        { (yyval.expr) = (yyvsp[-1].expr) ; }
#line 1945 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 6:
#line 76 "ass5_21CS10014_21CS30032.y"
                       {
        (yyval.sym) = symbol_table :: gentemp(new symbol_type("int"),int2string((yyvsp[0].intval)));
        emit("=",(yyval.sym)->name,(yyvsp[0].intval));
    }
#line 1954 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 7:
#line 80 "ass5_21CS10014_21CS30032.y"
                        { 
        (yyval.sym) = symbol_table :: gentemp(new symbol_type("float"),string((yyvsp[0].strval)));
        emit("=",(yyval.sym)->name,(yyvsp[0].strval));
     }
#line 1963 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 8:
#line 84 "ass5_21CS10014_21CS30032.y"
                    {
        (yyval.sym) = symbol_table :: gentemp(new symbol_type("char"),string((yyvsp[0].strval)));
        emit("=",(yyval.sym)->name,(yyvsp[0].strval));
    }
#line 1972 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 9:
#line 91 "ass5_21CS10014_21CS30032.y"
                         {
        (yyval.arr) = new Array();
        (yyval.arr)->arr = (yyvsp[0].expr)->loc;
        (yyval.arr)->type = (yyvsp[0].expr)->loc->type;
        (yyval.arr)->loc = (yyval.arr)->arr;

    }
#line 1984 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 10:
#line 98 "ass5_21CS10014_21CS30032.y"
                                                                             {
        (yyval.arr) = new Array();
        (yyval.arr)->type = (yyvsp[-3].arr)->type->ptr;
        (yyval.arr)->arr = (yyvsp[-3].arr)->arr;
        (yyval.arr)->loc = symbol_table :: gentemp(new symbol_type("int"));
        (yyval.arr)->arrtype = "arr";

        if((yyvsp[-3].arr)->arrtype == "arr")
        {
            symbol * symb = symbol_table :: gentemp(new symbol_type("int"));
            int size  = getsize((yyval.arr)->type);
            emit("+",symb->name,(yyvsp[-1].expr)->loc->name,int2string(size));
            emit("+",(yyval.arr)->loc->name,(yyvsp[-3].arr)->loc->name,symb->name);
        }
        else 
        {
            int size = getsize((yyval.arr)->type);
            emit("+",(yyval.arr)->loc->name,(yyvsp[-1].expr)->loc->name,int2string(size));
        }
    }
#line 2009 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 11:
#line 119 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2015 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 12:
#line 120 "ass5_21CS10014_21CS30032.y"
                                                                                             { 
        // Corresponds to calling a function with the  function name and the appropriate number of parameters
        (yyval.arr) = new Array();
        (yyval.arr)->arr = symbol_table :: gentemp((yyvsp[-3].arr)->type);
        emit("call",(yyval.arr)->arr->name,(yyvsp[-3].arr)->arr->name,int2string((yyvsp[-1].nparam)));
    }
#line 2026 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 13:
#line 127 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2032 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 14:
#line 129 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2038 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 15:
#line 130 "ass5_21CS10014_21CS30032.y"
                                   {
        (yyval.arr) = new Array();
        (yyval.arr)->arr = symbol_table :: gentemp((yyvsp[-1].arr)->arr->type);
        emit("=",(yyval.arr)->arr->name,(yyvsp[-1].arr)->arr->name);
        emit("+",(yyvsp[-1].arr)->arr->name,(yyvsp[-1].arr)->arr->name,"1");
    }
#line 2049 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 16:
#line 136 "ass5_21CS10014_21CS30032.y"
                                   {
        (yyval.arr) = new Array();
        (yyval.arr)->arr = symbol_table :: gentemp((yyvsp[-1].arr)->arr->type);
        emit("=",(yyval.arr)->arr->name,(yyvsp[-1].arr)->arr->name);
        emit("-",(yyvsp[-1].arr)->arr->name,(yyvsp[-1].arr)->arr->name,"1");
    }
#line 2060 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 17:
#line 143 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2066 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 18:
#line 145 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2072 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 19:
#line 149 "ass5_21CS10014_21CS30032.y"
                               {(yyval.nparam) = (yyvsp[0].nparam);}
#line 2078 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 20:
#line 151 "ass5_21CS10014_21CS30032.y"
    { (yyval.nparam) = 0; }
#line 2084 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 21:
#line 155 "ass5_21CS10014_21CS30032.y"
                            {
        (yyval.nparam) = 1;
        emit("param",(yyvsp[0].expr)->loc->name);
    }
#line 2093 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 22:
#line 159 "ass5_21CS10014_21CS30032.y"
                                                           { 
        (yyval.nparam) = (yyvsp[-2].nparam) + 1;
        emit("param",(yyvsp[0].expr)->loc->name);
    }
#line 2102 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 23:
#line 166 "ass5_21CS10014_21CS30032.y"
                         {(yyval.arr) = (yyvsp[0].arr);}
#line 2108 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 24:
#line 167 "ass5_21CS10014_21CS30032.y"
                                 {
        emit("+",(yyvsp[0].arr)->arr->name,(yyvsp[0].arr)->arr->name,"1");
        (yyval.arr) = (yyvsp[0].arr);
    }
#line 2117 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 25:
#line 171 "ass5_21CS10014_21CS30032.y"
                                 {
        emit("-",(yyvsp[0].arr)->arr->name,(yyvsp[0].arr)->arr->name,"1");
        (yyval.arr) = (yyvsp[0].arr);
    }
#line 2126 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 26:
#line 175 "ass5_21CS10014_21CS30032.y"
                                     {
        (yyval.arr) = new Array();
        switch((yyvsp[-1].op))
        {
            case '&' : 
                (yyval.arr)->arr = symbol_table :: gentemp(new symbol_type("ptr"));
                (yyval.arr)->arr->type->ptr = (yyvsp[0].arr)->arr->type;
                emit("= &",(yyval.arr)->arr->name,(yyvsp[0].arr)->arr->name);
                break;
            
            case '*' :
                (yyval.arr)->arrtype = "ptr" ;
                (yyval.arr)->loc = symbol_table :: gentemp((yyvsp[0].arr)->arr->type->ptr);
                (yyval.arr)->arr = (yyvsp[0].arr)->arr;
                emit("= *",(yyval.arr)->loc->name,(yyvsp[0].arr)->arr->name);
                break;
            
            case '+' :
                (yyval.arr) = (yyvsp[0].arr);
                break;

            case '-' :
                (yyval.arr)->arr = symbol_table :: gentemp((yyvsp[0].arr)->arr->type->ptr);
                emit("= -",(yyval.arr)->arr->name,(yyvsp[0].arr)->arr->name);
                break;

            case '~' :
                (yyval.arr)->arr = symbol_table :: gentemp((yyvsp[0].arr)->arr->type->ptr);
                emit("= ~",(yyval.arr)->arr->name,(yyvsp[0].arr)->arr->name);
                break;
            
            case '!' :
                (yyval.arr)->arr = symbol_table :: gentemp((yyvsp[0].arr)->arr->type->ptr);
                emit("= !",(yyval.arr)->arr->name,(yyvsp[0].arr)->arr->name);
                break;
        }
    }
#line 2168 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 27:
#line 213 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2174 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 28:
#line 215 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2180 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 29:
#line 219 "ass5_21CS10014_21CS30032.y"
                  { (yyval.op) = '&'; }
#line 2186 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 30:
#line 220 "ass5_21CS10014_21CS30032.y"
               { (yyval.op) = '*';}
#line 2192 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 31:
#line 221 "ass5_21CS10014_21CS30032.y"
           { (yyval.op) = '+';}
#line 2198 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 32:
#line 222 "ass5_21CS10014_21CS30032.y"
            { (yyval.op) = '-';}
#line 2204 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 33:
#line 223 "ass5_21CS10014_21CS30032.y"
                  { (yyval.op) = '~';}
#line 2210 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 34:
#line 224 "ass5_21CS10014_21CS30032.y"
                  { (yyval.op) = '!';}
#line 2216 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 35:
#line 228 "ass5_21CS10014_21CS30032.y"
                       { (yyval.arr) = (yyvsp[0].arr); }
#line 2222 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 36:
#line 229 "ass5_21CS10014_21CS30032.y"
                                                                       {
        (yyval.arr) = new Array() ;
        (yyval.arr)->arr = convertType((yyvsp[0].arr)->arr,typevar);
    }
#line 2231 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 37:
#line 236 "ass5_21CS10014_21CS30032.y"
                      {
        (yyval.expr) = new expression();
        if((yyvsp[0].arr)->arrtype == "arr")
        {
            (yyval.expr)->loc = symbol_table :: gentemp((yyvsp[0].arr)->loc->type);
            emit("=[]",(yyval.expr)->loc->name,(yyvsp[0].arr)->arr->name,(yyvsp[0].arr)->loc->name);
        }
        else if((yyvsp[0].arr)->arrtype == "ptr")
        {
            (yyval.expr)->loc = (yyvsp[0].arr)->arr;
        }
        else 
        {
            (yyval.expr)->loc = (yyvsp[0].arr)->arr;
        }
    }
#line 2252 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 38:
#line 252 "ass5_21CS10014_21CS30032.y"
                                                         {
        
        if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].arr)->arr))
        {
            (yyval.expr) = new expression();
            (yyval.expr)->loc = symbol_table :: gentemp(new symbol_type((yyvsp[-2].expr)->loc->type->type));
            emit("*",(yyval.expr)->loc->name,(yyvsp[-2].expr)->loc->name,(yyvsp[0].arr)->arr->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2270 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 39:
#line 265 "ass5_21CS10014_21CS30032.y"
                                                       {
        
        if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].arr)->arr))
        {
            (yyval.expr) = new expression();
            (yyval.expr)->loc = symbol_table :: gentemp(new symbol_type((yyvsp[-2].expr)->loc->type->type));
            emit("/",(yyval.expr)->loc->name,(yyvsp[-2].expr)->loc->name,(yyvsp[0].arr)->arr->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2288 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 40:
#line 278 "ass5_21CS10014_21CS30032.y"
                                                       {
        
        if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].arr)->arr))
        {
            (yyval.expr) = new expression();
            (yyval.expr)->loc = symbol_table :: gentemp(new symbol_type((yyvsp[-2].expr)->loc->type->type));
            emit("%",(yyval.expr)->loc->name,(yyvsp[-2].expr)->loc->name,(yyvsp[0].arr)->arr->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2306 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 41:
#line 294 "ass5_21CS10014_21CS30032.y"
                                { (yyval.expr)=(yyvsp[0].expr); }
#line 2312 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 42:
#line 295 "ass5_21CS10014_21CS30032.y"
                                                         {

        if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc))
        {
            (yyval.expr) = new expression();
            (yyval.expr)->loc = symbol_table :: gentemp(new symbol_type((yyvsp[-2].expr)->loc->type->type));
            emit("+",(yyval.expr)->loc->name,(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2330 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 43:
#line 308 "ass5_21CS10014_21CS30032.y"
                                                          {
        
        if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc))
        {
            (yyval.expr) = new expression();
            (yyval.expr)->loc = symbol_table :: gentemp(new symbol_type((yyvsp[-2].expr)->loc->type->type));
            emit("-",(yyval.expr)->loc->name,(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2348 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 44:
#line 324 "ass5_21CS10014_21CS30032.y"
                          { (yyval.expr)=(yyvsp[0].expr); }
#line 2354 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 45:
#line 325 "ass5_21CS10014_21CS30032.y"
                                                      {
        
        if((yyvsp[0].expr)->loc->type->type == "int")
        {
            (yyval.expr) = new expression();
            (yyval.expr)->loc = symbol_table :: gentemp(new symbol_type("int"));
            emit("<<",(yyval.expr)->loc->name,(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2372 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 46:
#line 338 "ass5_21CS10014_21CS30032.y"
                                                       {
        
        if((yyvsp[0].expr)->loc->type->type == "int")
        {
            (yyval.expr) = new expression();
            (yyval.expr)->loc = symbol_table :: gentemp(new symbol_type("int"));
            emit(">>",(yyval.expr)->loc->name,(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2390 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 47:
#line 354 "ass5_21CS10014_21CS30032.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 2396 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 48:
#line 356 "ass5_21CS10014_21CS30032.y"
    {
        if(typecheck((yyvsp[-2].expr)->loc ,(yyvsp[0].expr)->loc))
        {
            (yyval.expr) = new expression();
            (yyval.expr)->type = "bool";
            (yyval.expr)->truelist = makelist(nextinstr());
            (yyval.expr)->falselist = makelist(nextinstr()+1);
            emit("<","",(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
            emit("goto","");
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2416 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 49:
#line 371 "ass5_21CS10014_21CS30032.y"
                                                          { 
        if(typecheck((yyvsp[-2].expr)->loc ,(yyvsp[0].expr)->loc))
        {
            (yyval.expr) = new expression();
            (yyval.expr)->type = "bool";
            (yyval.expr)->truelist = makelist(nextinstr());
            (yyval.expr)->falselist = makelist(nextinstr()+1);
            emit(">","",(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
            emit("goto","");
        }
        else 
        {
            yyerror("Type mismatch");
        }
     }
#line 2436 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 50:
#line 386 "ass5_21CS10014_21CS30032.y"
                                                             {
        if(typecheck((yyvsp[-2].expr)->loc ,(yyvsp[0].expr)->loc))
        {
            (yyval.expr) = new expression();
            (yyval.expr)->type = "bool";
            (yyval.expr)->truelist = makelist(nextinstr());
            (yyval.expr)->falselist = makelist(nextinstr()+1);
            emit("<=","",(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
            emit("goto","");
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2456 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 51:
#line 403 "ass5_21CS10014_21CS30032.y"
    {
        if(typecheck((yyvsp[-2].expr)->loc ,(yyvsp[0].expr)->loc))
        {
            (yyval.expr) = new expression();
            (yyval.expr)->type = "bool";
            (yyval.expr)->truelist = makelist(nextinstr());
            (yyval.expr)->falselist = makelist(nextinstr()+1);
            emit(">=","",(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
            emit("goto","");
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2476 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 52:
#line 422 "ass5_21CS10014_21CS30032.y"
                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2482 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 53:
#line 423 "ass5_21CS10014_21CS30032.y"
                                                      {
        
        if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc))
        {
            convertBool2Int((yyvsp[-2].expr));
            convertBool2Int((yyvsp[0].expr));
            (yyval.expr) = new expression();
            (yyval.expr)->type = "bool";
            (yyval.expr)->truelist = makelist(nextinstr());
            (yyval.expr)->falselist = makelist(nextinstr()+1);
            emit("==","",(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
            emit("goto","");
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2505 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 54:
#line 441 "ass5_21CS10014_21CS30032.y"
                                                          {
        
        if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc))
        {
            convertBool2Int((yyvsp[-2].expr));
            convertBool2Int((yyvsp[0].expr));
            (yyval.expr) = new expression();
            (yyval.expr)->type = "bool";
            (yyval.expr)->truelist = makelist(nextinstr());
            (yyval.expr)->falselist = makelist(nextinstr()+1);
            emit("!=","",(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
            emit("goto","");
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2528 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 55:
#line 462 "ass5_21CS10014_21CS30032.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 2534 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 56:
#line 463 "ass5_21CS10014_21CS30032.y"
                                                     { 
        
        if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc))
        {
            convertBool2Int((yyvsp[-2].expr));
            convertBool2Int((yyvsp[0].expr));
            (yyval.expr) = new expression();
            (yyval.expr)->type = "not_bool";
            (yyval.expr)->loc = symbol_table :: gentemp(new symbol_type("int"));
            emit("&",(yyval.expr)->loc->name,(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2555 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 57:
#line 482 "ass5_21CS10014_21CS30032.y"
                     { (yyval.expr) = (yyvsp[0].expr); }
#line 2561 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 58:
#line 483 "ass5_21CS10014_21CS30032.y"
                                                         {
        
        if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc))
        {
            convertBool2Int((yyvsp[-2].expr));
            convertBool2Int((yyvsp[0].expr));
            (yyval.expr) = new expression();
            (yyval.expr)->type = "not_bool";
            (yyval.expr)->loc = symbol_table :: gentemp(new symbol_type("int"));
            emit("^",(yyval.expr)->loc->name,(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2582 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 59:
#line 502 "ass5_21CS10014_21CS30032.y"
                              {(yyval.expr) = (yyvsp[0].expr);}
#line 2588 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 60:
#line 503 "ass5_21CS10014_21CS30032.y"
                                                                 {
        
        if(typecheck((yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc))
        {
            convertBool2Int((yyvsp[-2].expr));
            convertBool2Int((yyvsp[0].expr));
            (yyval.expr) = new expression();
            (yyval.expr)->type = "not_bool";
            (yyval.expr)->loc = symbol_table :: gentemp(new symbol_type("int"));
            emit("|",(yyval.expr)->loc->name,(yyvsp[-2].expr)->loc->name,(yyvsp[0].expr)->loc->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
#line 2609 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 61:
#line 522 "ass5_21CS10014_21CS30032.y"
                              { (yyval.expr) = (yyvsp[0].expr); }
#line 2615 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 62:
#line 523 "ass5_21CS10014_21CS30032.y"
                                                                   {
        
        /* 
            here we have made few changes to the grammar to incorporate non terminal M to handle backpatching
        */

        convertBool2Int((yyvsp[-3].expr));
        convertBool2Int((yyvsp[0].expr));
        (yyval.expr) = new expression();
        (yyval.expr)->type = "bool";
        backpatch((yyvsp[-3].expr)->truelist,(yyvsp[-1].bp));
        (yyval.expr)->truelist = (yyvsp[0].expr)->truelist;
        (yyval.expr)->falselist = merge((yyvsp[-3].expr)->falselist,(yyvsp[0].expr)->falselist);

    }
#line 2635 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 63:
#line 541 "ass5_21CS10014_21CS30032.y"
                             { (yyval.expr) = (yyvsp[0].expr); }
#line 2641 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 64:
#line 542 "ass5_21CS10014_21CS30032.y"
                                                                {
        
        convertBool2Int((yyvsp[-3].expr));
        convertBool2Int((yyvsp[0].expr));
        (yyval.expr) = new expression();
        (yyval.expr)->type = "bool";
        backpatch((yyvsp[-3].expr)->falselist,(yyvsp[-1].bp));
        (yyval.expr)->truelist = merge((yyvsp[-3].expr)->truelist,(yyvsp[0].expr)->truelist);
        (yyval.expr)->falselist = (yyvsp[0].expr)->falselist;
    }
#line 2656 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 65:
#line 555 "ass5_21CS10014_21CS30032.y"
                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2662 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 66:
#line 556 "ass5_21CS10014_21CS30032.y"
                                                                                          {
        
        /* 
            here we have made few changes to the grammar to incorporate non terminal N and M to handle backpatching
        */

        (yyval.expr)->loc = symbol_table :: gentemp((yyvsp[-4].expr)->loc->type);
        (yyval.expr)->loc->update((yyvsp[-4].expr)->loc->type);
        emit("=", (yyval.expr)->loc->name, (yyvsp[0].expr)->loc->name);
        list<int> l1 = makelist(nextinstr());
        emit("goto", "");
        backpatch((yyvsp[-3].stmt)->nextlist, nextinstr());
        emit("=", (yyval.expr)->loc->name, (yyvsp[-4].expr)->loc->name);
        list<int> l2 = makelist(nextinstr());
        l1=merge(l1,l2);
        emit("goto", "");
        backpatch((yyvsp[-7].stmt)->nextlist, nextinstr());
        convertInt2Bool((yyvsp[-8].expr));
        backpatch((yyvsp[-8].expr)->truelist,(yyvsp[-5].bp));
        backpatch((yyvsp[-8].expr)->falselist,(yyvsp[-1].bp));
        backpatch(l1,nextinstr());
    }
#line 2689 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 67:
#line 581 "ass5_21CS10014_21CS30032.y"
    {
        // keeps track of the next instruction and is useful in backpatching

        (yyval.bp) = nextinstr();
    }
#line 2699 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 68:
#line 589 "ass5_21CS10014_21CS30032.y"
    {
        // helps in the handling control flow

        (yyval.stmt) = new statement();
        (yyval.stmt)->nextlist = makelist(nextinstr());
        emit("goto","");
    }
#line 2711 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 69:
#line 599 "ass5_21CS10014_21CS30032.y"
                             { (yyval.expr) = (yyvsp[0].expr); }
#line 2717 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 70:
#line 600 "ass5_21CS10014_21CS30032.y"
                                                                 {
        
        if((yyvsp[-2].arr)->arrtype == "arr")
        {
            (yyvsp[0].expr)->loc = convertType((yyvsp[0].expr)->loc,(yyvsp[-2].arr)->type->type);
            emit("[]=", (yyvsp[-2].arr)->arr->name,(yyvsp[-2].arr)->loc->name,(yyvsp[0].expr)->loc->name);
        }
        else if((yyvsp[-2].arr)->arrtype == "ptr")
        {
            emit("*=", (yyvsp[-2].arr)->arr->name,(yyvsp[0].expr)->loc->name);
        }
        else 
        {
            (yyvsp[0].expr)->loc = convertType((yyvsp[0].expr)->loc,(yyvsp[-2].arr)->arr->type->type);
            emit("=", (yyvsp[-2].arr)->arr->name,(yyvsp[0].expr)->loc->name);
        }
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2740 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 71:
#line 622 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2746 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 72:
#line 624 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2752 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 73:
#line 626 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2758 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 74:
#line 628 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2764 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 75:
#line 630 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2770 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 76:
#line 632 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2776 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 77:
#line 634 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2782 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 78:
#line 636 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2788 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 79:
#line 638 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2794 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 80:
#line 640 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2800 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 81:
#line 642 "ass5_21CS10014_21CS30032.y"
    { /* nothin */}
#line 2806 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 82:
#line 648 "ass5_21CS10014_21CS30032.y"
                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2812 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 83:
#line 649 "ass5_21CS10014_21CS30032.y"
                                             { /* No Action Taken */ }
#line 2818 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 84:
#line 653 "ass5_21CS10014_21CS30032.y"
                             { /* No Action Taken */ }
#line 2824 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 85:
#line 658 "ass5_21CS10014_21CS30032.y"
                                                                { /* No Action Taken */ }
#line 2830 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 86:
#line 662 "ass5_21CS10014_21CS30032.y"
                           { /* No Action Taken */ }
#line 2836 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 87:
#line 664 "ass5_21CS10014_21CS30032.y"
    { /* No Action Taken */ }
#line 2842 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 88:
#line 668 "ass5_21CS10014_21CS30032.y"
                                                         { /* No Action Taken */ }
#line 2848 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 89:
#line 669 "ass5_21CS10014_21CS30032.y"
                                                { /* No Action Taken */ }
#line 2854 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 90:
#line 670 "ass5_21CS10014_21CS30032.y"
                                                { /* No Action Taken */ }
#line 2860 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 91:
#line 671 "ass5_21CS10014_21CS30032.y"
                                                    { /* No Action Taken */ }
#line 2866 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 92:
#line 675 "ass5_21CS10014_21CS30032.y"
                             { /* No Action Taken */ }
#line 2872 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 93:
#line 677 "ass5_21CS10014_21CS30032.y"
    { /* No Action Taken */ }
#line 2878 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 94:
#line 681 "ass5_21CS10014_21CS30032.y"
                      { /* No Action Taken */ }
#line 2884 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 95:
#line 682 "ass5_21CS10014_21CS30032.y"
                                                 { /* No Action Taken */ }
#line 2890 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 96:
#line 686 "ass5_21CS10014_21CS30032.y"
                 { (yyval.sym) = (yyvsp[0].sym); }
#line 2896 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 97:
#line 688 "ass5_21CS10014_21CS30032.y"
    {
        if ((yyvsp[0].sym)->value != "")
        {
            (yyvsp[-2].sym)->value = (yyvsp[0].sym)->value;
        }
        emit("=", (yyvsp[-2].sym)->name, (yyvsp[0].sym)->name);
    }
#line 2908 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 98:
#line 698 "ass5_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 2914 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 99:
#line 699 "ass5_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 2920 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 100:
#line 700 "ass5_21CS10014_21CS30032.y"
           { /* No Action Taken */ }
#line 2926 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 101:
#line 701 "ass5_21CS10014_21CS30032.y"
               { /* No Action Taken */ }
#line 2932 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 102:
#line 707 "ass5_21CS10014_21CS30032.y"
           { typevar = "void"; }
#line 2938 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 103:
#line 708 "ass5_21CS10014_21CS30032.y"
           { typevar = "char"; }
#line 2944 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 104:
#line 709 "ass5_21CS10014_21CS30032.y"
            { /* No Action Taken */ }
#line 2950 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 105:
#line 710 "ass5_21CS10014_21CS30032.y"
          { typevar = "int"; }
#line 2956 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 106:
#line 711 "ass5_21CS10014_21CS30032.y"
           { /* No Action Taken */ }
#line 2962 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 107:
#line 712 "ass5_21CS10014_21CS30032.y"
            { typevar = "float"; }
#line 2968 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 108:
#line 713 "ass5_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 2974 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 109:
#line 714 "ass5_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 2980 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 110:
#line 715 "ass5_21CS10014_21CS30032.y"
               { /* No Action Taken */ }
#line 2986 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 111:
#line 716 "ass5_21CS10014_21CS30032.y"
           { /* No Action Taken */ }
#line 2992 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 112:
#line 717 "ass5_21CS10014_21CS30032.y"
              { /* No Action Taken */ }
#line 2998 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 113:
#line 718 "ass5_21CS10014_21CS30032.y"
                { /* No Action Taken */ }
#line 3004 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 114:
#line 719 "ass5_21CS10014_21CS30032.y"
                     { /* No Action Taken */ }
#line 3010 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 115:
#line 723 "ass5_21CS10014_21CS30032.y"
                                                  { /* No Action Taken */ }
#line 3016 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 116:
#line 724 "ass5_21CS10014_21CS30032.y"
                                                  { /* No Action Taken */ }
#line 3022 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 117:
#line 728 "ass5_21CS10014_21CS30032.y"
                               { /* No Action Taken */ }
#line 3028 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 118:
#line 730 "ass5_21CS10014_21CS30032.y"
    { /* No Action Taken */ }
#line 3034 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 119:
#line 734 "ass5_21CS10014_21CS30032.y"
                                                                                 { /* No Action Taken */ }
#line 3040 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 120:
#line 735 "ass5_21CS10014_21CS30032.y"
                                                                                       { /* No Action Taken */ }
#line 3046 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 121:
#line 736 "ass5_21CS10014_21CS30032.y"
                      { /* No Action Taken */ }
#line 3052 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 122:
#line 740 "ass5_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3058 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 123:
#line 741 "ass5_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3064 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 124:
#line 745 "ass5_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3070 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 125:
#line 746 "ass5_21CS10014_21CS30032.y"
                                       { /* No Action Taken */ }
#line 3076 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 126:
#line 750 "ass5_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3082 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 127:
#line 751 "ass5_21CS10014_21CS30032.y"
                                            { /* No Action Taken */ }
#line 3088 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 128:
#line 755 "ass5_21CS10014_21CS30032.y"
            { /* No Action Taken */ }
#line 3094 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 129:
#line 756 "ass5_21CS10014_21CS30032.y"
               { /* No Action Taken */ }
#line 3100 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 130:
#line 757 "ass5_21CS10014_21CS30032.y"
               { /* No Action Taken */ }
#line 3106 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 131:
#line 761 "ass5_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3112 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 132:
#line 767 "ass5_21CS10014_21CS30032.y"
    {
        symbol_type* t = (yyvsp[-1].symtyp);
        while(t->ptr != NULL)
        {
            t = t->ptr;
        }
        t->ptr = (yyvsp[0].sym)->type;
        (yyval.sym) = (yyvsp[0].sym)->update((yyvsp[-1].symtyp));
    }
#line 3126 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 133:
#line 776 "ass5_21CS10014_21CS30032.y"
                        { /* No Action Taken */ }
#line 3132 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 134:
#line 781 "ass5_21CS10014_21CS30032.y"
    { 
        (yyval.sym) = (yyvsp[0].sym)->update(new symbol_type(typevar));
        current_symbol = (yyval.sym);
    }
#line 3141 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 135:
#line 785 "ass5_21CS10014_21CS30032.y"
                                                        { (yyval.sym) = (yyvsp[-1].sym); }
#line 3147 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 136:
#line 786 "ass5_21CS10014_21CS30032.y"
                                                                                                           { /* No Action Taken */ }
#line 3153 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 137:
#line 787 "ass5_21CS10014_21CS30032.y"
                                                                                     { /* No Action Taken */ }
#line 3159 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 138:
#line 789 "ass5_21CS10014_21CS30032.y"
    {
        symbol_type* t = (yyvsp[-3].sym)->type;
        symbol_type* new1 = NULL;
        while(t->type == "arr")
        {
            new1 = t;
            t = t->ptr;
        }
        if (new1 == NULL)
        {
            int temp = atoi((yyvsp[-1].expr)->loc->value.c_str());
            symbol_type* new_type = new symbol_type("arr", (yyvsp[-3].sym)->type, temp);
            (yyval.sym) = (yyvsp[-3].sym)->update(new_type);
        }
        else
        {
            int temp = atoi((yyvsp[-1].expr)->loc->value.c_str());
            new1->ptr = new symbol_type("arr", t, temp);
            (yyval.sym) = (yyvsp[-3].sym)->update((yyvsp[-3].sym)->type);
        }
    }
#line 3185 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 139:
#line 811 "ass5_21CS10014_21CS30032.y"
    {
        symbol_type* t = (yyvsp[-2].sym)->type;
        symbol_type* new1 = NULL;
        while(t->type == "arr")
        {
            new1 = t;
            t = t->ptr;
        }
        if (new1 == NULL)
        {
            symbol_type* new_type = new symbol_type("arr", (yyvsp[-2].sym)->type, 0);
            (yyval.sym) = (yyvsp[-2].sym)->update(new_type);
        }
        else
        {
            new1->ptr = new symbol_type("arr", t, 0);
            (yyval.sym) = (yyvsp[-2].sym)->update((yyvsp[-2].sym)->type);
        }
    }
#line 3209 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 140:
#line 831 "ass5_21CS10014_21CS30032.y"
    {
        current_symbol_table->name = (yyvsp[-4].sym)->name;
        if ((yyvsp[-4].sym)->type->type != "void")
        {
            symbol* new1 = current_symbol_table->lookup("return");
            new1->update((yyvsp[-4].sym)->type);
        }
        (yyvsp[-4].sym)->nested_table = current_symbol_table;
        current_symbol_table->parent = global_symbol_table;
        switchTable(global_symbol_table);
        current_symbol = (yyval.sym);
    }
#line 3226 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 141:
#line 844 "ass5_21CS10014_21CS30032.y"
    {
        current_symbol_table->name = (yyvsp[-3].sym)->name;
        if ((yyvsp[-3].sym)->type->type != "void")
        {
            symbol* new1 = current_symbol_table->lookup("return");
            new1->update((yyvsp[-3].sym)->type);
        }
        (yyvsp[-3].sym)->nested_table = current_symbol_table;
        current_symbol_table->parent = global_symbol_table;
        switchTable(global_symbol_table);
        current_symbol = (yyval.sym);
    }
#line 3243 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 142:
#line 856 "ass5_21CS10014_21CS30032.y"
                                                                               { /* No Action Taken */ }
#line 3249 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 143:
#line 857 "ass5_21CS10014_21CS30032.y"
                                                                                                                  { /* No Action Taken */ }
#line 3255 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 144:
#line 858 "ass5_21CS10014_21CS30032.y"
                                                                                              { /* No Action Taken */ }
#line 3261 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 145:
#line 859 "ass5_21CS10014_21CS30032.y"
                                                                                                                  { /* No Action Taken */ }
#line 3267 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 146:
#line 860 "ass5_21CS10014_21CS30032.y"
                                                                                              { /* No Action Taken */ }
#line 3273 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 147:
#line 861 "ass5_21CS10014_21CS30032.y"
                                                                          { /* No Action Taken */ }
#line 3279 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 148:
#line 866 "ass5_21CS10014_21CS30032.y"
                          { /* No Action Taken */ }
#line 3285 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 149:
#line 867 "ass5_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3291 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 150:
#line 871 "ass5_21CS10014_21CS30032.y"
                                       { (yyval.symtyp) = new symbol_type("ptr"); }
#line 3297 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 151:
#line 872 "ass5_21CS10014_21CS30032.y"
                                               { (yyval.symtyp) = new symbol_type("ptr", (yyvsp[0].symtyp)); }
#line 3303 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 152:
#line 876 "ass5_21CS10014_21CS30032.y"
                     { /* No Action Taken */ }
#line 3309 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 153:
#line 877 "ass5_21CS10014_21CS30032.y"
                                         { /* No Action Taken */ }
#line 3315 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 154:
#line 881 "ass5_21CS10014_21CS30032.y"
                     { /* No Action Taken */ }
#line 3321 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 155:
#line 882 "ass5_21CS10014_21CS30032.y"
                                    { /* No Action Taken */ }
#line 3327 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 156:
#line 886 "ass5_21CS10014_21CS30032.y"
                            { /* No Action Taken */ }
#line 3333 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 157:
#line 887 "ass5_21CS10014_21CS30032.y"
                                                 { /* No Action Taken */ }
#line 3339 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 158:
#line 891 "ass5_21CS10014_21CS30032.y"
                                        { /* No Action Taken */ }
#line 3345 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 159:
#line 892 "ass5_21CS10014_21CS30032.y"
                             { /* No Action Taken */ }
#line 3351 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 160:
#line 896 "ass5_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3357 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 161:
#line 897 "ass5_21CS10014_21CS30032.y"
                                       { /* No Action Taken */ }
#line 3363 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 162:
#line 901 "ass5_21CS10014_21CS30032.y"
                               { /* No Action Taken */ }
#line 3369 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 163:
#line 905 "ass5_21CS10014_21CS30032.y"
                            { (yyval.sym) = (yyvsp[0].expr)->loc; }
#line 3375 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 164:
#line 906 "ass5_21CS10014_21CS30032.y"
                                                              { /* No Action Taken */ }
#line 3381 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 165:
#line 907 "ass5_21CS10014_21CS30032.y"
                                                                    { /* No Action Taken */ }
#line 3387 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 166:
#line 911 "ass5_21CS10014_21CS30032.y"
                                  { /* No Action Taken */ }
#line 3393 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 167:
#line 912 "ass5_21CS10014_21CS30032.y"
                                                         { /* No Action Taken */ }
#line 3399 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 168:
#line 916 "ass5_21CS10014_21CS30032.y"
                  { /* No Action Taken */ }
#line 3405 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 169:
#line 918 "ass5_21CS10014_21CS30032.y"
    { /* No Action Taken */ }
#line 3411 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 170:
#line 922 "ass5_21CS10014_21CS30032.y"
                             { /* No Action Taken */ }
#line 3417 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 171:
#line 926 "ass5_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3423 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 172:
#line 927 "ass5_21CS10014_21CS30032.y"
                                 { /* No Action Taken */ }
#line 3429 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 173:
#line 931 "ass5_21CS10014_21CS30032.y"
                                                                   { /* No Action Taken */ }
#line 3435 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 174:
#line 932 "ass5_21CS10014_21CS30032.y"
                     { /* No Action Taken */ }
#line 3441 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 175:
#line 938 "ass5_21CS10014_21CS30032.y"
                        { /* No Action Taken */ }
#line 3447 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 176:
#line 939 "ass5_21CS10014_21CS30032.y"
                         { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3453 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 177:
#line 941 "ass5_21CS10014_21CS30032.y"
    { 
        (yyval.stmt) = new statement();
        (yyval.stmt)->nextlist = (yyvsp[0].expr)->nextlist;
    }
#line 3462 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 178:
#line 945 "ass5_21CS10014_21CS30032.y"
                          { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3468 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 179:
#line 946 "ass5_21CS10014_21CS30032.y"
                          { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3474 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 180:
#line 947 "ass5_21CS10014_21CS30032.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3480 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 181:
#line 951 "ass5_21CS10014_21CS30032.y"
                        { /* No Action Taken */ }
#line 3486 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 182:
#line 952 "ass5_21CS10014_21CS30032.y"
                         { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3492 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 183:
#line 954 "ass5_21CS10014_21CS30032.y"
    {
        (yyval.stmt) = new statement();
        (yyval.stmt)->nextlist = (yyvsp[0].expr)->nextlist;
    }
#line 3501 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 184:
#line 958 "ass5_21CS10014_21CS30032.y"
                          { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3507 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 185:
#line 959 "ass5_21CS10014_21CS30032.y"
                          { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3513 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 186:
#line 960 "ass5_21CS10014_21CS30032.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3519 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 187:
#line 964 "ass5_21CS10014_21CS30032.y"
                                 { /* No Action Taken */ }
#line 3525 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 188:
#line 965 "ass5_21CS10014_21CS30032.y"
                                               { /* No Action Taken */ }
#line 3531 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 189:
#line 966 "ass5_21CS10014_21CS30032.y"
                              { /* No Action Taken */ }
#line 3537 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 190:
#line 971 "ass5_21CS10014_21CS30032.y"
    {
        (yyval.stmt) = (yyvsp[-1].stmt);
        switchTable(current_symbol_table->parent);
    }
#line 3546 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 191:
#line 978 "ass5_21CS10014_21CS30032.y"
                      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3552 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 192:
#line 980 "ass5_21CS10014_21CS30032.y"
    { (yyval.stmt) = new statement(); }
#line 3558 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 193:
#line 984 "ass5_21CS10014_21CS30032.y"
                 { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3564 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 194:
#line 986 "ass5_21CS10014_21CS30032.y"
    {
        (yyval.stmt) = (yyvsp[0].stmt);
        backpatch((yyvsp[-2].stmt)->nextlist, (yyvsp[-1].bp));
    }
#line 3573 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 195:
#line 993 "ass5_21CS10014_21CS30032.y"
                  { (yyval.stmt) = new statement(); }
#line 3579 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 196:
#line 994 "ass5_21CS10014_21CS30032.y"
                { (yyval.stmt) = (yyvsp[0].stmt); }
#line 3585 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 197:
#line 998 "ass5_21CS10014_21CS30032.y"
                           { (yyval.expr) = (yyvsp[-1].expr); }
#line 3591 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 198:
#line 999 "ass5_21CS10014_21CS30032.y"
                { (yyval.expr) = new expression(); }
#line 3597 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 199:
#line 1003 "ass5_21CS10014_21CS30032.y"
    {
        backpatch((yyvsp[-5].stmt)->nextlist, nextinstr());
        convertInt2Bool((yyvsp[-6].expr));
        (yyval.stmt) = new statement();
        backpatch((yyvsp[-6].expr)->truelist, (yyvsp[-3].bp));

        list<int> temp = merge ((yyvsp[-6].expr)->falselist, (yyvsp[-2].stmt)->nextlist);
        (yyval.stmt)->nextlist = merge((yyvsp[-1].stmt)->nextlist, temp);
    }
#line 3611 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 200:
#line 1013 "ass5_21CS10014_21CS30032.y"
    {
        backpatch((yyvsp[-7].stmt)->nextlist, nextinstr());
        convertInt2Bool((yyvsp[-8].expr));
        (yyval.stmt) = new statement();
        backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-5].bp));
        backpatch((yyvsp[-8].expr)->falselist, (yyvsp[-1].bp));

        list<int> temp = merge ((yyvsp[-8].expr)->falselist, (yyvsp[-3].stmt)->nextlist);
        (yyval.stmt)->nextlist = merge((yyvsp[0].stmt)->nextlist, temp);
    }
#line 3626 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 201:
#line 1023 "ass5_21CS10014_21CS30032.y"
                                                                         { /* No Action Taken */ }
#line 3632 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 202:
#line 1029 "ass5_21CS10014_21CS30032.y"
    {
        (yyval.stmt) = new statement();
        convertInt2Bool((yyvsp[-3].expr));
        backpatch((yyvsp[-3].expr)->truelist, (yyvsp[-1].bp));
        backpatch((yyvsp[0].stmt)->nextlist, (yyvsp[-4].bp));

        (yyval.stmt)->nextlist = (yyvsp[-3].expr)->falselist;
        emit("goto", int2string((yyvsp[-4].bp)));
        current_block_name = "";
        switchTable(current_symbol_table->parent);
    }
#line 3648 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 203:
#line 1041 "ass5_21CS10014_21CS30032.y"
    {
        (yyval.stmt) = new statement();
        convertInt2Bool((yyvsp[-5].expr));
        backpatch((yyvsp[-5].expr)->truelist, (yyvsp[-2].bp));
        backpatch((yyvsp[-1].stmt)->nextlist, (yyvsp[-6].bp));

        (yyval.stmt)->nextlist = (yyvsp[-5].expr)->falselist;
        emit("goto", int2string((yyvsp[-6].bp)));
        current_block_name = "";
        switchTable(current_symbol_table->parent);
    }
#line 3664 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 204:
#line 1053 "ass5_21CS10014_21CS30032.y"
    {
        (yyval.stmt) = new statement();
        convertInt2Bool((yyvsp[-2].expr));
        backpatch((yyvsp[-2].expr)->truelist, (yyvsp[-7].bp));
        backpatch((yyvsp[-6].stmt)->nextlist, (yyvsp[-5].bp));

        (yyval.stmt)->nextlist = (yyvsp[-2].expr)->falselist;

        current_block_name = "";
    }
#line 3679 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 205:
#line 1064 "ass5_21CS10014_21CS30032.y"
    {
        (yyval.stmt) = new statement();
        convertInt2Bool((yyvsp[-2].expr));
        backpatch((yyvsp[-2].expr)->truelist, (yyvsp[-8].bp));
        backpatch((yyvsp[-7].stmt)->nextlist, (yyvsp[-5].bp));

        (yyval.stmt)->nextlist = (yyvsp[-2].expr)->falselist;

        current_block_name = "";
    }
#line 3694 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 206:
#line 1075 "ass5_21CS10014_21CS30032.y"
    {
        (yyval.stmt) = new statement();
        convertInt2Bool((yyvsp[-6].expr));
        backpatch((yyvsp[-6].expr)->truelist, (yyvsp[-1].bp));
        backpatch((yyvsp[0].stmt)->nextlist, (yyvsp[-5].bp));
        backpatch((yyvsp[-3].stmt)->nextlist, (yyvsp[-7].bp));

        (yyval.stmt)->nextlist = (yyvsp[-6].expr)->falselist;
        emit("goto", int2string((yyvsp[-5].bp)));
        current_block_name = "";
        switchTable(current_symbol_table->parent);
    }
#line 3711 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 207:
#line 1088 "ass5_21CS10014_21CS30032.y"
    {
        (yyval.stmt) = new statement();
        convertInt2Bool((yyvsp[-6].expr));
        backpatch((yyvsp[-6].expr)->truelist, (yyvsp[-1].bp));
        backpatch((yyvsp[0].stmt)->nextlist, (yyvsp[-5].bp));
        backpatch((yyvsp[-3].stmt)->nextlist, (yyvsp[-7].bp));

        (yyval.stmt)->nextlist = (yyvsp[-6].expr)->falselist;
        emit("goto", int2string((yyvsp[-5].bp)));
        current_block_name = "";
        switchTable(current_symbol_table->parent);
    }
#line 3728 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 208:
#line 1101 "ass5_21CS10014_21CS30032.y"
    {
        (yyval.stmt) = new statement();
        convertInt2Bool((yyvsp[-8].expr));
        backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-3].bp));
        backpatch((yyvsp[-1].stmt)->nextlist, (yyvsp[-7].bp));
        backpatch((yyvsp[-5].stmt)->nextlist, (yyvsp[-9].bp));

        (yyval.stmt)->nextlist = (yyvsp[-8].expr)->falselist;
        emit("goto", int2string((yyvsp[-7].bp)));
        current_block_name = "";
        switchTable(current_symbol_table->parent);
    }
#line 3745 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 209:
#line 1114 "ass5_21CS10014_21CS30032.y"
    {
        (yyval.stmt) = new statement();
        convertInt2Bool((yyvsp[-8].expr));
        backpatch((yyvsp[-8].expr)->nextlist, (yyvsp[-3].bp));
        backpatch((yyvsp[-1].stmt)->nextlist, (yyvsp[-7].bp));
        backpatch((yyvsp[-5].stmt)->nextlist, (yyvsp[-9].bp));

        (yyval.stmt)->nextlist = (yyvsp[-8].expr)->falselist;
        emit("goto", int2string((yyvsp[-7].bp)));
        current_block_name = "";
        switchTable(current_symbol_table->parent);
    }
#line 3762 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 210:
#line 1129 "ass5_21CS10014_21CS30032.y"
      { current_block_name = "for"; }
#line 3768 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 211:
#line 1133 "ass5_21CS10014_21CS30032.y"
      { current_block_name = "while"; }
#line 3774 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 212:
#line 1137 "ass5_21CS10014_21CS30032.y"
      { current_block_name = "do_while"; }
#line 3780 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 213:
#line 1142 "ass5_21CS10014_21CS30032.y"
    {
        string new_ST = current_symbol_table->name + "_" + current_block_name + "_" + to_string(symbol_table_counter++);
        symbol* new_symbol = current_symbol_table->lookup(new_ST);
        new_symbol->nested_table = new symbol_table(new_ST);
        new_symbol->name = new_ST;
        new_symbol->nested_table->parent = current_symbol_table;
        new_symbol->type = new symbol_type("block");
        current_symbol = new_symbol;
    }
#line 3794 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 214:
#line 1154 "ass5_21CS10014_21CS30032.y"
    {
        if (current_symbol->nested_table != NULL)
        {
            switchTable(current_symbol->nested_table);
            emit("change", current_symbol_table->name);
        }
        else 
        {
            switchTable(new symbol_table(""));
        }
    }
#line 3810 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 215:
#line 1168 "ass5_21CS10014_21CS30032.y"
                                { /* No Action Taken */ }
#line 3816 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 216:
#line 1169 "ass5_21CS10014_21CS30032.y"
                         { (yyval.stmt) = new statement(); }
#line 3822 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 217:
#line 1170 "ass5_21CS10014_21CS30032.y"
                      { (yyval.stmt) = new statement(); }
#line 3828 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 218:
#line 1172 "ass5_21CS10014_21CS30032.y"
    {
        (yyval.stmt) = new statement();
        emit("return", (yyvsp[-1].expr)->loc->name);
    }
#line 3837 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 219:
#line 1177 "ass5_21CS10014_21CS30032.y"
    {
        (yyval.stmt) = new statement();
        emit("return", "");
    }
#line 3846 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 220:
#line 1185 "ass5_21CS10014_21CS30032.y"
                           { /* No Action Taken */ }
#line 3852 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 221:
#line 1186 "ass5_21CS10014_21CS30032.y"
                                            { /* No Action Taken */ }
#line 3858 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 222:
#line 1190 "ass5_21CS10014_21CS30032.y"
                          { /* No Action Taken */ }
#line 3864 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 223:
#line 1191 "ass5_21CS10014_21CS30032.y"
                  { /* No Action Taken */ }
#line 3870 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 224:
#line 1197 "ass5_21CS10014_21CS30032.y"
    {
        current_symbol_table->parent = global_symbol_table;
        symbol_table_counter = 0;
        switchTable(global_symbol_table);
    }
#line 3880 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 225:
#line 1205 "ass5_21CS10014_21CS30032.y"
                       { /* No Action Taken */ }
#line 3886 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 226:
#line 1207 "ass5_21CS10014_21CS30032.y"
    { /* No Action Taken */ }
#line 3892 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 227:
#line 1211 "ass5_21CS10014_21CS30032.y"
                  { /* No Action Taken */ }
#line 3898 "ass5_21CS10014_21CS30032.tab.c"
    break;

  case 228:
#line 1212 "ass5_21CS10014_21CS30032.y"
                                   { /* No Action Taken */ }
#line 3904 "ass5_21CS10014_21CS30032.tab.c"
    break;


#line 3908 "ass5_21CS10014_21CS30032.tab.c"

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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
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
                      yytoken, &yylval);
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
                  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 1215 "ass5_21CS10014_21CS30032.y"


void yyerror(string s) {
    // for error reporting
    cout << "Error: " << s << endl;
    cout << "Line: " << yylineno << endl;
    cout << "Text: " << yytext << endl;
}
