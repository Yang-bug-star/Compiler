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
#line 1 "clang.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    extern int yylineno;
    extern FILE * yyin;
    int yylex(void);
    void yyerror(const char *msg);
    int success = 1;

#line 76 "clang.tab.c" /* yacc.c:339  */

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
   by #include "clang.tab.h".  */
#ifndef YY_YY_CLANG_TAB_H_INCLUDED
# define YY_YY_CLANG_TAB_H_INCLUDED
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
    AUTO = 258,
    BREAK = 259,
    CASE = 260,
    CHAR = 261,
    CONST = 262,
    CONTINUE = 263,
    DEFAULT = 264,
    DO = 265,
    DOUBLE = 266,
    ENUM = 267,
    EXTERN = 268,
    FLOAT = 269,
    FOR = 270,
    GOTO = 271,
    IF = 272,
    INLINE = 273,
    INT = 274,
    LONG = 275,
    REGISTER = 276,
    RESTRICT = 277,
    RETURN = 278,
    SHORT = 279,
    SIGNED = 280,
    SIZEOF = 281,
    STATIC = 282,
    STRUCT = 283,
    SWITCH = 284,
    TYPEDEF = 285,
    UNION = 286,
    UNSIGNED = 287,
    VOID = 288,
    VOLATILE = 289,
    WHILE = 290,
    _ALIGNAS = 291,
    _ALIGNOF = 292,
    _ATOMIC = 293,
    _BOOL = 294,
    _COMPLEX = 295,
    _GENERIC = 296,
    _IMAGINARY = 297,
    _NORETURN = 298,
    _STATIC_ASSERT = 299,
    _THREAD_LOCAL = 300,
    __FUNC__ = 301,
    ID = 302,
    INT_CONSTANT = 303,
    FLOAT_CONSTANT = 304,
    CHARACTER = 305,
    STRING = 306,
    PLUS = 307,
    MINUS = 308,
    STAR = 309,
    DIV = 310,
    MOD = 311,
    INC = 312,
    DEC = 313,
    EQ = 314,
    NE = 315,
    LANGLE = 316,
    RANGLE = 317,
    GE = 318,
    LE = 319,
    NOT = 320,
    AND = 321,
    OR = 322,
    ESPERLUETTE = 323,
    BNOT = 324,
    BOR = 325,
    XOR = 326,
    LS = 327,
    RS = 328,
    DIRECTASSIGN = 329,
    ADDASSIGN = 330,
    SUBASSIGN = 331,
    MULASSIGN = 332,
    DIVASSIGN = 333,
    MODASSIGN = 334,
    BANDASSIGN = 335,
    XORASSIGN = 336,
    BORASSIGN = 337,
    LSASSIGN = 338,
    RSASSIGN = 339,
    ARROW = 340,
    PERIOD = 341,
    COMMA = 342,
    ELLIPSIS = 343,
    QUESTION = 344,
    COLON = 345,
    SEMICOLON = 346,
    LPARENTHESE = 347,
    RPARENTHESE = 348,
    LBRACE = 349,
    RBRACE = 350,
    LBRACKET = 351,
    RBRACKET = 352,
    ERRORCHAR = 353,
    ELSE = 355
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CLANG_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 227 "clang.tab.c" /* yacc.c:358  */

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


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif


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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1788

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  231
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  385

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   355

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    31,    31,    36,    37,    43,    45,    49,    50,    54,
      55,    59,    60,    64,    65,    66,    67,    68,    69,    70,
      71,    75,    76,    77,    78,    79,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    97,    98,    99,
     103,   104,   105,   109,   110,   114,   115,   119,   120,   124,
     125,   129,   130,   135,   136,   137,   138,   142,   144,   148,
     149,   150,   154,   156,   157,   158,   159,   163,   164,   168,
     170,   174,   175,   179,   181,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   196,   197,   198,   199,   203,   204,
     208,   210,   214,   215,   219,   220,   221,   225,   226,   230,
     231,   232,   236,   237,   241,   242,   246,   247,   248,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   270,   271,   272,   273,   274,   275,
     280,   281,   282,   286,   287,   291,   292,   296,   297,   301,
     302,   303,   307,   308,   312,   313,   314,   315,   316,   317,
     321,   322,   323,   324,   325,   330,   331,   336,   338,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     357,   358,   362,   367,   368,   373,   374,   379,   380,   385,
     386,   391,   393,   398,   399,   400,   405,   406,   407,   408,
     409,   414,   416,   417,   422,   423,   424,   429,   430,   431,
     432,   436,   437,   445,   446,   447,   448,   449,   450,   455,
     457,   459,   461,   463,   465,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   484,   485,   490,   491,   492,
     493,   494
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ENUM", "EXTERN", "FLOAT", "FOR",
  "GOTO", "IF", "INLINE", "INT", "LONG", "REGISTER", "RESTRICT", "RETURN",
  "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF",
  "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE", "_ALIGNAS", "_ALIGNOF",
  "_ATOMIC", "_BOOL", "_COMPLEX", "_GENERIC", "_IMAGINARY", "_NORETURN",
  "_STATIC_ASSERT", "_THREAD_LOCAL", "__FUNC__", "ID", "INT_CONSTANT",
  "FLOAT_CONSTANT", "CHARACTER", "STRING", "PLUS", "MINUS", "STAR", "DIV",
  "MOD", "INC", "DEC", "EQ", "NE", "LANGLE", "RANGLE", "GE", "LE", "NOT",
  "AND", "OR", "ESPERLUETTE", "BNOT", "BOR", "XOR", "LS", "RS",
  "DIRECTASSIGN", "ADDASSIGN", "SUBASSIGN", "MULASSIGN", "DIVASSIGN",
  "MODASSIGN", "BANDASSIGN", "XORASSIGN", "BORASSIGN", "LSASSIGN",
  "RSASSIGN", "ARROW", "PERIOD", "COMMA", "ELLIPSIS", "QUESTION", "COLON",
  "SEMICOLON", "LPARENTHESE", "RPARENTHESE", "LBRACE", "RBRACE",
  "LBRACKET", "RBRACKET", "ERRORCHAR", "\"then\"", "ELSE", "$accept",
  "program", "declarations_definitions", "declaration_definition",
  "function_definition", "declaration", "declaration_list",
  "declaration_definition_specifiers", "storage_specifier",
  "common_type_specifier", "common_type_qualifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "init_declarator_list", "init_declarator",
  "struct_declaration", "common_specifier_qualifier",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "declarator", "bare_declarator",
  "pointer", "common_type_qualifiers", "param_type_list", "param_list",
  "param_declaration", "id_list", "initializer", "initializer_list",
  "type_name", "declarator_without_id", "bare_declarator_without_id",
  "statement", "labeled_statement", "block_statement",
  "declaration_statement_list", "declaration_statement",
  "branch_statement", "comma_expr_statement", "iteration_statement",
  "jump_statement", "comma_expr", "assign_expr", "assign_op",
  "condition_expr", "const_expr", "or_expr", "and_expr", "bor_expr",
  "xor_expr", "band_expr", "eq_neq_expr", "lt_gt_le_ge_expr", "shift_expr",
  "add_sub_expr", "mult_div_mod_expr", "cast_expr", "unary_expr",
  "unary_op", "postfix_expr", "basic_expr", "naive_expr", YY_NULLPTR
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
     355
};
# endif

