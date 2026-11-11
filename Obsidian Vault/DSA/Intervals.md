# About

**Intervals** represent a continuous range between two endpoints.

An interval is generally represented using two values:

```
[start, end]
```

For example:

```
[2, 6]
[4, 9]
[10, 15]
```

These intervals represent ranges of numbers.

Interval problems involve operations such as:

- Merging overlapping intervals.
    
- Finding overlapping intervals.
    
- Inserting a new interval.
    
- Removing overlapping intervals.
    
- Finding gaps between intervals.
    
- Finding maximum simultaneous intervals.
    
- Finding the minimum number of resources required.
    
- Finding intersections between intervals.
    

Intervals are frequently used in:

- Scheduling problems.
    
- Calendar applications.
    
- Meeting room allocation.
    
- CPU scheduling.
    
- Range queries.
    
- Time management systems.
    
- Competitive programming.
    

---

# 1. Understanding Intervals

An interval represents a range between two endpoints.

Example:

```
[2, 7]
```

Here:

- Start = 2
    
- End = 7
    

A common representation in programming is:

```
vector<vector<int>> intervals = {
    {2, 7},
    {4, 9},
    {10, 15}
};
```

Each interval is stored as a pair of values.

## Types of Intervals

### 1. Closed Interval

Both endpoints are included.

[  
[a,b]  
]

Example:

```
[2, 5]
```

Includes:

```
2, 3, 4, 5
```

### 2. Open Interval

Neither endpoint is included.

[  
(a,b)  
]

Example:

```
(2, 5)
```

Does not include 2 or 5.

### 3. Half-Open Interval

One endpoint is included and the other is excluded.

Left-closed, right-open:

[  
[a,b)  
]

Left-open, right-closed:

[  
(a,b]  
]

Example:

```
[2, 5)
```

Includes 2 but excludes 5.

NOTE :- Most basic DSA interval problems use closed intervals unless stated otherwise. Always check the problem's endpoint convention.

---

# 2. Overlapping Intervals

Two intervals overlap if they share at least one point.

Example:

```
A = [2, 6]
B = [4, 9]
```

Visual representation:

```
A:  2 -------- 6
B:       4 -------- 9
```

Their overlapping range is:

```
[4, 6]
```

For two closed intervals:

[  
A=[a,b]  
]

[  
B=[c,d]  
]

They overlap when:

[  
a\leq d \quad \text{and} \quad c\leq b  
]

Equivalent condition:

[  
\max(a,c)\leq\min(b,d)  
]

### C++ Implementation

```
bool overlaps(vector<int>& a, vector<int>& b) {

    return max(a[0], b[0]) <= min(a[1], b[1]);
}
```

Time Complexity: O(1)

NOTE :- For closed intervals, `[1, 3]` and `[3, 5]` overlap at point 3. For half-open intervals, endpoint handling changes.

---

# 3. Sorting Intervals

Sorting is one of the most important operations in interval problems.

Most interval algorithms first sort intervals by their starting points.

Example:

Before sorting:

```
[6, 8]
[1, 4]
[3, 7]
[10, 12]
```

After sorting:

```
[1, 4]
[3, 7]
[6, 8]
[10, 12]
```

### C++ Implementation

```
sort(intervals.begin(), intervals.end());
```

For `vector<vector<int>>`, this sorts lexicographically:

1. First by starting point.
    
2. If starts are equal, by ending point.
    

Custom comparator:

```
sort(intervals.begin(), intervals.end(),
    [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
);
```

Time Complexity:

[  
O(n\log n)  
]

NOTE :- When equal starting points occur, sorting by both start and end can make the processing order more predictable.

---

# 4. Merge Intervals

Merging intervals combines overlapping intervals into a single interval.

Example:

Input:

```
[1, 3]
[2, 6]
[8, 10]
[9, 12]
```

Visual representation:

```
[1, 3]
   [2, 6]

[8, 10]
   [9, 12]
```

After merging:

```
[1, 6]
[8, 12]
```

## Algorithm

1. Sort intervals by their starting points.
    
2. Create an empty result array.
    
3. Traverse the sorted intervals.
    
4. If the current interval overlaps with the last interval in the result, merge them.
    
5. Otherwise, add the current interval.
    
