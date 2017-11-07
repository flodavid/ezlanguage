//@author : GARNIER Antoine
#include "Operator.h"

using namespace std;

Operator::Operator() {
}

Operator::Operator(int ope_type, string ope) {
    name= "Operator";

    ope_type= ope_type;
    ope= ope;
}

string Operator::preTranslate() const {
    string res= "";

    switch(ope_type){
        //Logical operators (and, or, xor, not)
        case LOGICAL:
            cout << "Operator's type : logical" << endl;
            switch(ope_nb){
                case UNARY:
                    //Unary operator
                    if(ope == "not"){res= "!" + getOperande_1(); }
                    else {};//unknown operator
                    break;

                case BINARY:
                    //Binary operators
                    if(ope == "and"){res= getOperande_1(); + "&&" + getOperande_2(); } else
                    if(ope == "or"){res= getOperande_1(); + "||" + getOperande_2(); } else
                    if(ope == "xor"){res= getOperande_1(); + "^" + getOperande_2(); }
                    else {};//unknown operator

                    break;

                default:
                    break;

            }
            break;
        //Arithmetic operators (-a, a+b, a-b, a*b, a/b, a mod b, a pow b)
        case ARITHMETIC:
            cout << "Operator's type : arithmetic" << endl;
            switch(ope_nb){
                case UNARY:
                    //Unary operator
                    if(ope == "-"){res= "-" + getOperande_1(); }
                    if(ope == "abs"){res= "abs(" + getOperande_1() + ")"; }
                    else {};//unknown operator
                    break;

                case BINARY:
                    //Binary operator
                    if(ope == "-"){res= getOperande_1() + "-" + getOperande_2();} else
                    if(ope == "+"){res= getOperande_1() + "+" + getOperande_2();} else
                    if(ope == "*"){res= getOperande_1() + "*" + getOperande_2();} else
                    if(ope == "/"){res= getOperande_1() + "/" + getOperande_2();} else
                    if(ope == "mod"){res= getOperande_1() + "%" + getOperande_2();} else
                    if(ope == "pow"){"pow(" + getOperande_1() + "," + getOperande_2() + ")";}
                    else {};//unknown operator
                    break;

                default:
                    break;

            }
            break;

        //Allocation's operators (=, +=, -=, *=, /=, .)
        case ALLOCATION:
            cout << "Operator's type : allocation" << endl;
            if(ope == "="){res= getOperande_1() + "= " + getOperande_2();} else
            if(ope == "+="){res= getOperande_1() + "+= " + getOperande_2();} else
            if(ope == "-"){res= getOperande_1() + "-= " + getOperande_2();} else
            if(ope == "*="){res= getOperande_1() + "*= " + getOperande_2();} else
            if(ope == "/="){res= getOperande_1() + "/= " + getOperande_2();} else
            if(ope == "."){res= getOperande_1() + " + " + getOperande_2();}
            else {};//unknown operator
            break;

        //Comparison's operators (==, !=, <, >, <=, >=)
        case COMPARISON:
            cout << "Operator's type : comparison" << endl;
            if(ope == "=="){res= getOperande_1() + " == " + getOperande_2();} else
            if(ope == "!="){res= getOperande_1() + " != " + getOperande_2();} else
            if(ope == "<"){res= getOperande_1() + " < " + getOperande_2();} else
            if(ope == ">"){res= getOperande_1() + " > " + getOperande_2();} else
            if(ope == "<="){res= getOperande_1() + " <= " + getOperande_2();} else
            if(ope == ">="){res= getOperande_1() + " >= " + getOperande_2();}
            else {};//unknown operator
            break;

        //Increment operators (a++, ++a, a--, --a)
        case INCREMENT:
            cout << "Operator's type : increment" << endl;
            if(ope == "++"){res= "++" + getOperande_1();} else
            if(ope == "--"){res= "--" + getOperande_1();} else {};//unknown operator
            break;
    }


    return res;
}
