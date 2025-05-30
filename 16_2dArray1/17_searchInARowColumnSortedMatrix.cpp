// searchInARowColumnSortedMatrix.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted 
in increasing order and a number x, the task is to find whether element x is present in the matrix.

Examples:

Input: mat[][] = [[3, 30, 38],
                 [20, 52, 54],
                 [35, 60, 69]], x = 62

Output: false

Explanation: 62 is not present in the matrix, so output is false.


Input: mat[][] = [[18, 21, 27],
                 [38, 55, 67]], x = 55

Output: true

Explanation: 55 is present in the matrix.



Input: mat[][] = [[1, 2, 3],
                 [4, 5, 6],
                 [7, 8, 9]], x = 3

Output: true
Explanation: 3 is present in the matrix.


Constraints:
1 <= n, m <=1000
1 <= mat[i][j] <= 10pow9
1<= x <= 109

*/


class Solution {
public:

    bool matSearch(vector<vector<int>> &mat, int x) {
        int m = mat.size();
        int n = mat[0].size();
        
        // har row pe gaye...
        for (int i=0; i<m; i++){
            
            // element find karne ke liye column par binary search laga diya...
            int lo = 0; 
            int hi = n-1;
            
            while (lo <= hi){ // lo < hi kiya but nahi chala tha..
            //  coz wo wala element bhi to target ho sakta tha. ussey thodi ignore kar sakte h..
                int mid = lo + (hi - lo)/2;
                
                if (mat[i][mid] == x) return true;
                
                else if (mat[i][mid] < x) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        
        return false;
    }
};
