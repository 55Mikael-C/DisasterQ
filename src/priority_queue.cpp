#include "priority_queue.h"
#include <iostream>
#include <stdexcept>
using namespace std;


// Constructors of the code

PriorityQueue::PriorityQueue() : size(0) {}

// Index Helpers

int PriorityQueue::parent(int index) const {
    return (index - 1) / 2;
}

int PriorityQueue::leftChild(int index) const {
    return (2 * index) + 1;
}

int PriorityQueue::rightChild(int index) const {
    return (2 * index) + 2;
}

void PriorityQueue::swap(Victim& a, Victim& b) {
    Victim temp = a;
    a = b;
    b = temp;
}

// Heap Helpers

// HeapifyUp: after inserting at the end, bubble up until heap order is restored
void PriorityQueue::heapifyUp(int index) {
    while (index > 0 && heap[index] > heap[parent(index)]) {
        swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

// HeapifyDown: after removing root, push the replacement down until the heap order is restored
void PriorityQueue::heapifyDown(int index) {
    int largest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

// core operators :3

// Insert: This adds a critical victim and restores heap order
void PriorityQueue::insert(const Victim& victim) {
    if (isFull()) {
        cout << "[Priority Queue] is full. Cannot accept more critical victims.\n";
        return;
    }

    heap[size] = victim;
    size++;
    heapifyUp(size - 1);

    cout << "[Priority Queue] " << victim.name
         << " (Severity: " << victim.severity
         << ", Location: " << victim.location
         << ") added to the critical queue.\n";
}

// ExtractMax: This manages the dispatches of the highest severity victim (always at index 0)
bool PriorityQueue::extractMax() {
    if (isEmpty()) {
        cout << "[Priority Queue] No critical victims pending.\n";
        return false;
    }

    cout << "[Dispatch] " << heap[0].name
         << " (Severity: " << heap[0].severity
         << ", Location: " << heap[0].location
         << ") has been dispatched from the critical queue.\n";

    heap[0] = heap[size - 1];   // Move last element to root
    size--;
    heapifyDown(0);             // Restore heap order

    return true;
}

// Peek: This returns the highest severity victim without removing them
Victim PriorityQueue::peekMax() const {
    if (isEmpty()) {
        throw runtime_error("[Priority Queue] Critical queue is empty. Nothing to peek.");
    }
    return heap[0];
}

// Display

// Recursive display traverses the heap array like a tree (level by level)
void PriorityQueue::displayRecursive(int index, int position) const {
    if (index >= size) return;  // Base case: out of bounds

    cout << position << ". " << heap[index].name
         << " | Location: " << heap[index].location
         << " | Severity: " << heap[index].severity << "\n";

    displayRecursive(leftChild(index), position + 1);
    displayRecursive(rightChild(index), position + 1);
}

void PriorityQueue::startRecursiveDisplay() const {
    if (isEmpty()) {
        cout << "[Priority Queue] No critical victims pending.\n";
        return;
    }

    cout << "\n===== CRITICAL QUEUE - MAX HEAP (Recursive) =====\n";
    displayRecursive(0, 1);
    cout << "==================================================\n";
    cout << "Total critical pending: " << size << "\n\n";
}

// Search

bool PriorityQueue::searchByName(const string& name) const {
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (heap[i].name == name) {
            cout << "[Found] " << heap[i].name
                 << " | Location: " << heap[i].location
                 << " | Severity: " << heap[i].severity << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "[Search] No victim named \"" << name << "\" in the critical queue.\n";
    }

    return found;
}

bool PriorityQueue::searchByLocation(const string& location) const {
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (heap[i].location == location) {
            cout << "[Found] " << heap[i].name
                 << " | Location: " << heap[i].location
                 << " | Severity: " << heap[i].severity << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "[Search] No victims from \"" << location << "\" in the critical queue.\n";
    }

    return found;
}

// Utility

bool PriorityQueue::isEmpty() const {
    return size == 0;
}

bool PriorityQueue::isFull() const {
    return size == MAX_SIZE;
}

int PriorityQueue::getSize() const {
    return size;
}