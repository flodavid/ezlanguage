#pragma once

#include "Instruction.h"

/**
 * @brief Node of the tree which represent the inclusion of C++ code into an
 * ezlanguage file
 */

class CppCode : public Instruction {

protected:
    std::string mTextCppCode;
	
public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor with content
     */
    CppCode(std::string & textCppCode);

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "CppCode"; }

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
