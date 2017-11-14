#ifndef DECLARATIONMULTIPLEVARIABLE_H
#define DECLARATIONMULTIPLEVARIABLE_H

#include "../modules/Node.h"
#include <vector>

/**
 * @brief Represent a node of the tree which will translate a multiple variable declaration
 * Exemple : locale a, b, c are integer -> int a, b, c;
 * @author Johan Defaye
 * @see if it is useful or if Variable is sufficient (with boolean or other for separator ?)
 */
class MultipleVariable : public Node {
	
	protected:
		std::vector<std::string> names;
		std::string type;
		std::string scope;
	
	public:
		/**
		 * @brief Constructor with parameters
		 * @param left : left son
		 * @param right : right son
		 * @param n : names of the variable to declare
		 * @param t :type of alle the variable to declare 
		 */
		MultipleVariable(Node * left, Node * right, const std::vector<std::string> & n, const std::string & t);
		
		
		virtual std::string preTranslate() const;
};

#endif
