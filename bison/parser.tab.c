/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/home/knd/Documents/lol/bison/parser.y"

#include "language/include/ast.h"

extern int yylex();
extern char * yytext;
ast head;

int yyerror(char * s);
const char * token_type_to_string(size_t category);

#line 82 "/home/knd/Documents/lol/bison/parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING = 3,                     /* STRING  */
  YYSYMBOL_ENDMARKER = 4,                  /* ENDMARKER  */
  YYSYMBOL_NEWLINE = 5,                    /* NEWLINE  */
  YYSYMBOL_COMMENT = 6,                    /* COMMENT  */
  YYSYMBOL_FALSE = 7,                      /* FALSE  */
  YYSYMBOL_TRUE = 8,                       /* TRUE  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_CANVAS = 11,                    /* CANVAS  */
  YYSYMBOL_COLOR = 12,                     /* COLOR  */
  YYSYMBOL_RECTANGLE = 13,                 /* RECTANGLE  */
  YYSYMBOL_CIRCLE = 14,                    /* CIRCLE  */
  YYSYMBOL_ELLIPSE = 15,                   /* ELLIPSE  */
  YYSYMBOL_SQUARE = 16,                    /* SQUARE  */
  YYSYMBOL_LINE = 17,                      /* LINE  */
  YYSYMBOL_TO = 18,                        /* TO  */
  YYSYMBOL_FROM = 19,                      /* FROM  */
  YYSYMBOL_POINT = 20,                     /* POINT  */
  YYSYMBOL_RANGE = 21,                     /* RANGE  */
  YYSYMBOL_APPEND = 22,                    /* APPEND  */
  YYSYMBOL_NORTH = 23,                     /* NORTH  */
  YYSYMBOL_EAST = 24,                      /* EAST  */
  YYSYMBOL_SOUTH = 25,                     /* SOUTH  */
  YYSYMBOL_WEST = 26,                      /* WEST  */
  YYSYMBOL_WRITE = 27,                     /* WRITE  */
  YYSYMBOL_NAME = 28,                      /* NAME  */
  YYSYMBOL_INTEGER = 29,                   /* INTEGER  */
  YYSYMBOL_DOUBLE = 30,                    /* DOUBLE  */
  YYSYMBOL_LPAR = 31,                      /* LPAR  */
  YYSYMBOL_RPAR = 32,                      /* RPAR  */
  YYSYMBOL_LSQB = 33,                      /* LSQB  */
  YYSYMBOL_RSQB = 34,                      /* RSQB  */
  YYSYMBOL_COMMA = 35,                     /* COMMA  */
  YYSYMBOL_PLUS = 36,                      /* PLUS  */
  YYSYMBOL_MINUS = 37,                     /* MINUS  */
  YYSYMBOL_STAR = 38,                      /* STAR  */
  YYSYMBOL_SLASH = 39,                     /* SLASH  */
  YYSYMBOL_VBAR = 40,                      /* VBAR  */
  YYSYMBOL_AMPER = 41,                     /* AMPER  */
  YYSYMBOL_LESS = 42,                      /* LESS  */
  YYSYMBOL_GREATER = 43,                   /* GREATER  */
  YYSYMBOL_EQUAL = 44,                     /* EQUAL  */
  YYSYMBOL_PERCENT = 45,                   /* PERCENT  */
  YYSYMBOL_LBRACE = 46,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 47,                    /* RBRACE  */
  YYSYMBOL_EQEQUAL = 48,                   /* EQEQUAL  */
  YYSYMBOL_NOTEQUAL = 49,                  /* NOTEQUAL  */
  YYSYMBOL_LESSEQUAL = 50,                 /* LESSEQUAL  */
  YYSYMBOL_GREATEREQUAL = 51,              /* GREATEREQUAL  */
  YYSYMBOL_DOUBLESLASH = 52,               /* DOUBLESLASH  */
  YYSYMBOL_IN = 53,                        /* IN  */
  YYSYMBOL_IF = 54,                        /* IF  */
  YYSYMBOL_HEIGHT = 55,                    /* HEIGHT  */
  YYSYMBOL_WIDTH = 56,                     /* WIDTH  */
  YYSYMBOL_MAJOR_AXIS = 57,                /* MAJOR_AXIS  */
  YYSYMBOL_MINOR_AXIS = 58,                /* MINOR_AXIS  */
  YYSYMBOL_THICKNESS = 59,                 /* THICKNESS  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_canvas_declaration = 62,        /* canvas_declaration  */
  YYSYMBOL_canvas_parameters = 63,         /* canvas_parameters  */
  YYSYMBOL_canvas_parameter = 64,          /* canvas_parameter  */
  YYSYMBOL_color_declaration = 65,         /* color_declaration  */
  YYSYMBOL_star_NEWLINE_stmt = 66,         /* star_NEWLINE_stmt  */
  YYSYMBOL_pick_NEWLINE_stmt = 67,         /* pick_NEWLINE_stmt  */
  YYSYMBOL_statement = 68,                 /* statement  */
  YYSYMBOL_if_stmt = 69,                   /* if_stmt  */
  YYSYMBOL_write_declaration = 70,         /* write_declaration  */
  YYSYMBOL_for_loop = 71,                  /* for_loop  */
  YYSYMBOL_expression_assignment = 72,     /* expression_assignment  */
  YYSYMBOL_expression_list = 73,           /* expression_list  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_shape_assignment = 75,          /* shape_assignment  */
  YYSYMBOL_shape = 76,                     /* shape  */
  YYSYMBOL_rectangle_declaration = 77,     /* rectangle_declaration  */
  YYSYMBOL_rectangle_parameters = 78,      /* rectangle_parameters  */
  YYSYMBOL_rectangle_parameter = 79,       /* rectangle_parameter  */
  YYSYMBOL_height_declaration = 80,        /* height_declaration  */
  YYSYMBOL_width_declaration = 81,         /* width_declaration  */
  YYSYMBOL_ellipse_declaration = 82,       /* ellipse_declaration  */
  YYSYMBOL_ellipse_parameters = 83,        /* ellipse_parameters  */
  YYSYMBOL_ellipse_parameter = 84,         /* ellipse_parameter  */
  YYSYMBOL_minor_axis_declaration = 85,    /* minor_axis_declaration  */
  YYSYMBOL_major_axis_declaration = 86,    /* major_axis_declaration  */
  YYSYMBOL_thickness_declartaion = 87,     /* thickness_declartaion  */
  YYSYMBOL_point_declaration = 88,         /* point_declaration  */
  YYSYMBOL_line_declaration = 89,          /* line_declaration  */
  YYSYMBOL_to_declaration = 90,            /* to_declaration  */
  YYSYMBOL_from_declaration = 91           /* from_declaration  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_uint8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   466

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    47,    47,    55,    62,    67,    71,    72,    73,    74,
      78,    87,    92,    96,   100,   104,   105,   106,   107,   108,
     109,   113,   121,   128,   134,   144,   153,   154,   161,   162,
     163,   164,   165,   172,   177,   183,   184,   185,   191,   197,
     203,   209,   215,   221,   227,   233,   239,   244,   251,   260,
     261,   262,   263,   264,   268,   275,   280,   284,   285,   286,
     287,   288,   289,   293,   300,   307,   314,   319,   323,   324,
     325,   326,   327,   331,   338,   345,   352,   360,   368,   372,
     379,   383
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "STRING", "ENDMARKER",
  "NEWLINE", "COMMENT", "FALSE", "TRUE", "BREAK", "FOR", "CANVAS", "COLOR",
  "RECTANGLE", "CIRCLE", "ELLIPSE", "SQUARE", "LINE", "TO", "FROM",
  "POINT", "RANGE", "APPEND", "NORTH", "EAST", "SOUTH", "WEST", "WRITE",
  "NAME", "INTEGER", "DOUBLE", "LPAR", "RPAR", "LSQB", "RSQB", "COMMA",
  "PLUS", "MINUS", "STAR", "SLASH", "VBAR", "AMPER", "LESS", "GREATER",
  "EQUAL", "PERCENT", "LBRACE", "RBRACE", "EQEQUAL", "NOTEQUAL",
  "LESSEQUAL", "GREATEREQUAL", "DOUBLESLASH", "IN", "IF", "HEIGHT",
  "WIDTH", "MAJOR_AXIS", "MINOR_AXIS", "THICKNESS", "$accept", "program",
  "canvas_declaration", "canvas_parameters", "canvas_parameter",
  "color_declaration", "star_NEWLINE_stmt", "pick_NEWLINE_stmt",
  "statement", "if_stmt", "write_declaration", "for_loop",
  "expression_assignment", "expression_list", "expression",
  "shape_assignment", "shape", "rectangle_declaration",
  "rectangle_parameters", "rectangle_parameter", "height_declaration",
  "width_declaration", "ellipse_declaration", "ellipse_parameters",
  "ellipse_parameter", "minor_axis_declaration", "major_axis_declaration",
  "thickness_declartaion", "point_declaration", "line_declaration",
  "to_declaration", "from_declaration", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-13)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,   -18,    15,   -16,     2,  -141,    16,  -141,   -14,    -3,
       5,     3,  -141,  -141,  -141,  -141,    -7,  -141,    14,    25,
      27,    29,    26,    16,  -141,  -141,  -141,  -141,  -141,  -141,
     156,   156,   156,  -141,     2,    24,    53,   113,   156,  -141,
    -141,  -141,  -141,  -141,    61,  -141,  -141,   156,   146,   156,
     361,   158,   174,  -141,    75,    65,    69,    70,    71,    73,
    -141,   405,  -141,  -141,  -141,  -141,  -141,   190,   156,   206,
    -141,    31,   405,   415,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,  -141,  -141,    76,  -141,    13,    17,
      91,   156,    67,   344,  -141,  -141,   156,   378,   415,   415,
     -19,   -19,  -141,  -141,   -19,  -141,  -141,   156,  -141,    80,
    -141,    47,  -141,  -141,  -141,  -141,  -141,    84,    86,  -141,
      60,  -141,  -141,  -141,  -141,  -141,    88,    87,   395,    16,
    -141,   405,   156,    48,   156,  -141,    13,   156,   156,  -141,
      17,   113,   105,   156,    77,   222,    81,   156,   238,  -141,
     254,   270,  -141,   286,    97,   100,   102,   302,  -141,  -141,
      16,   318,  -141,  -141,  -141,  -141,  -141,   113,  -141,  -141,
      85,    89,   334,   107,  -141,    16,  -141,  -141,    98,  -141
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     9,     0,     0,
       0,     0,     5,     8,     6,     7,    14,    17,     0,     0,
       0,     0,     0,     0,    13,    19,    20,    16,    18,    15,
       0,     0,     0,     3,     0,     0,     0,     0,     0,     2,
      11,    31,    36,    35,    30,    29,    28,     0,     0,     0,
       0,     0,     0,     4,     0,     0,     0,     0,     0,     0,
      53,    25,    48,    49,    50,    51,    52,     0,     0,     0,
      33,     0,    26,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    64,     0,    22,     0,     0,
       0,     0,     0,     0,    47,    34,     0,     0,    37,    38,
      39,    40,    42,    43,    41,    44,    45,     0,    62,     0,
      57,     0,    56,    59,    60,    61,    58,     0,     0,    68,
       0,    67,    71,    70,    72,    69,     0,     0,     0,     0,
      32,    27,     0,     0,     0,    54,     0,     0,     0,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    66,     0,     0,     0,     0,     0,    21,    10,
       0,     0,    75,    74,    73,    81,    80,     0,    77,    76,
       0,     0,     0,     0,    23,     0,    79,    78,     0,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,  -141,   114,     0,   -23,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,   -29,  -141,  -140,  -141,  -141,    11,
     -81,   -72,  -141,  -141,    18,  -141,  -141,   -79,   -77,  -141,
    -141,  -141
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    11,    12,    60,    22,    23,    24,    25,
      26,    27,    28,    71,    50,    29,    62,    63,   111,   112,
      14,    15,    64,   120,   121,   122,   123,   115,    65,    66,
     156,   127
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,   154,    51,    52,    13,     7,     1,   113,    61,    67,
     124,   116,   125,     4,     8,     5,   114,    30,    69,    72,
      73,    16,    17,    79,    80,     8,    18,   173,    31,     8,
       6,    82,    83,    59,    13,    33,    32,    59,    34,    93,
     -12,   108,    35,    19,    20,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   113,    36,     9,    10,   116,
      38,   124,   128,   125,   114,    95,    96,   131,     9,    10,
      21,    37,   109,    39,   117,   118,   109,    54,   133,   135,
     146,    55,   136,   147,    75,    76,    77,    78,   110,   119,
      79,    80,   139,    81,    68,   140,    86,    87,    82,    83,
      88,    89,    90,   145,    91,   148,   144,   107,   150,   151,
     126,   134,   153,   129,   157,   137,    41,   138,   161,   141,
      42,    43,   142,   155,   158,     8,    56,   160,    57,   166,
      58,   167,   174,    59,   168,   175,   110,   170,   172,   177,
     119,    44,    45,    46,    47,   179,    48,   149,    53,    41,
      49,     0,   178,    42,    43,     0,     0,     0,   152,    41,
       0,     0,     0,    42,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,    46,    47,     0,    48,
      70,     0,     0,    49,    44,    45,    46,    47,     0,    48,
      84,     0,     0,    49,    75,    76,    77,    78,     0,     0,
      79,    80,     0,    81,     0,     0,    85,     0,    82,    83,
      75,    76,    77,    78,     0,     0,    79,    80,     0,    81,
       0,     0,    92,     0,    82,    83,    75,    76,    77,    78,
       0,     0,    79,    80,     0,    81,     0,     0,    94,     0,
      82,    83,    75,    76,    77,    78,     0,     0,    79,    80,
       0,    81,     0,     0,   159,     0,    82,    83,    75,    76,
      77,    78,     0,     0,    79,    80,     0,    81,     0,     0,
     162,     0,    82,    83,    75,    76,    77,    78,     0,     0,
      79,    80,     0,    81,     0,     0,   163,     0,    82,    83,
      75,    76,    77,    78,     0,     0,    79,    80,     0,    81,
       0,     0,   164,     0,    82,    83,    75,    76,    77,    78,
       0,     0,    79,    80,     0,    81,     0,     0,   165,     0,
      82,    83,    75,    76,    77,    78,     0,     0,    79,    80,
       0,    81,     0,     0,   169,     0,    82,    83,    75,    76,
      77,    78,     0,     0,    79,    80,     0,    81,     0,     0,
     171,     0,    82,    83,    75,    76,    77,    78,     0,     0,
      79,    80,     0,    81,     0,     0,   176,     0,    82,    83,
      75,    76,    77,    78,     0,     0,    79,    80,   130,    81,
      75,    76,    77,    78,    82,    83,    79,    80,     0,    81,
       0,     0,     0,     0,    82,    83,    74,    75,    76,    77,
      78,     0,     0,    79,    80,     0,    81,     0,     0,     0,
       0,    82,    83,   132,    75,    76,    77,    78,     0,     0,
      79,    80,     0,    81,     0,     0,     0,     0,    82,    83,
     143,    75,    76,    77,    78,     0,     0,    79,    80,     0,
      81,    75,    76,    77,    78,    82,    83,    79,    80,     0,
      81,     0,     0,    77,    78,    82,    83,    79,    80,     0,
      81,     0,     0,     0,     0,    82,    83
};

static const yytype_int16 yycheck[] =
{
      23,   141,    31,    32,     4,     3,    11,    88,    37,    38,
      89,    88,    89,    31,    12,     0,    88,    31,    47,    48,
      49,     5,     6,    42,    43,    12,    10,   167,    31,    12,
      46,    50,    51,    20,    34,    32,    31,    20,    35,    68,
      47,    28,    28,    27,    28,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,   136,    31,    55,    56,   136,
      31,   140,    91,   140,   136,    34,    35,    96,    55,    56,
      54,    44,    59,    47,    57,    58,    59,    53,   107,    32,
      32,    28,    35,    35,    36,    37,    38,    39,    88,    89,
      42,    43,    32,    45,    33,    35,    21,    32,    50,    51,
      31,    31,    31,   132,    31,   134,   129,    31,   137,   138,
      19,    31,   141,    46,   143,    31,     3,    31,   147,    31,
       7,     8,    35,    18,    47,    12,    13,    46,    15,    32,
      17,    31,    47,    20,    32,    46,   136,   160,   167,    32,
     140,    28,    29,    30,    31,    47,    33,   136,    34,     3,
      37,    -1,   175,     7,     8,    -1,    -1,    -1,   140,     3,
      -1,    -1,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    -1,    33,
      34,    -1,    -1,    37,    28,    29,    30,    31,    -1,    33,
      32,    -1,    -1,    37,    36,    37,    38,    39,    -1,    -1,
      42,    43,    -1,    45,    -1,    -1,    32,    -1,    50,    51,
      36,    37,    38,    39,    -1,    -1,    42,    43,    -1,    45,
      -1,    -1,    32,    -1,    50,    51,    36,    37,    38,    39,
      -1,    -1,    42,    43,    -1,    45,    -1,    -1,    32,    -1,
      50,    51,    36,    37,    38,    39,    -1,    -1,    42,    43,
      -1,    45,    -1,    -1,    32,    -1,    50,    51,    36,    37,
      38,    39,    -1,    -1,    42,    43,    -1,    45,    -1,    -1,
      32,    -1,    50,    51,    36,    37,    38,    39,    -1,    -1,
      42,    43,    -1,    45,    -1,    -1,    32,    -1,    50,    51,
      36,    37,    38,    39,    -1,    -1,    42,    43,    -1,    45,
      -1,    -1,    32,    -1,    50,    51,    36,    37,    38,    39,
      -1,    -1,    42,    43,    -1,    45,    -1,    -1,    32,    -1,
      50,    51,    36,    37,    38,    39,    -1,    -1,    42,    43,
      -1,    45,    -1,    -1,    32,    -1,    50,    51,    36,    37,
      38,    39,    -1,    -1,    42,    43,    -1,    45,    -1,    -1,
      32,    -1,    50,    51,    36,    37,    38,    39,    -1,    -1,
      42,    43,    -1,    45,    -1,    -1,    32,    -1,    50,    51,
      36,    37,    38,    39,    -1,    -1,    42,    43,    34,    45,
      36,    37,    38,    39,    50,    51,    42,    43,    -1,    45,
      -1,    -1,    -1,    -1,    50,    51,    35,    36,    37,    38,
      39,    -1,    -1,    42,    43,    -1,    45,    -1,    -1,    -1,
      -1,    50,    51,    35,    36,    37,    38,    39,    -1,    -1,
      42,    43,    -1,    45,    -1,    -1,    -1,    -1,    50,    51,
      35,    36,    37,    38,    39,    -1,    -1,    42,    43,    -1,
      45,    36,    37,    38,    39,    50,    51,    42,    43,    -1,
      45,    -1,    -1,    38,    39,    50,    51,    42,    43,    -1,
      45,    -1,    -1,    -1,    -1,    50,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    61,    62,    31,     0,    46,     3,    12,    55,
      56,    63,    64,    65,    80,    81,     5,     6,    10,    27,
      28,    54,    66,    67,    68,    69,    70,    71,    72,    75,
      31,    31,    31,    32,    35,    28,    31,    44,    31,    47,
      66,     3,     7,     8,    28,    29,    30,    31,    33,    37,
      74,    74,    74,    64,    53,    28,    13,    15,    17,    20,
      65,    74,    76,    77,    82,    88,    89,    74,    33,    74,
      34,    73,    74,    74,    35,    36,    37,    38,    39,    42,
      43,    45,    50,    51,    32,    32,    21,    32,    31,    31,
      31,    31,    32,    74,    32,    34,    35,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    31,    28,    59,
      65,    78,    79,    80,    81,    87,    88,    57,    58,    65,
      83,    84,    85,    86,    87,    88,    19,    91,    74,    46,
      34,    74,    35,    74,    31,    32,    35,    31,    31,    32,
      35,    31,    35,    35,    66,    74,    32,    35,    74,    79,
      74,    74,    84,    74,    76,    18,    90,    74,    47,    32,
      46,    74,    32,    32,    32,    32,    32,    31,    32,    32,
      66,    32,    74,    76,    47,    46,    32,    32,    66,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    63,    63,    64,    64,    64,    64,
      65,    66,    66,    67,    67,    68,    68,    68,    68,    68,
      68,    69,    70,    71,    71,    72,    73,    73,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    76,
      76,    76,    76,    76,    77,    78,    78,    79,    79,    79,
      79,    79,    79,    80,    81,    82,    83,    83,    84,    84,
      84,    84,    84,    85,    86,    87,    88,    89,    90,    90,
      91,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     4,     3,     1,     1,     1,     1,     1,
       8,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     7,     4,    10,    12,     3,     1,     3,     1,     1,
       1,     1,     4,     2,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     1,
       1,     1,     1,     1,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     3,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     6,     6,     4,     4,
       4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: canvas_declaration LBRACE star_NEWLINE_stmt RBRACE  */
