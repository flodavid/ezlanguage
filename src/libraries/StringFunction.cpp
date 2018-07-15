#include "StringFunction.h"

using namespace std;

StringFunction::StringFunction(Expression* objectExpression, StringFunctionName functionName):
    FunctionCall(StringFunctionNameStrings[functionName], nullptr, objectExpression)
{ }

StringFunction::StringFunction(Expression* objectExpression, StringFunctionName functionName, Expression* arg):
    FunctionCall(StringFunctionNameStrings[functionName], arg, objectExpression)
{ }

StringFunction::StringFunction(Expression* objectExpression, StringFunctionName functionName, Expression* firstArg, Expression* secondArg):
    FunctionCall(StringFunctionNameStrings[functionName], firstArg, objectExpression)
{
    firstArg->addRightChild(secondArg);
}
