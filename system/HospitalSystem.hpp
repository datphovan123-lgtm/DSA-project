#ifndef HOSPITALSYSTEM_HPP
#define HOSPITALSYSTEM_HPP

#include <iostream>
#include <string>

#include "PatientService.hpp"
#include "VisitService.hpp"

using namespace std;

struct HospitalSystem {
private:
    PatientService patientService;
    VisitService visitService;
public:
    // Dang ky kham
    void registerNormalVisit() {
        visitService.registerNormalVisit();
    }

    // Goi benh nhan kham tiep theo
    void callNextNormalVisit() {
        visitService.callNextNormalVisit();
    }

    // Xem benh nhan dau hang doi kham thuong
    void viewNextNormalVisit() const {
        visitService.viewNextNormalVisit();
    }

    // Hien thi so luong benh nhan kham thuong dang cho
    void displayNormalQueueSize() const {
        visitService.displayNormalQueueSize();
    }

    // Hien thi danh sach benh nhan trong he thong
    void displayPatients() const {
        patientService.displayPatients();
    }
};

#endif