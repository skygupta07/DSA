// sudokuSolver.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:

Input: board = [["5","3",".",".","7",".",".",".","."],
                ["6",".",".","1","9","5",".",".","."],
                [".","9","8",".",".",".",".","6","."],
                ["8",".",".",".","6",".",".",".","3"],
                ["4",".",".","8",".","3",".",".","1"],
                ["7",".",".",".","2",".",".",".","6"],
                [".","6",".",".",".",".","2","8","."],
                [".",".",".","4","1","9",".",".","5"],
                [".",".",".",".","8",".",".","7","9"]]


Output: [["5","3","4","6","7","8","9","1","2"],
        ["6","7","2","1","9","5","3","4","8"],
        ["1","9","8","3","4","2","5","6","7"],
        ["8","5","9","7","6","1","4","2","3"],
        ["4","2","6","8","5","3","7","9","1"],
        ["7","1","3","9","2","4","8","5","6"],
        ["9","6","1","5","3","7","2","8","4"],
        ["2","8","7","4","1","9","6","3","5"],
        ["3","4","5","2","8","6","1","7","9"]]

Explanation: The input board is shown above and the only valid solution is shown below:


Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.

*/


class Solution {
public:

    // Function to check if placing a number in a cell is safe
    bool isSafe(vector<vector<char>> &board, int r, int c, char num) {
        // Check if 'num' is present in the current row
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == num) return false;
        }
        
        // Check if 'num' is present in the current column
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == num) return false;
        }
        
        // Check if 'num' is present in the 3x3 subgrid
        int startRow = (r / 3) * 3; // Top-left row of the 3x3 subgrid
        int startCol = (c / 3) * 3; // Top-left column of the 3x3 subgrid


        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num) return false;
            }
        }
        
        return true; // It's safe to place 'num'
    }
    
    // Backtracking function to solve the Sudoku - solving the grid row wise...
    bool solve(vector<vector<char>> &board, int r, int c) {

        // Base case: If we reach row 9, the board is solved - kyuki row 8th tak hi index tak kaam hua hoga..
        //  now ab ye last mai ek extra increment ho jaata h .. uske liye check karte h... 
        if (r == 9) return true;
        
        // If we reach column 9, move to the next row
        if (c == 9) return solve(board, r + 1, 0);
        

        // If the current cell is already filled, move to the next cell by moving to next column 
        // jitne bhi basecases h usmme se koi bhi true aata h toh return** true ho jaata h...
        if (board[r][c] != '.') return solve(board, r, c + 1);
        
        // Try placing numbers 1-9 in the current cell - ha bkl tabhi ye loop chalta h ... hume pta thodi hota h 
        // ki kaun sa number lagega...hum to saari possibilities explore karte h btc...

        // ha directly character use kar sakte h aur increment bhi kar sakte h...
        for (char num = '1'; num <= '9'; num++) { 

            if (isSafe(board, r, c, num)) { // Check if placing 'num' is safe in this current cell..
                board[r][c] = num; // Place the number
                
                // now immediately solve Recursively for the next cell in the row
                if (solve(board, r, c + 1)) return true;
                
                // Backtrack: Revert the cell to empty if solution doesn't work
                board[r][c] = '.';
            }
        }
        
        // If no number can be placed, return false
        return false;
    }
    
    // Public function to solve the Sudoku
    void solveSudoku(vector<vector<char>> &board) {
        // starting index pass na karne wale ladke {heere se na moti se... mai to ... meethe wala dance karte h...}
        solve(board, 0, 0); // Start solving from the top-left corner
    }

};

/*
EXPLANATION:
1. **isSafe Function**:
    - Checks whether it's valid to place a number in the current cell.
    - Verifies row, column, and 3x3 subgrid constraints.

2. **solve Function (Backtracking) **:
    - Processes each cell row by row.
    - If the cell is empty, it tries placing numbers 1-9.
    - If a number placement is valid, recursively** tries solving the next cell.
    - If the placement leads to a dead-end, it backtracks by reverting the cell to empty.

3. **Optimization**:
    - Avoid redundant checks by exiting early when a constraint fails.
    - Row, column, and subgrid checks are optimized to \( O(9) \).

4. **Complexity**:
    - **Time Complexity**: Approximately \( O(9^{m}) \), where \( m \) is the number of empty cells. Worst-case but feasible for Sudoku due to constraints.
    - **Space Complexity**: \( O(1) \), since changes are made in-place on the board.
*/
