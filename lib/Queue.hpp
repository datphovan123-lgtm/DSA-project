#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdexcept>

template <typename T>
struct Queue {
    T* data;
    int capacity;
    int frontIndex;  // Index cua phan tu duoc push vao gan nhat
    int rearIndex;   // Index cua phan tu dau hang
    int _size;       // So luong phan tu hien tai trong Queue

    // Ham khoi tao
    Queue(int cap) {
        capacity = cap;
        data = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
        _size = 0;
    }

    // Ham huy
    ~Queue() {
        delete[] data;
    }

    // Them phan tu vao cuoi hang
    void enqueue(const T& item) {
        if (_size == capacity) {
            throw overflow_error("Queue da day!"); // Queue da day -> khong the enqueue them
        }
        rearIndex = (rearIndex + 1) % capacity; // Tan dung lai khoang trong trong queue khi xoa phan tu dau mang
        data[rearIndex] = item;
        _size++; // Moi lan enqueue cong them 1 vao size cua queue
    }

    // Xoa phan tu o dau hang
    void dequeue() {
        if (empty()) {
            throw out_of_range("Queue dang rong, khong the dequeue!"); // Queue rong -> khong the dequeue
        }
        T frontValue = data[frontIndex];
        // Tang index toi phan tu tiep theo, neu den cuoi mang thi quay lai dau mang
        frontIndex = (frontIndex + 1) % capacity;
        _size--;
    }

    // Lay gia tri o dau hang
    T front() const {
        if (empty()) {
            throw out_of_range("Queue dang rong!"); // Queue rong -> khong the lay gia tri o dau hang
        }
        return data[frontIndex];
    }

    // Kiem tra queue rong hay khong
    bool empty() const {
        return _size == 0;
    }

    // Lay size cua queue
    int size() const {
        return _size;
    }
};

#endif