#ifndef BOOLEANVALUE_H
#define BOOLEANVALUE_H

#include <string>
#include "ConditionalExpression.h"

/**
 * @brief Represents a boolean as a node of the tree, with two possible values : true or false
 */
class BooleanValue : public ConditionalExpression {

private:
    bool value;
    bool isLitteral;
    std::string mLitteralName;

public:
    /**
     * @brief Constructor for using boolean value
     * @param boolean : value of the boolean
     */
    BooleanValue(bool boolean);

    /**
     * @brief Constructor for using variable as boolean
     * @param varName : name of the boolean variable
     */
    BooleanValue(const std::string & name);


protected:
    /**
     * @brief Get some details about the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string details() const
    { return isLitteral ? " is litteral" : "is a variable"; }

public:
    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Boolean value"; }

    /**
     * @brief Translate the begining part of the Forall
     * @return a string containing the C++ code of the node
     */

    virtual std::string preTranslate() const;
};

#endif
