#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    typedef long long ll;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector <ll> subarraySumVector;

        for (int i = 0; i < n; i++){    // will decide starting of window....
            ll windowSum = 0;
            for (int j = i; j < n; j++){    // will decide ending of window( har baar to end tak jaenge hi)
                windowSum += nums[j];
                subarraySumVector.push_back(windowSum);
            }
        }
        // sort subarraySumVector 

        sort (subarraySumVector.begin() , subarraySumVector.end());

        ll rangeSum = 0;
        for (int i=left-1; i<=right - 1; i++){
            rangeSum += subarraySumVector[i];
        }

        int ans = rangeSum%mod;
        return ans;
    }
};


/*

while generating the subarray calculate the sum of that subarray as well....(isme hoti hi aisa hai...)
and then push that sum into subarraySumVector 

then finally iterate over subarraySumVector  from left to right and store the answer 
return ans % mod

*/