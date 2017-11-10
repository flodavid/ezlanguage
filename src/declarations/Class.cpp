//@author Ismail ELFAQIR
#include "Class.h"
#include "../addons/String_addon.h"
#include <iostream>
using namespace std;

Class::Class():m_class(),public_functions(),static_functions(),public_variables(){
}

Class::Class(ClassHashed *c)
			:m_class(c),public_functions(),static_functions(),public_variables()
{
}


Class::Class(ClassHashed *c,
	     		const vector<Function *> &functions, 
	     		const vector<Function *> &s_functions,  
	     		const vector<Variable *> &variables )
		   :m_class(c),
			public_functions(functions),
			static_functions(s_functions),
			public_variables(variables) 
{
}

Class::Class(ClassHashed *c,
			const vector<Function *> &functions, 
			const vector<Variable *> &variables )
	   		:m_class(c),public_functions(functions),static_functions(),public_variables(variables) 
{
}

Class::Class(ClassHashed *c, const vector<Function *> &functions)
				   :m_class(c),public_functions(functions),static_functions(),public_variables() 
{
}

Class::Class(ClassHashed *c, const vector<Variable *> &variables )
				   :m_class(c),public_functions(),static_functions(),public_variables(variables) 
{
}

Class::Class(const Class & cpy)
				   :m_class(cpy.m_class), 
					public_functions(cpy.public_functions),
					static_functions(cpy.static_functions),
				    	public_variables(cpy.public_variables)
{
}

Class::~Class(){
}

ClassHashed * Class::get_class() const{
	return m_class;
}

const vector<Variable *>&  Class::get_variables() const{
	return public_variables;
}

const vector<Function *>&  Class::get_functions() const{
	return public_functions;
}

const vector<Function *>&  Class::get_static_functions() const{
	return static_functions;
}

void Class::set_class(ClassHashed *c){
	m_class=c;
}

void Class::set_variable(const vector<Variable *>&variables){
	public_variables=variables;
}

void Class::set_functions(const vector<Function *>&functions){
	public_functions=functions;
}

void Class::set_static_functions(const vector<Function *>&s_functions){
	static_functions=s_functions;
}

void Class::add_function(Function *function) {
	if(!this->is_in_class(function)){
		public_functions.push_back(function);
	}
	else cout<<"already in class"<<endl;
}

void Class::add_static_function(Function *function) {
	if(!this->is_in_class(function)){
		static_functions.push_back(function);
	}
	else cout<<"already in class"<<endl;
}

void Class::add_variable(Variable * variable){
	if(!this->is_in_class(variable)){
		public_variables.push_back(variable);
	}
	else cout<<"already in class"<<endl;
}

bool Class::is_in_class(Function * function){
	
	for(unsigned int i=0;i<public_functions.size();i++){
		if(public_functions[i]==function) return true;
	}
	for(unsigned int i=0;i<static_functions.size();i++){
		if(static_functions[i]==function) return true;
	}
	return false;
}

bool Class::is_in_class(Variable * variable){

	for(unsigned int i=0;i<public_variables.size();i++){
		if(public_variables[i]==variable) return true;
	}
	return false;
}

string Class::preTranslate() const
{
	string res="#ifndef "+toUpperCase(m_class->get_id())+"_H\n";
	res+="#define "+toUpperCase(m_class->get_id())+"_H\n";
	res+"#include <iostream>\n";
	res+="class "+m_class->get_id()+" {\n";
		res+="\tpublic:\n";
		// the attributes
		string buf_params_constructor= "";
		string buf_attribute_init= "";
		for(unsigned int i=0;i<public_variables.size();i++) {
			res+="\t\t"+public_variables[i]->translate() + "\n";
            
            const VariableHashed* var= public_variables[i]->getVariableHashed();
			// Add construtor parameters
			buf_params_constructor+= var->get_type()+" arg_"+to_string(i);
			// Add attribute initilization
			buf_attribute_init+=var->get_id()+"(arg_"+to_string(i)+")";

			if(i+1<public_variables.size()-1) {
			    buf_params_constructor+=",";
                buf_attribute_init+=",";
			}
		}
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
		for(unsigned int i=0;i<static_functions.size();i++) {
			res+="\t\t";
			res+="static "+static_functions[i]->translate()+"\n";
		}

		// functions
		for(unsigned int i=0;i<public_functions.size();i++) {
			res+="\t\t";
			res+=public_functions[i]->translate()+"\n";
		}

	return res;
}

string Class::postTranslate() const
{
    string res= "";
    res+="};\n";
    res+="#endif";
    
    return res;
}
