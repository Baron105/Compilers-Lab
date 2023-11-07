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
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  204
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
     834,   835,   847,   848,   870,   877,   886,   887,   902,   904,
     906,   908,   910,   912,   914,   916,   918,   920,   922,   929,
     930,   934,   939,   940,  1007,  1008,  1009,  1010,  1014,  1015,
    1020,  1021,  1025,  1030,  1038,  1039,  1040,  1041,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,
    1059,  1063,  1064,  1068,  1069,  1074,  1075,  1076,  1080,  1081,
    1085,  1086,  1090,  1091,  1095,  1096,  1097,  1101,  1106,  1111,
    1119,  1124,  1128,  1135,  1139,  1143,  1151,  1187,  1191,  1202,
    1203,  1207,  1208,  1209,  1210,  1214,  1215,  1219,  1220,  1224,
    1229,  1237,  1256,  1260,  1261,  1265,  1269,  1270,  1271,  1275,
    1276,  1280,  1281,  1285,  1289,  1290,  1294,  1295,  1299,  1300,
    1301,  1302,  1303,  1304,  1308,  1309,  1310,  1314,  1315,  1319,
    1324,  1333,  1334,  1338,  1339,  1342,  1351,  1361,  1365,  1376,
    1385,  1400,  1401,  1402,  1403,  1408,  1417,  1418,  1422,  1423,
    1428,  1429,  1437,  1456,  1457
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
  "declaration", "declaration_specifiers", "declaration_specifiers_opt",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "specifier_qualifier_list",
  "specifier_qualifier_list_opt", "enum_specifier", "identifier_opt",
  "enumerator_list", "enumerator", "type_qualifier", "function_specifier",
  "declarator", "direct_declarator", "type_qualifier_list_opt", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name", "initializer",
  "initializer_list", "designation_opt", "designation", "designator_list",
  "designator", "statement", "labeled_statement", "compound_statement",
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

