#include "Affectation.h"

using namespace std;

Affectation::Affectation(string & varName, Operator* ope, Expression* value):
	Instruction(nullptr, nullptr), mTarget(varName), mOperator(ope), mAffectedValue(value)
{ }

Affectation::~Affectation()
{
    delete mOperator;
    delete mAffectedValue;
}


string Affectation::preTranslate() const
{
    return indentationText() + mTarget + mOperator->translate() + mAffectedValue->translate() + ";\n";
}
