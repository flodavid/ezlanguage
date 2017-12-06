#ifndef OPERATION_H
#define OPERATION_H

#define UNARY 1
#define BINARY 2

enum operatorType { ARITHMETIC, BITWISE, RELATIONAL, LOGICAL, ALLOCATION, INCREMENT };
// @see Create subclasses for each operator type ?
// TODO for the moment, only the arithmetic and relational (comparison) operators will be implemented

#include "../modules/Node.h"

/**
 * @brief 
 * @author : GARNIER Antoine
 * 
 * Operators that need the value which they affect (abs for example),
 * pass it by addind a left son
 */
class Operation : public Node{

protected:
    //in the yacc file, "Operator(LOGICAL, "and")" could be called, given the appropriate token
    // int ope_nb; //operand's number, 1 = unary operator, 2 = binary operator...etc
    // int ope_type; //operator's type (1 : logical, 2 : arithmetic, 3 : allocation, 4 : comparison...etc)
    std::string opeChars; //operator's charcters

public:
    //constructors
    Operation(const std::string & ope);
    

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Operation"; }

    /**
     * @brief Translate the begining part of the Operator
     * @return a string containing the C++ code of the node
     *
     * All subclasses, must reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;

        
    /**
     * @brief Translate the begining part of the Operator
     * @return a string containing the C++ code of the node
     *
     * All subclasses, must reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string postTranslate() const;
};


#endif //OPERATEUR_H
