#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();    // number of rows
        int n = box[0].size(); // number of columns

        // Step 1: Rotate the matrix 90 degrees clockwise
        vector<vector<char>> rotated(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotated[j][m - 1 - i] = box[i][j];  // interesting Akash
            }
        }

        // Step 2: Apply gravity to each column in the rotated matrix
        for (int col = 0; col < m; ++col) {
            int emptyRow = n - 1; // Start from the bottom of the column
            for (int row = n - 1; row >= 0; --row) {
                if (rotated[row][col] == '#') {
                    // Move stone down to the nearest empty cell
                    swap(rotated[row][col], rotated[emptyRow][col]);
                    emptyRow--;
                } else if (rotated[row][col] == '*') {
                    // Obstacle blocks stones; reset emptyRow
                    emptyRow = row - 1;
                }
            }
        }

        return rotated;
    }
};
