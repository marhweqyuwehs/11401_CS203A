/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp
    - 2025/11/30: Finalized hash functions based on user's Multiplication Method and Polynomial Rolling Hash.

   Developer: marhweqyuwehs<tsai755197@gmail.com>
 */
#include "hash_fn.hpp"
#include<iostream>
#include <string>
#include <cmath>  
using namespace std;

//Computes the hash index for an integer key using the Multiplication Method.
//Uses the Golden Ratio constant A = (sqrt(5) - 1) / 2.
int myHashInt(int key, int m) {
    if(m<=0){
    cout << " size m must be positive." << "\n"; //avoid negative and 0
    return 0;}
    const double A = 0.6180339887;  // Multiplication hash constant A((√5 - 1) / 2)
    double frac = (key * A) - (int)(key * A);   // Calculate the fractional part: kA mod 1
    return static_cast<int>(m * frac);
}

 //Computes the hash index for a string key using the Polynomial Rolling Hash.
int myHashString(const std::string& key, int m) { 
    if (m <= 0) {
        cout << "size m must be positive." << "\n"; //avoid negative and 0
        return 0;
    }
    const int P = 31; 
    long long hashValue = 0;
    long long power = 1; 

    for (char c : key) {
        int charVal = (int)c; 
        hashValue = (hashValue + (long long)charVal * power) % m;
        power = (power * P) % m; 
    }

    return (int)hashValue;
}