#pragma once

#include <string>
#include "Instruction.h"
extern std::string INPUT_FUNC_NAME;

/**
 * @brief Statement to ask an input for the user
 */
class Input : public Instruction {

private:
    std::string mVarName;

public:

    /**
     * @brief : Constructor
     * 
     * Right son is set to null by default
     */
    Input(const std::string & varName);
    
    
    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual const std::string getName() const { return "Text Input"; };
    
    /* * * * * * * *
     * Translation *
     * * * * * * * */
    
    /**
     * @brief Translate the begining part of the text input
     * @return a string containing the C++ code of the Input
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;
};
