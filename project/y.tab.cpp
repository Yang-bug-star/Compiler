/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include"tree.h"
#include<stdlib.h>
#include<stdio.h>
#include<string>

extern char* yytext;
extern FILE* yyin;
extern FILE* yyout;
extern int yyrow,yycol;

TreeNode *root;

int yylex(void);
void yyerror(const char*s);

int flag = 0;

#line 85 "y.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.hpp".  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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
    CHAR = 258,
    INT = 259,
    DOUBLE = 260,
    VOID = 261,
    SIZEOF = 262,
    IF = 263,
    ELSE = 264,
    SWITCH = 265,
    CASE = 266,
    DEFAULT = 267,
    WHILE = 268,
    DO = 269,
    FOR = 270,
    GOTO = 271,
    CONTINUE = 272,
    BREAK = 273,
    RETURN = 274,
    IDENTIFIER = 275,
    INT_CONSTANT = 276,
    LEFT_SHIFT_OP = 277,
    RIGHT_SHIFT_OP = 278,
    LE_OP = 279,
    GE_OP = 280,
    EQ_OP = 281,
    NE_OP = 282,
    PTR_OP = 283,
    INC_OP = 284,
    DEC_OP = 285,
    ADD_ASSIGN = 286,
    SUB_ASSIGN = 287,
    MUL_ASSIGN = 288,
    DIV_ASSIGN = 289,
    MOD_ASSIGN = 290,
    LEFT_SHIFT_ASSIGN = 291,
    RIGHT_SHIFT_ASSIGN = 292,
    AND_ASSIGN = 293,
    XOR_ASSIGN = 294,
    OR_ASSIGN = 295,
    AND_OP = 296,
    OR_OP = 297,
    LOWER_PREC_THAN_ELSE = 298
  };
#endif
/* Tokens.  */
#define CHAR 258
#define INT 259
#define DOUBLE 260
#define VOID 261
#define SIZEOF 262
#define IF 263
#define ELSE 264
#define SWITCH 265
#define CASE 266
#define DEFAULT 267
#define WHILE 268
#define DO 269
#define FOR 270
#define GOTO 271
#define CONTINUE 272
#define BREAK 273
#define RETURN 274
#define IDENTIFIER 275
#define INT_CONSTANT 276
#define LEFT_SHIFT_OP 277
#define RIGHT_SHIFT_OP 278
#define LE_OP 279
#define GE_OP 280
#define EQ_OP 281
#define NE_OP 282
#define PTR_OP 283
#define INC_OP 284
#define DEC_OP 285
#define ADD_ASSIGN 286
#define SUB_ASSIGN 287
#define MUL_ASSIGN 288
#define DIV_ASSIGN 289
#define MOD_ASSIGN 290
#define LEFT_SHIFT_ASSIGN 291
#define RIGHT_SHIFT_ASSIGN 292
#define AND_ASSIGN 293
#define XOR_ASSIGN 294
#define OR_ASSIGN 295
#define AND_OP 296
#define OR_OP 297
#define LOWER_PREC_THAN_ELSE 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "parser.y" /* yacc.c:355  */

  TreeNode* node;

