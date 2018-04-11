#pragma once

#include "CommonDeclaration.h"
#include "../modules/Expression.h"
#include "../hash_table/VariableHashed.h"

/** 
 * @brief Node of the tree which represent the common part for declaring any kind of variable
 * @author : GINISTY Valentin
 * 
 * exemple : my_great_variable is integer -> int my_great_variable;
 * TODO Handle hashed variable (VariableHashed class) association or merging
 */
class CommonVar : public CommonDeclaration {

private:
    std::string mType;

protected:
    std::string mScope;
    Expression* mAffect;
    bool mIsInitList;
    VariableHashed* hashed;
    bool mIsConst;

public:

    /**
     * @brief Constructor with parameters for variable construction
     * @param name : name of the variable
     * @param type : type of the variable
     * @param content : the value that will be affected to the variable
     * @param isInitList : flag that defines if affectation uses equal sign or parenthesis
     * @param scope : scope of the variable (locale or globale)
     * @param isConst : if the variable is const
     */
    CommonVar(const std::string & name, const std::string & type,
            Expression* content = nullptr, bool isInitList = false,
            const std::string & scope = "", bool isConst = false);

    /**
     * @brief Destructor
     */
    ~CommonVar();


public:
    /**
     * @brief Getter for the name of the Node
     * @return the name node inheriting CommonVar
     */
    virtual const std::string getName() const =0;

    /**
     * @brief Getter for the variable's name
     * @return name of the variable
     */
    virtual const std::string & getVariableName() const { return getDeclarationName(); }

    /**
     * @brief Getter for the variable default value
     * @return the expression affected to the variable
     */
    virtual const Expression* getAffectation() const { return mAffect; }

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
