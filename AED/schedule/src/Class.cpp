#include "Class.h"
#include "UC.h"
using namespace std;

Class::Class(string class_code) {
    this->class_code = class_code;
}
Class::Class(){class_code="";}
//Getters
string Class::getClass_code() const {
    return class_code;
}
const std::vector<std::string>& Class::getUCs() const {
    return ucs;
}


// Setters
void Class::setClass(string new_class_code) {
    this->class_code = new_class_code;
}
//adiciona unidade curricular
void Class::addUC(string uc) {
    ucs.push_back(uc);
}