#line 215 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 232 "y.tab.cpp" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   418

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  223

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,     2,     2,    42,    33,     2,
      30,    31,    40,    38,    23,    39,    32,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    24,    22,
      43,    25,    44,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    26,     2,    27,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,    34,    29,    37,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    65,    68,    74,    77,    83,    86,    92,
      98,   101,   104,   107,   110,   116,   119,   122,   125,   128,
     131,   137,   140,   146,   149,   155,   158,   164,   167,   173,
     176,   179,   182,   185,   188,   194,   197,   203,   206,   212,
     215,   221,   224,   227,   233,   236,   242,   245,   248,   254,
     257,   260,   263,   269,   272,   275,   278,   281,   287,   290,
     296,   299,   305,   308,   314,   317,   320,   323,   326,   329,
     332,   335,   338,   341,   344,   350,   353,   359,   362,   368,
     371,   377,   380,   386,   389,   392,   398,   401,   404,   407,
     410,   416,   419,   422,   428,   431,   434,   440,   443,   446,
     449,   455,   458,   461,   464,   470,   473,   476,   479,   482,
     488,   491,   494,   497,   500,   503,   509,   512,   518,   521,
     524,   530,   533,   539,   542,   548,   551,   557,   560,   563,
     568,   571
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "INT", "DOUBLE", "VOID",
  "SIZEOF", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "IDENTIFIER",
  "INT_CONSTANT", "';'", "','", "':'", "'='", "'['", "']'", "'{'", "'}'",
  "'('", "')'", "'.'", "'&'", "'|'", "'^'", "'!'", "'~'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'<'", "'>'", "'?'", "LEFT_SHIFT_OP",
  "RIGHT_SHIFT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "PTR_OP", "INC_OP",
  "DEC_OP", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "LEFT_SHIFT_ASSIGN", "RIGHT_SHIFT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "AND_OP", "OR_OP", "LOWER_PREC_THAN_ELSE",
  "$accept", "program", "translation_unit", "external_declaration",
  "function_definition", "declaration_specifiers", "type_specifier",
  "declarator", "declaration_list", "parameter_list",
  "parameter_declaration", "identifier_list", "statement",
  "compound_statement", "block_item_list", "block_item",
  "labeled_statement", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "expression",
  "assignment_expression", "logical_or_expression", "assignment_operator",
  "logical_and_expression", "inclusive_or_expression",
  "exclusive_or_expression", "and_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "unary_expression", "unary_operator",
  "postfix_expression", "argument_expression_list", "primary_expression",
  "declaration", "init_declarator_list", "init_declarator", "initializer",
  "initializer_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    59,    44,    58,    61,    91,    93,   123,   125,
      40,    41,    46,    38,   124,    94,    33,   126,    43,    45,
      42,    47,    37,    60,    62,    63,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298
};
# endif

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -126

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     240,   -10,  -136,  -136,  -136,  -136,    22,   156,  -136,  -136,
     132,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   388,    38,
    -136,   274,    77,    13,    89,   132,   145,  -136,  -136,    81,
    -136,  -136,   274,   347,  -136,  -136,  -136,  -136,  -136,   347,
     347,  -136,    46,    53,    94,    99,   107,    -6,   120,    78,
     127,    44,    14,   347,   -17,  -136,  -136,  -136,   140,   142,
     172,   347,   183,   179,   247,   197,   213,   212,   220,   295,
     211,  -136,  -136,  -136,  -136,   200,  -136,  -136,  -136,  -136,
    -136,  -136,   148,  -136,  -136,  -136,  -136,    81,    17,  -136,
      23,    33,  -136,  -136,  -136,  -136,    73,    24,  -136,  -136,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   347,
    -136,   347,   316,  -136,  -136,  -136,   347,   347,    -4,  -136,
     247,   347,   234,   321,   226,  -136,  -136,  -136,   152,   247,
    -136,  -136,  -136,   347,   111,   240,  -136,   229,  -136,   252,
    -136,  -136,    53,    94,    99,   107,    -6,   120,   120,    78,
      78,    78,    78,   127,   127,    44,    44,  -136,  -136,  -136,
    -136,    76,  -136,  -136,    34,    37,    58,   247,  -136,    60,
     221,   321,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,   347,  -136,   247,   247,  -136,   247,   347,   342,  -136,
     241,  -136,  -136,    96,   247,    98,   247,   230,  -136,   247,
    -136,  -136,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    11,    12,    13,    10,     0,     0,     3,     6,
       0,     9,     5,    14,     1,     4,    15,   121,     0,   122,
     123,     0,     0,     0,     0,     0,     0,     8,    21,     0,
     118,   119,     0,     0,   108,   107,   105,   106,   109,     0,
       0,   127,    60,    62,    75,    77,    79,    81,    83,    86,
      91,    94,    97,     0,   101,   110,   126,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,    44,    35,    40,    29,     0,    37,    34,    30,    31,
      32,    33,     0,    58,    39,    27,    20,    26,     0,    23,
       0,   125,     7,    22,   124,   130,     0,     0,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
     104,     0,     0,   114,   115,    16,     0,     0,     0,    97,
       0,     0,     0,     0,     0,    54,    55,    56,     0,     0,
      36,    38,    45,     0,    25,     0,    18,     0,    19,     0,
     128,   120,    63,    76,    78,    80,    82,    84,    85,    87,
      88,    89,    90,    92,    93,    95,    96,    98,    99,   100,
      61,     0,   112,   116,     0,     0,     0,     0,    43,     0,
       0,     0,    53,    57,    41,    59,    24,    28,   129,   131,
     111,     0,   113,     0,     0,    42,     0,     0,     0,   117,
      47,    48,    49,     0,     0,     0,     0,     0,    51,     0,
      46,    50,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,   249,  -136,    80,   -20,    -5,  -136,  -136,
     115,  -136,   -61,   121,  -136,   196,  -136,  -135,  -136,  -136,
    -136,   -31,   -21,   215,  -136,   174,   177,   191,   176,   192,
     126,   116,    67,    68,    83,  -136,  -136,  -136,  -136,   -11,
    -136,   268,   -26,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    25,    11,    91,    26,    88,
      89,    90,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    42,   129,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,   184,    55,    12,
      19,    20,    56,    96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    58,    97,   142,    87,    18,    95,    28,   191,   131,
      13,    41,    84,   132,     1,    93,     2,     3,     4,     5,
     187,    59,    14,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    31,    71,   133,   134,   148,   118,
     155,    23,    72,    33,   105,   106,   157,   153,   156,    34,
      35,    36,    37,    38,   158,   161,   208,   201,    21,    22,
     153,    29,   100,    24,    84,   202,    39,    40,   203,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   188,
      10,   153,   154,   153,   115,   116,   117,    10,   194,   204,
       1,   206,     2,     3,     4,     5,   159,    30,    31,   153,
     181,    16,   160,   200,    57,   185,   186,    33,   180,    85,
     189,   183,   100,    34,    35,    36,    37,    38,   101,   153,
      86,   153,    98,    99,   111,   112,   205,   217,   102,   219,
      39,    40,   195,   199,   103,    87,   130,    22,    41,    27,
     104,    24,   210,   211,   139,   212,     1,    92,     2,     3,
       4,     5,    16,   218,    17,   220,    -2,     1,   222,     2,
       3,     4,     5,   107,   108,   113,   114,   135,   109,   110,
     152,   153,   136,    23,   193,   153,   213,   215,   173,   174,
     209,   175,   176,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   177,   178,
     179,     1,   137,     2,     3,     4,     5,   140,    59,   141,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    31,    71,   169,   170,   171,   172,   143,    23,   150,
      33,   167,   168,   144,   145,   149,    34,    35,    36,    37,
      38,     1,   146,     2,     3,     4,     5,   190,   192,   197,
     216,   207,   221,    39,    40,    59,    15,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    31,    71,
     196,   151,    30,    31,   162,    23,   138,    33,   163,   165,
      32,   198,    33,    34,    35,    36,    37,    38,    34,    35,
      36,    37,    38,   164,    30,    31,   166,    94,     0,     0,
      39,    40,    32,     0,    33,    39,    40,     0,     0,     0,
      34,    35,    36,    37,    38,    30,    31,   147,     0,     0,
       0,     0,     0,     0,     0,    33,     0,    39,    40,     0,
       0,    34,    35,    36,    37,    38,    30,    31,     0,     0,
       0,    30,    31,    71,     0,     0,    33,   182,    39,    40,
       0,    33,    34,    35,    36,    37,    38,    34,    35,    36,
      37,    38,    30,    31,     0,     0,     0,    30,    31,    39,
      40,     0,    33,   214,    39,    40,     0,    33,    34,    35,
      36,    37,    38,    34,    35,    36,    37,    38,  -125,     1,
       0,     2,     3,     4,     5,    39,    40,     0,     0,     0,
      39,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -125,     0,    21,    22,     0,    23,     0,    24
};

