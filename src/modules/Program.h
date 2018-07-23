#pragma once

#include "Module.h"
#include "../declarations/Class.h"
#include "../declarations/Import.h"
#include "../declarations/Variable.h"
#include "../declarations/Method.h"
#include "../declarations/Main.h"

/**
 * @brief Represent the root node of the tree
 * 
 * @author Florian DAVID
 */
class Program : public Module {

public:
    
    /**
     * @brief constructor with parameters
     * @param name: Name of the program
     * @param import: Imports used by the program
     * @param right: Diverse declarations
     * @param main: Main function of the program (starting point)
     */
    Program(std::string & name, Import* imports, Class* classes, Variable* vars,
        Method* methods, Main* main);
    

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Program"; }

};
