#ifndef REPEAT_H
#define REPEAT_H

//special files no to forget to import
#include "Node.h"

/**
 * @brief Represent a node of the tree whcih will traduct the loop repeat (do ... while in c++)
 * 
 * @details Using :
 * repeat
 *    instruction_1
 *    instruction_2
 *    ...
 *    instruction_n
 * until condition
 * 
 * @author Antoine GARNIER
 */
class Repeat : public Node {
	
protected:
	Node * condition;

public:
    
    /**
     * @brief constructor with parameters
     * @param left : left son
     * @param right : right son
     * @param cond : condition of the loop
     */
    Repeat(Node * left, Node* right , Node * cond);
    
    /**
     * @brief Translate the begining part of the Repeat
     * @return a string containing the C++ code of the instruction
     */
    virtual std::string preTranslate() const;
    
    /**
     * @brief Translate the end part of the Repeat
     * @return a string containing the C++ code of the instruction
     */
    virtual std::string postTranslate() const;

};
#endif
