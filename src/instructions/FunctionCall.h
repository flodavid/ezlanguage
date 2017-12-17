#pragma once

#include "../modules/Node.h"

/**
 * @brief Node of the tree which represent a condition else
 */

class FunctionCall : public Node {

protected:
    std::string mFunctionName;
    Node* mArguments; // TODO create an Argument class
	
public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor with parameters
     */
    FunctionCall(const std::string & functionName, Node * arguments);
        
    /**
     * @brief destructor
     */
    virtual ~FunctionCall();


    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Function call"; }

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
