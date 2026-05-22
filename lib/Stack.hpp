#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>

template <typename T>
struct Stack {
    T* data;
    int topIndex;
    int capacity;

    // Ham khoi tao
    Stack(int cap) {
        capacity = cap;
        data = new T[capacity];
        topIndex = -1;
    }

    // Ham huy
    ~Stack() {
        delete[] data;
    }

    // Push vao dinh stack
    void push(const T& item) {
        if (topIndex == capacity - 1) {
            throw overflow_error("Stack da day!"); // topindex = capacity - 1 -> khong push duoc nua
        }
        topIndex++; // Push vao stack -> tang them 1 vao topindex
        data[topIndex] = item;
    }

    // Xoa phan tu top 
    T pop() {
        if (empty()) {
            throw out_of_range("Khong co phan tu nao trong stack!"); // Stack rong -> khong pop duoc
        }
        T poppedValue = data[topIndex];
        topIndex--; // Pop khoi stack -> giam topindex di 1
        return poppedValue;
    }

    // Lay phan tu o top
    T top() const {
        if (empty()) {
            throw out_of_range("Stack dang rong!");
        }
        return data[topIndex];
    }

    // Kiem tra stack rong hay khong
    bool empty() const {
        return topIndex == -1;
    }

    // Lay size cua stack
    int size() const {
        return topIndex + 1;
    }
};

#endif