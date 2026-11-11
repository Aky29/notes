# About

**Disjoint Set Union (DSU)** is a data structure used to manage a collection of non-overlapping sets.
It is also called **Union-Find** because it mainly supports two operations:

1. Find
2. Union

- Find determines which set an element belongs to.
- Union combines two different sets into one set.

DSU is particularly useful when we need to maintain and check connectivity between elements efficiently.
For example, consider 5 elements:
```
1  2  3  4  5
```
Initially, every element belongs to its own set.
```
{1}  {2}  {3}  {4}  {5}
```
After performing:
```
Union(1, 2)
Union(3, 4)
Union(1, 3)
```

The sets become:

```
{1, 2, 3, 4}  {5}
```

Now, `Find(1)` and `Find(4)` return the same representative because both elements belong to the same set.

DSU is commonly used in:

- Network connectivity
- Cycle detection
- Kruskal's Algorithm
- Connected components
- Grouping related elements
- Dynamic connectivity problems
---
# Terminologies Used in DSU

## 1. Set

A set is a collection of distinct elements.
In DSU, each element belongs to exactly one set.
Example:

```
{1, 2, 3}
{4, 5}
{6}
```

## 2. Disjoint Sets

Two sets are disjoint if they do not contain any common elements.
Example:

```
A = {1, 2, 3}
B = {4, 5, 6}
```

Here, A and B are disjoint sets.

## 3. Representative

A representative is the element used to identify a particular set.
In a tree-based DSU, the representative is generally the root of that set's tree.
All elements belonging to the same set have the same representative.

## 4. Parent

Every element stores a reference to its parent.
The parent array is used to represent the structure of the sets.

## 5. Root

The root is the topmost element of a DSU tree.
A root is identified when:

```
parent[x] == x
```

The root acts as the representative of its set.

## 6. Component

A component is a group of elements that belong to the same set.
Initially, every element is its own component.

## 7. Path Compression

An optimization technique that makes nodes point directly to the root during the Find operation.

## 8. Union by Rank

An optimization technique that combines two trees based on their approximate heights.

## 9. Union by Size

An optimization technique that combines two trees based on their number of elements.

---

# Structure of DSU

DSU commonly represents each set as a rooted tree.
Each node points towards its parent, and the root represents the entire set.
Example:

```
       1
      / \
     2   3
        /
       4
```

Here:

```
parent[1] = 1
parent[2] = 1
parent[3] = 1
parent[4] = 3
```

The representative of every element is `1`.

```
Find(1) = 1
Find(2) = 1
Find(3) = 1
Find(4) = 1
```

NOTE :- A DSU tree is not necessarily a binary tree. A node can have any number of children.

---

# Initialisation

Initially, every element belongs to its own individual set.
For `n` elements, we create a parent array.

```
vector<int> parent(n);
```

Every element is initially its own parent.

```
for (int i = 0; i < n; i++) {
    parent[i] = i;
}
```

Example:

```
Elements:

0  1  2  3  4

Parent Array:

0  1  2  3  4
```

Each element represents a separate set.

---

# DSU Operations

DSU mainly supports two fundamental operations.

## 1. Find

Find determines the representative of the set to which an element belongs.
It starts from the given element and follows its parent references until it reaches the root.
The root is the representative.

Example:

```
       1
      / \
     2   3
        /
       4
```

For:

```
Find(4)
```

The traversal is:

```
4 -> 3 -> 1
```

Therefore:

```
Find(4) = 1
```

### C++ Implementation

```
int find(int x) {
    if (parent[x] == x)
        return x;

    return find(parent[x]);
}
```

Time Complexity: O(h)
Where h is the height of the DSU tree.

NOTE :- Without optimisations, a DSU tree can become a chain, making Find take O(n) time.

## 2. Union

Union combines the sets containing two given elements.
It first finds the representatives of both elements.
If their representatives are different, their sets are combined.

Example:

Initially:

```
{1}  {2}  {3}  {4}
```

Perform:

```
Union(1, 2)
Union(3, 4)
```

Result:

```
{1, 2}  {3, 4}
```

Now perform:

```
Union(1, 3)
```

Result:

```
{1, 2, 3, 4}
```

### Basic C++ Implementation

```
void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {
        parent[rootB] = rootA;
    }
}
```

Time Complexity: O(h) because it performs Find operations.

NOTE :- Union only needs to connect the representatives. Connecting arbitrary elements directly can produce an incorrect DSU structure.

---

# Optimisations in DSU

Without optimisations, the tree can become very deep.

This makes Find and Union inefficient.

Two major optimisations are used:

1. Path Compression
    
2. Union by Rank or Size
    

These techniques keep the tree shallow and improve performance.

---

