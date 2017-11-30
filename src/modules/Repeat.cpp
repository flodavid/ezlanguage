//@author Antoine GARNIER
#include "Repeat.h"

using namespace std;

Repeat::Repeat(Node * left, Node* right , Node * cond):
    Node(left, right), condition(cond)
{}

string Repeat::preTranslate() const
{
    return "do {\n";
}

string Repeat::postTranslate() const
{
    return "} while(" + condition->translate() + ");\n";
}
