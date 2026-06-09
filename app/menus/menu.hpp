#ifndef MENUS_HPP
#define MENUS_HPP

#include "EmergencyMenu.hpp"
#include "HospitalManagement.hpp"
#include "VisitedPatientMenu.hpp"
#include <cstdlib>

using namespace std;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen()
{
    cout << "\nNhan Enter de tiep tuc...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}


#endif