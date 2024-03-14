/*

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.
 You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space, respectively.



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




/*

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
        vector<vector<string>> ans;
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