#define YYPACT_NINF (-271)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-203)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1105,  -271,  -271,  -271,  -271,   -54,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,   -19,  1105,  1105,  -271,  1105,  1105,  1068,
    -271,  -271,     5,    26,    32,   -18,    -1,  -271,  -271,   -21,
    -271,   691,    54,   -17,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,   292,  -271,    -8,    57,  -271,  -271,    -1,   -18,  -271,
     695,  -271,   -19,  1028,    85,   470,    54,    24,   873,    56,
      33,  -271,   101,    63,   105,   715,   923,   119,  -271,   565,
    -271,   939,   939,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,    81,  -271,   171,   152,   873,  -271,
     117,   136,   142,   120,   166,   115,   139,   116,   134,     4,
    -271,  -271,    38,  -271,  -271,  -271,  -271,   124,  -271,  -271,
    -271,  -271,  -271,   128,   -27,  -271,  -271,  -271,  -271,  -271,
     130,    -4,  -271,  -271,  -271,  -271,  -271,    45,   739,   155,
    -271,   -18,   159,   131,  -271,   -15,  -271,  -271,  -271,   127,
    -271,   506,   506,   783,   153,   873,  -271,    61,   565,  -271,
     873,   200,    -2,  1139,  -271,  1139,   212,   565,  -271,  -271,
     506,   873,   807,   169,   174,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,   873,  -271,
     873,   873,   873,   873,   873,   873,   873,   873,   873,   873,
     873,   873,   873,   873,   873,   873,  -271,  -271,   172,   873,
    -271,  -271,   381,   873,  -271,   -16,   873,   175,     0,   695,
    -271,    17,  -271,   873,    45,  -271,   217,   221,   873,  -271,
    -271,   654,  -271,   176,   506,  -271,  -271,  -271,  -271,   187,
    -271,   226,     1,   873,  -271,  -271,  -271,  -271,   857,   227,
    -271,   -34,  -271,     3,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,   117,   117,   136,   136,   142,   142,   142,   142,   120,
     120,   166,   115,   139,   873,   873,  -271,  -271,  -271,  -271,
    -271,  -271,   232,  -271,  -271,    71,  -271,  -271,  -271,   233,
    -271,  -271,   236,  -271,  -271,  -271,  -271,   242,   783,   238,
     235,   506,   187,    -4,  -271,   235,  -271,  -271,   873,   116,
     134,   873,  -271,  -271,   695,  -271,  -271,   240,  -271,  -271,
    -271,   241,    10,  -271,   187,  -271,   873,  -271,   506,  -271,
    -271,   110,   203,   187,   873,  -271,   506,  -271,  -271,   243,
     187,   275,  -271,   873,   206,   247,  -271,  -271,  -271,  -271,
     506,   506,  -271,  -271,  -271
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    96,    99,   124,   104,   119,    94,   103,   127,   101,
     102,    97,   125,   100,   105,    95,   106,    98,   126,   107,
     108,   109,   199,     0,    89,    89,   110,    89,    89,     0,
     196,   198,     0,   117,     0,     0,   144,    82,   130,     0,
      90,    92,   129,     0,    88,    84,    85,    86,    87,     1,
     197,     0,   201,     0,     0,   145,   143,   141,     0,    83,
       0,   203,     0,     0,   140,     0,   128,     0,     0,     0,
       0,    64,     0,     0,     0,     0,     0,     0,    64,     0,
     177,     0,     0,    26,    30,    31,    27,    28,    29,   184,
       6,     5,     3,     4,     2,     8,    20,    32,     0,    34,
      38,    41,    44,    49,    52,    54,    56,    58,    60,    62,
      66,    79,     0,   181,   182,   168,   169,    64,   179,   170,
     171,   172,   173,   122,     0,   120,   131,   146,   142,    91,
      92,   162,     2,   156,    93,   204,   200,   140,     0,   139,
     153,   152,     0,   147,   149,     0,   193,    32,    81,     0,
     192,     0,     0,     0,     0,     0,   194,     0,     0,    24,
       0,     0,     0,   114,   155,   114,     0,     0,    21,    22,
       0,     0,     0,     0,     0,    14,    15,    68,    72,    73,
      69,    70,    71,    74,    75,    76,    77,    78,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    64,     0,     0,
     183,   178,     0,     0,   115,     0,     0,     0,     0,     0,
     161,     0,   164,     0,   139,   132,    27,     0,     0,   151,
     136,     0,   137,     0,     0,   176,    64,    64,   191,    65,
     195,     0,     0,     0,     7,   113,   111,   112,     0,     0,
     174,     0,    10,     0,    18,    12,    13,    67,    35,    36,
      37,    39,    40,    42,    43,    45,    46,    47,    48,    50,
      51,    53,    55,    57,     0,     0,    64,    80,   180,   123,
     116,   121,     0,   167,   157,   162,   159,   163,   165,     0,
     138,   135,     0,   148,   150,   154,   175,     0,     0,     0,
      25,     0,    65,   162,    33,     0,     9,    11,     0,    59,
      61,     0,   166,   158,     0,   133,   134,     0,    65,    64,
     187,     0,     0,    19,    65,   160,     0,    64,     0,    64,
      16,   162,     0,    65,     0,    65,     0,    17,    64,     0,
      65,   185,   188,     0,     0,     0,    64,    63,   189,    64,
       0,     0,    65,   190,   186
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -271,  -271,  -271,  -271,   -68,  -271,   -88,    46,    53,    47,
      49,    88,    89,    87,    30,    48,  -271,   -67,   -66,   -81,
     -20,  -271,   -70,  -107,   -30,     2,   167,  -271,   263,  -271,
     -53,    -6,   168,  -271,  -271,  -271,   109,    14,  -271,    -3,
     289,   198,    12,   -60,  -271,  -271,   107,  -271,   -72,  -216,
      36,  -270,  -271,  -271,   122,  -135,  -271,    -5,  -271,   132,
    -134,  -271,  -271,  -271,  -271,   317,  -271,  -271,  -271
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    95,    96,   253,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   152,   208,
     111,   188,   112,   149,    22,    44,    45,    39,    40,    24,
      25,   164,   246,    26,    34,   124,   125,    27,    28,   130,
      42,   138,    43,    57,   142,   143,   144,   145,   166,   134,
     218,   219,   220,   221,   222,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    29,    30,    31,    32,    63
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     147,   148,    23,   286,   139,   157,     3,   306,   159,   162,
     189,    61,   161,   168,   169,   314,   235,   236,   214,   237,
      41,   113,    12,    35,    35,    35,   163,    52,   232,   280,
     147,    23,    54,   135,    18,   250,   216,    33,    36,    36,
     133,   244,   217,    62,   301,   284,   307,   209,    56,    51,
      55,   212,     3,    62,   215,   330,    36,   216,   136,   207,
      58,   314,    59,   217,    37,    62,   233,   141,    12,   128,
    -118,   127,    38,    38,    38,   123,    53,   224,    55,   209,
      18,   285,   209,   123,   308,   239,   241,   287,   162,   -65,
     242,   331,     3,   165,    64,   249,    65,   162,   325,   296,
     126,   251,   258,   259,   260,   163,   279,   146,    12,   282,
     163,   216,   163,   137,   163,   151,   313,   217,   227,   209,
      18,   210,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   229,   150,
     274,   275,   209,   153,   240,   147,   148,   155,   147,   148,
     216,    55,   254,   127,   154,   337,   217,   245,   299,   245,
     304,   160,     3,   170,   318,   203,   320,   205,   257,   211,
     297,   298,   165,   302,   190,   191,   192,   165,    12,   165,
     147,   165,   113,   228,   197,   198,   199,   200,   206,   277,
      18,   204,    46,   335,    47,    48,   193,   194,   213,   133,
      60,   342,   230,   289,   195,   196,   147,   147,   292,   234,
     311,   171,   231,   172,    62,   352,   353,   173,   174,   175,
     176,   321,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   141,   201,   202,   238,   327,   127,   261,
     262,   324,   243,   332,   265,   266,   267,   268,   263,   264,
     269,   270,   339,   328,   341,   248,   333,   276,   290,   345,
     255,   334,   291,   336,   340,   256,   283,   295,   209,   300,
     305,   354,   343,   312,   315,   147,   347,   316,   317,   303,
     350,   319,   326,   351,   329,   338,   344,   346,   323,   348,
     349,   271,   273,   272,   133,     1,    67,    68,     2,     3,
      69,    70,    71,     4,   309,     5,     6,     7,    72,    73,
      74,     8,     9,    10,    11,    12,    75,    13,    14,    76,
      15,   129,    77,   310,   281,    16,    17,    18,    78,    19,
      20,    21,    66,   247,    79,   223,    51,    80,   294,   322,
      81,    82,    83,   288,   278,    84,    50,     0,    85,    86,
       0,     0,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,    90,
      91,    92,    93,    94,     1,    67,    68,     2,     3,    69,
      70,    71,     4,     0,     5,     6,     7,    72,    73,    74,
       8,     9,    10,    11,    12,    75,    13,    14,    76,    15,
       0,    77,     0,     0,    16,    17,    18,    78,    19,    20,
      21,     0,     0,    79,     0,    51,     0,     0,     0,    81,
      82,    83,     0,     0,    84,     0,     0,    85,    86,     0,
       0,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,    90,    91,
      92,    93,    94,     1,     0,     0,     2,     3,     0,     0,
       0,     4,     0,     5,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,     0,    13,    14,     0,    15,     0,
       0,     0,     0,    16,    17,    18,     0,    19,    20,    21,
      67,    68,     0,     0,    69,    70,    71,     0,     0,     0,
       0,     0,    72,    73,    74,     0,     0,     0,     0,     0,
      75,     0,     0,    76,     0,     0,    77,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,    79,     0,
      51,     0,     0,     0,    81,    82,    83,     0,     0,    84,
       0,   140,    85,    86,     0,     0,    87,    88,     0,     0,
       0,     2,     3,     0,     0,     0,     4,     0,     5,     0,
       7,     0,     0,     0,     0,     9,    10,     0,    12,    89,
      13,    14,    76,    90,    91,    92,    93,    94,    16,    17,
      18,     0,    19,    20,    21,     0,     0,    79,     0,     0,
       0,     0,     0,    81,    82,    83,     0,     0,    84,     0,
       0,    85,    86,     0,     0,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,   132,     1,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     5,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,     0,    13,
      14,     0,    15,     0,     0,     0,     0,    16,    17,    18,
       0,    19,    20,    21,     1,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     5,     6,     7,     0,     0,     0,
       8,     9,    10,    11,    12,     0,    13,    14,     0,    15,
       0,     0,    76,     0,    16,    17,    18,     0,    19,    20,
      21,     0,     0,     0,     0,  -202,     0,    79,   293,   131,
       0,     0,    76,    81,    82,    83,     0,     0,    84,     0,
       0,    85,    86,     0,     0,    87,    88,    79,     0,     0,
       0,    60,     0,    81,    82,    83,    76,     0,    84,     0,
       0,    85,    86,     0,     0,    87,    88,     0,     0,     0,
     225,    79,    90,    91,    92,    93,   132,    81,    82,    83,
       0,     0,    84,     0,     0,    85,   226,     0,   156,    87,
      88,     0,    90,    91,    92,    93,   132,     0,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    90,    91,    92,    93,
     132,    81,    82,    83,    76,     0,    84,     0,     0,    85,
      86,     0,     0,    87,    88,     0,     0,     0,     0,    79,
     252,     0,     0,     0,     0,    81,    82,    83,     0,     0,
      84,     0,     0,    85,    86,     0,    89,    87,    88,     0,
      90,    91,    92,    93,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,   132,    79,
      76,   303,     0,     0,     0,    81,    82,    83,     0,     0,
      84,     0,     0,    85,    86,    79,     0,    87,    88,     0,
       0,    81,    82,    83,     0,     0,    84,     0,     0,    85,
      86,     0,     0,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,   132,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,   132,   158,    76,     0,     0,     0,
       0,    81,    82,    83,     0,     0,    84,     0,     0,    85,
      86,   167,     0,    87,    88,     0,     0,    81,    82,    83,
       0,     0,    84,     0,     0,    85,    86,     0,     0,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
     132,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,     0,    13,    14,     0,    15,     0,     0,     0,
       0,    16,    17,    18,     0,    19,    20,    21,    49,     0,
       0,     1,    51,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,     0,    13,    14,     0,    15,     0,     0,     0,
       0,    16,    17,    18,     0,    19,    20,    21,     1,     0,
       0,     2,     3,     0,     0,     0,     4,     0,     5,     6,
       7,     0,     0,     0,     8,     9,    10,    11,    12,     0,
      13,    14,     0,    15,     0,     0,     0,     0,    16,    17,
      18,     0,    19,    20,    21,     2,     3,     0,     0,     0,
       4,     0,     5,     0,     7,     0,     0,     0,     0,     9,
      10,     0,    12,     0,    13,    14,     0,     0,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      68,    68,     0,   219,    64,    75,     7,    41,    76,    79,
      98,    41,    78,    81,    82,   285,   151,   152,    45,   153,
      23,    51,    23,    42,    42,    42,    79,    32,    43,    45,
      98,    29,    35,    63,    35,   170,    40,    91,    57,    57,
      60,    43,    46,    41,    43,    45,    43,    81,    36,    44,
      36,   117,     7,    51,    81,    45,    57,    40,    63,    55,
      81,   331,    83,    46,    83,    63,    81,    65,    23,    57,
      44,    57,    91,    91,    91,    91,    44,   137,    64,    81,
      35,    81,    81,    91,    81,   155,   158,    70,   158,    85,
     160,    81,     7,    79,    40,   167,    42,   167,   314,   234,
      43,   171,   190,   191,   192,   158,   213,    83,    23,   216,
     163,    40,   165,    28,   167,    82,    45,    46,   138,    81,
      35,    83,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   141,    83,
     206,   207,    81,    42,    83,   213,   213,    42,   216,   216,
      40,   137,   172,   139,    91,    45,    46,   163,   239,   165,
     248,    42,     7,    82,   298,    50,   301,    51,   188,    45,
     236,   237,   158,   243,    57,    58,    59,   163,    23,   165,
     248,   167,   212,    28,    64,    65,    66,    67,    54,   209,
      35,    52,    25,   328,    27,    28,    60,    61,    70,   219,
      70,   336,    43,   223,    62,    63,   274,   275,   228,    82,
     276,    40,    81,    42,   212,   350,   351,    46,    47,    48,
      49,   302,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,   231,    68,    69,    83,   318,   224,   193,
     194,   311,    42,   324,   197,   198,   199,   200,   195,   196,
     201,   202,   333,   319,   335,    43,   326,    85,    41,   340,
      91,   327,    41,   329,   334,    91,    91,    91,    81,    43,
      43,   352,   338,    41,    41,   343,   343,    41,    36,    44,
     346,    43,    42,   349,    43,    82,    43,    12,   308,    83,
      43,   203,   205,   204,   314,     3,     4,     5,     6,     7,
       8,     9,    10,    11,   274,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    58,    30,   275,   215,    33,    34,    35,    36,    37,
      38,    39,    43,   165,    42,   137,    44,    45,   231,   303,
      48,    49,    50,   221,   212,    53,    29,    -1,    56,    57,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    87,
      88,    89,    90,    91,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    87,    88,
      89,    90,    91,     3,    -1,    -1,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,    39,
       4,     5,    -1,    -1,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      44,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    53,
      -1,    91,    56,    57,    -1,    -1,    60,    61,    -1,    -1,
      -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,    -1,
      15,    -1,    -1,    -1,    -1,    20,    21,    -1,    23,    83,
      25,    26,    27,    87,    88,    89,    90,    91,    33,    34,
      35,    -1,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,    53,    -1,
      -1,    56,    57,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    91,     3,    -1,    -1,
       6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,    25,
      26,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      -1,    37,    38,    39,     3,    -1,    -1,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    -1,    25,    26,    -1,    28,
      -1,    -1,    27,    -1,    33,    34,    35,    -1,    37,    38,
      39,    -1,    -1,    -1,    -1,    44,    -1,    42,    84,    44,
      -1,    -1,    27,    48,    49,    50,    -1,    -1,    53,    -1,
      -1,    56,    57,    -1,    -1,    60,    61,    42,    -1,    -1,
      -1,    70,    -1,    48,    49,    50,    27,    -1,    53,    -1,
      -1,    56,    57,    -1,    -1,    60,    61,    -1,    -1,    -1,
      41,    42,    87,    88,    89,    90,    91,    48,    49,    50,
      -1,    -1,    53,    -1,    -1,    56,    57,    -1,    83,    60,
      61,    -1,    87,    88,    89,    90,    91,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    87,    88,    89,    90,
      91,    48,    49,    50,    27,    -1,    53,    -1,    -1,    56,
      57,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      53,    -1,    -1,    56,    57,    -1,    83,    60,    61,    -1,
      87,    88,    89,    90,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,    42,
      27,    44,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      53,    -1,    -1,    56,    57,    42,    -1,    60,    61,    -1,
      -1,    48,    49,    50,    -1,    -1,    53,    -1,    -1,    56,
      57,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,    -1,
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
      -1,    33,    34,    35,    -1,    37,    38,    39,     0,    -1,
      -1,     3,    44,    -1,     6,     7,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    37,    38,    39,     3,    -1,
      -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,
      25,    26,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    -1,    37,    38,    39,     6,     7,    -1,    -1,    -1,
      11,    -1,    13,    -1,    15,    -1,    -1,    -1,    -1,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    22,    23,    25,    26,    28,    33,    34,    35,    37,
      38,    39,   117,   118,   122,   123,   126,   130,   131,   157,
     158,   159,   160,    91,   127,    42,    57,    83,    91,   120,
     121,   132,   133,   135,   118,   119,   119,   119,   119,     0,
     158,    44,   150,    44,   132,   130,   135,   136,    81,    83,
      70,   117,   118,   161,    40,    42,   133,     4,     5,     8,
       9,    10,    16,    17,    18,    24,    27,    30,    36,    42,
      45,    48,    49,    50,    53,    56,    57,    60,    61,    83,
      87,    88,    89,    90,    91,    94,    95,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   113,   115,   117,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    91,   128,   129,    43,   130,   135,   121,
     132,    44,    91,   113,   142,   117,   150,    28,   134,   136,
      91,   118,   137,   138,   139,   140,    83,    97,   110,   116,
      83,    82,   111,    42,    91,    42,    83,   115,    42,    97,
      42,   111,   115,   123,   124,   130,   141,    42,    97,    97,
      82,    40,    42,    46,    47,    48,    49,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,   114,    99,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    50,    52,    51,    54,    55,   112,    81,
      83,    45,   111,    70,    45,    81,    40,    46,   143,   144,
     145,   146,   147,   134,   136,    41,    57,   113,    28,   132,
      43,    81,    43,    81,    82,   148,   148,   153,    83,   115,
      83,   141,   115,    42,    43,   124,   125,   125,    43,   141,
     148,   115,    43,    96,   113,    91,    91,   113,    99,    99,
      99,   100,   100,   101,   101,   102,   102,   102,   102,   103,
     103,   104,   105,   106,   111,   111,    85,   113,   152,   116,
      45,   129,   116,    91,    45,    81,   142,    70,   147,   113,
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
     115,   116,   117,   117,   118,   118,   118,   118,   119,   119,
     120,   120,   121,   121,   122,   122,   122,   122,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   124,   124,   125,   125,   126,   126,   126,   127,   127,
     128,   128,   129,   129,   130,   130,   130,   131,   132,   132,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   134,
     134,   135,   135,   135,   135,   136,   136,   137,   137,   138,
     138,   139,   139,   140,   140,   141,   142,   142,   142,   143,
     143,   144,   144,   145,   146,   146,   147,   147,   148,   148,
     148,   148,   148,   148,   149,   149,   149,   150,   150,   151,
     151,   152,   152,   153,   153,   154,   154,   154,   155,   155,
     155,   156,   156,   156,   156,   156,   157,   157,   158,   158,
     159,   159,   160,   161,   161
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
       3,     1,     2,     3,     2,     2,     2,     2,     1,     0,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     0,     5,     6,     2,     1,     0,
       1,     3,     1,     3,     1,     1,     1,     1,     2,     1,
       1,     3,     4,     6,     6,     5,     4,     4,     5,     1,
       0,     2,     3,     2,     1,     1,     2,     1,     3,     1,
       3,     2,     1,     1,     3,     1,     1,     3,     4,     2,
       4,     1,     0,     2,     1,     2,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     3,     1,
       3,     1,     1,     2,     1,     8,    12,     5,     8,    10,
      12,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       4,     2,     2,     1,     2
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
#line 1885 "ass6_21CS10014_21CS30032.tab.c"
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
#line 1898 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 4:
#line 88 "ass6_21CS10014_21CS30032.y"
                     { 
        (yyval.expr) = new expression() ; 
        (yyval.expr)->loc = ".LC" + to_string(string_count++) ;
        consts.push_back(*((yyvsp[0].str)));
    }
