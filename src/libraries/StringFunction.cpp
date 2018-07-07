#include "StringFunction.h"

using namespace std;

StringFunction::StringFunction(const string & objectName, StringFunctionName functionName):
    FunctionCall(StringFunctionNameStrings[functionName], nullptr, objectName)
{ }

StringFunction::StringFunction(const string & objectName, StringFunctionName functionName, Expression* arg):
    FunctionCall(StringFunctionNameStrings[functionName], arg, objectName)
{ }

StringFunction::StringFunction(const string & objectName, StringFunctionName functionName, Expression* firstArg, Expression* secondArg):
    FunctionCall(StringFunctionNameStrings[functionName], firstArg, objectName)
{
    firstArg->addRightChild(secondArg);
}
