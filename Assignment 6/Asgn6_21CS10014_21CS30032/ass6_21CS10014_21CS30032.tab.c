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
#line 1 "ass6_21CS10014_21CS30032.y"

    #include <iostream>
    #include "ass6_21CS10014_21CS30032_translator.h"
    using namespace std;

    extern int yylex();         
    void yyerror(string s);     
    extern char* yytext;        
    extern int yylineno;

    extern int next_instr;
    extern symbol_table global_symbol_table;
    extern symbol_table* current_symbol_table;
    extern vector<string> consts;
    extern quad_array quad_list;
    int string_count = 0;

#line 88 "ass6_21CS10014_21CS30032.tab.c"

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
#ifndef YY_YY_ASS6_21CS10014_21CS30032_TAB_H_INCLUDED
# define YY_YY_ASS6_21CS10014_21CS30032_TAB_H_INCLUDED
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
    CHAR_T = 261,
    CONST = 262,
    CONTINUE = 263,
    DEFAULT = 264,
    DO = 265,
    DOUBLE = 266,
    ELSE = 267,
    ENUM = 268,
    EXTERN = 269,
    FLOAT_T = 270,
    FOR = 271,
    GOTO_T = 272,
    IF = 273,
    INLINE = 274,
    INT_T = 275,
    LONG = 276,
    REGISTER = 277,
    RESTRICT = 278,
    RETURN_T = 279,
    SHORT = 280,
    SIGNED = 281,
    SIZEOF = 282,
    STATIC = 283,
    STRUCT = 284,
    SWITCH = 285,
    TYPEDEF = 286,
    UNION = 287,
    UNSIGNED = 288,
    VOID_T = 289,
    VOLATILE = 290,
    WHILE = 291,
    BOOL_T = 292,
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
    BIT_AND = 305,
    BIT_OR = 306,
    BIT_XOR = 307,
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
    ASSIGN_T = 325,
    PLUS_ASSIGN = 326,
    MINUS_ASSIGN = 327,
    MULTIPLY_ASSIGN = 328,
    DIVIDE_ASSIGN = 329,
    MODULO_ASSIGN = 330,
    LEFT_SHIFT_ASSIGN = 331,
    RIGHT_SHIFT_ASSIGN = 332,
    BIT_AND_ASSIGN = 333,
    BIT_XOR_ASSIGN = 334,
    BIT_OR_ASSIGN = 335,
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
    WS = 347
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "ass6_21CS10014_21CS30032.y"

    int intval;
    float floatval;
    char charval;
    void* ptr;
    string* str;
    symbol_type* symType;
    symbol* symp;
    data_type types;
    opcode opc;
    expression* expr;
    declaration* dec;
    vector<declaration*>* dec_list;
    param* p;
    vector<param*>* p_list;
    

#line 251 "ass6_21CS10014_21CS30032.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASS6_21CS10014_21CS30032_TAB_H_INCLUDED  */



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
#define YYLAST   1107

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  208
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  355

#define YYUNDEFTOK  2
#define YYMAXUTOK   347


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
      85,    86,    87,    88,    89,    90,    91,    92
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    73,    73,    79,    88,    93,   102,   110,   114,   115,
     131,   137,   157,   159,   161,   181,   202,   204,   209,   216,
     226,   227,   245,   263,   301,   303,   308,   309,   310,   311,
     312,   313,   317,   318,   322,   345,   372,   398,   427,   428,
     454,   484,   485,   509,   536,   537,   569,   599,   631,   666,
     667,   698,   732,   733,   761,   762,   790,   791,   819,   820,
     834,   835,   847,   848,   871,   878,   887,   888,   903,   905,
     907,   909,   911,   913,   915,   917,   919,   921,   923,   930,
     931,   935,   940,   941,  1010,  1012,  1014,  1016,  1018,  1020,
    1022,  1024,  1029,  1033,  1040,  1045,  1053,  1054,  1055,  1056,
    1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,  1073,  1074,  1078,  1079,  1083,  1084,  1089,  1090,  1091,
    1095,  1096,  1100,  1101,  1105,  1106,  1110,  1111,  1112,  1116,
    1121,  1126,  1134,  1139,  1143,  1150,  1154,  1158,  1167,  1203,
    1207,  1216,  1218,  1227,  1228,  1232,  1233,  1234,  1235,  1239,
    1240,  1244,  1245,  1249,  1254,  1262,  1281,  1285,  1286,  1290,
    1294,  1295,  1296,  1300,  1301,  1305,  1306,  1310,  1314,  1315,
    1319,  1320,  1324,  1325,  1326,  1327,  1328,  1329,  1333,  1334,
    1335,  1339,  1340,  1344,  1349,  1358,  1359,  1363,  1364,  1367,
    1377,  1389,  1393,  1404,  1413,  1429,  1430,  1431,  1432,  1437,
    1446,  1447,  1451,  1452,  1457,  1458,  1466,  1485,  1486
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR_T",
  "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN",
  "FLOAT_T", "FOR", "GOTO_T", "IF", "INLINE", "INT_T", "LONG", "REGISTER",
  "RESTRICT", "RETURN_T", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT",
  "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID_T", "VOLATILE", "WHILE",
  "BOOL_T", "COMPLEX", "IMAGINARY", "SQUARE_BRACKET_OPEN",
  "SQUARE_BRACKET_CLOSE", "ROUND_BRACKET_OPEN", "ROUND_BRACKET_CLOSE",
  "CURLY_BRACKET_OPEN", "CURLY_BRACKET_CLOSE", "DOT", "ARROW", "INCREMENT",
  "DECREMENT", "BIT_AND", "BIT_OR", "BIT_XOR", "BITWISE_NOT",
  "LOGICAL_AND", "LOGICAL_OR", "LOGICAL_NOT", "MULTIPLY", "DIVIDE",
  "MODULO", "PLUS", "MINUS", "LEFT_SHIFT", "RIGHT_SHIFT", "LESS_THAN",
  "GREATER_THAN", "LESS_THAN_EQUAL", "GREATER_THAN_EQUAL", "EQUAL",
  "NOT_EQUAL", "ASSIGN_T", "PLUS_ASSIGN", "MINUS_ASSIGN",
  "MULTIPLY_ASSIGN", "DIVIDE_ASSIGN", "MODULO_ASSIGN", "LEFT_SHIFT_ASSIGN",
  "RIGHT_SHIFT_ASSIGN", "BIT_AND_ASSIGN", "BIT_XOR_ASSIGN",
  "BIT_OR_ASSIGN", "COMMA", "COLON", "SEMICOLON", "ELLIPSIS",
  "QUESTION_MARK", "HASH", "INTEGER_CONSTANT", "FLOATING_CONSTANT",
  "CHAR_CONSTANT", "STRING_LITERAL", "IDENTIFIER", "WS", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "AND_expression",
  "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "M", "N", "assignment_expression",
  "assignment_operator", "expression", "constant_expression",
  "declaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "storage_class_specifier", "type_specifier",
  "specifier_qualifier_list", "specifier_qualifier_list_opt",
  "enum_specifier", "identifier_opt", "enumerator_list", "enumerator",
  "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "parameter_type_list_opt",
  "type_qualifier_list_opt", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "initializer", "initializer_list",
  "designation_opt", "designation", "designator_list", "designator",
  "statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "function_prototype", "declaration_list", YY_NULLPTR
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
     345,   346,   347
};
# endif