#line 1908 "ass6_21CS10014_21CS30032.tab.c"
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
#line 1921 "ass6_21CS10014_21CS30032.tab.c"
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
#line 1934 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 7:
#line 110 "ass6_21CS10014_21CS30032.y"
                                                        { (yyval.expr) = (yyvsp[-1].expr) ; }
#line 1940 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 8:
#line 114 "ass6_21CS10014_21CS30032.y"
                         {/* No Action Taken */}
#line 1946 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 9:
#line 115 "ass6_21CS10014_21CS30032.y"
                                                                             {
        symbol_type* t = current_symbol_table->lookup((yyvsp[-3].expr)->loc)->type;
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
#line 1967 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 10:
#line 132 "ass6_21CS10014_21CS30032.y"
    {
        // is for calling a function with no parameters
        symbol_table* table = global_symbol_table.lookup((yyvsp[-2].expr)->loc)->nested_table;
        emit((yyvsp[-2].expr)->loc,"0","",CALL);
    }
#line 1977 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 11:
#line 137 "ass6_21CS10014_21CS30032.y"
                                                                                         { 
        // Corresponds to calling a function with the  function name and the appropriate number of parameters
        symbol_table* table = global_symbol_table.lookup((yyvsp[-3].expr)->loc)->nested_table;
        vector<p> params = *((yyvsp[-1].p_list));
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
#line 2002 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 12:
#line 158 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2008 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 13:
#line 160 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2014 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 14:
#line 161 "ass6_21CS10014_21CS30032.y"
                                   {
        (yyval.expr) = new expression();
        symbol_type* t = current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type;
        if(t.type == ARR)
        {
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type.nextType);
            emit((yyval.expr)->loc,(yyvsp[-1].expr)->loc,*((yyvsp[-1].expr)->folder),ARR_IDX_ARG);
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,(yyvsp[-1].expr)->loc,*(1->folder),ARR_IDX_ARG);
            emit(temp,temp,"1",PLUS);
            emit((yyvsp[-1].expr)->loc,temp,*(1->folder),ARR_IDX_RES);
        }
        else 
        {
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type.type);
            emit((yyval.expr)->loc,(yyvsp[-1].expr)->loc,"",ASSIGN);
            emit((yyvsp[-1].expr)->loc,(yyvsp[-1].expr)->loc,"1",PLUS);
        }

    }
