// rotateImage.cpp

#include <bits/stdc++.h>
using namespace std;


/*


You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.


Example 1:

Input: matrix = [[1,2,3],
                [4,5,6],
                [7,8,9]]


Output: [[7,4,1],
        [8,5,2],
        [9,6,3]]


Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

*/


#include <vector>
using namespace std;

class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = i + 1; j < c; j++) { // Only swap if i < j #akash
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void reverseRows(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        // Go to each row
        for (int i = 0; i < r; i++) {
            int left = 0;
            int right = c - 1;

            // Reverse each row
            while (left < right) {
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverseRows(matrix);
    }
};