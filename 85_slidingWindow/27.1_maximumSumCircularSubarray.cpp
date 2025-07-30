// maximumSumCircularSubarray.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a circular integer array nums of length n, 
return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. 
Formally, the next element of nums[i] is nums[(i + 1) % n] 
and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. 
Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], 
there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.


Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.


Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 1e4
-3 * 1e4 <= nums[i] <= 3 * 1e4

*/


// o(n^2) brute force

class Solution {
public:

    int maxSubarraySumCircular(vector <int> &nums) {
        int n = nums.size();
        
        int maxSum = INT_MIN;
        

        for (int i=0; i<n; i++){
            int sum = 0; // imp to reset the sum for current starting point

            for (int j=0; j<n; j++){    // ye to kamal hogaya ki inner wala loop bhi zero se hi chal rha h...

                sum += nums[(i+j) % n]; // yaha circular subarray bhi lelene h na to ghuma ke bhi to wahi element hi consider hoga sum mai.. so (i + j)
                maxSum = max(maxSum, sum);

            }
        }

        return maxSum;
    }

};

// kadanes algo -> O(n)
class Solution {
public:

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        // find maximum subarray sum using kadane's algo
        int currMax = 0;
        int maxSum = INT_MIN;
        
        for (int i=0; i<n; i++){
            currMax = max(currMax + nums[i], nums[i]);
            maxSum = max(maxSum, currMax);
        }

        int currMin = 0;
        int minSum = INT_MAX;

        // chalaki se isi loop mai hi totalSum bhi calculate kar lijiye na...

        int totalSum = 0;

        for (int i=0; i<n; i++){
            currMin = min(currMin + nums[i], nums[i]);
            minSum = min(minSum, currMin);

            totalSum += nums[i];
        }

        // if all elements were negative then totalSum == minSum => simply return jo bhi maxSum ban chuka hoga..

        if (totalSum == minSum) return maxSum;

        // nahi to in general ya to maxSum aur (totalSum - minSum) mai se maximise karke return kardo..

        return max(maxSum, totalSum - minSum);
    }
};