#pragma once

#include "../modules/Node.h"

/**
 * @brief Statement to ask an input for the user
 */
class Input : public Instruction {

public:

    /**
     * @brief : Constructor
     * @param left : left son
     * @param right : right son
     * 
     * Right son is set to null by default
     */
    Input(Node * left, Node * right = nullptr);
    
protected:
    /**
     * Get text containing the spaces corresponding to the current indentation level
     */
    std::string indentationText() const;
};
