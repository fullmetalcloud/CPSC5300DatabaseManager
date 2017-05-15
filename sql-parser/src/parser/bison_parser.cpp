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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         HSQL_STYPE
#define YYLTYPE         HSQL_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         hsql_parse
#define yylex           hsql_lex
#define yyerror         hsql_error
#define yydebug         hsql_debug
#define yynerrs         hsql_nerrs


/* Copy the first part of user declarations.  */
#line 1 "bison_parser.y" /* yacc.c:339  */

/**
 * bison_parser.y
 * defines bison_parser.h
 * outputs bison_parser.c
 * 
 * Grammar File Spec: http://dinosaur.compilertools.net/bison/bison_6.html
 *
 */
/*********************************
 ** Section 1: C Declarations
 *********************************/

#include "bison_parser.h"
#include "flex_lexer.h"

#include <stdio.h>

using namespace hsql;

int yyerror(YYLTYPE* llocp, SQLParserResult** result, yyscan_t scanner, const char *msg) {
	delete *result;

	SQLParserResult* list = new SQLParserResult();
	list->setIsValid(false);
	list->setErrorDetails(strdup(msg), llocp->first_line, llocp->first_column);

	*result = list;
	return 0;
}




#line 109 "bison_parser.cpp" /* yacc.c:339  */

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
   by #include "bison_parser.h".  */
#ifndef YY_HSQL_BISON_PARSER_H_INCLUDED
# define YY_HSQL_BISON_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef HSQL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define HSQL_DEBUG 1
#  else
#   define HSQL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define HSQL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined HSQL_DEBUG */
#if HSQL_DEBUG
extern int hsql_debug;
#endif
/* "%code requires" blocks.  */
#line 41 "bison_parser.y" /* yacc.c:355  */

// %code requires block	

#include "../sql/statements.h"
#include "../SQLParserResult.h"
#include "parser_typedef.h"

// Auto update column and line number
#define YY_USER_ACTION \
    yylloc->first_line = yylloc->last_line; \
    yylloc->first_column = yylloc->last_column; \
    for(int i = 0; yytext[i] != '\0'; i++) { \
    	yylloc->total_column++; \
        if(yytext[i] == '\n') { \
            yylloc->last_line++; \
            yylloc->last_column = 0; \
        } \
        else { \
            yylloc->last_column++; \
        } \
    }

#line 170 "bison_parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef HSQL_TOKENTYPE
# define HSQL_TOKENTYPE
  enum hsql_tokentype
  {
    SQL_IDENTIFIER = 258,
    SQL_STRING = 259,
    SQL_FLOATVAL = 260,
    SQL_INTVAL = 261,
    SQL_NOTEQUALS = 262,
    SQL_LESSEQ = 263,
    SQL_GREATEREQ = 264,
    SQL_DEALLOCATE = 265,
    SQL_PARAMETERS = 266,
    SQL_INTERSECT = 267,
    SQL_TEMPORARY = 268,
    SQL_TIMESTAMP = 269,
    SQL_DISTINCT = 270,
    SQL_NVARCHAR = 271,
    SQL_RESTRICT = 272,
    SQL_TRUNCATE = 273,
    SQL_ANALYZE = 274,
    SQL_BETWEEN = 275,
    SQL_CASCADE = 276,
    SQL_COLUMNS = 277,
    SQL_CONTROL = 278,
    SQL_DEFAULT = 279,
    SQL_EXECUTE = 280,
    SQL_EXPLAIN = 281,
    SQL_HISTORY = 282,
    SQL_INTEGER = 283,
    SQL_NATURAL = 284,
    SQL_PREPARE = 285,
    SQL_PRIMARY = 286,
    SQL_SCHEMAS = 287,
    SQL_SPATIAL = 288,
    SQL_VIRTUAL = 289,
    SQL_BEFORE = 290,
    SQL_COLUMN = 291,
    SQL_CREATE = 292,
    SQL_DELETE = 293,
    SQL_DIRECT = 294,
    SQL_DOUBLE = 295,
    SQL_ESCAPE = 296,
    SQL_EXCEPT = 297,
    SQL_EXISTS = 298,
    SQL_GLOBAL = 299,
    SQL_HAVING = 300,
    SQL_IMPORT = 301,
    SQL_INSERT = 302,
    SQL_ISNULL = 303,
    SQL_OFFSET = 304,
    SQL_RENAME = 305,
    SQL_SCHEMA = 306,
    SQL_SELECT = 307,
    SQL_SORTED = 308,
    SQL_TABLES = 309,
    SQL_UNIQUE = 310,
    SQL_UNLOAD = 311,
    SQL_UPDATE = 312,
    SQL_VALUES = 313,
    SQL_AFTER = 314,
    SQL_ALTER = 315,
    SQL_BTREE = 316,
    SQL_CROSS = 317,
    SQL_DELTA = 318,
    SQL_GROUP = 319,
    SQL_INDEX = 320,
    SQL_INNER = 321,
    SQL_LIMIT = 322,
    SQL_LOCAL = 323,
    SQL_MERGE = 324,
    SQL_MINUS = 325,
    SQL_ORDER = 326,
    SQL_OUTER = 327,
    SQL_RIGHT = 328,
    SQL_TABLE = 329,
    SQL_UNION = 330,
    SQL_USING = 331,
    SQL_WHERE = 332,
    SQL_CALL = 333,
    SQL_CASE = 334,
    SQL_DATE = 335,
    SQL_DESC = 336,
    SQL_DROP = 337,
    SQL_ELSE = 338,
    SQL_FILE = 339,
    SQL_FROM = 340,
    SQL_FULL = 341,
    SQL_HASH = 342,
    SQL_HINT = 343,
    SQL_INTO = 344,
    SQL_JOIN = 345,
    SQL_LEFT = 346,
    SQL_LIKE = 347,
    SQL_LOAD = 348,
    SQL_NULL = 349,
    SQL_PART = 350,
    SQL_PLAN = 351,
    SQL_SHOW = 352,
    SQL_TEXT = 353,
    SQL_THEN = 354,
    SQL_TIME = 355,
    SQL_VIEW = 356,
    SQL_WHEN = 357,
    SQL_WITH = 358,
    SQL_ADD = 359,
    SQL_ALL = 360,
    SQL_AND = 361,
    SQL_ASC = 362,
    SQL_CSV = 363,
    SQL_END = 364,
    SQL_FOR = 365,
    SQL_INT = 366,
    SQL_KEY = 367,
    SQL_NOT = 368,
    SQL_OFF = 369,
    SQL_SET = 370,
    SQL_TBL = 371,
    SQL_TOP = 372,
    SQL_AS = 373,
    SQL_BY = 374,
    SQL_IF = 375,
    SQL_IN = 376,
    SQL_IS = 377,
    SQL_OF = 378,
    SQL_ON = 379,
    SQL_OR = 380,
    SQL_TO = 381,
    SQL_EQUALS = 382,
    SQL_LESS = 383,
    SQL_GREATER = 384,
    SQL_NOTNULL = 385,
    SQL_UMINUS = 386
  };
#endif

/* Value type.  */
#if ! defined HSQL_STYPE && ! defined HSQL_STYPE_IS_DECLARED

union HSQL_STYPE
{
#line 100 "bison_parser.y" /* yacc.c:355  */

	double fval;
	int64_t ival;
	char* sval;
	char* ssval;
	uintmax_t uval;
	bool bval;

