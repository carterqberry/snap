//
// Created by Jake on 1/28/22.
//

#ifndef SNAPLAB_CSG_H
#define SNAPLAB_CSG_H
#include "Course.h"

class Csg : public Course{
public:
    Csg(){
        courseName = "noName";
        studentID = "noSI";
        grade = "noGrade";
    }
    Csg(string n, string i, string g){
        courseName = n;
        studentID = i;
        grade = g;
    };
    string getID(){
        return studentID;
    }
    string getGrade(){
        return grade;
    }
    string toString() const;
    friend ostream& operator<< (ostream& os, const Csg& csg);
private:
    string studentID;
    string grade;
};


#endif //SNAPLAB_CSG_H
