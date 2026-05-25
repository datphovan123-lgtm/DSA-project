#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
struct AVLNode {
    T data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(const T& val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

template <typename T>
struct AVL {
    AVLNode<T>* root;
    int _size;

    AVL() : root(nullptr), _size(0) {}

    ~AVL() {
        clear();
    }

    // Chen value vao cay AVL
    void insert(const T& value) {
        bool inserted = false;
        root = insertHelper(root, value, inserted);

        if (inserted) {
            _size++;
        }
    }

    // Xoa value khoi cay AVL
    bool remove(const T& value) {
        bool removed = false;
        root = removeHelper(root, value, removed);

        if (removed) {
            _size--;
        }

        return removed;
    }

    // Tim kiem value trong cay AVL
    bool search(const T& value) const {
        return searchHelper(root, value);
    }

    // Duyet cay theo thu tu NLR
    void preorder() const {
        preorderHelper(root);
        cout << endl;
    }

    // Duyet cay theo thu tu LNR
    void inorder() const {
        inorderHelper(root);
        cout << endl;
    }

    // Duyet cay theo thu tu LRN
    void postorder() const {
        postorderHelper(root);
        cout << endl;
    }

    // Tra ve so node trong cay
    int size() const {
        return _size;
    }

    // Kiem tra cay co rong khong
    bool empty() const {
        return root == nullptr;
    }

    // Xoa toan bo cay
    void clear() {
        clearHelper(root);
        root = nullptr;
        _size = 0;
    }

private:
    // Lay chieu cao cua node
    int getHeight(AVLNode<T>* node) const {
        if (node == nullptr) return 0;
        return node->height;
    }

    // Cap nhat chieu cao cua node
    void updateHeight(AVLNode<T>* node) {
        if (node != nullptr) {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        }
    }

    // Tinh he so can bang cua node
    int getBalance(AVLNode<T>* node) const {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Xoay phai de can bang cay
    AVLNode<T>* rotateRight(AVLNode<T>* y) {
        AVLNode<T>* x = y->left;
        AVLNode<T>* temp = x->right;

        x->right = y;
        y->left = temp;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Xoay trai de can bang cay
    AVLNode<T>* rotateLeft(AVLNode<T>* x) {
        AVLNode<T>* y = x->right;
        AVLNode<T>* temp = y->left;

        y->left = x;
        x->right = temp;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Can bang lai node hien tai
    AVLNode<T>* balanceNode(AVLNode<T>* node) {
        updateHeight(node);

        int balance = getBalance(node);

        if (balance > 1) {
            if (getBalance(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }

        if (balance < -1) {
            if (getBalance(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        return node;
    }

    // Ham ho tro chen node vao cay AVL
    AVLNode<T>* insertHelper(AVLNode<T>* node, const T& value, bool& inserted) {
        if (node == nullptr) {
            inserted = true;
            return new AVLNode<T>(value);
        }

        if (value < node->data) {
            node->left = insertHelper(node->left, value, inserted);
        } else if (value > node->data) {
            node->right = insertHelper(node->right, value, inserted);
        } else {
            return node;
        }

        return balanceNode(node);
    }

    // Tim node co gia tri nho nhat trong cay con
    AVLNode<T>* findMin(AVLNode<T>* node) const {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

    // Ham ho tro xoa node khoi cay AVL
    AVLNode<T>* removeHelper(AVLNode<T>* node, const T& value, bool& removed) {
        if (node == nullptr) return nullptr;

        if (value < node->data) {
            node->left = removeHelper(node->left, value, removed);
        } else if (value > node->data) {
            node->right = removeHelper(node->right, value, removed);
        } else {
            removed = true;

            if (node->left == nullptr || node->right == nullptr) {
                AVLNode<T>* temp;

                if (node->left != nullptr) {
                    temp = node->left;
                } else {
                    temp = node->right;
                }

                delete node;
                return temp;
            }

            AVLNode<T>* temp = findMin(node->right);
            node->data = temp->data;

            bool dummy = false;
            node->right = removeHelper(node->right, temp->data, dummy);
        }

        return balanceNode(node);
    }

    // Ham ho tro tim kiem value
    bool searchHelper(AVLNode<T>* node, const T& value) const {
        if (node == nullptr) return false;

        if (value == node->data) return true;

        if (value < node->data) {
            return searchHelper(node->left, value);
        }

        return searchHelper(node->right, value);
    }

    // Ham ho tro duyet NLR
    void preorderHelper(AVLNode<T>* node) const {
        if (node == nullptr) return;

        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    // Ham ho tro duyet LNR
    void inorderHelper(AVLNode<T>* node) const {
        if (node == nullptr) return;

        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }

    // Ham ho tro duyet LRN
    void postorderHelper(AVLNode<T>* node) const {
        if (node == nullptr) return;

        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << " ";
    }

    // Ham ho tro xoa toan bo cay
    void clearHelper(AVLNode<T>* node) {
        if (node == nullptr) return;

        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }
};

#endif