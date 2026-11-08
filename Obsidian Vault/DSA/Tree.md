# About

A **Tree** is a non-linear data structure in which data is stored in the form of nodes connected through edges.

Unlike arrays, linked lists, stacks and queues, where data is generally organized sequentially, a tree represents hierarchical relationships between data.

You can think of a tree as a family hierarchy, where one node represents a parent and other nodes represent its children.

A tree starts with a single node called the **Root Node**, and all other nodes are connected below it.

Trees are commonly used in file systems, databases, searching algorithms, compilers and hierarchical data representation.

## Basic Structure of a Tree

A tree consists of two main components:

1. **Node** :- A node stores the actual data.
    
2. **Edge** :- An edge represents the connection between two nodes.
    

Example:

```
             10                 <- Root
           /    \
          20     30              <- Children
         / \       \
        40  50      60
```

In this example:

- 10 is the root node.
    
- 20 and 30 are children of 10.
    
- 10 is the parent of 20 and 30.
    
- 40, 50 and 60 are leaf nodes.
    

## Terminologies Used in Trees

### 1. Root Node

The topmost node of a tree is called the root node.

A tree has exactly one root node.

### 2. Parent Node

A node that has one or more children is called a parent node.

### 3. Child Node

A node directly connected below another node is called its child.

### 4. Sibling Nodes

Nodes that share the same parent are called siblings.

### 5. Leaf Node

A node that does not have any children is called a leaf node or external node.

### 6. Internal Node

A node that has at least one child is called an internal node.

### 7. Edge

An edge represents the connection between two nodes.

A tree containing `n` nodes always has `n - 1` edges.

### 8. Degree of a Node

The number of children a node has is called its degree.

### 9. Degree of a Tree

The maximum degree of any node in the tree is called the degree of the tree.

### 10. Path

A sequence of nodes connected through edges is called a path.

### 11. Ancestor

Any node that appears above another node in its path towards the root is called its ancestor.

### 12. Descendant

Any node that appears below another node is called its descendant.

### 13. Depth of a Node

The number of edges from the root node to a particular node is called its depth.

The root node has depth 0.

### 14. Height of a Node

The number of edges in the longest downward path from a node to a leaf is called its height.

A leaf node has height 0.

### 15. Height of a Tree

The height of the root node is called the height of the tree.

### 16. Subtree

A tree formed by a node and all its descendants is called a subtree.

## Properties of Trees

1. A tree with `n` nodes contains exactly `n - 1` edges.
    
2. Every tree has exactly one root node.
    
3. Every node except the root has exactly one parent.
    
4. There is exactly one path between any two nodes in a tree.
    
5. A tree does not contain cycles.
    
6. Removing any edge disconnects the tree.
    
7. Adding an edge between two existing nodes creates a cycle.
    

NOTE :- Height and depth are measured in edges in these notes. Some books measure height using the number of nodes, so always check the convention.

---

# Types of Trees

Trees can be classified according to their structure and the number of children allowed per node.

## 1. General Tree

A general tree is a tree in which a node can have any number of children.

There is no fixed limit on the number of children.

Example:

```
             A
          /  |  \
         B   C   D
        / \      |
       E   F     G
```

Applications:

- File systems
    
- Organization hierarchies
    
- XML and HTML document structures
    

## 2. Binary Tree

A binary tree is a tree in which every node can have at most two children.

These children are called:

1. Left Child
    
2. Right Child
    

Example:

```
             10
           /    \
          20     30
         / \       \
        40  50      60
```

A binary tree can have:

- Zero children
    
- One child
    
- Two children
    

### Representation of a Binary Tree

A binary tree can be represented using two common methods.

**1. Linked Representation**

Each node stores:

- Data
    
- Pointer to the left child
    
- Pointer to the right child
    

```
struct Node {
    int data;
    Node* left;
    Node* right;
};
```

**2. Array Representation**

Nodes are stored in an array.

For a zero-based array:

- Left Child = `2 * i + 1`
    
- Right Child = `2 * i + 2`
    
- Parent = `(i - 1) / 2`
    