# 1. Path Compression

Path Compression is an optimisation used in the Find operation.

It makes every visited node point directly to the root of its set.

Consider:

```
       1
       |
       2
       |
       3
       |
       4
       |
       5
```

To find the representative of 5:

```
5 -> 4 -> 3 -> 2 -> 1
```

After applying Path Compression:

```
       1
    / /|\ \
   2 3 4 5
```

Now every element directly points to the root.

### C++ Implementation

```
int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}
```

The important statement is:

```
parent[x] = find(parent[x]);
```

It updates the parent of the current node to the root returned by the recursive call.

### Complexity

Path Compression makes future Find operations much faster.

When used with Union by Rank or Union by Size, the amortized complexity becomes nearly constant.

---

# 2. Union by Rank

Union by Rank is an optimisation that combines two sets based on their ranks.

Rank is an upper-bound-like measure of tree height maintained by the algorithm.

The idea is to attach the tree with the smaller rank under the tree with the larger rank.

### Working

Suppose we have two sets:

```
Set A:

    1
   / \
  2   3

Rank = 1
```

```
Set B:

    4

Rank = 0
```

Since Set A has a larger rank, Set B is attached below Set A.

```
       1
      /|\
     2 3 4
```

If both trees have equal rank, either root can become the parent.

In that case, the rank of the new root is increased by 1.

### C++ Implementation

```
void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (rank[a] < rank[b]) {
        parent[a] = b;
    }
    else if (rank[a] > rank[b]) {
        parent[b] = a;
    }
    else {
        parent[b] = a;
        rank[a]++;
    }
}
```

Initialisation:

```
vector<int> rank(n, 0);
```

### Complexity

With Path Compression:

- Find: O(α(n)) amortized.
    
- Union: O(α(n)) amortized.
    

Where α(n) is the inverse Ackermann function.

NOTE :- Rank is not necessarily the current height of a tree after Path Compression. It is maintained as a balancing value.

---

# 3. Union by Size

Union by Size is another optimisation.

Instead of comparing ranks, it compares the number of elements in each set.

The smaller set is attached below the larger set.

### Working

Suppose:

```
Set A:

{1, 2, 3, 4}

Size = 4
```

```
Set B:

{5, 6}

Size = 2
```

After Union:

```
{1, 2, 3, 4, 5, 6}

Size = 6
```

The root of the smaller set becomes a child of the root of the larger set.

### C++ Implementation

```
void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (size[a] < size[b]) {
        swap(a, b);
    }

    parent[b] = a;
    size[a] += size[b];
}
```

Initialisation:

```
vector<int> size(n, 1);
```

### Complexity

With Path Compression:

- Find: O(α(n)) amortized.
    
- Union: O(α(n)) amortized.
    

---

# Union by Rank vs Union by Size

|Union by Rank|Union by Size|
|---|---|
|Uses rank values|Uses set sizes|
|Compares approximate tree heights|Compares number of elements|
|Increases rank when both ranks are equal|Adds sizes after merging|
|Keeps trees shallow|Keeps trees shallow|
|O(α(n)) amortized with Path Compression|O(α(n)) amortized with Path Compression|

NOTE :- Both are efficient. You generally only need one of them along with Path Compression.

---

# Complete DSU Implementation

This implementation uses:

- Parent Array
    
- Size Array
    
- Path Compression
    
- Union by Size
    
- Connected Check
    

```
#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> size;

public:

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (size[a] < size[b]) {
            swap(a, b);
        }

        parent[b] = a;
        size[a] += size[b];
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

int main() {

    DSU dsu(5);

    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);

    cout << dsu.connected(0, 2) << endl;
    cout << dsu.connected(0, 4) << endl;

    cout << dsu.getSize(0) << endl;
}
```

Output:

```
1
0
3
```

Explanation:

```
Set 1 = {0, 1, 2}
Set 2 = {3, 4}
```

Therefore:

- 0 and 2 belong to the same set.
    
- 0 and 4 belong to different sets.
    
- The size of the set containing 0 is 3.
    

---

# Cycle Detection Using DSU

DSU can be used to detect cycles in an undirected graph.

The idea is to check whether the endpoints of an edge already belong to the same set.

If they do, adding that edge creates a cycle.

### Working

For every edge `(u, v)`:

1. Find the representative of u.
    
2. Find the representative of v.
    
3. If both representatives are equal, a cycle exists.
    
4. Otherwise, combine their sets.
    

Example:

```
Edges:

0 --- 1
1 --- 2
2 --- 0
```

Process:

```
Union(0, 1)
Union(1, 2)
```

Now 0, 1 and 2 belong to the same set.

When processing:

```
(2, 0)
```

Both vertices already belong to the same set.

