#pragma once

#include "Container.h"

/**
 * @brief Node of the tree which represent a List
 * Translation part is already made in Container class
 */

class List : public Container {
	
public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor with parameters
    * @param nameC : name of the container
    * @param typeE : type of the elements
    * @param size: left son, expression defining the size of the container
     */
    List(const std::string & nameC, const std::string & typeE, Expression* size = nullptr);
        
    /**
     * Constructor with parameters
    * @param nameC : name of the container
    * @param typeE : type of the elements
    * @param size: left son, expression defining the size of the container
     */
    List(const std::string & nameC, Expression* list, const std::string & typeE);
        
    /**
     * @brief destructor
     */
    virtual ~List();


    /**
     * @brief Get the type of container (name in C++)
     * @return the type of the container. Defined at class creation
     */
    virtual inline const std::string getType() const { return "list"; };

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "List"; }

};