This representation is particularly useful for complete binary trees.

---

# Types of Binary Trees

## 1. Full Binary Tree

A full binary tree is a binary tree in which every node has either zero or exactly two children.

A node cannot have only one child.

Example:

```
             10
           /    \
          20     30
         /  \
        40   50
```

## 2. Complete Binary Tree

A complete binary tree is a binary tree in which:

- Every level is completely filled except possibly the last level.
    
- The last level is filled from left to right.
    

Example:

```
             10
           /    \
          20     30
         / \    /
        40 50  60
```

## 3. Perfect Binary Tree

A perfect binary tree is a binary tree in which:

- Every internal node has exactly two children.
    
- All leaf nodes are at the same level.
    

Example:

```
             10
           /    \
          20     30
         / \    / \
        40 50  60 70
```

For a perfect binary tree:

- Maximum nodes at level `l` = `2^l`
    
- Total nodes for height `h` = `2^(h+1) - 1`
    
- Number of leaf nodes = `2^h`
    

## 4. Balanced Binary Tree

A balanced binary tree is a binary tree in which the heights of the left and right subtrees are kept within a specified limit.

The exact balancing condition depends on the type of balanced tree.

For example, an AVL tree requires the height difference between the left and right subtrees of every node to be at most 1.

## 5. Degenerate Binary Tree

A degenerate binary tree is a tree in which every parent node has only one child.

It behaves similarly to a linked list.

Example:

```
        10
          \
           20
             \
              30
                \
                 40
```

## 6. Skewed Binary Tree

A skewed binary tree is a special type of degenerate tree in which all nodes are connected in one direction.

There are two types:

**Left Skewed Tree**

```
          40
         /
        30
       /
      20
     /
    10
```

**Right Skewed Tree**

```
    10
      \
       20
         \
          30
            \
             40
```

---

# Tree Traversal

Tree traversal is the process of visiting every node of a tree in a particular order.

There are two major categories:

1. Depth First Search (DFS)
    
2. Breadth First Search (BFS)
    

## 1. Depth First Search (DFS)

In DFS, we explore a branch as deeply as possible before moving to another branch.

There are three common types of DFS traversal.

### A. Preorder Traversal

The order is:

1. Visit Root
    
2. Traverse Left Subtree
    
3. Traverse Right Subtree
    

Order: **Root → Left → Right**

```
             10
           /    \
          20     30
         /  \
        40   50
```

Output:

```
10 20 40 50 30
```

C++ Implementation:

```
void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}
```

### B. Inorder Traversal

The order is:

1. Traverse Left Subtree
    
2. Visit Root
    
3. Traverse Right Subtree
    

Order: **Left → Root → Right**

Output:

```
40 20 50 10 30
```

C++ Implementation:

```
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}
```

NOTE :- Inorder traversal of a Binary Search Tree produces values in sorted order, assuming the BST follows the usual ordering rules.

### C. Postorder Traversal

The order is:

1. Traverse Left Subtree
    
2. Traverse Right Subtree
    
3. Visit Root
    

Order: **Left → Right → Root**

Output:

```
40 50 20 30 10
```

C++ Implementation:

```
void postorder(Node* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}
```

## 2. Breadth First Search (BFS)

BFS visits nodes level by level.

It is also called **Level Order Traversal**.

It uses a Queue to keep track of the nodes that need to be visited.

Example:

```
             10
           /    \
          20     30
         /  \
        40   50
```

Output:

```
10 20 30 40 50
```

C++ Implementation:

```
void levelOrder(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
}
```

## Complexity of Tree Traversals

Let `n` be the number of nodes and `h` be the height of the tree.

|Traversal|Time Complexity|Auxiliary Space|
|---|---|---|
|Preorder|O(n)|O(h)|
|Inorder|O(n)|O(h)|
|Postorder|O(n)|O(h)|
|Level Order|O(n)|O(w)|

Here:

- `h` = height of the tree.
    
- `w` = maximum width of the tree.
    

NOTE :- Recursive DFS uses the call stack. Level order traversal uses a queue.

---

