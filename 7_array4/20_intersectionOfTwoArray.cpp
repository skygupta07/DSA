// intersectionOfTwoArray.cpp

#include <bits/stdc++.h>
using namespace std;

/*
Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any order.
*/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> commonElements;

        unordered_set <int> st;
        for (auto el : nums1) st.insert(el);

        for (auto el: nums2){
            if (st.find(el) != st.end()){
                commonElements.push_back(el);
                st.erase(el);
            }
        }

        return commonElements;
    }
};




class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> result;
        set <int> s1;
        set <int> s2;

        for (auto el: nums1){
            s1.insert(el);
        }

        for (auto el: nums2){
            s2.insert(el);
        }

        int m = s1.size();
        int n = s2.size();

        if (m<=n){
            for (auto el : s1){
                if (s2.find(el) != s2.end()) result.push_back(el);
            }
        }else{
            for (auto el: s2){
                if (s1.find(el)!= s1.end()) result.push_back(el);
            }
        }

        return result;
    }
};

// make set s1 and s2 then find common element...


class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_set <int> common;
    
            unordered_set <int> st;
    
            for (auto el : nums1) st.insert(el);
    
            for (auto el : nums2){
                if (st.find(el) != st.end()) common.insert(el);
            }
    
            vector <int> result(common.begin(), common.end());
    
            return result;
        }
};