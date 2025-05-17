// intersectionOfTwoArrays.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.


Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

*/



class Solution { // best approach...
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // akash it is good that you are using good variable names...
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

class Solution { // wrong answer...
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            
            int i = 0, j = 0;
    
            vector<int> result;
            
            while (i < nums1.size() && j < nums2.size()) {
                if (nums1[i] < nums2[j]) {  // jo chota usi ka pointer aage
                    i++;
                } 
                else if (nums1[i] > nums2[j]) {
                    j++;
                }
    
                // both elements are equal 
                else{   
                    result.push_back(nums1[i]);
                    i++;
                    j++;
                }
            }
            
            return result;
        }
    };


// using two sets => make set s1 and s2 then find common element...

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


// using single set..

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        set <int> s;

        int m = nums1.size();
        int n = nums2.size();

        if (m<=n){
            for (int i=0; i<m; i++){
                for (int j=0; j<n; j++){
                    if (nums1[i] == nums2[j]){
                        s.insert(nums1[i]);
                        break;
                    }
                }
            }
        }
        else{ //m>n
            for (int i=0; i<n; i++){
                for (int j=0; j<m; j++){
                    if (nums2[i] == nums1[j]){
                        s.insert(nums2[i]);
                        break;
                    }
                }
            }
        
        }

        for (auto el: s){
            result.push_back(el);
        }

        return result;
       
    }
};

// brute force 
// ordered Set 