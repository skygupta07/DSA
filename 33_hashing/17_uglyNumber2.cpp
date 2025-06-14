// uglyNumber2.cpp

#include <bits/stdc++.h>
using namespace std;


/*

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.


Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

*/

class Solution {
public:
    int nthUglyNumber(int n) {
        
        if(n <= 0) return false; // Handle edge case where n is less than or equal to 0
        if(n == 1) return true;  // Base case: the first ugly number is 1
        
        // Initialize three pointers for multiples of 2, 3, and 5
        int t2 = 0, t3 = 0, t5 = 0;

        // Create a vector to store the first n ugly numbers
        vector <int> k(n);

        k[0] = 1;  // The first ugly number is 1

        // Generate the next ugly numbers until we reach the nth one
        for(int i = 1; i < n; i++) {

            // CONCEPT - The next ugly number is the minimum of the next multiples of 2, 3, and 5
            k[i] = min( { k[t2]*2, k[t3]*3, k[t5]*5} );

            // Increment the pointer corresponding to the factor that was used
            if(k[i] == k[t2] * 2) t2++;  // If the next ugly number is a multiple of 2, increment t2
            if(k[i] == k[t3] * 3) t3++;  // If the next ugly number is a multiple of 3, increment t3
            if(k[i] == k[t5] * 5) t5++;  // If the next ugly number is a multiple of 5, increment t5
        
        }

        // The nth ugly number is stored in the (n-1)th position (0-based index)
        return k[n-1];
    }
};
