#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxAndValue = 0;
        for (int i=0; i<n; i++){    // ek single individual element / maxElement of array hi maxAnd value bhi hogi... ab bas ye dekhna hai iska longest running sequence kaha tak aa raha hai..
            maxAndValue = max(maxAndValue, nums[i]);
        }

        int maxLen = 1; // minimum 1 length to hogi hi..

        int currLen = 0;

        for (int i=0; i<n; i++){

            if (nums[i] == maxAndValue){
                currLen++;
                maxLen = max(maxLen, currLen);
            }
            else{   // reset, if different value found
                currLen = 0;
            }
        }

        return maxLen; 
    }
};


/*
agar do number ka and karega to wo unme se chota number hoga ussey bhi chhota ho jaata hai...
agar AND karke maximum laana hai to  matlab same number se hi AND karna padega...

agar different number aaye to currLen ko reset kar do zero se ...
*/