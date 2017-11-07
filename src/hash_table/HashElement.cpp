#include "HashElement.h"

using namespace std;


HashElement::HashElement(): _id("")
{}



HashElement::HashElement(const string & s): _id(s)
{}



HashElement::HashElement(const HashElement & e): _id(e.get_id())
{}



bool HashElement::is_equal(const HashElement& e) const
{
  return (e.get_id() == _id);
}



bool operator==(const HashElement& e1, const HashElement& e2)
{
  return (e1.is_equal(e2));
}



bool operator!=(const HashElement& e1, const HashElement& e2)
{
  return (!e1.is_equal(e2));
}

