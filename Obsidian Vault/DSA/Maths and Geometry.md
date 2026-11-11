# About

**Mathematics and Geometry** are important foundations of Data Structures and Algorithms (DSA), competitive programming and problem-solving.

Mathematics helps us understand numerical relationships, patterns, calculations and optimisations.

Geometry focuses on points, lines, angles, distances, shapes and spatial relationships.

In programming, these concepts are used in:

- Number Theory
    
- Modular Arithmetic
    
- Combinatorics
    
- Probability
    
- Coordinate Geometry
    
- Computational Geometry
    
- Mathematical Optimisation
    
- Geometric Algorithms
    

---

# PART 1: MATHEMATICAL FOUNDATIONS

# 1. Number Systems

A number system represents numbers using a specific set of digits.

Common number systems:

|Number System|Base|Digits|
|---|---|---|
|Binary|2|0, 1|
|Octal|8|0–7|
|Decimal|10|0–9|
|Hexadecimal|16|0–9, A–F|

### Binary

Uses only 0 and 1.

Example:

```
1010₂ = 10₁₀
```

### Decimal

The standard number system used in everyday calculations.

### Octal

Uses digits from 0 to 7.

### Hexadecimal

Uses digits from 0 to 9 and A to F.

Example:

```
FF₁₆ = 255₁₀
```

---

# 2. Basic Arithmetic

Mathematical operations used in programming:

|Operation|Symbol|C++|
|---|---|---|
|Addition|+|`a + b`|
|Subtraction|−|`a - b`|
|Multiplication|×|`a * b`|
|Division|÷|`a / b`|
|Modulus|Remainder|`a % b`|
|Exponentiation|Power|`pow(a, b)`|

NOTE :- In C++, integer division removes the fractional part by truncating towards zero.

Example:

```
cout << 10 / 3;    // 3
cout << 10 % 3;    // 1
cout << 10.0 / 3;  // approximately 3.333
```

---

# 3. Factors and Multiples

## Factors

A factor of a number is an integer that divides that number exactly.

Example:

```
Factors of 12:

1, 2, 3, 4, 6, 12
```

## Multiples

Multiples are obtained by multiplying a number by integers.

Example:

```
Multiples of 4:

4, 8, 12, 16, 20, ...
```

## Prime Numbers

A prime number is a natural number greater than 1 that has exactly two positive divisors:

1. 1
    
2. The number itself
    

Examples:

```
2, 3, 5, 7, 11, 13, 17
```

NOTE :- 2 is the only even prime number.

## Composite Numbers

A composite number has more than two positive divisors.

Examples:

```
4, 6, 8, 9, 10, 12
```

NOTE :- 1 is neither prime nor composite.

---

# 4. Divisibility Rules

Divisibility rules help determine whether one number is divisible by another without performing full division.

|Number|Rule|
|---|---|
|2|Last digit is even|
|3|Sum of digits is divisible by 3|
|4|Last two digits are divisible by 4|
|5|Last digit is 0 or 5|
|6|Divisible by both 2 and 3|
|8|Last three digits are divisible by 8|
|9|Sum of digits is divisible by 9|
|10|Last digit is 0|
|11|Alternating sum of digits is divisible by 11|

---

# 5. Greatest Common Divisor (GCD)

GCD is the largest positive integer that divides two or more integers exactly.

It is also called Highest Common Factor (HCF).

Example:

```
12 = 1, 2, 3, 4, 6, 12
18 = 1, 2, 3, 6, 9, 18
```

Common factors:

```
1, 2, 3, 6
```

Therefore:

```
GCD(12, 18) = 6
```

## Euclidean Algorithm

The Euclidean Algorithm efficiently calculates GCD.

Formula:

[  
gcd(a,b)=gcd(b,a\bmod b)  
]

Base case:

[  
gcd(a,0)=|a|  
]

### C++ Implementation

```
int gcd(int a, int b) {

    if (b == 0)
        return abs(a);

    return gcd(b, a % b);
}
```

Modern C++ also provides:

```
#include <numeric>

cout << std::gcd(12, 18);
```

Time Complexity:

[  
O(\log(\min(a,b)))  
]

---

# 6. Least Common Multiple (LCM)

LCM is the smallest positive integer divisible by both given numbers.

Example:

```
Multiples of 4:

4, 8, 12, 16, 20, ...

Multiples of 6:

6, 12, 18, 24, ...
```

