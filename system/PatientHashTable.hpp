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

    int hashFunction(const string& id) const {
        if (id.empty()) return 0;

        char last = id[id.length() - 1];

        if (last >= '0' && last <= '9') {
            return last - '0';
        }

        return 0;
    }

public:
    PatientHashTable() {
        count = 0;
    }

    void insert(const Patient& patient) {
        int index = hashFunction(patient.id);

        if (!table[index].search(patient)) {
            table[index].insert(patient);
            count++;
            cout << "Da them benh nhan vao danh sach!" << index << endl;
        } else {
            cout << "Ma benh nhan da ton tai!\n";
        }
    }

    bool searchById(const string& id) {
        Patient temp;
        temp.id = id;

        int index = hashFunction(id);
        return table[index].search(temp);
    }

    bool removeById(const string& id) {
        Patient temp;
        temp.id = id;

        int index = hashFunction(id);

        if (table[index].remove(temp)) {
            count--;
            return true;
        }

        return false;
    }

    int size() const {
        return count;
    }
};

#endif