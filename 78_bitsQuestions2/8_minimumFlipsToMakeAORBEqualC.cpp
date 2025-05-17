// minimumFlipsToMakeAORBEqualC.cpp

/*

Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of 
a and b to make ( a OR b == c ). (bitwise OR operation).

Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 
in their binary representation.

Example 1:

Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)


Example 2:

Input: a = 4, b = 2, c = 7
Output: 1


Example 3:

Input: a = 1, b = 2, c = 3
Output: 0

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minFlips(int a, int b, int c) {
            int count = 0;
    
            while (a > 0 || b > 0 || c > 0) {
                int bitA = a & 1;  // Extract LSB of a
                int bitB = b & 1;  // Extract LSB of b
                int bitC = c & 1;  // Extract LSB of c
    
                if ((bitA | bitB) != bitC) {
                    if (bitC == 1) count += 1; // We need at least one 1, so flip 0 → 1
                    else count += (bitA + bitB); // If bitC is 0, we need to flip all 1s to 0
                }
    
                a >>= 1; // Right shift a
                b >>= 1; // Right shift b
                c >>= 1; // Right shift c
            }
    
            return count;
        }
    };
    