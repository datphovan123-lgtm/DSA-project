#ifndef HOSPITALSYSTEM_HPP
#define HOSPITALSYSTEM_HPP

#include <iostream>
#include <string>

#include "PatientService.hpp"
#include "VisitService.hpp"
#include "EmergencyService.hpp"

using namespace std;

struct HospitalSystem {
private:
    PatientService patientService;
    VisitService visitService;
    EmergencyService emergencyService;
public:
    // Dang ky kham
    void registerNormalVisit() {
        visitService.registerNormalVisit();
    }

    // Goi benh nhan kham tiep theo
    void callNextNormalVisit() {
        visitService.callNextNormalVisit();
    }

    // Xem benh nhan dau hang doi kham 
    void viewNextNormalVisit() const {
        visitService.viewNextNormalVisit();
    }

    // Hien thi so luong benh nhan kham hien tai
    void displayNormalQueueSize() const {
        visitService.displayNormalQueueSize();
    }

     // Xu ly benh nhan cap cuu co do uu tien cao nhat
    void processEmergencyPatient() {
        emergencyService.processEmergencyPatient();
    }

    // Xem benh nhan cap cuu uu tien cao nhat
    void viewTopEmergencyPatient() const {
        emergencyService.viewTopEmergencyPatient();
    }

    // Xem so luong benh nhan cap cuu dang cho
    void displayEmergencyQueueSize() const {
        emergencyService.displayEmergencyQueueSize();
    }

    // Hien thi danh sach benh nhan trong he thong
    void displayPatients() const {
        patientService.displayPatients();
    }
};

#endif