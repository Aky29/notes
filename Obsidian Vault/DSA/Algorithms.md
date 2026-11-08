# About

An **Algorithm** is a finite set of well-defined instructions used to solve a particular problem or perform a specific task.

An algorithm takes input, processes it through a sequence of steps, and produces the desired output.

**Example :-** Finding the largest element in an array.

```
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 25, 5, 40, 15};
    int n = 5;

    int largest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    cout << "Largest element: " << largest;

    return 0;
}
```

## Characteristics of an Algorithm

1. **Input :-** An algorithm can take zero or more inputs.
    
2. **Output :-** It must produce at least one output.
    
3. **Definiteness :-** Every instruction must be clear and unambiguous.
    
4. **Finiteness :-** It must terminate after a finite number of steps.
    
5. **Effectiveness :-** Every instruction must be simple enough to be performed.
    
6. **Correctness :-** It should produce the expected result for valid inputs.
    

## Representation of Algorithms

Algorithms can be represented in different ways.

### 1. Natural Language

Writing the steps in ordinary human language.

Example:

- Start.
    
- Take an array as input.
    
- Assume the first element is the largest.
    
- Compare every remaining element with it.
    
- Update the largest element if a bigger element is found.
    
- Print the largest element.
    

### 2. Pseudocode

Writing an algorithm using simple programming-like statements without following the exact syntax of a programming language.

```
START

INPUT array
largest = first element

FOR each remaining element
    IF element > largest
        largest = element

PRINT largest

END
```

### 3. Flowchart

A graphical representation of an algorithm using symbols and arrows to show the sequence of operations.

## Types of Algorithms

### 1. [[Searching Algorithms]]

Used to find a particular element in a collection of data.

Examples:

- Linear Search
    
- Binary Search
    
- Jump Search
    
- Interpolation Search

### 2. [[Sorting Algorithms]]

Used to arrange data in a particular order, usually ascending or descending.

Examples:

- Bubble Sort
    
- Selection Sort
    
- Insertion Sort
    
- Merge Sort
    
- Quick Sort
    
- Heap Sort
    

### 3. Divide and Conquer

Breaks a problem into smaller subproblems, solves them independently, and combines their results.

Examples:

- Merge Sort
    
- Quick Sort
    
- Binary Search

### 4. [[Greedy Algorithms]]

Makes the locally best choice at each step in the hope of finding a globally optimal solution.

Examples:

- Activity Selection
    
- Fractional Knapsack
    
- Huffman Coding
    
- Kruskal's Algorithm
    
- Prim's Algorithm
    

### 5. [[Dynamic Programming]]

Solves problems by breaking them into overlapping subproblems and storing their results to avoid repeated calculations.

Examples:

- Fibonacci
    
- 0/1 Knapsack
    
- Longest Common Subsequence
    
- Coin Change
    

### 6. [[Backtracking]]

Builds a solution step by step and goes back whenever a choice cannot lead to a valid solution.

Examples:

- N-Queens
    
- Sudoku Solver
    
- Rat in a Maze
    
- Subset Sum
    

### 7. [[Graph Algorithms]]

Used to solve problems involving vertices (nodes) and edges (connections).

Examples:

- BFS (Breadth First Search)
    
- DFS (Depth First Search)
    
- Dijkstra's Algorithm
    
- Bellman-Ford Algorithm
    
- Floyd-Warshall Algorithm
    

## Algorithm Analysis

Algorithm analysis is the process of evaluating an algorithm based on the resources it uses.

The two major factors are:

### 1. Time Complexity

Measures how the execution time of an algorithm grows with the size of the input.

Examples:

- O(1) - Constant
    
- O(log n) - Logarithmic
    
- O(n) - Linear
    
- O(n log n) - Linearithmic
    
- O(n²) - Quadratic
    

### 2. Space Complexity

Measures how much memory an algorithm requires as the input size grows.

Examples:

- O(1) - Constant extra space
    
- O(n) - Linear extra space
    
- O(n²) - Quadratic extra space
    

## Correctness of an Algorithm

An algorithm is correct if it produces the expected output for every valid input and terminates as required.

Correctness can be reasoned about using:

- **Precondition :-** Conditions that must be true before execution.
    
- **Postcondition :-** Conditions that must be true after execution.
    
- **Loop Invariant :-** A condition that remains true before and after every loop iteration.
    

## Important Terms

|Term|Meaning|
|---|---|
|Input|Data given to an algorithm|
|Output|Result produced by an algorithm|
|Pseudocode|Informal programming-like representation|
|Flowchart|Graphical representation of an algorithm|
|Optimization|Improving resource usage or performance|
|Correctness|Producing the expected result|
|Time Complexity|Growth of execution time|
|Space Complexity|Growth of memory usage|
|Brute Force|Trying all possible solutions|
|Recursion|A function calling itself|

## NOTE :-

- An algorithm is a logical procedure, whereas a program is its implementation in a programming language.
    
- The same algorithm can be implemented using different programming languages.
    
- A good algorithm should be correct, efficient, and easy to understand.
    
- The fastest algorithm is not always the best choice; memory usage, simplicity, and input constraints also matter.
    
- Before implementing an algorithm, understand the problem, its constraints, and possible edge cases.
    

## Next Topics you should try

1. Brute Force Algorithms
    
2. Searching Algorithms
    
3. Sorting Algorithms
    
4. Recursion
    
5. Divide and Conquer
    
6. Greedy Algorithms
    
7. Dynamic Programming
    
8. Backtracking
    
9. Graph Algorithms