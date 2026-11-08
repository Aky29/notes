# About

A **Stack** is a linear data structure in which insertion and deletion of elements take place from the same end, called the **Top**.

It follows the **LIFO (Last In, First Out)** principle.

**Example :-** A stack of plates. The last plate placed on top is the first plate removed.

```
       TOP
        |
      +----+
      | 30 |
      +----+
      | 20 |
      +----+
      | 10 |
      +----+
```

Here, `30` is the top element and will be removed first.

## Basic Operations of Stack

### 1. Push

Adds a new element to the top of the stack.

```
Before:          After Push(40):

  +----+           +----+
  | 30 |           | 40 | <- TOP
  +----+           +----+
  | 20 |           | 30 |
  +----+           +----+
  | 10 |           | 20 |
  +----+           +----+
                   | 10 |
                   +----+
```

**Time Complexity :-** O(1)

### 2. Pop

Removes the top element from the stack.

```
Before:          After Pop():

  +----+           +----+
  | 30 | <- TOP    | 20 | <- TOP
  +----+           +----+
  | 20 |           | 10 |
  +----+           +----+
  | 10 |           +----+
  +----+
```

**Time Complexity :-** O(1)

### 3. Peek / Top

Returns the top element without removing it.

```
stack<int> st;

st.push(10);
st.push(20);
st.push(30);

cout << st.top(); // 30
```

**Time Complexity :-** O(1)

### 4. isEmpty

Checks whether the stack contains any elements.

```
if (st.empty()) {
    cout << "Stack is empty";
}
```

**Time Complexity :-** O(1)

### 5. Size

Returns the number of elements present in the stack.

```
cout << st.size();
```

**Time Complexity :-** O(1)

## Implementation of Stack

A stack can be implemented using different data structures.

### 1. Stack Using Array

An array can be used to implement a stack by maintaining a variable called `top`.

Initially:

```
int top = -1;
```

- `top = -1` means the stack is empty.
    
- `top = 0` means the first element is at the top.
    
- `top = capacity - 1` means the stack is full.
    

**Implementation :-**

```
#include <iostream>
using namespace std;

#define SIZE 5

class Stack {
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == SIZE - 1) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }

        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.peek();

    st.pop();

    cout << "\n" << st.peek();

    return 0;
}
```

**Advantages:**

- Simple implementation.
    
- Fast operations.
    
- No extra pointer memory required.
    

**Disadvantages:**

- Fixed capacity in this implementation.
    
- Can result in stack overflow when full.
    

### 2. Stack Using Linked List

A linked list can also be used to implement a stack.

The head node is treated as the top of the stack.

- Push: Insert a node at the beginning.
    
- Pop: Delete the first node.
    
- Peek: Access the head node.
    

```
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node{value, top};
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return -1;
        }

        return top->data;
    }

    ~Stack() {
        while (top != NULL) {
            pop();
        }
    }
};
```

**Advantages:**

- Dynamic size.
    
- No fixed capacity.
    
- Push and pop take O(1) time.
    

**Disadvantages:**

- Extra memory is required for pointers.
    
- Dynamic memory allocation has overhead.
    

## Stack in C++ STL

C++ provides a built-in stack container adapter through the Standard Template Library (STL).

```
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;

    st.pop();

    cout << st.top() << endl;

    cout << st.size() << endl;

    cout << st.empty() << endl;

    return 0;
}
```

Common STL functions:

|Function|Description|
|---|---|
|`push(x)`|Inserts an element|
|`pop()`|Removes the top element|
|`top()`|Returns the top element|
|`empty()`|Checks whether stack is empty|
|`size()`|Returns the number of elements|
|`emplace(x)`|Constructs an element at the top|
|`swap()`|Exchanges two stacks|

NOTE :- `pop()` does not return the removed element. Use `top()` before `pop()` if you need its value.

## Stack Overflow and Stack Underflow

### 1. Stack Overflow

Occurs when an element is pushed into a stack that has reached its maximum capacity.

Example: Pushing an element into a full fixed-size array stack.

### 2. Stack Underflow

Occurs when trying to remove or access an element from an empty stack.

Example: Calling `pop()` when the stack contains no elements.

NOTE :- These terms can also refer to call-stack exhaustion and related runtime failures, not just a manually implemented stack.

## Applications of Stack

1. **Function Calls :-** The call stack manages function execution and return addresses.
    
2. **Recursion :-** Stores information about recursive function calls.
    
3. **Expression Evaluation :-** Used for evaluating mathematical expressions.
    
4. **Expression Conversion :-** Converts infix expressions into postfix or prefix expressions.
    
5. **Parentheses Matching :-** Checks balanced brackets in expressions.
    
6. **Undo / Redo :-** Stores previous actions in applications.
    
7. **Browser History :-** Can be used to manage navigation history.
    
8. **Backtracking :-** Used in maze solving and other search problems.
    
9. **Depth First Search :-** DFS can be implemented using a stack.
    

## Array vs Linked List Implementation

|Feature|Array Stack|Linked List Stack|
|---|---|---|
|Memory|Contiguous|Non-contiguous|
|Capacity|Fixed in basic implementation|Dynamic|
|Push|O(1)|O(1)|
|Pop|O(1)|O(1)|
|Extra pointer memory|No|Yes|
|Overflow|When capacity is reached|When memory allocation fails|

## Important Terms

|Term|Meaning|
|---|---|
|LIFO|Last In, First Out|
|TOP|Position of the last inserted element|
|Push|Insertion operation|
|Pop|Deletion operation|
|Peek|Accessing the top element|
|Overflow|Attempting to exceed stack capacity|
|Underflow|Attempting to remove from an empty stack|
|Call Stack|Memory structure used to manage function calls|
|Recursion|A function calling itself|

## NOTE :-

- Stack follows the LIFO principle.
    
- Insertion and deletion happen only at the top.
    
- Push, pop, and peek generally take O(1) time.
    
- A stack can be implemented using arrays or linked lists.
    
- C++ provides `stack` in the `<stack>` header.
    
- A stack is an ADT; its implementation can use different underlying data structures.
    

## Next Topics

1. Queue
    
2. Deque
    
3. Circular Queue
    
4. Priority Queue
    
5. Infix, Prefix and Postfix Expressions
    
6. Balanced Parentheses
    
7. Next Greater Element
    
8. Monotonic Stack
    
9. Stack-Based Problems on LeetCode