6. Return the merged intervals.
    

For closed intervals, two intervals merge when:

[  
currentStart\leq lastEnd  
]

The merged interval becomes:

[  
[lastStart,\max(lastEnd,currentEnd)]  
]

### C++ Implementation

```
vector<vector<int>> merge(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (auto& interval : intervals) {

        if (ans.empty() ||
            ans.back()[1] < interval[0]) {

            ans.push_back(interval);
        }
        else {

            ans.back()[1] =
                max(ans.back()[1], interval[1]);
        }
    }

    return ans;
}
```

### Example

Input:

```
[[1,3], [2,6], [8,10], [9,12]]
```

Output:

```
[[1,6], [8,12]]
```

Time Complexity:

[  
O(n\log n)  
]

Space Complexity:

[  
O(n)  
]

NOTE :- The result array requires O(n) space. Sorting may also require implementation-dependent auxiliary space.

---

# 5. Insert Interval

This problem involves inserting a new interval into an already sorted collection of non-overlapping intervals.

The resulting intervals must remain sorted and non-overlapping.

Example:

Existing intervals:

```
[1, 3]
[6, 9]
```

New interval:

```
[2, 5]
```

After insertion:

```
[1, 5]
[6, 9]
```

## Algorithm

There are three phases:

### Phase 1: Add intervals before the new interval

If an interval ends before the new interval starts, add it directly.

### Phase 2: Merge overlapping intervals

While intervals overlap with the new interval:

- Update the start to the minimum start.
    
- Update the end to the maximum end.
    

### Phase 3: Add remaining intervals

After merging, add the remaining intervals.

### C++ Implementation

```
vector<vector<int>> insertInterval(
    vector<vector<int>>& intervals,
    vector<int>& newInterval
) {

    vector<vector<int>> ans;

    int i = 0;
    int n = intervals.size();

    // Add intervals before the new interval
    while (i < n &&
           intervals[i][1] < newInterval[0]) {

        ans.push_back(intervals[i]);
        i++;
    }

    // Merge overlapping intervals
    while (i < n &&
           intervals[i][0] <= newInterval[1]) {

        newInterval[0] =
            min(newInterval[0], intervals[i][0]);

        newInterval[1] =
            max(newInterval[1], intervals[i][1]);

        i++;
    }

    ans.push_back(newInterval);

    // Add remaining intervals
    while (i < n) {

        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}
```

Time Complexity:

[  
O(n)  
]

Space Complexity:

[  
O(n)  
]

NOTE :- The original intervals must already be sorted and non-overlapping.

---

# 6. Non-Overlapping Intervals

This problem asks us to remove the minimum number of intervals so that the remaining intervals do not overlap.

Example:

Input:

```
[1, 2]
[2, 3]
[3, 4]
[1, 3]
```

One possible solution is to remove:

```
[1, 3]
```

Remaining intervals:

```
[1, 2]
[2, 3]
[3, 4]
```

These intervals do not overlap in their interiors.

For this common problem, touching endpoints are allowed.

## Greedy Approach

The key idea is to keep intervals that finish earliest.

Why?

An interval with a smaller ending point leaves more room for future intervals.

### Algorithm

1. Sort intervals by ending points.
    
2. Select the interval that finishes earliest.
    
3. Traverse the remaining intervals.
    
4. If the current interval starts before the last selected interval ends, remove it.
    
5. Otherwise, select it.
    

### C++ Implementation

```
int eraseOverlapIntervals(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        }
    );

    int removed = 0;
    int lastEnd = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {

        if (intervals[i][0] < lastEnd) {
            removed++;
        }
        else {
            lastEnd = intervals[i][1];
        }
    }

    return removed;
}
```

Time Complexity:

[  
O(n\log n)  
]

Space Complexity: Depends on sorting implementation; O(1) auxiliary space apart from sorting overhead.

NOTE :- The implementation assumes the input is non-empty. For an empty input, return 0. The strict `<` comparison allows intervals that touch at endpoints.

---

# 7. Activity Selection Problem

The Activity Selection Problem involves selecting the maximum number of non-overlapping activities.

Each activity has:

- Start time.
    
- End time.
    

Example:

```
Activity  Start  End

A1          1     3
A2          2     5
A3          4     6
A4          6     8
A5          7     9
```

