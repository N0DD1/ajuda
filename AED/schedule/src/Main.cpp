#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Class.h"
#include "UC.h"
#include "Students.h"
#include "Lecture.h"
#include "UC.cpp"
#include "Students.cpp"
#include "Class.cpp"
#include "Lecture.cpp"
#include <map>
#include <tuple>
using namespace std;
void readData(std::map<std::string, UC>& ucs,std::map<std::string, Class>& classes,std::map<int, Students>& students,std::map<std::tuple<std::string, std::string, std::string>, Lecture>& lectures){
    std::ifstream file1("classes_per_uc.csv");
    if (file1.is_open()) {
        std::string line;
        while (std::getline(file1, line)) {
            if (line[0] != 'U' || !line.empty()) {
                std::istringstream ss(line);
                std::string ucCode, classCode;
                std::getline(ss, ucCode, ',');
                std::getline(ss, classCode);

                if (ucs.find(ucCode) == ucs.end()) {
                    UC newUC(ucCode);
                    ucs[ucCode] = newUC;
                }
                if (classes.find(classCode) == classes.end()) {
                    Class newClass(classCode);
                    classes[classCode] = newClass;
                }
                ucs[ucCode].addClass(classCode);
                classes[classCode].addUC(ucCode);
            }
        }
        file1.close();
    }

    // Ler e analisar classes.csv
    std::ifstream file2("classes.csv");
    if (file2.is_open()) {
        std::string line;
        while (std::getline(file2, line)) {
            if (line[0] != 'C'|| !line.empty()) {
                std::istringstream ss(line);
                std::string classCode, ucCode, weekday, classType;
                double startHour, duration;

                std::getline(ss, classCode, ',');
                std::getline(ss, ucCode, ',');
                std::getline(ss, weekday, ',');
                ss >> startHour;
                ss.ignore(1); // Ignorar a vírgula
                ss >> duration;
                ss.ignore(1); // Ignorar a vírgula
                std::getline(ss, classType);
                std::string TorP;
                
                if (classType=="T")
                {
                    TorP="T";
                }else{
                    TorP="P";
                }
                
                if (lectures.find(std::make_tuple(classCode, ucCode, TorP)) == lectures.end()) {
                    Lecture newlecture(classType, weekday, startHour, duration, ucCode, classCode);
                    lectures[std::tuple(classCode, ucCode, TorP)] = newlecture;
                }    
            }
        }
        file2.close();
    }

    // Ler e analisar students_classes.csv
    std::ifstream in("students_classes.csv");
    std::string line, ucCode_, classCode_, sstudentCode, studentName;
    int studentCode;
    getline(in, line);
    while (getline(in, sstudentCode, ','), getline(in, studentName, ','), getline(in, ucCode_, ','), getline(in, classCode_)) {
        studentCode = stoi(sstudentCode);
        if (students.find(studentCode) == students.end()) {
            students[studentCode] = Students(studentCode, studentName);
        }
        students[studentCode].addClass(classCode_,ucCode_);
        
                
        }
        std::vector<std::pair<std::string, std::string>> studentClasses = students[studentCode].getClasses();
        for (auto ci:studentClasses)
            {
                cout <<ci.first<<","<<ci.second<<endl;
            }
            
    
    // std::ifstream file3("students_classes.csv");
    // if (file3.is_open()) {
    //     std::string line;
    //     while (std::getline(file3, line)) {
    //         if (line[0] != 'S'|| !line.empty()) {
    //             std::istringstream ss(line);
    //             int studentId;
    //             std::string studentName, ucCode, classCode;
    //             ss >> studentId;
    //             ss.ignore(1); // Ignorar a vírgula
    //             std::getline(ss, studentName, ',');
    //             std::getline(ss, ucCode, ',');
    //             std::getline(ss, classCode);

    //             if (students.find(studentId) == students.end()) {
    //                 Students newStudent(studentId,studentName);
    //                 students[studentId] = newStudent;
    //             }
    //             students[studentId].addClass(classCode, ucCode);
    //             std::vector<std::pair<std::string, std::string>> studentClasses = students[studentId].getClasses();
    //             for (auto ci:studentClasses)
    //             {
    //                 cout<<"("<<ci.first<<","<<ci.second<<")"<<endl;
    //             }
                
    //         }
    //     }
    //     file3.close();
    }

