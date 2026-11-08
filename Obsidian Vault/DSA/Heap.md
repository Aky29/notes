# About

A **Heap** is a specialized non-linear tree-based data structure that follows a specific ordering property called the **Heap Property**.

A Heap is generally implemented using a Complete Binary Tree.

It is mainly used when we need quick access to the maximum or minimum element.

There are two major types of Heap:

1. Max Heap
    
2. Min Heap
    

Heaps are commonly used in Priority Queues, Heap Sort, scheduling algorithms and graph algorithms.

## Structure of a Heap

A Heap is a Complete Binary Tree in which:

- Every level is completely filled except possibly the last level.
    
- The last level is filled from left to right.
    
- Nodes follow a specific ordering property.
    

Example:

```
             50
           /    \
          30     40
         / \    /
        10 20  35
```

This is a Max Heap because every parent node is greater than or equal to its children.

---

# Types of Heap

## 1. Max Heap

A Max Heap is a Complete Binary Tree in which the value of every parent node is greater than or equal to the values of its children.

The maximum element is always present at the root.

Example:

```
             100
           /     \
          50      80
         / \     / \
        20 30   40 60
```

Properties:

- Root contains the maximum element.
    
- Parent is greater than or equal to its children.
    
- Every subtree also follows the Max Heap property.
    

## 2. Min Heap

A Min Heap is a Complete Binary Tree in which the value of every parent node is smaller than or equal to the values of its children.

The minimum element is always present at the root.

Example:

```
             10
           /    \
          20     15
         / \    / \
        40 30  25 50
```

Properties:

- Root contains the minimum element.
    
- Parent is smaller than or equal to its children.
    
- Every subtree also follows the Min Heap property.
    

## Max Heap vs Min Heap

|Max Heap|Min Heap|
|---|---|
|Root contains maximum value|Root contains minimum value|
|Parent >= Children|Parent <= Children|
|Used for maximum-priority access|Used for minimum-priority access|
|Largest element is removed first|Smallest element is removed first|

NOTE :- A Heap is not a Binary Search Tree. It only maintains the ordering relationship between a parent and its children. It does not maintain a sorted left and right subtree.

---

# Array Representation of Heap

A Heap is generally implemented using an array because it is a Complete Binary Tree.

Since the tree is filled level by level from left to right, we do not need pointers to connect individual nodes.

Consider this Max Heap:

```
             50
           /    \
          30     40
         / \    /
        10 20  35
```

Its array representation is:

```
[50, 30, 40, 10, 20, 35]
```

For a zero-based array, if the current node is at index `i`:

|Operation|Formula|
|---|---|
|Parent|`(i - 1) / 2`|
|Left Child|`2 * i + 1`|
|Right Child|`2 * i + 2`|

Example:

```
Index:  0   1   2   3   4   5
Value: 50  30  40  10  20  35
```

For index 1:

- Parent = `(1 - 1) / 2 = 0`
    
- Left Child = `2 * 1 + 1 = 3`
    
- Right Child = `2 * 1 + 2 = 4`
    

NOTE :- The formulas above are for zero-based indexing. Some implementations use one-based indexing, where the formulas are different.

---

# Heap Operations

A Heap supports several operations to maintain its structure and ordering property.

## 1. Insertion

Insertion adds a new element to the Heap.

Steps:

1. Insert the new element at the end of the array.
    
2. Compare it with its parent.
    
3. If the Heap property is violated, swap it with its parent.
    
4. Continue until the Heap property is restored or the element reaches the root.
    

This process is called **Heapify Up** or **Sift Up**.

Example: Insert 60 into the following Max Heap.

Before insertion:

```
             50
           /    \
          30     40
         / \
        10 20
```

After placing 60 at the end:

```
             50
           /    \
          30     40
         / \    /
        10 20  60
```

Now compare 60 with its parent 40 and swap.

```
             50
           /    \
          30     60
         / \    /
        10 20  40
```

Compare 60 with its parent 50 and swap again.

Final Heap:

```
             60
           /    \
          30     50
         / \    /
        10 20  40
```

Time Complexity: O(log n)

## 2. Deletion

In a Heap, deletion generally means removing the root element.

In a Max Heap, it removes the maximum element.

In a Min Heap, it removes the minimum element.

Steps:

1. Replace the root with the last element.
    
2. Remove the last element.
    
3. Compare the new root with its children.
    
4. Swap it with the appropriate child if the Heap property is violated.
    
5. Continue until the Heap property is restored.
    

This process is called **Heapify Down** or **Sift Down**.

Example:

Before deletion:

```
             50
           /    \
          30     40
         / \    /
        10 20  35
```

Replace root with the last element 35:

```
             35
           /    \
          30     40
         / \
        10 20
```