#line 2039 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 15:
#line 181 "ass6_21CS10014_21CS30032.y"
                                   {
        (yyval.expr) = new expression();
        (yyval.expr)->loc = ST->gentemp(ST->lookup((yyvsp[-1].expr)->loc)->type.type);          // Generate a new temporary variable
        symbol_type* t = current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type;
        if(t.type == ARR)
        {
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type.nextType);
            emit((yyval.expr)->loc,(yyvsp[-1].expr)->loc,*((yyvsp[-1].expr)->folder),ARR_IDX_ARG);
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,(yyvsp[-1].expr)->loc,*(1->folder),ARR_IDX_ARG);
            emit((yyval.expr)->loc,temp,"",ASSIGN)
            emit(temp,temp,"1",MINUS);
            emit((yyvsp[-1].expr)->loc,temp,*(1->folder),ARR_IDX_RES);
        }
        else 
        {
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type.type);
            emit((yyval.expr)->loc,(yyvsp[-1].expr)->loc,"",ASSIGN);
            emit((yyvsp[-1].expr)->loc,(yyvsp[-1].expr)->loc,"1",MINUS);
        }
    }
#line 2065 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 16:
#line 203 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2071 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 17:
#line 205 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2077 "ass6_21CS10014_21CS30032.tab.c"
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
#line 2089 "ass6_21CS10014_21CS30032.tab.c"
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
#line 2101 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 20:
#line 226 "ass6_21CS10014_21CS30032.y"
                         {}
#line 2107 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 21:
#line 227 "ass6_21CS10014_21CS30032.y"
                                 {
        (yyval.expr) = new expression();  
        symbol_type t = current_symbol_table->lookup((yyvsp[0].expr)->loc)->type;
        if(type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            emit(temp,temp,"1",PLUS);
            emit((yyvsp[0].expr)->loc,temp,*(2->folder),ARR_IDX_RES);
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[0].expr)->loc)->type.nextType);
        }
        else{
            emit((yyvsp[0].expr)->loc,(yyvsp[0].expr)->loc,"1",PLUS);
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[0].expr)->loc)->type.type);
        }
        (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[0].expr)->loc)->type.type);
        emit((yyval.expr)->loc,(yyvsp[0].expr)->loc,"",ASSIGN);
    }
#line 2130 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 22:
#line 245 "ass6_21CS10014_21CS30032.y"
                                 {
        (yyval.expr) = new expression();
        symbol_type t = current_symbol_table->lookup((yyvsp[0].expr)->loc)->type;
        if(tyoe.type == ARR)
        {
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,(yyvsp[0].expr)->loc,*((yyvsp[0].expr)->folder),ARR_IDX_ARG);
            emit(temp,temp,"1",MINUS);
            emit((yyvsp[0].expr)->loc,temp,*(2->folder),ARR_IDX_RES);
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[0].expr)->loc)->type.nextType);
        }
        else 
        {
            emit((yyvsp[0].expr)->loc,(yyvsp[0].expr)->loc,"1",MINUS);
            (yyval.expr)->loc = current_symbol_table->gentemp(current_symbol_table->lookup((yyvsp[0].expr)->loc)->type.type);
        }
        emit((yyval.expr)->loc,(yyvsp[0].expr)->loc,"",ASSIGN);
    }
#line 2153 "ass6_21CS10014_21CS30032.tab.c"
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
                emit((yyval.expr)->loc,(yyvsp[0].expr)->loc,"",UMINUS);
                break;

            
            case '!' :
                (yyval.expr) = new expression();
                (yyval.expr)->loc = current_symbol_table->gentemp(INT);
                int temp = nextinstr + 2;
                emit(to_string(temp),(yyvsp[0].expr)->loc,"0",GOTO_EQ);
                temp = nextinstr + 3;
                emit(to_string(temp),"","",GOTO);
                emit((yyval.expr)->loc,"1","",ASSIGN);
                temp = nextinstr + 2;
                emit(to_string(temp),"","",GOTO);
                emit((yyval.expr)->loc,"0","",ASSIGN);
                break;
        }
    }
#line 2196 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 24:
#line 302 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2202 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 25:
#line 304 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2208 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 26:
#line 308 "ass6_21CS10014_21CS30032.y"
              { (yyval.charval) = '&'; }
#line 2214 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 27:
#line 309 "ass6_21CS10014_21CS30032.y"
               { (yyval.charval) = '*';}
#line 2220 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 28:
#line 310 "ass6_21CS10014_21CS30032.y"
           { (yyval.charval) = '+';}
#line 2226 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 29:
#line 311 "ass6_21CS10014_21CS30032.y"
            { (yyval.charval) = '-';}
#line 2232 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 30:
#line 312 "ass6_21CS10014_21CS30032.y"
                  { (yyval.charval) = '~';}
#line 2238 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 31:
#line 313 "ass6_21CS10014_21CS30032.y"
                  { (yyval.charval) = '!';}
#line 2244 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 32:
#line 317 "ass6_21CS10014_21CS30032.y"
                       { /* No Action Taken */ }
#line 2250 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 33:
#line 318 "ass6_21CS10014_21CS30032.y"
                                                                       { /* No Action Taken */ }
#line 2256 "ass6_21CS10014_21CS30032.tab.c"
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
#line 2284 "ass6_21CS10014_21CS30032.tab.c"
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

        data_type result = ((s1.type.type > s2.type.type) ? s1.type.type : s2.type.type);
        (yyval.expr)->loc = current_symbol_table->gentemp(result);
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,MULTIPLY);
    }
#line 2316 "ass6_21CS10014_21CS30032.tab.c"
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
        data_type result = ((s1.type.type > s2.type.type) ? s1.type.type : s2.type.type);
        (yyval.expr)->loc = current_symbol_table->gentemp(result);
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,DIVIDE);
    }
#line 2347 "ass6_21CS10014_21CS30032.tab.c"
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
        data_type result = ((s1.type.type > s2.type.type) ? s1.type.type : s2.type.type);
        (yyval.expr)->loc = current_symbol_table->gentemp(result);
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,MODULO);
    }