static const yytype_int16 yycheck[] =
{
      21,    22,    33,    64,    24,    10,    32,    18,   143,    26,
      20,    32,    23,    30,     1,    26,     3,     4,     5,     6,
      24,     8,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    53,    54,    69,    25,
      23,    28,    29,    30,    50,    51,    23,    23,    31,    36,
      37,    38,    39,    40,    31,    31,   191,    23,    25,    26,
      23,    23,    66,    30,    75,    31,    53,    54,    31,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   140,
       0,    23,    87,    23,    40,    41,    42,     7,   149,    31,
       1,    31,     3,     4,     5,     6,    23,    20,    21,    23,
     131,    20,    29,    27,    27,   136,   137,    30,   129,    20,
     141,   132,    66,    36,    37,    38,    39,    40,    65,    23,
      31,    23,    39,    40,    46,    47,   187,    31,    34,    31,
      53,    54,   153,   159,    35,   155,    53,    26,   159,    18,
      33,    30,   203,   204,    61,   206,     1,    26,     3,     4,
       5,     6,    20,   214,    22,   216,     0,     1,   219,     3,
       4,     5,     6,    43,    44,    38,    39,    27,    48,    49,
      22,    23,    30,    28,    22,    23,   207,   208,   111,   112,
     201,   113,   114,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     1,    30,     3,     4,     5,     6,    24,     8,    30,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   107,   108,   109,   110,    30,    28,    29,
      30,   105,   106,    20,    22,    24,    36,    37,    38,    39,
      40,     1,    22,     3,     4,     5,     6,    13,    22,    20,
       9,    30,    22,    53,    54,     8,     7,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     155,    75,    20,    21,   100,    28,    61,    30,   101,   103,
      28,    29,    30,    36,    37,    38,    39,    40,    36,    37,
      38,    39,    40,   102,    20,    21,   104,    29,    -1,    -1,
      53,    54,    28,    -1,    30,    53,    54,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    53,    54,    -1,
      -1,    36,    37,    38,    39,    40,    20,    21,    -1,    -1,
      -1,    20,    21,    22,    -1,    -1,    30,    31,    53,    54,
      -1,    30,    36,    37,    38,    39,    40,    36,    37,    38,
      39,    40,    20,    21,    -1,    -1,    -1,    20,    21,    53,
      54,    -1,    30,    31,    53,    54,    -1,    30,    36,    37,
      38,    39,    40,    36,    37,    38,    39,    40,     0,     1,
      -1,     3,     4,     5,     6,    53,    54,    -1,    -1,    -1,
      53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    -1,    25,    26,    -1,    28,    -1,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,    69,    70,    71,    72,
      73,    74,   107,    20,     0,    71,    20,    22,    75,   108,
     109,    25,    26,    28,    30,    73,    76,    81,   107,    23,
      20,    21,    28,    30,    36,    37,    38,    39,    40,    53,
      54,    90,    91,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   106,   110,    27,    90,     8,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    29,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,   107,    20,    31,    74,    77,    78,
      79,    75,    81,   107,   109,   110,   111,    89,   102,   102,
      66,    65,    34,    35,    33,    50,    51,    43,    44,    48,
      49,    46,    47,    38,    39,    40,    41,    42,    25,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    92,
     102,    26,    30,    53,    54,    27,    30,    30,    91,   102,
      24,    30,    80,    30,    20,    22,    22,    22,    89,    24,
      29,    83,    22,    23,    75,    23,    31,    23,    31,    23,
      29,    31,    93,    94,    95,    96,    97,    98,    98,    99,
      99,    99,    99,   100,   100,   101,   101,   102,   102,   102,
      90,    89,    31,    90,   105,    89,    89,    24,    80,    89,
      13,    85,    22,    22,    80,    90,    78,    20,    29,   110,
      27,    23,    31,    31,    31,    80,    31,    30,    85,    90,
      80,    80,    80,    89,    31,    89,     9,    31,    80,    31,
      80,    22,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    70,    70,    71,    71,    72,    72,    73,
      74,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    85,    85,    86,    86,    86,    87,
      87,    87,    87,    88,    88,    88,    88,    88,    89,    89,
      90,    90,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    93,    93,    94,    94,    95,
      95,    96,    96,    97,    97,    97,    98,    98,    98,    98,
      98,    99,    99,    99,   100,   100,   100,   101,   101,   101,
     101,   102,   102,   102,   102,   103,   103,   103,   103,   103,
     104,   104,   104,   104,   104,   104,   105,   105,   106,   106,
     106,   107,   107,   108,   108,   109,   109,   110,   110,   110,
     111,   111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     4,     3,     1,
       1,     1,     1,     1,     2,     1,     4,     3,     4,     4,
       3,     1,     2,     1,     3,     2,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     2,     1,
       1,     3,     4,     3,     1,     2,     7,     5,     5,     5,
       7,     6,     7,     3,     2,     2,     2,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     4,     3,     4,     2,     2,     1,     3,     1,     1,
       3,     2,     2,     1,     3,     1,     3,     1,     3,     4,
       1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
| yyreduce -- Do a reduction.  |
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
#line 59 "parser.y" /* yacc.c:1646  */
    {
        root = new TreeNode("program",1,(yyvsp[0].node));
    }
#line 1527 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 65 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node)=new TreeNode("translation_unit",1,(yyvsp[0].node));
    }
