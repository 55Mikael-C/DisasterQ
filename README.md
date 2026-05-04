# DisasterQ
DisasterQ is a C++ console-based disaster response coordination system built to simulate how emergency operations centers manage victim intake and rescue dispatch during large-scale disasters such as earthquakes, typhoons, and floods.

## 📍 Overview
The system addresses a core real-world challenge: when victim reports surge in from multiple locations, coordinators need a structured way to process cases fairly, prioritize the critically injured, and maintain dispatch history without losing state. DisasterQ models this by routing victims with standard injuries into a FIFO queue and escalating critical cases (severity 4–5) into a max-heap priority queue, ensuring the most severe victims are always dispatched first.

Built as a group project for CC 103 – Data Structures and Algorithms, the system implements linked lists and a max-heap from scratch without STL containers, demonstrating core OOP principles alongside manual data structure design.

## The Data Structures

<table width="100%">
  <thead>
    <tr>
      <th>Structure</th>
      <th>Used for</th>
      <th>Reason</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>Stack</strong></td>
      <td>Dispatch Log (LIFO)</td>
      <td>Implements a LIFO (Last-In, First-Out) structure to log all successfully dispatched victims. This ensures the Dispatch Log remains sorted by recency, allowing coordinators to see the latest rescue updates at the top of the stack while older records persist deeper in the structure.</td>
    </tr>
    <tr>
      <td><strong>Queue</strong></td>
      <td>Standard Intake (FIFO)</td>
      <td>A Singly Linked List Queue was implemented to handle victim records in the order of arrival (FIFO). By maintaining pointers to the head and tail, the system guarantees O(1) efficiency for primary queue operations. Searching remains O(n), as the system performs a full traversal to match specific identifiers like location or injury severity.</td>
    </tr>
    <tr>
      <td><strong>Priority Queue</strong></td>
      <td>Critical Case Escalation</td>
      <td>Utilizes a Binary Heap data structure to maintain a strictly prioritized queue. By using an array-based implementation, the system achieves efficient sorting for victims with high severity ratings. Note: The priority queue is subject to a 100-entry limit due to the static allocation of the underlying array.</td>
    </tr>
  </tbody>
</table>

## Algorithm
```
🚑 DisasterQ‧₊˚/
├─ Initialize Stack (Dispatch Log), Queue (Standard), Priority Queue (Critical), and Counter
├─ 🎮 Menu Loop (Options 1-6)
│
├─ 🔎 1. Report Victim/
│  ├─ Input: Name, Location, Severity (1-5)
│  ├─ Generate unique ID (V00X)
│  ├─ if severity >= 4
│  │  └─ 🔺 insert into Priority Queue (Highest severity to front)
│  ├─ else (severity 1-3)
│  │  └─ 🔹 enqueue in Standard Queue (FIFO)
│  └─ increment counter
│
├─ ⛑ 2. Dispatch Rescue/
│  ├─ if Priority Queue is NOT empty:
│  │  ├─ extractMax (highest priority)
│  │  └─ 📥 push to Dispatch Stack
│  ├─ else if Standard Queue is NOT empty:
│  │  ├─ dequeue (oldest record)
│  │  └─ 📥 push to Dispatch Stack
│  └─ else: print "No victims pending"
│
├─ 📄 3. Display Queues/
│  ├─ 🟢 Recursive Display: Critical Queue
│  └─ 🔵 Iterative Display: Standard Queue
│
├─ 🔍 4. Search Victim/
│  ├─ Choice: Search by Name or Location
│  ├─ keyword match in Priority Queue
│  └─ keyword match in Standard Queue
│
├─ 📜 5. View Dispatch Log/
│  └─ 📤 Display Stack (LIFO: Most recently dispatched first)
│
└─ 🚪 6. Exit/
   └─ Terminate Program
```

## Iteration Vs Recursion

#### Which is faster?

* In our Standard Queue, we opted for iteration for the displayIterative() and search functions. Since the standard queue is a linear structure, a simple loop is objectively faster; it avoids the "overhead" of creating new stack frames, additional benefit is that it's less prone to "Stack Overflow" errors for large data․
* In contrast, our PriorityQueue uses recursion for the heapify and startRecursiveDisplay() functions. While recursion is slightly more memory-intensive due to the call stack, it is necessary for the O(log n) efficiency of the heap.

