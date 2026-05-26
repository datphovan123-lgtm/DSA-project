#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string id;
    string name;
    int age;
    string department;
    int severityLevel;
    bool hasInsurance;
    double treatmentFee;

    Patient() {
        id = "";
        name = "";
        age = 0;
        department = "";
        severityLevel = 1;
        hasInsurance = false;
        treatmentFee = 0;
    }

    Patient(
        string id,
        string name,
        int age,
        string department,
        int severityLevel,
        bool hasInsurance,
        double treatmentFee
    ) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->department = department;
        this->severityLevel = severityLevel;
        this->hasInsurance = hasInsurance;
        this->treatmentFee = treatmentFee;
    }

    void display() const {
        cout << "Ma benh nhan: " << id << endl;
        cout << "Ho ten: " << name << endl;
        cout << "Tuoi: " << age << endl;
        cout << "Khoa: " << department << endl;
        cout << "Muc do benh: " << severityLevel << endl;
        cout << "Bao hiem: " << (hasInsurance ? "Co" : "Khong") << endl;
        cout << "Vien phi: " << treatmentFee << endl;
    }

    bool operator>(const Patient& other) const {
        return severityLevel > other.severityLevel;
    }

    bool operator<(const Patient& other) const {
        return severityLevel < other.severityLevel;
    }

    bool operator>=(const Patient& other) const {
        return severityLevel >= other.severityLevel;
    }

    bool operator<=(const Patient& other) const {
        return severityLevel <= other.severityLevel;
    }
};

ostream& operator<<(ostream& os, const Patient& patient) {
    os << "-------------------------\n";
    os << "Ma benh nhan: " << patient.id << endl;
    os << "Ho ten: " << patient.name << endl;
    os << "Tuoi: " << patient.age << endl;
    os << "Khoa dieu tri: " << patient.department << endl;
    os << "Muc do benh: " << patient.severityLevel << endl;
    os << "Bao hiem: " << (patient.hasInsurance ? "Co" : "Khong") << endl;
    os << "Vien phi: " << patient.treatmentFee << endl;
    return os;
}

#endif