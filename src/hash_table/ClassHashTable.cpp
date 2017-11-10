#include "ClassHashTable.h"

using namespace std;

ClassHashTable::ClassHashTable(): HashTable< ClassHashed >()
{}



ClassHashTable::ClassHashTable(int size): HashTable< ClassHashed >(size)
{}



bool ClassHashTable::contains(const string& id) const
{
    ClassHashed cd(id);
    return HashTable::contains(cd, id);
}



bool ClassHashTable::isParentClass(const string& parentClass, const ClassHashed& Class) const
{
  bool haveParentClass;
  
  bool isParentClass = false;
  
  string currentParentClassName = Class.getBaseClass();
  
  if (currentParentClassName.empty()) haveParentClass = false;
  else haveParentClass = true;
  
  int index;
  while (haveParentClass&&(!isParentClass)) {
    if (currentParentClassName == parentClass) isParentClass = true;
    else {
      index = hash(currentParentClassName);
      bool found = false;
      for (auto it = this->at(index).begin(); (it != this->at(index).end())&&(!found); ++it) {
	if (it->get_id() == currentParentClassName) {
	  found = true;
	  currentParentClassName = it->getBaseClass();
	  if (currentParentClassName.empty()) haveParentClass = false;
	}
      }
    }
  }
  return isParentClass;
}
