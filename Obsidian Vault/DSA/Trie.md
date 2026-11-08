# About

A **Trie** (pronounced as "try") is a special type of tree-based data structure used to store and search strings efficiently.

It is also called a **Prefix Tree** because it stores strings by sharing their common prefixes.

Unlike a Binary Search Tree, where nodes generally store complete values, a Trie stores characters along paths from the root.

Each path from the root represents a sequence of characters, and a special marker indicates whether that sequence forms a complete word.

Tries are commonly used in:

- Autocomplete systems
    
- Search engines
    
- Spell checkers
    
- Dictionary applications
    
- IP routing
    
- Word games
    

## Structure of a Trie

Consider the following words:

```
car
cat
care
dog
```

Their Trie representation:

```
              Root
             /    \
            c      d
            |      |
            a      o
           / \     |
          r   t    g*
          |
          e*
```

Here:

- Each node represents a character.
    
- The root represents an empty string.
    
- Common prefixes share the same path.
    
- The `*` indicates the end of a complete word.
    

NOTE :- The path `c → a → r` represents both `car` and the prefix of `care`. The end-of-word marker distinguishes whether a path is a complete word.

---

# Terminologies Used in Trie

## 1. Root Node

The topmost node of a Trie.

It does not represent any character and acts as the starting point for all strings.

## 2. Trie Node

A Trie Node represents a single character and stores references to its child nodes.

## 3. Prefix

A prefix is a sequence of characters that appears at the beginning of a word.

Example:

For the word `computer`:

```
c
co
com
comp
compu
comput
compute
computer
```

All these are prefixes of `computer`.

## 4. End of Word

A boolean marker used to indicate that a particular sequence of characters forms a complete word.

A Trie node can represent the end of one word and still have children.

Example:

```
car
care
```

The node representing `r` marks the end of `car`, but it also has a child `e`.

## 5. Child Node

A node directly connected below another node.

## 6. Branch

A path that represents a sequence of characters in the Trie.

## 7. Common Prefix

A prefix shared by two or more strings.

Example:

```
car
cat
```

Their common prefixes are:

```
c
ca
```

## 8. Terminal Node

A node marked as the end of a complete word.

## 9. Path

A sequence of connected nodes from the root to another node.

---

# Types of Trie

There are different variations of Tries designed to improve memory usage and searching performance.

## 1. Standard Trie

A Standard Trie stores strings character by character.

Each node contains references to its possible children and an end-of-word marker.

Example:

```
Words: app, apple, bat

             Root
            /    \
           a      b
           |      |
           p      a
           |      |
           p*     t*
           |
           l
           |
           e*
```

Properties:

- Stores each character as a node.
    
- Shares common prefixes.
    
- Supports efficient prefix searching.
    
- Can use considerable memory if many child pointers are allocated.
    

## 2. Compressed Trie (Radix Trie)

A Compressed Trie reduces the number of nodes by combining chains of nodes that have only one child.

Instead of storing each character separately, it stores sequences of characters in a single edge.

Example:

Standard Trie:

```
Root
 |
 c
 |
 o
 |
 m
 |
 p
 |
 u
 |
 t
 |
 e
 |
 r
```

Compressed Trie:

```
Root
 |
 "computer"
```

Properties:

- Reduces the number of nodes.
    
- Reduces pointer overhead.
    
- Stores common prefixes.
    
- Useful when strings have long shared paths.
    

## 3. Ternary Search Trie (TST)

A Ternary Search Trie is a Trie variation in which each node has at most three children:

1. Left
    
2. Equal
    
3. Right
    

Each node stores a character.

- Left: Stores characters smaller than the current character.
    
- Equal: Stores the next character in the string.
    
- Right: Stores characters greater than the current character.
    

It combines characteristics of a Trie and a Binary Search Tree.

Properties:

- Uses fewer child pointers than a standard array-based Trie.
    
- Supports prefix searching.
    
- Can be more memory-efficient for some character sets.
    

## 4. Suffix Trie

A Suffix Trie stores all suffixes of a given string.

A suffix is a substring that starts at some position and continues until the end of the string.

Example:

For the string:

```
banana
```

Its suffixes are:

```
banana
anana
nana
ana
na
a
```

A Suffix Trie stores these suffixes to support substring-related searches.

Properties:

- Useful for substring searching.
    
- Can answer certain pattern queries efficiently.
    
- Requires considerable memory in its basic form.
    

NOTE :- A Suffix Tree is a compressed representation of a Suffix Trie. They are related but are not the same data structure.

