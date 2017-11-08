#ifndef GLOBAL_H
#define GLOBAL_H


#include "./modules/Node.h"
#include "./hash_table/Variable.h"
#include "./hash_table/ScopeHashTable.h"
#include <vector>

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
    vector<Variable> vecString;
//    MaClasse	une_maclasse;
} mon_type;

#define YYSTYPE mon_type
extern YYSTYPE yylval;


#endif
