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
| 10             | 6, 8, 9, 1, ... The Multiplication Method is robust, but slight clustering is visible in smaller non-prime tables.
| 11             | 9, 1, 3, 4, ...        

Distribution is noticeably better and more uniform.
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

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
- Example output for integers:
  ```
  === Hash Function Observation (C Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  ...

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      0
  ...

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  ...

  === Hash Function Observation (C++ Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      1
  22      2
  ...

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      10
  22      0
  ...

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      21
  22      22
  ...
  ```

- Example output for strings:
  ```
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...

  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat     0
  dog     0
  ...
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
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.
