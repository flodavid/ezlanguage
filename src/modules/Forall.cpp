//@author : GINISTY Valentin
#include "Forall.h"
#include <iostream>
#include <string>
#include "String_addon.h"

using namespace std;

Forall::Forall(int ind_begin, int ind_end, int step, int imbrication): ind_begin(ind_begin), ind_end(ind_end), step(step), imbrication(imbrication){
    name = "Forall";
}

//forall i in 1..10 (step X)
string Forall::translate() {
    //Temporary solution before refactoring indices
    string i = "indice_" + to_string(imbrication);
    string res = "for(int "+i+" = "+(ind_begin-1)+"; "+i+" < "+(ind_end-1)+"; "+i+" = "+i+"+"+step+"){\n";
    res = res + "\t" + this->left_son->translate() + "\n";
    res = res + "}";
    return res;
}
