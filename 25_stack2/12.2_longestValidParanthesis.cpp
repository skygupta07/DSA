#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        stack <int> st;
        st.push(-1);    // base index to calculate length..

        int maxLen = 0;

        for(int i=0; i<s.length(); i++){
            if (s[i] == '(') st.push(i);    // few chutiya people push the element instead of index

            // if you encounter closing bracket..
            else{
                // open se pair karne ke liye ...
                st.pop();

                // but agar usme already open bracket nahi they.. and wo jo base index .. jo daala tha wo bhi pop kar diya ki ab stack empty ho gayi hogi tab to.... 

                // push the current index of closing bracket .. atleast closing h to kya hua... it will serve as base index atleast...
                if (st.empty()) st.push(i);

                // pop karne ke baad sab theek thak chal rha h... matlab good h mamla.. simply maximize the length...

                maxLen = max(maxLen, i - st.top());     // yes i - st.top() hi hoga..
                // i aapko current index yaani closing bracket ka index de rha h... a
                // and st.top se last opening bracket ka index mil jaa rha h... so 
            }
        }

        return maxLen;

    }
};