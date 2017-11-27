//@author Antoine GARNIER
#include "While.h"

using namespace std;

While::While(Node * left, Node * cond):
    Node(left, nullptr, "While"), condition(cond)
{}

string While::preTranslate() const {
    string res = "while (" + condition->translate() + ") {\n";
    return res;
}

string While::postTranslate() const
{
    //    The instructions have been translated, the loop closes
    return "}\n";
}
