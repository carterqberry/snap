//
// Created by Jake on 1/28/22.
//

#ifndef SNAPLAB_CR_H
#define SNAPLAB_CR_H
#include "Course.h"
using namespace std;

class Cr : public Course {
public:
    Cr(){
        courseName = "noName";
        room = "noRoom";
    }
    Cr(string n, string r){
        courseName = n;
        room = r;
    }
    string getRoom(){
        return room;
    }
    string toString() const;
    friend ostream& operator<< (ostream& os, const Cr& cr);
private:
    string room;
};


#endif //SNAPLAB_CR_H
