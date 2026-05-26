#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <stdexcept>
using namespace std;

// 1. Dinh nghia cau truc Node cho danh sach lien ket don
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& val) : data(val), next(nullptr) {}
};

// 2. Cau truc LinkedList quan ly danh sach lien ket don
template <typename T>
struct LinkedList {
    
    Node<T>* head; // Con tro dau tien cua danh sach
    Node<T>* tail; // Con tro cuoi cung cua danh sach
    int _size;     // Luu so luong phan tu co trong danh sach

    LinkedList() : head(nullptr), tail(nullptr), _size(0) {}

    // Ham huy tu dong giai phong bo nho
    ~LinkedList() {
        clear();
    }

    // Chen dau danh sach
    void insertFront(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        _size++; // Moi lan chen cong them 1 vao size cua danh sach
    }

    // Chen vao cuoi danh sach
    void insertBack(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        _size++;
    }

    // Chen node vao vi tri index 
    void insertAt(int index, const T& value) {
        if (index < 0 || index > _size) {
            throw out_of_range("Index hop khong le!"); // Truong hop index khong hop le
        }
        if (index == 0) {
            insertFront(value); // Chen dau neu index == 0
            return;
        }
        if (index == _size) {
            insertBack(value); // Chen cuoi neu index == size
            return;
        }

        Node<T>* newNode = new Node<T>(value);
        Node<T>* curr = head;
        for (int i = 0; i < index - 1; ++i) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        _size++; // Moi lan chen cong them 1 vao size cua danh sach
    }

    // Xoa phan tu co gia tri == value, tra ve true neu xoa thanh cong, nguoc lai tra ve false
    bool remove(const T& value) {
        if (head == nullptr) return false; // Khong co node nao -> tra ve false

        if (head->data == value) { // Truong hop xoa head
            Node<T>* temp = head;
            head = head->next;
            if (head == nullptr) tail = nullptr;
            delete temp;
            _size--; // Giam size khi xoa 
            return true;
        }

        Node<T>* curr = head;
        while (curr->next != nullptr && curr->next->data != value) {
            curr = curr->next;
        }

        if (curr->next != nullptr) {
            Node<T>* temp = curr->next;
            curr->next = curr->next->next;
            if (temp == tail) {
                tail = curr;
            }
            delete temp;
            _size--; // Giam size khi xoa
            return true;
        }
        return false;
    }

    // Xoa node tai vi tri index
    void removeAt(int index) {
        if (index < 0 || index >= _size) {
            throw out_of_range("Index khong hop le!"); // Truong hop index khong hop le
        }

        if (index == 0) { // Index 0 -> xoa head
            Node<T>* temp = head; 
            head = head->next;
            if (head == nullptr) tail = nullptr;
            delete temp;
        } else {
            Node<T>* curr = head;
            for (int i = 0; i < index - 1; ++i) {
                curr = curr->next;
            }
            Node<T>* temp = curr->next;
            curr->next = temp->next;
            if (temp == tail) {
                tail = curr;
            }
            delete temp;
        }
        _size--; // Giam size khi xoa
    }

    // Tim kiem tra ve node co gia tri == value
    Node<T>* find(const T& value) const {
        Node<T>* curr = head;
        while (curr != nullptr) {
            if (curr->data == value) return curr;
            curr = curr->next;
        }
        return nullptr; // Tra ve NULL neu khong tim thay
    }

    // Tra ve size danh sach
    int size() const {
        return _size;
    }

    // Xoa toan bo danh sach
    void clear() {
        Node<T>* curr = head;
        while (curr != nullptr) {
            Node<T>* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        head = tail = nullptr;
        _size = 0;
    }

    // In ra danh sach tu dau den cuoi
    void printForward() const {
        Node<T>* curr = head;
        while (curr != nullptr) {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }

    // In ra danh sach tu duoi len tren
    void printBackwardHelper(Node<T>* node) const {
        if (node == nullptr) return;
        printBackwardHelper(node->next);
        cout << node->data << " <- ";
    }
};

#endif