#include <bits/stdc++.h>
using namespace std;


/*
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
return the minimum integer common to both arrays. If there is no common integer 
amongst nums1 and nums2, return -1.
Note that an integer is said to be common to nums1 and nums2 if both arrays have
at least one occurrence of that integer.
*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();

        while (i<=m-1 && j<=n-1){
            if (nums1[i] < nums2[j]) i++;
            else if (nums1[i] > nums2[j]) j++;
            else return nums1[i];
        }
        return -1;
    }
};