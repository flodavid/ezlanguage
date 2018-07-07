#pragma once

#include <string>
#include "../modules/FunctionCall.h"
#include "../modules/Expression.h"
#include "../modules/Operator.h"

enum StringFunctionName {
    FUNC_LENGTH, FUNC_TOUPPERCASE, FUNC_TOLOWERCASE, FUNC_SUBSTRING, FUNC_SPLIT, FUNC_STRIP,
    FUNC_REPLACE, FUNC_CONTAINS, FUNC_FIND, FUNC_FINDFIRSTOF, FUNC_FINDLASTOF
};

static const char * StringFunctionNameStrings[] = {
    "length", "toUpperCase", "toLowerCase", "substring", "split", "strip",
    "replace", "contains", "find", "findFirstOf", "findLastOf"
};

/**
 * @brief Node of the tree which represent a condition else
 */

class StringFunction : public FunctionCall {
    
public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor for zero parameters functions
     */
    StringFunction(const std::string & objectName, StringFunctionName functionName);
    
    /**
     * Constructor for one integer parameter functions
     */
    StringFunction(const std::string & objectName, StringFunctionName functionName, Expression* arg);
    
    /**
     * Constructor for two integer parameters functions
     */
    StringFunction(const std::string & objectName, StringFunctionName functionName, Expression* firstArg, Expression* secondArg);

    
    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual const std::string getName() const { return "StringFunction call"; };
};