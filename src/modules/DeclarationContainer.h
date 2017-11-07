#ifndef DECLARATIONCONTAINER_H
#define DECLARATIONCONTAINER_H

#include "Node.h"

/**
 * @class DeclarationContainer
 * @brief Node of the tree whhich represent the declaration of a container
 * 
 * @author LAHYANI Zakaria - Ismail ELFAQIR
 */
class DeclarationContainer : public Node {
	
  protected:
	std::string nameContainer;
	std::string typeContainer; // Vector, Array, Set, Map or List
	std::string typeElement; // int, double, string etc ...
	std::string listInit;
    int size; 
    
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
    * @param s : size
    * @author LAHYANI Zakaria
    */
    DeclarationContainer(Node * left, Node * right, const std::string & nameC, const std::string & typeC, const std::string & typeE, int s = 0);



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
    DeclarationContainer(Node * left, Node * right, const std::string & nameC, const std::string & typeC, const std::string & typeE, const std::string & listI);


	/**
	 * @brief Translate the node after the translation of the left son
	 */
	virtual std::string preTranslate() const;
};

#endif // DECLARATIONCONTAINER_H
