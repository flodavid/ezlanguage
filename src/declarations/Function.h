#ifndef DECLARATION_FUNCTION_H
#define DECLARATION_FUNCTION_H

#include "../modules/Node.h"
#include "Variable.h"
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
class Function : public Node {

protected:
    std::string function_name;
    std::vector<Variable*> arguments; // TODO delete in destructor
    std::string return_type;
    Node* funReturn;

public:

    /**
     * @brief Constructor with parameters
     * @param left : left son
     * @param name : function's name
     * @param arguments : arguments list of the function
     * @param type : return type of the function
     * 
     * Right son is set to null
     */
    Function(Node * left, const std::string & name,
        const std::vector< Variable* > & arguments, const std::string & type);

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
    std::vector<Variable*> getArguments() const {return arguments;}
    
    /**
     * @brief Translate the begining part of the Function
     * @return a string containing the C++ code of the instruction
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;
    
    /**
     * @brief Translate the end part of the Function
     * @return a string containing the C++ code of the instruction
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string postTranslate() const;

};


#endif
