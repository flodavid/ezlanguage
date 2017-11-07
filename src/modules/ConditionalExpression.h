#ifndef CONDITIONALEXPRESSION_H
#define CONDITIONALEXPRESSION_H

#include <string>
#include "Node.h"
#include "../addons/String_addon.h"

/**
 * @brief Represent a node of the tree which will traduct a condtional expression such as : (a and b) or (b or c)
 * @author Antoine GARNIER && Valentin GINISTY
 */
class ConditionalExpression : public Node {

private:
    std::string operateur;
    std::string valeur;
    const ConditionalExpression * left_part;
    const ConditionalExpression * right_part;

public:

    /**
     * @brief Constructor
     * @param left : left son
     * @param right : right son
     * @param operateur_unaire : unary operator (with one parameter)
     * @param operande : conditionnal expression
     */
    ConditionalExpression(Node * left, Node * right, const std::string & operateur_unaire, const ConditionalExpression* operande);

    /**
     * @brief Constructor
     * @param left : left son
     * @param right : right son
     * @param operateur_unaire : binary operator (with two parameters)
     * @param left_operande : conditionnal expression which is the first operand
     * @param right_operande : conditionnal expression which is the second operand
     */
    ConditionalExpression(Node * left, Node * right, const std::string & operateur_binaire, const ConditionalExpression* left_operande, const ConditionalExpression* right_operande);

    /**
     * @brief Constructor
     * @param left : left son
     * @param right : right son
     * @param operande : value of the expression
     */
    ConditionalExpression(Node * left, Node * right, const std::string & operande);

    /**
     * @brief Translate the begining part of the Forall
     * @return a string containing the C++ code of the node
     */

    virtual std::string preTranslate() const;
};

#endif