Therefore:

```
LCM(4, 6) = 12
```

### Formula

[  
LCM(a,b)=\frac{|a\times b|}{GCD(a,b)}  
]

### C++ Implementation

```
long long lcm(long long a, long long b) {

    if (a == 0 || b == 0)
        return 0;

    return abs(a / gcd(a, b) * b);
}
```

NOTE :- Divide before multiplying to reduce overflow risk. Even then, the final result must fit in the chosen integer type.

---

# 7. Prime Number Algorithms

## Check Whether a Number Is Prime

A number is prime if it has no divisors other than 1 and itself.

Instead of checking every number up to n, we only need to check divisors up to its square root.

Why?

If:

[  
n=a\times b  
]

At least one of the factors must be less than or equal to:

[  
\sqrt n  
]

### C++ Implementation

```
bool isPrime(int n) {

    if (n <= 1)
        return false;

    for (int i = 2; i <= n / i; i++) {

        if (n % i == 0)
            return false;
    }

    return true;
}
```

Time Complexity:

[  
O(\sqrt n)  
]

## Sieve of Eratosthenes

The Sieve of Eratosthenes finds all prime numbers up to a given limit.

Instead of checking every number individually, it repeatedly marks multiples of prime numbers as composite.

### Working

Suppose:

```
n = 20
```

Initially, assume every number is prime.

Start with 2:

- Mark multiples of 2 as composite.
    
- Move to 3.
    
- Mark multiples of 3 as composite.
    
- Continue until the current prime exceeds √n.
    

The remaining unmarked numbers are prime.

### C++ Implementation

```
vector<bool> sieve(int n) {

    vector<bool> isPrime(n + 1, true);

    isPrime[0] = false;

    if (n >= 1)
        isPrime[1] = false;

    for (int i = 2; i <= n / i; i++) {

        if (isPrime[i]) {

            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}
```

Time Complexity:

[  
O(n\log\log n)  
]

Space Complexity:

[  
O(n)  
]

Applications:

- Finding prime numbers.
    
- Prime factorisation.
    
- Number theory problems.
    
- Cryptography fundamentals.
    

---

# 8. Prime Factorisation

Prime factorisation expresses a number as a product of prime numbers.

Example:

[  
60=2^2\times3\times5  
]

Every integer greater than 1 has a unique prime factorisation, apart from the order of factors.

### C++ Implementation

```
void primeFactors(int n) {

    for (int i = 2; i <= n / i; i++) {

        while (n % i == 0) {

            cout << i << " ";
            n /= i;
        }
    }

    if (n > 1)
        cout << n;
}
```

Time Complexity:

[  
O(\sqrt n)  
]

For many queries, use a Smallest Prime Factor (SPF) sieve to make factorisation faster.

---

# 9. Modular Arithmetic

Modular Arithmetic deals with remainders after division.

The expression:

[  
a\bmod m  
]

returns the remainder when a is divided by m.

Example:

[  
17\bmod5=2  
]

## Modular Properties

### Addition

[  
(a+b)\bmod m  
]

Equivalent to:

[  
((a\bmod m)+(b\bmod m))\bmod m  
]

### Subtraction

[  
(a-b)\bmod m  
]

In programming, add m before taking the remainder when working with normal non-negative residues:

```
((a - b) % m + m) % m
```

### Multiplication

[  
(a\times b)\bmod m  
]

Equivalent to:

[  
((a\bmod m)\times(b\bmod m))\bmod m  
]

### Division

Modular division is not ordinary integer division.

It requires a modular inverse when the inverse exists.

## Modular Inverse

The modular inverse of a number a modulo m is a number x satisfying:

[  
a\times x\equiv1\pmod m  
]

An inverse exists if and only if:

[  
gcd(a,m)=1  
]

For prime m and a not divisible by m, Fermat's Little Theorem gives:

[  
a^{-1}\equiv a^{m-2}\pmod m  
]

---

# 10. Fast Exponentiation

Fast Exponentiation calculates powers efficiently.

Normal calculation:

[  
a^n  
]

Repeated multiplication takes O(n) multiplications.

Fast Exponentiation uses the binary representation of the exponent.

### Principle

If n is even:

[  
a^n=(a^{n/2})^2  
]

If n is odd:

[  
a^n=a\times a^{n-1}  
]

### C++ Implementation

