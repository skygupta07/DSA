// jumpGame2.cpp

#include <bits/stdc++.h>
using namespace std;


/*


You are given a 0-indexed array of integers nums of length n. 
You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. 
In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n

Return the minimum number of jumps to reach nums[n - 1]. 
The test cases are generated such that you can reach nums[n - 1].

 
Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. 
Jump 1 step from index 0 to 1, then 3 steps to the last index.


Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 1e4
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].

*/


class Solution {
public:

    // Function to find the minimum number of jumps to reach the end
    int jump(vector <int> &nums) {
        
        int n = nums.size();           // Size of the input array
        
        int step = 0;                  // Kitne jumps liye hain ab tak
        
        int start = 0;
        int end = 0;        // Current range jahan tak pahuch sakte hain


        // Jab tak hum last index tak nahi pahuch jaate
        while (end < n - 1) {
            
            step++;                   // Ek aur jump lena padega
            int maxend = end + 1;     // Next range ka end initialize karo

            // Ab current window [start...end] ke andar check karo sabhi positions
            for (int i = start; i <= end; i++) {

                // Agar yahan se directly last index tak pahuch sakte ho, toh return current step
                if (i + nums[i] >= n - 1) return step;

                // maxend update karo taaki next window ka maximum reach mile
                maxend = max(maxend, i + nums[i]);
            }

            // Move the window forward
            start = end + 1;  // Nayi window ka start
            end = maxend;     // Nayi window ka end

        }

        // Total minimum jumps
        return step;

    }
};
