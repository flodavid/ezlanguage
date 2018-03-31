#include "FunctionCall.h"

using namespace std;

FunctionCall::FunctionCall(const string & functionName, Expression * arguments):
	Expression(nullptr, nullptr), mObjectName(""), mFunctionName(functionName),
    mArguments(arguments), mHasAnOtherFunctionCall(false), mIsInstruction(true)
{ }

FunctionCall::FunctionCall(const string & objectName, const string & functionName,
                        Expression * arguments):
	Expression(nullptr, nullptr), mObjectName(objectName), mFunctionName(functionName),
    mArguments(arguments), mHasAnOtherFunctionCall(false), mIsInstruction(true)
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
	// TODO check return type to convert to string only if useful
    string res= "";
	if (isString) res+= "std::to_string(";

    if (mObjectName != "") res+= mObjectName +".";
    res+= mFunctionName +"(";
    if (mArguments != nullptr) {
        res+= mArguments->translate();
        debugNode("mArguments translation: "+ mArguments->translate(), AT);
    } 
    res+= ")";
    
	if (isString) res+= ")";
    if (mHasAnOtherFunctionCall) res+= ".";
    else if (mIsInstruction) res+= ";\n";
    
    return res;
}
