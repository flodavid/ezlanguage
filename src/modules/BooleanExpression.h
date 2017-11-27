#ifndef BOOLEANEXPRESSION_H
#define BOOLEANEXPRESSION_H

#include <string>

#include "../addons/String_addon.h"
#include "ConditionalExpression.h"
#include "TranslatedNode.h"

/**
 * @brief Represent a node of the tree which will traduct a expression such as:
 * + (a and b) or (b or c)
 * + boolean variable
 * + ! a
 */
class BooleanExpression : public ConditionalExpression {

private:
    std::string strOperator;
    std::string value;
    // The nodes should be a ConditionalExpression or expression (as string in TranslatedNode)
    const Node * left_part; 
    const Node * right_part;

public:
    /**
     * @brief Variable constructor
     * @param operande : name of the variable
     */
    BooleanExpression(const std::string & operande);

    /**
     * @brief Unary operation constructor
     * @param unary_operator : unary operator (with one parameter)
     * @param operande : conditionnal expression
     */
    BooleanExpression(const std::string & unary_operator, const ConditionalExpression* operande);

    /**
     * @brief Constructor with logical operation between two expression
     * @param binary_operator : binary operator (with two parameters)
     * @param first_operande : conditionnal expression which is the first operand
     * @param second_operande : conditionnal expression which is the second operand
     */
    BooleanExpression(const std::string & binary_operator, const ConditionalExpression* first_operande,
                        const ConditionalExpression* second_operande);

    /**
     * @brief Expressions relation constructor
     * @param relational_operator : a relational operator (comparison)
     * @param first_expression : the first expression
     * @param second_expression : the second expression
     */
    BooleanExpression(const std::string & relational_operator, const TranslatedNode* first_expression,
                        const TranslatedNode* second_expression);

    /**
     * @brief Translate the begining part
     * @return a string containing the C++ code of the node
     */
    virtual std::string preTranslate() const;
};

#endif