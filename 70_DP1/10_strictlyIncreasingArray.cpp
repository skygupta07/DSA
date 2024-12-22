#include <bits/stdc++.h>
using namespace std;

/*
Return the string after making it good. The answer is guaranteed to be unique under the given constraints
*/

int min_operations(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n,1);
        int LIS = 1;    // longest Increasing Subsequence
        
        for (int i=1; i<n ; i++){
            for (int j=0; j<i; j++){
                if (nums[i] > nums[j] && (nums[i] - nums[j]) >= (i-j)){ // i coming later here..
                    dp[i] = max(1 + dp[j] , dp[i]);
                    LIS = max(LIS , dp[i]);
                }
            }
        }
        return (n - LIS);
}
