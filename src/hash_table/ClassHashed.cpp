#include "ClassHashed.h"

using namespace std;



ClassHashed::ClassHashed(): HashElement(""), _baseClass("")
{}



ClassHashed::ClassHashed(const string& identifer): HashElement(identifer), _baseClass("")
{}



ClassHashed::ClassHashed(const string& identifer, const string& baseClass): HashElement(identifer), _baseClass(baseClass)
{}



ClassHashed::ClassHashed(const ClassHashed& c): HashElement(c.get_id()), _baseClass(c.getBaseClass())
{}



void ClassHashed::print(std::ostream& flux) const
{
  HashElement::print(flux);
  if (!_baseClass.empty()) flux << endl << "Classe mère : " << _baseClass;
  else flux << endl << "Aucune classe mère";
}



bool operator==(const ClassHashed& c1, const ClassHashed& c2)
{
  return c1.is_equal(c2);
}



bool operator!=(const ClassHashed& c1, const ClassHashed& c2)
{
  return (!c1.is_equal(c2));
}



std::ostream& operator<<(std::ostream& flux, const ClassHashed& element)
{
  element.print(flux);
  return flux;
}

