// maximumSumOfThreeNonOverlappingSubarray.cpp

/*

Given an integer array nums and an integer k, find three non-overlapping subarrays of length k 
with maximum sum and return them.

Return the result as a list of indices representing the starting position of each interval (0-indexed). 
If there are multiple answers, return the lexicographically smallest one.


Example 1:

Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically smaller.


Example 2:

Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
Output: [0,2,4]
 

Constraints:

1 <= nums.length <= 2 * 10pow4
1 <= nums[i] < 2pow16
1 <= k <= floor(nums.length / 3)

*/


class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();

        // Step 1: Precompute sum of all k-length subarrays using sliding window
        vector<int> ksum(n - k + 1, 0);   // stores sum of subarray starting at index i with length k
        ksum[0] = accumulate(nums.begin(), nums.begin() + k, 0);
        for (int i = 1; i <= n - k; ++i) {
            ksum[i] = ksum[i - 1] - nums[i - 1] + nums[i + k - 1];
        }

        // Step 2: Compute L[i] = index of max sum subarray in ksum[0..i]
        vector<int> L(n - 3 * k + 1, -1); // best left subarray ending before i
        int maxKsum = ksum[0];
        L[0] = 0;

        for (int i = 1; i <= n - k; ++i) {
            if (i > n - 3 * k) continue; // middle must have room for right subarray

            if (ksum[i] > maxKsum) {
                maxKsum = ksum[i];
                L[i] = i;
            } else {
                L[i] = L[i - 1]; // carry forward best left index so far
            }
        }

        // Step 3: Compute R[i] = index of max sum subarray in ksum[i..end]
        vector<int> R(n - 3 * k + 1, -1); // best right subarray starting after i+2k
        maxKsum = ksum.back();
        R.back() = n - k;

        for (int i = n - k - 1; i >= 2 * k; --i) {
            if (ksum[i] >= maxKsum) {  // prefer earlier index for lexicographically smaller answer
                maxKsum = ksum[i];
                R[i - 2 * k] = i;
            } else {
                R[i - 2 * k] = R[i + 1 - 2 * k];  // carry forward best right index
            }
        }

        // Step 4: Try each middle subarray (starting at i+k) and combine with best L and R
        vector<int> ans(3, -1);
        int max3K = 0;

        for (int i = 0; i <= n - 3 * k; ++i) {
            int left = L[i];
            int mid = i + k;
            int right = R[i];

            // Ensure non-overlapping: left < mid < right
            int sum3K = ksum[left] + ksum[i + k] + ksum[right];

            if (sum3K > max3K) {
                max3K = sum3K;
                ans = {left, mid, right};
            }
        }

        return ans;
    }
};
