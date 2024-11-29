#include "HashTable.h"

unsigned int HashTable::hash(const std::string & id_variable) const
{
	if (this->size() == 0) return 0;
	else {
		int sum = 0;
		int remainder = 0;

		for (unsigned int i = 0; i < id_variable.size(); ++i) {
			sum += (int) id_variable[i];
		}

		remainder = sum % this->size();
		return remainder;
	}
};

void HashTable::addElement(const T & element, const std::string & id)
{
	if (this->empty()) throw std::string("Error, can not add an element because the hash table is empty");
	else if (this->contains(element, id)) throw std::string("Element "+ id + " already defined");
	else {
		int index = hash(id);
		this->at(index).push_front(element);
	}
};

void HashTable::removeElement(const T & element, const std::string & id)
{
	int index = hash(id);
	bool found = false;
	for (auto it = this->at(index).begin(); (it != this->at(index).end()) && (!found); ++it) {
		if (*it == element) {
			this->at(index).erase(it);
			found = true;
		}
	}
	if (!found) throw std::string("Error, the element to be removed is not in the hash table");
};

void HashTable::removeElement(typename std::list<T>::iterator & it, const std::string & id)
{
	int index = hash(id);
	this->at(index).erase(it);
};

bool HashTable::contains(const T & element, const std::string & id) const
{
	int index = hash(id);
	bool found = false;
	for (auto it = this->at(index).begin(); (it != this->at(index).end()) && (!found); ++it) {
		if (*it == element) found = true;
	}
	return found;
};

void HashTable::print() const
{
	for (unsigned int i = 0; i < this->size(); ++i) {
		std::cout << "Ligne " << i << " : " << std::endl;

		typename std::list<T>::const_iterator it;

		for (it = this->at(i).begin(); it != this->at(i).end(); ++it) {
			std::cout << *it << std::endl;
		}

		std::cout << std::endl;
	}
};
