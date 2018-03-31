#pragma once

#include "CommonDeclaration.h"
#include "../modules/Expression.h"
#include "../hash_table/VariableHashed.h"

/** 
 * @brief Node of the tree which represent the declaration of a variable
 * @author : GINISTY Valentin
 * 
 * exemple : my_great_variable is integer -> int my_great_variable;
 * TODO Handle hashed variable (VariableHashed class) association or merging
 */
class CommonVar : public CommonDeclaration {
	
protected:
    std::string mType;
    std::string mScope;
    const Node* mAffect;
    VariableHashed* hashed;
    bool isConst;

public:

    /**
     * @brief Constructor with parameters
     * @param name : name of the variable
     * @param type : type of the variable
     * @param scope : scope of the variable (locale or globale)
     * @param content : the value that will be affected to the variable
     * @param co : if the variable is const
     */
    CommonVar(const std::string & name, const std::string & type,
            const std::string & scope, const Node* content = nullptr, bool co = false);

    /**
     * @brief Constructor with parameters
     * @param name : name of the variable
     * @param type : type of the variable
     * @param scope : scope of the variable (locale or globale)
     * @param co : if the variable is const
     * @param st : if the variable is static
     */
    CommonVar(const std::string & name, const std::string & type,
            const std::string & scope, bool co = false);

    /**
     * @brief Destructor
     */
    ~CommonVar();


public:
    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "CommonVar declaration"; }

    /**
     * @brief Getter for the variable's name
     * @return name of the variable
     */
    const std::string & getVariableName() const { return getDeclarationName(); }

    /**
     * @brief Get the C++ type of the variable
     */
    std::string translateType() const;

    /**
     * @brief Set variable scope and constancy
     */
    void setScope(std::string & scope) { mScope= scope; }

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
