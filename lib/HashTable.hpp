#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>
#include <string>
#include "AVL.hpp"
using namespace std;

// Cap key-value luu trong HashTable
template <typename K, typename V>
struct HashEntry {
    K key;
    V value;

    HashEntry() {}

    HashEntry(const K& k, const V& v) {
        key = k;
        value = v;
    }

    bool operator<(const HashEntry<K, V>& other) const {
        return key < other.key;
    }

    bool operator>(const HashEntry<K, V>& other) const {
        return key > other.key;
    }

    bool operator==(const HashEntry<K, V>& other) const {
        return key == other.key;
    }
};

template <typename K, typename V>
struct HashTable {
private:
    AVL<HashEntry<K, V>>* table;
    int capacity;
    int count;

    // Ham bam cho key
    int hashFunction(const K& key) const {
        return std::hash<K>{}(key) % capacity;
    }

public:
    // Khoi tao bang bam voi so bucket mac dinh la 101
    HashTable(int cap = 101) {
        capacity = cap;
        count = 0;
        table = new AVL<HashEntry<K, V>>[capacity];
    }

    // Giai phong bo nho
    ~HashTable() {
        delete[] table;
    }

    // Them hoac cap nhat mot cap key-value
    void insert(const K& key, const V& value) {
        int index = hashFunction(key);

        HashEntry<K, V> entry(key, value);

        if (!table[index].search(entry)) {
            table[index].insert(entry);
            count++;
        } 
        else {
            table[index].remove(entry);
            table[index].insert(entry);
        }
    }

    // Xoa phan tu theo key, tra ve true neu xoa thanh cong
    bool remove(const K& key) {
        int index = hashFunction(key);

        HashEntry<K, V> temp;
        temp.key = key;

        if (table[index].remove(temp)) {
            count--;
            return true;
        }

        return false;
    }

    // Tim value theo key, tra ve con tro den value neu tim thay
    V* find(const K& key) {
        int index = hashFunction(key);

        HashEntry<K, V> temp;
        temp.key = key;

        return findInAVL(table[index].root, temp);
    }

    // Kiem tra key co ton tai trong bang bam khong
    bool contains(const K& key) const {
        int index = hashFunction(key);

        HashEntry<K, V> temp;
        temp.key = key;

        return table[index].search(temp);
    }

    // Tra ve so luong phan tu trong bang bam
    int size() const {
        return count;
    }

    // Xoa toan bo bang bam
    void clear() {
        for (int i = 0; i < capacity; i++) {
            table[i].clear();
        }

        count = 0;
    }

private:
    // Tim entry trong cay AVL va tra ve dia chi value
    V* findInAVL(AVLNode<HashEntry<K, V>>* node, const HashEntry<K, V>& target) {
        if (node == nullptr) return nullptr;

        if (target == node->data) {
            return &(node->data.value);
        }

        if (target < node->data) {
            return findInAVL(node->left, target);
        }

        return findInAVL(node->right, target);
    }
};

#endif