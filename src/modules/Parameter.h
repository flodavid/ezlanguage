#pragma once

#include "Node.h"

/**
 * @brief Represent the root node of the tree
 * 
 * @author Florian DAVID
 */
class Parameter : public Node {
    	
public:
    
    /**
     * @brief constructor with parameters
     * @param right : right son
     * @param prg_name : name of the program
     * TODO construct program as cpp 'main' (instead of particular procedure, should inherit)
     */
    Parameter(std::string parameter_name);
    

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Parameter"; }
    
    /**
     * @brief Translate the begining part of the Repeat
     * @return a string containing the C++ code of the instruction
     * 
     * Defines program imports and functions definitions
     */
    virtual std::string preTranslate() const;

}