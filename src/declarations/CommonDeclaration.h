#pragma once

#include "../instructions/Instruction.h"

/**
 * @brief Generic declaration of any variable
 */
class CommonDeclaration : public Instruction {

protected:
    std::string mName;

public:

    /**
     * @brief : Constructor
     * @param left : left son
     * @param name : variable's name
     * 
     * Right son is set to null
     */
    CommonDeclaration(Node * left, const std::string & name);
    

    /**
     * @brief Get some details about the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string details() const { return Instruction::details()+";'"+ mName +"'"; }

    /**
     * @brief Getter for the procedure's name
     * @return name of the procedure
     */
    const std::string & getDeclarationName() const { return mName; }
};
