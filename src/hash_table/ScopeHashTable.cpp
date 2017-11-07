#include "ScopeHashTable.h"

using namespace std;

ScopeHashTable::ScopeHashTable(): HashTable< Variable >(), _scopeStack(), _currentScope(0)
{
  list<list<Variable>::iterator> l;
  _scopeStack.push(l);
}



ScopeHashTable::ScopeHashTable(unsigned int size): HashTable< Variable >(size), _scopeStack(), _currentScope(0)
{
  list<list<Variable>::iterator> l;
  _scopeStack.push(l);
}



ScopeHashTable::ScopeHashTable(const ScopeHashTable& table): HashTable< Variable >(table), _scopeStack(table.get_scopeStack()), _currentScope(table.get_currentScope())
{}



void ScopeHashTable::incScope()
{
  _currentScope += 1;
  list<list<Variable>::iterator> l;
  _scopeStack.push(l);
}



void ScopeHashTable::decScope()
{
    if (_currentScope == 0) throw string("Can not have a scope less than zero");
    else {
	list<list<Variable>::iterator>::iterator it;
	int index;
	for (it = _scopeStack.top().begin(); it != _scopeStack.top().end(); ++it) {
	    index = hash( (*it)->get_id() );
	    this->at(index).erase(*it);
	}
	_scopeStack.pop();
	_currentScope -= 1;
    }
}



void ScopeHashTable::addElement(Variable& v)
{
  if (this->empty()) throw string("Error, can not add a Variable because the size of the hash table is null");
  else if (this->contains(v.get_id(), _currentScope)) throw string("Variable "+v.get_id()+" already defined");
  else {
    int index = hash(v.get_id());
    if (v.is_static()) {
    	v.set_scope(0);
    	this->at(index).push_front(v);
    }
    else {
    	v.set_scope(_currentScope);
    	this->at(index).push_front(v);
    	_scopeStack.top().push_front(this->at(index).begin());
    }
  }
}



string ScopeHashTable::get_type(const string& id) const
{
    int index = hash(id);
    string type = "";
    bool found = false;
    for (auto it = this->at(index).begin(); (it != this->at(index).end())&&(!found); ++it) {
	if (it->get_id() == id) {
	    type = it->get_type();
	    found = true;
	}
    }
    if (!found) throw string(id + " not found");
	return type;
    }



bool ScopeHashTable::contains(const string& id) const
{
    int index = hash(id);
    bool found = false;
    for (auto it = this->at(index).begin(); (it != this->at(index).end())&&(!found); ++it) {
	if (it->get_id() == id) found = true;
    }
    return found;
}



bool ScopeHashTable::contains(const string& id, unsigned int s) const
{
    int index = hash(id);
    bool found = false;
    for (auto it = this->at(index).begin(); (it != this->at(index).end())&&(!found); ++it) {
	if ((it->get_id() == id) && (it->get_scope() == s)) found = true;
    }
    return found;
}
