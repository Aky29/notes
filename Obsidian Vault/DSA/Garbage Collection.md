# About

Garbage collection is the process of automatically identifying and reclaiming memory that is no longer being used by a program.

When a program dynamically allocates memory, that memory needs to be released when it is no longer required. In languages like C and C++, memory management is generally handled manually or through resource-management mechanisms.

In languages like Java, Python, and C#, garbage collection is used to automatically manage memory.

The main purpose of garbage collection is to prevent memory leaks caused by memory that is no longer needed but has not been released.

# Why Garbage Collection?

Consider a situation where you dynamically allocate memory for an object and after using it, you no longer need it.

In manual memory management, you need to explicitly release that memory.

Example in C++:

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

Here we manually release the allocated memory using `delete`.

However, in languages with garbage collection, the runtime identifies objects that are no longer reachable and reclaims their memory automatically.

NOTE :- Garbage collection does not mean that memory is released immediately after an object is no longer needed. The garbage collector decides when to reclaim that memory.

# How Garbage Collection Works

Garbage collection generally works by identifying which objects are still reachable by the program and which objects are no longer reachable.

The basic process can be divided into three steps:

1. Identify objects that are reachable.
    
2. Identify objects that are no longer reachable.
    
3. Reclaim the memory occupied by unreachable objects.
    

## Reachability

An object is considered reachable if the program can still access it through a reference or a chain of references from a root object.

For example:

```
class Main {

    public static void main(String[] args) {

        Object a = new Object();

        Object b = new Object();

        a = null;

    }
}
```

Here:

- Initially, both objects are reachable through their references.
    
- When `a = null` is executed, the first object loses its reference from `a`.
    
- If no other references point to that object, it becomes eligible for garbage collection.
    
- The second object is still reachable through `b`.
    

NOTE :- An object becoming unreachable does not mean that it will be collected immediately.

# Garbage Collection Algorithms

There are different algorithms used by garbage collectors to identify and reclaim unused memory.

## Mark and Sweep

Mark and Sweep is one of the fundamental garbage collection algorithms.

It works in two main phases:

**1. Mark Phase**

The garbage collector starts from the root references and marks every object that can be reached.

**2. Sweep Phase**

The garbage collector scans memory and reclaims the objects that were not marked.

Example:

```
Objects in memory:

A -> B -> C

D -> E

Roots:
A

Reachable:
A, B, C

Unreachable:
D, E
```

After the Mark Phase, A, B and C are marked as reachable.

During the Sweep Phase, D and E are identified as garbage and their memory is reclaimed.

## Mark and Compact

Mark and Compact works similarly to Mark and Sweep, but instead of simply reclaiming unused memory, it also moves the remaining objects together.

The process:

1. Mark all reachable objects.
    
2. Identify unreachable objects.
    
3. Remove unreachable objects.
    
4. Move the remaining objects together to reduce memory fragmentation.
    
5. Update references to the moved objects.
    

This helps create larger continuous blocks of available memory.

## Reference Counting

Reference counting is a garbage collection technique in which every object maintains a count of how many references point to it.

Whenever a new reference is created, the count increases.

Whenever a reference is removed, the count decreases.

When the reference count becomes zero, the object can be reclaimed.

Example:

```
a = []
b = a

del a
```

Initially, both `a` and `b` refer to the same list.

When `a` is deleted, the list still has a reference through `b`, so it cannot be reclaimed.

NOTE :- Reference counting alone cannot handle circular references. For example, if two objects refer to each other but are no longer reachable from the program, their reference counts may never become zero.

# Memory Fragmentation

Memory fragmentation occurs when available memory is divided into smaller blocks, making it difficult to allocate large continuous memory blocks.

There are two main types:

## Internal Fragmentation

Internal fragmentation occurs when more memory is allocated to a process or object than it actually needs, resulting in unused space inside the allocated block.

## External Fragmentation

External fragmentation occurs when free memory is available but is divided into small, non-contiguous blocks.

Garbage collectors that use compaction can reduce external fragmentation by moving reachable objects together.

# Types of Garbage Collectors

Different programming languages and runtimes use different garbage collection techniques.

## Generational Garbage Collection

Generational garbage collection is based on the observation that most objects become unused shortly after they are created.

Instead of treating all objects equally, memory is divided into generations.

Common generations include:

- Young Generation
    
- Old Generation
    

**Young Generation**

Newly created objects are generally placed in the young generation. Garbage collection happens frequently here because many newly created objects become unused quickly.

