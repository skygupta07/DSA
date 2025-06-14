// twoSum.cpp


/*

Given an array of integers nums and an integer target, return indices of the two numbers 
such that they add up to target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
You can return the answer in any order.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector <int> twoSum(vector <int> &v, int target){
        int n = v.size();

        unordered_map <int, int> mp;    // key,value = element,index store...

        for (int i=0; i<n; i++){

            int compEle = target - v[i];    // or remaining 

            if (mp.find(compEle) != mp.end()){
                return {i , mp[compEle]};
            }
            // in general jo bhi element encounter kar rahe ho ussey map mai to store karenge hi
            mp[v[i]] = i; 
        } 
        
        // kai log ye wali vector ko nahi declare kar paate wo issey dekh ke kucch aur 
        // sochne lagte h..
        return {};
    }
    
};
