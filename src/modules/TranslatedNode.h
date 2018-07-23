#pragma once

#include "Expression.h"

/**
 * @brief An already translated Node
 * @author : DAVID Florian
 *
 * The content (code) can just be put into the cpp output
 */
class TranslatedNode : public Expression {

protected:
    std::string content; // already translated code

public:
    //constructors
    /**
     * @brief constructor without right son
     */
    TranslatedNode(const std::string& translated_content, const std::string & _name = "Translated Node");
    
    /**
     * @brief constructor with a right son
     */
    TranslatedNode(const std::string& translated_content, Node* right_son,  const std::string & _name = "Translated Node");
    

protected:
    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string details() const { return "["+ content +"]"; }

public:
    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "Litteral Node"; }

    /**
     * @brief Translate the begining part of the Operator
     * @return a string containing the C++ code of the node
     *
     * All subclasses, must reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;
};
