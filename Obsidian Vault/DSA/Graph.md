# About

A **Graph** is a non-linear data structure consisting of a collection of vertices (nodes) and edges (connections between vertices).

Unlike trees, graphs do not necessarily follow a hierarchical structure. A graph can contain cycles, multiple paths between vertices and disconnected components.

Graphs are used to represent relationships and connections between different entities.

For example:

- Social networks represent relationships between people.
    
- Google Maps represents locations and roads.
    
- Computer networks represent connected computers.
    
- Websites represent connections between web pages.
    
- Recommendation systems represent relationships between users and products.
    

A graph is generally represented as:

```
G = (V, E)
```

Where:

- `V` = Set of vertices.
    
- `E` = Set of edges.
    

Example:

```
        A
       / \
      B---C
      |   |
      D---E
```

Here:

```
V = {A, B, C, D, E}

E = {(A,B), (A,C), (B,C), (B,D), (C,E), (D,E)}
```

---

# Terminologies Used in Graphs

## 1. Vertex (Node)

A vertex is an individual element of a graph.

It represents an entity such as a person, city or computer.

## 2. Edge

An edge represents a connection between two vertices.

For example, an edge between A and B represents a connection between those vertices.

## 3. Adjacent Vertices

Two vertices are adjacent if there is an edge directly connecting them.

## 4. Incident Edge

An edge is incident to a vertex if that vertex is one of its endpoints.

## 5. Degree of a Vertex

The degree of a vertex is the number of edges connected to it.

For an undirected graph:

```
Degree(v) = Number of edges incident to v
```

A self-loop contributes 2 to the degree of a vertex in an undirected graph.

## 6. In-Degree

In a directed graph, the in-degree of a vertex is the number of incoming edges.

## 7. Out-Degree

In a directed graph, the out-degree of a vertex is the number of outgoing edges.

## 8. Path

A path is a sequence of vertices connected through edges.

Example:

```
A -> B -> C -> D
```

## 9. Path Length

The number of edges present in a path is called its path length.

## 10. Cycle

A cycle is a path that starts and ends at the same vertex, without repeating other vertices.

Example:

```
A -> B -> C -> A
```

## 11. Connected Vertices

Two vertices are connected if there is a path between them.

## 12. Connected Component

A connected component is a maximal group of vertices in which every vertex is reachable from every other vertex.

## 13. Self-Loop

An edge that connects a vertex to itself is called a self-loop.

Example:

```
A -> A
```

## 14. Parallel Edges

Two or more edges connecting the same pair of vertices are called parallel edges.

## 15. Weight

A weight is a numerical value assigned to an edge.

It can represent:

- Distance
    
- Cost
    
- Time
    
- Network capacity
    

## 16. Subgraph

A subgraph is a graph formed using a subset of the vertices and edges of another graph.

## 17. Walk, Trail and Path

- Walk: A sequence of vertices where vertices and edges may repeat.
    
- Trail: A walk in which no edge is repeated.
    
- Path: A walk in which no vertex is repeated.
    

---

# Types of Graphs

Graphs can be classified according to their direction, edge weights and connectivity.

## 1. Undirected Graph

An undirected graph is a graph in which edges do not have a direction.

If A is connected to B, then B is also connected to A.

Example:

```
       A
      / \
     B---C
```

An edge is represented as:

```
(A, B)
```

It is equivalent to:

```
(B, A)
```

Applications:

- Friendship networks
    
- Two-way roads
    
- Computer network connections
    

## 2. Directed Graph (Digraph)

A directed graph is a graph in which every edge has a specific direction.

An edge from A to B does not necessarily mean there is an edge from B to A.

Example:

```
A ----> B
^       |
|       v
D <---- C
```

An edge is represented as:

```
A -> B
```

Applications:

- Following relationships on social media
    
- One-way roads
    
- Web page links
    
- Task dependencies
    

## 3. Weighted Graph

A weighted graph is a graph in which edges contain numerical values called weights.

Example:

```
        A
       / \
     10   20
     /     \
    B---5---C
```

The weights can represent distance, cost or time.

Applications:

- GPS navigation
    
- Network routing
    
- Transportation systems
    

## 4. Unweighted Graph

An unweighted graph is a graph in which edges do not have any associated numerical weights.

