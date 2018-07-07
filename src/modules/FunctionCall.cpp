#include "FunctionCall.h"

using namespace std;

FunctionCall::FunctionCall(const string & functionName, Expression * arguments,
        const string & objectName):
	Node(nullptr, nullptr), mObjectName(objectName), mFunctionName(functionName),
    mArguments(arguments), mHasAnOtherFunctionCall(false)
{ }

FunctionCall::FunctionCall(FunctionCall * other):
	Node(nullptr, nullptr), mObjectName(other->mObjectName), mFunctionName(other->mFunctionName),
    mArguments(other->mArguments), mHasAnOtherFunctionCall(other->mHasAnOtherFunctionCall)
{
	// Deassociate arguments from old function call
	other->mArguments= nullptr;
    delete other;
}


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
    if (mArguments != nullptr) {
        res+= mArguments->translate();
        debugNode("mArguments translation: "+ mArguments->translate(), AT);
    } 
    res+= ")";

    if (mHasAnOtherFunctionCall) res+= ".";
    
    return res;
}
