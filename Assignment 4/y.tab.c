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
#line 1 "ass4_21CS10014_21CS30032.y"

    #include <stdio.h>
    extern int yylex();
    extern int yylineno;
    extern char* yytext;
    void yyerror(char* s);

#line 78 "y.tab.c"

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IDENTIFIER = 342,
    INTEGER_CONSTANT = 343,
    FLOATING_CONSTANT = 344,
    CHAR_CONSTANT = 345,
    STRING_LITERAL = 346,
    WS = 347
  };
#endif
/* Tokens.  */
#define AUTO 258
#define BREAK 259
#define CASE 260
#define CHAR 261
#define CONST 262
#define CONTINUE 263
#define DEFAULT 264
#define DO 265
#define DOUBLE 266
#define ELSE 267
#define ENUM 268
#define EXTERN 269
#define FLOAT 270
#define FOR 271
#define GOTO 272
#define IF 273
#define INLINE 274
#define INT 275
#define LONG 276
#define REGISTER 277
#define RESTRICT 278
#define RETURN 279
#define SHORT 280
#define SIGNED 281
#define SIZEOF 282
#define STATIC 283
#define STRUCT 284
#define SWITCH 285
#define TYPEDEF 286
#define UNION 287
#define UNSIGNED 288
#define VOID 289
#define VOLATILE 290
#define WHILE 291
#define BOOL 292
#define COMPLEX 293
#define IMAGINARY 294
#define SQUARE_BRACKET_OPEN 295
#define SQUARE_BRACKET_CLOSE 296
#define ROUND_BRACKET_OPEN 297
#define ROUND_BRACKET_CLOSE 298
#define CURLY_BRACKET_OPEN 299
#define CURLY_BRACKET_CLOSE 300
#define DOT 301
#define ARROW 302
#define INCREMENT 303
#define DECREMENT 304
#define BITWISE_AND 305
#define BITWISE_OR 306
#define BITWISE_XOR 307
#define BITWISE_NOT 308
#define LOGICAL_AND 309
#define LOGICAL_OR 310
#define LOGICAL_NOT 311
#define MULTIPLY 312
#define DIVIDE 313
#define MODULO 314
#define PLUS 315
#define MINUS 316
#define LEFT_SHIFT 317
#define RIGHT_SHIFT 318
#define LESS_THAN 319
#define GREATER_THAN 320
#define LESS_THAN_EQUAL 321
#define GREATER_THAN_EQUAL 322
#define EQUAL 323
#define NOT_EQUAL 324
#define ASSIGN 325
#define PLUS_ASSIGN 326
#define MINUS_ASSIGN 327
#define MULTIPLY_ASSIGN 328
#define DIVIDE_ASSIGN 329
#define MODULO_ASSIGN 330
#define LEFT_SHIFT_ASSIGN 331
#define RIGHT_SHIFT_ASSIGN 332
#define BITWISE_AND_ASSIGN 333
#define BITWISE_XOR_ASSIGN 334
#define BITWISE_OR_ASSIGN 335
#define COMMA 336
#define COLON 337
#define SEMICOLON 338
#define ELLIPSIS 339
#define QUESTION_MARK 340
#define HASH 341
#define IDENTIFIER 342
#define INTEGER_CONSTANT 343
#define FLOATING_CONSTANT 344
#define CHAR_CONSTANT 345
#define STRING_LITERAL 346
#define WS 347

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "ass4_21CS10014_21CS30032.y"

    int intval;
    float floatval;
    char charval;
    char* strval;

#line 321 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   982

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  210
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  340

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
       0,    40,    40,    41,    42,    43,    47,    48,    49,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    66,
      67,    71,    72,    76,    77,    78,    79,    80,    81,    85,
      86,    87,    88,    89,    90,    94,    95,    99,   100,   101,
     102,   106,   107,   108,   112,   113,   114,   118,   119,   120,
     121,   122,   126,   127,   128,   132,   133,   137,   138,   142,
     143,   147,   148,   152,   153,   157,   158,   162,   163,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     181,   182,   186,   193,   197,   198,   202,   203,   204,   205,
     209,   210,   214,   215,   219,   220,   224,   225,   226,   227,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   247,   248,   252,   253,   257,   258,   259,
     263,   264,   268,   269,   273,   274,   278,   279,   280,   284,
     288,   292,   293,   297,   298,   299,   300,   301,   302,   303,
     304,   308,   309,   313,   314,   318,   319,   323,   324,   328,
     329,   333,   334,   338,   339,   343,   344,   348,   349,   353,
     357,   358,   359,   363,   364,   368,   369,   373,   377,   378,
     382,   383,   389,   390,   391,   392,   393,   394,   398,   399,
     400,   404,   408,   409,   413,   414,   418,   419,   423,   427,
     428,   432,   433,   434,   438,   439,   440,   441,   445,   446,
     447,   448,   454,   455,   459,   460,   464,   468,   469,   473,
     474
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
  "COLON", "SEMICOLON", "ELLIPSIS", "QUESTION_MARK", "HASH", "IDENTIFIER",
  "INTEGER_CONSTANT", "FLOATING_CONSTANT", "CHAR_CONSTANT",
  "STRING_LITERAL", "WS", "$accept", "primary_expression", "constant",
  "postfix_expression", "argument_expression_list_opt",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "AND_expression", "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "init_declarator_list_opt", "declaration_specifiers",
  "declaration_specifiers_opt", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "specifier_qualifier_list",
  "specifier_qualifier_list_opt", "enum_specifier", "identifier_opt",
  "enumerator_list", "enumerator", "type_qualifier", "function_specifier",
  "declarator", "pointer_opt", "direct_declarator", "identifier_list_opt",
  "assignment_expression_opt", "type_qualifier_list_opt", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name", "initializer",
  "initializer_list", "designation_opt", "designation", "designator_list",
  "designator", "statement", "labeled_statement", "compound_statement",
  "block_item_list_opt", "block_item_list", "block_item",
  "expression_statement", "expression_opt", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list_opt",
  "declaration_list", YY_NULLPTR
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