---

# Trie Operations

A Trie supports several operations for managing strings.

## 1. Insertion

Insertion adds a new word to the Trie.

Steps:

1. Start from the root.
    
2. Read the first character of the word.
    
3. Check whether a child node for that character exists.
    
4. If it does not exist, create a new node.
    
5. Move to the child node.
    
6. Repeat for every character.
    
7. Mark the final node as the end of a complete word.
    

Example:

Insert:

```
cat
```

Initial Trie:

```
Root
```

After insertion:

```
Root
 |
 c
 |
 a
 |
 t*
```

C++ Implementation:

```
void insert(string word) {
    Node* current = root;

    for (char ch : word) {
        int index = ch - 'a';

        if (current->children[index] == nullptr) {
            current->children[index] = new Node();
        }

        current = current->children[index];
    }

    current->isEnd = true;
}
```

Time Complexity: O(L)

Where L is the length of the word.

## 2. Searching

Searching checks whether a complete word exists in the Trie.

Steps:

1. Start from the root.
    
2. Read each character of the word.
    
3. Move to the corresponding child node.
    
4. If a required child does not exist, the word is not present.
    
5. After processing all characters, check the end-of-word marker.
    

C++ Implementation:

```
bool search(string word) {
    Node* current = root;

    for (char ch : word) {
        int index = ch - 'a';

        if (current->children[index] == nullptr) {
            return false;
        }

        current = current->children[index];
    }

    return current->isEnd;
}
```

Time Complexity: O(L)

NOTE :- Reaching the final node does not automatically mean the word exists. Its `isEnd` value must be true.

## 3. Prefix Search

Prefix search checks whether at least one word in the Trie starts with a given prefix.

Unlike normal searching, it does not require the final node to be marked as the end of a word.

Example:

Stored words:

```
apple
application
apply
banana
```

Search prefix:

```
app
```

Result:

```
true
```

C++ Implementation:

```
bool startsWith(string prefix) {
    Node* current = root;

    for (char ch : prefix) {
        int index = ch - 'a';

        if (current->children[index] == nullptr) {
            return false;
        }

        current = current->children[index];
    }

    return true;
}
```

Time Complexity: O(L)

## 4. Deletion

Deletion removes a word from the Trie.

Unlike a normal tree, deleting a word from a Trie requires checking whether its nodes are shared with other words.

Steps:

1. Search for the complete word.
    
2. Check whether its final node marks the end of a word.
    
3. Remove the end-of-word marker.
    
4. Delete nodes that are no longer required by any other word.
    
5. Preserve nodes that are part of another word or prefix.
    

Example:

Stored words:

```
car
care
cat
```

Delete:

```
care
```

The path for `car` must remain because it represents another complete word.

The path for `cat` must also remain because it is a different word.

Time Complexity: O(L)

---

# C++ Implementation of Trie

This implementation supports:

- Insertion
    
- Searching
    
- Prefix searching
    
- Deletion
    

It uses an array of 26 child pointers, assuming lowercase English letters.

```
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;

    bool remove(TrieNode* node, string& word, int depth) {
        if (depth == word.size()) {
            if (!node->isEnd)
                return false;

            node->isEnd = false;
        }
        else {
            int index = word[depth] - 'a';

            if (node->children[index] == nullptr)
                return false;

            bool shouldDelete = remove(
                node->children[index], word, depth + 1
            );

            if (shouldDelete) {
                delete node->children[index];
                node->children[index] = nullptr;
            }
        }

        if (node->isEnd)
            return false;

        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr)
                return false;
        }

        return true;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
        }

        current->isEnd = true;
    }

    bool search(string word) {
        TrieNode* current = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (current->children[index] == nullptr)
                return false;

            current = current->children[index];
        }

        return current->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* current = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (current->children[index] == nullptr)
                return false;

            current = current->children[index];
        }

        return true;
    }

    void deleteWord(string word) {
        remove(root, word, 0);
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");

    cout << trie.search("app") << endl;
    cout << trie.search("appl") << endl;

    cout << trie.startsWith("appl") << endl;

    trie.deleteWord("app");

    cout << trie.search("app") << endl;
    cout << trie.search("apple") << endl;
}
```

Output:

```
1
0
1
0
1
```

NOTE :- This implementation accepts only lowercase English letters (`a` to `z`). It also assumes that the Trie object is not copied and that the input contains no invalid characters. A production implementation should also manage the remaining allocated nodes when the Trie is destroyed.

---

# Autocomplete

Autocomplete is a feature that suggests possible words or phrases based on the prefix entered by a user.

