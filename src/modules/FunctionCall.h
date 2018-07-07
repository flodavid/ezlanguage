#pragma once

#include "Node.h"
#include "Expression.h"

/**
 * @brief Node of the tree which represent the call to a function
 * The call is done without object, on another function call, or an object given its name
 * @see can be an instruction or not (expression, so a module), should we create to classes ? One as expression, that is an instruction. (If so, should all instruction automatically end with ";\n" ?)
 */
class FunctionCall : public Node {

protected:
    std::string mObjectName;
    std::string mFunctionName;
    Expression* mArguments;
    bool mHasAnOtherFunctionCall;
	
public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor with facultative object name
     */
    FunctionCall(const std::string & functionName, Expression * arguments,
            const std::string & objectName = "");

    /**
     * Copy constructor. Other class is deleted in the process
     */
    FunctionCall(FunctionCall * other);

    
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
