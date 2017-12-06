#ifndef GLOBAL_H
#define GLOBAL_H

#include "./addons/log.h"
#include "./modules/Node.h"
#include "./modules/TranslatedNode.h"
#include "./modules/ConditionalExpression.h"
#include "./declarations/Variable.h"
#include "./declarations/Parameter.h"
#include "./hash_table/VariableHashed.h"
#include "./hash_table/ScopeHashTable.h"
#include <vector>
#include <string>

extern ScopeHashTable symbolTable;

/**
 * @struct s_mon_type used to exchange value between flex and bison during parsing
 * @authors Valérian De Leeuw, Florentin Noël
 */
typedef struct s_mon_type {
    int numerical_value;
    double real_value;
    bool boolean;
    std::string texte;
    Node* tree;
    std::vector<VariableHashed> vectString;
    // TODO change as pointer or reference
    Variable* var;
    Expression* expr;
    ConditionalExpression* condExpr;
    TranslatedNode* transNode;
//    MaClasse	une_maclasse;
} mon_type;

typedef struct yyltype
{
  int first_line;
  int first_column;

  int last_line;
  int last_column;
} YYLTYPE;
# define YYLTYPE_IS_DECLARED 1 /* alert the parser that we have our own definition */

# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                 \
      if (N)                                                           \
        {                                                              \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;       \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;     \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;        \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;      \
          (Current).filename     = YYRHSLOC (Rhs, 1).filename;         \
        }                                                              \
      else                                                             \
        { /* empty RHS */                                              \
          (Current).first_line   = (Current).last_line   =             \
            YYRHSLOC (Rhs, 0).last_line;                               \
          (Current).first_column = (Current).last_column =             \
            YYRHSLOC (Rhs, 0).last_column;                             \
          (Current).filename  = NULL;                        /* new */ \
        }                                                              \
    while (0)

#define YYSTYPE mon_type
extern YYSTYPE yylval;


#endif
