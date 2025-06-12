// decodeString.cpp

/*

Given an encoded string, return its decoded string.

The encoding rule is: 
k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; 
there are no extra white spaces, square brackets are well-formed, etc. 
Furthermore, you may assume that the original data does not contain any digits 
and that digits are only for those repeat numbers, k. 
For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 1e5.

 
Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"


Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"


Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int n = s.length(); 

        // Agar string empty hai ya starting mein '0' hai, toh decoding nahi possible
        if (s.empty() || s[0] == '0') return 0; 
        
        vector<int> dp(n+1, 0); // n + 1 size taaki tabhi to dp[n] find kar payenge..

        dp[0] = 1; // Base case: empty string ke liye ek tareeka hai (no decoding needed)
        dp[1] = 1; // Ek character agar valid hai, toh ek hi tareeka hoga usko decode karne ka


        // DP loop chalate hain 2 se lekar n tak
        for (int i = 2; i <= n; i++) {
            int oneDigit = s[i-1] - '0'; // Current single digit ko integer mein convert karo
            int twoDigits = stoi(s.substr(i-2, 2)); // Previous 2 digits ko integer mein convert karo

            // Agar current single digit valid hai (1 to 9), toh uske liye ways add karo
            if (oneDigit != 0) dp[i] += dp[i-1];
            
            // Agar previous 2 digits valid hain (10 to 26), toh uske liye ways add karo
            if (twoDigits >= 10 && twoDigits <= 26) dp[i] += dp[i-2];
        }

        return dp[n]; // Pura string decode karne ke total tareeke return karo
    }
};

/*
dp[i] ka matlab hai: substring s[:i] (0 se i tak ka substring) ko decode karne ke tareeke.
Hum string ke har character par iterate karke DP array update karte hain, yeh dekhte hue ki 
current digit aur pichle digits valid hain ya nahi.
*/


class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;     // Stack to store strings
        stack<int> numStack;        // Stack to store repetition counts
        string currStr = "";        // Current working string
        
        int num = 0;                // Current frequency number

        for (char ch : s) {
            if (isdigit(ch)) {
                // Build the number (handle multi-digit numbers)
                num = num * 10 + (ch - '0');
            }
            else if (ch == '[') {
                // Push the number and current string to stacks
                numStack.push(num);
                strStack.push(currStr);

                // Reset for next segment
                num = 0;
                currStr = "";
            }
            
            else if (ch == ']') {
                // Decode: repeat the current string `num` times
                int repeatTimes = numStack.top(); numStack.pop();
                string prevStr = strStack.top(); strStack.pop();

                string temp = "";
                while (repeatTimes--) {
                    temp += currStr;
                }

                currStr = prevStr + temp; // Combine with previous context
            }
            else {
                // Regular character, add to current working string
                currStr += ch;
            }
        }

        return currStr;
    }
};
