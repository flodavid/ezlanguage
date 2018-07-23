#include "Method.h"

using namespace std;

Method::Method(const string & name, Node * parameters, Instruction * instructions):
    CommonDeclaration(instructions, name), mParameters(parameters)
{ }

Method::~Method()
{
    if (mParameters) delete mParameters;
}


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