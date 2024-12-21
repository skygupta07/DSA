#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        int maxSoFar = INT_MIN; // Stores the maximum subarray sum
        int currentSum = 0;     // Stores the current running sum

        for (int num : arr) {
            currentSum += num;          // Add the current element to the running sum
            maxSoFar = max(maxSoFar, currentSum); // Update the maximum sum if needed
            if (currentSum < 0)         // If the running sum becomes negative, reset it to 0
                currentSum = 0;
        }

        return maxSoFar;
    }
};