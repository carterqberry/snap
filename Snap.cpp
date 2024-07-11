//
// Created by Jake on 1/26/22.
//

#include "Snap.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Snap::Snap(){
    studentID = "00";
    studentName = "noName";
    studentAddress = "noAddress";
    studentPhone = "noPhone";
}

Snap::Snap(string studentID, string studentName, string studentAddress, string studentPhone){
    this->studentID = studentID;
    this->studentName = studentName;
    this->studentAddress = studentAddress;
    this->studentPhone = studentPhone;
}

string Snap::getSA(){
    return studentAddress;
}

string Snap::getSI(){
    return studentID;
}

string Snap::getSN(){
    return studentName;
}

string Snap::getSP(){
    return studentPhone;
}

string Snap::toString() const
{   stringstream out;
    out << "snap(" << this->studentID;
    out << "," << this->studentName;
    out << "," << this->studentAddress;
    out << "," << this->studentPhone << ")";
    return out.str();
}

ostream& operator<< (ostream& os, const Snap& snap)
{
    os << snap.toString();
    return os;
}