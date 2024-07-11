//
// Created by Jake on 1/26/22.
//

#ifndef SNAPLAB_SNAP_H
#define SNAPLAB_SNAP_H
#include <string>
#include <iostream>
using namespace std;

class Snap{
public:
    Snap();
    Snap(string, string, string, string);
    string getSI();
    string getSN();
    string getSA();
    string getSP();
    string toString() const;
    friend ostream& operator<< (ostream& os, const Snap& snap);
private:
    string studentID;
    string studentName;
    string studentAddress;
    string studentPhone;
};

#endif //SNAPLAB_SNAP_H