# Binary Search Tree (BST)

A Binary Search Tree is a special type of binary tree that follows a particular ordering property.

For every node:

- All values in the left subtree are smaller than the node.
    
- All values in the right subtree are greater than the node.
    
- Both left and right subtrees must also follow the BST property.
    

Example:

```
             50
           /    \
          30     70
         / \    / \
        20 40  60 80
```

### BST Operations

## 1. Searching

To search for an element:

1. Start from the root.
    
2. If the value is equal to the current node, the element is found.
    
3. If the value is smaller, move to the left subtree.
    
4. If the value is greater, move to the right subtree.
    
5. Continue until the value is found or the current node becomes NULL.
    

C++ Implementation:

```
bool search(Node* root, int key) {
    if (root == nullptr)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}
```

## 2. Insertion

To insert a new element:

1. Start from the root.
    
2. Compare the new value with the current node.
    
3. Move left if it is smaller.
    
4. Move right if it is greater.
    
5. Insert the new node at the first empty position.
    

C++ Implementation:

```
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}
```

This implementation ignores duplicate values.

## 3. Deletion

There are three cases when deleting a node.

**Case 1: Node is a Leaf Node**

Simply remove the node.

**Case 2: Node has One Child**

Replace the node with its only child.

**Case 3: Node has Two Children**

Replace the node with either:

- Its inorder successor (smallest value in the right subtree).
    
- Its inorder predecessor (largest value in the left subtree).
    

Then delete the replacement node from its original position.

### BST Complexity

Let `h` be the height of the tree.

|Operation|Average Case|Worst Case|
|---|---|---|
|Search|O(log n)|O(n)|
|Insertion|O(log n)|O(n)|
|Deletion|O(log n)|O(n)|
|Traversal|O(n)|O(n)|

NOTE :- A BST can become skewed if values are inserted in an already sorted order. In that case, its height becomes O(n), making its operations similar to a linked list.

---

# Self-Balancing Binary Search Trees

A self-balancing BST automatically maintains its height to prevent it from becoming highly skewed.

This helps maintain efficient searching, insertion and deletion.

## 1. AVL Tree

An AVL Tree is a self-balancing Binary Search Tree.

It was introduced by Adelson-Velsky and Landis.

In an AVL tree, the height difference between the left and right subtrees of every node must be at most 1.

### Balance Factor

Balance Factor is used to check whether a node is balanced.

Formula:

```
Balance Factor = Height(Left Subtree) - Height(Right Subtree)
```

Allowed values:

```
-1, 0, +1
```

If the balance factor becomes less than -1 or greater than +1, the tree needs rebalancing.

### Rotations in AVL Tree

Rotations are operations used to restore balance in an AVL tree.

There are four major cases:

**1. LL Rotation (Left-Left)**

Occurs when insertion happens in the left subtree of the left child.

Solution: Right Rotation.

**2. RR Rotation (Right-Right)**

Occurs when insertion happens in the right subtree of the right child.

Solution: Left Rotation.

**3. LR Rotation (Left-Right)**

Occurs when insertion happens in the right subtree of the left child.

Solution:

- Left Rotation on the left child.
    
- Right Rotation on the unbalanced node.
    

**4. RL Rotation (Right-Left)**

Occurs when insertion happens in the left subtree of the right child.

Solution:

- Right Rotation on the right child.
    
- Left Rotation on the unbalanced node.
    

### AVL Complexity

|Operation|Time Complexity|
|---|---|
|Searching|O(log n)|
|Insertion|O(log n)|
|Deletion|O(log n)|
|Traversal|O(n)|

## 2. Red-Black Tree

A Red-Black Tree is another type of self-balancing Binary Search Tree.

Every node is assigned one of two colours:

- Red
    
- Black
    

It follows a set of rules to maintain approximate balance.

### Properties of Red-Black Tree

1. Every node is either red or black.
    
2. The root node is always black.
    
3. Every NULL leaf (NIL sentinel) is black.
    
4. A red node cannot have a red parent or red child.
    
5. Every path from a node to its descendant NIL leaves contains the same number of black nodes.
    

