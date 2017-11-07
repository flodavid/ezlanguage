#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

/**
 * @brief Base class, used to structure the others classes as nodes of the main tree
 * @authors : GARNIER Antoine, ROUINEB Hamza
 *
 */
class Node {

protected:
    std::string name;

private:
    Node* left_son;
    Node* right_son;

public:
    /**
     * @brief Default constructor
     */
    Node();
    
    /**
     * @brief Constructor with a name
     * @param name : Name of the node
     */
    Node(const std::string &name);
    
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
    
    /**
     * @brief getter on left son
     */
    Node * getLeftSon() const;
    
    /**
     * @brief getter on right son
     */
    Node * getRightSon() const;
    
    /**
     * @brief setter on left son
     * @param node : New left son
     */
    void setLeftSon(Node *son);
    
    /**
     * @brief setter on right son
     * @param node : New right son
     */
    void setRightSon(Node* son);
    
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
