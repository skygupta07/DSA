#include <bits/stdc++.h>
using namespace std;

int minPoints(int m, int n, vector<vector<int>> points){
	    // if the grid is empty , return 0
	    if (m==0) return 0;
	    
	    // DP table with dimensions (m+1)x(n+1)
	    // initialised with all values set to INT_MAX
	    
	    vector <vector<int>> dp(m+1, vector <int> (n+1 , INT_MAX));
	    
	    // initialising the cell to the bottom and right of the princess cell with value 1..
	    dp[m-1][n] = 1;
	    dp[m][n-1] = 1;
	    
	    // iterating over dp excluding the additional row and column we added...
	    
	    for (int i=m-1; i>=0; i--){
	        for (int j=n-1; j>=0; j--){
	            // value is minimum health to land on next - health needed to stay..
	            
	            dp[i][j] = max( 1, min(dp[i+1][j] , dp[i][j+1]) - points[i][j] );
	        }
	    }
	    // return the minimum health required to reach the princess cell...
	    return dp[0][0];
} 