	hsql::SQLStatement* statement;
	hsql::SelectStatement* 	select_stmt;
	hsql::ImportStatement* 	import_stmt;
	hsql::CreateStatement* 	create_stmt;
	hsql::InsertStatement* 	insert_stmt;
	hsql::DeleteStatement* 	delete_stmt;
	hsql::UpdateStatement* 	update_stmt;
	hsql::DropStatement*   	drop_stmt;
	hsql::PrepareStatement* prep_stmt;
	hsql::ExecuteStatement* exec_stmt;
	hsql::ShowStatement*    show_stmt;

	hsql::TableRef* table;
	hsql::Expr* expr;
	hsql::OrderDescription* order;
	hsql::OrderType order_type;
	hsql::LimitDescription* limit;
	hsql::ColumnDefinition* column_t;
	hsql::GroupByDescription* group_t;
	hsql::UpdateClause* update_t;

	hsql::SQLParserResult* stmt_list;

	std::vector<char*>* str_vec;
	std::vector<hsql::TableRef*>* table_vec;
	std::vector<hsql::ColumnDefinition*>* column_vec;
	std::vector<hsql::UpdateClause*>* update_vec;
	std::vector<hsql::Expr*>* expr_vec;
	std::vector<hsql::OrderDescription*>* order_vec;

#line 353 "bison_parser.cpp" /* yacc.c:355  */
};

typedef union HSQL_STYPE HSQL_STYPE;
# define HSQL_STYPE_IS_TRIVIAL 1
# define HSQL_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined HSQL_LTYPE && ! defined HSQL_LTYPE_IS_DECLARED
typedef struct HSQL_LTYPE HSQL_LTYPE;
struct HSQL_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define HSQL_LTYPE_IS_DECLARED 1
# define HSQL_LTYPE_IS_TRIVIAL 1
#endif



int hsql_parse (hsql::SQLParserResult** result, yyscan_t scanner);

#endif /* !YY_HSQL_BISON_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 383 "bison_parser.cpp" /* yacc.c:358  */

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
         || (defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL \
             && defined HSQL_STYPE_IS_TRIVIAL && HSQL_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  55
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   459

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  152
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  184
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  353

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   386

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   138,     2,     2,
     143,   144,   136,   134,   150,   135,   145,   137,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   147,   146,
     129,   127,   130,   151,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   141,     2,   142,   139,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   148,     2,   149,     2,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   128,   131,   132,   133,   140
};

#if HSQL_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   249,   249,   256,   257,   261,   266,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   288,   293,   301,
     305,   317,   325,   329,   339,   345,   351,   358,   368,   369,
     370,   373,   374,   378,   379,   383,   387,   393,   394,   395,
     396,   400,   411,   415,   420,   424,   437,   440,   445,   457,
     465,   477,   483,   493,   494,   504,   513,   514,   518,   530,
     531,   535,   536,   540,   550,   564,   578,   579,   580,   584,
     596,   597,   601,   605,   610,   611,   615,   620,   624,   625,
     628,   629,   633,   634,   638,   642,   643,   644,   650,   651,
     655,   656,   657,   664,   665,   669,   670,   674,   681,   682,
     683,   684,   685,   686,   690,   691,   692,   693,   694,   695,
     699,   700,   701,   705,   706,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   722,   723,   727,   728,   729,   730,
     735,   739,   740,   744,   745,   746,   747,   748,   749,   753,
     757,   761,   762,   766,   767,   768,   772,   777,   778,   782,
     786,   790,   801,   802,   812,   813,   819,   824,   825,   830,
     840,   848,   849,   853,   854,   858,   859,   863,   870,   882,
     883,   884,   885,   886,   887,   888,   889,   890,   896,   902,
     906,   915,   916,   921,   922
};
#endif

#if HSQL_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "FLOATVAL",
  "INTVAL", "NOTEQUALS", "LESSEQ", "GREATEREQ", "DEALLOCATE", "PARAMETERS",
  "INTERSECT", "TEMPORARY", "TIMESTAMP", "DISTINCT", "NVARCHAR",
  "RESTRICT", "TRUNCATE", "ANALYZE", "BETWEEN", "CASCADE", "COLUMNS",
  "CONTROL", "DEFAULT", "EXECUTE", "EXPLAIN", "HISTORY", "INTEGER",
  "NATURAL", "PREPARE", "PRIMARY", "SCHEMAS", "SPATIAL", "VIRTUAL",
  "BEFORE", "COLUMN", "CREATE", "DELETE", "DIRECT", "DOUBLE", "ESCAPE",
  "EXCEPT", "EXISTS", "GLOBAL", "HAVING", "IMPORT", "INSERT", "ISNULL",
  "OFFSET", "RENAME", "SCHEMA", "SELECT", "SORTED", "TABLES", "UNIQUE",
  "UNLOAD", "UPDATE", "VALUES", "AFTER", "ALTER", "BTREE", "CROSS",
  "DELTA", "GROUP", "INDEX", "INNER", "LIMIT", "LOCAL", "MERGE", "MINUS",
  "ORDER", "OUTER", "RIGHT", "TABLE", "UNION", "USING", "WHERE", "CALL",
  "CASE", "DATE", "DESC", "DROP", "ELSE", "FILE", "FROM", "FULL", "HASH",
  "HINT", "INTO", "JOIN", "LEFT", "LIKE", "LOAD", "NULL", "PART", "PLAN",
  "SHOW", "TEXT", "THEN", "TIME", "VIEW", "WHEN", "WITH", "ADD", "ALL",
  "AND", "ASC", "CSV", "END", "FOR", "INT", "KEY", "NOT", "OFF", "SET",
  "TBL", "TOP", "AS", "BY", "IF", "IN", "IS", "OF", "ON", "OR", "TO",
  "'='", "EQUALS", "'<'", "'>'", "LESS", "GREATER", "NOTNULL", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'^'", "UMINUS", "'['", "']'", "'('", "')'",
  "'.'", "';'", "':'", "'{'", "'}'", "','", "'?'", "$accept", "input",
  "statement_list", "statement", "preparable_statement",
  "prepare_statement", "execute_statement", "import_statement",
  "import_file_type", "file_path", "create_statement", "opt_using_type",
  "opt_not_exists", "column_def_commalist", "column_def", "column_type",
  "column_list", "drop_statement", "show_statement", "delete_statement",
  "truncate_statement", "insert_statement", "opt_column_list",
  "update_statement", "update_clause_commalist", "update_clause",
  "select_statement", "select_with_paren", "select_no_paren",
  "set_operator", "select_clause", "opt_distinct", "select_list",
  "from_clause", "opt_where", "opt_group", "opt_having", "opt_order",
  "order_list", "order_desc", "opt_order_type", "opt_top", "opt_limit",
  "expr_list", "literal_list", "expr_alias", "expr", "operand",
  "scalar_expr", "unary_expr", "binary_expr", "logic_expr", "in_expr",
  "case_expr", "exists_expr", "comp_expr", "function_expr", "between_expr",
  "column_name", "literal", "string_literal", "num_literal", "int_literal",
  "star_expr", "placeholder_expr", "table_ref", "table_ref_atomic",
  "table_ref_commalist", "table_ref_name", "table_ref_name_no_alias",
  "table_name", "alias", "opt_alias", "index_name", "join_clause",
  "opt_join_type", "join_table", "join_condition", "opt_semicolon",
  "ident_commalist", YY_NULLPTR
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
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,    61,   382,    60,
      62,   383,   384,   385,    43,    45,    42,    47,    37,    94,
     386,    91,    93,    40,    41,    46,    59,    58,   123,   125,
      44,    63
};
# endif