#line 47 "/home/knd/Documents/lol/bison/parser.y"
                                                       {
    (yyvsp[-3].the_ast) = add_child((yyvsp[-3].the_ast), (yyvsp[-1].the_ast));
    head = (yyvsp[-3].the_ast);
    return ENDMARKER;
  }
#line 1346 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 3: /* canvas_declaration: CANVAS LPAR canvas_parameters RPAR  */
#line 55 "/home/knd/Documents/lol/bison/parser.y"
                                       {
    (yyval.the_ast) = init_ast((token){0}, IN_CANVAS_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1355 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 4: /* canvas_parameters: canvas_parameters COMMA canvas_parameter  */
#line 62 "/home/knd/Documents/lol/bison/parser.y"
                                             {
    (yyval.the_ast) = init_ast((token){0}, IN_CANVAS_PARAMETERS);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
  }
#line 1365 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 10: /* color_declaration: COLOR LPAR expression COMMA expression COMMA expression RPAR  */
#line 78 "/home/knd/Documents/lol/bison/parser.y"
                                                                 {
    (yyval.the_ast) = init_ast((token){0}, IN_COLOR_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-5].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-3].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1376 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 11: /* star_NEWLINE_stmt: pick_NEWLINE_stmt star_NEWLINE_stmt  */
#line 87 "/home/knd/Documents/lol/bison/parser.y"
                                        {
    (yyval.the_ast) = init_ast((token){0}, IN_STAR_NEWLINE_STMT);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
  }
#line 1386 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 12: /* star_NEWLINE_stmt: NEWLINE  */
#line 92 "/home/knd/Documents/lol/bison/parser.y"
            { (yyval.the_ast) = (ast){0}; }
#line 1392 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 13: /* pick_NEWLINE_stmt: statement  */
#line 96 "/home/knd/Documents/lol/bison/parser.y"
              {
    (yyval.the_ast) = init_ast((token){0}, IN_PICK_NEWLINE_STMT);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
  }
#line 1401 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 14: /* pick_NEWLINE_stmt: NEWLINE  */
#line 100 "/home/knd/Documents/lol/bison/parser.y"
            { (yyval.the_ast) = (ast){0}; }
#line 1407 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 17: /* statement: COMMENT  */
#line 106 "/home/knd/Documents/lol/bison/parser.y"
            { (yyval.the_ast) = (ast){0}; }
#line 1413 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 21: /* if_stmt: IF LPAR expression RPAR LBRACE star_NEWLINE_stmt RBRACE  */
#line 113 "/home/knd/Documents/lol/bison/parser.y"
                                                            {
    (yyval.the_ast) = init_ast((token){0}, IN_IF_STMT);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-4].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1423 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 22: /* write_declaration: WRITE LPAR NAME RPAR  */
#line 121 "/home/knd/Documents/lol/bison/parser.y"
                         {
    (yyval.the_ast) = init_ast((token){0}, IN_WRITE);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1432 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 23: /* for_loop: FOR NAME IN RANGE LPAR expression RPAR LBRACE star_NEWLINE_stmt RBRACE  */
#line 128 "/home/knd/Documents/lol/bison/parser.y"
                                                                           {
    (yyval.the_ast) = init_ast((token){0}, IN_FOR_LOOP);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-8].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-4].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1443 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 24: /* for_loop: FOR NAME IN RANGE LPAR expression COMMA expression RPAR LBRACE star_NEWLINE_stmt RBRACE  */
#line 134 "/home/knd/Documents/lol/bison/parser.y"
                                                                                            {
    (yyval.the_ast) = init_ast((token){0}, IN_FOR_LOOP);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-10].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-6].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-4].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1455 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 25: /* expression_assignment: NAME EQUAL expression  */
