# About

A **Queue** is a linear data structure in which insertion takes place at one end, called the **Rear**, and deletion takes place at the other end, called the **Front**.

It follows the **FIFO (First In, First Out)** principle.

**Example :-** A queue of people waiting for a ticket. The person who arrives first gets served first.

```
FRONT                         REAR
  |                             |
  v                             v
+----+    +----+    +----+
| 10 | -> | 20 | -> | 30 |
+----+    +----+    +----+
```

Here:

- `10` is the first element and will be removed first.
    
- `30` is the last element and will be removed last.
    
- New elements are inserted at the rear.
    
- Elements are removed from the front.
    

## Basic Operations of Queue

### 1. Enqueue

Adds a new element at the rear of the queue.

```
Before:                 After Enqueue(40):

FRONT       REAR        FRONT                REAR
  |           |           |                    |
  v           v           v                    v
+----+      +----+      +----+   +----+   +----+   +----+
| 10 | ---> | 30 |      | 10 |-> | 20 |-> | 30 |-> | 40 |
+----+      +----+      +----+   +----+   +----+   +----+
```

**Time Complexity :-** O(1) with a properly maintained rear pointer.

### 2. Dequeue

Removes an element from the front of the queue.

```
Before:                       After Dequeue():

FRONT             REAR        FRONT       REAR
  |                 |           |           |
  v                 v           v           v
+----+   +----+   +----+       +----+     +----+
| 10 |-> | 20 |-> | 30 |       | 20 | --> | 30 |
+----+   +----+   +----+       +----+     +----+
```

**Time Complexity :-** O(1) with a properly maintained front pointer.

### 3. Front / Peek

Returns the first element without removing it.

```
cout << q.front();
```

**Time Complexity :-** O(1)

### 4. Rear / Back

Returns the last element without removing it.

```
cout << q.back();
```

**Time Complexity :-** O(1)

### 5. isEmpty

Checks whether the queue is empty.

```
if (q.empty()) {
    cout << "Queue is empty";
}
```

**Time Complexity :-** O(1)

### 6. Size

Returns the number of elements present in the queue.

```
cout << q.size();
```

**Time Complexity :-** O(1)

## Types of Queues

### 1. Simple Queue (Linear Queue)

A queue that follows the FIFO principle.

- Insertion takes place at the rear.
    
- Deletion takes place at the front.
    
- Elements are processed in their insertion order.
    

```
FRONT                     REAR
  |                         |
  v                         v
[10] -> [20] -> [30] -> [40]
```

### 2. Circular Queue

A queue in which the last position is connected back to the first position.

It uses empty spaces created by deletion at the front instead of wasting them.

```
       +------+ 
       |  10  |
       +------+
      /        \
 +------+    +------+
 |  40  |    |  20  |
 +------+    +------+
      \        /
       +------+
       |  30  |
       +------+
```

- The rear can wrap around to the beginning.
    
- Efficiently utilizes available array space.
    
- Useful in CPU scheduling and buffering.
    

### 3. Priority Queue

A queue in which elements are removed according to their priority rather than their insertion order.

- Higher-priority elements are processed first.
    
- If priorities are equal, ordering depends on the implementation.
    
- Commonly implemented using a heap.
    

Examples:

- CPU scheduling.
    
- Network packet scheduling.
    
- Dijkstra's Algorithm.
    

### 4. Double-Ended Queue (Deque)

A queue in which insertion and deletion are possible from both ends.

```
FRONT                         REAR
  |                             |
  v                             v
<-- [10] <-> [20] <-> [30] -->
```

Types:

- Input Restricted Deque: Insertion is allowed at only one end, but deletion is allowed at both ends.
    
- Output Restricted Deque: Deletion is allowed at only one end, but insertion is allowed at both ends.
    

## Implementation of Queue

A queue can be implemented using arrays or linked lists.

### 1. Queue Using Array

We use two variables:

- `front` - Tracks the first element.
    
- `rear` - Tracks the last element.
    

Initially:

```
int front = -1;
int rear = -1;
```

**Implementation :-**

```
#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        arr[++rear] = value;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    int peek() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return -1;
        }

        return arr[front];
    }

    bool isEmpty() {
        return front == -1;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.peek() << endl;

    q.dequeue();

    cout << q.peek() << endl;

    return 0;
}
```

