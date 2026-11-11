# About

A **Data Structure** is a method of organizing and storing data in a computer so that operations such as accessing, inserting, deleting, searching, and updating can be performed efficiently.

**Example :-** An array stores multiple elements in contiguous memory locations, while a linked list stores elements as nodes connected through pointers.

## Why Data Structures?

Data structures help us to:

- Organize data efficiently.
    
- Perform searching and sorting operations.
    
- Reduce time and memory consumption.
    
- Manage large amounts of data.
    
- Implement complex algorithms.
    
- Represent real-world relationships.
    

## Types of Data Structures

Data structures are broadly classified into two categories:

### 1. Primitive Data Structures

These are the basic data types provided by a programming language.

Examples:

- Integer (`int`)
    
- Character (`char`)
    
- Floating Point (`float`, `double`)
    
- Boolean (`bool`)
    
- Pointer
    

### 2. Non-Primitive Data Structures

These are built using primitive data types and are used to store and organize collections of data.

They are further classified into:

#### A. Linear Data Structures

In a linear data structure, elements are arranged sequentially, one after another.

Examples:

**1. Array**

- Stores elements of the same type.
    
- Elements are stored in contiguous memory locations.
    
- Supports direct access using an index.
    

**2. Linked List**

- Consists of nodes connected through pointers.
    
- Each node contains data and a reference to another node.
    
- Does not require contiguous memory allocation.
    

**3. Stack**

- Follows LIFO (Last In, First Out).
    
- Insertion and deletion happen at the top.
    
- Operations: `push`, `pop`, `top`.
    

**4. Queue**

- Follows FIFO (First In, First Out).
    
- Insertion happens at the rear and deletion at the front.
    
- Operations: `enqueue`, `dequeue`.
    

**5. Deque**

- Double-ended queue.
    
- Insertion and deletion can happen at both ends.
    

#### B. Non-Linear Data Structures

In a non-linear data structure, elements are not arranged sequentially. They are organized in hierarchical or interconnected relationships.

**1. Tree**

- Represents hierarchical relationships.
    
- Consists of nodes connected through edges.
    
- Examples: Binary Tree, Binary Search Tree, AVL Tree, Heap.
    

**2. Graph**

- Consists of vertices (nodes) and edges (connections).
    
- Used to represent networks and relationships.
    
- Examples: Directed Graph, Undirected Graph, Weighted Graph.
    

**3. Hash Table**

- Stores data in key-value pairs.
    
- Uses a hash function to calculate the index where data should be stored.
    
- Provides average O(1) search, insertion, and deletion under suitable conditions.
    

## Classification Based on Memory Allocation

### 1. Static Data Structures

Data structures whose capacity is fixed when they are created.

Example:

```
int arr[5] = {10, 20, 30, 40, 50};
```

- Fixed capacity.
    
- Cannot grow or shrink automatically.
    
- Example: Built-in fixed-size arrays.
    

### 2. Dynamic Data Structures

Data structures that can grow or shrink during program execution.

Examples:

- Linked List
    
- Dynamic Array (`vector`)
    
- Trees
    
- Graphs
    

```
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {10, 20, 30};

    arr.push_back(40);

    return 0;
}
```

NOTE :- A data structure being dynamic does not necessarily mean that every operation requires dynamic memory allocation.

## Common Operations on Data Structures

|Operation|Description|
|---|---|
|Traversal|Visiting each element|
|Insertion|Adding a new element|
|Deletion|Removing an element|
|Searching|Finding a particular element|
|Sorting|Arranging elements in a specific order|
|Accessing|Retrieving an element|
|Updating|Modifying an existing element|
|Merging|Combining two data structures|

## Abstract Data Type (ADT)

An **Abstract Data Type (ADT)** defines what operations can be performed on data without specifying how those operations are implemented.

Example: Stack ADT

Operations:

- `push()` - Insert an element.
    
- `pop()` - Remove the top element.
    
- `top()` - Access the top element.
    
- `empty()` - Check whether the stack is empty.
    

A stack can be implemented using an array or a linked list.

NOTE :- ADT describes the behavior, while a data structure provides the implementation.

## Data Structure vs Algorithm

|Data Structure|Algorithm|
|---|---|
|Organizes and stores data.|Defines steps to solve a problem.|
|Focuses on data organization.|Focuses on problem-solving.|
|Example: Array, Stack, Tree.|Example: Binary Search, Merge Sort.|
|Provides a way to manage data.|Uses data to perform operations.|

## Data Structure Analysis

Every data structure has different performance characteristics.

We generally evaluate them based on:

1. **Time Complexity :-** Time required to perform an operation as data grows.
    
2. **Space Complexity :-** Memory required to store and process data.
    
3. **Memory Overhead :-** Extra memory required for managing the structure.
    
4. **Scalability :-** How well it handles increasing amounts of data.
    

## Important Terms

|Term|Meaning|
|---|---|
|Node|Basic unit containing data and possibly links|
|Pointer|Variable that stores a memory address|
|Index|Position of an element in an indexed structure|
|Root|Topmost node of a tree|
|Leaf|Node without children|
|Edge|Connection between two nodes|
|Vertex|Node in a graph|
|Key|Value used to identify or retrieve data|
|Hash Function|Function that maps a key to a hash value|
|ADT|Abstract Data Type|

## NOTE :-

- Choosing the correct data structure can significantly improve program performance.
    
- Different data structures are suitable for different problems.
    
- Arrays provide fast indexed access, while linked lists support flexible node insertion and deletion.
    
- Stacks and queues are based on specific rules for inserting and removing elements.
    
- Trees and graphs are useful for representing hierarchical and network-based relationships.
    
- Data structures and algorithms are closely related and are usually studied together.
    

## Next Topics

1. [[Array]]
    
2. [[Linked List]]
    
3. [[Stack]]
    
4. [[Queue]]
    
5. [[Hash Table]]
    
6. [[Tree]]
    
7. [[Heap]]
    
8. [[Graph]]
    
9. [[Trie]]
    
10. [[Disjoint Set Union]]