#line 2378 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 38:
#line 427 "ass6_21CS10014_21CS30032.y"
                                { /* No Action Taken */ }
#line 2384 "ass6_21CS10014_21CS30032.tab.c"
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
        data_type result = ((s1.type.type > s2.type.type) ? s1.type.type : s2.type.type);
        (yyval.expr)->loc = current_symbol_table->gentemp(result);
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,PLUS);
    }
#line 2415 "ass6_21CS10014_21CS30032.tab.c"
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
        data_type result = ((s1.type.type > s2.type.type) ? s1.type.type : s2.type.type);
        (yyval.expr)->loc = current_symbol_table->gentemp(result);
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,MINUS);
    }
#line 2447 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 41:
#line 484 "ass6_21CS10014_21CS30032.y"
                          { /* No Action Taken */ }
#line 2453 "ass6_21CS10014_21CS30032.tab.c"
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

        (yyval.expr)->loc = current_symbol_table->gentemp(s1.type.type);
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,LEFT_SHIFT);
    }
#line 2482 "ass6_21CS10014_21CS30032.tab.c"
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

        (yyval.expr)->loc = current_symbol_table->gentemp(s1.type.type);
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,RIGHT_SHIFT);
    }
#line 2511 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 44:
#line 536 "ass6_21CS10014_21CS30032.y"
                       { /* No Action Taken */ }
#line 2517 "ass6_21CS10014_21CS30032.tab.c"
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
        (yyval.expr)->truelist = makelist(nextinstr);
        emit("",(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,GOTO_LT);
        emit((yyval.expr)->loc,"0","",ASSIGN);
        (yyval.expr)->falselist = makelist(nextinstr);
        emit("", "", "", GOTO);

    }
#line 2553 "ass6_21CS10014_21CS30032.tab.c"
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
        (yyval.expr)->truelist = makelist(nextinstr);
        emit("",(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,GOTO_GT);
        emit((yyval.expr)->loc,"0","",ASSIGN);
        (yyval.expr)->falselist = makelist(nextinstr);
        emit("", "", "", GOTO);
    }
#line 2588 "ass6_21CS10014_21CS30032.tab.c"
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
        (yyval.expr)->truelist = makelist(nextinstr);
        emit("",(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,GOTO_LTE);
        emit((yyval.expr)->loc,"0","",ASSIGN);
        (yyval.expr)->falselist = makelist(nextinstr);
        emit("", "", "", GOTO);

    }
#line 2624 "ass6_21CS10014_21CS30032.tab.c"
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
        (yyval.expr)->truelist = makelist(nextinstr);
        emit("",(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,GOTO_GTE);
        emit((yyval.expr)->loc,"0","",ASSIGN);
        (yyval.expr)->falselist = makelist(nextinstr);
        emit("", "", "", GOTO);
    }
#line 2659 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 49:
#line 666 "ass6_21CS10014_21CS30032.y"
                            { (yyval.expr) = new expression() ;(yyval.expr) = (yyvsp[0].expr); }
#line 2665 "ass6_21CS10014_21CS30032.tab.c"
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
        (yyval.expr)->truelist = makelist(nextinstr);
        emit("",(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,GOTO_EQ);
        emit((yyval.expr)->loc,"0","",ASSIGN);
        (yyval.expr)->falselist = makelist(nextinstr);
        emit("", "", "", GOTO);
    }
#line 2701 "ass6_21CS10014_21CS30032.tab.c"
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
        (yyval.expr)->truelist = makelist(nextinstr);
        emit("",(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,GOTO_NEQ);
        emit((yyval.expr)->loc,"0","",ASSIGN);
        (yyval.expr)->falselist = makelist(nextinstr);
        emit("", "", "", GOTO);
    }
#line 2737 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 52:
#line 732 "ass6_21CS10014_21CS30032.y"
                          {}
#line 2743 "ass6_21CS10014_21CS30032.tab.c"
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
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,BIT_AND);
    }
#line 2773 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 54:
#line 761 "ass6_21CS10014_21CS30032.y"
                     { (yyval.expr) = (yyvsp[0].expr); }
#line 2779 "ass6_21CS10014_21CS30032.tab.c"
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
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,BIT_XOR);
    }
#line 2809 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 56:
#line 790 "ass6_21CS10014_21CS30032.y"
                              {new expression() ;(yyval.expr) = (yyvsp[0].expr);}
#line 2815 "ass6_21CS10014_21CS30032.tab.c"
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
        emit((yyval.expr)->loc,(yyvsp[-2].expr)->loc,(yyvsp[0].expr)->loc,BIT_OR);
    }
#line 2845 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 58:
#line 819 "ass6_21CS10014_21CS30032.y"
                              {}
#line 2851 "ass6_21CS10014_21CS30032.tab.c"
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
#line 2867 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 60:
#line 834 "ass6_21CS10014_21CS30032.y"
                             {}
#line 2873 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 61:
#line 835 "ass6_21CS10014_21CS30032.y"
                                                                {
        
        backpatch((yyvsp[-3].expr)->falselist,(yyvsp[-1].expr)->instruction);
        (yyval.expr)->truelist = merge((yyvsp[-3].expr)->truelist,(yyvsp[0].expr)->truelist);
        (yyval.expr)->falselist = (yyvsp[0].expr)->falselist;
        (yyval.expr)->type = BOOL;
    }
#line 2885 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 62:
#line 847 "ass6_21CS10014_21CS30032.y"
                            { /* No Action Taken */ }
#line 2891 "ass6_21CS10014_21CS30032.tab.c"
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
        templist = merge(templist, makelist(next_instr));
        emit("", "", "", GOTO);

        backpatch((yyvsp[-7].expr)->nextlist, next_instr);
        inttobool((yyvsp[-8].expr));
        backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-5].expr)->instruction);
        backpatch((yyvsp[-8].expr)->falselist, (yyvsp[-1].expr)->instruction);
        backpatch((yyvsp[-7].expr)->nextlist, next_instr);

    }
#line 2916 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 64:
#line 871 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.expr) = new expression();
        (yyval.expr)->instruction = next_instr;
    }
#line 2925 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 65:
#line 878 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.expr) = new expression();
        (yyval.expr)->nextlist = makelist(next_instr);
        emit("", "", "", GOTO);
    }
#line 2935 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 66:
#line 886 "ass6_21CS10014_21CS30032.y"
                             { /* No Action Taken */ }