#line 1535 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 68 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node)=new TreeNode("translation_unit",2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1543 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 74 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node)=new TreeNode("external_declaration",1,(yyvsp[0].node));
    }
#line 1551 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 77 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node)=new TreeNode("external_declaration",1,(yyvsp[0].node));
    }
#line 1559 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 83 "parser.y" /* yacc.c:1646  */
    {//声明符
        (yyval.node)=new TreeNode("function_definition",4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1567 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 86 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node)=new TreeNode("function_definition",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1575 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 92 "parser.y" /* yacc.c:1646  */
    {//省略存储类型声明符等，这里只保留类型声明
        (yyval.node)=new TreeNode("declaration_specifiers",1,(yyvsp[0].node));
    }
#line 1583 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 98 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node)=new TreeNode("type_specifier",1,(yyvsp[0].node));
    }
#line 1591 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 101 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node)=new TreeNode("type_specifier",1,(yyvsp[0].node));
    }
#line 1599 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 104 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node)=new TreeNode("type_specifier",1,(yyvsp[0].node));
    }
#line 1607 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 107 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node)=new TreeNode("type_specifier",1,(yyvsp[0].node));
    }
#line 1615 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 110 "parser.y" /* yacc.c:1646  */
    {
      flag = 1;
    }
#line 1623 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 116 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("declarator",1,(yyvsp[0].node));
    }
