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

    // Them benh nhan moi vao he thong
    void addPatient() {
        Patient patient = patientService.inputPatient();

        if (patientService.addPatientToSystem(patient)) {
            if (patient.severityLevel >= 3) {
                emergencyService.addEmergencyPatient(patient);
            }

            cout << "\nThem benh nhan thanh cong!\n";
        }
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

    // Tim benh nhan theo ma ID
    void searchPatientById() const {
        patientService.searchPatientById();
    }

    // Lay PatientService de FileService co the load/save file
    PatientService& getPatientService() {
        return patientService;
    }

    // Lay PatientService ban const de save file
    const PatientService& getPatientService() const {
        return patientService;
    }
};

#endif