#define YYPACT_NINF -279

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-279)))

#define YYTABLE_NINF -180

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-180)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     177,    -3,    32,   113,   123,    40,   -42,    54,    55,    29,
      32,   104,    24,   -32,   162,    19,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,    27,   178,    45,  -279,    42,   -47,   191,    77,    77,
      32,   105,    32,   197,   202,   111,  -279,   191,    32,    32,
     155,  -279,   159,   114,   116,  -279,   177,  -279,  -279,  -279,
     129,  -279,   -32,   190,  -279,   265,     2,   181,   177,  -279,
     148,   160,    32,    32,   206,  -279,   220,   147,  -279,  -279,
    -279,    25,   302,   222,  -279,  -279,    32,    32,  -279,  -279,
    -279,    25,   237,   237,   197,  -279,  -279,  -279,  -279,  -279,
     -67,  -279,  -279,  -279,  -279,  -279,  -279,    19,    32,   267,
     -62,   147,    25,  -279,   307,   309,    61,   -46,   170,   212,
      53,    57,  -279,    12,   233,   169,  -279,    34,   164,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,   195,   -58,  -279,    32,  -279,  -279,   173,  -279,
      73,   190,   190,   276,  -279,     2,   182,   250,  -279,   213,
      81,   217,   -81,   254,  -279,  -279,   -35,   201,  -279,   202,
     344,   296,    25,   211,    57,   257,   150,   219,   -59,     6,
     206,    25,  -279,    25,   353,    25,  -279,  -279,    57,    57,
      57,    57,    57,   -41,   224,    57,    57,    57,    57,    57,
      57,    57,    57,    57,     2,   302,  -279,  -279,    25,  -279,
    -279,  -279,  -279,  -279,   197,  -279,  -279,   -11,   225,   281,
      39,   261,    33,  -279,   -32,    32,  -279,   363,     2,    25,
    -279,   230,    76,   296,   283,  -279,  -279,   -32,  -279,   232,
     180,    18,  -279,   368,   319,  -279,  -279,  -279,   279,   272,
     288,   288,   203,   272,    57,   245,    12,   272,   288,   288,
     150,   150,   251,   251,   251,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,   309,  -279,   307,  -279,  -279,  -279,  -279,  -279,
     246,  -279,    81,  -279,  -279,  -279,    72,    95,  -279,    57,
     256,   259,     6,  -279,  -279,  -279,  -279,  -279,   326,   332,
     315,   293,  -279,    57,   272,    12,   269,    97,   117,  -279,
     309,  -279,  -279,  -279,   223,  -279,    18,  -279,   264,  -279,
    -279,     8,    25,   257,   271,   125,  -279,  -279,  -279,   132,
      57,   255,  -279,     6,   -32,  -279,   292,   -33,  -279,  -279,
    -279,   242,  -279,   275,    25,    25,  -279,  -279,    18,   -81,
    -279,   -81,  -279
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,   182,     3,     6,     5,    16,
       8,     9,    14,    15,    11,    12,    10,    13,     7,    59,
      60,    81,     0,   161,    50,    19,     0,     0,    32,    32,
       0,     0,     0,     0,    71,     0,   160,     0,     0,     0,
       0,    46,     0,     0,     0,     1,   181,     2,    67,    68,
       0,    66,     0,    92,    45,     0,     0,     0,     0,   167,
       0,     0,     0,     0,    75,    22,     0,    54,   149,    88,
      70,     0,     0,     0,    42,    44,     0,     0,    62,    61,
       4,     0,    81,    81,     0,    63,   162,   146,   147,   151,
       0,    95,   143,   144,   148,   145,    17,   182,     0,     0,
       0,    54,     0,    49,     0,     0,     0,   141,     0,     0,
       0,     0,   150,     0,     0,    72,    93,   166,    98,   105,
     106,   107,   100,   103,   102,   101,   115,   108,    99,   110,
     112,   111,     0,    75,    56,     0,    47,    48,    80,    82,
      87,    92,    92,    90,    20,     0,     0,    30,    31,     0,
       0,     0,    74,     0,    23,   183,     0,     0,    52,    71,
       0,     0,     0,     0,     0,   114,   113,     0,     0,     0,
      75,     0,   164,     0,     0,     0,   165,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    43,     0,    86,
      85,    84,    65,    64,     0,    96,    18,     0,     0,     0,
       0,     0,     0,    33,     0,     0,    53,     0,     0,     0,
     142,     0,     0,     0,     0,   109,   104,     0,    73,   152,
     154,   166,   156,   177,    77,    94,   124,   163,   125,   134,
     137,   138,     0,   122,     0,     0,     0,   133,   135,   136,
     117,   116,   119,   118,   120,   121,    58,    57,    83,    91,
      28,    29,     0,    27,     0,    38,    39,    40,    37,    36,
       0,    25,     0,    26,    21,   184,     0,     0,   131,     0,
       0,     0,     0,   159,   176,   175,   169,   170,   174,   173,
       0,     0,    69,     0,   123,     0,     0,     0,     0,    24,
       0,    34,    51,   139,     0,   132,   166,   157,   153,   172,
     171,     0,     0,   140,     0,     0,   128,   126,    41,     0,
       0,   165,   155,     0,     0,   179,     0,    79,   129,   127,
      35,     0,   158,     0,     0,     0,    76,   130,     0,   180,
     168,    78,   178
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -279,  -279,   352,   365,   361,  -279,  -279,  -279,  -279,   157,
    -279,  -279,   390,  -279,   151,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,   321,  -279,  -279,   231,  -192,    13,   -13,  -279,
     373,   268,  -279,  -279,  -109,  -279,  -279,    64,  -279,   234,
    -279,  -279,    85,  -215,   210,   258,   -90,   -68,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,   -61,
    -110,  -279,   -40,  -279,  -279,  -279,  -268,  -279,   122,  -279,
       0,  -278,  -228,   397,  -279,  -279,   124,  -279,   339,  -236
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    19,    20,    76,   163,
      21,   218,    72,   222,   223,   279,   273,    22,    23,    24,
      25,    26,   116,    27,   143,   144,    28,    29,    30,    62,
      31,    81,   124,   180,   113,   302,   346,    63,   148,   149,
     211,    44,    95,   125,   100,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     102,   103,   104,   141,   105,   238,   239,   318,   240,    45,
     241,   186,   187,    70,   242,   300,   243,   350,    57,   166
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   150,    34,    79,   164,   101,    97,    98,    78,    33,
      46,    33,   345,   293,   287,   117,    97,    98,    78,   112,
       9,   182,   162,   159,   317,   183,    53,    32,   117,    97,
      98,    78,   283,   178,   206,    33,   308,   182,   331,    58,
      74,   307,    77,    40,   185,   291,    50,   183,    84,    85,
     270,   254,   175,   176,   153,   118,   117,    97,    98,    78,
     117,    97,    98,    78,     9,   342,   185,   275,   118,    59,
     352,   244,   110,   111,   329,    92,   271,   154,    51,   276,
     255,   160,   232,   155,   220,   236,   146,   147,   332,    52,
     325,   119,   205,   246,   215,   248,   173,   169,    60,   170,
      67,    68,    61,   168,   119,    37,   175,   337,   157,   226,
     177,    13,   221,     9,    38,   227,    35,   181,   150,   167,
     249,   250,   251,   252,   253,   120,    36,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   184,   277,   120,    41,
     183,    39,   343,   266,    42,   207,    43,   121,   122,   237,
     278,   334,   184,    99,   209,   123,   151,   152,   231,   185,
     121,   122,    55,    99,   164,    56,   174,   101,   123,    47,
     174,   188,   189,   190,   269,   289,    99,   281,    48,   183,
     210,    64,   183,   282,   191,    66,   304,     1,   121,   122,
      65,     1,   121,   122,    69,     2,   123,    71,   185,     2,
     123,   185,     3,    78,    99,    49,     3,     4,    99,  -179,
     188,   189,   190,    75,     5,     6,   312,    80,     5,     6,
     290,   314,   155,     7,     8,   284,    82,     7,     8,     9,
     188,   189,   190,     9,    10,   323,   212,   213,    10,   313,
      86,   327,  -179,   306,    87,   181,  -179,   181,    91,   188,
     189,   190,  -179,  -179,   349,   351,   192,    94,    88,    11,
      89,   328,   341,    11,   188,   189,   190,   227,    96,   339,
    -179,  -179,   108,   109,    12,   181,   340,   193,    12,   188,
     189,   190,   227,   112,  -178,   194,   200,   201,   202,   203,
     115,   195,   324,   196,   197,   192,  -180,  -180,   198,   199,
     200,   201,   202,   203,   114,   142,   330,   145,    60,   303,
     158,    97,   165,   171,   172,   192,   234,  -178,   179,   181,
      13,  -178,   204,   208,    13,   214,   217,  -178,  -178,   219,
     195,   216,   196,   197,   192,   224,   234,   198,   199,   200,
     201,   202,   203,   225,   228,  -178,  -178,   230,     9,   192,
     195,   347,   196,   197,   233,   234,   247,   198,   199,   200,
     201,   202,   203,   235,   192,   274,   285,   256,   272,   195,
     234,   196,   197,   280,   288,   254,   198,   199,   200,   201,
     202,   203,   292,   301,   195,   183,   196,   197,   305,   310,
     203,   198,   199,   200,   201,   202,   203,   294,   319,   195,
     315,   196,   197,   316,   320,   321,   198,   199,   200,   201,
     202,   203,   322,   326,   333,   338,   344,  -180,  -180,   348,
     107,    90,   198,   199,   200,   201,   202,   203,   106,    73,
     295,   309,   161,   311,   296,    93,   267,   229,   286,   245,
     297,   298,   268,   335,    83,   336,   156,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   299
};

