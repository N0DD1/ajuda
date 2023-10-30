//Classe das unidades curriculares.
#ifndef AEDPROJ_UC_H
#define AEDPROJ_UC_H

#include <string>
#include <vector>
#include "Class.h"
#include "Students.h"


class UC{
private:
    std::string uc_id;
    std::vector<std::string> classes;
    std::vector<std::pair<std::string,std::string>> students;


public:
    UC();
    UC(std::string uc_id);
    void addClass (std::string);//add class to classes
    void addStudents(std::string,std::string);//add student to uc;
    //Getters
    std::string getUc_id();
    const std::vector<std::string>& getClasses()const;
    const std::vector<std::pair<std::string,std::string>>& getStudents()const;
    //Setters
    void setUc_id(int uc_id);
};

#endif //AEDPROJ_UC_H