Compare 35 with its children and swap it with 40.

Final Heap:

```
             40
           /    \
          30     35
         / \
        10 20
```

Time Complexity: O(log n)

## 3. Peek

Peek returns the root element without removing it.

- Max Heap: Returns the maximum element.
    
- Min Heap: Returns the minimum element.
    

Time Complexity: O(1)

## 4. Heapify

Heapify is the process of restoring the Heap property in a binary tree or array.

It is generally performed when:

- An element is inserted.
    
- The root is deleted.
    
- A Heap is constructed from an unsorted array.
    

There are two common directions:

- Heapify Up
    
- Heapify Down
    

### Heapify Up

Moves an element towards the root when it violates the Heap property with its parent.

### Heapify Down

Moves an element towards the leaves when it violates the Heap property with its children.

Time Complexity of one Heapify Down operation: O(log n)

---

# Building a Heap

A Heap can be constructed from an unsorted array.

There are two common approaches.

## 1. Repeated Insertion

Insert each element individually into an initially empty Heap.

Each insertion takes O(log n).

For n elements:

Time Complexity: O(n log n)

## 2. Bottom-Up Heap Construction

Instead of inserting elements one by one, we start from the last non-leaf node and apply Heapify Down.

For a zero-based array, the last non-leaf node is:

```
(n / 2) - 1
```

We move backwards until the root.

C++ Implementation:

```
void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
```

Time Complexity: O(n)

NOTE :- Although one Heapify operation can take O(log n), building a Heap using bottom-up construction takes O(n), not O(n log n).

---

# C++ Implementation of Max Heap

```
#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[parent] >= heap[index])
                break;

            swap(heap[parent], heap[index]);

            index = parent;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();

        while (true) {
            int largest = index;

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < n && heap[left] > heap[largest])
                largest = left;

            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest == index)
                break;

            swap(heap[index], heap[largest]);

            index = largest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);

        heapifyUp(heap.size() - 1);
    }

    int peek() {
        if (heap.empty())
            throw runtime_error("Heap is empty");

        return heap[0];
    }

    void deleteRoot() {
        if (heap.empty())
            throw runtime_error("Heap is empty");

        heap[0] = heap.back();

        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

    void display() {
        for (int value : heap)
            cout << value << " ";

        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);
    h.insert(60);

    h.display();

    cout << "Maximum: " << h.peek() << endl;

    h.deleteRoot();

    h.display();

    cout << "Maximum: " << h.peek() << endl;
}
```

---

# Heap Sort

Heap Sort is a comparison-based sorting algorithm that uses a Binary Heap.

It is used to sort an array in ascending or descending order.

For ascending order, Heap Sort generally uses a Max Heap.

### Working of Heap Sort

1. Build a Max Heap from the given array.
    
2. The largest element is at the root.
    
3. Swap the root with the last element.
    
4. Reduce the effective Heap size by one.
    
5. Apply Heapify Down to restore the Max Heap.
    
6. Repeat until all elements are sorted.
    

Example:

```
Original Array:

[4, 10, 3, 5, 1]

After Building Max Heap:

[10, 5, 3, 4, 1]

After First Extraction:

[5, 4, 3, 1, 10]

Final Sorted Array:

[1, 3, 4, 5, 10]
```

### C++ Implementation

```
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

    heapSort(arr);

    for (int value : arr)
        cout << value << " ";
}
```

Output:

```
1 3 4 5 10
```

### Heap Sort Complexity

|Case|Time Complexity|
|---|---|
|Best Case|O(n log n)|
|Average Case|O(n log n)|
|Worst Case|O(n log n)|

Space Complexity: O(1) auxiliary space for the iterative heap operations.

Properties:

- In-place sorting algorithm.
    
- Not stable.
    
- Does not require additional arrays.
    
- Uses a Heap to organize elements.
    

---

# Priority Queue

A Priority Queue is an Abstract Data Type in which elements are processed according to their priority rather than their insertion order.

A Heap is one of the most common ways to implement a Priority Queue.

There are two common types:

1. Max Priority Queue
    
2. Min Priority Queue
    

### Max Priority Queue

The element with the highest priority is removed first.

A Max Heap can be used to implement it.

### Min Priority Queue

The element with the lowest value or highest minimum-priority is removed first.

A Min Heap can be used to implement it.

### Priority Queue in C++

C++ provides a Priority Queue through the STL.

It is available in:

```
#include <queue>
```

**Max Priority Queue**

```
priority_queue<int> pq;

pq.push(10);
pq.push(50);
pq.push(30);

cout << pq.top();  // 50

pq.pop();
```

**Min Priority Queue**

```
priority_queue<int, vector<int>, greater<int>> pq;

pq.push(10);
pq.push(50);
pq.push(30);

cout << pq.top();  // 10

pq.pop();
```

