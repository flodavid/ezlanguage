#include "Affectation.h"

using namespace std;

Affectation::Affectation(string & varName, Operator* ope, Expression* value):
	Node(nullptr, nullptr), mTarget(varName), mOperator(ope), mAffectedValue(value)
{ }

Affectation::~Affectation()
{
    delete mOperator;
    delete mAffectedValue;
}


string Affectation::preTranslate() const
{
    return mTarget + mOperator->translate() + mAffectedValue->translate() + ";\n";
}
