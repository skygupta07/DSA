// findPivotInteger.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all elements
between x and n inclusively.

Return the pivot integer x. If no such integer exists, return -1.
It is guaranteed that there will be at most one pivot index for the given input.

Example 1:

Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.


Example 2:

Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.


Example 3:

Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.


Constraints:

1 <= n <= 1000

*/

class Solution{
public:
    // Utility function to calculate sum of first j natural numbers (1 + 2 + ... + j)
    int sum(int i, int j){
        return j * (j + 1) / 2; // Formula: n(n+1)/2
    }

    int pivotInteger(int n){
        int total = 0;

        // Step 1: Calculate the total sum from 1 to n
        for (int i = 1; i <= n; i++){ // or total = sum(0, n-1)
            total += i;
        }

        // Step 2: Try every number from 1 to n as the possible pivot
        for (int j = 1; j <= n; j++){
            // sum(1, j) gives left sum from 1 to j
            // total - sum(1, j) + j gives right sum from j to n (we subtract left part and add j once because it's common)

            if (sum(1, j) == total - sum(1, j) + j){
                return j; // Found the pivot where left sum == right sum
            }
        }

        return -1; // No pivot found
    }
};
