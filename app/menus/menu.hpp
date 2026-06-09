#ifndef MENUS_HPP
#define MENUS_HPP

#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

// Xoa man hinh console
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Tam dung man hinh de nguoi dung doc ket qua
void pauseScreen()
{
    cout << "\nNhan Enter de tiep tuc...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

#endif