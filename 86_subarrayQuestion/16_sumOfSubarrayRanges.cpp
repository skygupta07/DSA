// sumOfSubarrayRanges.cpp

/*
You are given an integer array nums. 
The range of a subarray of nums is the difference between the largest and smallest element 
in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.
 

Example 1:

Input: nums = [1,2,3]
Output: 4

Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.


Example 2:

Input: nums = [1,3,3]
Output: 4

Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.


Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59

Explanation: The sum of all subarray ranges of nums is 59.
 

Constraints:

1 <= nums.length <= 1000
-1e9 <= nums[i] <= 1e9
 
Follow-up: Could you find a solution with O(n) time complexity?

*/


#include <bits/stdc++.h>
using namespace std;


// O(n square) -> brute..

class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {
        long long totalSum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int mini = nums[i];
            int maxi = nums[i];

            for (int j = i; j < n; j++) {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);

                // kahi kahi par modulo kaam nahi karta to phir usko jaisi khurak chahiye..
                // ho usme baat karna padta h...
                totalSum += (long long)(maxi - mini);
            }
        }

        return totalSum;
    }
};



// using monotonic stack...
// ans = sumOfSubarrayMaximum - sumOfSubarrayMinimum


class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector <int> prevGreater(n), nextGreater(n);
        vector <int> prevSmaller(n), nextSmaller(n);

        // For nextGreater - yaha strict inequality checking mai to phir next wale equal jarur kar dena...
        // it is to handle the edge cases...
        stack <int> stk;

        for (int i = 0; i < n; i++) {

            // monotonic stack
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                nextGreater[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            nextGreater[stk.top()] = n;
            stk.pop();
        }

        // For prevGreater - greater dhund rahe h to phir obviously smaller ko pop karo..
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                prevGreater[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            prevGreater[stk.top()] = -1;
            stk.pop();
        }

        // For nextSmaller
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                nextSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            nextSmaller[stk.top()] = n;
            stk.pop();
        }

        // For prevSmaller
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                prevSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            prevSmaller[stk.top()] = -1;
            stk.pop();
        }

        long long maxSum = 0, minSum = 0;
        
        for (int i = 0; i < n; i++) {

            long long leftMax = i - prevGreater[i];
            long long rightMax = nextGreater[i] - i;

            maxSum += leftMax * rightMax * nums[i];

            long long leftMin = i - prevSmaller[i];
            long long rightMin = nextSmaller[i] - i;
            
            minSum += leftMin * rightMin * nums[i];
        }

        return maxSum - minSum;
    }
};


