#pragma once

#include "CommonDeclaration.h"
#include "../modules/Expression.h"

/**
 * @brief Node of the tree which represent a condition else
 */

class Array : public CommonDeclaration {

protected:
	std::string mTypeElement; // int, double, string etc ...
	Expression* mListInit;
    unsigned mSize; 
	
public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */    

   /**
    * Constructor with size
    * @param nameC : name of the container
    * @param typeE : type of the element in the container
    * @param size : size the container
    * @author Johan Defaye
    */
    Array(const std::string & nameC, const std::string & typeE, unsigned size);
        
   /**
    * Constructor with initialization list
    * @param nameC : name of the container
    * @param typeE : type of the element in the container
    * @param listInit: initialization list for the array, will be its left son
    * @author Johan Defaye
    */
    Array(const std::string & nameC, const std::string & typeE, Expression* listInit);
        
    /**
     * @brief destructor
     */
    virtual ~Array();


    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Array"; }

    /* * * * * * * *
     * Translation *
     * * * * * * * */
    
    /**
     * @brief Translate the begining part of the If
     * @return a string containing the C++ code of the If
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;
    
    /**
     * @brief Translate the end part of the Array
     * @return a string containing the C++ code of the Array
     */
    virtual std::string postTranslate() const;

};
