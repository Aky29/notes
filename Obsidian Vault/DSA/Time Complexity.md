# About

Time complexity is the measure of how the execution time of an algorithm grows with respect to the input size.

Whenever an algorithm runs, it performs a certain number of operations. As the input size increases, the number of operations also increases depending on how the algorithm is written.

Time complexity helps us understand how efficiently an algorithm performs as the input size grows.

For example:

```
#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << i << endl;
    }

    return 0;
}
```

Here the loop executes `n` times. If the input size doubles, the number of iterations also doubles.

Therefore, the time complexity is:

[  
O(n)  
]

NOTE :- Time complexity does not measure the actual time taken by an algorithm in seconds. It measures how the number of operations grows with the input size.

# Asymptotic Analysis

Asymptotic analysis is a method used to analyze the performance of an algorithm as the input size becomes larger.

Instead of calculating the exact execution time, we study how the number of operations grows.

For example:

```
int a = 10;
int b = 20;
int c = a + b;
```

Here, the number of operations does not depend on the input size.

Therefore:

[  
O(1)  
]

Another example:

```
for(int i = 0; i < n; i++){
    cout << i;
}
```

Here, the number of operations increases with `n`.

Therefore:

[  
O(n)  
]

NOTE :- In asymptotic analysis, we ignore constant factors and lower-order terms because we are interested in the growth rate of the algorithm.

# Types of Time Complexity

Time complexity is commonly analyzed using three cases:

1. Best Case
    
2. Average Case
    
3. Worst Case
    

## Best Case

Best case is the minimum number of operations required by an algorithm for a given input size.

For example, consider linear search:

```
int arr[5] = {10,20,30,40,50};

int target = 10;

for(int i = 0; i < 5; i++){

    if(arr[i] == target){
        cout << "Found";
        break;
    }

}
```

Here the target is present at the first position, so the algorithm finds it in the first iteration.

Best case:

[  
O(1)  
]

## Average Case

Average case is the expected number of operations performed by an algorithm over a distribution of possible inputs.

In linear search, if the target is equally likely to be present at any position, the algorithm will examine approximately half of the elements on average.

Average case:

[  
O(n)  
]

## Worst Case

Worst case is the maximum number of operations required by an algorithm for a given input size.

In linear search, the worst case occurs when the target is at the last position or is not present in the array.

Worst case:

[  
O(n)  
]

NOTE :- Best, average and worst cases describe different input scenarios. They are not separate asymptotic notations.

# Asymptotic Notations

Asymptotic notations are used to represent the growth rate of an algorithm.

The three main notations are:

1. Big O - O
    
2. Big Omega - Ω
    
3. Big Theta - Θ
    

## Big O - O(n)

Big O represents an asymptotic upper bound on the growth of an algorithm.

It tells us that the algorithm will not grow faster than a particular rate, beyond a sufficiently large input size.

Example:

```
for(int i = 0; i < n; i++){
    cout << i;
}
```

The loop executes `n` times.

Therefore:

[  
O(n)  
]

## Big Omega - Ω(n)

Big Omega represents an asymptotic lower bound on the growth of an algorithm.

It tells us that the algorithm grows at least as fast as a particular rate, beyond a sufficiently large input size.

For the previous loop:

[  
\Omega(n)  
]

Because it always executes `n` iterations.

## Big Theta - Θ(n)

Big Theta represents a tight asymptotic bound.

It means that the growth rate of the algorithm is bounded both above and below by the same asymptotic function.

For the previous loop:

[  
\Theta(n)  
]

Because the number of iterations is exactly proportional to `n`.

# Common Time Complexities

## Constant Time - O(1)

When the number of operations does not depend on the input size, the time complexity is constant.

Example:

```
int a = 10;
int b = 20;

int sum = a + b;
```

Regardless of the input size, the number of operations remains constant.

Therefore:

[  
O(1)  
]

## Logarithmic Time - O(log n)