The goal is to select the maximum number of activities that can be performed without overlap.

## Greedy Strategy

Always select the activity that finishes earliest.

### Algorithm

1. Sort activities by ending time.
    
2. Select the first activity.
    
3. Traverse the remaining activities.
    
4. Select an activity if its start time is greater than or equal to the end time of the previously selected activity.
    
5. Continue until all activities are processed.
    

### C++ Implementation

```
int activitySelection(
    vector<int>& start,
    vector<int>& end
) {

    int n = start.size();

    vector<pair<int, int>> activities;

    for (int i = 0; i < n; i++) {
        activities.push_back({end[i], start[i]});
    }

    sort(activities.begin(), activities.end());

    int count = 0;
    int lastEnd = INT_MIN;

    for (auto activity : activities) {

        int finish = activity.first;
        int begin = activity.second;

        if (begin >= lastEnd) {

            count++;
            lastEnd = finish;
        }
    }

    return count;
}
```

Time Complexity:

[  
O(n\log n)  
]

Space Complexity:

[  
O(n)  
]

---

# 8. Meeting Rooms

Meeting Room problems are common interval scheduling problems.

There are two important variations.

## Problem 1: Can a Person Attend All Meetings?

Given a list of meeting intervals, determine whether any meetings overlap.

Example:

```
[0, 30]
[5, 10]
[15, 20]
```

The first meeting overlaps with the other two.

Therefore, the person cannot attend all meetings.

### Algorithm

1. Sort intervals by starting time.
    
2. Compare each interval with the next interval.
    
3. If the current interval ends after the next interval starts, there is an overlap.
    

### C++ Implementation

```
bool canAttendMeetings(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());

    for (int i = 1; i < intervals.size(); i++) {

        if (intervals[i][0] < intervals[i - 1][1]) {
            return false;
        }
    }

    return true;
}
```

Time Complexity:

[  
O(n\log n)  
]

## Problem 2: Minimum Meeting Rooms

Given meeting intervals, determine the minimum number of rooms required so that all meetings can take place.

Example:

```
[0, 30]
[5, 10]
[15, 20]
```

At time 5, two meetings are active.

Therefore, at least two rooms are required.

## Approach 1: Min Heap

A Min Heap stores the ending times of ongoing meetings.

### Algorithm

1. Sort meetings by starting time.
    
2. Create a Min Heap.
    
3. For each meeting, remove meetings that have already finished.
    
4. Add the current meeting's ending time.
    
5. The maximum heap size represents the minimum rooms required.
    

### C++ Implementation

```
int minMeetingRooms(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());

    priority_queue<
        int,
        vector<int>,
        greater<int>
    > pq;

    int ans = 0;

    for (auto& meeting : intervals) {

        while (!pq.empty() &&
               pq.top() <= meeting[0]) {

            pq.pop();
        }

        pq.push(meeting[1]);

        ans = max(ans, (int)pq.size());
    }

    return ans;
}
```

Time Complexity:

[  
O(n\log n)  
]

Space Complexity:

[  
O(n)  
]

NOTE :- The `<=` condition allows a meeting to start exactly when another meeting ends, so one room can be reused.

---

# 9. Maximum Number of Overlapping Intervals

This problem asks for the maximum number of intervals active at the same time.

Example:

```
[1, 5]
[2, 6]
[4, 8]
[7, 9]
```

At time 4:

```
[1, 5]
[2, 6]
[4, 8]
```

Three intervals are active.

Answer:

```
3
```

## Sweep Line Algorithm

The Sweep Line Algorithm processes events in sorted order.

For every interval:

- Starting point creates an event of +1.
    
- Ending point creates an event of -1.
    

Then we process events to maintain the number of active intervals.

### C++ Implementation

For closed intervals with integer endpoints, an interval ending at x is still active at x. Therefore, process start events before end events at the same coordinate.

```
int maxOverlapping(vector<vector<int>>& intervals) {

    vector<pair<int, int>> events;

    for (auto& interval : intervals) {

        events.push_back({interval[0], 1});
        events.push_back({interval[1], -1});
    }

    sort(events.begin(), events.end(),
        [](auto& a, auto& b) {

            if (a.first == b.first)
                return a.second > b.second;

            return a.first < b.first;
        }
    );

    int active = 0;
    int maximum = 0;

    for (auto& event : events) {

        active += event.second;

        maximum = max(maximum, active);
    }

    return maximum;
}
```