All edges are treated equally.

## 5. Connected Graph

An undirected graph is connected if there is a path between every pair of vertices.

Example:

```
A --- B --- C
      |
      D
```

Every vertex is reachable from every other vertex.

## 6. Disconnected Graph

A disconnected graph contains two or more connected components.

Example:

```
A --- B       C --- D

E --- F
```

There is no path connecting all the vertices.

## 7. Complete Graph

A complete graph is a simple undirected graph in which every pair of distinct vertices is connected by an edge.

For `n` vertices, the number of edges is:

```
E = n(n - 1) / 2
```

Example:

```
       A
      /|\
     / | \
    B--|--C
     \ | /
      \|/
       D
```

## 8. Cyclic Graph

A cyclic graph contains at least one cycle.

Example:

```
A --- B
|     |
D --- C
```

## 9. Acyclic Graph

An acyclic graph does not contain any cycle.

A Directed Acyclic Graph is commonly called a DAG.

## 10. Directed Acyclic Graph (DAG)

A DAG is a directed graph that does not contain any directed cycle.

Example:

```
A ---> B ---> D
 \           ^
  \         /
   ---> C --
```

Applications:

- Task scheduling
    
- Course prerequisites
    
- Build systems
    
- Dependency management
    

## 11. Bipartite Graph

A bipartite graph is a graph whose vertices can be divided into two disjoint sets such that every edge connects a vertex from one set to a vertex in the other set.

There are no edges connecting vertices within the same set.

Example:

```
Set A          Set B

  A1 ---------- B1
   |           /
  A2 -------- B2
   |
  A3 ---------- B3
```

Applications:

- Matching problems
    
- Job assignments
    
- Student-course relationships
    
- Recommendation systems
    

## 12. Regular Graph

A regular graph is a graph in which every vertex has the same degree.

A graph where every vertex has degree `k` is called a k-regular graph.

## 13. Sparse Graph

A sparse graph contains relatively few edges compared to the maximum possible number of edges.

Adjacency lists are generally efficient for storing sparse graphs.

## 14. Dense Graph

A dense graph contains a large number of edges compared to the maximum possible number of edges.

Adjacency matrices can be useful for dense graphs.

---

# Graph Representation

A graph can be stored in memory using different representations.

The most commonly used representations are:

1. Adjacency Matrix
    
2. Adjacency List
    
3. Edge List
    

## 1. Adjacency Matrix

An adjacency matrix is a two-dimensional array used to represent connections between vertices.

For a graph with `V` vertices, the matrix has dimensions:

```
V x V
```

If an edge exists between two vertices, the corresponding position is marked as 1.

Otherwise, it is marked as 0.

Example:

```
Graph:

A --- B
|     |
C --- D
```

Adjacency Matrix:

```
    A B C D

A   0 1 1 0
B   1 0 0 1
C   1 0 0 1
D   0 1 1 0
```

C++ Implementation:

```
int V = 4;

vector<vector<int>> adj(V, vector<int>(V, 0));

// Adding edges
adj[0][1] = 1;
adj[1][0] = 1;

adj[0][2] = 1;
adj[2][0] = 1;

adj[1][3] = 1;
adj[3][1] = 1;

adj[2][3] = 1;
adj[3][2] = 1;
```

For weighted graphs, store the weight instead of 1.

### Advantages

- Easy to implement.
    
- Checking whether an edge exists takes O(1).
    
- Useful for dense graphs.
    

### Disadvantages

- Requires O(V²) space.
    
- Iterating over all neighbors of a vertex takes O(V).
    
- Inefficient for sparse graphs.
    

## 2. Adjacency List

An adjacency list stores the neighbors of each vertex.

It is generally implemented using an array or vector of lists.

Example:

```
Graph:

A --- B
|     |
C --- D
```

Adjacency List:

```
A -> B, C
B -> A, D
C -> A, D
D -> B, C
```

C++ Implementation:

```
int V = 4;

vector<vector<int>> adj(V);

// Adding edges
adj[0].push_back(1);
adj[1].push_back(0);

adj[0].push_back(2);
adj[2].push_back(0);

adj[1].push_back(3);
adj[3].push_back(1);

adj[2].push_back(3);
adj[3].push_back(2);
```