#define YYPACT_NINF (-212)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-209)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     909,  -212,  -212,  -212,  -212,   -73,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,    11,   909,   909,  -212,   909,   909,   872,
    -212,  -212,   -18,    -1,    29,    47,    71,  -212,   643,   -24,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,    67,  -212,
     108,    29,  -212,   108,   157,  -212,    11,   124,   909,   108,
    -212,    97,   101,   -28,  -212,  -212,  -212,  -212,   103,   692,
     479,    49,   736,   736,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,    94,   180,   760,
    -212,    89,   -13,    30,   130,    35,   125,   129,   138,   146,
       1,  -212,  -212,  -212,   263,  -212,  -212,   161,   128,   568,
     760,  -212,   -33,   479,  -212,  -212,   -23,   943,  -212,   943,
     165,   760,   122,   -14,   157,  -212,    41,  -212,   479,  -212,
    -212,   760,   648,   140,   141,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,   760,  -212,
    -212,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     133,   760,   147,   150,   420,   169,   142,   170,   760,   191,
     192,   154,   156,  -212,  -212,  -212,  -212,   193,   263,  -212,
    -212,   158,  -212,  -212,  -212,  -212,    29,   780,   163,  -212,
     -11,   196,   197,   181,  -212,   182,  -212,  -212,  -212,  -212,
     199,  -212,   760,  -212,  -212,  -212,   668,   220,  -212,  -212,
      62,  -212,  -212,  -212,   221,   -20,  -212,   222,   211,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,    89,    89,   -13,   -13,
      30,    30,    30,    30,   130,   130,    35,   125,   129,   138,
     146,    80,  -212,   212,  -212,   420,   259,   352,   223,   760,
     225,   760,   760,   420,  -212,  -212,  -212,   760,   262,  -212,
     268,   760,  -212,  -212,  -212,   605,   217,   266,  -212,    49,
    -212,  -212,  -212,   157,   266,  -212,  -212,   760,   760,   420,
    -212,   272,   760,   232,  -212,    -5,  -212,    -4,    -3,  -212,
     276,  -212,  -212,   277,  -212,  -212,  -212,     4,  -212,  -212,
    -212,  -212,   760,   238,   760,   420,   420,   420,  -212,  -212,
    -212,   104,     2,   760,   239,   313,  -212,  -212,  -212,   243,
     284,   760,   420,  -212,   420,   285,  -212,  -212,   420,  -212
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    98,   101,   126,   106,   121,    96,   105,   129,   103,
     104,    99,   127,   102,   107,    97,   108,   100,   128,   109,
     110,   111,   205,   132,    91,    91,   112,    91,    91,     0,
     202,   204,   119,     0,   146,     0,    84,    92,    94,     0,
     131,    90,    86,    87,    88,    89,     1,   203,     0,   149,
     147,   145,    83,   132,     0,   209,   132,     0,   207,   132,
     133,   130,   124,     0,   122,   148,   150,    93,    94,     0,
       0,   166,     0,     0,    29,    33,    34,    30,    31,    32,
       2,     6,     7,     8,     4,     9,     3,    23,    35,     0,
      37,    41,    44,    47,    52,    55,    57,    59,    61,    63,
      65,    67,   160,    95,   183,   206,   210,     0,   146,   142,
       0,   117,     0,     0,    27,    80,     0,   116,   159,   116,
       0,     0,     0,     0,     0,   165,     0,   168,     0,    24,
      25,     0,     0,     0,     0,    15,    16,    69,    73,    74,
      70,    71,    72,    75,    76,    77,    78,    79,     0,    35,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,     0,     0,     0,   190,     0,
       0,     2,   189,   186,   187,   172,   173,     0,   182,   184,
     174,     0,   175,   176,   177,   134,   146,   144,   145,   157,
     132,     0,     0,   151,   153,   141,    82,   125,   118,   123,
       0,     5,     0,   115,   113,   114,     0,     0,   171,   161,
     166,   163,   167,   169,     0,     0,    11,     0,    19,    21,
      13,    14,    68,    38,    39,    40,    42,    43,    45,    46,
      48,    49,    50,    51,    53,    54,    56,    58,    60,    62,
      64,     0,   200,     0,   199,   190,     0,   190,     0,     0,
       0,     0,     0,   190,   181,   185,   188,     0,    30,   143,
       0,     0,   155,   140,   139,     0,     0,    28,    81,   166,
      36,   170,   162,     0,     0,    10,    12,     0,     0,   190,
     180,     0,   190,     0,   198,     0,   201,     0,     0,   178,
       0,   138,   135,     0,   152,   154,   158,     0,   164,    22,
      66,   179,     0,     0,   190,   190,   190,   190,   136,   137,
      17,   166,     0,   190,     0,   191,   193,   194,    18,     0,
       0,   190,   190,   195,   190,     0,   192,   197,   190,   196
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -212,  -212,  -212,  -212,  -212,  -212,   -39,  -212,   -78,    24,
      46,    65,    58,   166,   164,   167,   168,   171,  -212,  -106,
     -52,  -212,   -69,  -111,   -35,  -212,     0,   160,  -212,   278,
    -212,   -62,   -82,   213,  -212,  -212,  -212,   224,   -29,  -212,
     -17,  -212,  -212,  -212,  -212,   -95,   287,   226,  -212,  -212,
      63,  -212,   -22,  -117,    61,  -211,  -212,  -212,   215,  -158,
    -212,   286,  -212,  -212,   159,  -212,  -159,  -212,  -212,  -212,
    -212,   315,  -212,  -212,  -212
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    85,    86,    87,   227,   228,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     115,   148,   182,   207,    22,    35,    56,    42,    36,    37,
      24,    25,   118,   214,    26,    33,    63,    64,    27,    28,
      68,    39,    61,   201,   270,    50,    40,    51,   202,   203,
     204,   205,   120,   103,   123,   124,   125,   126,   127,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      29,    30,    31,    57,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,   116,   102,    55,   206,    49,    38,   221,   117,   283,
     217,   150,   208,   197,    32,   206,   256,   111,    59,   260,
     211,   285,    66,   106,    41,    41,  -120,    41,    41,    23,
     114,   219,  -156,   129,   130,   213,     3,   213,   315,   316,
     317,   119,   107,    48,   116,   329,    34,   154,   155,   320,
     149,   117,    12,   112,    62,   117,   168,   117,   212,   116,
     253,   212,   225,    60,    18,   206,   117,   220,    34,   183,
    -156,   149,   102,   233,   234,   235,   212,   212,   212,    49,
     229,   121,   149,   212,   119,   321,   169,   122,   119,   121,
     119,   210,   156,   157,   -85,   122,   232,   290,   293,   119,
     251,   267,   121,   162,   163,   299,   224,   282,   122,   200,
     283,   222,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
      52,   311,   149,   313,   131,     3,   132,   108,   280,   109,
     133,   134,   135,   136,   121,   269,   151,   152,   153,   328,
     122,    12,    53,   183,    62,   324,   196,   325,   326,   327,
     278,   212,   288,    18,   330,    34,   308,    49,   104,    66,
       3,   110,   335,    54,   336,   164,   337,   149,   236,   237,
     339,   165,   310,   272,    69,    43,    12,    44,    45,   166,
     295,   271,   297,   298,   158,   159,   160,   161,    18,    70,
     167,    71,   238,   239,   195,    72,    73,    74,   216,   218,
      75,   257,   259,    76,    77,   300,   252,    78,    79,   303,
     244,   245,   292,   240,   241,   242,   243,   230,   231,   258,
     254,   102,   255,   261,   262,   309,   263,   212,   264,   273,
     274,   266,   277,   322,    80,    81,    82,    83,    84,   149,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   281,   275,   276,   284,   286,     1,   170,   171,     2,
       3,   172,   173,   174,     4,   200,     5,     6,     7,   175,
     176,   177,     8,     9,    10,    11,    12,   178,    13,    14,
      69,    15,   287,   179,   289,   291,    16,    17,    18,   180,
      19,    20,    21,   301,   306,    70,   294,   104,   296,   302,
     279,    72,    73,    74,   312,   314,    75,   318,   319,    76,
      77,   323,   331,    78,    79,   332,   333,   334,   338,   247,
     246,    67,   215,   248,   198,   249,   209,    65,   305,   250,
     307,   223,     0,   105,    47,     0,  -190,   265,     0,     0,
     181,    81,    82,    83,    84,     1,     0,     0,     2,     3,
       0,     0,     0,     4,     0,     5,     6,     7,     0,     0,
       0,     8,     9,    10,    11,    12,     0,    13,    14,    69,
      15,     0,     0,     0,     0,    16,    17,    18,     0,    19,
      20,    21,     0,     0,    70,     0,     0,     0,     0,     0,
      72,    73,    74,     0,     0,    75,     0,     0,    76,    77,
       0,     0,    78,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   170,   171,     0,     0,   172,   173,
     174,     0,     0,     0,     0,     0,   175,   176,   177,    80,
      81,    82,    83,    84,   178,     0,     0,    69,     0,     0,
     179,     0,     0,     0,     0,     0,   180,     0,     0,     0,
       0,     0,    70,     0,   104,     0,     0,     0,    72,    73,
      74,     0,     0,    75,     0,     0,    76,    77,     0,     0,
      78,    79,     0,     0,     0,     2,     3,     0,     0,     0,
       4,     0,     5,     0,     7,     0,     0,     0,     0,     9,
      10,     0,    12,     0,    13,    14,    69,   181,    81,    82,
      83,    84,    16,    17,    18,     0,    19,    20,    21,     0,
       0,    70,     0,     0,     0,     0,     0,    72,    73,    74,
       0,     0,    75,     0,     0,    76,    77,     0,     0,    78,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,     0,    13,    14,     0,    15,     0,     0,     0,
       0,    16,    17,    18,     0,    19,    20,    21,     1,     0,
       0,     2,     3,     0,     0,     0,     4,     0,     5,     6,
       7,     0,     0,     0,     8,     9,    10,    11,    12,     0,
      13,    14,     0,    15,     0,     0,     0,     0,    16,    17,
      18,     0,    19,    20,    21,     0,     1,     0,     0,     2,
       3,     0,     0,     0,     4,   199,     5,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,     0,    13,    14,
       0,    15,     0,     0,     0,    69,    16,    17,    18,     0,
      19,    20,    21,     0,     0,     0,     0,  -208,     0,   304,
      70,   226,     0,     0,     0,    69,    72,    73,    74,     0,
       0,    75,     0,     0,    76,    77,     0,     0,    78,    79,
      70,     0,   279,    54,     0,     0,    72,    73,    74,    69,
       0,    75,     0,     0,    76,    77,     0,     0,    78,    79,
       0,     0,     0,     0,   113,    80,    81,    82,    83,    84,
      72,    73,    74,     0,     0,    75,     0,     0,    76,    77,
       0,     0,    78,    79,     0,    80,    81,    82,    83,    84,
       0,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,    80,
      81,    82,    83,    84,    72,    73,    74,    69,     0,    75,
       0,     0,    76,    77,     0,     0,    78,    79,     0,     0,
       0,     0,    70,     0,     0,     0,     0,    69,    72,    73,
      74,     0,     0,    75,     0,     0,    76,    77,     0,     0,
      78,    79,    70,    80,    81,    82,    83,    84,    72,    73,
      74,     0,     0,    75,     0,     0,    76,   268,     0,     0,
      78,    79,     0,     0,     0,     0,     0,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    81,    82,
      83,    84,    46,     0,     0,     1,     0,     0,     2,     3,
       0,     0,     0,     4,     0,     5,     6,     7,     0,     0,
       0,     8,     9,    10,    11,    12,     0,    13,    14,     0,
      15,     0,     0,     0,     0,    16,    17,    18,     0,    19,
      20,    21,     1,     0,     0,     2,     3,     0,     0,     0,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,     0,    13,    14,     0,    15,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21,     2,
       3,     0,     0,     0,     4,     0,     5,     0,     7,     0,
       0,     0,     0,     9,    10,     0,    12,     0,    13,    14,
       0,     0,     0,     0,     0,     0,    16,    17,    18,     0,
      19,    20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    70,    54,    38,   110,    34,    23,   124,    70,   220,
     121,    89,    45,   108,    87,   121,   174,    45,    42,   178,
      43,    41,    51,    58,    24,    25,    44,    27,    28,    29,
      69,    45,    43,    72,    73,   117,     7,   119,    43,    43,
      43,    70,    59,    44,   113,    43,    57,    60,    61,    45,
      89,   113,    23,    81,    87,   117,    55,   119,    81,   128,
     171,    81,   131,    87,    35,   171,   128,    81,    57,   104,
      81,   110,   124,   151,   152,   153,    81,    81,    81,   108,
     132,    40,   121,    81,   113,    81,    85,    46,   117,    40,
     119,   113,    62,    63,    83,    46,   148,   255,   257,   128,
     169,   196,    40,    68,    69,   263,   128,    45,    46,   109,
     321,    70,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      83,   289,   171,   292,    40,     7,    42,    40,   216,    42,
      46,    47,    48,    49,    40,   197,    57,    58,    59,    45,
      46,    23,    81,   188,    87,   314,    28,   315,   316,   317,
     212,    81,    82,    35,   323,    57,   283,   196,    44,   198,
       7,    70,   331,    70,   332,    50,   334,   216,   154,   155,
     338,    52,   288,   200,    27,    25,    23,    27,    28,    51,
     259,    28,   261,   262,    64,    65,    66,    67,    35,    42,
      54,    44,   156,   157,    43,    48,    49,    50,    43,    87,
      53,    42,    42,    56,    57,   267,    83,    60,    61,   271,
     162,   163,   257,   158,   159,   160,   161,    87,    87,    87,
      83,   283,    82,    42,    42,   287,    82,    81,    45,    43,
      43,    83,    43,   312,    87,    88,    89,    90,    91,   288,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    41,    81,    81,    43,    43,     3,     4,     5,     6,
       7,     8,     9,    10,    11,   275,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    81,    30,    82,    36,    33,    34,    35,    36,
      37,    38,    39,    41,    87,    42,    83,    44,    83,    41,
      44,    48,    49,    50,    42,    83,    53,    41,    41,    56,
      57,    83,    83,    60,    61,    12,    83,    43,    43,   165,
     164,    53,   119,   166,   108,   167,   112,    50,   275,   168,
     279,   126,    -1,    57,    29,    -1,    83,   188,    -1,    -1,
      87,    88,    89,    90,    91,     3,    -1,    -1,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    -1,    -1,    53,    -1,    -1,    56,    57,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    87,
      88,    89,    90,    91,    24,    -1,    -1,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,    49,
      50,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,
      60,    61,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,
      11,    -1,    13,    -1,    15,    -1,    -1,    -1,    -1,    20,
      21,    -1,    23,    -1,    25,    26,    27,    87,    88,    89,
      90,    91,    33,    34,    35,    -1,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      -1,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    37,    38,    39,     3,    -1,
      -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,
      25,    26,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    -1,    37,    38,    39,    -1,     3,    -1,    -1,     6,
       7,    -1,    -1,    -1,    11,    87,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    -1,    25,    26,
      -1,    28,    -1,    -1,    -1,    27,    33,    34,    35,    -1,
      37,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,    84,
      42,    43,    -1,    -1,    -1,    27,    48,    49,    50,    -1,
      -1,    53,    -1,    -1,    56,    57,    -1,    -1,    60,    61,
      42,    -1,    44,    70,    -1,    -1,    48,    49,    50,    27,
      -1,    53,    -1,    -1,    56,    57,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    42,    87,    88,    89,    90,    91,
      48,    49,    50,    -1,    -1,    53,    -1,    -1,    56,    57,
      -1,    -1,    60,    61,    -1,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    87,
      88,    89,    90,    91,    48,    49,    50,    27,    -1,    53,
      -1,    -1,    56,    57,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    27,    48,    49,
      50,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,
      60,    61,    42,    87,    88,    89,    90,    91,    48,    49,
      50,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    91,     0,    -1,    -1,     3,    -1,    -1,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    -1,    25,    26,    -1,
      28,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,    37,
      38,    39,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39,     6,
       7,    -1,    -1,    -1,    11,    -1,    13,    -1,    15,    -1,
      -1,    -1,    -1,    20,    21,    -1,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,
      37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    22,    23,    25,    26,    28,    33,    34,    35,    37,
      38,    39,   117,   119,   123,   124,   127,   131,   132,   163,
     164,   165,    87,   128,    57,   118,   121,   122,   133,   134,
     139,   119,   120,   120,   120,   120,     0,   164,    44,   131,
     138,   140,    83,    81,    70,   117,   119,   166,   167,    42,
      87,   135,    87,   129,   130,   139,   131,   122,   133,    27,
      42,    44,    48,    49,    50,    53,    56,    57,    60,    61,
      87,    88,    89,    90,    91,    94,    95,    96,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   146,    44,   154,   117,   133,    40,    42,
      70,    45,    81,    42,    99,   113,   115,   124,   125,   131,
     145,    40,    46,   147,   148,   149,   150,   151,    42,    99,
      99,    40,    42,    46,    47,    48,    49,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,   114,    99,
     101,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    50,    52,    51,    54,    55,    85,
       4,     5,     8,     9,    10,    16,    17,    18,    24,    30,
      36,    87,   115,   117,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,    43,    28,   138,   140,    87,
     119,   136,   141,   142,   143,   144,   112,   116,    45,   130,
     145,    43,    81,   125,   126,   126,    43,   116,    87,    45,
      81,   146,    70,   151,   145,   115,    43,    97,    98,   113,
      87,    87,   113,   101,   101,   101,   102,   102,   103,   103,
     104,   104,   104,   104,   105,   105,   106,   107,   108,   109,
     110,   115,    83,   116,    83,    82,   152,    42,    87,    42,
     159,    42,    42,    82,    45,   157,    83,   138,    57,   113,
     137,    28,   133,    43,    43,    81,    81,    43,   113,    44,
     101,    41,    45,   148,    43,    41,    43,    81,    82,    82,
     152,    36,   117,   159,    83,   115,    83,   115,   115,   152,
     113,    41,    41,   113,    84,   143,    87,   147,   146,   113,
     112,   152,    42,   159,    83,    43,    43,    43,    41,    41,
      45,    81,   115,    83,   159,   152,   152,   152,    45,    43,
     159,    83,    12,    83,    43,   159,   152,   152,    43,   152
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    94,    94,    95,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    99,    99,    99,    99,    99,    99,   100,
     100,   100,   100,   100,   100,   101,   101,   102,   102,   102,
     102,   103,   103,   103,   104,   104,   104,   105,   105,   105,
     105,   105,   106,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   112,   112,   113,   113,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115,   116,   117,   118,   118,   119,   119,   119,   119,
     120,   120,   121,   121,   122,   122,   123,   123,   123,   123,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   125,   125,   126,   126,   127,   127,   127,
     128,   128,   129,   129,   130,   130,   131,   131,   131,   132,
     133,   134,   134,   135,   135,   135,   135,   135,   135,   135,
     135,   136,   136,   137,   137,   138,   138,   139,   139,   140,
     140,   141,   141,   142,   142,   143,   143,   144,   144,   145,
     146,   146,   146,   147,   147,   148,   148,   149,   150,   150,
     151,   151,   152,   152,   152,   152,   152,   152,   153,   153,
     153,   154,   155,   155,   156,   156,   157,   157,   158,   159,
     159,   160,   160,   160,   161,   161,   161,   161,   162,   162,
     162,   162,   163,   163,   164,   164,   165,   166,   166,   167,
     167
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
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     0,     2,     2,     2,     2,
       1,     0,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     0,     5,     6,     2,
       1,     0,     1,     3,     1,     3,     1,     1,     1,     1,
       2,     1,     0,     1,     3,     5,     6,     6,     5,     4,
       4,     1,     0,     1,     0,     1,     0,     2,     3,     1,
       2,     1,     3,     1,     3,     2,     1,     1,     3,     1,
       1,     3,     4,     2,     4,     1,     0,     2,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     3,     1,     0,     1,     2,     1,     1,     2,     1,
       0,     5,     7,     5,     5,     7,     9,     8,     3,     2,
       2,     3,     1,     2,     1,     1,     4,     1,     0,     1,
       2
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
#line 40 "ass4_21CS10014_21CS30032.y"
                 { printf("primary-expression -> identifier\n"); }
