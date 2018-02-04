//@author Ismail ELFAQIR
#include "Class.h"
#include "../addons/String_addon.h"
#include <iostream>
using namespace std;

Class::Class(ClassHashed *c):
	CommonDeclaration(nullptr, c->get_id()), mVariables(nullptr), mClass(c), mSupportsPragmas(true)
{ }

Class::Class(ClassHashed *c,
			Variable * variables,
			Method * functions,
			Method * s_functions ):
	CommonDeclaration(variables, c->get_id()), mVariables(variables), mClass(c), mSupportsPragmas(true)
{
	variables->addRightChild(functions);
	functions->addRightChild(s_functions);
}

Class::Class(ClassHashed *c,
			Variable * variables,
			Method * functions ):
	CommonDeclaration(variables, c->get_id()), mVariables(variables), mClass(c), mSupportsPragmas(true)
{
	variables->addRightChild(functions);
}

Class::Class(ClassHashed *c, Method * functions):
	CommonDeclaration(functions, c->get_id()), mVariables(nullptr), mClass(c), mSupportsPragmas(true) 
{ }

Class::Class(ClassHashed *c, Variable * variables ):
	CommonDeclaration(variables, c->get_id()), mVariables(variables), mClass(c), mSupportsPragmas(true)
{ }

Class::~Class()
{ }

ClassHashed * Class::get_class() const{
	return mClass;
}

void Class::addMethod(Method *function) {
	addRightChild(function);
}

// void Class::add_static_function(Method *function) {
// 	addRightChild(function);
// }

void Class::addVariable(Variable * variable){
	addRightChild(variable);
}

// bool Class::is_in_class(Method * function){
	
// 	for(unsigned int i=0;i<public_functions.size();i++){
// 		if(public_functions[i]==function) return true;
// 	}
// 	for(unsigned int i=0;i<static_functions.size();i++){
// 		if(static_functions[i]==function) return true;
// 	}
// 	return false;
// }

// bool Class::is_in_class(Variable * variable){

// 	for(unsigned int i=0;i<public_variables.size();i++){
// 		if(public_variables[i]==variable) return true;
// 	}
// 	return false;
// }

// string Class::getDefaultConstructParams() const
// {
            
//         //     const VariableHashed* var= public_variables[i]->getVariableHashed();
// 		// 	// Add construtor parameters
// 		// 	buf_params_constructor+= var->get_type()+" arg_"+to_string(i);
// 		// 	// Add attribute initilization
// 		// 	buf_attribute_init+=var->get_id()+"(arg_"+to_string(i)+")";

// 		// 	if(i+1<public_variables.size()-1) {
// 		// 	    buf_params_constructor+=",";
//         //         buf_attribute_init+=",";
// 		// 	}
// 		// }
// }

string Class::preTranslate() const
{
	string res= "#ifndef "+toUpperCase(mClass->get_id())+"_H\n";
	res+= "#define "+toUpperCase(mClass->get_id())+"_H\n";
	// TODO see how to handle imports (set flags ? Always import ?)
	res+= "#include <iostream>\n";
	res+= "class "+mClass->get_id()+" {\n";
	res+= "public:\n";

	/** The CONSTRUCTORS (according to classes.pdf default constructor and constructor
	 * with parameters are required ) **/

	/* Default constructor */
	res+= "\t"+mClass->get_id()+"()";
	res+= "\n\t{}\n\n";

	/* Constructor with parameters*/
	// Constructor parameters
	if (mVariables != nullptr) {
		string constructor_params= mVariables->translateType() +"_"+ mVariables->getDeclarationName();
		string initialization_list= mVariables->getDeclarationName() +"(_"+ mVariables->getDeclarationName() +")";
		
		for(const Node * var= mVariables; var->right_son != nullptr; var= var->right_son) {
			Variable * var_right_son= dynamic_cast<Variable *>(var->right_son);

			if (var_right_son != nullptr) {
				string right_son_name= var_right_son->getDeclarationName();
				constructor_params+= ", "+ var_right_son->translateType() +" _"+ right_son_name;
				initialization_list+= ", "+ right_son_name +"(_"+ right_son_name +")";
			}
		}

		// Constructor signature
		res+= "\t"+mClass->get_id()+"("+ constructor_params +"):";

		// Put constructor parameters buffer into output
		res+= "\n\t\t"+ initialization_list;
		
		// Empty definition
		res+= "\n\t{}\n\n";
	}

	// The Destructor
	res+= "\t~"+mClass->get_id()+"()";
	res+= "\n\t{}\n";
	
		// the static functions
		// for(unsigned int i=0;i<static_functions.size();i++) {
		// 	res+="\t\t";
		// 	res+="static "+static_functions[i]->translate()+"\n";
		// }

		// functions
		// for(unsigned int i=0;i<public_functions.size();i++) {
		// 	res+="\t\t";
		// 	res+=public_functions[i]->translate()+"\n";
		// }

	return res;
}

string Class::postTranslate() const
{
    string res= "";
    res+= "};\n";
    res+= "#endif\n\n";
    
    return res;
}
