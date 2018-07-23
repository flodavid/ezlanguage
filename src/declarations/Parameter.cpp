#include "Parameter.h"

using namespace std;

Parameter::Parameter(const std::string & name, const std::string & type,
        Expression* content, bool isConst):
    CommonVar(name, type, content, true, "", isConst), mIsLastOneOfList(true)
{
    debugNode("Parameter : "+ translateType() +"_"+ mName, AT);
}


string Parameter::preTranslate() const
{
    return CommonVar::preTranslate() + (!mIsLastOneOfList ? ", " : "");
}

void Parameter::addRightChild(Node* child)
{
    Node::addRightChild(child);
    mIsLastOneOfList= false;
}