```
long long power(long long a, long long b) {

    long long ans = 1;

    while (b > 0) {

        if (b & 1)
            ans *= a;

        a *= a;
        b >>= 1;
    }

    return ans;
}
```

Time Complexity:

[  
O(\log b)  
]

For large results, use modular exponentiation.

```
long long modPower(long long a, long long b, long long mod) {

    long long ans = 1;

    a %= mod;

    while (b > 0) {

        if (b & 1)
            ans = ans * a % mod;

        a = a * a % mod;
        b >>= 1;
    }

    return ans;
}
```

NOTE :- For sufficiently large mod values, multiplication may overflow `long long`. Use a wider multiplication strategy when required.

---

# 11. Number Sequences

## Arithmetic Progression (AP)

A sequence in which the difference between consecutive terms is constant.

Example:

```
2, 5, 8, 11, 14, ...
```

Common difference:

[  
d=3  
]

Nth term:

[  
a_n=a+(n-1)d  
]

Sum of n terms:

[  
S_n=\frac n2[2a+(n-1)d]  
]

## Geometric Progression (GP)

A sequence in which each term is obtained by multiplying the previous term by a constant ratio.

Example:

```
2, 4, 8, 16, 32, ...
```

Common ratio:

[  
r=2  
]

Nth term:

[  
a_n=ar^{n-1}  
]

Sum of n terms, when r is not 1:

[  
S_n=a\frac{r^n-1}{r-1}  
]

---

# 12. Logarithms

A logarithm answers the question:

To what power must a base be raised to obtain a given number?

[  
\log_b a=x  
]

Means:

[  
b^x=a  
]

Example:

[  
\log_2 8=3  
]

Because:

[  
2^3=8  
]

### Important Logarithm Rules

[  
\log(ab)=\log a+\log b  
]

[  
\log(a/b)=\log a-\log b  
]

[  
\log(a^n)=n\log a  
]

[  
\log_b a=\frac{\log_c a}{\log_c b}  
]

### Applications in DSA

- Binary Search: O(log n)
    
- Balanced Trees: O(log n)
    
- Heap Operations: O(log n)
    
- Divide and Conquer
    
- Fast Exponentiation
    

---

# 13. Combinatorics

Combinatorics is the branch of mathematics that studies counting, arrangements and selections.

It is widely used in competitive programming.

## Factorial

Factorial of n is the product of all positive integers from 1 to n.

[  
n!=n\times(n-1)\times\cdots\times1  
]

Example:

[  
5!=5\times4\times3\times2\times1=120  
]

By definition:

[  
0!=1  
]

C++:

```
long long factorial(int n) {

    long long ans = 1;

    for (int i = 2; i <= n; i++) {
        ans *= i;
    }

    return ans;
}
```

NOTE :- Factorials grow very quickly. `long long` cannot store large factorials such as 21!.

## Permutations

A permutation is an arrangement where order matters.

Example:

```
A, B, C
```

Possible arrangements:

```
ABC
ACB
BAC
BCA
CAB
CBA
```

Formula:

[  
P(n,r)=\frac{n!}{(n-r)!}  
]

## Combinations

A combination is a selection where order does not matter.

Formula:

[  
C(n,r)=\frac{n!}{r!(n-r)!}  
]

Example:

Selecting 2 people from 4:

[  
C(4,2)=6  
]

### Difference Between Permutation and Combination

|Permutation|Combination|
|---|---|
|Order matters|Order does not matter|
|Arrangement|Selection|
|Uses n!/(n-r)!|Uses n!/[r!(n-r)!]|

## Pascal's Triangle

Pascal's Triangle is used to calculate binomial coefficients.

```
          1
        1   1
      1   2   1
    1   3   3   1
  1   4   6   4   1
```

Property:

[  
C(n,r)=C(n-1,r-1)+C(n-1,r)  
]

Also:

[  
C(n,0)=C(n,n)=1  
]

Applications:

- Counting problems.
    
- Subset generation.
    
- Probability.
    
- Dynamic Programming.
    

---

# 14. Probability

Probability measures how likely an event is to happen.

Its value lies between 0 and 1.

[  
P(E)=\frac{\text{Favourable Outcomes}}{\text{Total Equally Likely Outcomes}}  
]

Example:

When rolling a fair six-sided die:

[  
P(4)=\frac16  
]

## Important Probability Rules

