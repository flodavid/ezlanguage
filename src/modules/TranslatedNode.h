#pragma once

#include "Node.h"

/**
 * @brief An already translated Node
 * @author : DAVID Florian
 *  
 * The content (code) can just be put into the cpp output
 */
class TranslatedNode : public Node{

protected:
    std::string content; // already translated code

public:
    //constructors
    TranslatedNode(const std::string& translated_content, const std::string & _name = "Translated Node");
    
    /**
     * @brief Translate the begining part of the Operator
     * @return a string containing the C++ code of the node
     *
     * All subclasses, must reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const { return content; }
};
