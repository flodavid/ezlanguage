#pragma once

#include "Procedure.h"
#include "Parameter.h"

/**
 * @brief Allows the declaration of procedures
 *
 * usage : procedure Name_Main (arguments list)
 *              instruction(s);
 *         end procedure
 */
class Main : public Procedure {

public:

    /**
     * @brief : Constructor
     * @param left : left son
     * @param name : procedure's name
     * @param args : arguments list of the procedure
     * 
     * Right son is set to null
     */
    Main(Node * parameters, Node * left);
    

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
    const std::string & getMainName() const { return getProcedureName(); }
    
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

};