#line 1913 "y.tab.c"
    break;

  case 3:
#line 41 "ass4_21CS10014_21CS30032.y"
               { printf("primary-expression -> constant\n"); }
#line 1919 "y.tab.c"
    break;

  case 4:
#line 42 "ass4_21CS10014_21CS30032.y"
                     { printf("primary-expression -> string-literal\n"); }
#line 1925 "y.tab.c"
    break;

  case 5:
#line 43 "ass4_21CS10014_21CS30032.y"
                                                        { printf("primary-expression -> ( expression )\n"); }
#line 1931 "y.tab.c"
    break;

  case 6:
#line 47 "ass4_21CS10014_21CS30032.y"
                       { printf("constant -> integer-constant\n"); }
#line 1937 "y.tab.c"
    break;

  case 7:
#line 48 "ass4_21CS10014_21CS30032.y"
                        { printf("constant -> floating-constant\n"); }
#line 1943 "y.tab.c"
    break;

  case 8:
#line 49 "ass4_21CS10014_21CS30032.y"
                    { printf("constant -> character-constant\n"); }
#line 1949 "y.tab.c"
    break;

  case 9:
#line 53 "ass4_21CS10014_21CS30032.y"
                         { printf("postfix-expression -> primary-expression\n"); }
#line 1955 "y.tab.c"
    break;

  case 10:
