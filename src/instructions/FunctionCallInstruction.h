#pragma once

#include "../modules/FunctionCall.h"
#include "Instruction.h"

/**
 * @brief Node of the tree which represent the call to a function, interpreted as an instruction
 * The call is done without object, on another function call, or an object given its name
 */
class FunctionCallInstruction : public FunctionCall, public Instruction {

public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor by copying the superclass
     */
    FunctionCallInstruction(FunctionCall* callToTransform);
    
    /**
     * Constructor with paremeters. For no parenthesis function calls
     */
    FunctionCallInstruction(const std::string & functionName, Expression * arguments,
            const std::string & objectName = "");

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Function call instruction"; }

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