### Complement Rule

[  
P(A')=1-P(A)  
]

### Addition Rule

[  
P(A\cup B)=P(A)+P(B)-P(A\cap B)  
]

### Multiplication Rule

For independent events:

[  
P(A\cap B)=P(A)\times P(B)  
]

### Conditional Probability

Probability of A occurring given that B has occurred:

[  
P(A|B)=\frac{P(A\cap B)}{P(B)}  
]

For non-zero P(B).

### Applications

- Randomised Algorithms.
    
- Expected Values.
    
- Probability-based problems.
    
- Game theory.
    
- Statistics and Machine Learning.
    

---

# PART 2: GEOMETRY

# 15. Introduction to Geometry

Geometry is the branch of mathematics concerned with shapes, sizes, positions and spatial relationships.

In programming, geometry is used to solve problems involving:

- Points
    
- Lines
    
- Angles
    
- Distances
    
- Triangles
    
- Circles
    
- Polygons
    
- Areas
    
- Intersections
    
- Convex Hulls
    

**Computational Geometry** is the study of designing algorithms to solve geometric problems using computers.

---

# 16. Coordinate System

A coordinate system represents positions using numerical values.

The most common system in 2D geometry is the Cartesian Coordinate System.

A point is represented as:

[  
P(x,y)  
]

Where:

- x represents horizontal position.
    
- y represents vertical position.
    

Example:

```
       Y
       |
   3   |       P(2,3)
       |
   2   |
       |
   1   |
-------+------------ X
       |
       0  1  2  3
```

## Quadrants

The Cartesian plane has four quadrants.

|Quadrant|x|y|
|---|---|---|
|I|+|+|
|II|-|+|
|III|-|-|
|IV|+|-|

---

# 17. Distance Between Two Points

The Euclidean distance between two points is the shortest straight-line distance between them.

For:

[  
A(x_1,y_1)  
]

[  
B(x_2,y_2)  
]

Formula:

[  
d=\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}  
]

### C++ Implementation

```
double distance(double x1, double y1,
                double x2, double y2) {

    return hypot(x2 - x1, y2 - y1);
}
```

Time Complexity: O(1)

## Manhattan Distance

Manhattan distance is the sum of the absolute horizontal and vertical differences.

[  
d=|x_2-x_1|+|y_2-y_1|  
]

Example:

```
A(1,2)
B(4,6)
```

[  
d=|4-1|+|6-2|=7  
]

Applications:

- Grid-based problems.
    
- Pathfinding.
    
- City-block movement.
    
- Some clustering algorithms.
    

## Chebyshev Distance

The Chebyshev distance is the maximum of the absolute coordinate differences.

[  
d=\max(|x_2-x_1|,|y_2-y_1|)  
]

It is useful when diagonal movement costs the same as horizontal and vertical movement.

---

# 18. Slope of a Line

Slope measures the steepness of a line.

For two points:

[  
A(x_1,y_1),B(x_2,y_2)  
]

Formula:

[  
m=\frac{y_2-y_1}{x_2-x_1}  
]

Interpretation:

- Positive slope: Line rises from left to right.
    
- Negative slope: Line falls from left to right.
    
- Zero slope: Horizontal line.
    
- Undefined slope: Vertical line.
    

NOTE :- A vertical line has x₂ = x₁, so its slope is undefined.

---

# 19. Equation of a Line

The slope-intercept form is:

[  
y=mx+c  
]

Where:

- m = Slope
    
- c = Y-intercept
    

The general form is:

[  
Ax+By+C=0  
]

The general form is often more convenient in computational geometry because it also represents vertical lines.

---

# 20. Midpoint of a Line Segment

The midpoint is the point exactly halfway between two endpoints.

For:

[  
A(x_1,y_1),B(x_2,y_2)  
]

Formula:

[  
M=\left(\frac{x_1+x_2}{2},\frac{y_1+y_2}{2}\right)  
]

### C++ Implementation

```
pair<double, double> midpoint(
    double x1, double y1,
    double x2, double y2
) {
    return {
        (x1 + x2) / 2.0,
        (y1 + y2) / 2.0
    };
}
```

---

# 21. Angles and Trigonometry

An angle measures the rotation between two lines or rays.

Common angle types:

|Type|Measurement|
|---|---|
|Acute|Less than 90°|
|Right|Exactly 90°|
|Obtuse|Between 90° and 180°|
|Straight|Exactly 180°|
|Reflex|Between 180° and 360°|
|Full Rotation|360°|

