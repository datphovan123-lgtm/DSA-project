#ifndef BST_HPP
#define BST_HPP

#include <iostream>
using namespace std;

template <typename T>
struct BSTNode {
    T data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const T& val) : data(val), left(nullptr), right(nullptr) {}
};

template <typename T>
struct BST {

    BSTNode<T>* root; // Con tro goc cua cay
    int _size;        // So luong node trong cay

    BST() : root(nullptr), _size(0) {}

    // Ham huy tu dong giai phong bo nho
    ~BST() {
        clear();
    }

    // Chen value vao cay BST
    void insert(const T& value) {
        if (insertHelper(root, value)) {
            _size++;
        }
    }

    // Xoa node co gia tri bang value
    bool remove(const T& value) {
        bool removed = false;
        root = removeHelper(root, value, removed);

        if (removed) {
            _size--;
        }

        return removed;
    }

    // Tim kiem value trong cay
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

    // Tra ve so luong node trong cay
    int size() const {
        return _size;
    }

    // Kiem tra cay co rong hay khong
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

    // Ham ho tro chen node vao cay
    bool insertHelper(BSTNode<T>*& node, const T& value) {
        if (node == nullptr) {
            node = new BSTNode<T>(value);
            return true;
        }

        if (value < node->data) {
            return insertHelper(node->left, value);
        } else if (value > node->data) {
            return insertHelper(node->right, value);
        }

        return false;
    }

    // Ham ho tro tim node nho nhat trong cay con
    BSTNode<T>* findMin(BSTNode<T>* node) const {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }

        return node;
    }

    // Ham ho tro xoa node trong cay
    BSTNode<T>* removeHelper(BSTNode<T>* node, const T& value, bool& removed) {
        if (node == nullptr) return nullptr;

        if (value < node->data) {
            node->left = removeHelper(node->left, value, removed);
        } else if (value > node->data) {
            node->right = removeHelper(node->right, value, removed);
        } else {
            removed = true;

            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }

            if (node->left == nullptr) {
                BSTNode<T>* temp = node->right;
                delete node;
                return temp;
            }

            if (node->right == nullptr) {
                BSTNode<T>* temp = node->left;
                delete node;
                return temp;
            }

            BSTNode<T>* temp = findMin(node->right);
            node->data = temp->data;

            bool dummy = false;
            node->right = removeHelper(node->right, temp->data, dummy);
        }

        return node;
    }

    // Ham ho tro tim kiem value
    bool searchHelper(BSTNode<T>* node, const T& value) const {
        if (node == nullptr) return false;

        if (value == node->data) return true;

        if (value < node->data) {
            return searchHelper(node->left, value);
        }

        return searchHelper(node->right, value);
    }

    // Ham ho tro duyet NLR
    void preorderHelper(BSTNode<T>* node) const {
        if (node == nullptr) return;

        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    // Ham ho tro duyet LNR
    void inorderHelper(BSTNode<T>* node) const {
        if (node == nullptr) return;

        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }

    // Ham ho tro duyet LRN
    void postorderHelper(BSTNode<T>* node) const {
        if (node == nullptr) return;

        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << " ";
    }

    // Ham ho tro xoa toan bo cay
    void clearHelper(BSTNode<T>* node) {
        if (node == nullptr) return;

        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }
};

#endif