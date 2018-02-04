#ifndef CLASS_H
#define CLASS_H

#include "CommonDeclaration.h"
#include "../modules/EmptyNode.h"
#include "../hash_table/ClassHashed.h"
#include "Method.h"
#include "Variable.h"
#include <string>
#include <vector>

/**
 * @brief 
 * @author : Ismail ELFAQIR
 * 
 * According to document of Houssam BENHOUD (les classes.pdf) all variables and functions
 * of classes are public @see if it changes
 */
class Class : public CommonDeclaration {

protected:
    Variable * mVariables;
    ClassHashed * mClass;

    // @see when/how to set to false mSupportsPragmas
    bool mSupportsPragmas;

public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */
    /**
    * Default constructor
    * Set the name of the class
    * @param c : class declaration
    * @author Ismail ELFAQIR
    */
    Class(ClassHashed *c);

    /**
    * Constructor with parameters
    * Set the vectors of fuctions and variables by the parameters passed to the constructor
    * @param c : class declaration
    * @param functions : functions
    * @param s_functions : static functions
    * @param variables : attributes
    * @author Ismail ELFAQIR
    */
    Class(ClassHashed *c, 
        Variable * variables,
        Method * functions,
        Method * s_functions);

    /**
    * Constructor with parameters
    * Set the vectors of fuctions and variables by the parameters passed to the constructor
    * @param c : class declaration
    * @param functions : vector of functions
    * @param variables : vector of attributes
    * @author Ismail ELFAQIR
    */
    Class(ClassHashed *c,
        Variable * variables,
        Method * functions);

    /**
    * Constructor with parameters
    * Set only the vector of functions
    * @param c : class declaration
    * @param functions : vector of functions
    * @author Ismail ELFAQIR
    */
    Class(ClassHashed *c, Method * functions);

    /**
    * Constructor with parameters
    * Set only the vector of variables
    * @param c : class declaration
    * @param variables : vector of attributes
    * @author Ismail ELFAQIR
    */
    Class(ClassHashed *c, Variable * variables);

    /**
    * Destructor
    * @author Ismail ELFAQIR
    */
    virtual ~Class();

    /* * * * * * * * * * * * * *
    * ACCESSORS  AND MUTATORS *
    * * * * * * * * * * * * * */

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Class declaration"; }

    /**
     * @brief Getter for the procedure's name
     * @return name of the procedure
     */
    const std::string & getClassName() const { return getDeclarationName(); }

    /**
    * getter of the class declaration
    * @author Ismail ELFAQIR
    */
    ClassHashed * get_class() const;

    /* * * * * *
     * METHOD  *
     * * * * * */

    /**
     * @brief add an function to this class
     * @param function : pointer to the function
     */
    void addMethod(Method *function);

    /**
     * @brief add an static function to this class
     * @param function : pointer to the function
     * TODO static functions implementation
     */
    // void add_static_function(Method *function);

    /**
     * @brief add an attribute to this class
     * @param variable : pointer to the variable
     */
    void addVariable(Variable * variable);

    /**
     * @brief check if an function is in class
     * @param function : pointer to the function
     * @return boolean
     * @author Ismail ELFAQIR
     * @see if useful
     */

    // bool is_in_class(Method * function);


    /**
     * @brief check if an variable is in class
     * @param variable : pointer to the variable
     * @return boolean
     * @author Ismail ELFAQIR
     * @see if useful
     */
    // bool is_in_class(Variable * variable);

    /* * * * * * * *
    * Translation  *
    * * * * * * * **/

    /**
     * @brief Translate the begining part of the Class
     * @return a string containing the C++ code of the instruction
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;
    
    /**
     * @brief Translate the end part of the Class
     * @return a string containing the C++ code of the instruction
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string postTranslate() const;
};

#endif
