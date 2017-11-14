#ifndef PROGRAM_H
#define PROGRAM_H

//special files no to forget to import
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
     * @param right : right son
     * @param prg_name : name of the program
     */
    Program(Node* right, std::string prg_name);
    
    /**
     * @brief Translate the begining part of the Repeat
     * @return a string containing the C++ code of the instruction
     */
    virtual std::string preTranslate() const;

};
#endif