For a weighted graph:

```
vector<vector<pair<int, int>>> adj(V);

// {neighbor, weight}
adj[0].push_back({1, 10});
```

### Advantages

- Requires O(V + E) space.
    
- Efficient for sparse graphs.
    
- Easy to traverse the neighbors of a vertex.
    

### Disadvantages

- Checking whether a specific edge exists can take O(degree of vertex).
    
- Slightly more complex than an adjacency matrix.
    

## 3. Edge List

An edge list stores all edges of a graph as pairs or triples.

For an unweighted graph:

```
vector<pair<int, int>> edges;

edges.push_back({0, 1});
edges.push_back({0, 2});
edges.push_back({1, 3});
```

For a weighted graph:

```
vector<tuple<int, int, int>> edges;

// {source, destination, weight}
edges.push_back({0, 1, 10});
```

### Advantages

- Simple representation.
    
- Requires O(E) space.
    
- Useful for algorithms that process all edges.
    

### Disadvantages

- Finding all neighbors of a vertex requires scanning the edge list.
    
- Checking whether a particular edge exists can take O(E).
    

## Comparison of Graph Representations

|Feature|Adjacency Matrix|Adjacency List|Edge List|
|---|---|---|---|
|Space|O(V²)|O(V + E)|O(E)|
|Check Edge|O(1)|O(degree)|O(E)|
|Find Neighbors|O(V)|O(degree)|O(E)|
|Add Edge|O(1)|O(1)|O(1)|
|Best For|Dense graphs|Sparse graphs|Edge-based algorithms|

NOTE :- For most competitive programming problems, adjacency lists are the most commonly used representation.

---

# Graph Traversal

Graph traversal is the process of visiting vertices in a graph systematically.

The two most important graph traversal algorithms are:

1. Breadth First Search (BFS)
    
2. Depth First Search (DFS)
    

Unlike trees, graphs can contain cycles. Therefore, we need a visited array or set to avoid visiting the same vertex repeatedly.

---

# 1. Breadth First Search (BFS)

BFS is a graph traversal algorithm that explores vertices level by level.

It first visits all immediate neighbors of a vertex before moving to the next level.

BFS uses a Queue.

### Working

1. Select a starting vertex.
    
2. Mark it as visited.
    
3. Insert it into a Queue.
    
4. Remove the front element from the Queue.
    
5. Visit all its unvisited neighbors.
    
6. Mark those neighbors as visited and insert them into the Queue.
    
7. Repeat until the Queue becomes empty.
    

Example:

```
          0
        /   \
       1     2
      / \     \
     3   4     5
```

Starting from vertex 0:

```
BFS = 0 1 2 3 4 5
```

### C++ Implementation

```
#include <bits/stdc++.h>
using namespace std;

void BFS(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int V = 6;

    vector<vector<int>> adj(V);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};

    BFS(0, adj, V);
}
```

### BFS Complexity

Using an adjacency list:

- Time Complexity: O(V + E)
    
- Space Complexity: O(V)
    

Applications:

- Shortest path in an unweighted graph.
    
- Finding connected components.
    
- Level-order exploration.
    
- Network broadcasting.
    
- Finding minimum number of edges between two vertices.
    

NOTE :- BFS finds the shortest path in terms of number of edges in an unweighted graph. It does not necessarily find the minimum-weight path in a weighted graph.

---

# 2. Depth First Search (DFS)

DFS is a graph traversal algorithm that explores a path as deeply as possible before backtracking.

It can be implemented using:

- Recursion
    
- Stack
    

### Working

1. Select a starting vertex.
    
2. Mark it as visited.
    
3. Visit an unvisited neighbor.
    
4. Continue exploring deeper.
    
5. If no unvisited neighbor exists, backtrack.
    
6. Continue until all reachable vertices have been visited.
    

Example:

```
          0
        /   \
       1     2
      / \     \
     3   4     5
```

One possible DFS traversal:

```
DFS = 0 1 3 4 2 5
```

The exact traversal depends on the order in which neighbors are stored.

### Recursive C++ Implementation

```
#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>>& adj,
         vector<bool>& visited) {

    visited[node] = true;

    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

int main() {
    int V = 6;

    vector<vector<int>> adj(V);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};

    vector<bool> visited(V, false);

    DFS(0, adj, visited);
}
```

