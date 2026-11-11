# About

**Bit Manipulation** is a technique used to perform operations directly on the individual bits of a number.

Computers represent integers internally using binary numbers (0s and 1s).

Bit Manipulation allows us to work with these binary representations using special operators called **Bitwise Operators**.

For example:

```
Decimal:  10
Binary:   1010

Decimal:  6
Binary:   0110
```

Bit Manipulation can perform operations such as:

- Checking whether a number is odd or even.
    
- Multiplying or dividing by powers of 2.
    
- Setting or clearing individual bits.
    
- Checking whether a number is a power of 2.
    
- Counting the number of set bits.
    
- Generating subsets using bitmasks.
    
- Solving competitive programming problems efficiently.
    

---

# Binary Number System

A binary number is a number represented using only two digits:

```
0 and 1
```

Each binary position represents a power of 2.

Example:

```
Binary:  1  0  1  1  0

Position 4  3  2  1  0
Value    16 8  4  2  1
```

To convert binary to decimal:

[  
(1 \times 16)+(0 \times 8)+(1 \times 4)+(1 \times 2)+(0 \times 1)  
]

[  
16+4+2=22  
]

Therefore:

```
10110 = 22
```

## Binary Representation of Common Numbers

|Decimal|Binary|
|---|---|
|0|0000|
|1|0001|
|2|0010|
|3|0011|
|4|0100|
|5|0101|
|6|0110|
|7|0111|
|8|1000|
|9|1001|
|10|1010|
|15|1111|

NOTE :- Leading zeros do not change the value of a binary number.

---

# Bits and Bytes

A **Bit** is the smallest unit of information in a computer.

It can have only two values:

```
0 or 1
```

A **Byte** consists of 8 bits.

```
1 Byte = 8 Bits
```

Common terminology:

|Unit|Size|
|---|---|
|Bit|1 binary digit|
|Nibble|4 bits|
|Byte|8 bits|
|Kilobyte (KB)|1024 bytes (binary convention)|
|Megabyte (MB)|1024 KB|
|Gigabyte (GB)|1024 MB|

---

# Bitwise Operators

Bitwise operators perform operations on individual bits of integers.

C++ provides the following bitwise operators:

|Operator|Name|Operation|
|---|---|---|
|`&`|AND|Both bits must be 1|
|`\|`|OR|At least one bit must be 1|
|`^`|XOR|Bits must be different|
|`~`|NOT|Inverts all bits|
|`<<`|Left Shift|Shifts bits left|
|`>>`|Right Shift|Shifts bits right|

---

# 1. Bitwise AND (&)

AND returns 1 only when both corresponding bits are 1.

### Truth Table

|A|B|A & B|
|---|---|---|
|0|0|0|
|0|1|0|
|1|0|0|
|1|1|1|

### Example

```
A = 10 = 1010
B =  6 = 0110

       1010
     & 0110
     -------
       0010
```

Result:

```
0010 = 2
```

C++:

```
int a = 10, b = 6;

cout << (a & b);  // 2
```

### Applications

- Checking whether a particular bit is set.
    
- Clearing a bit using a mask.
    
- Checking odd or even numbers.
    
- Extracting selected bits.
    

---

# 2. Bitwise OR (|)

OR returns 1 if at least one corresponding bit is 1.

### Truth Table

|A|B|A \| B|
|---|---|---|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|1|

### Example

```
A = 10 = 1010
B =  6 = 0110

       1010
     | 0110
     -------
       1110
```

Result:

```
1110 = 14
```

C++:

```
int a = 10, b = 6;

cout << (a | b);  // 14
```

### Applications

- Setting specific bits.
    
- Combining bit flags.
    
- Creating bitmasks.
    

---

# 3. Bitwise XOR (^)

XOR stands for Exclusive OR.

It returns 1 when the two corresponding bits are different.

### Truth Table

|A|B|A ^ B|
|---|---|---|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|0|

### Example

```
A = 10 = 1010
B =  6 = 0110

       1010
     ^ 0110
     -------
       1100
```

Result:

```
1100 = 12
```

C++:

```
int a = 10, b = 6;

cout << (a ^ b);  // 12
```