These rules ensure that the height of the tree remains O(log n).

### Operations

Red-Black Trees maintain balance using:

- Rotations
    
- Recolouring
    
- Insertion fix-up
    
- Deletion fix-up
    

### Complexity

|Operation|Time Complexity|
|---|---|
|Searching|O(log n)|
|Insertion|O(log n)|
|Deletion|O(log n)|
|Traversal|O(n)|

NOTE :- AVL trees are more strictly balanced, while Red-Black trees generally require fewer rotations during updates. Both provide logarithmic search, insertion and deletion.

---

# Multiway Search Trees

Unlike binary trees, where a node can have at most two children, a multiway search tree can have more than two children.

They are useful when data is stored on secondary storage such as disks because they reduce the number of levels that need to be accessed.

## 1. B-Tree

A B-Tree is a self-balancing multiway search tree.

A node can contain multiple keys and have multiple children.

It maintains sorted keys and keeps all leaf nodes at the same depth.

### Properties of a B-Tree

For a B-Tree of minimum degree `t`:

1. Every node can have at most `2t - 1` keys.
    
2. Every node can have at most `2t` children.
    
3. Every non-root internal node must have at least `t - 1` keys.
    
4. Every internal node with `k` keys has `k + 1` children.
    
5. The root has at least one key if the tree is non-empty.
    
6. All leaves appear at the same level.
    

### Operations

- Searching
    
- Insertion
    
- Deletion
    
- Splitting
    
- Merging
    
- Borrowing keys from sibling nodes
    

When a node becomes full during insertion, it is split to maintain the B-Tree properties.

### Complexity

|Operation|Time Complexity|
|---|---|
|Searching|O(log n)|
|Insertion|O(log n)|
|Deletion|O(log n)|

## 2. B+ Tree

A B+ Tree is a variation of the B-Tree.

The main difference is how data and keys are stored.

In a B+ Tree:

- Internal nodes store keys used for navigation.
    
- Actual records or record pointers are stored in leaf nodes.
    
- Leaf nodes are usually connected through linked pointers.
    
- All leaf nodes are at the same level.
    

### Advantages

1. Efficient range queries.
    
2. Sequential access is easier because leaf nodes are linked.
    
3. Internal nodes can store more keys when they contain only navigation keys.
    
4. It is suitable for database indexing and disk-based storage.
    

### B-Tree vs B+ Tree

|B-Tree|B+ Tree|
|---|---|
|Records can be stored in internal and leaf nodes|Records are stored in leaf nodes|
|Leaf nodes may not be linked|Leaf nodes are linked in common implementations|
|Search may finish at an internal node|Search for records reaches a leaf|
|Range queries are less efficient|Range queries are more efficient|

---

# Segment Tree

A Segment Tree is a tree-based data structure used to answer range queries efficiently.

It is especially useful when we need to perform queries over a range of an array and also update individual elements.

For example, consider an array:

```
arr = [2, 4, 6, 8, 10]
```

We may need to perform operations such as:

- Find the sum from index 1 to 3.
    
- Find the minimum value between index 0 and 4.
    
- Update the value at a particular index.
    

A Segment Tree divides the array into smaller segments and stores information about each segment in its nodes.

### Structure

Each node represents a segment of the original array.

- Root represents the entire array.
    
- Left child represents the left half.
    
- Right child represents the right half.
    
- Leaf nodes represent individual array elements.
    

### Example

For:

```
arr = [2, 4, 6, 8]
```

A segment tree storing range sums can look like:

```
                 20
              /      \
             6        14
           /  \      /  \
          2    4    6    8
```

The root stores the sum of the entire array.

### Operations

**1. Build**

Constructs the segment tree from the original array.

Time Complexity: O(n)

**2. Query**

Finds the answer for a given range.

For example, sum of elements from index 1 to 3.

Time Complexity: O(log n)

**3. Update**

Updates an element in the original array and modifies the affected nodes in the segment tree.

Time Complexity: O(log n)

### C++ Implementation (Range Sum)

