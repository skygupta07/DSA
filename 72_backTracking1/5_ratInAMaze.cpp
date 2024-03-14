#include <iostream>
#include <vector>
using namespace std;

bool canWeGo(vector <vector <int> > &grid , int n, int i, int j){
    if ( i >= 0 && j>=0 && i<n && j<n && grid[i][j]=0){
        return true;
    }
    else return false;
}
int ans;    // find out in how many ways the rat can reach end of the maze 
            // starting from (0,0)

void f(vector <vector <int> > &grid, int n, int i, int j){ // performing auxiliary fn which do work
    if (i==n-1 and j==n-1){ // base case
        ans += 1;
        return;
    }
    grid[i][j] = 2; // 2 means visited 

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

    grid[i][j] = 0; // chahe answer aaye ya nahi hume revert back to karna hi hai...

    
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

recursive deadlock handle karne ke liye, we will use backtracking..(and mark the already visited node)
standing at a cell we will go to next cell which is both open and non visited before...
whenver we reach to the bottom right end, then we include it in answer
answer mile chahe na mile state ko revert back jarur karna hai...
*/
