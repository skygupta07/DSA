#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        
        for(char &ch : s) {
            if(ch == '[') st.push(ch);
            // matlab closing bracket hi hoga...safety ke liye empty check kar lo...
            else if(!st.empty()) st.pop();
        }       
        return (st.size()+1)/2;
    }
};