#include "ConditionalExpression.h"

using namespace std;

ConditionalExpression::ConditionalExpression():
    Node(nullptr, nullptr)
{ }

ConditionalExpression::ConditionalExpression(Node* left, Node* right):
    Node(left, right)
{ }
