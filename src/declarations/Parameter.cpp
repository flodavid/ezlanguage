#include "Parameter.h"

using namespace std;

Parameter::Parameter(const string & type, const string & name):
    CommonDeclaration(nullptr, name), mType(type), mIsLastOneOfList(true)
{
    debugNode("Parameter : "+ type +"_"+ name, AT);
}


string Parameter::preTranslate() const
{
    string res= mType +" "+ mName;
    if (!mIsLastOneOfList) res+= ", ";
    return res;
}

void Parameter::addRightChild(Node* child)
{
    Node::addRightChild(child);
    mIsLastOneOfList= false;
}