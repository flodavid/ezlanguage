#ifndef CONTAINER_H
#define CONTAINER_H

#include "CommonDeclaration.h"

/**
 * @class Container
 * @brief Node of the tree whhich represent the declaration of a container
 * 
 * @author LAHYANI Zakaria - Ismail ELFAQIR - Johan Defaye
 */
class Container : public CommonDeclaration {
	
protected:
	std::string nameContainer;
	std::string typeContainer; // Vector, Array, Set, Map or List
	std::string typeElement; // int, double, string etc ...
	std::string listInit;
    unsigned mSize; 
    
public:

    /* * * * * * * * *
     * CONSTRUCTORS  *
     * * * * * * * * */

   /**
    * Constructor with size
    * @param left: left son 
    * @param right : right son
    * @param nameC : name of the container
    * @param typeC : type of the container
    * @param typeE : type of the element in the container
    * @param size : size the container
    * @author Johan Defaye
    */
    Container(const std::string & nameC, const std::string & typeC,
            const std::string & typeE, unsigned size);
    
   /**
    * Constructor with initialisation list
    * @param left: left son 
    * @param right : right son
    * @param nameC : name of the container
    * @param typeC : type of the container
    * @param typeE : type of the element in the container
    * @param listI : list of initialisation (only available for the "array")
    * @author Johan Defaye
    */
    Container(const std::string & nameC, const std::string & typeC,
            const std::string & typeE, const std::string & listI);


    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Container declaration"; }

	/**
	 * @brief Translate the node after the translation of the left son
	 */
	virtual std::string preTranslate() const;
};

#endif // DECLARATIONCONTAINER_H