static const yytype_int16 yycheck[] =
{
      13,    91,     2,    43,   114,    66,     4,     5,     6,     3,
      10,     3,    45,   241,   229,     3,     4,     5,     6,    77,
      52,     3,   112,    85,   292,   106,    13,    30,     3,     4,
       5,     6,   224,   123,   143,     3,   272,     3,   316,    12,
      40,   256,    42,    85,   125,   237,    22,   106,    48,    49,
      61,    92,   120,   121,    94,    43,     3,     4,     5,     6,
       3,     4,     5,     6,    52,   333,   125,    28,    43,    42,
     348,   180,    72,    73,   310,    62,    87,   144,    54,    40,
     121,   143,   172,   150,     3,   144,    86,    87,   316,    65,
     305,    79,   150,   183,   155,   185,    43,   143,    71,   145,
     147,   148,    75,   116,    79,    65,   174,   322,   108,   144,
     123,   143,    31,    52,    74,   150,     3,   150,   208,    58,
     188,   189,   190,   191,   192,   113,     3,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   118,    98,   113,    85,
     106,   101,   334,   204,    89,   145,   117,   135,   136,   143,
     111,   143,   118,   151,    81,   143,    92,    93,   171,   125,
     135,   136,     0,   151,   274,   146,   113,   228,   143,    65,
     113,     7,     8,     9,   214,    99,   151,   144,    74,   106,
     107,     3,   106,   150,    20,   143,   254,    10,   135,   136,
     145,    10,   135,   136,     3,    18,   143,   120,   125,    18,
     143,   125,    25,     6,   151,   101,    25,    30,   151,    29,
       7,     8,     9,   108,    37,    38,   144,    15,    37,    38,
     233,   289,   150,    46,    47,   225,   115,    46,    47,    52,
       7,     8,     9,    52,    57,   303,   151,   152,    57,   144,
      85,   144,    62,   256,    85,   150,    66,   150,   119,     7,
       8,     9,    72,    73,   344,   345,    92,    67,   144,    82,
     144,   144,   330,    82,     7,     8,     9,   150,     3,   144,
      90,    91,   124,   113,    97,   150,   144,   113,    97,     7,
       8,     9,   150,    77,    29,   121,   136,   137,   138,   139,
     143,   127,   305,   129,   130,    92,     8,     9,   134,   135,
     136,   137,   138,   139,    84,     3,    83,    85,    71,   106,
      43,     4,     3,   143,   102,    92,   113,    62,    85,   150,
     143,    66,   127,   150,   143,    49,    76,    72,    73,   116,
     127,   149,   129,   130,    92,   118,   113,   134,   135,   136,
     137,   138,   139,    89,   143,    90,    91,     3,    52,    92,
     127,   109,   129,   130,   143,   113,     3,   134,   135,   136,
     137,   138,   139,   144,    92,    84,     3,   143,   143,   127,
     113,   129,   130,   112,   144,    92,   134,   135,   136,   137,
     138,   139,   150,    64,   127,   106,   129,   130,   143,   143,
     139,   134,   135,   136,   137,   138,   139,    29,    72,   127,
     144,   129,   130,   144,    72,    90,   134,   135,   136,   137,
     138,   139,   119,   144,   150,   144,   124,   129,   130,   144,
      68,    56,   134,   135,   136,   137,   138,   139,    67,    39,
      62,   274,   111,   282,    66,    62,   205,   169,   228,   181,
      72,    73,   208,   321,    47,   321,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    18,    25,    30,    37,    38,    46,    47,    52,
      57,    82,    97,   143,   153,   154,   155,   156,   157,   158,
     159,   162,   169,   170,   171,   172,   173,   175,   178,   179,
     180,   182,    30,     3,   222,     3,     3,    65,    74,   101,
      85,    85,    89,   117,   193,   221,   222,    65,    74,   101,
      22,    54,    65,   179,   180,     0,   146,   230,    12,    42,
      71,    75,   181,   189,     3,   145,   143,   147,   148,     3,
     225,   120,   164,   164,   222,   108,   160,   222,     6,   214,
      15,   183,   115,   225,   222,   222,    85,    85,   144,   144,
     155,   119,   179,   182,    67,   194,     3,     4,     5,   151,
     196,   211,   212,   213,   214,   216,   156,   154,   124,   113,
     222,   222,    77,   186,    84,   143,   174,     3,    43,    79,
     113,   135,   136,   143,   184,   195,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   215,     3,   176,   177,    85,   222,   222,   190,   191,
     198,   189,   189,   214,   144,   150,   230,   222,    43,    85,
     143,   174,   198,   161,   212,     3,   231,    58,   180,   143,
     145,   143,   102,    43,   113,   199,   199,   180,   198,    85,
     185,   150,     3,   106,   118,   125,   223,   224,     7,     8,
       9,    20,    92,   113,   121,   127,   129,   130,   134,   135,
     136,   137,   138,   139,   127,   150,   186,   222,   150,    81,
     107,   192,   194,   194,    49,   211,   149,    76,   163,   116,
       3,    31,   165,   166,   118,    89,   144,   150,   143,   183,
       3,   180,   198,   143,   113,   144,   144,   143,   217,   218,
     220,   222,   226,   228,   186,   197,   198,     3,   198,   199,
     199,   199,   199,   199,    92,   121,   143,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   211,   177,   191,   214,
      61,    87,   143,   168,    84,    28,    40,    98,   111,   167,
     112,   144,   150,   178,   222,     3,   196,   195,   144,    99,
     180,   178,   150,   224,    29,    62,    66,    72,    73,    91,
     227,    64,   187,   106,   199,   143,   180,   195,   231,   161,
     143,   166,   144,   144,   199,   144,   144,   218,   219,    72,
      72,    90,   119,   199,   180,   195,   144,   144,   144,   231,
      83,   223,   224,   150,   143,   220,   228,   195,   144,   144,
     144,   199,   218,   178,   124,    45,   188,   109,   144,   198,
     229,   198,   223
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   152,   153,   154,   154,   155,   155,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   157,   157,   158,
     158,   159,   160,   161,   162,   162,   162,   162,   163,   163,
     163,   164,   164,   165,   165,   166,   166,   167,   167,   167,
     167,   168,   169,   169,   169,   169,   170,   170,   170,   171,
     172,   173,   173,   174,   174,   175,   176,   176,   177,   178,
     178,   179,   179,   180,   180,   180,   181,   181,   181,   182,
     183,   183,   184,   185,   186,   186,   187,   187,   188,   188,
     189,   189,   190,   190,   191,   192,   192,   192,   193,   193,
     194,   194,   194,   195,   195,   196,   196,   197,   198,   198,
     198,   198,   198,   198,   199,   199,   199,   199,   199,   199,
     200,   200,   200,   201,   201,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   203,   203,   204,   204,   204,   204,
     205,   206,   206,   207,   207,   207,   207,   207,   207,   208,
     209,   210,   210,   211,   211,   211,   212,   213,   213,   214,
     215,   216,   217,   217,   218,   218,   218,   219,   219,   220,
     221,   222,   222,   223,   223,   224,   224,   225,   226,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   228,   228,
     229,   230,   230,   231,   231
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     6,     2,
       5,     7,     1,     1,     8,     7,     7,     7,     2,     2,
       0,     3,     0,     1,     3,     5,     2,     1,     1,     1,
       1,     3,     3,     5,     3,     3,     2,     4,     4,     4,
       2,     8,     5,     3,     0,     5,     1,     3,     3,     1,
       1,     3,     3,     3,     5,     5,     1,     1,     1,     7,
       1,     0,     1,     2,     2,     0,     4,     0,     2,     0,
       3,     0,     1,     3,     2,     1,     1,     0,     2,     0,
       2,     4,     0,     1,     3,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     3,     5,     6,     5,     6,
       8,     4,     5,     3,     3,     3,     3,     3,     3,     5,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     1,     1,     3,     2,
       1,     1,     3,     2,     1,     1,     0,     1,     6,     1,
       1,     2,     2,     1,     1,     1,     1,     0,     4,     1,
       1,     1,     0,     1,     3
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
      yyerror (&yylloc, result, scanner, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if HSQL_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParserResult** result, yyscan_t scanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParserResult** result, yyscan_t scanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, result, scanner);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, hsql::SQLParserResult** result, yyscan_t scanner)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !HSQL_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !HSQL_DEBUG */


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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, hsql::SQLParserResult** result, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* IDENTIFIER  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 1599 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 4: /* STRING  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 1605 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 5: /* FLOATVAL  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1611 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 6: /* INTVAL  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1617 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 7: /* NOTEQUALS  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1623 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 8: /* LESSEQ  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1629 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 9: /* GREATEREQ  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1635 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 154: /* statement_list  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).stmt_list)); }
#line 1641 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 155: /* statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).statement)); }
#line 1647 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 156: /* preparable_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).statement)); }
#line 1653 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 157: /* prepare_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).prep_stmt)); }
#line 1659 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 158: /* execute_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).exec_stmt)); }
#line 1665 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 159: /* import_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).import_stmt)); }
#line 1671 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 160: /* import_file_type  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1677 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 161: /* file_path  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 1683 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 162: /* create_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).create_stmt)); }
#line 1689 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 163: /* opt_using_type  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1695 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 164: /* opt_not_exists  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1701 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 165: /* column_def_commalist  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).column_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).column_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).column_vec));
}
#line 1714 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 166: /* column_def  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).column_t)); }
#line 1720 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 167: /* column_type  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1726 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 168: /* column_list  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).str_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).str_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).str_vec));
}
#line 1739 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 169: /* drop_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).drop_stmt)); }
#line 1745 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 170: /* show_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).show_stmt)); }
#line 1751 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 171: /* delete_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).delete_stmt)); }
#line 1757 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 172: /* truncate_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).delete_stmt)); }
#line 1763 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 173: /* insert_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).insert_stmt)); }
#line 1769 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 174: /* opt_column_list  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).str_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).str_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).str_vec));
}
#line 1782 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 175: /* update_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).update_stmt)); }
#line 1788 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 176: /* update_clause_commalist  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).update_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).update_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).update_vec));
}
#line 1801 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 177: /* update_clause  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).update_t)); }
#line 1807 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 178: /* select_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1813 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 179: /* select_with_paren  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1819 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 180: /* select_no_paren  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1825 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 182: /* select_clause  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1831 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 183: /* opt_distinct  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1837 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 184: /* select_list  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1850 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 185: /* from_clause  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 1856 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 186: /* opt_where  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1862 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 187: /* opt_group  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).group_t)); }
#line 1868 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 188: /* opt_having  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1874 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 189: /* opt_order  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).order_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).order_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).order_vec));
}
#line 1887 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 190: /* order_list  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).order_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).order_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).order_vec));
}
#line 1900 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 191: /* order_desc  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).order)); }
#line 1906 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 192: /* opt_order_type  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1912 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 193: /* opt_top  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).limit)); }
#line 1918 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 194: /* opt_limit  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).limit)); }
#line 1924 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 195: /* expr_list  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1937 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 196: /* literal_list  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1950 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 197: /* expr_alias  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1956 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 198: /* expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1962 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 199: /* operand  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1968 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 200: /* scalar_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1974 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 201: /* unary_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1980 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 202: /* binary_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1986 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 203: /* logic_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1992 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 204: /* in_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1998 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 205: /* case_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2004 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 206: /* exists_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2010 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 207: /* comp_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2016 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 208: /* function_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2022 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 209: /* between_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2028 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 210: /* column_name  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2034 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 211: /* literal  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2040 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 212: /* string_literal  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2046 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 213: /* num_literal  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2052 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 214: /* int_literal  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2058 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 215: /* star_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2064 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 216: /* placeholder_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2070 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 217: /* table_ref  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2076 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 218: /* table_ref_atomic  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2082 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 219: /* table_ref_commalist  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).table_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).table_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).table_vec));
}
#line 2095 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 220: /* table_ref_name  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2101 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 221: /* table_ref_name_no_alias  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2107 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 222: /* table_name  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 2113 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 223: /* alias  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 2119 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 224: /* opt_alias  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 2125 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 225: /* index_name  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 2131 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 226: /* join_clause  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2137 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 227: /* opt_join_type  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 2143 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 228: /* join_table  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2149 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 229: /* join_condition  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2155 "bison_parser.cpp" /* yacc.c:1257  */
        break;

    case 231: /* ident_commalist  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).str_vec)) != NULL) {
		for (auto ptr : *(((*yyvaluep).str_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).str_vec));
}
#line 2168 "bison_parser.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (hsql::SQLParserResult** result, yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 78 "bison_parser.y" /* yacc.c:1436  */
{
	// Initialize
	yylloc.first_column = 0;
	yylloc.last_column = 0;
	yylloc.first_line = 0;
	yylloc.last_line = 0;
	yylloc.total_column = 0;
	yylloc.placeholder_id = 0;
}

