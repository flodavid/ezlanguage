#include "Return.h"

using namespace std;

Return::Return(Expression * expression):
	Instruction(nullptr, nullptr), mExpression(expression)
{ }

Return::~Return()
{
    delete mExpression;
}


string Return::preTranslate() const
{
    return indentationText() +"return "+ mExpression->translate();
}   
