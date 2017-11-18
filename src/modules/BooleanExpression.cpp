//@author : GINISTY Valentin && GARNIER Antoine
#include "BooleanExpression.h"

using namespace std;

BooleanExpression::BooleanExpression(const string & operande):
    ConditionalExpression(nullptr, nullptr), strOperator(""), valeur(operande), left_part(nullptr), right_part(nullptr)
{ }

BooleanExpression::BooleanExpression(const string & unary_operator, const ConditionalExpression* operande):
    ConditionalExpression(nullptr, nullptr), strOperator(unary_operator), valeur(""), left_part(operande), right_part(nullptr)
{ }

BooleanExpression::BooleanExpression(const string & binary_operator, const ConditionalExpression* first_operande,
        const ConditionalExpression* second_operande):
    ConditionalExpression(nullptr, nullptr), strOperator(binary_operator), valeur(""), left_part(first_operande),
    right_part(second_operande)
{ }

string BooleanExpression::preTranslate() const {
    string res= "";
    //cas où on a trois arguments
    if(right_part != nullptr) {
        debug("cas trois arguments", AT);
        res = res + left_part->translate() +" "+ strOperator +" "+ right_part->translate();
    }
    //cas unaire
    else if(strOperator != ""){
        debug("cas unaire", AT);
        res = strOperator + left_part->translate();
    }
        //cas où on a juste une valeur
    else {
        debug("cas  valeur", AT);
        res = res + valeur;
    }
    return res;
}
