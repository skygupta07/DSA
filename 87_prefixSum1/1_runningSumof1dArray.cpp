// runningSumof1dArray.cpp

/*

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.


Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].


Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].



Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
 

Constraints:

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        ans[0] = nums[0];   // threshold
        
        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] + nums[i];
        }
        return ans;
    }

};



class Solution {    // no extra memory used..
public:

    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        // zeroth element to wahi rahega.. no need to touch it...
        for (int i=1; i<n; i++){
            nums[i] = nums[i]+nums[i-1];
        }
        return nums;  
    }

};



// leetcode pe result vector banate ho (and uske index pe jaake element ko modify karna ho)
//  to uska size bhi mention kar diya karo.. otherwise heap memory full wala 
//error de deta hai.. 

/*

arr
0  1  2  3  4  5  6  7  8
5 10 15 20 25 30 35 40 45

pre
0  1  2  3  4  5   6   7   8
5 15 30 50 75 105 140 180 225

find 3rd index se 7th index tak ka sum -> 150
    === pre[7] - pre[2]


example 2 

arr
0  1  2  3  4  5  6  7  8 -> index
9  1  8  6  5  2  4  3  10 -> arr elements


pref
0  1  2  3  4  5  6  7  8 -> index
9  10 18 24 29 31 35 38 48 -> pref elements


*/