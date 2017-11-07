#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>
#include <string>

#include "HashElement.h"

/**
 * @brief Means a function, a procedure, or a method inside a class
 * @author Johan Defaye
 * 
 */
class Function : public HashElement {
  
  private:
    std::vector<std::string> _parameters; 	// argument types that need the function
    std::string _returnType; 			// type of the value returned by the function, or the empty string if no value returned
    std::string _class;				// name of the class which contains this function. The empty string if it's not a class method
  
  
  public:
    
    
    
  /* * * * * * * * *
   * CONSTRUCTORS  *
   * * * * * * * * */
  
  
  /**
   * Default constructor
   * @author Johan Defaye
   */
  Function();
  
  /**
   * Constructor with parameters
   * @param id : identifier of the function
   * @param param : parameters of the function
   * @param rtype : type of the value returned
   * @param className : name of the class wich contains this function
   * @author Johan Defaye
   */
  Function(const std::string & id, const std::vector<std::string> & param, const std::string & rtype, const std::string & className);
  
  /**
   * Copy constructor
   * @param f : another function
   * @author Johan Defaye
   */
  Function(const Function & f);
  
  
  
  /* * * * * * * * * * * * *
   * ACCESSOR AND MUTATOR  *
   * * * * * * * * * * * * */
  
  
  /**
   * @brief Give the parameters of the function
   * @return vector<string>
   * @author Johan Defaye
   */
  std::vector<std::string> get_param() const { return _parameters;}
  
  /**
   * @brief Give the returned type of the function
   * @return string
   * @author Johan Defaye
   */
  std::string get_returnType() const { return _returnType;}
  
  /**
   * @brief Give the class which contains the function
   * Return the empty string if it's not a method
   * @return string
   * @author Johan Defaye
   */
  std::string get_class() const { return _class;}
  
  /**
   * @brief Set the parameters of the function
   * @param param : parameters of the function
   * @author Johan Defaye
   */
   void set_param(const std::vector<std::string> & param) { _parameters = param;}
  
  /**
   * @brief Set the returned type of the function
   * @param returnType : type of the function's returned value
   * @author Johan Defaye
   */
  void set_returnType(const std::string & returnType) {_returnType = returnType;}
  
  /**
   * @brief Set the class which contains the function
   * Return the empty string if it's not a method
   * @param className : name of a class
   * @author Johan Defaye
   */
  void set_class(const std::string & className) {_class = className;}
  
  
  
  /* * * * * *
   * METHOD  *
   * * * * * */
  
  
  /**
   * @brief Test if the function belong to the class whose name is passed as parameter
   * @param className : name of a class
   * @return boolean
   * @author Johan Defaye
   */
  bool isMethodOf(const std::string & className) const;
  
  
  
  /* * * * * * * * * * * * *
   * OPERATOR OVERLOADING  *
   * * * * * * * * * * * * */
  
  
  /**
   * @brief Return true if the function given as parameter is the same
   * @param f : another function
   * @return boolean
   * @author Johan Defaye
   */
  bool is_equal(const Function & f) const;
  
  /**
   * @brief Print the function 
   * @param flux : flux where function will be print 
   * @author Johan Defaye
   */
  void print(std::ostream & flux) const;
  
};


/**
 * Check if two functions are the same
 * @param f1 : first function
 * @param f2 : second function
 * @return boolean
 * @author Johan Defa@brief ye
 */
bool operator==(const Function & f1, const Function & f2);

bool operator!=(const Function & f1, const Function & f2);


/** 
 * @brief Display a function
 * @param flux : flux where the function will be print 
 * @param f : the function to display
 * @return ostream&
 * @author Johan Defaye
 */
std::ostream& operator<<(std::ostream &flux, Function const& f);


#endif
