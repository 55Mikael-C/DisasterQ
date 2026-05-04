#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "victim.h"

const int MAX_SIZE = 100;   // Maximum number of critical victims the heap can hold

class PriorityQueue {
private:
    Victim heap[MAX_SIZE];  // Array-based max-heap
    int size;

    // Internal heap helpers
    void heapifyUp(int index);      // Restores heap order after insert
    void heapifyDown(int index);    // Restores heap order after extract

    // Index helpers for navigating the heap array
    int parent(int index) const;
    int leftChild(int index) const;
    int rightChild(int index) const;

    void swap(Victim& a, Victim& b);

public:
    // Constructor
    PriorityQueue();

    // Core operations
    void insert(const Victim& victim);  // Add a critical victim
    bool extractMax();                  // Dispatch the highest severity victim
    Victim peekMax() const;            // View the highest severity victim without removing

    // Display
    void displayRecursive(int index, int position) const;
    void startRecursiveDisplay() const;

    // Search
    bool searchByName(const string& name) const;
    bool searchByLocation(const string& location) const;

    // Utility
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
};

#endif // PRIORITY_QUEUE_H