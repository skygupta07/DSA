#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set <string> st;

        for (auto el: arr1){
            string s = to_string(el);

            string prefix;
            for (auto ch: s){   // generating and storing all the prefixes...
                prefix += ch;
                st.insert(prefix);
            }
        }   

        int maxi = 0;

        for (auto el: arr2){
            string s = to_string(el);

            string prefix;

            for (auto ch: s){
                prefix += ch;

                if (st.find(prefix) != st.end()){
                    maxi = max(maxi, int(prefix.length()));
                }
            }
        }

        return maxi;
    }
};

/*
generate all the possible prefix and store it in st1...
now generate all the possible prefix in arr2 , and see if it is already found in st1, then updat count of prefix...
*/