#line 1631 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 119 "parser.y" /* yacc.c:1646  */
    {//数组
      (yyval.node)=new TreeNode("declarator",4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1639 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 122 "parser.y" /* yacc.c:1646  */
    {//数组
      (yyval.node)=new TreeNode("declarator",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1647 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 125 "parser.y" /* yacc.c:1646  */
    {//带参函数
      (yyval.node)=new TreeNode("declarator",4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1655 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 128 "parser.y" /* yacc.c:1646  */
    {//函数调用
      (yyval.node)=new TreeNode("declarator",4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));      
    }
#line 1663 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 131 "parser.y" /* yacc.c:1646  */
    {//无参函数
      (yyval.node)=new TreeNode("declarator",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1671 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 137 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("declaration_list",1,(yyvsp[0].node));      
    }
#line 1679 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 140 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("declaration_list",2,(yyvsp[-1].node),(yyvsp[0].node));            
    }
#line 1687 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 146 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("parameter_list",1,(yyvsp[0].node));      
    }
#line 1695 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 149 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("parameter_list",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1703 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 155 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("parameter_declaration",2,(yyvsp[-1].node),(yyvsp[0].node));            
    }
#line 1711 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 158 "parser.y" /* yacc.c:1646  */
    {//只有类型符的参数
      (yyval.node)=new TreeNode("parameter_declaration",1,(yyvsp[0].node));          
    }
#line 1719 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 164 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("identifier_list",1,(yyvsp[0].node));      
    }
#line 1727 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 167 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("identifier_list",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1735 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 173 "parser.y" /* yacc.c:1646  */
    {//复合语句
      (yyval.node)=new TreeNode("statement",1,(yyvsp[0].node));          
    }
#line 1743 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 176 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("statement",1,(yyvsp[0].node));          
    }
#line 1751 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 179 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("statement",1,(yyvsp[0].node));          
    }
#line 1759 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 182 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("statement",1,(yyvsp[0].node));          
    }
#line 1767 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 185 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("statement",1,(yyvsp[0].node));          
    }
#line 1775 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 188 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("statement",1,(yyvsp[0].node));          
    }
#line 1783 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 194 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("compound_statement",2,(yyvsp[-1].node),(yyvsp[0].node));            
    }
#line 1791 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 197 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("compound_statement",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1799 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 203 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("block_item_list",1,(yyvsp[0].node));          
    }
#line 1807 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 206 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("block_item_list",2,(yyvsp[-1].node),(yyvsp[0].node));            
    }
#line 1815 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 212 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("block_item",1,(yyvsp[0].node));          
    }
#line 1823 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 215 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("block_item",1,(yyvsp[0].node));          
    }
#line 1831 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 221 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("labeled_statement",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1839 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 224 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("labeled_statement",4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1847 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 227 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("labeled_statement",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1855 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 233 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("expression_statement",1,(yyvsp[0].node));          
    }
#line 1863 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 236 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("expression_statement",2,(yyvsp[-1].node),(yyvsp[0].node));            
    }
