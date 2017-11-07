#ifndef SCOPEHASHTABLE_H
#define SCOPEHASHTABLE_H

#include <iostream>
#include <stack>
#include <list>
#include <string>

#include "HashTable.h"
#include "Variable.h"

/**
 * @brief Hash table which can only contains Variable
 * @author Johan Defaye
 */
class ScopeHashTable : public HashTable<Variable> {
  
  
  private:
    std::stack<std::list< std::list<Variable>::iterator > > _scopeStack; // Used to improve the suppression of all the element of the same scoop
    unsigned int _currentScope; 
  
  
  public:
    
    
    
    /* * * * * * * * *
     * CONSTRUCTORS  *
     * * * * * * * * */
    
    
    /**
     * Default constructor 
     * @brief Construct an empty hash table with a empty scope stack
     * Initialize the current scope to 0
     * @author Johan Defaye
     */
    ScopeHashTable();
    
    /**
     * Constructor with parameter
     * @param size : size of the hash table
     * @author Johan Defaye
     */
    ScopeHashTable(unsigned int size);
    
    /**
     * Copy constructor
     * @param table : another scope hash table
     * @author Johan Defaye
     */
    ScopeHashTable(const ScopeHashTable & table);
    
    
    
    /* * * * * * *
     * ACCESSOR  *
     * * * * * * */
    
    
    /**
     * @brief Give the scope stack of the hash table
     * @return stack<list< Variable::iterator > >
     * @author Johan Defaye
     */
    std::stack<std::list< std::list<Variable>::iterator > > get_scopeStack() const {return _scopeStack;}
    
    
    /**
     * @brief Give the current scope of the hash table
     * @return unsigned int : current scope
     * @author Johan Defaye
     */
    unsigned int get_currentScope() const {return _currentScope;}
    
    
    /* * * * * *
     * METHODS *
     * * * * * */
    
    
    /**
     * @brief Incremente the current scope by one unit
     * @author Johan Defaye
     */
    void incScope();
    
    /**
     * @brief Remove all the Variable from the highest scope in the hash table
     * Decremente the current scope by one unit
     * @exception : Return a string as exception if the current scope is equal to 0 before decremente
     * @author Johan Defaye
     */
    void decScope();
    
    /**
     * @brief Add a Variable in the hash table 
     * @param v : Variable to add
     * @exception : Return a string as exception if the hash table is empty
     * @author Johan Defaye
     */
     void addElement(Variable & v);
     
    /**
     * @brief Remove a Variable from the hash table
     * @param v : Variable to remove
     * @exception : Return a string as exception if the Variable to be removed has too small scope
     * @exception : Return a string as exception if the Variable to be removed is not in the hash table
     * @author Johan Defaye
     */
     //void removeElement(const Variable & v);
      
      
    /**
     * @brief Return the type of the Variable with the specified identifier
     * @brief Return the empty string if the type is not known
     * @param id : identifier of the Variable
     * @exception : Return an exception if not found
     * @return string
     * @author Johan Defaye
     */
      std::string get_type(const std::string & id) const;
      
      
     /**
      * @brief Test if an element is in the hash table
      * @param id : identifier
      * @return boolean
      * @author Johan Defaye
      */
      bool contains(const std::string & id) const;
      
      
     /**
      * @brief Test if an element is already in the hash table in the specified scope
      * @param id : identifier
      * @param s : scope
      * @author Johan Defaye
      */
     bool contains(const std::string & id, unsigned int s) const;
  
};

#endif
