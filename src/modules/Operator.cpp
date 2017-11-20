//@author : GARNIER Antoine
#include "Operator.h"

using namespace std;

Operator::Operator(const string & ope):
    Node(nullptr, nullptr, "Operator"), opeChars(ope)
{ }

string Operator::preTranslate() const {
//    TODO refactor Operator class
//    string res= "";

//    switch(ope_type){
//        //Logical operators (and, or, xor, not)
//        case LOGICAL:
//            cout << "Operator's type : logical" << endl;
//            switch(ope_nb){
//                case UNARY:
//                    //Unary operator
//                    if(opeChars == "not"){res= "!"; }
//                    else {};//unknown operator
//                    break;

//                case BINARY:
//                    //Binary operators
//                    if(opeChars == "and") { res= "&&"; } else
//                    if(opeChars == "or")  { res= "||"; } else
//                    if(opeChars == "xor") { res= "^"; }
//                    else {};//unknown operator

//                    break;

//                default:
//                    break;

//            }
//            break;
//        //Arithmetic operators (-a, a+b, a-b, a*b, a/b, a mod b, a pow b)
//        case ARITHMETIC:
//            cout << "Operator's type : arithmetic" << endl;
//            switch(ope_nb){
//                case UNARY:
//                    //Unary operator
//                    if(opeChars == "-"){res= "-"; }
//                    if(opeChars == "abs"){res= "abs(" + getOperande_1() + ")"; }
//                    else {};//unknown operator
//                    break;

//                case BINARY:
//                    //Binary operator
//                    if(opeChars == "-"){res= "-";} else
//                    if(opeChars == "+"){res= "+";} else
//                    if(opeChars == "*"){res= "*";} else
//                    if(opeChars == "/"){res= "/";} else
//                    if(opeChars == "mod"){res= "%";} else
//                    if(opeChars == "pow"){"pow(" + getOperande_1() + "," + ")";}
//                    else {};//unknown operator
//                    break;

//                default:
//                    break;

//            }
//            break;

//        //Allocation's operators (=, +=, -=, *=, /=, .)
//        case ALLOCATION:
//            cout << "Operator's type : allocation" << endl;
//            if(opeChars == "="){res= "= ";} else
//            if(opeChars == "+="){res= "+= ";} else
//            if(opeChars == "-"){res= "-= ";} else
//            if(opeChars == "*="){res= "*= ";} else
//            if(opeChars == "/="){res= "/= ";} else
//            if(opeChars == "."){res= " + ";}
//            else {};//unknown operator
//            break;

//        //Comparison's operators (==, !=, <, >, <=, >=)
//        case COMPARISON:
//            cout << "Operator's type : comparison" << endl;
//            if(opeChars == "=="){res= " == ";} else
//            if(opeChars == "!="){res= " != ";} else
//            if(opeChars == "<"){res= " < ";} else
//            if(opeChars == ">"){res= " > ";} else
//            if(opeChars == "<="){res= " <= ";} else
//            if(opeChars == ">="){res= " >= ";}
//            else {};//unknown operator
//            break;

//        //Increment operators (a++, ++a, a--, --a)
//        case INCREMENT:
//            cout << "Operator's type : increment" << endl;
//            if(opeChars == "++"){res= "++";} else
//            if(opeChars == "--"){res= "--";} else {};//unknown operator
//            break;
//    }

//    return res;
}

std::string Operator::postTranslate() const
{
    if(opeChars == "abs") {
        return ")";
    }
}
