#include <bits/stdc++.h>
using namespace std;


/*

You are given a 0-indexed string pattern of length n consisting of the characters 'I' 
meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].

Return the lexicographically smallest possible string num that meets the conditions.
 

Example 1: 

Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.


Example 2:

Input: pattern = "DDD"
Output: "4321"
Explanation:
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.

*/

class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";
        stack <int> stk; // Stack to reverse order during 'D'

        // Loop through the pattern + one extra iteration to handle last digit
        for (int i = 0; i <= pattern.size(); ++i) {
            stk.push(i + 1); // Always push the next number (1 to n+1)

            // If it's the last char or current char is 'I', pop and append to result
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!stk.empty()) {
                    result += to_string(stk.top()); // Convert number to string and add
                    stk.pop(); // Remove from stack
                }
            }
        }

        return result; // Final result string
    }
};







/*
'D' means delay decision → push in stack.
'I' or end means decision → pop and append to result.


⏱️ Time Complexity:
O(N) where N = pattern.length()
Each digit is pushed and popped exactly once

💾 Space Complexity:
O(N) for the stack and result string

*/