#include <iostream>
#include <vector>
using namespace std;
int main(){

}


class Solution {
public:
    void DFS(vector<vector<char>>& board, int i, int j, int m, int n) { // i is currentRow, j is currentColumn
        if(i<0 or j<0 or i>=n or j>=m or board[i][j] != 'O') return;
        board[i][j] = '#';      // you will be landing at border zero so make it and its neighbour hash 
        // and call dfs...
        DFS(board, i-1, j, m, n);
        DFS(board, i+1, j, m, n);
        DFS(board, i, j-1, m, n);
        DFS(board, i, j+1, m, n);
    }
    
    void solve(vector<vector<char>>& board) {                
     int n = board.size();  // no.of rows
      if(n == 0) return;        // then all be touching border so no change simply return
        
     int m = board[0].size();   // no. of columns..
        
     // Moving over first column and last column -> (obviously row to change hogi hi)  
     for(int i=0; i<n; i++) {
         if(board[i][0] == 'O')
             DFS(board, i, 0, m, n);
         if(board[i][n-1] == 'O')
             DFS(board, i, n-1, m, n);  // dfs fn hash bana raha hai...1 ko
     }
        
        
     //Moving over first and last row   
     for(int j=0; j<m; j++) {
         if(board[0][j] == 'O')
             DFS(board, 0, j, m, n);
         if(board[n-1][j] == 'O')
             DFS(board, n-1, j, m, n);
     }
        
    // now make final changes...
     for(int i=0; i<n; i++)
         for(int j=0; j<m; j++)
         {
             if(board[i][j] == 'O') board[i][j] = 'X';
                 
             if(board[i][j] == '#') board[i][j] = 'O';
                 
         }
    }
};

/*
      Steps to Solve :
      1. Move over the boundary of board, and find O's 
      2. Every time we find an O, perform DFS from it's position
      3. In DFS convert all 'O' to '#'      (why?? so that we can differentiate which 'O' can be    flipped and which cannot be)   
      4. After all DFSs have been performed, board contains three elements,#,O and X
      5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
      6. '#' are elements which cannot be flipped to 'X', so flip them back to 'O'



-- all the zeroes that are present on boundary do dfs on them and mark all the set of neighbours as 
non capturable...


*/
