// swapOddAndEvenBits.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an unsigned integer n, You have  to swap all even-position bits 
with their rightside adjacent odd-position bits.

Examples:

Input: n = 23
Output: 43

Explanation: Binary representation of the given number  is 00010111 after swapping  
00101011 = 43 in decimal.


Input: n = 2
Output: 1
Explanation: Binary representation of the given number is 10 after swapping 01 = 1 in decimal.


Constraints:
1 ≤ n ≤ 1e9

*/


class Solution {
public:
    unsigned int swapBits(unsigned int n) {
        
        vector <int> bits;

        // Step 1: Extract bits from MSB to LSB (bit 31 to bit 0)
        for (int i = 31; i >= 0; i--) {
            bits.push_back((n >> i) & 1);
        }

        // Step 2: Swap even-position bits with adjacent odd-position bits
        // Note: Bit positions are 0-indexed from the left (MSB)
        // So actual positions in binary are:
        // bits[0] = bit 31, bits[1] = bit 30, ..., bits[31] = bit 0
        for (int i = 0; i <= 30; i += 2) {
            swap(bits[i], bits[i + 1]);
        }

        // Step 3: Convert bits vector back to unsigned int
        unsigned int res = 0;

        for (int i = 0; i < 32; i++) {
            res |= (bits[i] << (31 - i));  // Correct mapping back to bit positions
        }

        return res;
        
    }
};
