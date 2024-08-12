#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int count = 0, n;
    vector<int> f;

    int find(int x) {
        if (x != f[x]) {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    void uni(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            f[x] = y;
            count--;
        }
    }

    int g(int i, int j, int k) {
        return (i * n + j) * 4 + k;
    }

    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();  // Initialize n correctly
        count = n * n * 4;
        f.resize(count);
        
        for (int i = 0; i < count; i++) {
            f[i] = i;  // Correct initialization
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) uni(g(i-1, j, 2), g(i, j, 0));  // Connect top cell with current cell
                if (j > 0) uni(g(i, j-1, 1), g(i, j, 3));  // Connect left cell with current cell

                if (grid[i][j] != '/') {
                    uni(g(i, j, 0), g(i, j, 1));  // Connect top-left and top-right
                    uni(g(i, j, 2), g(i, j, 3));  // Connect bottom-left and bottom-right
                }

                if (grid[i][j] != '\\') {
                    uni(g(i, j, 0), g(i, j, 3));  // Connect top-left and bottom-left
                    uni(g(i, j, 2), g(i, j, 1));  // Connect bottom-right and top-right
                }
            }
        }
        return count;
    }
};
