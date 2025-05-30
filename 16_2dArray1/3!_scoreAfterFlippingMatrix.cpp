// scoreAfterFlippingMatrix.cpp

#include <bits/stdc++.h>
using namespace std;


/*

you are given an m x n binary matrix grid.
A move consists of choosing any row or column and toggling each value in that row or column 
(i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, 
and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).


Example 1:

Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39


Example 2:

Input: grid = [[0]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 20
grid[i][j] is either 0 or 1.

*/


#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        int n = grid.size(), m = grid[0].size();

        int res = (1 << (m - 1)) * n;

        for(int j = 1; j < m; ++j){

            int val = 1 << (m - 1 - j);
            int set = 0;

            for(int i = 0; i < n; ++i) {
                if(grid[i][j] == grid[i][0]) {
                    set++;
                }
            }

            res += max(set, n - set) * val;
        }

        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


/*
greedy approach -> row wise trace kara and if the very first element of row is zero then filp the entire row...
-> now iterate column wise and see if number of zeroes are greater than number of ones in that column... if it is 
then flip the entire column....

*/


/*
dekh simple hai ek 2d matrix di hogi uski row = m = ( grid.size() ) se nikalunga.... and uski column = n = grid[0].size()
se nikala then for 
1. row wise traversal ke liye....
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout<<grid[i][j];
        }
    } 

2. column wise print karne ke liye... bahar column ki jai and andar row ki jai 
then print to grid ka [i][j] hi hota hai...
    for (int j=0; j<n; j++){
        for (int i=0; i<m; i++){
            cout<<grid[i][j];
        }
    }



*/


