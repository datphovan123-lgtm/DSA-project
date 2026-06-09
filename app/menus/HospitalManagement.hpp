#ifndef HOSPITALMANAGEMENT_HPP
#define HOSPITALMANAGEMENT_HPP

#include <iostream>
#include "menu.hpp"
#include "../../system/HospitalSystem.hpp"

using namespace std;

void showHospitalMenu(HospitalSystem &hospital)
{
    int choice;

    do
    {
        cout << "┌───────────────────────────────────────┐\n";
        cout << "│      HOSPITAL MANAGEMENT SYSTEM       │\n";
        cout << "├───────────────────────────────────────┤\n";
        cout << "│ 1. Them benh nhan                     │\n";
        cout << "│ 2. Tim benh nhan                      │\n";
        cout << "│ 3. Xoa benh nhan                      │\n";
        cout << "│ 4. Hien thi tat ca benh nhan          │\n";
        cout << "│ 0. Quay lai menu chinh                │\n";
        cout << "└───────────────────────────────────────┘\n";
        cout << "Choose: ";

        cin >> choice;
        clearScreen();

        switch (choice)
        {
        case 1:
            hospital.addPatient();
            pauseScreen();
            break;

        case 2:
            hospital.findPatientByID();
            pauseScreen();
            break;

        case 3:
            hospital.deletePatient();
            pauseScreen();
            break;

        case 4:
            hospital.displayPatients();
            pauseScreen();
            break;

        case 0:
            break;

        default:
            cout << "Lua chon khong hop le.\n";
            pauseScreen();
            break;
        }
        clearScreen();
    }while(choice != 0);
}

#endif