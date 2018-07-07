#include "CommonDeclaration.h"

using namespace std;

CommonDeclaration::CommonDeclaration(Node * left, const string & name):
    Instruction(left), mName(name)
{ }