## Degrees and Radians

A complete rotation:

[  
360^\circ=2\pi\text{ radians}  
]

Conversion:

[  
Radians=Degrees\times\frac{\pi}{180}  
]

[  
Degrees=Radians\times\frac{180}{\pi}  
]

C++:

```
double radians = degrees * M_PI / 180.0;
```

For portable C++ code, define π yourself or use a supported mathematical constant.

## Trigonometric Functions

|Function|Formula|
|---|---|
|sin θ|Opposite / Hypotenuse|
|cos θ|Adjacent / Hypotenuse|
|tan θ|Opposite / Adjacent|

Important identity:

[  
\sin^2\theta+\cos^2\theta=1  
]

Applications:

- Rotating points.
    
- Calculating angles.
    
- Measuring distances.
    
- Computer graphics.
    
- Physics simulations.
    

---

# 22. Area of Common Shapes

## Square

[  
Area=a^2  
]

[  
Perimeter=4a  
]

## Rectangle

[  
Area=l\times w  
]

[  
Perimeter=2(l+w)  
]

## Triangle

[  
Area=\frac12\times base\times height  
]

## Circle

[  
Area=\pi r^2  
]

[  
Circumference=2\pi r  
]

## Parallelogram

[  
Area=base\times height  
]

## Trapezium

[  
Area=\frac12(a+b)h  
]

Where a and b are the parallel sides.

---

# 23. Triangle Geometry

A triangle is a polygon with three sides and three angles.

The sum of its interior angles is:

[  
180^\circ  
]

Types based on sides:

- Equilateral: All sides equal.
    
- Isosceles: Two sides equal.
    
- Scalene: All sides different.
    

Types based on angles:

- Acute Triangle.
    
- Right Triangle.
    
- Obtuse Triangle.
    

## Pythagorean Theorem

For a right-angled triangle:

[  
a^2+b^2=c^2  
]

Where c is the hypotenuse.

## Heron's Formula

Used to calculate the area of a triangle when all three side lengths are known.

First calculate the semi-perimeter:

[  
s=\frac{a+b+c}{2}  
]

Then:

[  
Area=\sqrt{s(s-a)(s-b)(s-c)}  
]

## Triangle Inequality

For three sides to form a valid triangle:

[  
a+b>c  
]

[  
a+c>b  
]

[  
b+c>a  
]

---

# 24. Polygon Geometry

A polygon is a closed 2D shape formed by straight line segments.

Examples:

- Triangle
    
- Square
    
- Rectangle
    
- Pentagon
    
- Hexagon
    
- Octagon
    

For a simple polygon with n sides:

### Sum of Interior Angles

[  
(n-2)\times180^\circ  
]

### Each Interior Angle of a Regular Polygon

[  
\frac{(n-2)\times180^\circ}{n}  
]

### Sum of Exterior Angles

[  
360^\circ  
]

### Number of Diagonals

[  
\frac{n(n-3)}{2}  
]

---

# 25. Shoelace Formula

The Shoelace Formula calculates the area of a polygon when its vertices are given in order.

For vertices:

[  
(x_1,y_1),(x_2,y_2),\ldots,(x_n,y_n)  
]

Formula:

[  
Area=\frac12\left|  
\sum_{i=1}^{n}(x_i y_{i+1}-y_i x_{i+1})  
\right|  
]

The indices wrap around, so the next vertex after n is vertex 1.

### C++ Implementation

```
double polygonArea(vector<pair<double,double>>& p) {

    int n = p.size();

    double area = 0;

    for (int i = 0; i < n; i++) {

        int j = (i + 1) % n;

        area += p[i].first * p[j].second
              - p[i].second * p[j].first;
    }

    return abs(area) / 2.0;
}
```

Time Complexity:

[  
O(n)  
]

NOTE :- The vertices must be listed in their boundary order. The formula works for simple polygons, including concave ones.

---

# PART 3: COMPUTATIONAL GEOMETRY

# 26. Orientation of Three Points

Orientation determines the relative direction of three points.

Given three points:

[  
A(x_1,y_1), B(x_2,y_2), C(x_3,y_3)  
]

Calculate:

[  
cross=(x_2-x_1)(y_3-y_1)  
-(y_2-y_1)(x_3-x_1)  
]

