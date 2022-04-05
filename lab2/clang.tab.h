/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
