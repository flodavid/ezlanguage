#ifndef CONDITIONALEXPRESSION_H
#define CONDITIONALEXPRESSION_H

#include <string>
#include "Node.h"

/**
 * @brief Represent a node of the tree which will traduct a condtional expression such as : (a and b) or (b or c)
 * @author Antoine GARNIER && Valentin GINISTY
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