### Important XOR Properties

```
A ^ 0 = A

A ^ A = 0

A ^ B = B ^ A

(A ^ B) ^ C = A ^ (B ^ C)
```

These properties make XOR useful in many DSA problems.

### Applications

1. Finding the unique element when every other element appears twice.
    
2. Finding missing numbers.
    
3. Detecting differences between binary representations.
    
4. Bit manipulation problems.
    

Example: Find the element that appears only once.

```
int arr[] = {2, 3, 5, 3, 2};

int ans = 0;

for (int x : arr) {
    ans ^= x;
}

cout << ans;  // 5
```

Explanation:

```
2 ^ 3 ^ 5 ^ 3 ^ 2

(2 ^ 2) ^ (3 ^ 3) ^ 5

0 ^ 0 ^ 5

= 5
```

---

# 4. Bitwise NOT (~)

NOT inverts every bit.

```
0 becomes 1
1 becomes 0
```

### Example

For an 8-bit representation:

```
A = 00001010

~A = 11110101
```

C++:

```
int a = 10;

cout << ~a;  // -11
```

NOTE :- In C++, `int` is generally 32 bits on modern platforms. The NOT operator inverts all bits of the integer representation, not just the displayed binary digits.

For signed integers, the result is governed by the integer representation and C++ language rules. In ordinary modern C++ implementations:

[  
\sim x = -x-1  
]

Therefore:

```
~10 = -11
~5  = -6
~0  = -1
```

### Applications

- Inverting bits.
    
- Clearing selected bits using masks.
    
- Working with bitwise complements.
    

---

# 5. Left Shift (<<)

Left Shift moves bits towards the left by a specified number of positions.

Syntax:

```
a << n
```

Here, `n` represents the number of positions to shift.

### Example

```
A = 5

Binary = 00000101

A << 1

        00000101
        00001010

Result = 10
```

Another example:

```
5 << 2

00000101
00010100

Result = 20
```

For non-negative values where the result is representable:

[  
a << n = a \times 2^n  
]

### Applications

- Multiplication by powers of 2.
    
- Creating bitmasks.
    
- Setting specific bits.
    

NOTE :- Shifting by a negative amount or by an amount greater than or equal to the bit width of the promoted left operand is undefined behaviour in C++. Do not assume left shift is always safe for signed integers.

---

# 6. Right Shift (>>)

Right Shift moves bits towards the right by a specified number of positions.

Syntax:

```
a >> n
```

### Example

```
A = 20

Binary = 00010100

A >> 1

        00010100
        00001010

Result = 10
```

Another example:

```
20 >> 2

00010100
00000101

Result = 5
```

For non-negative integers:

[  
a >> n = \left\lfloor \frac{a}{2^n} \right\rfloor  
]

### Applications

- Division by powers of 2.
    
- Extracting bits.
    
- Processing binary representations.
    

NOTE :- Right shifting a negative signed integer has implementation-defined behaviour in C++. For predictable bit manipulation, prefer unsigned integer types.

---

# Bit Position

Bit positions are counted from right to left, starting from zero.

Example:

```
Binary = 10110

Position = 4 3 2 1 0
Bit      = 1 0 1 1 0
```

The rightmost bit is called the Least Significant Bit (LSB).

The leftmost bit is called the Most Significant Bit (MSB).

|Term|Meaning|
|---|---|
|LSB|Least Significant Bit|
|MSB|Most Significant Bit|
|Set Bit|A bit whose value is 1|
|Unset Bit|A bit whose value is 0|
|Bitmask|A binary pattern used to select or modify bits|

---

# Common Bit Manipulation Techniques

These are some of the most important operations used in competitive programming.

## 1. Check Whether a Bit Is Set

To check whether the bit at position `i` is set:

```
if (n & (1 << i)) {
    cout << "Set";
}
else {
    cout << "Not Set";
}
```

Example:

```
n = 10

Binary = 1010

Check bit at position 1:

  1010
& 0010
------
  0010
```

Result is non-zero, so the bit is set.

General formula:

[  
n \ & \ (1 << i)  
]

NOTE :- For generic C++ code, use `1ULL << i` with an appropriate unsigned integer type and ensure the shift is within its width.

