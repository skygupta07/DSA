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
        int n = blocks.length();  // Total number of blocks

        int left = 0, right = 0;  // Sliding window pointers

        int whiteCount = 0;       // Count of 'W' in current window
        int mini = INT_MAX;       // Store the minimum white blocks seen in any window of size k

        // Step 1: Initialize the first window of size k
        while (right < k) {  // First k elements
            if (blocks[right] == 'W') 
                whiteCount++;  // Count white blocks

            right++;  // Expand window to size k
        }

        // Store result of the first window
        mini = whiteCount;

        // Step 2: Slide the window to the right one character at a time
        while (right < n) {
            // Add new character to the window (at right)
            if (blocks[right] == 'W') 
                whiteCount++;

            // Remove the character going out of window (at left)
            if (blocks[left] == 'W') 
                whiteCount--;

            // Update minimum white count if current window has fewer whites
            mini = min(mini, whiteCount);

            // Move both pointers to slide window
            right++;
            left++;
        }

        return mini;  // Return the minimum number of white blocks to recolor
    }
};
