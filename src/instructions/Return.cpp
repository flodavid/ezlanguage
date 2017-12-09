#include "Return.h"

using namespace std;

Return::Return(Expression * expression):
	Node(nullptr, nullptr), mExpression(expression)
{ }

Return::~Return()
{
    delete mExpression;
}


string Return::preTranslate() const
{
    return "return "+ mExpression->translate();
}   