#line 54 "ass4_21CS10014_21CS30032.y"
                                                                             { printf("postfix-expression -> postfix-expression [ expression ]\n"); }
#line 1961 "y.tab.c"
    break;

  case 11:
#line 55 "ass4_21CS10014_21CS30032.y"
                                                                { printf("postfix-expression -> postfix-expression ( )\n"); }
#line 1967 "y.tab.c"
    break;

  case 12:
#line 56 "ass4_21CS10014_21CS30032.y"
                                                                                             { printf("postfix-expression -> postfix-expression ( argument-expression-list )\n"); }
#line 1973 "y.tab.c"
    break;

  case 13:
#line 57 "ass4_21CS10014_21CS30032.y"
                                        { printf("postfix-expression -> postfix-expression . identifier\n"); }
#line 1979 "y.tab.c"
    break;

  case 14:
#line 58 "ass4_21CS10014_21CS30032.y"
                                          { printf("postfix-expression -> postfix-expression -> identifier\n"); }
#line 1985 "y.tab.c"
    break;

  case 15:
#line 59 "ass4_21CS10014_21CS30032.y"
                                   { printf("postfix-expression -> postfix-expression ++\n"); }
#line 1991 "y.tab.c"
    break;

  case 16:
#line 60 "ass4_21CS10014_21CS30032.y"
                                   { printf("postfix-expression -> postfix-expression --\n"); }
#line 1997 "y.tab.c"
    break;

  case 17:
#line 61 "ass4_21CS10014_21CS30032.y"
                                                                                                               { printf("postfix-expression -> ( type-name ) { initializer-list }\n"); }
#line 2003 "y.tab.c"
    break;

  case 18:
#line 62 "ass4_21CS10014_21CS30032.y"
                                                                                                                     { printf("postfix-expression -> ( type-name ) { initializer-list , }\n"); }
#line 2009 "y.tab.c"
    break;

  case 19:
#line 66 "ass4_21CS10014_21CS30032.y"
                               { printf("argument-expression-list-opt -> argument-expression-list\n"); }
#line 2015 "y.tab.c"
    break;

  case 20:
#line 67 "ass4_21CS10014_21CS30032.y"
      { printf("argument-expression-list-opt -> epsilon\n"); }
#line 2021 "y.tab.c"
    break;

  case 21:
#line 71 "ass4_21CS10014_21CS30032.y"
                            { printf("argument-expression-list -> assignment-expression\n"); }
#line 2027 "y.tab.c"
    break;

  case 22:
#line 72 "ass4_21CS10014_21CS30032.y"
                                                           { printf("argument-expression-list -> argument-expression-list , assignment-expression\n"); }
#line 2033 "y.tab.c"
    break;

  case 23:
#line 76 "ass4_21CS10014_21CS30032.y"
                         { printf("unary-expression -> postfix-expression\n"); }
#line 2039 "y.tab.c"
    break;

  case 24:
#line 77 "ass4_21CS10014_21CS30032.y"
                                 { printf("unary-expression -> ++ unary-expression\n"); }
#line 2045 "y.tab.c"
    break;

  case 25:
#line 78 "ass4_21CS10014_21CS30032.y"
                                 { printf("unary-expression -> -- unary-expression\n"); }
#line 2051 "y.tab.c"
    break;

  case 26:
#line 79 "ass4_21CS10014_21CS30032.y"
                                     { printf("unary-expression -> unary-operator cast-expression\n"); }
#line 2057 "y.tab.c"
    break;

  case 27:
#line 80 "ass4_21CS10014_21CS30032.y"
                              { printf("unary-expression -> sizeof unary-expression\n"); }
#line 2063 "y.tab.c"
    break;

  case 28:
#line 81 "ass4_21CS10014_21CS30032.y"
                                                              { printf("unary-expression -> sizeof ( type-name )\n"); }
#line 2069 "y.tab.c"
    break;

  case 29:
#line 85 "ass4_21CS10014_21CS30032.y"
                  { printf("unary-operator -> &\n"); }
#line 2075 "y.tab.c"
    break;

  case 30:
#line 86 "ass4_21CS10014_21CS30032.y"
               { printf("unary-operator -> *\n"); }
#line 2081 "y.tab.c"
    break;

  case 31:
#line 87 "ass4_21CS10014_21CS30032.y"
           { printf("unary-operator -> +\n"); }
#line 2087 "y.tab.c"
    break;

  case 32:
#line 88 "ass4_21CS10014_21CS30032.y"
            { printf("unary-operator -> -\n"); }
#line 2093 "y.tab.c"
    break;

  case 33:
#line 89 "ass4_21CS10014_21CS30032.y"
                  { printf("unary-operator -> ~\n"); }
#line 2099 "y.tab.c"
    break;

  case 34:
#line 90 "ass4_21CS10014_21CS30032.y"
                  { printf("unary-operator -> !\n"); }
#line 2105 "y.tab.c"
    break;

  case 35:
#line 94 "ass4_21CS10014_21CS30032.y"
                       { printf("cast-expression -> unary-expression\n"); }
#line 2111 "y.tab.c"
    break;

  case 36:
#line 95 "ass4_21CS10014_21CS30032.y"
                                                                       { printf("cast-expression -> ( type-name ) cast-expression\n"); }
#line 2117 "y.tab.c"
    break;

  case 37:
#line 99 "ass4_21CS10014_21CS30032.y"
                      { printf("multiplicative-expression -> cast-expression\n"); }
#line 2123 "y.tab.c"
    break;

  case 38:
#line 100 "ass4_21CS10014_21CS30032.y"
                                                         { printf("multiplicative-expression -> multiplicative-expression * cast-expression\n"); }
#line 2129 "y.tab.c"
    break;

  case 39:
#line 101 "ass4_21CS10014_21CS30032.y"
                                                       { printf("multiplicative-expression -> multiplicative-expression / cast-expression\n"); }
