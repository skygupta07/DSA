// perfectSquares.cpp

/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; 
in other words, it is the product of some integer with itself.
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.


Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n){
        // dp[i] ka matlab: minimum number of perfect squares jinke sum se i ban sakta hai
        vector<int> dp(n + 1, INT_MAX);

        // 0 ko banane ke liye 0 numbers chahiye
        dp[0] = 0;

        // i = 1 to n tak iterate kar rahe hain
        for (int i = 1; i <= n; i++){
            // har perfect square j*j check kar rahe hain jo i se chhota ya equal ho
            for (int j = 1; j * j <= i; j++){
                // dp[i - j*j] already calculated hai, bas usme 1 add karo (kyunki j*j add karna pad raha)
                // aur dp[i] ko minimum value se update kar do
                dp[i] = min(dp[i], dp[i - (j * j)] + 1);
            }
        }

        // final answer: minimum number of perfect squares jinke sum se n banta hai
        return dp[n];
    }
};
