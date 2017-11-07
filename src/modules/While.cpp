//@author Antoine GARNIER
#include "While.h"

using namespace std;

While::While(Node * left, Node * right, Node * cond) : Node(left, right), condition(cond)
{}

string While::preTranslate() const {
    string res = "while (" + condition->translate() + ") {";
    return res;
}

string While::postTranslate() const
{
    return "}";
}
