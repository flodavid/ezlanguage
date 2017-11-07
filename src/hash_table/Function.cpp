#include "Function.h"

using namespace std;



Function::Function(): HashElement(), _parameters(), _returnType(""), _class("")
{}


Function::Function(const std::string &id, const std::vector< std::string > &param, const std::string &rtype, const std::string &className): HashElement(id), _parameters(param), _returnType(rtype), _class(className)
{}


Function::Function(const Function& f): HashElement(f.get_id()), _parameters(f.get_param()), _returnType(f.get_returnType()), _class(f.get_class())
{}



bool Function::isMethodOf(const string& className) const
{
  return (_class == className);
}



bool Function::is_equal(const Function& f) const
{
  bool equal = true;
  if ((HashElement::is_equal(f))&&(_class == f.get_class())&&(_returnType == f.get_returnType())&&(_parameters.size() == f.get_param().size())) {
    
    for (unsigned int i = 0; (i < _parameters.size())&&equal; ++i) {
      if (_parameters[i] != f.get_param()[i]) equal = false;
    }
    
  } 
  else equal = false;
  
  return equal;
}



void Function::print(ostream& flux) const
{
  if (_class.empty()) { // Function or procedure
    if (_returnType.empty()) { // procedure
      flux << "Procedure :" << endl;
      HashElement::print(flux);
      flux << endl << "Parameter(s) : ";
      if (_parameters.size() > 0) {
	for (unsigned int i = 0 ; i < (_parameters.size() - 1); ++i) flux << _parameters[i] << " , ";
	flux << _parameters[_parameters.size() - 1];
      }
    }
    else { // Function
      flux << "Function :" << endl;
      HashElement::print(flux);
      flux << endl << "Parameter(s) : ";
      if (_parameters.size() > 0) {
	for (unsigned int i = 0 ; i < (_parameters.size() - 1); ++i) flux << _parameters[i] << " , ";
	flux << _parameters[_parameters.size() - 1] << endl;
      }
      flux << "Type of returned value : " << _returnType;
    }
  }
  else { // Method of class
    
    flux << "Method of the class \"" << _class << "\" : " << endl;
    HashElement::print(flux);
    flux << endl << "Parameter(s) : ";
    
    if (_parameters.size() > 0) {
      for (unsigned int i = 0 ; i < (_parameters.size() - 1); ++i) flux << _parameters[i] << " , ";
      flux << _parameters[_parameters.size() - 1] << endl;
    } 
    else flux << endl;
    
    if (_returnType.empty()) {
      flux << "No returned value";
    }
    else {
      flux << "Type of returned value : " << _returnType;
    }
    
  }
}



ostream& operator<<(ostream& flux, const Function& f)
{
  f.print(flux);
  return flux;
}



bool operator==(const Function& f1, const Function& f2)
{
  return (f1.is_equal(f2));
}



bool operator!=(const Function& f1, const Function& f2)
{
  return (!f1.is_equal(f2));
}

