#ifndef VARIABLE_H
#define VARIABLE_H

#include "CommonVar.h"

/** 
 * @brief Node of the tree which represent the declaration of a variable
 * @author : GINISTY Valentin
 * 
 * exemple : my_great_variable is integer -> int my_great_variable;
 * TODO Handle hashed variable (VariableHashed class) association or merging
 */
class Variable : public CommonVar {

private:
    bool mIsInstruction;

protected:
    bool mIsStatic;

public:

    /**
     * @brief Constructor for standard variable declaration as instruction
     * @param name : name of the variable
     * @param type : type of the variable
     * @param construction_parameters : parameters used to construct the class
     * @param scope : scope of the variable (locale or globale)
     * @param isConst : if the variable is const
     * @param isStatic : if the variable is static
     */
    Variable(const std::string & name, const std::string & type,
            Expression * construction_parameters = nullptr, const std::string & scope = "", bool isConst = false,
            bool isStatic = false);

    /**
     * @brief Constructor for variable not as instruction
     * @param isConst : if the variable is const
     * @param name : name of the variable
     * @param type : type of the variable
     * @param construction_parameters : parameters used to construct the class
     */
    Variable(bool isConst, const std::string & name, const std::string & type,
            Expression * construction_parameters = nullptr);

    /**
     * @brief Destructor
     */
    ~Variable();


public:
    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Variable declaration"; }

    /**
     * @brief Set variable scope and constancy
     */
    void setScope(std::string & scope) { mScope= scope; }

    /**
     * @brief Translate the begining part of the Variable
     * @return a string containing the C++ code of the declaration
     */
    virtual std::string preTranslate() const;
};
#endif
