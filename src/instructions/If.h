#pragma once

#include "Instruction.h"
#include "Else.h"
#include "../modules/ConditionalExpression.h"

/**
 * @brief Node of the tree which represent a If: branching on condition
 */

class If : public Instruction {

protected:
    ConditionalExpression * mCondition;
    bool mHasElse;

public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor of if with an else
     * @param instructions : instructions contained by the if
     * @param elseNode : Else node and its instructions
     * @param condition : the condition of the if
     */
    If(Instruction * instructions, Else * elseNode, ConditionalExpression * condition);

    /**
     * Constructor of if without else
     * @param instructions : instructions contained by the if
     * @param condition : the condition of the if
     */
    If(Instruction * instructions, ConditionalExpression * condition);
        
    /**
     * @brief destructor
     */
    virtual ~If();


    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "If"; }

    /* * * * * * * *
     * Translation *
     * * * * * * * */
    
    /**
     * @brief Translate the begining part of the If
     * @return a string containing the C++ code of the If
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;
    
    /**
     * @brief Translate the end part of the If
     * @return a string containing the C++ code of the If
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string postTranslate() const;

};
