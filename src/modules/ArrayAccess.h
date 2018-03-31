#pragma once

#include "Expression.h"

/**
 * @class AccessArray
 * @brief meant to translate an access to array by index 
 * 
 * example of translation my_array[5] -> here index=5  
 * @author Ismail ELFAQIR
 */
class ArrayAccess : public Expression {

protected:	
    std::string mArrayName;
    int mIndex;
    Expression * mExpression;

public:

    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
    * Constructor with parameters
    * Set the array and the access index of array by the parameters passed to the constructor
    * @param left : left son
    * @param right : right son
    * @param arrayN : name of the array
    * @param ind : index to access
    * @author Ismail ELFAQIR
    */
    ArrayAccess(const std::string & arrayName, int ind);

    /**
    * Constructor with parameters
    * Set the array and the access index of array by the parameters passed to the constructor
    * @param left : left son
    * @param right : right son
    * @param arrayN : name of the array
    * @param ind : index to access
    * @author Ismail ELFAQIR
    */
    ArrayAccess(const std::string & arrayName, Expression * expression);

    /**
     * @brief destructor
     */
    virtual ~ArrayAccess();

    /* * * * * * * * * * * * * *
    * ACCESSORS  AND MUTATORS *
    * * * * * * * * * * * * * */

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Array access"; }

    /**
     * getter of array
     * @author Ismail ELFAQIR
     */
    const std::string & get_array() const;

    /**
     * getter of index
     * @author Ismail ELFAQIR
     */
    int get_index() const;

    /**
     * setter of array
     * @param a : reference to the ArrayDeclaration
     * @author Ismail ELFAQIR
     */
    void set_array(const std::string & a);

    /**
     * setter of index
     * @param i : index
     * @author Ismail ELFAQIR
     */
    void set_index(int i);

    /* * * * * * * *
    * Translation  *
    * * * * * * * **/

    /**
     * @brief Translate the begining part of the ArrayAccess
     * @return a string containing the C++ code of the ArrayAccess
     *
     * All subclasses, must reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;
};
