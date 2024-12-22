#include <bits/stdc++.h>
using namespace std;


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