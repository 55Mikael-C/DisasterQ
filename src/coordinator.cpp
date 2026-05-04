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
    num++;
    return id;
}

int selectMenu() {
    int choice;
    do {
        cout << "\n╔══════════════════════════════════════╗\n";
        cout << "║      " << "\033[0mDISASTERQ - RESPONSE CENTER\033[0m" << "     ║\n";
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
        cin.ignore();

        if (cin.fail() || choice < 1 || choice > 6) {
            cout << "\033[31mInvalid Input!\033[0m" << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (choice < 1 || choice > 7);

    return choice;
}

// Option 1: Accept a new victim report and route to the correct queue
void reportVictim(PriorityQueue& criticalQueue, Queue& standardQueue, int& counter) {
    string name, location;
    int severity;
 
    cout << "\n--- ACCEPT VICTIM REPORT ---\n";
 
    cout << "Victim name: ";
    getline(cin, name);
 
    cout << "Location: ";
    getline(cin, location);
 
    cout << "Injury severity (1 = minor, 5 = critical): ";
    cin >> severity;
    cin.ignore();
 
    if (severity < 1 || severity > 5) {
        cout << "[Error] Severity must be between 1 and 5.\n";
        return;
    }
 
    Victim v(generateID(counter), name, location, severity, counter);
 
    // Route: severity 4–5 goes to critical queue, 1–3 goes to standard queue
    if (severity >= 4) {
        criticalQueue.insert(v);
    } else {
        standardQueue.enqueue(v);
    }
}

// Option 2: Dispatch the next victim — critical queue takes priority
void dispatchRescue(Stack& dispatchLog, PriorityQueue& criticalQueue, Queue& standardQueue) {
    cout << "\n--- DISPATCH NEXT VICTIM ---\n";
 
    if (!criticalQueue.isEmpty()) {
        Victim v = criticalQueue.peekMax();
        criticalQueue.extractMax();
        dispatchLog.push(v);
    } else if (!standardQueue.isEmpty()) {
        Victim v = standardQueue.peekFront();
        standardQueue.dequeue();
        dispatchLog.push(v);
    } else {
        cout << "[System] No victims pending in either queue.\n";
    }
}

// Option 3: Display all pending victims in both queues
void displayQueues(PriorityQueue& criticalQueue, Queue& standardQueue) {
    cout << "\n--- DISPLAY ALL PENDING VICTIMS ---\n";
    criticalQueue.startRecursiveDisplay();
    standardQueue.displayIterative();
}