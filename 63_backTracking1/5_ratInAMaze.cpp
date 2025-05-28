// ratInAMaze.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Consider a rat placed at position (0, 0) in an n x n square matrix mat[][]. 
The rat's goal is to reach the destination at position (n-1, n-1). 
The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.

Your task is to find all possible paths the rat can take to reach the destination, 
starting from (0, 0) and ending at (n-1, n-1), 
under the condition that the rat cannot revisit any cell along the same path. 

Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix 
and not blocked.

If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.

Examples:

Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - 
DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.


Input: mat[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell is blocked.


Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: ["DDRR", "RRDD"]
Explanation: The rat has two possible paths to reach the destination: 
1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.

Constraints:
2 ≤ mat.size() ≤ 5
0 ≤ mat[i][j] ≤ 1

*/

bool canWeGo(vector <vector <int> > &grid , int n, int i, int j){
    if ( i >= 0 && j>=0 && i<n && j<n && grid[i][j]=0) return true;
    else return false;
}

int ans;    // find out in how many ways the rat can reach end of the maze 
            // starting from (0,0)

void f(vector <vector <int> > &grid, int n, int i, int j){ // performing auxiliary fn which do work
    
    if (i==n-1 and j==n-1){ // base case -> pahuch gaye end box tak
        ans += 1;
        return;
    }
    // mark the cell on which you landed as visited
    grid[i][j] = 2; // 2 means visited (binary grid mai visited karne ki trick) - ye normal aadmi ko yaad nahi reh sakta..

    // go left and check
    if (canWeGo(grid, n, i, j-1)){
        f(grid, n, i, j-1);
    }
    // top
    if (canWeGo(grid, n, i-1, j)){
        f(grid, n, i-1, j);
    }
    // right
    if (canWeGo(grid, n, i, j+1)){
        f(grid, n, i, j+1);
    }
    // down
    if (canWeGo(grid, n, i+1, j)){
        f(grid, n, i+1, j);
    }

    grid[i][j] = 0; // chahe answer aaye ya nahi hume revert back to karna hi hai...dubara block kar diya...
 
}


int ratInAMaze(vector <vector <int> > &grid, int n){    // virtual fn jisse fn calls hongi bas.. 
    ans = 0;
    f(grid,n,0,0);
    return ans;
}




int main(){
    vector <vector<int> > grid = {
        {0,0,1,0,0,1,0},
        {1,0,1,1,0,0,0},
        {0,0,0,0,1,0,1},
        {1,0,1,0,0,0,0},
        {1,0,1,1,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,0,0,0}
    };
    
    cout<<ratInAMaze(grid,7);

}




/*
given a maze with 0 and 1 
0-> open cells
1-> blocked cells

rat can go top left bottom right from a cell
find out in how many ways the rat can reach end of the maze starting from (0,0)

recursive deadlock (ping pong -> the box) ko handle karne ke liye, we will use backtracking..
(i.e. will mark the already visited node)
standing at a cell we will go to next cell which is both open and non visited (kapil sharma) before...
whenver we reach to the bottom right end, then we include it in answer
answer mile chahe na mile state ko revert back jarur karna hai...
*/