#define YYPACT_NINF (-261)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-207)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1068,  -261,  -261,  -261,  -261,   -54,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,    24,  1068,  1068,  -261,  1068,  1068,  1031,
    -261,  -261,     5,    36,    56,    53,    12,  -261,  -261,    38,
    -261,    39,   103,     2,  -261,  -261,  -261,  -261,  -261,  -261,
     293,  -261,    82,   -23,  -261,  -261,    12,    53,  -261,   657,
    -261,    24,   991,   168,   471,   103,    87,   834,    97,   131,
    -261,   143,   124,   181,   673,   878,   183,  -261,   566,  -261,
     902,   902,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,   156,  -261,   245,   285,   834,  -261,   109,
     137,   157,   163,   172,   197,   201,   205,   207,   -37,  -261,
    -261,    79,  -261,  -261,  -261,  -261,   218,  -261,  -261,  -261,
    -261,  -261,   196,    67,  -261,  -261,  -261,  -261,  -261,   198,
      71,  -261,  -261,  -261,  -261,  -261,   171,   724,   232,  -261,
      53,   231,  -261,   194,  -261,    -2,  -261,  -261,  -261,   200,
    -261,   507,   507,   740,   203,   834,  -261,   112,   566,  -261,
     834,   238,    20,   211,  -261,   211,   240,   566,  -261,  -261,
     507,   834,   790,   199,   214,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,   834,  -261,
     834,   834,   834,   834,   834,   834,   834,   834,   834,   834,
     834,   834,   834,   834,   834,   834,  -261,  -261,   237,   834,
    -261,  -261,   382,   834,  -261,   -21,   834,   233,    95,   657,
    -261,   119,  -261,   834,   171,  -261,   247,   284,   834,  -261,
    -261,   655,  -261,   242,   507,  -261,  -261,  -261,  -261,   253,
    -261,   296,    41,   834,  -261,  -261,  -261,  -261,   810,   297,
    -261,   -25,  -261,    73,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,   109,   109,   137,   137,   157,   157,   157,   157,   163,
     163,   172,   197,   201,   834,   834,  -261,  -261,  -261,  -261,
    -261,  -261,   295,  -261,  -261,    68,  -261,  -261,  -261,   303,
    -261,  -261,   304,  -261,  -261,  -261,  -261,   311,   740,   305,
     307,   507,   253,    71,  -261,   307,  -261,  -261,   834,   205,
     207,   834,  -261,  -261,   657,  -261,  -261,   310,  -261,  -261,
    -261,   323,   111,  -261,   253,  -261,   834,  -261,   507,  -261,
    -261,   118,   286,   253,   834,  -261,   507,  -261,  -261,   324,
     253,   357,  -261,   834,   287,   328,  -261,  -261,  -261,  -261,
     507,   507,  -261,  -261,  -261
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    98,   101,   126,   106,   121,    96,   105,   129,   103,
     104,    99,   127,   102,   107,    97,   108,   100,   128,   109,
     110,   111,   203,     0,    85,    87,   112,    89,    91,     0,
     200,   202,     0,   119,     0,     0,   148,    82,   132,     0,
      92,    94,   131,     0,    84,    86,    88,    90,     1,   201,
       0,   205,     0,     0,   149,   147,   145,     0,    83,     0,
     207,     0,     0,   144,   142,   130,     0,     0,     0,     0,
      64,     0,     0,     0,     0,     0,     0,    64,     0,   181,
       0,     0,    26,    30,    31,    27,    28,    29,   188,     6,
       5,     3,     4,     2,     8,    20,    32,     0,    34,    38,
      41,    44,    49,    52,    54,    56,    58,    60,    62,    66,
      79,     0,   185,   186,   172,   173,    64,   183,   174,   175,
     176,   177,   124,     0,   122,   133,   150,   146,    93,    94,
     166,     2,   160,    95,   208,   204,   144,     0,   143,   157,
     156,     0,   141,   151,   153,     0,   197,    32,    81,     0,
     196,     0,     0,     0,     0,     0,   198,     0,     0,    24,
       0,     0,     0,   116,   159,   116,     0,     0,    21,    22,
       0,     0,     0,     0,     0,    14,    15,    68,    72,    73,
      69,    70,    71,    74,    75,    76,    77,    78,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    64,     0,     0,
     187,   182,     0,     0,   117,     0,     0,     0,     0,     0,
     165,     0,   168,     0,   143,   134,    27,     0,     0,   155,
     138,     0,   139,     0,     0,   180,    64,    64,   195,    65,
     199,     0,     0,     0,     7,   115,   113,   114,     0,     0,
     178,     0,    10,     0,    18,    12,    13,    67,    35,    36,
      37,    39,    40,    42,    43,    45,    46,    47,    48,    50,
      51,    53,    55,    57,     0,     0,    64,    80,   184,   125,
     118,   123,     0,   171,   161,   166,   163,   167,   169,     0,
     140,   137,     0,   152,   154,   158,   179,     0,     0,     0,
      25,     0,    65,   166,    33,     0,     9,    11,     0,    59,
      61,     0,   170,   162,     0,   135,   136,     0,    65,    64,
     191,     0,     0,    19,    65,   164,     0,    64,     0,    64,
      16,   166,     0,    65,     0,    65,     0,    17,    64,     0,
      65,   189,   192,     0,     0,     0,    64,    63,   193,    64,
       0,     0,    65,   194,   190
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -261,  -261,  -261,  -261,   -67,  -261,   -87,    58,    63,    72,
      77,   169,   170,   173,    99,   100,  -261,   -66,   -65,  -119,
     -19,  -261,   -69,  -177,   -24,     4,  -261,   320,  -261,   -71,
      47,   229,  -261,  -261,  -261,   164,    19,  -261,    -1,   368,
    -261,   277,   -13,   -48,  -261,  -261,   191,  -261,   -68,  -208,
     120,  -260,  -261,  -261,   193,  -149,  -261,    -5,  -261,   213,
    -147,  -261,  -261,  -261,  -261,   398,  -261,  -261,  -261
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    94,    95,   253,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   152,   208,
     110,   188,   111,   149,    22,    61,    39,    40,    24,    25,
     164,   246,    26,    34,   123,   124,    27,    28,   129,    42,
     141,   137,    43,    56,   142,   143,   144,   145,   166,   133,
     218,   219,   220,   221,   222,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    29,    30,    31,    32,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     147,   148,   235,   236,    23,   157,   237,   163,   159,   162,
     189,   286,   161,   168,   169,   138,   306,    60,   207,     3,
     125,   250,    41,    55,   280,   314,   112,    51,    44,    45,
     147,    46,    47,    23,    53,    12,   279,    33,   134,   282,
     132,   232,     1,   127,    35,     2,     3,    18,   -65,    50,
       4,   212,     5,     6,     7,    54,   209,   135,     8,     9,
      10,    11,    12,   244,    13,    14,    35,    15,   140,    36,
     122,   314,    16,    17,    18,   126,    19,    20,    21,   233,
    -120,    36,    54,  -206,   301,   296,   239,   163,   224,   162,
     241,   242,   163,    38,   163,    35,   163,   165,   162,   249,
      52,   209,   251,   258,   259,   260,   325,    37,   216,    59,
      36,   216,   214,   313,   217,    38,   307,   217,   227,    57,
     299,    58,   209,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   229,
     284,   274,   275,    63,    38,    64,   147,   148,   215,   147,
     148,   318,   320,   254,   308,    54,   330,   126,   216,   216,
     209,   304,   210,   337,   217,   217,   190,   191,   192,   257,
     146,   297,   298,   122,   302,     3,   285,   165,     3,   335,
     150,   147,   165,   321,   165,   153,   165,   342,   112,   287,
     277,    12,   331,   209,    12,   240,   136,   193,   194,   327,
     132,   352,   353,    18,   289,   332,    18,   147,   147,   292,
     245,   311,   245,   151,   339,   154,   341,     2,     3,   195,
     196,   345,     4,   155,     5,   160,     7,   197,   198,   199,
     200,     9,    10,   354,    12,   140,    13,    14,   170,     3,
     201,   202,   324,   126,    16,    17,    18,   203,    19,    20,
      21,   261,   262,   204,   328,    12,   205,   333,   263,   264,
     228,   206,   334,   211,   336,   340,   213,    18,    59,   265,
     266,   267,   268,   343,   230,   231,   147,   347,   269,   270,
     243,   350,   234,   248,   351,   171,   238,   172,   290,   323,
     255,   173,   174,   175,   176,   132,     1,    66,    67,     2,
       3,    68,    69,    70,     4,   256,     5,     6,     7,    71,
      72,    73,     8,     9,    10,    11,    12,    74,    13,    14,
      75,    15,   276,    76,   283,   291,    16,    17,    18,    77,
      19,    20,    21,   295,   209,    78,   312,    50,    79,   300,
     305,    80,    81,    82,   315,   316,    83,   317,   319,    84,
      85,   303,   326,    86,    87,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   329,   344,   338,   346,
     348,   349,   271,   309,   272,   310,    88,   128,   273,   281,
      89,    90,    91,    92,    93,     1,    66,    67,     2,     3,
      68,    69,    70,     4,   247,     5,     6,     7,    71,    72,
      73,     8,     9,    10,    11,    12,    74,    13,    14,    75,
      15,    65,    76,   223,   288,    16,    17,    18,    77,    19,
      20,    21,   294,   322,    78,   278,    50,    49,     0,     0,
      80,    81,    82,     0,     0,    83,     0,     0,    84,    85,
       0,     0,    86,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,     0,     0,    89,
      90,    91,    92,    93,     1,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     5,     6,     7,     0,     0,     0,
       8,     9,    10,    11,    12,     0,    13,    14,     0,    15,
       0,     0,     0,     0,    16,    17,    18,     0,    19,    20,
      21,    66,    67,     0,     0,    68,    69,    70,     0,     0,
       0,     0,     0,    71,    72,    73,     0,     0,     0,     0,
       0,    74,     0,     0,    75,     0,     0,    76,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,    78,
       0,    50,     0,     0,     0,    80,    81,    82,     0,     0,
      83,     0,   139,    84,    85,     0,     0,    86,    87,     0,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     5,
       0,     7,     0,     0,     0,     0,     9,    10,     0,    12,
      88,    13,    14,    75,    89,    90,    91,    92,    93,    16,
      17,    18,     0,    19,    20,    21,     0,     0,    78,     0,
       0,     0,     0,     0,    80,    81,    82,     0,     0,    83,
       0,     0,    84,    85,     0,     0,    86,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,   131,     1,     0,
       0,     2,     3,     0,     0,     0,     4,     0,     5,     6,
       7,     0,     0,     0,     8,     9,    10,    11,    12,     0,
      13,    14,     0,    15,    75,     0,     0,     0,    16,    17,
      18,     0,    19,    20,    21,     0,     0,     0,     0,    78,
      75,   130,     0,     0,     0,    80,    81,    82,     0,     0,
      83,     0,     0,    84,    85,    78,     0,    86,    87,     0,
       0,    80,    81,    82,     0,     0,    83,     0,     0,    84,
      85,     0,     0,    86,    87,     0,     0,     0,     0,   293,
       0,     0,     0,     0,    89,    90,    91,    92,   131,     0,
       0,    75,     0,     0,     0,     0,   156,     0,     0,     0,
      89,    90,    91,    92,   131,   225,    78,    75,     0,     0,
       0,     0,    80,    81,    82,     0,     0,    83,     0,     0,
      84,   226,    78,     0,    86,    87,     0,     0,    80,    81,
      82,     0,     0,    83,     0,     0,    84,    85,     0,     0,
      86,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,    90,    91,    92,   131,     0,    75,     0,     0,
       0,     0,     0,    88,     0,     0,     0,    89,    90,    91,
      92,   131,    78,   252,     0,     0,     0,    75,    80,    81,
      82,     0,     0,    83,     0,     0,    84,    85,     0,     0,
      86,    87,    78,     0,   303,     0,     0,     0,    80,    81,
      82,    75,     0,    83,     0,     0,    84,    85,     0,     0,
      86,    87,     0,     0,     0,     0,    78,    89,    90,    91,
      92,   131,    80,    81,    82,     0,     0,    83,     0,     0,
      84,    85,     0,     0,    86,    87,     0,    89,    90,    91,
      92,   131,     0,     0,     0,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     158,    89,    90,    91,    92,   131,    80,    81,    82,    75,
       0,    83,     0,     0,    84,    85,     0,     0,    86,    87,
       0,     0,     0,     0,   167,     0,     0,     0,     0,     0,
      80,    81,    82,     0,     0,    83,     0,     0,    84,    85,
       0,     0,    86,    87,     0,    89,    90,    91,    92,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,    92,   131,     1,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     5,     6,     7,     0,     0,     0,
       8,     9,    10,    11,    12,     0,    13,    14,     0,    15,
       0,     0,     0,     0,    16,    17,    18,     0,    19,    20,
      21,    48,     0,     0,     1,    50,     0,     2,     3,     0,
       0,     0,     4,     0,     5,     6,     7,     0,     0,     0,
       8,     9,    10,    11,    12,     0,    13,    14,     0,    15,
       0,     0,     0,     0,    16,    17,    18,     0,    19,    20,
      21,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,     0,    13,    14,     0,    15,     0,     0,     0,
       0,    16,    17,    18,     0,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      67,    67,   151,   152,     0,    74,   153,    78,    75,    78,
      97,   219,    77,    80,    81,    63,    41,    41,    55,     7,
      43,   170,    23,    36,    45,   285,    50,    32,    24,    25,
      97,    27,    28,    29,    35,    23,   213,    91,    62,   216,
      59,    43,     3,    56,    42,     6,     7,    35,    85,    44,
      11,   116,    13,    14,    15,    36,    81,    62,    19,    20,
      21,    22,    23,    43,    25,    26,    42,    28,    64,    57,
      91,   331,    33,    34,    35,    56,    37,    38,    39,    81,
      44,    57,    63,    44,    43,   234,   155,   158,   136,   158,
     158,   160,   163,    91,   165,    42,   167,    78,   167,   167,
      44,    81,   171,   190,   191,   192,   314,    83,    40,    70,
      57,    40,    45,    45,    46,    91,    43,    46,   137,    81,
     239,    83,    81,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   140,
      45,   206,   207,    40,    91,    42,   213,   213,    81,   216,
     216,   298,   301,   172,    81,   136,    45,   138,    40,    40,
      81,   248,    83,    45,    46,    46,    57,    58,    59,   188,
      83,   236,   237,    91,   243,     7,    81,   158,     7,   328,
      83,   248,   163,   302,   165,    42,   167,   336,   212,    70,
     209,    23,    81,    81,    23,    83,    28,    60,    61,   318,
     219,   350,   351,    35,   223,   324,    35,   274,   275,   228,
     163,   276,   165,    82,   333,    91,   335,     6,     7,    62,
      63,   340,    11,    42,    13,    42,    15,    64,    65,    66,
      67,    20,    21,   352,    23,   231,    25,    26,    82,     7,
      68,    69,   311,   224,    33,    34,    35,    50,    37,    38,
      39,   193,   194,    52,   319,    23,    51,   326,   195,   196,
      28,    54,   327,    45,   329,   334,    70,    35,    70,   197,
     198,   199,   200,   338,    43,    81,   343,   343,   201,   202,
      42,   346,    82,    43,   349,    40,    83,    42,    41,   308,
      91,    46,    47,    48,    49,   314,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    91,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    85,    30,    91,    41,    33,    34,    35,    36,
      37,    38,    39,    91,    81,    42,    41,    44,    45,    43,
      43,    48,    49,    50,    41,    41,    53,    36,    43,    56,
      57,    44,    42,    60,    61,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    43,    43,    82,    12,
      83,    43,   203,   274,   204,   275,    83,    57,   205,   215,
      87,    88,    89,    90,    91,     3,     4,     5,     6,     7,
       8,     9,    10,    11,   165,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    43,    30,   136,   221,    33,    34,    35,    36,    37,
      38,    39,   231,   303,    42,   212,    44,    29,    -1,    -1,
      48,    49,    50,    -1,    -1,    53,    -1,    -1,    56,    57,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    87,
      88,    89,    90,    91,     3,    -1,    -1,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    -1,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,
      39,     4,     5,    -1,    -1,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    27,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    44,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      53,    -1,    91,    56,    57,    -1,    -1,    60,    61,    -1,
      -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      -1,    15,    -1,    -1,    -1,    -1,    20,    21,    -1,    23,
      83,    25,    26,    27,    87,    88,    89,    90,    91,    33,
      34,    35,    -1,    37,    38,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    53,
      -1,    -1,    56,    57,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,    90,    91,     3,    -1,
      -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,
      25,    26,    -1,    28,    27,    -1,    -1,    -1,    33,    34,
      35,    -1,    37,    38,    39,    -1,    -1,    -1,    -1,    42,
      27,    44,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      53,    -1,    -1,    56,    57,    42,    -1,    60,    61,    -1,
      -1,    48,    49,    50,    -1,    -1,    53,    -1,    -1,    56,
      57,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    41,    42,    27,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    53,    -1,    -1,
      56,    57,    42,    -1,    60,    61,    -1,    -1,    48,    49,
      50,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    89,    90,    91,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    42,    43,    -1,    -1,    -1,    27,    48,    49,
      50,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,
      60,    61,    42,    -1,    44,    -1,    -1,    -1,    48,    49,
      50,    27,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    42,    87,    88,    89,
      90,    91,    48,    49,    50,    -1,    -1,    53,    -1,    -1,
      56,    57,    -1,    -1,    60,    61,    -1,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    87,    88,    89,    90,    91,    48,    49,    50,    27,
      -1,    53,    -1,    -1,    56,    57,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    -1,    -1,    53,    -1,    -1,    56,    57,
      -1,    -1,    60,    61,    -1,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,     3,    -1,    -1,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    -1,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,
      39,     0,    -1,    -1,     3,    44,    -1,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    -1,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,
      39,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    22,    23,    25,    26,    28,    33,    34,    35,    37,
      38,    39,   117,   118,   121,   122,   125,   129,   130,   157,
     158,   159,   160,    91,   126,    42,    57,    83,    91,   119,
     120,   131,   132,   135,   118,   118,   118,   118,     0,   158,
      44,   150,    44,   131,   129,   135,   136,    81,    83,    70,
     117,   118,   161,    40,    42,   132,     4,     5,     8,     9,
      10,    16,    17,    18,    24,    27,    30,    36,    42,    45,
      48,    49,    50,    53,    56,    57,    60,    61,    83,    87,
      88,    89,    90,    91,    94,    95,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     113,   115,   117,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    91,   127,   128,    43,   129,   135,   120,   131,
      44,    91,   113,   142,   117,   150,    28,   134,   136,    91,
     118,   133,   137,   138,   139,   140,    83,    97,   110,   116,
      83,    82,   111,    42,    91,    42,    83,   115,    42,    97,
      42,   111,   115,   122,   123,   129,   141,    42,    97,    97,
      82,    40,    42,    46,    47,    48,    49,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,   114,    99,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    50,    52,    51,    54,    55,   112,    81,
      83,    45,   111,    70,    45,    81,    40,    46,   143,   144,
     145,   146,   147,   134,   136,    41,    57,   113,    28,   131,
      43,    81,    43,    81,    82,   148,   148,   153,    83,   115,
      83,   141,   115,    42,    43,   123,   124,   124,    43,   141,
     148,   115,    43,    96,   113,    91,    91,   113,    99,    99,
      99,   100,   100,   101,   101,   102,   102,   102,   102,   103,
     103,   104,   105,   106,   111,   111,    85,   113,   152,   116,
      45,   128,   116,    91,    45,    81,   142,    70,   147,   113,
      41,    41,   113,    84,   139,    91,   148,   111,   111,   112,
      43,    43,   115,    44,    99,    43,    41,    43,    81,   107,
     108,   111,    41,    45,   144,    41,    41,    36,   153,    43,
     148,   112,   143,   113,   115,   142,    42,   112,   111,    43,
      45,    81,   112,   115,   111,   148,   111,    45,    82,   112,
     115,   112,   148,   111,    43,   112,    12,   110,    83,    43,
     111,   111,   148,   148,   112
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    94,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    96,    96,
      97,    97,    97,    97,    97,    97,    98,    98,    98,    98,
      98,    98,    99,    99,   100,   100,   100,   100,   101,   101,
     101,   102,   102,   102,   103,   103,   103,   103,   103,   104,
     104,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     109,   109,   110,   110,   111,   112,   113,   113,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   115,
     115,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   119,   119,   120,   120,   121,   121,   121,   121,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   123,   123,   124,   124,   125,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   129,   130,
     131,   131,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   133,   133,   134,   134,   135,   135,   135,   135,   136,
     136,   137,   137,   138,   138,   139,   139,   140,   140,   141,
     142,   142,   142,   143,   143,   144,   144,   145,   146,   146,
     147,   147,   148,   148,   148,   148,   148,   148,   149,   149,
     149,   150,   150,   151,   151,   152,   152,   153,   153,   154,
     154,   154,   155,   155,   155,   156,   156,   156,   156,   156,
     157,   157,   158,   158,   159,   159,   160,   161,   161
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     6,     7,     1,     3,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     4,
       1,     4,     1,     9,     0,     0,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     2,     1,     2,     1,     2,     1,
       2,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     0,     5,     6,     2,
       1,     0,     1,     3,     1,     3,     1,     1,     1,     1,
       2,     1,     1,     3,     4,     6,     6,     5,     4,     4,
       5,     1,     0,     1,     0,     2,     3,     2,     1,     1,
       2,     1,     3,     1,     3,     2,     1,     1,     3,     1,
       1,     3,     4,     2,     4,     1,     0,     2,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     2,     3,     1,     3,     1,     1,     2,     1,     8,
      12,     5,     8,    10,    12,     3,     2,     2,     2,     3,
       1,     2,     1,     1,     4,     2,     2,     1,     2
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
#line 73 "ass6_21CS10014_21CS30032.y"
                 {
        (yyval.expr) = new expression(); 
        string s = *((yyvsp[0].str));
        current_symbol_table->lookup(s);
        (yyval.expr)->loc = s;
    }
