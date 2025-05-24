// removeInvalidParanthesis.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a string s that contains parentheses and letters, 
remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid with the minimum number of removals. 
You may return the answer in any order. 

Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]


Example 2:

Input: s = "(a)())()"
Output: ["(a())()", "(a)()()"]


Example 3:

Input: s = ")("
Output: [""]

Constraints:

1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.

*/


class Solution {
public:
    vector <string> res; // Ye vector store karega valid expressions ko

    // DFS function jo backtracking karega
    void dfs(const string &s, int start, int left, int right, int open, string path) {
        // Agar hum string ke end par aa gaye aur saare brackets balance ho gaye
        if (start == s.length()) {
            if (left == 0 && right == 0 && open == 0) {
                res.push_back(path);
            }
            return;
        }

        // Agar kisi bhi state mai count negative ho gaya to return
        if (left < 0 || right < 0 || open < 0) return;

        char ch = s[start];

        // Agar '(' aaya
        if (ch == '(') {
            // Agar start me ya consecutive '(' nhi hai to remove karke dekho
            if (start == 0 || s[start - 1] != ch) {
                for (int i = 0; (i < s.length() - start) && (s[start + i] == ch) && (i + 1 <= left); i++) {
                    dfs(s, start + i + 1, left - i - 1, right, open, path);
                }
            }

            // Is '(' ko consider karke next state par jao
            dfs(s, start + 1, left, right, open + 1, path + ch);
        }

        // Agar ')' aaya
        else if (ch == ')') {
            // Agar start me ya consecutive ')' nhi hai to remove karke dekho
            if (start == 0 || s[start - 1] != ch) {
                for (int i = 0; start + i < s.length() && s[start + i] == ch && i + 1 <= right; i++) {
                    dfs(s, start + i + 1, left, right - i - 1, open, path);
                }
            }

            // Is ')' ko consider karke next state par jao
            dfs(s, start + 1, left, right, open - 1, path + ch);
        }

        // Agar koi normal character aaya, to usko simply add karke next state par jao
        else dfs(s, start + 1, left, right, open, path + ch);
    }

    vector <string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;

        // Pehle count karo ki kitne extra '(' aur ')' hain jo remove karne hain
        for (char ch : s) {
            if (ch == '(') left++;  // Agar '(' mila to left badhao

            else if (ch == ')') {
                if (left > 0) left--;  // Agar left hai to ek pair balance kar do
                else right++;  // Nahi to right badhao
            }
        }

        res.clear();  // Result vector ko clear karo
        dfs(s, 0, left, right, 0, "");  // DFS se solve karo
        return res;
    }
};