When the input size is repeatedly divided or reduced by a constant factor, the time complexity is generally logarithmic.

Example:

```
int n = 100;

while(n > 1){

    n = n / 2;

}
```

At every iteration, the value of `n` is divided by 2.

The number of iterations is approximately:

[  
\log_2(n)  
]

Therefore:

[  
O(\log n)  
]

Binary search is a common example of a logarithmic time algorithm.

## Linear Time - O(n)

When the number of operations increases proportionally with the input size, the time complexity is linear.

Example:

```
for(int i = 0; i < n; i++){
    cout << i;
}
```

The loop executes `n` times.

Therefore:

[  
O(n)  
]

## Linearithmic Time - O(n log n)

When an algorithm performs `n` operations across approximately `log n` levels, its time complexity is generally O(n log n).

Example:

Merge sort divides the array into smaller parts and then merges them.

The number of levels is:

[  
\log_2(n)  
]

The merging work at each level is:

[  
O(n)  
]

Therefore:

[  
O(n \log n)  
]

## Quadratic Time - O(n²)

When an algorithm performs approximately `n × n` operations, its time complexity is quadratic.

Example:

```
for(int i = 0; i < n; i++){

    for(int j = 0; j < n; j++){

        cout << i << " " << j << endl;

    }

}
```

The outer loop executes `n` times and the inner loop also executes `n` times for every outer iteration.

Total iterations:

[  
n \times n = n^2  
]

Therefore:

[  
O(n^2)  
]

## Cubic Time - O(n³)

When an algorithm performs approximately `n × n × n` operations, its time complexity is cubic.

Example:

```
for(int i = 0; i < n; i++){

    for(int j = 0; j < n; j++){

        for(int k = 0; k < n; k++){

            cout << i << j << k;

        }

    }

}
```

Total iterations:

[  
n \times n \times n = n^3  
]

Therefore:

[  
O(n^3)  
]

## Exponential Time - O(2ⁿ)

When the number of operations approximately doubles with every increase in input size, the time complexity is exponential.

Example:

```
void generate(int n){

    if(n == 0){
        return;
    }

    generate(n-1);
    generate(n-1);

}
```

Each function call generates two additional recursive calls until the base condition is reached.

Therefore:

[  
O(2^n)  
]

## Factorial Time - O(n!)

Factorial time complexity occurs when the number of operations grows proportionally to the factorial of the input size.

Example:

Generating all possible permutations of `n` distinct elements.

The number of permutations is:

[  
n! = n \times (n-1) \times (n-2) \times \cdots \times 1  
]

Therefore:

[  
O(n!)  
]

# Growth Rate Comparison

The following table shows how different time complexities grow as the input size increases.

|Complexity|n = 10|n = 100|
|---|---|---|
|O(1)|1|1|
|O(log n)|~3|~7|
|O(n)|10|100|
|O(n log n)|~33|~664|
|O(n²)|100|10,000|
|O(n³)|1,000|1,000,000|
|O(2ⁿ)|1,024|~1.27 × 10³⁰|
|O(n!)|3,628,800|~9.33 × 10¹⁵⁷|

NOTE :- These are values of the respective growth functions, not exact counts of operations for every algorithm.

# Rules for Calculating Time Complexity

## 1. Ignore Constants

If an algorithm performs `5n` operations, its time complexity is O(n).

Example:

```
for(int i = 0; i < n; i++){
    cout << i;
}

for(int i = 0; i < n; i++){
    cout << i;
}

for(int i = 0; i < n; i++){
    cout << i;
}
```

Total operations:

[  
T(n) = 3n  
]

Ignoring the constant:

[  
O(n)  
]

## 2. Ignore Lower Order Terms

When an algorithm has multiple terms, we keep the term that grows the fastest.

Example:

[  
T(n) = n^2 + n + 10  
]

Since (n^2) grows faster than (n) and constants:

[  
O(n^2)  
]

## 3. Sequential Loops

