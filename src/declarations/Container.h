#ifndef CONTAINER_H
#define CONTAINER_H

#include "CommonVar.h"
#include "../modules/Expression.h"

/**
 * @class Container
 * @brief Node of the tree whhich represent the declaration of a container
 * 
 * @author LAHYANI Zakaria - Ismail ELFAQIR - Johan Defaye
 * @see if there must be a class for containers as parameter (not static), or flags in CommonVar ?
 * TODO use CommonVar::preTranslate() or redefine comportment to handle CommonVar attributes
 */
class Container : public CommonVar {

protected:
    std::string mTypeContainer; // Vector, Array, Set, Map or List
    // std::string mTypeElement; // int, double, string etc ...
    Expression* mSize;
    bool mIsParameter;
    
public:

    /* * * * * * * * *
     * CONSTRUCTORS  *
     * * * * * * * * */
                
   /**
    * Constructor with size
    * @param nameC : name of the container
    * @param size: expression defining the size of the container
    */
    Container(const std::string & nameC, const std::string & typeE, Expression* size,
        bool isParameter = false);
    
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
    virtual const std::string getContainerType() const =0;

    /**
     * @brief Translate the complete type of the container (with its element type)
     * return C++ container type
     */
    virtual std::string translateType() const;

    /**
     * @brief Add an initialization list to the vector
     */
    void setInitList(Expression* listInit) { setLeftSon(listInit); }

    /**
     * @brief Translate the node after the translation of the left son
     */
    virtual std::string preTranslate() const;

    /**
     * @brief Translate the end part of the Container
     * @return a string containing the C++ code of the Container
     */
    virtual std::string postTranslate() const;
};

#endif // DECLARATIONCONTAINER_H
