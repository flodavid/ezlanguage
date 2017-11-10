#ifndef DECLARATIONVARIABLE_H
#define DECLARATIONVARIABLE_H

#include "../modules/Node.h"
#include "../hash_table/VariableHashed.h"

/** 
 * @brief Node of the tree which represent the declaration of a variable
 * @author : GINISTY Valentin
 * 
 * exemple : my_great_variable is integer -> int my_great_variable;
 */
class Variable : public Node {
	
protected:
    std::string name;
    std::string type;
    std::string scope;
    Node* affect;
    VariableHashed* hashed;
    bool isConst;
    bool isStatic;

public:

	/**
	 * @brief Constructor with parameters
	 * @param left : left son
	 * @param right : right son
	 * @param n : name of the variable
	 * @param t : type of the variable
	 * @param s : scope of the variable (locale or globale)
	 * @param content : the value that will be affected to the variable
	 * @param co : if the variable is const
	 * @param st : if the variable is static
	 */
    Variable(Node * left, Node * right, const std::string & n, const std::string & t, const std::string & s, Node * content, bool co = false, bool st = false);
    
    /**
     * @brief Translate the begining part of the Variable
     * @return a string containing the C++ code of the declaration
     */
    virtual std::string preTranslate() const;
        
    /**
     * @brief 
     * @return the variable stored in hash table
     */
    const VariableHashed* getVariableHashed() const;
};
#endif
