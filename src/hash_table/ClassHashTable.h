#ifndef CLASSHASHTABLE_H
#define CLASSHASHTABLE_H

#include "HashTable.h"
#include "ClassDeclaration.h"


class ClassHashTable : public HashTable<ClassDeclaration> {
  
  private:
    
  
  public:
    
       /* * * * * * * * *
	* CONSTRUCTORS  *
	* * * * * * * * */
       
    /**
     * Default Constructor
     * @brief Initialize the hash table with the default size
     * @author Johan Defaye
     */
    ClassHashTable();
    
       
    /**
     * Constructor with parameter
     * @brief Initialize the hash table with the given size
     * @param size : Size of the hash table
     * @author Johan Defaye
     */
    ClassHashTable(int size);
    
    
    
       /* * * * * *
	* METHODS *
	* * * * * */
    
       
       
    /**
     * @brief Test if a ClassDeclaration is in the hash table
     * @param id : identifier of the ClassDeclaration
     * @author Johan Defaye
     */
    bool contains(const std::string & id) const;
    
    
    /**
     * @brief Test if a ClassDeclaration is one of the parent class of another ClassDeclaration
     * @param parentClass : name of the supposed parent class
     * @param Class : ClassDeclaration
     * @author Johan Defaye
     */
    bool isParentClass(const std::string & parentClass, const ClassDeclaration & Class) const;
    
};


#endif