#line 2287 "bison_parser.cpp" /* yacc.c:1436  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 249 "bison_parser.y" /* yacc.c:1661  */
    {
			*result = (yyvsp[-1].stmt_list);
		}
#line 2478 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 256 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.stmt_list) = new SQLParserResult((yyvsp[0].statement)); }
#line 2484 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 257 "bison_parser.y" /* yacc.c:1661  */
    { (yyvsp[-2].stmt_list)->addStatement((yyvsp[0].statement)); (yyval.stmt_list) = (yyvsp[-2].stmt_list); }
#line 2490 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 5:
#line 261 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyvsp[0].prep_stmt)->setPlaceholders(yyloc.placeholder_list);
			yyloc.placeholder_list.clear();
			(yyval.statement) = (yyvsp[0].prep_stmt);
		}
#line 2500 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 271 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.statement) = (yyvsp[0].select_stmt); }
#line 2506 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 272 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.statement) = (yyvsp[0].import_stmt); }
#line 2512 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 9:
#line 273 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.statement) = (yyvsp[0].create_stmt); }
#line 2518 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 274 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.statement) = (yyvsp[0].insert_stmt); }
#line 2524 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 275 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 2530 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 276 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 2536 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 13:
#line 277 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.statement) = (yyvsp[0].update_stmt); }
#line 2542 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 14:
#line 278 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.statement) = (yyvsp[0].drop_stmt); }
#line 2548 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 15:
#line 279 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.statement) = (yyvsp[0].show_stmt); }
#line 2554 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 280 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.statement) = (yyvsp[0].exec_stmt); }
#line 2560 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 288 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.prep_stmt) = new PrepareStatement();
			(yyval.prep_stmt)->name = (yyvsp[-2].sval);
			(yyval.prep_stmt)->query = new SQLParserResult((yyvsp[0].statement));
		}
