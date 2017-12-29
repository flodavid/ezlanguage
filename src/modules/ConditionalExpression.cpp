#include "ConditionalExpression.h"

using namespace std;

ConditionalExpression::ConditionalExpression():
    Expression()
{ }

ConditionalExpression::ConditionalExpression(Node* left, Node* right):
    Expression(left, right)
{ }
