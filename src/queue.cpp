#include "queue.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// ─────────────────────────────────────────────
// Constructor & Destructor
// ─────────────────────────────────────────────

Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// ─────────────────────────────────────────────
// Core Operations
// ─────────────────────────────────────────────

// Enqueue: adds a victim to the back of the line
void Queue::enqueue(const Victim& victim) {
    QueueNode* newNode = new QueueNode(victim);

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    size++;
    cout << "[Queue] " << victim.name
         << " (Severity: " << victim.severity
         << ", Location: " << victim.location
         << ") added to the standard queue.\n";
}

// Dequeue: removes and dispatches the front victim
bool Queue::dequeue() {
    if (isEmpty()) {
        cout << "[Queue] No victims in the standard queue.\n";
        return false;
    }

    QueueNode* temp = front;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    size--;
    cout << "[Dispatch] " << temp->data.name
         << " (Severity: " << temp->data.severity
         << ", Location: " << temp->data.location
         << ") has been dispatched from the standard queue.\n";

    delete temp;
    return true;
}

// Peek: returns the front victim without removing them
Victim Queue::peekFront() const {
    if (isEmpty()) {
        throw runtime_error("[Queue] Standard queue is empty. Nothing to peek.");
    }
    return front->data;
}

// ─────────────────────────────────────────────
// Display
// ─────────────────────────────────────────────

// Iterative display using a while loop
void Queue::displayIterative() const {
    if (isEmpty()) {
        cout << "[Queue] No pending victims in the standard queue.\n";
        return;
    }

    cout << "\n===== STANDARD QUEUE (Iterative) =====\n";

    QueueNode* current = front;
    int position = 1;

    while (current != nullptr) {
        cout << position << ". " << current->data.name
             << " | Location: " << current->data.location
             << " | Severity: " << current->data.severity << "\n";
        current = current->next;
        position++;
    }

    cout << "=======================================\n";
    cout << "Total pending: " << size << "\n\n";
}

// ─────────────────────────────────────────────
// Search
// ─────────────────────────────────────────────

bool Queue::searchByName(const string& name) const {
    QueueNode* current = front;
    bool found = false;

    while (current != nullptr) {
        if (current->data.name == name) {
            cout << "[Found] " << current->data.name
                 << " | Location: " << current->data.location
                 << " | Severity: " << current->data.severity << "\n";
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "[Search] No victim named \"" << name << "\" in the standard queue.\n";
    }

    return found;
}

bool Queue::searchByLocation(const string& location) const {
    QueueNode* current = front;
    bool found = false;

    while (current != nullptr) {
        if (current->data.location == location) {
            cout << "[Found] " << current->data.name
                 << " | Location: " << current->data.location
                 << " | Severity: " << current->data.severity << "\n";
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "[Search] No victims from \"" << location << "\" in the standard queue.\n";
    }

    return found;
}

// ─────────────────────────────────────────────
// Utility
// ─────────────────────────────────────────────

bool Queue::isEmpty() const {
    return front == nullptr;
}

int Queue::getSize() const {
    return size;
}

QueueNode* Queue::getFront() const {
    return front;
}