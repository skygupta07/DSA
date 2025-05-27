/*

You are playing a video game, which contains an N x N grid. 
You start on the top left cell of the grid,
 and are free to move anywhere through the grid, any number of times.

Each cell in the grid has some number of points that you can collect from it and you can collect points
 at most once from each cell. Furthermore, it is possible to collect points from a cell, 
 if and only if the cell lies on one of the two diagonals of the grid. 
Print the maximum number of points you can collect, given the grid.

*/
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum points from diagonals in an n x n grid
int maximumPoints(int n, vector<vector<int>> &grid){
    int count = 0; // total points store karne ke liye

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            
            // ✅ Left diagonal condition: i == j
            if (i == j)
                count += grid[i][j];

            // ✅ Right diagonal condition: i + j == n - 1
            else if (i + j == n - 1)
                count += grid[i][j];

            // ❌ Center element do baar add ho gaya hota hai 
            // (ek baar left diagonal se, ek baar right diagonal se)
            // isliye agar wo center element hai toh ek baar subtract kar do
            else if (i == n / 2 && j == n / 2)
                count -= grid[i][j];
        }
    }

    return count; // final total points return karo
}
