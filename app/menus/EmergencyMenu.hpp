#ifndef EMERGENCYMENU_HPP
#define EMERGENCYMENU_HPP

#include <iostream>
#include "../../system/HospitalSystem.hpp"

using namespace std;

// Menu quan ly cap cuu
void emergencyMenu(HospitalSystem& hospital) {
    int choice;

    do {
        cout << "\n========== QUAN LY CAP CUU ==========\n";
        cout << "1. Xu ly benh nhan cap cuu uu tien cao nhat\n";
        cout << "2. Xem benh nhan cap cuu uu tien cao nhat\n";
        cout << "3. Xem so luong benh nhan cap cuu dang cho\n";
        cout << "0. Quay lai menu chinh\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            hospital.processEmergencyPatient();
            break;

        case 2:
            hospital.viewTopEmergencyPatient();
            break;

        case 3:
            hospital.displayEmergencyQueueSize();
            break;
            
        case 0:
            cout << "Quay lai menu chinh...\n";
            break;

        default:
            cout << "Lua chon khong hop le.\n";
            break;
        }

    } while (choice != 0);
}

#endif