#line 1872 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 3:
#line 80 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.expr) = new expression() ;
        (yyval.expr)->loc = current_symbol_table->gentemp(CHAR);
        emit((yyval.expr)->loc,(yyvsp[0].charval),ASSIGN);
        symbol_value* val = new symbol_value();
        val->set_value((yyvsp[0].charval));
        current_symbol_table->lookup((yyval.expr)->loc)->initial_value = val;
    }
#line 1885 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 4:
#line 88 "ass6_21CS10014_21CS30032.y"
                     { 
        (yyval.expr) = new expression() ; 
        (yyval.expr)->loc = ".LC" + to_string(string_count++) ;
        consts.push_back(*((yyvsp[0].str)));
    }
#line 1895 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 5:
#line 94 "ass6_21CS10014_21CS30032.y"
    { 
        (yyval.expr) = new expression() ;
        (yyval.expr)->loc = current_symbol_table->gentemp(FLOAT);
        emit((yyval.expr)->loc,(yyvsp[0].floatval),ASSIGN);
        symbol_value* val = new symbol_value();
        val->set_value((yyvsp[0].floatval));
        current_symbol_table->lookup((yyval.expr)->loc)->initial_value = val;
    }
#line 1908 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 6:
#line 102 "ass6_21CS10014_21CS30032.y"
                       {
        (yyval.expr) = new expression() ;
        (yyval.expr)->loc = current_symbol_table->gentemp(INT);
        emit((yyval.expr)->loc,(yyvsp[0].intval),ASSIGN);
        symbol_value* val = new symbol_value();
        val->set_value((yyvsp[0].intval));
        current_symbol_table->lookup((yyval.expr)->loc)->initial_value = val;
    }
