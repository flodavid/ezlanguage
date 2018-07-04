#pragma once

#include "../modules/Node.h"

/**
 * @brief Generic declaration of any instruction
 * 
 * All subclasses must implement preTranslate() method and may implement postTranslate() method.
 * Use of the indentationText() method before each line of the translation is advised
 * 
 * If your subclasse contains instructions that should be over-indented, use the indent() method
 * at the end of your preTranslate() definition, use unindent() at the beginning of your
 * postTranslate() definition.
 */
class Instruction : public Node {

private:
    static int sIndentation;
    static std::string indent_sequence;

public:

    /**
     * @brief : Constructor
     * @param left : left son
     * @param right : right son
     * 
     * Right son is set to null by default
     */
    Instruction(Node * left, Node * right = nullptr);


    /**
     * Add one indentation level to the instruction indentation (4 spaces by default)
     */
    static void indent() { ++sIndentation; }
    
    /**
     * Remove one indentation level to the instruction indentation (4 spaces by default)
     */
    static void unindent() { --sIndentation; }

    /**
     * @brief Get some details about the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string details() const { return sIndentation +" spaces"; }
    
protected:
    /**
     * Get text containing the spaces corresponding to the current indentation level
     */
    std::string indentationText() const;
};
