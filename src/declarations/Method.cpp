#include "Method.h"
#include "../modules/EmptyNode.h"

using namespace std;

Method::Method(const string & name, Node * parameters, Node * instructions):
    CommonDeclaration(instructions, name), mParameters(parameters)
{ }

const Node* Method::getParameters() const
{
    if (mParameters != nullptr) return nullptr;
    return mParameters;
}

string Method::translateParameters() const
{
    if (mParameters == nullptr) return "";
    else return mParameters->translate();
}