// minPointsToReachDestination.cpp


/*

Given a m*n grid with each cell consisting of a positive, negative, or zero integer. 
We can move across a cell only if we have positive points. 

Whenever we pass through a cell, points in that cell are added to our overall points, 
the task is to find minimum initial points to reach cell (m-1, n-1) from (0, 0) 
by following these certain set of rules :

1. From a cell (i, j) we can move to (i + 1, j) or (i, j + 1).
2. We cannot move from (i, j) if your overall points at (i, j) are <= 0.
3. We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.


Example 1:

Input: 
m = 3, n = 3 

points = {{-2,-3,3}, 
          {-5,-10,1},
          {10,30,-5}} 

Output: 
7 

Explanation: 7 is the minimum value to reach the destination with positive throughout the path. 
Below is the path. (0,0) -> (0,1) -> (0,2) -> (1, 2) -> (2, 2) We start from (0, 0) with 7, 
we reach (0, 1) with 5, (0, 2) with 2, (1, 2) with 5, (2, 2) with and finally we have 1 point 
(we needed greater than 0 points at the end).


Example 2:

Input:
m = 3, n = 2
points = {{2,3},  
          {5,10},  
          {10,30}} 

Output: 
1 

Explanation: Take any path, all of them are positive. 
So, required one point at the start

Your Task:  
You don't need to read input or print anything. 
Complete the function minPoints() which takes 2 integers m and n 
and 2-d vector points as input parameters and returns an integer denoting the minimum initial points 
to reach cell (m-1, n-1) from (0, 0).


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)



Constraints:
1 ≤ m ≤ 10pow3  
1 ≤ n ≤ 10pow3
-10pow3 ≤ points[i][j] ≤ 10pow3

*/


#include <bits/stdc++.h>
using namespace std;


int minPoints(int m, int n, vector <vector<int>> points){
	    // if the grid is empty , return 0
	    if (m == 0) return 0;
	    
	    // DP table with dimensions (m+1)x(n+1)
	    // initialised with all values set to INT_MAX
	    
	    vector <vector<int>> dp(m+1, vector <int>(n+1 , INT_MAX));
	    
	    // initialising the cell to the bottom and right of the princess cell with value 1..
	    dp[m-1][n] = 1;
	    dp[m][n-1] = 1;
	    
	    // iterating over dp excluding the additional row and column we added...
	    
	    for (int i=m-1; i>=0; i--){
	        for (int j=n-1; j>=0; j--){

	            // value is minimum health to land on next - health needed to stay..
				
	            dp[i][j] = max(1, min(dp[i+1][j] , dp[i][j+1]) - points[i][j]);
	        }
	    }

	    // return the minimum health required to reach the princess cell...
	    return dp[0][0];
} 