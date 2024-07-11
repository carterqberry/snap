//
// Created by Jake on 1/28/22.
//

#include "Cr.h"
#include <sstream>

string Cr::toString() const {
    stringstream out;
    out << "cr(" << this->courseName;
    out << "," << this->room;
    out << ")";
    return out.str();
}

ostream& operator<< (ostream& os, const Cr& cr)
{
    os << cr.toString();
    return os;
}