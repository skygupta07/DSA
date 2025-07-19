// findTheKthSmallestPairDistance.cpp

/*

The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance 
among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.


Example 1:

Input: nums = [1,3,1], k = 1
Output: 0

Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.


Example 2:

Input: nums = [1,1,1], k = 2
Output: 0


Example 3:

Input: nums = [1,6,1], k = 3
Output: 5
 

Constraints:

n == nums.length
2 <= n <= 1e4
0 <= nums[i] <= 1e6
1 <= k <= n * (n - 1) / 2

*/




#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int solve(vector <int> &nums, int diff){
        int count = 0;

        int j = 0;
        int n = nums.size();

        for (int i=0; i<n; i++){
            while (j<n && nums[j] - nums[i] <= diff) j++;
            count += j-i-1;
        }

        return count; 
    }



    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        // binary search on difference
        int lo = 0;
        int hi = nums[n-1] - nums[0];

        int ans = 0;

        while (lo <= hi){
            int mid = lo + (hi - lo)/2;

            // number of pairs that are smaller than mid difference..
            int count = solve(nums, mid);

            if (count >= k){
                ans = mid;
                hi = mid-1;
            }

            else{
                lo = mid + 1;
            }
        }
        return ans;
    }

};


// method 2 

class Solution {
public:

    // 🔹 This function counts how many pairs (i, j) exist such that:
    // i < j and (nums[j] - nums[i]) <= diff
    // i.e., number of pairs whose absolute difference is ≤ current `mid` (i.e., diff)
    
    int solve(vector <int> &nums, int k, int diff) {
        int count = 0;
        int j = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // j will keep moving forward till the difference condition breaks
            while (j < n && (nums[j] - nums[i]) <= diff) {
                j++;
            }

            // 🔹 Total pairs formed with nums[i] such that difference ≤ diff = (j - i - 1)
            // Because i is fixed and we moved j ahead till it violated condition
            count += (j - i - 1);
        }
        return count;
    }

    // 🔹 Main function to return the k-th smallest absolute difference among all pairs
    int smallestDistancePair(vector <int> &nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  // Sorting helps in applying two-pointer + binary search

        // 🔹 After sorting, the smallest absolute difference can be 0
        // (if duplicates exist), and max = max_element - min_element
        int lo = 0;
        int hi = nums[n - 1] - nums[0];

        int ans = -1;

        // Binary search on answer space — trying all possible differences
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // Count number of pairs whose difference is ≤ mid
            int count = solve(nums, k, mid);

            if (count >= k) {
                // Mid can be a potential answer, but let's try to find even smaller one
                // So move to the left side of search space
                ans = mid;
                hi = mid - 1;
            } else {
                // Too few pairs — means we need to allow bigger differences
                lo = mid + 1;
            }
        }

        return ans;
    }
};


/*

🧠 Intuition:
Sort the array so that difference between elements becomes predictable.
Binary search the difference d (range: 0 to max - min) and for each d, count how many pairs (i, j) exist with nums[j] - nums[i] <= d.
If count >= k, then d can be the answer (but we want the smallest such d).
Otherwise, we need to increase d to get enough pairs.


📊 Time & Space Complexity:
🔹 Time Complexity:

Sorting: O(n log n)
Binary Search: log(range) = log(nums[n-1] - nums[0]) ≈ log(maxDiff)
solve() runs in O(n) (since j only moves forward, not reset)
Total: O(n log n + n log(maxDiff))

🔹 Space Complexity:

O(1) auxiliary, as everything is done in-place (excluding recursion stack or output)

*/
