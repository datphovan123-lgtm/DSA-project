#ifndef PATIENTSERVICE_HPP
#define PATIENTSERVICE_HPP

#include <iostream>
#include "../models/Models.hpp"
#include "../lib/LinkedList.hpp"

using namespace std;

struct PatientService {
private:
    LinkedList<Patient> patients;

public:
    // Them benh nhan vao he thong quan ly chinh thuc
    void addPatient(const Patient& patient) {
        patients.insertBack(patient);
    }

    // Hien thi toan bo benh nhan trong he thong
    void displayPatients() const {
        if (patients.size() == 0) {
            cout << "Danh sach benh nhan trong he thong dang rong.\n";
            return;
        }

        patients.printForward();
    }

    // Tra ve so luong benh nhan trong he thong
    int size() const {
        return patients.size();
    }
};

#endif