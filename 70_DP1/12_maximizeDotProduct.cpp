// maximizeDotProduct.cpp

/*

Given two arrays a and b of positive integers of size n and m where n >= m, 
the task is to maximize the dot product by inserting zeros in the second array 
but you cannot disturb the order of elements.

Dot product of array a and b of size n is a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1].


Example 1:

Input: 
n = 5, a[] = {2, 3, 1, 7, 8} 
m = 3, b[] = {3, 6, 7}

Output: 
107
Explanation: 

We get maximum dot product after inserting 0 at first and third positions in second array.
Therefore b becomes {0, 3, 0, 6, 7}. 
Maximum dot product = 2*0 + 3*3 + 1*0 + 7*6 + 8*7 = 107.


Example 2:

Input: 
n = 3, a[] = {1, 2, 3}
m = 1, b[] = {4} 
Output: 
12 

Explanation: 
We get maximum dot product after inserting 0 at first and second positions in second array.
Therefore b becomes {0, 0, 4}. 
Maximum Dot Product = 1*0 + 2*0 + 3*4 = 12.

Your Task:  
You don't need to read input or print anything. Complete the function maxDotProduct() 
which takes n, m, array a and b as input parameters and returns the maximum value.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ m ≤n ≤ 103
1 ≤ a[i], b[i] ≤ 103

*/



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