**Old Generation**

Objects that survive multiple garbage collection cycles may be moved to the old generation.

Garbage collection happens less frequently in this generation.

## Incremental Garbage Collection

Incremental garbage collection divides the garbage collection process into smaller steps instead of performing the entire process at once.

This helps reduce long pauses during program execution.

## Concurrent Garbage Collection

Concurrent garbage collection allows garbage collection work to happen alongside normal program execution.

This helps reduce the time during which the application is stopped.

# Garbage Collection in Different Languages

Different programming languages handle memory management differently.

|Language|Memory Management|
|---|---|
|C|Manual memory management|
|C++|Manual management and RAII|
|Java|Automatic garbage collection|
|Python|Reference counting and cyclic garbage collection|
|C#|Automatic garbage collection|
|Go|Concurrent garbage collection|
|JavaScript|Automatic garbage collection|

## Garbage Collection in Java

Java uses automatic garbage collection through its JVM (Java Virtual Machine).

The JVM identifies objects that are no longer reachable and reclaims their memory.

Example:

```
public class Main {

    public static void main(String[] args) {

        Main obj = new Main();

        obj = null;

    }
}
```

After assigning `null`, the object may become eligible for garbage collection if no other references exist.

Java also provides:

```
System.gc();
```

This requests garbage collection, but it does not guarantee that garbage collection will run immediately.

## Garbage Collection in Python

Python primarily uses reference counting along with a cyclic garbage collector.

Example:

```
a = [1, 2, 3]

b = a

del a
```

Here the list is still referenced by `b`, so it is not garbage.

Python also provides the `gc` module to interact with its cyclic garbage collector.

```
import gc

gc.collect()
```

This requests a garbage collection cycle.

# Garbage Collection vs Manual Memory Management

|Feature|Garbage Collection|Manual Memory Management|
|---|---|---|
|Memory release|Automatic|Programmer or resource-management mechanism|
|Control|Runtime managed|More direct control|
|Memory leaks|Still possible|Possible|
|Performance|Runtime overhead and pauses may occur|More predictable when managed carefully|
|Complexity|Less manual memory-management work|Requires careful management|
|Examples|Java, Python, C#|C, traditional C++ allocation|

# Advantages of Garbage Collection

- Reduces the need for manual memory deallocation.
    
- Helps prevent certain types of memory leaks.
    
- Reduces the risk of dangling pointers caused by manual deallocation.
    
- Makes memory management easier for developers.
    
- Automatically reclaims memory occupied by unreachable objects.
    

# Disadvantages of Garbage Collection

- Garbage collection consumes CPU resources.
    
- Collection cycles can cause application pauses.
    
- Memory may not be reclaimed immediately when an object becomes unreachable.
    
- Garbage collection does not prevent every kind of memory leak.
    
- Developers have less direct control over the exact timing of memory reclamation.
    

# Important Terms

- **Garbage:** Memory occupied by objects that are no longer reachable.
    
- **Garbage Collector (GC):** A runtime mechanism that identifies and reclaims unused memory.
    
- **Reachability:** Whether an object can be accessed from the program's root references.
    
- **Root Objects:** References from which the garbage collector starts tracing reachable objects.
    
- **Mark and Sweep:** An algorithm that marks reachable objects and reclaims unmarked objects.
    
- **Mark and Compact:** An algorithm that reclaims unreachable objects and moves remaining objects together.
    
- **Reference Counting:** A technique that tracks how many references point to an object.
    
- **Memory Fragmentation:** The division of available memory into smaller blocks.
    
- **Generational GC:** A garbage collection approach that groups objects based on their age.
    
- **Memory Leak:** Memory that remains occupied even though it is no longer needed.
    

# Important Notes

1. Garbage collection is not the same as memory deallocation. It is an automated process for reclaiming memory.
    
2. An object becoming unreachable does not mean its memory is immediately released.
    
3. Garbage collection cannot prevent all memory leaks. For example, an object that is no longer useful but is still referenced may remain in memory.
    
4. C++ does not have a built-in general-purpose garbage collector. It primarily uses RAII, smart pointers and manual memory management.
    
5. Garbage collection generally manages memory, not every other resource such as files, sockets or database connections.
    

# What to you can try

1. Pointers and References
    
2. Shallow Copy vs Deep Copy
    
3. Stack vs Heap
    
4. Memory Fragmentation
    
5. Memory Management in Operating Systems
    
6. RAII and Smart Pointers in C++