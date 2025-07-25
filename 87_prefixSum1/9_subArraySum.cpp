// subarraySum.cpp

/*

✅ Question Title:
Count Subarrays With Sum Equal to Goal

📄 Problem Statement:
You are given a binary array nums (i.e., it contains only 0s and 1s), and an integer goal.
Your task is to return the number of non-empty subarrays whose elements sum up to goal.

A subarray is a contiguous part of the array.

🧪 Example 1:
Input: nums = [1,0,1,0,1], goal = 2  
Output: 4  

Explanation: The 4 subarrays are:
[1,0,1], [0,1,0,1], [1,0,1], and [1,0,1]


🧪 Example 2:
Input: nums = [0,0,0,0,0], goal = 0  
Output: 15  

Explanation: All possible subarrays with sum 0 are counted.


⚙️ Constraints:
1 <= nums.length <= 3 * 1e4
nums[i] is either 0 or 1

0 <= goal <= nums.length
✨ Follow-up:

Can you solve this in O(n) time and O(1) space?
💡 Solution Approaches:


✅ Approach 1: Sliding Window (Two Pointer)

This approach works because the array is binary (0 or 1).
We count the number of subarrays whose sum is at most goal, 
and subtract those with at most goal - 1:

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal-1);
}


✅ Approach 2: Prefix Sum + Hash Map

Track the prefix sums and store their frequencies in a map.

int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map <int, int> freq;
    freq[0] = 1;

    int ans = 0, preSum = 0;

    for (int el : nums) {
        preSum += el;

        ans += freq[preSum - goal];
        freq[preSum]++;
    }
    return ans;
}
    

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int atMost(vector <int> &nums, int goal){
        int i=0, j=0, ans=0, sum=0, n= nums.size();

        while (j<n){
            sum += nums[j]; // added its contribution -> to increase the sum
            
            while (sum > goal && i<=j){ // to decrease the sum
                sum -= nums[i];
                i++;
            }

            // is loop se bahar aaya matlab sum <= goal 

            ans += j-i+1;
            j++;
        }
        return ans;
    }


    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};





class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int preSum = 0;

        unordered_map <int,int> freq;
        freq[0] = 1;

        for (auto el : nums){
            preSum += el;

            if (freq.find(preSum - goal) != freq.end())
                ans += freq[preSum - goal];

            freq[preSum]++;
        }

        return ans;
    }
};









/*
lc 560, lc 930
find all the subarrays and simultaneously compute the sum also...

to find range sum we have
1. prefix sum
2. sparse table
3. fenwick tree / segment tree

easy and best is to choose prefix sum...

two pointer mai aapka simultaneously window shrink and expand also......i.e. value inc , dec. or inc then dec

basic template: 

while (j<n){
    while (sum > goal){
        i++;
    }
    j++;
}



sliding window / two pointer is applicable -> when movement is directional....

sliding window lagaya   i se leke j tak window 
when sum of sliding window becomes less than goal you simply keep on increasing your j.....when the sum increases 
you simply increase i..... but this mentality causes confusion in case of negative element present in the array....



// binary wala ek problem hai usme you can't apply simple two pointer...
because if you shrink first then you are getting different combination and if you are expanding first then you are
getting different combinations...

binary wala array de diya matlab array mai zero aur one hai....
but still by shrinking  newSum <= sum
and expanding.          newSum >= sum

we can't directly deal with == sum.     we have to deal with <= sum or >= sum

number of subarray with sum == goal     => number of subarray with sum <= goal - number of subarray with sum < goal

number of subarrays are j-i+1


*/