When loops execute one after another, add their time complexities.

Example:

```
for(int i = 0; i < n; i++){
    cout << i;
}

for(int i = 0; i < n; i++){
    cout << i;
}
```

Total complexity:

[  
T(n) = n + n  
]

[  
O(n)  
]

## 4. Nested Loops

When one loop is inside another, multiply their iteration counts when their bounds are independent.

Example:

```
for(int i = 0; i < n; i++){

    for(int j = 0; j < n; j++){

        cout << i << j;

    }

}
```

Total complexity:

[  
T(n) = n \times n  
]

[  
O(n^2)  
]

## 5. Loops with Different Conditions

The number of iterations depends on how the loop variable changes.

Example:

```
for(int i = 1; i < n; i *= 2){

    cout << i;

}
```

Here the value of `i` doubles in every iteration.

The sequence is:

[  
1, 2, 4, 8, 16, \ldots  
]

Therefore:

[  
O(\log n)  
]

## 6. Conditional Statements

For conditional statements, the time complexity depends on the branch that executes.

Example:

```
if(n > 10){

    for(int i = 0; i < n; i++){
        cout << i;
    }

}
else{

    cout << n;

}
```

The first branch takes O(n), while the second takes O(1).

Worst-case complexity:

[  
O(n)  
]

# Time Complexity of Common DSA Operations

|Operation / Algorithm|Time Complexity|
|---|---|
|Array access|O(1)|
|Array traversal|O(n)|
|Linear search|O(n)|
|Binary search|O(log n)|
|Array insertion at beginning|O(n)|
|Array insertion at end (available capacity)|O(1)|
|Bubble sort|O(n²)|
|Selection sort|O(n²)|
|Insertion sort|O(n²) worst case|
|Merge sort|O(n log n)|
|Quick sort|O(n log n) average|
|Quick sort|O(n²) worst case|

# Time Complexity vs Space Complexity

Time complexity measures how the number of operations grows with input size.

Space complexity measures how the memory requirement grows with input size.

|Feature|Time Complexity|Space Complexity|
|---|---|---|
|Measures|Growth of execution work|Growth of memory usage|
|Concerned with|Operations|Memory|
|Main objective|Improve execution efficiency|Reduce memory requirements|
|Example|O(n)|O(n)|

# Important Terms

- **Time Complexity:** Measures how the execution work of an algorithm grows with input size.
    
- **Asymptotic Analysis:** Analyzing algorithm growth as input size increases.
    
- **Best Case:** Minimum operations for a given input size.
    
- **Average Case:** Expected operations over a distribution of inputs.
    
- **Worst Case:** Maximum operations for a given input size.
    
- **Big O:** Asymptotic upper bound.
    
- **Big Omega:** Asymptotic lower bound.
    
- **Big Theta:** Asymptotically tight bound.
    
- **Growth Rate:** How quickly the number of operations increases with input size.
    
- **Amortized Analysis:** Analysis of average cost per operation over a sequence of operations, even when individual operations have different costs.
    

# Important Notes

1. Time complexity does not tell you the exact execution time in seconds.
    
2. Two algorithms with the same time complexity can have different actual execution times.
    
3. Big O is commonly used to describe worst-case complexity, but technically it represents an upper bound and is not restricted to worst-case analysis.
    
4. Nested loops do not always mean O(n²). Their actual complexity depends on their iteration conditions.
    
5. Sequential loops are generally added, while independent nested loops are generally multiplied.
    
6. Recursive function calls must also be considered when calculating time complexity.
    
7. Always identify the input size before calculating complexity.
    
8. An algorithm with a better asymptotic complexity is not necessarily faster for every small input size.
    

# What to can try 

1. Best, Average and Worst Case Analysis (more deeply).
    
2. Asymptotic Notations and their mathematical definitions.
    
3. Recurrence Relations.
    
4. Recursion Tree Method.
    
5. Master Theorem.
    
6. Amortized Analysis.