#line 1921 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 7:
#line 110 "ass6_21CS10014_21CS30032.y"
                                                        { (yyval.expr) = (yyvsp[-1].expr) ; }
#line 1927 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 8:
#line 114 "ass6_21CS10014_21CS30032.y"
                         {/* No Action Taken */}
#line 1933 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 9:
#line 115 "ass6_21CS10014_21CS30032.y"
                                                                             {
        symbol_type t = current_symbol_table->lookup((yyvsp[-3].expr)->loc)->type;
        string str = "" ;
        if(!((yyvsp[-3].expr)->fold))
        {
            str = current_symbol_table->gentemp(INT);
            emit(str,0,ASSIGN);
            (yyvsp[-3].expr)->folder = new string(str);
        }
        string temp = current_symbol_table->gentemp(INT);

        emit(temp,(yyvsp[-1].expr)->loc,"",ASSIGN);
        emit(temp,temp,"4",MULT);
        emit(str,temp,"",ASSIGN);
        (yyval.expr)=(yyvsp[-3].expr);
    }
#line 1954 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 10:
#line 132 "ass6_21CS10014_21CS30032.y"
    {
        // is for calling a function with no parameters
        symbol_table* table = global_symbol_table.lookup((yyvsp[-2].expr)->loc)->nested_table;
        emit((yyvsp[-2].expr)->loc,"0","",CALL);
    }
#line 1964 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 11:
#line 137 "ass6_21CS10014_21CS30032.y"
                                                                                         { 
        // Corresponds to calling a function with the  function name and the appropriate number of parameters
        symbol_table* table = global_symbol_table.lookup((yyvsp[-3].expr)->loc)->nested_table;
        vector<param*> params = *((yyvsp[-1].p_list));
        vector<symbol*> param_list = table->symbol_list;

        for(int i =0 ;i<params.size();i++)
        {
            emit(params[i]->name,"","",PARAM);
        }

        data_type return_type = table->lookup("RETVAL")->type.type;       // making an entry to symbol table for the return value of the function
        if(return_type == VOID) emit((yyvsp[-3].expr)->loc,(int)params.size(),CALL);
        else{
            string return_value = current_symbol_table->gentemp(return_type);
            emit((yyvsp[-3].expr)->loc,to_string(params.size()),return_value,CALL);
            (yyval.expr) = new expression();
            (yyval.expr)->loc = return_value;
        }
    }
#line 1989 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 12:
#line 158 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 1995 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 13:
#line 160 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2001 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 14:
#line 161 "ass6_21CS10014_21CS30032.y"
                                   {
        (yyval.expr) = new expression();
        symbol_type t = current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type;
        if(t.type == ARR)
        {
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type.nextType);
            emit((yyval.expr)->loc,(yyvsp[-1].expr)->loc,*((yyvsp[-1].expr)->folder),ARR_IDX_ARG);
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,(yyvsp[-1].expr)->loc,*((yyvsp[-1].expr)->folder),ARR_IDX_ARG);
            emit(temp,temp,"1",ADD);
            emit((yyvsp[-1].expr)->loc,temp,*((yyvsp[-1].expr)->folder),ARR_IDX_RES);
        }
        else 
        {
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type.type);
            emit((yyval.expr)->loc,(yyvsp[-1].expr)->loc,"",ASSIGN);
            emit((yyvsp[-1].expr)->loc,(yyvsp[-1].expr)->loc,"1",ADD);
        }

    }
#line 2026 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 15:
#line 181 "ass6_21CS10014_21CS30032.y"
                                   {
        (yyval.expr) = new expression();
        (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type.type);          // Generate a new temporary variable
        symbol_type t = current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type;
        if(t.type == ARR)
        {
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type.nextType);
            emit((yyval.expr)->loc,(yyvsp[-1].expr)->loc,*((yyvsp[-1].expr)->folder),ARR_IDX_ARG);
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,(yyvsp[-1].expr)->loc,*((yyvsp[-1].expr)->folder),ARR_IDX_ARG);
            emit((yyval.expr)->loc,temp,"",ASSIGN);
            emit(temp,temp,"1",SUB);
            emit((yyvsp[-1].expr)->loc,temp,*((yyvsp[-1].expr)->folder),ARR_IDX_RES);
        }
        else 
        {
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type.type);
            emit((yyval.expr)->loc,(yyvsp[-1].expr)->loc,"",ASSIGN);
            emit((yyvsp[-1].expr)->loc,(yyvsp[-1].expr)->loc,"1",SUB);
        }
    }
#line 2052 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 16:
#line 203 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2058 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 17:
#line 205 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2064 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 18:
#line 209 "ass6_21CS10014_21CS30032.y"
                            {
        param* p = new param();
        p->name = (yyvsp[0].expr)->loc;
        p->type = current_symbol_table->lookup((yyvsp[0].expr)->loc)->type;
        (yyval.p_list) = new vector<param*>;
        (yyval.p_list)->push_back(p);
    }
#line 2076 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 19:
#line 216 "ass6_21CS10014_21CS30032.y"
                                                           { 
        param* p = new param();
        p->name = (yyvsp[0].expr)->loc;
        p->type = current_symbol_table->lookup(p->name)->type;
        (yyval.p_list) = (yyvsp[-2].p_list);
        (yyval.p_list)->push_back(p);
    }
#line 2088 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 20:
#line 226 "ass6_21CS10014_21CS30032.y"
                         {}
#line 2094 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 21:
#line 227 "ass6_21CS10014_21CS30032.y"
                                 {
        (yyval.expr) = new expression();  
        symbol_type t = current_symbol_table->lookup((yyvsp[0].expr)->loc)->type;
        if(t.type == ARR)
        {
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            emit(temp,temp,"1",ADD);
            emit((yyvsp[0].expr)->loc,temp,*((yyvsp[0].expr)->folder),ARR_IDX_RES);
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[0].expr)->loc)->type.nextType);
        }
        else{
            emit((yyvsp[0].expr)->loc,(yyvsp[0].expr)->loc,"1",ADD);
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[0].expr)->loc)->type.type);
        }
        (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[0].expr)->loc)->type.type);
        emit((yyval.expr)->loc,(yyvsp[0].expr)->loc,"",ASSIGN);
    }
#line 2117 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 22:
#line 245 "ass6_21CS10014_21CS30032.y"
                                 {
        (yyval.expr) = new expression();
        symbol_type t = current_symbol_table->lookup((yyvsp[0].expr)->loc)->type;
        if(t.type == ARR)
        {
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            emit(temp,temp,"1",SUB);
            emit((yyvsp[0].expr)->loc,temp,*((yyvsp[0].expr)->folder),ARR_IDX_RES);
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[0].expr)->loc)->type.nextType);
        }
        else 
        {
            emit((yyvsp[0].expr)->loc,(yyvsp[0].expr)->loc,"1",SUB);
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[0].expr)->loc)->type.type);
        }
        emit((yyval.expr)->loc,(yyvsp[0].expr)->loc,"",ASSIGN);
    }
#line 2140 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 23:
#line 263 "ass6_21CS10014_21CS30032.y"
                                     {
        switch((yyvsp[-1].charval))
        {
            case '&' :          // address 
                (yyval.expr) = new expression();
                (yyval.expr)->loc = current_symbol_table->gentemp(PTR);
                emit((yyval.expr)->loc,(yyvsp[0].expr)->loc,"",REFERENCE);
                break;
            
            case '*' :          // dereference
                (yyval.expr) = new expression();
                (yyval.expr)->loc = current_symbol_table->gentemp(INT);
                (yyval.expr)->fold = 1;
                (yyval.expr)->folder = new string((yyvsp[0].expr)->loc);
                emit((yyval.expr)->loc,(yyvsp[0].expr)->loc,"",DEREFERENCE);
                break;
            
            case '-' :
                (yyval.expr)= new expression();
                (yyval.expr)->loc = current_symbol_table->gentemp();
                emit((yyval.expr)->loc,(yyvsp[0].expr)->loc,"",UNARY_MINUS);
                break;

            
            case '!' :
                (yyval.expr) = new expression();
                (yyval.expr)->loc = current_symbol_table->gentemp(INT);
                int temp = next_instr + 2;
                emit(to_string(temp),(yyvsp[0].expr)->loc,"0",GOTO_EQ);
                temp = next_instr + 3;
                emit(to_string(temp),"","",GOTO);
                emit((yyval.expr)->loc,"1","",ASSIGN);
                temp = next_instr + 2;
                emit(to_string(temp),"","",GOTO);
                emit((yyval.expr)->loc,"0","",ASSIGN);
                break;
        }
    }
