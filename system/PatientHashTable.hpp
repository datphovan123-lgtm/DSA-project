#ifndef PATIENTHASHTABLE_HPP
#define PATIENTHASHTABLE_HPP

#include <iostream>
#include <string>
#include "../lib/AVL.hpp"
#include "../models/Patient.hpp"

using namespace std;

struct PatientHashTable {
private:
    AVL<Patient> table[10];
    int count;

    // Bam ma benh nhan dua vao chu so cuoi cung cua id
    int hashFunction(const string& id) const {
        if (id.empty()) return 0;

        char last = id[id.length() - 1];

        if (last >= '0' && last <= '9') {
            return last - '0';
        }

        return 0;
    }

    // Tim benh nhan theo id trong mot cay AVL
    bool findInAVL(AVLNode<Patient>* node, const string& id, Patient& result) const {
        if (node == nullptr) return false;

        if (node->data.id == id) {
            result = node->data;
            return true;
        }

        if (findInAVL(node->left, id, result)) {
            return true;
        }

        return findInAVL(node->right, id, result);
    }

    // Thu thap toan bo benh nhan trong mot cay AVL vao mang
    void collectAVL(AVLNode<Patient>* node, Patient arr[], int& index) const {
        if (node == nullptr) return;

        collectAVL(node->left, arr, index);
        arr[index++] = node->data;
        collectAVL(node->right, arr, index);
    }

public:
    // Khoi tao bang bam rong
    PatientHashTable() {
        count = 0;
    }

    // Them benh nhan vao bang bam
    void insert(const Patient& patient) {
        int index = hashFunction(patient.id);

        Patient temp;
        if (findInAVL(table[index].root, patient.id, temp)) {
            cout << "Ma benh nhan da ton tai!\n";
            return;
        }

        table[index].insert(patient);
        count++;

        cout << "Da them benh nhan vao bucket " << index << endl;
    }

    // Tim benh nhan theo ma id, neu thay thi gan vao result
    bool findById(const string& id, Patient& result) const {
        int index = hashFunction(id);

        return findInAVL(table[index].root, id, result);
    }

    // Tim va in thong tin co ban cua benh nhan theo ma id
    void displayPatientById(const string& id) const {
        Patient result;

        if (!findById(id, result)) {
            cout << "\nKhong tim thay benh nhan co ma: " << id << endl;
            return;
        }

        cout << "\n===== THONG TIN BENH NHAN =====\n";
        cout << "Ma benh nhan: " << result.id << endl;
        cout << "Ho ten: " << result.name << endl;
        cout << "Tuoi: " << result.age << endl;
        cout << "Khoa dieu tri: " << result.department << endl;
        cout << "Muc do benh: " << result.severityLevel << endl;
        cout << "Bao hiem: " << (result.hasInsurance ? "Co" : "Khong") << endl;
        cout << "Vien phi: " << result.treatmentFee << endl;
    }

    // Kiem tra benh nhan co ton tai theo id khong
    bool contains(const string& id) const {
        Patient temp;
        return findById(id, temp);
    }

    // Xoa benh nhan theo ma id
    bool removeById(const string& id) {
        Patient result;

        if (!findById(id, result)) {
            return false;
        }

        int index = hashFunction(id);

        if (table[index].remove(result)) {
            count--;
            return true;
        }

        return false;
    }

    // Tra ve so luong benh nhan trong bang bam
    int size() const {
        return count;
    }

    // Lay tat ca benh nhan trong bang bam dua vao mang arr
    int getAllPatients(Patient arr[]) const {
        int index = 0;

        for (int i = 0; i < 10; i++) {
            collectAVL(table[i].root, arr, index);
        }

        return index;
    }
};

#endif