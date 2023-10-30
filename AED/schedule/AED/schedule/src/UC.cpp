#include "UC.h"
#include "Class.h"
#include "Students.h"


UC::UC(std::string uc_id) : uc_id(uc_id){}
UC::UC(): uc_id(""){}


//Getters
std::string UC::getUc_id(){
    return uc_id;
}
const std::vector <std::string>& UC::getClasses() const{
    return classes;
}
const std::vector<std::pair<std::string,std::string>>& UC::getStudents()const{
    return students;
}

// Setters
void UC::setUc_id(int uc_id) {
    this->uc_id = uc_id;
}

//adiciona turma
void UC::addClass(std::string turma){
    classes.push_back(turma);
}
//adiciona aluno
void UC::addStudents(std::string studentID,std::string studentNm){
    std::pair<std::string,std::string> student(studentID,studentNm);
    students.push_back(student);
}
