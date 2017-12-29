#include "Expression.h"

using namespace std;

Expression::Expression():
    Node(nullptr, nullptr)
{ }

Expression::Expression(Node* left, Node* right):
    Node(left, right)
{ }
