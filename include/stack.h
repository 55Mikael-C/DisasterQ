#ifndef STACK_H
#define STACK_H

#include <string>
#include "victim.h"

// Each node in the linked list stack holds a dispatched victim record
struct StackNode {
    Victim data;
    StackNode* next;

    StackNode(const Victim& v) : data(v), next(nullptr) {}
};

class Stack {
private:
    StackNode* top;
    int size;

public:
    // Constructor & Destructor
    Stack();
    ~Stack();

    // Core operations
    void push(const Victim& victim);   // Log a dispatched victim
    bool pop();                        // Undo the last dispatch
    Victim peek() const;               // View the last dispatched victim without removing

    // Display
    void display() const;              // Show full dispatch log (top to bottom)

    // Utility
    bool isEmpty() const;
    int getSize() const;
};

#endif // STACK_H