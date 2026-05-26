#include <iostream>

#include "menu.hpp"

#include "../system/Systems.hpp"
#include "../models/Models.hpp"

using namespace std;

int main()
{

    PatientService patientService;

    PatientService patientService;

    // Doc file khi khoi dong
    FileService::loadPatientsFromFile(
        "patients.txt",
        patientService
    );

    int choice;
    do
    {
        system("cls");
        showMenu();
        cin >> choice;
        cin.ignore();

        system("cls");

        switch (choice)
        {
        case 1:
            cout << "=== ADD PATIENT ===\n";
            patientService.addPatient();
            pauseScreen();
            break;
        case 2:
            cout << "=== SHOW ALL PATIENTS ===\n";
            patientService.displayPatients();
            pauseScreen();
            break;
        case 0:
            cout << "Thoat chuong trinh...\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
            pauseScreen();
        }
    } while (choice != 0);

    // Luu file khi thoat// Luu file khi thoat
    FileService::savePatientsToFile(
        "patients.txt",
        patientService
    );

    return 0;
}