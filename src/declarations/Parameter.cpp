#include "Parameter.h"

using namespace std;

Parameter::Parameter(const string & type, const string & name):
    CommonDeclaration(nullptr, name), mType(type)
{
    debugNode("Parameter : "+ type +"_"+ name, AT);
}

string Parameter::preTranslate() const
{
    return mType +" "+ mName;
}
