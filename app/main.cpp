#include <iostream>
#include <windows.h>
#include "menus/menu.hpp"
#include "menus/HospitalManagement.hpp"
#include "menus/EmergencyMenu.hpp"
#include "menus/VisitedPatientMenu.hpp"

#include "../system/HospitalSystem.hpp"
#include "../system/FileService.hpp"

using namespace std;

void showMainMenu(HospitalSystem &hospital)
{
    int choice;

<<<<<<< HEAD
    HospitalSystem hospital;

    // Doc file khi khoi dong
    FileService::loadPatientsFromFile(
        "patients.txt",
        patientService
    );

    int c;

    do{
        
=======
    do
    {
        clearScreen();

>>>>>>> b4e0a3219afcd99018d936e8ab7ac8c85316d715
        cout << "┌───────────────────────────────────────┐\n";
        cout << "│             BENH VIEN POKER           │\n";
        cout << "├───────────────────────────────────────┤\n";
        cout << "│ 1. Quan li benh nhan                  │\n";
        cout << "│ 2. Dang ky va kham thuong             │\n";
        cout << "│ 3. Quan li benh nhan cap cuu          │\n";
        cout << "│ 0. Thoat                              │\n";
        cout << "└───────────────────────────────────────┘\n";
        cout << "Chon thao tac: ";
<<<<<<< HEAD
        cin >> c;
        cin.ignore();

        system("cls");
=======
>>>>>>> b4e0a3219afcd99018d936e8ab7ac8c85316d715

        cin >> choice;

        switch (choice)
        {
        case 1:
            clearScreen();
            showHospitalMenu(hospital);
            break;

        case 2:
            clearScreen();
            showVisitedPatientMenu(hospital);
            break;

        case 3:
            clearScreen();
            showEmergencyMenu(hospital);
            break;

        case 0:
            clearScreen();
            cout << "Cam on ban da su dung chuong trinh.\n";
            break;

        default:
            clearScreen();
            cout << "Lua chon khong hop le.\n";
            pauseScreen();
            break;
        }

    } while (choice != 0);
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    HospitalSystem hospital;

    FileService::loadPatientsFromFile(
        "patients.txt",
        hospital.getPatientService()
    );

    showMainMenu(hospital);

    FileService::savePatientsToFile(
        "patients.txt",
        hospital.getPatientService()
    );

    return 0;
}