#define YYPACT_NINF -222

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-222)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1725,  -222,  -222,  -222,  -222,   -33,  -222,  -222,  1725,  -222,
    -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
    -222,  -222,    32,  1725,  -222,  -222,  -222,   102,  1725,  1725,
    1725,  -222,   -29,  -222,   -55,     7,  -222,  -222,  -222,  -222,
      63,  -222,    37,    -4,  -222,   852,   -44,   -16,  -222,  -222,
    -222,   -12,  1754,     7,    21,    24,  -222,  -222,  -222,    63,
      42,    37,  -222,  1393,   439,  -222,   400,   102,  -222,   973,
     622,   -44,  1754,  1754,  1754,  1102,  -222,   165,    25,  1598,
     -35,  -222,  -222,  -222,  -222,  -222,    70,  1627,  -222,  -222,
    -222,  -222,  -222,  -222,  -222,  -222,  1656,  1656,  -222,  -222,
    -222,  1160,  1393,  -222,  -222,  -222,   -46,    93,   132,   147,
     135,    49,   222,   106,   136,   186,  -222,   195,  1598,   139,
    -222,  -222,   161,  1598,   168,   133,   883,   171,   191,   175,
    1540,   198,   210,   214,  -222,  -222,  -222,  -222,  -222,  -222,
     532,  -222,  -222,  -222,  -222,  -222,    31,  -222,  -222,  -222,
    -222,  -222,     8,   212,   219,  -222,    44,   211,  -222,  1218,
     215,  1131,  -222,  -222,  -222,  -222,  1598,  -222,    43,  -222,
     217,   -27,  -222,  -222,  -222,  -222,  -222,  -222,  1160,  -222,
    1160,  -222,  -222,    18,   220,    45,  -222,    26,  1598,  1598,
    1598,  1598,  1598,  1598,  1598,  1598,  1598,  1598,  1598,  1598,
    1598,  1598,  1598,  1598,  1598,  1598,  1598,  -222,  -222,  -222,
    -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  1598,  -222,
    -222,  -222,   269,   270,  1453,  1598,  -222,   234,  -222,   883,
     290,  1037,   240,  1598,  -222,   126,  1598,  1598,   883,  -222,
    -222,  1598,  -222,   308,   696,  -222,   -21,  -222,   130,  -222,
    1229,   287,  -222,  -222,   246,  -222,   247,  -222,  -222,  -222,
     154,  -222,  1598,  -222,   244,   252,   345,   138,  -222,  1423,
    -222,  1311,  -222,    93,   146,   132,   147,   135,    49,   222,
     222,   106,   106,   106,   106,   136,   136,   186,   186,  -222,
    -222,  -222,  -222,  -222,  -222,  -222,    52,     2,   883,  -222,
     254,  1569,  1569,  -222,    60,  -222,    61,   113,  -222,  -222,
    -222,   256,   257,   250,  -222,  1251,   263,   130,  1005,   770,
    -222,  -222,  -222,  -222,  -222,  -222,  -222,   259,   259,  1393,
    -222,  -222,  -222,  1598,  -222,  -222,  -222,  1598,  1482,  1511,
     883,   883,   883,  -222,  -222,  -222,  -222,   264,  -222,  -222,
     261,   271,  -222,  1281,   274,    28,  -222,   118,   883,   127,
     883,   128,   280,  -222,  -222,  -222,  -222,  -222,  -222,   277,
    -222,  1344,  -222,   291,  -222,   883,  -222,   883,   883,  -222,
    -222,  -222,  -222,  -222,  -222
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    23,    26,    37,    27,     0,    24,    28,    20,    29,
      30,    21,    38,    31,    32,    22,    43,    25,    44,    33,
      34,    39,     0,     2,     3,     5,     6,     0,    14,    16,
      18,    35,     0,    36,    66,     0,    19,     1,     4,    73,
      85,    10,     0,     0,    47,    49,    72,     0,    13,    15,
      17,    42,     0,     0,    69,     0,    67,    88,    87,    84,
       0,     0,     9,     0,     0,    11,     0,     0,     7,     0,
       0,    71,     0,    54,    56,     0,    45,     0,     0,     0,
       0,    64,    89,    86,    74,    48,    49,     0,   227,   228,
     229,   230,   231,   211,   212,   210,     0,     0,   214,   209,
     213,     0,     0,    50,    99,   157,   170,   173,   175,   177,
     179,   181,   183,   186,   191,   194,   197,   201,     0,   203,
     215,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   142,   134,   137,   138,   124,   126,
       0,   135,   127,   125,   128,   129,     0,   155,    12,     8,
      97,    83,    96,     0,    90,    92,     0,   210,    75,     0,
       0,     0,    53,    55,    41,    46,     0,    52,     0,    57,
      59,     0,    62,   172,    70,   201,    65,    68,     0,   207,
       0,   204,   205,   105,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,   160,   161,
     162,   163,   164,   167,   169,   168,   165,   166,     0,   206,
     216,   217,     0,     0,     0,     0,   153,     0,   152,     0,
       0,     0,     0,     0,   151,     0,     0,     0,     0,   133,
     136,     0,   143,     0,     0,    94,   106,    95,   108,    81,
       0,     0,    82,    76,   210,    79,     0,    80,    40,    61,
       0,    51,     0,    63,     0,     0,     0,   106,   104,     0,
     226,     0,   100,   174,     0,   176,   178,   180,   182,   184,
     185,   187,   188,   190,   189,   192,   193,   195,   196,   198,
     199,   200,   158,   222,   221,   219,     0,     0,     0,   131,
       0,     0,     0,   154,     0,   150,     0,     0,   132,   156,
     123,     0,     0,   210,   110,     0,     0,   107,     0,     0,
      91,    93,    98,    77,    78,    58,    60,   208,     0,     0,
     202,   101,   103,     0,   220,   218,   130,     0,     0,     0,
       0,     0,     0,   122,   109,   111,   113,     0,   114,   121,
       0,   210,   115,     0,     0,     0,   171,     0,     0,     0,
       0,     0,   139,   141,   148,   112,   120,   116,   118,     0,
     119,     0,   223,     0,   147,     0,   145,     0,     0,   117,
     224,   149,   146,   144,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -222,  -222,  -222,   358,  -222,   -39,  -222,     0,  -222,   -28,
     -37,  -222,  -222,   311,  -222,   323,   -58,     4,  -222,   125,
    -222,   333,   -69,    29,   -42,    -6,  -222,   -65,  -222,   137,
    -222,   -62,    59,    71,  -133,  -188,  -113,  -222,    41,  -222,
     249,  -222,  -221,  -222,  -222,   -38,   -61,  -222,   -72,  -107,
    -222,   202,   201,   203,   200,   204,    86,    97,    87,    95,
     -78,   -30,  -222,  -222,  -222,  -222
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    26,    66,    67,    28,    29,
      30,    31,    32,    75,    43,    44,    76,    77,   168,   169,
      33,    55,    56,    60,    46,    47,    59,   311,   154,   155,
     156,   186,   187,   184,   312,   248,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   218,   105,   174,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      27,   103,   104,    57,   153,    71,    65,   173,    36,   160,
     302,   177,    54,   230,    34,    74,   227,   165,    51,   247,
      54,   188,    82,    27,    73,   136,    39,   148,    48,    49,
      50,    39,    37,    74,    58,    74,    74,    74,    74,    53,
     219,   104,    73,   189,    73,    73,    73,    73,    69,   175,
     268,   173,    70,    83,    54,    39,    45,   179,   317,   259,
     176,    35,    40,   185,    74,    52,   181,   182,   263,   152,
       3,   243,    40,    73,   159,   244,    42,   162,   163,   317,
     338,   339,    72,    61,    39,    12,    68,    62,   175,   241,
      86,    40,   235,   175,   173,    79,    86,    21,   256,   335,
     243,   136,   177,   165,   244,   183,   170,   149,   194,   195,
     266,    80,   171,   271,   244,   371,   299,    40,   241,    81,
     172,   272,   242,   372,    74,   308,   289,   290,   291,    42,
     260,   251,   241,    73,   261,    84,   175,   252,   270,   241,
     185,    74,   185,    74,    63,   334,   246,   241,   241,    39,
      73,   274,    73,   340,   341,   326,    40,   292,   175,   190,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   267,   200,   201,
     309,   245,   183,   316,   183,   336,   296,   297,   202,   203,
     173,   330,   301,    41,    42,   304,   220,   221,   306,   307,
     241,    39,   191,   193,    71,   241,   342,    74,    40,   332,
     104,   373,    39,   241,   241,   241,    73,   305,   192,    40,
     375,   377,   318,   229,   222,   223,   319,   362,   363,   364,
     266,   224,   175,   241,   244,   225,   333,   246,   232,   175,
     204,   205,   206,   152,   166,   374,    42,   376,   315,   264,
     152,   265,   226,   350,   347,   166,   167,    42,   354,   228,
     267,   356,   382,   231,   383,   384,   152,   233,   104,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     279,   280,    74,   196,   197,   198,   199,   285,   286,   170,
     236,    73,   369,   281,   282,   283,   284,   287,   288,   357,
     359,   361,   237,   175,   238,   249,   250,   262,   253,   332,
     104,     1,   257,   269,     2,     3,   293,   294,   152,     4,
       5,     6,     7,   353,   298,   300,     8,     9,    10,    11,
      12,   303,    13,    14,   322,    15,    16,   327,    17,    18,
      19,    20,    21,   323,   324,   328,   337,   345,     1,   343,
     344,     2,     3,   329,   366,    39,     4,     5,     6,     7,
     348,   365,    40,     8,     9,    10,    11,    12,   367,    13,
      14,   370,    15,    16,   379,    17,    18,    19,    20,    21,
     378,    38,   381,   161,    85,   325,    78,   321,   355,   240,
     273,   275,   277,     0,   276,     0,     0,   278,     0,    40,
     243,   310,     0,     1,   244,     0,     2,     3,     0,     0,
       0,     4,     5,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,     0,    13,    14,     0,    15,    16,     0,
      17,    18,    19,    20,    21,     0,     0,   266,   310,     0,
       0,   244,     1,   122,   123,     2,     3,   124,   125,   126,
       4,     5,     6,     7,   127,   128,   129,     8,     9,    10,
      11,    12,   130,    13,    14,    87,    15,    16,   131,    17,
      18,    19,    20,    21,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   133,    89,    90,    91,
      92,    93,    94,    95,    64,     0,    96,    97,     0,     0,
       0,     0,     0,     0,    98,     0,     0,    99,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   101,     0,    64,   135,     1,   122,   123,     2,     3,
     124,   125,   126,     4,     5,     6,     7,   127,   128,   129,
       8,     9,    10,    11,    12,   130,    13,    14,    87,    15,
      16,   131,    17,    18,    19,    20,    21,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   133,
      89,    90,    91,    92,    93,    94,    95,     0,     0,    96,
      97,     0,     0,     0,     0,     0,     0,    98,     0,     0,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   101,     0,    64,   239,     2,     3,
       0,     0,     0,     4,     5,     0,     7,     0,     0,     0,
       0,     9,    10,     0,    12,     0,    13,    14,    87,     0,
      16,     0,     0,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,    92,    93,    94,   157,     0,     0,    96,
      97,     0,     0,     0,     0,     0,     0,    98,     0,     0,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     4,     5,     0,
       7,     0,     0,     0,   101,     9,    10,     0,    12,   158,
      13,    14,    87,     0,    16,     0,     0,    18,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,    92,    93,    94,
     313,     0,     0,    96,    97,     0,     0,     0,     0,     0,
       0,    98,     0,     0,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     0,
       0,     4,     5,     0,     7,     0,     0,     0,   101,     9,
      10,     0,    12,   314,    13,    14,    87,     0,    16,     0,
       0,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,    92,    93,    94,   351,     0,     0,    96,    97,     0,
       0,     0,     0,     0,     0,    98,     0,     0,    99,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     2,     3,
       0,     0,   101,     4,     5,     6,     7,   352,     0,     0,
       8,     9,    10,    11,    12,     0,    13,    14,     0,    15,
      16,     0,    17,    18,    19,    20,    21,   122,   123,     0,
       0,   124,   125,   126,     0,     0,     0,     0,   127,   128,
     129,     0,     0,     0,     0,     0,   130,     0,     0,    87,
       0,     0,   131,     0,     0,     0,     0,     0,   132,     0,
       0,     0,     0,     0,     0,     0,    63,     0,     0,     0,
     133,    89,    90,    91,    92,    93,    94,    95,     0,     0,
      96,    97,     0,     0,     0,     0,    64,     0,    98,     0,
       0,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   101,     1,    64,     0,     2,
       3,     0,     0,     0,     4,     5,     6,     7,     0,     0,
       0,     8,     9,    10,    11,    12,     0,    13,    14,     0,
      15,    16,     0,    17,    18,    19,    20,    21,     1,     0,
       0,     2,     3,     0,     0,     0,     4,     5,     6,     7,
     150,     0,     0,     8,     9,    10,    11,    12,     0,    13,
      14,     0,    15,    16,     0,    17,    18,    19,    20,    21,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     5,
       6,     7,     0,     0,     0,     8,     9,    10,    11,    12,
       0,    13,    14,    87,    15,    16,   151,    17,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,    92,    93,
      94,    95,     0,     0,    96,    97,     0,     0,   349,     0,
       0,     0,    98,     0,     0,    99,   100,     0,     2,     3,
       0,     0,     0,     4,     5,     0,     7,     0,     0,     0,
       0,     9,    10,     0,    12,     0,    13,    14,   134,   101,
      16,     0,     0,    18,    19,    20,    21,     2,     3,     0,
       0,     0,     4,     5,     0,     7,     0,     0,     0,     0,
       9,    10,     0,    12,     0,    13,    14,     0,     0,    16,
       0,     0,    18,    19,    20,    21,     2,     3,     0,     0,
       0,     4,     5,     0,     7,     0,     0,     0,     0,     9,
      10,     0,    12,     0,    13,    14,    87,     0,    16,     0,
       0,    18,    19,    20,    21,     0,     0,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,    96,    97,     0,
       0,     0,     0,     0,     0,    98,   258,     0,    99,   100,
       0,     0,     1,     0,     0,     2,     3,     0,     0,     0,
       4,     5,     6,     7,    87,     0,     0,     8,     9,    10,
      11,    12,   101,    13,    14,     0,    15,    16,     0,    17,
      18,    19,    20,    21,     0,    88,    89,    90,    91,    92,
      93,    94,   254,     0,     0,    96,    97,    87,     0,     0,
       0,     0,     0,    98,     0,     0,    99,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,    92,    93,    94,    95,     0,    87,    96,    97,
     101,     0,     0,     0,     0,   255,    98,   320,     0,    99,
     100,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,    92,    93,    94,    95,     0,    87,    96,    97,
       0,     0,     0,   101,     0,     0,    98,     0,   346,    99,
     100,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,    96,    97,
      87,     0,     0,   101,     0,     0,    98,     0,   368,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,    96,    97,   101,     0,   102,   331,     0,     0,    98,
       0,     0,    99,   100,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,     0,   102,   380,
      88,    89,    90,    91,    92,    93,    94,    95,     0,    87,
      96,    97,     0,     0,     0,     0,     0,     0,    98,     0,
       0,    99,   100,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,    92,    93,    94,    95,     0,    87,
      96,    97,     0,     0,     0,   101,     0,   102,    98,     0,
       0,    99,   100,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,    92,    93,    94,    95,    87,     0,
      96,    97,     0,     0,     0,   101,     0,   329,    98,     0,
       0,    99,   100,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,    92,    93,    94,    95,    87,     0,    96,
      97,     0,     0,     0,     0,   101,   295,    98,     0,     0,
      99,   100,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,    92,    93,    94,    95,    87,     0,    96,    97,
       0,     0,     0,     0,   101,   358,    98,     0,     0,    99,
     100,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,    92,    93,    94,    95,    87,     0,    96,    97,     0,
       0,     0,     0,   101,   360,    98,     0,     0,    99,   100,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
      92,    93,    94,    95,    87,     0,    96,    97,     0,     0,
       0,   234,   101,     0,    98,     0,     0,    99,   100,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,    92,
      93,    94,    95,    87,     0,    96,    97,     0,     0,     0,
     134,   101,     0,    98,     0,     0,    99,   100,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,    92,    93,
      94,    95,    87,     0,    96,    97,     0,     0,     0,     0,
     101,     0,    98,     0,     0,    99,   100,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,    96,    97,     0,     0,     0,     0,   178,
       0,    98,     0,     0,    99,   100,     0,     0,     1,     0,
       0,     2,     3,     0,     0,     0,     4,     5,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,   180,    13,
      14,     0,    15,    16,     0,    17,    18,    19,    20,    21,
       2,     3,     0,     0,     0,     4,     5,     0,     7,     0,
       0,     0,     0,     9,    10,     0,    12,     0,    13,    14,
       0,     0,    16,     0,     0,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    63,    63,    40,    69,    47,    45,    79,     8,    70,
     231,    80,    47,   126,    47,    52,   123,    75,    47,   152,
      47,    67,    59,    23,    52,    64,    47,    66,    28,    29,
      30,    47,     0,    70,    40,    72,    73,    74,    75,    94,
     118,   102,    70,    89,    72,    73,    74,    75,    92,    79,
     183,   123,    96,    59,    47,    47,    27,    87,   246,   166,
      95,    94,    54,   101,   101,    94,    96,    97,    95,    69,
       7,    92,    54,   101,    70,    96,    92,    73,    74,   267,
     301,   302,    94,    87,    47,    22,    45,    91,   118,    87,
      61,    54,   130,   123,   166,    74,    67,    34,   159,    97,
      92,   140,   171,   161,    96,   101,    77,    66,    59,    60,
      92,    87,    87,    87,    96,    87,   229,    54,    87,    95,
      95,    95,    91,    95,   161,   238,   204,   205,   206,    92,
      87,    87,    87,   161,    91,    93,   166,    93,    93,    87,
     178,   178,   180,   180,    74,    93,   152,    87,    87,    47,
     178,   189,   180,    93,    93,   262,    54,   218,   188,    66,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   183,    72,    73,
     241,   152,   178,   244,   180,   298,   224,   225,    52,    53,
     262,   269,   231,    91,    92,   233,    57,    58,   236,   237,
      87,    47,    70,    68,   246,    87,    93,   244,    54,   271,
     271,    93,    47,    87,    87,    87,   244,    91,    71,    54,
      93,    93,    92,    90,    85,    86,    96,   340,   341,   342,
      92,    92,   262,    87,    96,    96,    90,   243,    47,   269,
      54,    55,    56,   243,    90,   358,    92,   360,   244,   178,
     250,   180,    91,   318,   315,    90,    91,    92,   319,    91,
     266,   333,   375,    92,   377,   378,   266,    92,   329,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
     194,   195,   319,    61,    62,    63,    64,   200,   201,   260,
      92,   319,   353,   196,   197,   198,   199,   202,   203,   337,
     338,   339,    92,   333,    90,    93,    87,    90,    97,   371,
     371,     3,    97,    93,     6,     7,    47,    47,   318,    11,
      12,    13,    14,   319,    90,    35,    18,    19,    20,    21,
      22,    91,    24,    25,    47,    27,    28,    93,    30,    31,
      32,    33,    34,    97,    97,    93,    92,    97,     3,    93,
      93,     6,     7,    94,    93,    47,    11,    12,    13,    14,
      97,    97,    54,    18,    19,    20,    21,    22,    97,    24,
      25,    97,    27,    28,    97,    30,    31,    32,    33,    34,
     100,    23,    91,    72,    61,   260,    53,   250,   329,   140,
     188,   190,   192,    -1,   191,    -1,    -1,   193,    -1,    54,
      92,    93,    -1,     3,    96,    -1,     6,     7,    -1,    -1,
      -1,    11,    12,    13,    14,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    24,    25,    -1,    27,    28,    -1,
      30,    31,    32,    33,    34,    -1,    -1,    92,    93,    -1,
      -1,    96,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    94,    -1,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    -1,    94,    95,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    -1,    94,    95,     6,     7,
      -1,    -1,    -1,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    19,    20,    -1,    22,    -1,    24,    25,    26,    -1,
      28,    -1,    -1,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,    -1,    -1,    -1,    11,    12,    -1,
      14,    -1,    -1,    -1,    92,    19,    20,    -1,    22,    97,
      24,    25,    26,    -1,    28,    -1,    -1,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    -1,
      -1,    11,    12,    -1,    14,    -1,    -1,    -1,    92,    19,
      20,    -1,    22,    97,    24,    25,    26,    -1,    28,    -1,
      -1,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,     6,     7,
      -1,    -1,    92,    11,    12,    13,    14,    97,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    24,    25,    -1,    27,
      28,    -1,    30,    31,    32,    33,    34,     4,     5,    -1,
      -1,     8,     9,    10,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    26,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      57,    58,    -1,    -1,    -1,    -1,    94,    -1,    65,    -1,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,     3,    94,    -1,     6,
       7,    -1,    -1,    -1,    11,    12,    13,    14,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    -1,    24,    25,    -1,
      27,    28,    -1,    30,    31,    32,    33,    34,     3,    -1,
      -1,     6,     7,    -1,    -1,    -1,    11,    12,    13,    14,
      47,    -1,    -1,    18,    19,    20,    21,    22,    -1,    24,
      25,    -1,    27,    28,    -1,    30,    31,    32,    33,    34,
       3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,    12,
      13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    28,    93,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    57,    58,    -1,    -1,    93,    -1,
      -1,    -1,    65,    -1,    -1,    68,    69,    -1,     6,     7,
      -1,    -1,    -1,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    19,    20,    -1,    22,    -1,    24,    25,    91,    92,
      28,    -1,    -1,    31,    32,    33,    34,     6,     7,    -1,
      -1,    -1,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,
      19,    20,    -1,    22,    -1,    24,    25,    -1,    -1,    28,
      -1,    -1,    31,    32,    33,    34,     6,     7,    -1,    -1,
      -1,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    19,
      20,    -1,    22,    -1,    24,    25,    26,    -1,    28,    -1,
      -1,    31,    32,    33,    34,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    95,    -1,    68,    69,
      -1,    -1,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,
      11,    12,    13,    14,    26,    -1,    -1,    18,    19,    20,
      21,    22,    92,    24,    25,    -1,    27,    28,    -1,    30,
      31,    32,    33,    34,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    58,    26,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    26,    57,    58,
      92,    -1,    -1,    -1,    -1,    97,    65,    88,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    26,    57,    58,
      -1,    -1,    -1,    92,    -1,    -1,    65,    -1,    97,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    57,    58,
      26,    -1,    -1,    92,    -1,    -1,    65,    -1,    97,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    57,    58,    92,    -1,    94,    95,    -1,    -1,    65,
      -1,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    94,    95,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    26,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    26,
      57,    58,    -1,    -1,    -1,    92,    -1,    94,    65,    -1,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    26,    -1,
      57,    58,    -1,    -1,    -1,    92,    -1,    94,    65,    -1,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    26,    -1,    57,
      58,    -1,    -1,    -1,    -1,    92,    93,    65,    -1,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    26,    -1,    57,    58,
      -1,    -1,    -1,    -1,    92,    93,    65,    -1,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    26,    -1,    57,    58,    -1,
      -1,    -1,    -1,    92,    93,    65,    -1,    -1,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    26,    -1,    57,    58,    -1,    -1,
      -1,    91,    92,    -1,    65,    -1,    -1,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    26,    -1,    57,    58,    -1,    -1,    -1,
      91,    92,    -1,    65,    -1,    -1,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    26,    -1,    57,    58,    -1,    -1,    -1,    -1,
      92,    -1,    65,    -1,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    92,
      -1,    65,    -1,    -1,    68,    69,    -1,    -1,     3,    -1,
      -1,     6,     7,    -1,    -1,    -1,    11,    12,    13,    14,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    92,    24,
      25,    -1,    27,    28,    -1,    30,    31,    32,    33,    34,
       6,     7,    -1,    -1,    -1,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    19,    20,    -1,    22,    -1,    24,    25,
      -1,    -1,    28,    -1,    -1,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    12,    13,    14,    18,    19,
      20,    21,    22,    24,    25,    27,    28,    30,    31,    32,
      33,    34,   102,   103,   104,   105,   106,   108,   109,   110,
     111,   112,   113,   121,    47,    94,   108,     0,   104,    47,
      54,    91,    92,   115,   116,   124,   125,   126,   108,   108,
     108,    47,    94,    94,    47,   122,   123,   111,   126,   127,
     124,    87,    91,    74,    94,   106,   107,   108,   139,    92,
      96,   125,    94,   110,   111,   114,   117,   118,   122,    74,
      87,    95,   111,   126,    93,   116,   124,    26,    47,    48,
      49,    50,    51,    52,    53,    54,    57,    58,    65,    68,
      69,    92,    94,   132,   147,   149,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,     4,     5,     8,     9,    10,    15,    16,    17,
      23,    29,    35,    47,    91,    95,   106,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   106,   139,
      47,    93,   108,   128,   129,   130,   131,    54,    97,   118,
     147,   114,   118,   118,    95,   117,    90,    91,   119,   120,
     124,    87,    95,   149,   150,   162,    95,   123,    92,   162,
      92,   162,   162,   118,   134,   146,   132,   133,    67,    89,
      66,    70,    71,    68,    59,    60,    61,    62,    63,    64,
      72,    73,    52,    53,    54,    55,    56,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,   148,   161,
      57,    58,    85,    86,    92,    96,    91,   150,    91,    90,
     137,    92,    47,    92,    91,   146,    92,    92,    90,    95,
     141,    87,    91,    92,    96,   124,   126,   135,   136,    93,
      87,    87,    93,    97,    54,    97,   147,    97,    95,   150,
      87,    91,    90,    95,   134,   134,    92,   126,   135,    93,
      93,    87,    95,   152,   146,   153,   154,   155,   156,   157,
     157,   158,   158,   158,   158,   159,   159,   160,   160,   161,
     161,   161,   147,    47,    47,    93,   146,   146,    90,   137,
      35,   106,   143,    91,   146,    91,   146,   146,   137,   147,
      93,   128,   135,    54,    97,   118,   147,   136,    92,    96,
      88,   130,    47,    97,    97,   120,   150,    93,    93,    94,
     161,    95,   132,    90,    93,    97,   137,    92,   143,   143,
      93,    93,    93,    93,    93,    97,    97,   147,    97,    93,
     128,    54,    97,   118,   147,   133,   149,   146,    93,   146,
      93,   146,   137,   137,   137,    97,    93,    97,    97,   147,
      97,    87,    95,    93,   137,    93,   137,    93,   100,    97,
      95,    91,   137,   137,   137
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   107,   108,   108,   108,   108,   108,   108,   108,
     108,   109,   109,   109,   109,   109,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   111,
     112,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   118,   118,   119,   119,   120,
     120,   120,   121,   121,   121,   121,   121,   122,   122,   123,
     123,   124,   124,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   126,   126,   126,   126,   127,   127,
     128,   128,   129,   129,   130,   130,   130,   131,   131,   132,
     132,   132,   133,   133,   134,   134,   135,   135,   135,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   137,   137,   137,   137,   137,   137,
     138,   138,   138,   139,   139,   140,   140,   141,   141,   142,
     142,   142,   143,   143,   144,   144,   144,   144,   144,   144,
     145,   145,   145,   145,   145,   146,   146,   147,   147,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     149,   149,   150,   151,   151,   152,   152,   153,   153,   154,
     154,   155,   155,   156,   156,   156,   157,   157,   157,   157,
     157,   158,   158,   158,   159,   159,   159,   160,   160,   160,
     160,   161,   161,   162,   162,   162,   162,   162,   162,   163,
     163,   163,   163,   163,   163,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   165,   165,   166,   166,   166,
     166,   166
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     4,     3,
       2,     1,     2,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     2,     1,     1,     1,     2,     1,     3,     1,
       3,     3,     2,     2,     1,     2,     1,     1,     3,     1,
       3,     2,     5,     6,     4,     5,     2,     1,     3,     1,
       3,     2,     1,     1,     3,     3,     4,     5,     5,     4,
       4,     4,     4,     3,     2,     1,     3,     2,     1,     2,
       1,     3,     1,     3,     2,     2,     1,     1,     3,     1,
       3,     4,     1,     3,     2,     1,     1,     2,     1,     3,
       2,     3,     4,     3,     3,     3,     4,     5,     4,     4,
       4,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     3,     3,     3,     2,     1,     2,     1,     1,     5,
       7,     5,     1,     2,     7,     6,     7,     6,     5,     7,
       3,     2,     2,     2,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     4,     1,     2,     2,     2,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     4,     3,
       4,     3,     3,     6,     7,     1,     3,     1,     1,     1,
       1,     1
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
      YY_LAC_DISCARD ("YYBACKUP");                              \
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

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


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
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
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
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
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

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
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

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
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
  YY_LAC_DISCARD ("shift");

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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
        
#line 2127 "clang.tab.c" /* yacc.c:1646  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
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

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

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

#if 1
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
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 498 "clang.y" /* yacc.c:1906  */
 
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: <prog_name> <input_file>\n");
        exit(-1);
    }
    yyin = fopen(argv[1], "r");
    yyparse();
    if (success) {
        printf("Successful Parsing!\n");
    }
    fclose(yyin);
}

void yyerror(const char *msg) {
    fflush(stdout);
    fprintf(stderr, "Failed Parsing\nLine Number: %d %s\n", yylineno, msg);
    success = 0;
}