Interpretation:

|Cross Product|Orientation|
|---|---|
|Positive|Counterclockwise|
|Negative|Clockwise|
|Zero|Collinear|

This is one of the most important operations in computational geometry.

### C++ Implementation

```
struct Point {
    long long x, y;
};

long long cross(Point a, Point b, Point c) {

    return (b.x - a.x) * (c.y - a.y)
         - (b.y - a.y) * (c.x - a.x);
}
```

NOTE :- This implementation assumes the products fit in `long long`. Use a wider integer type when coordinate limits are large.

Applications:

- Line intersection.
    
- Convex Hull.
    
- Point-in-polygon.
    
- Segment intersection.
    

---

# 27. Dot Product and Cross Product

These are fundamental operations in vector geometry.

## Dot Product

For vectors:

[  
A=(a_x,a_y)  
]

[  
B=(b_x,b_y)  
]

Formula:

[  
A\cdot B=a_xb_x+a_yb_y  
]

The dot product measures how much two vectors point in the same direction.

Applications:

- Calculating angles.
    
- Checking perpendicularity.
    
- Projection.
    

If:

[  
A\cdot B=0  
]

The vectors are perpendicular, provided neither vector is zero.

## Cross Product in 2D

Formula:

[  
A\times B=a_xb_y-a_yb_x  
]

It gives the signed magnitude of the 2D cross product.

Applications:

- Orientation.
    
- Triangle area.
    
- Polygon area.
    
- Segment intersection.
    

For vectors:

[  
Area=\frac12|A\times B|  
]

This is the area of the triangle formed by the vectors from a common origin.

---

# 28. Line Segment Intersection

A line segment is a finite portion of a line between two endpoints.

Given two segments AB and CD, we need to determine whether they intersect.

The orientation test is commonly used.

### General Idea

Calculate:

```
orientation(A, B, C)
orientation(A, B, D)
orientation(C, D, A)
orientation(C, D, B)
```

For a proper intersection, the two endpoints of each segment must lie on opposite sides of the other segment.

Collinear cases must also be checked separately.

### C++ Implementation

```
struct Point {
    long long x, y;
};

long long cross(Point a, Point b, Point c) {

    return (b.x - a.x) * (c.y - a.y)
         - (b.y - a.y) * (c.x - a.x);
}

bool onSegment(Point a, Point b, Point p) {

    return min(a.x, b.x) <= p.x &&
           p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y &&
           p.y <= max(a.y, b.y);
}

bool segmentsIntersect(Point a, Point b,
                       Point c, Point d) {

    long long o1 = cross(a, b, c);
    long long o2 = cross(a, b, d);
    long long o3 = cross(c, d, a);
    long long o4 = cross(c, d, b);

    if (((o1 > 0 && o2 < 0) || (o1 < 0 && o2 > 0)) &&
        ((o3 > 0 && o4 < 0) || (o3 < 0 && o4 > 0))) {
        return true;
    }

    if (o1 == 0 && onSegment(a, b, c)) return true;
    if (o2 == 0 && onSegment(a, b, d)) return true;
    if (o3 == 0 && onSegment(c, d, a)) return true;
    if (o4 == 0 && onSegment(c, d, b)) return true;

    return false;
}
```

Time Complexity:

[  
O(1)  
]

NOTE :- This version uses integer coordinates and assumes cross-product calculations do not overflow.

---

# 29. Point Inside a Polygon

A common computational geometry problem is determining whether a point lies:

- Inside a polygon.
    
- Outside a polygon.
    
- On its boundary.
    

Two common approaches are:

1. Ray Casting Algorithm.
    
2. Winding Number Algorithm.
    

## Ray Casting Algorithm

The idea is to draw an imaginary ray from the given point towards infinity.

Count how many times the ray intersects the polygon boundary.

- Odd number of intersections: Inside.
    
- Even number of intersections: Outside.
    

Boundary cases must be handled separately.

Applications:

- Map applications.
    
- Collision detection.
    
- Computer graphics.
    
- Geometric queries.
    

---

# 30. Convex Hull

A Convex Hull is the smallest convex polygon that contains all given points.

Imagine stretching a rubber band around a collection of points. The shape formed by the band is the convex hull.

Applications:

- Computer vision.
    
- Geographic information systems.
    
- Pattern recognition.
    
- Collision detection.
    
