#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. 
After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that 
the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]


Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83


Example 3:

Input: arr = [1], k = 1
Output: 1
 


Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 10pow9
1 <= k <= arr.length

*/

// Recursive function with memoization to calculate max sum from idxex `idx` to end
int f(int idx, vector<int> &num, int k, vector<int> &dp) {
    int n = num.size();

    // ✅ Base Case: If we've gone past the last element, no contribution to sum
    if (idx == n) return 0;

    // 🧠 Return already computed result to avoid recomputation
    if (dp[idx] != -1) return dp[idx];

    int len = 0; // Tracks length of current partition
    int maxi = INT_MIN; // Tracks maximum value in the current partition
    int maxAns = INT_MIN; // Tracks the best possible sum from current idxex onward

    // Try all partition sizes from 1 to k (but not beyond array size)
    for (int j = idx; j < min(idx + k, n); j++) {
        len++; // Increase partition size
        maxi = max(maxi, num[j]); // Update max of the current partition

        // 🔁 Recursive call: Partition ends at `j`, next call starts from `j+1`
        int sum = len * maxi + f(j + 1, num, k, dp);

        // Update maxAns to keep track of the maximum total sum
        maxAns = max(maxAns, sum);
    }

    // Save result in dp and return
    return dp[idx] = maxAns;
}

// Driver function to initialize DP and start recursion from idxex 0
int maxSumAfterPartitioning(vector<int>& num, int k) {
    int n = num.size();

    // Initialize DP array with -1 to idxicate uncomputed states
    vector<int> dp(n, -1);

    // Start recursion from idxex 0
    return f(0, num, k, dp);
}

// Example usage
int main() {
    vector<int> num = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    int maxSum = maxSumAfterPartitioning(num, k);

    cout << "The maximum sum is: " << maxSum << "\n";

    return 0;
}



// bottom-up approach
// Function to fidx the maximum sum after partitioning the array.
int maxSumAfterPartitioning(vector<int>& num, int k) {
    int n = num.size();
    
    // Create a DP array to store the maximum sum.
    vector<int> dp(n + 1, 0);
    
    // Iterate through the array from right to left.
    for (int idx = n - 1; idx >= 0; idx--) {
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        
        // Loop through the next k elements (or remaining elements if k is smaller).
        for (int j = idx; j < min(idx + k, n); j++) {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        
        // Store the computed maximum sum in the DP array.
        dp[idx] = maxAns;
    }
    
    // The maximum sum after partitioning the entire array is stored in dp[0].
    return dp[0];
}

int main() {
    vector<int> num = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    int maxSum = maxSumAfterPartitioning(num, k);
    cout << "The maximum sum is: " << maxSum << "\n";
    return 0;
}