#line 2183 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 24:
#line 302 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2189 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 25:
#line 304 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2195 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 26:
#line 308 "ass6_21CS10014_21CS30032.y"
              { (yyval.charval) = '&'; }
#line 2201 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 27:
#line 309 "ass6_21CS10014_21CS30032.y"
               { (yyval.charval) = '*';}
#line 2207 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 28:
#line 310 "ass6_21CS10014_21CS30032.y"
           { (yyval.charval) = '+';}
#line 2213 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 29:
#line 311 "ass6_21CS10014_21CS30032.y"
            { (yyval.charval) = '-';}
#line 2219 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 30:
#line 312 "ass6_21CS10014_21CS30032.y"
                  { (yyval.charval) = '~';}
#line 2225 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 31:
#line 313 "ass6_21CS10014_21CS30032.y"
                  { (yyval.charval) = '!';}
#line 2231 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 32:
#line 317 "ass6_21CS10014_21CS30032.y"
                       { /* No Action Taken */ }
#line 2237 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 33:
#line 318 "ass6_21CS10014_21CS30032.y"
                                                                       { /* No Action Taken */ }
#line 2243 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 34:
#line 322 "ass6_21CS10014_21CS30032.y"
                      {
        (yyval.expr) = new expression();
        symbol_type t = current_symbol_table->lookup((yyvsp[0].expr)->loc)->type;
        if(t.type = ARR)
        {
            string temp = current_symbol_table->gentemp(t.nextType);
            if((yyvsp[0].expr)->folder != NULL)
            {
                emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
                (yyvsp[0].expr)->loc = temp;
                (yyvsp[0].expr)->type = t.nextType;
                (yyval.expr) = (yyvsp[0].expr);
            }
            else 
            {
                (yyval.expr) = (yyvsp[0].expr);
            }
        }
        else 
        {
            (yyval.expr) = (yyvsp[0].expr);
        }
    }
#line 2271 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 35:
#line 345 "ass6_21CS10014_21CS30032.y"
                                                         {
        
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        // assign the result of the multiplication to a new temporary variable in the higher data type

        data_type result = ((s1->type.type > s2->type.type) ? s1->type.type : s2->type.type);
        (yyval.expr)->loc = current_symbol_table->gentemp(result);
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,MULT);
    }
#line 2303 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 36:
#line 372 "ass6_21CS10014_21CS30032.y"
                                                       {
        
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        // assign the result of the division to a new temporary variable in the higher data type
        data_type result = ((s1->type.type > s2->type.type) ? s1->type.type : s2->type.type);
        (yyval.expr)->loc = current_symbol_table->gentemp(result);
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,DIV);
    }
#line 2334 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 37:
#line 398 "ass6_21CS10014_21CS30032.y"
                                                       {
        
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        // assign the result of the modulo to a new temporary variable in the higher data type
        data_type result = ((s1->type.type > s2->type.type) ? s1->type.type : s2->type.type);
        (yyval.expr)->loc = current_symbol_table->gentemp(result);
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,MOD);
    }
#line 2365 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 38:
#line 427 "ass6_21CS10014_21CS30032.y"
                                { /* No Action Taken */ }
#line 2371 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 39:
#line 428 "ass6_21CS10014_21CS30032.y"
                                                         {

        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        // assign the result of the addition to a new temporary variable in the higher data type
        data_type result = ((s1->type.type > s2->type.type) ? s1->type.type : s2->type.type);
        (yyval.expr)->loc = current_symbol_table->gentemp(result);
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,ADD);
    }
#line 2402 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 40:
#line 454 "ass6_21CS10014_21CS30032.y"
                                                          {
        
        
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        // assign the result of the subtraction to a new temporary variable in the higher data type
        data_type result = ((s1->type.type > s2->type.type) ? s1->type.type : s2->type.type);
        (yyval.expr)->loc = current_symbol_table->gentemp(result);
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,SUB);
    }
#line 2434 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 41:
#line 484 "ass6_21CS10014_21CS30032.y"
                          { /* No Action Taken */ }
#line 2440 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 42:
#line 485 "ass6_21CS10014_21CS30032.y"
                                                      {
        
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        (yyval.expr)->loc = current_symbol_table->gentemp(s1->type.type);
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,SL);
    }
#line 2469 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 43:
#line 509 "ass6_21CS10014_21CS30032.y"
                                                       {
        
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        (yyval.expr)->loc = current_symbol_table->gentemp(s1->type.type);
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,SR);
    }
#line 2498 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 44:
#line 536 "ass6_21CS10014_21CS30032.y"
                       { /* No Action Taken */ }
#line 2504 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 45:
#line 538 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        (yyval.expr) = new expression();
        (yyval.expr)->loc = current_symbol_table->gentemp();
        (yyval.expr)->type = BOOL;
        emit((yyval.expr)->loc,"1","",ASSIGN);
        (yyval.expr)->truelist = makelist(next_instr);
        emit("",(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,GOTO_LT);
        emit((yyval.expr)->loc,"0","",ASSIGN);
        (yyval.expr)->falselist = makelist(next_instr);
        emit("", "", "", GOTO);

    }
#line 2540 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 46:
#line 569 "ass6_21CS10014_21CS30032.y"
                                                          { 
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        (yyval.expr) = new expression();
        (yyval.expr)->loc = current_symbol_table->gentemp();
        (yyval.expr)->type = BOOL;
        emit((yyval.expr)->loc,"1","",ASSIGN);
        (yyval.expr)->truelist = makelist(next_instr);
        emit("",(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,GOTO_GT);
        emit((yyval.expr)->loc,"0","",ASSIGN);
        (yyval.expr)->falselist = makelist(next_instr);
        emit("", "", "", GOTO);
    }
#line 2575 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 47:
#line 599 "ass6_21CS10014_21CS30032.y"
                                                             {
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        (yyval.expr) = new expression();
        (yyval.expr)->loc = current_symbol_table->gentemp();
        (yyval.expr)->type = BOOL;
        emit((yyval.expr)->loc,"1","",ASSIGN);
        (yyval.expr)->truelist = makelist(next_instr);
        emit("",(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,GOTO_LTE);
        emit((yyval.expr)->loc,"0","",ASSIGN);
        (yyval.expr)->falselist = makelist(next_instr);
        emit("", "", "", GOTO);

    }
#line 2611 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 48:
#line 632 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        (yyval.expr) = new expression();
        (yyval.expr)->loc = current_symbol_table->gentemp();
        (yyval.expr)->type = BOOL;
        emit((yyval.expr)->loc,"1","",ASSIGN);
        (yyval.expr)->truelist = makelist(next_instr);
        emit("",(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,GOTO_GTE);
        emit((yyval.expr)->loc,"0","",ASSIGN);
        (yyval.expr)->falselist = makelist(next_instr);
        emit("", "", "", GOTO);
    }
#line 2646 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 49:
#line 666 "ass6_21CS10014_21CS30032.y"
                            { (yyval.expr) = new expression() ;(yyval.expr) = (yyvsp[0].expr); }
#line 2652 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 50:
#line 667 "ass6_21CS10014_21CS30032.y"
                                                      {
        
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        (yyval.expr) = new expression();
        (yyval.expr)->loc = current_symbol_table->gentemp();
        (yyval.expr)->type = BOOL;
        emit((yyval.expr)->loc,"1","",ASSIGN);
        (yyval.expr)->truelist = makelist(next_instr);
        emit("",(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,GOTO_EQ);
        emit((yyval.expr)->loc,"0","",ASSIGN);
        (yyval.expr)->falselist = makelist(next_instr);
        emit("", "", "", GOTO);
    }
#line 2688 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 51:
#line 698 "ass6_21CS10014_21CS30032.y"
                                                          {
        
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        (yyval.expr) = new expression();
        (yyval.expr)->loc = current_symbol_table->gentemp();
        (yyval.expr)->type = BOOL;
        emit((yyval.expr)->loc,"1","",ASSIGN);
        (yyval.expr)->truelist = makelist(next_instr);
        emit("",(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,GOTO_NEQ);
        emit((yyval.expr)->loc,"0","",ASSIGN);
        (yyval.expr)->falselist = makelist(next_instr);
        emit("", "", "", GOTO);
    }
#line 2724 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 52:
#line 732 "ass6_21CS10014_21CS30032.y"
                          {}
#line 2730 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 53:
#line 733 "ass6_21CS10014_21CS30032.y"
                                                 { 
        
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR) 
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR) 
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        (yyval.expr) = new expression();
        (yyval.expr)->loc = current_symbol_table->gentemp();
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,BITWISE_AND);
    }
#line 2760 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 54:
#line 761 "ass6_21CS10014_21CS30032.y"
                     { (yyval.expr) = (yyvsp[0].expr); }
#line 2766 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 55:
#line 762 "ass6_21CS10014_21CS30032.y"
                                                     {
        
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR) 
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR) 
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        (yyval.expr) = new expression();
        (yyval.expr)->loc = current_symbol_table->gentemp();
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,BITWISE_XOR);
    }
#line 2796 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 56:
#line 790 "ass6_21CS10014_21CS30032.y"
                              { (yyval.expr)=new expression() ;(yyval.expr) = (yyvsp[0].expr);}
