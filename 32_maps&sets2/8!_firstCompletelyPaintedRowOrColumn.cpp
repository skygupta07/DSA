#include <bits/stdc++.h>
using namespace std;


/*

You are given a 0-indexed integer array arr, 
and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell 
in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.


Example 1:

image explanation for example 1
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, 
and both the first row and second column of the matrix become fully painted at arr[2].


Example 2:

image explanation for example 2
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].
 

Constraints:

m == mat.length
n = mat[i].length
arr.length == m * n
1 <= m, n <= 105
1 <= m * n <= 105
1 <= arr[i], mat[r][c] <= m * n
All the integers of arr are unique.
All the integers of mat are unique.

*/

class Solution {
public:
    
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // matrix element and its index
        unordered_map <int, pair <int, int>> mp;

        for (int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[mat[i][j]] = {i, j};
            }
        }

        vector <int> rowCounter(m, 0);
        vector <int> colCounter(n, 0);

        for (int i=0; i<m*n; i++){  
                int x = mp[arr[i]].first;
                int y = mp[arr[i]].second;

                rowCounter[x]++;
                colCounter[y]++;

                // agar xth row mai (m nahi n) element visit ho gaye matlab puri row paint ho gayi
                if (rowCounter[x] == n || colCounter[y] == m) return i; 

                /*
                Answer
460 / 1058 testcases passed -> If I used rowCounter[x] == m and colCounter[y] == n


Editorial
Input
arr =
[1,4,5,2,6,3]
mat =
[[4,3,5],[1,2,6]]

Use Testcase
Output
2
Expected
1

                */ 
        }

        return -1;
    }
};

/*
faster lookup ke liye unordered_map create kar sakta hu with arr element as key and their indices as value

now iterate over arr and mark that particular element in mat
after each marking see if that element's row or column has been completely visited then return the arr's index
*/