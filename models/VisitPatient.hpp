#ifndef VISITPATIENT_HPP
#define VISITPATIENT_HPP

#include <iostream>
#include <string>
using namespace std;

struct VisitPatient {
    string visitId;
    string name;
    int age;
    string clinicRoom;

    VisitPatient() {
        visitId = "";
        name = "";
        age = 0;
        clinicRoom = "";
    }

    VisitPatient(string visitId, string name, int age, string clinicRoom) {
        this->visitId = visitId;
        this->name = name;
        this->age = age;
        this->clinicRoom = clinicRoom;
    }
};

ostream& operator<<(ostream& os, const VisitPatient& patient) {
    os << "-------------------------\n";
    os << "Ma dang ky kham: " << patient.visitId << endl;
    os << "Ho ten: " << patient.name << endl;
    os << "Tuoi: " << patient.age << endl;
    os << "Phong kham: " << patient.clinicRoom << endl;
    return os;
}

#endif