#line 2570 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 293 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.prep_stmt) = new PrepareStatement();
			(yyval.prep_stmt)->name = (yyvsp[-4].sval);
			(yyval.prep_stmt)->query = (yyvsp[-2].stmt_list);
		}
#line 2580 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 19:
#line 301 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.exec_stmt) = new ExecuteStatement();
			(yyval.exec_stmt)->name = (yyvsp[0].sval);
		}
#line 2589 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 20:
#line 305 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.exec_stmt) = new ExecuteStatement();
			(yyval.exec_stmt)->name = (yyvsp[-3].sval);
			(yyval.exec_stmt)->parameters = (yyvsp[-1].expr_vec);
		}
#line 2599 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 21:
#line 317 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.import_stmt) = new ImportStatement((ImportStatement::ImportType) (yyvsp[-4].uval));
			(yyval.import_stmt)->filePath = (yyvsp[-2].sval);
			(yyval.import_stmt)->tableName = (yyvsp[0].sval);
		}
#line 2609 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 325 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.uval) = ImportStatement::kImportCSV; }
#line 2615 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 329 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.sval) = strdup((yyvsp[0].expr)->name); delete (yyvsp[0].expr); }
#line 2621 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 339 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.create_stmt) = new CreateStatement(CreateStatement::kTableFromTbl);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-5].bval);
			(yyval.create_stmt)->tableName = (yyvsp[-4].sval);
			(yyval.create_stmt)->filePath = (yyvsp[0].sval);
		}
#line 2632 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 345 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.create_stmt) = new CreateStatement(CreateStatement::kTable);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
			(yyval.create_stmt)->tableName = (yyvsp[-3].sval);
			(yyval.create_stmt)->columns = (yyvsp[-1].column_vec);
		}
#line 2643 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 351 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.create_stmt) = new CreateStatement(CreateStatement::kView);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
			(yyval.create_stmt)->tableName = (yyvsp[-3].sval);
			(yyval.create_stmt)->viewColumns = (yyvsp[-2].str_vec);
			(yyval.create_stmt)->select = (yyvsp[0].select_stmt);
		}
#line 2655 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 358 "bison_parser.y" /* yacc.c:1661  */
    {
	        (yyval.create_stmt) = new CreateStatement(CreateStatement::kIndex);
	        (yyval.create_stmt)->indexName = (yyvsp[-4].sval);
	        (yyval.create_stmt)->tableName = (yyvsp[-2].sval);
	        (yyval.create_stmt)->indexType = (yyvsp[-1].ssval);
	        (yyval.create_stmt)->indexColumns = (yyvsp[0].str_vec);
	    }
#line 2667 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 368 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.ssval) = "BTREE"; }
#line 2673 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 369 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.ssval) = "HASH"; }
#line 2679 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 370 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.ssval) = "BTREE"; }
#line 2685 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 373 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.bval) = true; }
#line 2691 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 374 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.bval) = false; }
#line 2697 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 378 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.column_vec) = new std::vector<ColumnDefinition*>(); (yyval.column_vec)->push_back((yyvsp[0].column_t)); }
#line 2703 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 379 "bison_parser.y" /* yacc.c:1661  */
    { (yyvsp[-2].column_vec)->push_back((yyvsp[0].column_t)); (yyval.column_vec) = (yyvsp[-2].column_vec); }
#line 2709 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 383 "bison_parser.y" /* yacc.c:1661  */
    {
	        (yyval.column_t) = new ColumnDefinition();
	        (yyval.column_t)->primaryKeyColumns = (yyvsp[-1].str_vec);
	    }
#line 2718 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 387 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.column_t) = new ColumnDefinition((yyvsp[-1].sval), (ColumnDefinition::DataType) (yyvsp[0].uval));
		}
#line 2726 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 393 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.uval) = ColumnDefinition::INT; }
#line 2732 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 394 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.uval) = ColumnDefinition::INT; }
#line 2738 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 395 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.uval) = ColumnDefinition::DOUBLE; }
#line 2744 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 396 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.uval) = ColumnDefinition::TEXT; }
#line 2750 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 400 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.str_vec) = (yyvsp[-1].str_vec); }
#line 2756 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 411 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.drop_stmt) = new DropStatement(DropStatement::kTable);
			(yyval.drop_stmt)->name = (yyvsp[0].sval);
		}
#line 2765 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 415 "bison_parser.y" /* yacc.c:1661  */
    {
	        (yyval.drop_stmt) = new DropStatement(DropStatement::kIndex);
	        (yyval.drop_stmt)->indexName = (yyvsp[-2].sval);
	        (yyval.drop_stmt)->name = (yyvsp[0].sval);
	    }
#line 2775 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 420 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.drop_stmt) = new DropStatement(DropStatement::kView);
			(yyval.drop_stmt)->name = (yyvsp[0].sval);
		}
#line 2784 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 424 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.drop_stmt) = new DropStatement(DropStatement::kPreparedStatement);
			(yyval.drop_stmt)->name = (yyvsp[0].sval);
		}
