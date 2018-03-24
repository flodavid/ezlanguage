#pragma once

#include "../modules/Expression.h"

/**
 * @brief Node of the tree which represent a condition else
 * The call is done without object, on another function call, or an object given its name
 */

class FunctionCall : public Expression {

protected:
    std::string mObjectName;
    std::string mFunctionName;
    Expression* mArguments;
    bool mHasAnOtherFunctionCall;
    bool mIsInstruction;
	
public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor with object name
     */
    FunctionCall(const std::string & functionName, Expression * arguments);

    /**
     * Constructor with an object
     */
    FunctionCall(const std::string & objectName, const std::string & functionName, 
                Expression * arguments);
    
    /**
     * @brief destructor
     */
    virtual ~FunctionCall();


    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Function call"; }

    /**
     * @brief Add the object on which the function is called
     */
    inline void addObject(const std::string & objectName) { mObjectName= objectName; }

    /**
     * @brief Juxtapose another function call after the current
     * The function call added should not be called on an object
     */
    void addFunctionCall(FunctionCall* otherFunctionCall);

    /**
     * @brief Define the instruction as not an instruction, but simple expression
     */
    inline void setAsNotInstruction() { mIsInstruction= false; }

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

};