void consultStudentSchedule(std::map<std::string, UC>& ucs,std::map<std::string, Class>& classes,std::map<int, Students>& students,std::map<std::tuple<std::string, std::string, std::string>, Lecture>& lectures){
         std::cout << "All Lectures:" << std::endl;
    // for (const auto& lectureEntry : lectures) {
    //     const std::tuple<std::string, std::string,std::string>& lectureKey = lectureEntry.first;
    //     cout << "(" << get<0>(lectureKey) << ", " << get<1>(lectureKey) << ", " << get<2>(lectureKey) << ")" << endl;
        // const Lecture& lecture = lectureEntry.second;
        // std::cout << "Class Code: " << lecture.getClass() << std::endl;
        // std::cout << "UC Code: " << lecture.getUC() << std::endl;
        // std::cout << "Lecture Start hour: " << lecture.getStartH() << std::endl;
        // std::cout << "Lecture Duration: " << lecture.getLecTime() << std::endl;
        // std::cout << "UC: " << lecture.getUC() << std::endl;
        // std::cout << "Class: " << lecture.getClass() << std::endl;
        // std::cout << "Type: " << lecture.getType() << std::endl;
        // std::cout << "Weekday: " << lecture.getWeekday() << std::endl;
        // std::cout << std::endl;
    //}
    std::cout<<"Insert the studentID to see his schedule"<<endl;
    int ID;
    std::cin>>ID;
    std::cout<< '\n';
    if (students.find(ID)==students.end()){
        std::cout<<"No studentID correspond"<<endl;
        consultStudentSchedule(ucs,classes, students, lectures);
    }
    const Students& student= students[ID];
    std::cout<<"Student Name: "<< student.getName()<< std::endl;
    std::vector<std::pair<std::string, std::string>> studentClasses = student.getClasses();
    if (studentClasses.empty()) {
            std::cout << "This student is not enrolled in any classes." << std::endl;
        } else {
            std::cout << "Lectures for this student:" << std::endl;
            for (auto classInfo : studentClasses) {
                std::string classCode = classInfo.first; // Obtém o código da classe
                std::string ucCode = classInfo.second; // Obtém o código da UC
                
                std::cout << "(" << classCode << ", " << ucCode << ", " << "T)" << std::endl;
                
                if (lectures.find(std::tuple(classCode, ucCode, "T"))!=lectures.end())
                {
                    std::cout << "UC: " << ucCode << ", Class: " << classCode << std::endl;
                    std::cout << "Lecture Start Hour: " << lectures[std::tuple(classCode, ucCode, "T")].getStartH() << std::endl;
                    std::cout << "Lecture Duration: " << lectures[std::tuple(classCode, ucCode, "T")].getLecTime() << std::endl;
                    std::cout << "Type: " << lectures[std::tuple(classCode, ucCode, "T")].getType() << std::endl;
                    std::cout << "Weekday: " << lectures[std::tuple(classCode, ucCode, "T")].getWeekday() << std::endl;
                    std::cout << std::endl;   
                }
                
                
                if (lectures.find(std::tuple(classCode, ucCode, "P"))!=lectures.end())
                {
                    std::cout << "UC: " << ucCode << ", Class: " << classCode << std::endl;
                    std::cout << "Lecture Start Hour: " << lectures[std::tuple(classCode, ucCode, "P")].getStartH() << std::endl;
                    std::cout << "Lecture Duration: " << lectures[std::tuple(classCode, ucCode, "P")].getLecTime() << std::endl;
                    std::cout << "Type: " << lectures[std::tuple(classCode, ucCode, "P")].getType() << std::endl;
                    std::cout << "Weekday: " << lectures[std::tuple(classCode, ucCode, "P")].getWeekday() << std::endl;
                    std::cout << std::endl; 
                }
                
                
            }
        }
    
}
void porcessData(){
    std::map<std::string, UC> ucs;
    std::map<std::string, Class> classes;
    std::map<int, Students> students;
    std::map<std::tuple<std::string, std::string, std::string>, Lecture> lectures;
    
    readData(ucs,classes, students, lectures);
    
    
    
    //consultStudentSchedule(ucs,classes, students, lectures);
    // int ID;
    // cin>>ID;
    // if (students.find(ID)!=students.end())
    // {
    //     Students student=students[ID];
    //     std::cout << "Student ID: " << ID << std::endl;
    //     std::cout << "Student Name: " << student.getName() << std::endl;

    //     const std::vector<std::pair<std::string, std::string>>& studentClasses = student.getClasses();

    //     std::cout << "Classes enrolled:" << std::endl;
    //     for (const auto& classInfo : studentClasses) {
    //         std::string classCode = classInfo.first; // Obtém o código da classe
    //         std::string ucCode = classInfo.second; // Obtém o código da UC

    //         std::cout <<  "UC Code: " << ucCode <<", Class Code: " << classCode << std::endl;
    //     }
    //     std::cout << std::endl;
    // }
}

int main() {
    // Inicialize as estruturas de dados necessárias
    porcessData();
    
    return 0;

}


