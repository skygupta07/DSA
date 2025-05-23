#include <bits/stdc++.h>
using namespace std;

int help(int *a, int* b, int i, int j, vector <vector<int>> &memo){
	    // base case 
	    if (j<0) return 0;
	    
	    if (i<0) return -1e9;
	    
	    // memo check 
	    if (memo[i][j] != -1) return memo[i][j];
	    
	    // recursive calls and memo calculations
	    
	    int notTake = 0 + help(a, b, i-1,j,memo);
	    int take = a[i]*b[j] + help(a, b, i-1, j-1, memo);
	    
	    return memo[i][j] = max(take, notTake);
}
	
int maxDotProduct(int n, int m, int a[], int b[]){ 
        vector <vector<int>> memo(n, vector<int> (m, -1));
        int ans = help(a, b, n-1, m-1, memo);
        return ans;
} 


 // ----------- space optimised....

int maxDotProduct(int n, int m, int a[], int b[]){ 
		// Your code goes here
		vector <int> pre(m+1, 0);
		
		for (int i=1; i<(n+1); i++){
		    vector <int> curr(m+1, 0);
		    
		    for (int j=1; j<(m+1); j++){
		        if (i==0 or j==0) continue;
		        
		        else if (i == j) curr[j] = a[i-1] * b[j-1] + pre[j-1];
		        
		        else if (i>j) curr[j] = max(a[i-1]*b[j-1] + pre[j-1], pre[j]);
		    }
		    pre = curr;
		}
		return pre[m];
} 
