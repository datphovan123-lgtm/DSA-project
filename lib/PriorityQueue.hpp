#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
struct PriorityQueue {
private:
    T* data;
    int capacity;
    int count;

    // Tang kich thuoc mang khi day
    void resize() {
        capacity *= 2;

        T* newData = new T[capacity];

        for (int i = 0; i < count; i++) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

    // Swap hai phan tu
    void swapValue(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    // Day phan tu len tren de giu tinh chat max-heap
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (data[parent] >= data[index]) {
                break;
            }

            swapValue(data[parent], data[index]);
            index = parent;
        }
    }

    // Day phan tu xuong duoi de giu tinh chat max-heap
    void heapifyDown(int index) {
        while (true) {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int largest = index;

            if (left < count && data[left] > data[largest]) {
                largest = left;
            }

            if (right < count && data[right] > data[largest]) {
                largest = right;
            }

            if (largest == index) {
                break;
            }

            swapValue(data[index], data[largest]);
            index = largest;
        }
    }

public:
    // Khoi tao hang doi uu tien rong
    PriorityQueue(int cap = 10) {
        capacity = cap;
        count = 0;
        data = new T[capacity];
    }

    // Giai phong bo nho khi hang doi bi huy
    ~PriorityQueue() {
        delete[] data;
    }

    // Them mot phan tu vao hang doi uu tien
    void insert(const T& value) {
        if (count == capacity) {
            resize();
        }

        data[count] = value;
        heapifyUp(count);
        count++;
    }

    // Lay va xoa phan tu co do uu tien cao nhat
    T extract() {
        if (empty()) {
            throw runtime_error("PriorityQueue is empty");
        }

        T result = data[0];

        data[0] = data[count - 1];
        count--;

        if (!empty()) {
            heapifyDown(0);
        }

        return result;
    }

    // Xem phan tu co do uu tien cao nhat nhung khong xoa
    T peek() const {
        if (empty()) {
            throw runtime_error("PriorityQueue is empty");
        }

        return data[0];
    }

    // Kiem tra hang doi uu tien co rong khong
    bool empty() const {
        return count == 0;
    }

    // Tra ve so phan tu hien co
    int size() const {
        return count;
    }

    // Xoa toan bo phan tu
    void clear() {
        count = 0;
    }
};

#endif