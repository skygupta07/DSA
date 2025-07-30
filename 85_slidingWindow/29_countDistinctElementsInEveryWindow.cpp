// countDistinctElementsInEveryWindow.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given an integer array arr[] and a number k. 
Find the count of distinct elements in every window of size k in the array.

Examples:

Input: arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
Output:  [3, 4, 4, 3]

Explanation: Window 1 of size k = 4 is 1 2 1 3. 
Number of distinct elements in this window are 3. 

Window 2 of size k = 4 is 2 1 3 4. Number of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number of distinct elements in this window are 3.

Input: arr[] = [4, 1, 1], k = 2
Output: [2, 1]

Explanation: Window 1 of size k = 2 is 4 1. Number of distinct elements in this window are 2. 
Window 2 of size k = 2 is 1 1. Number of distinct elements in this window is 1. 

Input: arr[] = [1, 1, 1, 1, 1], k = 3
Output: [1, 1, 1]


Constraints:
1 <= k <= arr.size() <= 1e5
1 <= arr[i] <= 1e5

*/

class Solution {
public:
    vector<int> countDistinct(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> ans;

        // Edge case: if k > n
        if (k > n) return ans;

        unordered_map<int, int> freq;  // Stores frequency of elements in window

        // Step 1: Process the first window
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }
        ans.push_back(freq.size());  // Number of distinct elements in first window

        // Step 2: Slide the window
        for (int i = k; i < n; i++) {
            // Remove the outgoing element (left-most of the previous window)
            freq[nums[i - k]]--;

            // Remove completely if count becomes 0 {very very important}
            if (freq[nums[i - k]] == 0) {
                freq.erase(nums[i - k]);  
            }

            // Add the new incoming element
            freq[nums[i]]++;

            // Store current distinct count
            ans.push_back(freq.size());

        }

        return ans;
    }
    
};

