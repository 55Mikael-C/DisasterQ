# DisasterQ
DisasterQ is a C++ console-based disaster response coordination system built to simulate how emergency operations centers manage victim intake and rescue dispatch during large-scale disasters such as earthquakes, typhoons, and floods.
The system addresses a core real-world challenge: when victim reports surge in from multiple locations, coordinators need a structured way to process cases fairly, prioritize the critically injured, and maintain dispatch history without losing state. DisasterQ models this by routing victims with standard injuries into a FIFO queue and escalating critical cases (severity 4–5) into a max-heap priority queue, ensuring the most severe victims are always dispatched first.
Built as a group project for CC 103 – Data Structures and Algorithms, the system implements linked lists and a max-heap from scratch without STL containers, demonstrating core OOP principles alongside manual data structure design.

Key features:
- Victim intake with name, location, and injury severity (1–5 scale)
- FIFO queue for standard victims; priority queue for critical cases
- Rescue team dispatch with a stack-based log for undo support
- Iterative and recursive display of all pending victims
- Search by victim name or location
- Menu-driven console interface designed for emergency coordinators
