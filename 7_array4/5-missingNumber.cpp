// missingNumber.cpp

/*

 Given an array nums containing n distinct numbers in the range [0, n], return 
the only number in the range that is missing from the array.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums){
        int n = nums.size();
        int naturalSum = n*(n+1)/2;
        int givenSum = 0;

        for (int i=0; i<n; i++) givenSum += nums[i];
        
        return naturalSum - givenSum;
    }
};


// mehtod2 xor method-> remember xor with the same number give zero
// and xor zero with any other number give that other number...