#include "FunctionCall.h"

using namespace std;

FunctionCall::FunctionCall(const string & functionName, Expression * arguments,
        Expression* objectExpression):
    Node(nullptr, nullptr), mObjectExpression(objectExpression), mFunctionName(functionName),
    mArguments(arguments), mHasAnOtherFunctionCall(false)
{ }

FunctionCall::FunctionCall(FunctionCall * other):
    Node(nullptr, nullptr), mObjectExpression(other->mObjectExpression), mFunctionName(other->mFunctionName),
    mArguments(other->mArguments), mHasAnOtherFunctionCall(other->mHasAnOtherFunctionCall)
{
    // Deassociate arguments and object from old function call
    other->mArguments= nullptr;
    other->mObjectExpression= nullptr;
    delete other;
}


FunctionCall::~FunctionCall()
{
    delete mArguments;
    delete mObjectExpression;
}

void FunctionCall::setObject(Expression* objectExpression)
{
    if (mObjectExpression) {
        error("The function already applied on an object. The previous one will be delete (not a normal behavior, contact the application developper)", AT);
        delete mObjectExpression;
    }
    if (objectExpression == nullptr) debugNode("The new object is null", AT);
    else debugNode("New object the function applies on affected : " + objectExpression->getName() + ": "+ objectExpression->translate(), AT);
    mObjectExpression = objectExpression;
}

void FunctionCall::addFunctionCall(FunctionCall* otherFunctionCall)
{
    mHasAnOtherFunctionCall= true;
    addRightChild(otherFunctionCall);
}

string FunctionCall::preTranslate() const
{
    string res= "";

    if (mObjectExpression != nullptr) {
        debugNode(mObjectExpression->getName(), AT);
        debugNode(mObjectExpression->getDetails(), AT);
        string object_translation= mObjectExpression->translate();
        if (object_translation != "") res+= object_translation +".";
    }
    res+= mFunctionName +"(";
    if (mArguments != nullptr) {
        res+= mArguments->translate();
        debugNode("mArguments translation: "+ mArguments->translate(), AT);
    } 
    res+= ")";

    if (mHasAnOtherFunctionCall) res+= ".";
    
    return res;
}
