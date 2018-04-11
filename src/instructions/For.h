#ifndef FOR_H
#define FOR_H

#include "../modules/Node.h"
#include "../modules/Expression.h"
#include "../declarations/Variable.h"

/**
 * @brief Represent a node of the tree which will traduct a "for" loop
 * @author : GINISTY Valentin && DAVID Florian
 * 
 * example : forall i in 1..10 step 2 (step is optionnal)
 * Use Declaration, Condition and Instruction
 */
class For : public Node {
private:
    Variable* mIterator;

protected:
    const Node* mIndEnd;
    const Expression* mStep;
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
    For(const std::string & iterator, Expression* start, const Expression* end,
        const Expression* step, Node * instructions, const std::string & type = "");
    
    /**
     * @brief constructor with parameters
     * @param left : left son
     * @param name : name of the indice
     * @param container : name of the container to browse
     */
     For (Node * instructions, const std::string & iterator, const std::string & container);
    
    /**
     * @brief destructor
     */
    virtual ~For();


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
