#ifndef FOR_H
#define FOR_H

#include "Node.h"

/**
 * @brief Represent a node of the tree which will traduct a "for" loop
 * @author : GINISTY Valentin
 * 
 * example : forall i in 1..10 step 2 (step is optionnal)
 * Use Declaration, Condition and Instruction
 */
class For : public Node {
	
protected:
	std::string ind_name;
    std::string ind_begin;
    std::string ind_end;
    std::string step;
    std::string type;
    std::string container_name;
    
public:

   /**
	* @brief constructor with parameters
	* @param left : left son
	* @param right : right son
	* @param name : name of the indice
	* @param begin : indice of the begining of the loop
	* @param end : indice of the end of the loop
	* @param s : step of the loop
	* @param t : type of the indice
	* @param imbrication
	*/	
    For(Node * left, Node * right, const std::string & name, const std::string & begin, const std::string & end, const std::string & s, const std::string & t = "");
    
    
    /**
     * @brief constructor with parameters
     * @param left : left son
     * @param right : right son
     * @param name : name of the indice
     * @param container : name of the container to browse
     */
     For (Node * left, Node * right, const std::string & name, const std::string & container);
    
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
