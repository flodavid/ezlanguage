#ifndef IF_H
#define IF_H

#include "../modules/Node.h"
#include "../modules/ConditionalExpression.h"

/**
 * @brief Node of the tree which represent a condition else
 */

class If : public Node {

protected:
	ConditionalExpression * mCondition;
	
public:
    /* * * * * * * * *
    * CONSTRUCTORS  *
    * * * * * * * * */


    /**
    * Constructor with parameters
    * Set the block_type to the parameter passed to the constructor
    * @param condition : the condition of the if
    * @param left : left son
    * @param bt : block if, else or elseif
    * @author Ismail ELFAQIR
    */
    If(Node * left, Node * elseNode, ConditionalExpression * condition);
        
    /**
     * @brief destructor
     */
    virtual ~If();


    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "If"; }

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
    
    /**
     * @brief Translate the end part of the If
     * @return a string containing the C++ code of the If
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string postTranslate() const;

};
#endif
