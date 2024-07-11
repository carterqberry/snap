//
// Created by Jake on 1/28/22.
//

#include "Csg.h"
#include <iostream>
#include <sstream>
using namespace std;

string Csg::toString() const {
    stringstream out;
    out << "csg(" << this->courseName;
    out << "," << this->studentID;
    out << "," << this->grade;
    out << ")";
    return out.str();
}
ostream& operator<< (ostream& os, const Csg& csg)
{
    os << csg.toString();
    return os;
}