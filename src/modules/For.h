#ifndef FOR_H
#define FOR_H

#include "Node.h"
#include "TranslatedNode.h"

/**
 * @brief Represent a node of the tree which will traduct a "for" loop
 * @author : GINISTY Valentin && DAVID Florian
 * 
 * example : forall i in 1..10 step 2 (step is optionnal)
 * Use Declaration, Condition and Instruction
 */
class For : public Node {
	
protected:
	std::string mIteratorName;
    const Node* mIndStart;
    const Node* mIndEnd;
    const TranslatedNode* mStep;
    std::string mType;
    std::string mContainerName;
    
public:

   /**
	* @brief constructor with parameters
	* @param iterator : name of the iterator
	* @param start : indice of the begining of the loop
	* @param end : indice of the end of the loop
	* @param step : step of the loop
	* @param left : left son
	* @param type : type of the indice
	*/	
    For(const std::string & iterator, const TranslatedNode* start, const TranslatedNode* end,
        const TranslatedNode* step, Node * left, const std::string & type = "");
    
    /**
     * @brief constructor with parameters
     * @param left : left son
     * @param name : name of the indice
     * @param container : name of the container to browse
     */
     For (Node * left, const std::string & iterator, const std::string & container);
        

    /**
     * @brief Get the name of the node
     * @return the name of the node. Defined at class creation
     */
    virtual inline const std::string getName() const { return "For"; }

    /**
     * @brief Translate the begining part of the Forall
     * @return a string containing the C++ code of the node
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string preTranslate() const;
    
    /**
     * @brief Translate the end part of the Forall
     * @return a string containing the C++ code of the instruction
     *
     * All subclasses, should reimplement this method so that the translation corresponds
     * to their specifications, specificities and own values
     */
    virtual std::string postTranslate() const;
};

#endif
