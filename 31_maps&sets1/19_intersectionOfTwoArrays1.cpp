// intersectionOfTwoArrays.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given two integer arrays nums1 and nums2, 
return an array of their intersection. Each element in the result must be unique 
and you may return the result in any order.


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

class Solution {
public:

        vector <int> intersection(vector <int> &nums1, vector <int> &nums2) {
            vector <int> result;

            set <int> st1;
            set <int> st2;
    
            for (auto el: nums1) st1.insert(el);
    
            for (auto el: nums2) st2.insert(el);
    
            int m = st1.size();
            int n = st2.size();
    
            if (m <= n){
                // set1 ke har element ko set2 mai dekha...

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