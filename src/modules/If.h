#ifndef IF_H
#define IF_H

#include "Node.h"

#define block_if 1  
#define block_else_if 2 
#define block_else 3

/**

 * @brief Node of the tree which represent a condition if, else or elseif
 * @author : Ismail ELFAQIR
 */

class If : Node {
		
protected:
	Node * cond;
    int block_type;
	
public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */


    /**
    * Constructor with parameters
    * Set the block_type to the parameter passed to the constructor
    * @param condition : the condition of the if
    * @param left : left son
    * @param right : right son
    * @param bt : block if, else or elseif
    * @author Ismail ELFAQIR
    */
    If (Node * left, Node * right, Node * condition, const std::string & bt = "if");

	/**
    * Constructor with parameters
    * Set the block_type to the parameter passed to the constructor
    * @param left : left son
    * @param right : right son
    * @param bt : block if, else or elseif
    * @author Ismail ELFAQIR
    */
    If(Node * left, Node * right, const std::string & bt = "else");

    /* * * * * * * * * * * * * *
    * ACCESSORS  AND MUTATORS *
    * * * * * * * * * * * * * */

    /**
    * getter of the block_type
    * @author Ismail ELFAQIR
    */
    int get_block_type() const;


    /**
    * setter of block_type
    * @param bt : the block_type
    * @author Ismail ELFAQIR
    */
    void set_block_type(int bt);


    /* * * * * * * *
     * Translation *
     * * * * * * * */
    
    /**
     * @brief Translate the begining part of the If
     * @return a string containing the C++ code of the If
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;
    
    /**
     * @brief Translate the end part of the If
     * @return a string containing the C++ code of the If
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string postTranslate() const;

};
#endif
