#include <bits/stdc++.h>
using namespace std;

/*
Return the string after making it good. The answer is guaranteed to be unique under 
the given constraints
*/

class Solution {
public:
    string makeGood(string s) {
       stack <char> st;

       for (char ch : s){   // abey for char ch in string hoga bhai...
            if ( !st.empty() && abs(ch - st.top()) == 32){
                st.pop();
            }
            else st.push(ch);
       }

       string ans;

       while (!st.empty()){
            ans = st.top() + ans;   // wow ye sahi tarika hai stack mai se cheeze ulti nikalna ka (pretend hoga)
            st.pop();
       } 
       return ans;
    }

};

// time and space complexity -> O(n)