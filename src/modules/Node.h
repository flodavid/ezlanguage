#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

/**
 * @brief Base class, used to structure the others classes as nodes of the main tree
 * @authors : GARNIER Antoine, ROUINEB Hamza
 *
 */
class Node {
protected:
	string name;
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
     * @author ROUINEB Hamza
     * The destructor should be virtual so it could be called in inner classes !
     * & don't forget to delete the pointers
     */
    virtual ~Node();

    /**
     * @brief getter on left son
     */
    Node(Node* left, Node* right);
    ~Node();

    Node * get_left_son() const;

    /**
     * @brief getter on right son
     */
    Node * get_right_son() const;

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
     * @brief Translation of the instruction into it's C++ counterpart
     * @return a string containing the C++ code of the instruction
     *
     * The instance will be translated with it's C++ equivalent using its informations
     * All subclasses, must reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
     virtual std::string translate() const =0; // this function will allow the translation of the nodes's tree into c++ instructions*

};

#endif //NODE_H
