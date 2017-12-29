#ifndef CONDITIONALEXPRESSION_H
#define CONDITIONALEXPRESSION_H

#include <string>
#include "Expression.h"

/**
 * @brief Represent a node of the tree which will traduct any type of conditional expression
 * It is an abstract class
 */
class ConditionalExpression : public Expression {

public:
    /**
     * @brief Default constructor
     * @param left : left son
     * @param operande : value of the expression
     */
    ConditionalExpression();
    
    /**
     * @brief Constructor
     * @param left : left son
     * @param operande : value of the expression
     */
    ConditionalExpression(Node* left, Node* right);
    

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Conditional expression"; }
};

#endif
