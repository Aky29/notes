# About

A **Hash Table** is a data structure that stores information in the form of key-value pairs. It uses a **Hash Function** to convert a key into an index, which determines where the corresponding value should be stored.

This process is called **Hashing**.

**Example :-** Suppose we want to store the marks of students using their roll numbers as keys.

|Key (Roll No.)|Value (Marks)|
|---|---|
|101|85|
|102|90|
|103|78|

Instead of searching through every record, a hash table calculates the position using the key.

## Basic Structure of Hash Table

A hash table consists of three major components:

1. **Key :-** Used to identify a particular record.
    
2. **Value :-** The actual data associated with the key.
    
3. **Hash Function :-** Converts the key into an index.
    

```
       KEY
        |
        v
  Hash Function
        |
        v
      INDEX
        |
        v
  +------------+
  | Hash Table |
  +------------+
  | 0 |        |
  | 1 | Data A |
  | 2 | Data B |
  | 3 |        |
  | 4 | Data C |
  +------------+
```

## 1. Hashing

**Hashing** is the process of converting a key into a numerical value or index using a hash function.

The generated value is used to determine where the data should be stored in the hash table.

**Example :-**

Suppose we have a hash table of size 10 and use the following hash function:

[  
h(key) = key \bmod 10  
]

For key `25`:

[  
h(25) = 25 \bmod 10 = 5  
]

Therefore, the data associated with key `25` will be stored at index `5`.

```
Index       Value
  0
  1
  2
  3
  4
  5         25
  6
  7
  8
  9
```

## 2. Hash Function

A **Hash Function** is a function that converts a key into an index within the range of the hash table.

[  
h(key) = index  
]

A good hash function should have the following properties:

- **Deterministic :-** The same key should always generate the same hash value.
    
- **Uniform Distribution :-** Keys should be distributed as evenly as possible.
    
- **Efficiency :-** It should calculate the hash value quickly.
    
- **Valid Index :-** The result should be within the valid table range.
    

### Types of Hash Functions

#### A. Division Method

Uses the remainder after dividing the key by the table size.

[  
h(key) = key \bmod m  
]

Where:

- `key` = Input key.
    
- `m` = Size of hash table.
    

Example:

[  
h(42) = 42 \bmod 10 = 2  
]

#### B. Multiplication Method

Multiplies the key by a constant and uses the fractional part to calculate the index.

[  
h(key) = \lfloor m \times (keyA \bmod 1) \rfloor  
]

Where:

- `m` = Table size.
    
- `A` = Constant between 0 and 1.
    
- `key` = Input key.
    

#### C. Mid-Square Method

- Square the given key.
    
- Extract the middle digits or bits.
    
- Use them as the hash value.
    

Example:

[  
key = 25  
]

[  
25^2 = 625  
]

The middle digit is `2`, which can be used as the hash value for a suitable table.

#### D. Folding Method

- Divide the key into smaller parts.
    
- Add those parts together.
    
- Use the result to calculate the index.
    

Example:

```
Key = 123456

12 + 34 + 56 = 102

Index = 102 % 10 = 2
```

#### E. Universal Hashing

Uses a hash function selected from a family of hash functions to reduce the probability of collisions for different key distributions.

## 3. Collision

A **Collision** occurs when two or more different keys generate the same hash table index.

Example:

Suppose:

[  
h(key) = key \bmod 10  
]

For keys `25` and `35`:

[  
h(25) = 5  
]

[  
h(35) = 5  
]

Both keys generate index `5`, resulting in a collision.

```
Key 25 ----\
            \
             > Hash Function ---> Index 5
            /
Key 35 ----/
```

Collision is a common problem in hash tables because the number of possible keys is generally much larger than the number of available table positions.

## 4. Collision Resolution Techniques

Collision resolution techniques are used to store multiple keys that generate the same index.

There are two major approaches:

### A. Separate Chaining

In separate chaining, every index of the hash table stores a linked list (or another collection) of elements.

