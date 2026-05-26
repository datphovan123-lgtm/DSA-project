#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <cstdlib>
using namespace std;


// Tam dung, doi nguoi dung nhan Enter
void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

// In menu chinh
void showMenu() {
    cout << "========== HOSPITAL MANAGEMENT ==========\n";
    cout << "1. Them benh nhan\n";
    cout << "2. Tim benh nhan\n";
    cout << "3. Xoa benh nhan\n";
    cout << "4. Hien thi tat ca benh nhan\n";
    cout << "0. Thoat\n";
    cout << "Choose: ";
}

#endif