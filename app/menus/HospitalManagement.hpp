#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "menu.hpp"
#include "../../system/HospitalSystem.hpp"
using namespace std;


// In menu chinh
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
        cout << "│ 0. Thoat                              │\n";
        cout << "└───────────────────────────────────────┘\n";
        cout << "Choose: ";

        cin >> choice;

        clearScreen();

        switch (choice)
        {
        case 1:
            cin.ignore();
            hospital.addPatient();
            break;

        case 2:
            hospital.findPatientByID();
            break;

        case 3:
            hospital.deletePatient();
            break;

        case 4:
            hospital.displayPatients();
            break;

        case 0:
            cout << "Quay lai menu chinh...\n";
            break;

        default:
            cout << "Lua chon khong hop le.\n";
            break;
        }
        clearScreen();
    }while(choice != 0);
}

#endif