#line 144 "/home/knd/Documents/lol/bison/parser.y"
                          {
    (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION_ASSIGNMENT);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
  }
#line 1466 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 27: /* expression_list: expression_list COMMA expression  */
#line 154 "/home/knd/Documents/lol/bison/parser.y"
                                     {
    (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION_LIST);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
  }
#line 1476 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 32: /* expression: NAME LSQB expression RSQB  */
#line 165 "/home/knd/Documents/lol/bison/parser.y"
                                       {
             (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION);
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-3].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
           }
#line 1488 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 33: /* expression: LSQB RSQB  */
#line 172 "/home/knd/Documents/lol/bison/parser.y"
                       {
             (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION);
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
           }
#line 1498 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 34: /* expression: LSQB expression_list RSQB  */
#line 177 "/home/knd/Documents/lol/bison/parser.y"
                                       {
             (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION);
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
           }
#line 1509 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 37: /* expression: expression PLUS expression  */
#line 185 "/home/knd/Documents/lol/bison/parser.y"
                                        {
             (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION);
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
           }
#line 1520 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 38: /* expression: expression MINUS expression  */
#line 191 "/home/knd/Documents/lol/bison/parser.y"
                                         {
             (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION);
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
           }
#line 1531 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 39: /* expression: expression STAR expression  */
#line 197 "/home/knd/Documents/lol/bison/parser.y"
                                        {
             (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION);
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
           }
