#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr){

        int maxSum = INT_MIN; // Stores the maximum subarray sum
        int currSum = 0;     // Stores the current running sum

        for (int num : arr){
            currSum += num;                    // Add the current element to the running sum
            maxSum = max(maxSum, currSum); // Update the maximum sum if needed
            
            if (currSum < 0) currSum = 0;               // If the running sum becomes negative, reset it to 0         
        }

        return maxSum;
    }
};