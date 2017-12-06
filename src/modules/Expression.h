#pragma once

#include <string>
#include "Node.h"

/**
 * @brief Represent a node of the tree which will traduct any type of expression
 * It is an abstract class @see for now ?
 */
class Expression : public Node {

public:
    /**
     * @brief Default constructor
     * @param operande : value of the expression
     */
    Expression();
    
    /**
     * @brief Constructor
     * @param left : left son
     * @param right : right son
     */
    Expression(Node* left, Node* right);
};
