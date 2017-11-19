//@author : GINISTY Valentin && GARNIER Antoine
#include "BooleanExpression.h"

using namespace std;

BooleanExpression::BooleanExpression(const string & operande):
    ConditionalExpression(nullptr, nullptr), strOperator(""), value(operande), left_part(nullptr), right_part(nullptr)
{ }

BooleanExpression::BooleanExpression(const string & unary_operator, const ConditionalExpression* operande):
    ConditionalExpression(nullptr, nullptr), strOperator(unary_operator), value(""), left_part(operande), right_part(nullptr)
{ }

BooleanExpression::BooleanExpression(const string & binary_operator, const ConditionalExpression* first_operande,
        const ConditionalExpression* second_operande):
    ConditionalExpression(nullptr, nullptr), strOperator(binary_operator), value(""), left_part(first_operande),
    right_part(second_operande)
{ }

string BooleanExpression::preTranslate() const {
    string res= "";
    // Two operandes case
    if(right_part != nullptr) {
        debug("Cond. Expr.: binary operator", AT);
        res+= left_part->translate() +" "+ strOperator +" "+ right_part->translate();
    }
    // Unary case
    else if(strOperator != ""){
        debug("Cond. Expr.: unary operator", AT);
        res+= strOperator + left_part->translate();
    }
    // Case where we just have a value
    else {
        debug("Cond. Expr., just value", AT);
        res+= value;
    }
    return res;
}
