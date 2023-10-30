#include "Lecture.h"
#include "Class.h"
#include "UC.h"

Lecture::Lecture(std::string type, std::string weekday, double start_hour,double lecture_time,std::string uccode,std::string clcode){
    this->type=type;
    this->weekday=weekday;
    this->start_hour=start_hour;
    this->lecture_time=lecture_time;
    this->uccode=uccode;
    this->clcode=clcode;
}
Lecture::Lecture(){
    type="";weekday="";start_hour=0;lecture_time=0;
    uccode="";
    clcode="";
}
std::string Lecture::getType() const{
    return type;
}
std::string Lecture::getWeekday()const{
    return weekday;
}
double Lecture::getStartH()const{
    return start_hour;
}
double Lecture::getLecTime()const{
    return lecture_time;
}
std::string Lecture::getUC()const{
    return uccode;
}
std::string Lecture::getClass()const{
    return clcode;
}