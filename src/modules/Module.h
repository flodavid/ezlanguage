#pragma once

#include "Node.h"
#include "../declarations/Class.h"
#include "../declarations/Import.h"
#include "../declarations/Variable.h"
#include "../declarations/Method.h"
#include "../declarations/Main.h"

/**
 * @brief Represent a module of the program, containing declarations
 * (variables, functions, classes and methods)
 * 
 * @author Florian DAVID
 */
class Module : public Node {

private:
    std::string mName;

public:
    
    /**
     * @brief constructor with parameters
     * @param right : right son
     * @param prg_name : name of the program
     * TODO construct program as cpp 'main' (instead of particular procedure, should inherit)
     */
    Module(std::string & name, Import* imports, Class* classes, Variable* vars,
        Method* methods);
    

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Module"; }
    
    /**
     * @brief Translate the begining part of the module
     * @return a string containing the C++ code of the instruction
     * 
     * Defines program imports and functions definitions
     */
    virtual std::string preTranslate() const;

    /**
     * @brief Translate the begining part of the module
     * @return a string containing the C++ code of the instruction
     * 
     * Defines program imports and functions definitions
     */
    virtual std::string postTranslate() const;

};