If multiple keys generate the same index, they are stored in the same chain.

Example:

```
Index       Linked List

  0         NULL

  1         21 -> 31 -> NULL

  2         12 -> NULL

  3         13 -> 23 -> 33 -> NULL

  4         NULL
```

Here, keys `21` and `31` are stored at index `1` because they generate the same hash value.

**Advantages:**

- Simple collision handling.
    
- Multiple elements can be stored at the same index.
    
- Deletion is relatively straightforward.
    
- The load factor can be greater than 1.
    

**Disadvantages:**

- Requires extra memory for pointers.
    
- Dynamic memory allocation can introduce overhead.
    
- Poor hash distribution can create long chains.
    

### B. Open Addressing

In open addressing, all elements are stored directly inside the hash table itself.

When a collision occurs, the algorithm searches for another available position.

There are three major types:

#### 1. Linear Probing

In linear probing, if the calculated position is occupied, the next position is checked sequentially until an empty position is found.

Formula:

[  
h_i(key) = (h(key) + i) \bmod m  
]

Where:

- `h(key)` = Original hash index.
    
- `i` = Number of attempts.
    
- `m` = Table size.
    

Example:

Suppose the table size is 10 and the hash function is:

[  
h(key) = key \bmod 10  
]

Insert keys `25`, `35`, and `45`.

```
25 -> Index 5
35 -> Index 5 (Collision)
35 -> Index 6 (Next available)
45 -> Index 5 (Collision)
45 -> Index 7 (Next available)
```

Result:

```
Index       Value
  0
  1
  2
  3
  4
  5         25
  6         35
  7         45
  8
  9
```

**Disadvantage :-** Linear probing suffers from Primary Clustering, where consecutive occupied positions form long groups.

#### 2. Quadratic Probing

In quadratic probing, the interval between attempts increases quadratically.

Formula:

[  
h_i(key) = (h(key) + c_1i + c_2i^2) \bmod m  
]

Where:

- `h(key)` = Original hash index.
    
- `i` = Number of attempts.
    
- `c1`, `c2` = Constants.
    
- `m` = Table size.
    

For a simple example, use:

[  
h_i(key) = (h(key) + i^2) \bmod m  
]

The positions checked are:

```
Original Index = 5

Attempt 0: 5 + 0² = 5
Attempt 1: 5 + 1² = 6
Attempt 2: 5 + 2² = 9
Attempt 3: 5 + 3² = 14 % 10 = 4
```

**Advantages:**

- Reduces primary clustering.
    
- Spreads out collision attempts.
    

**Disadvantages:**

- Can suffer from Secondary Clustering.
    
- May not visit every table position, depending on the table size and constants.
    

#### 3. Double Hashing

Uses two different hash functions to calculate the next position.

Formula:

[  
h_i(key) = (h_1(key) + i \times h_2(key)) \bmod m  
]

Where:

- `h1(key)` = Primary hash function.
    
- `h2(key)` = Secondary hash function.
    
- `i` = Number of attempts.
    

Example:

[  
h_1(key) = key \bmod 10  
]

[  
h_2(key) = 7 - (key \bmod 7)  
]

The second hash function determines the step size.

**Advantages:**

- Reduces both primary and secondary clustering.
    
- Generally provides better distribution than linear and quadratic probing.
    

**Disadvantages:**

- Requires two hash functions.
    
- The secondary hash function must be chosen carefully.
    
- The step size must be relatively prime to the table size to guarantee that all positions can be visited.
    

## 5. Types of Hash Tables

Hash tables can be implemented using different collision-handling strategies and designs.

### A. Chained Hash Table

Uses separate chaining to store multiple elements at the same index.

### B. Open Addressing Hash Table

Stores all elements directly in the table and handles collisions through probing.

Its types include:

- Linear Probing
    
- Quadratic Probing
    
- Double Hashing
    

### C. Static Hash Table

