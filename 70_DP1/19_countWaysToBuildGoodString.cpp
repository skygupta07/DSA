// countWaysToBuildGoodString.cpp

/*

Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, 
and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high 
(inclusive).

Return the number of different good strings that can be constructed satisfying these properties. 
Since the answer can be large, return it modulo 10pow9 + 7.

 

Example 1:

Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation: 
One possible valid good string is "011". 
It can be constructed as follows: "" -> "0" -> "01" -> "011". 
All binary strings from "000" to "111" are good strings in this example.


Example 2:

Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".
 

Constraints:

1 <= low <= high <= 10pow5
1 <= zero, one <= low


*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    const int mod = 1e9 + 7; // Define a constant for the modulo operation to avoid overflow.

    // Recursive function to calculate the number of ways to form a string of length `target`
    int score(int target, vector<int> &dp, int numZero, int numOne) {
        
        if (target == 0) return 1; // Base case: If target length is 0, there is exactly one valid way (empty string).
        if (target < 0) return 0;  // Base case: If target length becomes negative, it's not valid.

        if (dp[target] != -1) return dp[target]; // Memoization: If already calculated, return the stored result.

        long long sum;

        // Calculate the number of ways by including `numOne` or `numZero`
        sum = score(target - numOne, dp, numOne, numZero) + score(target - numZero, dp, numOne, numZero);

        // Store the result in dp array and take modulo to handle large numbers.
        return dp[target] = (sum % mod);
        
    }

    // Main function to count good strings within the range [low, high]
    int countGoodStrings(int low, int high, int numZero, int numOne) {
        // Create a DP array initialized with -1 for memoization
        vector<int> dp(high + 1, -1);

        int ans = 0; // Variable to store the final answer.

        // Iterate through all target lengths in the range [low, high]
        for (int i = low; i <= high; i++) {
            // Add the number of ways to form a string of length `i` to the answer
            ans = ((ans % mod) + (score(i, dp, numOne, numZero) % mod)) % mod;
        }

        return ans; // Return the total count of good strings.
    }
};