### Iterative DFS Using Stack

```
void DFS(int start, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);

    stack<int> st;

    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (visited[node])
            continue;

        visited[node] = true;

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
            }
        }
    }
}
```

### DFS Complexity

Using an adjacency list:

- Time Complexity: O(V + E)
    
- Space Complexity: O(V)
    

Applications:

- Cycle detection.
    
- Connected components.
    
- Topological sorting.
    
- Path finding.
    
- Detecting bridges and articulation points.
    
- Solving maze problems.
    

---

# BFS vs DFS

|BFS|DFS|
|---|---|
|Breadth First Search|Depth First Search|
|Uses Queue|Uses Stack or Recursion|
|Explores level by level|Explores depth first|
|Finds shortest path in unweighted graphs|Does not guarantee shortest path|
|Useful for level-based problems|Useful for backtracking and structural analysis|
|O(V + E)|O(V + E)|

---

# Connected Components

A connected component is a maximal set of vertices where every vertex is reachable from every other vertex.

A disconnected graph can contain multiple connected components.

Example:

```
A --- B --- C

D --- E

F
```

There are three connected components:

1. A, B, C
    
2. D, E
    
3. F
    

### Finding Connected Components Using DFS

We can run DFS from every unvisited vertex.

Every new DFS traversal identifies one connected component.

C++ Implementation:

```
void DFS(int node, vector<vector<int>>& adj,
         vector<bool>& visited) {

    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

int countComponents(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);

    int components = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, adj, visited);
            components++;
        }
    }

    return components;
}
```

Time Complexity: O(V + E)

NOTE :- This implementation assumes an undirected graph. In directed graphs, connectedness requires different definitions and algorithms.

---

# Cycle Detection

Cycle detection is the process of determining whether a graph contains a cycle.

The approach depends on whether the graph is directed or undirected.

## 1. Cycle Detection in an Undirected Graph

Using DFS, we keep track of the parent of the current vertex.

If we encounter an already visited neighbor that is not the parent, a cycle exists.

C++ Implementation:

```
bool hasCycle(int node, int parent,
              vector<vector<int>>& adj,
              vector<bool>& visited) {

    visited[node] = true;

    for (int neighbor : adj[node]) {

        if (!visited[neighbor]) {
            if (hasCycle(neighbor, node, adj, visited))
                return true;
        }
        else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}
```

For a disconnected graph, call this function from every unvisited vertex.

## 2. Cycle Detection in a Directed Graph

In directed graphs, we can use DFS with a recursion-stack tracking array.

If we encounter a vertex that is already present in the current DFS path, a cycle exists.

C++ Implementation:

```
bool hasCycle(int node, vector<vector<int>>& adj,
              vector<bool>& visited,
              vector<bool>& path) {

    visited[node] = true;
    path[node] = true;

    for (int neighbor : adj[node]) {

        if (!visited[neighbor]) {
            if (hasCycle(neighbor, adj, visited, path))
                return true;
        }
        else if (path[neighbor]) {
            return true;
        }
    }

    path[node] = false;

    return false;
}
```

Time Complexity: O(V + E)

NOTE :- The parent check is important for undirected graphs, while the current recursion-path check is important for directed graphs.

---

# Shortest Path Algorithms

A shortest path is a path between two vertices with the minimum total cost or distance.

Different algorithms are used depending on the graph structure and edge weights.

## 1. BFS Shortest Path

BFS can find the shortest path in an unweighted graph.

It works because BFS explores vertices in increasing order of the number of edges from the starting vertex.

Time Complexity: O(V + E)

Applications:

- Minimum number of moves.
    
- Shortest path in an unweighted network.
    
- Minimum number of edges between two vertices.
    

## 2. Dijkstra's Algorithm

Dijkstra's Algorithm finds the shortest paths from one source vertex to all other reachable vertices in a weighted graph with non-negative edge weights.

It commonly uses a Min Priority Queue.

### Working

1. Set the distance of the source vertex to 0.
    
2. Set all other distances to infinity.
    
3. Insert the source into a Min Priority Queue.
    
4. Extract the vertex with the smallest current distance.
    
5. Check all its neighboring vertices.
    
