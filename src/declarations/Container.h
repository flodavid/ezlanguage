#ifndef CONTAINER_H
#define CONTAINER_H

#include "CommonDeclaration.h"
#include "../modules/Expression.h"

/**
 * @class Container
 * @brief Node of the tree whhich represent the declaration of a container
 * 
 * @author LAHYANI Zakaria - Ismail ELFAQIR - Johan Defaye
 */
class Container : public CommonDeclaration {
	
protected:
	std::string mTypeContainer; // Vector, Array, Set, Map or List
	std::string mTypeElement; // int, double, string etc ...
	Expression* mSize;
    
public:

    /* * * * * * * * *
     * CONSTRUCTORS  *
     * * * * * * * * */
                
   /**
    * Constructor with size
    * @param nameC : name of the container
    * @param size: left son, expression defining the size of the container
    */
    Container(const std::string & nameC, const std::string & typeE, Expression* size);
    
   /**
    * Constructor with initialisation list
    * @param nameC : name of the container
    * @param listI : list of initialisation (only available for the "array")
    * @param typeE : type of the element in the container
    * @author Johan Defaye
    */
    Container(const std::string & nameC, Expression* listI, const std::string & typeE);

    /**
     * @brief destructor
     */
    virtual ~Container();


    /**
     * @brief Get the type of container (name in C++)
     * @return the type of the container. Defined at class creation
     */
    virtual const std::string getType() const =0;

    /**
     * @brief Add an initialization list to the vector
     */
    void setInitList(Expression* listInit) { setLeftSon(listInit); }

    /**
     * @brief Translate the node after the translation of the left son
     */
    virtual std::string preTranslate() const;

    /**
     * @brief Translate the end part of the If
     * @return a string containing the C++ code of the If
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string postTranslate() const;
};

#endif // DECLARATIONCONTAINER_H
