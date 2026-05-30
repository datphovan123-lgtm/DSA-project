#ifndef FILESERVICE_HPP
#define FILESERVICE_HPP

#include <iostream>
#include <fstream>
#include <string>

#include "PatientService.hpp"

using namespace std;

struct FileService {

    // Doc du lieu benh nhan tu file txt
    static void loadPatientsFromFile(
        const string& filename,
        PatientService& patientService
    ) {
        ifstream fin(filename);

        if (!fin.is_open()) {
            cout << "Khong tim thay file du lieu!\n";
            return;
        }

        long long nextID;

        fin >> nextID;
        fin.ignore();

        patientService.setNextPatientID(nextID);

        Patient patient;

        while (
            getline(fin, patient.id, '|') &&
            getline(fin, patient.name, '|')
        ) {
            fin >> patient.age;
            fin.ignore();

            getline(fin, patient.department, '|');

            fin >> patient.severityLevel;
            fin.ignore();

            fin >> patient.hasInsurance;
            fin.ignore();

            fin >> patient.treatmentFee;
            fin.ignore();

            patientService.addPatientFromFile(patient);
        }

        fin.close();

        cout << "Da tai du lieu tu file!\n";
    }

    // Luu du lieu benh nhan ra file txt
    static void savePatientsToFile(
        const string& filename,
        const PatientService& patientService
    ) {
        ofstream fout(filename);

        if (!fout.is_open()) {
            cout << "Khong the mo file de ghi!\n";
            return;
        }

        fout << patientService.getNextPatientID() << '\n';

        Patient* patients = new Patient[patientService.size()];

        int count = patientService.getAllPatients(patients);

        for (int i = 0; i < count; i++) {
            fout << patients[i].id << '|'
                 << patients[i].name << '|'
                 << patients[i].age << '|'
                 << patients[i].department << '|'
                 << patients[i].severityLevel << '|'
                 << patients[i].hasInsurance << '|'
                 << patients[i].treatmentFee
                 << '\n';
        }

        delete[] patients;

        fout.close();

        cout << "Da luu du lieu vao file!\n";
    }
};

#endif