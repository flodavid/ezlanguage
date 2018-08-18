#pragma once

#include "HashElement.h"

class ClassHashed : public HashElement {

  private:
    std::string _baseClass; // Name of the based class, or the empty string if there is no based class

  public:


   /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */



    /**
     * Default constructor
     * @brief Initalize the identifier and the class inherits with the empty string
     * @author Johan Defaye
     */
    ClassHashed();


    /**
     * Constructor with parameters
     * @brief Initialize the identifier with the given string
     * @param identifier : a string
     * @author Johan Defaye
     */
    ClassHashed(const std::string & identifer);


    /**
     * Constructor with parameters
     * @brief Initialize the identifier and the class inherits with the given string
     * @param identifier : a string
     * @param baseClass : a string
     * @author Johan Defaye
     */
    ClassHashed(const std::string & identifer, const std::string & baseClass);


    /**
     * Copy Constructor
     * @param c : another ClassDeclaration object
     * @author Johan Defaye
     */
    ClassHashed(const ClassHashed & c);



   /* * * * * * * * * * * * * *
    * ACCESSORS  AND MUTATORS *
    * * * * * * * * * * * * * */

   /**
    * @brief Return the name of the base class or the empty string if there is not
    * @return string
    * @author Johan Defaye
    */
    std::string getBaseClass() const {return _baseClass;}


    /**
     * @brief Set the base class
     * @param baseClass : name of the base class (string)
     * @author Johan Defaye
     */
    void setBaseClass(const std::string & baseClass) {_baseClass = baseClass;}


   /**
    * @brief Print the ClassDeclaration
    * @param flux : flux where the Class Declaration will be print
    * @author Johan Defaye
    */
    void print(std::ostream & flux) const;

};



/**
 * @brief Check if two ClassDeclaration are the same
 * @param c1 : first ClassDeclaration
 * @param c2 : second ClassDeclaration
 * @return boolean
 * @author Johan Defaye
 */
bool operator==(const ClassHashed & c1, const ClassHashed & c2);

bool operator!=(const ClassHashed & c1, const ClassHashed & c2);



/**
 * @brief Display a ClassDeclaration
 * @param flux : flux where the ClassDeclaration will be print
 * @param element : the ClassDeclaration to display
 * @return std::ostream&
 * @author Johan Defaye
 */
std::ostream& operator<<(std::ostream &flux, const ClassHashed & element);
