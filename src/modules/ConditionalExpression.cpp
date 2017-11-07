//@author : GINISTY Valentin && GARNIER Antoine
#include "ConditionalExpression.h"

using namespace std;

ConditionalExpression::ConditionalExpression(Node * left, Node * right, const string & operateur_unaire, const ConditionalExpression* operande):
        Node(left, right), operateur(operateur_unaire), valeur(""), left_part(operande), right_part(nullptr)
{ }
ConditionalExpression::ConditionalExpression(Node * left, Node * right, const string & operateur_binaire, const ConditionalExpression* left_operande, const ConditionalExpression* right_operande):
        Node(left, right), operateur(operateur_binaire), valeur(""), left_part(left_operande), right_part(right_operande)
{
}
ConditionalExpression::ConditionalExpression(Node * left, Node * right, const string & operande):
        Node(left, right), operateur(""), valeur(operande), left_part(nullptr), right_part(nullptr)
{

}

string ConditionalExpression::preTranslate() const {
    string res= "";
    //cas où on a trois arguments
    if(right_part != nullptr) {
        cout << "cas trois arguments" << endl;
        res = res + left_part->translate() + operateur + right_part->translate();
    }
    //cas unaire
    else if(operateur != ""){
        cout << "cas unaire" << endl;
        res = operateur + left_part->translate();
    }
        //cas où on a juste une valeur
    else {
        cout << "cas  valeur" << endl;
        res = res + valeur;
    }
    return res;
};