Uses a fixed-size table that does not automatically resize.

### D. Dynamic Hash Table

Can grow or shrink its capacity when required.

Examples include dynamically resized hash tables and extensible hashing.

### E. Perfect Hashing

A hashing technique designed for a known, fixed set of keys in which no collisions occur.

It is especially useful for static sets of keys.

## 6. Load Factor

The **Load Factor** measures how full a hash table is.

It is calculated using:

[  
\alpha = \frac{n}{m}  
]

Where:

- `n` = Number of stored elements.
    
- `m` = Number of slots in the hash table.
    

Example:

If a hash table has 10 slots and contains 7 elements:

[  
\alpha = \frac{7}{10} = 0.7  
]

This means 70% of the table's slots are occupied.

NOTE :-

- In separate chaining, the load factor can be greater than 1.
    
- In open addressing, the load factor must remain below 1.
    
- A higher load factor generally increases collision frequency and can reduce performance.
    

## 7. Rehashing

**Rehashing** is the process of creating a new, usually larger hash table and inserting all existing elements into it again using the new table size.

It is performed when the load factor reaches a predefined threshold.

Steps:

1. Create a larger hash table.
    
2. Recalculate the hash index for every existing key.
    
3. Insert all elements into the new table.
    
4. Replace the old table with the new one.
    

Example:

```
Old Table (Size = 5)

[10] [ ] [22] [ ] [15]

          |
          v

New Table (Size = 10)

[ ] [10] [ ] [22] [ ] [15] [ ] [ ] [ ] [ ]
```

NOTE :- Rehashing is expensive because all existing elements must be processed again. However, it helps maintain efficient average performance.

## 8. Clustering

Clustering occurs when several occupied positions become grouped together in a hash table.

### A. Primary Clustering

Occurs in linear probing when consecutive occupied positions form groups.

### B. Secondary Clustering

Occurs when keys with the same initial hash value follow the same probing sequence.

Double hashing helps reduce both types of clustering.

## 9. Deletion in Hash Tables

Deletion depends on the collision resolution technique.

### A. Deletion in Separate Chaining

The required node is removed from its linked list.

### B. Deletion in Open Addressing

Simply making a deleted position empty can break the search sequence.

Therefore, a special marker called a **Tombstone** or **Deleted Marker** is used.

```
Before Deletion:

Index       Value
  5          25
  6          35
  7          45

After Deleting 35:

Index       Value
  5          25
  6       DELETED
  7          45
```

A search for `45` must continue past index `6` rather than treating it as an empty slot.

## 10. Time Complexity of Hash Table

|Operation|Average Case|Worst Case|
|---|---|---|
|Insertion|O(1)|O(n)|
|Searching|O(1)|O(n)|
|Deletion|O(1)|O(n)|
|Access by key|O(1)|O(n)|

NOTE :- Average O(1) performance depends on a good hash function, controlled load factor, and suitable collision handling. Worst-case O(n) can occur when many keys collide.

Rehashing can take O(n) time for one resize operation, although insertion is generally amortized O(1) in a well-designed dynamically resized table.

## 11. Implementation of Hash Table in C++

We can implement a simple hash table using separate chaining and a vector of linked lists.

```
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    static const int SIZE = 10;

    vector<list<pair<int, int>>> table;

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashTable() : table(SIZE) {}

    void insert(int key, int value) {
        int index = hashFunction(key);

        for (auto& item : table[index]) {
            if (item.first == key) {
                item.second = value;
                return;
            }
        }

        table[index].push_back({key, value});
    }

    void search(int key) {
        int index = hashFunction(key);

        for (auto item : table[index]) {
            if (item.first == key) {
                cout << "Value: " << item.second << endl;
                return;
            }
        }

        cout << "Key not found\n";
    }

    void remove(int key) {
        int index = hashFunction(key);

        for (auto it = table[index].begin();
             it != table[index].end(); it++) {

            if (it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(101, 85);
    ht.insert(102, 90);
    ht.insert(103, 78);

    ht.search(102);

    ht.remove(102);

    ht.search(102);

    return 0;
}
```

