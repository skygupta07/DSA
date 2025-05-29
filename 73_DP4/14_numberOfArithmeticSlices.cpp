#include <bits/stdc++.h>
using namespace std;

/*

An integer array is called arithmetic if it consists of at least three elements 
and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.

Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.


Example 2:

Input: nums = [1]
Output: 0

*/


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int count = 0; // yeh variable continuous arithmetic streak ka count karega
        int sum = 0;   // yeh final answer store karega (total number of arithmetic slices)

        // Hum loop 2nd index se start karenge kyunki 3 elements ka group dekhna hota hai
        for (int i = 2; i < n; i++) {

            // Check kar rahe hain ki current 3 elements ek arithmetic sequence mein hain ya nahi
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                count++; // agar hain, to streak badha do
            }
            else {
                // Agar streak toot jaata hai, to formula se us streak ke slices count karo:
                // For streak of length k (count consecutive triplets), total slices = k*(k+1)/2
                sum += (count) * (count + 1) / 2;

                // Streak reset kar do kyunki ab arithmetic pattern toot gaya hai
                count = 0;
            }
        }

        // Loop ke baad bhi ho sakta hai streak chal rahi ho,
        // isliye last streak ka result bhi add karna padega
        sum += (count) * (count + 1) / 2;

        return sum;
    }
};
