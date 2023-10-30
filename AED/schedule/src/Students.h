//Classe dos alunos.
using namespace std;
#ifndef AEDPROJ_STUDENTS_H
#define AEDPROJ_STUDENTS_H
#include <string>
#include <vector>
#include "Class.h"
#include "UC.h"


 class Students{
    private:
        int id;
        std::string name;
        std::vector<std::pair<std::string,std::string>> classes;
    public:
        Students(int id, string name);
        Students();
    //Getters
    int getId() const;
    std::string getName() const;
    std::vector <std::pair<std::string,std::string>> getClasses() const;
    
    //Setters
    void setId(int id);
    void setName(const string& name);

    //add
    void addClass(std::string clcode,std::string uccode);
    

    //tentar inscricao

};

#endif //AEDPROJ_STUDENTS_H
