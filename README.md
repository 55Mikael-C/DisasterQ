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

Iterative Vs Recursive Comparison:
Which is faster?
- Iteration is faster than recursion in terms of unnecessary use of computer memory because you only have the loop running in a single function instead of the CPU wasting resources by having to remember which part of a function you were executing before you called a different function․ In your Standard Queue‚ every iteration loop only needs a fixed amount of memory․ In your Priority Queue‚ every Recursion uses up part of the "Call Stack" at every level of the heap․ Thus‚ iteration is more memory-efficient‚ and less prone to "Stack Overflow" errors for large data․
Which is easier to understand?
- The answer depends entirely on the shape of your data: Iteration is easier for linear structures, like your standard linked list, because it mimics reading a simple list from top to bottom. However, Recursion is very often the easier one of the two understand because of data structures like the Heap data structure the programmers used and the code structure mirrors the branching "parent-child" relationship of a tree. While an iterative tree-traversal would require complex manual management of a stack, recursion allows you to handle branching paths with just a few lines of well aligned code.

Design Choices
- The system prioritizes order and safety over efficiency. By choosing a Max-Heap data structure, the system guarantees that the severity level of the victims is the priority for critical cases. By choosing a Linked List, it ensures that the system can remain fair for everybody else. The biggest trade-off made throughout the project is the memory being used over the reliability of the system because it uses extra memory to ensure that when a dispatcher asks "Who is next?", the answer is calculated in O(1) or O(log n) time, ensuring no delay in life-saving decisions.

Team Members:
- 55Mikael-C || Mikael Enrico Catapang
- Lelemonsquared || Jex Rommel Maralit
- RikaSetsuka || Cedrick Endaya

Acknowledgement

We, as the team that worked on this system, would like to give our thanks to Ma'am Fatima Marie Agdon, MSCS, for the guidance, teachings, support and insights that she has given us throughout the development of the project. Her dedication to all of her students, not only us, have greatly contributed to how we understood the data structures and algorithms that we have used, and the overall completion of this project is thanks to her.
