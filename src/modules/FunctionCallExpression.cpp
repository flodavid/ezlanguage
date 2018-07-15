#include "FunctionCallExpression.h"

using namespace std;

FunctionCallExpression::FunctionCallExpression(FunctionCall* callToTransform):
    FunctionCall(callToTransform), Expression(nullptr, nullptr)
{ }


string FunctionCallExpression::preTranslate() const
{
    return FunctionCall::preTranslate();
}
