#include <bits/stdc++.h>
using namespace std;

/*

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each 
row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.
 

Example 1:


Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.


Example 2:

Input: grid = [[8]]
Output: 0
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15

*/


class Solution {
public:
    int m, n;

    bool isValidSquare(vector<vector<int>>& grid, int sr, int sc) {
        return (sr + 2 < m && sc + 2 < n);
    }

    bool isMagicSquare(vector<vector<int>>& grid, int sr, int sc) {
        // Check if all numbers are distinct and in the range 1 to 9
        vector<int> freq(10, 0);

        for (int i = sr; i <= sr + 2; i++) {
            for (int j = sc; j <= sc + 2; j++) {

                int num = grid[i][j];
                if (num < 1 || num > 9 || freq[num] > 0) {
                    return false;
                }

                freq[num]++;
            }
        }

        // Calculate the sum of the first row as the base sum
        int baseSum = grid[sr][sc] + grid[sr][sc + 1] + grid[sr][sc + 2];

        // Check rows -> rowWise
        // good trick ki starting positions hi ye hai...

        for (int i = sr; i <= sr + 2; i++) {
            int rowSum = 0;

            for (int j = sc; j <= sc + 2; j++) {
                rowSum += grid[i][j];
            }

            if (rowSum != baseSum) {
                return false;
            }

        }

        // Check columns
        // starting row to jo bhej rakha hoga.. wo hi pass hoga....
        for (int j = sc; j <= sc + 2; j++) {
            int colSum = 0;

            for (int i = sr; i <= sr + 2; i++) {
                colSum += grid[i][j];
            }

            if (colSum != baseSum) {
                return false;
            }
        }

        // Check diagonals
        int diag1 = grid[sr][sc] + grid[sr + 1][sc + 1] + grid[sr + 2][sc + 2];
        int diag2 = grid[sr][sc + 2] + grid[sr + 1][sc + 1] + grid[sr + 2][sc];


        if (diag1 != baseSum || diag2 != baseSum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int count = 0;

        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                if (isValidSquare(grid, i, j) && isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};
