#include "Students.h"
#include "Class.h"
#include "UC.h"
using namespace std;
Students::Students(int id, std:: string name){
    this->id = id;
    this->name = name;
}
Students::Students(){
    id=000000000;
    name="";
}
//add
void Students::addClass(std::string clcode ,std::string uccode){
    
    classes.push_back({clcode,uccode});
}


//Getters
int Students::getId() const {
    return id;
}

std::string Students::getName() const {
    return name;
}
std::vector<std::pair<std::string,std::string>> Students::getClasses() const{
    return classes;
}

// Setters
void Students::setId(int id) {
    this->id = id;
}

void Students::setName(const string& name) {
    this->name = name;
}