## 2. Set a Bit

Setting a bit means changing it to 1.

Formula:

[  
n = n \ | \ (1 << i)  
]

C++:

```
n |= (1 << i);
```

Example:

```
n = 8

Binary = 1000

Set bit at position 1:

  1000
| 0010
------
  1010
```

Result:

```
1010 = 10
```

## 3. Clear a Bit

Clearing a bit means changing it to 0.

Formula:

[  
n = n \ & \ \sim(1 << i)  
]

C++:

```
n &= ~(1 << i);
```

Example:

```
n = 10

Binary = 1010

Clear bit at position 1:

  1010
& 1101
------
  1000
```

Result:

```
1000 = 8
```

## 4. Toggle a Bit

Toggling means:

```
0 becomes 1
1 becomes 0
```

Formula:

[  
n = n \oplus (1 << i)  
]

C++:

```
n ^= (1 << i);
```

Example:

```
n = 10

Binary = 1010

Toggle bit at position 1:

  1010
^ 0010
------
  1000
```

Result:

```
1000 = 8
```

## Summary of Bit Operations

|Operation|Formula|
|---|---|
|Check bit|`n & (1 << i)`|
|Set bit|`n \| (1 << i)`|
|Clear bit|`n & ~(1 << i)`|
|Toggle bit|`n ^ (1 << i)`|

---

# Important Bit Tricks

## 1. Check Odd or Even

The last bit determines whether an integer is odd or even.

```
Even number -> Last bit is 0
Odd number  -> Last bit is 1
```

Formula:

```
if (n & 1)
    cout << "Odd";
else
    cout << "Even";
```

## 2. Multiply by a Power of 2

```
n << k
```

For a safe, representable non-negative result:

[  
n \times 2^k  
]

Example:

```
int n = 5;

cout << (n << 3);  // 40
```

## 3. Divide by a Power of 2

For non-negative integers:

```
n >> k
```

Example:

```
int n = 40;

cout << (n >> 3);  // 5
```

## 4. Check Whether a Number Is a Power of 2

A positive power of 2 has exactly one set bit.

Examples:

```
1  = 0001
2  = 0010
4  = 0100
8  = 1000
16 = 10000
```

A useful property is:

[  
n \ & \ (n-1) = 0  
]

For a positive power of 2.

C++:

```
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

Why does it work?

Example:

```
n     = 8 = 1000
n - 1 = 7 = 0111

       1000
     & 0111
     ------
       0000
```

## 5. Remove the Rightmost Set Bit

Formula:

[  
n = n \ & \ (n-1)  
]

This changes the rightmost set bit to zero.

Example:

```
n = 12 = 1100

n - 1 = 11 = 1011

       1100
     & 1011
     ------
       1000
```

Result:

```
1000 = 8
```

## 6. Isolate the Rightmost Set Bit

Formula:

[  
n \ & \ (-n)  
]

Example:

```
n = 12 = 1100

-n = two's complement representation

n & -n = 0100
```

Result:

```
0100 = 4
```

This technique is commonly used in Fenwick Trees.

## 7. Count Set Bits

A set bit is a bit with value 1.

Example:

```
n = 13

Binary = 1101

Set bits = 3
```

### Method 1: Built-in Function

```
int n = 13;

