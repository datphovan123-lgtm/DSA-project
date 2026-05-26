#ifndef PATIENTSERVICE_HPP
#define PATIENTSERVICE_HPP

#include <iostream>
#include "PatientHashTable.hpp"
#include "../models/Models.hpp"
#include "../lib/LinkedList.hpp"

using namespace std;

struct PatientService {
private:
    PatientHashTable patientTable;

public:
    // Them benh nhan vao he thong quan ly chinh thuc
    void addPatient(const Patient& patient) {
        
    }

    // Hien thi toan bo benh nhan trong he thong
    void displayPatients() const {
    }

    // Tra ve so luong benh nhan trong he thong
    int size() const {
        return patientTable.size();
    }
};

#endif