6. If a shorter path is found, update the distance.
    
7. Repeat until the Priority Queue becomes empty.
    

### C++ Implementation

```
#include <bits/stdc++.h>
using namespace std;

void dijkstra(int source,
              vector<vector<pair<int, int>>>& adj,
              int V) {

    const int INF = INT_MAX;

    vector<int> dist(V, INF);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[source] = 0;

    pq.push({0, source});

    while (!pq.empty()) {

        int distance = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if (distance != dist[node])
            continue;

        for (auto edge : adj[node]) {

            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[neighbor]) {

                dist[neighbor] = dist[node] + weight;

                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    for (int i = 0; i < V; i++) {
        cout << i << " : ";

        if (dist[i] == INF)
            cout << "Unreachable";
        else
            cout << dist[i];

        cout << endl;
    }
}
```

Time Complexity: O((V + E) log V) with an adjacency list and binary heap priority queue.

NOTE :- Dijkstra's Algorithm does not work correctly with negative edge weights.

## 3. Bellman-Ford Algorithm

Bellman-Ford finds shortest paths from a single source vertex.

Unlike Dijkstra's Algorithm, it supports negative edge weights.

It can also detect reachable negative-weight cycles.

### Working

1. Initialize source distance as 0.
    
2. Initialize all other distances as infinity.
    
3. Relax every edge V - 1 times.
    
4. Perform one additional relaxation pass.
    
5. If a distance can still be reduced, a reachable negative-weight cycle exists.
    

### Edge Relaxation

Relaxation means checking whether a shorter path can be obtained through an edge.

For an edge `u -> v` with weight `w`:

```
if dist[u] + w < dist[v]

    dist[v] = dist[u] + w
```

### Complexity

- Time Complexity: O(V × E)
    
- Space Complexity: O(V)
    

Applications:

- Graphs containing negative weights.
    
- Detecting negative-weight cycles.
    
- Routing algorithms.
    

## 4. Floyd-Warshall Algorithm

Floyd-Warshall finds shortest paths between every pair of vertices.

It is an all-pairs shortest path algorithm.

It uses Dynamic Programming.

### Working

For every intermediate vertex `k`, check whether travelling from `i` to `j` through `k` gives a shorter path.

Formula:

```
dist[i][j] = min(
    dist[i][j],
    dist[i][k] + dist[k][j]
)
```

### Complexity

- Time Complexity: O(V³)
    
- Space Complexity: O(V²)
    

It supports negative edge weights but does not produce meaningful shortest paths when a negative cycle exists.

---

# Minimum Spanning Tree (MST)

A Minimum Spanning Tree is a spanning tree of a connected, undirected, weighted graph with the minimum possible total edge weight.

A spanning tree:

- Connects all vertices.
    
- Contains no cycles.
    
- Has exactly V - 1 edges.
    

An MST minimizes the total weight of these edges.

Example:

```
       10
   A ------- B
    \       / 
   6 \     / 5
      \   /
        C
```

The minimum spanning tree contains the edges with weights 5 and 6.

Total Weight:

```
5 + 6 = 11
```

There are two major algorithms for finding an MST.

## 1. Prim's Algorithm

Prim's Algorithm builds an MST by starting from a vertex and repeatedly selecting the minimum-weight edge that connects the current tree to a vertex outside it.

### Working

1. Select any starting vertex.
    
2. Mark it as included in the MST.
    
3. Find the minimum-weight edge connecting the included vertices to an unvisited vertex.
    
4. Add that edge and vertex.
    
5. Repeat until all vertices are included.
    

It commonly uses a Min Priority Queue.

Time Complexity: O((V + E) log V) using an adjacency list and binary heap.

## 2. Kruskal's Algorithm

Kruskal's Algorithm builds an MST by selecting edges in increasing order of their weights.

It uses Disjoint Set Union (DSU) to detect cycles efficiently.

### Working

1. Sort all edges by increasing weight.
    
2. Select the smallest edge.
    
3. Check whether its endpoints belong to different components.
    
4. If they belong to different components, include the edge.
    
5. Merge their components.
    
6. Continue until V - 1 edges are selected or all edges are processed.
    

Time Complexity: O(E log E), including edge sorting.

