/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h
    - 2025/11/30: implement hash functions based on Multiplication Method and Polynomial Rolling Hash.

   Developer: marhweqyuwehs<tsai755197@gmail.com>
 */

#include "hash_fn.h"
#include <stdio.h>
#include <string.h>
#include <math.h> 
//Computes the hash index for an integer key using the Multiplication Method.
//Uses the Golden Ratio constant A = (sqrt(5) - 1) / 2.
int hash_int(int key, int m) { 
    if (m <= 0) {
        fprintf(stderr, "size m must be positive.\n"); //avoid negative and 0
        return 0;
    }

    const double A = 0.6180339887; // Multiplication hash constant A((√5 - 1) / 2)
    double k_double = (double)key; // Calculate the fractional part: kA mod 1
    double frac = (k_double * A) - floor(k_double * A);// h(k) = floor(m * frac)
    return (int)(m * frac);
}

// Computes the hash index for a string key using the Polynomial Rolling Hash.
int hash_string(const char *key, int m) { 
    if (m <= 0 || key == NULL) {
        fprintf(stderr, "size m must be positive.\n"); //avoid negative and 0
        return 0;
    }
    const int P = 31; 
    long long hashValue = 0;
    long long power = 1; 

    for (int i = 0; key[i] != '\0'; i++) {
        int charVal = (int)key[i]; 
        hashValue = (hashValue + (long long)charVal * power) % m;// Core computation: hash_value = (hash_value + char_val * P^i) mod m
        power = (power * P) % m; // Update power = P^(i+1) mod m
    }

    return (int)hashValue;
}