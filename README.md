# DisasterQ
DisasterQ is a C++ console-based disaster response coordination system built to simulate how emergency operations centers manage victim intake and rescue dispatch during large-scale disasters such as earthquakes, typhoons, and floods.
The system addresses a core real-world challenge: when victim reports surge in from multiple locations, coordinators need a structured way to process cases fairly, prioritize the critically injured, and maintain dispatch history without losing state. DisasterQ models this by routing victims with standard injuries into a FIFO queue and escalating critical cases (severity 4–5) into a max-heap priority queue, ensuring the most severe victims are always dispatched first.
Built as a group project for CC 103 – Data Structures and Algorithms, the system implements linked lists and a max-heap from scratch without STL containers, demonstrating core OOP principles alongside manual data structure design.

The Data Structures that were used to program and make the system are

Stacks:
- Stacks was used in system to store information about the victims that were already dispatched per the Dispatch Log function of the system. The most recent dispatched victims will show up at the top of the list and as more victims are registered in the system, the more recent victims will push the older victims down the list.

Queue:
- A Singly Linked List Queue was specifically used as the data structure for this part because of its high performance and compatibility with the task, being storing the victims in the list by the order they arrivee, following the logic of FIFO (First In,  First Out). This uses a O(1) time constraint for enqueue, dequeue, and peeking in the linked list. While searching the linked list will use the O(1) to look from the front to back to find a specific name, location, or severity rate.

Priority Queue:
- This uses Arrays as its data structure via Heap. This helps with the sorting of the victims in severe conditions as Heap will prioritize the most severe case in the priority queue. Though because it is an array, the priority queue can only hold up to 100 victims at a time because these arrays have a set limit on it.

This is how the algorithm will flow:
- System uses two primary data structures: Arrays via Heap for Priority Queue and Linked List for the Queue.
- First, it reads the severity rate of the victim
- Then it checks if it's severe enough for priority queue or not
- For dispatching, priority queued victims are first in line, checking to see who is next in the priority queue after the first one, then it goes to standard queue for dispatching
- Then if needed, a search for a victim can be conducted  
  
Key features:
- Victim intake with name, location, and injury severity scale
- FIFO queue for standard victims; priority queue for critical cases
- Rescue team dispatch with a stack-based log for undo support
- Iterative and recursive display of all pending victims
- Search by victim name or location
- Menu-driven console interface designed for emergency coordinators