NOTE :- Prim's and Kruskal's algorithms work with connected, undirected, weighted graphs. For a disconnected graph, applying Kruskal's algorithm produces a Minimum Spanning Forest.

---

# Topological Sorting

Topological Sorting is a linear ordering of vertices in a Directed Acyclic Graph (DAG).

For every directed edge:

```
u -> v
```

Vertex `u` must appear before vertex `v` in the ordering.

Example:

```
A ---> C
|
v
B ---> D
```

One possible topological ordering:

```
A, B, C, D
```

Another valid ordering may also exist.

Topological sorting is only possible for Directed Acyclic Graphs.

## 1. Kahn's Algorithm (BFS Approach)

Kahn's Algorithm uses the in-degree of vertices.

### Working

1. Calculate the in-degree of every vertex.
    
2. Insert all vertices with in-degree 0 into a Queue.
    
3. Remove a vertex from the Queue.
    
4. Add it to the topological ordering.
    
5. Decrease the in-degree of all its outgoing neighbors.
    
6. Insert a neighbor into the Queue when its in-degree becomes 0.
    
7. Continue until the Queue becomes empty.
    

If fewer than V vertices are processed, the graph contains a directed cycle.

### C++ Implementation

```
vector<int> topologicalSort(int V,
                            vector<vector<int>>& adj) {

    vector<int> indegree(V, 0);

    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> result;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        result.push_back(node);

        for (int neighbor : adj[node]) {

            indegree[neighbor]--;

            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    if (result.size() != V)
        return {};

    return result;
}
```

Time Complexity: O(V + E)

## 2. DFS Approach

Topological sorting can also be performed using DFS.

The basic idea is to push each vertex into a stack after all its outgoing neighbors have been processed.

Reversing the finishing order produces a topological ordering.

Time Complexity: O(V + E)

Applications:

- Task scheduling.
    
- Course prerequisites.
    
- Dependency resolution.
    
- Build systems.
    

---

# Disjoint Set Union (DSU)

Disjoint Set Union is also called Union-Find.

It is a data structure used to manage a collection of non-overlapping sets.

It supports two main operations:

1. Find
    
2. Union
    

### 1. Find

Determines which set a particular element belongs to.

It returns the representative (root) of that set.

### 2. Union

Combines two different sets into one set.

### Path Compression

Path Compression optimizes the Find operation.

It makes each visited node point directly to the root of its set.

### Union by Size / Rank

This technique keeps the set structure shallow by attaching the smaller or shallower tree under the larger or deeper tree.