NOTE :- This is a basic educational implementation. It uses a fixed number of buckets and does not implement automatic rehashing.

## 12. Hash Table in C++ STL

C++ provides hash-table-based containers through the Standard Template Library.

### A. unordered_map

Stores unique keys with associated values.

```
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> mp;

    mp[101] = "Anish";
    mp[102] = "Rahul";
    mp[103] = "Aman";

    cout << mp[101] << endl;

    mp.erase(102);

    if (mp.find(103) != mp.end()) {
        cout << "Key found";
    }

    return 0;
}
```

### B. unordered_set

Stores unique elements without associated values.

```
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);

    cout << s.count(20);

    s.erase(20);

    return 0;
}
```

### C. unordered_multimap

Stores multiple values associated with the same key.

### D. unordered_multiset

Allows duplicate elements.

## 13. Hash Table vs Hash Map vs Hash Set

|Structure|Description|
|---|---|
|Hash Table|General data structure using hashing|
|Hash Map|Stores key-value pairs|
|Hash Set|Stores unique values|
|Multi Map|Allows multiple values for the same key|
|Multi Set|Allows duplicate values|

NOTE :- In C++, `unordered_map` and `unordered_set` are common hash-table-based containers.

## 14. Applications of Hash Tables

1. **Database Indexing :-** Helps retrieve records using keys.
    
2. **Caching :-** Stores frequently accessed information.
    
3. **Compiler Design :-** Symbol tables store variable and function information.
    
4. **Password Verification :-** Hash functions are used in secure password storage systems.
    
5. **Duplicate Detection :-** Identifies repeated elements efficiently.
    
6. **Frequency Counting :-** Counts occurrences of elements.
    
7. **Dictionaries :-** Maps words to their meanings.
    
8. **Sets :-** Maintains unique elements.
    
9. **Memoization :-** Stores previously calculated results.
    
10. **Routing and Lookup :-** Helps retrieve information using identifiers.
    

## 15. Important Terms

|Term|Meaning|
|---|---|
|Hashing|Converting a key into a hash value|
|Hash Function|Function used to calculate the hash value|
|Hash Table|Data structure that stores elements using hashing|
|Key|Identifier used to access a value|
|Value|Data associated with a key|
|Collision|Two or more keys generating the same index|
|Chaining|Storing collided elements in a collection at the same index|
|Probing|Searching for another available position|
|Linear Probing|Checking consecutive positions|
|Quadratic Probing|Checking positions using quadratic intervals|
|Double Hashing|Using two hash functions|
|Load Factor|Ratio of stored elements to table capacity|
|Rehashing|Rebuilding the table and reinserting elements|
|Clustering|Grouping of occupied positions|
|Tombstone|Marker used for deleted entries in open addressing|
|Bucket|A storage position in a hash table|

## NOTE :-

- Hash tables use hash functions to calculate storage positions.
    
- Collisions occur when different keys generate the same index.
    
- Separate chaining and open addressing are the two major collision resolution approaches.
    
- Linear probing, quadratic probing, and double hashing are types of open addressing.
    
- Load factor affects the performance of a hash table.
    
- Rehashing helps maintain efficient performance as the number of elements increases.
    
- Hash table operations generally take O(1) average time, but can take O(n) in the worst case.
    
- Hash tables do not generally maintain elements in sorted order.
    
- A hash table is not the same as a cryptographic hash function, although both use hashing concepts.
    

## Next Topics

1. Hash Function Design
    
2. Collision Resolution in Detail
    
3. Linear Probing Implementation
    
4. Quadratic Probing Implementation
    
5. Double Hashing Implementation
    
6. Rehashing and Dynamic Resizing
    
7. unordered_map and unordered_set
    
8. Hashing Problems on LeetCode
    
9. Hash Tables vs Trees