#line 2941 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 67:
#line 887 "ass6_21CS10014_21CS30032.y"
                                                                 {
        symbol* s1 = current_symbol_table->lookup((yyvsp[-2].expr)->loc);
        symbol* s2 = current_symbol_table->lookup((yyvsp[0].expr)->loc);
        if ((yyvsp[-2].expr)->fold == 0)
        {
            if (s1->type.type != ARR) emit((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, "", ASSIGN);
            else emit((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc, *((yyvsp[-2].expr)->folder), ARR_IDX_RES);
        }
        else emit(*((yyvsp[-2].expr)->folder), (yyvsp[0].expr)->loc, "", ASSIGN);

        (yyval.expr) = (yyvsp[-2].expr);
    }
#line 2958 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 68:
#line 903 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2964 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 69:
#line 905 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2970 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 70:
#line 907 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2976 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 71:
#line 909 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2982 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 72:
#line 911 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2988 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 73:
#line 913 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 2994 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 74:
#line 915 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 3000 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 75:
#line 917 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 3006 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 76:
#line 919 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 3012 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 77:
#line 921 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 3018 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 78:
#line 923 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */}
#line 3024 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 79:
#line 929 "ass6_21CS10014_21CS30032.y"
                            { /* No Action Taken */ }
#line 3030 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 80:
#line 930 "ass6_21CS10014_21CS30032.y"
                                             { /* No Action Taken */ }
#line 3036 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 81:
#line 934 "ass6_21CS10014_21CS30032.y"
                             { /* No Action Taken */ }
#line 3042 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 82:
#line 939 "ass6_21CS10014_21CS30032.y"
                                       { /* No Action Taken */ }
#line 3048 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 83:
#line 941 "ass6_21CS10014_21CS30032.y"
    {
        data_type curr_type = (yyvsp[-2].types);
        int curr_size = 0;
        if (curr_type == INT) curr_size = SIZE_OF_INT;
        else if (curr_type == FLOAT) curr_size = SIZE_OF_FLOAT;
        else if (curr_type == CHAR) curr_size = SIZE_OF_CHAR;

        vector<declaration*> decl_list = *((yyvsp[-1].dec_list));
        for (int i = 0; i < decl_list.size(); i++)
        {
            declaration* curr_decl = decl_list[i];
            if (curr_decl->type == FUNCTION)
            {
                current_symbol_table = &global_symbol_table;
                emit(curr_decl->name, "", "", FUNC_END);
                symbol* s1 = current_symbol_table->lookup(curr_decl->name);
                symbol* s2 = s1->nested_table->lookup("RETVAL", curr_type, curr_decl->ptr);
                s1->size = 0;
                s1->initial_value = NULL;
            }

            symbol* s3 = current_symbol_table->lookup(curr_decl->name, curr_type);
            s3->nested_table = NULL;

            if(curr_decl->instr_list == vector<int>() && curr_decl->ptr == 0)
            {
                s3->size = curr_size;
                s3->type.type = curr_type;
                if (curr_decl->initial_value)
                {
                    emit(s3->name, curr_decl->initial_value->loc, "", ASSIGN);
                    s3->initial_value = current_symbol_table->lookup(curr_decl->initial_value->loc)->initial_value;
                }
                else s3->initial_value = NULL;
            }

            else if (curr_decl->instr_list != vector<int>())
            {
                s3->type.type = ARR;
                s3->type.next_type = curr_type;
                s3->type.dimensions = curr_decl->instr_list;
                vector<int> temp = s3->type.dimensions;

                int temp_size = curr_size;
                for (int i = 0; i < temp.size(); i++)
                {
                    temp_size *= temp[i];
                }
                current_symbol_table->offset += temp_size;
                s3->size = temp_size;
                current_symbol_table->offset -= SIZE_OF_INT;
            }

            else if (curr_decl->ptr != 0)
            {
                s3->type.type = PTR;
                s3->type.next_type = curr_type;
                s3->type.ptr = curr_decl->ptr;
                current_symbol_table->offset += (SIZE_OF_PTR - curr_size);
                s3->size = SIZE_OF_PTR;
            }
        }
    }
#line 3116 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 84:
#line 1007 "ass6_21CS10014_21CS30032.y"
                                                         { /* No Action Taken */ }
#line 3122 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 85:
#line 1008 "ass6_21CS10014_21CS30032.y"
                                                { /* No Action Taken */ }
#line 3128 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 86:
#line 1009 "ass6_21CS10014_21CS30032.y"
                                                { /* No Action Taken */ }
#line 3134 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 87:
#line 1010 "ass6_21CS10014_21CS30032.y"
                                                    { /* No Action Taken */ }
#line 3140 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 88:
#line 1014 "ass6_21CS10014_21CS30032.y"
                             { /* No Action Taken */ }
#line 3146 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 89:
#line 1016 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */ }
#line 3152 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 90:
#line 1020 "ass6_21CS10014_21CS30032.y"
                      { /* No Action Taken */ }
#line 3158 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 91:
#line 1021 "ass6_21CS10014_21CS30032.y"
                                                 { /* No Action Taken */ }
#line 3164 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 92:
#line 1026 "ass6_21CS10014_21CS30032.y"
    { 
        (yyval.dec) = (yyvsp[0].dec);
        (yyval.dec)->initial_value = NULL;
    }
#line 3173 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 93:
#line 1031 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.dec) = (yyvsp[-2].dec);
        (yyval.dec)->initial_value = (yyvsp[0].expr);
    }
#line 3182 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 94:
#line 1038 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3188 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 95:
#line 1039 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3194 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 96:
#line 1040 "ass6_21CS10014_21CS30032.y"
           { /* No Action Taken */ }
#line 3200 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 97:
#line 1041 "ass6_21CS10014_21CS30032.y"
               { /* No Action Taken */ }
#line 3206 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 98:
#line 1047 "ass6_21CS10014_21CS30032.y"
             { (yyval.types) = VOID; }
#line 3212 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 99:
#line 1048 "ass6_21CS10014_21CS30032.y"
             { (yyval.types) = CHAR; }
#line 3218 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 100:
#line 1049 "ass6_21CS10014_21CS30032.y"
            { /* No Action Taken */ }
#line 3224 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 101:
#line 1050 "ass6_21CS10014_21CS30032.y"
            { (yyval.types) = INT; }
#line 3230 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 102:
#line 1051 "ass6_21CS10014_21CS30032.y"
           { /* No Action Taken */ }
#line 3236 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 103:
#line 1052 "ass6_21CS10014_21CS30032.y"
              { (yyval.types) = FLOAT; }
#line 3242 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 104:
#line 1053 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3248 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 105:
#line 1054 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3254 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 106:
#line 1055 "ass6_21CS10014_21CS30032.y"
               { /* No Action Taken */ }
#line 3260 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 107:
#line 1056 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3266 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 108:
#line 1057 "ass6_21CS10014_21CS30032.y"
              { /* No Action Taken */ }
#line 3272 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 109:
#line 1058 "ass6_21CS10014_21CS30032.y"
                { /* No Action Taken */ }
#line 3278 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 110:
#line 1059 "ass6_21CS10014_21CS30032.y"
                     { /* No Action Taken */ }
#line 3284 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 111:
#line 1063 "ass6_21CS10014_21CS30032.y"
                                                  { /* No Action Taken */ }
#line 3290 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 112:
#line 1064 "ass6_21CS10014_21CS30032.y"
                                                  { /* No Action Taken */ }
#line 3296 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 113:
#line 1068 "ass6_21CS10014_21CS30032.y"
                               { /* No Action Taken */ }
#line 3302 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 114:
#line 1070 "ass6_21CS10014_21CS30032.y"
    { /* No Action Taken */ }
#line 3308 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 115:
#line 1074 "ass6_21CS10014_21CS30032.y"
                                                                                 { /* No Action Taken */ }
#line 3314 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 116:
#line 1075 "ass6_21CS10014_21CS30032.y"
                                                                                       { /* No Action Taken */ }
#line 3320 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 117:
#line 1076 "ass6_21CS10014_21CS30032.y"
                      { /* No Action Taken */ }
#line 3326 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 118:
#line 1080 "ass6_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3332 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 119:
#line 1081 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3338 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 120:
#line 1085 "ass6_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3344 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 121:
#line 1086 "ass6_21CS10014_21CS30032.y"
                                       { /* No Action Taken */ }
#line 3350 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 122:
#line 1090 "ass6_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3356 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 123:
#line 1091 "ass6_21CS10014_21CS30032.y"
                                              { /* No Action Taken */ }
#line 3362 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 124:
#line 1095 "ass6_21CS10014_21CS30032.y"
            { /* No Action Taken */ }
#line 3368 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 125:
#line 1096 "ass6_21CS10014_21CS30032.y"
               { /* No Action Taken */ }
#line 3374 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 126:
#line 1097 "ass6_21CS10014_21CS30032.y"
               { /* No Action Taken */ }
#line 3380 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 127:
#line 1101 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3386 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 128:
#line 1107 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.dec) = (yyvsp[0].dec);
        (yyval.dec)->ptr = (yyvsp[-1].intval);
    }
#line 3395 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 129:
#line 1112 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.dec) = (yyvsp[0].dec);
        (yyval.dec)->ptr = 0;
    }
