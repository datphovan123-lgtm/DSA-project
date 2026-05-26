#ifndef VISITSERVICE_HPP
#define VISITSERVICE_HPP

#include <iostream>
#include <string>
#include "../models/Models.hpp"
#include "../lib/Queue.hpp"

using namespace std;

struct VisitService {
private:
    Queue<VisitPatient> normalQueue;

public:
    // Khoi tao hang doi kham voi suc chua 100
    VisitService() : normalQueue(100) {}

    // Dang ky benh nhan kham  vao Queue
    void registerNormalVisit() {
        VisitPatient patient = inputVisitPatient();

        normalQueue.enqueue(patient);

        cout << "\nDang ky kham thanh cong. Benh nhan da vao hang doi kham.\n";
    }

    // Goi benh nhan kham   tiep theo va lay ra khoi Queue
    VisitPatient callNextNormalVisit() {
        if (normalQueue.empty()) {
            cout << "\nKhong co benh nhan nao trong hang doi kham.\n";
            return VisitPatient();
        }

        VisitPatient patient = normalQueue.front();
        normalQueue.dequeue();

        cout << "\n===== BENH NHAN KHAM TIEP THEO =====\n";
        cout << patient;

        return patient;
    }

    // Xem benh nhan dau hang doi nhung khong xoa
    void viewNextNormalVisit() const {
        if (normalQueue.empty()) {
            cout << "\nKhong co benh nhan nao trong hang doi kham.\n";
            return;
        }

        cout << "\n===== BENH NHAN DAU HANG DOI KHAM =====\n";
        cout << normalQueue.front();
    }

    // Hien thi so luong benh nhan dang cho kham  
    void displayNormalQueueSize() const {
        cout << "\nSo benh nhan dang cho kham  : " << normalQueue.size() << endl;
    }

    // Kiem tra hang doi kham co rong khong
    bool empty() const {
        return normalQueue.empty();
    }

private:
    // Nhap thong tin dang ky kham  
    VisitPatient inputVisitPatient() {
        string visitId;
        string name;
        int age;
        string clinicRoom;

        cout << "\n===== DANG KY KHAM =====\n";

        cout << "Nhap ma dang ky kham: ";
        cin >> visitId;

        cin.ignore();

        cout << "Nhap ho ten benh nhan: ";
        getline(cin, name);

        cout << "Nhap tuoi: ";
        cin >> age;

        cin.ignore();

        cout << "Nhap ten phong kham: ";
        getline(cin, clinicRoom);

        return VisitPatient(visitId, name, age, clinicRoom);
    }
};

#endif