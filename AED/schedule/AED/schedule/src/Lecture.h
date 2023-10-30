
#ifndef AEDPROJ_LECTURE_H
#define AEDPROJ_LECTURE_H

#include <string>
#include "Class.h"
#include "UC.h"
class Lecture{
    private:
        std::string type;
        std::string weekday;
        double start_hour;
        double lecture_time;
        std::string uccode;
        std::string clcode;
    public:
        
        Lecture(std::string type, std::string weekday, double start_hour,double lecture_time,std::string uccode,std::string clcode);
        //getters
        Lecture();
        std::string getType()const;
        std::string getWeekday()const;
        double getStartH()const;
        double getLecTime()const;  
        std::string getClass() const;
        std::string getUC() const;  
};
#endif