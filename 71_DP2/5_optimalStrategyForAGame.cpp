// optimalStrategyForAGame.cpp

/*


You are given an integer array arr[] of size n. 
The array elements represent n coins of values v1, v2, ....vn.
You play against an opponent in an alternating way. In each turn, a player selects either 
the first or last coin from the row, removes it from the row permanently, and receives the coin's value.

You need to determine the maximum possible amount of money you can win if you go first.

Note: Both the players are playing optimally.


Examples:

Input: arr[] = [5, 3, 7, 10]
Output: 15
Explanation: The user collects the maximum value as 15(10 + 5). It is guaranteed that we cannot get more than 15 by any possible moves.


Input: arr[] = [8, 15, 3, 7]
Output: 22
Explanation: The user collects the maximum value as 22(7 + 15). It is guaranteed that we cannot get more than 22 by any possible moves.
Constraints:


2 <= n <= 10pow3
1 <= arr[i] <= 10pow6

*/

// kind of alice bob question

#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution{
public:
    
    ll helper(int arr[], int i, int j, vector <vector<ll>> &dp){
        
        // base case 
         // I was missing it....
        if (i > j) return 0; 
        
        // base case ke turant baad dp checkup(or doctor checkup)
        if (dp[i][j] != -1) return dp[i][j];
        
        // recursive calls and small calculations.
        
        // to minimise what other opponent is taking...
        ll left = arr[i] + min( helper(arr,i+2,j,dp) , helper(arr,i+1,j-1,dp));
        ll right = arr[j] + min( helper(arr,i,j-2,dp) , helper(arr,i+1,j-1,dp));
        
        return dp[i][j] = max(left, right);

    }
    

    long long maximumAmount(int n, int arr[]){

        vector <vector<ll>> dp(n, vector<ll> (n,-1));

        return helper(arr, 0, n-1, dp);
    }
};