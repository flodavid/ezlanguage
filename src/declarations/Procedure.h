#pragma once

#include "Method.h"
#include "Parameter.h"

/**
 * @brief Allows the declaration of procedures
 * @author : GARNIER Antoine
 *
 * usage : procedure Name_Procedure (arguments list)
 *              instruction(s);
 *         end procedure
 */
class Procedure : public Method {

public:

    /**
     * @brief : Constructor
     * @param left : left son
     * @param name : procedure's name
     * @param args : arguments list of the procedure
     * 
     * Right son is set to null
     */
    Procedure(const std::string & name, Node * parameters, Instruction * instructions);
    

public:
    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Procedure declaration"; }

    /**
     * @brief Getter for the procedure's name
     * @return name of the procedure
     */
    const std::string & getProcedureName() const { return getDeclarationName(); }
    
    /**
     * @brief Translate the begining part of the Procedure
     * @return a string containing the C++ code of the instruction
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;
    
    /**
     * @brief Translate the end part of the Procedure
     * @return a string containing the C++ code of the instruction
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string postTranslate() const;

};
