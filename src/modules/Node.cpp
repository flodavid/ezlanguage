#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(): left_son(nullptr), right_son(nullptr)
{}

Node::Node(const string &name) : name(name), left_son(nullptr), right_son(nullptr)
{}

Node::Node(Node* left, Node* right): left_son(left), right_son(right)
{}

Node::~Node()
{
    delete left_son;
    delete right_son;
}


Node * Node::getLeftSon() const {
    return left_son;
}

Node * Node::getRightSon() const{
    return right_son;
}

void Node::setLeftSon(Node *left) {
    left_son = left;
}

void Node::setRightSon(Node *right) {
    right_son = right;
}

string Node::postTranslate() const
{
    return "";
}


string Node::translate() const {
    string left_translate= "";
    string right_translate= "";
    if (left_son != nullptr)
	left_translate = "\n" + left_son->translate() + "\n";
    if (right_son != nullptr)
	right_translate = "\n\n" + right_son->translate() + "\n";
    std::cout << "[traduction noeud--translate() Node.cpp l.43]" << std::endl;
    return preTranslate() + left_translate + postTranslate() + right_translate;
}
