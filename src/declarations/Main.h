#pragma once

#include "Function.h"
#include "CommonVar.h"

/**
 * @brief Allows the declaration of the main function (program entrance)
 *
 * usage : Main_Name (argument list)
 *              instruction-s;
 *         end
 *  TODO correct main function check (main name is the program name, not mandatory "main")
 */
class Main : public Function {

private:
    CommonVar * mMainOpts; // @see if it must be changed: Creation of a class dedicated to parameters ?

public:

    /**
     * @brief : Constructor
     * @param left : left son
     * @param name : procedure's name
     * @param args : arguments list of the procedure
     * 
     * Right son is set to null
     */
    Main(CommonVar * parameters, Instruction * prgm_intructions);
    

public:
    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Main declaration"; }

    /**
     * @brief Getter for the procedure's name
     * @return name of the procedure
     */
    const std::string & getMainName() const { return getFunctionName(); }
    
    /**
     * @brief Translate the begining part of the Main
     * @return a string containing the C++ code of the instruction
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;
    
    /**
     * @brief Translate the end part of the Main
     * @return a string containing the C++ code of the instruction
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string postTranslate() const;

    std::string createParsingParameterCode(std::string * input_arguments_summary) const;

};
