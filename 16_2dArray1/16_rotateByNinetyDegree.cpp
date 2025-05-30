// rotateByNinetyDegree.cpp

/*

Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees 
in an anti-clockwise direction without using any extra space. 

Examples:

Input: mat[][] = [[1, 2, 3],
                [4, 5, 6]
                [7, 8, 9]]

Output: Rotated Matrix:
[3, 6, 9]
[2, 5, 8]
[1, 4, 7]


Input: mat[][] = [[1, 2],
                [3, 4]]

Output: Rotated Matrix:
[2, 4]
[1, 3]


Constraints:
1 ≤ n ≤ 102
0 <= mat[i][j] <= 10pow3

*/


class Solution {
public:

    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
            
        //swap only for j > i (kuch bc bhul jaate h like me and overwrite karne lagte h)
        for (int i=0; i<m; i++){
            for (int j=i+1; j<n; j++) swap(mat[i][j] , mat[j][i]);
        }
        
        // column wise traverse
        
        for (int col = 0; col < n; col++){
            int i = 0;
            int j = m - 1;
            
            while ( i < j){
                swap(mat[i][col] , mat[j][col]);
                i++;
                j--;
            }
        }
        
    }
};