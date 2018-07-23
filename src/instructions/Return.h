#pragma once

#include "Instruction.h"
#include "../modules/Expression.h"

/**
 * @brief Node of the tree which represent a condition else
 */

class Return : public Instruction {

protected:
	Expression * mExpression;
	
public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor with parameters
     * @param left : left son
     * @param expression: the expression returned
     */
    Return(Expression * expression);
        
    /**
     * @brief destructor
     */
    virtual ~Return();


    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Return"; }

    /* * * * * * * *
     * Translation *
     * * * * * * * */
    
    /**
     * @brief Translate the a return statement
     * @return a string containing the C++ code of the Return
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;

};
