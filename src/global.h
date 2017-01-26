#ifndef GLOBAL_H
#define GLOBAL_H

#include "./modules/Node.h"
#include "./modules/Variable.h"
#include "./modules/ScopeHashTable.h"
#include <vector>

typedef struct s_mon_type {
    int numerical_value;
    double reel_value;
    bool booleen;
    std::string texte;
    Node* arbre;
    vector<Variable> vecString;
//    MaClasse	une_maclasse;
} mon_type;

#define YYSTYPE mon_type
extern YYSTYPE yylval;
extern ScopeHashTable symbolTable;

#endif