- Spatial analysis.
    

## Graham Scan

Graham Scan is an algorithm used to construct the convex hull.

General steps:

1. Find the point with the lowest y-coordinate.
    
2. Sort other points by their polar angle relative to that point.
    
3. Process the sorted points using a stack.
    
4. Remove points that create a clockwise turn when constructing a counterclockwise hull.
    
5. The remaining points form the convex hull.
    

Time Complexity:

[  
O(n\log n)  
]

## Monotonic Chain Algorithm

Another popular convex hull algorithm.

Steps:

1. Sort points lexicographically.
    
2. Build the lower hull.
    
3. Build the upper hull.
    
4. Combine both hulls.
    

Time Complexity:

[  
O(n\log n)  
]

NOTE :- Both Graham Scan and Monotonic Chain commonly remove collinear interior points from the hull. The exact treatment of collinear boundary points depends on the implementation.

---

# 31. Closest Pair of Points

Given n points in a plane, find the two points with the smallest Euclidean distance.

A brute-force solution compares every pair.

Number of pairs:

[  
\frac{n(n-1)}{2}  
]

Time Complexity:

[  
O(n^2)  
]

A more efficient Divide and Conquer algorithm achieves:

[  
O(n\log n)  
]

General idea:

1. Sort points by x-coordinate.
    
2. Divide the points into two halves.
    
3. Find the closest pair in each half.
    
4. Check points near the dividing line.
    
5. Return the smallest distance.
    

Applications:

- Geographic information systems.
    
- Computer vision.
    
- Spatial databases.
    
- Collision detection.
    

---

# 32. Coordinate Compression

Coordinate Compression converts large coordinate values into smaller integer indices while preserving their relative order.

Example:

```
Original:

100, 5000, 100000, 900000
```

Compressed:

```
0, 1, 2, 3
```

The actual distances are not preserved, but the ordering is.

### C++ Implementation

```
vector<int> compress(vector<int> arr) {

    vector<int> sorted = arr;

    sort(sorted.begin(), sorted.end());

    sorted.erase(
        unique(sorted.begin(), sorted.end()),
        sorted.end()
    );

    vector<int> result;

    for (int x : arr) {

        int index = lower_bound(
            sorted.begin(),
            sorted.end(),
            x
        ) - sorted.begin();

        result.push_back(index);
    }

    return result;
}
```

Applications:

- Segment Trees.
    
- Fenwick Trees.
    
- Range Query Problems.
    
- Large-coordinate geometry problems.
    
- Offline Queries.
    

---

# 33. Geometry in Computer Graphics

Geometry is heavily used in computer graphics.

Important concepts:

## Translation

Moves a point by a fixed distance.

[  
x'=x+t_x  
]

[  
y'=y+t_y  
]

## Scaling

Changes the size of an object.

[  
x'=sx  
]

[  
y'=sy  
]

## Rotation

Rotates a point around the origin by an angle θ.

[  
x'=x\cos\theta-y\sin\theta  
]

[  
y'=x\sin\theta+y\cos\theta  
]

## Reflection

Reflects a point across an axis.

Reflection across the x-axis:

[  
(x,y)\rightarrow(x,-y)  
]

Reflection across the y-axis:

[  
(x,y)\rightarrow(-x,y)  
]

Applications:

- Game development.
    
- 2D and 3D graphics.
    
- Animation.
    
- Robotics.
    
- Simulation.
    

---

# PART 4: COMPLEXITY AND APPLICATIONS

# 34. Mathematical Complexity

Mathematics also helps us understand algorithm complexity.

Common mathematical growth rates:

|Complexity|Example|
|---|---|
|O(1)|Direct arithmetic operation|
|O(log n)|Binary Search|
|O(n)|Linear Traversal|
|O(n log n)|Merge Sort|
|O(n²)|Pairwise comparison|
|O(n³)|Triple nested loops|
|O(2ⁿ)|Generating all subsets|
|O(n!)|Generating all permutations|

---

# 35. Important Mathematical Formulas

