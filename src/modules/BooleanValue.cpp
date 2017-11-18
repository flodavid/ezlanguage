#include "BooleanValue.h"

using namespace std;

BooleanValue::BooleanValue(bool boolean):
    ConditionalExpression(nullptr, nullptr, "Boolean-litteral"), value(boolean)
{ }

BooleanValue::BooleanValue(const std::string & name):
    ConditionalExpression(nullptr, nullptr, "Boolean-variable")
{

}

string BooleanValue::preTranslate() const {
    string res;

    // Set the boolean string accord to its value (true or false)
    if (value) res= "true";
    else res= "false";

    return res;
}
