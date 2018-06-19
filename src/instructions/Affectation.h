#pragma once

#include "Instruction.h"
#include "../modules/Expression.h"
#include "../modules/Operator.h"

/**
 * @brief Node of the tree which represent a condition else
 */

class Affectation : public Instruction {

protected:
    std::string mTarget;
    Operator* mOperator;
    Expression* mAffectedValue;
	
public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */

    /**
     * Constructor with parameters
     */
    Affectation(std::string & varName, Operator* ope, Expression* value);
        
    /**
     * @brief destructor
     */
    virtual ~Affectation();


    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Affectation"; }

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

};
