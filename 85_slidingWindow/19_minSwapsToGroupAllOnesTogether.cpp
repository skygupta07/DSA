#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;  // window size = total number of ones...

        for (int i=0; i<n; i++){
            if (nums[i] == 1) k++;
        }

        // initialise first window of k size
        int zeroCount = 0;
        for (int i=0; i<k; i++){
            if (nums[i] == 0) zeroCount++;
        }

        int mini = zeroCount;   // number of swaps

        for (int i=1; i<n; i++){
            // starting element removed contribution check
            if (nums[(i-1)%n] == 0){
                zeroCount--;
            }

            // ending element of window contribution check..

            if (nums[(i+k-1)%n] == 0){
                zeroCount++;
            }

            mini = min(mini, zeroCount);
        }

        return mini;

        // now 1st index se start hoga window and ek ek kadam aage badhega... circualar ke liye bhi dhyan rakhna...


    }
};


/*
approach: 

total number of ones find kara.... utne hi size ka window initialise kiya.....
now window ke andar dekha kitne number of zeros hai utne swap lagenge...
window ko aage badhate gaye ...ek banda jo window se bahar hua uska contribution dekha kya uska constribution currentZeroCount mai tha ...agar tha to phir ab ghata do....
now ek naya element jo sliding window mai recently add hua hai uska bhi same hi contribution dekho...


*/