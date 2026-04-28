#include <iostream>
#include <limits>   // needed for numeric_limits
#include <string>
#include "coordinator.h"
using namespace std;

string generateID(int num) {
    string id = "V";
    if (num < 10) id += "00";
    else if (num < 100) id += "0";
    id += to_string(num);
    return id;
}

int selectMenu() {
    int choice;
    do {
        cout << "\n\033[36m===== DISASTERQ: DISASTER RESPONSE COORDINATION SYSTEM =====\033[0m\n";
        cout << "1. Report new victim" << endl;
        cout << "2. Dispatch rescue team (process next victim)" << endl;
        cout << "3. Display all pending victims" << endl;
        cout << "4. Search victim by name or location" << endl;
        cout << "5. View dispatch log" << endl;
        cout << "6. Exit" << endl;

        cout << "your choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 6) {
            cout << "\033[31mInvalid Input!\033[0m" << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (choice < 1 || choice > 7);

    return choice;
}