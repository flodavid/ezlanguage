#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

#include "../addons/log.h"
// #include "../declarations/Class.h"

/**
 * @brief Base class, used to structure the others classes as nodes of the main tree
 * @authors : GARNIER Antoine, ROUINEB Hamza
 *
 */
class Node {

// Exception to the rule: Node sub-classes should not acceed to their sons
friend class Class;

private:
    Node* left_son;
    Node* right_son;

public:
    /**
     * @brief Default constructor
     */
    Node();

    /**
     * @brief Constructor with nodes
     * @param left : pointer to the left son
     * @param right : pointer to the right son
     */
    Node(Node* left, Node* right);

    /**
     * @author ROUINEB Hamza
     * The destructor should be virtual so it could be called in inner classes !
     * & don't forget to delete the pointers
     */
    virtual ~Node();

private:
    
    /**
     * @brief setter on right son
     * @param node : New right son
     * @note should only be could right after the node construction
     */
    void setRightSon(Node* son);

protected:
    /**
     * @brief setter on left son
     * @param node : New left son
     */
    void setLeftSon(Node* son);

    /**
     * @brief Get some details about the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string details() const { return ""; }

public:
    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual const std::string getName() const =0;
    
    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getDetails() const { return getName() +": "+ details(); }

    /**
     * @brief Add a right son to the last of the right sons
     * @param child : New right son
     * 
     * If there is already a right son, the right son of the group formed by the current
     * son and all its right sons (the right of its right son, of its ... etc) will be the
     * right son of the current last right son (that had no right son)
     * TL;DR : The right son of a group is the right son of the last one of the group
     */
    virtual void addRightChild(Node* child);

    /**
     * @brief Translate the begining part of the Node
     * @return a string containing the C++ code of the node
     *
     * All subclasses, must reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const =0;

    /**
     * @brief Translate the end part of the Node
     * @return a string containing the C++ code of the instruction
     *
     * By default, the post-translation is an empty string.
     * But, some subclasses, may reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string postTranslate() const;

    /**
     * @brief Translation of the instruction into it's C++ counterpart
     * @return a string containing the C++ code of the instruction
     *
     * The instance will be translated with it's C++ equivalent using its informations
     * This method must not be reimplemented by subclasses
     */
    virtual std::string translate() const final;

};

#endif //NODE_H
