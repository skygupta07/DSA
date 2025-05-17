#include <bits/stdc++.h>
using namespace std;

/*

Given a 32-bit integer num, return a string representing its hexadecimal representation.
For negative integers, two’s complement method is used.

All the letters in the answer string should be lowercase characters, 
and there should not be any leading zeros in the answer except for the zero itself.

Note: You are not allowed to use any built-in library method to directly solve this problem.


Example 1:

Input: num = 26
Output: "1a"

Example 2:

Input: num = -1
Output: "ffffffff"

*/

// Constant string HEX containing all possible hexadecimal characters
const string HEX = "0123456789abcdef";

class Solution {
public:
    string toHex(int num) {
        // Agar number 0 hai to directly "0" return kar dena hai
        if (num == 0) return "0";

        string ans;  // Yeh final hexadecimal string ko store karega
        int count = 0; // Yeh track karega ki maximum 8 hex digits tak limit ho

        // Jab tak num non-zero hai aur 8 hex digits tak process nahi ho gaya
        while (num && count++ < 8) {
            // num ka last 4-bit extract karna hai (yeh basically num % 16 jaisa kaam karega)
            ans = HEX[(num & 0xf)] + ans;

            // Right shift kar ke num ko 16 se divide jaisa effect dena hai
            num >>= 4;  // equivalent to num = num / 16;
        }

        // Final hexadecimal representation return karni hai
        return ans;
    }
};