#line 2135 "y.tab.c"
    break;

  case 40:
#line 102 "ass4_21CS10014_21CS30032.y"
                                                       { printf("multiplicative-expression -> multiplicative-expression %% cast-expression\n"); }
#line 2141 "y.tab.c"
    break;

  case 41:
#line 106 "ass4_21CS10014_21CS30032.y"
                                { printf("additive-expression -> multiplicative-expression\n"); }
#line 2147 "y.tab.c"
    break;

  case 42:
#line 107 "ass4_21CS10014_21CS30032.y"
                                                         { printf("additive-expression -> additive-expression + multiplicative-expression\n"); }
#line 2153 "y.tab.c"
    break;

  case 43:
#line 108 "ass4_21CS10014_21CS30032.y"
                                                          { printf("additive-expression -> additive-expression - multiplicative-expression\n"); }
#line 2159 "y.tab.c"
    break;

  case 44:
#line 112 "ass4_21CS10014_21CS30032.y"
                          { printf("shift-expression -> additive-expression\n"); }
#line 2165 "y.tab.c"
    break;

  case 45:
#line 113 "ass4_21CS10014_21CS30032.y"
                                                      { printf("shift-expression -> shift-expression << additive-expression\n"); }
#line 2171 "y.tab.c"
    break;

  case 46:
#line 114 "ass4_21CS10014_21CS30032.y"
                                                       { printf("shift-expression -> shift-expression >> additive-expression\n"); }
#line 2177 "y.tab.c"
    break;

  case 47:
#line 118 "ass4_21CS10014_21CS30032.y"
                       { printf("relational-expression -> shift-expression\n"); }
#line 2183 "y.tab.c"
    break;

  case 48:
#line 119 "ass4_21CS10014_21CS30032.y"
                                                       { printf("relational-expression -> relational-expression < shift-expression\n"); }
#line 2189 "y.tab.c"
    break;

  case 49:
#line 120 "ass4_21CS10014_21CS30032.y"
                                                          { printf("relational-expression -> relational-expression > shift-expression\n"); }
#line 2195 "y.tab.c"
    break;

  case 50:
#line 121 "ass4_21CS10014_21CS30032.y"
                                                             { printf("relational-expression -> relational-expression <= shift-expression\n"); }
#line 2201 "y.tab.c"
    break;

  case 51:
#line 122 "ass4_21CS10014_21CS30032.y"
                                                                { printf("relational-expression -> relational-expression >= shift-expression\n"); }
#line 2207 "y.tab.c"
    break;

  case 52:
#line 126 "ass4_21CS10014_21CS30032.y"
                            { printf("equality-expression -> relational-expression\n"); }
#line 2213 "y.tab.c"
    break;

  case 53:
#line 127 "ass4_21CS10014_21CS30032.y"
                                                      { printf("equality-expression -> equality-expression == relational-expression\n"); }
#line 2219 "y.tab.c"
    break;

  case 54:
#line 128 "ass4_21CS10014_21CS30032.y"
                                                          { printf("equality-expression -> equality-expression != relational-expression\n"); }
#line 2225 "y.tab.c"
    break;

  case 55:
#line 132 "ass4_21CS10014_21CS30032.y"
                          { printf("AND-expression -> equality-expression\n"); }
#line 2231 "y.tab.c"
    break;

  case 56:
#line 133 "ass4_21CS10014_21CS30032.y"
                                                     { printf("AND-expression -> AND-expression & equality-expression\n"); }
#line 2237 "y.tab.c"
    break;

  case 57:
#line 137 "ass4_21CS10014_21CS30032.y"
                     { printf("exclusive-OR-expression -> AND-expression\n"); }
#line 2243 "y.tab.c"
    break;

  case 58:
#line 138 "ass4_21CS10014_21CS30032.y"
                                                         { printf("exclusive-OR-expression -> exclusive-OR-expression ^ AND-expression\n"); }
#line 2249 "y.tab.c"
    break;

  case 59:
#line 142 "ass4_21CS10014_21CS30032.y"
                              { printf("inclusive-OR-expression -> exclusive-OR-expression\n"); }
#line 2255 "y.tab.c"
    break;

  case 60:
#line 143 "ass4_21CS10014_21CS30032.y"
                                                                 { printf("inclusive-OR-expression -> inclusive-OR-expression | exclusive-OR-expression\n"); }
#line 2261 "y.tab.c"
    break;

  case 61:
#line 147 "ass4_21CS10014_21CS30032.y"
                              { printf("logical-AND-expression -> inclusive-OR-expression\n"); }
#line 2267 "y.tab.c"
    break;

  case 62:
#line 148 "ass4_21CS10014_21CS30032.y"
                                                                 { printf("logical-AND-expression -> logical-AND-expression && inclusive-OR-expression\n"); }
#line 2273 "y.tab.c"
    break;

  case 63:
#line 152 "ass4_21CS10014_21CS30032.y"
                             { printf("logical-OR-expression -> logical-AND-expression\n"); }
#line 2279 "y.tab.c"
    break;

  case 64:
#line 153 "ass4_21CS10014_21CS30032.y"
                                                              { printf("logical-OR-expression -> logical-OR-expression || logical-AND-expression\n"); }
#line 2285 "y.tab.c"
    break;

  case 65:
#line 157 "ass4_21CS10014_21CS30032.y"
                            { printf("conditional-expression -> logical-OR-expression\n"); }
#line 2291 "y.tab.c"
    break;

  case 66:
#line 158 "ass4_21CS10014_21CS30032.y"
                                                                                  { printf("conditional-expression -> logical-OR-expression ? expression : conditional-expression\n"); }
#line 2297 "y.tab.c"
    break;

  case 67:
#line 162 "ass4_21CS10014_21CS30032.y"
                             { printf("assignment-expression -> conditional-expression\n"); }
#line 2303 "y.tab.c"
    break;

  case 68:
#line 163 "ass4_21CS10014_21CS30032.y"
                                                                 { printf("assignment-expression -> unary-expression assignment-operator assignment-expression\n"); }
#line 2309 "y.tab.c"
    break;

  case 69:
#line 167 "ass4_21CS10014_21CS30032.y"
             { printf("assignment-operator -> =\n"); }
#line 2315 "y.tab.c"
    break;

  case 70:
#line 168 "ass4_21CS10014_21CS30032.y"
                      { printf("assignment-operator -> *=\n"); }
#line 2321 "y.tab.c"
    break;

  case 71:
#line 169 "ass4_21CS10014_21CS30032.y"
                    { printf("assignment-operator -> /=\n"); }
#line 2327 "y.tab.c"
    break;

  case 72:
#line 170 "ass4_21CS10014_21CS30032.y"
                    { printf("assignment-operator -> %%=\n"); }
#line 2333 "y.tab.c"
    break;

  case 73:
#line 171 "ass4_21CS10014_21CS30032.y"
                  { printf("assignment-operator -> +=\n"); }
#line 2339 "y.tab.c"
    break;

  case 74:
#line 172 "ass4_21CS10014_21CS30032.y"
                   { printf("assignment-operator -> -=\n"); }
#line 2345 "y.tab.c"
    break;

  case 75:
#line 173 "ass4_21CS10014_21CS30032.y"
                        { printf("assignment-operator -> <<=\n"); }
#line 2351 "y.tab.c"
    break;

  case 76:
#line 174 "ass4_21CS10014_21CS30032.y"
                         { printf("assignment-operator -> >>=\n"); }
#line 2357 "y.tab.c"
    break;

  case 77:
#line 175 "ass4_21CS10014_21CS30032.y"
                         { printf("assignment-operator -> &=\n"); }
#line 2363 "y.tab.c"
    break;

  case 78:
#line 176 "ass4_21CS10014_21CS30032.y"
                         { printf("assignment-operator -> ^=\n"); }
#line 2369 "y.tab.c"
    break;

  case 79:
#line 177 "ass4_21CS10014_21CS30032.y"
                        { printf("assignment-operator -> |=\n"); }
#line 2375 "y.tab.c"
    break;

  case 80:
#line 181 "ass4_21CS10014_21CS30032.y"
                            { printf("expression -> assignment-expression\n"); }
#line 2381 "y.tab.c"
    break;

  case 81:
#line 182 "ass4_21CS10014_21CS30032.y"
                                             { printf("expression -> expression , assignment-expression\n"); }
#line 2387 "y.tab.c"
    break;

  case 82:
