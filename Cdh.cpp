//
// Created by Jake on 1/28/22.
//

#include "Cdh.h"
#include <sstream>
using namespace std;

string Cdh::toString() const {
    stringstream out;
    out << "cdh(" << this->courseName;
    out << "," << this->day;
    out << "," << this->hour;
    out << ")";
    return out.str();
}

ostream& operator<< (ostream& os, const Cdh& cdh)
{
    os << cdh.toString();
    return os;
}