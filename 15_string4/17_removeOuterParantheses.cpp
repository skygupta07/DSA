// removeOuterParantheses.cpp

#include <bits/stdc++.h>
using namespace std;

/*

A valid parentheses string is either empty "", "(" + A + ")", or A + B, 
where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, 
and there does not exist a way to split it into s = A + B, 
with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: 
s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string 
in the primitive decomposition of s.

 
Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".


Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".


Example 3:

Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
 

Constraints:

1 <= s.length <= 105
s[i] is either '(' or ')'.
s is a valid parentheses string.


*/


// deleted_user solution top notch..

class Solution {
public:
    string removeOuterParentheses(string S) {
        string res = "";  // final result string

        int opened = 0;   // counter to track how many '(' are currently open

        for (char ch : S) {

            // if we see '(', increase count first
            // we add '(' only if it's **not the outermost** → i.e., after first open
            if (ch == '(' && opened++ > 0) res += ch;

            // if we see ')', decrease count after checking
            // we add ')' only if it's **not the closing of the outermost** group
            if (ch == ')' && opened-- > 1) res += ch;
        }

        return res;
    }
};