#line 1871 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 242 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("selection_statement",7,(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1879 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 245 "parser.y" /* yacc.c:1646  */
    {//这条语句的优先级更低
      (yyval.node)=new TreeNode("selection_statement",5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1887 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 248 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("selection_statement",5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1895 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 254 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("iteration_statement",5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));            
    }
#line 1903 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 257 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("iteration_statement",7,(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1911 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 260 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("iteration_statement",6,(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1919 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 263 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("iteration_statement",7,(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1927 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 269 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("jump_statement",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1935 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 272 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("jump_statement",2,(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1943 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 275 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("jump_statement",2,(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1951 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 278 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("jump_statement",2,(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1959 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 281 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("jump_statement",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1967 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 287 "parser.y" /* yacc.c:1646  */
    {//赋值   
      (yyval.node)=new TreeNode("expression",1,(yyvsp[0].node));                
    }
#line 1975 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 290 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1983 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 296 "parser.y" /* yacc.c:1646  */
    {//逻辑或表达式
      (yyval.node)=new TreeNode("assignment_expression",1,(yyvsp[0].node));                
    }
#line 1991 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 299 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("assignment_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 1999 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 305 "parser.y" /* yacc.c:1646  */
    {//逻辑与表达式
      (yyval.node)=new TreeNode("logical_or_expression",1,(yyvsp[0].node));                
    }
#line 2007 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 308 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("logical_or_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 2015 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 314 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("assignment_operator",1,(yyvsp[0].node));                
    }
#line 2023 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 317 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("assignment_operator",1,(yyvsp[0].node));                      
    }
#line 2031 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 320 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("assignment_operator",1,(yyvsp[0].node));                      
    }
#line 2039 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 323 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("assignment_operator",1,(yyvsp[0].node));                      
    }
#line 2047 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 326 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("assignment_operator",1,(yyvsp[0].node));                      
    }
#line 2055 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 329 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("assignment_operator",1,(yyvsp[0].node));                      
    }
#line 2063 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 332 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("assignment_operator",1,(yyvsp[0].node));                      
    }
#line 2071 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 335 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("assignment_operator",1,(yyvsp[0].node));                      
    }
#line 2079 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 338 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("assignment_operator",1,(yyvsp[0].node));                      
    }
#line 2087 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 341 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("assignment_operator",1,(yyvsp[0].node));                      
    }
#line 2095 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 344 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("assignment_operator",1,(yyvsp[0].node));                      
    }
#line 2103 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 350 "parser.y" /* yacc.c:1646  */
    {//按位或表达式 |
      (yyval.node)=new TreeNode("logical_and_expression",1,(yyvsp[0].node));                      
    }
#line 2111 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 353 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("logical_and_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));          
    }
#line 2119 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 359 "parser.y" /* yacc.c:1646  */
    {//按位异或表达式 ^
      (yyval.node)=new TreeNode("inclusive_or_expression",1,(yyvsp[0].node));                            
    }
#line 2127 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 362 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("inclusive_or_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                
    }
#line 2135 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 368 "parser.y" /* yacc.c:1646  */
    {//按位与表达式 &
      (yyval.node)=new TreeNode("exclusive_or_expression",1,(yyvsp[0].node));                            
    }
#line 2143 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 371 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("exclusive_or_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                      
    }
#line 2151 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 377 "parser.y" /* yacc.c:1646  */
    {//相等关系表达式
      (yyval.node)=new TreeNode("and_expression",1,(yyvsp[0].node));                            
    }
#line 2159 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 380 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("and_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                            
    }
#line 2167 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 386 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("equality_expression",1,(yyvsp[0].node));                            
    }
#line 2175 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 389 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("equality_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                  
    }
#line 2183 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 392 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("equality_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                        
    }
#line 2191 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 398 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("relational_expression",1,(yyvsp[0].node));                                    
      }
#line 2199 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 401 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("relational_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                              
    }
#line 2207 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 404 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("relational_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                    
    }
#line 2215 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 407 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("relational_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                    
    }
#line 2223 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 410 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("relational_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                    
    }
#line 2231 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 416 "parser.y" /* yacc.c:1646  */
    {//可加表达式
      (yyval.node)=new TreeNode("shift_expression",1,(yyvsp[0].node));                                    
    }
#line 2239 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 419 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("shift_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                          
    }
#line 2247 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 422 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("shift_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                          
    }