#line 186 "ass4_21CS10014_21CS30032.y"
                             { printf("constant-expression -> conditional-expression\n"); }
#line 2393 "y.tab.c"
    break;

  case 83:
#line 193 "ass4_21CS10014_21CS30032.y"
                                                                { printf("declaration -> declaration-specifiers init-declarator-list-opt ;\n"); }
#line 2399 "y.tab.c"
    break;

  case 84:
#line 197 "ass4_21CS10014_21CS30032.y"
                           { printf("init-declarator-list-opt -> init-declarator-list\n"); }
#line 2405 "y.tab.c"
    break;

  case 85:
#line 198 "ass4_21CS10014_21CS30032.y"
      { printf("init-declarator-list-opt -> epsilon\n"); }
#line 2411 "y.tab.c"
    break;

  case 86:
#line 202 "ass4_21CS10014_21CS30032.y"
                                                         { printf("declaration-specifiers -> storage-class-specifier declaration-specifiers-opt\n"); }
#line 2417 "y.tab.c"
    break;

  case 87:
#line 203 "ass4_21CS10014_21CS30032.y"
                                                { printf("declaration-specifiers -> type-specifier declaration-specifiers-opt\n"); }
#line 2423 "y.tab.c"
    break;

  case 88:
#line 204 "ass4_21CS10014_21CS30032.y"
                                                { printf("declaration-specifiers -> type-qualifier declaration-specifiers-opt\n"); }
#line 2429 "y.tab.c"
    break;

  case 89:
#line 205 "ass4_21CS10014_21CS30032.y"
                                                    { printf("declaration-specifiers -> function-specifier declaration-specifiers-opt\n"); }
#line 2435 "y.tab.c"
    break;

  case 90:
#line 209 "ass4_21CS10014_21CS30032.y"
                             { printf("declaration-specifiers-opt -> declaration-specifiers\n"); }
#line 2441 "y.tab.c"
    break;

  case 91:
#line 210 "ass4_21CS10014_21CS30032.y"
      { printf("declaration-specifiers-opt -> epsilon\n"); }
#line 2447 "y.tab.c"
    break;

  case 92:
#line 214 "ass4_21CS10014_21CS30032.y"
                      { printf("init-declarator-list -> init-declarator\n"); }
#line 2453 "y.tab.c"
    break;

  case 93:
#line 215 "ass4_21CS10014_21CS30032.y"
                                                 { printf("init-declarator-list -> init-declarator-list , init-declarator\n"); }
#line 2459 "y.tab.c"
    break;

  case 94:
#line 219 "ass4_21CS10014_21CS30032.y"
                 { printf("init-declarator -> declarator\n"); }
#line 2465 "y.tab.c"
    break;

  case 95:
#line 220 "ass4_21CS10014_21CS30032.y"
                                    { printf("init-declarator -> declarator = initializer\n"); }
#line 2471 "y.tab.c"
    break;

  case 96:
#line 224 "ass4_21CS10014_21CS30032.y"
             { printf("storage-class-specifier -> extern\n"); }
#line 2477 "y.tab.c"
    break;

  case 97:
#line 225 "ass4_21CS10014_21CS30032.y"
             { printf("storage-class-specifier -> static\n"); }
#line 2483 "y.tab.c"
    break;

  case 98:
#line 226 "ass4_21CS10014_21CS30032.y"
           { printf("storage-class-specifier -> auto\n"); }
#line 2489 "y.tab.c"
    break;

  case 99:
#line 227 "ass4_21CS10014_21CS30032.y"
               { printf("storage-class-specifier -> register\n"); }
#line 2495 "y.tab.c"
    break;

  case 100:
#line 231 "ass4_21CS10014_21CS30032.y"
           { printf("type-specifier -> void\n"); }
#line 2501 "y.tab.c"
    break;

  case 101:
#line 232 "ass4_21CS10014_21CS30032.y"
           { printf("type-specifier -> char\n"); }
#line 2507 "y.tab.c"
    break;

  case 102:
#line 233 "ass4_21CS10014_21CS30032.y"
            { printf("type-specifier -> short\n"); }
#line 2513 "y.tab.c"
    break;

  case 103:
#line 234 "ass4_21CS10014_21CS30032.y"
          { printf("type-specifier -> int\n"); }
#line 2519 "y.tab.c"
    break;

  case 104:
#line 235 "ass4_21CS10014_21CS30032.y"
           { printf("type-specifier -> long\n"); }
#line 2525 "y.tab.c"
    break;

  case 105:
#line 236 "ass4_21CS10014_21CS30032.y"
            { printf("type-specifier -> float\n"); }
#line 2531 "y.tab.c"
    break;

  case 106:
#line 237 "ass4_21CS10014_21CS30032.y"
             { printf("type-specifier -> double\n"); }
#line 2537 "y.tab.c"
    break;

  case 107:
#line 238 "ass4_21CS10014_21CS30032.y"
             { printf("type-specifier -> signed\n"); }
#line 2543 "y.tab.c"
    break;

  case 108:
#line 239 "ass4_21CS10014_21CS30032.y"
               { printf("type-specifier -> unsigned\n"); }
#line 2549 "y.tab.c"
    break;

  case 109:
#line 240 "ass4_21CS10014_21CS30032.y"
           { printf("type-specifier -> _Bool\n"); }
#line 2555 "y.tab.c"
    break;

  case 110:
#line 241 "ass4_21CS10014_21CS30032.y"
              { printf("type-specifier -> _Complex\n"); }
#line 2561 "y.tab.c"
    break;

  case 111:
#line 242 "ass4_21CS10014_21CS30032.y"
                { printf("type-specifier -> _Imaginary\n"); }
#line 2567 "y.tab.c"
    break;

  case 112:
#line 243 "ass4_21CS10014_21CS30032.y"
                     { printf("type-specifier -> enum-specifier\n"); }
#line 2573 "y.tab.c"
    break;

  case 113:
#line 247 "ass4_21CS10014_21CS30032.y"
                                                  { printf("specifier-qualifier-list -> type-specifier specifier-qualifier-list-opt\n"); }
#line 2579 "y.tab.c"
    break;

  case 114:
#line 248 "ass4_21CS10014_21CS30032.y"
                                                  { printf("specifier-qualifier-list -> type-qualifier specifier-qualifier-list-opt\n"); }
#line 2585 "y.tab.c"
    break;

  case 115:
#line 252 "ass4_21CS10014_21CS30032.y"
                               { printf("specifier-qualifier-list-opt -> specifier-qualifier-list\n"); }
#line 2591 "y.tab.c"
    break;

  case 116:
#line 253 "ass4_21CS10014_21CS30032.y"
      { printf("specifier-qualifier-list-opt -> epsilon\n"); }
#line 2597 "y.tab.c"
    break;

  case 117:
#line 257 "ass4_21CS10014_21CS30032.y"
                                                                                 { printf("enum-specifier -> enum identifier-opt { enumerator-list-opt }\n"); }
#line 2603 "y.tab.c"
    break;

  case 118:
#line 258 "ass4_21CS10014_21CS30032.y"
                                                                                       { printf("enum-specifier -> enum identifier-opt { enumerator-list , }\n"); }
#line 2609 "y.tab.c"
    break;

  case 119:
#line 259 "ass4_21CS10014_21CS30032.y"
                      { printf("enum-specifier -> enum identifier\n"); }
#line 2615 "y.tab.c"
    break;

  case 120:
#line 263 "ass4_21CS10014_21CS30032.y"
                 { printf("identifier-opt -> identifier\n"); }
#line 2621 "y.tab.c"
    break;

  case 121:
#line 264 "ass4_21CS10014_21CS30032.y"
      { printf("identifier-opt -> epsilon\n"); }
#line 2627 "y.tab.c"
    break;

  case 122:
#line 268 "ass4_21CS10014_21CS30032.y"
                 { printf("enumerator-list -> enumerator\n"); }
#line 2633 "y.tab.c"
    break;

  case 123:
#line 269 "ass4_21CS10014_21CS30032.y"
                                       { printf("enumerator-list -> enumerator-list , enumerator\n"); }
#line 2639 "y.tab.c"
    break;

  case 124:
#line 273 "ass4_21CS10014_21CS30032.y"
                 { printf("enumerator -> enumeration-constant\n"); }
#line 2645 "y.tab.c"
    break;

  case 125:
#line 274 "ass4_21CS10014_21CS30032.y"
                                            { printf("enumerator -> enumeration-constant = constant-expression\n"); }
