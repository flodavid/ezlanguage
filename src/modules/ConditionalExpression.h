#ifndef CONDITIONALEXPRESSION_H
#define CONDITIONALEXPRESSION_H

#include <string>
#include "Node.h"

/**
 * @brief Represent a node of the tree which will traduct any type of conditional expression
 * It is an abstract class
 */
class ConditionalExpression : public Node {

public:
    /**
     * @brief Constructor
     * @param left : left son
     * @param operande : value of the expression
     */
    ConditionalExpression(Node* left, Node* right, const std::string & _name = "");
};

#endif
