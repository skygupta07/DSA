#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	     int n = matrix.size();
	   
	   // temp changes for ease
	    for (int i=0; i<n; i++){
	        for (int j=0; j<n; j++){
	            if (i == j) matrix[i][j] = 0;
	            if (matrix[i][j] == -1) matrix[i][j] = 1e9;
	        }
	    }
	    
	   
	    for (int k=0; k<n; k++){    // via 
	        for (int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
	    
	    // revert back
	    for (int i=0; i<n; i++){
	        for (int j=0; j<n; j++){
	            if (matrix[i][j] == 1e9) matrix[i][j] = -1;
	        }
	    }
	}
};



/*
multisource shortest path algorithm 
-> detects negative cycle as well

(any path that takes the least amount of edge weight is the shortest path)

go via every vertex/node

-> at a time precomputation is also required 

(undirected graph ko directed mai convert karne ke liye to simply u se v and v se u 
assign kardo same weight ko....)

how to detect a negative cycle here?
 simply mat[i][i] < 0
    implies there is negative cycle...
*/