#pragma once

#include "Container.h"

/**
 * @brief Node of the tree which represent a set
 * Translation part is already made in Container class
 */

class Set : public Container {

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
    Set(const std::string & nameC, const std::string & typeE, Expression* size = nullptr,
        bool isParameter = false);
        
    /**
     * Constructor with parameters
    * @param nameC : name of the container
    * @param typeE : type of the elements
    * @param size: left son, expression defining the size of the container
     */
    Set(const std::string & nameC, Expression* listInit, const std::string & typeE);
        
    /**
     * @brief destructor
     */
    virtual ~Set();


    /**
     * @brief Get the type of container (name in C++)
     * @return the type of the container. Defined at class creation
     */
    virtual inline const std::string getContainerType() const { return "set"; };

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Set"; }

};
