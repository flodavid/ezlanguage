#include "ClassDeclaration.h"

using namespace std;



ClassDeclaration::ClassDeclaration(): HashElement(""), _baseClass("")
{}



ClassDeclaration::ClassDeclaration(const string& identifer): HashElement(identifer), _baseClass("")
{}



ClassDeclaration::ClassDeclaration(const string& identifer, const string& baseClass): HashElement(identifer), _baseClass(baseClass)
{}



ClassDeclaration::ClassDeclaration(const ClassDeclaration& c): HashElement(c.get_id()), _baseClass(c.getBaseClass())
{}



void ClassDeclaration::print(std::ostream& flux) const
{
  HashElement::print(flux);
  if (!_baseClass.empty()) flux << endl << "Classe mère : " << _baseClass;
  else flux << endl << "Aucune classe mère";
}



bool operator==(const ClassDeclaration& c1, const ClassDeclaration& c2)
{
  return c1.is_equal(c2);
}



bool operator!=(const ClassDeclaration& c1, const ClassDeclaration& c2)
{
  return (!c1.is_equal(c2));
}



std::ostream& operator<<(std::ostream& flux, const ClassDeclaration& element)
{
  element.print(flux);
  return flux;
}

