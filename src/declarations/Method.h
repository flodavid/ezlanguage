#pragma once

#include "CommonDeclaration.h"
#include "Parameter.h"

/**
 * @brief Abstract class that allows the declaration of methods
 */
class Method : public CommonDeclaration {

protected:
    Node* mParameters;

public:

    /**
     * @brief : Constructor
     * @param left : left son
     * @param name : variable's name
     * 
     * Right son is set to null
     */
    Method(const std::string & name, Node * parameters, Node * instructions);

public:

    /**
     * @brief Getter for the argument's list
     * @return List of arguments
     */
    const Node& getParameters() const { return *mParameters; }

    /**
     * @brief Setter of the list of arguments
     * @param arguments : list of the arguments of the function
     */
    void setArguments(Parameter* params){ mParameters= params; }

};
