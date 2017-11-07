#ifndef GLOBAL_H
#define GLOBAL_H

/**
 * @struct s_mon_type used to exchange value between flex and bison during parsing
 * @authors Valérian De Leeuw, Florentin Noël
 */
typedef struct s_mon_type {
    int numerical_value;
    double real_value;
    bool booleen;
    std::string texte;
//    MaClasse	une_maclasse;
} mon_type;

#define YYSTYPE mon_type
extern YYSTYPE yylval;


#endif
