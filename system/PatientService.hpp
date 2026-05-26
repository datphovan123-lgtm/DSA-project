#ifndef PATIENTSERVICE_HPP
#define PATIENTSERVICE_HPP

#include <iostream>
#include "PatientHashTable.hpp"
#include "EmergencyService.hpp"
#include "../models/Models.hpp"
#include "../lib/LinkedList.hpp"
#include "../lib/Algorithms.hpp"

using namespace std;

struct PatientService
{
private:
    PatientHashTable patientTable;
    EmergencyService emergencyQueue;

public:
    // Them benh nhan vao he thong quan ly chinh thuc
    void addPatient()
    {
        // lam 1 ham thong tin trong file txt roi lay
        Patient newPatient;
        cout << "Ten benh nhan: ";
        getline(cin, newPatient.name);
        cout << "Tuoi: ";
        cin >> newPatient.age;
        cin.ignore();
        cout << "Khoa: ";
        getline(cin, newPatient.department);
        cout << "Muc do benh (1-4): ";
        cin >> newPatient.severityLevel;
        cin.ignore();
        cout << "Bao hiem (1. Co / 0. Khong): ";
        cin >> newPatient.hasInsurance;
        cin.ignore();
        cout << "Vien phi: ";
        cin >> newPatient.treatmentFee;
        cin.ignore();
        if (newPatient.severityLevel >= 3)
        {
            emergencyQueue.addEmergencyPatient(newPatient);
        }
        patientTable.insert(newPatient);
    }

    // Them benh nhan tu file txt
    void addPatientFromFile(const Patient &patient)
    {
        // Them vao bang bam
        patientTable.insert(patient);

        // Neu muc do benh >= 3
        // thi dua vao hang doi uu tien
        if (patient.severityLevel >= 3)
        {
            emergencyQueue.addEmergencyPatient(patient);
        }
    }

    // Hien thi toan bo benh nhan trong he thong
    void displayPatients() const
    {
        int n = patientTable.size();

        if (n == 0)
        {
            cout << "\nKhong co benh nhan nao.\n";
            return;
        }

        Patient *patients = new Patient[n];
        int count = patientTable.getAllPatients(patients);

        int choice;

        cout << "\n===== CHON KIEU SAP XEP =====\n";
        cout << "1. Theo ma benh nhan\n";
        cout << "2. Theo ten benh nhan\n";
        cout << "3. Theo cap do benh\n";
        cout << "Chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            quickSort(patients, 0, count - 1, [](const Patient &a, const Patient &b)
                      { return a.id < b.id; });
            break;

        case 2:
            quickSort(patients, 0, count - 1, [](const Patient &a, const Patient &b)
                      { return a.name < b.name; });
            break;

        case 3:
            quickSort(patients, 0, count - 1, [](const Patient &a, const Patient &b)
                      { return a.severityLevel < b.severityLevel; });
            break;

        default:
            cout << "Lua chon khong hop le!\n";
            delete[] patients;
            return;
        }

        cout << "\n===== DANH SACH BENH NHAN =====\n";

        for (int i = 0; i < count; i++)
        {
            patients[i].display();
            cout << endl;
        }

        delete[] patients;
    }

    int getAllPatients(Patient arr[]) const
    {
        return patientTable.getAllPatients(arr);
    }

    // Tra ve so luong benh nhan trong he thong
    int size() const
    {
        return patientTable.size();
    }
};

#endif