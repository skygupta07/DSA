// maximumSubarray.cpp

/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


*/

#include <bits/stdc++.h>
using namespace std;

// currentMaxSum and  GlobalMaxSum
class Solution {
public:
    int maxSubArray(vector<int>& v){
        int globalMaxSum = v[0];
        int currMaxSum = v[0];

        for (int i=1; i<v.size(); i++){
            currMaxSum = max(currMaxSum + v[i], v[i]);
            globalMaxSum = max(globalMaxSum , currMaxSum);
        }
        return globalMaxSum;    
    }
};


//A subarray is a contiguous non-empty sequence of elements within an array
// ya to tum current element ko include karo ya phir current element hi itna capable ho ki 
// usi se start karo....




// O(n^3) solution gives tle
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;

        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                int sum = 0;
                for (int k=i; k<=j; k++){
                    sum += nums[k];
                }
                maxSum = max(sum, maxSum);
            }
        }

        return maxSum;
        
    }
};

// t.c. = O(n^3)

// brute -> better -> optimal 
// brute force -> finding all subsequence from i to j and updating the maxSum variable simultaneously...




// using kadane's algorithm...


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxSum = INT_MIN;
        int sum = 0;

        for (int i=0; i<n; i++){
            sum += nums[i];

            if (sum > maxSum ) maxSum = sum;

            if (sum < 0) sum = 0;
        }

        return maxSum;
        
    }
};


// using kadane's algorithm...



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxSum = INT_MIN;
        int sum = 0;

        for (int i=0; i<n; i++){
            sum += nums[i]; // ka -> kaam 

            if (sum > maxSum ) maxSum = sum;    // da -> dagabaaji

            if (sum < 0) sum = 0;   // ne -> negative check 
        }

        return maxSum;
        
    }
};


