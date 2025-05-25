// countPalindromicSubsequence.cpp

#include <bits/stdc++.h>
using namespace std;

/*


Given a string of digits s, return the number of palindromic subsequences of s having length 5. 
Since the answer may be very large, return it modulo 10pow9 + 7.

Note:

A string is palindromic if it reads the same forward and backward.
A subsequence is a string that can be derived from another string by deleting some or no 
characters without changing the order of the remaining characters.
 

Example 1:

Input: s = "103301"
Output: 2

Explanation: 
There are 6 possible subsequences of length 5: "10330","10331","10301","10301","13301","03301". 
Two of them (both equal to "10301") are palindromic.

Example 2:

Input: s = "0000000"
Output: 21
Explanation: All 21 subsequences are "00000", which is palindromic.

Example 3:

Input: s = "9999900000"
Output: 2
Explanation: The only two palindromic subsequences are "99999" and "00000".
 

Constraints:

1 <= s.length <= 104
s consists of digits.


*/


class Solution {
public:

    // 3D arrays to store prefix and suffix counts of digit pairs
    int pref[10000][10][10];  // pref[i][j][k] -> count of (j, k) pairs ending at or before index i
    int suff[10000][10][10];  // suff[i][j][k] -> count of (j, k) pairs starting at or after index i
    
    int cnts[10] = {};        // Frequency counter for single digits (0 to 9)

    const int mod = 1e9 + 7;  // Modulo to avoid integer overflow

    int countPalindromes(string s) {
        int n = s.length();  // Length of input string
        int ans = 0;         // Final answer to store count of valid 5-length palindromes

        // STEP 1: Prefix Calculation (left to right)
        for (int i = 0; i < n; i++) {
            int c = s[i] - '0';  // Convert char to digit

            if (i) {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 10; k++) {
                        // Carry forward previous counts
                        pref[i][j][k] = pref[i - 1][j][k];

                        // If current digit is k, update pair (j, k)
                        if (k == c) pref[i][j][k] += cnts[j];
                    }
                }
            }
            // Increase current digit count
            cnts[c]++;
        }

        // Reset the counter for suffix use
        memset(cnts, 0, sizeof(cnts));

        // STEP 2: Suffix Calculation (right to left)
        for (int i = n - 1; i >= 0; i--){
            int c = s[i] - '0';

            if (i < n - 1) {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 10; k++) {
                        // Carry forward previous counts
                        suff[i][j][k] = suff[i + 1][j][k];

                        // If current digit is k, update pair (j, k)
                        if (k == c) suff[i][j][k] += cnts[j];
                    }
                }
            }
            // Increase current digit count
            cnts[c]++;
        }

        // STEP 3: Calculate the final answer
        // Fix center digit at index i, and count valid combinations around it
        for (int i = 2; i < n - 2; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    // Multiply the number of (j,k) prefix pairs ending before i
                    // with number of (j,k) suffix pairs starting after i
                    // Yeh dono milke banaate hain valid 5-length palindrome: j k x k j
                    ans = (ans + 1LL * pref[i - 1][j][k] * suff[i + 1][j][k]) % mod;
                }
            }
        }

        return ans;  // Return the total number of palindromes
    }
};
