#include <iostream>
#include <limits>   // needed for numeric_limits
#include <string>
#include "coordinator.h"
#include "priority_queue.h"
#include "queue.h"
#include "stack.h"

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
        cout << "\n╔══════════════════════════════════════╗\n";
        cout << "║      " << "\033DISASTERQ - RESPONSE CENTER\033[0m" << "     ║\n";
        cout << "╠══════════════════════════════════════╣\n";
        cout << "║  1. Accept Victim Report             ║\n";
        cout << "║  2. Dispatch Next Victim             ║\n";
        cout << "║  3. Display All Pending Victims      ║\n";
        cout << "║  4. Search Victim                    ║\n";
        cout << "║  5. View Dispatch Log                ║\n";
        cout << "║  6. Exit                             ║\n";
        cout << "╚══════════════════════════════════════╝\n";
        
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 6) {
            cout << "\033[31mInvalid Input!\033[0m" << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (choice < 1 || choice > 7);

    return choice;
}

void reportVictim(){

}