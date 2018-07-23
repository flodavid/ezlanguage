#ifndef WHILE_H
#define WHILE_H

#include "Instruction.h"
#include "../modules/ConditionalExpression.h"

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
class While : public Instruction {
    
protected:
    ConditionalExpression * mCondition;
    
public:
    
    /**
     * @brief constructor with parameters
     * @param left : left son
     * @param right : right son
     * @param cond : condition of the loop
     */
    While(ConditionalExpression * cond, Node * instructions);

    /**
     * @brief destructor
     */
    virtual ~While();
        

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "While"; }

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
