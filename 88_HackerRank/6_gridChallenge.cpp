#include <iostream>
#include <vector>
using namespace std;
int main(){

}



string gridChallenge(vector<string>& grid) {
    // Step 1: Sort each row of the grid
    for (string& row : grid) {
        sort(row.begin(), row.end());
    }

    // Step 2: Check if each column is sorted
    int numRows = grid.size();
    int numCols = grid[0].size();

    for (int col = 0; col < numCols; ++col) {
        for (int row = 1; row < numRows; ++row) {
            if (grid[row][col] < grid[row - 1][col]) {
                return "NO";
            }
        }
    }

    return "YES";
}