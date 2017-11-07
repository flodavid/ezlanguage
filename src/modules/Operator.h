#ifndef OPERATOR_H
#define OPERATOR_H

#define UNARY 1
#define BINARY 2

#define LOGICAL 1
#define ARITHMETIC 2
#define ALLOCATION 3
#define COMPARISON 4
#define INCREMENT 5

#include "Node.h"

/**
 * @brief 
 * @author : GARNIER Antoine
 * 
 */
class Operator : public Node{

protected:
    //in the yacc file, "Operator(LOGICAL, "and")" could be called, given the appropriate token
    int ope_nb; //operand's number, 1 = unary operator, 2 = binary operator...etc
    int ope_type; //operator's type (1 : logical, 2 : arithmetic, 3 : allocation, 4 : comparison...etc)
    std::string ope; //operator's value

    std::string operande_1, operande_2;

public:
    //constructors
    Operator();
    Operator(int ope_type, std::string ope);
    Operator(int ope_nb, int ope_type, std::string ope, std::string ope_1, std::string ope_2);

    std::string getOperande_1() const { return operande_1; }
    std::string getOperande_2() const { return operande_2; }
    
    /**
     * @brief Translate the begining part of the Operator
     * @return a string containing the C++ code of the node
     *
     * All subclasses, must reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const =0;
};


#endif //OPERATEUR_H
