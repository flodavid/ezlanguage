#pragma once

#include "CommonDeclaration.h"
#include "Parameter.h"

/**
 * @brief Abstract class that allows the declaration of methods
 */
class Method : public CommonDeclaration {

private:
    Node* mParameters;

public:

    /**
     * @brief : Constructor
     * @param left : left son
     * @param name : variable's name
     * 
     * Right son is set to null
     */
    Method(const std::string & name, Node * parameters, Instruction * instructions);
    
    /**
     * @brief destructor
     */
    virtual ~Method();

public:

    /**
     * @brief Getter for the argument's list
     * @return List of arguments
     */
    const Node* getParameters() const;

    /**
     * @brief Add a parameter or list of parameters to the method
     * @param arguments : list of the arguments of the function
     */
    void addParameters(Parameter* params){ mParameters->addRightChild(params); }

    std::string translateParameters() const;

};
