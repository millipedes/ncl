/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_KND_DOCUMENTS_LOL_BISON_PARSER_TAB_H_INCLUDED
# define YY_YY_HOME_KND_DOCUMENTS_LOL_BISON_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 18 "/home/knd/Documents/lol/bison/parser.y"

  #include "language/include/ast.h"

#line 53 "/home/knd/Documents/lol/bison/parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    STRING = 258,                  /* STRING  */
    ENDMARKER = 259,               /* ENDMARKER  */
    NEWLINE = 260,                 /* NEWLINE  */
    COMMENT = 261,                 /* COMMENT  */
    FALSE = 262,                   /* FALSE  */
    TRUE = 263,                    /* TRUE  */
    BREAK = 264,                   /* BREAK  */
    FOR = 265,                     /* FOR  */
    CANVAS = 266,                  /* CANVAS  */
    COLOR = 267,                   /* COLOR  */
    RECTANGLE = 268,               /* RECTANGLE  */
    CIRCLE = 269,                  /* CIRCLE  */
    ELLIPSE = 270,                 /* ELLIPSE  */
    SQUARE = 271,                  /* SQUARE  */
    LINE = 272,                    /* LINE  */
    TO = 273,                      /* TO  */
    FROM = 274,                    /* FROM  */
    POINT = 275,                   /* POINT  */
    RANGE = 276,                   /* RANGE  */
    APPEND = 277,                  /* APPEND  */
    NORTH = 278,                   /* NORTH  */
    EAST = 279,                    /* EAST  */
    SOUTH = 280,                   /* SOUTH  */
    WEST = 281,                    /* WEST  */
    WRITE = 282,                   /* WRITE  */
    NAME = 283,                    /* NAME  */
    INTEGER = 284,                 /* INTEGER  */
    DOUBLE = 285,                  /* DOUBLE  */
    LPAR = 286,                    /* LPAR  */
    RPAR = 287,                    /* RPAR  */
    LSQB = 288,                    /* LSQB  */
    RSQB = 289,                    /* RSQB  */
    COMMA = 290,                   /* COMMA  */
    PLUS = 291,                    /* PLUS  */
    MINUS = 292,                   /* MINUS  */
    STAR = 293,                    /* STAR  */
    SLASH = 294,                   /* SLASH  */
    VBAR = 295,                    /* VBAR  */
    AMPER = 296,                   /* AMPER  */
    LESS = 297,                    /* LESS  */
    GREATER = 298,                 /* GREATER  */
    EQUAL = 299,                   /* EQUAL  */
    PERCENT = 300,                 /* PERCENT  */
    LBRACE = 301,                  /* LBRACE  */
    RBRACE = 302,                  /* RBRACE  */
    EQEQUAL = 303,                 /* EQEQUAL  */
    NOTEQUAL = 304,                /* NOTEQUAL  */
    LESSEQUAL = 305,               /* LESSEQUAL  */
    GREATEREQUAL = 306,            /* GREATEREQUAL  */
    DOUBLESLASH = 307,             /* DOUBLESLASH  */
    IN = 308,                      /* IN  */
    IF = 309,                      /* IF  */
    HEIGHT = 310,                  /* HEIGHT  */
    WIDTH = 311,                   /* WIDTH  */
    MAJOR_AXIS = 312,              /* MAJOR_AXIS  */
    MINOR_AXIS = 313,              /* MINOR_AXIS  */
    THICKNESS = 314                /* THICKNESS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "/home/knd/Documents/lol/bison/parser.y"

  ast the_ast;

#line 133 "/home/knd/Documents/lol/bison/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_KND_DOCUMENTS_LOL_BISON_PARSER_TAB_H_INCLUDED  */
