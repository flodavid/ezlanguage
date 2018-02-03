//@author Ismail ELFAQIR
#include "Class.h"
#include "../addons/String_addon.h"
#include <iostream>
using namespace std;

Class::Class(ClassHashed *c):
	CommonDeclaration(nullptr, c->get_id()), m_class(c), mSupportsPragmas(true)
{ }

Class::Class(ClassHashed *c,
				Variable * variables,
	     		Function * functions,
	     		Function * s_functions ):
	CommonDeclaration(variables, c->get_id()), m_class(c), mSupportsPragmas(true)
{
	variables->addRightChild(functions);
	functions->addRightChild(s_functions);
}

Class::Class(ClassHashed *c,
			Variable * variables,
			Function * functions ):
	CommonDeclaration(variables, c->get_id()), m_class(c), mSupportsPragmas(true)
{
	variables->addRightChild(functions);
}

Class::Class(ClassHashed *c, Function * functions):
	CommonDeclaration(functions, c->get_id()), m_class(c), mSupportsPragmas(true) 
{ }

Class::Class(ClassHashed *c, Variable * variables ):
	CommonDeclaration(nullptr, c->get_id()), m_class(c), mSupportsPragmas(true)
{ }

Class::~Class()
{ }

ClassHashed * Class::get_class() const{
	return m_class;
}

void Class::addFunction(Function *function) {
	addRightChild(function);
}

// void Class::add_static_function(Function *function) {
// 	addRightChild(function);
// }

void Class::addVariable(Variable * variable){
	addRightChild(variable);
}

// bool Class::is_in_class(Function * function){
	
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

string Class::preTranslate() const
{
	string res="#ifndef "+toUpperCase(m_class->get_id())+"_H\n";
	res+="#define "+toUpperCase(m_class->get_id())+"_H\n";
	// TODO see how to handle imports (set flags ? Always import ?)
	res+"#include <iostream>\n";
	res+="class "+m_class->get_id()+" {\n";
		res+="\tpublic:\n";
		// the attributes
		string buf_params_constructor= "";
		string buf_attribute_init= "";
		// for(unsigned int i=0;i<public_variables.size();i++) {
			
            
        //     const VariableHashed* var= public_variables[i]->getVariableHashed();
		// 	// Add construtor parameters
		// 	buf_params_constructor+= var->get_type()+" arg_"+to_string(i);
		// 	// Add attribute initilization
		// 	buf_attribute_init+=var->get_id()+"(arg_"+to_string(i)+")";

		// 	if(i+1<public_variables.size()-1) {
		// 	    buf_params_constructor+=",";
        //         buf_attribute_init+=",";
		// 	}
		// }
		// the CONSTRUCTORS (according to classes.pdf default constructor and constructor with parameters are required )
		res+="\t\t"+m_class->get_id()+"(){}\n";

		res+="\t\t"+m_class->get_id()+"(";

        // Put constructor parameters buffer into output
		res+= buf_params_constructor;
		res+=")\n";
		res+="\t\t\t :";

        // Put attribute initialization buffer into output
		res+= buf_attribute_init;

		res+="\n{}\n"; 

		// the Destructor
		res+="\t\t~"+m_class->get_id()+"(){}\n";
	
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
    res+="};\n";
    res+="#endif";
    
    return res;
}
