// maximumAverageSubarray1.cpp

/*

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value 
and return this value. Any answer with a calculation error less than 10-5 will be accepted.


Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000

Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75


Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 1e5
-1e4 <= nums[i] <= 1e4

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        vector <int> pref(n, 0);
        pref[0] = nums[0];
        for (int i=1; i<n; i++) pref[i] = nums[i] + pref[i-1];

        double maxAvg = -1e9;

        for (int left = 0; left <= n-k; left++){
            int right = left + k - 1;

            // arey ha ye syntax to mujhe yaad h ... 
            // ha ki agar wo left wala pointer zero par h tab to arr[left] se leke arr[right] tak ka sum 
            // simply pref[right] se mil jaata h....

            // but left agar zero index par nahi hota tab to bhai pref[right] - pref[left - 1]
            int sum = (left == 0) ? pref[right] : pref[right] - pref[left - 1];

            double subarrAvg = (double)sum/k;   // bhai very imp syntax ki (double) hi bracket mai rahega bas..
            // otherwise wo integer division hi perform karne lagta h...

            maxAvg = max(maxAvg, subarrAvg);
        }

        return maxAvg;
    }
};