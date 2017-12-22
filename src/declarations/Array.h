#pragma once

#include "CommonDeclaration.h"

/**
 * @brief Node of the tree which represent a condition else
 */

class Array : public CommonDeclaration {

protected:
	std::string mTypeElement; // int, double, string etc ...
	std::string mListInit;
    unsigned mSize; 
	
public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */    

   /**
    * Constructor with size
    * @param left: left son
    * @param nameC : name of the container
    * @param typeC : type of the container
    * @param typeE : type of the element in the container
    * @param size : size the container
    * @author Johan Defaye
    */
    Array(const std::string & nameC, const std::string & typeE, unsigned size);
        
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

};
