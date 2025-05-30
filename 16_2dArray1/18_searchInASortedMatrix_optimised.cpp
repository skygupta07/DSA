#include <bits/stdc++.h>
using namespace std;

/*

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity. 

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true


Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10pow4 <= matrix[i][j], target <= 10pow4

*/

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        
        for (int i=0; i<m; i++){
            
            int lo = 0;
            int hi = n - 1;
            
            if (mat[i][lo] == target || mat[i][hi] == target) return true;
            
            // agar target ekdum last wale se bhi chota hoga tabhi iss wali row mai lie kar rha hoga...
            else if ( target < mat[i][hi] ){
                // binary search in this row...
                
                while (lo <= hi){
                     int mid = lo + (hi - lo)/2;
                
                    if (mat[i][mid] == target) return true;
                    else if (mat[i][mid] < target) lo = mid + 1;
                    else hi = mid - 1;
                }
               
            }
            
            else continue;  // search in the next row then...
        }
        
        return false;
    }
};
