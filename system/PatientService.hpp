#ifndef PATIENTSERVICE_HPP
#define PATIENTSERVICE_HPP

#include <iostream>
#include <string>
#include <limits>

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
    long long nextPatientID;

public:
    // Khoi tao ma benh nhan dau tien
    PatientService()
    {
        nextPatientID = 25120201;
    }

    // Tao ma benh nhan tu dong
    string generatePatientID()
    {
        string id = to_string(nextPatientID);
        nextPatientID++;
        return id;
    }

    // Lay ma benh nhan tiep theo de luu vao file
    long long getNextPatientID() const
    {
        return nextPatientID;
    }

    // Gan ma benh nhan tiep theo khi doc tu file
    void setNextPatientID(long long id)
    {
        nextPatientID = id;
    }

    // Them benh nhan bang cach nhap tu ban phim
    void addPatient()
    {
        Patient newPatient;

        newPatient.id = generatePatientID();

        cout << "Ma benh nhan: " << newPatient.id << endl;

        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.ignore();
        cout << "Ten benh nhan: ";
        getline(cin, newPatient.name);

        cout << "Tuoi: ";
        cin >> newPatient.age;
        cin.ignore();

        cout << "Khoa: ";
        getline(cin, newPatient.department);

        do
        {
            cout << "Muc do benh:\n";
            cout << "1. Nhe\n";
            cout << "2. Binh thuong\n";
            cout << "3. Nang\n";
            cout << "4. Cap cuu\n";
            cout << "Chon: ";
            cin >> newPatient.severityLevel;

            if (newPatient.severityLevel < 1 || newPatient.severityLevel > 4)
            {
                cout << "Muc do khong hop le. Vui long nhap lai!\n";
            }

        } while (newPatient.severityLevel < 1 || newPatient.severityLevel > 4);

        cout << "Bao hiem (1. Co / 0. Khong): ";
        cin >> newPatient.hasInsurance;
        cin.ignore();

        cout << "Vien phi: ";
        cin >> newPatient.treatmentFee;
        cin.ignore();

        patientTable.insert(newPatient);

        if (newPatient.severityLevel >= 3)
        {
            emergencyQueue.addEmergencyPatient(newPatient);
        }

        cout << "\nThem benh nhan thanh cong!\n";
    }

    // Them benh nhan tu file txt
    void addPatientFromFile(const Patient &patient)
    {
        patientTable.insert(patient);

        if (patient.severityLevel >= 3)
        {
            emergencyQueue.addEmergencyPatient(patient);
        }
    }

    // Lay toan bo benh nhan ra mang
    int getAllPatients(Patient arr[]) const
    {
        return patientTable.getAllPatients(arr);
    }

    // Hien thi toan bo benh nhan theo lua chon sap xep
    void displayPatients() const
    {
        int n = patientTable.size();

        if (n == 0)
        {
            cout << "\nKhong co benh nhan nao trong he thong.\n";
            return;
        }

        Patient *patients = new Patient[n];

        int count = patientTable.getAllPatients(patients);

        int choice;

        cout << "\n========== SAP XEP DANH SACH BENH NHAN ==========\n";
        cout << "1. Theo ma benh nhan\n";
        cout << "2. Theo ten benh nhan\n";
        cout << "3. Theo muc do benh\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Sap xep theo ma benh nhan
            for (int i = 0; i < count - 1; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    if (patients[i].id > patients[j].id)
                    {
                        Patient temp = patients[i];
                        patients[i] = patients[j];
                        patients[j] = temp;
                    }
                }
            }
            break;

        case 2: // Sap xep theo ten
            for (int i = 0; i < count - 1; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    if (patients[i].name > patients[j].name)
                    {
                        Patient temp = patients[i];
                        patients[i] = patients[j];
                        patients[j] = temp;
                    }
                }
            }
            break;

        case 3: // Sap xep theo muc do benh (1 -> 4)
            for (int i = 0; i < count - 1; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    if (patients[i].severityLevel > patients[j].severityLevel)
                    {
                        Patient temp = patients[i];
                        patients[i] = patients[j];
                        patients[j] = temp;
                    }
                }
            }
            break;

        default:
            cout << "\nLua chon khong hop le!\n";
            delete[] patients;
            return;
        }

        cout << "\n========== DANH SACH BENH NHAN ==========\n";
        for (int i = 0; i < count; i++)
        {
            cout << "\nBenh nhan thu " << i + 1 << endl;
            patients[i].display();
        }

        delete[] patients;
    }

    // Tim benh nhan theo ma ID va hien thi thong tin
    void searchPatientById() const
    {
        string id;

        cout << "\nNhap ma benh nhan can tim: ";
        cin >> id;

        Patient result;

        if (patientTable.findById(id, result))
        {
            cout << "\n========== THONG TIN BENH NHAN ==========\n";
            result.display();
        }
        else
        {
            cout << "\nKhong tim thay benh nhan co ma: " << id << endl;
        }
    }

    void removePatient()
    {
        string patientID;

        cin.ignore();
        cout << "Nhap ma benh nhan can xoa: ";
        getline(cin, patientID);

        if (patientTable.removeById(patientID))
        {
            cout << "\nXoa benh nhan thanh cong!\n";
        }
        else
        {
            cout << "\nKhong tim thay benh nhan!\n";
        }
    }

    // Tra ve so luong benh nhan
    int size() const
    {
        return patientTable.size();
    }

    // Xu ly benh nhan cap cuu uu tien cao nhat
    void processEmergencyPatient()
    {
        emergencyQueue.processEmergencyPatient();
    }

    // Xem benh nhan cap cuu uu tien cao nhat
    void viewTopEmergencyPatient() const
    {
        emergencyQueue.viewTopEmergencyPatient();
    }

    // Xem so luong benh nhan cap cuu dang cho
    void displayEmergencyQueueSize() const
    {
        emergencyQueue.displayEmergencyQueueSize();
    }
};

#endif