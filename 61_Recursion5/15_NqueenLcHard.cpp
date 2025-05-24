#include <bits/stdc++.h>
using namespace std;


/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard 
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space, respectively.

*/

class Solution {
public:

    bool isSafe(int row, int col, vector <string> board , int n){   // kind of black box...
        int duprow = row;   // chalaki
        int dupcol = col;

        while (row>=0 && col>=0){       // left diagonal check-> jaate jaate 0,0 ki hit karta woahi constraint hai..
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = duprow;   // pehle ched lo phir apne backup wale se turant theek bhi kardo 
                        // taki next iteration walo ko pta bhi na chale...
        col = dupcol;

        while (row <n && col>=0){      // left check...
            if (board[row][col] == 'Q') return false;
            col--;
        }

        row = duprow;
        col = dupcol;

        while (row<n && col>=0){    // left lower diagonal check
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        // if none of above hits false then it is safe, place it..
        return true;       
    }


    void solve(int col , vector<string> &board, vector<vector<string> > &ans, int n ){
        if (col == n){  // since filling  column wise and have zero based indexing and we are passing col+1 in 
            // the very next iteration so when n = 4 i.e. it crossed the column and previous column has been filled
            // i.e. a new possible board combination has been found...
            ans.push_back(board);
            return;
        }

        // kisi bhi ek column ke corresponding har row mai jaake dekha....

        for (int row=0; row<n; row++){
            if (isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';      // backtracking step...
            }
        }

    }



    vector<vector<string>> solveNQueens(int n){
        vector <vector <string>> ans;
        vector <string> board(n);   // yes smartly you can represent a 2d type matrix grid into a vector of 
        // stirng provided that you initialise that string smartly...

        string s(n, '.');   // vector of string banayi jaha har string ko pura pura dot se initialise kiya...
        
        for (int i=0; i<n; i++){
            board[i] = s;
        }

        solve(0, board, ans, n);
        return ans;
    }
};





/*
make sure you remove the queen while backtracking because you altered the board by your bad move while going in recursion depth
har step pe saari possibilities dekh rahea hai (bas wo no attacking wala constraint) laga ke...

basically we are filling queen column wise while maintaining the no attak in each row also...
we have to check three constraint for safe move.....

*/



class Solution {
public:

    void solve(int col, vector <string> &board, vector<vector<string>> &ans, 
    vector <int> leftRow, vector <int> upperDiagonal, vector <int> lowerDiagonal , int n){

        if (col == n){
            ans.push_back(board);
            return;
        }
        // basically 2d matrix mai row index aur column index ko aapas mai manupulate karke dekh rahe hai...
        // 0 means absence of queen => no attack possible (na rahegi baas na bajegi basuri)

        for (int row=0; row<n; row++){  // for a particular column trying each row....
            
            if (leftRow[row]==0 && lowerDiagonal[row + col] == 0  && upperDiagonal[n-1 + col - row] == 0 ){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[ row + col ] = 1;
                upperDiagonal[n-1 + col - row ] = 1;

                solve(col+1 , board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n-1 + col - row] = 0;
            }
        }


    }



    vector<vector<string>> solveNQueens(int n) {
        vector <vector <string>> ans;

        vector <string> board(n);
        string s(n,'.');

        for (int i=0; i<n; i++){
            board[i] = s;
        }

        // hashing ke liye vector use kiya..
        vector <int> leftRow(n,0);
        vector <int> upperDiagonal(2*n - 1 , 0);
        vector <int> lowerDiagonal(2*n - 1,  0);

        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};

/*
optimising Nqueen using hashing...

*/





// interviews

class Solution {
public:

    vector<vector<string>> allSolutions; // Sab valid boards store karne ke liye

    // Check karo ki (row, col) pe queen rakhna safe hai ya nahi
    bool isSafe(vector<vector<bool>> &grid, int row, int col, int n) {
        // Column ke upar check karo
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col]) return false;
        }

        // Upper-left diagonal check karo - multiple conditions and karke likhi jaati h..
        // and multiple increments aap comma deke likh sakte ho...
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (grid[i][j]) return false;
        }

        // Upper-right diagonal check karo
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (grid[i][j]) return false;
        }

        return true; // Safe hai
    }

    // Convert current grid into vector<string> format aur store karo result me
    void addSolution(vector<vector<bool>> &grid, int n) {
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < n; j++) {
                row += grid[i][j] ? 'Q' : '.';
            }
            board.push_back(row);
        }
        allSolutions.push_back(board); // Ek valid board mil gaya
    }

    // Backtracking function
    void solveNQueen(vector<vector<bool>> &grid, int currRow, int n) {
        if (currRow == n) {
            addSolution(grid, n); // Valid solution mil gaya, add karo
            return;
        }

        // currentrow mai har jagah place karke dekho..
        for (int j = 0; j < n; j++) {
            if (isSafe(grid, currRow, j, n)) {
                grid[currRow][j] = true; // Queen place karo
                solveNQueen(grid, currRow + 1, n); // Agli row me jao
                grid[currRow][j] = false; // Backtrack
            }
        }
    }

    // Main function
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> grid(n, vector<bool>(n, false)); // Empty board banao
        solveNQueen(grid, 0, n); // Solve karo starting from row 0
        return allSolutions;
    }
};













