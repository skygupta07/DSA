#include <bits/stdc++.h>
using namespace std;


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
