#pragma once

#include "Instruction.h"

#include <string>

/**
 * @brief Node of the tree which represent a condition else
 */

class Print : public Instruction {
    
private:
    std::string mText;

public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor with parameters
     * @param text: text to print
     */
    Print(const std::string & textStream = "");


    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Print"; }

    /* * * * * * * *
     * Translation *
     * * * * * * * */
    
    /**
     * @brief Translate print instruction
     * @return a string containing the C++ code of the If
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;

};
