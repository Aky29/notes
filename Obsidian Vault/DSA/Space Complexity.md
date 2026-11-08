# About

Space complexity is the amount of memory an algorithm requires to execute as a function of the input size.

Whenever an algorithm runs, it requires memory to store input data, variables, data structures and other information needed during execution.

Space complexity helps us understand how the memory requirement of an algorithm increases as the input size increases.

For example:

```
#include<iostream>
using namespace std;

int main(){

    int a = 10;
    int b = 20;

    cout << a + b;

    return 0;
}
```

Here we are using two integer variables. The memory required for these variables does not depend on the input size.

Therefore, the auxiliary space complexity is:

[  
O(1)  
]

# Types of Space Complexity

Space complexity can be understood through two important concepts:

1. Input Space
    
2. Auxiliary Space
    

## Input Space

Input space is the memory required to store the input provided to an algorithm.

For example:

```
int arr[n];
```

Here the array stores `n` integer elements.

If each integer occupies 4 bytes, the memory required is:

[  
4n \text{ bytes}  
]

Therefore, the input space complexity is:

[  
O(n)  
]

## Auxiliary Space

Auxiliary space is the additional memory used by an algorithm apart from the memory occupied by its input.

For example:

```
#include<iostream>
using namespace std;

int main(){

    int arr[5] = {1,2,3,4,5};

    int sum = 0;

    for(int i = 0; i < 5; i++){
        sum += arr[i];
    }

    cout << sum;

    return 0;
}
```

Here:

- The array stores the input.
    
- `sum` stores the calculated result.
    
- `i` is used as a loop variable.
    

The additional memory used by `sum` and `i` is constant.

Therefore:

Auxiliary space complexity:

[  
O(1)  
]

NOTE :- Space complexity is often used to describe the total memory requirement, while auxiliary space specifically describes the additional memory required by the algorithm. Always check which definition a question is using.

# Common Space Complexities

## Constant Space - O(1)

When an algorithm uses a fixed amount of additional memory regardless of the input size, its auxiliary space complexity is O(1).

Example:

```
#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += i;
    }

    cout << sum;

    return 0;
}
```

Here, regardless of the value of `n`, we only use a fixed number of variables.

Therefore:

[  
O(1)  
]

## Linear Space - O(n)

When the memory requirement increases proportionally with the input size, its space complexity is O(n).

Example:

```
#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        arr[i] = i;
    }

    delete[] arr;

    return 0;
}
```

Here we allocate memory for `n` integers.

Therefore:

[  
O(n)  
]

## Quadratic Space - O(n²)

When the memory requirement increases proportionally to the square of the input size, its space complexity is O(n²).

Example:

```
#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int** arr = new int*[n];

    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
    }

    for(int i = 0; i < n; i++){
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}
```

Here we allocate an n × n matrix.

Total number of elements:

[  
n \times n = n^2  
]

Therefore:

[  
O(n^2)  
]

## Logarithmic Space - O(log n)

When the memory requirement increases logarithmically with the input size, its space complexity is O(log n).

This commonly occurs in recursive algorithms where the problem size is reduced by a constant factor at every recursive call.

Example:

```
#include<iostream>
using namespace std;

void divide(int n){

    if(n <= 1){
        return;
    }

    divide(n/2);

}

int main(){

    divide(16);

    return 0;
}
```

At every recursive call, the value of `n` is divided by 2.

The recursion depth is approximately:

[  
\log_2(n)  
]

Each recursive call requires memory in the call stack.

Therefore:

[  
O(\log n)  
]

# Recursive Space Complexity

Whenever a function calls itself, memory is required to store information about each function call.

This information is stored in the call stack.

Example:

```
#include<iostream>
using namespace std;

void count(int n){

    if(n == 0){
        return;
    }

    count(n-1);

}

int main(){

    count(5);

    return 0;
}
```

Here the function calls itself `n` times before reaching the base condition.

Each call occupies space in the call stack.

Therefore:

[  
O(n)  
]

NOTE :- Even if a recursive function does not create any additional arrays or variables, its recursive calls still consume stack memory.

# Space Complexity of Common Operations

|Operation / Algorithm|Auxiliary Space|
|---|---|
|Array traversal (iterative)|O(1)|
|Array access|O(1)|
|Array insertion in place|O(1)|
|Array copying|O(n)|
|Linear search (iterative)|O(1)|
|Binary search (iterative)|O(1)|
|Binary search (recursive)|O(log n)|
|Bubble sort (in place)|O(1)|
|Merge sort|O(n)|
|Recursive factorial|O(n)|

# In-place Algorithms

An in-place algorithm is an algorithm that performs operations directly on the input data without requiring significant additional memory proportional to the input size.

Example:

```
#include<iostream>
using namespace std;

int main(){

    int arr[5] = {1,2,3,4,5};

    int i = 0;
    int j = 4;

    while(i < j){

        int temp = arr[i];

        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;

    }

    for(int k = 0; k < 5; k++){
        cout << arr[k] << " ";
    }

    return 0;
}
```

Here we reverse the array by swapping elements without creating another array.

The only additional memory used is a few variables.

Therefore:

[  
O(1)  
]

# Space Complexity vs Time Complexity

Time complexity measures how the execution time of an algorithm grows with input size.

Space complexity measures how the memory requirement of an algorithm grows with input size.

|Feature|Time Complexity|Space Complexity|
|---|---|---|
|Measures|Execution time growth|Memory usage growth|
|Concerned with|Operations performed|Memory required|
|Common notation|Big O|Big O|
|Example|O(n)|O(n)|

# Important Rules

1. Ignore constant values when calculating asymptotic space complexity.
    
2. Ignore lower-order terms.
    
3. Count memory that grows with the input size.
    
4. In recursive algorithms, consider the memory occupied by the call stack.
    
5. When multiple memory allocations are independent, add their space requirements.
    
6. When allocations are nested or have different lifetimes, consider the maximum memory used at the same time.
    
7. Auxiliary space and total space complexity are not always the same.
    

# Important Terms

- **Space Complexity:** Memory required by an algorithm as a function of input size.
    
- **Input Space:** Memory required to store the input.
    
- **Auxiliary Space:** Additional memory used by an algorithm apart from its input.
    
- **Call Stack:** Memory used to manage function calls and their execution.
    
- **Recursion Depth:** Number of active recursive function calls.
    
- **In-place Algorithm:** An algorithm that operates directly on input data using constant or otherwise limited auxiliary memory.
    
- **Memory Overhead:** Additional memory required to manage data structures or operations.
    

# What you can try

1. Best, Average and Worst Case Analysis.
    
2. Asymptotic Notations (Big O, Big Omega and Big Theta).
    
3. Time Complexity Analysis.
    
4. Recursion and Recursion Tree.
    
5. Amortized Analysis.