### Priority Queue Operations

|Operation|Time Complexity|
|---|---|
|push()|O(log n)|
|pop()|O(log n)|
|top()|O(1)|
|size()|O(1)|
|empty()|O(1)|

NOTE :- `pop()` removes the top element but does not return it. Use `top()` before `pop()` if you need its value.

---

# Types of Heap Beyond Binary Heap

Apart from the ordinary Binary Heap, there are other Heap structures designed for particular operations.

## 1. D-ary Heap

A D-ary Heap is a generalization of a Binary Heap in which each node can have at most D children.

In a Binary Heap, D = 2.

In a Ternary Heap, D = 3.

It can be useful when a particular balance between insertion and extraction costs is required.

## 2. Binomial Heap

A Binomial Heap is a collection of Binomial Trees that follow the Heap Property.

It supports efficient merging of two Heaps.

Its operations include:

- Insertion
    
- Finding minimum
    
- Extracting minimum
    
- Decreasing a key
    
- Merging Heaps
    

## 3. Fibonacci Heap

A Fibonacci Heap is a collection of heap-ordered trees.

It is designed to make certain operations especially efficient through lazy restructuring.

Important amortized complexities:

|Operation|Amortized Complexity|
|---|---|
|Find Minimum|O(1)|
|Insertion|O(1)|
|Decrease Key|O(1)|
|Merge|O(1)|
|Extract Minimum|O(log n)|
|Delete|O(log n)|

NOTE :- Fibonacci Heaps are more advanced and are mainly studied in theoretical algorithm analysis and some graph algorithm implementations.

---

# Applications of Heap

1. **Priority Queues** :- Processing elements based on priority.
    
2. **Heap Sort** :- Sorting elements efficiently.
    
3. **Dijkstra's Algorithm** :- Efficiently selecting the next minimum-distance vertex.
    
4. **Prim's Algorithm** :- Selecting the next minimum-weight edge or vertex.
    
5. **Scheduling** :- Managing tasks based on priority.
    
6. **Top K Elements** :- Finding the largest or smallest K elements.
    
7. **K-way Merge** :- Merging multiple sorted arrays or lists.
    
8. **Median Maintenance** :- Using two Heaps to maintain a running median.
    

---

# Time and Space Complexity

|Operation|Binary Heap|
|---|---|
|Access Root|O(1)|
|Search|O(n)|
|Insertion|O(log n)|
|Delete Root|O(log n)|
|Heapify Down|O(log n)|
|Build Heap|O(n)|
|Heap Sort|O(n log n)|
|Space|O(n)|

NOTE :- Searching for an arbitrary value in a Binary Heap takes O(n) because the Heap property does not provide the complete ordering needed for Binary Search.

---

# Important Terms

|Term|Meaning|
|---|---|
|Heap|Tree-based data structure following the Heap Property|
|Heap Property|Ordering relationship between parents and children|
|Max Heap|Parent is greater than or equal to children|
|Min Heap|Parent is smaller than or equal to children|
|Complete Binary Tree|All levels filled except possibly the last, which is filled left to right|
|Heapify|Restoring the Heap Property|
|Heapify Up|Moving an element towards the root|
|Heapify Down|Moving an element towards the leaves|
|Sift Up|Another name for Heapify Up|
|Sift Down|Another name for Heapify Down|
|Priority Queue|ADT that processes elements according to priority|
|Heap Sort|Sorting algorithm based on a Heap|
|D-ary Heap|Heap where each node can have up to D children|
|Binomial Heap|Collection of Binomial Trees|
|Fibonacci Heap|Heap structure with efficient amortized operations|

---

# Important Notes

1. A Binary Heap is a Complete Binary Tree.
    
2. A Heap is not necessarily a Binary Search Tree.
    
3. Max Heap provides O(1) access to the maximum element.
    
4. Min Heap provides O(1) access to the minimum element.
    
5. Insertion and deletion take O(log n).
    
6. Building a Heap using bottom-up construction takes O(n).
    
7. Searching for an arbitrary element takes O(n).
    
8. Heap Sort takes O(n log n) time.
    
9. Heap Sort is not stable.
    
10. A Binary Heap is generally represented using an array.
    
11. A Priority Queue is an ADT, while a Heap is a data structure commonly used to implement it.
    
12. C++ `priority_queue` is a Max Priority Queue by default.
    

---

# Next Topics

After completing Heap, continue with:

1. Graphs
    
2. Graph Representation
    
3. Graph Traversal (BFS and DFS)
    
4. Shortest Path Algorithms
    
5. Minimum Spanning Tree
    
6. Topological Sorting
    
7. Disjoint Set Union (DSU)