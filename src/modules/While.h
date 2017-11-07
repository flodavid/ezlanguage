#ifndef WHILE_H
#define WHILE_H

#include "Node.h"

/**
 * @brief Represent a node of the tree which will traduct the loop while
 * @details Using :
 * while condition do
 *    instruction_1
 *    instruction_2
 *    ...
 *    instruction_n
 * end while
 * 
 * @author Antoine GARNIER
 */
class While : public Node {
	
protected:
	Node * condition;
	
public:
    
	/**
     * @brief constructor with parameters
     * @param left : left son
     * @param right : right son
     * @param cond : condition of the loop
     */
    While(Node * left, Node * right, Node * cond);


    
    /*** Translations ***/
    
    /**
     * @brief Translate the begining part of the While
     * @return a string containing the C++ code of the instruction
     */
    virtual std::string preTranslate() const;
    
    /**
     * @brief Translate the end part of the While
     * @return a string containing the C++ code of the instruction
     */
    virtual std::string postTranslate() const;
};

#endif
