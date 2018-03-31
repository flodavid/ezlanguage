#include "Node.h"

#include <iostream>

using namespace std;

Node::Node():
    left_son(nullptr), right_son(nullptr)
{}

Node::Node(Node* left, Node* right):
    left_son(left), right_son(right)
{}

Node::~Node()
{
    if (right_son != nullptr) delete right_son;
    if (left_son != nullptr) delete left_son;
}

void Node::setLeftSon(Node *left) {
    left_son= left;
}

void Node::setRightSon(Node* son) {
    right_son= son;
}

void Node::addRightChild(Node* child) {
    // debugNode("addRightChildCall:"+ getName(), AT);
    // Right son recursive definition
    if (right_son == nullptr) {
        right_son= child;
    } else {
        right_son->addRightChild(child);
    }
}

string Node::postTranslate() const
{
    return "";
}


string Node::translate() const {
    if (left_son) {
        if (right_son) debugNode(""+ getName() +"--translate(), has left and right sons", AT);
        else debugNode(""+ getName() +"--translate(), has left son", AT);
    } else if (right_son) debugNode(""+ getName() +"--translate(), has right son", AT);
        else debugNode(""+ getName() +"--translate(), no sons", AT);

    string left_translate= "";
    string right_translate= "";
    if (left_son != nullptr)    left_translate+= left_son->translate();
    if (left_translate == "\n") left_translate= "\n\n";
    if (left_translate != "")   right_translate+= '\n';
    if (right_son != nullptr)   right_translate+= right_son->translate();
    // std::cout << "[traduction noeud--translate() Node.cpp l.43]" << std::endl;
    return preTranslate() + left_translate + postTranslate() + right_translate;
}
