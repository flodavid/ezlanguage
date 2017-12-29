//@author : GINISTY Valentin && GARNIER Antoine
#include "BooleanExpression.h"

using namespace std;

BooleanExpression::BooleanExpression(const string & operande):
    mOperator(nullptr), value(operande), left_part(nullptr), right_part(nullptr)
{ }

BooleanExpression::BooleanExpression(Operator* unary_operator, const ConditionalExpression* operande):
    mOperator(unary_operator), value(""), left_part(nullptr), right_part(operande)
{ }

BooleanExpression::BooleanExpression(Operator* binary_operator, const ConditionalExpression* first_operande,
        const ConditionalExpression* second_operande):
    mOperator(binary_operator), value(""), left_part(first_operande),
    right_part(second_operande)
{ }

BooleanExpression::BooleanExpression(Operator* relational_operator, const Expression* first_expression,
        const Expression* second_expression):
    mOperator(relational_operator), value(""), left_part(first_expression),
    right_part(second_expression)
{ }

BooleanExpression::~BooleanExpression()
{
    delete mOperator;
}

string BooleanExpression::preTranslate() const {
    string res= "";

    if (value != "") {
        debug("Cond. Expr., just value", AT);
        res+= value;
    } else {
        // Two operandes case
        if(left_part != nullptr) {
            debug("Cond. Expr.: binary operator", AT);
            res+= left_part->translate() +" ";
        }
        if(right_part != nullptr && mOperator != nullptr) res+= mOperator->translate() + " "+ right_part->translate();
        // There is no right part or operator whereas there is a left part
        else error("BooleanExpression is not correctly initialized (no operator or right part)", AT);
    }
    return res;

}
