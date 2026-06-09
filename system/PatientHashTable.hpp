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
    bool insert(const Patient& patient) {
        int index = hashFunction(patient.id);

        Patient temp;

        if (findInAVL(table[index].root, patient.id, temp)) {
            cout << "Ma benh nhan da ton tai!\n";
            return false;
        }

        table[index].insert(patient);
        count++;

        return true;
    }

    // Tim benh nhan theo ma id, neu thay thi gan vao result
    bool findById(const string& id, Patient& result) const {
        int index = hashFunction(id);

        return findInAVL(table[index].root, id, result);
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

    // Kiem tra bang bam co rong khong
    bool empty() const {
        return count == 0;
    }

    // Lay tat ca benh nhan trong bang bam dua vao mang arr
    int getAllPatients(Patient arr[]) const {
        int index = 0;

        for (int i = 0; i < 10; i++) {
            collectAVL(table[i].root, arr, index);
        }

        return index;
    }

    bool removeById(const string& id)
{
    Patient temp;
    temp.id = id;

    int index = hashFunction(id);

    if (table[index].remove(temp))
    {
        count--;
        return true;
    }

    return false;
}
    // Xoa toan bo bang bam
    void clear() {
        for (int i = 0; i < 10; i++) {
            table[i].clear();
        }

        count = 0;
    }
};

#endif