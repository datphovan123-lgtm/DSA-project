#ifndef EMERGENCYMENU_HPP
#define EMERGENCYMENU_HPP

#include <iostream>
#include "menu.hpp"
#include "../../system/HospitalSystem.hpp"

using namespace std;

void showEmergencyMenu(HospitalSystem &hospital)
{
    int choice;

    do
    {
        clearScreen();

        cout << "┌───────────────────────────────────────┐\n";
        cout << "│           QUAN LY CAP CUU             │\n";
        cout << "├───────────────────────────────────────┤\n";
        cout << "│ 1. Xu ly benh nhan uu tien cao nhat   │\n";
        cout << "│ 2. Xem benh nhan uu tien cao nhat     │\n";
        cout << "│ 3. Xem so luong benh nhan dang cho    │\n";
        cout << "│ 0. Quay lai menu chinh                │\n";
        cout << "└───────────────────────────────────────┘\n";
        cout << "Nhap lua chon: ";

        cin >> choice;
        clearScreen();

        switch (choice)
        {
        case 1:
            hospital.processEmergencyPatient();
            pauseScreen();
            break;

        case 2:
            hospital.viewTopEmergencyPatient();
            pauseScreen();
            break;

        case 3:
            hospital.displayEmergencyQueueSize();
            pauseScreen();
            break;

        case 0:
            break;

        default:
            cout << "Lua chon khong hop le.\n";
            pauseScreen();
            break;
        }

    } while (choice != 0);
}

#endif