#line 2651 "y.tab.c"
    break;

  case 126:
#line 278 "ass4_21CS10014_21CS30032.y"
            { printf("type-qualifier -> const\n"); }
#line 2657 "y.tab.c"
    break;

  case 127:
#line 279 "ass4_21CS10014_21CS30032.y"
               { printf("type-qualifier -> restrict\n"); }
#line 2663 "y.tab.c"
    break;

  case 128:
#line 280 "ass4_21CS10014_21CS30032.y"
               { printf("type-qualifier -> volatile\n"); }
#line 2669 "y.tab.c"
    break;

  case 129:
#line 284 "ass4_21CS10014_21CS30032.y"
             { printf("function-specifier -> inline\n"); }
#line 2675 "y.tab.c"
    break;

  case 130:
#line 288 "ass4_21CS10014_21CS30032.y"
                                    { printf("declarator -> pointer-opt direct-declarator\n"); }
#line 2681 "y.tab.c"
    break;

  case 131:
#line 292 "ass4_21CS10014_21CS30032.y"
              { printf("pointer-opt -> pointer\n"); }
#line 2687 "y.tab.c"
    break;

  case 132:
#line 293 "ass4_21CS10014_21CS30032.y"
      { printf("pointer-opt -> epsilon\n"); }
#line 2693 "y.tab.c"
    break;

  case 133:
#line 297 "ass4_21CS10014_21CS30032.y"
                 { printf("direct-declarator -> identifier\n"); }
#line 2699 "y.tab.c"
    break;

  case 134:
#line 298 "ass4_21CS10014_21CS30032.y"
                                                        { printf("direct-declarator -> ( declarator )\n"); }
#line 2705 "y.tab.c"
    break;

  case 135:
#line 299 "ass4_21CS10014_21CS30032.y"
                                                                                                                   { printf("direct-declarator -> direct-declarator [ type-qualifier-list-opt assignment-expression-opt ]\n"); }
#line 2711 "y.tab.c"
    break;

  case 136:
#line 300 "ass4_21CS10014_21CS30032.y"
                                                                                                                      { printf("direct-declarator -> direct-declarator [ static type-qualifier-list-opt assignment-expression ]\n"); }
#line 2717 "y.tab.c"
    break;

  case 137:
#line 301 "ass4_21CS10014_21CS30032.y"
                                                                                                                  { printf("direct-declarator -> direct-declarator [ type-qualifier-list static assignment-expression ]\n"); }
#line 2723 "y.tab.c"
    break;

  case 138:
#line 302 "ass4_21CS10014_21CS30032.y"
                                                                                                  { printf("direct-declarator -> direct-declarator [ type-qualifier-list-opt * ]\n"); }
#line 2729 "y.tab.c"
    break;

  case 139:
#line 303 "ass4_21CS10014_21CS30032.y"
                                                                                   { printf("direct-declarator -> direct-declarator ( parameter-type-list )\n"); }
#line 2735 "y.tab.c"
    break;

  case 140:
#line 304 "ass4_21CS10014_21CS30032.y"
                                                                                   { printf("direct-declarator -> direct-declarator ( identifier-list-opt )\n"); }
#line 2741 "y.tab.c"
    break;

  case 141:
#line 308 "ass4_21CS10014_21CS30032.y"
                      { printf("identifier-list-opt -> identifier-list\n"); }
#line 2747 "y.tab.c"
    break;

  case 142:
#line 309 "ass4_21CS10014_21CS30032.y"
      { printf("identifier-list-opt -> epsilon\n"); }
#line 2753 "y.tab.c"
    break;

  case 143:
#line 313 "ass4_21CS10014_21CS30032.y"
                            { printf("assignment-expression-opt -> assignment-expression\n"); }
#line 2759 "y.tab.c"
    break;

  case 144:
#line 314 "ass4_21CS10014_21CS30032.y"
      { printf("assignment-expression-opt -> epsilon\n"); }
#line 2765 "y.tab.c"
    break;

  case 145:
#line 318 "ass4_21CS10014_21CS30032.y"
                          { printf("type-qualifier-list-opt -> type-qualifier-list\n"); }
#line 2771 "y.tab.c"
    break;

  case 146:
#line 319 "ass4_21CS10014_21CS30032.y"
      { printf("type-qualifier-list-opt -> epsilon\n"); }
#line 2777 "y.tab.c"
    break;

  case 147:
#line 323 "ass4_21CS10014_21CS30032.y"
                                       { printf("pointer -> * type-qualifier-list-opt\n"); }
#line 2783 "y.tab.c"
    break;

  case 148:
#line 324 "ass4_21CS10014_21CS30032.y"
                                               { printf("pointer -> * type-qualifier-list-opt pointer\n"); }
#line 2789 "y.tab.c"
    break;

  case 149:
#line 328 "ass4_21CS10014_21CS30032.y"
                     { printf("type-qualifier-list -> type-qualifier\n"); }
#line 2795 "y.tab.c"
    break;

  case 150:
#line 329 "ass4_21CS10014_21CS30032.y"
                                         { printf("type-qualifier-list -> type-qualifier-list type-qualifier\n"); }
#line 2801 "y.tab.c"
    break;

  case 151:
#line 333 "ass4_21CS10014_21CS30032.y"
                     { printf("parameter-type-list -> parameter-list\n"); }
#line 2807 "y.tab.c"
    break;

  case 152:
#line 334 "ass4_21CS10014_21CS30032.y"
                                    { printf("parameter-type-list -> parameter-list , ...\n"); }
#line 2813 "y.tab.c"
    break;

  case 153:
#line 338 "ass4_21CS10014_21CS30032.y"
                            { printf("parameter-list -> parameter-declaration\n"); }
#line 2819 "y.tab.c"
    break;

  case 154:
#line 339 "ass4_21CS10014_21CS30032.y"
                                                 { printf("parameter-list -> parameter-list , parameter-declaration\n"); }
#line 2825 "y.tab.c"
    break;

  case 155:
#line 343 "ass4_21CS10014_21CS30032.y"
                                        { printf("parameter-declaration -> declaration-specifiers declarator\n"); }
#line 2831 "y.tab.c"
    break;

  case 156:
#line 344 "ass4_21CS10014_21CS30032.y"
                             { printf("parameter-declaration -> declaration-specifiers\n"); }
#line 2837 "y.tab.c"
    break;

  case 157:
#line 348 "ass4_21CS10014_21CS30032.y"
                 { printf("identifier-list -> identifier\n"); }
#line 2843 "y.tab.c"
    break;

  case 158:
#line 349 "ass4_21CS10014_21CS30032.y"
                                       { printf("identifier-list -> identifier-list , identifier\n"); }
#line 2849 "y.tab.c"
    break;

  case 159:
#line 353 "ass4_21CS10014_21CS30032.y"
                               { printf("type-name -> specifier-qualifier-list\n"); }
#line 2855 "y.tab.c"
    break;

  case 160:
#line 357 "ass4_21CS10014_21CS30032.y"
                            { printf("initializer -> assignment-expression\n"); }
#line 2861 "y.tab.c"
    break;

  case 161:
#line 358 "ass4_21CS10014_21CS30032.y"
                                                              { printf("initializer -> { initializer-list }\n"); }
#line 2867 "y.tab.c"
    break;

  case 162:
#line 359 "ass4_21CS10014_21CS30032.y"
                                                                    { printf("initializer -> { initializer-list , }\n"); }
#line 2873 "y.tab.c"
    break;

  case 163:
#line 363 "ass4_21CS10014_21CS30032.y"
                                  { printf("initializer-list -> designation-opt initializer\n"); }
#line 2879 "y.tab.c"
    break;

  case 164:
#line 364 "ass4_21CS10014_21CS30032.y"
                                                         { printf("initializer-list -> initializer-list , designation-opt initializer\n"); }
#line 2885 "y.tab.c"
    break;

  case 165:
#line 368 "ass4_21CS10014_21CS30032.y"
                  { printf("designation-opt -> designation\n"); }
#line 2891 "y.tab.c"
    break;

  case 166:
#line 369 "ass4_21CS10014_21CS30032.y"
      { printf("designation-opt -> epsilon\n"); }
#line 2897 "y.tab.c"
    break;

  case 167:
#line 373 "ass4_21CS10014_21CS30032.y"
                             { printf("designation -> designator-list =\n"); }
#line 2903 "y.tab.c"
    break;

  case 168:
