//
// Created by Jake on 1/28/22.
//

#ifndef SNAPLAB_COURSE_H
#define SNAPLAB_COURSE_H
#include <string>
using namespace std;

class Course {
public:
    Course(){courseName = "noName";}
    Course(string name){courseName = name;}
    string getName(){
        return courseName;
    }
protected: // makes it inherited
    string courseName;
};


#endif //SNAPLAB_COURSE_H
