#include "ConvertNode.h"

using namespace std;

ConvertNode::ConvertNode(string functionName, Expression* expressionToConvert):
    Expression(expressionToConvert, nullptr), mFunctionName(functionName)
{ }


string ConvertNode::preTranslate() const
{
    return mFunctionName +"(";
}

string ConvertNode::postTranslate() const
{
    return ")";
}