```
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int start, int end,
              int left, int right) {
        if (right < start || end < left)
            return 0;

        if (left <= start && end <= right)
            return tree[node];

        int mid = (start + end) / 2;

        int a = query(2 * node, start, mid, left, right);
        int b = query(2 * node + 1, mid + 1, end, left, right);

        return a + b;
    }

    void update(int node, int start, int end,
                int index, int value) {
        if (start == end) {
            tree[node] = value;
            return;
        }

        int mid = (start + end) / 2;

        if (index <= mid)
            update(2 * node, start, mid, index, value);
        else
            update(2 * node + 1, mid + 1, end, index, value);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);

        if (n > 0)
            build(arr, 1, 0, n - 1);
    }

    int query(int left, int right) {
        if (n == 0 || left < 0 || right >= n || left > right)
            return 0;

        return query(1, 0, n - 1, left, right);
    }

    void update(int index, int value) {
        if (index < 0 || index >= n)
            return;

        update(1, 0, n - 1, index, value);
    }
};

int main() {
    vector<int> arr = {2, 4, 6, 8};

    SegmentTree st(arr);

    cout << st.query(1, 3) << endl;

    st.update(1, 10);

    cout << st.query(1, 3) << endl;
}
```

Output:

```
18
24
```

### Segment Tree Complexity

|Operation|Time Complexity|
|---|---|
|Building|O(n)|
|Range Query|O(log n)|
|Point Update|O(log n)|
|Space|O(n)|

NOTE :- This implementation uses a range-sum query. Segment Trees can also support minimum, maximum, GCD and other suitable range operations.

---

# Fenwick Tree (Binary Indexed Tree)

A Fenwick Tree is also called a Binary Indexed Tree (BIT).

It is a data structure used to efficiently calculate prefix sums and perform point updates.

It uses an array-based representation rather than explicitly storing nodes and edges.

It is generally simpler and uses less memory than a Segment Tree, but it supports a more limited set of operations in its basic form.

### Why Fenwick Tree?

Consider an array:

```
arr = [2, 4, 6, 8, 10]
```

Suppose we want to:

1. Calculate the sum of elements from index 0 to index 3.
    
2. Update the value at a particular index.
    
3. Calculate another prefix sum after the update.
    

Without a Fenwick Tree, calculating a prefix sum takes O(n) time.

A Fenwick Tree reduces both prefix-sum queries and point updates to O(log n).

### Important Concept: Lowest Set Bit

Fenwick Tree uses binary representation to manage ranges.

The expression:

```
i & -i
```

returns the lowest set bit of `i`.

It is used to determine how many elements a particular Fenwick Tree position represents.

Example:

```
i = 12

Binary = 1100

Lowest set bit = 0100

i & -i = 4
```

### Operations

**1. Update**

Updates an element and modifies all the relevant positions in the Fenwick Tree.

Time Complexity: O(log n)

**2. Prefix Sum**

Calculates the sum from index 1 to a given position in the Fenwick Tree's one-based indexing.

Time Complexity: O(log n)

**3. Range Sum**

The sum between indexes `l` and `r` can be calculated using:

```
Range Sum(l, r) = Prefix Sum(r) - Prefix Sum(l - 1)
```

Time Complexity: O(log n)

### C++ Implementation

```
#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int index, int value) {
        index++;

        while (index <= n) {
            bit[index] += value;
            index += index & -index;
        }
    }

    int prefixSum(int index) {
        index++;

        int sum = 0;

        while (index > 0) {
            sum += bit[index];
            index -= index & -index;
        }

        return sum;
    }

    int rangeSum(int left, int right) {
        if (left > right || left < 0 || right >= n)
            return 0;

        return prefixSum(right) - prefixSum(left - 1);
    }
};

int main() {
    vector<int> arr = {2, 4, 6, 8, 10};

    FenwickTree ft(arr.size());

    for (int i = 0; i < arr.size(); i++)
        ft.update(i, arr[i]);

    cout << ft.rangeSum(1, 3) << endl;

    ft.update(2, 4);

    cout << ft.rangeSum(1, 3) << endl;
}
```

Output:

```
18
22
```

NOTE :- The `update()` function above performs an addition, not direct assignment. To change an existing value, calculate the difference between the new and old values and add that difference.

### Fenwick Tree Complexity

|Operation|Time Complexity|
|---|---|
|Building using repeated updates|O(n log n)|
|Prefix Sum|O(log n)|
|Range Sum|O(log n)|
|Point Update|O(log n)|
|Space|O(n)|

---

# Segment Tree vs Fenwick Tree

Both are used to solve range-query problems, but they have different capabilities.

|Feature|Segment Tree|Fenwick Tree|
|---|---|---|
|Representation|Tree stored in an array|Binary Indexed Array|
|Space|O(n)|O(n)|
|Build|O(n)|O(n log n) using repeated updates|
|Point Update|O(log n)|O(log n)|
|Range Sum|O(log n)|O(log n)|
|Range Minimum|Supported|Not generally supported with basic BIT|
|Flexibility|More flexible|More limited|
|Implementation|More complex|Simpler|

NOTE :- Use a Fenwick Tree for straightforward prefix and range-sum problems with point updates. Use a Segment Tree when you need more flexible range queries or updates.

---

# Applications of Trees

Trees are used in many areas of computer science.

1. **File Systems** :- Directories and files are organized hierarchically.
    
2. **Databases** :- B-Trees and B+ Trees are used for indexing.
    
3. **Searching** :- BSTs support efficient searching.
    
4. **Compilers** :- Syntax trees represent program structure.
    
5. **HTML and XML** :- Document elements are organized hierarchically.
    
6. **Networking** :- Spanning trees are used in network topology.
    
7. **Range Queries** :- Segment Trees and Fenwick Trees are used for efficient range calculations.
    
8. **Artificial Intelligence** :- Decision trees are used in machine learning.
    
9. **Data Compression** :- Huffman trees are used in Huffman coding.
    

---

# Important Terms

|Term|Meaning|
|---|---|
|Root|Topmost node of a tree|
|Parent|Node that has children|
|Child|Node connected below another node|
|Sibling|Nodes sharing the same parent|
|Leaf|Node without children|
|Internal Node|Node having at least one child|
|Edge|Connection between two nodes|
|Height|Longest downward path to a leaf|
|Depth|Distance from root to a node|
|Subtree|A node and all its descendants|
|Traversal|Visiting every node|
|DFS|Depth First Search|
|BFS|Breadth First Search|
|BST|Binary Search Tree|
|Balance Factor|Difference between left and right subtree heights|
|Rotation|Operation used to rebalance a tree|
|Inorder Successor|Next node in inorder traversal|
|Inorder Predecessor|Previous node in inorder traversal|
|Segment Tree|Data structure for range queries and updates|
|Fenwick Tree|Data structure for efficient prefix sums and updates|

---

# Important Notes

1. A tree is a non-linear data structure.
    
2. A tree with `n` nodes has exactly `n - 1` edges.
    
3. A binary tree allows at most two children per node.
    
4. Full, Complete and Perfect Binary Trees are different structures.
    
5. Inorder traversal of a BST gives sorted values.
    
6. An ordinary BST can become skewed.
    
7. AVL and Red-Black Trees maintain balance automatically.
    
8. B-Trees and B+ Trees are useful for database indexing.
    
9. Segment Trees support flexible range queries and updates.
    
10. Fenwick Trees are especially useful for prefix sums and point updates.
    
11. DFS uses recursion or an explicit stack, while BFS uses a queue.
    
12. Tree traversal visits every node exactly once, so its time complexity is O(n).
    

---

# Next Topics

After completing Trees, continue with:

1. Graphs
    
2. Graph Representation
    
3. Graph Traversal (BFS and DFS)
    
4. Shortest Path Algorithms
    
5. Minimum Spanning Tree
    
6. Topological Sorting
    
7. Disjoint Set Union (DSU)
    

NOTE :- Before moving to Graphs, practice implementing a Binary Tree, BST, AVL Tree, Segment Tree and Fenwick Tree. You do not need to master every advanced balancing operation immediately.