#line 2255 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 428 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("additive_expression",1,(yyvsp[0].node));                                            
      }
#line 2263 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 431 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("additive_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                          
    }
#line 2271 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 434 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("additive_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                                
    }
#line 2279 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 440 "parser.y" /* yacc.c:1646  */
    {//一元运算表达式
      (yyval.node)=new TreeNode("multiplicative_expression",1,(yyvsp[0].node));                                            
    }
#line 2287 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 443 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("multiplicative_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                                
    }
#line 2295 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 446 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("multiplicative_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                                
    }
#line 2303 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 449 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("multiplicative_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                                
    }
#line 2311 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 455 "parser.y" /* yacc.c:1646  */
    {//后缀表达式
      (yyval.node)=new TreeNode("unary_expression",1,(yyvsp[0].node));                                            
    }
#line 2319 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 458 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("unary_expression",2,(yyvsp[-1].node),(yyvsp[0].node));         
    }
#line 2327 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 461 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("unary_expression",2,(yyvsp[-1].node),(yyvsp[0].node));    
    }
#line 2335 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 464 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("unary_expression",2,(yyvsp[-1].node),(yyvsp[0].node));         
    }
#line 2343 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 470 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("unary_operator",1,(yyvsp[0].node));                                                    
      }
#line 2351 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 473 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("unary_operator",1,(yyvsp[0].node));                                                  
    }
#line 2359 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 476 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("unary_operator",1,(yyvsp[0].node));                                                  
    }
#line 2367 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 479 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("unary_operator",1,(yyvsp[0].node));                                                  
    }
#line 2375 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 482 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("unary_operator",1,(yyvsp[0].node));
    }
#line 2383 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 488 "parser.y" /* yacc.c:1646  */
    {//基本表达式
      (yyval.node)=new TreeNode("postfix_expression",1,(yyvsp[0].node));                                                    
    }
#line 2391 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 491 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("postfix_expression",4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                                
    }
#line 2399 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 494 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("postfix_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                                    
    }
#line 2407 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 497 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("postfix_expression",4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                                
    }
#line 2415 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 500 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("postfix_expression",2,(yyvsp[-1].node),(yyvsp[0].node));                                                                     
    }
#line 2423 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 503 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("postfix_expression",2,(yyvsp[-1].node),(yyvsp[0].node));                                                                  
    }
#line 2431 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 509 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("argument_expression_list",1,(yyvsp[0].node));                                                    
      }
#line 2439 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 512 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("argument_expression_list",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                                          
    }
#line 2447 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 518 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("primary_expression",1,(yyvsp[0].node));                                                           
      }
#line 2455 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 521 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("primary_expression",1,(yyvsp[0].node));                                                          
    }
#line 2463 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 524 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("primary_expression",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                                                
    }
#line 2471 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 530 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("declaration",1,(yyvsp[-1].node));                                                          
      }
#line 2479 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 533 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("declaration",2,(yyvsp[-1].node),(yyvsp[0].node));                                                                       
    }
#line 2487 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 539 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("init_declarator_list",1,(yyvsp[0].node));                                                                  
      }
#line 2495 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 542 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("init_declarator_list",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                                                      
    }
#line 2503 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 548 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("init_declarator",1,(yyvsp[0].node));                                                                  
      }
#line 2511 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 551 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("init_declarator",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                                                           
    }
#line 2519 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 557 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("initializer",1,(yyvsp[0].node));
      }
#line 2527 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 560 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("initializer",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                                                                 
    }
#line 2535 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 563 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("initializer",4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                                      
    }
#line 2543 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 568 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("initializer_list",1,(yyvsp[0].node));                                                                  
      }
#line 2551 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 571 "parser.y" /* yacc.c:1646  */
    {
      (yyval.node)=new TreeNode("initializer_list",3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));                                                                                                      
    }
#line 2559 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2563 "y.tab.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 575 "parser.y" /* yacc.c:1906  */


int main(int argc,char* argv[]){
    if (argc < 2) {
        fprintf(stderr, "Usage: <prog_name> <input_file>\n");
        exit(-1);
    }  
    yyin = fopen(argv[1],"r");
    yyparse();
    root->save_json("syntax-tree.json");
    fclose(yyin);
}

void yyerror(const char* error_msg)
{
	fflush(stdout);
  cout << "line: "  << yyrow << " col: " << yycol << "   "
       << error_msg << endl;
}