#line 2802 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 57:
#line 791 "ass6_21CS10014_21CS30032.y"
                                                             {
        
        (yyval.expr) = new expression();
        symbol * s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol * s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);

        if(s2->type.type == ARR) 
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            (yyvsp[0].expr)->loc = temp;
            (yyvsp[0].expr)->type = s2->type.nextType;
        }
        if(s1->type.type == ARR) 
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,(yyvsp[-2].expr)->loc,*((yyvsp[-2].expr)->folder),ARR_IDX_ARG);
            (yyvsp[-2].expr)->loc = temp;
            (yyvsp[-2].expr)->type = s1->type.nextType;
        }

        (yyval.expr) = new expression();
        (yyval.expr)->loc = current_symbol_table->gentemp();
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,BITWISE_OR);
    }
#line 2832 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 58:
#line 819 "ass6_21CS10014_21CS30032.y"
                              {}
#line 2838 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 59:
#line 820 "ass6_21CS10014_21CS30032.y"
                                                                   {
        
        /* 
            here we have made few changes to the grammar to incorporate non terminal M to handle backpatching
        */

        backpatch((yyvsp[-3].expr)->truelist,(yyvsp[-1].expr)->instruction);
        (yyval.expr)->falselist = merge((yyvsp[-3].expr)->falselist,(yyvsp[0].expr)->falselist);
        (yyval.expr)->truelist = (yyvsp[0].expr)->truelist;
        (yyval.expr)->type = BOOL;
    }
#line 2854 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 60:
#line 834 "ass6_21CS10014_21CS30032.y"
                             {}
#line 2860 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 61:
#line 835 "ass6_21CS10014_21CS30032.y"
                                                                {
        
        backpatch((yyvsp[-3].expr)->falselist,(yyvsp[-1].expr)->instruction);
        (yyval.expr)->truelist = merge((yyvsp[-3].expr)->truelist,(yyvsp[0].expr)->truelist);
        (yyval.expr)->falselist = (yyvsp[0].expr)->falselist;
        (yyval.expr)->type = BOOL;
    }
#line 2872 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 62:
#line 847 "ass6_21CS10014_21CS30032.y"
                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2878 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 63:
#line 848 "ass6_21CS10014_21CS30032.y"
                                                                                          {
        symbol* s1 = current_symbol_table->lookup((yyvsp[-4].expr)->loc);
        (yyval.expr)->loc = current_symbol_table->gentemp(s1->type.type);
        (yyval.expr)->type = s1->type.type;

        emit((yyval.expr)->loc, (yyvsp[0].expr)->loc, "", ASSIGN);
        list<int> templist = makelist(next_instr);
        emit("", "", "", GOTO);
        backpatch((yyvsp[-3].expr)->nextlist, next_instr);
        emit((yyval.expr)->loc, (yyvsp[-4].expr)->loc, "", ASSIGN);
        list<int> temp = makelist(next_instr);
        templist = merge(templist, temp);
        emit("", "", "", GOTO);

        backpatch((yyvsp[-7].expr)->nextlist, next_instr);
        inttobool((yyvsp[-8].expr));
        backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-5].expr)->instruction);
        backpatch((yyvsp[-8].expr)->falselist, (yyvsp[-1].expr)->instruction);
        backpatch((yyvsp[-7].expr)->nextlist, next_instr);

    }
#line 2904 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 64:
#line 872 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.expr) = new expression();
        (yyval.expr)->instruction = next_instr;
    }
#line 2913 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 65:
#line 879 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.expr) = new expression();
        (yyval.expr)->nextlist = makelist(next_instr);
        emit("", "", "", GOTO);
    }
#line 2923 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 66:
#line 887 "ass6_21CS10014_21CS30032.y"
                             { /* No Action Taken */ }
#line 2929 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 67:
#line 888 "ass6_21CS10014_21CS30032.y"
                                                                 {
        symbol* s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol* s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);
        if ((yyvsp[-2].expr)->fold == 0)
        {
            if (s1->type.type != ARR) emit((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, "", ASSIGN);
            else emit((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, *((yyvsp[-2].expr)->folder), ARR_IDX_RES);
        }
        else emit(*((yyvsp[-2].expr)->folder), (yyvsp[0].expr)->loc, "", L_DEREF);

        (yyval.expr) = (yyvsp[-2].expr);
    }
#line 2946 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 68:
#line 904 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2952 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 69:
#line 906 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2958 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 70:
#line 908 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2964 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 71:
#line 910 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2970 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 72:
#line 912 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2976 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 73:
#line 914 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2982 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 74:
#line 916 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2988 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 75:
#line 918 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2994 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 76:
#line 920 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 3000 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 77:
#line 922 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 3006 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 78:
#line 924 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 3012 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 79:
#line 930 "ass6_21CS10014_21CS30032.y"
                            { /* No Action Taken */ }
#line 3018 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 80:
#line 931 "ass6_21CS10014_21CS30032.y"
                                             { /* No Action Taken */ }
#line 3024 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 81:
#line 935 "ass6_21CS10014_21CS30032.y"
                             { /* No Action Taken */ }
#line 3030 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 82:
#line 940 "ass6_21CS10014_21CS30032.y"
                                       { /* No Action Taken */ }
#line 3036 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 83:
#line 942 "ass6_21CS10014_21CS30032.y"
    {
        data_type curr_type = (yyvsp[-2].types);
        int curr_size = -1;
        if (curr_type == INT) curr_size = SIZE_OF_INT;
        else if (curr_type == FLOAT) curr_size = SIZE_OF_FLOAT;
        else if (curr_type == CHAR) curr_size = SIZE_OF_CHAR;

        vector<declaration*> decl_list = *((yyvsp[-1].dec_list));
        for (vector<declaration*>::iterator it = decl_list.begin();it!=decl_list.end();it++)
        {
            declaration* curr_decl = *it;
            if (curr_decl->type == FUNC)
            {
                current_symbol_table = &global_symbol_table;
                emit(curr_decl->name, "", "", FUNC_END);
                symbol* s1 = current_symbol_table->lookup(curr_decl->name);
                symbol* s2 = s1->nested_table->lookup("RETVAL", curr_type, curr_decl->ptrs);
                s1->size = 0;
                s1->initial_value = NULL;
                continue ;
            }

            symbol* s3 = current_symbol_table->lookup(curr_decl->name, curr_type);
            s3->nested_table = NULL;

            if(curr_decl->instr_list == vector<int>() && curr_decl->ptrs == 0)
            {
                s3->size = curr_size;
                s3->type.type = curr_type;
                if (curr_decl->initial_value)
                {
                    string rval = curr_decl->initial_value->loc;
                    emit(s3->name, rval, "", ASSIGN);
                    s3->initial_value = current_symbol_table->lookup(rval)->initial_value;
                }
                else s3->initial_value = NULL;
            }

            else if (curr_decl->instr_list != vector<int>())
            {
                s3->type.type = ARR;
                s3->type.nextType = curr_type;
                s3->type.dimensions = curr_decl->instr_list;
                vector<int> temp = s3->type.dimensions;

                int temp_size = curr_size;
                for (int i = 0; i < temp.size(); i++)
                {
                    temp_size *= temp[i];
                }
                current_symbol_table->offset += temp_size;
                s3->size = temp_size;
                current_symbol_table->offset -= 4;
            }

            else if (curr_decl->ptrs != 0)
            {
                s3->type.type = PTR;
                s3->type.nextType = curr_type;
                s3->type.ptr = curr_decl->ptrs;
                current_symbol_table->offset += (SIZE_OF_PTR - curr_size);
                s3->size = SIZE_OF_PTR;
            }
        }
    }
#line 3106 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 84:
#line 1011 "ass6_21CS10014_21CS30032.y"
        {}
#line 3112 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 85:
#line 1013 "ass6_21CS10014_21CS30032.y"
        {}
#line 3118 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 86:
#line 1015 "ass6_21CS10014_21CS30032.y"
        {}
#line 3124 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 87:
#line 1017 "ass6_21CS10014_21CS30032.y"
        {}
#line 3130 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 88:
#line 1019 "ass6_21CS10014_21CS30032.y"
        {}
#line 3136 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 89:
#line 1021 "ass6_21CS10014_21CS30032.y"
        {}
#line 3142 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 90:
#line 1023 "ass6_21CS10014_21CS30032.y"
        {}
#line 3148 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 91:
#line 1025 "ass6_21CS10014_21CS30032.y"
        {}
#line 3154 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 92:
#line 1029 "ass6_21CS10014_21CS30032.y"
                      { 
        (yyval.dec_list) = new vector<declaration*>;
        (yyval.dec_list)->push_back((yyvsp[0].dec));
     }
#line 3163 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 93:
#line 1033 "ass6_21CS10014_21CS30032.y"
                                                 {
        (yyvsp[-2].dec_list)->push_back((yyvsp[0].dec));
        (yyval.dec_list) = (yyvsp[-2].dec_list);
    }
#line 3172 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 94:
#line 1041 "ass6_21CS10014_21CS30032.y"
    { 
        (yyval.dec) = (yyvsp[0].dec);
        (yyval.dec)->initial_value = NULL;
    }
#line 3181 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 95:
#line 1046 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.dec) = (yyvsp[-2].dec);
        (yyval.dec)->initial_value = (yyvsp[0].expr);
    }
#line 3190 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 96:
#line 1053 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3196 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 97:
#line 1054 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3202 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 98:
#line 1055 "ass6_21CS10014_21CS30032.y"
           { /* No Action Taken */ }
#line 3208 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 99:
#line 1056 "ass6_21CS10014_21CS30032.y"
               { /* No Action Taken */ }
#line 3214 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 100:
#line 1062 "ass6_21CS10014_21CS30032.y"
             { (yyval.types) = VOID; }
#line 3220 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 101:
#line 1063 "ass6_21CS10014_21CS30032.y"
             { (yyval.types) = CHAR; }
