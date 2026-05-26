#include <iostream>
#include "menu.hpp"
using namespace std;

int main(){
    int choice;

    do {
        system("cls");
        showMenu();
        cin >> choice;

        system("cls");

        switch (choice) {
        case 1:
            cout << "=== ADD PATIENT ===\n";
            cout << "Thuc hien chuc nang them benh nhan...\n";
            pauseScreen();
            break;

        case 2:
            cout << "=== SEARCH PATIENT ===\n";
            cout << "Thuc hien chuc nang tim benh nhan...\n";
            pauseScreen();
            break;

        case 3:
            cout << "=== REMOVE PATIENT ===\n";
            cout << "Thuc hien chuc nang xoa benh nhan...\n";
            pauseScreen();
            break;

        case 4:
            cout << "=== SHOW ALL PATIENTS ===\n";
            cout << "Hien thi danh sach benh nhan...\n";
            pauseScreen();
            break;

        case 0:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice!\n";
            pauseScreen();
        }

    } while (choice != 0);

    return 0;
}