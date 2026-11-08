# About

Memory allocation is the process of reserving a portion of memory (RAM) to store data during the execution of a program. Whenever you declare a variable, array or any other data structure, memory is allocated to store that data.

Memory allocation in C++ can be divided into two types:

1. Static Memory Allocation
    
2. Dynamic Memory Allocation
    

# Static Memory Allocation

Static memory allocation is when the memory required by a variable or array is determined before or at the beginning of program execution. The size of the memory allocated cannot be changed during its lifetime.

For example:

```
#include<iostream>
using namespace std;

int main(){

    int a = 10;
    int arr[5] = {1,2,3,4,5};

    return 0;
}
```

Here the memory for `a` and `arr` is allocated automatically. Since the array has a fixed size of 5, you cannot increase its size during execution.

NOTE :- Local variables are generally stored in stack memory, while global and static variables have static storage duration. Static memory allocation does not always mean stack allocation.

# Dynamic Memory Allocation

Dynamic memory allocation allows you to allocate memory during program execution. Unlike static arrays, here you can decide how much memory you need while the program is running.

In C++ dynamic memory allocation is done using `new` and `delete`.

## Allocating memory using new

`new` is used to allocate memory dynamically and it returns the address of the allocated memory.

Syntax:

```
data_type* pointer = new data_type;
```

Example:

```
#include<iostream>
using namespace std;

int main(){

    int* ptr = new int;

    *ptr = 10;

    cout << *ptr;

    delete ptr;

    return 0;
}
```

Here `new int` allocates memory for one integer and returns its address which is stored in the pointer `ptr`. To access the value stored at that address we use `*ptr`.

NOTE :- `delete` is used to release the memory allocated using `new`.

## Allocating an array using new[]

When you want to allocate memory for multiple elements you use `new[]`.

Syntax:

```
data_type* pointer = new data_type[size];
```

Example:

```
#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    delete[] arr;

    return 0;
}
```

Here `new int[n]` allocates memory for n integers and returns the address of the first element. Since the elements are stored continuously, we can access them using normal array indexing.

NOTE :- For dynamically allocated arrays always use `delete[]` and not `delete`.

# Stack Memory and Heap Memory

Memory used by a program is organized into different regions. Two important regions to understand are stack and heap.

## Stack Memory

Stack memory is used to store local variables and information related to function calls. The memory is automatically managed and is released when the corresponding function or scope ends.

Example:

```
#include<iostream>
using namespace std;

void example(){

    int a = 10;
    int b = 20;

}

int main(){

    example();

    return 0;
}
```

Here `a` and `b` are local variables. Their lifetime ends when the function `example()` finishes execution.

## Heap Memory

Heap memory is used for dynamically allocated memory. Unlike stack memory, its lifetime is not automatically tied to the function in which it was allocated.

Example:

```
#include<iostream>
using namespace std;

int main(){

    int* ptr = new int(100);

    cout << *ptr;

    delete ptr;

    return 0;
}
```

Here the integer is allocated dynamically and remains allocated until we release it using `delete`.

NOTE :-

- Stack memory is generally managed automatically.
    
- Heap memory allocated using `new` needs to be released using `delete`.
    
- Stack and heap are different memory regions with different allocation and lifetime rules.
    

# Deallocation

Deallocation is the process of releasing memory that was previously allocated dynamically.

In C++ we use `delete` for a single dynamically allocated variable and `delete[]` for dynamically allocated arrays.

## Using delete

```
int* ptr = new int(10);

delete ptr;
ptr = nullptr;
```

## Using delete[]

```
int* arr = new int[5];

delete[] arr;
arr = nullptr;
```

NOTE :- Always match the allocation and deallocation operators.

|Allocation|Deallocation|
|---|---|
|`new int`|`delete ptr`|
|`new int[n]`|`delete[] ptr`|

# Memory Management Problems

Improper memory management can lead to problems which can affect the performance and correctness of a program.

## Memory Leak

A memory leak occurs when dynamically allocated memory is no longer accessible but has not been released.

Example:

```
int* ptr = new int(10);

ptr = nullptr;
```

Here the address of the allocated memory is lost when we assign `nullptr` to the pointer. Since we no longer have its address, we cannot release that memory through this pointer.

## Dangling Pointer

A dangling pointer is a pointer which refers to memory that has already been released or whose object lifetime has ended.

Example:

```
int* ptr = new int(10);

delete ptr;

// ptr is now dangling
ptr = nullptr;
```

After deleting the memory, the pointer still contains the old address. Setting it to `nullptr` prevents accidental use through that pointer.

## Double Deletion

Double deletion occurs when we try to release the same dynamically allocated memory more than once.

Example:

```
int* ptr = new int(10);

delete ptr;
delete ptr; // Undefined behaviour
```

## Buffer Overflow

Buffer overflow occurs when we try to access memory outside the allocated boundaries of an array.

Example:

```
int* arr = new int[5];

arr[5] = 100; // Invalid access

delete[] arr;
```

Here the valid indices are from 0 to 4. Accessing index 5 is outside the allocated array.


# Dynamic Arrays in C++

In C++ we generally use `vector` for dynamically sized arrays instead of manually allocating and deallocating memory.

A vector automatically manages memory allocation and resizing when new elements are inserted.

Example:

```
#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }

    return 0;
}
```

Some important functions of vector:

|Function|Use|
|---|---|
|`push_back()`|Inserts an element at the end|
|`pop_back()`|Removes the last element|
|`size()`|Returns the number of elements|
|`capacity()`|Returns the allocated element capacity|
|`resize()`|Changes the number of elements|
|`reserve()`|Requests memory capacity|
|`clear()`|Removes all elements|

NOTE :-

- Size represents the number of elements currently present.
    
- Capacity represents the number of elements that can fit without requiring reallocation.
    

# Static Array vs Dynamic Array

|Feature|Static Array|Dynamic Array|
|---|---|---|
|Size|Fixed|Can grow or shrink|
|Allocation|Automatic or static storage|Dynamic storage|
|Resizing|Not supported|Supported through reallocation|
|Memory management|Automatic for local arrays|Manual or container managed|
|Example|`int arr[5]`|`new int[n]`, `vector<int>`|

# Important Terms

- **Pointer:** A variable which stores the address of another variable.
    
- **Dereferencing:** Accessing the value stored at the memory address using `*`.
    
- **Memory Allocation:** Reserving memory to store data.
    
- **Memory Deallocation:** Releasing previously allocated memory.
    
- **Memory Leak:** Allocated memory that is no longer accessible but has not been released.
    
- **Dangling Pointer:** A pointer referring to memory that is no longer valid.
    
- **Reallocation:** Changing the size of an allocated memory block.
    
- **Contiguous Memory:** Memory locations arranged consecutively.
    
- **RAII:** A C++ technique in which resource management is tied to object lifetime.
    

# Modern C++ Memory Management

Although `new` and `delete` are important to understand, in modern C++ we generally use containers and smart pointers to manage memory safely.

|Requirement|Recommended approach|
|---|---|
|Fixed-size array|`std::array`|
|Dynamic-size array|`std::vector`|
|Dynamic single object|`std::unique_ptr`|
|Dynamic array ownership|`std::vector` or `std::unique_ptr<T[]>`|
|Shared ownership|`std::shared_ptr`|

Example:

```
#include<iostream>
#include<memory>
using namespace std;

int main(){

    unique_ptr<int> ptr = make_unique<int>(100);

    cout << *ptr;

    return 0;
}
```

Here memory is automatically released when `ptr` goes out of scope.