#line 3226 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 102:
#line 1064 "ass6_21CS10014_21CS30032.y"
            { /* No Action Taken */ }
#line 3232 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 103:
#line 1065 "ass6_21CS10014_21CS30032.y"
            { (yyval.types) = INT; }
#line 3238 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 104:
#line 1066 "ass6_21CS10014_21CS30032.y"
           { /* No Action Taken */ }
#line 3244 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 105:
#line 1067 "ass6_21CS10014_21CS30032.y"
              { (yyval.types) = FLOAT; }
#line 3250 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 106:
#line 1068 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3256 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 107:
#line 1069 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3262 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 108:
#line 1070 "ass6_21CS10014_21CS30032.y"
               { /* No Action Taken */ }
#line 3268 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 109:
#line 1071 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3274 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 110:
#line 1072 "ass6_21CS10014_21CS30032.y"
              { /* No Action Taken */ }
#line 3280 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 111:
#line 1073 "ass6_21CS10014_21CS30032.y"
                { /* No Action Taken */ }
#line 3286 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 112:
#line 1074 "ass6_21CS10014_21CS30032.y"
                     { /* No Action Taken */ }
#line 3292 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 113:
#line 1078 "ass6_21CS10014_21CS30032.y"
                                                  { /* No Action Taken */ }
#line 3298 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 114:
#line 1079 "ass6_21CS10014_21CS30032.y"
                                                  { /* No Action Taken */ }
#line 3304 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 115:
#line 1083 "ass6_21CS10014_21CS30032.y"
                               { /* No Action Taken */ }
#line 3310 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 116:
#line 1085 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */ }
#line 3316 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 117:
#line 1089 "ass6_21CS10014_21CS30032.y"
                                                                                 { /* No Action Taken */ }
#line 3322 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 118:
#line 1090 "ass6_21CS10014_21CS30032.y"
                                                                                       { /* No Action Taken */ }
#line 3328 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 119:
#line 1091 "ass6_21CS10014_21CS30032.y"
                      { /* No Action Taken */ }
#line 3334 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 120:
#line 1095 "ass6_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3340 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 121:
#line 1096 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3346 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 122:
#line 1100 "ass6_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3352 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 123:
#line 1101 "ass6_21CS10014_21CS30032.y"
                                       { /* No Action Taken */ }
#line 3358 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 124:
#line 1105 "ass6_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3364 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 125:
#line 1106 "ass6_21CS10014_21CS30032.y"
                                              { /* No Action Taken */ }
#line 3370 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 126:
#line 1110 "ass6_21CS10014_21CS30032.y"
            { /* No Action Taken */ }
#line 3376 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 127:
#line 1111 "ass6_21CS10014_21CS30032.y"
               { /* No Action Taken */ }
#line 3382 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 128:
#line 1112 "ass6_21CS10014_21CS30032.y"
               { /* No Action Taken */ }
#line 3388 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 129:
#line 1116 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3394 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 130:
#line 1122 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.dec) = (yyvsp[0].dec);
        (yyval.dec)->ptrs = (yyvsp[-1].intval);
    }
#line 3403 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 131:
#line 1127 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.dec) = (yyvsp[0].dec);
        (yyval.dec)->ptrs = 0;
    }
#line 3412 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 132:
#line 1135 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.dec) = new declaration();
        (yyval.dec)->name = *((yyvsp[0].str));
    }
#line 3421 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 133:
#line 1140 "ass6_21CS10014_21CS30032.y"
    {
        /* No Action Taken */
    }
#line 3429 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 134:
#line 1144 "ass6_21CS10014_21CS30032.y"
    {
        (yyvsp[-3].dec)->type = ARR;
        (yyvsp[-3].dec)->next_type = INT;
        (yyval.dec) = (yyvsp[-3].dec);
        (yyval.dec)->instr_list.push_back(0); 
    }
#line 3440 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 135:
#line 1151 "ass6_21CS10014_21CS30032.y"
    {
        /* No Action Taken */
    }
#line 3448 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 136:
#line 1155 "ass6_21CS10014_21CS30032.y"
    {
        /* No Action Taken */
    }
#line 3456 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 137:
#line 1159 "ass6_21CS10014_21CS30032.y"
    {
        (yyvsp[-4].dec)->type = ARR;
        (yyvsp[-4].dec)->next_type = INT;
        (yyval.dec) = (yyvsp[-4].dec);
        int id = current_symbol_table->lookup((yyvsp[-1].expr)->loc)->initial_value->int_val;
        (yyval.dec)->instr_list.push_back(id);
        // check
    }
#line 3469 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 138:
#line 1168 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.dec) = (yyvsp[-3].dec);
        (yyval.dec)->type = FUNC;
        symbol* s1 = current_symbol_table->lookup((yyval.dec)->name, (yyval.dec)->type);
        symbol_table* st = new symbol_table();
        s1->nested_table = st;

        vector<param*> param_list = *((yyvsp[-1].p_list));
        for (int i = 0; i < param_list.size(); i++)
        {
            param* curr_param = param_list[i];
            
            if (curr_param->type.type == ARR)
            {
                st->lookup(curr_param->name, curr_param->type.type);
                st->lookup(curr_param->name)->type.nextType = INT;
                st->lookup(curr_param->name)->type.dimensions.push_back(0);
            }
            
            else if (curr_param->type.type == PTR)
            {
                st->lookup(curr_param->name, curr_param->type.type);
                st->lookup(curr_param->name)->type.nextType = INT;
                st->lookup(curr_param->name)->type.dimensions.push_back(0);
            }
            
            else
            {
                st->lookup(curr_param->name, curr_param->type.type);
            }
        }

        current_symbol_table = st;
        emit((yyvsp[-3].dec)->name, "", "", FUNC_BEG);
    }
#line 3509 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 139:
#line 1204 "ass6_21CS10014_21CS30032.y"
    {
        /* No Action Taken */
    }
#line 3517 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 140:
#line 1208 "ass6_21CS10014_21CS30032.y"
    {
        (yyvsp[-4].dec)->type = PTR;
        (yyvsp[-4].dec)->next_type = INT;
        (yyval.dec) = (yyvsp[-4].dec);
    }
#line 3527 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 141:
#line 1217 "ass6_21CS10014_21CS30032.y"
        {}
#line 3533 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 142:
#line 1219 "ass6_21CS10014_21CS30032.y"
        {
            (yyval.p_list) = new vector<param*>;
        }
#line 3541 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 143:
#line 1227 "ass6_21CS10014_21CS30032.y"
                          { /* No Action Taken */ }
#line 3547 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 144:
#line 1228 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3553 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 145:
#line 1232 "ass6_21CS10014_21CS30032.y"
                                   { /* No Action Taken */ }
#line 3559 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 146:
#line 1233 "ass6_21CS10014_21CS30032.y"
                                           { /* No Action Taken */ }
#line 3565 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 147:
#line 1234 "ass6_21CS10014_21CS30032.y"
                       { (yyval.intval) = 1+(yyvsp[0].intval); }
#line 3571 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 148:
#line 1235 "ass6_21CS10014_21CS30032.y"
               { /* No Action Taken */ }
#line 3577 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 149:
#line 1239 "ass6_21CS10014_21CS30032.y"
                     { /* No Action Taken */ }
#line 3583 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 150:
#line 1240 "ass6_21CS10014_21CS30032.y"
                                         { /* No Action Taken */ }
#line 3589 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 151:
#line 1244 "ass6_21CS10014_21CS30032.y"
                     { /* No Action Taken */ }
#line 3595 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 152:
#line 1245 "ass6_21CS10014_21CS30032.y"
                                    { /* No Action Taken */ }
#line 3601 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 153:
#line 1250 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.p_list) = new vector<param*>();
        (yyval.p_list)->push_back((yyvsp[0].p));
    }
#line 3610 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 154:
#line 1255 "ass6_21CS10014_21CS30032.y"
    {
        (yyvsp[-2].p_list)->push_back((yyvsp[0].p));  
        (yyval.p_list) = (yyvsp[-2].p_list);
    }
#line 3619 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 155:
#line 1263 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.p) = new param();
        (yyval.p)->name = (yyvsp[0].dec)->name;
        if ((yyvsp[0].dec)->type == ARR)
        {
            (yyval.p)->type.type = ARR;
            (yyval.p)->type.nextType = (yyvsp[-1].types);
        }
        else if ((yyvsp[0].dec)->pc)
        {
            (yyval.p)->type.type = PTR;
            (yyval.p)->type.nextType = (yyvsp[-1].types);
        }
        else
        {
            (yyval.p)->type.type = (yyvsp[-1].types);
        }
    }
#line 3642 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 156:
#line 1281 "ass6_21CS10014_21CS30032.y"
                             { /* No Action Taken */ }
#line 3648 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 157:
#line 1285 "ass6_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3654 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 158:
#line 1286 "ass6_21CS10014_21CS30032.y"
                                       { /* No Action Taken */ }
#line 3660 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 159:
#line 1290 "ass6_21CS10014_21CS30032.y"
                               { /* No Action Taken */ }
#line 3666 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 160:
#line 1294 "ass6_21CS10014_21CS30032.y"
                            { /* No Action Taken */ }
#line 3672 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 161:
#line 1295 "ass6_21CS10014_21CS30032.y"
                                                              { /* No Action Taken */ }
#line 3678 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 162:
#line 1296 "ass6_21CS10014_21CS30032.y"
                                                                    { /* No Action Taken */ }
#line 3684 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 163:
#line 1300 "ass6_21CS10014_21CS30032.y"
                                  { /* No Action Taken */ }
#line 3690 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 164:
#line 1301 "ass6_21CS10014_21CS30032.y"
                                                         { /* No Action Taken */ }
#line 3696 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 165:
#line 1305 "ass6_21CS10014_21CS30032.y"
                  { /* No Action Taken */ }
