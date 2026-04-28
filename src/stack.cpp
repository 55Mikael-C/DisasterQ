#include "stack.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// ─────────────────────────────────────────────
// Constructor & Destructor
// ─────────────────────────────────────────────

Stack::Stack() : top(nullptr), size(0) {}

Stack::~Stack() {
    // Free all nodes on destruction
    while (!isEmpty()) {
        pop();
    }
}

// ─────────────────────────────────────────────
// Core Operations
// ─────────────────────────────────────────────

// Push: logs a newly dispatched victim onto the stack
void Stack::push(const Victim& victim) {
    StackNode* newNode = new StackNode(victim);
    newNode->next = top;
    top = newNode;
    size++;

    cout << "[Dispatch Log] " << victim.name
         << " (Severity: " << victim.severity
         << ", Location: " << victim.location
         << ") has been logged.\n";
}

// Pop: undoes the last dispatch, removes and returns the top record
bool Stack::pop() {
    if (isEmpty()) {
        cout << "[Stack] Dispatch log is empty. Nothing to undo.\n";
        return false;
    }

    StackNode* temp = top;
    top = top->next;
    size--;

    cout << "[Undo] Dispatch of " << temp->data.name
         << " (Severity: " << temp->data.severity
         << ", Location: " << temp->data.location
         << ") has been reversed.\n";

    delete temp;
    return true;
}

// Peek: returns the most recent dispatch without removing it
Victim Stack::peek() const {
    if (isEmpty()) {
        throw runtime_error("[Stack] Dispatch log is empty. Nothing to peek.");
    }
    return top->data;
}

// ─────────────────────────────────────────────
// Display
// ─────────────────────────────────────────────

// Displays all dispatched victims from most recent to oldest
void Stack::display() const {
    if (isEmpty()) {
        cout << "[Dispatch Log] No dispatches recorded yet.\n";
        return;
    }

    cout << "\n===== DISPATCH LOG (Most Recent First) =====\n";

    StackNode* current = top;
    int count = 1;

    while (current != nullptr) {
        cout << count << ". " << current->data.name
             << " | Location: " << current->data.location
             << " | Severity: " << current->data.severity << "\n";
        current = current->next;
        count++;
    }

    cout << "============================================\n";
    cout << "Total dispatched: " << size << "\n\n";
}

// ─────────────────────────────────────────────
// Utility
// ─────────────────────────────────────────────

bool Stack::isEmpty() const {
    return top == nullptr;
}

int Stack::getSize() const {
    return size;
}