#ifndef GLOBAL_H
#define GLOBAL_H

#include "./addons/debug.h"
#include "./modules/Node.h"
#include "./hash_table/VariableHashed.h"
#include "./hash_table/ScopeHashTable.h"
#include <vector>
#include <string>

/**
 * @struct s_mon_type used to exchange value between flex and bison during parsing
 * @authors Valérian De Leeuw, Florentin Noël
 */
extern ScopeHashTable symbolTable;

typedef struct s_mon_type {
    int numerical_value;
    double real_value;
    bool booleen;
    std::string texte;
    Node* arbre;
    vector<VariableHashed> vecString;
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
