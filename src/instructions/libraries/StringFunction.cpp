#include "StringFunction.h"

using namespace std;

StringFunction::StringFunction(StringFunctionName functionName):
	Instruction(nullptr, nullptr), mFunctionName(functionName), nbArgs(0)
{ }

StringFunction::StringFunction(StringFunctionName functionName, int intArg):
	Instruction(nullptr, nullptr), mFunctionName(functionName), mFirstArg(intArg),
    nbArgs(1)
{ }

StringFunction::StringFunction(StringFunctionName functionName, int firstArg, int secondArg):
	Instruction(nullptr, nullptr), mFunctionName(functionName), mFirstArg(firstArg),
    mSecondArg(secondArg), nbArgs(2)
{ }

string StringFunction::preTranslate() const
{
    string result = indentationText() + mFunctionName + "(" ;
    nbArgs > 0 ? result += mFirstArg;
    nbArgs > 1 ? result += ", "+ mSecondArg;
    result += ")";
    return result;
}