#### Which is easier to understand?

* For the standardQueue, iteration is the natural fit. Since the data is a simple sequence (a linked list), a while loop directly mirrors the physical layout of the memory. It reads like a list of instructions: "Start at the first victim, then move to the next." Using recursion here would add unnecessary cognitive load for no functional gain.
* For the criticalQueue, recursion is actually more readable because a Heap is conceptually a tree, not a line. Our heapify and recursiveDisplay functions use a "divide and conquer" logic that handles branching paths (Parent → Left Child / Right Child) simultaneously. To do this with iteration, we would have to implement a manual stack or complex index math, which obscures the intent of the code. Recursion allows the code to stay clean and focus on the relationship between victims' severities rather than the mechanics of navigation.

## 🛠️ Design Decisions

#### 1. Custom Memory Management: Linked Nodes vs. Arrays‧₊˚
The Stack (Dispatch Log) and Standard Queue are built from scratch using singly linked nodes.

* Stack: Uses a top pointer for LIFO (Last-In, First-Out) tracking, ensuring the most recent rescue is always at the top of the log.
* Standard Queue: Uses front and rear pointers for FIFO (First-In, First-Out) processing, ensuring non-critical victims are seen in the order they were reported.
* Trade-off: By avoiding STL containers, we gain absolute control over pointer manipulation, though it requires manual memory cleanup (destructors) to prevent leaks during high-casualty simulations.

#### 2. Dual-Track Triage (Severity-Based Routing)‧₊˚
The system automatically routes victims based on a severity scale (1–5).

* Severity 4–5: Dispatched to the PriorityQueue (Critical).
* Severity 1–3: Dispatched to the StandardQueue (Stable).
* Logic: This ensures that a victim with a life-threatening injury reported at 2:00 PM is always dispatched before a victim with a minor injury reported at 1:00 PM.

#### 3. Binary Heap for Priority Management‧₊˚
Unlike a simple sorted array, our PriorityQueue is implemented as a Max-Heap.

* Performance: It maintains a "Partial Order" where the highest severity is always at the root. This allows for $O(\log n)$ insertions and extractions, which is significantly faster than a standard array when dealing with large numbers of victims.
* Trade-off: Heap logic is more complex to implement than a sorted list, but it provides the efficiency required for a real-time emergency response system.

#### 4. Hybrid Display Strategy (Recursion & Iteration)‧₊˚
We implemented a deliberate split in how data is visualized:

* Recursive Display: Used for the PriorityQueue to naturally traverse the tree-like structure of the heap.
* Iterative Display: Used for the StandardQueue to demonstrate a "low-overhead" traversal of the linear linked list.
* Reasoning: This proves the system can handle both hierarchical and linear data architectures efficiently.

#### 5. Persistent Dispatch Log (The Rescue Stack)‧₊˚
Once a victim is dispatched, they aren't just deleted; they are moved to a Stack.

* Purpose: This serves as a "Last-Rescued-First" audit trail. If a coordinator needs to check the most recent activity, the Stack provides immediate access ($O(1)$) to the last dispatched victim.
* Trade-off: Memory remains allocated for dispatched victims, but this is a necessary cost for maintaining a searchable history of the rescue operation.

#### 6. Multi-Parameter Search Functionality‧₊˚
The system supports searching by both Name and Location across all data structures simultaneously.

* Implementation: Since victims move between queues and the stack, the search logic must "poll" every container to find a match.
* Trade-off: This is an $O(n)$ operation, but essential for family members trying to locate victims in a chaotic disaster zone.

## Team Members

|  Github Username  |        Full Name        | 
|-------------------|-------------------------|
|  55Mikael-C       | Mikael Enrico Catapang  |
|  Lelemonsquared   | Jex Rommel Maralit      |
|  RikaSetsuka      | Cedrick Endaya          |

## Acknowledgement💖

We would like to express our sincere gratitude to Ma’am Fatima Marie Agdon, MSCS, for her guidance throughout this year. Her dedication to her students made these complex concepts much more approachable, and this project is a direct result of the clarity and support she provided throughout the term. Thank you, Ma'am!
