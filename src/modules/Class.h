#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <vector>
#include <algorithm>
#include "Node.h"
#include "DeclarationFunction.h"
#include "../hash_table/ClassDeclaration.h"
#include "../hash_table/Variable.h"

/**
 * @brief 
 * @author : Ismail ELFAQIR
 * 
 */
class Class : public Node {
protected:

    ClassDeclaration *m_class;
    // as the validate document of Houssam BENHOUD (les classes.pdf) all variables and functions of classes are public
    std::vector<DeclarationFunction *> public_functions;
    // here are the static functions
    std::vector<DeclarationFunction *> static_functions;
    std::vector<Variable *> public_variables;

public:

    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */


    /**
    * Default constructor
    * Set public_fuctions and variables to null
    * @author Ismail ELFAQIR
    */
    Class();

    /**
    * Default constructor
    * Set the name of the class
    * @param c : class declaration
    * @author Ismail ELFAQIR
    */
    Class(ClassDeclaration *c);

    /**
    * Constructor with parameters
    * Set the vectors of fuctions and variables by the parameters passed to the constructor
    * @param c : class declaration
    * @param functions : vector of functions
    * @param s_functions : vector of static functions
    * @param variables : vector of attributes
    * @author Ismail ELFAQIR
    */
    Class(ClassDeclaration *c,
                         const std::vector<DeclarationFunction *> &functions,
                         const std::vector<DeclarationFunction *> &s_functions,
                         const std::vector<Variable *> &variables );


    /**
    * Constructor with parameters
    * Set the vectors of fuctions and variables by the parameters passed to the constructor
    * @param c : class declaration
    * @param functions : vector of functions
    * @param variables : vector of attributes
    * @author Ismail ELFAQIR
    */
    Class(ClassDeclaration *c,
                         const std::vector<DeclarationFunction *> &functions,
                         const std::vector<Variable *> &variables );

    /**
    * Constructor with parameters
    * Set only the vector of functions
    * @param c : class declaration
    * @param functions : vector of functions
    * @author Ismail ELFAQIR
    */
    Class(ClassDeclaration *c, const std::vector<DeclarationFunction *> &functions);


    /**
    * Constructor with parameters
    * Set only the vector of variables
    * @param c : class declaration
    * @param variables : vector of attributes
    * @author Ismail ELFAQIR
    */
    Class(ClassDeclaration *c, const std::vector<Variable *> &variables);

    /**
    * Copy constructor
    * @param cpy : the class that we want to cpy to the actual class
    * @author Ismail ELFAQIR
    */
    Class(const Class & cpy);

    /**
    * Destructor
    * @author Ismail ELFAQIR
    */
    virtual ~Class();

    /* * * * * * * * * * * * * *
    * ACCESSORS  AND MUTATORS *
    * * * * * * * * * * * * * */

    /**
    * getter of the class declaration
    * @author Ismail ELFAQIR
    */
    ClassDeclaration * get_class() const;

    /**
    * getter of variables
    * @author Ismail ELFAQIR
    */
    const std::vector<Variable *>&  get_variables() const;

    /**
    * getter of functions
    * @author Ismail ELFAQIR
    */
    const std::vector<DeclarationFunction *>&  get_functions() const;

    /**
    * getter of static functions
    * @author Ismail ELFAQIR
    */
    const std::vector<DeclarationFunction *>&  get_static_functions() const;

    /**
    * setter of class declaration
    * @param name : the pointer of this class declaration
    * @author Ismail ELFAQIR
    */
    void set_class(ClassDeclaration *c);

    /**
    * setter of variables
    * @param variables : vector of attributes
    * @author Ismail ELFAQIR
    */
    void set_variable(const std::vector<Variable *>&variables);

    /**
    * setter of variables
    * @param functions : vector of functions
    * @author Ismail ELFAQIR
    */
    void set_functions(const std::vector<DeclarationFunction *>&functions);

    /**
    * setter of variables
    * @param s_functions : vector of static functions
    * @author Ismail ELFAQIR
    */
    void set_static_functions(const std::vector<DeclarationFunction *>&s_functions);

    /* * * * * *
     * METHOD  *
     * * * * * */

    /**
     * @brief add an function to this class
     * @param function : pointer to the function
     * @author Ismail ELFAQIR
     */

    void add_function(DeclarationFunction *function);

    /**
     * @brief add an static function to this class
     * @param function : pointer to the function
     * @author Ismail ELFAQIR
     */

    void add_static_function(DeclarationFunction *function);

    /**
     * @brief add an attribute to this class
     * @param variable : pointer to the variable
     * @author Ismail ELFAQIR
     */

    void add_variable(Variable * variable);

    /**
     * @brief check if an function is in class
     * @param function : pointer to the function
     * @return boolean
     * @author Ismail ELFAQIR
     */

    bool is_in_class(DeclarationFunction * function);


    /**
     * @brief check if an variable is in class
     * @param variable : pointer to the variable
     * @return boolean
     * @author Ismail ELFAQIR
     */

    bool is_in_class(Variable * variable);



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
