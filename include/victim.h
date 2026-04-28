#ifndef VICTIM_H
#define VICTIM_H

#include <string>
using namespace std;

struct Victim {
    string id;
    string name;
    string location;
    int severity;       // 1–5 scale (1 = minor, 5 = critical)
    int arrivalOrder;   // Used by the queue to maintain FIFO order

    // Default constructor
    Victim() : id("") ,name(""), location(""), severity(0), arrivalOrder(0) {}

    // Parameterized constructor
    Victim(const string& id, const string& name, const string& location, int severity, int arrivalOrder)
        : id(id) ,name(name), location(location), severity(severity), arrivalOrder(arrivalOrder) {}

    // For priority queue comparison (higher severity = higher priority)
    bool operator<(const Victim& other) const {
        return severity < other.severity;
    }

    bool operator>(const Victim& other) const {
        return severity > other.severity;
    }
};

#endif // VICTIM_H