#include <bits/stdc++.h>
using namespace std;

/*
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
Permute the characters of s so that they match the order that order was sorted. 
More specifically, if a character x occurs before a character y in order, 
then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.
*/

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map <char,int> freq;
        for (auto el : s) freq[el]++;

        string ans = "";
        
        for (auto el : order){
            while (freq[el]-- > 0 ) ans.push_back(el);
        }

        // for remaining....
        for (auto [el,fr] : freq){
            while (fr-- > 0 ) ans.push_back(el);
        }

        return ans;
    }
};



class Solution {
public:
    string customSortString(string order, string s) {
        
        auto cmp = [&](char a, char b){
            return order.find(a) < order.find(b);
        };
        sort(s.begin(), s.end(), cmp);

        return s;

    }
};


// custom comparator ki madad se hoga ye problem....

// puri string mai ek character add karna is more time taking...