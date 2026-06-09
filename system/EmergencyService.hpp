#ifndef EMERGENCYSERVICE_HPP
#define EMERGENCYSERVICE_HPP

#include <iostream>
#include <string>

#include "../models/Models.hpp"
#include "../lib/PriorityQueue.hpp"

using namespace std;

// Dung rieng cho PriorityQueue de so sanh theo severityLevel
struct EmergencyPatient {
    Patient patient;

    EmergencyPatient() {}

    EmergencyPatient(const Patient& p) {
        patient = p;
    }

    bool operator<(const EmergencyPatient& other) const {
        return patient.severityLevel < other.patient.severityLevel;
    }

    bool operator>(const EmergencyPatient& other) const {
        return patient.severityLevel > other.patient.severityLevel;
    }

    bool operator>=(const EmergencyPatient& other) const {
        return patient.severityLevel >= other.patient.severityLevel;
    }
};

struct EmergencyService {
private:
    PriorityQueue<EmergencyPatient> emergencyQueue;

public:
    // Chi them benh nhan muc do 3 hoac 4 vao PriorityQueue
    void addEmergencyPatient(const Patient& patient) {
        if (patient.severityLevel >= 3) {
            emergencyQueue.insert(EmergencyPatient(patient));

            cout << "\nBenh nhan muc do " << patient.severityLevel
                 << " da duoc dua vao hang doi uu tien.\n";
        }
    }

    // Xu ly benh nhan uu tien cao nhat
    Patient processEmergencyPatient() {
        if (emergencyQueue.empty()) {
            cout << "\nKhong co benh nhan nao trong hang doi uu tien.\n";
            return Patient();
        }

        EmergencyPatient emergencyPatient = emergencyQueue.extract();
        Patient patient = emergencyPatient.patient;

        cout << "\n===== BENH NHAN DUOC XU LY TRUOC =====\n";
        patient.display();

        return patient;
    }

    // Xem benh nhan uu tien cao nhat
    void viewTopEmergencyPatient() const {
        if (emergencyQueue.empty()) {
            cout << "\nKhong co benh nhan nao trong hang doi uu tien.\n";
            return;
        }

        cout << "\n===== BENH NHAN UU TIEN CAO NHAT =====\n";
        emergencyQueue.peek().patient.display();
    }

    // Hien thi so luong benh nhan trong hang doi uu tien
    void displayEmergencyQueueSize() const {
        cout << "\nSo benh nhan dang cho trong hang doi uu tien: "
             << emergencyQueue.size()
             << endl;
    }

    // Kiem tra hang doi uu tien co rong khong
    bool empty() const {
        return emergencyQueue.empty();
    }
};

#endif