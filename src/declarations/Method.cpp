#include "Method.h"

using namespace std;

Method::Method(const string & name, Node * parameters, Node * instructions):
    CommonDeclaration(instructions, name), mParameters(parameters)
{ }