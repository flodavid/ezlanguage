#include "FunctionCall.h"

using namespace std;

FunctionCall::FunctionCall(const string & functionName, Node * arguments):
	Node(nullptr, nullptr), mObjectName(""), mFunctionName(functionName),
    mArguments(arguments), mHasAnOtherFunctionCall(false)
{ }

FunctionCall::FunctionCall(const string & objectName, const string & functionName,
                        Node * arguments):
	Node(nullptr, nullptr), mObjectName(objectName), mFunctionName(functionName),
    mArguments(arguments), mHasAnOtherFunctionCall(false)
{ }

FunctionCall::~FunctionCall()
{
    delete mArguments;
}

void FunctionCall::addFunctionCall(FunctionCall* otherFunctionCall)
{
    mHasAnOtherFunctionCall= true;
    addRightChild(otherFunctionCall);
}

string FunctionCall::preTranslate() const
{
    string res= "";
    if (mObjectName != "") res+= mObjectName +".";
    res+= mFunctionName +"(";
    if (mArguments != nullptr) res+= mArguments->translate();
    debugNode("mArguments translation: "+ mArguments->translate(), AT);
    res+= ");\n";
    if (mHasAnOtherFunctionCall) res+= ".";
    
    return res;
}
