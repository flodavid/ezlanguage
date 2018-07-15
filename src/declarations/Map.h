#pragma once

#include "Container.h"

/**
 * @brief Node of the tree which represent a map
 * Translation part is already made in Container class
 */

class Map : public Container {

private:
    std::string mKeyType;

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
    Map(const std::string & nameC, const std::string & typeFirstE,
        const std::string & typeSecondE, Expression* size = nullptr,
        bool isParameter =false);
        
    /**
     * Constructor with parameters
    * @param nameC : name of the container
    * @param typeE : type of the elements
    * @param size: left son, expression defining the size of the container
     */
    Map(const std::string & nameC, Expression* list, const std::string & typeE);
        
    /**
     * @brief destructor
     */
    virtual ~Map();


    /**
     * @brief Translate the complete type of the map (with its element type)
     * return C++ container type
     */
    std::string translateType() const;

    /**
     * @brief Get the type of container (name in C++)
     * @return the type of the container. Defined at class creation
     */
    virtual inline const std::string getContainerType() const { return "map"; };

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Map"; }

};