#line 2793 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 437 "bison_parser.y" /* yacc.c:1661  */
    {
            (yyval.show_stmt) = new ShowStatement(ShowStatement::kTables);
        }
#line 2801 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 440 "bison_parser.y" /* yacc.c:1661  */
    {
            (yyval.show_stmt) = new ShowStatement(ShowStatement::kColumns);
            (yyval.show_stmt)->tableName = (yyvsp[0].sval);
        }
#line 2810 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 445 "bison_parser.y" /* yacc.c:1661  */
    {
            (yyval.show_stmt) = new ShowStatement(ShowStatement::kIndex);
            (yyval.show_stmt)->tableName = (yyvsp[0].sval);
        }
#line 2819 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 457 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.delete_stmt) = new DeleteStatement();
			(yyval.delete_stmt)->tableName = (yyvsp[-1].sval);
			(yyval.delete_stmt)->expr = (yyvsp[0].expr);
		}
#line 2829 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 465 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.delete_stmt) = new DeleteStatement();
			(yyval.delete_stmt)->tableName = (yyvsp[0].sval);
		}
#line 2838 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 477 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.insert_stmt) = new InsertStatement(InsertStatement::kInsertValues);
			(yyval.insert_stmt)->tableName = (yyvsp[-5].sval);
			(yyval.insert_stmt)->columns = (yyvsp[-4].str_vec);
			(yyval.insert_stmt)->values = (yyvsp[-1].expr_vec);
		}
#line 2849 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 483 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.insert_stmt) = new InsertStatement(InsertStatement::kInsertSelect);
			(yyval.insert_stmt)->tableName = (yyvsp[-2].sval);
			(yyval.insert_stmt)->columns = (yyvsp[-1].str_vec);
			(yyval.insert_stmt)->select = (yyvsp[0].select_stmt);
		}
#line 2860 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 493 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.str_vec) = (yyvsp[-1].str_vec); }
#line 2866 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 494 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.str_vec) = NULL; }
#line 2872 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 504 "bison_parser.y" /* yacc.c:1661  */
    {
		(yyval.update_stmt) = new UpdateStatement();
		(yyval.update_stmt)->table = (yyvsp[-3].table);
		(yyval.update_stmt)->updates = (yyvsp[-1].update_vec);
		(yyval.update_stmt)->where = (yyvsp[0].expr);
	}
#line 2883 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 513 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.update_vec) = new std::vector<UpdateClause*>(); (yyval.update_vec)->push_back((yyvsp[0].update_t)); }
#line 2889 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 514 "bison_parser.y" /* yacc.c:1661  */
    { (yyvsp[-2].update_vec)->push_back((yyvsp[0].update_t)); (yyval.update_vec) = (yyvsp[-2].update_vec); }
#line 2895 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 518 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.update_t) = new UpdateClause();
			(yyval.update_t)->column = (yyvsp[-2].sval);
			(yyval.update_t)->value = (yyvsp[0].expr);
		}
#line 2905 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 535 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 2911 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 536 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 2917 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 540 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.select_stmt) = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order_vec);

			// Limit could have been set by TOP.
			if ((yyvsp[0].limit) != NULL) {
				delete (yyval.select_stmt)->limit;
				(yyval.select_stmt)->limit = (yyvsp[0].limit);
			}
		}
#line 2932 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 550 "bison_parser.y" /* yacc.c:1661  */
    {
			// TODO: allow multiple unions (through linked list)
			// TODO: capture type of set_operator
			// TODO: might overwrite order and limit of first select here
			(yyval.select_stmt) = (yyvsp[-4].select_stmt);
			(yyval.select_stmt)->unionSelect = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order_vec);

			// Limit could have been set by TOP.
			if ((yyvsp[0].limit) != NULL) {
				delete (yyval.select_stmt)->limit;
				(yyval.select_stmt)->limit = (yyvsp[0].limit);
			}
		}
#line 2951 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 564 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.select_stmt) = (yyvsp[-4].select_stmt);
			(yyval.select_stmt)->unionSelect = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order_vec);

			// Limit could have been set by TOP.
			if ((yyvsp[0].limit) != NULL) {
				delete (yyval.select_stmt)->limit;
				(yyval.select_stmt)->limit = (yyvsp[0].limit);
			}
		}
#line 2967 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 584 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.select_stmt) = new SelectStatement();
			(yyval.select_stmt)->limit = (yyvsp[-5].limit);
			(yyval.select_stmt)->selectDistinct = (yyvsp[-4].bval);
			(yyval.select_stmt)->selectList = (yyvsp[-3].expr_vec);
			(yyval.select_stmt)->fromTable = (yyvsp[-2].table);
			(yyval.select_stmt)->whereClause = (yyvsp[-1].expr);
			(yyval.select_stmt)->groupBy = (yyvsp[0].group_t);
		}
#line 2981 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 596 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.bval) = true; }
#line 2987 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 597 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.bval) = false; }
#line 2993 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 605 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.table) = (yyvsp[0].table); }
#line 2999 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 74:
#line 610 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 3005 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 611 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = NULL; }
#line 3011 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 615 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.group_t) = new GroupByDescription();
			(yyval.group_t)->columns = (yyvsp[-1].expr_vec);
			(yyval.group_t)->having = (yyvsp[0].expr);
		}
#line 3021 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 620 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.group_t) = NULL; }
#line 3027 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 624 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 3033 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 625 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = NULL; }
#line 3039 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 628 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.order_vec) = (yyvsp[0].order_vec); }
#line 3045 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 629 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.order_vec) = NULL; }
#line 3051 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 633 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.order_vec) = new std::vector<OrderDescription*>(); (yyval.order_vec)->push_back((yyvsp[0].order)); }
#line 3057 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 634 "bison_parser.y" /* yacc.c:1661  */
    { (yyvsp[-2].order_vec)->push_back((yyvsp[0].order)); (yyval.order_vec) = (yyvsp[-2].order_vec); }
#line 3063 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 638 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.order) = new OrderDescription((yyvsp[0].order_type), (yyvsp[-1].expr)); }
#line 3069 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 642 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.order_type) = kOrderAsc; }
#line 3075 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 86:
#line 643 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.order_type) = kOrderDesc; }
#line 3081 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 644 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.order_type) = kOrderAsc; }
#line 3087 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 650 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.limit) = new LimitDescription((yyvsp[0].expr)->ival, kNoOffset); delete (yyvsp[0].expr); }
#line 3093 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 651 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.limit) = NULL; }
#line 3099 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 655 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.limit) = new LimitDescription((yyvsp[0].expr)->ival, kNoOffset); delete (yyvsp[0].expr); }
#line 3105 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 656 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.limit) = new LimitDescription((yyvsp[-2].expr)->ival, (yyvsp[0].expr)->ival); delete (yyvsp[-2].expr); delete (yyvsp[0].expr); }
#line 3111 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 657 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.limit) = NULL; }
#line 3117 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 664 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 3123 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 665 "bison_parser.y" /* yacc.c:1661  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 3129 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 669 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 3135 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 670 "bison_parser.y" /* yacc.c:1661  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 3141 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 674 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.expr) = (yyvsp[-1].expr);
			(yyval.expr)->alias = (yyvsp[0].sval);
		}
