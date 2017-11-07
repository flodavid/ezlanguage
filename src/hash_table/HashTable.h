#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <string>

#define DEFAULT_SIZE 50

/**
 * @brief An hash table which can contains any type of element that contain the operator operator==
 * @author Johan Defaye
 * 
 */
template <typename T>
class HashTable : public std::vector<std::list<T> > {
   
public:
  
  
  
  /* * * * * * * * *
   * CONSTRUCTORS  *
   * * * * * * * * */
  
  
  /**
   * Default constructor
   * @author Johan Defaye
   */
  HashTable() {this->resize(DEFAULT_SIZE);}
  
  /**
   * Constructor with parameters
   * @brief Initialize the hash table with a given size
   * @param size : size of the HashTable
   * @author Johan Defaye
   */
  HashTable(unsigned int size) {this->resize(size);}
  
  /**
   * Copy constructor
   * @brief Initialize a hash table with the elements of another hash table
   * @param h : another hash table
   * @author Johan Defaye
   */
  HashTable(const HashTable &h) {*this = h;}
  
  
  
  /* * * * * *
   * METHODS *
   * * * * * */
  
  
  /**
   * @brief Give the hash code of an identifier passed as parameter
   * @param id_variable : identifier of the id_variable
   * @return unsigned int
   * @author Johan Defaye
   */
  unsigned int hash(const std::string & id_variable) const 
  {
    if (this->size() == 0) return 0;
    else {
      int sum = 0;
      int remainder = 0;
      
      for (unsigned int i = 0; i < id_variable.size(); ++i){
	sum += (int) id_variable[i]; 
      }
      
      remainder = sum % this->size();
      return remainder;
    }
  }
  
  /**
   * @brief Add an element in the hash table with the specified identifier
   * Throw an error if the size of the hash table is null
   * @param element : an hash element
   * @param id : an identifier of the hash element to add
   * @exception : Return a string as exception if the hash table is empty
   * @author Johan Defaye
   */
  void addElement(const T & element, const std::string & id)
  {
    if (this->empty()) throw std::string("Error, can not add an element because the hash table is empty");
    else if (this->contains(element, id)) throw std::string("Element "+ id + " already defined");
    else {
      int index = hash(id);
      this->at(index).push_front(element);
    }
  }
  
  /**
   * @brief Remove an element from the hash table with the specified identifier
   * @param element : an hash element
   * @param id : an identifier of the hash element to remove
   * @exception : Return a string as exception if the element to be removed is not in the hash table
   * @author Johan Defaye
   */
  void removeElement(const T & element, const std::string & id)
  {
    int index = hash(id);
    bool found = false;
    for (auto it = this->at(index).begin(); (it != this->at(index).end())&&(!found); ++it) {
      if (*it == element) {
	this->at(index).erase(it);
	found = true;
      }
    }
    if (!found) throw std::string("Error, the element to be removed is not in the hash table");
  }
  
  /**
   * @brief Remove an element from the hash table with the specified iterator and identifier
   * @param it : iterator of the element to remove
   * @param id : an identifier of the hash element to remove
   * @author Johan Defaye
   */
  void removeElement(typename std::list<T>::iterator & it, const std::string & id)
  {
    int index = hash(id);
    this->at(index).erase(it);
  }
  
  /**
   * @brief Test if an element is in the hash table
   * @param element : an element
   * @param id : indetifier of the element
   * @return boolean
   * @author Johan Defaye
   */
  bool contains(const T & element, const std::string & id) const {
    int index = hash(id);
    bool found = false;
    for (auto it = this->at(index).begin(); (it != this->at(index).end())&&(!found); ++it) {
      if (*it == element) found = true;
    }
    return found;
  }
  
  /**
   * @brief Display the hash table
   * @author Johan Defaye
   */
  void print() const
  {
    for (unsigned int i = 0; i < this->size(); ++i) {
      std::cout << "Ligne " << i << " : " << std::endl;
      
      typename std::list<T>::const_iterator it;
      
      for (it = this->at(i).begin(); it != this->at(i).end(); ++it) {
	std::cout << *it << std::endl;
      }
      
      std::cout << std::endl;
    }
  }
  
};



#endif