#line 3404 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 130:
#line 1120 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.dec) = new declaration();
        (yyval.dec)->name = *((yyvsp[0].str));
    }
#line 3413 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 131:
#line 1125 "ass6_21CS10014_21CS30032.y"
    {
        /* No Action Taken */
    }
#line 3421 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 132:
#line 1129 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.dec) = (yyvsp[-3].dec);
        (yyvsp[-3].dec)->type = ARR;
        (yyvsp[-3].dec)->next_type = INT;
        (yyval.dec)->instr_list.push_back(0); 
    }
#line 3432 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 133:
#line 1136 "ass6_21CS10014_21CS30032.y"
    {
        /* No Action Taken */
    }
#line 3440 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 134:
#line 1140 "ass6_21CS10014_21CS30032.y"
    {
        /* No Action Taken */
    }
#line 3448 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 135:
#line 1144 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.dec) = (yyvsp[-4].dec);
        (yyvsp[-4].dec)->type = ARR;
        (yyvsp[-4].dec)->next_type = INT;
        (yyval.dec)->instr_list.push_back(current_symbol_table->lookup((yyvsp[-1].expr)->loc)->initial_value);
        // check
    }
#line 3460 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 136:
#line 1152 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.dec) = (yyvsp[-3].dec);
        (yyval.dec)->type = FUNCTION;
        symbol* s1 = current_symbol_table->lookup((yyvsp[-3].dec)->name, (yyvsp[-3].dec)->type);
        symbol_table* st = new symbol_table();
        s1->nested_table = st;

        vector<param*> param_list = *((yyvsp[-1].p_list));
        for (int i = 0; i < param_list.size(); i++)
        {
            param* curr_param = param_list[i];
            
            if (curr_param->type.type == ARR)
            {
                st->lookup(curr_param->name, curr_param->type.type);
                st->lookup(curr_param->name)->type.next_type = INT;
                st->lookup(curr_param->name)->type.dimensions.push_back(0);
            }
            
            else if (curr_param->type.type == PTR)
            {
                st->lookup(curr_param->name, curr_param->type.type);
                st->lookup(curr_param->name)->type.next_type = INT;
                st->lookup(curr_param->name)->type.ptr = curr_param->type.ptr;
            }
            
            else
            {
                st->lookup(curr_param->name, curr_param->type.type);
            }
        }

        current_symbol_table = st;
        emit((yyvsp[-3].dec)->name, "", "", FUNC_BEGIN);
    }
#line 3500 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 137:
#line 1188 "ass6_21CS10014_21CS30032.y"
    {
        /* No Action Taken */
    }
#line 3508 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 138:
#line 1192 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.dec) = (yyvsp[-4].dec);
        (yyval.dec)->type = PTR;
        (yyval.dec)->next_type = INT;
    }
#line 3518 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 139:
#line 1202 "ass6_21CS10014_21CS30032.y"
                          { /* No Action Taken */ }
#line 3524 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 140:
#line 1203 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3530 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 141:
#line 1207 "ass6_21CS10014_21CS30032.y"
                                   { /* No Action Taken */ }
#line 3536 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 142:
#line 1208 "ass6_21CS10014_21CS30032.y"
                                           { /* No Action Taken */ }
#line 3542 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 143:
#line 1209 "ass6_21CS10014_21CS30032.y"
                       { (yyval.intval) = 1+(yyvsp[0].intval); }
#line 3548 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 144:
#line 1210 "ass6_21CS10014_21CS30032.y"
               { /* No Action Taken */ }
#line 3554 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 145:
#line 1214 "ass6_21CS10014_21CS30032.y"
                     { /* No Action Taken */ }
#line 3560 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 146:
#line 1215 "ass6_21CS10014_21CS30032.y"
                                         { /* No Action Taken */ }
#line 3566 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 147:
#line 1219 "ass6_21CS10014_21CS30032.y"
                     { /* No Action Taken */ }
#line 3572 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 148:
#line 1220 "ass6_21CS10014_21CS30032.y"
                                    { /* No Action Taken */ }
#line 3578 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 149:
#line 1225 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.p_list) = new vector<param*>();
        (yyval.p_list)->push_back((yyvsp[0].p));
    }
#line 3587 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 150:
#line 1230 "ass6_21CS10014_21CS30032.y"
    {
        (yyvsp[-2].p_list)->push_back((yyvsp[0].p));  
        (yyval.p_list) = (yyvsp[-2].p_list);
    }
#line 3596 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 151:
#line 1238 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.p) = new param();
        (yyval.p)->name = (yyvsp[0].dec)->name;
        if ((yyvsp[0].dec)->type == ARR)
        {
            (yyval.p)->type.type = ARR;
            (yyval.p)->type.next_type = (yyvsp[-1].types);
        }
        else if ((yyvsp[0].dec)->pc)
        {
            (yyval.p)->type.type = PTR;
            (yyval.p)->type.next_type = (yyvsp[-1].types);
        }
        else
        {
            (yyval.p)->type.type = (yyvsp[-1].types);
        }
    }
#line 3619 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 152:
#line 1256 "ass6_21CS10014_21CS30032.y"
                             { /* No Action Taken */ }
#line 3625 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 153:
#line 1260 "ass6_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3631 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 154:
#line 1261 "ass6_21CS10014_21CS30032.y"
                                       { /* No Action Taken */ }
#line 3637 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 155:
#line 1265 "ass6_21CS10014_21CS30032.y"
                               { /* No Action Taken */ }
#line 3643 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 156:
#line 1269 "ass6_21CS10014_21CS30032.y"
                            { /* No Action Taken */ }
#line 3649 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 157:
#line 1270 "ass6_21CS10014_21CS30032.y"
                                                              { /* No Action Taken */ }
#line 3655 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 158:
#line 1271 "ass6_21CS10014_21CS30032.y"
                                                                    { /* No Action Taken */ }
#line 3661 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 159:
#line 1275 "ass6_21CS10014_21CS30032.y"
                                  { /* No Action Taken */ }
#line 3667 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 160:
#line 1276 "ass6_21CS10014_21CS30032.y"
                                                         { /* No Action Taken */ }
#line 3673 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 161:
#line 1280 "ass6_21CS10014_21CS30032.y"
                  { /* No Action Taken */ }
#line 3679 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 162:
#line 1281 "ass6_21CS10014_21CS30032.y"
             { /* No Action Taken */ }
#line 3685 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 163:
#line 1285 "ass6_21CS10014_21CS30032.y"
                               { /* No Action Taken */ }
#line 3691 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 164:
#line 1289 "ass6_21CS10014_21CS30032.y"
                 { /* No Action Taken */ }
#line 3697 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 165:
#line 1290 "ass6_21CS10014_21CS30032.y"
                                 { /* No Action Taken */ }
#line 3703 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 166:
#line 1294 "ass6_21CS10014_21CS30032.y"
                                                                   { /* No Action Taken */ }
#line 3709 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 167:
#line 1295 "ass6_21CS10014_21CS30032.y"
                     { /* No Action Taken */ }
#line 3715 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 168:
#line 1299 "ass6_21CS10014_21CS30032.y"
                        { /* No Action Taken */ }
#line 3721 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 169:
#line 1300 "ass6_21CS10014_21CS30032.y"
                         { /* No Action Taken */ }
#line 3727 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 170:
#line 1301 "ass6_21CS10014_21CS30032.y"
                           { /* No Action Taken */ }
#line 3733 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 171:
#line 1302 "ass6_21CS10014_21CS30032.y"
                          { /* No Action Taken */ }
#line 3739 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 172:
#line 1303 "ass6_21CS10014_21CS30032.y"
                          { /* No Action Taken */ }
#line 3745 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 173:
#line 1304 "ass6_21CS10014_21CS30032.y"
                     { /* No Action Taken */ }
#line 3751 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 174:
#line 1308 "ass6_21CS10014_21CS30032.y"
                                 { /* No Action Taken */ }