NOTE :- This is a basic linear array implementation. Even after dequeue, it does not reuse the freed positions at the beginning. A circular queue solves this problem.

### 2. Queue Using Linked List

A linked list can also be used to implement a queue.

We maintain two pointers:

- `front` - Points to the first node.
    
- `rear` - Points to the last node.
    

**Implementation :-**

```
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node{value, NULL};

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    int peek() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }

        return front->data;
    }

    ~Queue() {
        while (front != NULL) {
            dequeue();
        }
    }
};
```

**Advantages:**

- Dynamic size.
    
- No fixed capacity.
    
- Enqueue and dequeue take O(1) time.
    

**Disadvantages:**

- Extra memory is required for pointers.
    
- Dynamic memory allocation has overhead.
    

## Queue in C++ STL

C++ provides a built-in queue container adapter through the Standard Template Library (STL).

```
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << endl;
    cout << q.back() << endl;

    q.pop();

    cout << q.front() << endl;

    cout << q.size() << endl;
    cout << q.empty() << endl;

    return 0;
}
```

Common STL functions:

|Function|Description|
|---|---|
|`push(x)`|Inserts an element at the rear|
|`emplace(x)`|Constructs an element at the rear|
|`pop()`|Removes the front element|
|`front()`|Returns the front element|
|`back()`|Returns the rear element|
|`empty()`|Checks whether the queue is empty|
|`size()`|Returns the number of elements|
|`swap()`|Exchanges two queues|

NOTE :- `pop()` does not return the removed element. Use `front()` before `pop()` if you need its value.

## Queue Overflow and Queue Underflow

### 1. Queue Overflow

Occurs when trying to insert an element into a full queue.

Example: Inserting an element into a full fixed-size array queue.

### 2. Queue Underflow

Occurs when trying to remove an element from an empty queue.

Example: Calling `dequeue()` or `pop()` when no elements are present.

## Applications of Queue

1. **CPU Scheduling :-** Processes are maintained in queues for scheduling.
    
2. **Printer Queue :-** Print jobs are processed in an ordered manner.
    
3. **Breadth First Search :-** BFS uses a queue to traverse graphs and trees.
    
4. **Network Buffering :-** Stores packets temporarily before processing.
    
5. **Task Scheduling :-** Manages tasks waiting for execution.
    
6. **Operating Systems :-** Used in process and resource management.
    
7. **Customer Service Systems :-** Manages people waiting for service.
    
8. **Data Streaming :-** Stores incoming data before processing.
    

## Stack vs Queue

|Feature|Stack|Queue|
|---|---|---|
|Principle|LIFO|FIFO|
|Insertion|Top|Rear|
|Deletion|Top|Front|
|Insertion operation|Push|Enqueue|
|Deletion operation|Pop|Dequeue|
|Access|Top element|Front and rear elements|
|Example|Stack of plates|People waiting in a line|

## Important Terms

|Term|Meaning|
|---|---|
|FIFO|First In, First Out|
|Front|Position of the first element|
|Rear|Position of the last element|
|Enqueue|Insertion operation|
|Dequeue|Deletion operation|
|Circular Queue|Queue with circular connections|
|Priority Queue|Queue based on element priority|
|Deque|Double-ended queue|
|Overflow|Attempting to exceed queue capacity|
|Underflow|Attempting to remove from an empty queue|

## NOTE :-

- Queue follows the FIFO principle.
    
- Insertion takes place at the rear.
    
- Deletion takes place at the front.
    
- A queue can be implemented using arrays or linked lists.
    
- Circular queues help reuse empty positions in array-based queues.
    
- Priority queues process elements according to priority.
    
- C++ provides `queue`, `priority_queue`, and `deque` in the STL.
    
- Enqueue and dequeue can both take O(1) time with a suitable implementation.
    

## Next Topics

1. Circular Queue Implementation
    
2. Deque Implementation
    
3. Priority Queue
    
4. Queue Using Two Stacks
    
5. Stack Using Two Queues
    
6. BFS (Breadth First Search)
    
7. Level Order Traversal
    
8. Sliding Window Maximum
    
9. Queue-Based Problems on LeetCode