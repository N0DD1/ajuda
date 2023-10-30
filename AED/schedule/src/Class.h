//Classe das turmas.
#ifndef AEDPROJ_CLASS_H
#define AEDPROJ_CLASS_H
#include <string>
#include <vector>
#include "Lecture.h"
#include "UC.h"


class Class{
    private:
        std::string class_code;
        std::vector<string> ucs;
    public:
        Class();
        Class(std::string class_code);
        void addUC(std::string);//add uc to ucs;
        //Getters
        std::string getClass_code() const;
        const std::vector<std::string>& getUCs()const;
        
        //Setters
        void setClass(std::string& new_class_code);
};

#endif //AEDPROJ_CLASS_H
