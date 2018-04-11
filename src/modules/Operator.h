#ifndef OPERATION_H
#define OPERATION_H

#define UNARY 1
#define BINARY 2

// enum operatorType { ARITHMETIC, BITWISE, RELATIONAL, LOGICAL, ALLOCATION, INCREMENT };
// @see Create subclasses for each operator type ?
// TODO for the moment, only the arithmetic and relational (comparison) operators will be implemented

#include "../modules/Node.h"
#include "Expression.h"

/**
 * @brief 
 * @author : 
 * 
 * Operators that need the value which they affect (abs for example),
 * pass it by addind a left son
 * @see old code may need to be removed
 * 
 * @note We could create RelationalOperator and LogicalOperator classes in order to
 * have more precise type checking. Or use the operatorType enum
 */
class Operator : public Node {

protected:
    //in the yacc file, "Operator(LOGICAL, "and")" could be called, given the appropriate token
    // int ope_nb; //operand's number, 1 = unary operator, 2 = binary operator...etc
    // int ope_type; //operator's type (1 : logical, 2 : arithmetic, 3 : allocation, 4 : comparison...etc)
    std::string mOpeChars; //operator's characters

public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor with parameters
     * @param ope : string representing the operator
     */
    Operator(const std::string & ope, Expression * right_operande = nullptr);
    

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Operator"; }

    /**
     * @brief Adds an equals sign to set as affectation operator
     * @return false if there already was two characters in the operator or was malformed
     */
    bool setAsAffectation();

    /**
     * @brief Translate the begining part of the Operator
     * @return a string containing the C++ code of the node
     *
     * All subclasses, must reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;

};


#endif //OPERATEUR_H
