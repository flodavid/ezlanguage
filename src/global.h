#ifndef GLOBAL_H
#define GLOBAL_H


#include "./addons/log.h"
#include "./modules/Node.h"

#include "./modules/ConditionalExpression.h"
#include "./modules/Expression.h"
#include "./modules/Operator.h"
#include "./modules/TranslatedNode.h"

#include "./declarations/Array.h"
#include "./declarations/Class.h"
#include "./declarations/Container.h"
#include "./declarations/Parameter.h"
#include "./declarations/Variable.h"

#include "./instructions/Affectation.h"
#include "./instructions/Else.h"
#include "./instructions/If.h"
#include "./instructions/FunctionCall.h"
#include "./instructions/Return.h"
#include "./hash_table/VariableHashed.h"
#include "./hash_table/ScopeHashTable.h"
#include <string>

extern ScopeHashTable symbolTable;

/**
 * @struct s_node_types used to exchange value between flex and bison during parsing
 * @authors Valérian De Leeuw, Florentin Noël
 */
typedef struct s_node_types {
    int numerical_value;
    double real_value;
    bool boolean;
    std::string text;
    // Modules
    Node* tree;
    ConditionalExpression* condExpr;
    Expression* expr;
    Operator* opeNode;
    TranslatedNode* transNode;
    // Declarations
    Array* array;
    Class* classNode;
    Container* cont;
    Variable* var;
    // Instructions
    Affectation* affectation;
    Else* elseNode;
    If* ifNode;
    FunctionCall* functionCall;
    Return* returnNode;
} node_types;

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

#define YYSTYPE node_types
extern YYSTYPE yylval;


#endif