Time Complexity:

[  
O(n\log n)  
]

Space Complexity:

[  
O(n)  
]

NOTE :- For half-open intervals `[start, end)`, end events should be processed before start events at the same coordinate. Event ordering depends on endpoint conventions.

---

# 10. Interval Intersection

Interval intersection finds the common range between two intervals.

Example:

```
A = [1, 6]
B = [4, 9]
```

Intersection:

```
[4, 6]
```

Formula:

[  
Start=\max(a_1,b_1)  
]

[  
End=\min(a_2,b_2)  
]

An intersection exists when:

[  
Start\leq End  
]

## Intersection of Two Interval Lists

Given two sorted, non-overlapping interval lists, find all intersections.

### Algorithm

1. Compare the current intervals from both lists.
    
2. Calculate the maximum starting point.
    
3. Calculate the minimum ending point.
    
4. If start is less than or equal to end, add the intersection.
    
5. Move the pointer of the interval that ends first.
    
6. Repeat.
    

### C++ Implementation

```
vector<vector<int>> intervalIntersection(
    vector<vector<int>>& A,
    vector<vector<int>>& B
) {

    vector<vector<int>> ans;

    int i = 0;
    int j = 0;

    while (i < A.size() && j < B.size()) {

        int start = max(A[i][0], B[j][0]);
        int end = min(A[i][1], B[j][1]);

        if (start <= end) {
            ans.push_back({start, end});
        }

        if (A[i][1] < B[j][1]) {
            i++;
        }
        else {
            j++;
        }
    }

    return ans;
}
```

Time Complexity:

[  
O(n+m)  
]

Space Complexity:

[  
O(k)  
]

Where k is the number of intersections.

---

# 11. Finding Gaps Between Intervals

Sometimes we need to find the ranges that are not covered by any interval.

Example:

```
[1, 3]
[5, 7]
[10, 12]
```

The gaps are:

```
[3, 5]
[7, 10]
```

The exact representation of gaps depends on whether endpoints are included.

For continuous closed intervals, the uncovered gaps between them are open intervals:

```
(3, 5)
(7, 10)
```

### Algorithm

1. Sort intervals.
    
2. Merge overlapping intervals.
    
3. Compare the ending point of one merged interval with the starting point of the next.
    
4. Record the uncovered ranges.
    

This is useful in:

- Calendar scheduling.
    
- Resource allocation.
    
- Free-time calculations.
    
- Network availability.
    

---

# 12. Interval Partitioning

Interval Partitioning is the problem of assigning intervals to the minimum number of groups such that intervals in the same group do not overlap.

Example:

```
[1, 4]
[2, 5]
[5, 7]
[6, 9]
```

One possible assignment:

```
Group 1:
[1, 4]
[5, 7]

Group 2:
[2, 5]
[6, 9]
```

Minimum groups required:

```
2
```

A Min Heap can be used to track the ending times of groups.

The greedy approach is:

1. Sort intervals by starting time.
    
2. Maintain the earliest ending interval for each group.
    
3. Reuse a group if its ending time is compatible with the new interval.
    
4. Otherwise, create a new group.
    

Time Complexity:

[  
O(n\log n)  
]

This is closely related to the Meeting Rooms II problem.

---

# 13. Difference Between Intervals and DSU

Intervals and Disjoint Set Union are different concepts.

|Intervals|DSU|
|---|---|
|Represent continuous ranges|Represents collections of elements|
|Usually stored as start and end|Usually stored using parent arrays|
|Used in scheduling and range problems|Used in connectivity and grouping|
|Uses sorting, merging and sweep line|Uses Find and Union|
|Can represent overlapping ranges|Maintains disjoint sets|
|Commonly uses greedy algorithms|Commonly uses graph algorithms|

NOTE :- Intervals can overlap, whereas the sets maintained by DSU are always disjoint.

---

# 14. Interval Problems and Common Techniques

