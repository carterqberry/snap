//
// Created by Jake on 1/28/22.
//

#ifndef SNAPLAB_CDH_H
#define SNAPLAB_CDH_H
#include "Course.h"

class Cdh : public Course{
public:
    Cdh(){
        day = "noDay";
        hour = "noHour";
    }
    Cdh(string n, string d, string h){
        courseName = n;
        day = d;
        hour = h;
    }
    string getDay(){
        return day;
    }
    string getHour(){
        return hour;
    }
    string toString() const;
    friend ostream& operator<< (ostream& os, const Cdh& cdh);
private:
    string day;
    string hour;
};


#endif //SNAPLAB_CDH_H
