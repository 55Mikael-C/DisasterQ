#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include "victim.h"

// Each node in the linked list queue holds a victim
struct QueueNode {
    Victim data;
    QueueNode* next;

    QueueNode(const Victim& v) : data(v), next(nullptr) {}
};

class Queue {
private:
    QueueNode* front;   // Points to the first victim in line (next to be served)
    QueueNode* rear;    // Points to the last victim in line (most recently added)
    int size;

public:
    // Constructor & Destructor
    Queue();
    ~Queue();

    // Core operations
    void enqueue(const Victim& victim);     // Add a victim to the back of the line
    bool dequeue();                         // Remove and dispatch the front victim
    Victim peekFront() const;              // View the front victim without removing

    // Display
    void displayIterative() const;          // Show all pending victims using a loop

    // Search
    bool searchByName(const string& name) const;
    bool searchByLocation(const string& location) const;

    // Utility
    bool isEmpty() const;
    int getSize() const;
    QueueNode* getFront() const;
};

#endif // QUEUE_H