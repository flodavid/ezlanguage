#include "CommonDeclaration.h"

using namespace std;

CommonDeclaration::CommonDeclaration(Node * left, const string & name):
    Node(left, nullptr), mName(name)
{ }