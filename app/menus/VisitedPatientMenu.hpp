#ifndef VISITEDPATIENTMENU_HPP
#define VISITEDPATIENTMENU_HPP

#include <iostream>
#include "menu.hpp"
#include "../../system/HospitalSystem.hpp"

using namespace std;

// Menu dang ky va kham thuong
void showVisitedPatientMenu(HospitalSystem &hospital)
{
    int choice;

    do
    {
        cout << "┌───────────────────────────────────────┐\n";
        cout << "│         DANG KY VA KHAM BENH          │\n";
        cout << "├───────────────────────────────────────┤\n";
        cout << "│ 1. Dang ky benh nhan kham             │\n";
        cout << "│ 2. Goi benh nhan kham tiep theo       │\n";
        cout << "│ 3. Xem benh nhan dau hang doi         │\n";
        cout << "│ 4. Xem so luong benh nhan dang cho    │\n";
        cout << "│ 0. Quay lai menu chinh                │\n";
        cout << "└───────────────────────────────────────┘\n";
        cout << "Nhap lua chon: ";

        cin >> choice;
        clearScreen();

        switch (choice)
        {
        case 1:
            hospital.registerNormalVisit();
            break;

        case 2:
            hospital.callNextNormalVisit();
            break;

        case 3:
            hospital.viewNextNormalVisit();
            break;

        case 4:
            hospital.displayNormalQueueSize();
            break;

        case 0:
            cout << "Quay lai menu chinh...\n";
            break;

        default:
            cout << "Lua chon khong hop le.\n";
            break;
        }
        clearScreen();

    } while (choice != 0);
}

#endif