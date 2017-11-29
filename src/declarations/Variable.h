#ifndef VARIABLE_H
#define VARIABLE_H

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
    std::string varName;
    std::string type;
    std::string scope;
    const Node* affect;
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
    Variable(Node * right, const std::string & _name, const std::string & _type,
            const std::string & _scope, const Node* content, bool co = false, bool st = false);


protected:
    /**
     * @brief Get some details about the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string details() const { return varName; }

public:
    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Variable declaration"; }

    /**
     * @brief Set variable scope and constancy
     */
    void setScope(std::string & _scope) { scope= _scope; }

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
