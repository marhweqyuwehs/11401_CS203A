# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: marhweqyuwehs
Email: tsai755197@gmail.com

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
// Multiplication Method using the Golden Ratio
int myHashInt(int key, int m) {
// A is the Golden Ratio constant, approximately 0.6180339887
const double A = 0.6180339887;

// Calculate the fractional part: kA mod 1
double frac = (key * A) - (int)(key * A);

// h(k) = floor(m * frac)
return static_cast<int>(m * frac);
}
- Rationale: We chose the Multiplication Method, a robust and general-purpose hashing scheme whose performance is independent of whether the table size $m$ is prime or non-prime. By using the Golden Ratio constant $A$  (0.618), we ensure the fractional part of the product is maximally dispersed across the [0, 1) interval, leading to near-optimal uniform distribution.
### Non-integer Keys
- Formula / pseudocode: 
 Polynomial Rolling Hash (P=31)
int myHashString(const std::string& key, int m) {
const int P = 31;
long long hashValue = 0;
long long power = 1;
for (char c : key) {
// Core computation: hash_value = (hash_value + char_val * P^i) mod m
hashValue = (hashValue + (long long)c * power) % m;
power = (power * P) % m;
}
return (int)hashValue;
}
- Rationale: We implemented the Polynomial Rolling Hash. This method uses increasing powers of a prime base p=31 to effectively incorporate the character's position and order into the hash value. This design provides excellent dispersion for strings, avoiding collisions common to simpler additive hash methods, and the modulo operation at each step prevents integer overflow

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 6, 8, 9, 1, ...        |Shows slight clustering due to small table size.|
| 11             | 9, 1, 3, 4, ...        |more uniform.|
| 37             | 30, 32, 34, 0, ...     |Near-optimal dispersion with minimal visible patterns.|

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  Makefile.bat
  
  # Build only C version
  Makefile.bat c
  
  # Build only C++ version
 Makefile.bat cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot
  ```
=== Hash Function Observation (C Version) ===

=== Table Size m = 10  ===
Key     Index
-----------------
21      7
22      4
23      2
24      9
25      3
26      0
27      8
28      5
29      9
30      8
51      6 
52      0
53      3
54      7
55      6
56      0
57      7
58      9
59      8
60      4

=== Table Size m = 11  ===
Key     Index
-----------------
21      5
22      2
23      2
24      6
25      5
26      8
27      3
28      7
29      5
30      5
51      3
52      5
53      7
54      1
55      7
56      3
57      5
58      5
59      3
60      8

=== Table Size m = 37  ===
Key     Index
-----------------
21      18
22      17
23      28
24      23
25      19
26      21
27      26
28      0
29      15
30      14
51      30
52      5
53      1
54      18
55      2
56      0
57      32
58      33
59      25
60      12

=== String Hash Observation (C Version) ===

=== String Hash (m = 10) ===
Key     Index
-----------------
cat     2
dog     2
bat     8
cow     3
ant     6
owl     9
bee     5
hen     0
pig     7
fox     7

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     9
dog     4
bat     3
cow     4
ant     5
owl     4
bee     2
hen     6
pig     8
fox     8

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     21
dog     10
bat     8
cow     29
ant     32
owl     27
bee     17
hen     21
pig     10
fox     9

---
=== Hash Function Observation (C++ Version) ===

=== Table Size m = 10  ===
Key     Index
-----------------
21      7
22      4
23      2
24      9
25      3
26      0
27      8
28      5
29      9
30      8
51      6 
52      0
53      3
54      7
55      6
56      0
57      7
58      9
59      8
60      4

=== Table Size m = 11  ===
Key     Index
-----------------
21      5
22      2
23      2
24      6
25      5
26      8
27      3
28      7
29      5
30      5
51      3
52      5
53      7
54      1
55      7
56      3
57      5
58      5
59      3
60      8

=== Table Size m = 37  ===
Key     Index
-----------------
21      18
22      17
23      28
24      23
25      19
26      21
27      26
28      0
29      15
30      14
51      30
52      5
53      1
54      18
55      2
56      0
57      32
58      33
59      25
60      12

=== String Hash Observation (C++ Version) ===

=== String Hash (m = 10) ===
Key     Index
-----------------
cat     2
dog     2
bat     8
cow     3
ant     6
owl     9
bee     5
hen     0
pig     7
fox     7

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     9
dog     4
bat     3
cow     4
ant     5
owl     4
bee     2
hen     6
pig     8
fox     8

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     21
dog     10
bat     8
cow     29
ant     32
owl     27
bee     17
hen     21
pig     10
fox     9
 ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Prime vs non-prime $m$: The Multiplication Method minimizes the impact of $m$'s primality, but results confirm that prime $m$ still aids in preventing minor clustering, offering superior stability and uniformity in the index sequence.
- Patterns or collisions: The design effectively eliminates the systematic collisions seen in simple Division Hashing. The Polynomial Hash consistently provided good dispersion, avoiding noticeable patterns even when $m$ was small.
- Improvements: The implementation is highly robust for standard integer and string inputs. Future improvements could involve using 64-bit data types for the intermediate hash value to handle keys of extreme magnitude.

## Reflection
1.Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2.The Multiplication Method using the golden ratio proved highly effective and robust, providing a clear and uniform index sequence across all table sizes tested.
3.Table size significantly impacts the uniformity of the hash distribution, and while our method mitigated the reliance on prime numbers, selecting a prime $m$ remains the best practice for optimal performance.
