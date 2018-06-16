#pragma once

#include "../modules/Node.h"

/**
 * @brief Generic declaration of any instruction
 */
class Instruction : public Node {

private:
    static unsigned sIndentation;
    static std::string indent_sequence;

public:

    /**
     * @brief : Constructor
     * @param left : left son
     * @param indent : number of space of the instruction
     * 
     * Right son is set to null
     */
    Instruction(Node * left);


    /**
     * Add one indentation level to the instruction indentation (4 spaces by default)
     */
    void indent() const { ++sIndentation; }
    
    /**
     * Remove one indentation level to the instruction indentation (4 spaces by default)
     */
    void unindent() const { --sIndentation; }

    /**
     * @brief Get some details about the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string details() const { return sIndentation +" spaces"; }
    
protected:
    /**
     * Remove one indentation level to the instruction indentation (4 spaces by default)
     */
    std::string getIndentation() const;
};
