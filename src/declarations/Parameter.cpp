#include "Parameter.h"

using namespace std;

Parameter::Parameter(const std::string & name, const std::string & type,
        const Node* content, bool co):
    CommonVar(name, type, "", content, co), mIsLastOneOfList(true)
{
    debugNode("Parameter : "+ mType +"_"+ mName, AT);
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