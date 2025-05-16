// minimumRecolorsToGetKConsecutiveBlackBlocks

/*

You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', 
representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, 
respectively.

You are also given an integer k, which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block such that it becomes a black block.

Return the minimum number of operations needed such that there is at least one occurrence of k 
consecutive black blocks.

 

Example 1:

Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
Explanation:
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW". 
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.

Example 2:

Input: blocks = "WBWBBBW", k = 2
Output: 0
Explanation:
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.
 

Constraints:

n == blocks.length
1 <= n <= 100
blocks[i] is either 'W' or 'B'.
1 <= k <= n

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.length();
            int left = 0, right = 0; // --- (1)
            
            int wc = 0; // white count
            int mini = INT_MAX; // Initialize with a large value
    
            // Initialize the first window of size k
            while (right < k) {   // ----- (2)
                if (blocks[right] == 'W') wc++;

                right++; // ------- (3)
            }
    
            mini = wc; // Store the count of 'W' in the first window
    
            // Sliding window
            while (right < n) {
                if (blocks[right] == 'W') wc++; // Add new element
                if (blocks[left] == 'W') wc--;  // Remove the outgoing element
    
                mini = min(mini, wc); // Update the global minimum
                right++;
                left++;
            }
    
            return mini;
        }
    };
    