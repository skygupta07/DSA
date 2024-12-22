#include <bits/stdc++.h>
using namespace std;

/*
You are given an n x n integer matrix grid.
Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:
maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix
     in grid centered around row i + 1 and column j + 1.
In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.
Return the generated matrix.
*/


class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> res(n-2, vector <int> (n-2));

        for (int i=1; i<n-1; ++i){
            for (int j=1; j<n-1; ++j){
                int temp = 0;

                for (int k=i-1; k<=i+1; ++k){
                    for (int l=j-1; l<=j+1; ++l){
                        temp = max(temp, grid[k][l]);
                    }
                }
                res[i-1][j-1] = temp;
            }
        }
        return res;
    }
};