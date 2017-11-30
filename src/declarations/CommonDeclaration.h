#pragma once

#include "../modules/Node.h"

/**
 * @brief Allows the declaration of procedures
 * @author : GARNIER Antoine
 *
 * usage : procedure Name_Procedure (arguments list)
 *              instruction(s);
 *         end procedure
 */
class CommonDeclaration : public Node {

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
    

protected:
    /**
     * @brief Get some details about the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string details() const { return "'"+ mName +"'"; }

    /**
     * @brief Getter for the procedure's name
     * @return name of the procedure
     */
    const std::string & getDeclarationName() const { return mName; }
};
