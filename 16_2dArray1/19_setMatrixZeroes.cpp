// setMatrixZeroes.cpp

/*

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place. 

Example 1:


Input: matrix = [[1,1,1],
                [1,0,1],
                [1,1,1]]

Output: [[1,0,1],[0,0,0],[1,0,1]]


Example 2:

Input: matrix = [[0,1,2,0],
                [3,4,5,2],
                [1,3,1,5]]

Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200

-2pow31 <= matrix[i][j] <= 2pow31 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Do sets maintain karenge ek rows ke liye aur ek columns ke liye jaha zero milega.

        unordered_set<int> zrow; // Set to store rows jaha zero milega
        unordered_set<int> zcol; // Set to store columns jaha zero milega

        int row = matrix.size();    // Total rows in matrix
        int col = matrix[0].size(); // Total columns in matrix

        // **First iteration:** Har cell check karte hain ki kahin zero hai kya.
        for (int i = 0; i < row; i++) { // Row-wise traverse karo
            for (int j = 0; j < col; j++) { // Column-wise traverse karo
                
                if (matrix[i][j] == 0) { 
                    zrow.insert(i); // Agar cell zero hai, to uski row ko mark karlo
                    zcol.insert(j); // Aur uski column ko bhi mark karlo
                }
                
            }
        }

        // **Second iteration:** Rows aur columns ko modify karte hain based on sets.
        for (int i = 0; i < row; i++) { // Har row ke liye
            for (int j = 0; j < col; j++) { // Har column ke liye
                // Agar current row `zrow` set me hai, to pura row zero kar do
                if (zrow.find(i) != zrow.end()) {
                    matrix[i][j] = 0;
                }

                // Agar current column `zcol` set me hai, to pura column zero kar do
                if (zcol.find(j) != zcol.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

/*
### Explanation in Hindi wali English ###
1. Pehle iteration mai matrix ka har cell traverse kiya aur zero ka position mark kara
     (row aur column sets me).
2. Doosre iteration mai un marked rows aur columns ko pura zero kar diya.
3. Code ka time complexity O(row * col) hai, lekin space complexity O(row + col) hai 
    because hum dono rows aur columns ke liye sets use kar rahe hain.
*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector <pair <int,int>> zeroCoordinates;

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (matrix[i][j] == 0) zeroCoordinates.push_back({i, j});
            }
        }

        for (auto [x, y] : zeroCoordinates){
            // make xth row zero
            for (int j=0; j<n; j++){
                matrix[x][j] = 0;
            }

            // make yth column zero
            for (int i=0; i<m; i++){
                matrix[i][y] = 0;
            }
        }

        return;

    }
};


// more optimised

void setZeroes(vector<vector<int>>& matrix) {
        bool isZeroCol = false;
        bool isZeroRow = false;

        for (int i = 0; i < matrix.size(); i++) { //check the first column
            if (matrix[i][0] == 0) {
                isZeroCol = true;
                break;
            } 
        }
        for (int i = 0; i < matrix[0].size(); i++) { //check the first row
            if (matrix[0][i] == 0) {
                isZeroRow = true;
                break;
            } 
        }
        for (int i = 1; i < matrix.size(); i++) { //check except the first row and column
            for (int j = 1; j < matrix[0].size(); j++) 
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }

        for (int i = 1; i < matrix.size(); i++) { //process except the first row and column
           for (int j = 1; j < matrix[0].size(); j++) 
               if (matrix[i][0] == 0 || matrix[0][j] == 0)
                   matrix[i][j] = 0;
        }

        if (isZeroCol) { //handle the first column
            for (int i = 0; i < matrix.size(); i++) 
                matrix[i][0] = 0;
        }

        if (isZeroRow) { //handle the first row
            for (int i = 0; i < matrix[0].size(); i++) 
                matrix[0][i] = 0;
        }
}