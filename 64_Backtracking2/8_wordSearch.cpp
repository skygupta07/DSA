#include <bits/stdc++.h>
using namespace std;


/*

Given an m x n grid of characters board and a string word, 
return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
 

Example 1:


Input: board = [["A","B","C","E"],
               ["S","F","C","S"],
               ["A","D","E","E"]],       word = "ABCCED"
Output: true


Example 2:


Input: board = [["A","B","C","E"],
               ["S","F","C","S"],
               ["A","D","E","E"]],       word = "SEE"
Output: true


Example 3:


Input: board = [["A","B","C","E"],
               ["S","F","C","S"],
               ["A","D","E","E"]],        word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?

*/

class Solution {
public:

        // DFS function jo check karega ki word exist karta hai ya nahi
        bool solve(vector<vector<char>> &board, string &word, int row, int col, int idx, vector<vector<int>> &visited) {
            // Base Case: Agar pura word match ho gaya, toh return true
            if (idx == word.length()) {
                return true;
            }
    
            int m = board.size();
            int n = board[0].size();
    
            // Agar out of bounds ho ya visited ho ya character match na kare toh false return karo
            if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col] || board[row][col] != word[idx]) {
                return false;
            }
    
            // Current cell ko visited mark kar diya
            visited[row][col] = 1;
    
            // 4 directions me DFS call maar rahe hain (UP, DOWN, LEFT, RIGHT)
            bool found = solve(board, word, row + 1, col, idx + 1, visited) ||
                         solve(board, word, row - 1, col, idx + 1, visited) ||
                         solve(board, word, row, col + 1, idx + 1, visited) ||
                         solve(board, word, row, col - 1, idx + 1, visited);
    
            // Backtracking: Agar word nahi mila toh visited ko wapas 0 kar do
            visited[row][col] = 0;
    
            return found;
        }
        
    
        bool exist(vector<vector<char>>& board, string word) {
            int m = board.size();
            int n = board[0].size();
    
            vector<vector<int>> visited(m, vector<int>(n, 0)); // Visited matrix
    
            // Har cell se start karke word find karne ki koshish kar rahe hain
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    // Agar word ka first character match karta hai toh DFS call maaro
                    if (board[i][j] == word[0] && solve(board, word, i, j, 0, visited)) {
                        return true; // Word mil gaya
                    }
                }
            }
    
            return false; // Agar koi bhi path word nahi bana paya toh false return karo
        }
    };
    


// without visited matrix

    class Solution {
        public:
        
            bool solve(vector <vector <char>> &board, string &word, int row, int col, int idx){
                if (idx == word.length()) return true;
        
                int m = board.size();
                int n = board[0].size();
        
                if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] == '#' || board[row][col] != word[idx]) return false;
        
                char temp = board[row][col];
                board[row][col] = '#';
        
                bool found = solve(board, word, row + 1, col, idx + 1) ||
                             solve(board, word, row - 1, col, idx + 1) ||
                             solve(board, word, row, col + 1, idx + 1) ||
                             solve(board, word, row, col - 1, idx + 1);
                
                board[row][col] = temp;
                return found;
                
            }
        
        
            bool exist(vector<vector<char>>& board, string word) {
                int m = board.size();
                int n = board[0].size();
        
                for (int i=0; i<m; i++){
                    for (int j=0; j<n; j++){
                        if (board[i][j] == word[0] && solve(board, word, i, j, 0)) return true;
                    }
                }
                return false;
            }
        };