#line 3702 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 166:
#line 1306 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3708 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 167:
#line 1310 "ass6_21CS10014_21CS30032.y"
                               { /* No Action Taken */ }
#line 3714 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 168:
#line 1314 "ass6_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3720 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 169:
#line 1315 "ass6_21CS10014_21CS30032.y"
                                 { /* No Action Taken */ }
#line 3726 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 170:
#line 1319 "ass6_21CS10014_21CS30032.y"
                                                                   { /* No Action Taken */ }
#line 3732 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 171:
#line 1320 "ass6_21CS10014_21CS30032.y"
                     { /* No Action Taken */ }
#line 3738 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 172:
#line 1324 "ass6_21CS10014_21CS30032.y"
                        { /* No Action Taken */ }
#line 3744 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 173:
#line 1325 "ass6_21CS10014_21CS30032.y"
                         { /* No Action Taken */ }
#line 3750 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 174:
#line 1326 "ass6_21CS10014_21CS30032.y"
                           { /* No Action Taken */ }
#line 3756 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 175:
#line 1327 "ass6_21CS10014_21CS30032.y"
                          { /* No Action Taken */ }
#line 3762 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 176:
#line 1328 "ass6_21CS10014_21CS30032.y"
                          { /* No Action Taken */ }
#line 3768 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 177:
#line 1329 "ass6_21CS10014_21CS30032.y"
                     { /* No Action Taken */ }
#line 3774 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 178:
#line 1333 "ass6_21CS10014_21CS30032.y"
                                 { /* No Action Taken */ }
#line 3780 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 179:
#line 1334 "ass6_21CS10014_21CS30032.y"
                                               { /* No Action Taken */ }
#line 3786 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 180:
#line 1335 "ass6_21CS10014_21CS30032.y"
                              { /* No Action Taken */ }
#line 3792 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 181:
#line 1339 "ass6_21CS10014_21CS30032.y"
                                             { /* No Action Taken */ }
#line 3798 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 182:
#line 1340 "ass6_21CS10014_21CS30032.y"
                                                             { (yyval.expr) = (yyvsp[-1].expr); }
#line 3804 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 183:
#line 1345 "ass6_21CS10014_21CS30032.y"
    { 
        (yyval.expr) = (yyvsp[0].expr); 
        backpatch((yyvsp[0].expr)->nextlist, next_instr);
    }
#line 3813 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 184:
#line 1350 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.expr) = new expression();
        backpatch((yyvsp[-2].expr)->nextlist, (yyvsp[-1].expr)->instruction);
        (yyval.expr)->nextlist = (yyvsp[0].expr)->nextlist;
    }
#line 3823 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 185:
#line 1358 "ass6_21CS10014_21CS30032.y"
                  { (yyval.expr) = new expression(); }
#line 3829 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 186:
#line 1359 "ass6_21CS10014_21CS30032.y"
                { /* No Action Taken */ }
#line 3835 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 187:
#line 1363 "ass6_21CS10014_21CS30032.y"
                           { /* No Action Taken */ }
#line 3841 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 188:
#line 1364 "ass6_21CS10014_21CS30032.y"
                { (yyval.expr) = new expression(); }
#line 3847 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 189:
#line 1368 "ass6_21CS10014_21CS30032.y"
    {
        backpatch((yyvsp[-4].expr)->nextlist, next_instr);
        inttobool((yyvsp[-5].expr));
        (yyval.expr) = new expression();
        backpatch((yyvsp[-5].expr)->truelist, (yyvsp[-2].expr)->instruction);

        (yyvsp[-1].expr)->nextlist = merge((yyvsp[0].expr)->nextlist, (yyvsp[-1].expr)->nextlist);
        (yyval.expr)->nextlist = merge((yyvsp[-5].expr)->falselist, (yyvsp[-1].expr)->nextlist);
    }
#line 3861 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 190:
#line 1378 "ass6_21CS10014_21CS30032.y"
    {
        backpatch((yyvsp[-8].expr)->nextlist, next_instr);
        inttobool((yyvsp[-9].expr));
        (yyval.expr) = new expression();
        backpatch((yyvsp[-9].expr)->truelist, (yyvsp[-6].expr)->instruction);
        backpatch((yyvsp[-9].expr)->falselist, (yyvsp[-2].expr)->instruction);

        (yyval.expr)->nextlist = merge((yyvsp[-5].expr)->nextlist, (yyvsp[-4].expr)->nextlist);
        (yyval.expr)->nextlist = merge((yyval.expr)->nextlist, (yyvsp[-1].expr)->nextlist);
        (yyval.expr)->nextlist = merge((yyval.expr)->nextlist, (yyvsp[0].expr)->nextlist);
    }
#line 3877 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 191:
#line 1389 "ass6_21CS10014_21CS30032.y"
                                                                         { /* No Action Taken */ }
#line 3883 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 192:
#line 1394 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.expr) = new expression();
        emit("", "", "", GOTO);
        backpatch(makelist(next_instr-1), (yyvsp[-6].expr)->instruction);
        backpatch((yyvsp[-3].expr)->nextlist, next_instr);
        inttobool((yyvsp[-4].expr));
        (yyval.expr)->nextlist = (yyvsp[-4].expr)->falselist;
        backpatch((yyvsp[-4].expr)->truelist, (yyvsp[-1].expr)->instruction);
        backpatch((yyvsp[0].expr)->nextlist, (yyvsp[-6].expr)->instruction);
    }
#line 3898 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 193:
#line 1405 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.expr) = new expression();
        backpatch((yyvsp[-2].expr)->nextlist, next_instr);
        inttobool((yyvsp[-3].expr));
        (yyval.expr)->nextlist = (yyvsp[-3].expr)->falselist;
        backpatch((yyvsp[-3].expr)->truelist, (yyvsp[-8].expr)->instruction);
        backpatch((yyvsp[-7].expr)->nextlist, (yyvsp[-6].expr)->instruction);
    }
#line 3911 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 194:
#line 1414 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.expr) = new expression();
        emit("", "", "", GOTO);
        auto temp = makelist(next_instr-1);
        (yyvsp[0].expr)->nextlist = merge((yyvsp[0].expr)->nextlist, temp);
        backpatch((yyvsp[0].expr)->nextlist, (yyvsp[-5].expr)->instruction);
        backpatch((yyvsp[-6].expr)->nextlist, next_instr);
        backpatch((yyvsp[-3].expr)->nextlist, (yyvsp[-8].expr)->instruction);
        inttobool((yyvsp[-7].expr));
        backpatch((yyvsp[-7].expr)->truelist, (yyvsp[-1].expr)->instruction);
        (yyval.expr)->nextlist = (yyvsp[-7].expr)->falselist;
    }
#line 3928 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 195:
#line 1429 "ass6_21CS10014_21CS30032.y"
                                  { /* No Action Taken */ }
#line 3934 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 196:
#line 1430 "ass6_21CS10014_21CS30032.y"
                         { /* No Action Taken */ }
#line 3940 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 197:
#line 1431 "ass6_21CS10014_21CS30032.y"
                      { /* No Action Taken */ }
#line 3946 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 198:
#line 1433 "ass6_21CS10014_21CS30032.y"
    {
        if (current_symbol_table->lookup("RETVAL")->type.type == VOID) emit("", "", "", RETURN);
        (yyval.expr) = new expression();
    }
#line 3955 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 199:
#line 1438 "ass6_21CS10014_21CS30032.y"
    {
        if (current_symbol_table->lookup("RETVAL")->type.type == current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type.type) emit((yyvsp[-1].expr)->loc, "", "", RETURN);
        (yyval.expr) = new expression();
    }
#line 3964 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 200:
#line 1446 "ass6_21CS10014_21CS30032.y"
                           { /* No Action Taken */ }
#line 3970 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 201:
#line 1447 "ass6_21CS10014_21CS30032.y"
                                            { /* No Action Taken */ }
#line 3976 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 202:
#line 1451 "ass6_21CS10014_21CS30032.y"
                          { /* No Action Taken */ }
#line 3982 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 203:
#line 1452 "ass6_21CS10014_21CS30032.y"
                  { /* No Action Taken */ }
#line 3988 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 204:
#line 1457 "ass6_21CS10014_21CS30032.y"
                                                                            { /* No Action Taken */ }
#line 3994 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 205:
#line 1459 "ass6_21CS10014_21CS30032.y"
    {
        current_symbol_table = &global_symbol_table;
        emit((yyvsp[-1].dec)->name, "", "", FUNC_END);
    }
#line 4003 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 206:
#line 1467 "ass6_21CS10014_21CS30032.y"
    {
        data_type temp = (yyvsp[-1].types);
        int size = 0;
        if (temp == CHAR) size = SIZE_OF_CHAR;
        else if (temp == INT) size = SIZE_OF_INT;
        else if (temp == FLOAT) size = SIZE_OF_FLOAT;
        declaration* new1 = (yyvsp[0].dec);
        symbol* new2 = current_symbol_table->lookup(new1->name);
        if (new1->type == FUNC)
        {
            symbol* return_value = new2->nested_table->lookup("RETVAL", temp, new1->ptrs);
            new2->size = 0;
            new2->initial_value = NULL;
        }
        (yyval.dec) = (yyvsp[0].dec);
    }
#line 4024 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 207:
#line 1485 "ass6_21CS10014_21CS30032.y"
                  { /* No Action Taken */ }
#line 4030 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 208:
#line 1486 "ass6_21CS10014_21CS30032.y"
                                   { /* No Action Taken */ }
#line 4036 "ass6_21CS10014_21CS30032.tab.c"
    break;


#line 4040 "ass6_21CS10014_21CS30032.tab.c"

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
#line 1489 "ass6_21CS10014_21CS30032.y"


void yyerror(string s) {
    // for error reporting
    cout << "Error: " << s << endl;
    cout << "Line: " << yylineno << endl;
    cout << "Text: " << yytext << endl;
}
