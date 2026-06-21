#ifndef HOSPITALSYSTEM_HPP
#define HOSPITALSYSTEM_HPP

#include <iostream>
#include <string>

#include "PatientService.hpp"
#include "EmergencyService.hpp"
#include "VisitService.hpp"

using namespace std;

struct HospitalSystem
{
private:
    PatientService patientService;
    VisitService visitService;

public:
    // Dang ky kham
    void registerNormalVisit()
    {
        visitService.registerNormalVisit();
    }

    // Goi benh nhan kham tiep theo
    void callNextNormalVisit()
    {
        visitService.callNextNormalVisit();
    }

    // Xem benh nhan dau hang doi kham
    void viewNextNormalVisit() const
    {
        visitService.viewNextNormalVisit();
    }

    // Hien thi so luong benh nhan kham hien tai
    void displayNormalQueueSize() const
    {
        visitService.displayNormalQueueSize();
    }

    // Them benh nhan moi
    void addPatient()
    {
        patientService.addPatient();
    }

    // Tim benh nhan theo ma benh nhan
    void findPatientByID()
    {
        patientService.searchPatientById();
    }

    // Xoa benh nhan theo ma benh nhan
    void deletePatient()
    {
        patientService.removePatient();
    }

    // Hien thi danh sach benh nhan
    void displayPatients() const
    {
        patientService.displayPatients();
    }

    // Lay PatientService de FileService load/save
    PatientService &getPatientService()
    {
        return patientService;
    }

    const PatientService &getPatientService() const
    {
        return patientService;
    }

    // Xu ly benh nhan cap cuu uu tien cao nhat
    void processEmergencyPatient()
    {
        patientService.processEmergencyPatient();
    }

    // Xem benh nhan cap cuu uu tien cao nhat
    void viewTopEmergencyPatient() const
    {
        patientService.viewTopEmergencyPatient();
    }

    // Xem so luong benh nhan cap cuu dang cho
    void displayEmergencyQueueSize() const
    {
        patientService.displayEmergencyQueueSize();
    }
};

#endif