Therefore, this edge creates a cycle.

### C++ Implementation

```
bool hasCycle(int V, vector<pair<int, int>>& edges) {

    DSU dsu(V);

    for (auto edge : edges) {

        int u = edge.first;
        int v = edge.second;

        if (dsu.connected(u, v)) {
            return true;
        }

        dsu.unite(u, v);
    }

    return false;
}
```

Time Complexity: O(E × α(V)) amortized.

NOTE :- This approach detects cycles in undirected graphs. Directed graph cycle detection requires different techniques.

---

# DSU in Kruskal's Algorithm

Kruskal's Algorithm is a Minimum Spanning Tree algorithm.

It selects edges in increasing order of their weights while avoiding cycles.

DSU is used to check whether adding an edge would create a cycle.

### Working

1. Sort all edges by increasing weight.
    
2. Create a DSU with every vertex in its own set.
    
3. Select the edge with the smallest weight.
    
4. Check whether its endpoints belong to different sets.
    
5. If they belong to different sets, include the edge in the MST.
    
6. Perform Union on the two endpoints.
    
7. Repeat until V - 1 edges have been selected or all edges are processed.
    

### Example

```
       10
   0 ------- 1
    \       /
   6 \     / 5
      \   /
        2
```

Edges sorted by weight:

```
(1, 2) = 5
(0, 2) = 6
(0, 1) = 10
```

Select:

```
(1, 2) = 5
(0, 2) = 6
```

The final edge is rejected because it would create a cycle.

Minimum Spanning Tree weight:

```
5 + 6 = 11
```

---

# Complexity Analysis

Let:

- `n` = Number of elements.
    
- `m` = Number of operations.
    
- `α(n)` = Inverse Ackermann function.
    

|Operation|Without Optimisation|With Path Compression + Union by Size/Rank|
|---|---|---|
|Initialisation|O(n)|O(n)|
|Find|O(n) worst case|O(α(n)) amortized|
|Union|O(n) worst case|O(α(n)) amortized|
|Connected Check|O(n) worst case|O(α(n)) amortized|
|Space|O(n)|O(n)|

NOTE :- The O(α(n)) complexity is an amortized bound over a sequence of operations, not a strict worst-case bound for every individual operation.

The inverse Ackermann function grows so slowly that it is effectively constant for practical input sizes.

---

# Applications of DSU

1. **Network Connectivity** :- Determines whether two computers belong to the same connected network.
    
2. **Cycle Detection** :- Detects cycles in undirected graphs.
    
3. **Kruskal's Algorithm** :- Helps construct a Minimum Spanning Tree.
    
4. **Connected Components** :- Groups vertices belonging to the same component.
    
5. **Social Networks** :- Groups users based on relationships.
    
6. **Image Processing** :- Groups connected pixels into regions.
    
7. **Dynamic Connectivity** :- Maintains connectivity while edges are added.
    
8. **Grouping Problems** :- Combines elements based on common properties.
    

---

# Important Terms

|Term|Meaning|
|---|---|
|DSU|Disjoint Set Union|
|Union-Find|Another name for DSU|
|Disjoint Set|A set with no common elements with another set|
|Find|Finds the representative of a set|
|Union|Combines two sets|
|Parent|Reference to another node in the DSU tree|
|Root|Topmost node representing a set|
|Representative|Element identifying a set|
|Path Compression|Makes nodes point directly to the root|
|Union by Rank|Combines sets based on rank|
|Union by Size|Combines sets based on their number of elements|
|Component|Group of elements belonging to the same set|
|α(n)|Inverse Ackermann function|

---

# Important Notes

1. DSU is also called Union-Find.
    
2. It manages a collection of disjoint sets.
    
3. Every element initially belongs to its own set.
    
4. Find returns the representative of a set.
    
5. Union combines two sets.
    
6. The root of a DSU tree represents its set.
    
7. Path Compression optimises the Find operation.
    
8. Union by Rank combines trees based on rank.
    
9. Union by Size combines trees based on the number of elements.
    
10. Path Compression and Union by Size/Rank together provide nearly constant amortized operation time.
    
11. DSU is commonly used in Kruskal's Algorithm.
    
12. DSU can detect cycles in undirected graphs.
    
13. DSU efficiently supports merging sets, but does not efficiently support splitting a set after a Union.
    

---

# Next Topics

After completing DSU, continue with:

1. Segment Tree
    
2. Fenwick Tree (Binary Indexed Tree)
    
3. Sparse Table
    
4. Advanced Graph Algorithms
    
5. Network Flow Algorithms
    

NOTE :- Practise implementing DSU from scratch using both Union by Rank and Union by Size. Understand Path Compression thoroughly because these concepts are frequently used in competitive programming.