#line 377 "ass4_21CS10014_21CS30032.y"
                 { printf("designator-list -> designator\n"); }
#line 2909 "y.tab.c"
    break;

  case 169:
#line 378 "ass4_21CS10014_21CS30032.y"
                                 { printf("designator-list -> designator-list designator\n"); }
#line 2915 "y.tab.c"
    break;

  case 170:
#line 382 "ass4_21CS10014_21CS30032.y"
                                                                   { printf("designator -> [ constant-expression ]\n"); }
#line 2921 "y.tab.c"
    break;

  case 171:
#line 383 "ass4_21CS10014_21CS30032.y"
                     { printf("designator -> . identifier\n"); }
#line 2927 "y.tab.c"
    break;

  case 172:
#line 389 "ass4_21CS10014_21CS30032.y"
                        { printf("statement -> labeled-statement\n"); }
#line 2933 "y.tab.c"
    break;

  case 173:
#line 390 "ass4_21CS10014_21CS30032.y"
                         { printf("statement -> compound-statement\n"); }
#line 2939 "y.tab.c"
    break;

  case 174:
#line 391 "ass4_21CS10014_21CS30032.y"
                           { printf("statement -> expression-statement\n"); }
#line 2945 "y.tab.c"
    break;

  case 175:
#line 392 "ass4_21CS10014_21CS30032.y"
                          { printf("statement -> selection-statement\n"); }
#line 2951 "y.tab.c"
    break;

  case 176:
#line 393 "ass4_21CS10014_21CS30032.y"
                          { printf("statement -> iteration-statement\n"); }
#line 2957 "y.tab.c"
    break;

  case 177:
#line 394 "ass4_21CS10014_21CS30032.y"
                     { printf("statement -> jump-statement\n"); }
#line 2963 "y.tab.c"
    break;

  case 178:
#line 398 "ass4_21CS10014_21CS30032.y"
                                 { printf("labeled-statement -> identifier : statement\n"); }
#line 2969 "y.tab.c"
    break;

  case 179:
#line 399 "ass4_21CS10014_21CS30032.y"
                                               { printf("labeled-statement -> case constant-expression : statement\n"); }
#line 2975 "y.tab.c"
    break;

  case 180:
#line 400 "ass4_21CS10014_21CS30032.y"
                              { printf("labeled-statement -> default : statement\n"); }
#line 2981 "y.tab.c"
    break;

  case 181:
#line 404 "ass4_21CS10014_21CS30032.y"
                                                                 { printf("compound-statement -> { block-item-list-opt }\n"); }
#line 2987 "y.tab.c"
    break;

  case 182:
#line 408 "ass4_21CS10014_21CS30032.y"
                      { printf("block-item-list-opt -> block-item-list\n"); }
#line 2993 "y.tab.c"
    break;

  case 183:
#line 409 "ass4_21CS10014_21CS30032.y"
      { printf("block-item-list-opt -> epsilon\n"); }
#line 2999 "y.tab.c"
    break;

  case 184:
#line 413 "ass4_21CS10014_21CS30032.y"
                 { printf("block-item-list -> block-item\n"); }
#line 3005 "y.tab.c"
    break;

  case 185:
#line 414 "ass4_21CS10014_21CS30032.y"
                                 { printf("block-item-list -> block-item-list block-item\n"); }
#line 3011 "y.tab.c"
    break;

  case 186:
#line 418 "ass4_21CS10014_21CS30032.y"
                  { printf("block-item -> declaration\n"); }
#line 3017 "y.tab.c"
    break;

  case 187:
#line 419 "ass4_21CS10014_21CS30032.y"
                { printf("block-item -> statement\n"); }
#line 3023 "y.tab.c"
    break;

  case 188:
#line 423 "ass4_21CS10014_21CS30032.y"
                               { printf("expression-statement -> expression-opt ;\n"); }
#line 3029 "y.tab.c"
    break;

  case 189:
#line 427 "ass4_21CS10014_21CS30032.y"
                 { printf("expression-opt -> expression\n"); }
#line 3035 "y.tab.c"
    break;

  case 190:
#line 428 "ass4_21CS10014_21CS30032.y"
      { printf("expression-opt -> epsilon\n"); }
#line 3041 "y.tab.c"
    break;

  case 191:
#line 432 "ass4_21CS10014_21CS30032.y"
                                                                     { printf("selection-statement -> if ( expression ) statement\n"); }
#line 3047 "y.tab.c"
    break;

  case 192:
#line 433 "ass4_21CS10014_21CS30032.y"
                                                                                    { printf("selection-statement -> if ( expression ) statement else statement\n"); }
#line 3053 "y.tab.c"
    break;

  case 193:
#line 434 "ass4_21CS10014_21CS30032.y"
                                                                         { printf("selection-statement -> switch ( expression ) statement\n"); }
#line 3059 "y.tab.c"
    break;

  case 194:
#line 438 "ass4_21CS10014_21CS30032.y"
                                                                        { printf("iteration-statement -> while ( expression ) statement\n"); }
#line 3065 "y.tab.c"
    break;

  case 195:
#line 439 "ass4_21CS10014_21CS30032.y"
                                                                                     { printf("iteration-statement -> do statement while ( expression ) ;\n"); }
#line 3071 "y.tab.c"
    break;

  case 196:
#line 440 "ass4_21CS10014_21CS30032.y"
                                                                                                                            { printf("iteration-statement -> for ( expression-opt ; expression-opt ; expression-opt ) statement\n"); }
#line 3077 "y.tab.c"
    break;

  case 197:
#line 441 "ass4_21CS10014_21CS30032.y"
                                                                                                               { printf("iteration-statement -> for ( declaration expression-opt ; expression-opt ) statement\n"); }
#line 3083 "y.tab.c"
    break;

  case 198:
#line 445 "ass4_21CS10014_21CS30032.y"
                                { printf("jump-statement -> goto identifier ;\n"); }
#line 3089 "y.tab.c"
    break;

  case 199:
#line 446 "ass4_21CS10014_21CS30032.y"
                         { printf("jump-statement -> continue ;\n"); }
#line 3095 "y.tab.c"
    break;

  case 200:
#line 447 "ass4_21CS10014_21CS30032.y"
                      { printf("jump-statement -> break ;\n"); }
#line 3101 "y.tab.c"
    break;

  case 201:
#line 448 "ass4_21CS10014_21CS30032.y"
                                      { printf("jump-statement -> return expression-opt ;\n"); }
#line 3107 "y.tab.c"
    break;

  case 202:
#line 454 "ass4_21CS10014_21CS30032.y"
                           { printf("translation-unit -> external-declaration\n"); }
#line 3113 "y.tab.c"
    break;

  case 203:
#line 455 "ass4_21CS10014_21CS30032.y"
                                            { printf("translation-unit -> translation-unit external-declaration\n"); }
#line 3119 "y.tab.c"
    break;

  case 204:
#line 459 "ass4_21CS10014_21CS30032.y"
                          { printf("external-declaration -> function-definition\n"); }
#line 3125 "y.tab.c"
    break;

  case 205:
#line 460 "ass4_21CS10014_21CS30032.y"
                  { printf("external-declaration -> declaration\n"); }
#line 3131 "y.tab.c"
    break;

  case 206:
#line 464 "ass4_21CS10014_21CS30032.y"
                                                                                { printf("function-definition --> declaration-specifiers declarator declaration-list-opt compound-statement\n"); }
#line 3137 "y.tab.c"
    break;

  case 207:
#line 468 "ass4_21CS10014_21CS30032.y"
                       { printf("declaration-list-opt -> declaration-list\n"); }
#line 3143 "y.tab.c"
    break;

  case 208:
#line 469 "ass4_21CS10014_21CS30032.y"
      { printf("declaration-list-opt -> epsilon\n"); }
#line 3149 "y.tab.c"
    break;

  case 209:
#line 473 "ass4_21CS10014_21CS30032.y"
                  { printf("declaration-list -> declaration\n"); }
#line 3155 "y.tab.c"
    break;

  case 210:
#line 474 "ass4_21CS10014_21CS30032.y"
                                   { printf("declaration-list -> declaration-list declaration\n"); }
#line 3161 "y.tab.c"
    break;


#line 3165 "y.tab.c"

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
#line 477 "ass4_21CS10014_21CS30032.y"


void yyerror(char* s) {
    printf("Error: %s\n", s);
    printf("Line: %d\n", yylineno);
    printf("Text: %s\n", yytext);
}
