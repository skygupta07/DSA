// removeKDigits.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.


Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack <char> st;

        // remove larger digits from smaller digits..
        for (auto ch : num){
            while(!st.empty() && st.top()>ch && k>0){
                st.pop();
                k--;
            }
            st.push(ch);
        }

        // remove from the last k digits
        while (k>0){
            st.pop();
            k--;
        }

        // formation of string...
        string ans = "";
        while (!st.empty()){
            ans += st.top();
            st.pop();
        }

        // finding index to eliminate leading zeroes....
        int endingIdx = 0;
        for (int i=ans.size()-1; i>=0; i--){
            if (ans[i] != '0'){
                endingIdx = i;
                break;
            }
        }

        ans = ans.substr(0, endingIdx + 1);
        // reverse to counter stack effect...

        reverse(ans.begin() , ans.end());
        if (ans == "") ans = "0";

        return ans;
    }
};