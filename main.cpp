#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Snap.h"
#include "Csg.h"
#include "Cdh.h"
#include "Cr.h"
using namespace std;

string findName(string, vector<Snap>);

int main(int argc, char* argv[]) {
    if (argc < 3)
    {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);
    if (!out)
    {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }

    string inputLine;

    //these will contain all the Snap, Course (etc) objects
    vector<Snap> snapVector;
    vector<Csg> csgVector;
    vector<Cdh> cdhVector;
    vector<Cr> crVector;

    out << "Input Strings:" << endl;

    while(getline(in, inputLine)){ // this loop reads all of the input file
        string subLine = "";
        stringstream iss(inputLine);
        getline(iss, subLine, '(');
        try{ // checks for erroneous input
            if(subLine != "snap" && subLine != "csg" && subLine != "cdh" && subLine != "cr"){
                throw inputLine;
            }else{
                out << inputLine << endl;
            }
        }
        catch(string ex){
            out << "**Error: " << ex << endl;
        }
        if(subLine == "snap"){ // The next big section of code reads and fills each class vector with their respective data
            string sID;
            string sName;
            string sAddress;
            string sPhone;
            getline(iss, sID, ',');
            getline(iss, sName, ',');
            getline(iss, sAddress, ',');
            getline(iss, sPhone, ')');
            Snap snapData = Snap(sID, sName, sAddress, sPhone);
            snapVector.push_back(snapData);
        }else if(subLine == "csg"){
            string cName;
            string sID;
            string grade;
            getline(iss, cName, ',');
            getline(iss, sID, ',');
            getline(iss, grade, ')');
            Csg csgData = Csg(cName, sID, grade);
            csgVector.push_back(csgData);
        }else if(subLine == "cdh"){
            string cName;
            string day;
            string hour;
            getline(iss, cName, ',');
            getline(iss, day, ',');
            getline(iss, hour, ')');
            Cdh cdhData = Cdh(cName, day, hour);
            cdhVector.push_back(cdhData);
        }else if(subLine == "cr"){
            string cName;
            string room;
            getline(iss, cName, ',');
            getline(iss, room, ')');
            Cr crData = Cr(cName, room);
            crVector.push_back(crData);
        }
    }

    //these print out the information in each vector

    out << endl << "Vectors:" << endl;
    for(int i = 0; i < snapVector.size(); i++){
        out << snapVector.at(i) << endl;
    }
    for(int i = 0; i < csgVector.size(); i++){
        out << csgVector.at(i) << endl;
    }
    for(int i = 0; i < cdhVector.size(); i++){
        out << cdhVector.at(i) << endl;
    }
    for(int i = 0; i < crVector.size(); i++){
        out << crVector.at(i) << endl;
    }
    out << endl << "Course Grades:" << endl;
    for(int i = 0; i < csgVector.size(); i++){
        out << csgVector.at(i).getName() << "," << findName(csgVector.at(i).getID(), snapVector) << ","
        << csgVector.at(i).getGrade() << endl;
        if(i == csgVector.size()-1 || csgVector.at(i).getName() != csgVector.at(i+1).getName()){
            out << endl;
        }
    }
    out << "Student Schedules:" << endl;
    for(int i = 0; i < snapVector.size(); i++){
        vector<Csg> iStudentCoursesGrades;
        vector<Cdh> iStudentDayHours;
        vector<Cr> iStudentRooms;
        out << snapVector.at(i).getSN() << ", " << snapVector.at(i).getSI() << ", "
        << snapVector.at(i).getSA() << ", " << snapVector.at(i).getSP() << endl;
        for(int j = 0; j < csgVector.size(); j++){
            if(snapVector.at(i).getSI() == csgVector.at(j).getID()){
                iStudentCoursesGrades.push_back(csgVector.at(j));
            }
        }
        for(int j = 0; j < iStudentCoursesGrades.size(); j++){
            for(int k = 0; k < cdhVector.size(); k++){
                if(cdhVector.at(k).getName() == iStudentCoursesGrades.at(j).getName()){
                    iStudentDayHours.push_back(cdhVector.at(k));
                }
            }
            for(int s = 0; s < crVector.size(); s++){
                if(crVector.at(s).getName() == iStudentCoursesGrades.at(j).getName()){
                    iStudentRooms.push_back(crVector.at(s));
                }
            }
        }
        for(int j = 0; j < iStudentCoursesGrades.size(); j++){
            out << "  " << iStudentCoursesGrades.at(j).getName() << " ";
            for(int k = 0; k < iStudentDayHours.size(); k++){
                if(iStudentDayHours.at(k).getName() == iStudentCoursesGrades.at(j).getName()){
                    out << iStudentDayHours.at(k).getDay();
                }
            }
            out << " ";
            for(int k = 0; k < iStudentDayHours.size(); k++){
                if(iStudentDayHours.at(k).getName() == iStudentCoursesGrades.at(j).getName()){
                    out << iStudentDayHours.at(k).getHour();
                    break;
                }
            }
            out << ", ";
            for(int k = 0; k < iStudentRooms.size(); k++){
                if(iStudentRooms.at(k).getName() == iStudentCoursesGrades.at(j).getName()){
                    out << iStudentRooms.at(k).getRoom();
                    break;
                }
            }
            out << endl;
        }
        out << endl;
    }
    return 0;
}

string findName(string id, vector<Snap> snaps){ //this returns a student name from the snap vector given a student ID
    for(int i = 0; i < snaps.size(); i++){
        if(id == snaps.at(i).getSI()){
            return snaps.at(i).getSN();
        }
    }
    return "noNameFound";
}