
// largestSubarrayWithZeroSum


/*

Given an array arr[] containing both positive and negative integers, 
the task is to find the length of the longest subarray with a sum equals to 0.

Note: A subarray is a contiguous part of an array, formed by selecting one or more consecutive elements 
while maintaining their original order.

Examples:

Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5

Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].


Input: arr[] = [2, 10, 4]
Output: 0
Explanation: There is no subarray with a sum of 0.


Input: arr[] = [1, 0, -4, 3, 1, 0]
Output: 5

Explanation: The longest subarray with sum equals to 0 is [0, -4, 3, 1, 0]


Constraints:
1 ≤ arr.size() ≤ 1e6
−1e3 ≤ arr[i] ≤ 1e3

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxLen(vector <int> &arr) {

        int n = arr.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += arr[j];

                if (sum == 0) maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;

    }
};
class Solution
{
public:
    // Function ka naam: maxLen
    // Purpose: input array 'arr' me se sabse lambi subarray (continuous elements ka group) dhundhna jiska sum zero ho
    int maxLen(vector<int> &arr) {
        int n = arr.size(); // Total elements count kar liya

        // unordered_map use kiya gaya hai to store prefix sum and its first occurrence index
        // key = prefix sum, value = first index jaha ye prefix sum mila tha
        unordered_map <int, int> prefixSumMap; 

        int sum = 0;      // Ye variable cumulative prefix sum ko track karta hai
        int maxLen = 0;   // Ye maximum length store karega jaha tak subarray ka sum zero hai

        // Traverse the array
        for (int i = 0; i < n; i++) {
            sum += arr[i]; // Har element ka cumulative sum calculate kar rahe hain

            // Case 1: Agar sum khud hi 0 ban gaya, to matlab 0 se lekar i tak ka subarray ka sum 0 hai
            if (sum == 0) {
                maxLen = i + 1; // Index 0 se lekar i tak length = i+1
            }

            // Case 2: Agar same sum pehle bhi kahin aaya hai
            // To iska matlab, beech ka subarray ka sum 0 tha (because net increase/decrease hua hi nahi)
            if (prefixSumMap.find(sum) != prefixSumMap.end()) {
                // Length calculate karo: current index - pehli baar jaha ye sum aaya tha
                maxLen = max(maxLen, i - prefixSumMap[sum]);
            }

            else {
                // Agar ye sum pehli baar aaya hai, to uska index store karo
                // Kyuki hume sirf pehli occurrence chahiye to get longest possible subarray
                prefixSumMap[sum] = i;
            }
        }

        return maxLen; // Finally return karo max length of zero-sum subarray
    }
};

/*
iterating over the subarray calculate its sum
if sum == 0 then maximise length...

brute force approach...
O(n square) gives tle...

*/

