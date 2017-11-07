#ifndef VARIABLE_H
#define VARIABLE_H

#include "HashElement.h"


class Variable : public HashElement {
private:
  
  std::string _type;
  unsigned int _scope;
  bool _const;
  bool _static;
  
public:
  
  
  
  /* * * * * * * * *
   * CONSTRUCTORS  *
   * * * * * * * * */
  
  
  /**
   * Default constructor
   * @brief Set the identifier and the type of the Variable by the empty string
   * @author Johan Defaye
   */
  Variable();
  
  /**
   * Constructor with parameters
   * @brief Set the identifier and the type by those passed as parameters
   * @param i : id of the Variable
   * @param t : type of the Variable
   * @param c : if the Variable is const
   * @author Johan Defaye
   */
  Variable(const std::string & i, const std::string & t, bool c = false);
  
  /**
   * Constructor with parameters
   * @brief Set the identifier and the type by those passed as parameters
   * @param i : id of the Variable
   * @param t : type of the Variable
   * @param c : if the Variable is const
   * @param s : if the Variable is static
   * @author Johan Defaye
   */
  Variable(const std::string & i, const std::string & t, bool c, bool s);
  
  /**
   * Copy constructor
   * @param v : another Variable
   * @author Johan Defaye
   */
  Variable(const Variable & v);
  
  
  
  /* * * * * * * * * * * * * *
   * ACCESSORS  AND MUTATORS *
   * * * * * * * * * * * * * */
  
  
  /**
   * @brief Give the type
   * @return string
   * @author Johan Defaye
   */
  std::string get_type() const {return _type;}
  
  /**
   * @brief Set the type
   * @param s : an identifier
   * @author Johan Defaye
   */
  void set_type(const std::string & t) {_type = t;}
  
  /**
   * @brief Give the type
   * @return unsigned int
   * @author Johan Defaye
   */
  unsigned int get_scope() const {return _scope;}
  
  /**
   * @brief Set the scope
   * @param s : a scope
   * @author Johan Defaye
   */
  void set_scope(unsigned int s) {_scope = s;}
  
  /**
   * @brief Return true if the Variable is const
   * @return bool
   * @author Johan Defaye
   */
   bool is_const() const { return _const;}
   
  /**
   * @brief Set the _const attribute of the Variable
   * @param c : const or not
   * @author Johan Defaye
   */
   void set_const(bool c) { _const = c;}
   
  /**
   * @brief Return true if the Variable is static
   * @return bool
   * @author Johan Defaye
   */
   bool is_static() const { return _static;}
   
  /**
   * @brief Set the _static attribute of the Variable
   * @param s : static or not
   * @author Johan Defaye
   */
   void set_static(bool s) { _static = s;}
  
  
  /* * * * * * * * * * * * *
   * OPERATOR OVERLOADING  *
   * * * * * * * * * * * * */

  /**
   * @brief Return true if the Variable given as parameter has the same identifier and the same type
   * @param v : another Variable
   * @return boolean
   * @author Johan Defaye
   */
  bool is_equal(const Variable & v) const;
  
  /**
   * @brief Print the Variable 
   * @param flux : flux where the Variable will be print 
   * @author Johan Defaye
   */
  void print(std::ostream & flux) const;
  
};


/**
 * @brief Check if two Variables are the same
 * @param v1 : first Variable
 * @param v2 : second Variable
 * @return boolean
 * @author Johan Defaye
 */
bool operator==(const Variable & v1, const Variable & v2);

bool operator!=(const Variable & v1, const Variable & v2);

/** 
 * @brief Display a Variable
 * @param flux : flux where the Variable will be print 
 * @param element : the Variable to display
 * @return std::ostream&
 * @author Johan Defaye
 */
std::ostream& operator<<(std::ostream &flux, const Variable & element);




#endif
