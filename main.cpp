#include <iostream>

using namespace std;

int main(){
    cout << "------------Menu-------------" << endl;
    cout << "1. Delete" << endl;
    cout << "2. Add" << endl;
    cout << "3. Create" << endl;
    cout << "4.End" << endl;
    cout << "Choose: ";
    int t;
    cin >> t;
    switch(t){
        case 1: 
            cout << "Delete Function";
            break;
        case 2: 
            cout << "Add Function";
            break;
        case 3: 
            cout << "Create Function";
            break;
        case 4: 
            break;
    }
}