#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>

#define DEFAULT_SIZE 50

/**
 * @brief An hash table which can contains any type of element that contain the operator operator==
 * @author Johan Defaye
 */
template <typename T>
class HashTable : public std::vector<std::list<T>> {

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
  HashTable(unsigned int size) {this->resize(size);};

  /**
   * Copy constructor
   * @brief Initialize a hash table with the elements of another hash table
   * @param h : another hash table
   * @author Johan Defaye
   */
  HashTable(const HashTable &h) {*this = h;};



  /* * * * * *
   * METHODS *
   * * * * * */


  /**
   * @brief Give the hash code of an identifier passed as parameter
   * @param id_variable : identifier of the id_variable
   * @return unsigned int
   * @author Johan Defaye
   */
  unsigned int hash(const std::string & id_variable) const;

  /**
   * @brief Add an element in the hash table with the specified identifier
   * Throw an error if the size of the hash table is null
   * @param element : an hash element
   * @param id : an identifier of the hash element to add
   * @exception : Return a string as exception if the hash table is empty
   * @author Johan Defaye
   */
  void addElement(const T & element, const std::string & id);

  /**
   * @brief Remove an element from the hash table with the specified identifier
   * @param element : an hash element
   * @param id : an identifier of the hash element to remove
   * @exception : Return a string as exception if the element to be removed is not in the hash table
   * @author Johan Defaye
   */
  void removeElement(const T & element, const std::string & id);

  /**
   * @brief Remove an element from the hash table with the specified iterator and identifier
   * @param it : iterator of the element to remove
   * @param id : an identifier of the hash element to remove
   * @author Johan Defaye
   */
  void removeElement(typename std::list<T>::iterator & it, const std::string & id);

  /**
   * @brief Test if an element is in the hash table
   * @param element : an element
   * @param id : indetifier of the element
   * @return boolean
   * @author Johan Defaye
   */
  bool contains(const T & element, const std::string & id) const;

  /**
   * @brief Display the hash table
   * @author Johan Defaye
   */
  void print() const;
