// maximumSumOfAPairWithEqualSumOfDigits.cpp

#include <bits/stdc++.h>
using namespace std;


/*

-> Problem Intuition:

We are given an array of positive integers. We have to find **two different elements** such that:
1. The sum of digits of both elements is the same.
2. Among all such valid pairs, we need to return the **maximum value of nums[i] + nums[j]**.

If no such valid pair exists, return -1.

-> Key Observations:

- A number ≤ 10^9 can have **at most 81** as its digit sum (since 9+9+... up to 9 digits = 9*9 = 81).
- So for each digit sum from 1 to 81, we can store the **maximum number** 
  seen so far with that digit sum.

- When we find another number with the same digit sum, 
we try to pair it with the previously stored maximum.

*/

class Solution {
public:

    int maximumSum(vector <int> &nums) {
        // maxSum[sum] stores the maximum number encountered with a digit sum 'sum'
        int maxSum[82] = {0}; // max possible digit sum is 81, so size 82 (0-81)
        
        int ans = -1; // final answer to store the max sum of any valid pair

        // Traverse all numbers in the array
        for (int x : nums) {
            int sum = 0, temp = x;

            // Step 1: Calculate digit sum of x
            while (temp != 0) {
                sum += temp % 10;  // get last digit and add to sum
                temp /= 10;        // remove last digit
            }

            // Step 2: If this digit sum has been seen before,
            // try to make a pair with previously max number of same digit sum
            if (maxSum[sum] != 0) {
                ans = max(ans, x + maxSum[sum]); // update max pair sum if better
            }

            // Step 3: Update the max number for this digit sum
            maxSum[sum] = max(maxSum[sum], x);
        }

        return ans; // Return result: max sum of valid pair or -1 if no such pair
    }
};


/*

Group numbers by their digit sum.

For each group, store the largest number encountered so far.

When another number with the same digit sum comes in, pair it with the existing largest one 
in that group and update the answer if this sum is greater than the previous maximum.

This is a greedy + hashing-style approach that avoids nested loops (O(n) time complexity).

*/