|Concept|Formula|
|---|---|
|GCD|Euclidean Algorithm|
|LCM|\|a × b\| / GCD(a,b)|
|Sum of first n natural numbers|n(n+1)/2|
|Sum of first n squares|n(n+1)(2n+1)/6|
|Sum of first n cubes|[n(n+1)/2]²|
|Arithmetic Progression|n/2 [2a+(n-1)d]|
|Geometric Progression|a(rⁿ-1)/(r-1), for r ≠ 1|
|Permutation|n!/(n-r)!|
|Combination|n!/[r!(n-r)!]|
|Circle Area|πr²|
|Circle Circumference|2πr|
|Triangle Area|½ × base × height|
|Euclidean Distance|√[(x₂-x₁)²+(y₂-y₁)²]|
|Manhattan Distance|\|x₂-x₁\|+\|y₂-y₁\||
|Polygon Interior Angle Sum|(n-2) × 180°|
|Polygon Diagonals|n(n-3)/2|
|Triangle Area (Heron)|√[s(s-a)(s-b)(s-c)]|

---

# Important Terms

|Term|Meaning|
|---|---|
|Number Theory|Study of integers and their properties|
|Prime Number|Number with exactly two positive divisors|
|Composite Number|Number with more than two positive divisors|
|GCD|Greatest Common Divisor|
|LCM|Least Common Multiple|
|Sieve|Algorithm for finding prime numbers|
|Prime Factorisation|Expressing a number as a product of primes|
|Modular Arithmetic|Arithmetic involving remainders|
|Modular Inverse|Multiplicative inverse under modulo|
|Factorial|Product of positive integers up to n|
|Permutation|Arrangement where order matters|
|Combination|Selection where order does not matter|
|Probability|Measure of the likelihood of an event|
|Coordinate System|System for representing positions|
|Euclidean Distance|Straight-line distance|
|Manhattan Distance|Sum of coordinate differences|
|Polygon|Closed shape made of line segments|
|Convex Hull|Smallest convex polygon containing a set of points|
|Cross Product|Operation used to determine orientation and area|
|Dot Product|Operation used to measure vector alignment|
|Coordinate Compression|Replacing values with smaller ordered indices|
|Computational Geometry|Designing algorithms for geometric problems|

---

# Important Notes

1. GCD and LCM are fundamental number theory concepts.
    
2. Euclidean Algorithm calculates GCD in logarithmic time.
    
3. Sieve of Eratosthenes finds all primes up to n in O(n log log n).
    
4. Modular arithmetic is frequently used when results become very large.
    
5. Modular division requires a modular inverse.
    
6. Fast Exponentiation reduces exponentiation from O(n) to O(log n).
    
7. Permutations are used when order matters.
    
8. Combinations are used when order does not matter.
    
9. Probability measures the likelihood of an event.
    
10. Euclidean distance measures straight-line distance.
    
11. Manhattan distance is useful for grid-based movement.
    
12. Cross product is fundamental to computational geometry.
    
13. Orientation determines whether three points are clockwise, counterclockwise or collinear.
    
14. Shoelace Formula calculates the area of a polygon.
    
15. Convex Hull finds the smallest convex boundary around a collection of points.
    
16. Coordinate Compression preserves relative ordering but not actual distances.
    
17. Floating-point calculations can introduce precision errors.
    
18. Integer overflow must be considered when calculating distances, areas and cross products.
    

---

# Next Topics

## Mathematical Algorithms

1. Advanced Number Theory
    
2. Extended Euclidean Algorithm
    
3. Modular Inverse
    
4. Chinese Remainder Theorem
    
5. Combinatorics with Modular Arithmetic
    
6. Matrix Exponentiation
    
7. Probability and Expected Value
    

## Computational Geometry

1. Point and Segment Intersection
    
2. Convex Hull
    
3. Closest Pair of Points
    
4. Sweep Line Algorithm
    
5. Rotating Calipers
    
6. Line and Circle Intersection
    
7. Polygon Triangulation
    
8. Voronoi Diagrams
    
9. Delaunay Triangulation
    

## Practice Problems

- Find GCD and LCM.
    
- Check whether a number is prime.
    
- Generate all primes up to n.
    
- Find prime factors.
    
- Calculate modular exponentiation.
    
- Find a modular inverse.
    
- Calculate nCr.
    
- Generate Pascal's Triangle.
    
- Calculate Euclidean distance.
    
- Calculate Manhattan distance.
    
- Find the area of a triangle.
    
- Find the area of a polygon.
    
- Determine the orientation of three points.
    
- Check whether two line segments intersect.
    
- Determine whether a point lies inside a polygon.
    
- Find the Convex Hull of a set of points.
    
- Find the closest pair of points.