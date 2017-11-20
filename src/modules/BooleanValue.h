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

    /**
     * @brief Translate the begining part of the Forall
     * @return a string containing the C++ code of the node
     */

    virtual std::string preTranslate() const;
};

#endif
