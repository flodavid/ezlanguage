#include "Method.h"

using namespace std;

Method::Method(const string & name, Node * parameters, Node * left):
    CommonDeclaration(left, name), mParameters(parameters)
{ }