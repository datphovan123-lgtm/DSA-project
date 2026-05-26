#ifndef EMERGENCYSERVICE_HPP
#define EMERGENCYSERVICE_HPP

#include <iostream>
#include <string>
#include "../models/Models.hpp"
#include "../lib/PriorityQueue.hpp"

using namespace std;

struct EmergencyService {
private:
    PriorityQueue<Patient> emergencyQueue;

public:
    // Them benh nhan cap cuu vao PriorityQueue
    void addEmergencyPatient(const Patient& patient) {
        emergencyQueue.insert(patient);
        cout << "\nBenh nhan cap cuu da duoc dua vao hang doi uu tien.\n";
    }

    // Xu ly benh nhan cap cuu co muc do uu tien cao nhat
    Patient processEmergencyPatient() {
        if (emergencyQueue.empty()) {
            cout << "\nKhong co benh nhan cap cuu nao dang cho.\n";
            return Patient();
        }

        Patient patient = emergencyQueue.extract();

        cout << "\n===== BENH NHAN CAP CUU DUOC XU LY =====\n";
        cout << patient;

        return patient;
    }

    // Xem benh nhan cap cuu uu tien cao nhat
    void viewTopEmergencyPatient() const {
        if (emergencyQueue.empty()) {
            cout << "\nKhong co benh nhan cap cuu nao dang cho.\n";
            return;
        }

        cout << "\n===== BENH NHAN CAP CUU UU TIEN CAO NHAT =====\n";
        cout << emergencyQueue.peek();
    }

    // Hien thi so luong benh nhan cap cuu
    void displayEmergencyQueueSize() const {
        cout << "\nSo benh nhan cap cuu dang cho: " << emergencyQueue.size() << endl;
    }
};

#endif