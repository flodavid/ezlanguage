#pragma once

#include "Expression.h"
#include "FunctionCall.h"

/**
 * @brief Node of the tree which represent the call to a function, interpreted as an expression
 * The call is done without object, on another function call, or an object given its name
 */
class FunctionCallExpression : public FunctionCall, public Expression {
	
public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor by copying the superclass
     */
    FunctionCallExpression(FunctionCall* callToTransform);

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Function call expression"; }
    
    /* * * * * * * *
     * Translation *
     * * * * * * * */
    
    /**
     * @brief Translate the begining part of the function call
     * @return a string containing the C++ code of the function call
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;
};
