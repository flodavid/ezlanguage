#ifndef BOOLEANEXPRESSION_H
#define BOOLEANEXPRESSION_H

#include <string>
#include "ConditionalExpression.h"
#include "../addons/String_addon.h"

/**
 * @brief Represent a node of the tree which will traduct a condtional expression such as : (a and b) or (b or c)
 * @author Antoine GARNIER && Valentin GINISTY
 */
class BooleanExpression : public ConditionalExpression {

private:
    std::string strOperator;
    std::string value;
    const ConditionalExpression * left_part;
    const ConditionalExpression * right_part;

public:
    /**
     * @brief Constructor
     * @param left : left son
     * @param operande : value of the expression
     */
    BooleanExpression(const std::string & operande);

    /**
     * @brief Constructor
     * @param left : left son
     * @param operateur_unaire : unary operator (with one parameter)
     * @param operande : conditionnal expression
     */
    BooleanExpression(const std::string & unary_operator, const ConditionalExpression* operande);

    /**
     * @brief Constructor
     * @param left : left son
     * @param operateur_unaire : binary operator (with two parameters)
     * @param left_operande : conditionnal expression which is the first operand
     * @param right_operande : conditionnal expression which is the second operand
     */
    BooleanExpression(const std::string & binary_operator, const ConditionalExpression* first_operande,
                        const ConditionalExpression* second_operande);

    /**
     * @brief Translate the begining part of the Forall
     * @return a string containing the C++ code of the node
     */

    virtual std::string preTranslate() const;
};

#endif
