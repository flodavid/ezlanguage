//@author : GINISTY Valentin && GARNIER Antoine
#include "BooleanExpression.h"

using namespace std;

BooleanExpression::BooleanExpression(const Expression * operande):
    mOperator(nullptr), mValue(operande), left_part(nullptr), right_part(nullptr)
{ }

BooleanExpression::BooleanExpression(Operator* unary_operator, const ConditionalExpression* operande):
    mOperator(unary_operator), mValue(nullptr), left_part(nullptr), right_part(operande)
{ }

BooleanExpression::BooleanExpression(Operator* binary_operator, const ConditionalExpression* first_operande,
        const ConditionalExpression* second_operande):
    mOperator(binary_operator), mValue(nullptr), left_part(first_operande),
    right_part(second_operande)
{ }

BooleanExpression::BooleanExpression(Operator* relational_operator, const Expression* first_expression,
        const Expression* second_expression):
    mOperator(relational_operator), mValue(nullptr), left_part(first_expression),
    right_part(second_expression)
{ }

BooleanExpression::~BooleanExpression()
{
    if (mOperator) delete mOperator;
    if (mValue) delete mValue;
    if (left_part) delete left_part;
    if (right_part) delete right_part;
}

string BooleanExpression::preTranslate() const {
    string res= "( ";

    if (mValue != nullptr) {
        debugNode("Cond. Expr., just value", AT);
        res+= mValue->translate();
    } else {
        // Two operandes case
        if(left_part != nullptr) {
            res+= left_part->translate() +" ";
        }
        if(right_part != nullptr && mOperator != nullptr) {
            debugNode("Cond. Expr.: binary operator", AT);
            res+= mOperator->translate() + " "+ right_part->translate();
        }
        // There is no right part or operator whereas there is a left part
        else error("BooleanExpression is not correctly initialized (no operator or right part)", AT);
        
    }

    res+= " )";
    
    return res;

}