cout << __builtin_popcount(n);
```

For an unsigned long long:

```
cout << __builtin_popcountll(n);
```

### Method 2: Brian Kernighan's Algorithm

Repeatedly remove the rightmost set bit.

```
int countSetBits(int n) {

    int count = 0;

    while (n) {
        n &= (n - 1);
        count++;
    }

    return count;
}
```

Time Complexity: O(k), where k is the number of set bits.

## 8. Check Whether Two Numbers Have Opposite Signs

For fixed-width signed integer representations using the usual two's complement model:

```
bool oppositeSigns(int a, int b) {
    return (a ^ b) < 0;
}
```

If the sign bits differ, the XOR result has its sign bit set.

NOTE :- This is a specialised signed-integer trick. Do not use it as a replacement for careful overflow-safe arithmetic in general code.

---

# Bitmasking

Bitmasking is a technique that uses bits to represent a collection of boolean states or choices.

Each bit represents whether an element or condition is selected.

Example:

Suppose we have four elements:

```
A, B, C, D
```

A mask can represent which elements are selected.

```
Mask = 0101
```

This means:

```
A = Selected
B = Not Selected
C = Selected
D = Not Selected
```

Depending on the convention, the rightmost bit represents the first element.

## Generating All Subsets Using Bitmasks

For a collection of `n` elements, there are:

[  
2^n  
]

possible subsets.

Each subset can be represented by a binary mask from:

```
0 to (1 << n) - 1
```

Example:

```
Elements = {A, B, C}
```

All possible masks:

|Mask|Binary|Subset|
|---|---|---|
|0|000|{}|
|1|001|{A}|
|2|010|{B}|
|3|011|{A, B}|
|4|100|{C}|
|5|101|{A, C}|
|6|110|{B, C}|
|7|111|{A, B, C}|

### C++ Implementation

```
int arr[] = {10, 20, 30};

int n = 3;

for (int mask = 0; mask < (1 << n); mask++) {

    for (int i = 0; i < n; i++) {

        if (mask & (1 << i)) {
            cout << arr[i] << " ";
        }
    }

    cout << endl;
}
```

Time Complexity:

[  
O(n \times 2^n)  
]

Space Complexity: O(1) auxiliary space, excluding the input array.

NOTE :- Bitmasking is especially useful when the number of elements is small, because the number of subsets grows exponentially.

---

# Two's Complement

Two's Complement is the common method used to represent signed integers in binary.

It allows computers to represent positive and negative integers.

To find the two's complement of a positive binary number:

1. Invert all bits.
    
2. Add 1.
    

Example: Represent -5 using 8 bits.

```
 5 = 00000101

Invert:

    11111010

Add 1:

    11111011
```

Therefore:

```
-5 = 11111011
```

For an 8-bit signed integer:

|Type|Range|
|---|---|
|Signed 8-bit|-128 to 127|
|Unsigned 8-bit|0 to 255|

For an unsigned integer with `w` bits, the range is:

[  
0 \text{ to } 2^w-1  
]

For a signed two's-complement integer with `w` bits:

[  
-2^{w-1} \text{ to } 2^{w-1}-1  
]

---

# XOR-Based Problems

XOR is especially important in DSA.

## 1. Find the Unique Element

Given an array where every element appears twice except one, find the unique element.

```
int singleNumber(vector<int>& nums) {

    int ans = 0;

    for (int x : nums) {
        ans ^= x;
    }

    return ans;
}
```

Time Complexity: O(n)

Space Complexity: O(1)

## 2. Find the Missing Number

Given an array containing distinct numbers from 0 to n, with one number missing:

```
int missingNumber(vector<int>& nums) {

    int ans = nums.size();

    for (int i = 0; i < nums.size(); i++) {
        ans ^= i;
        ans ^= nums[i];
    }

    return ans;
}
```

Time Complexity: O(n)

Space Complexity: O(1)

## 3. Swap Two Numbers Using XOR

```
a ^= b;
b ^= a;
a ^= b;
```

This swaps the values without a temporary variable.

NOTE :- This is mainly a demonstration of XOR properties. In normal C++ code, use `swap(a, b)` because it is clearer and avoids problems when both references refer to the same variable.

---

# Standard Library Bit Operations in C++

C++ provides useful functions in the `<bit>` header (C++20 and later).

```
#include <bit>
```

|Function|Purpose|
|---|---|
|`std::popcount(x)`|Counts set bits|
|`std::countl_zero(x)`|Counts leading zeros|
|`std::countr_zero(x)`|Counts trailing zeros|
|`std::has_single_bit(x)`|Checks whether an unsigned integer has exactly one set bit|
|`std::bit_width(x)`|Returns the number of bits needed to represent the value|

Example:

```
#include <iostream>
#include <bit>
using namespace std;

