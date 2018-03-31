#pragma once

#include "CommonVar.h"

/**
 * @brief Represent the root node of the tree
 * 
 * @author Florian DAVID
 */
class Parameter : public CommonVar {

private:
    std::string mType;
    // At construction, we suppose that it is true
    bool mIsLastOneOfList;

public:
	/**
	 * @brief Constructor with parameters
	 * @param name : name of the variable
	 * @param type : type of the variable
	 * @param content : the value that will be affected to the variable
	 * @param co : if the variable is const
	 */
    Parameter(const std::string & name, const std::string & type,
            const Node* content, bool co = false);
    

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Parameter"; }
    
    /**
     * @brief Getter for the parameter's name
     * @return name of the parameter
     */
    const std::string & getParameterName() const { return getVariableName(); }

    /**
     * @brief Translate the begining part of the Repeat
     * @return a string containing the C++ code of the instruction
     * 
     * Defines program imports and functions definitions
     */
    virtual std::string preTranslate() const;

    virtual void addRightChild(Node* child);
};
