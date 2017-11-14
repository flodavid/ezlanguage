#include "VariableHashed.h"

using namespace std;


VariableHashed::VariableHashed():
        HashElement(), _type(""), _scope(0), _const(false), _static(false)
{}


VariableHashed::VariableHashed(const string & i, const string & t, bool c):
        HashElement(i), _type(t), _scope(0), _const(c), _static(false)
{}


VariableHashed::VariableHashed(const string & i, const string & t, bool c, bool s):
        HashElement(i), _type(t), _scope(0), _const(c), _static(s)
{}


VariableHashed::VariableHashed(const VariableHashed& v):
        HashElement(v), _type(v.get_type()), _scope(v.get_scope()), _const(v.is_const()), _static(v.is_static())
{}

VariableHashed::~VariableHashed()
{};


bool VariableHashed::is_equal(const VariableHashed& v) const
{
        return ((HashElement::is_equal(v)) && (v.get_type() == _type) && (v.get_scope() == _scope));
}


bool operator==(const VariableHashed& v1, const VariableHashed& v2)
{
        return (v1.is_equal(v2));
}


bool operator!=(const VariableHashed& v1, const VariableHashed& v2)
{
    return (!v1.is_equal(v2));
}


void VariableHashed::print(ostream& flux) const
{
    HashElement::print(flux);
    flux << "  ;  type = " << _type << "  ;  scope = " << _scope;
    if (_const) flux << "  ;  const";
    else flux << "  ;  not const";
    if (_static) flux << "  ;  static";
    else flux << "  ;  not static";
}



ostream& operator<<(ostream& flux, const VariableHashed& element)
{
    element.print(flux);
    return flux;
}