A Trie is particularly useful for implementing autocomplete because it stores words according to their prefixes.

Example:

Stored words:

```
apple
application
apply
app
banana
```

User enters:

```
app
```

Possible suggestions:

```
app
apple
application
apply
```

### Working

1. Search for the given prefix.
    
2. Move to the Trie node representing the end of the prefix.
    
3. Traverse all descendants of that node.
    
4. Collect words marked as complete words.
    
5. Return the collected words as suggestions.
    

The time complexity depends on the prefix length and the number of results returned.

If the prefix length is P and K results are collected, a basic traversal takes O(P + S), where S is the number of Trie nodes explored. Writing the returned strings also takes time proportional to their total output length.

---

# Trie Complexity

Let:

- `L` = Length of the word or prefix.
    
- `N` = Number of words.
    
- `Σ` = Size of the character set (alphabet).
    

|Operation|Time Complexity|
|---|---|
|Insertion|O(L)|
|Searching|O(L)|
|Prefix Search|O(L)|
|Deletion|O(L)|
|Autocomplete|Depends on prefix and results|
|Space|O(N × L × Σ) upper bound for a basic fixed-array Trie|

NOTE :- The actual space usage depends on shared prefixes, the number of allocated child pointers and the character representation. A Trie does not necessarily allocate a separate complete path for every word.

---

# Trie vs Hash Table vs Binary Search Tree

|Feature|Trie|Hash Table|BST|
|---|---|---|---|
|Main Purpose|String and prefix searching|Key-value lookup|Ordered searching|
|Exact Search|O(L)|Average O(1) for suitable hashing|O(log N) if balanced|
|Prefix Search|Efficient|Not naturally supported|Possible with additional traversal|
|Ordering|Lexicographical traversal possible|No guaranteed order|Maintains key order|
|Memory|Can be high|Depends on implementation|Depends on number of nodes|
|Common Usage|Autocomplete|Fast lookup|Ordered data|

---

# Applications of Trie

1. **Autocomplete** :- Suggests words while typing.
    
2. **Spell Checkers** :- Checks whether a word exists in a dictionary.
    
3. **Search Engines** :- Supports prefix-based suggestions.
    
4. **IP Routing** :- Binary prefix trees are used for matching network addresses.
    
5. **Word Games** :- Efficiently searches valid words and prefixes.
    
6. **Dictionary Applications** :- Stores and searches words.
    
7. **Text Processing** :- Supports prefix and pattern-related operations.
    
8. **Contact Search** :- Finds names based on entered prefixes.
    
9. **Search Suggestions** :- Generates suggestions based on partial input.
    

---

# Important Terms

|Term|Meaning|
|---|---|
|Trie|Tree-based data structure for storing strings|
|Prefix|Beginning sequence of a string|
|Root|Starting node of a Trie|
|Trie Node|Node representing a character|
|End of Word|Marker indicating a complete word|
|Terminal Node|Node representing the end of a word|
|Standard Trie|Character-by-character Trie|
|Compressed Trie|Trie with compressed paths|
|Radix Trie|Another name for a compressed Trie|
|Ternary Search Trie|Trie with left, equal and right children|
|Suffix Trie|Trie storing all suffixes of a string|
|Autocomplete|Suggesting words based on a prefix|
|Alphabet|Set of characters used by the Trie|

---

# Important Notes

1. A Trie is a tree-based non-linear data structure.
    
2. A Trie is also called a Prefix Tree.
    
3. Each node generally represents a character.
    
4. The root represents an empty string.
    
5. Common prefixes share the same path.
    
6. The end-of-word marker distinguishes complete words from prefixes.
    
7. Searching and insertion take O(L) time.
    
8. Prefix searching does not require the end-of-word marker.
    
9. Deletion must preserve nodes shared by other words.
    
10. Tries are especially useful for string-related problems.
    
11. Standard Tries can consume more memory than Hash Tables.
    
12. Compressed Tries reduce unnecessary nodes and pointer overhead.
    

---

# Next Topics

After completing Tries, continue with:

1. Disjoint Set Union (DSU)
    
2. Segment Tree (Advanced)
    
3. Fenwick Tree (Advanced)
    
4. Suffix Array
    
5. Suffix Tree
    
6. Advanced String Algorithms (KMP, Z-Algorithm, Rabin-Karp)
    

NOTE :- Before moving to advanced string algorithms, practise Trie insertion, searching, prefix searching, deletion and autocomplete. These operations form the foundation of most Trie problems.