# About

A **Linked List** is a linear data structure consisting of a collection of nodes. Each node stores data and a pointer to the next node.

The first node is called the **Head**, and the last node points to `NULL` (in a singly linked list).

**Example :-**

```
HEAD
 |
 v
[10 | *] -> [20 | *] -> [30 | NULL]
```

Here:

- `10`, `20`, `30` are data values.
    
- `*` represents a pointer to the next node.
    
- `HEAD` stores the address of the first node.
    
- `NULL` indicates the end of the linked list.
    

## Structure of a Node

A node generally consists of two parts:

1. **Data :-** Stores the actual value.
    
2. **Pointer :-** Stores the address of the next node.
    

```
+---------+----------+
|  Data   |  Next    |
+---------+----------+
```

In C++, we can define a node using a structure.

```
struct Node {
    int data;
    Node* next;
};
```

## Types of Linked Lists

### 1. Singly Linked List

Each node contains data and a pointer to the next node.

The last node points to `NULL`.

```
HEAD
 |
 v
[10 | *] -> [20 | *] -> [30 | NULL]
```

- Traversal is possible only in the forward direction.
    
- Requires one pointer per node.
    
- Simple to implement.
    

### 2. Doubly Linked List

Each node contains three parts:

- Pointer to the previous node.
    
- Data.
    
- Pointer to the next node.
    

```
NULL <- [10] <=> [20] <=> [30] -> NULL
```

- Traversal is possible in both directions.
    
- Requires additional memory for the previous pointer.
    
- Easier to delete a node when its address is already known.
    

### 3. Circular Singly Linked List

The last node points back to the first node instead of pointing to `NULL`.

```
       +-------------------+
       |                   |
       v                   |
HEAD -> [10] -> [20] -> [30]
```

- No `NULL` at the end.
    
- Traversal can continue from the last node to the first.
    
- Useful in circular scheduling.
    

### 4. Circular Doubly Linked List

A doubly linked list in which:

- The last node points to the first node.
    
- The first node's previous pointer points to the last node.
    

```
      +-----------------------+
      |                       |
      v                       |
[10] <=> [20] <=> [30]
  ^                       |
  +-----------------------+
```

- Supports traversal in both directions.
    
- Forms a circular connection.
    

## Basic Operations on Linked List

### 1. Traversal

Visiting every node in the linked list, starting from the head.

```
void traverse(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
```

**Time Complexity :-** O(n)

**Space Complexity :-** O(1)

### 2. Insertion

Adding a new node to the linked list.

**A. Insertion at Beginning**

- Create a new node.
    
- Point its `next` to the current head.
    
- Update head to the new node.
    

```
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}
```

**Time Complexity :-** O(1)

**B. Insertion at End**

- Create a new node.
    
- Traverse to the last node.
    
- Connect the last node to the new node.
    

```
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}
```

**Time Complexity :-** O(n) without a tail pointer.

**C. Insertion at a Specific Position**

- Traverse to the node just before the required position.
    
- Connect the new node to the next node.
    
- Update the previous node's next pointer.
    

**Time Complexity :-** O(n) when traversal is required.

### 3. Deletion

Removing a node from the linked list.

**A. Deletion at Beginning**

- Store the current head in a temporary pointer.
    
- Move head to the next node.
    
- Delete the old head.
    

```
void deleteAtBeginning(Node*& head) {
    if (head == NULL)
        return;

    Node* temp = head;
    head = head->next;

    delete temp;
}
```

**Time Complexity :-** O(1)

**B. Deletion at End**

- Traverse to the second-last node.
    
- Delete the last node.
    
- Set the second-last node's next pointer to `NULL`.
    

**Time Complexity :-** O(n)

**C. Deletion at a Specific Position**

- Traverse to the node before the required position.
    
- Store the node to be deleted.
    
- Update the previous node's next pointer.
    
- Delete the selected node.
    

**Time Complexity :-** O(n) when traversal is required.

### 4. Searching

Finding a particular element in the linked list.

```
bool search(Node* head, int value) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value)
            return true;

        temp = temp->next;
    }

    return false;
}
```

**Time Complexity :-** O(n)

**Space Complexity :-** O(1)

## Array vs Linked List

|Feature|Array|Linked List|
|---|---|---|
|Memory|Contiguous|Non-contiguous|
|Size|Fixed for built-in arrays|Can grow or shrink|
|Access|O(1) by index|O(n)|
|Searching|O(n)|O(n)|
|Insertion at beginning|O(n)|O(1)|
|Deletion at beginning|O(n)|O(1)|
|Extra memory|Usually no pointer per element|Requires pointer(s) per node|
|Cache locality|Generally good|Generally poor|

NOTE :- Insertion and deletion in a linked list are O(1) when the required node or its predecessor is already available. Finding that position can still take O(n).

## Advantages of Linked List

- Dynamic size.
    
- Does not require contiguous memory allocation.
    
- Efficient insertion and deletion when the required position is known.
    
- Useful for implementing stacks, queues, and other data structures.
    

## Disadvantages of Linked List

- No direct access using an index.
    
- Extra memory is required for pointers.
    
- Traversal is slower than array traversal in many practical situations.
    
- Poor cache locality compared to arrays.
    
- Pointer management can make implementation more complex.
    

## Applications of Linked List

- Implementing stacks and queues.
    
- Browser navigation using doubly linked lists.
    
- Music playlists.
    
- Undo and redo operations.
    
- Memory management.
    
- Hash table collision handling using separate chaining.
    
- Round-robin scheduling using circular linked lists.
    

## Important Terms

|Term|Meaning|
|---|---|
|Node|Basic unit of a linked list|
|Head|Pointer to the first node|
|Tail|Last node of the linked list|
|Next|Pointer to the next node|
|Previous|Pointer to the previous node|
|NULL|Indicates no next node in a conventional singly linked list|
|Traversal|Visiting nodes one by one|
|Dynamic Memory Allocation|Allocating memory during program execution|

## NOTE :-

- Linked list nodes are generally allocated dynamically using `new` in C++.
    
- Every node in a singly linked list contains a pointer to the next node.
    
- The head pointer is required to access the linked list.
    
- If the head is lost without preserving its address, the list may become inaccessible.
    
- Always release dynamically allocated nodes to avoid memory leaks.
    
- A linked list does not provide O(1) random access like an array.
    
- A tail pointer can make insertion at the end O(1), but it must be maintained correctly.
    

## Next Topics

1. Singly Linked List Implementation
    
2. Doubly Linked List Implementation
    
3. Circular Linked List Implementation
    
4. Reversing a Linked List
    
5. Middle of a Linked List (Slow and Fast Pointers)
    
6. Detecting a Cycle (Floyd's Cycle Detection)
    
7. Merging Two Sorted Linked Lists
    
8. Linked List Problems on LeetCode