|Problem|Technique|
|---|---|
|Merge Intervals|Sorting + Greedy|
|Insert Interval|Two Pointers|
|Non-overlapping Intervals|Greedy|
|Activity Selection|Greedy|
|Meeting Rooms|Sorting|
|Minimum Meeting Rooms|Min Heap|
|Maximum Overlap|Sweep Line|
|Interval Intersection|Two Pointers|
|Find Free Time|Merge + Gap Detection|
|Interval Scheduling|Greedy|
|Dynamic Range Queries|Segment Tree / Fenwick Tree, depending on the problem|

---

# 15. Common Mistakes

1. Forgetting to sort intervals before merging them.
    
2. Confusing overlapping intervals with adjacent intervals.
    
3. Using `<` instead of `<=` for closed intervals.
    
4. Forgetting to update the ending point during merging.
    
5. Assuming all interval problems require merging.
    
6. Using the wrong sorting criterion.
    
7. Forgetting to handle empty input.
    
8. Ignoring duplicate intervals.
    
9. Incorrectly handling equal start or end times in sweep line problems.
    
10. Using a greedy strategy without proving that it is valid.
    
11. Confusing interval scheduling with interval partitioning.
    
12. Ignoring whether endpoints are open or closed.
    

---

# Complexity Analysis

|Operation|Time Complexity|
|---|---|
|Check two intervals for overlap|O(1)|
|Sort intervals|O(n log n)|
|Merge intervals|O(n log n)|
|Insert into sorted non-overlapping intervals|O(n)|
|Non-overlapping intervals|O(n log n)|
|Activity Selection|O(n log n)|
|Meeting Rooms I|O(n log n)|
|Meeting Rooms II using Min Heap|O(n log n)|
|Maximum Overlap using Sweep Line|O(n log n)|
|Intersection of two sorted lists|O(n + m)|

---

# Important Terms

|Term|Meaning|
|---|---|
|Interval|Continuous range between two endpoints|
|Start|Beginning of an interval|
|End|Ending of an interval|
|Closed Interval|Includes both endpoints|
|Open Interval|Excludes both endpoints|
|Half-Open Interval|Includes one endpoint and excludes the other|
|Overlapping Intervals|Intervals sharing at least one point|
|Merging|Combining overlapping intervals|
|Interval Scheduling|Selecting maximum non-overlapping intervals|
|Interval Partitioning|Assigning intervals to minimum groups|
|Greedy Algorithm|Makes locally optimal choices|
|Sweep Line|Processes sorted events across coordinates|
|Event|Start or end of an interval|
|Active Interval|Interval currently covering the sweep position|
|Interval Intersection|Common portion of intervals|
|Gap|Range not covered by intervals|

---

# Important Notes

1. Most interval problems use arrays or pairs to represent start and end points.
    
2. Sorting by start time is common for merging problems.
    
3. Sorting by end time is common for activity selection.
    
4. Merge Intervals generally requires O(n log n) time.
    
5. Insert Interval can be solved in O(n) when the input is already sorted and non-overlapping.
    
6. Greedy algorithms are commonly used in scheduling problems.
    
7. Min Heaps are useful for tracking ending times.
    
8. Sweep Line algorithms process interval start and end events.
    
9. Two Pointers can efficiently find intersections between sorted interval lists.
    
10. Endpoint conventions determine whether touching intervals overlap.
    
11. DSU and Intervals are different data structures and concepts.
    
12. Always check empty input and duplicate intervals.
    

---

# Next Topics

1. Greedy Algorithms
    
2. Sweep Line Algorithm
    
3. Line Sweep with Events
    
4. Priority Queue Applications
    
5. Segment Tree
    
6. Fenwick Tree
    
7. Interval DP
    
8. Range Queries
    

## Practice Problems

**Beginner**

- Merge Intervals
    
- Insert Interval
    
- Check Overlapping Intervals
    
- Meeting Rooms
    
- Minimum Number of Platforms
    

**Intermediate**

- Non-overlapping Intervals
    
- Meeting Rooms II
    
- Interval List Intersections
    
- Minimum Arrows to Burst Balloons
    
- Employee Free Time
    
- Maximum Number of Overlapping Intervals
    

**Advanced**

- My Calendar I
    
- My Calendar II
    
- My Calendar III
    
- Range Module
    
- Falling Squares
    
- The Skyline Problem
    
- Count of Smaller Numbers After Self