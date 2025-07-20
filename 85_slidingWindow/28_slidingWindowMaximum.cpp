#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(); // Total number of elements in the input array

        vector<int> maxIdx; // Deque-like vector to store indices of potential maximum elements
        vector<int> ans(n - k + 1); // Result vector to store the maximum of each sliding window

        int left = 0; // Pointer to track the leftmost valid index in the deque
        
        // Traverse the array
        for (int i = 0; i < n; i++) {
            // Maintain the deque to only store indices of elements in decreasing order
            // If the current element is greater than or equal to the last indexed element in deque,
            // pop the indices from the back since they can no longer be maximum.
            while (maxIdx.size() > left && nums[i] >= nums[maxIdx.back()]) {
                maxIdx.pop_back();
            }

            // Add the current element's index to the deque
            maxIdx.push_back(i);

            // If the leftmost index in the deque is out of the current sliding window range, increment `left`
            if (maxIdx[left] == i - k) {
                left++;
            }

            // Once the window reaches size `k`, start recording the maximums
            // The maximum of the current window is the value at the index `maxIdx[left]`
            if (i >= k - 1) {
                ans[i - k + 1] = nums[maxIdx[left]];
            }
        }

        // Return the resulting array containing the maximums of all sliding windows
        return ans;
    }
};



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(); // Total number of elements in the input array

        vector<int> maxIdx; // Deque-like vector to store indices of potential maximum elements
        vector<int> ans(n - k + 1); // Result vector to store the maximum of each sliding window

        int left = 0; // Pointer to track the leftmost valid index in the deque
        
        // Traverse the array
        for (int i = 0; i < n; i++) {
            // Maintain the deque to only store indices of elements in decreasing order
            // If the current element is greater than or equal to the last indexed element in deque,
            // pop the indices from the back since they can no longer be maximum.
            while (maxIdx.size() > left && nums[i] >= nums[maxIdx.back()]) {
                maxIdx.pop_back();
            }

            // Add the current element's index to the deque
            maxIdx.push_back(i);

            // If the leftmost index in the deque is out of the current sliding window range, increment `left`
            if (maxIdx[left] == i - k) {
                left++;
            }

            // Once the window reaches size `k`, start recording the maximums
            // The maximum of the current window is the value at the index `maxIdx[left]`
            if (i >= k - 1) {
                ans[i - k + 1] = nums[maxIdx[left]];
            }
        }

        // Return the resulting array containing the maximums of all sliding windows
        return ans;
    }
};