#line 3150 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 690 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 3156 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 109:
#line 695 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeSelect((yyvsp[-1].select_stmt)); }
#line 3162 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 113:
#line 705 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpUnary(Expr::UMINUS, (yyvsp[0].expr)); }
#line 3168 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 114:
#line 706 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpUnary(Expr::NOT, (yyvsp[0].expr)); }
#line 3174 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 116:
#line 711 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '-', (yyvsp[0].expr)); }
#line 3180 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 117:
#line 712 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '+', (yyvsp[0].expr)); }
#line 3186 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 118:
#line 713 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '/', (yyvsp[0].expr)); }
#line 3192 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 119:
#line 714 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '*', (yyvsp[0].expr)); }
#line 3198 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 120:
#line 715 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '%', (yyvsp[0].expr)); }
#line 3204 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 121:
#line 716 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '^', (yyvsp[0].expr)); }
#line 3210 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 122:
#line 717 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::LIKE, (yyvsp[0].expr)); }
#line 3216 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 123:
#line 718 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-3].expr), Expr::NOT_LIKE, (yyvsp[0].expr)); }
#line 3222 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 124:
#line 722 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::AND, (yyvsp[0].expr)); }
#line 3228 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 125:
#line 723 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::OR, (yyvsp[0].expr)); }
#line 3234 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 126:
#line 727 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].expr_vec)); }
#line 3240 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 127:
#line 728 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpUnary(Expr::NOT, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].expr_vec))); }
#line 3246 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 128:
#line 729 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].select_stmt)); }
#line 3252 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 129:
#line 730 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpUnary(Expr::NOT, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].select_stmt))); }
#line 3258 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 130:
#line 735 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeCase((yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 3264 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 131:
#line 739 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeExists((yyvsp[-1].select_stmt)); }
#line 3270 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 132:
#line 740 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpUnary(Expr::NOT, Expr::makeExists((yyvsp[-1].select_stmt))); }
#line 3276 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 133:
#line 744 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '=', (yyvsp[0].expr)); }
#line 3282 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 134:
#line 745 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::NOT_EQUALS, (yyvsp[0].expr)); }
#line 3288 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 135:
#line 746 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '<', (yyvsp[0].expr)); }
#line 3294 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 136:
#line 747 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '>', (yyvsp[0].expr)); }
#line 3300 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 137:
#line 748 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::LESS_EQ, (yyvsp[0].expr)); }
#line 3306 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 138:
#line 749 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::GREATER_EQ, (yyvsp[0].expr)); }
#line 3312 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 139:
#line 753 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-4].sval), (yyvsp[-1].expr_vec), (yyvsp[-2].bval)); }
#line 3318 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 140:
#line 757 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeBetween((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3324 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 141:
#line 761 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeColumnRef((yyvsp[0].sval)); }
#line 3330 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 142:
#line 762 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeColumnRef((yyvsp[-2].sval), (yyvsp[0].sval)); }
#line 3336 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 146:
#line 772 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].sval)); }
#line 3342 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 147:
#line 777 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].fval)); }
#line 3348 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 149:
#line 782 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].ival)); }
#line 3354 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 150:
#line 786 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.expr) = new Expr(kExprStar); }
#line 3360 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 151:
#line 790 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.expr) = Expr::makePlaceholder(yylloc.total_column);
			yyloc.placeholder_list.push_back((yyval.expr));
		}
#line 3369 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 153:
#line 802 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyvsp[0].table_vec)->push_back((yyvsp[-2].table));
			auto tbl = new TableRef(kTableCrossProduct);
			tbl->list = (yyvsp[0].table_vec);
			(yyval.table) = tbl;
		}
#line 3380 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 155:
#line 813 "bison_parser.y" /* yacc.c:1661  */
    {
			auto tbl = new TableRef(kTableSelect);
			tbl->select = (yyvsp[-2].select_stmt);
			tbl->alias = (yyvsp[0].sval);
			(yyval.table) = tbl;
		}
#line 3391 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 157:
#line 824 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.table_vec) = new std::vector<TableRef*>(); (yyval.table_vec)->push_back((yyvsp[0].table)); }
#line 3397 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 158:
#line 825 "bison_parser.y" /* yacc.c:1661  */
    { (yyvsp[-2].table_vec)->push_back((yyvsp[0].table)); (yyval.table_vec) = (yyvsp[-2].table_vec); }
#line 3403 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 159:
#line 830 "bison_parser.y" /* yacc.c:1661  */
    {
			auto tbl = new TableRef(kTableName);
			tbl->name = (yyvsp[-1].sval);
			tbl->alias = (yyvsp[0].sval);
			(yyval.table) = tbl;
		}
#line 3414 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 160:
#line 840 "bison_parser.y" /* yacc.c:1661  */
    {
			(yyval.table) = new TableRef(kTableName);
			(yyval.table)->name = (yyvsp[0].sval);
		}
#line 3423 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 163:
#line 853 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 3429 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 166:
#line 859 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.sval) = NULL; }
#line 3435 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 168:
#line 871 "bison_parser.y" /* yacc.c:1661  */
    { 
			(yyval.table) = new TableRef(kTableJoin);
			(yyval.table)->join = new JoinDefinition();
			(yyval.table)->join->type = (JoinType) (yyvsp[-4].uval);
			(yyval.table)->join->left = (yyvsp[-5].table);
			(yyval.table)->join->right = (yyvsp[-2].table);
			(yyval.table)->join->condition = (yyvsp[0].expr);
		}
#line 3448 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 169:
#line 882 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.uval) = kJoinInner; }
#line 3454 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 170:
#line 883 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.uval) = kJoinOuter; }
#line 3460 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 171:
#line 884 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.uval) = kJoinLeftOuter; }
#line 3466 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 172:
#line 885 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.uval) = kJoinRightOuter; }
#line 3472 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 173:
#line 886 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.uval) = kJoinLeft; }
#line 3478 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 174:
#line 887 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.uval) = kJoinRight; }
#line 3484 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 175:
#line 888 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.uval) = kJoinCross; }
#line 3490 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 176:
#line 889 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.uval) = kJoinNatural; }
#line 3496 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 177:
#line 890 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.uval) = kJoinInner; }
#line 3502 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 178:
#line 896 "bison_parser.y" /* yacc.c:1661  */
    {
			auto tbl = new TableRef(kTableSelect);
			tbl->select = (yyvsp[-2].select_stmt);
			tbl->alias = (yyvsp[0].sval);
			(yyval.table) = tbl;
		}
#line 3513 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 183:
#line 921 "bison_parser.y" /* yacc.c:1661  */
    { (yyval.str_vec) = new std::vector<char*>(); (yyval.str_vec)->push_back((yyvsp[0].sval)); }
#line 3519 "bison_parser.cpp" /* yacc.c:1661  */
    break;

  case 184:
#line 922 "bison_parser.y" /* yacc.c:1661  */
    { (yyvsp[-2].str_vec)->push_back((yyvsp[0].sval)); (yyval.str_vec) = (yyvsp[-2].str_vec); }
#line 3525 "bison_parser.cpp" /* yacc.c:1661  */
    break;


#line 3529 "bison_parser.cpp" /* yacc.c:1661  */
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
  *++yylsp = yyloc;

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
      yyerror (&yylloc, result, scanner, YY_("syntax error"));
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
        yyerror (&yylloc, result, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, result, scanner);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, result, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, result, scanner);
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
#line 925 "bison_parser.y" /* yacc.c:1906  */

/*********************************
 ** Section 4: Additional C code
 *********************************/

/* empty */