#line 1542 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 40: /* expression: expression SLASH expression  */
#line 203 "/home/knd/Documents/lol/bison/parser.y"
                                         {
             (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION);
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
           }
#line 1553 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 41: /* expression: expression PERCENT expression  */
#line 209 "/home/knd/Documents/lol/bison/parser.y"
                                           {
             (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION);
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
           }
#line 1564 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 42: /* expression: expression LESS expression  */
#line 215 "/home/knd/Documents/lol/bison/parser.y"
                                        {
             (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION);
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
           }
#line 1575 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 43: /* expression: expression GREATER expression  */
#line 221 "/home/knd/Documents/lol/bison/parser.y"
                                           {
             (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION);
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
           }
#line 1586 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 44: /* expression: expression LESSEQUAL expression  */
#line 227 "/home/knd/Documents/lol/bison/parser.y"
                                             {
             (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION);
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
           }
#line 1597 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 45: /* expression: expression GREATEREQUAL expression  */
#line 233 "/home/knd/Documents/lol/bison/parser.y"
                                                {
             (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION);
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
           }
#line 1608 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 46: /* expression: MINUS expression  */
#line 239 "/home/knd/Documents/lol/bison/parser.y"
                              {
             (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION);
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
           }
#line 1618 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 47: /* expression: LPAR expression RPAR  */
#line 244 "/home/knd/Documents/lol/bison/parser.y"
                                  {
             (yyval.the_ast) = init_ast((token){0}, IN_EXPRESSION);
             (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
           }
#line 1627 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 48: /* shape_assignment: NAME EQUAL shape  */
#line 251 "/home/knd/Documents/lol/bison/parser.y"
                     {
    (yyval.the_ast) = init_ast((token){0}, IN_SHAPE_ASSIGNMENT);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
  }
#line 1638 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 54: /* rectangle_declaration: RECTANGLE LPAR rectangle_parameters RPAR  */
#line 268 "/home/knd/Documents/lol/bison/parser.y"
                                             {
    (yyval.the_ast) = init_ast((token){0}, IN_RECTANGLE_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1647 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 55: /* rectangle_parameters: rectangle_parameters COMMA rectangle_parameter  */
#line 275 "/home/knd/Documents/lol/bison/parser.y"
                                                   {
    (yyval.the_ast) = init_ast((token){0}, IN_RECTANGLE_PARAMETERS);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
  }
#line 1657 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 63: /* height_declaration: HEIGHT LPAR expression RPAR  */
#line 293 "/home/knd/Documents/lol/bison/parser.y"
                                {
    (yyval.the_ast) = init_ast((token){0}, IN_HEIGHT_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1666 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 64: /* width_declaration: WIDTH LPAR expression RPAR  */
#line 300 "/home/knd/Documents/lol/bison/parser.y"
                               {
    (yyval.the_ast) = init_ast((token){0}, IN_WIDTH_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1675 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 65: /* ellipse_declaration: ELLIPSE LPAR ellipse_parameters RPAR  */
#line 307 "/home/knd/Documents/lol/bison/parser.y"
                                         {
    (yyval.the_ast) = init_ast((token){0}, IN_ELLIPSE_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1684 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 66: /* ellipse_parameters: ellipse_parameters COMMA ellipse_parameter  */
#line 314 "/home/knd/Documents/lol/bison/parser.y"
                                               {
    (yyval.the_ast) = init_ast((token){0}, IN_ELLIPSE_PARAMETERS);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-2].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[0].the_ast));
  }
#line 1694 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 73: /* minor_axis_declaration: MINOR_AXIS LPAR expression RPAR  */
#line 331 "/home/knd/Documents/lol/bison/parser.y"
                                    {
    (yyval.the_ast) = init_ast((token){0}, IN_MAJOR_AXIS_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1703 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 74: /* major_axis_declaration: MAJOR_AXIS LPAR expression RPAR  */
#line 338 "/home/knd/Documents/lol/bison/parser.y"
                                    {
    (yyval.the_ast) = init_ast((token){0}, IN_MINOR_AXIS_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1712 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 75: /* thickness_declartaion: THICKNESS LPAR expression RPAR  */
#line 345 "/home/knd/Documents/lol/bison/parser.y"
                                   {
    (yyval.the_ast) = init_ast((token){0}, IN_THICKNESS_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1721 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 76: /* point_declaration: POINT LPAR expression COMMA expression RPAR  */
#line 352 "/home/knd/Documents/lol/bison/parser.y"
                                                {
    (yyval.the_ast) = init_ast((token){0}, IN_POINT_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-3].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1731 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 77: /* line_declaration: LINE LPAR from_declaration COMMA to_declaration RPAR  */
#line 360 "/home/knd/Documents/lol/bison/parser.y"
                                                         {
    (yyval.the_ast) = init_ast((token){0}, IN_LINE_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-3].the_ast));
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1741 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 78: /* to_declaration: TO LPAR shape RPAR  */
#line 368 "/home/knd/Documents/lol/bison/parser.y"
                       {
    (yyval.the_ast) = init_ast((token){0}, IN_TO_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1750 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 79: /* to_declaration: TO LPAR expression RPAR  */
#line 372 "/home/knd/Documents/lol/bison/parser.y"
                            {
    (yyval.the_ast) = init_ast((token){0}, IN_TO_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1759 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 80: /* from_declaration: FROM LPAR shape RPAR  */
#line 379 "/home/knd/Documents/lol/bison/parser.y"
                         {
    (yyval.the_ast) = init_ast((token){0}, IN_FROM_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1768 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;

  case 81: /* from_declaration: FROM LPAR expression RPAR  */
#line 383 "/home/knd/Documents/lol/bison/parser.y"
                              {
    (yyval.the_ast) = init_ast((token){0}, IN_FROM_DECLARATION);
    (yyval.the_ast) = add_child((yyval.the_ast), (yyvsp[-1].the_ast));
  }
#line 1777 "/home/knd/Documents/lol/bison/parser.tab.c"
    break;


#line 1781 "/home/knd/Documents/lol/bison/parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 389 "/home/knd/Documents/lol/bison/parser.y"


int yyerror(char * s) {
  fprintf(stderr, "Error: `%s`\n", s);
  exit(1);
}

const char * token_type_to_string(size_t category) {
  switch(category) {
    case STRING:        return "string";
    case ENDMARKER:     return "endmarker";
    case NEWLINE:       return "newline";
    case COMMENT:       return "comment";
    case FALSE:         return "false";
    case TRUE:          return "true";
    case BREAK:         return "break";
    case FOR:           return "for";
    case CANVAS:        return "canvas";
    case COLOR:         return "color";
    case RECTANGLE:     return "rectangle";
    case CIRCLE:        return "circle";
    case ELLIPSE:       return "ellipse";
    case SQUARE:        return "square";
    case LINE:          return "line";
    case TO:            return "to";
    case FROM:          return "from";
    case POINT:         return "point";
    case RANGE:         return "range";
    case APPEND:        return "append";
    case NORTH:         return "north";
    case EAST:          return "east";
    case SOUTH:         return "south";
    case WEST:          return "west";
    case WRITE:         return "write";
    case NAME:          return "name";
    case INTEGER:       return "integer";
    case DOUBLE:        return "double";
    case LPAR:          return "lpar";
    case RPAR:          return "rpar";
    case LSQB:          return "lsqb";
    case RSQB:          return "rsqb";
    case COMMA:         return "comma";
    case PLUS:          return "plus";
    case MINUS:         return "minus";
    case STAR:          return "star";
    case SLASH:         return "slash";
    case VBAR:          return "vbar";
    case AMPER:         return "amper";
    case LESS:          return "less";
    case GREATER:       return "greater";
    case EQUAL:         return "equal";
    case PERCENT:       return "percent";
    case LBRACE:        return "lbrace";
    case RBRACE:        return "rbrace";
    case EQEQUAL:       return "eqequal";
    case NOTEQUAL:      return "notequal";
    case LESSEQUAL:     return "lessequal";
    case GREATEREQUAL:  return "greaterequal";
    case DOUBLESLASH:   return "doubleslash";
  }
  return NULL;
}
