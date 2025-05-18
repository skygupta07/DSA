// findNthDigit.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an integer n, return the nth digit of the infinite integer sequence
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].


Example 1:

Input: n = 3
Output: 3

Example 2:

Input: n = 11
Output: 0
Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
... is a 0, which is part of the number 10.


Constraints:

1 <= n <= 2pow31 - 1

*/


class Solution{
public:
    int findNthDigit(int n){
        // to remember "lcs" 
        long long length = 1; // Number length (1-digit, 2-digit, ...)
        long long count = 9;  // Total numbers in this range
        long long start = 1;  // Starting number of this range

        while (n > length * count){
            n -= length * count; // Reduce `n` by the count of digits covered so far

            length++;            // Move to the next digit length (1 → 2 → 3 ...)
            count *= 10;         // Update the count of numbers (9, 90, 900, ...)
            start *= 10;         // Update the starting number (1, 10, 100, ...)
        }

        // Find the exact number containing the nth digit
        start += (n - 1) / length; // Get the number in this range
        string num = to_string(start);

        // Return the specific digit from the number
        return num[(n - 1) % length] - '0';
    }
};
