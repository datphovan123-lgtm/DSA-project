#include <iostream>
#include <windows.h>
#include "menus/menu.hpp"
#include "../models/Models.hpp"
#include "../system/HospitalSystem.hpp"
#include "../system/FileService.hpp"

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    PatientService patientService;

    HospitalSystem hospital;

    // Doc file khi khoi dong
    FileService::loadPatientsFromFile(
        "patients.txt",
        patientService
    );

    int c;

    do{
        cout << "┌───────────────────────────────────────┐\n";
        cout << "│            BENH VIEN POKER            │\n";
        cout << "├───────────────────────────────────────┤\n";
        cout << "│ 1. Quan li benh nhan                  │\n";
        cout << "│ 2. Dang ky va kham thuong             │\n";
        cout << "│ 3. Quan li benh nhan cap cuu          │\n";
        cout << "│ 0. Thoat                              │\n";
        cout << "└───────────────────────────────────────┘\n";
        cout << "Chon thao tac: ";
        cin >> c;
        cin.ignore();

        switch (c)
        {
        case 1:
            showHospitalMenu(hospital);
            break;
        case 2:
            showVisitedPatientMenu(hospital);
            break;
        case 3:
            showEmergencyMenu(hospital);
            break;
        case 0:
            cout << "Dang thoat..." << endl;
            break;
        default:
            cout << "Lua chon khong hop le! Vui long thu lai." << endl;
        }
    } while (c != 0);

    // Luu file khi thoat// Luu file khi thoat
    FileService::savePatientsToFile(
        "patients.txt",
        patientService
    );

    return 0;
}