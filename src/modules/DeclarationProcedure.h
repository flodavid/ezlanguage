#ifndef DECLARATION_PROCEDURE_H
#define DECLARATION_PROCEDURE_H

#include "Node.h"
#include <vector>


/**
 * @brief Allows the declaration of procedures
 * @author : GARNIER Antoine
 *
 * usage : procedure Name_Procedure (arguments list)
 *              instruction(s);
 *         end procedure
 */
class DeclarationProcedure : public Node {

protected:
    std::string procedure_name;
    std::vector<std::pair<std::string, std::string> > arguments;

public:

    /**
     * @brief : Constructor
     * @param left : left son
     * @param right : right son
     * @param name : procedure's name
     * @param args : arguments list of the procedure
     */
    DeclarationProcedure(Node * left, Node * right, const std::string & name, const std::vector<std::pair<std::string, std::string> > & args);

    /**
     * @brief Getter for the procedure's name
     * @return name of the procedure
     */
    std::string getProcedureName() const {return procedure_name;}

    /**
     * @brief Getter for the argument's list
     * @return List of arguments
     */
    std::vector<std::pair<std::string, std::string> > getArguments() const {return arguments;}

    /**
     * @brief Setter of the procedure's name
     * @param name : name of the procedure
     */
    void setProcedureName(std::string name){procedure_name= name;}

    /**
     * @brief Setter of the list of arguments
     * @param arguments : list of the arguments of the function
     */
    void setArguments(std::vector<std::pair<std::string, std::string> > args){arguments= args;}
    
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