### C++ Implementation

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

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
```

### Complexity

With path compression and union by size/rank:

- Find: Nearly O(1) amortized.
    
- Union: Nearly O(1) amortized.
    

More formally, the amortized complexity per operation is O(α(n)), where α is the inverse Ackermann function.

Applications:

- Kruskal's Algorithm.
    
- Cycle detection in undirected graphs.
    
- Network connectivity.
    
- Grouping connected elements.
    

---

# Bridges and Articulation Points

These are important graph concepts used to understand connectivity.

## 1. Bridge

A bridge is an edge whose removal increases the number of connected components in an undirected graph.

In other words, removing that edge disconnects part of the graph.

## 2. Articulation Point

An articulation point is a vertex whose removal, along with its incident edges, increases the number of connected components.

These concepts are commonly identified using DFS and discovery/low-link times.

Applications:

- Network reliability.
    
- Finding critical connections.
    
- Identifying vulnerable points in networks.
    

---

# Strongly Connected Components (SCC)

A Strongly Connected Component is a maximal set of vertices in a directed graph where every vertex is reachable from every other vertex.

Two commonly used algorithms are:

## 1. Kosaraju's Algorithm

It uses two DFS passes:

1. Perform DFS on the original graph and record vertices in finishing order.
    
2. Reverse all directed edges.
    
3. Process vertices in reverse finishing order using DFS.
    
4. Every DFS traversal in the reversed graph identifies one SCC.
    

Time Complexity: O(V + E)

## 2. Tarjan's Algorithm

Tarjan's Algorithm finds SCCs using a single DFS traversal.

It maintains:

- Discovery time
    
- Low-link value
    
- Stack
    

Time Complexity: O(V + E)

Applications:

- Dependency analysis.
    
- Social network analysis.
    
- Detecting mutually reachable groups.
    
- Program analysis.
    

---

# Important Graph Algorithms Summary

|Algorithm|Purpose|Time Complexity|
|---|---|---|
|BFS|Graph traversal|O(V + E)|
|DFS|Graph traversal|O(V + E)|
|Dijkstra|Single-source shortest path|O((V + E) log V)|
|Bellman-Ford|Shortest path with negative weights|O(VE)|
|Floyd-Warshall|All-pairs shortest path|O(V³)|
|Prim|Minimum Spanning Tree|O((V + E) log V)|
|Kruskal|Minimum Spanning Tree|O(E log E)|
|Kahn's Algorithm|Topological Sorting|O(V + E)|
|Kosaraju|Strongly Connected Components|O(V + E)|
|Tarjan|Strongly Connected Components|O(V + E)|

These complexities assume the common adjacency-list or edge-list implementations described in the notes.

---

# Applications of Graphs

1. **Social Networks** :- Represent relationships between users.
    
2. **Navigation Systems** :- Represent cities, locations and roads.
    
3. **Computer Networks** :- Represent connections between computers.
    
4. **Search Engines** :- Represent links between web pages.
    
5. **Recommendation Systems** :- Represent relationships between users and products.
    
6. **Operating Systems** :- Represent resource allocation and dependencies.
    
7. **Compilers** :- Represent dependencies between instructions and modules.
    
8. **Scheduling** :- Represent task dependencies.
    
9. **Machine Learning** :- Represent relationships in graph-based learning.
    
10. **Biology** :- Represent protein interactions and molecular networks.
    

---

# Important Terms

|Term|Meaning|
|---|---|
|Vertex|Individual node in a graph|
|Edge|Connection between two vertices|
|Degree|Number of incident edges|
|In-Degree|Number of incoming edges|
|Out-Degree|Number of outgoing edges|
|Path|Sequence of connected vertices|
|Cycle|Path that returns to its starting vertex|
|Weight|Numerical value assigned to an edge|
|Connected Component|Maximal connected group of vertices|
|Adjacency Matrix|Two-dimensional graph representation|
|Adjacency List|Stores neighbors of each vertex|
|Edge List|Stores all edges|
|BFS|Breadth First Search|
|DFS|Depth First Search|
|DAG|Directed Acyclic Graph|
|MST|Minimum Spanning Tree|
|DSU|Disjoint Set Union|
|Relaxation|Updating a distance when a shorter path is found|
|Topological Sorting|Ordering of vertices in a DAG|
|Bridge|Edge whose removal increases connected components|
|Articulation Point|Vertex whose removal increases connected components|
|SCC|Strongly Connected Component|

---

# Important Notes

1. A graph is a non-linear data structure.
    
2. A graph is represented as G = (V, E).
    
3. Graphs can be directed or undirected.
    
4. Graphs can be weighted or unweighted.
    
5. A graph can contain cycles.
    
6. A tree is a special type of connected, undirected, acyclic graph.
    
7. An undirected graph with V vertices can have at most V(V-1)/2 edges if it is simple.
    
8. A connected undirected graph contains at least V - 1 edges.
    
9. BFS uses a Queue.
    
10. DFS uses a Stack or Recursion.
    
11. BFS finds shortest paths in unweighted graphs.
    
12. Dijkstra does not support negative edge weights.
    
13. Bellman-Ford supports negative edge weights and can detect reachable negative cycles.
    
14. Floyd-Warshall calculates shortest paths between all pairs of vertices.
    
15. Prim's and Kruskal's algorithms find Minimum Spanning Trees.
    
16. Topological Sorting is possible only for DAGs.
    
17. DSU is commonly used in Kruskal's Algorithm.
    
18. Adjacency Lists are generally preferred for sparse graphs.
    

---

# Next Topics

After completing Graphs, continue with:

1. Advanced Graph Algorithms
    
2. Shortest Path Problem Practice
    
3. Minimum Spanning Tree Problems
    
4. Strongly Connected Components
    
5. Bridges and Articulation Points
    
6. Network Flow Algorithms
    
7. Advanced Graph Problems
    

NOTE :- Learn graph representation, BFS and DFS thoroughly before moving to advanced algorithms. They are the foundation for almost every graph problem in DSA.