#include"tree.h"
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
#line 22 "parser.y" /* yacc.c:1909  */

  TreeNode* node;

#line 144 "y.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
