// magicNumber.cpp

#include <bits/stdc++.h>
using namespace std;

/*

A magic number is defined as a number that can be expressed as a power of 5 
or sum of unique powers of 5. First few magic numbers are 5, 25, 30(5 + 25), 125, 130(125 + 5), …


Given the value of n, find the n'th Magic number modulo 1e9 + 7.

Example 1:

Input: n = 1
Output: 5

Explanation: 1'st Magic number is 5.


Example 2:

Input: n = 2
Output: 25
Explanation: 2'nd Magic number is 25. 


Your Task:  
You don't need to read input or print anything. 
Your task is to complete the function nthMagicNo() which takes n input and returns the answer 
with modulo 1e9 + 7.

Expected Time Complexity: O(log n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 1e5

*/


class Solution {
public:
    
    const int MOD = 1e9 + 7;

    long long int nthMagicNo(int n) {

        long long int ans = 0;
        long long int power = 5;

    
        while (n > 0) {

            // If LSB is set, add current power of 5
            if (n & 1) {
                ans = (ans + power) % MOD;
            }

            // Move to next bit and increase power
            n >>= 1;

            power = (power * 5) % MOD;
        }

        return ans;
    }
};
