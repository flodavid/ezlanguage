#ifndef DECLARATION_PROCEDURE_H
#define DECLARATION_PROCEDURE_H

#include "../modules/Node.h"
#include "Variable.h"
#include <vector>


/**
 * @brief Allows the declaration of procedures
 * @author : GARNIER Antoine
 *
 * usage : procedure Name_Procedure (arguments list)
 *              instruction(s);
 *         end procedure
 */
class Procedure : public Node {

protected:
    std::string procedure_name;
    std::vector<Variable*> arguments; // TODO delete in destructor

public:

    /**
     * @brief : Constructor
     * @param left : left son
     * @param name : procedure's name
     * @param args : arguments list of the procedure
     * 
     * Right son is set to null
     */
    Procedure(Node * left, const std::string & name, const std::vector<Variable*> & args);

    /**
     * @brief Getter for the procedure's name
     * @return name of the procedure
     */
    std::string getProcedureName() const {return procedure_name;}

    /**
     * @brief Getter for the argument's list
     * @return List of arguments
     */
    std::vector<Variable*> getArguments() const {return arguments;}

    /**
     * @brief Setter of the list of arguments
     * @param arguments : list of the arguments of the function
     */
    void setArguments(std::vector<Variable*> args){arguments= args;}
    
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


#endif
