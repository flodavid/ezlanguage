#ifndef PROGRAM_H
#define PROGRAM_H

//special files no to forget to import
#include "../addons/debug.h"
#include "Node.h"

/**
 * @brief Represent the root node of the tree
 * 
 * @author Florian DAVID
 */
class Program : public Node {
	
public:
    
    /**
     * @brief constructor with parameters
     * @param left : left son
     * @param right : right son
     * @param cond : condition of the loop
     */
    Program(Node* right, std::string prg_name);
    
    /**
     * @brief Translate the begining part of the Repeat
     * @return a string containing the C++ code of the instruction
     */
    virtual std::string preTranslate() const;

};
#endif
