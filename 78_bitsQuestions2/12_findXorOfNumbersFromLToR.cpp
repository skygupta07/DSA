#include <bits/stdc++.h>
using namespace std;

/*

You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

Example:

Input: 
L = 4, R = 8 
Output:
8 

Explanation:
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8

Your Task:

Your task is to complete the function findXOR() which takes two integers 
l and r and returns the XOR of numbers from l to r.

Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).

Constraints:

1<= l<=r <=10pow9

*/



class Solution {
  public:

    // Function to compute XOR from 0 to n in O(1)
    int computeXOR(int n) {
        // There is a pattern in XOR from 0 to n:
        // If n % 4 == 0, the result is n
        // If n % 4 == 1, the result is 1
        // If n % 4 == 2, the result is n + 1
        // If n % 4 == 3, the result is 0

        if (n % 4 == 0) return n;       // Pattern: 0 ^ 1 ^ 2 ^ ... ^ n == n
        if (n % 4 == 1) return 1;       // Pattern ends in 1
        if (n % 4 == 2) return n + 1;   // Pattern ends in n+1
        return 0;                       // Pattern resets to 0
    }

    // Function to compute XOR from l to r using XOR from 0 to n
    int findXOR(int l, int r) {
        // XOR from l to r is computed as:
        // XOR(l to r) = XOR(0 to r) ^ XOR(0 to l-1)

        // This works because XOR is reversible:
        // (a ^ a = 0), so the common part (0 to l-1) cancels out.

        return computeXOR(r) ^ computeXOR(l - 1);
    }
};
