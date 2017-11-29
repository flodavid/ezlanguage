#include "BooleanValue.h"

using namespace std;

BooleanValue::BooleanValue(bool boolean):
    value(boolean), isLitteral(false), mLitteralName("")
{ }

BooleanValue::BooleanValue(const std::string & litteralName):
    value(false), isLitteral(true), mLitteralName(litteralName)
{ }

string BooleanValue::preTranslate() const {
    string res;

    if (isLitteral) res= mLitteralName;

    // Set the boolean string accord to its value (true or false)
    if (value) res= "true";
    else res= "false";

    return res;
}
