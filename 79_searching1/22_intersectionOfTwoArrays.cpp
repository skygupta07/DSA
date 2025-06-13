// intersectionOfTwoArrays.cpp

/*


Given two integer arrays nums1 and nums2, 
return an array of their intersection. 
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



#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector <int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector <int> result;
        set <int> st;
        

        if (m <= n){
            for (int i=0; i<m; i++){
                for (int j=0; j<n; j++){

                    if (nums1[i] == nums2[j]){
                        st.insert(nums1[i]);
                        break;
                    }

                }
            }
        }
        //m > n

        else{
            for (int i=0; i<n; i++){
                for (int j=0; j<m; j++){
                    if (nums2[i] == nums1[j]){
                        st.insert(nums2[i]);
                        break;
                    }
                }
            }
        }

        for (auto el: st){
            result.push_back(el);
        }

        return result;
       
    }
};

// brute force 
// ordered Set 



class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> result;

        set <int> st1;
        set <int> st2;

        for (auto el: nums1){
            st1.insert(el);
        }

        for (auto el: nums2){
            st2.insert(el);
        }

        int m = st1.size(); // number of unique elements in nums1 vector..
        int n = st2.size();

        if (m<=n){
            for (auto el : st1){
                if (st2.find(el) != st2.end()) result.push_back(el);
            }
        }
        
        else{
            for (auto el: st2){
                if (st1.find(el)!= st1.end()) result.push_back(el);
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



class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> commonElements;

        unordered_set <int> st;
        for (auto el : nums1) st.insert(el);

        for (auto el: nums2){
            // agar already set mai element present h to...
            if (st.find(el) != st.end()){
                commonElements.push_back(el);
                st.erase(el);
            }
        }

        return commonElements;
    }
};