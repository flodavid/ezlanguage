//@author Antoine GARNIER
#include "Repeat.h"

using namespace std;

Repeat::Repeat(Node * left, ConditionalExpression * cond):
    Node(left, nullptr), mCondition(cond)
{}

Repeat::~Repeat()
{
    delete mCondition;
}

string Repeat::preTranslate() const
{
    return "do {\n";
}

string Repeat::postTranslate() const
{
    return "} while(" + mCondition->translate() + ");\n";
}
