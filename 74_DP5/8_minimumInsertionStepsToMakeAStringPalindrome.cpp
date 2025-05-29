// minimumInsertionStepsToMakeAStringPalindrome.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.
A Palindrome String is one that reads the same backward as well as forward.
 
Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.


Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".


Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

*/



class Solution {
public:

    // Helper function using recursion + memoization
    int solve(string &s, int left, int right, vector <vector <int>> &dp) {

        // Base Case:
        // If the left index crosses or meets the right index, string is already a palindrome
        // No insertion needed

        if (left >= right) return 0;

        // Memoization Check:
        // If we've already computed for this substring [left, right], return the stored result
        if (dp[left][right] != -1) return dp[left][right];

        // Case 1: Characters match
        // Move inward without adding any insertion
        if (s[left] == s[right])
            return dp[left][right] = solve(s, left + 1, right - 1, dp);

        // Case 2: Characters don't match
        // Option 1: Insert at left side → solve from (left + 1, right)
        // Option 2: Insert at right side → solve from (left, right - 1)
        // Add 1 insertion and take the minimum of both options
        
        return dp[left][right] = min(1 + solve(s, left + 1, right, dp),
                                     1 + solve(s, left, right - 1, dp));
    }



    // 🔁 Main function
    int minInsertions(string s) {
        int n = s.length();

        // Create a DP table of size n x n initialized with -1
        // dp[i][j] will store the min insertions required to make s[i..j] a palindrome
        
        // {halaki mujhe puri string ko palindrome banana tha... but mene phir bhi dp ke chakkar mai 
        // socha ki index i se j tak string ko palindrome banana hota to kitne steps lagte....
        // then phir chalaki kari... index 0 se n-1 pass kar diya jissey puri puri string waise bhi 
        // consider ho gayi....}

        vector <vector <int>> dp(n, vector <int>(n, -1));

        // Start recursion from full string (0 to n-1)
        return solve(s, 0, n - 1, dp);
    }
};
