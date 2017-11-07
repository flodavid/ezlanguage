#ifndef DECLARATION_FUNCTION_H
#define DECLARATION_FUNCTION_H

#include "Node.h"
#include <vector>

/**
 * @brief Allows the declaration of functions
 * @author : GARNIER Antoine
 *
 * usage : function Name_Fonction (arguments list) return type1
 *              type1 variable;
 *              instruction(s);
 *              return variable;
 *          end function
 */
class DeclarationFunction : public Node {

protected:
    std::string function_name;
    std::vector<std::pair<std::string, std::string> > arguments;
    std::string return_type;

public:

    /**
     * @brief Constructor with parameters
     * @param left : left son
     * @param right : right son
     * @param name : function's name
     * @param arguments : arguments list of the function
     * @param type : return type of the function
     */
    DeclarationFunction(Node * left, Node * right, const std::string & name, const std::vector<std::pair<std::string, std::string> > & arguments, const std::string & type);

    /**
     * @brief Getter for the function's name
     * @return name of the function
     */
    std::string getFunctionName() const {return function_name;}

    /**
     * @brief Getter for the return's type
     * @return return's type
     */
    std::string getReturnType() const {return return_type;}

    /**
     * @brief Getter for the argument's list
     * @return List of arguments
     */
    std::vector<std::pair<std::string, std::string> > getArguments() const {return arguments;}

    /**
     * @brief Setter of the function's name
     * @param name : name of the function
     */
    void setFunctionName(const std::string & name){function_name= name;}

    /**
     * @brief Setter of the return type
     * @param type : return type of the function
     */
    void setReturnType(const std::string & type){return_type= type;}

    /**
     * @brief Setter of the list of arguments
     * @param arguments : list of the arguments of the function
     */
    void setArguments(const std::vector<std::pair<std::string, std::string>> & args){arguments= args;}

    
    /**
     * @brief Translate the begining part of the DeclarationFunction
     * @return a string containing the C++ code of the instruction
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;
    
    /**
     * @brief Translate the end part of the DeclarationFunction
     * @return a string containing the C++ code of the instruction
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string postTranslate() const;

};


#endif