#line 3757 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 175:
#line 1309 "ass6_21CS10014_21CS30032.y"
                                               { /* No Action Taken */ }
#line 3763 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 176:
#line 1310 "ass6_21CS10014_21CS30032.y"
                              { /* No Action Taken */ }
#line 3769 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 177:
#line 1314 "ass6_21CS10014_21CS30032.y"
                                             { /* No Action Taken */ }
#line 3775 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 178:
#line 1315 "ass6_21CS10014_21CS30032.y"
                                                             { (yyval.expr) = (yyvsp[-1].expr); }
#line 3781 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 179:
#line 1320 "ass6_21CS10014_21CS30032.y"
    { 
        (yyval.expr) = (yyvsp[0].expr); 
        backpatch((yyvsp[0].expr)->nextlist, next_instr);
    }
#line 3790 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 180:
#line 1325 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.expr) = new expression();
        backpatch((yyvsp[-2].expr)->nextlist, (yyvsp[-1].expr)->instruction);
        (yyval.expr)->nextlist = (yyvsp[0].expr)->nextlist;
    }
#line 3800 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 181:
#line 1333 "ass6_21CS10014_21CS30032.y"
                  { (yyval.expr) = new expression(); }
#line 3806 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 182:
#line 1334 "ass6_21CS10014_21CS30032.y"
                { /* No Action Taken */ }
#line 3812 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 183:
#line 1338 "ass6_21CS10014_21CS30032.y"
                           { /* No Action Taken */ }
#line 3818 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 184:
#line 1339 "ass6_21CS10014_21CS30032.y"
                { (yyval.expr) = new expression(); }
#line 3824 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 185:
#line 1343 "ass6_21CS10014_21CS30032.y"
    {
        backpatch((yyvsp[-4].expr)->nextlist, next_instr);
        inttobool((yyvsp[-5].expr));
        (yyval.expr) = new expression();
        backpatch((yyvsp[-5].expr)->truelist, (yyvsp[-2].expr));

        (yyval.expr)->nextlist = merge((yyvsp[-5].expr)->falselist, merge((yyvsp[-1].expr)->nextlist, (yyvsp[0].expr)->nextlist));
    }
#line 3837 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 186:
#line 1352 "ass6_21CS10014_21CS30032.y"
    {
        backpatch((yyvsp[-8].expr)->nextlist, next_instr);
        inttobool((yyvsp[-9].expr));
        (yyval.expr) = new expression();
        backpatch((yyvsp[-9].expr)->truelist, (yyvsp[-6].expr)->instruction);
        backpatch((yyvsp[-9].expr)->falselist, (yyvsp[-2].expr)->instruction);

        (yyval.expr)->nextlist = merge(merge(merge((yyvsp[-5].expr)->nextlist, (yyvsp[-4].expr)->nextlist), (yyvsp[-1].expr)->nextlist), (yyvsp[0].expr)->nextlist);
    }
#line 3851 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 187:
#line 1361 "ass6_21CS10014_21CS30032.y"
                                                                         { /* No Action Taken */ }
#line 3857 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 188:
#line 1366 "ass6_21CS10014_21CS30032.y"
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
#line 3872 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 189:
#line 1377 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.expr) = new expression();
        backpatch((yyvsp[-2].expr)->nextlist, next_instr);
        inttobool((yyvsp[-3].expr));
        (yyval.expr)->nextlist = (yyvsp[-3].expr)->falselist;
        backpatch((yyvsp[-3].expr)->truelist, (yyvsp[-8].expr)->instruction);
        backpatch((yyvsp[-7].expr)->nextlist, (yyvsp[-6].expr)->instruction);
    }
#line 3885 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 190:
#line 1386 "ass6_21CS10014_21CS30032.y"
    {
        (yyval.expr) = new expression();
        emit("", "", "", GOTO);
        (yyvsp[0].expr)->nextlist = merge((yyvsp[0].expr)->nextlist, makelist(next_instr-1));
        backpatch((yyvsp[0].expr)->nextlist, (yyvsp[-5].expr)->instruction);
        backpatch((yyvsp[-6].expr)->nextlist, next_instr);
        backpatch((yyvsp[-3].expr)->nextlist, (yyvsp[-8].expr)->instruction);
        inttobool((yyvsp[-7].expr));
        backpatch((yyvsp[-7].expr)->truelist, (yyvsp[-1].expr)->instruction);
        (yyval.expr)->nextlist = (yyvsp[-7].expr)->falselist;
    }
#line 3901 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 191:
#line 1400 "ass6_21CS10014_21CS30032.y"
                                  { /* No Action Taken */ }
#line 3907 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 192:
#line 1401 "ass6_21CS10014_21CS30032.y"
                         { /* No Action Taken */ }
#line 3913 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 193:
#line 1402 "ass6_21CS10014_21CS30032.y"
                      { /* No Action Taken */ }
#line 3919 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 194:
#line 1404 "ass6_21CS10014_21CS30032.y"
    {
        if (current_symbol_table->lookup("RETVAL")->type.type == VOID) emit("", "", "", RETURN);
        (yyval.expr) = new statement();
    }
#line 3928 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 195:
#line 1409 "ass6_21CS10014_21CS30032.y"
    {
        if (current_symbol_table->lookup("RETVAL")->type.type == current_symbol_table->lookup((yyvsp[-1].expr)->loc)->type.type) emit((yyvsp[-1].expr)->loc, "", "", RETURN);
        (yyval.expr) = new statement();
    }
#line 3937 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 196:
#line 1417 "ass6_21CS10014_21CS30032.y"
                           { /* No Action Taken */ }
#line 3943 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 197:
#line 1418 "ass6_21CS10014_21CS30032.y"
                                            { /* No Action Taken */ }
#line 3949 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 198:
#line 1422 "ass6_21CS10014_21CS30032.y"
                          { /* No Action Taken */ }
#line 3955 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 199:
#line 1423 "ass6_21CS10014_21CS30032.y"
                  { /* No Action Taken */ }
#line 3961 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 200:
#line 1428 "ass6_21CS10014_21CS30032.y"
                                                                            { /* No Action Taken */ }
#line 3967 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 201:
#line 1430 "ass6_21CS10014_21CS30032.y"
    {
        current_symbol_table = &global_symbol_table;
        emit((yyvsp[-1].dec)->name, "", "", FUNC_END);
    }
#line 3976 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 202:
#line 1438 "ass6_21CS10014_21CS30032.y"
    {
        data_type temp = (yyvsp[-1].types);
        int size = 0;
        if (temp == CHAR) size = SIZE_OF_CHAR;
        else if (temp == INT) size = SIZE_OF_INT;
        else if (temp == FLOAT) size = SIZE_OF_FLOAT;
        declaration* new1 = (yyvsp[0].dec);
        symbol* new2 = current_symbol_table->lookup(new1->name);
        if (new2->type == FUNCTION)
        {
            symbol* return_value = new2->nested_table->lookup("RETVAL", temp, new2->ptr);
            new2->size = 0;
            new2->initial_value = NULL;
        }
        (yyval.dec) = (yyvsp[0].dec);
    }
#line 3997 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 203:
#line 1456 "ass6_21CS10014_21CS30032.y"
                  { /* No Action Taken */ }
#line 4003 "ass6_21CS10014_21CS30032.tab.c"
    break;

  case 204:
#line 1457 "ass6_21CS10014_21CS30032.y"
                                   { /* No Action Taken */ }
#line 4009 "ass6_21CS10014_21CS30032.tab.c"
    break;


#line 4013 "ass6_21CS10014_21CS30032.tab.c"

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
#line 1460 "ass6_21CS10014_21CS30032.y"


void yyerror(string s) {
    // for error reporting
    cout << "Error: " << s << endl;
    cout << "Line: " << yylineno << endl;
    cout << "Text: " << yytext << endl;
}
