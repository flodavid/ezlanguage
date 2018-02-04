#ifndef DECLARATION_FUNCTION_H
#define DECLARATION_FUNCTION_H

#include "Method.h"

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
class Function : public Method {

protected:
    std::string return_type;

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
    Function(Node * arguments, const std::string & name, Node * left,
        const std::string & type);


    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Function declaration"; }

    /**
     * @brief Getter for the function's name
     * @return name of the function
     */
    const std::string & getFunctionName() const { return getDeclarationName(); }


    /**
     * @brief Getter for the return's type
     * @return return's type
     */
    const std::string & getReturnType() const {return return_type;}
    
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
