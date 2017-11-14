#include "Node.h"

#include <iostream>

using namespace std;

Node::Node(): left_son(nullptr), name(""), right_son(nullptr)
{}

Node::Node(const string &_name) : name(_name), left_son(nullptr), right_son(nullptr)
{}

Node::Node(Node* left, Node* right): name(""), left_son(left), right_son(right)
{}

Node::~Node()
{
    delete left_son;
    delete right_son;
}

void Node::setLeftSon(Node *left) {
    left_son = left; // TODO replace by reference
}

void Node::setRightSon(Node *right) {
    right_son = right;
}

string Node::postTranslate() const
{
    return "";
}


string Node::translate() const {
    debug("[node--translate()]"+ getName(), AT);
    // debug("Translation of the node : "+ getName(), AT);
    string left_translate= "";
    string right_translate= "";
    if (left_son != nullptr)	left_translate += "\n" + left_son->translate() + "\n";
    if (right_son != nullptr)	right_translate += "\n\n" + right_son->translate() + "\n";
    // std::cout << "[traduction noeud--translate() Node.cpp l.43]" << std::endl;
    return preTranslate() + left_translate + postTranslate() + right_translate;
}
