#include <bits/stdc++.h>
using namespace std;


/*

The n-queens puzzle is the problem of placing n queens on an n x n chessboard 
such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:

Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.


Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 9

*/



// nQueen2
class Solution {
public:

    int countWays = 0; // Total number of ways to arrange queens.

    // Function to check if placing a queen at (row, col) is safe
    bool isSafe(vector <vector <bool>> &grid, int row, int col, int n){
        // Check vertically above the current cell in that particular column.. matlab row vary karega..
        for (int i = row - 1; i >= 0; i--){
            if (grid[i][col]) return false; // Agar upar koi queen hai, toh safe nahi hai
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if (grid[i][j]) return false; // Agar diagonal pe koi queen hai, toh safe nahi hai
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if (grid[i][j]) return false; // Agar doosri diagonal pe queen hai, toh safe nahi hai
        }

        return true; // Agar upar, left-diagonal, aur right-diagonal pe koi queen nahi hai, toh safe hai
    }

    // Recursive function to count the number of valid arrangements of queens
    void countNQueen(vector <vector <bool>> &grid, int currRow, int n){
        // Base case: Agar current row n ke equal ho gaya, ek valid arrangement mil gaya
        if (currRow == n){
            countWays++; // Valid arrangement milne par count badhao
            return; // Wapas previous state par jao
        }

        // Har column par queen place karne ki koshish karo uss currRow ke liye karenge...
        for (int j = 0; j < n; j++){
            // Check karo ki kya (currRow, j) pe queen safely place ho sakti hai
            if (isSafe(grid, currRow, j, n)){
                grid[currRow][j] = true; // Queen ko yahan place karo

                // Recursively agle row par move karo
                countNQueen(grid, currRow + 1, n);

                // Backtracking: Queen ko hata do
                grid[currRow][j] = false;
            }
        }
    }

    // Main function to calculate total number of solutions for n-queens problem
    int totalNQueens(int n) {
        // Create an n x n grid initialized to false (sab cells empty hain)
        vector <vector <bool>> grid(n, vector <bool> (n, false));

        // Start placing queens from the first row
        countNQueen(grid, 0, n);
        
        return countWays; // Total number of valid arrangements return karo
    }
};
