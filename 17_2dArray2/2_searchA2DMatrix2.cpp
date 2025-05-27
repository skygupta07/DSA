#include <bits/stdc++.h>
using namespace std;


/*

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom. (ab ki baar dono hi tareeke se sorted de diya...)
 

Example 1:


Input: matrix = [[1,4,7,11,15],
                [2,5,8,12,19],
                [3,6,9,16,22],
                [10,13,14,17,24],
                [18,21,23,26,30]],       target = 5
Output: true


Example 2:


Input: matrix = [[1,4,7,11,15],
                [2,5,8,12,19],
                [3,6,9,16,22],
                [10,13,14,17,24],
                [18,21,23,26,30]],      target = 20
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length

1 <= n, m <= 300

-10pow9 <= matrix[i][j] <= 10pow9
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.

-10pow9 <= target <= 10pow9

*/




class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // Get the dimensions of the matrix

        int m = matrix.size(); // Number of rows
        int n = m ? matrix[0].size() : 0; // Number of columns (if matrix is non-empty)
        
        // Start the search from the top-right corner of the matrix
        int r = 0, c = n - 1;
        
        // Loop until we go out of bounds
        while (r < m && c >= 0) {
            // If the current element equals the target, return true
            
            if (matrix[r][c] == target) {
                return true;
            }
            
            // If the current element is greater than the target, move left
            // (eliminating the current column from further consideration)
            // matlab target chota h to phir column ko kam karo..
            if (matrix[r][c] > target) {
                c--;
            }

            // Otherwise, move down
            // (eliminating the current row from further consideration)
            else {
                r++;
            }

        }
        
        // If we exit the loop without finding the target, return false
        return false;
    }
};
