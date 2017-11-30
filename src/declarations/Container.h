#ifndef CONTAINER_H
#define CONTAINER_H

#include "CommonDeclaration.h"

/**
 * @class Container
 * @brief Node of the tree whhich represent the declaration of a container
 * 
 * @author LAHYANI Zakaria - Ismail ELFAQIR
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
    * Constructor with parameters
    * @param left: left son 
    * @param right : right son
    * @param nameC : name of the container
    * @param typeC : type of the container
    * @param typeE : type of the element in the container
    * @param listI : list of initialisation (only available for the "array")
    * @author Johan Defaye
    */
    Container(Node * left, const std::string & nameC, const std::string & typeC,
            const std::string & typeE, const std::string & listI, unsigned size = 0);


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
