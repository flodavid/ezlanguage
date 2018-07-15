#pragma once

#include <string>
#include "Expression.h"

/**
 * @brief Represent a node of the tree which will traduct a convertion of an expression
 * 
 * The Expression will be "encapsulated" into this Node that defines a function that should
 * convert it. The function will just be called, given the expression as only parameter.
 * The basic example is the use of "std::to_string" function on an expression to convert
 * to a string
 */
class ConvertNode : public Expression {

private:
    std::string mFunctionName;

public:
    
    /**
     * @brief Constructor
     * @param functionName : complete name (std, ...) of the function that will convert the node
     * @param expressionToConvert : expression to be converted by the function
     */
    ConvertNode(const std::string & functionName, Expression* expressionToConvert);
    

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Convertion of an Expression"; }

    /* * * * * * * *
     * Translation *
     * * * * * * * */
    
    /**
     * @brief Translate the begining part of the convertion
     * @return a string containing the C++ code of the convertion
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;

    /**
     * @brief Translate the end part of the convertion
     * @return a string containing the C++ code
     */
    virtual std::string postTranslate() const;
};
