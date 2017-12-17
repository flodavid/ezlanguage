#include "FunctionCall.h"

using namespace std;

FunctionCall::FunctionCall(const std::string & functionName, Node * arguments):
	Node(nullptr, nullptr), mFunctionName(functionName), mArguments(arguments)
{ }

FunctionCall::~FunctionCall()
{
    delete mArguments;
}


string FunctionCall::preTranslate() const
{
    string res= mFunctionName +"("+ mArguments->translate() +");\n";
    
    return res;
}
