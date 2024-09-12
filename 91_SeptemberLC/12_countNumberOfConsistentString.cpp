#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set <char> st;

        for (auto ch : allowed) st.insert(ch);

        int count = 0;

        for (auto word : words){
            bool found = true;
            for (auto ch: word){
                if (st.find(ch) == st.end()){
                    found = false;
                    break;
                }
            }
            if (found) count++;
        }

        return count;
    }
};