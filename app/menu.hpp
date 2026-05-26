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
    cout << "1. Add patient\n";
    cout << "2. Search patient\n";
    cout << "3. Remove patient\n";
    cout << "4. Show all patients\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
}

#endif