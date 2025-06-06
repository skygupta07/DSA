#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution{
    public:
    
    ll helper(int arr[], int i,int j, vector <vector<ll>> &dp){
        // base case 
        if (i>j) return 0;  // i was missing it....
        
        // base case ke turant baad dp checkup(or doctor checkup)
        
        if (dp[i][j] != -1) return dp[i][j];
        
        // recursive calls and small calculations.
        
        ll left = arr[i] + min( helper(arr,i+2,j,dp) , helper(arr,i+1,j-1,dp)); // to minimise what other opponent is taking...
        ll right = arr[j] + min( helper(arr,i,j-2,dp) , helper(arr,i+1,j-1,dp));
        
        return dp[i][j] = max(left, right);
    }
    
    long long maximumAmount(int n, int arr[]){
        vector <vector<ll>> dp(n, vector<ll> (n,-1));
        return helper(arr, 0 , n-1, dp);
    }
};