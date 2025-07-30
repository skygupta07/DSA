// maximizeCircularSubarraySumKadanesAlgo.cpp

#include <bits/stdc++.h>
using namespace std;



// asked in uber -> will give tle 
class Solution {
public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        
        int maxi = INT_MIN; // Initialize maximum sum to a very small value
        
        // Iterate over all possible starting points
        for (int i = 0; i < n; i++) {
            int current_sum = 0; // Reset current sum for each starting point
            
            // Traverse the array in a circular manner
            for (int j = 0; j < n; j++) {
                int idx = (i + j) % n; // Wrap-around using modulo operator
                current_sum += arr[idx]; // Add current element to sum
                maxi = max(maxi, current_sum); // Update the maximum sum
            }
        }
        
        return maxi; // Return the maximum circular subarray sum
    }
};



// if i == n -1  -> can chose element as first element.
/*
har element ko starting element banne ka mauka diya...
jaha se bhi start hoga just uske ek peeche wale element tak jaaega..
aur iterate karte waqt mai hi global maximum variable ko maximize karte rehna...

*/


// optimise using circular kadane's algorithm...

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxSubarraySum(vector<int> &arr, int n) {
    int totalSum = 0, maxSum = INT_MIN, currMax = 0;
    int minSum = INT_MAX, currMin = 0;

    for (int i = 0; i < n; i++) {
        totalSum += arr[i];

        // Kadane's for max subarray sum
        currMax = max(currMax + arr[i], arr[i]);
        maxSum = max(maxSum, currMax);

        // Kadane's for min subarray sum
        currMin = min(currMin + arr[i], arr[i]);
        minSum = min(minSum, currMin);
    }

    // If all elements are negative, maxSum is the result
    if (maxSum < 0) return maxSum;

    // Maximum of non-circular and circular subarray sums
    return max(maxSum, totalSum - minSum);
}

