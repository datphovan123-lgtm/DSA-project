#ifndef HOSPITALSYSTEM_HPP
#define HOSPITALSYSTEM_HPP

#include <iostream>
#include <string>
#include "PatientHashTable.hpp"
#include "../models/Patient.hpp"
#include "../lib/LinkedList.hpp"
using namespace std;

struct HospitalSystem {
private:
    LinkedList<Patient> patients;
    PatientHashTable patientTable;

public:
    // Them benh nhan moi vao he thong
    void addPatient() {
        string id, name, department;
        int age, severityLevel;
        int insuranceChoice;
        double treatmentFee;

        cout << "Nhap ma benh nhan: ";
        cin >> id;

        cin.ignore();

        cout << "Nhap ho ten benh nhan: ";
        getline(cin, name);

        cout << "Nhap tuoi: ";
        cin >> age;

        cin.ignore();

        cout << "Nhap khoa dieu tri: ";
        getline(cin, department);

        cout << "Nhap muc do benh 1-4: ";
        cin >> severityLevel;

        cout << "Co bao hiem khong? 1.Co  0.Khong: ";
        cin >> insuranceChoice;

        cout << "Nhap vien phi ban dau: ";
        cin >> treatmentFee;

        Patient newPatient(
            id,
            name,
            age,
            department,
            severityLevel,
            insuranceChoice == 1,
            treatmentFee
        );

        patients.insertBack(newPatient);
        patientTable.insert(newPatient);

        cout << "\nThem benh nhan thanh cong!\n";
    }

    // Hien thi danh sach benh nhan
    void displayPatients() const {
        if (patients.size() == 0) {
            cout << "Danh sach benh nhan dang rong.\n";
            return;
        }

        patients.printForward();
    }
};

#endif