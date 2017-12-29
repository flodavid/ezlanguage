//@author Antoine GARNIER
#include "While.h"

using namespace std;

While::While(ConditionalExpression * cond, Node * left):
    Node(left, nullptr), mCondition(cond)
{}

While::~While()
{
    delete mCondition;
}


string While::preTranslate() const {
    return "while " + mCondition->translate() + " {\n";
}

string While::postTranslate() const
{
    //    The instructions have been translated, the loop closes
    return "}\n";
}