int main() {

    unsigned int n = 13;

    cout << popcount(n) << endl;
    cout << has_single_bit(n) << endl;
    cout << countr_zero(n) << endl;
}
```

Output:

```
3
0
0
```

NOTE :- These functions operate on unsigned integer types. Some functions have specific behaviour for zero, so check their requirements before using them.

---

# Complexity Analysis

|Operation|Time Complexity|
|---|---|
|AND, OR, XOR, NOT|O(1)|
|Left Shift|O(1)|
|Right Shift|O(1)|
|Check a bit|O(1)|
|Set a bit|O(1)|
|Clear a bit|O(1)|
|Toggle a bit|O(1)|
|Count set bits using loop|O(w) worst case|
|Brian Kernighan's Algorithm|O(k)|
|Generate all subsets|O(n × 2^n)|

Where:

- `w` = Number of bits in the integer type.
    
- `k` = Number of set bits.
    
- `n` = Number of elements.
    

---

# Applications of Bit Manipulation

1. **Competitive Programming** :- Efficiently solving problems involving binary representations.
    
2. **Operating Systems** :- Managing permissions, flags and status information.
    
3. **Networking** :- Working with IP addresses, masks and protocols.
    
4. **Cryptography** :- XOR and other bitwise operations are used in cryptographic algorithms.
    
5. **Compression** :- Storing and processing information at the bit level.
    
6. **Subset Generation** :- Representing selected elements using bitmasks.
    
7. **Dynamic Programming** :- Bitmask DP for problems involving small sets.
    
8. **Fenwick Tree** :- Uses the rightmost set bit to navigate indices.
    

---

# Important Terms

|Term|Meaning|
|---|---|
|Bit|Smallest unit of binary information|
|Byte|Group of 8 bits|
|LSB|Least Significant Bit|
|MSB|Most Significant Bit|
|Set Bit|Bit with value 1|
|Unset Bit|Bit with value 0|
|Bitwise AND|Returns 1 when both bits are 1|
|Bitwise OR|Returns 1 when at least one bit is 1|
|XOR|Returns 1 when bits are different|
|NOT|Inverts bits|
|Left Shift|Moves bits towards the left|
|Right Shift|Moves bits towards the right|
|Bitmask|Binary pattern used to select or modify bits|
|Bitmasking|Technique for representing states using bits|
|Two's Complement|Common signed integer representation|
|Set Bit Count|Number of bits equal to 1|
|Path Compression|Not a bit operation; an optimisation in DSU|

---

# Important Notes

1. Computers represent integers using binary.
    
2. One byte consists of 8 bits.
    
3. Bit positions start from zero at the rightmost bit.
    
4. AND checks whether corresponding bits are both 1.
    
5. OR sets a bit if either corresponding bit is 1.
    
6. XOR returns 1 when corresponding bits differ.
    
7. NOT inverts every bit.
    
8. Left shift moves bits towards the left.
    
9. Right shift moves bits towards the right.
    
10. `n & 1` checks whether a non-negative integer is odd.
    
11. `n & (n - 1)` removes the rightmost set bit for positive integers.
    
12. `n & -n` isolates the rightmost set bit for suitable integer representations.
    
13. `n & (n - 1) == 0` checks for powers of two when combined with `n > 0`.
    
14. XOR can find a unique element when all other elements appear exactly twice.
    
15. Bitmasking can represent subsets using binary numbers.
    
16. An array of n elements has (2^n) possible subsets.
    
17. Be careful with signed integers, overflow and invalid shift amounts in C++.
    
18. Prefer unsigned integer types for low-level bit manipulation.
    

---

# Next Topics

1. Number Theory
    
2. Recursion
    
3. Backtracking
    
4. Greedy Algorithms
    
5. Dynamic Programming
    
6. String Algorithms
    
7. Advanced Graph Algorithms
    

**Practice Problems:**

- Check if a number is odd or even.
    
- Check if the i-th bit is set.
    
- Set the i-th bit.
    
- Clear the i-th bit.
    
- Toggle the i-th bit.
    
- Count set bits.
    
- Check whether a number is a power of two.
    
- Find the single number in an array.
    
- Find the missing number.
    
- Find two unique numbers in an array where all other numbers appear twice.
    
- Generate all subsets using bitmasks.
    
- Find the XOR of numbers from 1 to n.
    
- Count the number of bits needed to represent a number.