// numberOfSubarraysWithOddSum.cpp

/*

Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,3,5]
Output: 4

Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.


Example 2:

Input: arr = [2,4,6]
Output: 0

Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.


Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16
 

Constraints:

1 <= arr.length <= 1e5
1 <= arr[i] <= 100

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

        const int MOD = 1e9 + 7;
    
        int numOfSubarrays(vector <int>& arr) {
            int n = arr.size();

            long long evenCount = 1; // Initially, prefix sum 0 is even.
            long long oddCount = 0;

            long long count = 0;    // Final answer count.
            long long prefSum = 0;
    
            for (int i = 0; i < n; i++) {
                prefSum += arr[i];
    
                // Correctly check if prefSum is even. 
                // my mistake that I forgot brackets here..
                if ((prefSum & 1) == 0) {
                    // If current prefix sum is even, then a subarray ending here is odd
                    // if it starts after a prefix with odd sum.
                    count = (count + oddCount) % MOD;
                    evenCount++;
                } 
                
                else {
                    // If current prefix sum is odd, then a subarray ending here is odd
                    // if it starts after a prefix with even sum.
                    count = (count + evenCount) % MOD;
                    oddCount++;
                }
                
            }
    
            return count;
        }
    };
    