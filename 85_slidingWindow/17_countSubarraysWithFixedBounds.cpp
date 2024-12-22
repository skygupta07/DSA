#include <bits/stdc++.h>
using namespace std;

/*

You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

*/


class Solution {
public:
    long long countSubarrays(vector <int> &nums, int minK, int maxK) {
        long long ans = 0;
        int badi = -1;
        int mini = -1;
        int maxi = -1;
        int n = nums.size();

        for (int i=0; i<n; i++){
            if (nums[i]<minK || nums[i]>maxK) badi = i;
            if (nums[i] == minK) mini = i;
            if (nums[i] == maxK) maxi = i;

            ans += max(0 , min(mini, maxi) - badi);
        }
        
        return ans;   
    }
};


/*
 all the numbers in the array were between minK and maxK inclusive -> ek check laga diya badindex ka...


badi ke teen case bane they jisme   
case 1 -> badi A B
case 2 -> A badi B
case3 -> A B badi

isme case 2 aur case 3 mai to badi include ho jayega isliye usko ignore kar denge....
jab bhi case 2 ya case 3 waala case evaluate hoga to answer negative compute hoga usko hi counteract 
karne ke liye humne max(0,). zero wala factor daala hai....


also we don't mini or maxi which comes first.....so min(mini, maxi)   

maxi - badi waali trick ....
so finally we ans by ans += max(0 , min(mini, maxi) - badi);



in general ->
total number of subarrays if there are n elements -> n(n+1)/2 
for example for n=5 elements -> we have 5 + 4 + 3 + 2 + 1 options at each next step....


*/