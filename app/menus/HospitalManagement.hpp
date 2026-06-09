#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <cstdlib>
#include "../../system/HospitalSystem.hpp"
using namespace std;

// Tam dung, doi nguoi dung nhan Enter
void pauseScreen()
{
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

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

        switch (choice)
        {
        case 1:
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
    }
}

#endif